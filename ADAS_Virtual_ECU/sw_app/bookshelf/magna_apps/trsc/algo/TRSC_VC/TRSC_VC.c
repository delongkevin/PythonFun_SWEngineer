/*
 * File: TRSC_VC.c
 *
 * Code generated for Simulink model 'TRSC_VC'.
 *
 * Model version                  : 1.7705
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:52:03 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "TRSC_VC.h"
#include "TRSC_VC_private.h"
#include "rt_Spline2Derivf.h"
#include "look_SplNLinXZf.h"
#include "BINARYSEARCH_real_Treal32_T_Near_iL.h"
#include "LookUp_real32_T_real32_T.h"
#include "LookUpEven_real32_T_real32_T.h"
#include "look1_iflf_binlcapw.h"
#include "look1_iflf_binlxpw.h"
#include "look1_iflf_linlxpw.h"
#include "look2_iflf_binlxpw.h"
#include "look2_iflf_linlcapw.h"
#include "rt_modf_snf.h"
#include "rt_remf_snf.h"
#include "tand_brbYAlcS.h"

/* Exported block signals */
TbTRSC_KM_MABx KM_MABx;                /* '<S8>/Bus Creator1'
                                        * KM_MABx
                                        */
real32_T IeLSCAN_m_TrailerBeamLen;     /* '<S170>/Saturation4'
                                        * IeLSCAN_m_TrailerBeamLen
                                        */
real32_T MeCtrl_deg_THInit;            /* '<S168>/Switch'
                                        * MeCtrl_deg_THInit
                                        */
real32_T MeCtrl_deg_HdgDevLookup;      /* '<S119>/Lookup Table Dynamic'
                                        * MeCtrl_deg_HdgDevLookup
                                        */
real32_T MeCtrl_deg_TAD_des;           /* '<S147>/Switch2'
                                        * MeCtrl_deg_TAD_des
                                        */
real32_T MeCtrl_deg_TAD_error;         /* '<S137>/Switch2'
                                        * MeCtrl_deg_TAD_error
                                        */
real32_T MeTRSC_deg_TrlrAngKnob;       /* '<S117>/Data Type Conversion1'
                                        * MeTRSC_deg_TrlrAngKnob
                                        */
real32_T MeCtrl_deg_TAD_PID;           /* '<S141>/Add'
                                        * Intermediate signal for Trailer Angle Detect for PID
                                        */
real32_T MeCtrl_deg_SteerAngIn;        /* '<S113>/Switch1'
                                        * MeCtrl_deg_SteerAngIn
                                        */
real32_T MeCtrl_deg_SteerCMD;          /* '<S126>/Data Type Conversion'
                                        * MeCtrl_deg_SteerCMD
                                        */
real32_T StrCmd;                       /* '<S160>/Sum'
                                        * StrCmd
                                        */
real32_T StrRpt;                       /* '<S122>/Data Type Conversion1'
                                        * StrRpt
                                        */
real32_T MeTRSC_s_TwitchTmr;           /* '<S122>/Discrete-Time Integrator1'
                                        * MeTRSC_s_TwitchTmr
                                        */
real32_T MeTRSC_e_IdentifiedCase;      /* '<S122>/Data Type Conversion3'
                                        * MeTRSC_e_IdentifiedCase
                                        */
real32_T MeCtrl_m_TravelDist;          /* '<S121>/Add'
                                        * MeCtrl_m_TravelDist
                                        */
real32_T MeCtrl_deg_PIDe_p;            /* '<S151>/Switch2'
                                        * MeCtrl_deg_PIDe_p
                                        */
real32_T MeTRA_deg_PathDeviation;      /* '<S115>/Add5'
                                        * MeTRA_deg_PathDeviation
                                        */
real32_T MeCtrl_deg_HeadingOut;        /* '<S131>/Switch'
                                        * Intermediate signal for Heading Output
                                        */
real32_T MeCtrl_deg_e_p;               /* '<S114>/Switch'
                                        * Intermediate signal for error
                                        */
real32_T MeCtrl_deg_HeadingDeviation;  /* '<S114>/Add'
                                        * Intermediate signal for Heading Deviation
                                        */
real32_T MeTRSC_deg_RawDesTrlrAng;     /* '<S99>/Product_DesiredTAD1  '
                                        * Intermediate signal for Raw value of desired trailer angle
                                        */
real32_T IeLSCAN_v_VehSp_pulse;        /* '<S37>/Sum'
                                        * IeLSCAN_v_VehSp_pulse
                                        */
real32_T MeKM_deg_GyroYawRate;         /* '<S52>/Switch'
                                        * MeKM_deg_GyroYawRate
                                        */
real32_T JackKnifeAngle_deg;           /* '<S22>/Switch2'
                                        * JackKnifeAngle_deg
                                        */
int16_T MeTRSC_deg_KnobAngHys;         /* '<S101>/Switch_TAD_des_Final1'
                                        * Intermediate signal for Knob Angle (Output of knob hysteresis logic)
                                        */
boolean_T MeTRSC_b_TRAAct;             /* '<S19>/Logical Operator1'
                                        * TRA ACT
                                        */
boolean_T MeOTBL_b_Enable_1;           /* '<S176>/Logical Operator1'
                                        * MeOTBL_b_Enable_1
                                        */
boolean_T MeOTBL_b_Enable;             /* '<S179>/Compare'
                                        * MeOTBL_b_Enable
                                        */
boolean_T MeTRSC_b_TwitchCompleted;    /* '<S122>/Logical Operator'
                                        * MeTRSC_b_TwitchCompleted
                                        */
MdlrefDW_TRSC_VC_T TRSC_VC_MdlrefDW;

/* Block signals (default storage) */
B_TRSC_VC_c_T TRSC_VC_B;

/* Block states (default storage) */
DW_TRSC_VC_f_T TRSC_VC_DW;

/* Previous zero-crossings (trigger) states */
ZCE_TRSC_VC_T TRSC_VC_PrevZCX;

/*
 * System initialize for atomic system:
 *    '<S141>/Integrator_Subsytem1'
 *    '<S146>/Integrator_Subsytem1'
 *    '<S146>/Integrator_Subsytem2'
 *    '<S150>/Integrator_Subsytem1'
 */
void TRSC_VC_Integrator_Subsytem1_Init(DW_Integrator_Subsytem1_TRSC_VC_T
  *localDW)
{
  /* InitializeConditions for UnitDelay: '<S143>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S143>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0.0F;
}

/*
 * System reset for atomic system:
 *    '<S141>/Integrator_Subsytem1'
 *    '<S146>/Integrator_Subsytem1'
 *    '<S146>/Integrator_Subsytem2'
 *    '<S150>/Integrator_Subsytem1'
 */
void TRSC_VC_Integrator_Subsytem1_Reset(DW_Integrator_Subsytem1_TRSC_VC_T
  *localDW)
{
  /* InitializeConditions for UnitDelay: '<S143>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S143>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0.0F;
}

/*
 * Outputs for atomic system:
 *    '<S141>/Integrator_Subsytem1'
 *    '<S146>/Integrator_Subsytem1'
 *    '<S146>/Integrator_Subsytem2'
 *    '<S150>/Integrator_Subsytem1'
 */
void TRSC_VC_Integrator_Subsytem1(real32_T rtu_t, boolean_T rtu_Reset, real32_T *
  rty_y, B_Integrator_Subsytem1_TRSC_VC_T *localB,
  DW_Integrator_Subsytem1_TRSC_VC_T *localDW, ZCE_Integrator_Subsytem1_TRSC_VC_T
  *localZCE)
{
  /* Outputs for Resettable SubSystem: '<S141>/Integrator_Subsytem1' incorporates:
   *  ResetPort: '<S143>/Reset'
   */
  if (rtu_Reset && (localZCE->Integrator_Subsytem1_Reset_ZCE != POS_ZCSIG)) {
    TRSC_VC_Integrator_Subsytem1_Reset(localDW);
  }

  localZCE->Integrator_Subsytem1_Reset_ZCE = rtu_Reset;

  /* UnitDelay: '<S143>/Unit Delay' */
  localB->UnitDelay = localDW->UnitDelay_DSTATE;

  /* UnitDelay: '<S143>/Unit Delay1' */
  localB->Product = localDW->UnitDelay1_DSTATE;

  /* Product: '<S143>/Product' */
  localB->Product *= rtu_t;

  /* Sum: '<S143>/Add' */
  *rty_y = localB->UnitDelay + localB->Product;

  /* End of Outputs for SubSystem: '<S141>/Integrator_Subsytem1' */
}

/*
 * Update for atomic system:
 *    '<S141>/Integrator_Subsytem1'
 *    '<S146>/Integrator_Subsytem1'
 *    '<S146>/Integrator_Subsytem2'
 *    '<S150>/Integrator_Subsytem1'
 */
void TRSC_VC_Integrator_Subsytem1_Update(real32_T rtu_u, real32_T *rty_y,
  DW_Integrator_Subsytem1_TRSC_VC_T *localDW)
{
  /* Update for Resettable SubSystem: '<S141>/Integrator_Subsytem1' incorporates:
   *  ResetPort: '<S143>/Reset'
   */
  /* Update for UnitDelay: '<S143>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rty_y;

  /* Update for UnitDelay: '<S143>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = rtu_u;

  /* End of Update for SubSystem: '<S141>/Integrator_Subsytem1' */
}

/* Output and update for atomic system: '<S170>/OTBL_Enable' */
void TRSC_VC_OTBL_Enable(void)
{
  /* UnitDelay: '<S181>/Unit Delay' */
  TRSC_VC_B.UnitDelay = TRSC_VC_DW.UnitDelay_DSTATE;

  /* RelationalOperator: '<S180>/Compare' incorporates:
   *  Constant: '<S180>/Constant'
   */
  TRSC_VC_B.Switch5_j = (TRSC_VC_B.DataTypeConversion2_f == ((uint8_T)5U));

  /* Logic: '<S175>/AND4' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Switch5_j =
    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_OBTLRecalibrate &&
     TRSC_VC_B.Switch5_j);

  /* DataTypeConversion: '<S175>/Data Type Conversion' */
  TRSC_VC_B.Product2 = TRSC_VC_B.Switch5_j;

  /* Sum: '<S181>/Sum2' */
  TRSC_VC_B.Product2 -= TRSC_VC_B.UnitDelay;

  /* Product: '<S181>/Product2' incorporates:
   *  Constant: '<S175>/Constant1'
   */
  TRSC_VC_B.Product2 *= 0.5;

  /* Sum: '<S181>/Sum' */
  TRSC_VC_B.Sum = TRSC_VC_B.UnitDelay + TRSC_VC_B.Product2;

  /* RelationalOperator: '<S179>/Compare' incorporates:
   *  Constant: '<S179>/Constant'
   */
  MeOTBL_b_Enable = (TRSC_VC_B.Sum > 0.1);

  /* Update for UnitDelay: '<S181>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE = TRSC_VC_B.Sum;
}

/* Output and update for atomic system: '<S170>/OTBL_Enable1' */
void TRSC_VC_OTBL_Enable1(void)
{
  /* RelationalOperator: '<S182>/Compare' incorporates:
   *  Constant: '<S182>/Constant'
   */
  TRSC_VC_B.Switch5_j = (TRSC_VC_B.DataTypeConversion2_f == ((uint8_T)5U));

  /* Logic: '<S176>/Logical Operator1' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  MeOTBL_b_Enable_1 = (TRSC_VC_B.Switch5_j &&
                       IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_OBTLRecalibrate);
}

/* System initialize for referenced model: 'TRSC_VC' */
void TRSC_VC_Init(void)
{
  int32_T i;

  /* SystemInitialize for Atomic SubSystem: '<Root>/TRSC_VC2' */
  /* SystemInitialize for Enabled SubSystem: '<S1>/Trailer Beam Length1' */
  /* SystemInitialize for S-Function (fcncallgen): '<S18>/Function-Call Generator' incorporates:
   *  SubSystem: '<S18>/Subsystem'
   */
  /* InitializeConditions for UnitDelay: '<S170>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_o = 1.8F;

  /* SystemInitialize for Enabled SubSystem: '<S170>/OnlineTrailerBeamLengthEstimation' */
  /* SystemInitialize for SignalConversion generated from: '<S177>/LogOut' */
  TRSC_VC_B.TADvec = TRSC_VC_B.TADvec_n;

  /* SystemInitialize for SignalConversion generated from: '<S177>/LogOut' */
  TRSC_VC_B.TAD01 = TRSC_VC_B.TAD01_a;

  /* SystemInitialize for SignalConversion generated from: '<S177>/LogOut' */
  TRSC_VC_B.KeOTBL_m_HV_WheelBase = TRSC_VC_B.KeOTBL_m_HV_WheelBase_m;

  /* End of SystemInitialize for SubSystem: '<S170>/OnlineTrailerBeamLengthEstimation' */
  /* End of SystemInitialize for S-Function (fcncallgen): '<S18>/Function-Call Generator' */
  /* End of SystemInitialize for SubSystem: '<S1>/Trailer Beam Length1' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/JackKnife Angle ' */
  /* InitializeConditions for Delay: '<S7>/Delay' */
  TRSC_VC_DW.icLoad_m = 1U;

  /* SystemInitialize for Outport: '<S7>/JackKnife_deg_out' */
  JackKnifeAngle_deg = 53.0F;

  /* End of SystemInitialize for SubSystem: '<S1>/JackKnife Angle ' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/Kinematic Model' */
  /* SystemInitialize for Resettable SubSystem: '<S8>/Kinematic_model' */
  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay5' */
  TRSC_VC_DW.UnitDelay5_DSTATE = false;

  /* InitializeConditions for UnitDelay: '<S37>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_e = 0.0F;

  /* InitializeConditions for Delay: '<S24>/Delay' */
  TRSC_VC_DW.icLoad_c = 1U;

  /* InitializeConditions for Delay: '<S24>/Delay1' */
  TRSC_VC_DW.icLoad_jq = 1U;

  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_m[0] = 0.0F;
  TRSC_VC_DW.UnitDelay1_DSTATE_m[1] = 0.0F;
  TRSC_VC_DW.UnitDelay1_DSTATE_m[2] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S28>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_k = KeKM_k_KM_YawRateGyroBiasInit;

  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay3' */
  for (i = 0; i < 9; i++) {
    TRSC_VC_DW.UnitDelay3_DSTATE_d[i] = rtCP_UnitDelay3_InitialCondition_e[i];
  }

  /* End of InitializeConditions for UnitDelay: '<S24>/Unit Delay3' */

  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay4' */
  TRSC_VC_DW.UnitDelay4_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S55>/Delay Input1'
   *
   * Block description for '<S55>/Delay Input1':
   *
   *  Store in Global RAM
   */
  TRSC_VC_DW.DelayInput1_DSTATE_g = true;

  /* InitializeConditions for UnitDelay: '<S56>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_kz = false;

  /* InitializeConditions for UnitDelay: '<S33>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_pk = false;

  /* SystemInitialize for Resettable SubSystem: '<S57>/ResettableSubsystem' */
  /* InitializeConditions for UnitDelay: '<S63>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_b = 0.0F;

  /* InitializeConditions for UnitDelay: '<S63>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_bl = 0.0F;

  /* InitializeConditions for UnitDelay: '<S62>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_pb = 0.0F;

  /* InitializeConditions for UnitDelay: '<S62>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_a = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S57>/ResettableSubsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S24>/YawRate_RPM_Bias' */
  /* InitializeConditions for UnitDelay: '<S97>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_dj = 2.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/YawRate_RPM_Bias' */

  /* SystemInitialize for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal1' */
  /* InitializeConditions for UnitDelay: '<S30>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_m5 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S30>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_he = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/KM_Integrator_Trapazoidal1' */

  /* SystemInitialize for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal' */
  /* InitializeConditions for UnitDelay: '<S29>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_kq = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_nt = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/KM_Integrator_Trapazoidal' */

  /* SystemInitialize for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal2' */
  /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_m = 0.0F;

  /* InitializeConditions for UnitDelay: '<S31>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_p = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/KM_Integrator_Trapazoidal2' */
  /* End of SystemInitialize for SubSystem: '<S8>/Kinematic_model' */
  /* End of SystemInitialize for SubSystem: '<S1>/Kinematic Model' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/Torque Control' */
  /* SystemInitialize for S-Function (fcncallgen): '<S17>/Function-Call Generator' incorporates:
   *  SubSystem: '<S17>/VehicleControl'
   */
  /* SystemInitialize for Enabled SubSystem: '<S108>/Controller_Main2' */
  /* InitializeConditions for UnitDelay: '<S136>/Delay Input2'
   *
   * Block description for '<S136>/Delay Input2':
   *
   *  Store in Global RAM
   */
  TRSC_VC_DW.DelayInput2_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S135>/Resettable Delay' */
  TRSC_VC_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S134>/Resettable Delay' */
  TRSC_VC_DW.icLoad_k = 1U;

  /* InitializeConditions for Delay: '<S118>/Delay' */
  TRSC_VC_DW.Delay_DSTATE_o[0] = true;
  TRSC_VC_DW.Delay_DSTATE_o[1] = true;
  TRSC_VC_DW.Delay_DSTATE_o[2] = true;
  TRSC_VC_DW.Delay_DSTATE_o[3] = true;

  /* InitializeConditions for Delay: '<S109>/Delay' */
  TRSC_VC_DW.Delay_DSTATE_kg = false;

  /* InitializeConditions for Delay: '<S126>/Resettable Delay' */
  TRSC_VC_DW.icLoad_d = 1U;

  /* InitializeConditions for Delay: '<S160>/Delay' */
  TRSC_VC_DW.icLoad_j = 1U;

  /* InitializeConditions for UnitDelay: '<S159>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_n = 0.0F;

  /* InitializeConditions for Delay: '<S166>/Delay' */
  TRSC_VC_DW.icLoad_p = 1U;

  /* InitializeConditions for UnitDelay: '<S159>/Unit Delay2' */
  TRSC_VC_DW.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */
  TRSC_VC_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  TRSC_VC_DW.DiscreteTimeIntegrator1_PrevResetState = 2;

  /* InitializeConditions for UnitDelay: '<S122>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_ed = false;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
  TRSC_VC_DW.DiscreteTimeIntegrator_IC_LOADING = 1U;
  TRSC_VC_DW.DiscreteTimeIntegrator_PrevResetState = 2;

  /* InitializeConditions for UnitDelay: '<S163>/Delay Input2'
   *
   * Block description for '<S163>/Delay Input2':
   *
   *  Store in Global RAM
   */
  TRSC_VC_DW.DelayInput2_DSTATE_p = 0.0F;

  /* InitializeConditions for UnitDelay: '<S156>/Delay Input2'
   *
   * Block description for '<S156>/Delay Input2':
   *
   *  Store in Global RAM
   */
  TRSC_VC_DW.DelayInput2_DSTATE_d = 0.0F;

  /* SystemInitialize for Resettable SubSystem: '<S109>/Path_Deviation' */
  /* InitializeConditions for UnitDelay generated from: '<S115>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay generated from: '<S115>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_1_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S109>/Path_Deviation' */

  /* SystemInitialize for Resettable SubSystem: '<S109>/TravDist_TrapIntegrator' */
  /* InitializeConditions for UnitDelay: '<S121>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_fm = 0.0F;

  /* InitializeConditions for UnitDelay: '<S121>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S109>/TravDist_TrapIntegrator' */

  /* SystemInitialize for Resettable SubSystem: '<S109>/TAD_ep1' */
  /* SystemInitialize for Resettable SubSystem: '<S150>/Integrator_Subsytem2' */
  /* InitializeConditions for UnitDelay: '<S153>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_d = 0.0F;

  /* InitializeConditions for UnitDelay: '<S153>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S150>/Integrator_Subsytem2' */

  /* SystemInitialize for Resettable SubSystem: '<S150>/Integrator_Subsytem1' */
  TRSC_VC_Integrator_Subsytem1_Init(&TRSC_VC_DW.Integrator_Subsytem1_j);

  /* End of SystemInitialize for SubSystem: '<S150>/Integrator_Subsytem1' */
  /* End of SystemInitialize for SubSystem: '<S109>/TAD_ep1' */

  /* SystemInitialize for Resettable SubSystem: '<S146>/Integrator_Subsytem2' */
  TRSC_VC_Integrator_Subsytem1_Init(&TRSC_VC_DW.Integrator_Subsytem2);

  /* End of SystemInitialize for SubSystem: '<S146>/Integrator_Subsytem2' */

  /* SystemInitialize for Resettable SubSystem: '<S146>/Integrator_Subsytem1' */
  TRSC_VC_Integrator_Subsytem1_Init(&TRSC_VC_DW.Integrator_Subsytem1_g);

  /* End of SystemInitialize for SubSystem: '<S146>/Integrator_Subsytem1' */

  /* SystemInitialize for Resettable SubSystem: '<S141>/Integrator_Subsytem' */
  /* InitializeConditions for UnitDelay: '<S142>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_p = 0.0F;

  /* InitializeConditions for UnitDelay: '<S142>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE = 0.0;

  /* End of SystemInitialize for SubSystem: '<S141>/Integrator_Subsytem' */

  /* SystemInitialize for Resettable SubSystem: '<S141>/Integrator_Subsytem1' */
  TRSC_VC_Integrator_Subsytem1_Init(&TRSC_VC_DW.Integrator_Subsytem1);

  /* End of SystemInitialize for SubSystem: '<S141>/Integrator_Subsytem1' */

  /* SystemInitialize for Enabled SubSystem: '<S122>/THA_SteerTweakProfile_Processing2' */
  /* InitializeConditions for Delay: '<S158>/Delay1' */
  TRSC_VC_DW.Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S158>/Delay' */
  TRSC_VC_DW.Delay_DSTATE_j = 0.0F;

  /* InitializeConditions for Delay: '<S158>/Delay2' */
  TRSC_VC_DW.Delay2_DSTATE_o = false;

  /* End of SystemInitialize for SubSystem: '<S122>/THA_SteerTweakProfile_Processing2' */
  /* End of SystemInitialize for SubSystem: '<S108>/Controller_Main2' */
  /* End of SystemInitialize for S-Function (fcncallgen): '<S17>/Function-Call Generator' */
  /* End of SystemInitialize for SubSystem: '<S1>/Torque Control' */
  /* End of SystemInitialize for SubSystem: '<Root>/TRSC_VC2' */
}

/* Disable for referenced model: 'TRSC_VC' */
void TRSC_VC_Disable(TeTRSC_e_SpdLmtReq *rty_MeTRSC_e_SpdLmtReq)
{
  /* Disable for Atomic SubSystem: '<Root>/TRSC_VC2' */
  /* Disable for Enabled SubSystem: '<S1>/Trailer Beam Length1' */
  if (TRSC_VC_DW.TrailerBeamLength1_MODE) {
    /* Disable for S-Function (fcncallgen): '<S18>/Function-Call Generator' incorporates:
     *  SubSystem: '<S18>/Subsystem'
     */
    /* Disable for Enabled SubSystem: '<S170>/OnlineTrailerBeamLengthEstimation' */
    TRSC_VC_DW.OnlineTrailerBeamLengthEstimation_MODE = false;

    /* End of Disable for SubSystem: '<S170>/OnlineTrailerBeamLengthEstimation' */

    /* Disable for Enabled SubSystem: '<S170>/Subsystem' */
    TRSC_VC_DW.Subsystem_MODE = false;

    /* End of Disable for SubSystem: '<S170>/Subsystem' */
    /* End of Disable for S-Function (fcncallgen): '<S18>/Function-Call Generator' */
    TRSC_VC_DW.TrailerBeamLength1_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/Trailer Beam Length1' */

  /* Disable for Enabled SubSystem: '<S9>/KnobAngleComp' */
  if (TRSC_VC_DW.KnobAngleComp_MODE) {
    /* Disable for Outport: '<S100>/Rotary_Encoder_Btn' */
    TRSC_VC_B.Computed_Out = 0;

    /* Disable for Outport: '<S100>/Change_In_Dir' */
    TRSC_VC_B.OutportBufferForChange_In_Dir = 0;

    /* Disable for Outport: '<S100>/knob_up_change_flg' */
    TRSC_VC_B.OutportBufferForknob_up_change_flg = 0.0F;

    /* Disable for Outport: '<S100>/knob_dwn_change_flg' */
    TRSC_VC_B.OutportBufferForknob_dwn_change_flg = 0.0F;

    /* Disable for Outport: '<S100>/Change_In_Dir_Flag' */
    TRSC_VC_B.OutportBufferForChange_In_Dir_Flag = 0.0F;
    TRSC_VC_DW.KnobAngleComp_MODE = false;
  }

  /* End of Disable for SubSystem: '<S9>/KnobAngleComp' */

  /* Disable for Enabled SubSystem: '<S9>/DesiredTrailerAngleComp' */
  if (TRSC_VC_DW.DesiredTrailerAngleComp_MODE) {
    /* Disable for Outport: '<S99>/MeTRSC_deg_RawDesTrlrAng' */
    MeTRSC_deg_RawDesTrlrAng = 0.0F;
    TRSC_VC_DW.DesiredTrailerAngleComp_MODE = false;
  }

  /* End of Disable for SubSystem: '<S9>/DesiredTrailerAngleComp' */

  /* Disable for Enabled SubSystem: '<S1>/Kinematic Model' */
  if (TRSC_VC_DW.KinematicModel_MODE) {
    /* Disable for Resettable SubSystem: '<S8>/Kinematic_model' */
    /* Disable for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal1' */
    if (TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE) {
      /* Disable for Outport: '<S30>/MeKM_k_HeadingIn' */
      TRSC_VC_B.MeKM_k_HeadingIn = 0.0F;
      TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE = false;
    }

    /* End of Disable for SubSystem: '<S24>/KM_Integrator_Trapazoidal1' */

    /* Disable for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal' */
    if (TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE) {
      /* Disable for Outport: '<S29>/IeLSCAN_m_HV_X' */
      TRSC_VC_B.IeLSCAN_m_HV_X = 0.0F;
      TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE = false;
    }

    /* End of Disable for SubSystem: '<S24>/KM_Integrator_Trapazoidal' */

    /* Disable for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal2' */
    if (TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE) {
      /* Disable for Outport: '<S31>/IeLSCAN_m_HV_Y' */
      TRSC_VC_B.IeLSCAN_m_HV_Y = 0.0F;
      TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE = false;
    }

    /* End of Disable for SubSystem: '<S24>/KM_Integrator_Trapazoidal2' */
    /* End of Disable for SubSystem: '<S8>/Kinematic_model' */
    TRSC_VC_DW.KinematicModel_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/Kinematic Model' */

  /* Disable for Atomic SubSystem: '<S1>/Torque Control' */
  /* Disable for S-Function (fcncallgen): '<S17>/Function-Call Generator' incorporates:
   *  SubSystem: '<S17>/VehicleControl'
   */
  /* Disable for Enabled SubSystem: '<S108>/Controller_Main2' */
  if (TRSC_VC_DW.Controller_Main2_MODE) {
    /* Disable for Enabled SubSystem: '<S122>/THA_SteerTweakProfile_Processing2' */
    TRSC_VC_DW.THA_SteerTweakProfile_Processing2_MODE = false;

    /* End of Disable for SubSystem: '<S122>/THA_SteerTweakProfile_Processing2' */

    /* Disable for Outport: '<S109>/MeTRSC_M_StrTrqCmd' */
    TRSC_VC_B.TrqCMD = 0.0F;

    /* Disable for Outport: '<S109>/MeTRSC_e_SpdLmtReq' */
    *rty_MeTRSC_e_SpdLmtReq = TeTRSC_e_SpdLmtReq_NotLim;

    /* Disable for Outport: '<S109>/MeTRSC_deg_TrlrAngKnob' */
    MeTRSC_deg_TrlrAngKnob = 0.0F;

    /* Disable for Outport: '<S109>/MeCtrl_deg_frntwhlCommand' */
    TRSC_VC_B.tanVals = 0.0F;
    TRSC_VC_DW.Controller_Main2_MODE = false;
  }

  /* End of Disable for SubSystem: '<S108>/Controller_Main2' */

  /* Disable for Outport: '<S108>/MeCtrl_deg_frntwhlCommand' */
  TRSC_VC_B.OutportBufferForMeCtrl_deg_frntwhlCommand = 0.0F;

  /* End of Disable for S-Function (fcncallgen): '<S17>/Function-Call Generator' */

  /* Disable for SignalConversion generated from: '<S17>/VehicleControl' */
  MeTRSC_M_TRSCStrTrq = TRSC_VC_B.TrqCMD;

  /* End of Disable for SubSystem: '<S1>/Torque Control' */
  /* End of Disable for SubSystem: '<Root>/TRSC_VC2' */
}

/* Start for referenced model: 'TRSC_VC' */
void TRSC_VC_Start(void)
{
  /* Start for Atomic SubSystem: '<Root>/TRSC_VC2' */
  /* Start for Enabled SubSystem: '<S1>/Kinematic Model' */
  /* Start for Resettable SubSystem: '<S8>/Kinematic_model' */
  /* Start for Lookup_n-D: '<S78>/1-D Lookup Table_0_2' */
  {
    rt_LUTnWork *TWork_start = (rt_LUTnWork *) &TRSC_VC_DW.TWork[0];
    void **bpDataSet = (void **) &TRSC_VC_DW.m_bpDataSet;
    TWork_start->m_dimSizes = (const uint32_T *)
      &rtCP_uDLookupTable_0_2_dimSizes_g;
    TWork_start->m_tableData = (void *) rtCP_uDLookupTable_0_2_tableData_j;
    TWork_start->m_bpDataSet = bpDataSet;
    TWork_start->m_bpIndex = &TRSC_VC_DW.m_bpIndex;
    TWork_start->m_bpLambda = &TRSC_VC_DW.m_bpLambda;
    TWork_start->m_maxIndex = (const uint32_T *)
      &rtCP_uDLookupTable_0_2_maxIndex_e;
    bpDataSet[0] = (void *) rtCP_uDLookupTable_0_2_bp01Data_c;
  }

  {
    const real32_T **bpDataSet;
    const real32_T *xp, *yp;
    real32_T *up, *y2;
    uint32_T i, len;
    const rt_LUTnWork *TWork_interp;
    rt_LUTSplineWork *rt_SplWk = (rt_LUTSplineWork*)&TRSC_VC_DW.SWork[0];
    rt_SplWk->m_TWork = (rt_LUTnWork*)&TRSC_VC_DW.TWork[0];
    rt_SplWk->m_yyA = &TRSC_VC_DW.m_yyA;
    rt_SplWk->m_yyB = &TRSC_VC_DW.m_yyB;
    rt_SplWk->m_yy2 = &TRSC_VC_DW.m_yy2;
    rt_SplWk->m_up = &TRSC_VC_DW.m_up[0];
    rt_SplWk->m_y2 = &TRSC_VC_DW.m_y2[0];
    rt_SplWk->m_numYWorkElts = rtCP_uDLookupTable_0_2_numYWorkElts_n;

    /* If table and bps are not-tunable then precalculate 1st dim 2nd deriv */
    TWork_interp = (const rt_LUTnWork *)rt_SplWk->m_TWork;
    bpDataSet = (const real32_T **) TWork_interp->m_bpDataSet;
    xp = bpDataSet[0U];
    yp = (real32_T *) TWork_interp->m_tableData;
    len = TWork_interp->m_maxIndex[0U] + 1U;
    up = (real32_T *) rt_SplWk->m_up;
    y2 = (real32_T *) rt_SplWk->m_y2;

    /* Generate first dimension's second derivatives */
    for (i = 0U; i < rt_SplWk->m_numYWorkElts[0U]; i++) {
      rt_Spline2Derivf(xp, yp, len, up, y2);
      yp = &yp[len];
      y2 = &y2[len];
    }
  }

  /* Start for Lookup_n-D: '<S75>/1-D Lookup Table_0_2' */
  {
    rt_LUTnWork *TWork_start = (rt_LUTnWork *) &TRSC_VC_DW.TWork_d[0];
    void **bpDataSet = (void **) &TRSC_VC_DW.m_bpDataSet_i;
    TWork_start->m_dimSizes = (const uint32_T *)
      &rtCP_uDLookupTable_0_2_dimSizes;
    TWork_start->m_tableData = (void *) rtCP_uDLookupTable_0_2_tableData_i;
    TWork_start->m_bpDataSet = bpDataSet;
    TWork_start->m_bpIndex = &TRSC_VC_DW.m_bpIndex_i;
    TWork_start->m_bpLambda = &TRSC_VC_DW.m_bpLambda_o;
    TWork_start->m_maxIndex = (const uint32_T *)
      &rtCP_uDLookupTable_0_2_maxIndex;
    bpDataSet[0] = (void *) rtCP_uDLookupTable_0_2_bp01Data_h;
  }

  {
    const real32_T **bpDataSet;
    const real32_T *xp, *yp;
    real32_T *up, *y2;
    uint32_T i, len;
    const rt_LUTnWork *TWork_interp;
    rt_LUTSplineWork *rt_SplWk = (rt_LUTSplineWork*)&TRSC_VC_DW.SWork_k[0];
    rt_SplWk->m_TWork = (rt_LUTnWork*)&TRSC_VC_DW.TWork_d[0];
    rt_SplWk->m_yyA = &TRSC_VC_DW.m_yyA_d;
    rt_SplWk->m_yyB = &TRSC_VC_DW.m_yyB_o;
    rt_SplWk->m_yy2 = &TRSC_VC_DW.m_yy2_a;
    rt_SplWk->m_up = &TRSC_VC_DW.m_up_j[0];
    rt_SplWk->m_y2 = &TRSC_VC_DW.m_y2_j[0];
    rt_SplWk->m_numYWorkElts = rtCP_uDLookupTable_0_2_numYWorkElts;

    /* If table and bps are not-tunable then precalculate 1st dim 2nd deriv */
    TWork_interp = (const rt_LUTnWork *)rt_SplWk->m_TWork;
    bpDataSet = (const real32_T **) TWork_interp->m_bpDataSet;
    xp = bpDataSet[0U];
    yp = (real32_T *) TWork_interp->m_tableData;
    len = TWork_interp->m_maxIndex[0U] + 1U;
    up = (real32_T *) rt_SplWk->m_up;
    y2 = (real32_T *) rt_SplWk->m_y2;

    /* Generate first dimension's second derivatives */
    for (i = 0U; i < rt_SplWk->m_numYWorkElts[0U]; i++) {
      rt_Spline2Derivf(xp, yp, len, up, y2);
      yp = &yp[len];
      y2 = &y2[len];
    }
  }

  /* End of Start for SubSystem: '<S8>/Kinematic_model' */
  /* End of Start for SubSystem: '<S1>/Kinematic Model' */
  /* End of Start for SubSystem: '<Root>/TRSC_VC2' */
}

/* Output and update for referenced model: 'TRSC_VC' */
void TRSC_VC(const TeTRSC_e_TRSCStat *rtu_MeTRSC_e_TRSCStat,
             TeTRSC_e_TRSCStrTrqActvReq *rty_MeTRSC_e_TRSCStrTrqActvReq,
             TeTRSC_e_SpdLmtReq *rty_MeTRSC_e_SpdLmtReq)
{
  int8_T n;
  int32_T i;
  uint32_T tmp;
  boolean_T tmp_0;
  real32_T TAD_pred_tmp;
  int32_T Add2_m_tmp;
  int32_T Selector2_tmp;
  int32_T Divide5_h_tmp;
  int32_T Product2_j_tmp;
  int32_T u1wNxN1_tmp;
  int32_T u1wNxN1_tmp_0;
  int32_T Gain_k_tmp;
  int32_T Selector2_tmp_0;
  int32_T Selector_g_tmp;
  static const real_T b[121] = { 2.0, 2.05, 2.1, 2.15, 2.2, 2.25, 2.3, 2.35, 2.4,
    2.45, 2.5, 2.55, 2.6, 2.65, 2.7, 2.75, 2.8, 2.85, 2.9, 2.95, 3.0, 3.05, 3.1,
    3.1500000000000004, 3.2, 3.25, 3.3, 3.35, 3.4000000000000004, 3.45, 3.5,
    3.55, 3.6, 3.6500000000000004, 3.7, 3.75, 3.8, 3.85, 3.9000000000000004,
    3.95, 4.0, 4.0500000000000007, 4.1, 4.15, 4.2, 4.25, 4.3000000000000007,
    4.35, 4.4, 4.45, 4.5, 4.5500000000000007, 4.6, 4.65, 4.7, 4.75,
    4.8000000000000007, 4.85, 4.9, 4.95, 5.0, 5.05, 5.1, 5.15,
    5.1999999999999993, 5.25, 5.3, 5.35, 5.4, 5.4499999999999993, 5.5, 5.55, 5.6,
    5.65, 5.6999999999999993, 5.75, 5.8, 5.85, 5.9, 5.9499999999999993, 6.0,
    6.05, 6.1, 6.15, 6.2, 6.25, 6.3, 6.35, 6.4, 6.45, 6.5, 6.55, 6.6, 6.65, 6.7,
    6.75, 6.8, 6.85, 6.9, 6.95, 7.0, 7.05, 7.1, 7.15, 7.2, 7.25, 7.3, 7.35, 7.4,
    7.45, 7.5, 7.55, 7.6, 7.65, 7.7, 7.75, 7.8, 7.85, 7.9, 7.95, 8.0 };

  boolean_T guard1 = false;
  boolean_T exitg1;

  /* UnitDelay: '<Root>/Unit Delay' */
  TRSC_VC_B.Gain_k = TRSC_VC_DW.UnitDelay_DSTATE_f;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  IeTRSC_deg_FrntWhlAng = TRSC_VC_B.Gain_k;

  /* Outputs for Atomic SubSystem: '<Root>/TRSC_VC2' */
  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.DataTypeConversion2_f = (uint8_T)
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState;

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   */
  TRSC_VC_B.Compare_m = (TRSC_VC_B.DataTypeConversion2_f == ((uint8_T)0U));

  /* Logic: '<S1>/Logical Operator3' */
  TRSC_VC_B.Compare_m = !TRSC_VC_B.Compare_m;

  /* Logic: '<S1>/Logical Operator2' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.LogicalOperator2 = (TRSC_VC_B.Compare_m ||
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_OBTLRecalibrate);

  /* Gain: '<S1>/Gain5' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain5 = (-1.0F) *
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle;

  /* Gain: '<S1>/Gain4' */
  TRSC_VC_B.Gain4 = (-1.0F) * TRSC_VC_B.Gain5;

  /* Gain: '<S1>/Gain2' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain2 = 0.001F *
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_m_HitchLength;

  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain = 0.277777791F *
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_kph_VehSpeedVSOSig;

  /* RelationalOperator: '<S14>/LowerRelop1' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_m = (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase >
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase_Up_Limit);

  /* RelationalOperator: '<S14>/UpperRelop' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_mp = (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase <
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase_Low_Limit);

  /* Switch: '<S14>/Switch' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_VC_B.Compare_mp) {
    TRSC_VC_B.Switch_d =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase_Low_Limit;
  } else {
    TRSC_VC_B.Switch_d = IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Switch: '<S14>/Switch2' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_VC_B.Compare_m) {
    TRSC_VC_B.Switch2 =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase_Up_Limit;
  } else {
    TRSC_VC_B.Switch2 = TRSC_VC_B.Switch_d;
  }

  /* End of Switch: '<S14>/Switch2' */

  /* Gain: '<S1>/Gain13' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain13 = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFWt;

  /* Gain: '<S1>/Gain14' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain14 = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFBias;

  /* RelationalOperator: '<S16>/LowerRelop1' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_mp =
    (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle >
     IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle_Up_Limit);

  /* RelationalOperator: '<S16>/UpperRelop' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_m =
    (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle <
     IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle_Low_Limit);

  /* Switch: '<S16>/Switch' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_VC_B.Compare_m) {
    TRSC_VC_B.Switch_g =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle_Low_Limit;
  } else {
    TRSC_VC_B.Switch_g =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Switch: '<S16>/Switch2' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_VC_B.Compare_mp) {
    TRSC_VC_B.Switch2_a =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle_Up_Limit;
  } else {
    TRSC_VC_B.Switch2_a = TRSC_VC_B.Switch_g;
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Gain: '<S1>/Gain11' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain_k = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFWt;

  /* Product: '<S13>/Product' */
  TRSC_VC_B.Gain_k *= TRSC_VC_B.Switch2_a;

  /* Abs: '<S45>/Abs' incorporates:
   *  Gain: '<S1>/Gain12'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Product_DesiredTAD = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFBias;

  /* Sum: '<S13>/Add' */
  TRSC_VC_B.Add = TRSC_VC_B.Gain_k + TRSC_VC_B.Product_DesiredTAD;

  /* Outputs for Enabled SubSystem: '<S1>/Trailer Beam Length1' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (TRSC_VC_B.LogicalOperator2) {
    TRSC_VC_DW.TrailerBeamLength1_MODE = true;

    /* S-Function (fcncallgen): '<S18>/Function-Call Generator' incorporates:
     *  SubSystem: '<S18>/Subsystem'
     */
    /* Outputs for Atomic SubSystem: '<S170>/OTBL_Enable' */
    TRSC_VC_OTBL_Enable();

    /* End of Outputs for SubSystem: '<S170>/OTBL_Enable' */

    /* Delay: '<S170>/Delay2' */
    TRSC_VC_B.Switch1_f = TRSC_VC_DW.Delay2_DSTATE;

    /* Outputs for Enabled SubSystem: '<S170>/OnlineTrailerBeamLengthEstimation' incorporates:
     *  EnablePort: '<S177>/Enable'
     */
    /* Switch: '<S170>/Switch' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    if (MeOTBL_b_Enable) {
      TRSC_VC_B.Switch_f = TRSC_VC_B.Switch1_f;
      TRSC_VC_DW.OnlineTrailerBeamLengthEstimation_MODE = true;

      /* Product: '<S183>/Product' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.Product_b =
        IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng *
        TRSC_VC_B.Gain13;

      /* Sum: '<S183>/Add' */
      TRSC_VC_B.Add_h = TRSC_VC_B.Product_b + TRSC_VC_B.Gain14;

      /* Outputs for Enabled SubSystem: '<S184>/TBL_DataLog' incorporates:
       *  EnablePort: '<S185>/Enable'
       */
      if (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_OBTLRecalibrate) {
        /* SignalConversion generated from: '<S185>/LogOut' */
        TRSC_VC_B.TADvec_n = TRSC_VC_B.Gain4;

        /* DiscreteIntegrator: '<S185>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S185>/Constant'
         */
        TRSC_VC_B.DiscreteTimeIntegrator = 0.03F * 1.0F +
          TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE;

        /* SignalConversion generated from: '<S185>/LogOut' */
        TRSC_VC_B.TAD01_a = TRSC_VC_B.Switch_f;

        /* SignalConversion generated from: '<S185>/LogOut' */
        TRSC_VC_B.KeOTBL_m_HV_WheelBase_m = TRSC_VC_B.Switch2;

        /* Product: '<S185>/Divide' incorporates:
         *  Constant: '<S185>/Constant1'
         *  Constant: '<S185>/Constant2'
         */
        TRSC_VC_B.Divide_m = KeTRSC_s_TblKmDelay / CeTRSC_s_TRSCLpTm;

        /* Delay: '<S185>/Delay One Step' incorporates:
         *  Delay: '<S185>/Delay One Step1'
         */
        tmp_0 = rtIsNaNF(TRSC_VC_B.Divide_m);
        if ((TRSC_VC_B.Divide_m < 1.0F) || tmp_0) {
          TRSC_VC_B.DelayOneStep = TRSC_VC_B.Add_h;
        } else {
          if (TRSC_VC_B.Divide_m > 100.0F) {
            tmp = 100U;
          } else {
            TRSC_VC_B.gamma_now_deg_m = truncf(TRSC_VC_B.Divide_m);
            if (rtIsNaNF(TRSC_VC_B.gamma_now_deg_m) || rtIsInfF
                (TRSC_VC_B.gamma_now_deg_m)) {
              TRSC_VC_B.gamma_now_deg_m = 0.0F;
            } else {
              TRSC_VC_B.gamma_now_deg_m = fmodf(TRSC_VC_B.gamma_now_deg_m,
                4.2949673E+9F);
            }

            tmp = TRSC_VC_B.gamma_now_deg_m < 0.0F ? (uint32_T)-(int32_T)
              (uint32_T)-TRSC_VC_B.gamma_now_deg_m : (uint32_T)
              TRSC_VC_B.gamma_now_deg_m;
          }

          TRSC_VC_B.DelayOneStep = TRSC_VC_DW.DelayOneStep_DSTATE[100U - tmp];
        }

        /* End of Delay: '<S185>/Delay One Step' */

        /* Delay: '<S185>/Delay One Step1' */
        if ((TRSC_VC_B.Divide_m < 1.0F) || tmp_0) {
          TRSC_VC_B.DelayOneStep1 = TRSC_VC_B.Gain;
        } else {
          if (TRSC_VC_B.Divide_m > 100.0F) {
            tmp = 100U;
          } else {
            TRSC_VC_B.gamma_now_deg_m = truncf(TRSC_VC_B.Divide_m);
            if (rtIsNaNF(TRSC_VC_B.gamma_now_deg_m) || rtIsInfF
                (TRSC_VC_B.gamma_now_deg_m)) {
              TRSC_VC_B.gamma_now_deg_m = 0.0F;
            } else {
              TRSC_VC_B.gamma_now_deg_m = fmodf(TRSC_VC_B.gamma_now_deg_m,
                4.2949673E+9F);
            }

            tmp = TRSC_VC_B.gamma_now_deg_m < 0.0F ? (uint32_T)-(int32_T)
              (uint32_T)-TRSC_VC_B.gamma_now_deg_m : (uint32_T)
              TRSC_VC_B.gamma_now_deg_m;
          }

          TRSC_VC_B.DelayOneStep1 = TRSC_VC_DW.DelayOneStep1_DSTATE[100U - tmp];
        }

        /* Update for DiscreteIntegrator: '<S185>/Discrete-Time Integrator' */
        TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE =
          TRSC_VC_B.DiscreteTimeIntegrator;

        /* Update for Delay: '<S185>/Delay One Step' */
        for (TRSC_VC_B.idxDelay = 0; TRSC_VC_B.idxDelay < 99; TRSC_VC_B.idxDelay
             ++) {
          TRSC_VC_DW.DelayOneStep_DSTATE[TRSC_VC_B.idxDelay] =
            TRSC_VC_DW.DelayOneStep_DSTATE[TRSC_VC_B.idxDelay + 1];
        }

        TRSC_VC_DW.DelayOneStep_DSTATE[99] = TRSC_VC_B.Add_h;

        /* End of Update for Delay: '<S185>/Delay One Step' */

        /* Update for Delay: '<S185>/Delay One Step1' */
        for (TRSC_VC_B.idxDelay = 0; TRSC_VC_B.idxDelay < 99; TRSC_VC_B.idxDelay
             ++) {
          TRSC_VC_DW.DelayOneStep1_DSTATE[TRSC_VC_B.idxDelay] =
            TRSC_VC_DW.DelayOneStep1_DSTATE[TRSC_VC_B.idxDelay + 1];
        }

        TRSC_VC_DW.DelayOneStep1_DSTATE[99] = TRSC_VC_B.Gain;

        /* End of Update for Delay: '<S185>/Delay One Step1' */
      }

      /* End of Outputs for SubSystem: '<S184>/TBL_DataLog' */

      /* SignalConversion generated from: '<S177>/LogOut' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.TADvec = TRSC_VC_B.TADvec_n;

      /* SignalConversion generated from: '<S177>/LogOut' */
      TRSC_VC_B.TAD01 = TRSC_VC_B.TAD01_a;

      /* SignalConversion generated from: '<S177>/LogOut' */
      TRSC_VC_B.KeOTBL_m_HV_WheelBase = TRSC_VC_B.KeOTBL_m_HV_WheelBase_m;
    } else {
      TRSC_VC_B.Switch_f = TRSC_VC_B.Gain4;
      TRSC_VC_DW.OnlineTrailerBeamLengthEstimation_MODE = false;
    }

    /* End of Switch: '<S170>/Switch' */
    /* End of Outputs for SubSystem: '<S170>/OnlineTrailerBeamLengthEstimation' */

    /* Outputs for Atomic SubSystem: '<S170>/OTBL_Enable1' */
    TRSC_VC_OTBL_Enable1();

    /* End of Outputs for SubSystem: '<S170>/OTBL_Enable1' */

    /* Delay: '<S170>/Delay One Step1' */
    TRSC_VC_B.Compare_h = TRSC_VC_DW.DelayOneStep1_DSTATE_d;

    /* Logic: '<S170>/NOT2' */
    TRSC_VC_B.Compare_h = !TRSC_VC_B.Compare_h;

    /* Logic: '<S170>/AND1' */
    TRSC_VC_B.AND1 = (MeOTBL_b_Enable_1 && TRSC_VC_B.Compare_h);

    /* Outputs for Enabled SubSystem: '<S170>/Subsystem' incorporates:
     *  EnablePort: '<S178>/Enable'
     */
    if (MeOTBL_b_Enable_1) {
      if (!TRSC_VC_DW.Subsystem_MODE) {
        /* SystemReset for MATLAB Function: '<S178>/MATLAB Function2' */
        TRSC_VC_DW.prev_time_not_empty = false;
        TRSC_VC_DW.Subsystem_MODE = true;
      }

      /* MATLAB Function: '<S178>/MATLAB Function2' */
      TRSC_VC_B.TBL_Failed = 0.0F;
      if ((!TRSC_VC_DW.prev_time_not_empty) || TRSC_VC_B.AND1) {
        TRSC_VC_DW.prev_time = TRSC_VC_B.DiscreteTimeIntegrator;
        TRSC_VC_DW.prev_time_not_empty = true;
        for (i = 0; i < 121; i++) {
          TRSC_VC_DW.TAD_predz1[i] = TRSC_VC_B.TAD01;
          TRSC_VC_DW.errorIntVec[i] = 0.0;
        }

        TRSC_VC_DW.MaxTadAngle = 0.0F;
        TRSC_VC_DW.MaxPhiAngle = 0.0F;
      }

      TRSC_VC_B.MaxPhiAngle_out = TRSC_VC_DW.MaxPhiAngle;
      TRSC_VC_B.MaxTadAngle_out = TRSC_VC_DW.MaxTadAngle;
      TRSC_VC_B.Dt = TRSC_VC_B.DiscreteTimeIntegrator - TRSC_VC_DW.prev_time;
      TRSC_VC_B.pulse_counter_RR = fabsf(TRSC_VC_B.TADvec);
      TRSC_VC_DW.MaxTadAngle = fmaxf(TRSC_VC_B.pulse_counter_RR,
        TRSC_VC_DW.MaxTadAngle);
      TRSC_VC_DW.MaxPhiAngle = fmaxf(fabsf(TRSC_VC_B.DelayOneStep),
        TRSC_VC_DW.MaxPhiAngle);
      if (TRSC_VC_DW.MaxTadAngle < 30.0F) {
        memset(&TRSC_VC_DW.errorIntVec[0], 0, 121U * sizeof(real_T));
        TRSC_VC_B.shallowTurn_out = true;
      } else {
        TRSC_VC_B.shallowTurn_out = false;
      }

      for (TRSC_VC_B.idxDelay = 0; TRSC_VC_B.idxDelay < 121; TRSC_VC_B.idxDelay
           ++) {
        if (rtIsInfF(TRSC_VC_DW.TAD_predz1[TRSC_VC_B.idxDelay]) || rtIsNaNF
            (TRSC_VC_DW.TAD_predz1[TRSC_VC_B.idxDelay])) {
          TRSC_VC_B.absx = (rtNaNF);
          TRSC_VC_B.b_absx = (rtNaNF);
        } else {
          TRSC_VC_B.gamma_now_deg_m = rt_remf_snf
            (TRSC_VC_DW.TAD_predz1[TRSC_VC_B.idxDelay], 360.0F);
          TRSC_VC_B.absx = fabsf(TRSC_VC_B.gamma_now_deg_m);
          if (TRSC_VC_B.absx > 180.0F) {
            if (TRSC_VC_B.gamma_now_deg_m > 0.0F) {
              TRSC_VC_B.gamma_now_deg_m -= 360.0F;
            } else {
              TRSC_VC_B.gamma_now_deg_m += 360.0F;
            }

            TRSC_VC_B.absx = fabsf(TRSC_VC_B.gamma_now_deg_m);
          }

          if (TRSC_VC_B.absx <= 45.0F) {
            TRSC_VC_B.gamma_now_deg_m *= 0.0174532924F;
            n = 0;
          } else if (TRSC_VC_B.absx <= 135.0F) {
            if (TRSC_VC_B.gamma_now_deg_m > 0.0F) {
              TRSC_VC_B.gamma_now_deg_m = (TRSC_VC_B.gamma_now_deg_m - 90.0F) *
                0.0174532924F;
              n = 1;
            } else {
              TRSC_VC_B.gamma_now_deg_m = (TRSC_VC_B.gamma_now_deg_m + 90.0F) *
                0.0174532924F;
              n = -1;
            }
          } else if (TRSC_VC_B.gamma_now_deg_m > 0.0F) {
            TRSC_VC_B.gamma_now_deg_m = (TRSC_VC_B.gamma_now_deg_m - 180.0F) *
              0.0174532924F;
            n = 2;
          } else {
            TRSC_VC_B.gamma_now_deg_m = (TRSC_VC_B.gamma_now_deg_m + 180.0F) *
              0.0174532924F;
            n = -2;
          }

          switch (n) {
           case 0:
            TRSC_VC_B.absx = cosf(TRSC_VC_B.gamma_now_deg_m);
            break;

           case 1:
            TRSC_VC_B.absx = -sinf(TRSC_VC_B.gamma_now_deg_m);
            break;

           case -1:
            TRSC_VC_B.absx = sinf(TRSC_VC_B.gamma_now_deg_m);
            break;

           default:
            TRSC_VC_B.absx = -cosf(TRSC_VC_B.gamma_now_deg_m);
            break;
          }

          TRSC_VC_B.gamma_now_deg_m = rt_remf_snf
            (TRSC_VC_DW.TAD_predz1[TRSC_VC_B.idxDelay], 360.0F);
          TRSC_VC_B.b_absx = fabsf(TRSC_VC_B.gamma_now_deg_m);
          if (TRSC_VC_B.b_absx > 180.0F) {
            if (TRSC_VC_B.gamma_now_deg_m > 0.0F) {
              TRSC_VC_B.gamma_now_deg_m -= 360.0F;
            } else {
              TRSC_VC_B.gamma_now_deg_m += 360.0F;
            }

            TRSC_VC_B.b_absx = fabsf(TRSC_VC_B.gamma_now_deg_m);
          }

          if (TRSC_VC_B.b_absx <= 45.0F) {
            TRSC_VC_B.gamma_now_deg_m *= 0.0174532924F;
            n = 0;
          } else if (TRSC_VC_B.b_absx <= 135.0F) {
            if (TRSC_VC_B.gamma_now_deg_m > 0.0F) {
              TRSC_VC_B.gamma_now_deg_m = (TRSC_VC_B.gamma_now_deg_m - 90.0F) *
                0.0174532924F;
              n = 1;
            } else {
              TRSC_VC_B.gamma_now_deg_m = (TRSC_VC_B.gamma_now_deg_m + 90.0F) *
                0.0174532924F;
              n = -1;
            }
          } else if (TRSC_VC_B.gamma_now_deg_m > 0.0F) {
            TRSC_VC_B.gamma_now_deg_m = (TRSC_VC_B.gamma_now_deg_m - 180.0F) *
              0.0174532924F;
            n = 2;
          } else {
            TRSC_VC_B.gamma_now_deg_m = (TRSC_VC_B.gamma_now_deg_m + 180.0F) *
              0.0174532924F;
            n = -2;
          }

          switch (n) {
           case 0:
            TRSC_VC_B.b_absx = sinf(TRSC_VC_B.gamma_now_deg_m);
            break;

           case 1:
            TRSC_VC_B.b_absx = cosf(TRSC_VC_B.gamma_now_deg_m);
            break;

           case -1:
            TRSC_VC_B.b_absx = -cosf(TRSC_VC_B.gamma_now_deg_m);
            break;

           default:
            TRSC_VC_B.b_absx = -sinf(TRSC_VC_B.gamma_now_deg_m);
            break;
          }
        }

        TRSC_VC_B.gamma_now_deg_m = TRSC_VC_B.DelayOneStep;
        tand_brbYAlcS(&TRSC_VC_B.gamma_now_deg_m);
        TRSC_VC_B.d = TRSC_VC_B.DelayOneStep;
        tand_brbYAlcS(&TRSC_VC_B.d);
        TAD_pred_tmp = TRSC_VC_B.DelayOneStep1 / (real32_T)b[TRSC_VC_B.idxDelay];
        TRSC_VC_B.gamma_now_deg_m = ((TAD_pred_tmp * TRSC_VC_B.Gain2 /
          TRSC_VC_B.KeOTBL_m_HV_WheelBase * TRSC_VC_B.d * TRSC_VC_B.absx +
          TRSC_VC_B.DelayOneStep1 / TRSC_VC_B.KeOTBL_m_HV_WheelBase *
          TRSC_VC_B.gamma_now_deg_m) - TAD_pred_tmp * TRSC_VC_B.b_absx) * 180.0F
          / 3.14159274F * TRSC_VC_B.Dt +
          TRSC_VC_DW.TAD_predz1[TRSC_VC_B.idxDelay];
        TRSC_VC_DW.TAD_predz1[TRSC_VC_B.idxDelay] = TRSC_VC_B.gamma_now_deg_m;
        if ((TRSC_VC_B.pulse_counter_RR > 3.0F) && (TRSC_VC_B.DelayOneStep1 >
             0.5F)) {
          TRSC_VC_DW.errorIntVec[TRSC_VC_B.idxDelay] = fabsf
            (TRSC_VC_B.gamma_now_deg_m - TRSC_VC_B.TADvec) + (real32_T)
            TRSC_VC_DW.errorIntVec[TRSC_VC_B.idxDelay];
        }
      }

      TRSC_VC_DW.prev_time = TRSC_VC_B.DiscreteTimeIntegrator;
      if (!rtIsNaN(TRSC_VC_DW.errorIntVec[0])) {
        TRSC_VC_B.idxDelay = 1;
      } else {
        TRSC_VC_B.idxDelay = 0;
        TRSC_VC_B.k = 2;
        exitg1 = false;
        while ((!exitg1) && (TRSC_VC_B.k < 122)) {
          if (!rtIsNaN(TRSC_VC_DW.errorIntVec[TRSC_VC_B.k - 1])) {
            TRSC_VC_B.idxDelay = TRSC_VC_B.k;
            exitg1 = true;
          } else {
            TRSC_VC_B.k++;
          }
        }
      }

      if (TRSC_VC_B.idxDelay != 0) {
        TRSC_VC_B.ex = TRSC_VC_DW.errorIntVec[TRSC_VC_B.idxDelay - 1];
        TRSC_VC_B.k = TRSC_VC_B.idxDelay - 1;
        while (TRSC_VC_B.idxDelay + 1 <= 121) {
          if (TRSC_VC_B.ex > TRSC_VC_DW.errorIntVec[TRSC_VC_B.idxDelay]) {
            TRSC_VC_B.ex = TRSC_VC_DW.errorIntVec[TRSC_VC_B.idxDelay];
            TRSC_VC_B.k = TRSC_VC_B.idxDelay;
          }

          TRSC_VC_B.idxDelay++;
        }

        TRSC_VC_B.idxDelay = TRSC_VC_B.k;
      }

      TRSC_VC_B.ex = TRSC_VC_DW.errorIntVec[TRSC_VC_B.idxDelay];
      for (Add2_m_tmp = 0; Add2_m_tmp < 121; Add2_m_tmp++) {
        TRSC_VC_DW.errorIntVec[Add2_m_tmp] -= TRSC_VC_B.ex;
      }

      if (TRSC_VC_B.shallowTurn_out) {
        TRSC_VC_B.b_PI_k1 = 1.8F;
      } else {
        TRSC_VC_B.b_PI_k1 = (real32_T)b[TRSC_VC_B.idxDelay];
      }

      /* End of MATLAB Function: '<S178>/MATLAB Function2' */

      /* RelationalOperator: '<S187>/LowerRelop1' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.LowerRelop1 = (TRSC_VC_B.b_PI_k1 >
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_TBL_UpLimit);

      /* RelationalOperator: '<S187>/UpperRelop' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.UpperRelop = (TRSC_VC_B.b_PI_k1 <
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_TBL_LowLimit);

      /* Switch: '<S187>/Switch' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      if (TRSC_VC_B.UpperRelop) {
        TRSC_VC_B.Switch_gn =
          IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_TBL_LowLimit;
      } else {
        TRSC_VC_B.Switch_gn = TRSC_VC_B.b_PI_k1;
      }

      /* End of Switch: '<S187>/Switch' */

      /* Switch: '<S187>/Switch2' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      if (TRSC_VC_B.LowerRelop1) {
        TRSC_VC_B.Switch2_d =
          IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_m_TBL_UpLimit;
      } else {
        TRSC_VC_B.Switch2_d = TRSC_VC_B.Switch_gn;
      }

      /* End of Switch: '<S187>/Switch2' */

      /* DataStoreWrite: '<S178>/Data Store Write2' */
      TRSC_VC_DW.Online_FINAL_TBL = TRSC_VC_B.Switch2_d;
    } else {
      TRSC_VC_DW.Subsystem_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S170>/Subsystem' */

    /* RelationalOperator: '<S173>/Compare' incorporates:
     *  Constant: '<S173>/Constant'
     */
    TRSC_VC_B.Compare_h = (TRSC_VC_B.DataTypeConversion2_f == ((uint8_T)5U));

    /* Logic: '<S170>/NOT' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.AND4 =
      !IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_OBTLRecalibrate;

    /* Delay: '<S170>/Delay One Step' */
    TRSC_VC_B.Switch5_j = TRSC_VC_DW.DelayOneStep_DSTATE_d;

    /* Logic: '<S170>/AND' */
    TRSC_VC_B.AND4 = (TRSC_VC_B.AND4 && TRSC_VC_B.Switch5_j);

    /* Logic: '<S170>/AND3' */
    TRSC_VC_B.AND3 = (TRSC_VC_B.Compare_h && TRSC_VC_B.AND4);

    /* UnitDelay: '<S170>/Unit Delay1' */
    TRSC_VC_B.Switch1_f = TRSC_VC_DW.UnitDelay1_DSTATE_o;

    /* Switch: '<S170>/Switch4' */
    if (TRSC_VC_B.AND3) {
      /* DataStoreRead: '<S170>/Data Store Read3' */
      TRSC_VC_B.DataStoreRead3 = TRSC_VC_DW.Online_FINAL_TBL;
      TRSC_VC_B.Switch4 = TRSC_VC_B.DataStoreRead3;
    } else {
      TRSC_VC_B.Switch4 = TRSC_VC_B.Switch1_f;
    }

    /* End of Switch: '<S170>/Switch4' */

    /* Constant: '<S170>/EnableOTBL' */
    TRSC_VC_B.Switch1_f = OTBL_EN;

    /* Switch: '<S170>/Switch1' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    if (TRSC_VC_B.Switch1_f != 0.0F) {
      TRSC_VC_B.Switch1_f = TRSC_VC_B.Switch4;
    } else {
      TRSC_VC_B.Switch1_f = IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_m_BeamLength;
    }

    /* End of Switch: '<S170>/Switch1' */

    /* Saturate: '<S170>/Saturation4' */
    if (TRSC_VC_B.Switch1_f > 8.0F) {
      IeLSCAN_m_TrailerBeamLen = 8.0F;
    } else if (TRSC_VC_B.Switch1_f < 1.8F) {
      IeLSCAN_m_TrailerBeamLen = 1.8F;
    } else {
      IeLSCAN_m_TrailerBeamLen = TRSC_VC_B.Switch1_f;
    }

    /* End of Saturate: '<S170>/Saturation4' */

    /* UnitDelay: '<S170>/Unit Delay' */
    TRSC_VC_B.UnitDelay_m = TRSC_VC_DW.UnitDelay_DSTATE_kg;

    /* RelationalOperator: '<S171>/Compare' incorporates:
     *  Constant: '<S171>/Constant'
     */
    TRSC_VC_B.Switch5_j = (TRSC_VC_B.UnitDelay_m == ((uint8_T)5U));

    /* RelationalOperator: '<S172>/Compare' incorporates:
     *  Constant: '<S172>/Constant'
     */
    TRSC_VC_B.AND4 = (TRSC_VC_B.DataTypeConversion2_f != ((uint8_T)5U));

    /* Logic: '<S170>/AND2' */
    TRSC_VC_B.Switch5_j = (TRSC_VC_B.Switch5_j && TRSC_VC_B.AND4);

    /* Switch: '<S170>/Switch2' incorporates:
     *  Constant: '<S170>/Constant'
     */
    if (TRSC_VC_B.Switch5_j) {
      TRSC_VC_B.AND4 = (0.0 != 0.0);
    } else {
      /* DataStoreRead: '<S170>/Data Store Read1' */
      TRSC_VC_B.DataStoreRead1 = TRSC_VC_DW.TBLComputationDone;
      TRSC_VC_B.AND4 = TRSC_VC_B.DataStoreRead1;
    }

    /* End of Switch: '<S170>/Switch2' */

    /* DataStoreWrite: '<S170>/Data Store Write' */
    TRSC_VC_DW.TBLComputationDone = TRSC_VC_B.AND4;

    /* Delay: '<S170>/Delay One Step2' */
    TRSC_VC_B.AND4 = TRSC_VC_DW.DelayOneStep2_DSTATE;

    /* Logic: '<S170>/NOT1' */
    TRSC_VC_B.AND4 = !TRSC_VC_B.AND4;

    /* Logic: '<S170>/AND4' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.AND4 =
      (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_OBTLRecalibrate &&
       TRSC_VC_B.AND4);

    /* Logic: '<S170>/AND5' */
    TRSC_VC_B.Switch5_j = (TRSC_VC_B.Switch5_j || TRSC_VC_B.AND4);

    /* Switch: '<S170>/Switch5' incorporates:
     *  Constant: '<S170>/Constant2'
     */
    if (TRSC_VC_B.Switch5_j) {
      TRSC_VC_B.Switch5_j = false;
    } else {
      /* DataStoreRead: '<S170>/Data Store Read4' */
      TRSC_VC_B.DataStoreRead4 = TRSC_VC_DW.OTBLReset;
      TRSC_VC_B.Switch5_j = TRSC_VC_B.DataStoreRead4;
    }

    /* End of Switch: '<S170>/Switch5' */

    /* DataStoreWrite: '<S170>/Data Store Write1' */
    TRSC_VC_DW.OTBLReset = TRSC_VC_B.Switch5_j;

    /* Outputs for Enabled SubSystem: '<S170>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S174>/Enable'
     */
    if (TRSC_VC_B.AND3) {
      /* Logic: '<S174>/Logical Operator' */
      TRSC_VC_B.LogicalOperator1_a = !TRSC_VC_B.shallowTurn_out;

      /* Switch: '<S174>/Switch' incorporates:
       *  Constant: '<S174>/Constant'
       *  Constant: '<S174>/Constant1'
       */
      if (TRSC_VC_B.LogicalOperator1_a) {
        TRSC_VC_B.LogicalOperator1_a = true;
      } else {
        TRSC_VC_B.LogicalOperator1_a = false;
      }

      /* End of Switch: '<S174>/Switch' */

      /* DataStoreWrite: '<S174>/Data Store Write1' */
      TRSC_VC_DW.TBLComputationDone = TRSC_VC_B.LogicalOperator1_a;

      /* Logic: '<S174>/Logical Operator1' */
      TRSC_VC_B.LogicalOperator1_a = !TRSC_VC_B.LogicalOperator1_a;

      /* DataStoreWrite: '<S174>/Data Store Write2' */
      TRSC_VC_DW.OTBLReset = TRSC_VC_B.LogicalOperator1_a;
    }

    /* End of Outputs for SubSystem: '<S170>/Enabled Subsystem' */

    /* DataStoreRead: '<S170>/Data Store Read2' */
    TRSC_VC_B.DataStoreRead2 = TRSC_VC_DW.TBLComputationDone;

    /* DataStoreRead: '<S170>/Data Store Read' */
    TRSC_VC_B.DataStoreRead = TRSC_VC_DW.OTBLReset;

    /* Update for Delay: '<S170>/Delay2' */
    TRSC_VC_DW.Delay2_DSTATE = TRSC_VC_B.Switch_f;

    /* Update for Delay: '<S170>/Delay One Step1' */
    TRSC_VC_DW.DelayOneStep1_DSTATE_d = MeOTBL_b_Enable_1;

    /* Update for Delay: '<S170>/Delay One Step' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_DW.DelayOneStep_DSTATE_d =
      IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_OBTLRecalibrate;

    /* Update for UnitDelay: '<S170>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_DSTATE_o = TRSC_VC_B.Switch4;

    /* Update for UnitDelay: '<S170>/Unit Delay' */
    TRSC_VC_DW.UnitDelay_DSTATE_kg = TRSC_VC_B.DataTypeConversion2_f;

    /* Update for Delay: '<S170>/Delay One Step2' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_DW.DelayOneStep2_DSTATE =
      IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_OBTLRecalibrate;

    /* End of Outputs for S-Function (fcncallgen): '<S18>/Function-Call Generator' */
  } else {
    if (TRSC_VC_DW.TrailerBeamLength1_MODE) {
      /* Disable for S-Function (fcncallgen): '<S18>/Function-Call Generator' incorporates:
       *  SubSystem: '<S18>/Subsystem'
       */
      /* Disable for Enabled SubSystem: '<S170>/OnlineTrailerBeamLengthEstimation' */
      TRSC_VC_DW.OnlineTrailerBeamLengthEstimation_MODE = false;

      /* End of Disable for SubSystem: '<S170>/OnlineTrailerBeamLengthEstimation' */

      /* Disable for Enabled SubSystem: '<S170>/Subsystem' */
      TRSC_VC_DW.Subsystem_MODE = false;

      /* End of Disable for SubSystem: '<S170>/Subsystem' */
      /* End of Disable for S-Function (fcncallgen): '<S18>/Function-Call Generator' */
      TRSC_VC_DW.TrailerBeamLength1_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/Trailer Beam Length1' */

  /* DataTypeConversion: '<S1>/Data Type Conversion12' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.DataTypeConversion12 =
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  TRSC_VC_B.Compare = (TRSC_VC_B.DataTypeConversion12 ==
                       TeTRSC_e_TrlrCalInfo_Calibrated);

  /* Abs: '<S45>/Abs' incorporates:
   *  Constant: '<S1>/KeTRSC_m_HitchLength_HD2'
   */
  TRSC_VC_B.Product_DesiredTAD = KeTRSC_b_HardcodeTBLflag;

  /* Switch: '<S1>/Switch6' incorporates:
   *  Constant: '<S1>/KeTRSC_m_HitchLength_HD3'
   *  Switch: '<S1>/Switch'
   */
  if (TRSC_VC_B.Product_DesiredTAD != 0.0F) {
    TRSC_VC_B.Switch6 = KeTRSC_m_HardcodedTBL;
  } else {
    if (TRSC_VC_B.Compare) {
      /* DataTypeConversion: '<S1>/Data Type Conversion7' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       *  Switch: '<S1>/Switch'
       */
      TRSC_VC_B.DataTypeConversion7 =
        IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_m_DetTrailerBeamLen;

      /* Switch: '<S1>/Switch' */
      TRSC_VC_B.Switch_k = TRSC_VC_B.DataTypeConversion7;
    } else {
      /* Switch: '<S1>/Switch' */
      TRSC_VC_B.Switch_k = IeLSCAN_m_TrailerBeamLen;
    }

    TRSC_VC_B.Switch6 = TRSC_VC_B.Switch_k;
  }

  /* End of Switch: '<S1>/Switch6' */

  /* Gain: '<S1>/Gain3' */
  TRSC_VC_B.Gain3 = 0.92F * TRSC_VC_B.Add;

  /* SignalConversion generated from: '<S1>/Trailer Beam Length1' */
  MeTRSC_b_TBLComputationDone = TRSC_VC_B.DataStoreRead2;

  /* UnitDelay: '<S1>/Unit Delay2' */
  TRSC_VC_B.Compare_mp = TRSC_VC_DW.UnitDelay2_DSTATE_o;

  /* Logic: '<S1>/NOT4' */
  TRSC_VC_B.Compare_mp = !TRSC_VC_B.Compare_mp;

  /* Logic: '<S1>/AND2' */
  TRSC_VC_B.Compare_mp = (MeTRSC_b_TBLComputationDone && TRSC_VC_B.Compare_mp);

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Constant: '<S1>/Constant15'
   */
  TRSC_VC_B.LogicalOperator1 = (KeTRSC_b_ForceJKCalc || TRSC_VC_B.Compare_mp);

  /* Outputs for Enabled SubSystem: '<S1>/JackKnife Angle ' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (TRSC_VC_B.LogicalOperator1) {
    /* Delay: '<S7>/Delay' incorporates:
     *  Constant: '<S7>/MaxFrontAngle2'
     */
    if (TRSC_VC_DW.icLoad_m != 0) {
      TRSC_VC_DW.Delay_DSTATE_i = 40.3391418F;
    }

    TRSC_VC_B.Delay_n = TRSC_VC_DW.Delay_DSTATE_i;

    /* End of Delay: '<S7>/Delay' */

    /* Delay: '<S7>/Delay2' */
    TRSC_VC_B.Delay2 = TRSC_VC_DW.Delay2_DSTATE_k;

    /* UnitDelay: '<S20>/Delay Input1'
     *
     * Block description for '<S20>/Delay Input1':
     *
     *  Store in Global RAM
     */
    TRSC_VC_B.u1wN = TRSC_VC_DW.DelayInput1_DSTATE;

    /* RelationalOperator: '<S20>/FixPt Relational Operator' */
    TRSC_VC_B.FixPtRelationalOperator_b = (TRSC_VC_B.Switch6 != TRSC_VC_B.u1wN);

    /* MATLAB Function: '<S7>/MATLAB Function1' incorporates:
     *  Constant: '<S1>/Constant15'
     */
    if (TRSC_VC_B.FixPtRelationalOperator_b || TRSC_VC_B.Delay2 ||
        KeTRSC_b_ForceJKCalc) {
      TRSC_VC_B.Dt = fabsf(TRSC_VC_B.Gain2 - 0.03F);
      TRSC_VC_B.pulse_counter_RR = TRSC_VC_B.Gain3;
      tand_brbYAlcS(&TRSC_VC_B.pulse_counter_RR);
      TRSC_VC_B.absx = TRSC_VC_B.Gain3;
      tand_brbYAlcS(&TRSC_VC_B.absx);
      TRSC_VC_B.gamma_now_deg_m = TRSC_VC_B.Gain3;
      tand_brbYAlcS(&TRSC_VC_B.gamma_now_deg_m);
      TRSC_VC_B.JackKnifeAngle = fabsf(asinf(fmaxf(fminf(fmaxf(fabsf
        (TRSC_VC_B.Switch6 - 0.5F), 2.0F) * TRSC_VC_B.absx / sqrtf(TRSC_VC_B.Dt *
        TRSC_VC_B.Dt * (TRSC_VC_B.pulse_counter_RR * TRSC_VC_B.pulse_counter_RR)
        + TRSC_VC_B.Switch2 * TRSC_VC_B.Switch2), 1.0F), -1.0F)) * 57.2957802F -
        atanf(-TRSC_VC_B.Dt * TRSC_VC_B.gamma_now_deg_m / TRSC_VC_B.Switch2) *
        57.2957802F);
    } else {
      TRSC_VC_B.JackKnifeAngle = TRSC_VC_B.Delay_n;
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function1' */

    /* RelationalOperator: '<S22>/LowerRelop1' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.JackKnifeAngle >
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_JKAngle_UpLimit);

    /* RelationalOperator: '<S22>/UpperRelop' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.JackKnifeAngle <
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_JKAngle_LowLimit);

    /* Switch: '<S22>/Switch' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    if (TRSC_VC_B.RelationalOperator1_e) {
      TRSC_VC_B.Switch_n =
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_JKAngle_LowLimit;
    } else {
      TRSC_VC_B.Switch_n = TRSC_VC_B.JackKnifeAngle;
    }

    /* End of Switch: '<S22>/Switch' */

    /* Switch: '<S22>/Switch2' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    if (TRSC_VC_B.LogicalOperator_c) {
      JackKnifeAngle_deg =
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_JKAngle_UpLimit;
    } else {
      JackKnifeAngle_deg = TRSC_VC_B.Switch_n;
    }

    /* End of Switch: '<S22>/Switch2' */

    /* Update for Delay: '<S7>/Delay' */
    TRSC_VC_DW.icLoad_m = 0U;
    TRSC_VC_DW.Delay_DSTATE_i = JackKnifeAngle_deg;

    /* Update for Delay: '<S7>/Delay2' */
    TRSC_VC_DW.Delay2_DSTATE_k = TRSC_VC_B.FixPtRelationalOperator_b;

    /* Update for UnitDelay: '<S20>/Delay Input1'
     *
     * Block description for '<S20>/Delay Input1':
     *
     *  Store in Global RAM
     */
    TRSC_VC_DW.DelayInput1_DSTATE = TRSC_VC_B.Switch6;
  }

  /* End of Outputs for SubSystem: '<S1>/JackKnife Angle ' */

  /* Logic: '<S1>/Logical Operator4' incorporates:
   *  Constant: '<S1>/Constant15'
   */
  TRSC_VC_B.Compare_mp = !KeTRSC_b_ForceJKCalc;

  /* Logic: '<S1>/Logical Operator5' */
  TRSC_VC_B.Compare_mp = (TRSC_VC_B.Compare && TRSC_VC_B.Compare_mp);

  /* Switch: '<S1>/Switch1' */
  if (TRSC_VC_B.Compare_mp) {
    /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.DataTypeConversion8 =
      IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_DetJackKnifeAngle;
    TRSC_VC_B.Switch1 = TRSC_VC_B.DataTypeConversion8;
  } else {
    TRSC_VC_B.Switch1 = JackKnifeAngle_deg;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* RelationalOperator: '<S15>/LowerRelop1' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_mp = (TRSC_VC_B.Switch1 >
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxTrlrAngl);

  /* RelationalOperator: '<S15>/UpperRelop' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  TRSC_VC_B.Compare_m = (TRSC_VC_B.Switch1 < KeTRSC_deg_Zero);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  if (TRSC_VC_B.Compare_m) {
    TRSC_VC_B.Switch_b = KeTRSC_deg_Zero;
  } else {
    TRSC_VC_B.Switch_b = TRSC_VC_B.Switch1;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Switch: '<S15>/Switch2' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_VC_B.Compare_mp) {
    TRSC_VC_B.Switch2_c =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxTrlrAngl;
  } else {
    TRSC_VC_B.Switch2_c = TRSC_VC_B.Switch_b;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* RelationalOperator: '<S193>/Compare' incorporates:
   *  Constant: '<S193>/Constant'
   */
  TRSC_VC_B.Compare_mp = (*rtu_MeTRSC_e_TRSCStat == TeTRSC_e_TRSCStat_Active);

  /* RelationalOperator: '<S189>/Compare' incorporates:
   *  Constant: '<S189>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_m =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
     TeVBII_e_GearEngagedForDsply_R);

  /* Logic: '<S19>/Logical Operator5' */
  TRSC_VC_B.RelationalOperator_e = !TRSC_VC_B.Compare_m;

  /* UnitDelay: '<S195>/UnitDelay3' */
  TRSC_VC_B.Sum_h = TRSC_VC_B.MinMax;

  /* Switch: '<S195>/Switch1' incorporates:
   *  Constant: '<S195>/Constant4'
   */
  if (TRSC_VC_B.RelationalOperator_e) {
    TRSC_VC_B.Sum_h = 0.0;
  }

  /* End of Switch: '<S195>/Switch1' */

  /* Sum: '<S195>/Sum1' incorporates:
   *  Constant: '<S19>/Constant3'
   */
  TRSC_VC_B.Sum1 = 0.35 - TRSC_VC_B.Sum_h;

  /* Gain: '<S195>/Gain' incorporates:
   *  Constant: '<S19>/Constant2'
   */
  TRSC_VC_B.Switch3 = 0.99 * 0.03;

  /* RelationalOperator: '<S195>/Relational Operator' */
  TRSC_VC_B.RelationalOperator_e = (TRSC_VC_B.Sum1 < TRSC_VC_B.Switch3);

  /* RelationalOperator: '<S194>/Compare' incorporates:
   *  Constant: '<S194>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_fv =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
     TeVBII_e_StrTrqResp_Active);

  /* RelationalOperator: '<S190>/Compare' incorporates:
   *  Constant: '<S190>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.LogicalOperator_g =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
     TeVBII_e_EngineSts_Engine_Off);

  /* RelationalOperator: '<S191>/Compare' incorporates:
   *  Constant: '<S191>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.RelationalOperator1_f =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
     TeVBII_e_EngineSts_Engine_On);

  /* RelationalOperator: '<S192>/Compare' incorporates:
   *  Constant: '<S192>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.LogicalOperator1_fq =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
     TeVBII_e_EngineSts_Engine_Cranking);

  /* Logic: '<S19>/Logical Operator' */
  TRSC_VC_B.LogicalOperator_g = (TRSC_VC_B.LogicalOperator_g ||
    TRSC_VC_B.RelationalOperator1_f || TRSC_VC_B.LogicalOperator1_fq);

  /* Logic: '<S19>/Logical Operator1' */
  MeTRSC_b_TRAAct = (TRSC_VC_B.Compare_mp && TRSC_VC_B.RelationalOperator_e &&
                     TRSC_VC_B.Compare_fv && TRSC_VC_B.LogicalOperator_g);

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.DataTypeConversion_j = (int16_T)
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_k_KnobAngl;

  /* UnitDelay: '<S9>/Unit Delay1' */
  TRSC_VC_B.UnitDelay1_j = TRSC_VC_DW.UnitDelay1_DSTATE_g;

  /* RelationalOperator: '<S102>/LowerRelop1' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant3'
   */
  TRSC_VC_B.LogicalOperator1_fq = (KeTRSC_k_MaxJumpSize >
    CeTRSC_k_MaxJumpSizeUpLim);

  /* RelationalOperator: '<S102>/UpperRelop' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant4'
   */
  TRSC_VC_B.RelationalOperator1_f = (KeTRSC_k_MaxJumpSize <
    CeTRSC_k_MaxJumpSizeLowLim);

  /* Switch: '<S102>/Switch' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant4'
   */
  if (TRSC_VC_B.RelationalOperator1_f) {
    TRSC_VC_B.Switch_nf = CeTRSC_k_MaxJumpSizeLowLim;
  } else {
    TRSC_VC_B.Switch_nf = KeTRSC_k_MaxJumpSize;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Switch: '<S102>/Switch2' incorporates:
   *  Constant: '<S9>/Constant3'
   */
  if (TRSC_VC_B.LogicalOperator1_fq) {
    TRSC_VC_B.Switch2_kvh = CeTRSC_k_MaxJumpSizeUpLim;
  } else {
    TRSC_VC_B.Switch2_kvh = TRSC_VC_B.Switch_nf;
  }

  /* End of Switch: '<S102>/Switch2' */

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  TRSC_VC_B.DataTypeConversion1_g = (int16_T)TRSC_VC_B.Switch2_kvh;

  /* RelationalOperator: '<S103>/LowerRelop1' incorporates:
   *  Constant: '<S9>/Constant5'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.LogicalOperator1_fq =
    (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxKnobAngle >
     CeTRSC_deg_MaxKnobAngleUpLim);

  /* RelationalOperator: '<S103>/UpperRelop' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.RelationalOperator1_f =
    (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxKnobAngle <
     CeTRSC_deg_MaxKnobAngleLowLim);

  /* Switch: '<S103>/Switch' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_VC_B.RelationalOperator1_f) {
    TRSC_VC_B.Switch_o = CeTRSC_deg_MaxKnobAngleLowLim;
  } else {
    TRSC_VC_B.Switch_o =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxKnobAngle;
  }

  /* End of Switch: '<S103>/Switch' */

  /* Switch: '<S103>/Switch2' incorporates:
   *  Constant: '<S9>/Constant5'
   */
  if (TRSC_VC_B.LogicalOperator1_fq) {
    TRSC_VC_B.Switch2_m = CeTRSC_deg_MaxKnobAngleUpLim;
  } else {
    TRSC_VC_B.Switch2_m = TRSC_VC_B.Switch_o;
  }

  /* End of Switch: '<S103>/Switch2' */

  /* DataTypeConversion: '<S9>/Data Type Conversion4' */
  TRSC_VC_B.gamma_now_deg_m = floorf(TRSC_VC_B.Switch2_m);
  if (rtIsNaNF(TRSC_VC_B.gamma_now_deg_m) || rtIsInfF(TRSC_VC_B.gamma_now_deg_m))
  {
    TRSC_VC_B.gamma_now_deg_m = 0.0F;
  } else {
    TRSC_VC_B.gamma_now_deg_m = fmodf(TRSC_VC_B.gamma_now_deg_m, 65536.0F);
  }

  TRSC_VC_B.DataTypeConversion4 = (int16_T)(TRSC_VC_B.gamma_now_deg_m < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-TRSC_VC_B.gamma_now_deg_m : (int32_T)
    (int16_T)(uint16_T)TRSC_VC_B.gamma_now_deg_m);

  /* End of DataTypeConversion: '<S9>/Data Type Conversion4' */

  /* RelationalOperator: '<S98>/Compare' incorporates:
   *  Constant: '<S98>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_b =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CenterBtnSts ==
     TeVBII_e_CenterBtnSts_Pressed);

  /* UnitDelay: '<S9>/Unit Delay2' */
  TRSC_VC_B.LogicalOperator1_fq = TRSC_VC_DW.UnitDelay2_DSTATE_a;

  /* Logic: '<S9>/NOT4' */
  TRSC_VC_B.LogicalOperator1_fq = !TRSC_VC_B.LogicalOperator1_fq;

  /* Logic: '<S9>/AND2' */
  TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.Compare_b &&
    TRSC_VC_B.LogicalOperator1_fq);

  /* Logic: '<S9>/NOT2' */
  TRSC_VC_B.LogicalOperator1_fq = !TRSC_VC_B.LogicalOperator1_fq;

  /* UnitDelay: '<S9>/Unit Delay' */
  TRSC_VC_B.RelationalOperator1_f = TRSC_VC_DW.UnitDelay_DSTATE_n;

  /* Logic: '<S9>/NOT' */
  TRSC_VC_B.RelationalOperator1_f = !TRSC_VC_B.RelationalOperator1_f;

  /* Logic: '<S9>/AND1' */
  TRSC_VC_B.RelationalOperator1_f = (MeTRSC_b_TRAAct &&
    TRSC_VC_B.RelationalOperator1_f);

  /* Logic: '<S9>/NOT3' */
  TRSC_VC_B.RelationalOperator1_f = !TRSC_VC_B.RelationalOperator1_f;

  /* Logic: '<S9>/AND' */
  TRSC_VC_B.AND = (TRSC_VC_B.LogicalOperator1_fq &&
                   TRSC_VC_B.RelationalOperator1_f);

  /* Outputs for Enabled SubSystem: '<S9>/KnobAngleComp' incorporates:
   *  EnablePort: '<S100>/Enable'
   */
  if (TRSC_VC_B.AND) {
    if (!TRSC_VC_DW.KnobAngleComp_MODE) {
      /* SystemReset for Chart: '<S100>/KnobAngle' */
      TRSC_VC_DW.is_active_c1_TRSC_VC = 0U;
      TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn = 0;
      TRSC_VC_DW.i = 0U;
      TRSC_VC_DW.j = 0U;
      TRSC_VC_DW.Prev_knob_up_change_flg = false;
      TRSC_VC_DW.Prev_knob_dwn_change_flg = false;
      TRSC_VC_DW.Prev_Change_In_Dir = 0;
      TRSC_VC_B.Rotary_Encoder_Btn = 0;
      TRSC_VC_B.Change_In_Dir = 0;
      TRSC_VC_B.knob_up_change_flg = 0.0F;
      TRSC_VC_B.knob_dwn_change_flg = 0.0F;
      TRSC_VC_B.Change_In_Dir_Flag = 0.0F;
      TRSC_VC_DW.KnobAngleComp_MODE = true;
    }

    /* Chart: '<S100>/KnobAngle' */
    if (TRSC_VC_DW.is_active_c1_TRSC_VC == 0U) {
      TRSC_VC_DW.is_active_c1_TRSC_VC = 1U;
      TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn = TRSC_VC_B.UnitDelay1_j;
      TRSC_VC_B.knob_up_change_flg = 0.0F;
      TRSC_VC_B.knob_dwn_change_flg = 0.0F;
      TRSC_VC_DW.Prev_knob_up_change_flg = false;
      TRSC_VC_DW.Prev_knob_dwn_change_flg = false;
      TRSC_VC_DW.Prev_Change_In_Dir = 0;
      TRSC_VC_B.Change_In_Dir_Flag = 0.0F;
      Add2_m_tmp = TRSC_VC_B.DataTypeConversion_j -
        TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
      Selector2_tmp = 360 - TRSC_VC_B.DataTypeConversion1_g;
      if (((TRSC_VC_B.DataTypeConversion_j >
            TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn) &&
           (TRSC_VC_B.knob_up_change_flg == 0.0F)) || (Add2_m_tmp >=
           Selector2_tmp)) {
        if (Add2_m_tmp >= Selector2_tmp) {
          TRSC_VC_B.knob_up_change_flg = 0.0F;
          TRSC_VC_B.knob_dwn_change_flg = 1.0F;
          if (TRSC_VC_DW.Prev_knob_up_change_flg &&
              (!TRSC_VC_DW.Prev_knob_dwn_change_flg)) {
            TRSC_VC_B.Change_In_Dir_Flag = 1.0F;
            TRSC_VC_B.Change_In_Dir = TRSC_VC_B.Rotary_Encoder_Btn;
          } else {
            TRSC_VC_B.Change_In_Dir = TRSC_VC_DW.Prev_Change_In_Dir;
          }

          Add2_m_tmp = ((TRSC_VC_B.Rotary_Encoder_Btn +
                         TRSC_VC_B.DataTypeConversion_j) -
                        TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn) - 360;
          if (Add2_m_tmp > 32767) {
            Add2_m_tmp = 32767;
          } else {
            if (Add2_m_tmp < -32768) {
              Add2_m_tmp = -32768;
            }
          }

          TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          TRSC_VC_DW.j = 0U;
          if (TRSC_VC_B.Rotary_Encoder_Btn < -TRSC_VC_B.DataTypeConversion4) {
            Add2_m_tmp = -TRSC_VC_B.DataTypeConversion4;
            if (Add2_m_tmp > 32767) {
              Add2_m_tmp = 32767;
            }

            TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          }
        } else {
          TRSC_VC_B.knob_up_change_flg = 1.0F;
          TRSC_VC_B.knob_dwn_change_flg = 0.0F;
          if ((!TRSC_VC_DW.Prev_knob_up_change_flg) &&
              TRSC_VC_DW.Prev_knob_dwn_change_flg) {
            TRSC_VC_B.Change_In_Dir_Flag = 1.0F;
            TRSC_VC_B.Change_In_Dir = TRSC_VC_B.Rotary_Encoder_Btn;
          } else {
            TRSC_VC_B.Change_In_Dir = TRSC_VC_DW.Prev_Change_In_Dir;
          }

          Add2_m_tmp = (TRSC_VC_B.Rotary_Encoder_Btn +
                        TRSC_VC_B.DataTypeConversion_j) -
            TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
          if (Add2_m_tmp > 32767) {
            Add2_m_tmp = 32767;
          } else {
            if (Add2_m_tmp < -32768) {
              Add2_m_tmp = -32768;
            }
          }

          TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          TRSC_VC_DW.i = 0U;
          if (TRSC_VC_B.Rotary_Encoder_Btn > TRSC_VC_B.DataTypeConversion4) {
            TRSC_VC_B.Rotary_Encoder_Btn = TRSC_VC_B.DataTypeConversion4;
          }
        }
      } else {
        if ((TRSC_VC_B.knob_up_change_flg == 1.0F) &&
            (TRSC_VC_B.DataTypeConversion_j >
             TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn)) {
          Add2_m_tmp = TRSC_VC_DW.i + 1;
          if (Add2_m_tmp > 65535) {
            Add2_m_tmp = 65535;
          }

          TRSC_VC_DW.i = (uint16_T)Add2_m_tmp;
          if (TRSC_VC_DW.i > 0) {
            Add2_m_tmp = (TRSC_VC_B.Rotary_Encoder_Btn +
                          TRSC_VC_B.DataTypeConversion_j) -
              TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
            if (Add2_m_tmp > 32767) {
              Add2_m_tmp = 32767;
            } else {
              if (Add2_m_tmp < -32768) {
                Add2_m_tmp = -32768;
              }
            }

            TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
            TRSC_VC_DW.i = 0U;
            if (TRSC_VC_B.Rotary_Encoder_Btn > TRSC_VC_B.DataTypeConversion4) {
              TRSC_VC_B.Rotary_Encoder_Btn = TRSC_VC_B.DataTypeConversion4;
            }
          }
        }
      }

      Add2_m_tmp = TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn -
        TRSC_VC_B.DataTypeConversion_j;
      if (((TRSC_VC_B.DataTypeConversion_j <
            TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn) &&
           (TRSC_VC_B.knob_dwn_change_flg == 0.0F)) || (Add2_m_tmp >=
           Selector2_tmp)) {
        if (Add2_m_tmp >= Selector2_tmp) {
          TRSC_VC_B.knob_up_change_flg = 1.0F;
          TRSC_VC_B.knob_dwn_change_flg = 0.0F;
          if ((!TRSC_VC_DW.Prev_knob_up_change_flg) &&
              TRSC_VC_DW.Prev_knob_dwn_change_flg) {
            TRSC_VC_B.Change_In_Dir_Flag = 1.0F;
            TRSC_VC_B.Change_In_Dir = TRSC_VC_B.Rotary_Encoder_Btn;
          } else {
            TRSC_VC_B.Change_In_Dir = TRSC_VC_DW.Prev_Change_In_Dir;
          }

          Add2_m_tmp = ((TRSC_VC_B.Rotary_Encoder_Btn +
                         TRSC_VC_B.DataTypeConversion_j) -
                        TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn) + 360;
          if (Add2_m_tmp > 32767) {
            Add2_m_tmp = 32767;
          } else {
            if (Add2_m_tmp < -32768) {
              Add2_m_tmp = -32768;
            }
          }

          TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          TRSC_VC_DW.i = 0U;
          if (TRSC_VC_B.Rotary_Encoder_Btn > TRSC_VC_B.DataTypeConversion4) {
            TRSC_VC_B.Rotary_Encoder_Btn = TRSC_VC_B.DataTypeConversion4;
          }
        } else {
          TRSC_VC_B.knob_dwn_change_flg = 1.0F;
          TRSC_VC_B.knob_up_change_flg = 0.0F;
          if (TRSC_VC_DW.Prev_knob_up_change_flg &&
              (!TRSC_VC_DW.Prev_knob_dwn_change_flg)) {
            TRSC_VC_B.Change_In_Dir_Flag = 1.0F;
            TRSC_VC_B.Change_In_Dir = TRSC_VC_B.Rotary_Encoder_Btn;
          } else {
            TRSC_VC_B.Change_In_Dir = TRSC_VC_DW.Prev_Change_In_Dir;
          }

          Add2_m_tmp = (TRSC_VC_B.Rotary_Encoder_Btn +
                        TRSC_VC_B.DataTypeConversion_j) -
            TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
          if (Add2_m_tmp > 32767) {
            Add2_m_tmp = 32767;
          } else {
            if (Add2_m_tmp < -32768) {
              Add2_m_tmp = -32768;
            }
          }

          TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          TRSC_VC_DW.j = 0U;
          if (TRSC_VC_B.Rotary_Encoder_Btn < -TRSC_VC_B.DataTypeConversion4) {
            Add2_m_tmp = -TRSC_VC_B.DataTypeConversion4;
            if (Add2_m_tmp > 32767) {
              Add2_m_tmp = 32767;
            }

            TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          }
        }
      } else {
        if ((TRSC_VC_B.knob_dwn_change_flg == 1.0F) &&
            (TRSC_VC_B.DataTypeConversion_j <
             TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn)) {
          Add2_m_tmp = TRSC_VC_DW.j + 1;
          if (Add2_m_tmp > 65535) {
            Add2_m_tmp = 65535;
          }

          TRSC_VC_DW.j = (uint16_T)Add2_m_tmp;
          if (TRSC_VC_DW.j > 0) {
            Add2_m_tmp = (TRSC_VC_B.Rotary_Encoder_Btn +
                          TRSC_VC_B.DataTypeConversion_j) -
              TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
            if (Add2_m_tmp > 32767) {
              Add2_m_tmp = 32767;
            } else {
              if (Add2_m_tmp < -32768) {
                Add2_m_tmp = -32768;
              }
            }

            TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
            TRSC_VC_DW.j = 0U;
            if (TRSC_VC_B.Rotary_Encoder_Btn < -TRSC_VC_B.DataTypeConversion4) {
              Add2_m_tmp = -TRSC_VC_B.DataTypeConversion4;
              if (Add2_m_tmp > 32767) {
                Add2_m_tmp = 32767;
              }

              TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
            }
          }
        }
      }

      TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn = TRSC_VC_B.DataTypeConversion_j;
      TRSC_VC_DW.Prev_knob_up_change_flg = (TRSC_VC_B.knob_up_change_flg != 0.0F);
      TRSC_VC_DW.Prev_knob_dwn_change_flg = (TRSC_VC_B.knob_dwn_change_flg !=
        0.0F);
      TRSC_VC_DW.Prev_Change_In_Dir = TRSC_VC_B.Change_In_Dir;
    } else {
      Add2_m_tmp = TRSC_VC_B.DataTypeConversion_j -
        TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
      Selector2_tmp = 360 - TRSC_VC_B.DataTypeConversion1_g;
      if (((TRSC_VC_B.DataTypeConversion_j >
            TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn) &&
           (TRSC_VC_B.knob_up_change_flg == 0.0F)) || (Add2_m_tmp >=
           Selector2_tmp)) {
        if (Add2_m_tmp >= Selector2_tmp) {
          TRSC_VC_B.knob_up_change_flg = 0.0F;
          TRSC_VC_B.knob_dwn_change_flg = 1.0F;
          if (TRSC_VC_DW.Prev_knob_up_change_flg &&
              (!TRSC_VC_DW.Prev_knob_dwn_change_flg)) {
            TRSC_VC_B.Change_In_Dir_Flag = 1.0F;
            TRSC_VC_B.Change_In_Dir = TRSC_VC_B.Rotary_Encoder_Btn;
          } else {
            TRSC_VC_B.Change_In_Dir = TRSC_VC_DW.Prev_Change_In_Dir;
          }

          Add2_m_tmp = ((TRSC_VC_B.Rotary_Encoder_Btn +
                         TRSC_VC_B.DataTypeConversion_j) -
                        TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn) - 360;
          if (Add2_m_tmp > 32767) {
            Add2_m_tmp = 32767;
          } else {
            if (Add2_m_tmp < -32768) {
              Add2_m_tmp = -32768;
            }
          }

          TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          TRSC_VC_DW.j = 0U;
          if (TRSC_VC_B.Rotary_Encoder_Btn < -TRSC_VC_B.DataTypeConversion4) {
            Add2_m_tmp = -TRSC_VC_B.DataTypeConversion4;
            if (Add2_m_tmp > 32767) {
              Add2_m_tmp = 32767;
            }

            TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          }
        } else {
          TRSC_VC_B.knob_up_change_flg = 1.0F;
          TRSC_VC_B.knob_dwn_change_flg = 0.0F;
          if ((!TRSC_VC_DW.Prev_knob_up_change_flg) &&
              TRSC_VC_DW.Prev_knob_dwn_change_flg) {
            TRSC_VC_B.Change_In_Dir_Flag = 1.0F;
            TRSC_VC_B.Change_In_Dir = TRSC_VC_B.Rotary_Encoder_Btn;
          } else {
            TRSC_VC_B.Change_In_Dir = TRSC_VC_DW.Prev_Change_In_Dir;
          }

          Add2_m_tmp = (TRSC_VC_B.Rotary_Encoder_Btn +
                        TRSC_VC_B.DataTypeConversion_j) -
            TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
          if (Add2_m_tmp > 32767) {
            Add2_m_tmp = 32767;
          } else {
            if (Add2_m_tmp < -32768) {
              Add2_m_tmp = -32768;
            }
          }

          TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          TRSC_VC_DW.i = 0U;
          if (TRSC_VC_B.Rotary_Encoder_Btn > TRSC_VC_B.DataTypeConversion4) {
            TRSC_VC_B.Rotary_Encoder_Btn = TRSC_VC_B.DataTypeConversion4;
          }
        }
      } else {
        if ((TRSC_VC_B.knob_up_change_flg == 1.0F) &&
            (TRSC_VC_B.DataTypeConversion_j >
             TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn)) {
          Add2_m_tmp = TRSC_VC_DW.i + 1;
          if (Add2_m_tmp > 65535) {
            Add2_m_tmp = 65535;
          }

          TRSC_VC_DW.i = (uint16_T)Add2_m_tmp;
          if (TRSC_VC_DW.i > 0) {
            Add2_m_tmp = (TRSC_VC_B.Rotary_Encoder_Btn +
                          TRSC_VC_B.DataTypeConversion_j) -
              TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
            if (Add2_m_tmp > 32767) {
              Add2_m_tmp = 32767;
            } else {
              if (Add2_m_tmp < -32768) {
                Add2_m_tmp = -32768;
              }
            }

            TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
            TRSC_VC_DW.i = 0U;
            if (TRSC_VC_B.Rotary_Encoder_Btn > TRSC_VC_B.DataTypeConversion4) {
              TRSC_VC_B.Rotary_Encoder_Btn = TRSC_VC_B.DataTypeConversion4;
            }
          }
        }
      }

      Add2_m_tmp = TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn -
        TRSC_VC_B.DataTypeConversion_j;
      if (((TRSC_VC_B.DataTypeConversion_j <
            TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn) &&
           (TRSC_VC_B.knob_dwn_change_flg == 0.0F)) || (Add2_m_tmp >=
           Selector2_tmp)) {
        if (Add2_m_tmp >= Selector2_tmp) {
          TRSC_VC_B.knob_up_change_flg = 1.0F;
          TRSC_VC_B.knob_dwn_change_flg = 0.0F;
          if ((!TRSC_VC_DW.Prev_knob_up_change_flg) &&
              TRSC_VC_DW.Prev_knob_dwn_change_flg) {
            TRSC_VC_B.Change_In_Dir_Flag = 1.0F;
            TRSC_VC_B.Change_In_Dir = TRSC_VC_B.Rotary_Encoder_Btn;
          } else {
            TRSC_VC_B.Change_In_Dir = TRSC_VC_DW.Prev_Change_In_Dir;
          }

          Add2_m_tmp = ((TRSC_VC_B.Rotary_Encoder_Btn +
                         TRSC_VC_B.DataTypeConversion_j) -
                        TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn) + 360;
          if (Add2_m_tmp > 32767) {
            Add2_m_tmp = 32767;
          } else {
            if (Add2_m_tmp < -32768) {
              Add2_m_tmp = -32768;
            }
          }

          TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          TRSC_VC_DW.i = 0U;
          if (TRSC_VC_B.Rotary_Encoder_Btn > TRSC_VC_B.DataTypeConversion4) {
            TRSC_VC_B.Rotary_Encoder_Btn = TRSC_VC_B.DataTypeConversion4;
          }
        } else {
          TRSC_VC_B.knob_dwn_change_flg = 1.0F;
          TRSC_VC_B.knob_up_change_flg = 0.0F;
          if (TRSC_VC_DW.Prev_knob_up_change_flg &&
              (!TRSC_VC_DW.Prev_knob_dwn_change_flg)) {
            TRSC_VC_B.Change_In_Dir_Flag = 1.0F;
            TRSC_VC_B.Change_In_Dir = TRSC_VC_B.Rotary_Encoder_Btn;
          } else {
            TRSC_VC_B.Change_In_Dir = TRSC_VC_DW.Prev_Change_In_Dir;
          }

          Add2_m_tmp = (TRSC_VC_B.Rotary_Encoder_Btn +
                        TRSC_VC_B.DataTypeConversion_j) -
            TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
          if (Add2_m_tmp > 32767) {
            Add2_m_tmp = 32767;
          } else {
            if (Add2_m_tmp < -32768) {
              Add2_m_tmp = -32768;
            }
          }

          TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          TRSC_VC_DW.j = 0U;
          if (TRSC_VC_B.Rotary_Encoder_Btn < -TRSC_VC_B.DataTypeConversion4) {
            Add2_m_tmp = -TRSC_VC_B.DataTypeConversion4;
            if (Add2_m_tmp > 32767) {
              Add2_m_tmp = 32767;
            }

            TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
          }
        }
      } else {
        if ((TRSC_VC_B.knob_dwn_change_flg == 1.0F) &&
            (TRSC_VC_B.DataTypeConversion_j <
             TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn)) {
          Add2_m_tmp = TRSC_VC_DW.j + 1;
          if (Add2_m_tmp > 65535) {
            Add2_m_tmp = 65535;
          }

          TRSC_VC_DW.j = (uint16_T)Add2_m_tmp;
          if (TRSC_VC_DW.j > 0) {
            Add2_m_tmp = (TRSC_VC_B.Rotary_Encoder_Btn +
                          TRSC_VC_B.DataTypeConversion_j) -
              TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn;
            if (Add2_m_tmp > 32767) {
              Add2_m_tmp = 32767;
            } else {
              if (Add2_m_tmp < -32768) {
                Add2_m_tmp = -32768;
              }
            }

            TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
            TRSC_VC_DW.j = 0U;
            if (TRSC_VC_B.Rotary_Encoder_Btn < -TRSC_VC_B.DataTypeConversion4) {
              Add2_m_tmp = -TRSC_VC_B.DataTypeConversion4;
              if (Add2_m_tmp > 32767) {
                Add2_m_tmp = 32767;
              }

              TRSC_VC_B.Rotary_Encoder_Btn = (int16_T)Add2_m_tmp;
            }
          }
        }
      }

      TRSC_VC_DW.Prev_CAN_In_Rotary_Encoder_Btn = TRSC_VC_B.DataTypeConversion_j;
      TRSC_VC_DW.Prev_knob_up_change_flg = (TRSC_VC_B.knob_up_change_flg != 0.0F);
      TRSC_VC_DW.Prev_knob_dwn_change_flg = (TRSC_VC_B.knob_dwn_change_flg !=
        0.0F);
      TRSC_VC_DW.Prev_Change_In_Dir = TRSC_VC_B.Change_In_Dir;
    }

    /* End of Chart: '<S100>/KnobAngle' */

    /* SignalConversion generated from: '<S100>/Change_In_Dir' */
    TRSC_VC_B.OutportBufferForChange_In_Dir = TRSC_VC_B.Change_In_Dir;

    /* SignalConversion generated from: '<S100>/Rotary_Encoder_Btn' */
    TRSC_VC_B.Computed_Out = TRSC_VC_B.Rotary_Encoder_Btn;

    /* SignalConversion generated from: '<S100>/Change_In_Dir_Flag' */
    TRSC_VC_B.OutportBufferForChange_In_Dir_Flag = TRSC_VC_B.Change_In_Dir_Flag;

    /* SignalConversion generated from: '<S100>/knob_dwn_change_flg' */
    TRSC_VC_B.OutportBufferForknob_dwn_change_flg =
      TRSC_VC_B.knob_dwn_change_flg;

    /* SignalConversion generated from: '<S100>/knob_up_change_flg' */
    TRSC_VC_B.OutportBufferForknob_up_change_flg = TRSC_VC_B.knob_up_change_flg;
  } else {
    if (TRSC_VC_DW.KnobAngleComp_MODE) {
      /* Disable for Outport: '<S100>/Rotary_Encoder_Btn' */
      TRSC_VC_B.Computed_Out = 0;

      /* Disable for Outport: '<S100>/Change_In_Dir' */
      TRSC_VC_B.OutportBufferForChange_In_Dir = 0;

      /* Disable for Outport: '<S100>/knob_up_change_flg' */
      TRSC_VC_B.OutportBufferForknob_up_change_flg = 0.0F;

      /* Disable for Outport: '<S100>/knob_dwn_change_flg' */
      TRSC_VC_B.OutportBufferForknob_dwn_change_flg = 0.0F;

      /* Disable for Outport: '<S100>/Change_In_Dir_Flag' */
      TRSC_VC_B.OutportBufferForChange_In_Dir_Flag = 0.0F;
      TRSC_VC_DW.KnobAngleComp_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S9>/KnobAngleComp' */

  /* Outputs for Atomic SubSystem: '<S9>/KnobHysteresis' */
  /* Sum: '<S101>/Add' incorporates:
   *  Constant: '<S101>/KeTRSC_ddeg_TadDesRateLim2'
   *  Constant: '<S101>/KeTRSC_ddeg_TadDesRateLim4'
   */
  TRSC_VC_B.Add2_e = (int16_T)(KeTRSC_deg_ZeroPadUpThr + CeConst_k_ConstOneInt16);

  /* RelationalOperator: '<S105>/LowerRelop1' incorporates:
   *  Constant: '<S101>/Constant5'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.LogicalOperator1_fq =
    (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_KnobHys >
     CeTRSC_deg_KnobHysUpLim);

  /* RelationalOperator: '<S105>/UpperRelop' incorporates:
   *  Constant: '<S101>/Constant6'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.RelationalOperator1_f =
    (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_KnobHys <
     CeTRSC_deg_KnobHysLowLim);

  /* Switch: '<S105>/Switch' incorporates:
   *  Constant: '<S101>/Constant6'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_VC_B.RelationalOperator1_f) {
    TRSC_VC_B.Switch_ae = CeTRSC_deg_KnobHysLowLim;
  } else {
    TRSC_VC_B.Switch_ae = IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_KnobHys;
  }

  /* End of Switch: '<S105>/Switch' */

  /* Switch: '<S105>/Switch2' incorporates:
   *  Constant: '<S101>/Constant5'
   */
  if (TRSC_VC_B.LogicalOperator1_fq) {
    TRSC_VC_B.Switch2_f4 = CeTRSC_deg_KnobHysUpLim;
  } else {
    TRSC_VC_B.Switch2_f4 = TRSC_VC_B.Switch_ae;
  }

  /* End of Switch: '<S105>/Switch2' */

  /* Abs: '<S45>/Abs' incorporates:
   *  Sum: '<S101>/Add3'
   */
  TRSC_VC_B.Product_DesiredTAD = (real32_T)TRSC_VC_B.Add2_e +
    TRSC_VC_B.Switch2_f4;

  /* Sum: '<S101>/Add1' */
  TRSC_VC_B.Add2_e = (int16_T)(TRSC_VC_B.Computed_Out -
    TRSC_VC_B.OutportBufferForChange_In_Dir);

  /* RelationalOperator: '<S101>/Relational Operator' */
  TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.Add2_e <=
    TRSC_VC_B.Product_DesiredTAD);

  /* Logic: '<S101>/Logical Operator' */
  TRSC_VC_B.RelationalOperator1_f = (TRSC_VC_B.LogicalOperator1_fq &&
    (TRSC_VC_B.OutportBufferForknob_up_change_flg != 0.0F));

  /* Sum: '<S101>/Add2' */
  TRSC_VC_B.Add2_e = (int16_T)(TRSC_VC_B.OutportBufferForChange_In_Dir -
    TRSC_VC_B.Computed_Out);

  /* RelationalOperator: '<S101>/Relational Operator1' */
  TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.Add2_e <=
    TRSC_VC_B.Product_DesiredTAD);

  /* Logic: '<S101>/Logical Operator1' */
  TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.LogicalOperator1_fq &&
    (TRSC_VC_B.OutportBufferForknob_dwn_change_flg != 0.0F));

  /* Logic: '<S101>/OR' */
  TRSC_VC_B.RelationalOperator1_f = (TRSC_VC_B.RelationalOperator1_f ||
    TRSC_VC_B.RelationalOperator1_e);

  /* Logic: '<S101>/Logical Operator2' */
  TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.RelationalOperator1_f &&
    (TRSC_VC_B.OutportBufferForChange_In_Dir_Flag != 0.0F));

  /* Logic: '<S101>/NOT1' */
  TRSC_VC_B.NOT1 = !TRSC_VC_B.RelationalOperator1_e;

  /* Outputs for Enabled SubSystem: '<S101>/Subsystem' incorporates:
   *  EnablePort: '<S106>/Enable'
   */
  if (TRSC_VC_B.NOT1) {
    /* Inport: '<S106>/In1' */
    TRSC_VC_B.In1 = TRSC_VC_B.Computed_Out;
  }

  /* End of Outputs for SubSystem: '<S101>/Subsystem' */

  /* RelationalOperator: '<S101>/Relational Operator3' incorporates:
   *  Constant: '<S101>/KeTRSC_ddeg_TadDesRateLim1'
   */
  TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.In1 > KeTRSC_deg_ZeroPadUpThr);

  /* Switch: '<S101>/Switch_TAD_des_Final1' */
  if (TRSC_VC_B.RelationalOperator1_e) {
    MeTRSC_deg_KnobAngHys = TRSC_VC_B.In1;
  } else {
    /* Gain: '<S101>/Gain4' incorporates:
     *  Constant: '<S101>/KeTRSC_ddeg_TadDesRateLim1'
     */
    TRSC_VC_B.Gain4_n = (int16_T)(((-32768) * KeTRSC_deg_ZeroPadUpThr) >> 15);

    /* RelationalOperator: '<S101>/Relational Operator2' */
    TRSC_VC_B.RelationalOperator2_ba = (TRSC_VC_B.In1 < TRSC_VC_B.Gain4_n);

    /* Switch: '<S101>/Switch_TAD_des_Final2' incorporates:
     *  Constant: '<S101>/KeTRSC_ddeg_TadDesRateLim3'
     */
    if (TRSC_VC_B.RelationalOperator2_ba) {
      TRSC_VC_B.Switch_TAD_des_Final2 = TRSC_VC_B.In1;
    } else {
      TRSC_VC_B.Switch_TAD_des_Final2 = KeTRSC_deg_ZeroInt16;
    }

    /* End of Switch: '<S101>/Switch_TAD_des_Final2' */
    MeTRSC_deg_KnobAngHys = TRSC_VC_B.Switch_TAD_des_Final2;
  }

  /* End of Switch: '<S101>/Switch_TAD_des_Final1' */
  /* End of Outputs for SubSystem: '<S9>/KnobHysteresis' */

  /* Outputs for Enabled SubSystem: '<S9>/DesiredTrailerAngleComp' incorporates:
   *  EnablePort: '<S99>/Enable'
   */
  if (MeTRSC_b_TRAAct) {
    TRSC_VC_DW.DesiredTrailerAngleComp_MODE = true;

    /* Abs: '<S45>/Abs' incorporates:
     *  Gain: '<S99>/Gain2'
     *  Inport: '<Root>/IbTRSC_InpBus'
     *  Product: '<S99>/Divide'
     *  Product: '<S99>/Product_DesiredTAD'
     */
    TRSC_VC_B.Product_DesiredTAD = 0.01F *
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_pct_JackKnifePerc;
    TRSC_VC_B.Product_DesiredTAD *= TRSC_VC_B.Switch2_c;
    TRSC_VC_B.Product_DesiredTAD /=
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxKnobAngle;

    /* Product: '<S99>/Product_DesiredTAD1  ' */
    MeTRSC_deg_RawDesTrlrAng = TRSC_VC_B.Product_DesiredTAD * (real32_T)
      MeTRSC_deg_KnobAngHys;
  } else {
    if (TRSC_VC_DW.DesiredTrailerAngleComp_MODE) {
      /* Disable for Outport: '<S99>/MeTRSC_deg_RawDesTrlrAng' */
      MeTRSC_deg_RawDesTrlrAng = 0.0F;
      TRSC_VC_DW.DesiredTrailerAngleComp_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S9>/DesiredTrailerAngleComp' */

  /* Gain: '<S1>/Gain15' */
  TRSC_VC_B.Gain15 = (-1.0F) * MeTRSC_deg_RawDesTrlrAng;

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_f =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_VehStandStillSts ==
     TeVBII_e_VehStandStillSts_True);

  /* Gain: '<S1>/Gain1' */
  TRSC_VC_B.Gain1 = 0.95F * TRSC_VC_B.Switch2_a;

  /* Gain: '<S1>/Gain7' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain7 = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFWt;

  /* Gain: '<S1>/Gain8' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain8 = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFBias;

  /* DataTypeConversion: '<S1>/Data Type Conversion4' */
  TRSC_VC_B.DataTypeConversion4_h = MeTRSC_b_TRAAct;

  /* Gain: '<S5>/Gain1' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain1_h = 0.0174532924F *
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_ddeg_VehYawRate;

  /* Gain: '<S1>/Gain10' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain10 = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFBias;

  /* Gain: '<S1>/Gain9' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain9 = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFWt;

  /* DataTypeConversion: '<S1>/Data Type Conversion17' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.DataTypeConversion17 = (real32_T)(int32_T)
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply;

  /* MATLAB Function: '<S1>/MATLAB Function' */
  if (TRSC_VC_B.DataTypeConversion17 == 14.0F) {
    TRSC_VC_B.Gear_out = 2.0;
  } else if (TRSC_VC_B.DataTypeConversion17 == 15.0F) {
    TRSC_VC_B.Gear_out = 4.0;
  } else {
    TRSC_VC_B.Gear_out = 0.0;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* Outputs for Enabled SubSystem: '<S1>/Kinematic Model' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (TRSC_VC_B.DataTypeConversion4_h > 0) {
    if (!TRSC_VC_DW.KinematicModel_MODE) {
      /* SystemReset for Resettable SubSystem: '<S8>/Kinematic_model' */
      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay5' */
      TRSC_VC_DW.UnitDelay5_DSTATE = false;

      /* InitializeConditions for UnitDelay: '<S37>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_e = 0.0F;

      /* InitializeConditions for Delay: '<S24>/Delay' */
      TRSC_VC_DW.icLoad_c = 1U;

      /* InitializeConditions for Delay: '<S24>/Delay1' */
      TRSC_VC_DW.icLoad_jq = 1U;

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_m[0] = 0.0F;
      TRSC_VC_DW.UnitDelay1_DSTATE_m[1] = 0.0F;
      TRSC_VC_DW.UnitDelay1_DSTATE_m[2] = 0.0F;

      /* InitializeConditions for UnitDelay: '<S28>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_k = KeKM_k_KM_YawRateGyroBiasInit;

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay3' */
      for (i = 0; i < 9; i++) {
        TRSC_VC_DW.UnitDelay3_DSTATE_d[i] = rtCP_UnitDelay3_InitialCondition_e[i];
      }

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay4' */
      TRSC_VC_DW.UnitDelay4_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S55>/Delay Input1'
       *
       * Block description for '<S55>/Delay Input1':
       *
       *  Store in Global RAM
       */
      TRSC_VC_DW.DelayInput1_DSTATE_g = true;

      /* InitializeConditions for UnitDelay: '<S56>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_kz = false;

      /* InitializeConditions for UnitDelay: '<S33>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_pk = false;

      /* SystemReset for Resettable SubSystem: '<S57>/ResettableSubsystem' */
      /* InitializeConditions for UnitDelay: '<S63>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_b = 0.0F;

      /* InitializeConditions for UnitDelay: '<S63>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_bl = 0.0F;

      /* InitializeConditions for UnitDelay: '<S62>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_pb = 0.0F;

      /* InitializeConditions for UnitDelay: '<S62>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_a = 0.0F;

      /* End of SystemReset for SubSystem: '<S57>/ResettableSubsystem' */
      /* End of SystemReset for SubSystem: '<S8>/Kinematic_model' */
      TRSC_VC_DW.KinematicModel_MODE = true;
    }

    /* DataTypeConversion: '<S8>/Data Type Conversion' */
    TRSC_VC_B.DataTypeConversion_h = (real32_T)TRSC_VC_B.Gear_out;

    /* RelationalOperator: '<S8>/Relational Operator3' incorporates:
     *  Constant: '<S8>/Constant'
     */
    TRSC_VC_B.RelationalOperator3_g = (MeTRSC_deg_KnobAngHys == KeTRSC_deg_Zero);

    /* Outputs for Resettable SubSystem: '<S8>/Kinematic_model' incorporates:
     *  ResetPort: '<S24>/Reset'
     */
    if (TRSC_VC_B.RelationalOperator3_g &&
        (TRSC_VC_PrevZCX.Kinematic_model_Reset_ZCE != POS_ZCSIG)) {
      /* Disable for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal1' */
      if (TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE) {
        /* Disable for Outport: '<S30>/MeKM_k_HeadingIn' */
        TRSC_VC_B.MeKM_k_HeadingIn = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE = false;
      }

      /* End of Disable for SubSystem: '<S24>/KM_Integrator_Trapazoidal1' */

      /* Disable for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal' */
      if (TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE) {
        /* Disable for Outport: '<S29>/IeLSCAN_m_HV_X' */
        TRSC_VC_B.IeLSCAN_m_HV_X = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE = false;
      }

      /* End of Disable for SubSystem: '<S24>/KM_Integrator_Trapazoidal' */

      /* Disable for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal2' */
      if (TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE) {
        /* Disable for Outport: '<S31>/IeLSCAN_m_HV_Y' */
        TRSC_VC_B.IeLSCAN_m_HV_Y = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE = false;
      }

      /* End of Disable for SubSystem: '<S24>/KM_Integrator_Trapazoidal2' */

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay5' */
      TRSC_VC_DW.UnitDelay5_DSTATE = false;

      /* InitializeConditions for UnitDelay: '<S37>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_e = 0.0F;

      /* InitializeConditions for Delay: '<S24>/Delay' */
      TRSC_VC_DW.icLoad_c = 1U;

      /* InitializeConditions for Delay: '<S24>/Delay1' */
      TRSC_VC_DW.icLoad_jq = 1U;

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_m[0] = 0.0F;
      TRSC_VC_DW.UnitDelay1_DSTATE_m[1] = 0.0F;
      TRSC_VC_DW.UnitDelay1_DSTATE_m[2] = 0.0F;

      /* InitializeConditions for UnitDelay: '<S28>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_k = KeKM_k_KM_YawRateGyroBiasInit;

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay3' */
      for (i = 0; i < 9; i++) {
        TRSC_VC_DW.UnitDelay3_DSTATE_d[i] = rtCP_UnitDelay3_InitialCondition_e[i];
      }

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay4' */
      TRSC_VC_DW.UnitDelay4_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S55>/Delay Input1'
       *
       * Block description for '<S55>/Delay Input1':
       *
       *  Store in Global RAM
       */
      TRSC_VC_DW.DelayInput1_DSTATE_g = true;

      /* InitializeConditions for UnitDelay: '<S56>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_kz = false;

      /* InitializeConditions for UnitDelay: '<S33>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_pk = false;

      /* SystemReset for Resettable SubSystem: '<S57>/ResettableSubsystem' */
      /* InitializeConditions for UnitDelay: '<S63>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_b = 0.0F;

      /* InitializeConditions for UnitDelay: '<S63>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_bl = 0.0F;

      /* InitializeConditions for UnitDelay: '<S62>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_pb = 0.0F;

      /* InitializeConditions for UnitDelay: '<S62>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_a = 0.0F;

      /* End of SystemReset for SubSystem: '<S57>/ResettableSubsystem' */
    }

    TRSC_VC_PrevZCX.Kinematic_model_Reset_ZCE = TRSC_VC_B.RelationalOperator3_g;

    /* UnitDelay: '<S24>/Unit Delay5' */
    TRSC_VC_B.UnitDelay5 = TRSC_VC_DW.UnitDelay5_DSTATE;

    /* SignalConversion generated from: '<S36>/Assignment' incorporates:
     *  Constant: '<S36>/Constant2'
     */
    for (i = 0; i < 9; i++) {
      TRSC_VC_B.Assignment2[i] = rtCP_Constant2_Value_b[i];
    }

    /* End of SignalConversion generated from: '<S36>/Assignment' */

    /* Abs: '<S45>/Abs' incorporates:
     *  DataTypeConversion: '<S24>/Cast To Single6'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Product_DesiredTAD =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng;

    /* Abs: '<S36>/Abs' */
    TRSC_VC_B.Gain_k = fabsf(TRSC_VC_B.Product_DesiredTAD);

    /* Switch: '<S36>/Switch' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    if (TRSC_VC_B.Gain_k > 10.0F) {
      TRSC_VC_B.Gain_k =
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_KM_SF_YawRateCov;
    } else {
      /* Product: '<S36>/Divide' incorporates:
       *  Constant: '<S36>/Constant'
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.Divide_j =
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_KM_SF_YawRateCov / 100.0F;
      TRSC_VC_B.Gain_k = TRSC_VC_B.Divide_j;
    }

    /* End of Switch: '<S36>/Switch' */

    /* Assignment: '<S36>/Assignment' */
    TRSC_VC_B.Assignment2[0] = TRSC_VC_B.Gain_k;

    /* Assignment: '<S36>/Assignment1' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Assignment2[4] =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_KM_SF_RelAngRateCov;

    /* Assignment: '<S36>/Assignment2' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Assignment2[8] =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_KM_SF_RelAngRateCov;

    /* DataTypeConversion: '<S24>/Cast To Single5' */
    TRSC_VC_B.IeLSCAN_Cnt_Gear = TRSC_VC_B.DataTypeConversion_h;

    /* MultiPortSwitch: '<S34>/Driving_Direction' incorporates:
     *  Constant: '<S34>/CeConst_k_ConstOne'
     *  Constant: '<S34>/CeConst_k_ConstZero'
     */
    switch ((int32_T)TRSC_VC_B.IeLSCAN_Cnt_Gear) {
     case 2:
      /* Gain: '<S34>/Gain' incorporates:
       *  Constant: '<S34>/CeConst_k_ConstOne1'
       */
      TRSC_VC_B.Gain_hg = (-1.0F) * CeConst_k_ConstOne;
      TRSC_VC_B.MeKM_k_Direction = TRSC_VC_B.Gain_hg;
      break;

     case 4:
      TRSC_VC_B.MeKM_k_Direction = CeConst_k_ConstOne;
      break;

     default:
      TRSC_VC_B.MeKM_k_Direction = CeConst_k_ConstZero;
      break;
    }

    /* End of MultiPortSwitch: '<S34>/Driving_Direction' */

    /* Product: '<S68>/Divide3' incorporates:
     *  Constant: '<S68>/CeKM_deg_180'
     *  Constant: '<S68>/CeKM_k_pi'
     *  Product: '<S43>/Divide'
     *  Product: '<S46>/Divide'
     *  Product: '<S67>/Divide3'
     *  Product: '<S69>/Divide'
     *  Product: '<S69>/Divide1'
     *  Switch: '<S46>/Switch'
     *  Switch: '<S69>/Switch2'
     */
    TRSC_VC_B.gamma_now_deg_m = CeKM_deg_180 / CeKM_k_pi;
    TRSC_VC_B.Gain_k = TRSC_VC_B.gamma_now_deg_m;

    /* UnitDelay: '<S37>/Unit Delay' */
    TRSC_VC_B.Selector1_a = TRSC_VC_DW.UnitDelay_DSTATE_e;

    /* DataTypeConversion: '<S24>/Cast To Single3' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRR =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_cnt_RhrPulseCtr;

    /* DataTypeConversion: '<S24>/Cast To Single4' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRL =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_cnt_LhrPulseCtr;
    for (i = 0; i < 5; i++) {
      /* Delay: '<S24>/Delay' */
      if (TRSC_VC_DW.icLoad_c != 0) {
        TRSC_VC_DW.Delay_DSTATE_k[i] = TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRR;
      }

      /* Delay: '<S24>/Delay1' */
      if (TRSC_VC_DW.icLoad_jq != 0) {
        TRSC_VC_DW.Delay1_DSTATE_d[i] = TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRL;
      }
    }

    /* Delay: '<S24>/Delay' */
    TRSC_VC_B.Delay = TRSC_VC_DW.Delay_DSTATE_k[0];

    /* Delay: '<S24>/Delay1' */
    TRSC_VC_B.Delay1 = TRSC_VC_DW.Delay1_DSTATE_d[0];

    /* Gain: '<S24>/Gain' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Gain_c = 5.0F *
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_s_SampleTime;

    /* DataTypeConversion: '<S24>/Cast To Single1' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Selector2 =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_kph_RhrWhlSpd;

    /* Gain: '<S24>/Gain1' */
    TRSC_VC_B.Gain1_h3 = 0.277777791F * TRSC_VC_B.Selector2;

    /* DataTypeConversion: '<S24>/Cast To Single2' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Selector2 =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_kph_LhrWhlSpd;

    /* Gain: '<S24>/Gain2' */
    TRSC_VC_B.Gain2_bd = 0.277777791F * TRSC_VC_B.Selector2;

    /* Sum: '<S27>/Add' */
    TRSC_VC_B.Selector2 = TRSC_VC_B.Gain2_bd + TRSC_VC_B.Gain1_h3;

    /* Product: '<S27>/Divide' incorporates:
     *  Constant: '<S27>/CeConst_k_ConstTwo'
     */
    TRSC_VC_B.IeLSCAN_v_VehSpd = TRSC_VC_B.Selector2 / 2.0F;

    /* Gain: '<S24>/Gain3' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Selector2 = 0.001F *
      IbTRSC_InpBus.IbTRSC_MEProxiToIpc.IePRX_mm_VehTyreSize;

    /* Saturate: '<S24>/Saturation' */
    if (TRSC_VC_B.Selector2 > 2.68F) {
      TRSC_VC_B.Saturation = 2.68F;
    } else if (TRSC_VC_B.Selector2 < 2.454F) {
      TRSC_VC_B.Saturation = 2.454F;
    } else {
      TRSC_VC_B.Saturation = TRSC_VC_B.Selector2;
    }

    /* End of Saturate: '<S24>/Saturation' */

    /* MATLAB Function: '<S24>/Host Vehicle Speed Calculation - Wheel Pulse_MODIFIED' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Dt = IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_high_lim -
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_low_lim;
    TRSC_VC_B.pulse_counter_RR = 0.0F;
    TRSC_VC_B.absx = 0.0F;
    if (TRSC_VC_B.IeLSCAN_v_VehSpd != 0.0F) {
      TRSC_VC_B.HV_Speed_RearAxle = TRSC_VC_B.IeLSCAN_v_VehSpd;
    } else {
      if (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRR != TRSC_VC_B.Delay) {
        TRSC_VC_B.pulse_counter_RR = fabsf(TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRR -
          TRSC_VC_B.Delay);
        if (TRSC_VC_B.pulse_counter_RR > floorf(TRSC_VC_B.Dt / 2.0F) + 1.0F) {
          if (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRR < TRSC_VC_B.Delay) {
            TRSC_VC_B.pulse_counter_RR = (fabsf
              (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_high_lim -
               TRSC_VC_B.Delay) + 1.0F) + fabsf
              (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRR -
               IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_low_lim);
          } else {
            if (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRR > TRSC_VC_B.Delay) {
              TRSC_VC_B.pulse_counter_RR = (fabsf
                (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_low_lim -
                 TRSC_VC_B.Delay) + 1.0F) + fabsf
                (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRR -
                 IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_high_lim);
            }
          }
        }
      }

      if (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRL != TRSC_VC_B.Delay1) {
        TRSC_VC_B.absx = fabsf(TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRL -
          TRSC_VC_B.Delay1);
        if (TRSC_VC_B.absx > floorf(TRSC_VC_B.Dt / 2.0F) + 1.0F) {
          if (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRL < TRSC_VC_B.Delay1) {
            TRSC_VC_B.absx = (fabsf
                              (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_high_lim
                               - TRSC_VC_B.Delay1) + 1.0F) + fabsf
              (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRL -
               IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_low_lim);
          } else {
            if (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRL > TRSC_VC_B.Delay1) {
              TRSC_VC_B.absx = (fabsf
                                (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_low_lim
                                 - TRSC_VC_B.Delay1) + 1.0F) + fabsf
                (TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRL -
                 IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_high_lim);
            }
          }
        }
      }

      TRSC_VC_B.HV_Speed_RearAxle = (TRSC_VC_B.pulse_counter_RR + TRSC_VC_B.absx)
        / 2.0F / (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_NumWheelPulses /
                  TRSC_VC_B.Saturation) / TRSC_VC_B.Gain_c;
    }

    /* End of MATLAB Function: '<S24>/Host Vehicle Speed Calculation - Wheel Pulse_MODIFIED' */

    /* RelationalOperator: '<S32>/Relational Operator' incorporates:
     *  Constant: '<S32>/CeConst_k_ConstZero'
     */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.IeLSCAN_v_VehSpd ==
      CeConst_k_ConstZero);

    /* RelationalOperator: '<S32>/Relational Operator1' incorporates:
     *  Constant: '<S32>/CeConst_k_WhlPulsespdlimit'
     */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.HV_Speed_RearAxle >
      0.33333333333333331);

    /* Logic: '<S32>/Logical Operator' */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.RelationalOperator1_e &&
      TRSC_VC_B.LogicalOperator1_fq);

    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S32>/CeConst_k_ConstZero1'
     */
    if (TRSC_VC_B.RelationalOperator1_e) {
      TRSC_VC_B.Selector2 = CeConst_k_ConstZero;
    } else {
      TRSC_VC_B.Selector2 = TRSC_VC_B.HV_Speed_RearAxle;
    }

    /* End of Switch: '<S32>/Switch' */

    /* Sum: '<S37>/Sum2' */
    TRSC_VC_B.Selector2 -= TRSC_VC_B.Selector1_a;

    /* Product: '<S37>/Product2' incorporates:
     *  Constant: '<S24>/Constant1'
     */
    TRSC_VC_B.Selector_g = (real32_T)(TRSC_VC_B.Selector2 * 0.5);

    /* Sum: '<S37>/Sum' */
    IeLSCAN_v_VehSp_pulse = TRSC_VC_B.Selector1_a + TRSC_VC_B.Selector_g;

    /* Gain: '<S68>/Gain' */
    TRSC_VC_B.Selector_g = (-1.0F) * IeLSCAN_v_VehSp_pulse;

    /* UnitDelay: '<S24>/Unit Delay1' */
    TRSC_VC_B.Divide8[0] = TRSC_VC_DW.UnitDelay1_DSTATE_m[0];
    TRSC_VC_B.Divide8[1] = TRSC_VC_DW.UnitDelay1_DSTATE_m[1];
    TRSC_VC_B.Divide8[2] = TRSC_VC_DW.UnitDelay1_DSTATE_m[2];

    /* DataTypeConversion: '<S24>/Cast To Single7' */
    TRSC_VC_B.Selector2 = TRSC_VC_B.Gain1_h;

    /* Product: '<S43>/Divide' */
    TRSC_VC_B.Selector1_a = TRSC_VC_B.gamma_now_deg_m;

    /* Product: '<S43>/Product' */
    TRSC_VC_B.Product_k = TRSC_VC_B.Selector2 * TRSC_VC_B.Selector1_a;

    /* UnitDelay: '<S28>/Unit Delay' */
    TRSC_VC_B.UnitDelay_h = TRSC_VC_DW.UnitDelay_DSTATE_k;

    /* Abs: '<S52>/Abs' */
    TRSC_VC_B.Selector2 = fabsf(TRSC_VC_B.Product_k);

    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S52>/CeConst_k_ConstZero'
     */
    if (TRSC_VC_B.Selector2 > 0.0F) {
      /* Sum: '<S52>/Add' */
      TRSC_VC_B.Add_ol = TRSC_VC_B.Product_k - TRSC_VC_B.UnitDelay_h;
      MeKM_deg_GyroYawRate = TRSC_VC_B.Add_ol;
    } else {
      MeKM_deg_GyroYawRate = CeConst_k_ConstZero;
    }

    /* End of Switch: '<S52>/Switch' */

    /* Product: '<S40>/Divide4' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Selector2 = (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H
      [0] * TRSC_VC_B.Divide8[0] +
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[1] *
      TRSC_VC_B.Divide8[1]) +
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[2] *
      TRSC_VC_B.Divide8[2];

    /* Sum: '<S40>/Subtract1' */
    TRSC_VC_B.Selector2 = MeKM_deg_GyroYawRate - TRSC_VC_B.Selector2;

    /* Selector: '<S91>/Selector2' incorporates:
     *  Assignment: '<S91>/Assignment2'
     *  Constant: '<S91>/Constant4'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.idxDelay = (int32_T)2.0F;
    TRSC_VC_B.Selector1_a =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[TRSC_VC_B.idxDelay];

    /* Selector: '<S91>/Selector1' incorporates:
     *  Assignment: '<S91>/Assignment1'
     *  Constant: '<S91>/Constant3'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    Add2_m_tmp = (int32_T)1.0F;
    TRSC_VC_B.Add2_m =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[Add2_m_tmp];

    /* Selector: '<S91>/Selector' incorporates:
     *  Constant: '<S90>/Constant2'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Switch2_du = IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H
      [(int32_T)0.0F];

    /* Assignment: '<S91>/Assignment' incorporates:
     *  Constant: '<S91>/Constant1'
     *  Constant: '<S91>/Constant2'
     */
    TRSC_VC_B.Divide5_h[0] = 0.0F;
    TRSC_VC_B.Divide5_h[1] = 0.0F;
    TRSC_VC_B.Divide5_h[2] = 0.0F;
    TRSC_VC_B.Divide5_h[(int32_T)0.0F] = TRSC_VC_B.Switch2_du;

    /* Assignment: '<S91>/Assignment1' */
    TRSC_VC_B.Divide5_h[Add2_m_tmp] = TRSC_VC_B.Add2_m;

    /* Assignment: '<S91>/Assignment2' */
    TRSC_VC_B.Divide5_h[TRSC_VC_B.idxDelay] = TRSC_VC_B.Selector1_a;

    /* UnitDelay: '<S24>/Unit Delay3' */
    for (i = 0; i < 9; i++) {
      TRSC_VC_B.Subtract3_a[i] = TRSC_VC_DW.UnitDelay3_DSTATE_d[i];
    }

    /* End of UnitDelay: '<S24>/Unit Delay3' */

    /* Product: '<S40>/Divide6' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      TRSC_VC_B.Assignment1[Add2_m_tmp] = 0.0F;
      TRSC_VC_B.Assignment1[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp]
        * IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[0];
      TRSC_VC_B.Assignment1[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp
        + 1] * IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[1];
      TRSC_VC_B.Assignment1[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp
        + 2] * IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[2];
    }

    /* End of Product: '<S40>/Divide6' */

    /* Product: '<S40>/Divide7' */
    TRSC_VC_B.Switch2_du = (TRSC_VC_B.Assignment1[0] * TRSC_VC_B.Divide5_h[0] +
      TRSC_VC_B.Assignment1[1] * TRSC_VC_B.Divide5_h[1]) +
      TRSC_VC_B.Assignment1[2] * TRSC_VC_B.Divide5_h[2];

    /* Sum: '<S40>/Subtract' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Switch2_du += IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_GyroYawCov;

    /* Product: '<S40>/Divide2' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      TRSC_VC_B.Assignment1[Add2_m_tmp] = 0.0F;
      TRSC_VC_B.Assignment1[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[Add2_m_tmp] *
        TRSC_VC_B.Divide5_h[0];
      TRSC_VC_B.Assignment1[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[Add2_m_tmp + 3]
        * TRSC_VC_B.Divide5_h[1];
      TRSC_VC_B.Assignment1[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[Add2_m_tmp + 6]
        * TRSC_VC_B.Divide5_h[2];
    }

    /* End of Product: '<S40>/Divide2' */

    /* Product: '<S40>/Divide1' */
    TRSC_VC_B.Divide5_h[0] = TRSC_VC_B.Assignment1[0] / TRSC_VC_B.Switch2_du;

    /* Product: '<S40>/Divide3' incorporates:
     *  Product: '<S40>/Divide1'
     */
    TRSC_VC_B.Assignment1[0] = TRSC_VC_B.Assignment1[0] / TRSC_VC_B.Switch2_du *
      TRSC_VC_B.Selector2;

    /* Sum: '<S40>/Subtract2' */
    TRSC_VC_B.Assignment1[0] += TRSC_VC_B.Divide8[0];

    /* Product: '<S40>/Divide1' */
    TRSC_VC_B.Dt = TRSC_VC_B.Assignment1[1] / TRSC_VC_B.Switch2_du;
    TRSC_VC_B.Divide5_h[1] = TRSC_VC_B.Dt;

    /* Product: '<S40>/Divide3' incorporates:
     *  Product: '<S40>/Divide1'
     */
    TRSC_VC_B.Assignment1[1] = TRSC_VC_B.Dt * TRSC_VC_B.Selector2;

    /* Sum: '<S40>/Subtract2' */
    TRSC_VC_B.Assignment1[1] += TRSC_VC_B.Divide8[1];

    /* Product: '<S40>/Divide1' */
    TRSC_VC_B.Dt = TRSC_VC_B.Assignment1[2] / TRSC_VC_B.Switch2_du;
    TRSC_VC_B.Divide5_h[2] = TRSC_VC_B.Dt;

    /* Product: '<S40>/Divide3' incorporates:
     *  Product: '<S40>/Divide1'
     */
    TRSC_VC_B.Assignment1[2] = TRSC_VC_B.Dt * TRSC_VC_B.Selector2;

    /* Sum: '<S40>/Subtract2' */
    TRSC_VC_B.Assignment1[2] += TRSC_VC_B.Divide8[2];

    /* DataTypeConversion: '<S24>/Cast To Single' */
    TRSC_VC_B.Switch2_du = TRSC_VC_B.Gain5;

    /* Product: '<S42>/Divide4' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Add2_m = (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[0] *
                        TRSC_VC_B.Assignment1[0] +
                        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[1] *
                        TRSC_VC_B.Assignment1[1]) +
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[2] *
      TRSC_VC_B.Assignment1[2];

    /* Sum: '<S42>/Subtract1' */
    TRSC_VC_B.Add2_m = TRSC_VC_B.Switch2_du - TRSC_VC_B.Add2_m;

    /* Selector: '<S95>/Selector2' incorporates:
     *  Assignment: '<S95>/Assignment2'
     *  Constant: '<S95>/Constant4'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    Selector2_tmp = (int32_T)2.0F;
    TRSC_VC_B.Selector2 =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[Selector2_tmp];

    /* Selector: '<S95>/Selector1' incorporates:
     *  Assignment: '<S95>/Assignment1'
     *  Constant: '<S95>/Constant3'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.idxDelay = (int32_T)1.0F;
    TRSC_VC_B.Selector1_a =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[TRSC_VC_B.idxDelay];

    /* Selector: '<S95>/Selector' incorporates:
     *  Constant: '<S94>/Constant2'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Product2_j = IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H
      [(int32_T)0.0F];

    /* Assignment: '<S95>/Assignment' incorporates:
     *  Constant: '<S95>/Constant1'
     *  Constant: '<S95>/Constant2'
     */
    TRSC_VC_B.Divide8[0] = 0.0F;
    TRSC_VC_B.Divide8[1] = 0.0F;
    TRSC_VC_B.Divide8[2] = 0.0F;
    TRSC_VC_B.Divide8[(int32_T)0.0F] = TRSC_VC_B.Product2_j;

    /* Assignment: '<S95>/Assignment1' */
    TRSC_VC_B.Divide8[TRSC_VC_B.idxDelay] = TRSC_VC_B.Selector1_a;

    /* Assignment: '<S95>/Assignment2' */
    TRSC_VC_B.Divide8[Selector2_tmp] = TRSC_VC_B.Selector2;

    /* Product: '<S40>/Divide5' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      TRSC_VC_B.Divide3[3 * Add2_m_tmp] = TRSC_VC_B.Divide5_h[0] *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[Add2_m_tmp];
      TRSC_VC_B.Divide3[3 * Add2_m_tmp + 1] = TRSC_VC_B.Divide5_h[1] *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[Add2_m_tmp];
      TRSC_VC_B.Divide3[3 * Add2_m_tmp + 2] = TRSC_VC_B.Divide5_h[2] *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[Add2_m_tmp];
    }

    /* End of Product: '<S40>/Divide5' */

    /* Product: '<S40>/Divide8' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      for (Selector2_tmp = 0; Selector2_tmp < 3; Selector2_tmp++) {
        Divide5_h_tmp = Selector2_tmp + 3 * Add2_m_tmp;
        TRSC_VC_B.Divide5_h[Divide5_h_tmp] = 0.0F;
        TRSC_VC_B.Divide5_h[Divide5_h_tmp] += TRSC_VC_B.Subtract3_a[3 *
          Add2_m_tmp] * TRSC_VC_B.Divide3[Selector2_tmp];
        TRSC_VC_B.Divide5_h[Divide5_h_tmp] += TRSC_VC_B.Subtract3_a[3 *
          Add2_m_tmp + 1] * TRSC_VC_B.Divide3[Selector2_tmp + 3];
        TRSC_VC_B.Divide5_h[Divide5_h_tmp] += TRSC_VC_B.Subtract3_a[3 *
          Add2_m_tmp + 2] * TRSC_VC_B.Divide3[Selector2_tmp + 6];
      }
    }

    /* End of Product: '<S40>/Divide8' */

    /* Sum: '<S40>/Subtract3' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 9; Add2_m_tmp++) {
      TRSC_VC_B.Subtract3_a[Add2_m_tmp] -= TRSC_VC_B.Divide5_h[Add2_m_tmp];
    }

    /* End of Sum: '<S40>/Subtract3' */

    /* Product: '<S42>/Divide6' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      TRSC_VC_B.fv[Add2_m_tmp] = TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp + 2] *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[2] +
        (TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp + 1] *
         IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[1] +
         TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp] *
         IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[0]);
    }

    /* End of Product: '<S42>/Divide6' */

    /* Product: '<S42>/Divide7' */
    TRSC_VC_B.Product2_j = (TRSC_VC_B.fv[0] * TRSC_VC_B.Divide8[0] +
      TRSC_VC_B.fv[1] * TRSC_VC_B.Divide8[1]) + TRSC_VC_B.fv[2] *
      TRSC_VC_B.Divide8[2];

    /* Sum: '<S42>/Subtract' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Product2_j += IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_TADCov;

    /* Product: '<S42>/Divide2' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      TRSC_VC_B.Divide3[Add2_m_tmp] = 0.0F;
      TRSC_VC_B.Divide3[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[Add2_m_tmp] *
        TRSC_VC_B.Divide8[0];
      TRSC_VC_B.Divide3[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[Add2_m_tmp + 3] *
        TRSC_VC_B.Divide8[1];
      TRSC_VC_B.Divide3[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[Add2_m_tmp + 6] *
        TRSC_VC_B.Divide8[2];
    }

    /* End of Product: '<S42>/Divide2' */

    /* Product: '<S42>/Divide1' */
    TRSC_VC_B.Divide8[0] = TRSC_VC_B.Divide3[0] / TRSC_VC_B.Product2_j;

    /* Product: '<S42>/Divide3' */
    TRSC_VC_B.Dt = TRSC_VC_B.Divide8[0] * TRSC_VC_B.Add2_m;

    /* Sum: '<S42>/Subtract2' */
    TRSC_VC_B.Subtract2[0] = TRSC_VC_B.Dt + TRSC_VC_B.Assignment1[0];

    /* Product: '<S42>/Divide1' */
    TRSC_VC_B.Divide8[1] = TRSC_VC_B.Divide3[1] / TRSC_VC_B.Product2_j;

    /* Product: '<S42>/Divide3' */
    TRSC_VC_B.Dt = TRSC_VC_B.Divide8[1] * TRSC_VC_B.Add2_m;

    /* Sum: '<S42>/Subtract2' */
    TRSC_VC_B.Subtract2[1] = TRSC_VC_B.Dt + TRSC_VC_B.Assignment1[1];

    /* Product: '<S42>/Divide1' */
    TRSC_VC_B.Divide8[2] = TRSC_VC_B.Divide3[2] / TRSC_VC_B.Product2_j;

    /* Product: '<S42>/Divide3' */
    TRSC_VC_B.Dt = TRSC_VC_B.Divide8[2] * TRSC_VC_B.Add2_m;

    /* Sum: '<S42>/Subtract2' */
    TRSC_VC_B.Subtract2[2] = TRSC_VC_B.Dt + TRSC_VC_B.Assignment1[2];

    /* Selector: '<S68>/Selector' incorporates:
     *  Assignment: '<S68>/Assignment'
     *  Assignment: '<S68>/Assignment1'
     *  Assignment: '<S68>/Assignment2'
     *  Constant: '<S68>/CeConst_k_ConstTwo'
     *  Selector: '<S48>/Selector1'
     *  Selector: '<S67>/Selector'
     *  Selector: '<S67>/Selector1'
     *  Selector: '<S68>/Selector1'
     *  Selector: '<S70>/Selector3'
     *  Switch: '<S70>/Switch2'
     */
    TRSC_VC_B.idxDelay = (int32_T)CeConst_k_ConstTwo;
    TRSC_VC_B.Selector = TRSC_VC_B.Subtract2[TRSC_VC_B.idxDelay];

    /* RelationalOperator: '<S78>/Relational Operator2' */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.Selector >=
      TRSC_VC_ConstB.Gain1_i);

    /* RelationalOperator: '<S78>/Relational Operator3' incorporates:
     *  Constant: '<S78>/90Deg2'
     */
    TRSC_VC_B.LogicalOperator1_fq = (90.0F >= TRSC_VC_B.Selector);

    /* Logic: '<S78>/Logical Operator' */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.RelationalOperator1_e &&
      TRSC_VC_B.LogicalOperator1_fq);

    /* Switch: '<S78>/Switch2' */
    if (TRSC_VC_B.RelationalOperator1_e) {
      /* RelationalOperator: '<S78>/Relational Operator4' incorporates:
       *  Constant: '<S78>/0Deg1'
       */
      TRSC_VC_B.RelationalOperator4_p = (TRSC_VC_B.Selector >= 0.0F);

      /* Switch: '<S78>/Switch3' */
      if (TRSC_VC_B.RelationalOperator4_p) {
        /* Lookup_n-D: '<S78>/1-D Lookup Table_0_3' */
        TRSC_VC_B.uDLookupTable_0_3_f = look1_iflf_linlxpw(TRSC_VC_B.Selector,
          rtCP_uDLookupTable_0_3_bp01Data_l, rtCP_uDLookupTable_0_3_tableData_n,
          90U);
        TRSC_VC_B.Switch3_j = TRSC_VC_B.uDLookupTable_0_3_f;
      } else {
        /* Gain: '<S78>/Gain2' */
        TRSC_VC_B.Gain2_e = (-1.0F) * TRSC_VC_B.Selector;

        /* Lookup_n-D: '<S78>/1-D Lookup Table_0_2' */
        /*
         * About '<S78>/1-D Lookup Table_0_2':
         *       Table size:  91
         *    Interpolation:  Spline
         *    Extrapolation:  Linear
         *   Breakpt Search:  Linear
         *    Breakpt Cache:  OFF
         */
        TRSC_VC_B.uDLookupTable_0_2_i = look_SplNLinXZf(1U, &TRSC_VC_B.Gain2_e,
          (rt_LUTSplineWork*)&TRSC_VC_DW.SWork[0]);
        TRSC_VC_B.Switch3_j = TRSC_VC_B.uDLookupTable_0_2_i;
      }

      /* End of Switch: '<S78>/Switch3' */
      TRSC_VC_B.Product2_j = TRSC_VC_B.Switch3_j;
    } else {
      /* Abs: '<S78>/Abs1' */
      TRSC_VC_B.uDLookupTable_0_1_jm = fabsf(TRSC_VC_B.Selector);

      /* Sum: '<S78>/Add1' incorporates:
       *  Constant: '<S78>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_jm -= 90.0F;

      /* Sum: '<S78>/Add2' incorporates:
       *  Constant: '<S78>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_jm = 90.0F - TRSC_VC_B.uDLookupTable_0_1_jm;

      /* Lookup_n-D: '<S78>/1-D Lookup Table_0_1' */
      TRSC_VC_B.uDLookupTable_0_1_jm = look1_iflf_linlxpw
        (TRSC_VC_B.uDLookupTable_0_1_jm, rtCP_uDLookupTable_0_1_bp01Data_p5,
         rtCP_uDLookupTable_0_1_tableData_n, 90U);

      /* Gain: '<S78>/Gain3' */
      TRSC_VC_B.Gain3_d = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_jm;
      TRSC_VC_B.Product2_j = TRSC_VC_B.Gain3_d;
    }

    /* End of Switch: '<S78>/Switch2' */

    /* Product: '<S68>/Divide2' */
    TRSC_VC_B.Product2_j /= TRSC_VC_B.Switch6;

    /* Product: '<S34>/Product' */
    TRSC_VC_B.Add2_m = TRSC_VC_B.Product_DesiredTAD * TRSC_VC_B.Gain9;

    /* Sum: '<S34>/Add' */
    TRSC_VC_B.MeKM_k_WhlAngl = TRSC_VC_B.Add2_m + TRSC_VC_B.Gain10;

    /* Lookup_n-D: '<S80>/tan Lookup' */
    TRSC_VC_B.Add2_m = look1_iflf_linlxpw(TRSC_VC_B.MeKM_k_WhlAngl,
      rtCP_tanLookup_bp01Data_j, rtCP_tanLookup_tableData_h, 180U);

    /* Product: '<S68>/Divide' */
    TRSC_VC_B.Add2_m /= TRSC_VC_B.Switch2;

    /* Selector: '<S68>/Selector1' */
    TRSC_VC_B.Selector1 = TRSC_VC_B.Subtract2[TRSC_VC_B.idxDelay];

    /* RelationalOperator: '<S79>/Relational Operator1' */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.Selector1 >=
      TRSC_VC_ConstB.Gain4_o);

    /* RelationalOperator: '<S79>/Relational Operator5' incorporates:
     *  Constant: '<S79>/90Deg5'
     */
    TRSC_VC_B.LogicalOperator1_fq = (90.0F >= TRSC_VC_B.Selector1);

    /* Logic: '<S79>/Logical Operator1' */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.RelationalOperator1_e &&
      TRSC_VC_B.LogicalOperator1_fq);

    /* Abs: '<S79>/Abs2' */
    TRSC_VC_B.Selector2 = fabsf(TRSC_VC_B.Selector1);

    /* Sum: '<S79>/Add3' incorporates:
     *  Constant: '<S79>/90Deg5'
     */
    TRSC_VC_B.Selector2 -= 90.0F;

    /* Sum: '<S79>/Add4' incorporates:
     *  Constant: '<S79>/90Deg5'
     */
    TRSC_VC_B.Selector2 = 90.0F - TRSC_VC_B.Selector2;

    /* Lookup_n-D: '<S79>/1-D Lookup Table_0_2' */
    TRSC_VC_B.uDLookupTable_0_2_o = look1_iflf_linlxpw(TRSC_VC_B.Selector2,
      rtCP_uDLookupTable_0_2_bp01Data_c0, rtCP_uDLookupTable_0_2_tableData_f,
      90U);

    /* Switch: '<S79>/Switch1' */
    if (TRSC_VC_B.RelationalOperator1_e) {
      /* RelationalOperator: '<S79>/Relational Operator6' incorporates:
       *  Constant: '<S79>/Deg_0'
       */
      TRSC_VC_B.RelationalOperator6_n = (TRSC_VC_B.Selector1 >= 0.0F);

      /* Switch: '<S79>/Switch4' */
      if (TRSC_VC_B.RelationalOperator6_n) {
        /* Lookup_n-D: '<S79>/1-D Lookup Table_0_6' */
        TRSC_VC_B.uDLookupTable_0_6_i = look1_iflf_linlxpw(TRSC_VC_B.Selector1,
          rtCP_uDLookupTable_0_6_bp01Data_j, rtCP_uDLookupTable_0_6_tableData_b,
          90U);
        TRSC_VC_B.Switch4_h = TRSC_VC_B.uDLookupTable_0_6_i;
      } else {
        /* Gain: '<S79>/Gain5' */
        TRSC_VC_B.uDLookupTable_0_1_c = (-1.0F) * TRSC_VC_B.Selector1;

        /* Lookup_n-D: '<S79>/1-D Lookup Table_0_1' */
        TRSC_VC_B.uDLookupTable_0_1_c = look1_iflf_linlxpw
          (TRSC_VC_B.uDLookupTable_0_1_c, rtCP_uDLookupTable_0_1_bp01Data_d2,
           rtCP_uDLookupTable_0_1_tableData_p, 90U);

        /* Gain: '<S79>/Gain1' */
        TRSC_VC_B.Gain1_a = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_c;
        TRSC_VC_B.Switch4_h = TRSC_VC_B.Gain1_a;
      }

      /* End of Switch: '<S79>/Switch4' */
      TRSC_VC_B.Selector2 = TRSC_VC_B.Switch4_h;
    } else {
      /* RelationalOperator: '<S79>/Relational Operator2' incorporates:
       *  Constant: '<S79>/90Deg5'
       */
      TRSC_VC_B.RelationalOperator2_h = (TRSC_VC_B.Selector1 >= 90.0F);

      /* Switch: '<S79>/Switch2' */
      if (TRSC_VC_B.RelationalOperator2_h) {
        TRSC_VC_B.Switch2_ht = TRSC_VC_B.uDLookupTable_0_2_o;
      } else {
        /* Gain: '<S79>/Gain2' */
        TRSC_VC_B.Gain2_fq = (-1.0F) * TRSC_VC_B.uDLookupTable_0_2_o;
        TRSC_VC_B.Switch2_ht = TRSC_VC_B.Gain2_fq;
      }

      /* End of Switch: '<S79>/Switch2' */
      TRSC_VC_B.Selector2 = TRSC_VC_B.Switch2_ht;
    }

    /* End of Switch: '<S79>/Switch1' */

    /* Product: '<S68>/Divide1' */
    TRSC_VC_B.Selector2 *= 1.0F / TRSC_VC_B.Switch6;

    /* Product: '<S68>/Product1' */
    TRSC_VC_B.Selector2 *= TRSC_VC_B.Gain2;

    /* Sum: '<S68>/Add2' incorporates:
     *  Constant: '<S68>/CeConst_k_ConstOne'
     */
    TRSC_VC_B.Selector2 = CeConst_k_ConstOne - TRSC_VC_B.Selector2;

    /* Product: '<S68>/Product2' */
    TRSC_VC_B.Add2_m *= TRSC_VC_B.Selector2;

    /* Sum: '<S68>/Add1' */
    TRSC_VC_B.Product2_j += TRSC_VC_B.Add2_m;

    /* Product: '<S68>/Product4' */
    TRSC_VC_B.Selector_g *= TRSC_VC_B.Product2_j;

    /* Product: '<S68>/Product3' */
    TRSC_VC_B.Gain_k = TRSC_VC_B.Gain_k * TRSC_VC_B.MeKM_k_Direction *
      TRSC_VC_B.Selector_g;

    /* SignalConversion generated from: '<S68>/Assignment' incorporates:
     *  Constant: '<S68>/zeros(3,3)'
     */
    for (i = 0; i < 9; i++) {
      TRSC_VC_B.Divide3[i] = rtCP_zeros33_Value[i];
    }

    /* End of SignalConversion generated from: '<S68>/Assignment' */

    /* Assignment: '<S68>/Assignment' incorporates:
     *  Assignment: '<S68>/Assignment1'
     *  Assignment: '<S68>/Assignment2'
     *  Constant: '<S68>/CeConst_k_ConstOne1'
     *  Selector: '<S70>/Selector2'
     *  Switch: '<S70>/Switch2'
     */
    TRSC_VC_B.k = (int32_T)CeConst_k_ConstOne;
    i = 3 * TRSC_VC_B.idxDelay;
    TRSC_VC_B.Divide3[TRSC_VC_B.k + i] = TRSC_VC_B.Gain_k;

    /* Assignment: '<S68>/Assignment1' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Divide3[TRSC_VC_B.idxDelay + 3 * TRSC_VC_B.k] =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_s_SampleTime;

    /* Assignment: '<S68>/Assignment2' incorporates:
     *  Constant: '<S68>/CeConst_k_ConstOne3'
     */
    TRSC_VC_B.Divide3[TRSC_VC_B.idxDelay + i] = CeConst_k_ConstOne;

    /* Product: '<S42>/Divide5' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      TRSC_VC_B.Divide5_h[3 * Add2_m_tmp] = TRSC_VC_B.Divide8[0] *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[Add2_m_tmp];
      TRSC_VC_B.Divide5_h[3 * Add2_m_tmp + 1] = TRSC_VC_B.Divide8[1] *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[Add2_m_tmp];
      TRSC_VC_B.Divide5_h[3 * Add2_m_tmp + 2] = TRSC_VC_B.Divide8[2] *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[Add2_m_tmp];
    }

    /* End of Product: '<S42>/Divide5' */

    /* Product: '<S42>/Divide8' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      for (Selector2_tmp = 0; Selector2_tmp < 3; Selector2_tmp++) {
        Divide5_h_tmp = Selector2_tmp + 3 * Add2_m_tmp;
        TRSC_VC_B.Divide8[Divide5_h_tmp] = 0.0F;
        TRSC_VC_B.Divide8[Divide5_h_tmp] += TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp]
          * TRSC_VC_B.Divide5_h[Selector2_tmp];
        TRSC_VC_B.Divide8[Divide5_h_tmp] += TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp
          + 1] * TRSC_VC_B.Divide5_h[Selector2_tmp + 3];
        TRSC_VC_B.Divide8[Divide5_h_tmp] += TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp
          + 2] * TRSC_VC_B.Divide5_h[Selector2_tmp + 6];
      }
    }

    /* End of Product: '<S42>/Divide8' */

    /* Sum: '<S42>/Subtract3' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 9; Add2_m_tmp++) {
      TRSC_VC_B.Divide8[Add2_m_tmp] = TRSC_VC_B.Subtract3_a[Add2_m_tmp] -
        TRSC_VC_B.Divide8[Add2_m_tmp];
    }

    /* End of Sum: '<S42>/Subtract3' */

    /* Product: '<S58>/Product' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      for (Selector2_tmp = 0; Selector2_tmp < 3; Selector2_tmp++) {
        Divide5_h_tmp = Selector2_tmp + 3 * Add2_m_tmp;
        TRSC_VC_B.Divide5_h[Divide5_h_tmp] = 0.0F;
        TRSC_VC_B.Divide5_h[Divide5_h_tmp] += TRSC_VC_B.Divide8[3 * Add2_m_tmp] *
          TRSC_VC_B.Divide3[Selector2_tmp];
        TRSC_VC_B.Divide5_h[Divide5_h_tmp] += TRSC_VC_B.Divide8[3 * Add2_m_tmp +
          1] * TRSC_VC_B.Divide3[Selector2_tmp + 3];
        TRSC_VC_B.Divide5_h[Divide5_h_tmp] += TRSC_VC_B.Divide8[3 * Add2_m_tmp +
          2] * TRSC_VC_B.Divide3[Selector2_tmp + 6];
      }
    }

    /* End of Product: '<S58>/Product' */

    /* Selector: '<S74>/Selector2' incorporates:
     *  Assignment: '<S74>/Assignment'
     *  Assignment: '<S74>/Assignment2'
     *  Constant: '<S66>/Constant4'
     *  Constant: '<S74>/Constant4'
     *  Selector: '<S74>/Selector'
     *  Selector: '<S74>/Selector1'
     */
    Product2_j_tmp = (int32_T)2.0F;
    TRSC_VC_B.Product2_j = TRSC_VC_B.Divide3[3 * (int32_T)2.0F + Product2_j_tmp];

    /* Selector: '<S74>/Selector1' incorporates:
     *  Assignment: '<S74>/Assignment1'
     *  Constant: '<S74>/Constant3'
     */
    Add2_m_tmp = (int32_T)1.0F;
    TRSC_VC_B.Add2_m = TRSC_VC_B.Divide3[3 * Add2_m_tmp + Product2_j_tmp];

    /* Selector: '<S74>/Selector' incorporates:
     *  Assignment: '<S74>/Assignment'
     *  Constant: '<S74>/Constant2'
     */
    Selector_g_tmp = (int32_T)0.0F;
    TRSC_VC_B.Selector_g = TRSC_VC_B.Divide3[3 * Selector_g_tmp + Product2_j_tmp];

    /* Selector: '<S73>/Selector2' incorporates:
     *  Assignment: '<S73>/Assignment'
     *  Assignment: '<S73>/Assignment1'
     *  Assignment: '<S73>/Assignment2'
     *  Constant: '<S66>/Constant3'
     *  Constant: '<S73>/Constant4'
     *  Selector: '<S73>/Selector'
     *  Selector: '<S73>/Selector1'
     */
    Selector2_tmp = (int32_T)1.0F;
    Selector2_tmp_0 = (int32_T)2.0F;
    TRSC_VC_B.Selector2 = TRSC_VC_B.Divide3[3 * Selector2_tmp_0 + Selector2_tmp];

    /* Selector: '<S73>/Selector1' incorporates:
     *  Constant: '<S73>/Constant3'
     */
    TRSC_VC_B.Selector1_a = TRSC_VC_B.Divide3[3 * (int32_T)1.0F + Selector2_tmp];

    /* Selector: '<S73>/Selector' incorporates:
     *  Assignment: '<S73>/Assignment'
     *  Constant: '<S73>/Constant2'
     */
    Gain_k_tmp = (int32_T)0.0F;
    TRSC_VC_B.Gain_k = TRSC_VC_B.Divide3[3 * Gain_k_tmp + Selector2_tmp];

    /* Selector: '<S72>/Selector2' incorporates:
     *  Assignment: '<S72>/Assignment'
     *  Assignment: '<S72>/Assignment2'
     *  Constant: '<S66>/Constant2'
     *  Constant: '<S72>/Constant4'
     *  Selector: '<S72>/Selector'
     *  Selector: '<S72>/Selector1'
     */
    u1wNxN1_tmp = (int32_T)0.0F;
    u1wNxN1_tmp_0 = (int32_T)2.0F;
    TRSC_VC_B.u1wNxN1 = TRSC_VC_B.Divide3[3 * u1wNxN1_tmp_0 + u1wNxN1_tmp];

    /* Selector: '<S72>/Selector1' incorporates:
     *  Assignment: '<S72>/Assignment1'
     *  Constant: '<S72>/Constant3'
     */
    Divide5_h_tmp = (int32_T)1.0F;
    TRSC_VC_B.uwNxN = TRSC_VC_B.Divide3[3 * Divide5_h_tmp + u1wNxN1_tmp];

    /* Selector: '<S72>/Selector' incorporates:
     *  Constant: '<S72>/Constant2'
     */
    TRSC_VC_B.u1wN = TRSC_VC_B.Divide3[3 * (int32_T)0.0F + u1wNxN1_tmp];

    /* Assignment: '<S72>/Assignment' incorporates:
     *  Assignment: '<S72>/Assignment1'
     *  Assignment: '<S72>/Assignment2'
     *  Constant: '<S72>/Constant1'
     */
    for (i = 0; i < 9; i++) {
      TRSC_VC_B.Divide3[i] = rtCP_Constant1_Value_n5[i];
    }

    i = 3 * u1wNxN1_tmp;
    TRSC_VC_B.Divide3[u1wNxN1_tmp + i] = TRSC_VC_B.u1wN;

    /* Assignment: '<S72>/Assignment1' */
    TRSC_VC_B.Divide3[Divide5_h_tmp + i] = TRSC_VC_B.uwNxN;

    /* Assignment: '<S72>/Assignment2' */
    TRSC_VC_B.Divide3[u1wNxN1_tmp_0 + i] = TRSC_VC_B.u1wNxN1;

    /* Assignment: '<S73>/Assignment' incorporates:
     *  Assignment: '<S73>/Assignment1'
     *  Assignment: '<S73>/Assignment2'
     */
    i = 3 * Selector2_tmp;
    TRSC_VC_B.Divide3[Gain_k_tmp + i] = TRSC_VC_B.Gain_k;

    /* Assignment: '<S73>/Assignment1' */
    TRSC_VC_B.Divide3[Selector2_tmp + i] = TRSC_VC_B.Selector1_a;

    /* Assignment: '<S73>/Assignment2' */
    TRSC_VC_B.Divide3[Selector2_tmp_0 + i] = TRSC_VC_B.Selector2;

    /* Assignment: '<S74>/Assignment' incorporates:
     *  Assignment: '<S74>/Assignment1'
     *  Assignment: '<S74>/Assignment2'
     */
    i = 3 * Product2_j_tmp;
    TRSC_VC_B.Divide3[Selector_g_tmp + i] = TRSC_VC_B.Selector_g;

    /* Assignment: '<S74>/Assignment1' */
    TRSC_VC_B.Divide3[Add2_m_tmp + i] = TRSC_VC_B.Add2_m;

    /* Assignment: '<S74>/Assignment2' */
    TRSC_VC_B.Divide3[Product2_j_tmp + i] = TRSC_VC_B.Product2_j;

    /* Product: '<S58>/Product1' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      for (Selector2_tmp = 0; Selector2_tmp < 3; Selector2_tmp++) {
        Divide5_h_tmp = Selector2_tmp + 3 * Add2_m_tmp;
        TRSC_VC_B.Divide8[Divide5_h_tmp] = 0.0F;
        TRSC_VC_B.Divide8[Divide5_h_tmp] += TRSC_VC_B.Divide3[3 * Add2_m_tmp] *
          TRSC_VC_B.Divide5_h[Selector2_tmp];
        TRSC_VC_B.Divide8[Divide5_h_tmp] += TRSC_VC_B.Divide3[3 * Add2_m_tmp + 1]
          * TRSC_VC_B.Divide5_h[Selector2_tmp + 3];
        TRSC_VC_B.Divide8[Divide5_h_tmp] += TRSC_VC_B.Divide3[3 * Add2_m_tmp + 2]
          * TRSC_VC_B.Divide5_h[Selector2_tmp + 6];
      }
    }

    /* End of Product: '<S58>/Product1' */

    /* Sum: '<S58>/Add2' */
    for (i = 0; i < 9; i++) {
      TRSC_VC_B.MaKM_k_P_next[i] = TRSC_VC_B.Divide8[i] +
        TRSC_VC_B.Assignment2[i];
    }

    /* End of Sum: '<S58>/Add2' */

    /* Selector: '<S93>/Selector2' incorporates:
     *  Assignment: '<S93>/Assignment2'
     *  Constant: '<S93>/Constant4'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    Add2_m_tmp = (int32_T)2.0F;
    TRSC_VC_B.u1wN =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[Add2_m_tmp];

    /* Selector: '<S93>/Selector1' incorporates:
     *  Assignment: '<S93>/Assignment1'
     *  Constant: '<S93>/Constant3'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    Divide5_h_tmp = (int32_T)1.0F;
    TRSC_VC_B.uwNxN =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[Divide5_h_tmp];

    /* Selector: '<S93>/Selector' incorporates:
     *  Constant: '<S92>/Constant2'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.u1wNxN1 = IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H
      [(int32_T)0.0F];

    /* Assignment: '<S93>/Assignment' incorporates:
     *  Constant: '<S93>/Constant1'
     *  Constant: '<S93>/Constant2'
     */
    TRSC_VC_B.Divide3[0] = 0.0F;
    TRSC_VC_B.Divide3[1] = 0.0F;
    TRSC_VC_B.Divide3[2] = 0.0F;
    TRSC_VC_B.Divide3[(int32_T)0.0F] = TRSC_VC_B.u1wNxN1;

    /* Assignment: '<S93>/Assignment1' */
    TRSC_VC_B.Divide3[Divide5_h_tmp] = TRSC_VC_B.uwNxN;

    /* Assignment: '<S93>/Assignment2' */
    TRSC_VC_B.Divide3[Add2_m_tmp] = TRSC_VC_B.u1wN;

    /* Product: '<S41>/Divide6' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      TRSC_VC_B.fv[Add2_m_tmp] = TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp + 2] *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[2] +
        (TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp + 1] *
         IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[1] +
         TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp] *
         IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[0]);
    }

    /* End of Product: '<S41>/Divide6' */

    /* Product: '<S41>/Divide7' */
    TRSC_VC_B.u1wN = (TRSC_VC_B.fv[0] * TRSC_VC_B.Divide3[0] + TRSC_VC_B.fv[1] *
                      TRSC_VC_B.Divide3[1]) + TRSC_VC_B.fv[2] *
      TRSC_VC_B.Divide3[2];

    /* Sum: '<S41>/Subtract' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.u1wN += IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_WhlRPMYawCov;

    /* Product: '<S41>/Divide2' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      TRSC_VC_B.Divide5_h[Add2_m_tmp] = 0.0F;
      TRSC_VC_B.Divide5_h[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[Add2_m_tmp] *
        TRSC_VC_B.Divide3[0];
      TRSC_VC_B.Divide5_h[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[Add2_m_tmp + 3] *
        TRSC_VC_B.Divide3[1];
      TRSC_VC_B.Divide5_h[Add2_m_tmp] += TRSC_VC_B.Subtract3_a[Add2_m_tmp + 6] *
        TRSC_VC_B.Divide3[2];
    }

    /* End of Product: '<S41>/Divide2' */

    /* Product: '<S41>/Divide1' */
    TRSC_VC_B.Divide3[0] = TRSC_VC_B.Divide5_h[0] / TRSC_VC_B.u1wN;
    TRSC_VC_B.pulse_counter_RR = TRSC_VC_B.Divide5_h[0] / TRSC_VC_B.u1wN;
    TRSC_VC_B.Divide3[1] = TRSC_VC_B.Divide5_h[1] / TRSC_VC_B.u1wN;
    TRSC_VC_B.absx = TRSC_VC_B.Divide5_h[1] / TRSC_VC_B.u1wN;
    TRSC_VC_B.Dt = TRSC_VC_B.Divide5_h[2] / TRSC_VC_B.u1wN;
    TRSC_VC_B.Divide3[2] = TRSC_VC_B.Dt;

    /* Product: '<S41>/Divide5' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      TRSC_VC_B.Divide5_h[3 * Add2_m_tmp] = TRSC_VC_B.pulse_counter_RR *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[Add2_m_tmp];
      TRSC_VC_B.Divide5_h[3 * Add2_m_tmp + 1] = TRSC_VC_B.absx *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[Add2_m_tmp];
      TRSC_VC_B.Divide5_h[3 * Add2_m_tmp + 2] = TRSC_VC_B.Dt *
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[Add2_m_tmp];
    }

    /* End of Product: '<S41>/Divide5' */

    /* Product: '<S41>/Divide8' */
    for (Add2_m_tmp = 0; Add2_m_tmp < 3; Add2_m_tmp++) {
      for (Selector2_tmp = 0; Selector2_tmp < 3; Selector2_tmp++) {
        Divide5_h_tmp = Selector2_tmp + 3 * Add2_m_tmp;
        TRSC_VC_B.Divide8[Divide5_h_tmp] = 0.0F;
        TRSC_VC_B.Divide8[Divide5_h_tmp] += TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp]
          * TRSC_VC_B.Divide5_h[Selector2_tmp];
        TRSC_VC_B.Divide8[Divide5_h_tmp] += TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp
          + 1] * TRSC_VC_B.Divide5_h[Selector2_tmp + 3];
        TRSC_VC_B.Divide8[Divide5_h_tmp] += TRSC_VC_B.Subtract3_a[3 * Add2_m_tmp
          + 2] * TRSC_VC_B.Divide5_h[Selector2_tmp + 6];
      }
    }

    /* End of Product: '<S41>/Divide8' */

    /* Sum: '<S41>/Subtract3' */
    for (i = 0; i < 9; i++) {
      TRSC_VC_B.Subtract3[i] = TRSC_VC_B.Subtract3_a[i] - TRSC_VC_B.Divide8[i];
    }

    /* End of Sum: '<S41>/Subtract3' */

    /* Abs: '<S46>/Abs2' */
    TRSC_VC_B.u1wN = fabsf(TRSC_VC_B.Gain1_h3);

    /* RelationalOperator: '<S46>/Relational Operator2' incorporates:
     *  Constant: '<S46>/CeConst_k_ConstZero2'
     */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.u1wN > CeConst_k_ConstZero);

    /* Abs: '<S46>/Abs3' */
    TRSC_VC_B.u1wN = fabsf(TRSC_VC_B.Gain2_bd);

    /* RelationalOperator: '<S46>/Relational Operator3' incorporates:
     *  Constant: '<S46>/CeConst_k_ConstZero3'
     */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.u1wN > CeConst_k_ConstZero);

    /* Logic: '<S46>/Logical Operator1' */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.RelationalOperator1_e &&
      TRSC_VC_B.LogicalOperator1_fq);

    /* Switch: '<S46>/Switch' */
    if (TRSC_VC_B.RelationalOperator1_e) {
      /* Product: '<S46>/Divide' */
      TRSC_VC_B.Divide_k = TRSC_VC_B.gamma_now_deg_m;

      /* DataTypeConversion: '<S46>/Data Type Conversion' */
      TRSC_VC_B.DataTypeConversion_c = TRSC_VC_B.MeKM_k_Direction;

      /* Product: '<S46>/Divide4' incorporates:
       *  Constant: '<S46>/CeConst_k_ConstZero4'
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.Divide4 = 1.0F /
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_m_TrackWidth;

      /* Sum: '<S46>/Add2' */
      TRSC_VC_B.Product4 = TRSC_VC_B.Gain1_h3 - TRSC_VC_B.Gain2_bd;

      /* Product: '<S46>/Product4' */
      TRSC_VC_B.Product4 = TRSC_VC_B.Product4 * TRSC_VC_B.Divide4 *
        TRSC_VC_B.DataTypeConversion_c * TRSC_VC_B.Divide_k;

      /* DataTypeConversion: '<S46>/Data Type Conversion1' */
      TRSC_VC_B.DataTypeConversion1_d = TRSC_VC_B.Product4;
      TRSC_VC_B.MeKM_ddeg_YawRateWhlRPM = TRSC_VC_B.DataTypeConversion1_d;
    } else {
      /* DataTypeConversion: '<S46>/Data Type Conversion2' incorporates:
       *  Constant: '<S46>/CeConst_k_ConstZero1'
       */
      TRSC_VC_B.DataTypeConversion2 = CeConst_k_ConstZero;
      TRSC_VC_B.MeKM_ddeg_YawRateWhlRPM = TRSC_VC_B.DataTypeConversion2;
    }

    /* UnitDelay: '<S24>/Unit Delay4' */
    TRSC_VC_B.u1wN = TRSC_VC_DW.UnitDelay4_DSTATE;

    /* Sum: '<S24>/Subtract1' */
    TRSC_VC_B.u1wN = TRSC_VC_B.MeKM_ddeg_YawRateWhlRPM - TRSC_VC_B.u1wN;

    /* Product: '<S41>/Divide4' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.uwNxN = (IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[0] *
                       TRSC_VC_B.Assignment1[0] +
                       IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[1] *
                       TRSC_VC_B.Assignment1[1]) +
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[2] *
      TRSC_VC_B.Assignment1[2];

    /* Sum: '<S41>/Subtract1' */
    TRSC_VC_B.u1wN -= TRSC_VC_B.uwNxN;

    /* Product: '<S41>/Divide3' */
    TRSC_VC_B.Divide3[0] *= TRSC_VC_B.u1wN;
    TRSC_VC_B.Divide3[1] *= TRSC_VC_B.u1wN;
    TRSC_VC_B.Divide3[2] *= TRSC_VC_B.u1wN;

    /* Sum: '<S41>/Subtract2' */
    TRSC_VC_B.Subtract2_p[0] = TRSC_VC_B.Divide3[0] + TRSC_VC_B.Assignment1[0];
    TRSC_VC_B.Subtract2_p[1] = TRSC_VC_B.Divide3[1] + TRSC_VC_B.Assignment1[1];
    TRSC_VC_B.Subtract2_p[2] = TRSC_VC_B.Divide3[2] + TRSC_VC_B.Assignment1[2];

    /* Selector: '<S71>/Selector' incorporates:
     *  Constant: '<S58>/CeKM_k_pi2'
     *  Constant: '<S65>/Constant2'
     */
    TRSC_VC_B.u1wN = CeKM_k_ArrayZeros[(int32_T)0.0F];

    /* Assignment: '<S71>/Assignment' incorporates:
     *  Constant: '<S71>/Constant1'
     *  Constant: '<S71>/Constant2'
     */
    TRSC_VC_B.Assignment1[2] = 0.0F;
    TRSC_VC_B.Assignment1[(int32_T)0.0F] = TRSC_VC_B.u1wN;

    /* Selector: '<S71>/Selector1' incorporates:
     *  Assignment: '<S71>/Assignment1'
     *  Constant: '<S58>/CeKM_k_pi2'
     *  Constant: '<S71>/Constant3'
     */
    Add2_m_tmp = (int32_T)1.0F;
    TRSC_VC_B.u1wN = CeKM_k_ArrayZeros[Add2_m_tmp];

    /* Assignment: '<S71>/Assignment1' */
    TRSC_VC_B.Assignment1[Add2_m_tmp] = TRSC_VC_B.u1wN;

    /* Selector: '<S71>/Selector2' incorporates:
     *  Assignment: '<S71>/Assignment2'
     *  Constant: '<S58>/CeKM_k_pi2'
     *  Constant: '<S71>/Constant4'
     */
    Add2_m_tmp = (int32_T)2.0F;
    TRSC_VC_B.u1wN = CeKM_k_ArrayZeros[Add2_m_tmp];

    /* Assignment: '<S71>/Assignment2' */
    TRSC_VC_B.Assignment1[Add2_m_tmp] = TRSC_VC_B.u1wN;

    /* RelationalOperator: '<S59>/Relational Operator' incorporates:
     *  Constant: '<S59>/CeConst_k_ConstTwo'
     */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.IeLSCAN_Cnt_Gear ==
      CeConst_k_ConstTwo);

    /* RelationalOperator: '<S59>/Relational Operator1' incorporates:
     *  Constant: '<S59>/CeKM_k_ConstFour'
     */
    TRSC_VC_B.RelationalOperator1_f = (TRSC_VC_B.IeLSCAN_Cnt_Gear ==
      CeKM_k_ConstFour);

    /* Logic: '<S59>/Logical Operator' */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.LogicalOperator1_fq ||
      TRSC_VC_B.RelationalOperator1_f);

    /* RelationalOperator: '<S59>/Relational Operator2' incorporates:
     *  Constant: '<S59>/CeConst_k_ConstZero2'
     */
    TRSC_VC_B.RelationalOperator1_f = (TRSC_VC_B.IeLSCAN_v_VehSpd !=
      CeConst_k_ConstZero);

    /* Logic: '<S59>/Logical Operator1' */
    TRSC_VC_B.RelationalOperator1_f = (TRSC_VC_B.RelationalOperator1_f &&
      TRSC_VC_B.LogicalOperator1_fq);

    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S59>/CeConst_k_ConstZero'
     *  Constant: '<S59>/CeConst_k_ConstZero1'
     */
    if (TRSC_VC_B.RelationalOperator1_f) {
      TRSC_VC_B.start_avg = CeConst_k_ConstZero;
    } else {
      TRSC_VC_B.start_avg = CeConst_k_ConstOne;
    }

    /* End of Switch: '<S59>/Switch' */

    /* Outputs for Resettable SubSystem: '<S57>/ResettableSubsystem' incorporates:
     *  ResetPort: '<S60>/Reset'
     */
    if ((rt_ZCFcn(ANY_ZERO_CROSSING,
                  &TRSC_VC_PrevZCX.ResettableSubsystem_Reset_ZCE,
                  (TRSC_VC_B.start_avg)) != NO_ZCEVENT) || (TRSC_VC_B.start_avg
         != 0.0F)) {
      /* InitializeConditions for UnitDelay: '<S63>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_b = 0.0F;

      /* InitializeConditions for UnitDelay: '<S63>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_bl = 0.0F;

      /* InitializeConditions for UnitDelay: '<S62>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_pb = 0.0F;

      /* InitializeConditions for UnitDelay: '<S62>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_a = 0.0F;
    }

    /* UnitDelay: '<S63>/Unit Delay' */
    TRSC_VC_B.u1wN = TRSC_VC_DW.UnitDelay_DSTATE_b;

    /* UnitDelay: '<S63>/Unit Delay1' */
    TRSC_VC_B.uwNxN = TRSC_VC_DW.UnitDelay1_DSTATE_bl;

    /* Product: '<S63>/Product' incorporates:
     *  Constant: '<S60>/numpts_init'
     */
    TRSC_VC_B.uwNxN *= CeConst_k_ConstOne;

    /* Sum: '<S63>/Add' */
    TRSC_VC_B.Add_o = TRSC_VC_B.u1wN + TRSC_VC_B.uwNxN;

    /* UnitDelay: '<S62>/Unit Delay' */
    TRSC_VC_B.u1wN = TRSC_VC_DW.UnitDelay_DSTATE_pb;

    /* UnitDelay: '<S62>/Unit Delay1' */
    TRSC_VC_B.uwNxN = TRSC_VC_DW.UnitDelay1_DSTATE_a;

    /* Product: '<S62>/Product' incorporates:
     *  Constant: '<S60>/numpts_init1'
     */
    TRSC_VC_B.uwNxN *= CeConst_k_ConstOne;

    /* Sum: '<S62>/Add' */
    TRSC_VC_B.Add_i = TRSC_VC_B.u1wN + TRSC_VC_B.uwNxN;

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S61>/CeConst_k_ConstZero'
     */
    if (TRSC_VC_B.Add_o > 0.0F) {
      /* Product: '<S61>/Divide' */
      TRSC_VC_B.Divide_p = 1.0F / TRSC_VC_B.Add_o * TRSC_VC_B.Add_i;
      TRSC_VC_B.MeKM_deg_AvgTanAngle = TRSC_VC_B.Divide_p;
    } else {
      TRSC_VC_B.MeKM_deg_AvgTanAngle = CeConst_k_ConstZero;
    }

    /* End of Switch: '<S61>/Switch' */

    /* Lookup_n-D: '<S64>/tan Lookup' */
    TRSC_VC_B.tanVals_p = look1_iflf_linlxpw(TRSC_VC_B.MeKM_k_WhlAngl,
      rtCP_tanLookup_bp01Data, rtCP_tanLookup_tableData, 180U);

    /* Update for UnitDelay: '<S63>/Unit Delay' */
    TRSC_VC_DW.UnitDelay_DSTATE_b = TRSC_VC_B.Add_o;

    /* Update for UnitDelay: '<S63>/Unit Delay1' incorporates:
     *  Constant: '<S60>/numpts_init'
     */
    TRSC_VC_DW.UnitDelay1_DSTATE_bl = CeConst_k_ConstOne;

    /* Update for UnitDelay: '<S62>/Unit Delay' */
    TRSC_VC_DW.UnitDelay_DSTATE_pb = TRSC_VC_B.Add_i;

    /* Update for UnitDelay: '<S62>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_DSTATE_a = TRSC_VC_B.tanVals_p;

    /* End of Outputs for SubSystem: '<S57>/ResettableSubsystem' */

    /* Switch: '<S69>/Switch2' */
    if (TRSC_VC_B.IeLSCAN_v_VehSpd > 0.0F) {
      /* Product: '<S69>/Divide' */
      TRSC_VC_B.Divide_c = TRSC_VC_B.gamma_now_deg_m;

      /* Lookup_n-D: '<S81>/tan Lookup' */
      TRSC_VC_B.Divide5 = look1_iflf_linlxpw(TRSC_VC_B.MeKM_k_WhlAngl,
        rtCP_tanLookup_bp01Data_h, rtCP_tanLookup_tableData_n, 180U);

      /* Product: '<S69>/Divide5' */
      TRSC_VC_B.Divide5 /= TRSC_VC_B.Switch2;

      /* Product: '<S69>/Product6' */
      TRSC_VC_B.yr2 = IeLSCAN_v_VehSp_pulse * TRSC_VC_B.Divide5 *
        TRSC_VC_B.Divide_c * TRSC_VC_B.MeKM_k_Direction;
      TRSC_VC_B.u1wN = TRSC_VC_B.yr2;
    } else {
      /* Product: '<S69>/Divide1' */
      TRSC_VC_B.Divide1 = TRSC_VC_B.gamma_now_deg_m;

      /* Product: '<S69>/Divide6' */
      TRSC_VC_B.Divide6_p = TRSC_VC_B.MeKM_deg_AvgTanAngle / TRSC_VC_B.Switch2;

      /* Product: '<S69>/Product7' */
      TRSC_VC_B.Product7 = IeLSCAN_v_VehSp_pulse * TRSC_VC_B.Divide6_p *
        TRSC_VC_B.Divide1 * TRSC_VC_B.MeKM_k_Direction;
      TRSC_VC_B.u1wN = TRSC_VC_B.Product7;
    }

    /* Assignment: '<S58>/Assignment' */
    TRSC_VC_B.Assignment1[0] = TRSC_VC_B.u1wN;

    /* Product: '<S67>/Divide3' */
    TRSC_VC_B.u1wN = TRSC_VC_B.gamma_now_deg_m;

    /* Gain: '<S67>/Gain' */
    TRSC_VC_B.uwNxN = (-1.0F) * IeLSCAN_v_VehSp_pulse;

    /* Selector: '<S67>/Selector' */
    TRSC_VC_B.Selector_d = TRSC_VC_B.Subtract2[TRSC_VC_B.idxDelay];

    /* RelationalOperator: '<S76>/Relational Operator1' */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.Selector_d >=
      TRSC_VC_ConstB.Gain4_c);

    /* RelationalOperator: '<S76>/Relational Operator5' incorporates:
     *  Constant: '<S76>/90Deg5'
     */
    TRSC_VC_B.RelationalOperator1_f = (90.0F >= TRSC_VC_B.Selector_d);

    /* Logic: '<S76>/Logical Operator1' */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.LogicalOperator1_fq &&
      TRSC_VC_B.RelationalOperator1_f);

    /* Abs: '<S76>/Abs2' */
    TRSC_VC_B.u1wNxN1 = fabsf(TRSC_VC_B.Selector_d);

    /* Sum: '<S76>/Add3' incorporates:
     *  Constant: '<S76>/90Deg5'
     */
    TRSC_VC_B.u1wNxN1 -= 90.0F;

    /* Sum: '<S76>/Add4' incorporates:
     *  Constant: '<S76>/90Deg5'
     */
    TRSC_VC_B.u1wNxN1 = 90.0F - TRSC_VC_B.u1wNxN1;

    /* Lookup_n-D: '<S76>/1-D Lookup Table_0_2' */
    TRSC_VC_B.uDLookupTable_0_2_h = look1_iflf_linlxpw(TRSC_VC_B.u1wNxN1,
      rtCP_uDLookupTable_0_2_bp01Data_l1, rtCP_uDLookupTable_0_2_tableData_m,
      90U);

    /* Switch: '<S76>/Switch1' */
    if (TRSC_VC_B.LogicalOperator1_fq) {
      /* RelationalOperator: '<S76>/Relational Operator6' incorporates:
       *  Constant: '<S76>/Deg_0'
       */
      TRSC_VC_B.RelationalOperator6_gk = (TRSC_VC_B.Selector_d >= 0.0F);

      /* Switch: '<S76>/Switch4' */
      if (TRSC_VC_B.RelationalOperator6_gk) {
        /* Lookup_n-D: '<S76>/1-D Lookup Table_0_6' */
        TRSC_VC_B.uDLookupTable_0_6_hg = look1_iflf_linlxpw(TRSC_VC_B.Selector_d,
          rtCP_uDLookupTable_0_6_bp01Data_e, rtCP_uDLookupTable_0_6_tableData_c,
          90U);
        TRSC_VC_B.Switch4_d = TRSC_VC_B.uDLookupTable_0_6_hg;
      } else {
        /* Gain: '<S76>/Gain5' */
        TRSC_VC_B.uDLookupTable_0_1_h = (-1.0F) * TRSC_VC_B.Selector_d;

        /* Lookup_n-D: '<S76>/1-D Lookup Table_0_1' */
        TRSC_VC_B.uDLookupTable_0_1_h = look1_iflf_linlxpw
          (TRSC_VC_B.uDLookupTable_0_1_h, rtCP_uDLookupTable_0_1_bp01Data_p,
           rtCP_uDLookupTable_0_1_tableData_c, 90U);

        /* Gain: '<S76>/Gain1' */
        TRSC_VC_B.Gain1_ey = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_h;
        TRSC_VC_B.Switch4_d = TRSC_VC_B.Gain1_ey;
      }

      /* End of Switch: '<S76>/Switch4' */
      TRSC_VC_B.u1wNxN1 = TRSC_VC_B.Switch4_d;
    } else {
      /* RelationalOperator: '<S76>/Relational Operator2' incorporates:
       *  Constant: '<S76>/90Deg5'
       */
      TRSC_VC_B.RelationalOperator2_i = (TRSC_VC_B.Selector_d >= 90.0F);

      /* Switch: '<S76>/Switch2' */
      if (TRSC_VC_B.RelationalOperator2_i) {
        TRSC_VC_B.Switch2_ec = TRSC_VC_B.uDLookupTable_0_2_h;
      } else {
        /* Gain: '<S76>/Gain2' */
        TRSC_VC_B.Gain2_ae = (-1.0F) * TRSC_VC_B.uDLookupTable_0_2_h;
        TRSC_VC_B.Switch2_ec = TRSC_VC_B.Gain2_ae;
      }

      /* End of Switch: '<S76>/Switch2' */
      TRSC_VC_B.u1wNxN1 = TRSC_VC_B.Switch2_ec;
    }

    /* End of Switch: '<S76>/Switch1' */

    /* Product: '<S67>/Divide2' */
    TRSC_VC_B.u1wNxN1 /= TRSC_VC_B.Switch6;

    /* Lookup_n-D: '<S77>/tan Lookup' */
    TRSC_VC_B.Product2_j = look1_iflf_linlxpw(TRSC_VC_B.MeKM_k_WhlAngl,
      rtCP_tanLookup_bp01Data_jb, rtCP_tanLookup_tableData_a, 180U);

    /* Product: '<S67>/Divide' */
    TRSC_VC_B.Product2_j /= TRSC_VC_B.Switch2;

    /* Selector: '<S67>/Selector1' */
    TRSC_VC_B.Selector1_m = TRSC_VC_B.Subtract2[TRSC_VC_B.idxDelay];

    /* RelationalOperator: '<S75>/Relational Operator2' */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.Selector1_m >=
      TRSC_VC_ConstB.Gain1_d);

    /* RelationalOperator: '<S75>/Relational Operator3' incorporates:
     *  Constant: '<S75>/90Deg2'
     */
    TRSC_VC_B.RelationalOperator1_f = (90.0F >= TRSC_VC_B.Selector1_m);

    /* Logic: '<S75>/Logical Operator' */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.LogicalOperator1_fq &&
      TRSC_VC_B.RelationalOperator1_f);

    /* Switch: '<S75>/Switch2' */
    if (TRSC_VC_B.LogicalOperator1_fq) {
      /* RelationalOperator: '<S75>/Relational Operator4' incorporates:
       *  Constant: '<S75>/0Deg1'
       */
      TRSC_VC_B.RelationalOperator4_a = (TRSC_VC_B.Selector1_m >= 0.0F);

      /* Switch: '<S75>/Switch3' */
      if (TRSC_VC_B.RelationalOperator4_a) {
        /* Lookup_n-D: '<S75>/1-D Lookup Table_0_3' */
        TRSC_VC_B.uDLookupTable_0_3_m = look1_iflf_linlxpw(TRSC_VC_B.Selector1_m,
          rtCP_uDLookupTable_0_3_bp01Data_n, rtCP_uDLookupTable_0_3_tableData_j,
          90U);
        TRSC_VC_B.Switch3_p = TRSC_VC_B.uDLookupTable_0_3_m;
      } else {
        /* Gain: '<S75>/Gain2' */
        TRSC_VC_B.Gain2_eh = (-1.0F) * TRSC_VC_B.Selector1_m;

        /* Lookup_n-D: '<S75>/1-D Lookup Table_0_2' */
        /*
         * About '<S75>/1-D Lookup Table_0_2':
         *       Table size:  91
         *    Interpolation:  Spline
         *    Extrapolation:  Linear
         *   Breakpt Search:  Linear
         *    Breakpt Cache:  OFF
         */
        TRSC_VC_B.uDLookupTable_0_2_of = look_SplNLinXZf(1U, &TRSC_VC_B.Gain2_eh,
          (rt_LUTSplineWork*)&TRSC_VC_DW.SWork_k[0]);
        TRSC_VC_B.Switch3_p = TRSC_VC_B.uDLookupTable_0_2_of;
      }

      /* End of Switch: '<S75>/Switch3' */
      TRSC_VC_B.Add2_m = TRSC_VC_B.Switch3_p;
    } else {
      /* Abs: '<S75>/Abs1' */
      TRSC_VC_B.uDLookupTable_0_1_k = fabsf(TRSC_VC_B.Selector1_m);

      /* Sum: '<S75>/Add1' incorporates:
       *  Constant: '<S75>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_k -= 90.0F;

      /* Sum: '<S75>/Add2' incorporates:
       *  Constant: '<S75>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_k = 90.0F - TRSC_VC_B.uDLookupTable_0_1_k;

      /* Lookup_n-D: '<S75>/1-D Lookup Table_0_1' */
      TRSC_VC_B.uDLookupTable_0_1_k = look1_iflf_linlxpw
        (TRSC_VC_B.uDLookupTable_0_1_k, rtCP_uDLookupTable_0_1_bp01Data_dd,
         rtCP_uDLookupTable_0_1_tableData_f, 90U);

      /* Gain: '<S75>/Gain3' */
      TRSC_VC_B.Gain3_h = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_k;
      TRSC_VC_B.Add2_m = TRSC_VC_B.Gain3_h;
    }

    /* End of Switch: '<S75>/Switch2' */

    /* Product: '<S67>/Divide1' */
    TRSC_VC_B.Add2_m *= 1.0F / TRSC_VC_B.Switch6;

    /* Product: '<S67>/Product1' */
    TRSC_VC_B.Add2_m *= TRSC_VC_B.Gain2;

    /* Sum: '<S67>/Add2' incorporates:
     *  Constant: '<S67>/CeConst_k_ConstOne'
     */
    TRSC_VC_B.Add2_m += CeConst_k_ConstOne;

    /* Product: '<S67>/Product2' */
    TRSC_VC_B.Product2_j *= TRSC_VC_B.Add2_m;

    /* Sum: '<S67>/Add1' */
    TRSC_VC_B.u1wNxN1 += TRSC_VC_B.Product2_j;

    /* Product: '<S67>/Product4' */
    TRSC_VC_B.uwNxN *= TRSC_VC_B.u1wNxN1;

    /* Product: '<S67>/Product3' */
    TRSC_VC_B.u1wN = TRSC_VC_B.u1wN * TRSC_VC_B.MeKM_k_Direction *
      TRSC_VC_B.uwNxN;

    /* Assignment: '<S58>/Assignment1' */
    TRSC_VC_B.Assignment1[1] = TRSC_VC_B.u1wN;

    /* Switch: '<S70>/Switch2' */
    if (TRSC_VC_B.IeLSCAN_v_VehSpd > 0.0F) {
      /* Selector: '<S70>/Selector3' */
      TRSC_VC_B.Selector3 = TRSC_VC_B.Subtract2[TRSC_VC_B.idxDelay];

      /* Selector: '<S70>/Selector2' */
      TRSC_VC_B.Product4_m = TRSC_VC_B.Subtract2[TRSC_VC_B.k];

      /* Product: '<S70>/Product4' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.Product4_m *=
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_s_SampleTime;

      /* Sum: '<S70>/Add3' */
      TRSC_VC_B.Add3_m = TRSC_VC_B.Product4_m + TRSC_VC_B.Selector3;
      TRSC_VC_B.Switch2_du = TRSC_VC_B.Add3_m;
    }

    /* Assignment: '<S58>/Assignment2' */
    TRSC_VC_B.MaKM_k_x_next[0] = TRSC_VC_B.Assignment1[0];
    TRSC_VC_B.MaKM_k_x_next[1] = TRSC_VC_B.Assignment1[1];
    TRSC_VC_B.MaKM_k_x_next[2] = TRSC_VC_B.Switch2_du;

    /* Abs: '<S45>/Abs' incorporates:
     *  Abs: '<S51>/Abs'
     */
    TRSC_VC_B.Product_DesiredTAD = fabsf(TRSC_VC_B.Product_DesiredTAD);
    TRSC_VC_B.u1wN = TRSC_VC_B.Product_DesiredTAD;

    /* RelationalOperator: '<S45>/Relational Operator' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.u1wN <=
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_k_SWA_Res);

    /* RelationalOperator: '<S45>/Relational Operator1' incorporates:
     *  Constant: '<S45>/CeConst_k_ConstTwo3'
     */
    TRSC_VC_B.RelationalOperator1_f = (TRSC_VC_B.Gain2_bd != CeConst_k_ConstZero);

    /* RelationalOperator: '<S45>/Relational Operator2' incorporates:
     *  Constant: '<S45>/CeConst_k_ConstTwo4'
     */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.Gain1_h3 != CeConst_k_ConstZero);

    /* Logic: '<S45>/Logical Operator1' */
    TRSC_VC_B.LogicalOperator1_fq = (TRSC_VC_B.LogicalOperator1_fq &&
      TRSC_VC_B.RelationalOperator1_f && TRSC_VC_B.LogicalOperator_c);

    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S45>/CeConst_k_ConstTwo1'
     *  Constant: '<S45>/CeConst_k_ConstTwo5'
     */
    if (TRSC_VC_B.LogicalOperator1_fq) {
      TRSC_VC_B.MeKM_k_YawRateWhlRPMEn = CeConst_k_ConstOne;
    } else {
      TRSC_VC_B.MeKM_k_YawRateWhlRPMEn = CeConst_k_ConstZero;
    }

    /* End of Switch: '<S45>/Switch' */

    /* Outputs for Enabled SubSystem: '<S24>/YawRate_RPM_Bias' incorporates:
     *  EnablePort: '<S47>/Enable'
     */
    if (TRSC_VC_B.MeKM_k_YawRateWhlRPMEn > 0.0F) {
      /* UnitDelay: '<S97>/Unit Delay' */
      TRSC_VC_B.u1wN = TRSC_VC_DW.UnitDelay_DSTATE_dj;

      /* UnitDelay: '<S97>/Unit Delay1' */
      TRSC_VC_B.uwNxN = TRSC_VC_DW.UnitDelay1_DSTATE_e;

      /* Product: '<S97>/Product' incorporates:
       *  Constant: '<S96>/numpts_init1'
       */
      TRSC_VC_B.uwNxN *= CeConst_k_ConstOne;

      /* Sum: '<S97>/Add' */
      TRSC_VC_B.Add_pe = TRSC_VC_B.u1wN + TRSC_VC_B.uwNxN;

      /* Sum: '<S47>/Subtract' incorporates:
       *  Constant: '<S47>/numpts_init2'
       */
      TRSC_VC_B.u1wN = TRSC_VC_B.Add_pe - CeConst_k_ConstOne;

      /* UnitDelay: '<S47>/Unit Delay3' */
      TRSC_VC_B.uwNxN = TRSC_VC_DW.UnitDelay3_DSTATE_a;

      /* Product: '<S47>/Multiply' */
      TRSC_VC_B.uwNxN *= TRSC_VC_B.u1wN;

      /* Sum: '<S47>/Add' */
      TRSC_VC_B.uwNxN += TRSC_VC_B.MeKM_ddeg_YawRateWhlRPM;

      /* Product: '<S47>/Divide1' */
      TRSC_VC_B.MeKM_ddeg_YawRateRPM_Bias = TRSC_VC_B.uwNxN / TRSC_VC_B.Add_pe;

      /* Update for UnitDelay: '<S97>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_dj = TRSC_VC_B.Add_pe;

      /* Update for UnitDelay: '<S97>/Unit Delay1' incorporates:
       *  Constant: '<S47>/numpts_init1'
       */
      TRSC_VC_DW.UnitDelay1_DSTATE_e = CeConst_k_ConstOne;

      /* Update for UnitDelay: '<S47>/Unit Delay3' */
      TRSC_VC_DW.UnitDelay3_DSTATE_a = TRSC_VC_B.MeKM_ddeg_YawRateRPM_Bias;
    }

    /* End of Outputs for SubSystem: '<S24>/YawRate_RPM_Bias' */

    /* Switch: '<S46>/Switch1' incorporates:
     *  Constant: '<S46>/CeKM_b_False'
     *  Constant: '<S46>/CeKM_b_True'
     */
    if (TRSC_VC_B.RelationalOperator1_e) {
      TRSC_VC_B.enable_RPM = CeKM_b_True;
    } else {
      TRSC_VC_B.enable_RPM = CeKM_b_False;
    }

    /* End of Switch: '<S46>/Switch1' */

    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S44>/CeConst_k_ConstZero'
     */
    if (IeLSCAN_v_VehSp_pulse > 0.0F) {
      /* Selector: '<S48>/Selector' incorporates:
       *  Constant: '<S48>/CeConst_k_ConstZero'
       */
      TRSC_VC_B.YR = TRSC_VC_B.Subtract2[(int32_T)CeConst_k_ConstZero];
      TRSC_VC_B.MeKM_k_yawrate = TRSC_VC_B.YR;
    } else {
      TRSC_VC_B.MeKM_k_yawrate = CeConst_k_ConstZero;
    }

    /* End of Switch: '<S44>/Switch' */

    /* DataTypeConversion: '<S33>/Data Type Conversion3' */
    TRSC_VC_B.DataTypeConversion3_e = (TRSC_VC_B.DataTypeConversion4_h != 0);

    /* UnitDelay: '<S55>/Delay Input1'
     *
     * Block description for '<S55>/Delay Input1':
     *
     *  Store in Global RAM
     */
    TRSC_VC_B.LogicalOperator_c = TRSC_VC_DW.DelayInput1_DSTATE_g;

    /* RelationalOperator: '<S55>/FixPt Relational Operator' */
    TRSC_VC_B.FixPtRelationalOperator = ((int32_T)
      TRSC_VC_B.DataTypeConversion3_e > (int32_T)TRSC_VC_B.LogicalOperator_c);

    /* Logic: '<S24>/Logical Operator4' */
    TRSC_VC_B.LogicalOperator4 = !TRSC_VC_B.FixPtRelationalOperator;

    /* Outputs for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal1' incorporates:
     *  EnablePort: '<S30>/Enable'
     */
    if (TRSC_VC_B.LogicalOperator4) {
      if (!TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE) {
        /* InitializeConditions for UnitDelay: '<S30>/Unit Delay' */
        TRSC_VC_DW.UnitDelay_DSTATE_m5 = 0.0F;

        /* InitializeConditions for UnitDelay: '<S30>/Unit Delay1' */
        TRSC_VC_DW.UnitDelay1_DSTATE_he = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE = true;
      }

      /* UnitDelay: '<S30>/Unit Delay' */
      TRSC_VC_B.u1wN = TRSC_VC_DW.UnitDelay_DSTATE_m5;

      /* UnitDelay: '<S30>/Unit Delay1' */
      TRSC_VC_B.uwNxN = TRSC_VC_DW.UnitDelay1_DSTATE_he;

      /* Sum: '<S30>/Add1' */
      TRSC_VC_B.uwNxN += TRSC_VC_B.MeKM_k_yawrate;

      /* Product: '<S30>/Divide' incorporates:
       *  Constant: '<S30>/CeConst_k_ConstTwo'
       */
      TRSC_VC_B.uwNxN /= CeConst_k_ConstTwo;

      /* Product: '<S30>/Product' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.uwNxN *= IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_s_SampleTime;

      /* Sum: '<S30>/Add' */
      TRSC_VC_B.MeKM_k_HeadingIn = TRSC_VC_B.u1wN + TRSC_VC_B.uwNxN;

      /* Update for UnitDelay: '<S30>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_m5 = TRSC_VC_B.MeKM_k_HeadingIn;

      /* Update for UnitDelay: '<S30>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_he = TRSC_VC_B.MeKM_k_yawrate;
    } else {
      if (TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE) {
        /* Disable for Outport: '<S30>/MeKM_k_HeadingIn' */
        TRSC_VC_B.MeKM_k_HeadingIn = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S24>/KM_Integrator_Trapazoidal1' */

    /* Gain: '<S35>/Gain' incorporates:
     *  Constant: '<S35>/CeKM_deg_180'
     */
    TRSC_VC_B.u1wN = (-1.0F) * CeKM_deg_180;

    /* RelationalOperator: '<S35>/Relational Operator' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.MeKM_k_HeadingIn < TRSC_VC_B.u1wN);

    /* Abs: '<S35>/Abs' */
    TRSC_VC_B.u1wN = fabsf(TRSC_VC_B.MeKM_k_HeadingIn);

    /* Product: '<S35>/Divide' incorporates:
     *  Constant: '<S35>/CeKM_deg_360_1'
     */
    TRSC_VC_B.gamma_now_deg_m = TRSC_VC_B.u1wN / CeKM_deg_360;
    if (fabsf(TRSC_VC_B.gamma_now_deg_m) < 8.388608E+6F) {
      if (TRSC_VC_B.gamma_now_deg_m > 0.5F) {
        if (!(rt_remf_snf(TRSC_VC_B.gamma_now_deg_m, 2.0F) == 0.5F)) {
          TRSC_VC_B.gamma_now_deg_m += 0.5F;
        }

        TRSC_VC_B.gamma_now_deg_m = floorf(TRSC_VC_B.gamma_now_deg_m);
      } else if (TRSC_VC_B.gamma_now_deg_m >= -0.5F) {
        TRSC_VC_B.gamma_now_deg_m *= 0.0F;
      } else {
        if (!(rt_remf_snf(TRSC_VC_B.gamma_now_deg_m, 2.0F) == -0.5F)) {
          TRSC_VC_B.gamma_now_deg_m -= 0.5F;
        }

        TRSC_VC_B.gamma_now_deg_m = ceilf(TRSC_VC_B.gamma_now_deg_m);
      }
    }

    if (rtIsNaNF(TRSC_VC_B.gamma_now_deg_m) || rtIsInfF
        (TRSC_VC_B.gamma_now_deg_m)) {
      TRSC_VC_B.gamma_now_deg_m = 0.0F;
    } else {
      TRSC_VC_B.gamma_now_deg_m = fmodf(TRSC_VC_B.gamma_now_deg_m, 4.2949673E+9F);
    }

    TRSC_VC_B.Divide = TRSC_VC_B.gamma_now_deg_m < 0.0F ? (uint32_T)-(int32_T)
      (uint32_T)-TRSC_VC_B.gamma_now_deg_m : (uint32_T)TRSC_VC_B.gamma_now_deg_m;

    /* End of Product: '<S35>/Divide' */

    /* RelationalOperator: '<S35>/Relational Operator2' incorporates:
     *  Constant: '<S35>/CeConst_k_ConstZero'
     */
    TRSC_VC_B.RelationalOperator1_e = (TRSC_VC_B.Divide == CeConst_k_ConstZero);

    /* Switch: '<S35>/Switch2' incorporates:
     *  Constant: '<S35>/CeConst_k_ConstOne'
     */
    if (TRSC_VC_B.RelationalOperator1_e) {
      TRSC_VC_B.u1wN = CeConst_k_ConstOne;
    } else {
      TRSC_VC_B.u1wN = (real32_T)TRSC_VC_B.Divide;
    }

    /* End of Switch: '<S35>/Switch2' */

    /* Product: '<S35>/Product' incorporates:
     *  Constant: '<S35>/CeKM_deg_360'
     */
    TRSC_VC_B.Product_a = TRSC_VC_B.u1wN * CeKM_deg_360;

    /* Switch: '<S35>/Switch' */
    if (TRSC_VC_B.LogicalOperator_c) {
      /* Sum: '<S35>/Add3' */
      TRSC_VC_B.Add3_m3 = TRSC_VC_B.MeKM_k_HeadingIn + TRSC_VC_B.Product_a;
      TRSC_VC_B.IeLSCAN_deg_HV_H = TRSC_VC_B.Add3_m3;
    } else {
      /* RelationalOperator: '<S35>/Relational Operator1' incorporates:
       *  Constant: '<S35>/CeKM_deg_180_1'
       */
      TRSC_VC_B.RelationalOperator1_d = (TRSC_VC_B.MeKM_k_HeadingIn >
        CeKM_deg_180);

      /* Switch: '<S35>/Switch1' */
      if (TRSC_VC_B.RelationalOperator1_d) {
        /* Sum: '<S35>/Add2' */
        TRSC_VC_B.Add2_p = TRSC_VC_B.MeKM_k_HeadingIn - TRSC_VC_B.Product_a;
        TRSC_VC_B.Switch1_c = TRSC_VC_B.Add2_p;
      } else {
        TRSC_VC_B.Switch1_c = TRSC_VC_B.MeKM_k_HeadingIn;
      }

      /* End of Switch: '<S35>/Switch1' */
      TRSC_VC_B.IeLSCAN_deg_HV_H = TRSC_VC_B.Switch1_c;
    }

    /* End of Switch: '<S35>/Switch' */

    /* RelationalOperator: '<S49>/Relational Operator2' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.IeLSCAN_deg_HV_H >=
      TRSC_VC_ConstB.Gain1_o);

    /* RelationalOperator: '<S49>/Relational Operator3' incorporates:
     *  Constant: '<S49>/90Deg2'
     */
    TRSC_VC_B.RelationalOperator1_e = (90.0F >= TRSC_VC_B.IeLSCAN_deg_HV_H);

    /* Logic: '<S49>/Logical Operator' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.LogicalOperator_c &&
      TRSC_VC_B.RelationalOperator1_e);

    /* Switch: '<S49>/Switch2' */
    if (TRSC_VC_B.LogicalOperator_c) {
      /* RelationalOperator: '<S49>/Relational Operator4' incorporates:
       *  Constant: '<S49>/0Deg1'
       */
      TRSC_VC_B.RelationalOperator4_b4 = (TRSC_VC_B.IeLSCAN_deg_HV_H >= 0.0F);

      /* Switch: '<S49>/Switch3' */
      if (TRSC_VC_B.RelationalOperator4_b4) {
        /* Lookup_n-D: '<S49>/1-D Lookup Table_0_3' */
        TRSC_VC_B.uDLookupTable_0_3_l = look1_iflf_linlxpw
          (TRSC_VC_B.IeLSCAN_deg_HV_H, rtCP_uDLookupTable_0_3_bp01Data,
           rtCP_uDLookupTable_0_3_tableData, 90U);
        TRSC_VC_B.Switch3_e = TRSC_VC_B.uDLookupTable_0_3_l;
      } else {
        /* Gain: '<S49>/Gain2' */
        TRSC_VC_B.Gain2_d = (-1.0F) * TRSC_VC_B.IeLSCAN_deg_HV_H;

        /* Lookup_n-D: '<S49>/1-D Lookup Table_0_2' */
        TRSC_VC_B.uDLookupTable_0_2_j = look1_iflf_linlxpw(TRSC_VC_B.Gain2_d,
          rtCP_uDLookupTable_0_2_bp01Data, rtCP_uDLookupTable_0_2_tableData, 90U);
        TRSC_VC_B.Switch3_e = TRSC_VC_B.uDLookupTable_0_2_j;
      }

      /* End of Switch: '<S49>/Switch3' */
      TRSC_VC_B.u1wN = TRSC_VC_B.Switch3_e;
    } else {
      /* Abs: '<S49>/Abs1' */
      TRSC_VC_B.uDLookupTable_0_1_d = fabsf(TRSC_VC_B.IeLSCAN_deg_HV_H);

      /* Sum: '<S49>/Add1' incorporates:
       *  Constant: '<S49>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_d -= 90.0F;

      /* Sum: '<S49>/Add2' incorporates:
       *  Constant: '<S49>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_d = 90.0F - TRSC_VC_B.uDLookupTable_0_1_d;

      /* Lookup_n-D: '<S49>/1-D Lookup Table_0_1' */
      TRSC_VC_B.uDLookupTable_0_1_d = look1_iflf_linlxpw
        (TRSC_VC_B.uDLookupTable_0_1_d, rtCP_uDLookupTable_0_1_bp01Data,
         rtCP_uDLookupTable_0_1_tableData, 90U);

      /* Gain: '<S49>/Gain3' */
      TRSC_VC_B.Gain3_ot = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_d;
      TRSC_VC_B.u1wN = TRSC_VC_B.Gain3_ot;
    }

    /* End of Switch: '<S49>/Switch2' */

    /* Product: '<S26>/Product2' */
    TRSC_VC_B.uwNxN = IeLSCAN_v_VehSp_pulse * TRSC_VC_B.MeKM_k_Direction;

    /* Product: '<S26>/Product' */
    TRSC_VC_B.MeKM_m_HV_X = TRSC_VC_B.u1wN * TRSC_VC_B.uwNxN;

    /* Outputs for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal' incorporates:
     *  EnablePort: '<S29>/Enable'
     */
    if (TRSC_VC_B.LogicalOperator4) {
      if (!TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE) {
        /* InitializeConditions for UnitDelay: '<S29>/Unit Delay' */
        TRSC_VC_DW.UnitDelay_DSTATE_kq = 0.0F;

        /* InitializeConditions for UnitDelay: '<S29>/Unit Delay1' */
        TRSC_VC_DW.UnitDelay1_DSTATE_nt = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE = true;
      }

      /* UnitDelay: '<S29>/Unit Delay' */
      TRSC_VC_B.u1wN = TRSC_VC_DW.UnitDelay_DSTATE_kq;

      /* UnitDelay: '<S29>/Unit Delay1' */
      TRSC_VC_B.u1wNxN1 = TRSC_VC_DW.UnitDelay1_DSTATE_nt;

      /* Sum: '<S29>/Add1' */
      TRSC_VC_B.u1wNxN1 += TRSC_VC_B.MeKM_m_HV_X;

      /* Product: '<S29>/Divide' incorporates:
       *  Constant: '<S29>/CeConst_k_ConstTwo'
       */
      TRSC_VC_B.u1wNxN1 /= CeConst_k_ConstTwo;

      /* Product: '<S29>/Product' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.u1wNxN1 *= IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_s_SampleTime;

      /* Sum: '<S29>/Add' */
      TRSC_VC_B.IeLSCAN_m_HV_X = TRSC_VC_B.u1wN + TRSC_VC_B.u1wNxN1;

      /* Update for UnitDelay: '<S29>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_kq = TRSC_VC_B.IeLSCAN_m_HV_X;

      /* Update for UnitDelay: '<S29>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_nt = TRSC_VC_B.MeKM_m_HV_X;
    } else {
      if (TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE) {
        /* Disable for Outport: '<S29>/IeLSCAN_m_HV_X' */
        TRSC_VC_B.IeLSCAN_m_HV_X = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S24>/KM_Integrator_Trapazoidal' */

    /* RelationalOperator: '<S33>/Relational Operator3' incorporates:
     *  Constant: '<S33>/CeConst_k_ConstZero2'
     */
    TRSC_VC_B.IeLSCAN_b_KM_RstRprt = (TRSC_VC_B.IeLSCAN_m_HV_X ==
      CeConst_k_ConstZero);

    /* RelationalOperator: '<S86>/Relational Operator2' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.IeLSCAN_deg_HV_H >=
      TRSC_VC_ConstB.Gain1_h);

    /* RelationalOperator: '<S86>/Relational Operator3' incorporates:
     *  Constant: '<S86>/90Deg2'
     */
    TRSC_VC_B.RelationalOperator1_e = (90.0F >= TRSC_VC_B.IeLSCAN_deg_HV_H);

    /* Logic: '<S86>/Logical Operator' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.LogicalOperator_c &&
      TRSC_VC_B.RelationalOperator1_e);

    /* Switch: '<S86>/Switch2' */
    if (TRSC_VC_B.LogicalOperator_c) {
      /* RelationalOperator: '<S86>/Relational Operator4' incorporates:
       *  Constant: '<S86>/0Deg1'
       */
      TRSC_VC_B.RelationalOperator4_h = (TRSC_VC_B.IeLSCAN_deg_HV_H >= 0.0F);

      /* Switch: '<S86>/Switch3' */
      if (TRSC_VC_B.RelationalOperator4_h) {
        /* Lookup_n-D: '<S86>/1-D Lookup Table_0_3' */
        TRSC_VC_B.uDLookupTable_0_3_n = look1_iflf_linlxpw
          (TRSC_VC_B.IeLSCAN_deg_HV_H, rtCP_uDLookupTable_0_3_bp01Data_lk,
           rtCP_uDLookupTable_0_3_tableData_o, 90U);
        TRSC_VC_B.Switch3_fz = TRSC_VC_B.uDLookupTable_0_3_n;
      } else {
        /* Gain: '<S86>/Gain2' */
        TRSC_VC_B.Gain2_on = (-1.0F) * TRSC_VC_B.IeLSCAN_deg_HV_H;

        /* Lookup_n-D: '<S86>/1-D Lookup Table_0_2' */
        TRSC_VC_B.uDLookupTable_0_2_f = look1_iflf_linlxpw(TRSC_VC_B.Gain2_on,
          rtCP_uDLookupTable_0_2_bp01Data_m, rtCP_uDLookupTable_0_2_tableData_l,
          90U);
        TRSC_VC_B.Switch3_fz = TRSC_VC_B.uDLookupTable_0_2_f;
      }

      /* End of Switch: '<S86>/Switch3' */
      TRSC_VC_B.u1wN = TRSC_VC_B.Switch3_fz;
    } else {
      /* Abs: '<S86>/Abs1' */
      TRSC_VC_B.uDLookupTable_0_1_l = fabsf(TRSC_VC_B.IeLSCAN_deg_HV_H);

      /* Sum: '<S86>/Add1' incorporates:
       *  Constant: '<S86>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_l -= 90.0F;

      /* Sum: '<S86>/Add2' incorporates:
       *  Constant: '<S86>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_l = 90.0F - TRSC_VC_B.uDLookupTable_0_1_l;

      /* Lookup_n-D: '<S86>/1-D Lookup Table_0_1' */
      TRSC_VC_B.uDLookupTable_0_1_l = look1_iflf_linlxpw
        (TRSC_VC_B.uDLookupTable_0_1_l, rtCP_uDLookupTable_0_1_bp01Data_g,
         rtCP_uDLookupTable_0_1_tableData_a, 90U);

      /* Gain: '<S86>/Gain3' */
      TRSC_VC_B.Gain3_o = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_l;
      TRSC_VC_B.u1wN = TRSC_VC_B.Gain3_o;
    }

    /* End of Switch: '<S86>/Switch2' */

    /* Product: '<S83>/Product' */
    TRSC_VC_B.u1wN *= TRSC_VC_B.Gain2;

    /* Selector: '<S48>/Selector1' */
    TRSC_VC_B.u1wNxN1 = TRSC_VC_B.Subtract2[TRSC_VC_B.idxDelay];

    /* Sum: '<S82>/Add' */
    TRSC_VC_B.Add_b = TRSC_VC_B.IeLSCAN_deg_HV_H + TRSC_VC_B.u1wNxN1;

    /* Abs: '<S85>/Abs' */
    TRSC_VC_B.u1wNxN1 = fabsf(TRSC_VC_B.Add_b);

    /* Product: '<S85>/Divide' incorporates:
     *  Constant: '<S85>/CeKM_deg_360_1'
     */
    TRSC_VC_B.gamma_now_deg_m = TRSC_VC_B.u1wNxN1 / CeKM_deg_360;
    if (fabsf(TRSC_VC_B.gamma_now_deg_m) < 8.388608E+6F) {
      if (TRSC_VC_B.gamma_now_deg_m > 0.5F) {
        if (!(rt_remf_snf(TRSC_VC_B.gamma_now_deg_m, 2.0F) == 0.5F)) {
          TRSC_VC_B.gamma_now_deg_m += 0.5F;
        }

        TRSC_VC_B.gamma_now_deg_m = floorf(TRSC_VC_B.gamma_now_deg_m);
      } else if (TRSC_VC_B.gamma_now_deg_m >= -0.5F) {
        TRSC_VC_B.gamma_now_deg_m *= 0.0F;
      } else {
        if (!(rt_remf_snf(TRSC_VC_B.gamma_now_deg_m, 2.0F) == -0.5F)) {
          TRSC_VC_B.gamma_now_deg_m -= 0.5F;
        }

        TRSC_VC_B.gamma_now_deg_m = ceilf(TRSC_VC_B.gamma_now_deg_m);
      }
    }

    if (rtIsNaNF(TRSC_VC_B.gamma_now_deg_m) || rtIsInfF
        (TRSC_VC_B.gamma_now_deg_m)) {
      TRSC_VC_B.gamma_now_deg_m = 0.0F;
    } else {
      TRSC_VC_B.gamma_now_deg_m = fmodf(TRSC_VC_B.gamma_now_deg_m, 4.2949673E+9F);
    }

    TRSC_VC_B.Divide = TRSC_VC_B.gamma_now_deg_m < 0.0F ? (uint32_T)-(int32_T)
      (uint32_T)-TRSC_VC_B.gamma_now_deg_m : (uint32_T)TRSC_VC_B.gamma_now_deg_m;

    /* End of Product: '<S85>/Divide' */

    /* RelationalOperator: '<S85>/Relational Operator2' incorporates:
     *  Constant: '<S85>/CeConst_k_ConstZero'
     */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.Divide == CeConst_k_ConstZero);

    /* Switch: '<S85>/Switch2' incorporates:
     *  Constant: '<S85>/CeConst_k_ConstOne'
     */
    if (TRSC_VC_B.LogicalOperator_c) {
      TRSC_VC_B.u1wNxN1 = CeConst_k_ConstOne;
    } else {
      TRSC_VC_B.u1wNxN1 = (real32_T)TRSC_VC_B.Divide;
    }

    /* End of Switch: '<S85>/Switch2' */

    /* Product: '<S85>/Product' incorporates:
     *  Constant: '<S85>/CeKM_deg_360'
     */
    TRSC_VC_B.Product_l = TRSC_VC_B.u1wNxN1 * CeKM_deg_360;

    /* Gain: '<S85>/Gain' incorporates:
     *  Constant: '<S85>/CeKM_deg_180'
     */
    TRSC_VC_B.u1wNxN1 = (-1.0F) * CeKM_deg_180;

    /* RelationalOperator: '<S85>/Relational Operator' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.Add_b < TRSC_VC_B.u1wNxN1);

    /* Switch: '<S85>/Switch' */
    if (TRSC_VC_B.LogicalOperator_c) {
      /* Sum: '<S85>/Add3' */
      TRSC_VC_B.Add3_f = TRSC_VC_B.Add_b + TRSC_VC_B.Product_l;
      TRSC_VC_B.IeLSCAN_deg_TH = TRSC_VC_B.Add3_f;
    } else {
      /* RelationalOperator: '<S85>/Relational Operator1' incorporates:
       *  Constant: '<S85>/CeKM_deg_180_1'
       */
      TRSC_VC_B.RelationalOperator1_j = (TRSC_VC_B.Add_b > CeKM_deg_180);

      /* Switch: '<S85>/Switch1' */
      if (TRSC_VC_B.RelationalOperator1_j) {
        /* Sum: '<S85>/Add2' */
        TRSC_VC_B.Add2_i = TRSC_VC_B.Add_b - TRSC_VC_B.Product_l;
        TRSC_VC_B.Switch1_o = TRSC_VC_B.Add2_i;
      } else {
        TRSC_VC_B.Switch1_o = TRSC_VC_B.Add_b;
      }

      /* End of Switch: '<S85>/Switch1' */
      TRSC_VC_B.IeLSCAN_deg_TH = TRSC_VC_B.Switch1_o;
    }

    /* End of Switch: '<S85>/Switch' */

    /* RelationalOperator: '<S87>/Relational Operator2' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.IeLSCAN_deg_TH >=
      TRSC_VC_ConstB.Gain1_hh);

    /* RelationalOperator: '<S87>/Relational Operator3' incorporates:
     *  Constant: '<S87>/90Deg2'
     */
    TRSC_VC_B.RelationalOperator1_e = (90.0F >= TRSC_VC_B.IeLSCAN_deg_TH);

    /* Logic: '<S87>/Logical Operator' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.LogicalOperator_c &&
      TRSC_VC_B.RelationalOperator1_e);

    /* Switch: '<S87>/Switch2' */
    if (TRSC_VC_B.LogicalOperator_c) {
      /* RelationalOperator: '<S87>/Relational Operator4' incorporates:
       *  Constant: '<S87>/0Deg1'
       */
      TRSC_VC_B.RelationalOperator4_b = (TRSC_VC_B.IeLSCAN_deg_TH >= 0.0F);

      /* Switch: '<S87>/Switch3' */
      if (TRSC_VC_B.RelationalOperator4_b) {
        /* Lookup_n-D: '<S87>/1-D Lookup Table_0_3' */
        TRSC_VC_B.uDLookupTable_0_3_e = look1_iflf_linlxpw
          (TRSC_VC_B.IeLSCAN_deg_TH, rtCP_uDLookupTable_0_3_bp01Data_e,
           rtCP_uDLookupTable_0_3_tableData_nw, 90U);
        TRSC_VC_B.Switch3_c = TRSC_VC_B.uDLookupTable_0_3_e;
      } else {
        /* Gain: '<S87>/Gain2' */
        TRSC_VC_B.Gain2_l = (-1.0F) * TRSC_VC_B.IeLSCAN_deg_TH;

        /* Lookup_n-D: '<S87>/1-D Lookup Table_0_2' */
        TRSC_VC_B.uDLookupTable_0_2_e = look1_iflf_linlxpw(TRSC_VC_B.Gain2_l,
          rtCP_uDLookupTable_0_2_bp01Data_l, rtCP_uDLookupTable_0_2_tableData_b,
          90U);
        TRSC_VC_B.Switch3_c = TRSC_VC_B.uDLookupTable_0_2_e;
      }

      /* End of Switch: '<S87>/Switch3' */
      TRSC_VC_B.u1wNxN1 = TRSC_VC_B.Switch3_c;
    } else {
      /* Abs: '<S87>/Abs1' */
      TRSC_VC_B.uDLookupTable_0_1_im = fabsf(TRSC_VC_B.IeLSCAN_deg_TH);

      /* Sum: '<S87>/Add1' incorporates:
       *  Constant: '<S87>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_im -= 90.0F;

      /* Sum: '<S87>/Add2' incorporates:
       *  Constant: '<S87>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_im = 90.0F - TRSC_VC_B.uDLookupTable_0_1_im;

      /* Lookup_n-D: '<S87>/1-D Lookup Table_0_1' */
      TRSC_VC_B.uDLookupTable_0_1_im = look1_iflf_linlxpw
        (TRSC_VC_B.uDLookupTable_0_1_im, rtCP_uDLookupTable_0_1_bp01Data_m,
         rtCP_uDLookupTable_0_1_tableData_j, 90U);

      /* Gain: '<S87>/Gain3' */
      TRSC_VC_B.Gain3_c = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_im;
      TRSC_VC_B.u1wNxN1 = TRSC_VC_B.Gain3_c;
    }

    /* End of Switch: '<S87>/Switch2' */

    /* Product: '<S83>/Product1' */
    TRSC_VC_B.u1wNxN1 *= TRSC_VC_B.Switch6;

    /* Sum: '<S83>/Add2' */
    TRSC_VC_B.u1wN += TRSC_VC_B.u1wNxN1;

    /* Sum: '<S83>/Add3' */
    KM_MABx.IeLSCAN_m_TX = TRSC_VC_B.IeLSCAN_m_HV_X - TRSC_VC_B.u1wN;

    /* RelationalOperator: '<S89>/Relational Operator1' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.IeLSCAN_deg_TH >=
      TRSC_VC_ConstB.Gain4_j);

    /* RelationalOperator: '<S89>/Relational Operator5' incorporates:
     *  Constant: '<S89>/90Deg5'
     */
    TRSC_VC_B.RelationalOperator1_e = (90.0F >= TRSC_VC_B.IeLSCAN_deg_TH);

    /* Logic: '<S89>/Logical Operator1' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.LogicalOperator_c &&
      TRSC_VC_B.RelationalOperator1_e);

    /* Abs: '<S89>/Abs2' */
    TRSC_VC_B.u1wN = fabsf(TRSC_VC_B.IeLSCAN_deg_TH);

    /* Sum: '<S89>/Add3' incorporates:
     *  Constant: '<S89>/90Deg5'
     */
    TRSC_VC_B.u1wN -= 90.0F;

    /* Sum: '<S89>/Add4' incorporates:
     *  Constant: '<S89>/90Deg5'
     */
    TRSC_VC_B.u1wN = 90.0F - TRSC_VC_B.u1wN;

    /* Lookup_n-D: '<S89>/1-D Lookup Table_0_2' */
    TRSC_VC_B.uDLookupTable_0_2_g = look1_iflf_linlxpw(TRSC_VC_B.u1wN,
      rtCP_uDLookupTable_0_2_bp01Data_o, rtCP_uDLookupTable_0_2_tableData_f2,
      90U);

    /* Switch: '<S89>/Switch1' */
    if (TRSC_VC_B.LogicalOperator_c) {
      /* RelationalOperator: '<S89>/Relational Operator6' incorporates:
       *  Constant: '<S89>/Deg_0'
       */
      TRSC_VC_B.RelationalOperator6_a = (TRSC_VC_B.IeLSCAN_deg_TH >= 0.0F);

      /* Switch: '<S89>/Switch4' */
      if (TRSC_VC_B.RelationalOperator6_a) {
        /* Lookup_n-D: '<S89>/1-D Lookup Table_0_6' */
        TRSC_VC_B.uDLookupTable_0_6_a = look1_iflf_linlxpw
          (TRSC_VC_B.IeLSCAN_deg_TH, rtCP_uDLookupTable_0_6_bp01Data_d,
           rtCP_uDLookupTable_0_6_tableData_l, 90U);
        TRSC_VC_B.Switch4_b = TRSC_VC_B.uDLookupTable_0_6_a;
      } else {
        /* Gain: '<S89>/Gain5' */
        TRSC_VC_B.uDLookupTable_0_1_o = (-1.0F) * TRSC_VC_B.IeLSCAN_deg_TH;

        /* Lookup_n-D: '<S89>/1-D Lookup Table_0_1' */
        TRSC_VC_B.uDLookupTable_0_1_o = look1_iflf_linlxpw
          (TRSC_VC_B.uDLookupTable_0_1_o, rtCP_uDLookupTable_0_1_bp01Data_ml,
           rtCP_uDLookupTable_0_1_tableData_o, 90U);

        /* Gain: '<S89>/Gain1' */
        TRSC_VC_B.Gain1_n = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_o;
        TRSC_VC_B.Switch4_b = TRSC_VC_B.Gain1_n;
      }

      /* End of Switch: '<S89>/Switch4' */
      TRSC_VC_B.u1wN = TRSC_VC_B.Switch4_b;
    } else {
      /* RelationalOperator: '<S89>/Relational Operator2' incorporates:
       *  Constant: '<S89>/90Deg5'
       */
      TRSC_VC_B.RelationalOperator2_p = (TRSC_VC_B.IeLSCAN_deg_TH >= 90.0F);

      /* Switch: '<S89>/Switch2' */
      if (TRSC_VC_B.RelationalOperator2_p) {
        TRSC_VC_B.Switch2_ju = TRSC_VC_B.uDLookupTable_0_2_g;
      } else {
        /* Gain: '<S89>/Gain2' */
        TRSC_VC_B.Gain2_f = (-1.0F) * TRSC_VC_B.uDLookupTable_0_2_g;
        TRSC_VC_B.Switch2_ju = TRSC_VC_B.Gain2_f;
      }

      /* End of Switch: '<S89>/Switch2' */
      TRSC_VC_B.u1wN = TRSC_VC_B.Switch2_ju;
    }

    /* End of Switch: '<S89>/Switch1' */

    /* Product: '<S84>/Product1' */
    TRSC_VC_B.u1wN *= TRSC_VC_B.Switch6;

    /* RelationalOperator: '<S88>/Relational Operator1' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.IeLSCAN_deg_HV_H >=
      TRSC_VC_ConstB.Gain4_cf);

    /* RelationalOperator: '<S88>/Relational Operator5' incorporates:
     *  Constant: '<S88>/90Deg5'
     */
    TRSC_VC_B.RelationalOperator1_e = (90.0F >= TRSC_VC_B.IeLSCAN_deg_HV_H);

    /* Logic: '<S88>/Logical Operator1' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.LogicalOperator_c &&
      TRSC_VC_B.RelationalOperator1_e);

    /* Abs: '<S88>/Abs2' */
    TRSC_VC_B.u1wNxN1 = fabsf(TRSC_VC_B.IeLSCAN_deg_HV_H);

    /* Sum: '<S88>/Add3' incorporates:
     *  Constant: '<S88>/90Deg5'
     */
    TRSC_VC_B.u1wNxN1 -= 90.0F;

    /* Sum: '<S88>/Add4' incorporates:
     *  Constant: '<S88>/90Deg5'
     */
    TRSC_VC_B.u1wNxN1 = 90.0F - TRSC_VC_B.u1wNxN1;

    /* Lookup_n-D: '<S88>/1-D Lookup Table_0_2' */
    TRSC_VC_B.uDLookupTable_0_2_a = look1_iflf_linlxpw(TRSC_VC_B.u1wNxN1,
      rtCP_uDLookupTable_0_2_bp01Data_mn, rtCP_uDLookupTable_0_2_tableData_d,
      90U);

    /* Switch: '<S88>/Switch1' */
    if (TRSC_VC_B.LogicalOperator_c) {
      /* RelationalOperator: '<S88>/Relational Operator6' incorporates:
       *  Constant: '<S88>/Deg_0'
       */
      TRSC_VC_B.RelationalOperator6_o = (TRSC_VC_B.IeLSCAN_deg_HV_H >= 0.0F);

      /* Switch: '<S88>/Switch4' */
      if (TRSC_VC_B.RelationalOperator6_o) {
        /* Lookup_n-D: '<S88>/1-D Lookup Table_0_6' */
        TRSC_VC_B.uDLookupTable_0_6_h = look1_iflf_linlxpw
          (TRSC_VC_B.IeLSCAN_deg_HV_H, rtCP_uDLookupTable_0_6_bp01Data_c,
           rtCP_uDLookupTable_0_6_tableData_m, 90U);
        TRSC_VC_B.Switch4_j = TRSC_VC_B.uDLookupTable_0_6_h;
      } else {
        /* Gain: '<S88>/Gain5' */
        TRSC_VC_B.uDLookupTable_0_1_j = (-1.0F) * TRSC_VC_B.IeLSCAN_deg_HV_H;

        /* Lookup_n-D: '<S88>/1-D Lookup Table_0_1' */
        TRSC_VC_B.uDLookupTable_0_1_j = look1_iflf_linlxpw
          (TRSC_VC_B.uDLookupTable_0_1_j, rtCP_uDLookupTable_0_1_bp01Data_mf,
           rtCP_uDLookupTable_0_1_tableData_pl, 90U);

        /* Gain: '<S88>/Gain1' */
        TRSC_VC_B.Gain1_f = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_j;
        TRSC_VC_B.Switch4_j = TRSC_VC_B.Gain1_f;
      }

      /* End of Switch: '<S88>/Switch4' */
      TRSC_VC_B.u1wNxN1 = TRSC_VC_B.Switch4_j;
    } else {
      /* RelationalOperator: '<S88>/Relational Operator2' incorporates:
       *  Constant: '<S88>/90Deg5'
       */
      TRSC_VC_B.RelationalOperator2_l = (TRSC_VC_B.IeLSCAN_deg_HV_H >= 90.0F);

      /* Switch: '<S88>/Switch2' */
      if (TRSC_VC_B.RelationalOperator2_l) {
        TRSC_VC_B.Switch2_dh = TRSC_VC_B.uDLookupTable_0_2_a;
      } else {
        /* Gain: '<S88>/Gain2' */
        TRSC_VC_B.Gain2_n = (-1.0F) * TRSC_VC_B.uDLookupTable_0_2_a;
        TRSC_VC_B.Switch2_dh = TRSC_VC_B.Gain2_n;
      }

      /* End of Switch: '<S88>/Switch2' */
      TRSC_VC_B.u1wNxN1 = TRSC_VC_B.Switch2_dh;
    }

    /* End of Switch: '<S88>/Switch1' */

    /* Product: '<S84>/Product' */
    TRSC_VC_B.u1wNxN1 *= TRSC_VC_B.Gain2;

    /* Sum: '<S84>/Add2' */
    TRSC_VC_B.u1wNxN1 += TRSC_VC_B.u1wN;

    /* RelationalOperator: '<S50>/Relational Operator1' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.IeLSCAN_deg_HV_H >=
      TRSC_VC_ConstB.Gain4_m);

    /* RelationalOperator: '<S50>/Relational Operator5' incorporates:
     *  Constant: '<S50>/90Deg5'
     */
    TRSC_VC_B.RelationalOperator1_e = (90.0F >= TRSC_VC_B.IeLSCAN_deg_HV_H);

    /* Logic: '<S50>/Logical Operator1' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.LogicalOperator_c &&
      TRSC_VC_B.RelationalOperator1_e);

    /* Abs: '<S50>/Abs2' */
    TRSC_VC_B.u1wN = fabsf(TRSC_VC_B.IeLSCAN_deg_HV_H);

    /* Sum: '<S50>/Add3' incorporates:
     *  Constant: '<S50>/90Deg5'
     */
    TRSC_VC_B.u1wN -= 90.0F;

    /* Sum: '<S50>/Add4' incorporates:
     *  Constant: '<S50>/90Deg5'
     */
    TRSC_VC_B.u1wN = 90.0F - TRSC_VC_B.u1wN;

    /* Lookup_n-D: '<S50>/1-D Lookup Table_0_2' */
    TRSC_VC_B.uDLookupTable_0_2_b = look1_iflf_linlxpw(TRSC_VC_B.u1wN,
      rtCP_uDLookupTable_0_2_bp01Data_oy, rtCP_uDLookupTable_0_2_tableData_lt,
      90U);

    /* Switch: '<S50>/Switch1' */
    if (TRSC_VC_B.LogicalOperator_c) {
      /* RelationalOperator: '<S50>/Relational Operator6' incorporates:
       *  Constant: '<S50>/Deg_0'
       */
      TRSC_VC_B.RelationalOperator6_f = (TRSC_VC_B.IeLSCAN_deg_HV_H >= 0.0F);

      /* Switch: '<S50>/Switch4' */
      if (TRSC_VC_B.RelationalOperator6_f) {
        /* Lookup_n-D: '<S50>/1-D Lookup Table_0_6' */
        TRSC_VC_B.uDLookupTable_0_6_i0 = look1_iflf_linlxpw
          (TRSC_VC_B.IeLSCAN_deg_HV_H, rtCP_uDLookupTable_0_6_bp01Data,
           rtCP_uDLookupTable_0_6_tableData, 90U);
        TRSC_VC_B.Switch4_a = TRSC_VC_B.uDLookupTable_0_6_i0;
      } else {
        /* Gain: '<S50>/Gain5' */
        TRSC_VC_B.uDLookupTable_0_1_p = (-1.0F) * TRSC_VC_B.IeLSCAN_deg_HV_H;

        /* Lookup_n-D: '<S50>/1-D Lookup Table_0_1' */
        TRSC_VC_B.uDLookupTable_0_1_p = look1_iflf_linlxpw
          (TRSC_VC_B.uDLookupTable_0_1_p, rtCP_uDLookupTable_0_1_bp01Data_d,
           rtCP_uDLookupTable_0_1_tableData_i, 90U);

        /* Gain: '<S50>/Gain1' */
        TRSC_VC_B.Gain1_hs = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_p;
        TRSC_VC_B.Switch4_a = TRSC_VC_B.Gain1_hs;
      }

      /* End of Switch: '<S50>/Switch4' */
      TRSC_VC_B.u1wN = TRSC_VC_B.Switch4_a;
    } else {
      /* RelationalOperator: '<S50>/Relational Operator2' incorporates:
       *  Constant: '<S50>/90Deg5'
       */
      TRSC_VC_B.RelationalOperator2_bi = (TRSC_VC_B.IeLSCAN_deg_HV_H >= 90.0F);

      /* Switch: '<S50>/Switch2' */
      if (TRSC_VC_B.RelationalOperator2_bi) {
        TRSC_VC_B.Switch2_cz = TRSC_VC_B.uDLookupTable_0_2_b;
      } else {
        /* Gain: '<S50>/Gain2' */
        TRSC_VC_B.Gain2_c = (-1.0F) * TRSC_VC_B.uDLookupTable_0_2_b;
        TRSC_VC_B.Switch2_cz = TRSC_VC_B.Gain2_c;
      }

      /* End of Switch: '<S50>/Switch2' */
      TRSC_VC_B.u1wN = TRSC_VC_B.Switch2_cz;
    }

    /* End of Switch: '<S50>/Switch1' */

    /* Product: '<S26>/Product1' */
    TRSC_VC_B.MeKM_m_HV_Y = TRSC_VC_B.uwNxN * TRSC_VC_B.u1wN;

    /* Outputs for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal2' incorporates:
     *  EnablePort: '<S31>/Enable'
     */
    if (TRSC_VC_B.LogicalOperator4) {
      if (!TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE) {
        /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
        TRSC_VC_DW.UnitDelay_DSTATE_m = 0.0F;

        /* InitializeConditions for UnitDelay: '<S31>/Unit Delay1' */
        TRSC_VC_DW.UnitDelay1_DSTATE_p = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE = true;
      }

      /* UnitDelay: '<S31>/Unit Delay' */
      TRSC_VC_B.u1wN = TRSC_VC_DW.UnitDelay_DSTATE_m;

      /* UnitDelay: '<S31>/Unit Delay1' */
      TRSC_VC_B.uwNxN = TRSC_VC_DW.UnitDelay1_DSTATE_p;

      /* Sum: '<S31>/Add1' */
      TRSC_VC_B.uwNxN += TRSC_VC_B.MeKM_m_HV_Y;

      /* Product: '<S31>/Divide' incorporates:
       *  Constant: '<S31>/CeConst_k_ConstTwo'
       */
      TRSC_VC_B.uwNxN /= CeConst_k_ConstTwo;

      /* Product: '<S31>/Product' incorporates:
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_VC_B.uwNxN *= IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_s_SampleTime;

      /* Sum: '<S31>/Add' */
      TRSC_VC_B.IeLSCAN_m_HV_Y = TRSC_VC_B.u1wN + TRSC_VC_B.uwNxN;

      /* Update for UnitDelay: '<S31>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_m = TRSC_VC_B.IeLSCAN_m_HV_Y;

      /* Update for UnitDelay: '<S31>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_p = TRSC_VC_B.MeKM_m_HV_Y;
    } else {
      if (TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE) {
        /* Disable for Outport: '<S31>/IeLSCAN_m_HV_Y' */
        TRSC_VC_B.IeLSCAN_m_HV_Y = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S24>/KM_Integrator_Trapazoidal2' */

    /* Sum: '<S84>/Add3' */
    KM_MABx.IeLSCAN_m_TY = TRSC_VC_B.IeLSCAN_m_HV_Y - TRSC_VC_B.u1wNxN1;

    /* RelationalOperator: '<S33>/Relational Operator2' incorporates:
     *  Constant: '<S33>/CeConst_k_ConstZero1'
     */
    TRSC_VC_B.RelationalOperator2 = (TRSC_VC_B.IeLSCAN_m_HV_Y ==
      CeConst_k_ConstZero);

    /* RelationalOperator: '<S33>/Relational Operator1' incorporates:
     *  Constant: '<S33>/CeConst_k_ConstZero'
     */
    TRSC_VC_B.RelationalOperator1 = (TRSC_VC_B.MeKM_k_HeadingIn ==
      CeConst_k_ConstZero);

    /* UnitDelay: '<S56>/Unit Delay' */
    TRSC_VC_B.UnitDelay_g = TRSC_VC_DW.UnitDelay_DSTATE_kz;

    /* UnitDelay: '<S33>/Unit Delay1' */
    TRSC_VC_B.LogicalOperator_c = TRSC_VC_DW.UnitDelay1_DSTATE_pk;

    /* Switch: '<S56>/Switch1' incorporates:
     *  Constant: '<S56>/CeConst_k_ConstZero1'
     */
    if (TRSC_VC_B.LogicalOperator_c) {
      TRSC_VC_B.MeKM_b_ResetKM = CeKM_b_False;
    } else {
      /* Logic: '<S56>/Logical Operator' */
      TRSC_VC_B.LogicalOperator = (TRSC_VC_B.FixPtRelationalOperator ||
        TRSC_VC_B.UnitDelay_g);
      TRSC_VC_B.MeKM_b_ResetKM = TRSC_VC_B.LogicalOperator;
    }

    /* End of Switch: '<S56>/Switch1' */

    /* RelationalOperator: '<S51>/Relational Operator' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.Product_DesiredTAD <
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeKM_deg_AngTh);

    /* RelationalOperator: '<S51>/Relational Operator1' incorporates:
     *  Constant: '<S51>/CeConst_k_ConstZero1'
     */
    TRSC_VC_B.RelationalOperator1_e = (IeLSCAN_v_VehSp_pulse ==
      CeConst_k_ConstZero);

    /* Logic: '<S51>/Logical Operator' */
    TRSC_VC_B.LogicalOperator_c = (TRSC_VC_B.LogicalOperator_c ||
      TRSC_VC_B.RelationalOperator1_e);

    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S51>/CeConst_k_ConstOne'
     *  Constant: '<S51>/CeConst_k_ConstZero'
     */
    if (TRSC_VC_B.LogicalOperator_c) {
      TRSC_VC_B.Switch_e = CeConst_k_ConstOne;
    } else {
      TRSC_VC_B.Switch_e = CeConst_k_ConstZero;
    }

    /* End of Switch: '<S51>/Switch' */

    /* Outputs for Enabled SubSystem: '<S28>/Gyro_YawRate_Bias' incorporates:
     *  EnablePort: '<S53>/Enable'
     */
    if (TRSC_VC_B.Switch_e > 0.0F) {
      /* UnitDelay: '<S54>/Unit Delay' */
      TRSC_VC_B.u1wN = TRSC_VC_DW.UnitDelay_DSTATE_d1;

      /* Product: '<S54>/Product' incorporates:
       *  Constant: '<S53>/CeConst_k_ConstOne'
       */
      TRSC_VC_B.u1wN *= CeConst_k_ConstOne;

      /* Sum: '<S54>/Sum' incorporates:
       *  Constant: '<S54>/Constant1'
       */
      TRSC_VC_B.wN = TRSC_VC_B.u1wN + 1.0F;

      /* Product: '<S54>/Divide' incorporates:
       *  Constant: '<S54>/Constant1'
       */
      TRSC_VC_B.u1wN = 1.0F / TRSC_VC_B.wN;

      /* Product: '<S54>/Product1' */
      TRSC_VC_B.uwNxN = TRSC_VC_B.u1wN * TRSC_VC_B.Product_k;

      /* UnitDelay: '<S54>/Unit Delay1' */
      TRSC_VC_B.u1wNxN1 = TRSC_VC_DW.UnitDelay1_DSTATE_oq;

      /* Sum: '<S54>/Sum1' incorporates:
       *  Constant: '<S54>/Constant1'
       */
      TRSC_VC_B.u1wN = 1.0F - TRSC_VC_B.u1wN;

      /* Product: '<S54>/Product2' */
      TRSC_VC_B.u1wNxN1 *= TRSC_VC_B.u1wN;

      /* Sum: '<S54>/Sum2' */
      TRSC_VC_B.xN = TRSC_VC_B.u1wNxN1 + TRSC_VC_B.uwNxN;

      /* Update for UnitDelay: '<S54>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_d1 = TRSC_VC_B.wN;

      /* Update for UnitDelay: '<S54>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_oq = TRSC_VC_B.xN;
    }

    /* End of Outputs for SubSystem: '<S28>/Gyro_YawRate_Bias' */

    /* Update for UnitDelay: '<S24>/Unit Delay5' */
    TRSC_VC_DW.UnitDelay5_DSTATE = TRSC_VC_B.FixPtRelationalOperator;

    /* Update for UnitDelay: '<S37>/Unit Delay' */
    TRSC_VC_DW.UnitDelay_DSTATE_e = IeLSCAN_v_VehSp_pulse;

    /* Update for Delay: '<S24>/Delay' */
    TRSC_VC_DW.icLoad_c = 0U;
    TRSC_VC_DW.Delay_DSTATE_k[0] = TRSC_VC_DW.Delay_DSTATE_k[1];

    /* Update for Delay: '<S24>/Delay1' */
    TRSC_VC_DW.Delay1_DSTATE_d[0] = TRSC_VC_DW.Delay1_DSTATE_d[1];

    /* Update for Delay: '<S24>/Delay' */
    TRSC_VC_DW.Delay_DSTATE_k[1] = TRSC_VC_DW.Delay_DSTATE_k[2];

    /* Update for Delay: '<S24>/Delay1' */
    TRSC_VC_DW.Delay1_DSTATE_d[1] = TRSC_VC_DW.Delay1_DSTATE_d[2];

    /* Update for Delay: '<S24>/Delay' */
    TRSC_VC_DW.Delay_DSTATE_k[2] = TRSC_VC_DW.Delay_DSTATE_k[3];

    /* Update for Delay: '<S24>/Delay1' */
    TRSC_VC_DW.Delay1_DSTATE_d[2] = TRSC_VC_DW.Delay1_DSTATE_d[3];

    /* Update for Delay: '<S24>/Delay' */
    TRSC_VC_DW.Delay_DSTATE_k[3] = TRSC_VC_DW.Delay_DSTATE_k[4];

    /* Update for Delay: '<S24>/Delay1' */
    TRSC_VC_DW.Delay1_DSTATE_d[3] = TRSC_VC_DW.Delay1_DSTATE_d[4];

    /* Update for Delay: '<S24>/Delay' */
    TRSC_VC_DW.Delay_DSTATE_k[4] = TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRR;

    /* Update for Delay: '<S24>/Delay1' */
    TRSC_VC_DW.icLoad_jq = 0U;
    TRSC_VC_DW.Delay1_DSTATE_d[4] = TRSC_VC_B.IeLSCAN_Cnt_WhlPlsCntRL;

    /* Update for UnitDelay: '<S24>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_DSTATE_m[0] = TRSC_VC_B.MaKM_k_x_next[0];
    TRSC_VC_DW.UnitDelay1_DSTATE_m[1] = TRSC_VC_B.MaKM_k_x_next[1];
    TRSC_VC_DW.UnitDelay1_DSTATE_m[2] = TRSC_VC_B.MaKM_k_x_next[2];

    /* Update for UnitDelay: '<S28>/Unit Delay' */
    TRSC_VC_DW.UnitDelay_DSTATE_k = TRSC_VC_B.xN;

    /* Update for UnitDelay: '<S24>/Unit Delay3' */
    for (i = 0; i < 9; i++) {
      TRSC_VC_DW.UnitDelay3_DSTATE_d[i] = TRSC_VC_B.MaKM_k_P_next[i];
    }

    /* End of Update for UnitDelay: '<S24>/Unit Delay3' */

    /* Update for UnitDelay: '<S24>/Unit Delay4' */
    TRSC_VC_DW.UnitDelay4_DSTATE = TRSC_VC_B.MeKM_ddeg_YawRateRPM_Bias;

    /* Update for UnitDelay: '<S55>/Delay Input1'
     *
     * Block description for '<S55>/Delay Input1':
     *
     *  Store in Global RAM
     */
    TRSC_VC_DW.DelayInput1_DSTATE_g = TRSC_VC_B.DataTypeConversion3_e;

    /* Update for UnitDelay: '<S56>/Unit Delay' */
    TRSC_VC_DW.UnitDelay_DSTATE_kz = TRSC_VC_B.MeKM_b_ResetKM;

    /* Update for UnitDelay: '<S33>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_DSTATE_pk = TRSC_VC_B.FixPtRelationalOperator;

    /* End of Outputs for SubSystem: '<S8>/Kinematic_model' */

    /* BusCreator: '<S8>/Bus Creator1' */
    KM_MABx.IeLSCAN_m_HV_X = TRSC_VC_B.IeLSCAN_m_HV_X;
    KM_MABx.IeLSCAN_m_HV_Y = TRSC_VC_B.IeLSCAN_m_HV_Y;
    KM_MABx.IeLSCAN_deg_HV_H = TRSC_VC_B.IeLSCAN_deg_HV_H;
    KM_MABx.IeLSCAN_deg_TH = TRSC_VC_B.IeLSCAN_deg_TH;
  } else {
    if (TRSC_VC_DW.KinematicModel_MODE) {
      /* Disable for Resettable SubSystem: '<S8>/Kinematic_model' */
      /* Disable for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal1' */
      if (TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE) {
        /* Disable for Outport: '<S30>/MeKM_k_HeadingIn' */
        TRSC_VC_B.MeKM_k_HeadingIn = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal1_MODE = false;
      }

      /* End of Disable for SubSystem: '<S24>/KM_Integrator_Trapazoidal1' */

      /* Disable for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal' */
      if (TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE) {
        /* Disable for Outport: '<S29>/IeLSCAN_m_HV_X' */
        TRSC_VC_B.IeLSCAN_m_HV_X = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal_MODE = false;
      }

      /* End of Disable for SubSystem: '<S24>/KM_Integrator_Trapazoidal' */

      /* Disable for Enabled SubSystem: '<S24>/KM_Integrator_Trapazoidal2' */
      if (TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE) {
        /* Disable for Outport: '<S31>/IeLSCAN_m_HV_Y' */
        TRSC_VC_B.IeLSCAN_m_HV_Y = 0.0F;
        TRSC_VC_DW.KM_Integrator_Trapazoidal2_MODE = false;
      }

      /* End of Disable for SubSystem: '<S24>/KM_Integrator_Trapazoidal2' */
      /* End of Disable for SubSystem: '<S8>/Kinematic_model' */
      TRSC_VC_DW.KinematicModel_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/Kinematic Model' */

  /* Outputs for Atomic SubSystem: '<S1>/Torque Control' */
  /* S-Function (fcncallgen): '<S17>/Function-Call Generator' incorporates:
   *  SubSystem: '<S17>/VehicleControl'
   */
  /* Gain: '<S111>/Gain' */
  TRSC_VC_B.Gain_g = (-1.0F) * TRSC_VC_B.Gain5;

  /* Delay: '<S108>/Delay' */
  TRSC_VC_B.Delay_lx = TRSC_VC_DW.Delay_DSTATE_d[0];

  /* Logic: '<S168>/Logical Operator' */
  TRSC_VC_B.LogicalOperator2_b = !TRSC_VC_B.Delay_lx;

  /* RelationalOperator: '<S168>/Relational Operator3' incorporates:
   *  Constant: '<S168>/CeConst_k_ConstZero1'
   */
  TRSC_VC_B.RelationalOperator3_i = (MeTRSC_deg_KnobAngHys !=
    CeConst_k_ConstZero);

  /* Logic: '<S168>/Logical Operator2' */
  TRSC_VC_B.LogicalOperator2_b = (TRSC_VC_B.LogicalOperator2_b ||
    TRSC_VC_B.RelationalOperator3_i);

  /* UnitDelay: '<S168>/Unit Delay1' */
  TRSC_VC_B.UnitDelay1 = MeCtrl_deg_THInit;

  /* Switch: '<S168>/Switch' */
  if (TRSC_VC_B.LogicalOperator2_b) {
    /* Sum: '<S168>/Add1' incorporates:
     *  Constant: '<S168>/CeConst_k_ConstZero2'
     */
    TRSC_VC_B.Add1 = CeConst_k_ConstZero - TRSC_VC_B.Gain_g;
    MeCtrl_deg_THInit = TRSC_VC_B.Add1;
  }

  /* End of Switch: '<S168>/Switch' */
  /* DataTypeConversion: '<S108>/Data Type Conversion' */
  TRSC_VC_B.DataTypeConversion_m = MeTRSC_b_TRAAct;

  /* Outputs for Enabled SubSystem: '<S108>/Controller_Main2' incorporates:
   *  EnablePort: '<S109>/Enable'
   */
  if (TRSC_VC_B.DataTypeConversion_m) {
    if (!TRSC_VC_DW.Controller_Main2_MODE) {
      /* InitializeConditions for UnitDelay: '<S136>/Delay Input2'
       *
       * Block description for '<S136>/Delay Input2':
       *
       *  Store in Global RAM
       */
      TRSC_VC_DW.DelayInput2_DSTATE = 0.0F;

      /* InitializeConditions for Delay: '<S135>/Resettable Delay' */
      TRSC_VC_DW.icLoad = 1U;

      /* InitializeConditions for Delay: '<S134>/Resettable Delay' */
      TRSC_VC_DW.icLoad_k = 1U;

      /* InitializeConditions for Delay: '<S118>/Delay' */
      TRSC_VC_DW.Delay_DSTATE_o[0] = true;
      TRSC_VC_DW.Delay_DSTATE_o[1] = true;
      TRSC_VC_DW.Delay_DSTATE_o[2] = true;
      TRSC_VC_DW.Delay_DSTATE_o[3] = true;

      /* InitializeConditions for Delay: '<S109>/Delay' */
      TRSC_VC_DW.Delay_DSTATE_kg = false;

      /* InitializeConditions for Delay: '<S126>/Resettable Delay' */
      TRSC_VC_DW.icLoad_d = 1U;

      /* InitializeConditions for Delay: '<S160>/Delay' */
      TRSC_VC_DW.icLoad_j = 1U;

      /* InitializeConditions for UnitDelay: '<S159>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_n = 0.0F;

      /* InitializeConditions for Delay: '<S166>/Delay' */
      TRSC_VC_DW.icLoad_p = 1U;

      /* InitializeConditions for UnitDelay: '<S159>/Unit Delay2' */
      TRSC_VC_DW.UnitDelay2_DSTATE = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */
      TRSC_VC_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
      TRSC_VC_DW.DiscreteTimeIntegrator1_PrevResetState = 2;

      /* InitializeConditions for UnitDelay: '<S122>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_ed = false;

      /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
      TRSC_VC_DW.DiscreteTimeIntegrator_IC_LOADING = 1U;
      TRSC_VC_DW.DiscreteTimeIntegrator_PrevResetState = 2;

      /* InitializeConditions for UnitDelay: '<S163>/Delay Input2'
       *
       * Block description for '<S163>/Delay Input2':
       *
       *  Store in Global RAM
       */
      TRSC_VC_DW.DelayInput2_DSTATE_p = 0.0F;

      /* InitializeConditions for UnitDelay: '<S156>/Delay Input2'
       *
       * Block description for '<S156>/Delay Input2':
       *
       *  Store in Global RAM
       */
      TRSC_VC_DW.DelayInput2_DSTATE_d = 0.0F;

      /* SystemReset for Resettable SubSystem: '<S109>/Path_Deviation' */
      /* InitializeConditions for UnitDelay generated from: '<S115>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_2_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay generated from: '<S115>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_1_DSTATE = 0.0F;

      /* End of SystemReset for SubSystem: '<S109>/Path_Deviation' */

      /* SystemReset for Resettable SubSystem: '<S109>/TravDist_TrapIntegrator' */
      /* InitializeConditions for UnitDelay: '<S121>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_fm = 0.0F;

      /* InitializeConditions for UnitDelay: '<S121>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_h = 0.0F;

      /* End of SystemReset for SubSystem: '<S109>/TravDist_TrapIntegrator' */

      /* SystemReset for Resettable SubSystem: '<S109>/TAD_ep1' */
      /* SystemReset for Resettable SubSystem: '<S150>/Integrator_Subsytem2' */
      /* InitializeConditions for UnitDelay: '<S153>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_d = 0.0F;

      /* InitializeConditions for UnitDelay: '<S153>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_b = 0.0F;

      /* End of SystemReset for SubSystem: '<S150>/Integrator_Subsytem2' */

      /* SystemReset for Resettable SubSystem: '<S150>/Integrator_Subsytem1' */
      TRSC_VC_Integrator_Subsytem1_Reset(&TRSC_VC_DW.Integrator_Subsytem1_j);

      /* End of SystemReset for SubSystem: '<S150>/Integrator_Subsytem1' */
      /* End of SystemReset for SubSystem: '<S109>/TAD_ep1' */

      /* SystemReset for Resettable SubSystem: '<S146>/Integrator_Subsytem2' */
      TRSC_VC_Integrator_Subsytem1_Reset(&TRSC_VC_DW.Integrator_Subsytem2);

      /* End of SystemReset for SubSystem: '<S146>/Integrator_Subsytem2' */

      /* SystemReset for Resettable SubSystem: '<S146>/Integrator_Subsytem1' */
      TRSC_VC_Integrator_Subsytem1_Reset(&TRSC_VC_DW.Integrator_Subsytem1_g);

      /* End of SystemReset for SubSystem: '<S146>/Integrator_Subsytem1' */

      /* SystemReset for Resettable SubSystem: '<S141>/Integrator_Subsytem' */
      /* InitializeConditions for UnitDelay: '<S142>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_p = 0.0F;

      /* InitializeConditions for UnitDelay: '<S142>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE = 0.0;

      /* End of SystemReset for SubSystem: '<S141>/Integrator_Subsytem' */

      /* SystemReset for Resettable SubSystem: '<S141>/Integrator_Subsytem1' */
      TRSC_VC_Integrator_Subsytem1_Reset(&TRSC_VC_DW.Integrator_Subsytem1);

      /* End of SystemReset for SubSystem: '<S141>/Integrator_Subsytem1' */

      /* SystemReset for MATLAB Function: '<S122>/MATLAB Function' */
      TRSC_VC_DW.last_Identified_Case = 0.0;

      /* SystemReset for MATLAB Function: '<S159>/MATLAB Function' */
      TRSC_VC_DW.internal_timer = 0.0F;
      TRSC_VC_DW.Controller_Main2_MODE = true;
    }

    /* SignalConversion generated from: '<S113>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S113>/Constant'
     */
    TRSC_VC_B.TmpSignalConversionAtLookupTableDynamic1Inport3[0] = 30.0F;
    TRSC_VC_B.TmpSignalConversionAtLookupTableDynamic1Inport3[1] = TRSC_VC_B.Add;

    /* S-Function (sfix_look1_dyn): '<S145>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S145>/Constant'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    /* Dynamic Look-Up Table Block: '<S145>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Nearest
     *
     */
    {
      uint32_T iLeft;
      BINARYSEARCH_real_Treal32_T_Near_iL( &(iLeft), 0.0,
        &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRA_m_TrailerBeamLenXBrkPts[0], 2U);
      TRSC_VC_B.LookupTableDynamic =
        IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRA_deg_TrailerBeamLenYBrkPts[iLeft];
    }

    /* Outputs for Resettable SubSystem: '<S109>/TAD_ep1' incorporates:
     *  ResetPort: '<S120>/Reset'
     */
    /* Abs: '<S119>/Abs1' incorporates:
     *  Abs: '<S112>/Abs'
     *  Abs: '<S118>/Abs'
     *  Abs: '<S120>/Abs1'
     */
    TRSC_VC_B.gamma_now_deg_m = fabsf(TRSC_VC_B.Gain);

    /* End of Outputs for SubSystem: '<S109>/TAD_ep1' */
    TRSC_VC_B.Divide_pk = TRSC_VC_B.gamma_now_deg_m;

    /* S-Function (sfix_look1_dyn): '<S119>/Lookup Table Dynamic' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    /* Dynamic Look-Up Table Block: '<S119>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real32_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real32_T_real32_T( &(MeCtrl_deg_HdgDevLookup),
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_k_VehSpd_HdgDeviatLUTTblData[0],
      TRSC_VC_B.Divide_pk,
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[0],
      2U);

    /* RelationalOperator: '<S109>/Relational Operator3' incorporates:
     *  Constant: '<S109>/Constant2'
     */
    TRSC_VC_B.RelationalOperator3 = (MeTRSC_deg_KnobAngHys == KeTRSC_deg_Zero);

    /* Outputs for Resettable SubSystem: '<S109>/Path_Deviation' incorporates:
     *  ResetPort: '<S115>/Reset'
     */
    if (TRSC_VC_B.RelationalOperator3 &&
        (TRSC_VC_PrevZCX.Path_Deviation_Reset_ZCE != POS_ZCSIG)) {
      /* InitializeConditions for UnitDelay generated from: '<S115>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_2_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay generated from: '<S115>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_1_DSTATE = 0.0F;
    }

    TRSC_VC_PrevZCX.Path_Deviation_Reset_ZCE = TRSC_VC_B.RelationalOperator3;

    /* UnitDelay generated from: '<S115>/Unit Delay1' */
    TRSC_VC_B.Add_me = TRSC_VC_DW.UnitDelay1_2_DSTATE;

    /* Switch generated from: '<S115>/Switch' */
    if (TRSC_VC_B.Delay_lx) {
      TRSC_VC_B.IeLSCAN_m_TY = TRSC_VC_B.Add_me;
    } else {
      TRSC_VC_B.IeLSCAN_m_TY = KM_MABx.IeLSCAN_m_TY;
    }

    /* Sum: '<S115>/Add1' */
    TRSC_VC_B.Add_me = TRSC_VC_B.IeLSCAN_m_TY - KM_MABx.IeLSCAN_m_TY;

    /* Sum: '<S115>/Add3' incorporates:
     *  Constant: '<S115>/CeTRA_deg_AngleNinety1'
     *  Sum: '<S115>/Add2'
     */
    TRSC_VC_B.Add3 = MeCtrl_deg_THInit - CeTRA_deg_AngleNinety;

    /* RelationalOperator: '<S133>/Relational Operator1' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.Add3 >= TRSC_VC_ConstB.Gain4_b);

    /* RelationalOperator: '<S133>/Relational Operator5' incorporates:
     *  Constant: '<S133>/90Deg5'
     */
    TRSC_VC_B.RelationalOperator1_g = (90.0F >= TRSC_VC_B.Add3);

    /* Logic: '<S133>/Logical Operator1' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.RelationalOperator_f &&
      TRSC_VC_B.RelationalOperator1_g);

    /* Abs: '<S133>/Abs2' */
    TRSC_VC_B.Add_kg = fabsf(TRSC_VC_B.Add3);

    /* Sum: '<S133>/Add3' incorporates:
     *  Constant: '<S133>/90Deg5'
     */
    TRSC_VC_B.Add_kg -= 90.0F;

    /* Sum: '<S133>/Add4' incorporates:
     *  Constant: '<S133>/90Deg5'
     */
    TRSC_VC_B.Add_kg = 90.0F - TRSC_VC_B.Add_kg;

    /* Lookup_n-D: '<S133>/1-D Lookup Table_0_2' */
    TRSC_VC_B.uDLookupTable_0_2_m = look1_iflf_linlxpw(TRSC_VC_B.Add_kg,
      rtCP_uDLookupTable_0_2_bp01Data_k, rtCP_uDLookupTable_0_2_tableData_du,
      90U);

    /* Switch: '<S133>/Switch1' */
    if (TRSC_VC_B.RelationalOperator_f) {
      /* RelationalOperator: '<S133>/Relational Operator6' incorporates:
       *  Constant: '<S133>/Deg_0'
       */
      TRSC_VC_B.RelationalOperator6_g = (TRSC_VC_B.Add3 >= 0.0F);

      /* Switch: '<S133>/Switch4' */
      if (TRSC_VC_B.RelationalOperator6_g) {
        /* Lookup_n-D: '<S133>/1-D Lookup Table_0_6' */
        TRSC_VC_B.uDLookupTable_0_6 = look1_iflf_linlxpw(TRSC_VC_B.Add3,
          rtCP_uDLookupTable_0_6_bp01Data_n, rtCP_uDLookupTable_0_6_tableData_aw,
          90U);
        TRSC_VC_B.Switch4_o = TRSC_VC_B.uDLookupTable_0_6;
      } else {
        /* Gain: '<S133>/Gain5' */
        TRSC_VC_B.uDLookupTable_0_1 = (-1.0F) * TRSC_VC_B.Add3;

        /* Lookup_n-D: '<S133>/1-D Lookup Table_0_1' */
        TRSC_VC_B.uDLookupTable_0_1 = look1_iflf_linlxpw
          (TRSC_VC_B.uDLookupTable_0_1, rtCP_uDLookupTable_0_1_bp01Data_db,
           rtCP_uDLookupTable_0_1_tableData_b, 90U);

        /* Gain: '<S133>/Gain1' */
        TRSC_VC_B.Gain1_k = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1;
        TRSC_VC_B.Switch4_o = TRSC_VC_B.Gain1_k;
      }

      /* End of Switch: '<S133>/Switch4' */
      TRSC_VC_B.Add_kg = TRSC_VC_B.Switch4_o;
    } else {
      /* RelationalOperator: '<S133>/Relational Operator2' incorporates:
       *  Constant: '<S133>/90Deg5'
       */
      TRSC_VC_B.RelationalOperator2_n = (TRSC_VC_B.Add3 >= 90.0F);

      /* Switch: '<S133>/Switch2' */
      if (TRSC_VC_B.RelationalOperator2_n) {
        TRSC_VC_B.Switch2_hj = TRSC_VC_B.uDLookupTable_0_2_m;
      } else {
        /* Gain: '<S133>/Gain2' */
        TRSC_VC_B.Gain2_a = (-1.0F) * TRSC_VC_B.uDLookupTable_0_2_m;
        TRSC_VC_B.Switch2_hj = TRSC_VC_B.Gain2_a;
      }

      /* End of Switch: '<S133>/Switch2' */
      TRSC_VC_B.Add_kg = TRSC_VC_B.Switch2_hj;
    }

    /* End of Switch: '<S133>/Switch1' */

    /* Product: '<S115>/Product1' */
    TRSC_VC_B.Add_me *= TRSC_VC_B.Add_kg;

    /* UnitDelay generated from: '<S115>/Unit Delay1' */
    TRSC_VC_B.Add_kg = TRSC_VC_DW.UnitDelay1_1_DSTATE;

    /* Switch generated from: '<S115>/Switch' */
    if (TRSC_VC_B.Delay_lx) {
      TRSC_VC_B.IeLSCAN_m_TX = TRSC_VC_B.Add_kg;
    } else {
      TRSC_VC_B.IeLSCAN_m_TX = KM_MABx.IeLSCAN_m_TX;
    }

    /* Sum: '<S115>/Add4' */
    TRSC_VC_B.Add_kg = TRSC_VC_B.IeLSCAN_m_TX - KM_MABx.IeLSCAN_m_TX;

    /* Sum: '<S115>/Add2' */
    TRSC_VC_B.Add2 = TRSC_VC_B.Add3;

    /* RelationalOperator: '<S132>/Relational Operator2' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.Add2 >= TRSC_VC_ConstB.Gain1_e);

    /* RelationalOperator: '<S132>/Relational Operator3' incorporates:
     *  Constant: '<S132>/90Deg2'
     */
    TRSC_VC_B.RelationalOperator1_g = (90.0F >= TRSC_VC_B.Add2);

    /* Logic: '<S132>/Logical Operator' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.RelationalOperator_f &&
      TRSC_VC_B.RelationalOperator1_g);

    /* Switch: '<S132>/Switch2' */
    if (TRSC_VC_B.RelationalOperator_f) {
      /* RelationalOperator: '<S132>/Relational Operator4' incorporates:
       *  Constant: '<S132>/0Deg1'
       */
      TRSC_VC_B.RelationalOperator4_l = (TRSC_VC_B.Add2 >= 0.0F);

      /* Switch: '<S132>/Switch3' */
      if (TRSC_VC_B.RelationalOperator4_l) {
        /* Lookup_n-D: '<S132>/1-D Lookup Table_0_3' */
        TRSC_VC_B.uDLookupTable_0_3 = look1_iflf_linlxpw(TRSC_VC_B.Add2,
          rtCP_uDLookupTable_0_3_bp01Data_j, rtCP_uDLookupTable_0_3_tableData_n4,
          90U);
        TRSC_VC_B.Switch3_f = TRSC_VC_B.uDLookupTable_0_3;
      } else {
        /* Gain: '<S132>/Gain2' */
        TRSC_VC_B.Gain2_o = (-1.0F) * TRSC_VC_B.Add2;

        /* Lookup_n-D: '<S132>/1-D Lookup Table_0_2' */
        TRSC_VC_B.uDLookupTable_0_2_c = look1_iflf_linlxpw(TRSC_VC_B.Gain2_o,
          rtCP_uDLookupTable_0_2_bp01Data_oe, rtCP_uDLookupTable_0_2_tableData_c,
          90U);
        TRSC_VC_B.Switch3_f = TRSC_VC_B.uDLookupTable_0_2_c;
      }

      /* End of Switch: '<S132>/Switch3' */
      TRSC_VC_B.Add_mf = TRSC_VC_B.Switch3_f;
    } else {
      /* Abs: '<S132>/Abs1' */
      TRSC_VC_B.uDLookupTable_0_1_f = fabsf(TRSC_VC_B.Add2);

      /* Sum: '<S132>/Add1' incorporates:
       *  Constant: '<S132>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_f -= 90.0F;

      /* Sum: '<S132>/Add2' incorporates:
       *  Constant: '<S132>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_f = 90.0F - TRSC_VC_B.uDLookupTable_0_1_f;

      /* Lookup_n-D: '<S132>/1-D Lookup Table_0_1' */
      TRSC_VC_B.uDLookupTable_0_1_f = look1_iflf_linlxpw
        (TRSC_VC_B.uDLookupTable_0_1_f, rtCP_uDLookupTable_0_1_bp01Data_lr,
         rtCP_uDLookupTable_0_1_tableData_fi, 90U);

      /* Gain: '<S132>/Gain3' */
      TRSC_VC_B.Gain3_f = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_f;
      TRSC_VC_B.Add_mf = TRSC_VC_B.Gain3_f;
    }

    /* End of Switch: '<S132>/Switch2' */

    /* Product: '<S115>/Product' */
    TRSC_VC_B.Add_kg *= TRSC_VC_B.Add_mf;

    /* Sum: '<S115>/Add5' */
    MeTRA_deg_PathDeviation = TRSC_VC_B.Add_kg + TRSC_VC_B.Add_me;

    /* Update for UnitDelay generated from: '<S115>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_2_DSTATE = TRSC_VC_B.IeLSCAN_m_TY;

    /* Update for UnitDelay generated from: '<S115>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_1_DSTATE = TRSC_VC_B.IeLSCAN_m_TX;

    /* End of Outputs for SubSystem: '<S109>/Path_Deviation' */

    /* Logic: '<S109>/Logical Operator1' */
    TRSC_VC_B.LogicalOperator1_c = (TRSC_VC_B.RelationalOperator3 ||
      TRSC_VC_B.Delay_lx);

    /* Outputs for Resettable SubSystem: '<S109>/TravDist_TrapIntegrator' incorporates:
     *  ResetPort: '<S121>/Reset'
     */
    if (TRSC_VC_B.LogicalOperator1_c &&
        (TRSC_VC_PrevZCX.TravDist_TrapIntegrator_Reset_ZCE != POS_ZCSIG)) {
      /* InitializeConditions for UnitDelay: '<S121>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_fm = 0.0F;

      /* InitializeConditions for UnitDelay: '<S121>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_h = 0.0F;
    }

    TRSC_VC_PrevZCX.TravDist_TrapIntegrator_Reset_ZCE =
      TRSC_VC_B.LogicalOperator1_c;

    /* UnitDelay: '<S121>/Unit Delay' */
    TRSC_VC_B.Product_p = TRSC_VC_DW.UnitDelay_DSTATE_fm;

    /* UnitDelay: '<S121>/Unit Delay1' */
    TRSC_VC_B.Product5_m = TRSC_VC_DW.UnitDelay1_DSTATE_h;

    /* Sum: '<S121>/Add1' */
    TRSC_VC_B.Product5_m += TRSC_VC_B.Gain;

    /* Product: '<S121>/Divide' incorporates:
     *  Constant: '<S121>/CeConst_k_ConstTwo'
     */
    TRSC_VC_B.Product5_m /= CeConst_k_ConstTwo;

    /* Product: '<S121>/Product' incorporates:
     *  Constant: '<S121>/CeKM_s_SampleTime  '
     */
    TRSC_VC_B.Product5_m *= CeTRA_sec_SampleTime;

    /* Sum: '<S121>/Add' */
    MeCtrl_m_TravelDist = TRSC_VC_B.Product_p + TRSC_VC_B.Product5_m;

    /* Update for UnitDelay: '<S121>/Unit Delay' */
    TRSC_VC_DW.UnitDelay_DSTATE_fm = MeCtrl_m_TravelDist;

    /* Update for UnitDelay: '<S121>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_DSTATE_h = TRSC_VC_B.Gain;

    /* End of Outputs for SubSystem: '<S109>/TravDist_TrapIntegrator' */

    /* Outputs for Resettable SubSystem: '<S109>/TAD_ep1' incorporates:
     *  ResetPort: '<S120>/Reset'
     */
    if (TRSC_VC_B.RelationalOperator3 && (TRSC_VC_PrevZCX.TAD_ep1_Reset_ZCE !=
         POS_ZCSIG)) {
      /* SystemReset for Resettable SubSystem: '<S150>/Integrator_Subsytem2' */
      /* InitializeConditions for UnitDelay: '<S153>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_d = 0.0F;

      /* InitializeConditions for UnitDelay: '<S153>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_b = 0.0F;

      /* End of SystemReset for SubSystem: '<S150>/Integrator_Subsytem2' */

      /* SystemReset for Resettable SubSystem: '<S150>/Integrator_Subsytem1' */
      TRSC_VC_Integrator_Subsytem1_Reset(&TRSC_VC_DW.Integrator_Subsytem1_j);

      /* End of SystemReset for SubSystem: '<S150>/Integrator_Subsytem1' */
    }

    TRSC_VC_PrevZCX.TAD_ep1_Reset_ZCE = TRSC_VC_B.RelationalOperator3;

    /* Abs: '<S120>/Abs2' incorporates:
     *  Abs: '<S113>/Abs1'
     *  Abs: '<S116>/Abs'
     *  Abs: '<S124>/Abs1'
     *  Abs: '<S125>/Abs2'
     *  Abs: '<S141>/Abs1'
     *  MATLAB Function: '<S122>/MATLAB Function'
     *  Switch: '<S124>/Switch2'
     */
    TRSC_VC_B.Abs_c = fabsf(TRSC_VC_B.Gain_g);
    TRSC_VC_B.Product_p = TRSC_VC_B.Abs_c;

    /* S-Function (sfix_look1_dyn): '<S120>/Lookup Table Dynamic2' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    /* Dynamic Look-Up Table Block: '<S120>/Lookup Table Dynamic2'
     * Input0  Data Type:  Floating Point real32_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real32_T_real32_T( &(TRSC_VC_B.LookupTableDynamic2_k),
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_deg_TADLUTTblData[0],
      TRSC_VC_B.Product_p,
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_deg_TADLUTBrkPts[0], 2U);

    /* Abs: '<S120>/Abs1' */
    TRSC_VC_B.Product_p = TRSC_VC_B.gamma_now_deg_m;

    /* S-Function (sfix_look1_dyn): '<S120>/Lookup Table Dynamic1' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    /* Dynamic Look-Up Table Block: '<S120>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real32_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real32_T_real32_T( &(TRSC_VC_B.LookupTableDynamic1_j),
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_k_VehSpdLUTTblData[0],
      TRSC_VC_B.Product_p,
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_v_VehSpdLUTBrkPts[0], 1U);

    /* S-Function (sfix_look1_dyn): '<S120>/Lookup Table Dynamic' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    /* Dynamic Look-Up Table Block: '<S120>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real32_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real32_T_real32_T( &(TRSC_VC_B.LookupTableDynamic_j),
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_k_TravDistLUTTblData[0],
      MeCtrl_m_TravelDist,
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_m_TravDistLUTBrkPts[0], 1U);

    /* Product: '<S120>/Product' */
    TRSC_VC_B.Product_p = TRSC_VC_B.LookupTableDynamic2_k *
      TRSC_VC_B.LookupTableDynamic1_j * TRSC_VC_B.LookupTableDynamic_j;

    /* Product: '<S150>/Product1' */
    TRSC_VC_B.Product1_j = MeTRA_deg_PathDeviation * TRSC_VC_B.Product_p;

    /* Product: '<S120>/Product4' incorporates:
     *  Constant: '<S120>/CeTRA_k_One_Four'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Product_p = IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_TADep_k_PIDKp
      * 1.0F;

    /* Product: '<S150>/Product' */
    TRSC_VC_B.Product_p *= MeTRA_deg_PathDeviation;

    /* Outputs for Resettable SubSystem: '<S150>/Integrator_Subsytem2' incorporates:
     *  ResetPort: '<S153>/Reset'
     */
    if (TRSC_VC_B.Delay_lx && (TRSC_VC_PrevZCX.Integrator_Subsytem2_Reset_ZCE !=
         POS_ZCSIG)) {
      /* InitializeConditions for UnitDelay: '<S153>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_d = 0.0F;

      /* InitializeConditions for UnitDelay: '<S153>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE_b = 0.0F;
    }

    TRSC_VC_PrevZCX.Integrator_Subsytem2_Reset_ZCE = TRSC_VC_B.Delay_lx;

    /* UnitDelay: '<S153>/Unit Delay' */
    TRSC_VC_B.Product5_m = TRSC_VC_DW.UnitDelay_DSTATE_d;

    /* UnitDelay: '<S153>/Unit Delay1' */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 = TRSC_VC_DW.UnitDelay1_DSTATE_b;

    /* Product: '<S153>/Product' incorporates:
     *  Constant: '<S120>/CeTRA_sec_SampleTime'
     */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 *= CeTRA_sec_SampleTime;

    /* Sum: '<S153>/Add' */
    TRSC_VC_B.Add_m = TRSC_VC_B.Product5_m + TRSC_VC_B.DiscreteTimeIntegrator_o1;

    /* Update for UnitDelay: '<S153>/Unit Delay' */
    TRSC_VC_DW.UnitDelay_DSTATE_d = TRSC_VC_B.Add_m;

    /* Update for UnitDelay: '<S153>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_DSTATE_b = TRSC_VC_B.Product1_j;

    /* End of Outputs for SubSystem: '<S150>/Integrator_Subsytem2' */

    /* Product: '<S150>/Product2' incorporates:
     *  Constant: '<S120>/CeConst_k_ConstZero2'
     */
    TRSC_VC_B.Product5_m = MeTRA_deg_PathDeviation * KeTRSC_k_PIDKdPathDeviation;

    /* Outputs for Resettable SubSystem: '<S150>/Integrator_Subsytem1' */
    /* Constant: '<S120>/CeTRA_sec_SampleTime' */
    TRSC_VC_Integrator_Subsytem1(CeTRA_sec_SampleTime, TRSC_VC_B.Delay_lx,
      &TRSC_VC_B.DiscreteTimeIntegrator_o1, &TRSC_VC_B.Integrator_Subsytem1_j,
      &TRSC_VC_DW.Integrator_Subsytem1_j,
      &TRSC_VC_PrevZCX.Integrator_Subsytem1_j);

    /* End of Outputs for SubSystem: '<S150>/Integrator_Subsytem1' */

    /* Sum: '<S150>/Add1' */
    TRSC_VC_B.Product5_m -= TRSC_VC_B.DiscreteTimeIntegrator_o1;

    /* Product: '<S150>/Product3' incorporates:
     *  Constant: '<S120>/CeConst_k_Prob2Perc'
     */
    TRSC_VC_B.Product3_j = TRSC_VC_B.Product5_m * CeTRA_k_ConstTen;

    /* Sum: '<S150>/Add' */
    TRSC_VC_B.Add_k = (TRSC_VC_B.Product_p + TRSC_VC_B.Add_m) +
      TRSC_VC_B.Product3_j;

    /* RelationalOperator: '<S151>/LowerRelop1' incorporates:
     *  Constant: '<S120>/CeTRA_k_fifteen'
     */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.Add_k > CeTRA_k_fifteen);

    /* Gain: '<S120>/Gain' incorporates:
     *  Constant: '<S120>/CeTRA_k_fifteen'
     */
    TRSC_VC_B.Product_p = (-1.0F) * CeTRA_k_fifteen;

    /* RelationalOperator: '<S151>/UpperRelop' */
    TRSC_VC_B.RelationalOperator1_g = (TRSC_VC_B.Add_k < TRSC_VC_B.Product_p);

    /* Switch: '<S151>/Switch' */
    if (TRSC_VC_B.RelationalOperator1_g) {
      TRSC_VC_B.Switch_cz = TRSC_VC_B.Product_p;
    } else {
      TRSC_VC_B.Switch_cz = TRSC_VC_B.Add_k;
    }

    /* End of Switch: '<S151>/Switch' */

    /* Switch: '<S151>/Switch2' incorporates:
     *  Constant: '<S120>/CeTRA_k_fifteen'
     */
    if (TRSC_VC_B.RelationalOperator_f) {
      MeCtrl_deg_PIDe_p = CeTRA_k_fifteen;
    } else {
      MeCtrl_deg_PIDe_p = TRSC_VC_B.Switch_cz;
    }

    /* End of Switch: '<S151>/Switch2' */

    /* Update for Resettable SubSystem: '<S150>/Integrator_Subsytem1' */
    TRSC_VC_Integrator_Subsytem1_Update(TRSC_VC_B.Product3_j,
      &TRSC_VC_B.DiscreteTimeIntegrator_o1, &TRSC_VC_DW.Integrator_Subsytem1_j);

    /* End of Update for SubSystem: '<S150>/Integrator_Subsytem1' */
    /* End of Outputs for SubSystem: '<S109>/TAD_ep1' */

    /* Abs: '<S113>/Abs1' */
    TRSC_VC_B.Divide_pk = TRSC_VC_B.Abs_c;

    /* S-Function (sfix_look1_dyn): '<S113>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S113>/Constant1'
     */
    /* Dynamic Look-Up Table Block: '<S113>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real32_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUpEven_real32_T_real32_T( &(TRSC_VC_B.LookupTableDynamic1),
      &TRSC_VC_B.TmpSignalConversionAtLookupTableDynamic1Inport3[0],
      TRSC_VC_B.Divide_pk, 5.0F, 1U, 15.0F);

    /* Abs: '<S112>/Abs' */
    TRSC_VC_B.Divide_pk = TRSC_VC_B.gamma_now_deg_m;

    /* RelationalOperator: '<S112>/Relational Operator' incorporates:
     *  Constant: '<S112>/CeConst_k_ConstOne'
     */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.Divide_pk < CeConst_k_ConstOne);

    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S112>/CeConst_k_ConstOne'
     */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Divide_pk = CeConst_k_ConstOne;
    } else {
      TRSC_VC_B.Divide_pk = TRSC_VC_B.Gain;
    }

    /* End of Switch: '<S112>/Switch' */

    /* Abs: '<S112>/Abs1' */
    TRSC_VC_B.Divide_pk = fabsf(TRSC_VC_B.Divide_pk);

    /* Gain: '<S112>/Gain1' */
    TRSC_VC_B.Divide_pk *= (-1.0F);

    /* RelationalOperator: '<S125>/Relational Operator1' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.Gain_g >= TRSC_VC_ConstB.Gain4);

    /* RelationalOperator: '<S125>/Relational Operator5' incorporates:
     *  Constant: '<S125>/90Deg5'
     */
    TRSC_VC_B.RelationalOperator1_g = (90.0F >= TRSC_VC_B.Gain_g);

    /* Logic: '<S125>/Logical Operator1' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.UpperRelop_m &&
      TRSC_VC_B.RelationalOperator1_g);

    /* Abs: '<S125>/Abs2' */
    TRSC_VC_B.integrator_multiplier_table_type1 = TRSC_VC_B.Abs_c;

    /* Sum: '<S125>/Add3' incorporates:
     *  Constant: '<S125>/90Deg5'
     */
    TRSC_VC_B.integrator_multiplier_table_type1 -= 90.0F;

    /* Sum: '<S125>/Add4' incorporates:
     *  Constant: '<S125>/90Deg5'
     */
    TRSC_VC_B.integrator_multiplier_table_type1 = 90.0F -
      TRSC_VC_B.integrator_multiplier_table_type1;

    /* Lookup_n-D: '<S125>/1-D Lookup Table_0_2' */
    TRSC_VC_B.uDLookupTable_0_2 = look1_iflf_linlxpw
      (TRSC_VC_B.integrator_multiplier_table_type1,
       rtCP_uDLookupTable_0_2_bp01Data_d, rtCP_uDLookupTable_0_2_tableData_o,
       90U);

    /* Switch: '<S125>/Switch1' */
    if (TRSC_VC_B.UpperRelop_m) {
      /* RelationalOperator: '<S125>/Relational Operator6' incorporates:
       *  Constant: '<S125>/Deg_0'
       */
      TRSC_VC_B.RelationalOperator6_i = (TRSC_VC_B.Gain_g >= 0.0F);

      /* Switch: '<S125>/Switch4' */
      if (TRSC_VC_B.RelationalOperator6_i) {
        /* Lookup_n-D: '<S125>/1-D Lookup Table_0_6' */
        TRSC_VC_B.uDLookupTable_0_6_b = look1_iflf_linlxpw(TRSC_VC_B.Gain_g,
          rtCP_uDLookupTable_0_6_bp01Data_p, rtCP_uDLookupTable_0_6_tableData_a,
          90U);
        TRSC_VC_B.Switch4_m = TRSC_VC_B.uDLookupTable_0_6_b;
      } else {
        /* Gain: '<S125>/Gain5' */
        TRSC_VC_B.uDLookupTable_0_1_i = (-1.0F) * TRSC_VC_B.Gain_g;

        /* Lookup_n-D: '<S125>/1-D Lookup Table_0_1' */
        TRSC_VC_B.uDLookupTable_0_1_i = look1_iflf_linlxpw
          (TRSC_VC_B.uDLookupTable_0_1_i, rtCP_uDLookupTable_0_1_bp01Data_c,
           rtCP_uDLookupTable_0_1_tableData_jj, 90U);

        /* Gain: '<S125>/Gain1' */
        TRSC_VC_B.Gain1_e = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_i;
        TRSC_VC_B.Switch4_m = TRSC_VC_B.Gain1_e;
      }

      /* End of Switch: '<S125>/Switch4' */
      TRSC_VC_B.integrator_multiplier_table_type1 = TRSC_VC_B.Switch4_m;
    } else {
      /* RelationalOperator: '<S125>/Relational Operator2' incorporates:
       *  Constant: '<S125>/90Deg5'
       */
      TRSC_VC_B.RelationalOperator2_e = (TRSC_VC_B.Gain_g >= 90.0F);

      /* Switch: '<S125>/Switch2' */
      if (TRSC_VC_B.RelationalOperator2_e) {
        TRSC_VC_B.Switch2_j = TRSC_VC_B.uDLookupTable_0_2;
      } else {
        /* Gain: '<S125>/Gain2' */
        TRSC_VC_B.Gain2_b = (-1.0F) * TRSC_VC_B.uDLookupTable_0_2;
        TRSC_VC_B.Switch2_j = TRSC_VC_B.Gain2_b;
      }

      /* End of Switch: '<S125>/Switch2' */
      TRSC_VC_B.integrator_multiplier_table_type1 = TRSC_VC_B.Switch2_j;
    }

    /* End of Switch: '<S125>/Switch1' */

    /* Product: '<S112>/Divide7' */
    TRSC_VC_B.integrator_multiplier_table_type1 /= TRSC_VC_B.Switch6;

    /* Product: '<S112>/Divide4' */
    TRSC_VC_B.integrator_multiplier_table_type1 *= TRSC_VC_B.Divide_pk;

    /* UnitDelay: '<S136>/Delay Input2'
     *
     * Block description for '<S136>/Delay Input2':
     *
     *  Store in Global RAM
     */
    TRSC_VC_B.Yk1 = TRSC_VC_DW.DelayInput2_DSTATE;

    /* SampleTimeMath: '<S136>/sample time'
     *
     * About '<S136>/sample time':
     *  y = K where K = ( w * Ts )
     */
    TRSC_VC_B.sampletime = 0.03F;

    /* Product: '<S136>/delta rise limit' incorporates:
     *  Constant: '<S117>/KeTRSC_ddeg_TadDesRateLim'
     */
    TRSC_VC_B.deltariselimit = KeTRSC_ddeg_TadDesRateLim * TRSC_VC_B.sampletime;

    /* Lookup_n-D: '<S117>/KnobScalingLUT' */
    TRSC_VC_B.KnobScalingLUT = look1_iflf_binlxpw(TRSC_VC_B.Switch6, ((real32_T *)
      &(KeTRSC_m_DesAnglScaleTBLThr[0])), ((real32_T *)
      &(KeTRSC_pct_TrlrAngScaleDwnPct[0])), 3U);

    /* Product: '<S119>/Product' incorporates:
     *  Constant: '<S119>/CeTRA_k_fifteen'
     */
    TRSC_VC_B.Abs_d = 30.0F * MeCtrl_deg_HdgDevLookup;

    /* Outputs for Resettable SubSystem: '<S109>/Heading_Deviation1' incorporates:
     *  ResetPort: '<S114>/Reset'
     */
    TRSC_VC_PrevZCX.Heading_Deviation1_Reset_ZCE = TRSC_VC_B.RelationalOperator3;

    /* Sum: '<S114>/Add6' */
    TRSC_VC_B.MeCtrl_deg_HeadingIn = KM_MABx.IeLSCAN_deg_TH - MeCtrl_deg_THInit;

    /* Abs: '<S131>/Abs' */
    TRSC_VC_B.Add_me = fabsf(TRSC_VC_B.MeCtrl_deg_HeadingIn);

    /* Product: '<S131>/Divide' incorporates:
     *  Constant: '<S131>/CeTRA_deg_AngleThreeSixty'
     */
    TRSC_VC_B.Add_me /= CeTRA_deg_AngleThreeSixty;

    /* RelationalOperator: '<S131>/Relational Operator2' incorporates:
     *  Constant: '<S131>/CeConst_k_ConstZero'
     */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.Add_me == CeConst_k_ConstZero);

    /* Switch: '<S131>/Switch2' incorporates:
     *  Constant: '<S131>/CeConst_k_ConstOne'
     */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Add_me = CeConst_k_ConstOne;
    }

    /* End of Switch: '<S131>/Switch2' */

    /* Product: '<S131>/Product' incorporates:
     *  Constant: '<S131>/CeTRA_deg_AngleThreeSixty1'
     */
    TRSC_VC_B.Product_n = TRSC_VC_B.Add_me * CeTRA_deg_AngleThreeSixty;

    /* Gain: '<S131>/Gain' incorporates:
     *  Constant: '<S131>/CeTRA_deg_AngleOneEighty'
     */
    TRSC_VC_B.Add_me = (-1.0F) * CeTRA_deg_AngleOneEighty;

    /* RelationalOperator: '<S131>/Relational Operator' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.MeCtrl_deg_HeadingIn <
      TRSC_VC_B.Add_me);

    /* Switch: '<S131>/Switch' */
    if (TRSC_VC_B.RelationalOperator_f) {
      /* Sum: '<S131>/Add3' */
      TRSC_VC_B.Add3_b = TRSC_VC_B.MeCtrl_deg_HeadingIn + TRSC_VC_B.Product_n;
      MeCtrl_deg_HeadingOut = TRSC_VC_B.Add3_b;
    } else {
      /* RelationalOperator: '<S131>/Relational Operator1' incorporates:
       *  Constant: '<S131>/CeTRA_deg_AngleOneEighty1'
       */
      TRSC_VC_B.RelationalOperator1_c = (TRSC_VC_B.MeCtrl_deg_HeadingIn >
        CeTRA_deg_AngleOneEighty);

      /* Switch: '<S131>/Switch1' */
      if (TRSC_VC_B.RelationalOperator1_c) {
        /* Sum: '<S131>/Add2' */
        TRSC_VC_B.Add2_l = TRSC_VC_B.MeCtrl_deg_HeadingIn - TRSC_VC_B.Product_n;
        TRSC_VC_B.Switch1_d = TRSC_VC_B.Add2_l;
      } else {
        TRSC_VC_B.Switch1_d = TRSC_VC_B.MeCtrl_deg_HeadingIn;
      }

      /* End of Switch: '<S131>/Switch1' */
      MeCtrl_deg_HeadingOut = TRSC_VC_B.Switch1_d;
    }

    /* End of Switch: '<S131>/Switch' */

    /* Lookup_n-D: '<S114>/Frt to Str Whl1' */
    TRSC_VC_B.Add_me = look1_iflf_binlcapw(MeCtrl_m_TravelDist,
      rtCP_FrttoStrWhl1_bp01Data, rtCP_FrttoStrWhl1_tableData, 2U);

    /* Product: '<S114>/Product' */
    TRSC_VC_B.Add_me *= MeCtrl_deg_HeadingOut;

    /* Switch: '<S114>/Switch' incorporates:
     *  Constant: '<S114>/CeConst_k_ConstOne'
     *  Constant: '<S114>/CeConst_k_ConstZero'
     */
    if (CeConst_k_ConstOne > 0.0F) {
      /* Gain: '<S114>/Gain' */
      TRSC_VC_B.Gain_h = (-1.0F) * MeCtrl_deg_PIDe_p;
      MeCtrl_deg_e_p = TRSC_VC_B.Gain_h;
    } else {
      MeCtrl_deg_e_p = CeConst_k_ConstZero;
    }

    /* End of Switch: '<S114>/Switch' */

    /* Sum: '<S114>/Add' */
    MeCtrl_deg_HeadingDeviation = TRSC_VC_B.Add_me + MeCtrl_deg_e_p;

    /* End of Outputs for SubSystem: '<S109>/Heading_Deviation1' */

    /* RelationalOperator: '<S144>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator1_g = (MeCtrl_deg_HeadingDeviation >
      TRSC_VC_B.Abs_d);

    /* Gain: '<S119>/Gain' */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 = (-1.0F) * TRSC_VC_B.Abs_d;

    /* RelationalOperator: '<S144>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (MeCtrl_deg_HeadingDeviation <
      TRSC_VC_B.DiscreteTimeIntegrator_o1);

    /* Switch: '<S144>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_d2 = TRSC_VC_B.DiscreteTimeIntegrator_o1;
    } else {
      TRSC_VC_B.Switch_d2 = MeCtrl_deg_HeadingDeviation;
    }

    /* End of Switch: '<S144>/Switch' */

    /* Switch: '<S144>/Switch2' */
    if (TRSC_VC_B.RelationalOperator1_g) {
      TRSC_VC_B.Switch2_n = TRSC_VC_B.Abs_d;
    } else {
      TRSC_VC_B.Switch2_n = TRSC_VC_B.Switch_d2;
    }

    /* End of Switch: '<S144>/Switch2' */

    /* Product: '<S146>/Product' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRA_m_K_beta * TRSC_VC_B.Switch2_n;

    /* Outputs for Resettable SubSystem: '<S146>/Integrator_Subsytem2' */
    /* Constant: '<S145>/CeTRA_sec_SampleTime' */
    TRSC_VC_Integrator_Subsytem1(CeTRA_sec_SampleTime, TRSC_VC_B.Delay_lx,
      &TRSC_VC_B.Add_mf, &TRSC_VC_B.Integrator_Subsytem2,
      &TRSC_VC_DW.Integrator_Subsytem2, &TRSC_VC_PrevZCX.Integrator_Subsytem2);

    /* End of Outputs for SubSystem: '<S146>/Integrator_Subsytem2' */

    /* Product: '<S146>/Product2' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Abs_d = TRSC_VC_B.Switch2_n *
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_TADdes_k_PIDKd;

    /* Outputs for Resettable SubSystem: '<S146>/Integrator_Subsytem1' */
    /* Constant: '<S145>/CeTRA_sec_SampleTime' */
    TRSC_VC_Integrator_Subsytem1(CeTRA_sec_SampleTime, TRSC_VC_B.Delay_lx,
      &TRSC_VC_B.Add_kg, &TRSC_VC_B.Integrator_Subsytem1_g,
      &TRSC_VC_DW.Integrator_Subsytem1_g,
      &TRSC_VC_PrevZCX.Integrator_Subsytem1_g);

    /* End of Outputs for SubSystem: '<S146>/Integrator_Subsytem1' */

    /* Sum: '<S146>/Add1' */
    TRSC_VC_B.Abs_d -= TRSC_VC_B.Add_kg;

    /* Product: '<S146>/Product3' incorporates:
     *  Constant: '<S145>/CeConst_k_Prob2Perc'
     */
    TRSC_VC_B.Product3 = TRSC_VC_B.Abs_d * CeTRA_k_ConstTen;

    /* Sum: '<S146>/Add' */
    TRSC_VC_B.Add_l = (TRSC_VC_B.DiscreteTimeIntegrator_o1 + TRSC_VC_B.Add_mf) +
      TRSC_VC_B.Product3;

    /* RelationalOperator: '<S147>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator1_g = (TRSC_VC_B.Add_l >
      TRSC_VC_B.LookupTableDynamic);

    /* Gain: '<S145>/Gain' */
    TRSC_VC_B.Switch = (-1.0) * TRSC_VC_B.LookupTableDynamic;

    /* RelationalOperator: '<S147>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.Add_l < TRSC_VC_B.Switch);

    /* Switch: '<S147>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_j = (real32_T)TRSC_VC_B.Switch;
    } else {
      TRSC_VC_B.Switch_j = TRSC_VC_B.Add_l;
    }

    /* End of Switch: '<S147>/Switch' */

    /* Switch: '<S147>/Switch2' */
    if (TRSC_VC_B.RelationalOperator1_g) {
      MeCtrl_deg_TAD_des = (real32_T)TRSC_VC_B.LookupTableDynamic;
    } else {
      MeCtrl_deg_TAD_des = TRSC_VC_B.Switch_j;
    }

    /* End of Switch: '<S147>/Switch2' */

    /* Delay: '<S135>/Resettable Delay' */
    if (TRSC_VC_B.Delay_lx && (TRSC_VC_PrevZCX.ResettableDelay_Reset_ZCE !=
         POS_ZCSIG)) {
      TRSC_VC_DW.icLoad = 1U;
    }

    TRSC_VC_PrevZCX.ResettableDelay_Reset_ZCE = TRSC_VC_B.Delay_lx;
    if (TRSC_VC_DW.icLoad != 0) {
      TRSC_VC_DW.ResettableDelay_DSTATE = MeCtrl_deg_TAD_des;
    }

    TRSC_VC_B.Yk1_m2 = TRSC_VC_DW.ResettableDelay_DSTATE;

    /* End of Delay: '<S135>/Resettable Delay' */

    /* Product: '<S135>/delta rise limit' incorporates:
     *  Constant: '<S135>/Constant'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_TAD_DesRateUpLim *
      KM_SamplingTime;

    /* Sum: '<S135>/Difference Inputs1'
     *
     * Block description for '<S135>/Difference Inputs1':
     *
     *  Add in CPU
     */
    TRSC_VC_B.UkYk1 = MeCtrl_deg_TAD_des - TRSC_VC_B.Yk1_m2;

    /* RelationalOperator: '<S139>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator1_g = (TRSC_VC_B.UkYk1 >
      TRSC_VC_B.DiscreteTimeIntegrator_o1);

    /* Gain: '<S135>/Gain' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Abs_d = (-1.0F) *
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_TAD_DesRateUpLim;

    /* Product: '<S135>/Delta_Fall_Limit' incorporates:
     *  Constant: '<S135>/Constant'
     */
    TRSC_VC_B.Abs_d *= KM_SamplingTime;

    /* RelationalOperator: '<S139>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.UkYk1 < TRSC_VC_B.Abs_d);

    /* Switch: '<S139>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_bm = TRSC_VC_B.Abs_d;
    } else {
      TRSC_VC_B.Switch_bm = TRSC_VC_B.UkYk1;
    }

    /* End of Switch: '<S139>/Switch' */

    /* Switch: '<S139>/Switch2' */
    if (TRSC_VC_B.RelationalOperator1_g) {
      TRSC_VC_B.Switch2_g = TRSC_VC_B.DiscreteTimeIntegrator_o1;
    } else {
      TRSC_VC_B.Switch2_g = TRSC_VC_B.Switch_bm;
    }

    /* End of Switch: '<S139>/Switch2' */

    /* Sum: '<S135>/Difference Inputs2'
     *
     * Block description for '<S135>/Difference Inputs2':
     *
     *  Add in CPU
     */
    TRSC_VC_B.Yk = TRSC_VC_B.Switch2_g + TRSC_VC_B.Yk1_m2;

    /* Switch: '<S117>/Switch_TAD_des_Final' */
    if (MeTRSC_deg_KnobAngHys != 0) {
      /* Product: '<S117>/Product1' */
      TRSC_VC_B.Product1_b = TRSC_VC_B.KnobScalingLUT * TRSC_VC_B.Gain15;
      TRSC_VC_B.Switch_TAD_des_Final = TRSC_VC_B.Product1_b;
    } else {
      TRSC_VC_B.Switch_TAD_des_Final = TRSC_VC_B.Yk;
    }

    /* End of Switch: '<S117>/Switch_TAD_des_Final' */

    /* Sum: '<S136>/Difference Inputs1'
     *
     * Block description for '<S136>/Difference Inputs1':
     *
     *  Add in CPU
     */
    TRSC_VC_B.UkYk1_c = TRSC_VC_B.Switch_TAD_des_Final - TRSC_VC_B.Yk1;

    /* RelationalOperator: '<S140>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator1_g = (TRSC_VC_B.UkYk1_c >
      TRSC_VC_B.deltariselimit);

    /* Gain: '<S117>/Gain7' incorporates:
     *  Constant: '<S117>/KeTRSC_ddeg_TadDesRateLim'
     */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 = (-1.0F) * KeTRSC_ddeg_TadDesRateLim;

    /* Product: '<S136>/delta fall limit' */
    TRSC_VC_B.deltafalllimit = TRSC_VC_B.DiscreteTimeIntegrator_o1 *
      TRSC_VC_B.sampletime;

    /* RelationalOperator: '<S140>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.UkYk1_c < TRSC_VC_B.deltafalllimit);

    /* Switch: '<S140>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_a = TRSC_VC_B.deltafalllimit;
    } else {
      TRSC_VC_B.Switch_a = TRSC_VC_B.UkYk1_c;
    }

    /* End of Switch: '<S140>/Switch' */

    /* Switch: '<S140>/Switch2' */
    if (TRSC_VC_B.RelationalOperator1_g) {
      TRSC_VC_B.Switch2_k = TRSC_VC_B.deltariselimit;
    } else {
      TRSC_VC_B.Switch2_k = TRSC_VC_B.Switch_a;
    }

    /* End of Switch: '<S140>/Switch2' */

    /* Sum: '<S136>/Difference Inputs2'
     *
     * Block description for '<S136>/Difference Inputs2':
     *
     *  Add in CPU
     */
    TRSC_VC_B.DifferenceInputs2 = TRSC_VC_B.Switch2_k + TRSC_VC_B.Yk1;

    /* Sum: '<S117>/Add6' */
    TRSC_VC_B.Add6 = TRSC_VC_B.Gain_g - TRSC_VC_B.DifferenceInputs2;

    /* RelationalOperator: '<S137>/LowerRelop1' incorporates:
     *  Constant: '<S117>/KeTRSC_deg_TadErrSatLim'
     */
    TRSC_VC_B.RelationalOperator1_g = (TRSC_VC_B.Add6 > KeTRSC_deg_TadErrSatLim);

    /* Gain: '<S117>/Gain4' incorporates:
     *  Constant: '<S117>/KeTRSC_deg_TadErrSatLim'
     */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 = (-1.0F) * KeTRSC_deg_TadErrSatLim;

    /* RelationalOperator: '<S137>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.Add6 <
      TRSC_VC_B.DiscreteTimeIntegrator_o1);

    /* Switch: '<S137>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_am = TRSC_VC_B.DiscreteTimeIntegrator_o1;
    } else {
      TRSC_VC_B.Switch_am = TRSC_VC_B.Add6;
    }

    /* End of Switch: '<S137>/Switch' */

    /* Switch: '<S137>/Switch2' incorporates:
     *  Constant: '<S117>/KeTRSC_deg_TadErrSatLim'
     */
    if (TRSC_VC_B.RelationalOperator1_g) {
      MeCtrl_deg_TAD_error = KeTRSC_deg_TadErrSatLim;
    } else {
      MeCtrl_deg_TAD_error = TRSC_VC_B.Switch_am;
    }

    /* End of Switch: '<S137>/Switch2' */

    /* Delay: '<S134>/Resettable Delay' */
    if (TRSC_VC_B.Delay_lx && (TRSC_VC_PrevZCX.ResettableDelay_Reset_ZCE_a !=
         POS_ZCSIG)) {
      TRSC_VC_DW.icLoad_k = 1U;
    }

    TRSC_VC_PrevZCX.ResettableDelay_Reset_ZCE_a = TRSC_VC_B.Delay_lx;
    if (TRSC_VC_DW.icLoad_k != 0) {
      TRSC_VC_DW.ResettableDelay_DSTATE_e = TRSC_VC_B.Gain15;
    }

    TRSC_VC_B.Yk1_l = TRSC_VC_DW.ResettableDelay_DSTATE_e;

    /* End of Delay: '<S134>/Resettable Delay' */

    /* Product: '<S134>/delta rise limit' incorporates:
     *  Constant: '<S134>/Constant'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_TGTADdesRateChange *
      KM_SamplingTime;

    /* Sum: '<S134>/Difference Inputs1'
     *
     * Block description for '<S134>/Difference Inputs1':
     *
     *  Add in CPU
     */
    TRSC_VC_B.UkYk1_n = TRSC_VC_B.Gain15 - TRSC_VC_B.Yk1_l;

    /* RelationalOperator: '<S138>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator1_g = (TRSC_VC_B.UkYk1_n >
      TRSC_VC_B.DiscreteTimeIntegrator_o1);

    /* Gain: '<S134>/Gain' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Abs_d = (-1.0F) *
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_deg_TGTADdesRateChange;

    /* Product: '<S134>/Delta_Fall_Limit' incorporates:
     *  Constant: '<S134>/Constant'
     */
    TRSC_VC_B.Abs_d *= KM_SamplingTime;

    /* RelationalOperator: '<S138>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.UkYk1_n < TRSC_VC_B.Abs_d);

    /* Switch: '<S138>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_p = TRSC_VC_B.Abs_d;
    } else {
      TRSC_VC_B.Switch_p = TRSC_VC_B.UkYk1_n;
    }

    /* End of Switch: '<S138>/Switch' */

    /* Switch: '<S138>/Switch2' */
    if (TRSC_VC_B.RelationalOperator1_g) {
      TRSC_VC_B.Switch2_mv = TRSC_VC_B.DiscreteTimeIntegrator_o1;
    } else {
      TRSC_VC_B.Switch2_mv = TRSC_VC_B.Switch_p;
    }

    /* End of Switch: '<S138>/Switch2' */

    /* Sum: '<S134>/Difference Inputs2'
     *
     * Block description for '<S134>/Difference Inputs2':
     *
     *  Add in CPU
     */
    TRSC_VC_B.Yk_p = TRSC_VC_B.Switch2_mv + TRSC_VC_B.Yk1_l;

    /* DataTypeConversion: '<S117>/Data Type Conversion1' */
    MeTRSC_deg_TrlrAngKnob = TRSC_VC_B.Yk_p;

    /* Switch: '<S118>/Switch_TAD_des_Final' incorporates:
     *  Constant: '<S118>/KeTRSC_ddeg_TadDesRateLim'
     *  Constant: '<S118>/KeTRSC_ddeg_TadDesRateLim1'
     */
    if (MeTRSC_deg_TrlrAngKnob != 0.0F) {
      TRSC_VC_B.DiscreteTimeIntegrator_o1 = KeTRSC_k_TadPidPGainMult;
    } else {
      TRSC_VC_B.DiscreteTimeIntegrator_o1 = CeConst_k_ConstOne;
    }

    /* End of Switch: '<S118>/Switch_TAD_des_Final' */

    /* Abs: '<S118>/Abs' */
    TRSC_VC_B.Abs_d = TRSC_VC_B.gamma_now_deg_m;

    /* Lookup_n-D: '<S118>/2-D Lookup Table1' */
    TRSC_VC_B.Product5_m = look2_iflf_linlcapw(TRSC_VC_B.Abs_d,
      TRSC_VC_B.Switch6, ((real32_T *)&(KaTRA_v_PGainLUTXBrkPts[0])), ((real32_T
      *)&(KaTRA_m_PGainLUTYBrkPts[0])), ((real32_T *)&(KaTRA_k_PGainLUTTblData[0])),
      rtCP_uDLookupTable1_maxIndex, 2U);

    /* Product: '<S118>/Divide3' */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 *= TRSC_VC_B.Product5_m;

    /* Product: '<S141>/Product' */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 *= MeCtrl_deg_TAD_error;

    /* Gain: '<S117>/Gain' incorporates:
     *  Constant: '<S117>/Constant1'
     */
    TRSC_VC_B.Product5_m = 0.01F * KeTRSC_pct_JackKnifePerc;

    /* Product: '<S117>/Product2' */
    TRSC_VC_B.Product5_m *= TRSC_VC_B.KnobScalingLUT * TRSC_VC_B.Switch2_c;

    /* Abs: '<S141>/Abs1' */
    TRSC_VC_B.Product_p = TRSC_VC_B.Abs_c;

    /* RelationalOperator: '<S141>/Relational Operator1' */
    TRSC_VC_B.RelationalOperator1_g = (TRSC_VC_B.Product5_m <
      TRSC_VC_B.Product_p);

    /* Sum: '<S117>/Subtract' */
    TRSC_VC_B.Product_p = TRSC_VC_B.Gain_g - MeCtrl_deg_TAD_error;

    /* Signum: '<S141>/Sign' */
    if (TRSC_VC_B.Product_p < 0.0F) {
      TRSC_VC_B.Product_p = -1.0F;
    } else if (TRSC_VC_B.Product_p > 0.0F) {
      TRSC_VC_B.Product_p = 1.0F;
    } else if (TRSC_VC_B.Product_p == 0.0F) {
      TRSC_VC_B.Product_p = 0.0F;
    } else {
      TRSC_VC_B.Product_p = (rtNaNF);
    }

    /* End of Signum: '<S141>/Sign' */

    /* Signum: '<S141>/Sign1' */
    if (TRSC_VC_B.Gain_g < 0.0F) {
      TRSC_VC_B.Product5_m = -1.0F;
    } else if (TRSC_VC_B.Gain_g > 0.0F) {
      TRSC_VC_B.Product5_m = 1.0F;
    } else if (TRSC_VC_B.Gain_g == 0.0F) {
      TRSC_VC_B.Product5_m = 0.0F;
    } else {
      TRSC_VC_B.Product5_m = (rtNaNF);
    }

    /* End of Signum: '<S141>/Sign1' */

    /* RelationalOperator: '<S141>/Relational Operator2' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.Product_p == TRSC_VC_B.Product5_m);

    /* Logic: '<S141>/Logical Operator' */
    TRSC_VC_B.RelationalOperator1_g = (TRSC_VC_B.RelationalOperator1_g &&
      TRSC_VC_B.UpperRelop_m);

    /* Logic: '<S141>/Logical Operator1' */
    TRSC_VC_B.RelationalOperator1_g = !TRSC_VC_B.RelationalOperator1_g;

    /* Switch: '<S141>/Switch1' incorporates:
     *  Constant: '<S141>/Constant2'
     *  Constant: '<S141>/Constant3'
     */
    if (TRSC_VC_B.RelationalOperator1_g) {
      TRSC_VC_B.Product_p = CeConst_k_ConstZero;
    } else {
      TRSC_VC_B.Product_p = CeConst_k_ConstOne;
    }

    /* End of Switch: '<S141>/Switch1' */

    /* Delay: '<S118>/Delay' */
    if (TRSC_VC_B.Delay_lx && (TRSC_VC_PrevZCX.Delay_Reset_ZCE != POS_ZCSIG)) {
      TRSC_VC_DW.Delay_DSTATE_o[0] = true;
      TRSC_VC_DW.Delay_DSTATE_o[1] = true;
      TRSC_VC_DW.Delay_DSTATE_o[2] = true;
      TRSC_VC_DW.Delay_DSTATE_o[3] = true;
    }

    TRSC_VC_PrevZCX.Delay_Reset_ZCE = TRSC_VC_B.Delay_lx;
    TRSC_VC_B.Delay_p = TRSC_VC_DW.Delay_DSTATE_o[0];

    /* End of Delay: '<S118>/Delay' */

    /* Logic: '<S118>/OR' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.Compare_f || TRSC_VC_B.Delay_p);

    /* Logic: '<S118>/AND' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.UpperRelop_m && TRSC_VC_B.Delay_lx);

    /* Logic: '<S141>/Logical Operator2' */
    TRSC_VC_B.LogicalOperator2_m = (TRSC_VC_B.RelationalOperator1_g ||
      TRSC_VC_B.UpperRelop_m);

    /* Outputs for Resettable SubSystem: '<S141>/Integrator_Subsytem' incorporates:
     *  ResetPort: '<S142>/Reset'
     */
    if ((((TRSC_VC_PrevZCX.Integrator_Subsytem_Reset_ZCE == POS_ZCSIG) !=
          (int32_T)TRSC_VC_B.LogicalOperator2_m) &&
         (TRSC_VC_PrevZCX.Integrator_Subsytem_Reset_ZCE != UNINITIALIZED_ZCSIG))
        || TRSC_VC_B.LogicalOperator2_m) {
      /* InitializeConditions for UnitDelay: '<S142>/Unit Delay' */
      TRSC_VC_DW.UnitDelay_DSTATE_p = 0.0F;

      /* InitializeConditions for UnitDelay: '<S142>/Unit Delay1' */
      TRSC_VC_DW.UnitDelay1_DSTATE = 0.0;
    }

    TRSC_VC_PrevZCX.Integrator_Subsytem_Reset_ZCE = TRSC_VC_B.LogicalOperator2_m;

    /* UnitDelay: '<S142>/Unit Delay' */
    TRSC_VC_B.Add_me = TRSC_VC_DW.UnitDelay_DSTATE_p;

    /* UnitDelay: '<S142>/Unit Delay1' */
    TRSC_VC_B.Switch = TRSC_VC_DW.UnitDelay1_DSTATE;

    /* Product: '<S142>/Product' incorporates:
     *  Constant: '<S118>/CeTRA_sec_SampleTime'
     */
    TRSC_VC_B.Product = TRSC_VC_B.Switch * CeTRA_sec_SampleTime;

    /* Sum: '<S142>/Add' */
    TRSC_VC_B.Add_pu = (real32_T)(TRSC_VC_B.Add_me + TRSC_VC_B.Product);

    /* End of Outputs for SubSystem: '<S141>/Integrator_Subsytem' */

    /* Product: '<S141>/Product4' incorporates:
     *  Constant: '<S141>/Constant1'
     */
    TRSC_VC_B.Product_p = TRSC_VC_B.Product_p * TRSC_VC_B.Add_pu *
      KeTRSC_k_EnblJKPrevention;

    /* Product: '<S141>/Product2' incorporates:
     *  Constant: '<S118>/CeTRA_k_Zero_One1'
     */
    TRSC_VC_B.Product5_m = MeCtrl_deg_TAD_error * CeTRA_k_OnePerHundred;

    /* Outputs for Resettable SubSystem: '<S141>/Integrator_Subsytem1' */
    /* Constant: '<S118>/CeTRA_sec_SampleTime' */
    TRSC_VC_Integrator_Subsytem1(CeTRA_sec_SampleTime, TRSC_VC_B.Delay_lx,
      &TRSC_VC_B.Add_me, &TRSC_VC_B.Integrator_Subsytem1,
      &TRSC_VC_DW.Integrator_Subsytem1, &TRSC_VC_PrevZCX.Integrator_Subsytem1);

    /* End of Outputs for SubSystem: '<S141>/Integrator_Subsytem1' */

    /* Sum: '<S141>/Add1' */
    TRSC_VC_B.Product5_m -= TRSC_VC_B.Add_me;

    /* Product: '<S141>/Product3' incorporates:
     *  Constant: '<S118>/CeTRA_k_ConstTen'
     */
    TRSC_VC_B.Product3_g = TRSC_VC_B.Product5_m * CeTRA_k_ConstTen;

    /* Sum: '<S141>/Add' */
    MeCtrl_deg_TAD_PID = (TRSC_VC_B.DiscreteTimeIntegrator_o1 +
                          TRSC_VC_B.Product_p) + TRSC_VC_B.Product3_g;

    /* Product: '<S112>/Product' incorporates:
     *  Constant: '<S112>/CeConst_ku_deg2rad'
     */
    TRSC_VC_B.Product_p = MeCtrl_deg_TAD_PID * CeConst_ku_deg2rad;

    /* Sum: '<S112>/Add1' */
    TRSC_VC_B.integrator_multiplier_table_type1 -= TRSC_VC_B.Product_p;

    /* Product: '<S112>/Divide1' */
    TRSC_VC_B.Product_p = TRSC_VC_B.Gain2 * TRSC_VC_B.Divide_pk;

    /* Product: '<S112>/Divide2' */
    TRSC_VC_B.Product_p /= TRSC_VC_B.Switch6;

    /* RelationalOperator: '<S124>/Relational Operator2' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.Gain_g >= TRSC_VC_ConstB.Gain1);

    /* RelationalOperator: '<S124>/Relational Operator3' incorporates:
     *  Constant: '<S124>/90Deg2'
     */
    TRSC_VC_B.RelationalOperator_f = (90.0F >= TRSC_VC_B.Gain_g);

    /* Logic: '<S124>/Logical Operator' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.UpperRelop_m &&
      TRSC_VC_B.RelationalOperator_f);

    /* Switch: '<S124>/Switch2' */
    if (TRSC_VC_B.UpperRelop_m) {
      /* RelationalOperator: '<S124>/Relational Operator4' incorporates:
       *  Constant: '<S124>/0Deg1'
       */
      TRSC_VC_B.RelationalOperator4_c = (TRSC_VC_B.Gain_g >= 0.0F);

      /* Switch: '<S124>/Switch3' */
      if (TRSC_VC_B.RelationalOperator4_c) {
        /* Lookup_n-D: '<S124>/1-D Lookup Table_0_3' */
        TRSC_VC_B.uDLookupTable_0_3_p = look1_iflf_linlxpw(TRSC_VC_B.Gain_g,
          rtCP_uDLookupTable_0_3_bp01Data_d, rtCP_uDLookupTable_0_3_tableData_f,
          90U);
        TRSC_VC_B.Switch3_h = TRSC_VC_B.uDLookupTable_0_3_p;
      } else {
        /* Gain: '<S124>/Gain2' */
        TRSC_VC_B.Gain2_i = (-1.0F) * TRSC_VC_B.Gain_g;

        /* Lookup_n-D: '<S124>/1-D Lookup Table_0_2' */
        TRSC_VC_B.uDLookupTable_0_2_mx = look1_iflf_linlxpw(TRSC_VC_B.Gain2_i,
          rtCP_uDLookupTable_0_2_bp01Data_i, rtCP_uDLookupTable_0_2_tableData_ia,
          90U);
        TRSC_VC_B.Switch3_h = TRSC_VC_B.uDLookupTable_0_2_mx;
      }

      /* End of Switch: '<S124>/Switch3' */
      TRSC_VC_B.Product5_m = TRSC_VC_B.Switch3_h;
    } else {
      /* Abs: '<S124>/Abs1' */
      TRSC_VC_B.uDLookupTable_0_1_e = TRSC_VC_B.Abs_c;

      /* Sum: '<S124>/Add1' incorporates:
       *  Constant: '<S124>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_e -= 90.0F;

      /* Sum: '<S124>/Add2' incorporates:
       *  Constant: '<S124>/90Deg2'
       */
      TRSC_VC_B.uDLookupTable_0_1_e = 90.0F - TRSC_VC_B.uDLookupTable_0_1_e;

      /* Lookup_n-D: '<S124>/1-D Lookup Table_0_1' */
      TRSC_VC_B.uDLookupTable_0_1_e = look1_iflf_linlxpw
        (TRSC_VC_B.uDLookupTable_0_1_e, rtCP_uDLookupTable_0_1_bp01Data_l,
         rtCP_uDLookupTable_0_1_tableData_jz, 90U);

      /* Gain: '<S124>/Gain3' */
      TRSC_VC_B.Gain3_l = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_e;
      TRSC_VC_B.Product5_m = TRSC_VC_B.Gain3_l;
    }

    /* Product: '<S112>/Divide3' */
    TRSC_VC_B.Product_p *= TRSC_VC_B.Product5_m;

    /* Sum: '<S112>/Add' */
    TRSC_VC_B.Divide_pk += TRSC_VC_B.Product_p;

    /* Product: '<S112>/Divide' */
    TRSC_VC_B.Divide_pk = TRSC_VC_B.Switch2 / TRSC_VC_B.Divide_pk;

    /* Product: '<S112>/Divide6' */
    TRSC_VC_B.Divide6 = TRSC_VC_B.Divide_pk *
      TRSC_VC_B.integrator_multiplier_table_type1;

    /* RelationalOperator: '<S123>/Relational Operator6' incorporates:
     *  Constant: '<S123>/Deg_0'
     */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.Divide6 >= 0.0F);

    /* Switch: '<S123>/Switch4' */
    if (TRSC_VC_B.RelationalOperator_f) {
      /* Lookup_n-D: '<S123>/1-D Lookup Table_0_6' */
      TRSC_VC_B.uDLookupTable_0_6_k = look1_iflf_linlxpw(TRSC_VC_B.Divide6,
        rtCP_uDLookupTable_0_6_bp01Data_f, rtCP_uDLookupTable_0_6_tableData_e,
        100U);
      TRSC_VC_B.tanVals = TRSC_VC_B.uDLookupTable_0_6_k;
    } else {
      /* Gain: '<S123>/Gain5' */
      TRSC_VC_B.uDLookupTable_0_1_g = (-1.0F) * TRSC_VC_B.Divide6;

      /* Lookup_n-D: '<S123>/1-D Lookup Table_0_1' */
      TRSC_VC_B.uDLookupTable_0_1_g = look1_iflf_linlxpw
        (TRSC_VC_B.uDLookupTable_0_1_g, rtCP_uDLookupTable_0_1_bp01Data_j,
         rtCP_uDLookupTable_0_1_tableData_n5, 100U);

      /* Gain: '<S123>/Gain1' */
      TRSC_VC_B.Gain1_g = (-1.0F) * TRSC_VC_B.uDLookupTable_0_1_g;
      TRSC_VC_B.tanVals = TRSC_VC_B.Gain1_g;
    }

    /* End of Switch: '<S123>/Switch4' */

    /* RelationalOperator: '<S127>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.tanVals >
      TRSC_VC_B.LookupTableDynamic1);

    /* Gain: '<S113>/Gain5' */
    TRSC_VC_B.Product_p = (-1.0F) * TRSC_VC_B.LookupTableDynamic1;

    /* RelationalOperator: '<S127>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.tanVals < TRSC_VC_B.Product_p);

    /* Switch: '<S127>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_a4 = TRSC_VC_B.Product_p;
    } else {
      TRSC_VC_B.Switch_a4 = TRSC_VC_B.tanVals;
    }

    /* End of Switch: '<S127>/Switch' */

    /* Switch: '<S127>/Switch2' */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch2_l = TRSC_VC_B.LookupTableDynamic1;
    } else {
      TRSC_VC_B.Switch2_l = TRSC_VC_B.Switch_a4;
    }

    /* End of Switch: '<S127>/Switch2' */

    /* RelationalOperator: '<S113>/Relational Operator1' incorporates:
     *  Constant: '<S113>/Constant3'
     */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.Switch2_l == CeConst_k_ConstZero);

    /* Switch: '<S113>/Switch1' */
    if (TRSC_VC_B.RelationalOperator_f) {
      MeCtrl_deg_SteerAngIn = TRSC_VC_B.Switch2_l;
    } else {
      /* Product: '<S113>/Divide' incorporates:
       *  Constant: '<S113>/Constant4'
       */
      TRSC_VC_B.Divide_n = CeConst_k_ConstOne / TRSC_VC_B.Gain7;

      /* Sum: '<S113>/Add' */
      TRSC_VC_B.Add_b2 = TRSC_VC_B.Switch2_l - TRSC_VC_B.Gain8;

      /* Product: '<S113>/Product' */
      TRSC_VC_B.MeCtrl_deg_SteerAngIn_c = TRSC_VC_B.Add_b2 * TRSC_VC_B.Divide_n;
      MeCtrl_deg_SteerAngIn = TRSC_VC_B.MeCtrl_deg_SteerAngIn_c;
    }

    /* End of Switch: '<S113>/Switch1' */

    /* RelationalOperator: '<S129>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator_f = (MeCtrl_deg_SteerAngIn > TRSC_VC_B.Gain1);

    /* Gain: '<S113>/Gain3' */
    TRSC_VC_B.Product_p = (-1.0F) * TRSC_VC_B.Gain1;

    /* RelationalOperator: '<S129>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (MeCtrl_deg_SteerAngIn < TRSC_VC_B.Product_p);

    /* Switch: '<S129>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_m = TRSC_VC_B.Product_p;
    } else {
      TRSC_VC_B.Switch_m = MeCtrl_deg_SteerAngIn;
    }

    /* End of Switch: '<S129>/Switch' */

    /* Switch: '<S129>/Switch2' */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch2_f = TRSC_VC_B.Gain1;
    } else {
      TRSC_VC_B.Switch2_f = TRSC_VC_B.Switch_m;
    }

    /* End of Switch: '<S129>/Switch2' */

    /* DataTypeConversion: '<S113>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.DataTypeConversion1 =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng;

    /* Delay: '<S109>/Delay' */
    TRSC_VC_B.RelationalOperator_f = TRSC_VC_DW.Delay_DSTATE_kg;

    /* Logic: '<S113>/Logical Operator1' */
    TRSC_VC_B.LogicalOperator1_g = (TRSC_VC_B.Delay_lx &&
      TRSC_VC_B.RelationalOperator_f);

    /* Delay: '<S126>/Resettable Delay' */
    if (TRSC_VC_B.LogicalOperator1_g &&
        (TRSC_VC_PrevZCX.ResettableDelay_Reset_ZCE_g != POS_ZCSIG)) {
      TRSC_VC_DW.icLoad_d = 1U;
    }

    TRSC_VC_PrevZCX.ResettableDelay_Reset_ZCE_g = TRSC_VC_B.LogicalOperator1_g;
    if (TRSC_VC_DW.icLoad_d != 0) {
      TRSC_VC_DW.ResettableDelay_DSTATE_i = TRSC_VC_B.DataTypeConversion1;
    }

    TRSC_VC_B.Yk1_c = TRSC_VC_DW.ResettableDelay_DSTATE_i;

    /* End of Delay: '<S126>/Resettable Delay' */

    /* Sum: '<S126>/Difference Inputs1'
     *
     * Block description for '<S126>/Difference Inputs1':
     *
     *  Add in CPU
     */
    TRSC_VC_B.UkYk1_k = TRSC_VC_B.Switch2_f - TRSC_VC_B.Yk1_c;

    /* Product: '<S126>/delta rise limit' incorporates:
     *  Constant: '<S126>/Constant'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Product_p =
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRA_k_SteerAngRateLmt *
      KM_SamplingTime;

    /* RelationalOperator: '<S130>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.UkYk1_k > TRSC_VC_B.Product_p);

    /* Gain: '<S126>/Gain' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.Product5_m = (-1.0F) *
      IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRA_k_SteerAngRateLmt;

    /* Product: '<S126>/Delta_Fall_Limit' incorporates:
     *  Constant: '<S126>/Constant'
     */
    TRSC_VC_B.Product5_m *= KM_SamplingTime;

    /* RelationalOperator: '<S130>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.UkYk1_k < TRSC_VC_B.Product5_m);

    /* Switch: '<S130>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_c = TRSC_VC_B.Product5_m;
    } else {
      TRSC_VC_B.Switch_c = TRSC_VC_B.UkYk1_k;
    }

    /* End of Switch: '<S130>/Switch' */

    /* Switch: '<S130>/Switch2' */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch2_mt = TRSC_VC_B.Product_p;
    } else {
      TRSC_VC_B.Switch2_mt = TRSC_VC_B.Switch_c;
    }

    /* End of Switch: '<S130>/Switch2' */

    /* Sum: '<S126>/Difference Inputs2'
     *
     * Block description for '<S126>/Difference Inputs2':
     *
     *  Add in CPU
     */
    TRSC_VC_B.Yk_j = TRSC_VC_B.Switch2_mt + TRSC_VC_B.Yk1_c;

    /* DataTypeConversion: '<S126>/Data Type Conversion' */
    MeCtrl_deg_SteerCMD = TRSC_VC_B.Yk_j;

    /* RelationalOperator: '<S128>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator_f = (MeCtrl_deg_SteerCMD > TRSC_VC_B.Gain1);

    /* Gain: '<S113>/Gain1' */
    TRSC_VC_B.Product_p = (-1.0F) * TRSC_VC_B.Gain1;

    /* RelationalOperator: '<S128>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (MeCtrl_deg_SteerCMD < TRSC_VC_B.Product_p);

    /* Switch: '<S128>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_l = TRSC_VC_B.Product_p;
    } else {
      TRSC_VC_B.Switch_l = MeCtrl_deg_SteerCMD;
    }

    /* End of Switch: '<S128>/Switch' */

    /* Switch: '<S128>/Switch2' */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch2_e = TRSC_VC_B.Gain1;
    } else {
      TRSC_VC_B.Switch2_e = TRSC_VC_B.Switch_l;
    }

    /* End of Switch: '<S128>/Switch2' */

    /* Product: '<S160>/Divide' incorporates:
     *  Constant: '<S122>/Constant3'
     *  Constant: '<S122>/Steering_controller_low_pass_filter_frequency'
     *  Constant: '<S160>/Constant1'
     */
    TRSC_VC_B.Product_p = (real32_T)(6.28318548F * KeTRSC_k_StrCtrlLPFFrequency *
      0.03);

    /* Product: '<S160>/Product1' */
    TRSC_VC_B.Product5_m = TRSC_VC_B.Switch2_e * TRSC_VC_B.Product_p;

    /* Delay: '<S160>/Delay' */
    if (TRSC_VC_DW.icLoad_j != 0) {
      TRSC_VC_DW.Delay_DSTATE = TRSC_VC_B.Switch2_e;
    }

    TRSC_VC_B.Delay_d = TRSC_VC_DW.Delay_DSTATE;

    /* End of Delay: '<S160>/Delay' */

    /* Sum: '<S160>/Add' incorporates:
     *  Constant: '<S160>/Constant'
     */
    TRSC_VC_B.Product_p = 1.0F - TRSC_VC_B.Product_p;

    /* Product: '<S160>/Product' */
    TRSC_VC_B.Product_p *= TRSC_VC_B.Delay_d;

    /* Sum: '<S160>/Sum' */
    StrCmd = TRSC_VC_B.Product5_m + TRSC_VC_B.Product_p;

    /* UnitDelay: '<S159>/Unit Delay1' */
    TRSC_VC_B.Product_p = TRSC_VC_DW.UnitDelay1_DSTATE_n;

    /* Sum: '<S159>/Subtract2' */
    TRSC_VC_B.Product_p = StrCmd - TRSC_VC_B.Product_p;

    /* Gain: '<S159>/inverse_dt1' */
    TRSC_VC_B.Product_p *= 33.3333321F;

    /* DataTypeConversion: '<S122>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    StrRpt = IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng;

    /* Product: '<S166>/Divide' incorporates:
     *  Constant: '<S159>/Constant6'
     *  Constant: '<S159>/Steering_report_low_pass_filter_frequency'
     *  Constant: '<S166>/Constant1'
     */
    TRSC_VC_B.Product5_m = (real32_T)(6.28318548F * KeTRSC_k_StrRptLPFFrequency *
      0.03);

    /* Product: '<S166>/Product1' */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 = StrRpt * TRSC_VC_B.Product5_m;

    /* Delay: '<S166>/Delay' */
    if (TRSC_VC_DW.icLoad_p != 0) {
      TRSC_VC_DW.Delay_DSTATE_f = StrRpt;
    }

    TRSC_VC_B.Delay_l = TRSC_VC_DW.Delay_DSTATE_f;

    /* End of Delay: '<S166>/Delay' */

    /* Sum: '<S166>/Add' incorporates:
     *  Constant: '<S166>/Constant'
     */
    TRSC_VC_B.Product5_m = 1.0F - TRSC_VC_B.Product5_m;

    /* Product: '<S166>/Product' */
    TRSC_VC_B.Product5_m *= TRSC_VC_B.Delay_l;

    /* Sum: '<S166>/Sum' */
    TRSC_VC_B.Sum_m = TRSC_VC_B.DiscreteTimeIntegrator_o1 + TRSC_VC_B.Product5_m;

    /* UnitDelay: '<S159>/Unit Delay2' */
    TRSC_VC_B.Product5_m = TRSC_VC_DW.UnitDelay2_DSTATE;

    /* Sum: '<S159>/Subtract3' */
    TRSC_VC_B.Product5_m = TRSC_VC_B.Sum_m - TRSC_VC_B.Product5_m;

    /* Gain: '<S159>/inverse_dt2' */
    TRSC_VC_B.Product5_m *= 33.3333321F;

    /* Sum: '<S159>/Sum2' */
    TRSC_VC_B.Product_p -= TRSC_VC_B.Product5_m;

    /* RelationalOperator: '<S154>/Compare' incorporates:
     *  Constant: '<S154>/Constant'
     */
    TRSC_VC_B.Compare_p = (TRSC_VC_B.Delay_lx == true);

    /* DataTypeConversion: '<S122>/Data Type Conversion' */
    TRSC_VC_B.DataTypeConversion = TRSC_VC_B.Compare_p;

    /* DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */
    if (((TRSC_VC_B.DataTypeConversion > 0.0F) &&
         (TRSC_VC_DW.DiscreteTimeIntegrator1_PrevResetState <= 0)) ||
        ((TRSC_VC_B.DataTypeConversion <= 0.0F) &&
         (TRSC_VC_DW.DiscreteTimeIntegrator1_PrevResetState == 1))) {
      TRSC_VC_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }

    MeTRSC_s_TwitchTmr = TRSC_VC_DW.DiscreteTimeIntegrator1_DSTATE;

    /* End of DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */

    /* MATLAB Function: '<S122>/MATLAB Function' incorporates:
     *  Constant: '<S122>/Constant1'
     *  Constant: '<S122>/Constant10'
     *  Constant: '<S122>/Constant11'
     *  Constant: '<S122>/Constant9'
     */
    if (MeTRSC_s_TwitchTmr < KeTRSC_sec_CornerCaseTimeLimit) {
      if (0.0 == TRSC_VC_DW.last_Identified_Case) {
        TRSC_VC_B.gamma_now_deg_m = fabsf(StrRpt);
        TRSC_VC_B.Dt = KeTRSC_pct_StrCornerCaseThr * TRSC_VC_B.Gain1;
        if ((TRSC_VC_B.gamma_now_deg_m >= TRSC_VC_B.Dt) && (TRSC_VC_B.Abs_c >=
             KeTRSC_deg_TadCornerCaseThr)) {
          if (StrRpt < 0.0F) {
            TRSC_VC_B.gamma_now_deg_m = -1.0F;
          } else if (StrRpt > 0.0F) {
            TRSC_VC_B.gamma_now_deg_m = 1.0F;
          } else if (StrRpt == 0.0F) {
            TRSC_VC_B.gamma_now_deg_m = 0.0F;
          } else {
            TRSC_VC_B.gamma_now_deg_m = (rtNaNF);
          }

          if (TRSC_VC_B.Gain_g < 0.0F) {
            TRSC_VC_B.Dt = -1.0F;
          } else if (TRSC_VC_B.Gain_g > 0.0F) {
            TRSC_VC_B.Dt = 1.0F;
          } else if (TRSC_VC_B.Gain_g == 0.0F) {
            TRSC_VC_B.Dt = 0.0F;
          } else {
            TRSC_VC_B.Dt = (rtNaNF);
          }

          guard1 = false;
          if (TRSC_VC_B.gamma_now_deg_m != TRSC_VC_B.Dt) {
            if (TRSC_VC_B.Gain_g < 0.0F) {
              TRSC_VC_B.Dt = -1.0F;
            } else if (TRSC_VC_B.Gain_g > 0.0F) {
              TRSC_VC_B.Dt = 1.0F;
            } else if (TRSC_VC_B.Gain_g == 0.0F) {
              TRSC_VC_B.Dt = 0.0F;
            } else {
              TRSC_VC_B.Dt = (rtNaNF);
            }

            if (TRSC_VC_B.gamma_now_deg_m * TRSC_VC_B.Dt != 0.0F) {
              TRSC_VC_B.Identified_Case = 1.0;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            if (StrRpt < 0.0F) {
              TRSC_VC_B.gamma_now_deg_m = -1.0F;
            } else if (StrRpt > 0.0F) {
              TRSC_VC_B.gamma_now_deg_m = 1.0F;
            } else if (StrRpt == 0.0F) {
              TRSC_VC_B.gamma_now_deg_m = 0.0F;
            } else {
              TRSC_VC_B.gamma_now_deg_m = (rtNaNF);
            }

            if (TRSC_VC_B.Gain_g < 0.0F) {
              TRSC_VC_B.Dt = -1.0F;
            } else if (TRSC_VC_B.Gain_g > 0.0F) {
              TRSC_VC_B.Dt = 1.0F;
            } else if (TRSC_VC_B.Gain_g == 0.0F) {
              TRSC_VC_B.Dt = 0.0F;
            } else {
              TRSC_VC_B.Dt = (rtNaNF);
            }

            if (TRSC_VC_B.gamma_now_deg_m == TRSC_VC_B.Dt) {
              if (StrRpt < 0.0F) {
                TRSC_VC_B.gamma_now_deg_m = -1.0F;
              } else if (StrRpt > 0.0F) {
                TRSC_VC_B.gamma_now_deg_m = 1.0F;
              } else if (StrRpt == 0.0F) {
                TRSC_VC_B.gamma_now_deg_m = 0.0F;
              } else {
                TRSC_VC_B.gamma_now_deg_m = (rtNaNF);
              }

              if (TRSC_VC_B.Gain_g < 0.0F) {
                TRSC_VC_B.Dt = -1.0F;
              } else if (TRSC_VC_B.Gain_g > 0.0F) {
                TRSC_VC_B.Dt = 1.0F;
              } else if (TRSC_VC_B.Gain_g == 0.0F) {
                TRSC_VC_B.Dt = 0.0F;
              } else {
                TRSC_VC_B.Dt = (rtNaNF);
              }

              if (TRSC_VC_B.gamma_now_deg_m * TRSC_VC_B.Dt != 0.0F) {
                TRSC_VC_B.Identified_Case = 3.0;
              } else {
                TRSC_VC_B.Identified_Case = 0.0;
              }
            } else {
              TRSC_VC_B.Identified_Case = 0.0;
            }
          }
        } else if (TRSC_VC_B.gamma_now_deg_m >= TRSC_VC_B.Dt) {
          if (TRSC_VC_B.Abs_c <= KeTRSC_deg_TadCornerCaseThr) {
            TRSC_VC_B.Identified_Case = 2.0;
          } else {
            TRSC_VC_B.Identified_Case = 0.0;
          }
        } else {
          TRSC_VC_B.Identified_Case = 0.0;
        }

        TRSC_VC_DW.last_Identified_Case = TRSC_VC_B.Identified_Case;
      } else {
        TRSC_VC_B.Identified_Case = TRSC_VC_DW.last_Identified_Case;
      }
    } else if (MeTRSC_s_TwitchTmr < KeTRSC_sec_CornerCaseLatchLimit) {
      TRSC_VC_B.Identified_Case = TRSC_VC_DW.last_Identified_Case;
    } else {
      TRSC_VC_B.Identified_Case = 0.0;
    }

    /* DataTypeConversion: '<S122>/Data Type Conversion3' */
    MeTRSC_e_IdentifiedCase = (real32_T)TRSC_VC_B.Identified_Case;

    /* Lookup_n-D: '<S159>/diffrential_multiplier_table_type1' */
    TRSC_VC_B.Product5_m = look1_iflf_binlxpw(MeTRSC_e_IdentifiedCase,
      rtCP_diffrential_multiplier_table_type1_bp01Data, ((real32_T *)
      &(KeTRSC_k_TrqCtrlDMultiplier[0])), 3U);

    /* Product: '<S159>/Product6' */
    TRSC_VC_B.Product_p *= TRSC_VC_B.Product5_m;

    /* RelationalOperator: '<S159>/Relational Operator3' incorporates:
     *  Constant: '<S159>/Constant4'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.RelationalOperator3_e =
      (IbTRSC_InpBus.IbTRSC_MEProxiToIpc.IePRX_e_StrRackPinTyp ==
       TeTRSC_e_StrRackPinTyp_Type2);

    /* RelationalOperator: '<S159>/Relational Operator5' incorporates:
     *  Constant: '<S159>/Constant8'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_VC_B.RelationalOperator_f =
      (IbTRSC_InpBus.IbTRSC_MEProxiToIpc.IePRX_e_StrRackPinTyp ==
       TeTRSC_e_StrRackPinTyp_Type3);

    /* Logic: '<S159>/Logical Operator2' */
    TRSC_VC_B.LogicalOperator2_d = (TRSC_VC_B.RelationalOperator3_e ||
      TRSC_VC_B.RelationalOperator_f);

    /* Switch: '<S159>/Switch11' */
    if (TRSC_VC_B.LogicalOperator2_d) {
      /* Lookup_n-D: '<S159>/proportional_multiplier_table_type2or3' */
      TRSC_VC_B.proportional_multiplier_table_type2or3 = look1_iflf_binlxpw
        (MeTRSC_e_IdentifiedCase,
         rtCP_proportional_multiplier_table_type2or3_bp01Data, ((real32_T *)
          &(KeTRSC_k_TrqCtrlPMultiplierT2or3[0])), 3U);
      TRSC_VC_B.Product5_m = TRSC_VC_B.proportional_multiplier_table_type2or3;
    } else {
      /* Lookup_n-D: '<S159>/proportional_multiplier_table_type1' */
      TRSC_VC_B.proportional_multiplier_table_type1 = look1_iflf_binlxpw
        (MeTRSC_e_IdentifiedCase,
         rtCP_proportional_multiplier_table_type1_bp01Data, ((real32_T *)
          &(KeTRSC_k_TrqCtrlPMultiplierT1[0])), 3U);
      TRSC_VC_B.Product5_m = TRSC_VC_B.proportional_multiplier_table_type1;
    }

    /* End of Switch: '<S159>/Switch11' */

    /* Lookup_n-D: '<S159>/error_sat_limit' */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 = look1_iflf_binlxpw
      (MeTRSC_e_IdentifiedCase, rtCP_error_sat_limit_bp01Data, ((real32_T *)
        &(KeTRSC_k_ErrSatLim[0])), 3U);

    /* Sum: '<S159>/Sum1' */
    TRSC_VC_B.err = StrCmd - StrRpt;

    /* RelationalOperator: '<S165>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.err >
      TRSC_VC_B.DiscreteTimeIntegrator_o1);

    /* Gain: '<S159>/Gain2' */
    TRSC_VC_B.integrator_multiplier_table_type1 = (-1.0F) *
      TRSC_VC_B.DiscreteTimeIntegrator_o1;

    /* RelationalOperator: '<S165>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.err <
      TRSC_VC_B.integrator_multiplier_table_type1);

    /* Switch: '<S165>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_bb = TRSC_VC_B.integrator_multiplier_table_type1;
    } else {
      TRSC_VC_B.Switch_bb = TRSC_VC_B.err;
    }

    /* End of Switch: '<S165>/Switch' */

    /* Switch: '<S165>/Switch2' */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch2_i = TRSC_VC_B.DiscreteTimeIntegrator_o1;
    } else {
      TRSC_VC_B.Switch2_i = TRSC_VC_B.Switch_bb;
    }

    /* End of Switch: '<S165>/Switch2' */

    /* DataTypeConversion: '<S159>/Data Type Conversion1' */
    TRSC_VC_B.DiscreteTimeIntegrator_o1 = TRSC_VC_B.Switch2_i;

    /* MATLAB Function: '<S159>/MATLAB Function' incorporates:
     *  Constant: '<S159>/Constant2'
     *  Constant: '<S159>/Constant7'
     */
    if (!TRSC_VC_B.RelationalOperator3) {
      TRSC_VC_DW.internal_timer = 0.0F;
    } else if (0.001F < fabsf(MeTRSC_e_IdentifiedCase)) {
      TRSC_VC_DW.internal_timer = 0.0F;
    } else {
      TRSC_VC_DW.internal_timer += CeTRA_sec_SampleTime;
    }

    if (0.0F != MeTRSC_e_IdentifiedCase) {
      TRSC_VC_B.KeTRSC_k_const_P_gain = 1.0F;
    } else {
      TRSC_VC_B.KeTRSC_k_const_P_gain = (real32_T)!(TRSC_VC_DW.internal_timer >=
        KeTRSC_s_HeldThreshold);
    }

    /* End of MATLAB Function: '<S159>/MATLAB Function' */

    /* Gain: '<S122>/Gain6' */
    TRSC_VC_B.integrator_multiplier_table_type1 = 3.6F * TRSC_VC_B.Gain;

    /* Abs: '<S159>/Abs1' */
    TRSC_VC_B.Abs1 = fabsf(TRSC_VC_B.integrator_multiplier_table_type1);

    /* Abs: '<S159>/Abs' */
    TRSC_VC_B.Abs = fabsf(TRSC_VC_B.DiscreteTimeIntegrator_o1);

    /* Switch: '<S159>/Switch13' incorporates:
     *  Switch: '<S159>/Switch8'
     */
    if (TRSC_VC_B.KeTRSC_k_const_P_gain != 0.0F) {
      TRSC_VC_B.integrator_multiplier_table_type1 =
        TRSC_VC_B.KeTRSC_k_const_P_gain;
    } else {
      if (TRSC_VC_B.LogicalOperator2_d) {
        /* Switch: '<S159>/Switch1' incorporates:
         *  Switch: '<S159>/Switch8'
         */
        if (TRSC_VC_B.RelationalOperator3_e) {
          /* Lookup_n-D: '<S159>/P_gain_lookup_table_type2' */
          TRSC_VC_B.P_gain_lookup_table_type2 = look2_iflf_binlxpw
            (TRSC_VC_B.Abs1, TRSC_VC_B.Abs, ((real32_T *)
              &(KaTRSC_kph_PGainLUTXBPTyp2[0])), ((real32_T *)
              &(KaTRSC_deg_PGainLUTYBPTyp2[0])), ((real32_T *)
              &(KaTRSC_k_PGainLUTTDTyp2[0])),
             rtCP_P_gain_lookup_table_type2_maxIndex, 4U);
          TRSC_VC_B.Switch1_n = TRSC_VC_B.P_gain_lookup_table_type2;
        } else {
          /* Lookup_n-D: '<S159>/P_gain_lookup_table_type3' */
          TRSC_VC_B.P_gain_lookup_table_type3 = look2_iflf_binlxpw
            (TRSC_VC_B.Abs1, TRSC_VC_B.Abs, ((real32_T *)
              &(KaTRSC_kph_PGainLUTXBPTyp3[0])), ((real32_T *)
              &(KaTRSC_deg_PGainLUTYBPTyp3[0])), ((real32_T *)
              &(KaTRSC_k_PGainLUTTDTyp3[0])),
             rtCP_P_gain_lookup_table_type3_maxIndex, 4U);
          TRSC_VC_B.Switch1_n = TRSC_VC_B.P_gain_lookup_table_type3;
        }

        /* End of Switch: '<S159>/Switch1' */

        /* Switch: '<S159>/Switch8' */
        TRSC_VC_B.StrTqFB_P_Old = TRSC_VC_B.Switch1_n;
      } else {
        /* Lookup_n-D: '<S159>/P_gain_lookup_table_type1' incorporates:
         *  Switch: '<S159>/Switch8'
         */
        TRSC_VC_B.StrTqFB_P_Old_f = look2_iflf_binlxpw(TRSC_VC_B.Abs1,
          TRSC_VC_B.Abs, ((real32_T *)&(KaTRSC_kph_PGainLUTXBPTyp1[0])),
          ((real32_T *)&(KaTRSC_deg_PGainLUTYBPTyp1[0])), ((real32_T *)
          &(KaTRSC_k_PGainLUTTDTyp1[0])),
          rtCP_P_gain_lookup_table_type1_maxIndex, 4U);

        /* Switch: '<S159>/Switch8' */
        TRSC_VC_B.StrTqFB_P_Old = TRSC_VC_B.StrTqFB_P_Old_f;
      }

      TRSC_VC_B.integrator_multiplier_table_type1 = TRSC_VC_B.StrTqFB_P_Old;
    }

    /* End of Switch: '<S159>/Switch13' */

    /* Product: '<S159>/Product' */
    TRSC_VC_B.integrator_multiplier_table_type1 *=
      TRSC_VC_B.DiscreteTimeIntegrator_o1;

    /* Product: '<S159>/Product4' */
    TRSC_VC_B.Product5_m *= TRSC_VC_B.integrator_multiplier_table_type1;

    /* UnitDelay: '<S122>/Unit Delay1' */
    TRSC_VC_B.RelationalOperator_f = TRSC_VC_DW.UnitDelay1_DSTATE_ed;

    /* RelationalOperator: '<S122>/Relational Operator4' incorporates:
     *  Constant: '<S122>/KeTRSC_s_TwitchTime'
     */
    TRSC_VC_B.UpperRelop_m = (MeTRSC_s_TwitchTmr >= KeTRSC_s_TwitchTime);

    /* Logic: '<S122>/Logical Operator' */
    MeTRSC_b_TwitchCompleted = (TRSC_VC_B.RelationalOperator_f ||
      TRSC_VC_B.UpperRelop_m);

    /* Logic: '<S122>/Logical Operator1' */
    TRSC_VC_B.LogicalOperator1_f = (TRSC_VC_B.Delay_lx &&
      MeTRSC_b_TwitchCompleted);

    /* DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
    if (TRSC_VC_DW.DiscreteTimeIntegrator_IC_LOADING != 0) {
      TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l =
        TRSC_VC_ConstB.DataTypeConversion2;
      if (TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l >= KeTRSC_k_IntExtSat) {
        TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l = KeTRSC_k_IntExtSat;
      } else {
        if (TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l <= -KeTRSC_k_IntExtSat) {
          TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l = -KeTRSC_k_IntExtSat;
        }
      }
    }

    if ((TRSC_VC_B.LogicalOperator1_f &&
         (TRSC_VC_DW.DiscreteTimeIntegrator_PrevResetState <= 0)) ||
        ((!TRSC_VC_B.LogicalOperator1_f) &&
         (TRSC_VC_DW.DiscreteTimeIntegrator_PrevResetState == 1))) {
      TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l =
        TRSC_VC_ConstB.DataTypeConversion2;
      if (TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l >= KeTRSC_k_IntExtSat) {
        TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l = KeTRSC_k_IntExtSat;
      } else {
        if (TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l <= -KeTRSC_k_IntExtSat) {
          TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l = -KeTRSC_k_IntExtSat;
        }
      }
    }

    if (TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l >= KeTRSC_k_IntExtSat) {
      TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l = KeTRSC_k_IntExtSat;
      TRSC_VC_B.DiscreteTimeIntegrator_o2 = 1.0F;
    } else if (TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l <= -KeTRSC_k_IntExtSat)
    {
      TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l = -KeTRSC_k_IntExtSat;
      TRSC_VC_B.DiscreteTimeIntegrator_o2 = -1.0F;
    } else {
      TRSC_VC_B.DiscreteTimeIntegrator_o2 = 0.0F;
    }

    TRSC_VC_B.DiscreteTimeIntegrator_o1 =
      TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l;

    /* End of DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */

    /* Sum: '<S159>/Add' */
    TRSC_VC_B.Product5_m = (TRSC_VC_B.Product5_m +
      TRSC_VC_B.DiscreteTimeIntegrator_o1) + TRSC_VC_B.Product_p;

    /* Sum: '<S159>/Add1' incorporates:
     *  Constant: '<S159>/Constant'
     */
    TRSC_VC_B.Add1_k = 0.0F + TRSC_VC_B.Product5_m;

    /* UnitDelay: '<S163>/Delay Input2'
     *
     * Block description for '<S163>/Delay Input2':
     *
     *  Store in Global RAM
     */
    TRSC_VC_B.Yk1_m = TRSC_VC_DW.DelayInput2_DSTATE_p;

    /* Sum: '<S163>/Difference Inputs1'
     *
     * Block description for '<S163>/Difference Inputs1':
     *
     *  Add in CPU
     */
    TRSC_VC_B.UkYk1_ks = TRSC_VC_B.Add1_k - TRSC_VC_B.Yk1_m;

    /* SampleTimeMath: '<S163>/sample time'
     *
     * About '<S163>/sample time':
     *  y = K where K = ( w * Ts )
     */
    TRSC_VC_B.sampletime_n = 0.03F;

    /* Product: '<S163>/delta rise limit' incorporates:
     *  Constant: '<S159>/Constant3'
     */
    TRSC_VC_B.deltariselimit_b = KeTRSC_k_TrqConstRateLim *
      TRSC_VC_B.sampletime_n;

    /* RelationalOperator: '<S167>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.UkYk1_ks >
      TRSC_VC_B.deltariselimit_b);

    /* Gain: '<S159>/Gain4' incorporates:
     *  Constant: '<S159>/Constant3'
     */
    TRSC_VC_B.Product_p = (-1.0F) * KeTRSC_k_TrqConstRateLim;

    /* Product: '<S163>/delta fall limit' */
    TRSC_VC_B.deltafalllimit_n = TRSC_VC_B.Product_p * TRSC_VC_B.sampletime_n;

    /* RelationalOperator: '<S167>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.UkYk1_ks < TRSC_VC_B.deltafalllimit_n);

    /* Switch: '<S167>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_g3 = TRSC_VC_B.deltafalllimit_n;
    } else {
      TRSC_VC_B.Switch_g3 = TRSC_VC_B.UkYk1_ks;
    }

    /* End of Switch: '<S167>/Switch' */

    /* Switch: '<S167>/Switch2' */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch2_b = TRSC_VC_B.deltariselimit_b;
    } else {
      TRSC_VC_B.Switch2_b = TRSC_VC_B.Switch_g3;
    }

    /* End of Switch: '<S167>/Switch2' */

    /* Sum: '<S163>/Difference Inputs2'
     *
     * Block description for '<S163>/Difference Inputs2':
     *
     *  Add in CPU
     */
    TRSC_VC_B.DifferenceInputs2_g = TRSC_VC_B.Switch2_b + TRSC_VC_B.Yk1_m;

    /* RelationalOperator: '<S164>/LowerRelop1' incorporates:
     *  Constant: '<S159>/Constant5'
     */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.DifferenceInputs2_g >
      KeTRSC_k_TrqConstSatLim);

    /* Gain: '<S159>/Gain3' incorporates:
     *  Constant: '<S159>/Constant5'
     */
    TRSC_VC_B.Product_p = (-1.0F) * KeTRSC_k_TrqConstSatLim;

    /* RelationalOperator: '<S164>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.DifferenceInputs2_g <
      TRSC_VC_B.Product_p);

    /* Switch: '<S164>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_h = TRSC_VC_B.Product_p;
    } else {
      TRSC_VC_B.Switch_h = TRSC_VC_B.DifferenceInputs2_g;
    }

    /* End of Switch: '<S164>/Switch' */

    /* Switch: '<S164>/Switch2' incorporates:
     *  Constant: '<S159>/Constant5'
     */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch2_bd = KeTRSC_k_TrqConstSatLim;
    } else {
      TRSC_VC_B.Switch2_bd = TRSC_VC_B.Switch_h;
    }

    /* End of Switch: '<S164>/Switch2' */

    /* UnitDelay: '<S156>/Delay Input2'
     *
     * Block description for '<S156>/Delay Input2':
     *
     *  Store in Global RAM
     */
    TRSC_VC_B.Yk1_i = TRSC_VC_DW.DelayInput2_DSTATE_d;

    /* SampleTimeMath: '<S156>/sample time'
     *
     * About '<S156>/sample time':
     *  y = K where K = ( w * Ts )
     */
    TRSC_VC_B.sampletime_g = 0.03F;

    /* Product: '<S156>/delta rise limit' incorporates:
     *  Constant: '<S122>/Constant6 '
     */
    TRSC_VC_B.deltariselimit_m = KeTRSC_deg_TwitchTrqRateLim *
      TRSC_VC_B.sampletime_g;

    /* Outputs for Enabled SubSystem: '<S122>/THA_SteerTweakProfile_Processing2' incorporates:
     *  EnablePort: '<S158>/Enable'
     */
    if (TRSC_VC_B.Compare_p) {
      if (!TRSC_VC_DW.THA_SteerTweakProfile_Processing2_MODE) {
        /* InitializeConditions for Delay: '<S158>/Delay1' */
        TRSC_VC_DW.Delay1_DSTATE = 0.0F;

        /* InitializeConditions for Delay: '<S158>/Delay' */
        TRSC_VC_DW.Delay_DSTATE_j = 0.0F;

        /* InitializeConditions for Delay: '<S158>/Delay2' */
        TRSC_VC_DW.Delay2_DSTATE_o = false;
        TRSC_VC_DW.THA_SteerTweakProfile_Processing2_MODE = true;
      }

      /* Delay: '<S158>/Delay1' */
      TRSC_VC_B.Delay1_c = TRSC_VC_DW.Delay1_DSTATE;

      /* Product: '<S158>/Divide' incorporates:
       *  Constant: '<S122>/KeTRSC_s_TwitchTime'
       *  Constant: '<S158>/Constant1'
       */
      TRSC_VC_B.Product1_a = KeTRSC_s_TwitchTime / KeTRSC_k_NumTwitchPulse;

      /* Gain: '<S158>/Gain' */
      TRSC_VC_B.Product1_a *= 0.5F;

      /* Delay: '<S158>/Delay' */
      TRSC_VC_B.Switch_jy = TRSC_VC_DW.Delay_DSTATE_j;

      /* Product: '<S158>/Product1' */
      TRSC_VC_B.Product1_a *= TRSC_VC_B.Switch_jy;

      /* RelationalOperator: '<S158>/Relational Operator' */
      TRSC_VC_B.RelationalOperator = (MeTRSC_s_TwitchTmr >= TRSC_VC_B.Product1_a);

      /* Delay: '<S158>/Delay2' */
      TRSC_VC_B.LogicalOperator_e = TRSC_VC_DW.Delay2_DSTATE_o;

      /* Logic: '<S158>/Logical Operator1' */
      TRSC_VC_B.LogicalOperator_e = !TRSC_VC_B.LogicalOperator_e;

      /* Logic: '<S158>/Logical Operator' */
      TRSC_VC_B.LogicalOperator_e = (TRSC_VC_B.RelationalOperator &&
        TRSC_VC_B.LogicalOperator_e);

      /* Sum: '<S158>/Add' */
      TRSC_VC_B.Add_h2 = TRSC_VC_B.Delay1_c + (real32_T)
        TRSC_VC_B.LogicalOperator_e;

      /* Math: '<S158>/Mod' incorporates:
       *  Constant: '<S158>/Constant'
       */
      TRSC_VC_B.Switch_jy = rt_modf_snf(TRSC_VC_B.Add_h2, 2.0F);

      /* Switch: '<S158>/Switch' incorporates:
       *  Constant: '<S122>/Constant6'
       */
      if (TRSC_VC_B.Switch_jy != 0.0F) {
        TRSC_VC_B.Switch_jy = KeTRSC_Nm_MaxTrqLim;
      } else {
        /* Gain: '<S158>/Gain3' incorporates:
         *  Constant: '<S122>/Constant6'
         */
        TRSC_VC_B.Gain3_g = (-1.0F) * KeTRSC_Nm_MaxTrqLim;
        TRSC_VC_B.Switch_jy = TRSC_VC_B.Gain3_g;
      }

      /* End of Switch: '<S158>/Switch' */

      /* Product: '<S158>/Product' */
      TRSC_VC_B.Product_g = TRSC_VC_B.Switch_jy * (real32_T)TRSC_VC_B.Compare_p;

      /* Update for Delay: '<S158>/Delay1' */
      TRSC_VC_DW.Delay1_DSTATE = TRSC_VC_B.Add_h2;

      /* Update for Delay: '<S158>/Delay' */
      TRSC_VC_DW.Delay_DSTATE_j = TRSC_VC_B.Add_h2;

      /* Update for Delay: '<S158>/Delay2' */
      TRSC_VC_DW.Delay2_DSTATE_o = TRSC_VC_B.RelationalOperator;
    } else {
      TRSC_VC_DW.THA_SteerTweakProfile_Processing2_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S122>/THA_SteerTweakProfile_Processing2' */

    /* Sum: '<S156>/Difference Inputs1'
     *
     * Block description for '<S156>/Difference Inputs1':
     *
     *  Add in CPU
     */
    TRSC_VC_B.UkYk1_o = TRSC_VC_B.Product_g - TRSC_VC_B.Yk1_i;

    /* RelationalOperator: '<S161>/LowerRelop1' */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.UkYk1_o >
      TRSC_VC_B.deltariselimit_m);

    /* Gain: '<S122>/Gain8' incorporates:
     *  Constant: '<S122>/Constant6 '
     */
    TRSC_VC_B.Product_p = (-1.0F) * KeTRSC_deg_TwitchTrqRateLim;

    /* Product: '<S156>/delta fall limit' */
    TRSC_VC_B.deltafalllimit_j = TRSC_VC_B.Product_p * TRSC_VC_B.sampletime_g;

    /* RelationalOperator: '<S161>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.UkYk1_o < TRSC_VC_B.deltafalllimit_j);

    /* Switch: '<S161>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_a2 = TRSC_VC_B.deltafalllimit_j;
    } else {
      TRSC_VC_B.Switch_a2 = TRSC_VC_B.UkYk1_o;
    }

    /* End of Switch: '<S161>/Switch' */

    /* Switch: '<S161>/Switch2' */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch2_h = TRSC_VC_B.deltariselimit_m;
    } else {
      TRSC_VC_B.Switch2_h = TRSC_VC_B.Switch_a2;
    }

    /* End of Switch: '<S161>/Switch2' */

    /* Sum: '<S156>/Difference Inputs2'
     *
     * Block description for '<S156>/Difference Inputs2':
     *
     *  Add in CPU
     */
    TRSC_VC_B.DifferenceInputs2_p = TRSC_VC_B.Switch2_h + TRSC_VC_B.Yk1_i;

    /* RelationalOperator: '<S157>/LowerRelop1' incorporates:
     *  Constant: '<S122>/Constant4'
     */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.DifferenceInputs2_p >
      KeTRSC_Nm_MaxTrqLim);

    /* Gain: '<S122>/Gain3' incorporates:
     *  Constant: '<S122>/Constant4'
     */
    TRSC_VC_B.Product_p = (-1.0F) * KeTRSC_Nm_MaxTrqLim;

    /* RelationalOperator: '<S157>/UpperRelop' */
    TRSC_VC_B.UpperRelop_m = (TRSC_VC_B.DifferenceInputs2_p <
      TRSC_VC_B.Product_p);

    /* Switch: '<S157>/Switch' */
    if (TRSC_VC_B.UpperRelop_m) {
      TRSC_VC_B.Switch_aq = TRSC_VC_B.Product_p;
    } else {
      TRSC_VC_B.Switch_aq = TRSC_VC_B.DifferenceInputs2_p;
    }

    /* End of Switch: '<S157>/Switch' */

    /* Switch: '<S157>/Switch2' incorporates:
     *  Constant: '<S122>/Constant4'
     */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch2_fb = KeTRSC_Nm_MaxTrqLim;
    } else {
      TRSC_VC_B.Switch2_fb = TRSC_VC_B.Switch_aq;
    }

    /* End of Switch: '<S157>/Switch2' */

    /* Switch: '<S122>/Switch4' */
    if (MeTRSC_b_TwitchCompleted) {
      /* DataTypeConversion: '<S122>/Data Type Conversion2' */
      TRSC_VC_B.TrqCMD_i = TRSC_VC_B.Switch2_bd;
      TRSC_VC_B.TrqCMD = TRSC_VC_B.TrqCMD_i;
    } else {
      TRSC_VC_B.TrqCMD = TRSC_VC_B.Switch2_fb;
    }

    /* End of Switch: '<S122>/Switch4' */

    /* Switch: '<S159>/Switch3' */
    if (TRSC_VC_B.LogicalOperator2_d) {
      /* Lookup_n-D: '<S159>/integrator_gain_table_type2or3' */
      TRSC_VC_B.integrator_gain_table_type2or3 = look2_iflf_binlxpw
        (TRSC_VC_B.Abs1, MeTRSC_e_IdentifiedCase, ((real32_T *)
          &(KaTRSC_kph_IntGainBPTyp2or3[0])),
         rtCP_integrator_gain_table_type2or3_bp02Data, ((real32_T *)
          &(KaTRSC_k_IntGainTDTyp2or3[0])),
         rtCP_integrator_gain_table_type2or3_maxIndex, 4U);
      TRSC_VC_B.Product_p = TRSC_VC_B.integrator_gain_table_type2or3;
    } else {
      /* Lookup_n-D: '<S159>/integrator_gain_table_type1' */
      TRSC_VC_B.integrator_gain_table_type1 = look2_iflf_binlxpw(TRSC_VC_B.Abs1,
        MeTRSC_e_IdentifiedCase, ((real32_T *)&(KaTRSC_kph_IntGainBPTyp1[0])),
        rtCP_integrator_gain_table_type1_bp02Data, ((real32_T *)
        &(KaTRSC_k_IntGainTDTyp1[0])), rtCP_integrator_gain_table_type1_maxIndex,
        4U);
      TRSC_VC_B.Product_p = TRSC_VC_B.integrator_gain_table_type1;
    }

    /* End of Switch: '<S159>/Switch3' */

    /* DataTypeConversion: '<S159>/Data Type Conversion3' */
    TRSC_VC_B.Product5_m = TRSC_VC_B.err;

    /* Lookup_n-D: '<S159>/integrator_multiplier_table_type1' */
    TRSC_VC_B.integrator_multiplier_table_type1 = look1_iflf_binlxpw
      (MeTRSC_e_IdentifiedCase, rtCP_integrator_multiplier_table_type1_bp01Data,
       ((real32_T *)&(KeTRSC_k_TrqCtrlIMultiplier[0])), 3U);

    /* Product: '<S159>/Product5' */
    TRSC_VC_B.Product5_m *= TRSC_VC_B.integrator_multiplier_table_type1;

    /* Product: '<S159>/Product2' */
    TRSC_VC_B.Product2_l = TRSC_VC_B.Product_p * TRSC_VC_B.Product5_m;

    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S141>/Constant'
     */
    if (TRSC_VC_B.RelationalOperator1_g) {
      TRSC_VC_B.Switch = 0.0;
    } else {
      TRSC_VC_B.Switch = MeCtrl_deg_TAD_error;
    }

    /* End of Switch: '<S141>/Switch' */

    /* S-Function (sfix_look1_dyn): '<S118>/Lookup Table Dynamic2' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    /* Dynamic Look-Up Table Block: '<S118>/Lookup Table Dynamic2'
     * Input0  Data Type:  Floating Point real32_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real32_T_real32_T( &(TRSC_VC_B.LookupTableDynamic2),
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_k_VehSpd_IGainLUTTblData[0],
      TRSC_VC_B.Abs_d,
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_v_VehSpd_IGainLUTBrkPts[0], 1U);

    /* Product: '<S141>/Product1' */
    TRSC_VC_B.Product1 = TRSC_VC_B.Switch * TRSC_VC_B.LookupTableDynamic2;

    /* Abs: '<S116>/Abs1' */
    TRSC_VC_B.Abs1_b = fabsf(MeCtrl_deg_TAD_error);

    /* RelationalOperator: '<S116>/Relational Operator3' incorporates:
     *  Constant: '<S116>/Constant12'
     */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.Abs1_b <=
      KeTRSC_deg_TADErrSpdLmtLowThr);

    /* Product: '<S116>/Product1' incorporates:
     *  Constant: '<S116>/Constant'
     */
    TRSC_VC_B.Product_p = TRSC_VC_B.Switch2_c * KeTRSC_pct_4kphSpdThr;

    /* RelationalOperator: '<S116>/Relational Operator1' */
    TRSC_VC_B.RelationalOperator1_g = (TRSC_VC_B.Abs_c >= TRSC_VC_B.Product_p);

    /* Switch: '<S116>/Switch' incorporates:
     *  Constant: '<S116>/Constant2'
     */
    if (TRSC_VC_B.RelationalOperator1_g) {
      TRSC_VC_B.MeTRSC_e_SpdLmtReq = TeTRSC_e_SpdLmtReq_Spd4;
    } else {
      /* Product: '<S116>/Product2' incorporates:
       *  Constant: '<S116>/Constant9'
       */
      TRSC_VC_B.Product2_d = TRSC_VC_B.Switch2_c * KeTRSC_pct_5kphSpdThr;

      /* RelationalOperator: '<S116>/Relational Operator2' */
      TRSC_VC_B.RelationalOperator2_b = (TRSC_VC_B.Abs_c >= TRSC_VC_B.Product2_d);

      /* Switch: '<S116>/Switch1' incorporates:
       *  Constant: '<S116>/Constant1'
       */
      if (TRSC_VC_B.RelationalOperator2_b) {
        TRSC_VC_B.Switch1_m = TeTRSC_e_SpdLmtReq_Spd5;
      } else {
        /* Product: '<S116>/Product5' incorporates:
         *  Constant: '<S116>/Constant11'
         */
        TRSC_VC_B.Product5 = TRSC_VC_B.Switch2_c * KeTRSC_pct_6kphSpdThr;

        /* RelationalOperator: '<S116>/Relational Operator5' */
        TRSC_VC_B.RelationalOperator5 = (TRSC_VC_B.Abs_c >= TRSC_VC_B.Product5);

        /* Switch: '<S116>/Switch2' incorporates:
         *  Constant: '<S116>/Constant3'
         */
        if (TRSC_VC_B.RelationalOperator5) {
          TRSC_VC_B.Switch2_kv = TeTRSC_e_SpdLmtReq_Spd6;
        } else {
          /* Product: '<S116>/Product7' incorporates:
           *  Constant: '<S116>/Constant13'
           */
          TRSC_VC_B.Product7_m = TRSC_VC_B.Switch2_c * KeTRSC_pct_7kphSpdThr;

          /* RelationalOperator: '<S116>/Relational Operator7' */
          TRSC_VC_B.RelationalOperator7 = (TRSC_VC_B.Abs_c >=
            TRSC_VC_B.Product7_m);

          /* Switch: '<S116>/Switch3' incorporates:
           *  Constant: '<S116>/Constant4'
           */
          if (TRSC_VC_B.RelationalOperator7) {
            TRSC_VC_B.Switch3_l = TeTRSC_e_SpdLmtReq_Spd7;
          } else {
            /* Product: '<S116>/Product9' incorporates:
             *  Constant: '<S116>/Constant15'
             */
            TRSC_VC_B.Product9 = TRSC_VC_B.Switch2_c * KeTRSC_pct_8kphSpdThr;

            /* RelationalOperator: '<S116>/Relational Operator9' */
            TRSC_VC_B.RelationalOperator9 = (TRSC_VC_B.Abs_c >=
              TRSC_VC_B.Product9);

            /* Switch: '<S116>/Switch4' incorporates:
             *  Constant: '<S116>/Constant6'
             */
            if (TRSC_VC_B.RelationalOperator9) {
              TRSC_VC_B.Switch4_g = TeTRSC_e_SpdLmtReq_Spd8;
            } else {
              /* Product: '<S116>/Product11' incorporates:
               *  Constant: '<S116>/Constant17'
               */
              TRSC_VC_B.Product11 = TRSC_VC_B.Switch2_c * KeTRSC_pct_9kphSpdThr;

              /* RelationalOperator: '<S116>/Relational Operator11' */
              TRSC_VC_B.RelationalOperator11 = (TRSC_VC_B.Abs_c >=
                TRSC_VC_B.Product11);

              /* Switch: '<S116>/Switch5' incorporates:
               *  Constant: '<S116>/Constant5'
               *  Constant: '<S116>/Constant7'
               */
              if (TRSC_VC_B.RelationalOperator11) {
                TRSC_VC_B.Switch5_n = TeTRSC_e_SpdLmtReq_Spd9;
              } else {
                TRSC_VC_B.Switch5_n = TeTRSC_e_SpdLmtReq_Spd10;
              }

              /* End of Switch: '<S116>/Switch5' */
              TRSC_VC_B.Switch4_g = TRSC_VC_B.Switch5_n;
            }

            /* End of Switch: '<S116>/Switch4' */
            TRSC_VC_B.Switch3_l = TRSC_VC_B.Switch4_g;
          }

          /* End of Switch: '<S116>/Switch3' */
          TRSC_VC_B.Switch2_kv = TRSC_VC_B.Switch3_l;
        }

        /* End of Switch: '<S116>/Switch2' */
        TRSC_VC_B.Switch1_m = TRSC_VC_B.Switch2_kv;
      }

      /* End of Switch: '<S116>/Switch1' */
      TRSC_VC_B.MeTRSC_e_SpdLmtReq = TRSC_VC_B.Switch1_m;
    }

    /* End of Switch: '<S116>/Switch' */

    /* Switch: '<S116>/Switch7' */
    if (TRSC_VC_B.RelationalOperator_f) {
      TRSC_VC_B.Switch7 = TRSC_VC_B.MeTRSC_e_SpdLmtReq;
    } else {
      /* RelationalOperator: '<S116>/Relational Operator4' incorporates:
       *  Constant: '<S116>/Constant16'
       */
      TRSC_VC_B.RelationalOperator4 = (TRSC_VC_B.Abs1_b <=
        KeTRSC_deg_TADErrSpdLmtMidThr);

      /* Switch: '<S116>/Switch8' incorporates:
       *  Constant: '<S116>/Constant21'
       */
      if (TRSC_VC_B.RelationalOperator4) {
        /* DataTypeConversion: '<S116>/Data Type Conversion4' */
        TRSC_VC_B.Add3_n = (uint8_T)TRSC_VC_B.MeTRSC_e_SpdLmtReq;

        /* Sum: '<S116>/Add2' incorporates:
         *  Constant: '<S116>/Constant19'
         */
        TRSC_VC_B.Add3_n = (uint8_T)((uint32_T)TRSC_VC_B.Add3_n +
          CeConst_k_ConstThreeUint8);

        /* Sum: '<S116>/Subtract1' incorporates:
         *  Constant: '<S116>/Constant20'
         */
        TRSC_VC_B.Add3_n -= CeConst_k_ConstTwoUint8;

        /* Saturate: '<S116>/Saturation1' */
        if (TRSC_VC_B.Add3_n > ((uint8_T)10U)) {
          TRSC_VC_B.Add3_n = ((uint8_T)10U);
        } else {
          if (TRSC_VC_B.Add3_n < ((uint8_T)4U)) {
            TRSC_VC_B.Add3_n = ((uint8_T)4U);
          }
        }

        /* End of Saturate: '<S116>/Saturation1' */

        /* Sum: '<S116>/Add3' incorporates:
         *  Constant: '<S116>/Constant18'
         */
        TRSC_VC_B.Add3_n -= CeConst_k_ConstThreeUint8;

        /* DataTypeConversion: '<S116>/Data Type Conversion7' */
        TRSC_VC_B.DataTypeConversion7_p = (TeTRSC_e_SpdLmtReq)TRSC_VC_B.Add3_n;
        TRSC_VC_B.Switch8 = TRSC_VC_B.DataTypeConversion7_p;
      } else {
        TRSC_VC_B.Switch8 = TeTRSC_e_SpdLmtReq_Spd4;
      }

      /* End of Switch: '<S116>/Switch8' */
      TRSC_VC_B.Switch7 = TRSC_VC_B.Switch8;
    }

    /* End of Switch: '<S116>/Switch7' */

    /* RelationalOperator: '<S116>/Relational Operator' incorporates:
     *  Constant: '<S116>/Constant8'
     */
    TRSC_VC_B.RelationalOperator_f = (TRSC_VC_B.Switch6 >
      KeTRSC_m_SprLimitTBLThr);

    /* Switch: '<S116>/Switch6' */
    if (TRSC_VC_B.RelationalOperator_f) {
      *rty_MeTRSC_e_SpdLmtReq = TRSC_VC_B.Switch7;
    } else {
      /* RelationalOperator: '<S116>/Relational Operator6' incorporates:
       *  Constant: '<S116>/Constant22'
       */
      TRSC_VC_B.RelationalOperator6 = (TRSC_VC_B.Switch6 >=
        KeTRSC_m_SprLimitTBLThr1);

      /* Switch: '<S116>/Switch9' */
      if (TRSC_VC_B.RelationalOperator6) {
        /* DataTypeConversion: '<S116>/Data Type Conversion' */
        TRSC_VC_B.Add1_g = (uint8_T)TRSC_VC_B.Switch7;

        /* Sum: '<S116>/Add' incorporates:
         *  Constant: '<S116>/Constant14'
         */
        TRSC_VC_B.Add1_g = (uint8_T)((uint32_T)TRSC_VC_B.Add1_g +
          CeConst_k_ConstThreeUint8);

        /* DataTypeConversion: '<S116>/Data Type Conversion1' */
        TRSC_VC_B.Saturation_b = TRSC_VC_B.Add1_g;

        /* Gain: '<S116>/Gain' */
        TRSC_VC_B.Gain_n = 0.25F * TRSC_VC_B.Saturation_b;

        /* Sum: '<S116>/Subtract' */
        TRSC_VC_B.Saturation_b -= TRSC_VC_B.Gain_n;

        /* Saturate: '<S116>/Saturation' */
        if (TRSC_VC_B.Saturation_b > 10.0F) {
          TRSC_VC_B.Saturation_b = 10.0F;
        } else {
          if (TRSC_VC_B.Saturation_b < 4.0F) {
            TRSC_VC_B.Saturation_b = 4.0F;
          }
        }

        /* End of Saturate: '<S116>/Saturation' */

        /* DataTypeConversion: '<S116>/Data Type Conversion2' */
        TRSC_VC_B.gamma_now_deg_m = floorf(TRSC_VC_B.Saturation_b);
        if (rtIsNaNF(TRSC_VC_B.gamma_now_deg_m) || rtIsInfF
            (TRSC_VC_B.gamma_now_deg_m)) {
          TRSC_VC_B.gamma_now_deg_m = 0.0F;
        } else {
          TRSC_VC_B.gamma_now_deg_m = fmodf(TRSC_VC_B.gamma_now_deg_m, 256.0F);
        }

        TRSC_VC_B.Add1_g = (uint8_T)(TRSC_VC_B.gamma_now_deg_m < 0.0F ? (int32_T)
          (uint8_T)-(int8_T)(uint8_T)-TRSC_VC_B.gamma_now_deg_m : (int32_T)
          (uint8_T)TRSC_VC_B.gamma_now_deg_m);

        /* End of DataTypeConversion: '<S116>/Data Type Conversion2' */

        /* Sum: '<S116>/Add1' incorporates:
         *  Constant: '<S116>/Constant10'
         */
        TRSC_VC_B.Add1_g -= CeConst_k_ConstThreeUint8;

        /* DataTypeConversion: '<S116>/Data Type Conversion3' */
        TRSC_VC_B.DataTypeConversion3 = (TeTRSC_e_SpdLmtReq)TRSC_VC_B.Add1_g;
        TRSC_VC_B.Switch9 = TRSC_VC_B.DataTypeConversion3;
      } else {
        /* DataTypeConversion: '<S116>/Data Type Conversion5' */
        TRSC_VC_B.Add5 = (uint8_T)TRSC_VC_B.Switch7;

        /* Sum: '<S116>/Add4' incorporates:
         *  Constant: '<S116>/Constant24'
         */
        TRSC_VC_B.Add5 = (uint8_T)((uint32_T)TRSC_VC_B.Add5 +
          CeConst_k_ConstThreeUint8);

        /* DataTypeConversion: '<S116>/Data Type Conversion6' */
        TRSC_VC_B.Saturation2 = TRSC_VC_B.Add5;

        /* Gain: '<S116>/Gain1' */
        TRSC_VC_B.Gain1_hh = 0.5F * TRSC_VC_B.Saturation2;

        /* Sum: '<S116>/Subtract2' */
        TRSC_VC_B.Saturation2 -= TRSC_VC_B.Gain1_hh;

        /* Saturate: '<S116>/Saturation2' */
        if (TRSC_VC_B.Saturation2 > 10.0F) {
          TRSC_VC_B.Saturation2 = 10.0F;
        } else {
          if (TRSC_VC_B.Saturation2 < 4.0F) {
            TRSC_VC_B.Saturation2 = 4.0F;
          }
        }

        /* End of Saturate: '<S116>/Saturation2' */

        /* DataTypeConversion: '<S116>/Data Type Conversion8' */
        TRSC_VC_B.gamma_now_deg_m = floorf(TRSC_VC_B.Saturation2);
        if (rtIsNaNF(TRSC_VC_B.gamma_now_deg_m) || rtIsInfF
            (TRSC_VC_B.gamma_now_deg_m)) {
          TRSC_VC_B.gamma_now_deg_m = 0.0F;
        } else {
          TRSC_VC_B.gamma_now_deg_m = fmodf(TRSC_VC_B.gamma_now_deg_m, 256.0F);
        }

        TRSC_VC_B.Add5 = (uint8_T)(TRSC_VC_B.gamma_now_deg_m < 0.0F ? (int32_T)
          (uint8_T)-(int8_T)(uint8_T)-TRSC_VC_B.gamma_now_deg_m : (int32_T)
          (uint8_T)TRSC_VC_B.gamma_now_deg_m);

        /* End of DataTypeConversion: '<S116>/Data Type Conversion8' */

        /* Sum: '<S116>/Add5' incorporates:
         *  Constant: '<S116>/Constant23'
         */
        TRSC_VC_B.Add5 -= CeConst_k_ConstThreeUint8;

        /* DataTypeConversion: '<S116>/Data Type Conversion9' */
        TRSC_VC_B.DataTypeConversion9 = (TeTRSC_e_SpdLmtReq)TRSC_VC_B.Add5;
        TRSC_VC_B.Switch9 = TRSC_VC_B.DataTypeConversion9;
      }

      /* End of Switch: '<S116>/Switch9' */
      *rty_MeTRSC_e_SpdLmtReq = TRSC_VC_B.Switch9;
    }

    /* End of Switch: '<S116>/Switch6' */

    /* Abs: '<S145>/Abs' */
    TRSC_VC_B.Product_p = fabsf(TRSC_VC_B.Gain_g);

    /* S-Function (sfix_look1_dyn): '<S145>/Lookup Table Dynamic1' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    /* Dynamic Look-Up Table Block: '<S145>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real32_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real32_T_real32_T( &(TRSC_VC_B.LookupTableDynamic1_b),
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_k_TAD_IGainLUTTblData[0],
      TRSC_VC_B.Product_p,
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_deg_TAD_IGainLUTBrkPts[0], 1U);

    /* Abs: '<S145>/Abs1' */
    TRSC_VC_B.Product_p = fabsf(TRSC_VC_B.Gain);

    /* S-Function (sfix_look1_dyn): '<S145>/Lookup Table Dynamic2' incorporates:
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    /* Dynamic Look-Up Table Block: '<S145>/Lookup Table Dynamic2'
     * Input0  Data Type:  Floating Point real32_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real32_T_real32_T( &(TRSC_VC_B.LookupTableDynamic2_b),
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_k_VehSpdLUTTblData[0],
      TRSC_VC_B.Product_p,
      &IbTRSC_InpBus.IbTRSCSmVc_TunParam.KaTRA_v_VehSpdLUTBrkPts[0], 1U);

    /* Product: '<S145>/Product' */
    TRSC_VC_B.Product_p = TRSC_VC_B.LookupTableDynamic1_b *
      TRSC_VC_B.LookupTableDynamic2_b;

    /* Product: '<S146>/Product1' */
    TRSC_VC_B.Product1_i = TRSC_VC_B.Switch2_n * TRSC_VC_B.Product_p;

    /* Update for UnitDelay: '<S136>/Delay Input2'
     *
     * Block description for '<S136>/Delay Input2':
     *
     *  Store in Global RAM
     */
    TRSC_VC_DW.DelayInput2_DSTATE = TRSC_VC_B.DifferenceInputs2;

    /* Update for Resettable SubSystem: '<S146>/Integrator_Subsytem2' */
    TRSC_VC_Integrator_Subsytem1_Update(TRSC_VC_B.Product1_i, &TRSC_VC_B.Add_mf,
      &TRSC_VC_DW.Integrator_Subsytem2);

    /* End of Update for SubSystem: '<S146>/Integrator_Subsytem2' */

    /* Update for Resettable SubSystem: '<S146>/Integrator_Subsytem1' */
    TRSC_VC_Integrator_Subsytem1_Update(TRSC_VC_B.Product3, &TRSC_VC_B.Add_kg,
      &TRSC_VC_DW.Integrator_Subsytem1_g);

    /* End of Update for SubSystem: '<S146>/Integrator_Subsytem1' */

    /* Update for Delay: '<S135>/Resettable Delay' */
    TRSC_VC_DW.icLoad = 0U;
    TRSC_VC_DW.ResettableDelay_DSTATE = TRSC_VC_B.Yk;

    /* Update for Delay: '<S134>/Resettable Delay' */
    TRSC_VC_DW.icLoad_k = 0U;
    TRSC_VC_DW.ResettableDelay_DSTATE_e = TRSC_VC_B.Yk_p;

    /* Update for Delay: '<S118>/Delay' */
    TRSC_VC_DW.Delay_DSTATE_o[0] = TRSC_VC_DW.Delay_DSTATE_o[1];
    TRSC_VC_DW.Delay_DSTATE_o[1] = TRSC_VC_DW.Delay_DSTATE_o[2];
    TRSC_VC_DW.Delay_DSTATE_o[2] = TRSC_VC_DW.Delay_DSTATE_o[3];
    TRSC_VC_DW.Delay_DSTATE_o[3] = TRSC_VC_B.RelationalOperator3;

    /* Update for Resettable SubSystem: '<S141>/Integrator_Subsytem' incorporates:
     *  ResetPort: '<S142>/Reset'
     */
    /* Update for UnitDelay: '<S142>/Unit Delay' */
    TRSC_VC_DW.UnitDelay_DSTATE_p = TRSC_VC_B.Add_pu;

    /* Update for UnitDelay: '<S142>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_DSTATE = TRSC_VC_B.Product1;

    /* End of Update for SubSystem: '<S141>/Integrator_Subsytem' */

    /* Update for Resettable SubSystem: '<S141>/Integrator_Subsytem1' */
    TRSC_VC_Integrator_Subsytem1_Update(TRSC_VC_B.Product3_g, &TRSC_VC_B.Add_me,
      &TRSC_VC_DW.Integrator_Subsytem1);

    /* End of Update for SubSystem: '<S141>/Integrator_Subsytem1' */

    /* Update for Delay: '<S109>/Delay' */
    TRSC_VC_DW.Delay_DSTATE_kg = MeTRSC_b_TwitchCompleted;

    /* Update for Delay: '<S126>/Resettable Delay' */
    TRSC_VC_DW.icLoad_d = 0U;
    TRSC_VC_DW.ResettableDelay_DSTATE_i = TRSC_VC_B.Yk_j;

    /* Update for Delay: '<S160>/Delay' */
    TRSC_VC_DW.icLoad_j = 0U;
    TRSC_VC_DW.Delay_DSTATE = StrCmd;

    /* Update for UnitDelay: '<S159>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_DSTATE_n = StrCmd;

    /* Update for Delay: '<S166>/Delay' */
    TRSC_VC_DW.icLoad_p = 0U;
    TRSC_VC_DW.Delay_DSTATE_f = TRSC_VC_B.Sum_m;

    /* Update for UnitDelay: '<S159>/Unit Delay2' */
    TRSC_VC_DW.UnitDelay2_DSTATE = TRSC_VC_B.Sum_m;

    /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */
    TRSC_VC_DW.DiscreteTimeIntegrator1_DSTATE += 0.03F *
      TRSC_VC_B.DataTypeConversion;
    if (TRSC_VC_B.DataTypeConversion > 0.0F) {
      TRSC_VC_DW.DiscreteTimeIntegrator1_PrevResetState = 1;
    } else if (TRSC_VC_B.DataTypeConversion < 0.0F) {
      TRSC_VC_DW.DiscreteTimeIntegrator1_PrevResetState = -1;
    } else if (TRSC_VC_B.DataTypeConversion == 0.0F) {
      TRSC_VC_DW.DiscreteTimeIntegrator1_PrevResetState = 0;
    } else {
      TRSC_VC_DW.DiscreteTimeIntegrator1_PrevResetState = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */

    /* Update for UnitDelay: '<S122>/Unit Delay1' */
    TRSC_VC_DW.UnitDelay1_DSTATE_ed = MeTRSC_b_TwitchCompleted;

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
    TRSC_VC_DW.DiscreteTimeIntegrator_IC_LOADING = 0U;
    TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l += 0.03F * TRSC_VC_B.Product2_l;
    if (TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l >= KeTRSC_k_IntExtSat) {
      TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l = KeTRSC_k_IntExtSat;
    } else {
      if (TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l <= -KeTRSC_k_IntExtSat) {
        TRSC_VC_DW.DiscreteTimeIntegrator_DSTATE_l = -KeTRSC_k_IntExtSat;
      }
    }

    TRSC_VC_DW.DiscreteTimeIntegrator_PrevResetState = (int8_T)
      TRSC_VC_B.LogicalOperator1_f;

    /* End of Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */

    /* Update for UnitDelay: '<S163>/Delay Input2'
     *
     * Block description for '<S163>/Delay Input2':
     *
     *  Store in Global RAM
     */
    TRSC_VC_DW.DelayInput2_DSTATE_p = TRSC_VC_B.DifferenceInputs2_g;

    /* Update for UnitDelay: '<S156>/Delay Input2'
     *
     * Block description for '<S156>/Delay Input2':
     *
     *  Store in Global RAM
     */
    TRSC_VC_DW.DelayInput2_DSTATE_d = TRSC_VC_B.DifferenceInputs2_p;
  } else {
    if (TRSC_VC_DW.Controller_Main2_MODE) {
      /* Disable for Enabled SubSystem: '<S122>/THA_SteerTweakProfile_Processing2' */
      TRSC_VC_DW.THA_SteerTweakProfile_Processing2_MODE = false;

      /* End of Disable for SubSystem: '<S122>/THA_SteerTweakProfile_Processing2' */

      /* Disable for Outport: '<S109>/MeTRSC_M_StrTrqCmd' */
      TRSC_VC_B.TrqCMD = 0.0F;

      /* Disable for Outport: '<S109>/MeTRSC_e_SpdLmtReq' */
      *rty_MeTRSC_e_SpdLmtReq = TeTRSC_e_SpdLmtReq_NotLim;

      /* Disable for Outport: '<S109>/MeTRSC_deg_TrlrAngKnob' */
      MeTRSC_deg_TrlrAngKnob = 0.0F;

      /* Disable for Outport: '<S109>/MeCtrl_deg_frntwhlCommand' */
      TRSC_VC_B.tanVals = 0.0F;
      TRSC_VC_DW.Controller_Main2_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S108>/Controller_Main2' */

  /* SignalConversion generated from: '<S108>/MeCtrl_deg_frntwhlCommand' */
  TRSC_VC_B.OutportBufferForMeCtrl_deg_frntwhlCommand = TRSC_VC_B.tanVals;

  /* Update for Delay: '<S108>/Delay' */
  TRSC_VC_DW.Delay_DSTATE_d[0] = TRSC_VC_DW.Delay_DSTATE_d[1];
  TRSC_VC_DW.Delay_DSTATE_d[1] = MeTRSC_b_TRAAct;

  /* End of Outputs for S-Function (fcncallgen): '<S17>/Function-Call Generator' */

  /* SignalConversion generated from: '<S17>/VehicleControl' */
  MeTRSC_M_TRSCStrTrq = TRSC_VC_B.TrqCMD;

  /* SignalConversion generated from: '<S17>/VehicleControl' */
  MeTRSC_b_StrTwitchComplete = MeTRSC_b_TwitchCompleted;

  /* SignalConversion generated from: '<S17>/VehicleControl' */
  MeTRSC_deg_StrCMD = TRSC_VC_B.Switch2_e;

  /* End of Outputs for SubSystem: '<S1>/Torque Control' */

  /* Abs: '<S45>/Abs' incorporates:
   *  Gain: '<S6>/Gain18'
   *  Inport: '<Root>/IbTRSC_InpBus'
   *  Product: '<S6>/Product'
   */
  TRSC_VC_B.Product_DesiredTAD = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFWt;
  TRSC_VC_B.Product_DesiredTAD *=
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng;

  /* Gain: '<S6>/Gain1' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Gain_k = (-1.0F) *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFBias;

  /* Sum: '<S6>/Add' */
  TRSC_VC_B.Add_p = TRSC_VC_B.Product_DesiredTAD + TRSC_VC_B.Gain_k;

  /* Gain: '<S1>/Gain18' */
  TRSC_VC_B.gamma_now_deg = (-1.0F) * TRSC_VC_B.Gain5;

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_kph_VehSpeedVSOSig < 1.0F) {
    TRSC_VC_B.speed_out = 1.0F;
  } else {
    TRSC_VC_B.speed_out =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_kph_VehSpeedVSOSig;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function2' */

  /* Abs: '<S45>/Abs' incorporates:
   *  Abs: '<S1>/Abs'
   *  Gain: '<S1>/Gain17'
   */
  TRSC_VC_B.Product_DesiredTAD = 0.277777791F * TRSC_VC_B.speed_out;
  TRSC_VC_B.Product_DesiredTAD = fabsf(TRSC_VC_B.Product_DesiredTAD);

  /* Gain: '<S1>/Gain19' */
  TRSC_VC_B.Gain19 = (-1.0F) * TRSC_VC_B.Product_DesiredTAD;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Constant: '<S1>/Dt'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.gamma_now_deg_m = TRSC_VC_B.gamma_now_deg;
  TRSC_VC_B.k = 0;
  while (TRSC_VC_B.k <= (int32_T)TRSC_VC_ConstB.Gain16 - 1) {
    Add2_m_tmp = (int32_T)
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply;
    if ((Add2_m_tmp == 14) || (Add2_m_tmp == 12)) {
      TRSC_VC_B.Dt = TRSC_VC_B.gamma_now_deg * 3.14159274F / 180.0F;
      TRSC_VC_B.pulse_counter_RR = tanf(TRSC_VC_B.Add_p * 3.14159274F / 180.0F);
      TRSC_VC_B.gamma_now_deg += (TRSC_VC_B.Gain19 / TRSC_VC_B.Switch2 *
        TRSC_VC_B.pulse_counter_RR - (sinf(TRSC_VC_B.Dt) -
        TRSC_VC_B.pulse_counter_RR / TRSC_VC_B.Switch2 * TRSC_VC_B.Gain2 * cosf
        (TRSC_VC_B.Dt)) * (TRSC_VC_B.Gain19 / TRSC_VC_B.Switch6)) * 57.2957802F *
        0.3F;
    }

    TRSC_VC_B.k++;
  }

  TRSC_VC_B.gamma_dot_deg = (TRSC_VC_B.gamma_now_deg - TRSC_VC_B.gamma_now_deg_m)
    / 1.4F;

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */

  /* Switch: '<S1>/Switch5' */
  if (MeTRSC_b_TRAAct) {
    TRSC_VC_B.Switch5 = MeTRSC_deg_TrlrAngKnob;
  } else {
    TRSC_VC_B.Switch5 = TRSC_VC_B.gamma_now_deg;
  }

  /* End of Switch: '<S1>/Switch5' */

  /* DataTypeConversion: '<S1>/Data Type Conversion6' */
  TRSC_VC_B.DataTypeConversion6 = MeTRSC_b_TRAAct;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' */
  *rty_MeTRSC_e_TRSCStrTrqActvReq = (TeTRSC_e_TRSCStrTrqActvReq)
    TRSC_VC_B.DataTypeConversion6;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  TRSC_VC_B.DataTypeConversion_n = MeTRSC_b_TRAAct;

  /* Switch: '<S195>/Switch3' incorporates:
   *  Constant: '<S195>/Constant2'
   *  Constant: '<S19>/Constant2'
   */
  if (TRSC_VC_B.Compare_m) {
    TRSC_VC_B.Switch3 = 0.03;
  } else {
    TRSC_VC_B.Switch3 = 0.0;
  }

  /* End of Switch: '<S195>/Switch3' */

  /* Sum: '<S195>/Sum' */
  TRSC_VC_B.Sum_h += TRSC_VC_B.Switch3;

  /* MinMax: '<S195>/MinMax' incorporates:
   *  Constant: '<S19>/Constant3'
   */
  TRSC_VC_B.MinMax = fmin(TRSC_VC_B.Sum_h, 0.35);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  MeTRSC_deg_JackKnifeAngle = TRSC_VC_B.Switch2_c;

  /* Abs: '<S45>/Abs' incorporates:
   *  Gain: '<S1>/Gain6'
   *  Inport: '<Root>/IbTRSC_InpBus'
   *  Product: '<S1>/Product_DesiredTAD'
   */
  TRSC_VC_B.Product_DesiredTAD = 0.01F *
    IbTRSC_InpBus.IbTRSCSmVc_TunParam.KeTRSC_pct_JackKnifePerc;
  TRSC_VC_B.Product_DesiredTAD *= TRSC_VC_B.Switch2_c;

  /* DataTypeConversion: '<S1>/Data Type Conversion10' */
  MeTRSC_deg_MaxAllowedTADAngle = TRSC_VC_B.Product_DesiredTAD;

  /* DataTypeConversion: '<S1>/Data Type Conversion9' */
  MeTRSC_deg_JackknifeThrAngle = TRSC_VC_B.Product_DesiredTAD;

  /* SignalConversion generated from: '<S1>/Trailer Beam Length1' */
  MeTRSC_b_OTBLReset = TRSC_VC_B.DataStoreRead;

  /* RelationalOperator: '<S188>/Compare' incorporates:
   *  Constant: '<S188>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.Compare_j = (IbTRSC_InpBus.IbTRSC_SVStoTRSC.MeSVS_e_DispView2Info ==
    TeTRSC_e_DispView2_View13);

  /* Constant: '<S9>/Constant2' */
  TRSC_VC_B.Constant2 = KeTRSC_deg_Zero;

  /* Logic: '<S19>/Logical Operator3' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.LogicalOperator3 =
    !IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_b_StrTchSts;

  /* DataTypeConversion: '<S1>/Data Type Conversion13' incorporates:
   *  Constant: '<S1>/Constant4'
   */
  MeTRSC_pct_TRSCStrDmp = (real32_T)0.0;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_B.DataTypeConversion5 =
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_DetJackknifeThrAngle;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  TRSC_VC_DW.UnitDelay2_DSTATE_o = MeTRSC_b_TBLComputationDone;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  TRSC_VC_DW.UnitDelay1_DSTATE_g = TRSC_VC_B.DataTypeConversion_j;

  /* Update for UnitDelay: '<S9>/Unit Delay2' */
  TRSC_VC_DW.UnitDelay2_DSTATE_a = TRSC_VC_B.Compare_b;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_n = MeTRSC_b_TRAAct;

  /* End of Outputs for SubSystem: '<Root>/TRSC_VC2' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  IeTRSC_m_TrlrWhlBaseEff = TRSC_VC_B.Switch6;

  /* Gain: '<Root>/Gain' */
  TRSC_VC_B.Gain_k = (-1.0F) * TRSC_VC_B.Switch5;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  IeTRSC_deg_TrlrAngKnob = TRSC_VC_B.Gain_k;

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  MeTRSC_deg_KnobAngle = TRSC_VC_B.Gain_k;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  IeTRSC_deg_JackknifeThrAngle = MeTRSC_deg_JackknifeThrAngle;

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  MeTRSC_m_TrailerBeamLen = TRSC_VC_B.Switch6;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  TRSC_VC_DW.UnitDelay_DSTATE_f =
    TRSC_VC_B.OutportBufferForMeCtrl_deg_frntwhlCommand;
}

/* Model initialize function */
void TRSC_VC_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_TRSC_VC_T *const TRSC_VC_M = &(TRSC_VC_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(TRSC_VC_M, rt_errorStatus);
  TRSC_VC_PrevZCX.ResettableSubsystem_Reset_ZCE = UNINITIALIZED_ZCSIG;
  TRSC_VC_PrevZCX.Kinematic_model_Reset_ZCE = POS_ZCSIG;
  TRSC_VC_PrevZCX.Heading_Deviation1_Reset_ZCE = POS_ZCSIG;
  TRSC_VC_PrevZCX.Path_Deviation_Reset_ZCE = POS_ZCSIG;
  TRSC_VC_PrevZCX.Integrator_Subsytem_Reset_ZCE = UNINITIALIZED_ZCSIG;
  TRSC_VC_PrevZCX.Integrator_Subsytem2_Reset_ZCE = POS_ZCSIG;
  TRSC_VC_PrevZCX.TAD_ep1_Reset_ZCE = POS_ZCSIG;
  TRSC_VC_PrevZCX.TravDist_TrapIntegrator_Reset_ZCE = POS_ZCSIG;
  TRSC_VC_PrevZCX.ResettableDelay_Reset_ZCE = POS_ZCSIG;
  TRSC_VC_PrevZCX.ResettableDelay_Reset_ZCE_a = POS_ZCSIG;
  TRSC_VC_PrevZCX.Delay_Reset_ZCE = POS_ZCSIG;
  TRSC_VC_PrevZCX.ResettableDelay_Reset_ZCE_g = POS_ZCSIG;
  TRSC_VC_PrevZCX.Integrator_Subsytem1_j.Integrator_Subsytem1_Reset_ZCE =
    POS_ZCSIG;
  TRSC_VC_PrevZCX.Integrator_Subsytem2.Integrator_Subsytem1_Reset_ZCE =
    POS_ZCSIG;
  TRSC_VC_PrevZCX.Integrator_Subsytem1_g.Integrator_Subsytem1_Reset_ZCE =
    POS_ZCSIG;
  TRSC_VC_PrevZCX.Integrator_Subsytem1.Integrator_Subsytem1_Reset_ZCE =
    POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
