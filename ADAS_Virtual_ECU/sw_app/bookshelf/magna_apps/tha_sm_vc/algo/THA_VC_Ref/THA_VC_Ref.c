/*
 * File: THA_VC_Ref.c
 *
 * Code generated for Simulink model 'THA_VC_Ref'.
 *
 * Model version                  : 1.2042
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:42:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "THA_VC_Ref.h"
#include "THA_VC_Ref_private.h"
#include "LookUpEven_real32_T_real32_T.h"
#include "LookUp_real32_T_real32_T.h"
#include "ComputeWheelSpeed_Rw46Mgmr.h"
#include "look1_iflf_binlg.h"
#include "look1_iflf_binlx.h"
#include "look2_iflf_binlg.h"
#include "rt_hypotf.h"
#include "rt_modf.h"

#if DEBUG_PRINTS
#include <UART_stdio.h>
#include <stdio.h>
#include <ti/osal/TaskP.h>
#include "ti/osal/TimerP.h"
//Dipti : WorkAround for Snooping variables
volatile real32_T plot_StrAngCmd = 0.0f;
volatile real32_T plot_THASteerTrqInfo = 0.0f;
#endif

/* Named constants for Chart: '<S41>/Chart' */
#define THA_VC_Ref_IN_I_Remove_Neg     ((uint8_T)1U)
#define THA_VC_Ref_IN_I_Remove_Pos     ((uint8_T)2U)
#define THA_VC_Ref_IN_I_Update_Neg     ((uint8_T)3U)
#define THA_VC_Ref_IN_I_Update_Pos     ((uint8_T)4U)
#define THA_VC_Ref_IN_Init             ((uint8_T)5U)
#define THA_VC_Ref_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)

/* Exported block signals */
real32_T MeTHA_deg_RelAngle;           /* '<S146>/Switch'
                                        * Initial angle made by coupler with Hitch when THA is engaged.
                                        */
real32_T MeTHA_deg_StrAngCmd;          /* '<S39>/Signal Copy'
                                        * Required steering angle calculated by steering control block of VC.
                                        */

/* Block signals (default storage) */
B_THA_VC_Ref_caua_T THA_VC_Ref_B;

/* Block states (default storage) */
DW_THA_VC_Ref_fwu4_T THA_VC_Ref_DW;

/* Previous zero-crossings (trigger) states */
ZCE_THA_VC_Ref_T THA_VC_Ref_PrevZCX;

/*
 * Output and update for atomic system:
 *    '<S62>/MATLAB Function'
 *    '<S63>/MATLAB Function'
 *    '<S61>/MATLAB Function'
 */
void THA_VC_Ref_MATLABFunction(real32_T rtu_rear, real32_T rtu_right, real32_T
  rtu_left, int8_T rtu_str_dir, real32_T rty_angles[4])
{
  rty_angles[0] = rtu_rear;
  if (rtu_str_dir == 1) {
    rty_angles[1] = rtu_right;
    rty_angles[2] = rtu_left;
  } else {
    rty_angles[1] = rtu_left;
    rty_angles[2] = rtu_right;
  }

  rty_angles[3] = rtu_rear;
}

/* System initialize for referenced model: 'THA_VC_Ref' */
void THA_VC_Ref_Init(void)
{
  int32_T i;
  static const int8_T tmp[12] = { 1, 1, 1, 2, 2, 3, 2, 3, 4, 3, 4, 4 };

  /* InitializeConditions for UnitDelay: '<S7>/UnitDelay3' */
  THA_VC_Ref_DW.UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  THA_VC_Ref_DW.UnitDelay_DSTATE_dqs4 = false;

  /* InitializeConditions for UnitDelay: '<S8>/Delay Input2'
   *
   * Block description for '<S8>/Delay Input2':
   *
   *  Store in Global RAM
   */
  THA_VC_Ref_DW.DelayInput2_DSTATE = 0.0F;

  /* SystemInitialize for Atomic SubSystem: '<S2>/InitCplrAngSelect' */
  /* InitializeConditions for UnitDelay: '<S146>/Unit Delay' */
  THA_VC_Ref_DW.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S146>/Unit Delay1' */
  THA_VC_Ref_DW.UnitDelay1_DSTATE_ogps = false;

  /* End of SystemInitialize for SubSystem: '<S2>/InitCplrAngSelect' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/THA_Distance_SpeedLimit_Processing' */
  /* InitializeConditions for Delay: '<S9>/Delay1' */
  THA_VC_Ref_DW.Delay1_DSTATE = 0;

  /* InitializeConditions for Delay: '<S15>/Resettable Delay' */
  THA_VC_Ref_DW.icLoad = 1U;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay1' */
  THA_VC_Ref_DW.UnitDelay1_DSTATE_am1v = TeTHA_e_THARmpUpDwnSpd_No_Request;

  /* InitializeConditions for UnitDelay: '<S33>/UnitDelay3' */
  THA_VC_Ref_DW.UnitDelay3_DSTATE_bncg = 0.0F;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
  THA_VC_Ref_DW.UnitDelay_DSTATE_lln4 = TeTHA_e_THARmpUpDwnSpd_No_Request;

  /* InitializeConditions for Delay: '<S9>/Delay' */
  THA_VC_Ref_DW.Delay_DSTATE_b3on = 0;

  /* InitializeConditions for Delay: '<S14>/Resettable Delay' */
  THA_VC_Ref_DW.icLoad_hchm = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/THA_Distance_SpeedLimit_Processing' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/THA_KM_SteerTorque_Processing' */
  /* InitializeConditions for Delay: '<S69>/Delay' */
  THA_VC_Ref_DW.Delay_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S70>/Delay' */
  THA_VC_Ref_DW.Delay_DSTATE_lu4u = 0.0F;

  /* InitializeConditions for Delay: '<S71>/Delay' */
  THA_VC_Ref_DW.Delay_DSTATE_psr1 = 0.0F;

  /* InitializeConditions for Delay: '<S72>/Delay' */
  THA_VC_Ref_DW.Delay_DSTATE_nkk5 = 0.0F;

  /* InitializeConditions for Delay: '<S75>/Delay' */
  THA_VC_Ref_DW.Delay_DSTATE_pwdf = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
  THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE = THA_VC_Ref_ConstB.Constant1;
  if (THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE >= KsTHA_k_TrqCtrlIntExtSatTD
      [0]) {
    THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE = KsTHA_k_TrqCtrlIntExtSatTD[0];
  } else {
    if (THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE <=
        -KsTHA_k_TrqCtrlIntExtSatTD[0]) {
      THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE = -KsTHA_k_TrqCtrlIntExtSatTD
        [0];
    }
  }

  THA_VC_Ref_DW.DiscreteTimeIntegrator_PrevResetState = 2;

  /* End of InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */

  /* InitializeConditions for Delay: '<S73>/Delay' */
  THA_VC_Ref_DW.Delay_DSTATE_j2qc = 0.0F;

  /* InitializeConditions for Delay: '<S74>/Delay' */
  THA_VC_Ref_DW.Delay_DSTATE_h4yd = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S36>/Forward_Kinematics_Model1' */
  /*              [RR,RF;   RR,LF;  RR,LR;  RF,LF;  RF,LR;  LF,LR]; */
  /* Code to generate pairs of wheels */
  /*     %{ */
  /*     %Code has potention to generate wheel_pair but  */
  /*     %currently disablled as it uses dynamic memory allocation */
  /*     %wheel_pairs = generatePairs(total_wheel_num); */
  /*     %} */
  /* I dont know how to create enum in matlab hence using variables */
  /* An error means either the sensor returning anglular orientation of wheel */
  /* failed or the sensor returning wheel speed failed or both failed */
  THA_VC_Ref_DW.x = 1U;
  THA_VC_Ref_DW.y = 2U;
  THA_VC_Ref_DW.error = 1U;
  for (i = 0; i < 12; i++) {
    THA_VC_Ref_DW.wheel_pairs[i] = (real_T)tmp[i];

    /* SystemInitialize for MATLAB Function: '<S36>/Forward_Kinematics_Model' */
    THA_VC_Ref_DW.wheel_pairs_etgb[i] = (real_T)tmp[i];
  }

  /* End of SystemInitialize for MATLAB Function: '<S36>/Forward_Kinematics_Model1' */

  /* SystemInitialize for MATLAB Function: '<S36>/Forward_Kinematics_Model' */
  /*              [RR,RF;   RR,LF;  RR,LR;  RF,LF;  RF,LR;  LF,LR]; */
  /* Code to generate pairs of wheels */
  /*     %{ */
  /*     %Code has potention to generate wheel_pair but  */
  /*     %currently disablled as it uses dynamic memory allocation */
  /*     %wheel_pairs = generatePairs(total_wheel_num); */
  /*     %} */
  /* I dont know how to create enum in matlab hence using variables */
  /* An error means either the sensor returning anglular orientation of wheel */
  /* failed or the sensor returning wheel speed failed or both failed */
  THA_VC_Ref_DW.x_mu1j = 1U;
  THA_VC_Ref_DW.y_eojm = 2U;
  THA_VC_Ref_DW.error_n0hy = 1U;

  /* SystemInitialize for Atomic SubSystem: '<S10>/STR_Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S40>/Discrete_Time_Integrator1' */
  THA_VC_Ref_DW.Discrete_Time_Integrator1_PrevResetState = 2;

  /* End of SystemInitialize for SubSystem: '<S10>/STR_Control' */

  /* SystemInitialize for Enabled SubSystem: '<S39>/Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S79>/Discrete_Time_Integrator1' */
  THA_VC_Ref_DW.Discrete_Time_Integrator1_DSTATE_m4zj = 0.0F;
  THA_VC_Ref_DW.Discrete_Time_Integrator1_PrevResetState_pyfj = 2;

  /* End of SystemInitialize for SubSystem: '<S39>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S10>/TrqControlOld' */
  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay4' */
  THA_VC_Ref_DW.UnitDelay4_DSTATE = false;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/DiscreteTimeIntegrator' */
  THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE_e31n =
    THA_VC_Ref_ConstB.Constant1_it32;

  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay2' */
  THA_VC_Ref_DW.UnitDelay2_DSTATE_gk31 = 0.0F;

  /* InitializeConditions for RateLimiter: '<S41>/DgainRateLimitor1' */
  THA_VC_Ref_DW.PrevY = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S10>/TrqControlOld' */
  /* End of SystemInitialize for SubSystem: '<S1>/THA_KM_SteerTorque_Processing' */

  /* SystemInitialize for Merge: '<S1>/Merge1' */
  THA_VC_Ref_B.Merge1 = 0.0F;
}

/* System reset for referenced model: 'THA_VC_Ref' */
void THA_VC_Ref_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S7>/UnitDelay3' */
  THA_VC_Ref_DW.UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  THA_VC_Ref_DW.UnitDelay_DSTATE_dqs4 = false;

  /* InitializeConditions for UnitDelay: '<S8>/Delay Input2'
   *
   * Block description for '<S8>/Delay Input2':
   *
   *  Store in Global RAM
   */
  THA_VC_Ref_DW.DelayInput2_DSTATE = 0.0F;

  /* SystemReset for Atomic SubSystem: '<S2>/InitCplrAngSelect' */
  /* InitializeConditions for UnitDelay: '<S146>/Unit Delay' */
  THA_VC_Ref_DW.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S146>/Unit Delay1' */
  THA_VC_Ref_DW.UnitDelay1_DSTATE_ogps = false;

  /* End of SystemReset for SubSystem: '<S2>/InitCplrAngSelect' */
}

/* Disable for referenced model: 'THA_VC_Ref' */
void THA_VC_Ref_Disable(TeTHA_e_THARmpUpDwnSpd *rty_IeTHA_e_THARmpUpDwnSpd,
  real32_T *rty_MeTHA_deg_RoadWhlAng)
{
  /* Disable for Enabled SubSystem: '<S1>/THA_Distance_SpeedLimit_Processing' */
  if (THA_VC_Ref_DW.THA_Distance_SpeedLimit_Processing_MODE) {
    /* Disable for Outport: '<S9>/IeTHA_e_THARmpUpDwnSpd' */
    *rty_IeTHA_e_THARmpUpDwnSpd = TeTHA_e_THARmpUpDwnSpd_No_Request;
    THA_VC_Ref_DW.THA_Distance_SpeedLimit_Processing_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/THA_Distance_SpeedLimit_Processing' */

  /* Disable for Enabled SubSystem: '<S1>/THA_KM_SteerTorque_Processing' */
  if (THA_VC_Ref_DW.THA_KM_SteerTorque_Processing_MODE) {
    /* Disable for Enabled SubSystem: '<S39>/Subsystem' */
    if (THA_VC_Ref_DW.Subsystem_MODE) {
      /* Disable for Outport: '<S79>/Reset_time' */
      THA_VC_Ref_B.Discrete_Time_Integrator1_hao2 = 0.0F;
      THA_VC_Ref_DW.Subsystem_MODE = false;
    }

    /* End of Disable for SubSystem: '<S39>/Subsystem' */

    /* Disable for Enabled SubSystem: '<S10>/TrqControlOld' */
    THA_VC_Ref_DW.TrqControlOld_MODE = false;

    /* End of Disable for SubSystem: '<S10>/TrqControlOld' */

    /* Disable for Outport: '<S10>/MeTHA_deg_RoadWhlAng' */
    *rty_MeTHA_deg_RoadWhlAng = 0.0F;

    /* Disable for Outport: '<S10>/MeTHA_deg_StrAngCmd' */
    MeTHA_deg_StrAngCmd = 0.0F;
    THA_VC_Ref_DW.THA_KM_SteerTorque_Processing_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/THA_KM_SteerTorque_Processing' */
}

/* Start for referenced model: 'THA_VC_Ref' */
void THA_VC_Ref_Start(real32_T *rty_IeTHA_pct_THAStrDamp)
{
  /* Start for Constant: '<S1>/Constant' */
  *rty_IeTHA_pct_THAStrDamp = KeTHA_pct_StrDampDefault;
}

/* Output and update for referenced model: 'THA_VC_Ref' */
void THA_VC_Ref(const TbTHASmVc_InputFromThaDet_t *rtu_MbTHA_ThaDetOutData,
                const TbTHASmVc_InputFromVehInp_t *rtu_MbTHA_VehInpOutData,
                const TbTHASmVc_InputFromProxiMgr_t *rtu_MbTHA_ProxiMgrOutData,
                const TbTHASmVc_InputVrntTunParam_t
                *rtu_MbTHA_VrntTunParamOutData, const TeTHA_e_THASteerTrqReq
                *rtu_MeTHA_e_THASteerTrqReq, const TeTHA_e_THAStateInfo
                *rtu_MeTHA_e_THAStateInfo, TeTHA_e_THARmpUpDwnSpd
                *rty_IeTHA_e_THARmpUpDwnSpd, real32_T
                *rty_IeTHA_M_THASteerTrqInfo, TeTHA_e_THASteerTrqReq
                *rty_IeTHA_e_THASteerTrqReq, real32_T *rty_IeTHA_pct_THAStrDamp,
                real32_T *rty_MeTHA_deg_RoadWhlAng)
{
  uint8_T valid_combos;
  real32_T wheel_1_x_dot;
  real32_T wheel_2_x_dot;
  real32_T wheel_1_y_dot;
  real32_T wheel_2_y_dot;
  int32_T i;
  real32_T v;
  int32_T veh_x_dot_tmp;
  int32_T tmp;
  int32_T tmp_0;
  real32_T tmp_1;
  int32_T veh_theta_dot_all_tmp;
  int32_T wheel_2_x_dot_tmp;
  boolean_T guard1 = false;

  /* RelationalOperator: '<S2>/RelationalOperator' incorporates:
   *  Constant: '<S140>/Constant'
   */
  THA_VC_Ref_B.UnitDelay4 = (*rtu_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Engaged);

  /* RelationalOperator: '<S2>/RelationalOperator3' incorporates:
   *  Constant: '<S143>/Constant'
   */
  THA_VC_Ref_B.MeTHA_b_ThaSmAbrtSts = (*rtu_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Engaged_Delta);

  /* RelationalOperator: '<S2>/RelationalOperator4' incorporates:
   *  Constant: '<S144>/Constant'
   */
  THA_VC_Ref_B.RelationalOperator6 = (*rtu_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Engaged_Inquiry);

  /* Logic: '<S2>/Logical Operator1' */
  THA_VC_Ref_B.UnitDelay4 = (THA_VC_Ref_B.UnitDelay4 ||
    THA_VC_Ref_B.MeTHA_b_ThaSmAbrtSts || THA_VC_Ref_B.RelationalOperator6);

  /* RelationalOperator: '<S2>/RelationalOperator5' incorporates:
   *  Constant: '<S145>/Constant'
   */
  THA_VC_Ref_B.RelationalOperator6 = (*rtu_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Complete);

  /* Logic: '<S2>/Logical Operator2' */
  THA_VC_Ref_B.MeTHA_b_VCActive = (THA_VC_Ref_B.UnitDelay4 ||
    THA_VC_Ref_B.RelationalOperator6);

  /* Logic: '<S1>/Logical Operator4' */
  THA_VC_Ref_B.RelationalOperator6 = !THA_VC_Ref_B.MeTHA_b_VCActive;

  /* UnitDelay: '<S7>/UnitDelay3' */
  THA_VC_Ref_B.integrator_external_saturation_table =
    THA_VC_Ref_DW.UnitDelay3_DSTATE;

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S7>/Constant4'
   */
  if (THA_VC_Ref_B.RelationalOperator6) {
    THA_VC_Ref_B.Switch1 = 0.0F;
  } else {
    THA_VC_Ref_B.Switch1 = THA_VC_Ref_B.integrator_external_saturation_table;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Sum: '<S7>/Sum1' */
  THA_VC_Ref_B.integrator_external_saturation_table =
    rtu_MbTHA_VrntTunParamOutData->KeTHA_s_SteerTweakTime - THA_VC_Ref_B.Switch1;

  /* Outputs for Enabled SubSystem: '<S1>/THA_Distance_SpeedLimit_Processing' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  /* Gain: '<S7>/Gain' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Gain: '<S33>/Gain'
   */
  wheel_1_x_dot = 0.99F * KeTHA_s_ThaSampleTime;

  /* End of Outputs for SubSystem: '<S1>/THA_Distance_SpeedLimit_Processing' */
  THA_VC_Ref_B.Sum_hqju = wheel_1_x_dot;

  /* RelationalOperator: '<S7>/RelationalOperator' */
  THA_VC_Ref_B.RelationalOperator6 =
    (THA_VC_Ref_B.integrator_external_saturation_table < THA_VC_Ref_B.Sum_hqju);

  /* RelationalOperator: '<S2>/RelationalOperator1' incorporates:
   *  Constant: '<S141>/Constant'
   */
  THA_VC_Ref_B.MeTHA_b_ThaSmAbrtSts = (*rtu_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Faulted);

  /* Logic: '<S1>/Logical Operator1' */
  THA_VC_Ref_B.LogicalOperator6 = !THA_VC_Ref_B.MeTHA_b_ThaSmAbrtSts;

  /* Logic: '<S1>/Logical Operator5' */
  THA_VC_Ref_B.LogicalOperator5 = (THA_VC_Ref_B.LogicalOperator6 &&
    THA_VC_Ref_B.RelationalOperator6);

  /* Logic: '<S1>/Logical Operator2' */
  THA_VC_Ref_B.RelationalOperator6 = !THA_VC_Ref_B.RelationalOperator6;

  /* Logic: '<S1>/Logical Operator3' */
  THA_VC_Ref_B.LogicalOperator3 = (THA_VC_Ref_B.MeTHA_b_VCActive &&
    THA_VC_Ref_B.RelationalOperator6);

  /* Switch: '<S1>/Switch' incorporates:
   *  Switch: '<S1>/Switch1'
   */
  if (THA_VC_Ref_B.LogicalOperator3) {
    /* Product: '<S1>/Divide' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/Constant7'
     */
    THA_VC_Ref_B.Divide = KeTHA_M_SteerTweakTrq / KeTHA_s_SteerTweakTime;

    /* Gain: '<S1>/Gain' */
    THA_VC_Ref_B.Gain_fl2v = 10.0F * THA_VC_Ref_B.Divide;
    THA_VC_Ref_B.Sum_hqju = THA_VC_Ref_B.Gain_fl2v;
  } else {
    if (THA_VC_Ref_B.LogicalOperator5) {
      /* Switch: '<S1>/Switch1' incorporates:
       *  Constant: '<S1>/Constant4'
       */
      THA_VC_Ref_B.Switch1_gex1 = KeTHA_dM_TrqCtrlSlewRate;
    } else {
      /* Switch: '<S1>/Switch1' incorporates:
       *  Constant: '<S1>/Constant1'
       */
      THA_VC_Ref_B.Switch1_gex1 = KeTHA_dM_EpsRampOutSlewRate;
    }

    THA_VC_Ref_B.Sum_hqju = THA_VC_Ref_B.Switch1_gex1;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Gain: '<S1>/Gain4' */
  THA_VC_Ref_B.integrator_external_saturation_table = (-1.0F) *
    THA_VC_Ref_B.Sum_hqju;

  /* SampleTimeMath: '<S8>/sample time'
   *
   * About '<S8>/sample time':
   *  y = K where K = ( w * Ts )
   */
  THA_VC_Ref_B.sampletime = 0.03F;

  /* Product: '<S8>/delta fall limit' */
  THA_VC_Ref_B.deltafalllimit =
    THA_VC_Ref_B.integrator_external_saturation_table * THA_VC_Ref_B.sampletime;

  /* Outputs for Enabled SubSystem: '<S1>/THA_SteerTweakProfile_Processing2' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (THA_VC_Ref_B.LogicalOperator3) {
    /* Gain: '<S12>/Gain2' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    THA_VC_Ref_B.integrator_external_saturation_table = 2.0F *
      KeTHA_k_NumTweakPulse;

    /* Product: '<S12>/Divide' */
    THA_VC_Ref_B.integrator_external_saturation_table =
      rtu_MbTHA_VrntTunParamOutData->KeTHA_s_SteerTweakTime /
      THA_VC_Ref_B.integrator_external_saturation_table;

    /* Gain: '<S12>/Gain' */
    THA_VC_Ref_B.integrator_external_saturation_table *= 33.3333321F;

    /* DataTypeConversion: '<S12>/Data Type Conversion1' */
    v = fabsf(THA_VC_Ref_B.integrator_external_saturation_table);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        THA_VC_Ref_B.DataTypeConversion1 = (uint8_T)floorf
          (THA_VC_Ref_B.integrator_external_saturation_table + 0.5F);
      } else {
        THA_VC_Ref_B.DataTypeConversion1 = 0U;
      }
    } else {
      THA_VC_Ref_B.DataTypeConversion1 = (uint8_T)
        THA_VC_Ref_B.integrator_external_saturation_table;
    }

    /* End of DataTypeConversion: '<S12>/Data Type Conversion1' */

    /* Product: '<S12>/Divide1' incorporates:
     *  Constant: '<S12>/Constant2'
     */
    THA_VC_Ref_B.Divide1 = (real_T)THA_VC_Ref_B.Switch1 / 0.03;

    /* DataTypeConversion: '<S12>/Data Type Conversion' */
    THA_VC_Ref_B.wheel_status_index1 = fabs(THA_VC_Ref_B.Divide1);
    if (THA_VC_Ref_B.wheel_status_index1 < 4.503599627370496E+15) {
      if (THA_VC_Ref_B.wheel_status_index1 >= 0.5) {
        THA_VC_Ref_B.DataTypeConversion_hcep = (uint8_T)floor
          (THA_VC_Ref_B.Divide1 + 0.5);
      } else {
        THA_VC_Ref_B.DataTypeConversion_hcep = 0U;
      }
    } else {
      THA_VC_Ref_B.DataTypeConversion_hcep = (uint8_T)THA_VC_Ref_B.Divide1;
    }

    /* End of DataTypeConversion: '<S12>/Data Type Conversion' */

    /* Product: '<S12>/Divide2' */
    THA_VC_Ref_B.DataTypeConversion1_dyy3 = (uint8_T)((uint32_T)
      THA_VC_Ref_B.DataTypeConversion1 == 0U ? MAX_uint32_T : (uint32_T)
      THA_VC_Ref_B.DataTypeConversion_hcep / (uint32_T)
      THA_VC_Ref_B.DataTypeConversion1);

    /* Math: '<S12>/Mod' incorporates:
     *  Constant: '<S12>/Constant3'
     */
    if ((int32_T)((uint8_T)2U) != 0) {
      THA_VC_Ref_B.DataTypeConversion1_dyy3 %= ((uint8_T)2U);
    }

    /* End of Math: '<S12>/Mod' */

    /* Switch: '<S12>/Switch' */
    if ((int32_T)THA_VC_Ref_B.DataTypeConversion1_dyy3 != 0) {
      THA_VC_Ref_B.integrator_external_saturation_table =
        rtu_MbTHA_VrntTunParamOutData->KeTHA_M_SteerTweakTrq;
    } else {
      /* Gain: '<S12>/Gain3' */
      THA_VC_Ref_B.Gain3 = (-1.0F) *
        rtu_MbTHA_VrntTunParamOutData->KeTHA_M_SteerTweakTrq;
      THA_VC_Ref_B.integrator_external_saturation_table = THA_VC_Ref_B.Gain3;
    }

    /* End of Switch: '<S12>/Switch' */

    /* Product: '<S12>/Product' */
    THA_VC_Ref_B.Merge1 = THA_VC_Ref_B.MeTHA_b_VCActive ?
      THA_VC_Ref_B.integrator_external_saturation_table : 0.0F;
  }

  /* End of Outputs for SubSystem: '<S1>/THA_SteerTweakProfile_Processing2' */

  /* Outputs for Atomic SubSystem: '<S2>/InitCplrAngSelect' */
  /* Logic: '<S146>/Logical Operator2' */
  THA_VC_Ref_B.LogicalOperator2 = (THA_VC_Ref_B.MeTHA_b_VCActive &&
    rtu_MbTHA_ThaDetOutData->MeTHA_b_CplrAngFound);

  /* UnitDelay: '<S146>/Unit Delay' */
  THA_VC_Ref_B.UnitDelay = THA_VC_Ref_DW.UnitDelay_DSTATE;

  /* UnitDelay: '<S146>/Unit Delay1' */
  THA_VC_Ref_B.LogicalOperator6 = THA_VC_Ref_DW.UnitDelay1_DSTATE_ogps;

  /* Logic: '<S146>/Logical Operator' */
  THA_VC_Ref_B.LogicalOperator6 = !THA_VC_Ref_B.LogicalOperator6;

  /* Logic: '<S146>/Logical Operator1' */
  THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.LogicalOperator2 &&
    THA_VC_Ref_B.LogicalOperator6);

  /* Switch: '<S146>/Switch' */
  if (THA_VC_Ref_B.LogicalOperator6) {
    /* Saturate: '<S2>/Saturation' */
    if (rtu_MbTHA_ThaDetOutData->MeTHA_deg_CplrAng > 180.0F) {
      THA_VC_Ref_B.Saturation = 180.0F;
    } else if (rtu_MbTHA_ThaDetOutData->MeTHA_deg_CplrAng < (-180.0F)) {
      THA_VC_Ref_B.Saturation = (-180.0F);
    } else {
      THA_VC_Ref_B.Saturation = rtu_MbTHA_ThaDetOutData->MeTHA_deg_CplrAng;
    }

    /* End of Saturate: '<S2>/Saturation' */
    MeTHA_deg_RelAngle = THA_VC_Ref_B.Saturation;
  } else {
    /* Logic: '<S146>/Logical Operator3' */
    THA_VC_Ref_B.LogicalOperator3_cq0a = !THA_VC_Ref_B.LogicalOperator2;

    /* Switch: '<S146>/Switch1' incorporates:
     *  Constant: '<S146>/Constant'
     */
    if (THA_VC_Ref_B.LogicalOperator3_cq0a) {
      THA_VC_Ref_B.Switch1_i2av = (real32_T)0;
    } else {
      THA_VC_Ref_B.Switch1_i2av = THA_VC_Ref_B.UnitDelay;
    }

    /* End of Switch: '<S146>/Switch1' */
    MeTHA_deg_RelAngle = THA_VC_Ref_B.Switch1_i2av;
  }

  /* End of Switch: '<S146>/Switch' */

  /* Update for UnitDelay: '<S146>/Unit Delay' */
  THA_VC_Ref_DW.UnitDelay_DSTATE = MeTHA_deg_RelAngle;

  /* Update for UnitDelay: '<S146>/Unit Delay1' */
  THA_VC_Ref_DW.UnitDelay1_DSTATE_ogps = THA_VC_Ref_B.LogicalOperator2;

  /* End of Outputs for SubSystem: '<S2>/InitCplrAngSelect' */

  /* Saturate: '<S2>/Saturation1' */
  if (rtu_MbTHA_VehInpOutData->IeVBII_deg_StrWhlAng > 570.0F) {
    THA_VC_Ref_B.Saturation1 = 570.0F;
  } else if (rtu_MbTHA_VehInpOutData->IeVBII_deg_StrWhlAng < (-570.0F)) {
    THA_VC_Ref_B.Saturation1 = (-570.0F);
  } else {
    THA_VC_Ref_B.Saturation1 = rtu_MbTHA_VehInpOutData->IeVBII_deg_StrWhlAng;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Saturate: '<S2>/Saturation6' */
  if (rtu_MbTHA_VehInpOutData->IeVBII_kph_RhrWhlSpd > 50.0F) {
    THA_VC_Ref_B.Saturation6 = 50.0F;
  } else if (rtu_MbTHA_VehInpOutData->IeVBII_kph_RhrWhlSpd < 0.0F) {
    THA_VC_Ref_B.Saturation6 = 0.0F;
  } else {
    THA_VC_Ref_B.Saturation6 = rtu_MbTHA_VehInpOutData->IeVBII_kph_RhrWhlSpd;
  }

  /* End of Saturate: '<S2>/Saturation6' */

  /* Saturate: '<S2>/Saturation3' */
  if (rtu_MbTHA_VehInpOutData->IeVBII_kph_LhrWhlSpd > 50.0F) {
    THA_VC_Ref_B.Saturation3 = 50.0F;
  } else if (rtu_MbTHA_VehInpOutData->IeVBII_kph_LhrWhlSpd < 0.0F) {
    THA_VC_Ref_B.Saturation3 = 0.0F;
  } else {
    THA_VC_Ref_B.Saturation3 = rtu_MbTHA_VehInpOutData->IeVBII_kph_LhrWhlSpd;
  }

  /* End of Saturate: '<S2>/Saturation3' */

  /* Saturate: '<S2>/Saturation4' */
  if (rtu_MbTHA_VehInpOutData->IeVBII_kph_LhfWhlSpd > 50.0F) {
    THA_VC_Ref_B.Saturation4 = 50.0F;
  } else if (rtu_MbTHA_VehInpOutData->IeVBII_kph_LhfWhlSpd < 0.0F) {
    THA_VC_Ref_B.Saturation4 = 0.0F;
  } else {
    THA_VC_Ref_B.Saturation4 = rtu_MbTHA_VehInpOutData->IeVBII_kph_LhfWhlSpd;
  }

  /* End of Saturate: '<S2>/Saturation4' */

  /* Saturate: '<S2>/Saturation5' */
  if (rtu_MbTHA_VehInpOutData->IeVBII_kph_RhfWhlSpd > 50.0F) {
    THA_VC_Ref_B.Saturation5 = 50.0F;
  } else if (rtu_MbTHA_VehInpOutData->IeVBII_kph_RhfWhlSpd < 0.0F) {
    THA_VC_Ref_B.Saturation5 = 0.0F;
  } else {
    THA_VC_Ref_B.Saturation5 = rtu_MbTHA_VehInpOutData->IeVBII_kph_RhfWhlSpd;
  }

  /* End of Saturate: '<S2>/Saturation5' */

  /* Saturate: '<S2>/Saturation7' */
  if (rtu_MbTHA_VehInpOutData->IeVBII_ddeg_StrWhlSpd > 2000.0F) {
    THA_VC_Ref_B.Saturation7 = 2000.0F;
  } else if (rtu_MbTHA_VehInpOutData->IeVBII_ddeg_StrWhlSpd < (-2000.0F)) {
    THA_VC_Ref_B.Saturation7 = (-2000.0F);
  } else {
    THA_VC_Ref_B.Saturation7 = rtu_MbTHA_VehInpOutData->IeVBII_ddeg_StrWhlSpd;
  }

  /* End of Saturate: '<S2>/Saturation7' */

  /* Saturate: '<S2>/Saturation10' */
  if (rtu_MbTHA_ThaDetOutData->MeTHA_px_CplrPnt[0] > 1280) {
    THA_VC_Ref_B.Saturation10 = 1280;
  } else if (rtu_MbTHA_ThaDetOutData->MeTHA_px_CplrPnt[0] < 0) {
    THA_VC_Ref_B.Saturation10 = 0;
  } else {
    THA_VC_Ref_B.Saturation10 = rtu_MbTHA_ThaDetOutData->MeTHA_px_CplrPnt[0];
  }

  /* End of Saturate: '<S2>/Saturation10' */

  /* Saturate: '<S2>/Saturation9' */
  if (rtu_MbTHA_ThaDetOutData->MeTHA_px_CplrPnt[1] > 1920) {
    THA_VC_Ref_B.Saturation9 = 1920;
  } else if (rtu_MbTHA_ThaDetOutData->MeTHA_px_CplrPnt[1] < 0) {
    THA_VC_Ref_B.Saturation9 = 0;
  } else {
    THA_VC_Ref_B.Saturation9 = rtu_MbTHA_ThaDetOutData->MeTHA_px_CplrPnt[1];
  }

  /* End of Saturate: '<S2>/Saturation9' */

  /* Saturate: '<S2>/Saturation8' */
  if (rtu_MbTHA_ThaDetOutData->MeTHA_px_HitchPnt[0] > 1280) {
    THA_VC_Ref_B.Saturation8 = 1280;
  } else if (rtu_MbTHA_ThaDetOutData->MeTHA_px_HitchPnt[0] < 0) {
    THA_VC_Ref_B.Saturation8 = 0;
  } else {
    THA_VC_Ref_B.Saturation8 = rtu_MbTHA_ThaDetOutData->MeTHA_px_HitchPnt[0];
  }

  /* End of Saturate: '<S2>/Saturation8' */

  /* Saturate: '<S2>/Saturation11' */
  if (rtu_MbTHA_ThaDetOutData->MeTHA_px_HitchPnt[1] > 1920) {
    THA_VC_Ref_B.Saturation11 = 1920;
  } else if (rtu_MbTHA_ThaDetOutData->MeTHA_px_HitchPnt[1] < 0) {
    THA_VC_Ref_B.Saturation11 = 0;
  } else {
    THA_VC_Ref_B.Saturation11 = rtu_MbTHA_ThaDetOutData->MeTHA_px_HitchPnt[1];
  }

  /* End of Saturate: '<S2>/Saturation11' */

  /* RelationalOperator: '<S147>/RelationalOperator6' incorporates:
   *  Constant: '<S148>/Constant'
   */
  THA_VC_Ref_B.LogicalOperator6 =
    (rtu_MbTHA_VehInpOutData->IeVBII_e_GearEngagedForDsply ==
     TeVBII_e_GearEngagedForDsply_R);

  /* Logic: '<S147>/Logical Operator11' */
  THA_VC_Ref_B.MeTHA_b_THAEnggdNotSupp = (THA_VC_Ref_B.UnitDelay4 &&
    THA_VC_Ref_B.LogicalOperator6);

  /* Outputs for Enabled SubSystem: '<S1>/THA_Distance_SpeedLimit_Processing' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (THA_VC_Ref_B.MeTHA_b_THAEnggdNotSupp) {
    if (!THA_VC_Ref_DW.THA_Distance_SpeedLimit_Processing_MODE) {
      /* InitializeConditions for Delay: '<S9>/Delay1' */
      THA_VC_Ref_DW.Delay1_DSTATE = 0;

      /* InitializeConditions for Delay: '<S15>/Resettable Delay' */
      THA_VC_Ref_DW.icLoad = 1U;

      /* InitializeConditions for UnitDelay: '<S16>/Unit Delay1' */
      THA_VC_Ref_DW.UnitDelay1_DSTATE_am1v = TeTHA_e_THARmpUpDwnSpd_No_Request;

      /* InitializeConditions for UnitDelay: '<S33>/UnitDelay3' */
      THA_VC_Ref_DW.UnitDelay3_DSTATE_bncg = 0.0F;

      /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
      THA_VC_Ref_DW.UnitDelay_DSTATE_lln4 = TeTHA_e_THARmpUpDwnSpd_No_Request;

      /* InitializeConditions for Delay: '<S9>/Delay' */
      THA_VC_Ref_DW.Delay_DSTATE_b3on = 0;

      /* InitializeConditions for Delay: '<S14>/Resettable Delay' */
      THA_VC_Ref_DW.icLoad_hchm = 1U;
      THA_VC_Ref_DW.THA_Distance_SpeedLimit_Processing_MODE = true;
    }

    /* Inport: '<S9>/MeTHA_Pnt_HitchPnt' */
    THA_VC_Ref_B.MeTHA_Pnt_HitchPnt[0] = THA_VC_Ref_B.Saturation8;
    THA_VC_Ref_B.MeTHA_Pnt_HitchPnt[1] = THA_VC_Ref_B.Saturation11;

    /* SignalConversion generated from: '<S9>/MeTHA_pixel_HitchLocationY' */
    THA_VC_Ref_B.OutportBufferForMeTHA_pixel_HitchLocationY =
      THA_VC_Ref_B.MeTHA_Pnt_HitchPnt[1];

    /* Delay: '<S9>/Delay1' */
    THA_VC_Ref_B.Delay1 = THA_VC_Ref_DW.Delay1_DSTATE;

    /* Delay: '<S15>/Resettable Delay' */
    if (THA_VC_Ref_B.MeTHA_b_VCActive && ((uint32_T)
         THA_VC_Ref_PrevZCX.ResettableDelay_Reset_ZCE != POS_ZCSIG)) {
      THA_VC_Ref_DW.icLoad = 1U;
    }

    THA_VC_Ref_PrevZCX.ResettableDelay_Reset_ZCE = THA_VC_Ref_B.MeTHA_b_VCActive
      ? (ZCSigState)1 : (ZCSigState)0;
    if ((int32_T)THA_VC_Ref_DW.icLoad != 0) {
      THA_VC_Ref_DW.ResettableDelay_DSTATE = THA_VC_Ref_B.Delay1;
    }

    THA_VC_Ref_B.ResettableDelay = THA_VC_Ref_DW.ResettableDelay_DSTATE;

    /* End of Delay: '<S15>/Resettable Delay' */

    /* Constant: '<S9>/Constant1' */
    THA_VC_Ref_B.Filter = (real32_T)KeTHA_dpx_CplrPntRateLimitMax;

    /* Product: '<S15>/Product' incorporates:
     *  Constant: '<S15>/Constant'
     */
    THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.Filter * KeTHA_s_ThaSampleTime *
      (real32_T)THA_VC_Ref_B.Saturation9;

    /* Sum: '<S15>/Difference Inputs1'
     *
     * Block description for '<S15>/Difference Inputs1':
     *
     *  Add in CPU
     */
    THA_VC_Ref_B.DifferenceInputs1 = (int32_T)(real32_T)((real32_T)
      THA_VC_Ref_B.Saturation9 - (real32_T)THA_VC_Ref_B.ResettableDelay);

    /* RelationalOperator: '<S19>/LowerRelop1' */
    THA_VC_Ref_B.LogicalOperator6 = ((real32_T)THA_VC_Ref_B.DifferenceInputs1 >
      THA_VC_Ref_B.Add1_jabu);

    /* Gain: '<S15>/Gain' */
    THA_VC_Ref_B.Square3 = (-1.0F) * THA_VC_Ref_B.Filter;

    /* Product: '<S15>/Product1' incorporates:
     *  Constant: '<S15>/Constant'
     */
    THA_VC_Ref_B.Dgain = THA_VC_Ref_B.Square3 * KeTHA_s_ThaSampleTime *
      (real32_T)THA_VC_Ref_B.Saturation9;

    /* RelationalOperator: '<S19>/UpperRelop' */
    THA_VC_Ref_B.RelationalOperator6 = ((real32_T)THA_VC_Ref_B.DifferenceInputs1
      < THA_VC_Ref_B.Dgain);

    /* Switch: '<S19>/Switch' */
    if (THA_VC_Ref_B.RelationalOperator6) {
      THA_VC_Ref_B.Switch_j13x = THA_VC_Ref_B.Dgain;
    } else {
      THA_VC_Ref_B.Switch_j13x = (real32_T)THA_VC_Ref_B.DifferenceInputs1;
    }

    /* End of Switch: '<S19>/Switch' */

    /* Switch: '<S19>/Switch2' */
    if (THA_VC_Ref_B.LogicalOperator6) {
      THA_VC_Ref_B.Switch2_kwro = THA_VC_Ref_B.Add1_jabu;
    } else {
      THA_VC_Ref_B.Switch2_kwro = THA_VC_Ref_B.Switch_j13x;
    }

    /* End of Switch: '<S19>/Switch2' */

    /* Sum: '<S15>/Difference Inputs2'
     *
     * Block description for '<S15>/Difference Inputs2':
     *
     *  Add in CPU
     */
    v = floorf(THA_VC_Ref_B.Switch2_kwro + (real32_T)
               THA_VC_Ref_B.ResettableDelay);
    if (v < 2.14748365E+9F) {
      if (v >= -2.14748365E+9F) {
        THA_VC_Ref_B.DifferenceInputs2_lsrk = (int32_T)v;
      } else {
        THA_VC_Ref_B.DifferenceInputs2_lsrk = MIN_int32_T;
      }
    } else {
      THA_VC_Ref_B.DifferenceInputs2_lsrk = MAX_int32_T;
    }

    /* End of Sum: '<S15>/Difference Inputs2' */

    /* Sum: '<S9>/Rpt_Xdiff' */
    THA_VC_Ref_B.Rpt_Xdiff = (real32_T)THA_VC_Ref_B.MeTHA_Pnt_HitchPnt[1] -
      (real32_T)THA_VC_Ref_B.DifferenceInputs2_lsrk;

    /* RelationalOperator: '<S17>/Relational Operator' incorporates:
     *  Constant: '<S17>/Constant2'
     */
    THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.Rpt_Xdiff <= (real32_T)0);

    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S17>/Constant1'
     */
    if (THA_VC_Ref_B.LogicalOperator6) {
      THA_VC_Ref_B.Add1_jabu = 0.0F;
    } else {
      /* Lookup_n-D: '<S17>/1-D Lookup Table' */
      THA_VC_Ref_B.uDLookupTable = look1_iflf_binlg(THA_VC_Ref_B.Rpt_Xdiff,
        THA_VC_Ref_ConstP.uDLookupTable_bp01Data, ((real32_T *)
        &(KsTHA_mps_DistSpdTD[0])), 5U);
      THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.uDLookupTable;
    }

    /* End of Switch: '<S17>/Switch' */

    /* Gain: '<S16>/Gain' */
    THA_VC_Ref_B.Add1_jabu *= 3.6F;

    /* DataTypeConversion: '<S16>/DataTypeConversion' */
    THA_VC_Ref_B.DataTypeConversion_kd4p = (uint8_T)ceilf(THA_VC_Ref_B.Add1_jabu);

    /* MultiPortSwitch: '<S16>/Multiport' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S21>/Constant'
     *  Constant: '<S22>/Constant'
     *  Constant: '<S24>/Constant'
     *  Constant: '<S25>/Constant'
     *  Constant: '<S26>/Constant'
     *  Constant: '<S27>/Constant'
     *  Constant: '<S28>/Constant'
     *  Constant: '<S29>/Constant'
     *  Constant: '<S30>/Constant'
     *  Constant: '<S31>/Constant'
     *  Constant: '<S32>/Constant'
     */
    switch (THA_VC_Ref_B.DataTypeConversion_kd4p) {
     case 0:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_1;
      break;

     case 1:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_1;
      break;

     case 2:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_2;
      break;

     case 3:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_3;
      break;

     case 4:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_4;
      break;

     case 5:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_5;
      break;

     case 6:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_6;
      break;

     case 7:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_7;
      break;

     case 8:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_8;
      break;

     case 9:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_9;
      break;

     case 10:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_Kph_10;
      break;

     default:
      THA_VC_Ref_B.Multiport = TeTHA_e_THARmpUpDwnSpd_No_Request;
      break;
    }

    /* End of MultiPortSwitch: '<S16>/Multiport' */

    /* RelationalOperator: '<S16>/Relational Operator2' incorporates:
     *  Constant: '<S23>/Constant'
     */
    THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.Multiport !=
      TeTHA_e_THARmpUpDwnSpd_No_Request);

    /* UnitDelay: '<S16>/Unit Delay1' */
    THA_VC_Ref_B.UnitDelay_ej2n = THA_VC_Ref_DW.UnitDelay1_DSTATE_am1v;

    /* RelationalOperator: '<S16>/Relational Operator1' incorporates:
     *  Constant: '<S23>/Constant'
     */
    THA_VC_Ref_B.RelationalOperator6 = (THA_VC_Ref_B.UnitDelay_ej2n ==
      TeTHA_e_THARmpUpDwnSpd_No_Request);

    /* Logic: '<S16>/Logical Operator1' */
    THA_VC_Ref_B.RelationalOperator6 = (THA_VC_Ref_B.RelationalOperator6 &&
      THA_VC_Ref_B.LogicalOperator6);

    /* RelationalOperator: '<S16>/Relational Operator' */
    THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.Multiport ==
      THA_VC_Ref_B.UnitDelay_ej2n);

    /* Logic: '<S16>/LogicalOperator6' */
    THA_VC_Ref_B.UnitDelay4 = !THA_VC_Ref_B.LogicalOperator6;

    /* UnitDelay: '<S33>/UnitDelay3' */
    THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_DW.UnitDelay3_DSTATE_bncg;

    /* Switch: '<S33>/Switch1' incorporates:
     *  Constant: '<S33>/Constant4'
     */
    if (THA_VC_Ref_B.UnitDelay4) {
      THA_VC_Ref_B.Add1_jabu = 0.0F;
    }

    /* End of Switch: '<S33>/Switch1' */

    /* Sum: '<S33>/Sum1' incorporates:
     *  Constant: '<S16>/Constant7'
     */
    THA_VC_Ref_B.Square3 = KeTHA_s_SpdLimConfDur - THA_VC_Ref_B.Add1_jabu;

    /* Gain: '<S33>/Gain' */
    THA_VC_Ref_B.Dgain = wheel_1_x_dot;

    /* RelationalOperator: '<S33>/RelationalOperator' */
    THA_VC_Ref_B.UnitDelay4 = (THA_VC_Ref_B.Square3 < THA_VC_Ref_B.Dgain);

    /* Logic: '<S16>/Logical Operator2' */
    THA_VC_Ref_B.UnitDelay4 = (THA_VC_Ref_B.UnitDelay4 ||
      THA_VC_Ref_B.RelationalOperator6);

    /* UnitDelay: '<S16>/Unit Delay' */
    THA_VC_Ref_B.UnitDelay_ej2n = THA_VC_Ref_DW.UnitDelay_DSTATE_lln4;

    /* Switch: '<S16>/Switch' */
    if (THA_VC_Ref_B.UnitDelay4) {
      *rty_IeTHA_e_THARmpUpDwnSpd = THA_VC_Ref_B.Multiport;
    } else {
      *rty_IeTHA_e_THARmpUpDwnSpd = THA_VC_Ref_B.UnitDelay_ej2n;
    }

    /* End of Switch: '<S16>/Switch' */

    /* Switch: '<S33>/Switch3' incorporates:
     *  Constant: '<S16>/Constant3'
     *  Constant: '<S33>/Constant2'
     */
    if (THA_VC_Ref_B.LogicalOperator6) {
      THA_VC_Ref_B.Square3 = KeTHA_s_ThaSampleTime;
    } else {
      THA_VC_Ref_B.Square3 = 0.0F;
    }

    /* End of Switch: '<S33>/Switch3' */

    /* Sum: '<S33>/Sum' */
    THA_VC_Ref_B.Add1_jabu += THA_VC_Ref_B.Square3;

    /* MinMax: '<S33>/MinMax' incorporates:
     *  Constant: '<S16>/Constant7'
     */
    THA_VC_Ref_B.MinMax_pmrs = fminf(THA_VC_Ref_B.Add1_jabu,
      KeTHA_s_SpdLimConfDur);

    /* Product: '<S14>/Product' incorporates:
     *  Constant: '<S14>/Constant'
     */
    THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.Filter * KeTHA_s_ThaSampleTime *
      (real32_T)THA_VC_Ref_B.Saturation10;

    /* Delay: '<S9>/Delay' */
    THA_VC_Ref_B.Delay_pt0m = THA_VC_Ref_DW.Delay_DSTATE_b3on;

    /* Delay: '<S14>/Resettable Delay' */
    if (THA_VC_Ref_B.MeTHA_b_VCActive && ((uint32_T)
         THA_VC_Ref_PrevZCX.ResettableDelay_Reset_ZCE_ajsj != POS_ZCSIG)) {
      THA_VC_Ref_DW.icLoad_hchm = 1U;
    }

    THA_VC_Ref_PrevZCX.ResettableDelay_Reset_ZCE_ajsj =
      THA_VC_Ref_B.MeTHA_b_VCActive ? (ZCSigState)1 : (ZCSigState)0;
    if ((int32_T)THA_VC_Ref_DW.icLoad_hchm != 0) {
      THA_VC_Ref_DW.ResettableDelay_DSTATE_lieo = THA_VC_Ref_B.Delay_pt0m;
    }

    THA_VC_Ref_B.ResettableDelay_lzig =
      THA_VC_Ref_DW.ResettableDelay_DSTATE_lieo;

    /* End of Delay: '<S14>/Resettable Delay' */

    /* Sum: '<S14>/Difference Inputs1'
     *
     * Block description for '<S14>/Difference Inputs1':
     *
     *  Add in CPU
     */
    v = (real32_T)THA_VC_Ref_B.Saturation10 - (real32_T)
      THA_VC_Ref_B.ResettableDelay_lzig;
    if (v < 2.14748365E+9F) {
      if (v >= -2.14748365E+9F) {
        THA_VC_Ref_B.DifferenceInputs1_ab5m = (int32_T)v;
      } else {
        THA_VC_Ref_B.DifferenceInputs1_ab5m = MIN_int32_T;
      }
    } else {
      THA_VC_Ref_B.DifferenceInputs1_ab5m = MAX_int32_T;
    }

    /* End of Sum: '<S14>/Difference Inputs1' */

    /* RelationalOperator: '<S18>/LowerRelop1' */
    THA_VC_Ref_B.LogicalOperator6 = ((real32_T)
      THA_VC_Ref_B.DifferenceInputs1_ab5m > THA_VC_Ref_B.Add1_jabu);

    /* Gain: '<S14>/Gain' */
    THA_VC_Ref_B.Filter *= (-1.0F);

    /* Product: '<S14>/Product1' incorporates:
     *  Constant: '<S14>/Constant'
     */
    THA_VC_Ref_B.Square3 = THA_VC_Ref_B.Filter * KeTHA_s_ThaSampleTime *
      (real32_T)THA_VC_Ref_B.Saturation10;

    /* RelationalOperator: '<S18>/UpperRelop' */
    THA_VC_Ref_B.RelationalOperator6 = ((real32_T)
      THA_VC_Ref_B.DifferenceInputs1_ab5m < THA_VC_Ref_B.Square3);

    /* Switch: '<S18>/Switch' */
    if (THA_VC_Ref_B.RelationalOperator6) {
      v = floorf(THA_VC_Ref_B.Square3);
      if (v < 2.14748365E+9F) {
        if (v >= -2.14748365E+9F) {
          THA_VC_Ref_B.Switch_fg02 = (int32_T)v;
        } else {
          THA_VC_Ref_B.Switch_fg02 = MIN_int32_T;
        }
      } else {
        THA_VC_Ref_B.Switch_fg02 = MAX_int32_T;
      }
    } else {
      THA_VC_Ref_B.Switch_fg02 = THA_VC_Ref_B.DifferenceInputs1_ab5m;
    }

    /* End of Switch: '<S18>/Switch' */

    /* Switch: '<S18>/Switch2' */
    if (THA_VC_Ref_B.LogicalOperator6) {
      v = floorf(THA_VC_Ref_B.Add1_jabu);
      if (v < 2.14748365E+9F) {
        if (v >= -2.14748365E+9F) {
          THA_VC_Ref_B.Switch2_haof = (int32_T)v;
        } else {
          THA_VC_Ref_B.Switch2_haof = MIN_int32_T;
        }
      } else {
        THA_VC_Ref_B.Switch2_haof = MAX_int32_T;
      }
    } else {
      THA_VC_Ref_B.Switch2_haof = THA_VC_Ref_B.Switch_fg02;
    }

    /* End of Switch: '<S18>/Switch2' */

    /* Sum: '<S14>/Difference Inputs2'
     *
     * Block description for '<S14>/Difference Inputs2':
     *
     *  Add in CPU
     */
    v = (real32_T)THA_VC_Ref_B.Switch2_haof + (real32_T)
      THA_VC_Ref_B.ResettableDelay_lzig;
    if (v < 2.14748365E+9F) {
      if (v >= -2.14748365E+9F) {
        THA_VC_Ref_B.DifferenceInputs2_jov4 = (int32_T)v;
      } else {
        THA_VC_Ref_B.DifferenceInputs2_jov4 = MIN_int32_T;
      }
    } else {
      THA_VC_Ref_B.DifferenceInputs2_jov4 = MAX_int32_T;
    }

    /* End of Sum: '<S14>/Difference Inputs2' */

    /* Update for Delay: '<S9>/Delay1' */
    THA_VC_Ref_DW.Delay1_DSTATE = THA_VC_Ref_B.DifferenceInputs2_lsrk;

    /* Update for Delay: '<S15>/Resettable Delay' */
    THA_VC_Ref_DW.icLoad = 0U;
    THA_VC_Ref_DW.ResettableDelay_DSTATE = THA_VC_Ref_B.DifferenceInputs2_lsrk;

    /* Update for UnitDelay: '<S16>/Unit Delay1' */
    THA_VC_Ref_DW.UnitDelay1_DSTATE_am1v = THA_VC_Ref_B.Multiport;

    /* Update for UnitDelay: '<S33>/UnitDelay3' */
    THA_VC_Ref_DW.UnitDelay3_DSTATE_bncg = THA_VC_Ref_B.MinMax_pmrs;

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    THA_VC_Ref_DW.UnitDelay_DSTATE_lln4 = *rty_IeTHA_e_THARmpUpDwnSpd;

    /* Update for Delay: '<S9>/Delay' */
    THA_VC_Ref_DW.Delay_DSTATE_b3on = THA_VC_Ref_B.DifferenceInputs2_jov4;

    /* Update for Delay: '<S14>/Resettable Delay' */
    THA_VC_Ref_DW.icLoad_hchm = 0U;
    THA_VC_Ref_DW.ResettableDelay_DSTATE_lieo =
      THA_VC_Ref_B.DifferenceInputs2_jov4;
  } else {
    if (THA_VC_Ref_DW.THA_Distance_SpeedLimit_Processing_MODE) {
      /* Disable for Outport: '<S9>/IeTHA_e_THARmpUpDwnSpd' */
      *rty_IeTHA_e_THARmpUpDwnSpd = TeTHA_e_THARmpUpDwnSpd_No_Request;
      THA_VC_Ref_DW.THA_Distance_SpeedLimit_Processing_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/THA_Distance_SpeedLimit_Processing' */

  /* UnitDelay: '<S1>/Unit Delay' */
  THA_VC_Ref_B.UnitDelay_h2xn = THA_VC_Ref_DW.UnitDelay_DSTATE_dqs4;

  /* Outputs for Enabled SubSystem: '<S1>/THA_KM_SteerTorque_Processing' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (THA_VC_Ref_B.LogicalOperator5) {
    THA_VC_Ref_DW.THA_KM_SteerTorque_Processing_MODE = true;

    /* DataTypeConversion: '<S10>/Data Type Conversion30' */
    THA_VC_Ref_B.DataTypeConversion30 = (uint8_T)
      rtu_MbTHA_ProxiMgrOutData->MePRX_e_Wheelbase;

    /* MultiPortSwitch: '<S36>/Multiport Switch' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S36>/Constant3'
     *  Constant: '<S36>/Constant4'
     *  Constant: '<S36>/Constant6'
     */
    switch (THA_VC_Ref_B.DataTypeConversion30) {
     case 0:
      THA_VC_Ref_B.MultiportSwitch = 3.5687F;
      break;

     case 1:
      THA_VC_Ref_B.MultiportSwitch = 3.6703F;
      break;

     case 2:
      THA_VC_Ref_B.MultiportSwitch = 3.8989F;
      break;

     default:
      THA_VC_Ref_B.MultiportSwitch = 3.6703F;
      break;
    }

    /* End of MultiPortSwitch: '<S36>/Multiport Switch' */

    /* MATLAB Function: '<S36>/Compute_Whl_Pos' incorporates:
     *  Constant: '<S36>/track_m'
     */
    THA_VC_Ref_B.wheel_pos[0] = 0.0F;
    THA_VC_Ref_B.wheel_pos[2] = -THA_VC_Ref_B.MultiportSwitch;
    THA_VC_Ref_B.wheel_pos[4] = -THA_VC_Ref_B.MultiportSwitch;
    THA_VC_Ref_B.wheel_pos[6] = 0.0F;
    THA_VC_Ref_B.wheel_pos[1] = 1.7388F / 2.0F;
    THA_VC_Ref_B.wheel_pos[3] = 1.7388F / 2.0F;
    v = -1.7388F / 2.0F;
    THA_VC_Ref_B.wheel_pos[5] = v;
    THA_VC_Ref_B.wheel_pos[7] = v;

    /* DataTypeConversion: '<S10>/Data Type Conversion23' */
    THA_VC_Ref_B.DataTypeConversion23 = (uint8_T)
      rtu_MbTHA_VehInpOutData->IeVBII_e_RhrWhlSpnSts;

    /* DataTypeConversion: '<S10>/Data Type Conversion24' */
    THA_VC_Ref_B.DataTypeConversion24 = (uint8_T)
      rtu_MbTHA_VehInpOutData->IeVBII_e_RhfWhlSpnSts;

    /* DataTypeConversion: '<S10>/Data Type Conversion25' */
    THA_VC_Ref_B.DataTypeConversion25 = (uint8_T)
      rtu_MbTHA_VehInpOutData->IeVBII_e_LhfWhlSpnSts;

    /* DataTypeConversion: '<S10>/Data Type Conversion26' */
    THA_VC_Ref_B.DataTypeConversion26 = (uint8_T)
      rtu_MbTHA_VehInpOutData->IeVBII_e_LhrWhlSpnSts;

    /* MATLAB Function: '<S36>/WhlStatus_Merger' */
    THA_VC_Ref_B.status[0] = THA_VC_Ref_B.DataTypeConversion23;
    THA_VC_Ref_B.status[1] = THA_VC_Ref_B.DataTypeConversion24;
    THA_VC_Ref_B.status[2] = THA_VC_Ref_B.DataTypeConversion25;
    THA_VC_Ref_B.status[3] = THA_VC_Ref_B.DataTypeConversion26;

    /* DataTypeConversion: '<S10>/Data Type Conversion29' */
    THA_VC_Ref_B.DataTypeConversion29 =
      rtu_MbTHA_ProxiMgrOutData->MePRX_mm_TyreSz;

    /* Gain: '<S36>/mm_to_m' */
    THA_VC_Ref_B.mm_to_m = 0.001F * (real32_T)THA_VC_Ref_B.DataTypeConversion29;

    /* MATLAB Function: '<S36>/Compute_Whl_Radius' */
    v = THA_VC_Ref_B.mm_to_m / 6.28318548F;
    THA_VC_Ref_B.wheel_radius[0] = v;
    THA_VC_Ref_B.wheel_radius[1] = v;
    THA_VC_Ref_B.wheel_radius[2] = v;
    THA_VC_Ref_B.wheel_radius[3] = v;

    /* DataTypeConversion: '<S10>/Data Type Conversion32' */
    THA_VC_Ref_B.DataTypeConversion32 =
      rtu_MbTHA_VehInpOutData->IeVBII_cnt_RhrPulseCtr;

    /* DataTypeConversion: '<S10>/Data Type Conversion33' */
    THA_VC_Ref_B.DataTypeConversion33 =
      rtu_MbTHA_VehInpOutData->IeVBII_cnt_RhfPulseCtr;

    /* DataTypeConversion: '<S10>/Data Type Conversion34' */
    THA_VC_Ref_B.DataTypeConversion34 =
      rtu_MbTHA_VehInpOutData->IeVBII_cnt_LhfPulseCtr;

    /* DataTypeConversion: '<S10>/Data Type Conversion35' */
    THA_VC_Ref_B.DataTypeConversion35 =
      rtu_MbTHA_VehInpOutData->IeVBII_cnt_LhrPulseCtr;

    /* DataTypeConversion: '<S10>/Data Type Conversion21' */
    THA_VC_Ref_B.DataTypeConversion21 = (uint8_T)
      rtu_MbTHA_VehInpOutData->IeVBII_e_GearEngagedForDsply;

    /* MATLAB Function: '<S36>/ComputeTickBasedWhlSpeed' */
    if (!THA_VC_Ref_DW.last_tick_RR_not_empty) {
      THA_VC_Ref_DW.last_tick_RR = THA_VC_Ref_B.DataTypeConversion32;
      THA_VC_Ref_DW.last_tick_RR_not_empty = true;
      THA_VC_Ref_DW.last_tick_RF = THA_VC_Ref_B.DataTypeConversion33;
      THA_VC_Ref_DW.last_tick_LF = THA_VC_Ref_B.DataTypeConversion34;
      THA_VC_Ref_DW.last_tick_LR = THA_VC_Ref_B.DataTypeConversion35;
    }

    THA_VC_Ref_B.tick_speed_RR = ComputeWheelSpeed_Rw46Mgmr
      (THA_VC_Ref_B.DataTypeConversion32, THA_VC_Ref_DW.last_tick_RR,
       THA_VC_Ref_ConstB.DataTypeConversion27, 96,
       THA_VC_Ref_B.DataTypeConversion21, THA_VC_Ref_B.wheel_radius[0]);
    THA_VC_Ref_B.tick_speed_RF = ComputeWheelSpeed_Rw46Mgmr
      (THA_VC_Ref_B.DataTypeConversion33, THA_VC_Ref_DW.last_tick_RF,
       THA_VC_Ref_ConstB.DataTypeConversion27, 96,
       THA_VC_Ref_B.DataTypeConversion21, THA_VC_Ref_B.wheel_radius[1]);
    THA_VC_Ref_B.tick_speed_LF = ComputeWheelSpeed_Rw46Mgmr
      (THA_VC_Ref_B.DataTypeConversion34, THA_VC_Ref_DW.last_tick_LF,
       THA_VC_Ref_ConstB.DataTypeConversion27, 96,
       THA_VC_Ref_B.DataTypeConversion21, THA_VC_Ref_B.wheel_radius[2]);
    THA_VC_Ref_B.tick_speed_LR = ComputeWheelSpeed_Rw46Mgmr
      (THA_VC_Ref_B.DataTypeConversion35, THA_VC_Ref_DW.last_tick_LR,
       THA_VC_Ref_ConstB.DataTypeConversion27, 96,
       THA_VC_Ref_B.DataTypeConversion21, THA_VC_Ref_B.wheel_radius[3]);
    THA_VC_Ref_DW.last_tick_RR = THA_VC_Ref_B.DataTypeConversion32;
    THA_VC_Ref_DW.last_tick_RF = THA_VC_Ref_B.DataTypeConversion33;
    THA_VC_Ref_DW.last_tick_LF = THA_VC_Ref_B.DataTypeConversion34;
    THA_VC_Ref_DW.last_tick_LR = THA_VC_Ref_B.DataTypeConversion35;

    /* End of MATLAB Function: '<S36>/ComputeTickBasedWhlSpeed' */

    /* MATLAB Function: '<S36>/Tick_WhlSpeed_Merger1' */
    /* tick_diff = [tick_diff_RR, tick_diff_RF, tick_diff_LF, tick_diff_LR]; */
    THA_VC_Ref_B.wheelSpeeds[0] = THA_VC_Ref_B.tick_speed_RR;
    THA_VC_Ref_B.wheelSpeeds[1] = THA_VC_Ref_B.tick_speed_RF;
    THA_VC_Ref_B.wheelSpeeds[2] = THA_VC_Ref_B.tick_speed_LF;
    THA_VC_Ref_B.wheelSpeeds[3] = THA_VC_Ref_B.tick_speed_LR;

    /* SignalConversion: '<S36>/Signal Copy1' */
    THA_VC_Ref_B.SignalCopy1[0] = THA_VC_Ref_B.wheelSpeeds[0];
    THA_VC_Ref_B.SignalCopy1[1] = THA_VC_Ref_B.wheelSpeeds[1];
    THA_VC_Ref_B.SignalCopy1[2] = THA_VC_Ref_B.wheelSpeeds[2];
    THA_VC_Ref_B.SignalCopy1[3] = THA_VC_Ref_B.wheelSpeeds[3];

    /* DataTypeConversion: '<S10>/Data Type Conversion31' */
    THA_VC_Ref_B.DataTypeConversion1_dyy3 = (uint8_T)
      rtu_MbTHA_ProxiMgrOutData->MePRX_e_SteerRatRackPinionTyp;

    /* DataTypeConversion: '<S10>/Data Type Conversion20' */
    THA_VC_Ref_B.DataTypeConversion20 = THA_VC_Ref_B.Saturation1;

    /* If: '<S46>/If_else_Steering_Type' */
    if ((int32_T)THA_VC_Ref_B.DataTypeConversion1_dyy3 == 0) {
      /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S64>/Action Port'
       */
      /* Abs: '<S64>/Abs' */
      THA_VC_Ref_B.uD_LUT_CENTER_55C = fabsf(THA_VC_Ref_B.DataTypeConversion20);

      /* Lookup_n-D: '<S64>/1D_LUT_LEFT_55C' */
      THA_VC_Ref_B.uD_LUT_LEFT_55C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_55C, THA_VC_Ref_ConstP.pooled13,
         THA_VC_Ref_ConstP.uD_LUT_LEFT_55C_tableData, 8U);

      /* Lookup_n-D: '<S64>/1D_LUT_RIGHT_55C' */
      THA_VC_Ref_B.uD_LUT_RIGHT_55C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_55C, THA_VC_Ref_ConstP.pooled13,
         THA_VC_Ref_ConstP.uD_LUT_RIGHT_55C_tableData, 8U);

      /* Signum: '<S64>/Sign' */
      if (THA_VC_Ref_B.DataTypeConversion20 < 0.0F) {
        THA_VC_Ref_B.uD_LUT_CORRECTION_55C = -1.0F;
      } else if (THA_VC_Ref_B.DataTypeConversion20 > 0.0F) {
        THA_VC_Ref_B.uD_LUT_CORRECTION_55C = 1.0F;
      } else {
        THA_VC_Ref_B.uD_LUT_CORRECTION_55C = THA_VC_Ref_B.DataTypeConversion20;
      }

      /* End of Signum: '<S64>/Sign' */

      /* DataTypeConversion: '<S64>/Data Type Conversion' */
      THA_VC_Ref_B.DataTypeConversion_dwsq = (int8_T)floorf
        (THA_VC_Ref_B.uD_LUT_CORRECTION_55C);

      /* MATLAB Function: '<S64>/MATLAB Function' incorporates:
       *  Constant: '<S64>/rear_wheel_angles'
       */
      THA_VC_Ref_B.angles_nyg4[0] = 0.0F;
      if (THA_VC_Ref_B.DataTypeConversion_dwsq == 1) {
        THA_VC_Ref_B.angles_nyg4[1] = THA_VC_Ref_B.uD_LUT_RIGHT_55C;
        THA_VC_Ref_B.angles_nyg4[2] = THA_VC_Ref_B.uD_LUT_LEFT_55C;
      } else {
        THA_VC_Ref_B.angles_nyg4[1] = THA_VC_Ref_B.uD_LUT_LEFT_55C;
        THA_VC_Ref_B.angles_nyg4[2] = THA_VC_Ref_B.uD_LUT_RIGHT_55C;
      }

      THA_VC_Ref_B.angles_nyg4[3] = 0.0F;

      /* End of MATLAB Function: '<S64>/MATLAB Function' */

      /* Lookup_n-D: '<S64>/1D_LUT_CORRECTION_55C' */
      THA_VC_Ref_B.uD_LUT_CORRECTION_55C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_55C,
         THA_VC_Ref_ConstP.uD_LUT_CORRECTION_55C_bp01Data,
         THA_VC_Ref_ConstP.uD_LUT_CORRECTION_55C_tableData, 7U);

      /* Product: '<S64>/Product2' */
      THA_VC_Ref_B.Merge1_ptoy[0] = THA_VC_Ref_B.angles_nyg4[0] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_55C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_dwsq;
      THA_VC_Ref_B.Merge1_ptoy[1] = THA_VC_Ref_B.angles_nyg4[1] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_55C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_dwsq;
      THA_VC_Ref_B.Merge1_ptoy[2] = THA_VC_Ref_B.angles_nyg4[2] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_55C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_dwsq;
      THA_VC_Ref_B.Merge1_ptoy[3] = THA_VC_Ref_B.angles_nyg4[3] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_55C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_dwsq;

      /* Lookup_n-D: '<S64>/1D_LUT_CENTER_55C' */
      THA_VC_Ref_B.uD_LUT_CENTER_55C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_55C, THA_VC_Ref_ConstP.pooled13,
         THA_VC_Ref_ConstP.uD_LUT_CENTER_55C_tableData, 8U);

      /* Product: '<S64>/Product1' */
      THA_VC_Ref_B.Gain4 = THA_VC_Ref_B.uD_LUT_CENTER_55C *
        THA_VC_Ref_B.uD_LUT_CORRECTION_55C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_dwsq;

      /* End of Outputs for SubSystem: '<S46>/If Action Subsystem8' */
    } else if ((int32_T)THA_VC_Ref_B.DataTypeConversion1_dyy3 == 1) {
      /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S62>/Action Port'
       */
      /* Abs: '<S62>/Abs' */
      THA_VC_Ref_B.uD_LUT_CENTER_60C = fabsf(THA_VC_Ref_B.DataTypeConversion20);

      /* Lookup_n-D: '<S62>/1D_LUT_LEFT_60C' */
      THA_VC_Ref_B.uD_LUT_LEFT_60C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_60C, THA_VC_Ref_ConstP.pooled14,
         THA_VC_Ref_ConstP.uD_LUT_LEFT_60C_tableData, 8U);

      /* Lookup_n-D: '<S62>/1D_LUT_RIGHT_60C' */
      THA_VC_Ref_B.uD_LUT_RIGHT_60C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_60C, THA_VC_Ref_ConstP.pooled14,
         THA_VC_Ref_ConstP.uD_LUT_RIGHT_60C_tableData, 8U);

      /* Signum: '<S62>/Sign' */
      if (THA_VC_Ref_B.DataTypeConversion20 < 0.0F) {
        THA_VC_Ref_B.uD_LUT_CORRECTION_60C = -1.0F;
      } else if (THA_VC_Ref_B.DataTypeConversion20 > 0.0F) {
        THA_VC_Ref_B.uD_LUT_CORRECTION_60C = 1.0F;
      } else {
        THA_VC_Ref_B.uD_LUT_CORRECTION_60C = THA_VC_Ref_B.DataTypeConversion20;
      }

      /* End of Signum: '<S62>/Sign' */

      /* DataTypeConversion: '<S62>/Data Type Conversion' */
      THA_VC_Ref_B.DataTypeConversion_p5bw = (int8_T)floorf
        (THA_VC_Ref_B.uD_LUT_CORRECTION_60C);

      /* MATLAB Function: '<S62>/MATLAB Function' incorporates:
       *  Constant: '<S62>/rear_wheel_angles'
       */
      THA_VC_Ref_MATLABFunction(0.0F, THA_VC_Ref_B.uD_LUT_RIGHT_60C,
        THA_VC_Ref_B.uD_LUT_LEFT_60C, THA_VC_Ref_B.DataTypeConversion_p5bw,
        THA_VC_Ref_B.angles_k40t);

      /* Lookup_n-D: '<S62>/1D_LUT_CORRECTION_60C' */
      THA_VC_Ref_B.uD_LUT_CORRECTION_60C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_60C,
         THA_VC_Ref_ConstP.uD_LUT_CORRECTION_60C_bp01Data,
         THA_VC_Ref_ConstP.uD_LUT_CORRECTION_60C_tableData, 7U);

      /* Product: '<S62>/Product2' */
      THA_VC_Ref_B.Merge1_ptoy[0] = THA_VC_Ref_B.angles_k40t[0] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_60C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_p5bw;
      THA_VC_Ref_B.Merge1_ptoy[1] = THA_VC_Ref_B.angles_k40t[1] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_60C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_p5bw;
      THA_VC_Ref_B.Merge1_ptoy[2] = THA_VC_Ref_B.angles_k40t[2] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_60C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_p5bw;
      THA_VC_Ref_B.Merge1_ptoy[3] = THA_VC_Ref_B.angles_k40t[3] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_60C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_p5bw;

      /* Lookup_n-D: '<S62>/1D_LUT_CENTER_60C' */
      THA_VC_Ref_B.uD_LUT_CENTER_60C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_60C, THA_VC_Ref_ConstP.pooled14,
         THA_VC_Ref_ConstP.uD_LUT_CENTER_60C_tableData, 8U);

      /* Product: '<S62>/Product1' */
      THA_VC_Ref_B.Gain4 = THA_VC_Ref_B.uD_LUT_CENTER_60C *
        THA_VC_Ref_B.uD_LUT_CORRECTION_60C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_p5bw;

      /* End of Outputs for SubSystem: '<S46>/If Action Subsystem2' */
    } else if ((int32_T)THA_VC_Ref_B.DataTypeConversion1_dyy3 == 2) {
      /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      /* Abs: '<S63>/Abs' */
      THA_VC_Ref_B.uD_LUT_CENTER_63C_albi = fabsf
        (THA_VC_Ref_B.DataTypeConversion20);

      /* Lookup_n-D: '<S63>/1D_LUT_LEFT_63C' */
      THA_VC_Ref_B.uD_LUT_LEFT_63C_msgm = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_63C_albi, THA_VC_Ref_ConstP.pooled16,
         THA_VC_Ref_ConstP.pooled15, 8U);

      /* Lookup_n-D: '<S63>/1D_LUT_RIGHT_63C' */
      THA_VC_Ref_B.uD_LUT_RIGHT_63C_g1oc = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_63C_albi, THA_VC_Ref_ConstP.pooled16,
         THA_VC_Ref_ConstP.pooled17, 8U);

      /* Signum: '<S63>/Sign' */
      if (THA_VC_Ref_B.DataTypeConversion20 < 0.0F) {
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs = -1.0F;
      } else if (THA_VC_Ref_B.DataTypeConversion20 > 0.0F) {
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs = 1.0F;
      } else {
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs =
          THA_VC_Ref_B.DataTypeConversion20;
      }

      /* End of Signum: '<S63>/Sign' */

      /* DataTypeConversion: '<S63>/Data Type Conversion' */
      THA_VC_Ref_B.DataTypeConversion_otfa = (int8_T)floorf
        (THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs);

      /* MATLAB Function: '<S63>/MATLAB Function' incorporates:
       *  Constant: '<S63>/rear_wheel_angles'
       */
      THA_VC_Ref_MATLABFunction(0.0F, THA_VC_Ref_B.uD_LUT_RIGHT_63C_g1oc,
        THA_VC_Ref_B.uD_LUT_LEFT_63C_msgm, THA_VC_Ref_B.DataTypeConversion_otfa,
        THA_VC_Ref_B.angles_ftc1);

      /* Lookup_n-D: '<S63>/1D_LUT_CORRECTION_63C' */
      THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_63C_albi, THA_VC_Ref_ConstP.pooled19,
         THA_VC_Ref_ConstP.pooled18, 6U);

      /* Product: '<S63>/Product2' */
      THA_VC_Ref_B.Merge1_ptoy[0] = THA_VC_Ref_B.angles_ftc1[0] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_otfa;
      THA_VC_Ref_B.Merge1_ptoy[1] = THA_VC_Ref_B.angles_ftc1[1] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_otfa;
      THA_VC_Ref_B.Merge1_ptoy[2] = THA_VC_Ref_B.angles_ftc1[2] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_otfa;
      THA_VC_Ref_B.Merge1_ptoy[3] = THA_VC_Ref_B.angles_ftc1[3] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_otfa;

      /* Lookup_n-D: '<S63>/1D_LUT_CENTER_63C' */
      THA_VC_Ref_B.uD_LUT_CENTER_63C_albi = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_63C_albi, THA_VC_Ref_ConstP.pooled16,
         THA_VC_Ref_ConstP.pooled20, 8U);

      /* Product: '<S63>/Product1' */
      THA_VC_Ref_B.Gain4 = THA_VC_Ref_B.uD_LUT_CENTER_63C_albi *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C_cixs * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_otfa;

      /* End of Outputs for SubSystem: '<S46>/If Action Subsystem3' */
    } else {
      /* Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S61>/Action Port'
       */
      /* Abs: '<S61>/Abs' */
      THA_VC_Ref_B.uD_LUT_CENTER_63C = fabsf(THA_VC_Ref_B.DataTypeConversion20);

      /* Lookup_n-D: '<S61>/1D_LUT_LEFT_63C' */
      THA_VC_Ref_B.uD_LUT_LEFT_63C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_63C, THA_VC_Ref_ConstP.pooled16,
         THA_VC_Ref_ConstP.pooled15, 8U);

      /* Lookup_n-D: '<S61>/1D_LUT_RIGHT_63C' */
      THA_VC_Ref_B.uD_LUT_RIGHT_63C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_63C, THA_VC_Ref_ConstP.pooled16,
         THA_VC_Ref_ConstP.pooled17, 8U);

      /* Signum: '<S61>/Sign' */
      if (THA_VC_Ref_B.DataTypeConversion20 < 0.0F) {
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C = -1.0F;
      } else if (THA_VC_Ref_B.DataTypeConversion20 > 0.0F) {
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C = 1.0F;
      } else {
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C = THA_VC_Ref_B.DataTypeConversion20;
      }

      /* End of Signum: '<S61>/Sign' */

      /* DataTypeConversion: '<S61>/Data Type Conversion' */
      THA_VC_Ref_B.DataTypeConversion_jb1p = (int8_T)floorf
        (THA_VC_Ref_B.uD_LUT_CORRECTION_63C);

      /* MATLAB Function: '<S61>/MATLAB Function' incorporates:
       *  Constant: '<S61>/rear_wheel_angles'
       */
      THA_VC_Ref_MATLABFunction(0.0F, THA_VC_Ref_B.uD_LUT_RIGHT_63C,
        THA_VC_Ref_B.uD_LUT_LEFT_63C, THA_VC_Ref_B.DataTypeConversion_jb1p,
        THA_VC_Ref_B.angles);

      /* Lookup_n-D: '<S61>/1D_LUT_CORRECTION_63C' */
      THA_VC_Ref_B.uD_LUT_CORRECTION_63C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_63C, THA_VC_Ref_ConstP.pooled19,
         THA_VC_Ref_ConstP.pooled18, 6U);

      /* Product: '<S61>/Product2' */
      THA_VC_Ref_B.Merge1_ptoy[0] = THA_VC_Ref_B.angles[0] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_jb1p;
      THA_VC_Ref_B.Merge1_ptoy[1] = THA_VC_Ref_B.angles[1] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_jb1p;
      THA_VC_Ref_B.Merge1_ptoy[2] = THA_VC_Ref_B.angles[2] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_jb1p;
      THA_VC_Ref_B.Merge1_ptoy[3] = THA_VC_Ref_B.angles[3] *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_jb1p;

      /* Lookup_n-D: '<S61>/1D_LUT_CENTER_63C' */
      THA_VC_Ref_B.uD_LUT_CENTER_63C = look1_iflf_binlg
        (THA_VC_Ref_B.uD_LUT_CENTER_63C, THA_VC_Ref_ConstP.pooled16,
         THA_VC_Ref_ConstP.pooled20, 8U);

      /* Product: '<S61>/Product1' */
      THA_VC_Ref_B.Gain4 = THA_VC_Ref_B.uD_LUT_CENTER_63C *
        THA_VC_Ref_B.uD_LUT_CORRECTION_63C * (real32_T)
        THA_VC_Ref_B.DataTypeConversion_jb1p;

      /* End of Outputs for SubSystem: '<S46>/If Action Subsystem1' */
    }

    /* End of If: '<S46>/If_else_Steering_Type' */

    /* Gain: '<S46>/Gain13' */
    THA_VC_Ref_B.Gain13[0] = 0.0174532924F * THA_VC_Ref_B.Merge1_ptoy[0];

    /* SignalConversion: '<S36>/Signal Copy2' */
    THA_VC_Ref_B.SignalCopy2[0] = THA_VC_Ref_B.Gain13[0];

    /* Gain: '<S46>/Gain13' */
    THA_VC_Ref_B.Gain13[1] = 0.0174532924F * THA_VC_Ref_B.Merge1_ptoy[1];

    /* SignalConversion: '<S36>/Signal Copy2' */
    THA_VC_Ref_B.SignalCopy2[1] = THA_VC_Ref_B.Gain13[1];

    /* Gain: '<S46>/Gain13' */
    THA_VC_Ref_B.Gain13[2] = 0.0174532924F * THA_VC_Ref_B.Merge1_ptoy[2];

    /* SignalConversion: '<S36>/Signal Copy2' */
    THA_VC_Ref_B.SignalCopy2[2] = THA_VC_Ref_B.Gain13[2];

    /* Gain: '<S46>/Gain13' */
    THA_VC_Ref_B.Gain13[3] = 0.0174532924F * THA_VC_Ref_B.Merge1_ptoy[3];

    /* SignalConversion: '<S36>/Signal Copy2' */
    THA_VC_Ref_B.SignalCopy2[3] = THA_VC_Ref_B.Gain13[3];

    /* MATLAB Function: '<S36>/Forward_Kinematics_Model1' */
    /* Explanation */
    /* { */
    /* wheel_num is integer denoting number of wheels in our configration */
    /* wheel_pos is 2 x n matrix with first row being xpos of wheel and 2nd row is y pos of wheel */
    /* Special Note: wheel pos should be denifed relative to the point which we consider are reference point for overall vehicle body motion */
    /* this means that lets say you select rear axel center as refrence point then x coord of rear wheel should be 0, but if you select */
    /* front axel as refrence point then x coord of rear axel should be -wheelbase */
    /* wheel_radius is 1 x n matrix denoting the radius of individual wheel in meter */
    /* wheel_spin is 1 x n matrix consisting of individual wheel_spins in rad/s */
    /* wheel_theta is 1 x n matrix consisting of individual wheel_spins in rad */
    /*  */
    /* veh_x_dot is same as vehicle's longitudinal velocity */
    /* veh_y_dot is same as vehicle's lateral velocity */
    /* veh_theta_dot is same as vehicle's yaw rate */
    /* } */
    /* temp variables used for in loop calculations */
    valid_combos = 0U;
    for (i = 0; i < 6; i++) {
      THA_VC_Ref_B.veh_x_dot_all[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      THA_VC_Ref_B.veh_y_dot_all[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      THA_VC_Ref_B.veh_theta_dot_all[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      THA_VC_Ref_B.wheel_status_index1 = THA_VC_Ref_DW.wheel_pairs[i];
      THA_VC_Ref_B.wheel_status_index2 = THA_VC_Ref_DW.wheel_pairs[i + 6];
      if (THA_VC_Ref_DW.wheel_pairs[i] > 4.0) {
        THA_VC_Ref_B.wheel_status_index1 = 4.0;
      }

      if (THA_VC_Ref_B.wheel_status_index2 > 4.0) {
        THA_VC_Ref_B.wheel_status_index2 = 4.0;
      }

      veh_x_dot_tmp = (int32_T)THA_VC_Ref_B.wheel_status_index1 - 1;
      if (THA_VC_Ref_B.status[veh_x_dot_tmp] != THA_VC_Ref_DW.error) {
        wheel_2_x_dot_tmp = (int32_T)THA_VC_Ref_B.wheel_status_index2 - 1;
        if (THA_VC_Ref_B.status[wheel_2_x_dot_tmp] != THA_VC_Ref_DW.error) {
          wheel_1_x_dot = THA_VC_Ref_B.SignalCopy1[veh_x_dot_tmp] * cosf
            (THA_VC_Ref_B.SignalCopy2[veh_x_dot_tmp]);
          wheel_2_x_dot = THA_VC_Ref_B.SignalCopy1[wheel_2_x_dot_tmp] * cosf
            (THA_VC_Ref_B.SignalCopy2[wheel_2_x_dot_tmp]);
          wheel_1_y_dot = THA_VC_Ref_B.SignalCopy1[veh_x_dot_tmp] * sinf
            (THA_VC_Ref_B.SignalCopy2[veh_x_dot_tmp]);
          wheel_2_y_dot = THA_VC_Ref_B.SignalCopy1[wheel_2_x_dot_tmp] * sinf
            (THA_VC_Ref_B.SignalCopy2[wheel_2_x_dot_tmp]);
          wheel_2_x_dot_tmp <<= (uint32_T)1;
          veh_x_dot_tmp <<= (uint32_T)1;
          tmp = (wheel_2_x_dot_tmp + (int32_T)THA_VC_Ref_DW.y) - 1;
          tmp_0 = (veh_x_dot_tmp + (int32_T)THA_VC_Ref_DW.y) - 1;
          if ((THA_VC_Ref_B.wheel_pos[tmp] == THA_VC_Ref_B.wheel_pos[tmp_0]) &&
              (THA_VC_Ref_B.wheel_pos[(wheel_2_x_dot_tmp + (int32_T)
                THA_VC_Ref_DW.x) - 1] == THA_VC_Ref_B.wheel_pos[(veh_x_dot_tmp +
                (int32_T)THA_VC_Ref_DW.x) - 1])) {
            /* You entered same wheel twice as both co-ordinates are same, code */
            /* needs to throw error here indicated the user that they are at */
            /* fault and what fault exactly is */
          } else {
            valid_combos = (uint8_T)(int32_T)((int32_T)valid_combos + 1);
            if ((int32_T)valid_combos > 6) {
              valid_combos = 6U;
            }

            /* Here last elseif is not really required but added just for extra precaution */
            veh_x_dot_tmp = ((((int32_T)THA_VC_Ref_B.wheel_status_index1 - 1) <<
                              (uint32_T)1) + (int32_T)THA_VC_Ref_DW.x) - 1;
            wheel_2_x_dot_tmp = ((((int32_T)THA_VC_Ref_B.wheel_status_index2 - 1)
                                  << (uint32_T)1) + (int32_T)THA_VC_Ref_DW.x) -
              1;
            v = THA_VC_Ref_B.wheel_pos[veh_x_dot_tmp] -
              THA_VC_Ref_B.wheel_pos[wheel_2_x_dot_tmp];
            guard1 = false;
            if (v != 0.0F) {
              tmp_1 = THA_VC_Ref_B.wheel_pos[tmp] - THA_VC_Ref_B.wheel_pos[tmp_0];
              if (tmp_1 != 0.0F) {
                veh_theta_dot_all_tmp = (int32_T)valid_combos - 1;
                THA_VC_Ref_B.veh_theta_dot_all[veh_theta_dot_all_tmp] =
                  (wheel_1_y_dot - wheel_2_y_dot) * 0.5F / v;
                THA_VC_Ref_B.veh_theta_dot_all[veh_theta_dot_all_tmp] +=
                  (wheel_1_x_dot - wheel_2_x_dot) * 0.5F / tmp_1;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              if (v != 0.0F) {
                THA_VC_Ref_B.veh_theta_dot_all[(int32_T)valid_combos - 1] =
                  (wheel_1_y_dot - wheel_2_y_dot) / v;
              } else {
                v = THA_VC_Ref_B.wheel_pos[tmp] - THA_VC_Ref_B.wheel_pos[tmp_0];
                if (v != 0.0F) {
                  THA_VC_Ref_B.veh_theta_dot_all[(int32_T)valid_combos - 1] =
                    (wheel_1_x_dot - wheel_2_x_dot) / v;
                } else {
                  /* Default value is already 0 so no need to write extra code. */
                }
              }
            }

            veh_theta_dot_all_tmp = (int32_T)valid_combos - 1;
            THA_VC_Ref_B.veh_x_dot_all[veh_theta_dot_all_tmp] =
              ((THA_VC_Ref_B.wheel_pos[tmp_0] + THA_VC_Ref_B.wheel_pos[tmp]) *
               THA_VC_Ref_B.veh_theta_dot_all[veh_theta_dot_all_tmp] +
               (wheel_1_x_dot + wheel_2_x_dot)) * 0.5F;
            THA_VC_Ref_B.veh_y_dot_all[veh_theta_dot_all_tmp] = ((wheel_1_y_dot
              + wheel_2_y_dot) - (THA_VC_Ref_B.wheel_pos[veh_x_dot_tmp] +
                                  THA_VC_Ref_B.wheel_pos[wheel_2_x_dot_tmp]) *
              THA_VC_Ref_B.veh_theta_dot_all[veh_theta_dot_all_tmp]) * 0.5F;
          }
        } else {
          /* We found error this means pair is useless */
        }
      } else {
        /* We found error this means pair is useless */
      }
    }

    if (0 == (int32_T)valid_combos) {
      /* We cannot do anything, throw error!! */
      THA_VC_Ref_B.veh_x_dot = 0.0F;
      THA_VC_Ref_B.veh_y_dot = 0.0F;
      THA_VC_Ref_B.veh_theta_dot = 0.0F;
      THA_VC_Ref_B.km_err = 1U;
    } else {
      THA_VC_Ref_B.veh_x_dot = 0.0F;
      THA_VC_Ref_B.veh_y_dot = 0.0F;
      THA_VC_Ref_B.veh_theta_dot = 0.0F;
      for (i = 1; i - 1 < (int32_T)valid_combos; i++) {
        veh_x_dot_tmp = (int32_T)(uint8_T)i - 1;
        THA_VC_Ref_B.veh_x_dot += THA_VC_Ref_B.veh_x_dot_all[veh_x_dot_tmp];
        THA_VC_Ref_B.veh_y_dot += THA_VC_Ref_B.veh_y_dot_all[veh_x_dot_tmp];
        THA_VC_Ref_B.veh_theta_dot +=
          THA_VC_Ref_B.veh_theta_dot_all[veh_x_dot_tmp];
      }

      THA_VC_Ref_B.veh_x_dot /= (real32_T)valid_combos;
      THA_VC_Ref_B.veh_y_dot /= (real32_T)valid_combos;
      THA_VC_Ref_B.veh_theta_dot /= (real32_T)valid_combos;
      THA_VC_Ref_B.km_err = 0U;
    }

    /* End of MATLAB Function: '<S36>/Forward_Kinematics_Model1' */

    /* Product: '<S69>/Product1' */
    /* { */
    /* function pairs = generatePairs(n) */
    /* n=uint8(4); */
    /* pairs = zeros(n*(n-1)/2,2); */
    /* index = 0; */
    /*     for i = 1:n */
    /*         for j = i+1:n */
    /*             index = index + 1; */
    /*             pairs(index,:) = [i, j]; */
    /*         end */
    /*     end */
    /* end */
    /* } */
    THA_VC_Ref_B.integrator_external_saturation_table =
      THA_VC_Ref_B.tick_speed_RR * THA_VC_Ref_ConstB.alpha;

    /* DataTypeConversion: '<S10>/Data Type Conversion28' */
    THA_VC_Ref_B.DataTypeConversion1_dyy3 = THA_VC_Ref_B.MeTHA_b_VCActive ?
      (uint8_T)1 : (uint8_T)0;

    /* Logic: '<S36>/OR' incorporates:
     *  Constant: '<S36>/Constant1'
     */
    THA_VC_Ref_B.OR = (((int32_T)((uint8_T)0U) != 0) || ((int32_T)
      THA_VC_Ref_B.DataTypeConversion1_dyy3 != 0));

    /* Delay: '<S36>/Delay One Step' */
    THA_VC_Ref_B.LogicalOperator6 = THA_VC_Ref_DW.DelayOneStep_DSTATE;

    /* Logic: '<S36>/Logical Operator1' */
    THA_VC_Ref_B.LogicalOperator6 = !THA_VC_Ref_B.LogicalOperator6;

    /* Logic: '<S36>/Logical Operator' */
    THA_VC_Ref_B.LogicalOperator = (THA_VC_Ref_B.OR &&
      THA_VC_Ref_B.LogicalOperator6);

    /* Delay: '<S69>/Delay' */
    if (THA_VC_Ref_B.LogicalOperator && ((uint32_T)
         THA_VC_Ref_PrevZCX.Delay_Reset_ZCE != POS_ZCSIG)) {
      THA_VC_Ref_DW.Delay_DSTATE = 0.0F;
    }

    THA_VC_Ref_PrevZCX.Delay_Reset_ZCE = THA_VC_Ref_B.LogicalOperator ?
      (ZCSigState)1 : (ZCSigState)0;
    THA_VC_Ref_B.Delay = THA_VC_Ref_DW.Delay_DSTATE;

    /* End of Delay: '<S69>/Delay' */

    /* Product: '<S69>/Product' */
    THA_VC_Ref_B.Dgain = THA_VC_Ref_B.Delay * THA_VC_Ref_ConstB.one_minus_alpha;

    /* Sum: '<S69>/Sum' */
    THA_VC_Ref_B.Sum = THA_VC_Ref_B.integrator_external_saturation_table +
      THA_VC_Ref_B.Dgain;

    /* Product: '<S70>/Product1' */
    THA_VC_Ref_B.Dgain = THA_VC_Ref_B.tick_speed_RF *
      THA_VC_Ref_ConstB.alpha_kmmg;

    /* Delay: '<S70>/Delay' */
    if (THA_VC_Ref_B.LogicalOperator && ((uint32_T)
         THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_pnvs != POS_ZCSIG)) {
      THA_VC_Ref_DW.Delay_DSTATE_lu4u = 0.0F;
    }

    THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_pnvs = THA_VC_Ref_B.LogicalOperator ?
      (ZCSigState)1 : (ZCSigState)0;
    THA_VC_Ref_B.Delay_kfuy = THA_VC_Ref_DW.Delay_DSTATE_lu4u;

    /* End of Delay: '<S70>/Delay' */

    /* Product: '<S70>/Product' */
    THA_VC_Ref_B.integrator_external_saturation_table = THA_VC_Ref_B.Delay_kfuy *
      THA_VC_Ref_ConstB.one_minus_alpha_byr0;

    /* Sum: '<S70>/Sum' */
    THA_VC_Ref_B.Sum_pkps = THA_VC_Ref_B.Dgain +
      THA_VC_Ref_B.integrator_external_saturation_table;

    /* Product: '<S71>/Product1' */
    THA_VC_Ref_B.Dgain = THA_VC_Ref_B.tick_speed_LF *
      THA_VC_Ref_ConstB.alpha_poul;

    /* Delay: '<S71>/Delay' */
    if (THA_VC_Ref_B.LogicalOperator && ((uint32_T)
         THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_cdhr != POS_ZCSIG)) {
      THA_VC_Ref_DW.Delay_DSTATE_psr1 = 0.0F;
    }

    THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_cdhr = THA_VC_Ref_B.LogicalOperator ?
      (ZCSigState)1 : (ZCSigState)0;
    THA_VC_Ref_B.Delay_irja = THA_VC_Ref_DW.Delay_DSTATE_psr1;

    /* End of Delay: '<S71>/Delay' */

    /* Product: '<S71>/Product' */
    THA_VC_Ref_B.integrator_external_saturation_table = THA_VC_Ref_B.Delay_irja *
      THA_VC_Ref_ConstB.one_minus_alpha_iwdm;

    /* Sum: '<S71>/Sum' */
    THA_VC_Ref_B.Sum_jqym = THA_VC_Ref_B.Dgain +
      THA_VC_Ref_B.integrator_external_saturation_table;

    /* Product: '<S72>/Product1' */
    THA_VC_Ref_B.Dgain = THA_VC_Ref_B.tick_speed_LR *
      THA_VC_Ref_ConstB.alpha_dyf4;

    /* Delay: '<S72>/Delay' */
    if (THA_VC_Ref_B.LogicalOperator && ((uint32_T)
         THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_kvqh != POS_ZCSIG)) {
      THA_VC_Ref_DW.Delay_DSTATE_nkk5 = 0.0F;
    }

    THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_kvqh = THA_VC_Ref_B.LogicalOperator ?
      (ZCSigState)1 : (ZCSigState)0;
    THA_VC_Ref_B.Delay_o4cj = THA_VC_Ref_DW.Delay_DSTATE_nkk5;

    /* End of Delay: '<S72>/Delay' */

    /* Product: '<S72>/Product' */
    THA_VC_Ref_B.integrator_external_saturation_table = THA_VC_Ref_B.Delay_o4cj *
      THA_VC_Ref_ConstB.one_minus_alpha_ozv1;

    /* Sum: '<S72>/Sum' */
    THA_VC_Ref_B.Sum_fdny = THA_VC_Ref_B.Dgain +
      THA_VC_Ref_B.integrator_external_saturation_table;

    /* MATLAB Function: '<S36>/Tick_WhlSpeed_Merger' */
    THA_VC_Ref_B.tickSpeed[0] = THA_VC_Ref_B.Sum;
    THA_VC_Ref_B.tickSpeed[1] = THA_VC_Ref_B.Sum_pkps;
    THA_VC_Ref_B.tickSpeed[2] = THA_VC_Ref_B.Sum_jqym;
    THA_VC_Ref_B.tickSpeed[3] = THA_VC_Ref_B.Sum_fdny;

    /* DataTypeConversion: '<S10>/Data Type Conversion37' */
    THA_VC_Ref_B.DataTypeConversion37 = THA_VC_Ref_B.Saturation6;

    /* DataTypeConversion: '<S10>/Data Type Conversion38' */
    THA_VC_Ref_B.DataTypeConversion38 = THA_VC_Ref_B.Saturation5;

    /* DataTypeConversion: '<S10>/Data Type Conversion39' */
    THA_VC_Ref_B.DataTypeConversion39 = THA_VC_Ref_B.Saturation4;

    /* DataTypeConversion: '<S10>/Data Type Conversion22' */
    THA_VC_Ref_B.DataTypeConversion22 = THA_VC_Ref_B.Saturation3;

    /* MATLAB Function: '<S36>/CAN_WhlSpeed_Merger1' */
    THA_VC_Ref_B.wheelSpeeds_ckym[0] = 0.277777791F *
      THA_VC_Ref_B.DataTypeConversion37;
    THA_VC_Ref_B.wheelSpeeds_ckym[1] = 0.277777791F *
      THA_VC_Ref_B.DataTypeConversion38;
    THA_VC_Ref_B.wheelSpeeds_ckym[2] = 0.277777791F *
      THA_VC_Ref_B.DataTypeConversion39;
    THA_VC_Ref_B.wheelSpeeds_ckym[3] = 0.277777791F *
      THA_VC_Ref_B.DataTypeConversion22;
    if (2 != (int32_T)THA_VC_Ref_B.DataTypeConversion21) {
      THA_VC_Ref_B.wheelSpeeds_ckym[0] = -THA_VC_Ref_B.wheelSpeeds_ckym[0];
      THA_VC_Ref_B.wheelSpeeds_ckym[1] = -THA_VC_Ref_B.wheelSpeeds_ckym[1];
      THA_VC_Ref_B.wheelSpeeds_ckym[2] = -THA_VC_Ref_B.wheelSpeeds_ckym[2];
      THA_VC_Ref_B.wheelSpeeds_ckym[3] = -THA_VC_Ref_B.wheelSpeeds_ckym[3];
    }

    /* End of MATLAB Function: '<S36>/CAN_WhlSpeed_Merger1' */

    /* SignalConversion: '<S36>/Signal Copy' */
    /* 0.14 is speed treshold in mps */
    THA_VC_Ref_B.SignalCopy[0] = THA_VC_Ref_B.wheelSpeeds_ckym[0];

    /* MATLAB Function: '<S36>/MATLAB Function' */
    if (fabsf(THA_VC_Ref_B.SignalCopy[0]) < 0.14F) {
      THA_VC_Ref_B.WhlSpeed[0] = THA_VC_Ref_B.tickSpeed[0];
    } else if ((int32_T)THA_VC_Ref_ConstB.DataTypeConversion36 != 1) {
      THA_VC_Ref_B.WhlSpeed[0] = THA_VC_Ref_B.tickSpeed[0];
    } else {
      THA_VC_Ref_B.WhlSpeed[0] = THA_VC_Ref_B.SignalCopy[0];
    }

    /* SignalConversion: '<S36>/Signal Copy' */
    THA_VC_Ref_B.SignalCopy[1] = THA_VC_Ref_B.wheelSpeeds_ckym[1];

    /* MATLAB Function: '<S36>/MATLAB Function' */
    if (fabsf(THA_VC_Ref_B.SignalCopy[1]) < 0.14F) {
      THA_VC_Ref_B.WhlSpeed[1] = THA_VC_Ref_B.tickSpeed[1];
    } else if ((int32_T)THA_VC_Ref_ConstB.DataTypeConversion36 != 1) {
      THA_VC_Ref_B.WhlSpeed[1] = THA_VC_Ref_B.tickSpeed[1];
    } else {
      THA_VC_Ref_B.WhlSpeed[1] = THA_VC_Ref_B.SignalCopy[1];
    }

    /* SignalConversion: '<S36>/Signal Copy' */
    THA_VC_Ref_B.SignalCopy[2] = THA_VC_Ref_B.wheelSpeeds_ckym[2];

    /* MATLAB Function: '<S36>/MATLAB Function' */
    if (fabsf(THA_VC_Ref_B.SignalCopy[2]) < 0.14F) {
      THA_VC_Ref_B.WhlSpeed[2] = THA_VC_Ref_B.tickSpeed[2];
    } else if ((int32_T)THA_VC_Ref_ConstB.DataTypeConversion36 != 1) {
      THA_VC_Ref_B.WhlSpeed[2] = THA_VC_Ref_B.tickSpeed[2];
    } else {
      THA_VC_Ref_B.WhlSpeed[2] = THA_VC_Ref_B.SignalCopy[2];
    }

    /* SignalConversion: '<S36>/Signal Copy' */
    THA_VC_Ref_B.SignalCopy[3] = THA_VC_Ref_B.wheelSpeeds_ckym[3];

    /* MATLAB Function: '<S36>/MATLAB Function' */
    if (fabsf(THA_VC_Ref_B.SignalCopy[3]) < 0.14F) {
      THA_VC_Ref_B.WhlSpeed[3] = THA_VC_Ref_B.tickSpeed[3];
    } else if ((int32_T)THA_VC_Ref_ConstB.DataTypeConversion36 != 1) {
      THA_VC_Ref_B.WhlSpeed[3] = THA_VC_Ref_B.tickSpeed[3];
    } else {
      THA_VC_Ref_B.WhlSpeed[3] = THA_VC_Ref_B.SignalCopy[3];
    }

    /* MATLAB Function: '<S36>/Forward_Kinematics_Model' */
    /* Explanation */
    /* { */
    /* wheel_num is integer denoting number of wheels in our configration */
    /* wheel_pos is 2 x n matrix with first row being xpos of wheel and 2nd row is y pos of wheel */
    /* Special Note: wheel pos should be denifed relative to the point which we consider are reference point for overall vehicle body motion */
    /* this means that lets say you select rear axel center as refrence point then x coord of rear wheel should be 0, but if you select */
    /* front axel as refrence point then x coord of rear axel should be -wheelbase */
    /* wheel_radius is 1 x n matrix denoting the radius of individual wheel in meter */
    /* wheel_spin is 1 x n matrix consisting of individual wheel_spins in rad/s */
    /* wheel_theta is 1 x n matrix consisting of individual wheel_spins in rad */
    /*  */
    /* veh_x_dot is same as vehicle's longitudinal velocity */
    /* veh_y_dot is same as vehicle's lateral velocity */
    /* veh_theta_dot is same as vehicle's yaw rate */
    /* } */
    /* temp variables used for in loop calculations */
    valid_combos = 0U;
    for (i = 0; i < 6; i++) {
      THA_VC_Ref_B.veh_x_dot_all_cx3j[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      THA_VC_Ref_B.veh_y_dot_all_mkvv[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      THA_VC_Ref_B.veh_theta_dot_all_mtc1[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      THA_VC_Ref_B.wheel_status_index1 = THA_VC_Ref_DW.wheel_pairs_etgb[i];
      THA_VC_Ref_B.wheel_status_index2_tmp = THA_VC_Ref_DW.wheel_pairs_etgb[i +
        6];
      THA_VC_Ref_B.wheel_status_index2 = THA_VC_Ref_B.wheel_status_index2_tmp;
      if (THA_VC_Ref_DW.wheel_pairs_etgb[i] > 4.0) {
        THA_VC_Ref_B.wheel_status_index1 = 4.0;
      }

      if (THA_VC_Ref_B.wheel_status_index2_tmp > 4.0) {
        THA_VC_Ref_B.wheel_status_index2 = 4.0;
      }

      veh_x_dot_tmp = (int32_T)THA_VC_Ref_B.wheel_status_index1 - 1;
      if ((THA_VC_Ref_B.status[veh_x_dot_tmp] != THA_VC_Ref_DW.error_n0hy) &&
          (THA_VC_Ref_B.status[(int32_T)THA_VC_Ref_B.wheel_status_index2_tmp - 1]
           != THA_VC_Ref_DW.error_n0hy)) {
        wheel_1_x_dot = THA_VC_Ref_B.WhlSpeed[veh_x_dot_tmp] * cosf
          (THA_VC_Ref_B.Gain13[veh_x_dot_tmp]);
        wheel_2_x_dot_tmp = (int32_T)THA_VC_Ref_B.wheel_status_index2 - 1;
        wheel_2_x_dot = THA_VC_Ref_B.WhlSpeed[wheel_2_x_dot_tmp] * cosf
          (THA_VC_Ref_B.Gain13[wheel_2_x_dot_tmp]);
        wheel_1_y_dot = THA_VC_Ref_B.WhlSpeed[veh_x_dot_tmp] * sinf
          (THA_VC_Ref_B.Gain13[veh_x_dot_tmp]);
        wheel_2_y_dot = THA_VC_Ref_B.WhlSpeed[wheel_2_x_dot_tmp] * sinf
          (THA_VC_Ref_B.Gain13[wheel_2_x_dot_tmp]);
        wheel_2_x_dot_tmp <<= (uint32_T)1;
        veh_x_dot_tmp <<= (uint32_T)1;
        tmp = (wheel_2_x_dot_tmp + (int32_T)THA_VC_Ref_DW.y_eojm) - 1;
        tmp_0 = (veh_x_dot_tmp + (int32_T)THA_VC_Ref_DW.y_eojm) - 1;
        if ((THA_VC_Ref_B.wheel_pos[tmp] == THA_VC_Ref_B.wheel_pos[tmp_0]) &&
            (THA_VC_Ref_B.wheel_pos[(wheel_2_x_dot_tmp + (int32_T)
              THA_VC_Ref_DW.x_mu1j) - 1] == THA_VC_Ref_B.wheel_pos
             [(veh_x_dot_tmp + (int32_T)THA_VC_Ref_DW.x_mu1j) - 1])) {
          /* You entered same wheel twice as both co-ordinates are same, code */
          /* needs to throw error here indicated the user that they are at */
          /* fault and what fault exactly is */
        } else {
          valid_combos = (uint8_T)(int32_T)((int32_T)valid_combos + 1);
          if ((int32_T)valid_combos > 6) {
            valid_combos = 6U;
          }

          /* Here last elseif is not really required but added just for extra precaution */
          veh_x_dot_tmp = ((((int32_T)THA_VC_Ref_B.wheel_status_index1 - 1) <<
                            (uint32_T)1) + (int32_T)THA_VC_Ref_DW.x_mu1j) - 1;
          wheel_2_x_dot_tmp = ((((int32_T)THA_VC_Ref_B.wheel_status_index2 - 1) <<
                                (uint32_T)1) + (int32_T)THA_VC_Ref_DW.x_mu1j) -
            1;
          v = THA_VC_Ref_B.wheel_pos[veh_x_dot_tmp] -
            THA_VC_Ref_B.wheel_pos[wheel_2_x_dot_tmp];
          guard1 = false;
          if (v != 0.0F) {
            tmp_1 = THA_VC_Ref_B.wheel_pos[tmp] - THA_VC_Ref_B.wheel_pos[tmp_0];
            if (tmp_1 != 0.0F) {
              veh_theta_dot_all_tmp = (int32_T)valid_combos - 1;
              THA_VC_Ref_B.veh_theta_dot_all_mtc1[veh_theta_dot_all_tmp] =
                (wheel_1_y_dot - wheel_2_y_dot) / v * 0.5F;
              THA_VC_Ref_B.veh_theta_dot_all_mtc1[veh_theta_dot_all_tmp] +=
                (wheel_1_x_dot - wheel_2_x_dot) / tmp_1 * 0.5F;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            if (v != 0.0F) {
              THA_VC_Ref_B.veh_theta_dot_all_mtc1[(int32_T)valid_combos - 1] =
                (wheel_1_y_dot - wheel_2_y_dot) /
                (THA_VC_Ref_B.wheel_pos[veh_x_dot_tmp] -
                 THA_VC_Ref_B.wheel_pos[wheel_2_x_dot_tmp]);
            } else if (THA_VC_Ref_B.wheel_pos[tmp] -
                       THA_VC_Ref_B.wheel_pos[tmp_0] != 0.0F) {
              THA_VC_Ref_B.veh_theta_dot_all_mtc1[(int32_T)valid_combos - 1] =
                (wheel_1_x_dot - wheel_2_x_dot) / (THA_VC_Ref_B.wheel_pos[tmp] -
                THA_VC_Ref_B.wheel_pos[tmp_0]);
            } else {
              /* Default value is already 0 so no need to write extra code. */
            }
          }

          veh_theta_dot_all_tmp = (int32_T)valid_combos - 1;
          THA_VC_Ref_B.veh_x_dot_all_cx3j[veh_theta_dot_all_tmp] =
            ((THA_VC_Ref_B.wheel_pos[tmp_0] + THA_VC_Ref_B.wheel_pos[tmp]) *
             THA_VC_Ref_B.veh_theta_dot_all_mtc1[veh_theta_dot_all_tmp] +
             (wheel_1_x_dot + wheel_2_x_dot)) * 0.5F;
          THA_VC_Ref_B.veh_y_dot_all_mkvv[veh_theta_dot_all_tmp] =
            ((wheel_1_y_dot + wheel_2_y_dot) -
             (THA_VC_Ref_B.wheel_pos[veh_x_dot_tmp] +
              THA_VC_Ref_B.wheel_pos[wheel_2_x_dot_tmp]) *
             THA_VC_Ref_B.veh_theta_dot_all_mtc1[veh_theta_dot_all_tmp]) * 0.5F;
        }
      } else {
        /* We found error this means pair is useless */
      }
    }

    if (0 == (int32_T)valid_combos) {
      /* We cannot do anything, throw error!! */
      THA_VC_Ref_B.veh_x_dot_nnwm = 0.0F;
      THA_VC_Ref_B.veh_y_dot_p3vd = 0.0F;
      THA_VC_Ref_B.veh_theta_dot_ktag = 0.0F;
    } else {
      wheel_2_x_dot = 0.0F;
      wheel_1_x_dot = 0.0F;
      v = 0.0F;
      for (i = 1; i - 1 < (int32_T)valid_combos; i++) {
        veh_x_dot_tmp = (int32_T)(uint8_T)i - 1;
        wheel_2_x_dot += THA_VC_Ref_B.veh_x_dot_all_cx3j[veh_x_dot_tmp];
        wheel_1_x_dot += THA_VC_Ref_B.veh_y_dot_all_mkvv[veh_x_dot_tmp];
        v += THA_VC_Ref_B.veh_theta_dot_all_mtc1[veh_x_dot_tmp];
      }

      THA_VC_Ref_B.veh_x_dot_nnwm = wheel_2_x_dot / (real32_T)valid_combos;
      THA_VC_Ref_B.veh_y_dot_p3vd = wheel_1_x_dot / (real32_T)valid_combos;
      THA_VC_Ref_B.veh_theta_dot_ktag = v / (real32_T)valid_combos;
    }

    /* End of MATLAB Function: '<S36>/Forward_Kinematics_Model' */

    /* MATLAB Function: '<S36>/Inst_Vel_Merger' */
    /* { */
    /* function pairs = generatePairs(n) */
    /* n=uint8(4); */
    /* pairs = zeros(n*(n-1)/2,2); */
    /* index = 0; */
    /*     for i = 1:n */
    /*         for j = i+1:n */
    /*             index = index + 1; */
    /*             pairs(index,:) = [i, j]; */
    /*         end */
    /*     end */
    /* end */
    /* } */
    THA_VC_Ref_B.merger[0] = THA_VC_Ref_B.veh_x_dot_nnwm;
    THA_VC_Ref_B.merger[1] = THA_VC_Ref_B.veh_y_dot_p3vd;
    THA_VC_Ref_B.merger[2] = THA_VC_Ref_B.veh_theta_dot_ktag;

    /* MATLAB Function: '<S36>/Compute_Dead_Reckoning' */
    if (THA_VC_Ref_B.LogicalOperator) {
      THA_VC_Ref_DW.last_pos[0] = 0.0F;
      THA_VC_Ref_DW.last_pos[1] = 0.0F;
      THA_VC_Ref_DW.last_pos[2] = 0.0F;
    }

    THA_VC_Ref_B.theta = THA_VC_Ref_B.merger[2] *
      THA_VC_Ref_ConstB.DataTypeConversion27 + THA_VC_Ref_DW.last_pos[2];

    /* Commented due to issues with LPF during -pi to pi transition */
    /* current_pos(3) = mod_2pi(current_pos(3)); */
    THA_VC_Ref_B.x = cosf(THA_VC_Ref_B.theta) * THA_VC_Ref_B.merger[0] *
      THA_VC_Ref_ConstB.DataTypeConversion27 + THA_VC_Ref_DW.last_pos[0];
    THA_VC_Ref_B.y = sinf(THA_VC_Ref_B.theta) * THA_VC_Ref_B.merger[0] *
      THA_VC_Ref_ConstB.DataTypeConversion27 + THA_VC_Ref_DW.last_pos[1];
    THA_VC_Ref_DW.last_pos[0] = THA_VC_Ref_B.x;
    THA_VC_Ref_DW.last_pos[1] = THA_VC_Ref_B.y;
    THA_VC_Ref_DW.last_pos[2] = THA_VC_Ref_B.theta;

    /* End of MATLAB Function: '<S36>/Compute_Dead_Reckoning' */

    /* Product: '<S75>/Product1' */
    THA_VC_Ref_B.Dgain = THA_VC_Ref_B.theta * THA_VC_Ref_ConstB.alpha_f52f;

    /* Delay: '<S75>/Delay' */
    if (THA_VC_Ref_B.LogicalOperator && ((uint32_T)
         THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_cqgx != POS_ZCSIG)) {
      THA_VC_Ref_DW.Delay_DSTATE_pwdf = 0.0F;
    }

    THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_cqgx = THA_VC_Ref_B.LogicalOperator ?
      (ZCSigState)1 : (ZCSigState)0;
    THA_VC_Ref_B.Delay_oetc = THA_VC_Ref_DW.Delay_DSTATE_pwdf;

    /* End of Delay: '<S75>/Delay' */

    /* Product: '<S75>/Product' */
    THA_VC_Ref_B.integrator_external_saturation_table = THA_VC_Ref_B.Delay_oetc *
      THA_VC_Ref_ConstB.one_minus_alpha_l2zc;

    /* Sum: '<S75>/Sum' */
    THA_VC_Ref_B.Sum_d1um = THA_VC_Ref_B.Dgain +
      THA_VC_Ref_B.integrator_external_saturation_table;

    /* Gain: '<S36>/Gain' */
    THA_VC_Ref_B.Gain = 57.2957802F * THA_VC_Ref_B.Sum_d1um;

    /* MATLAB Function: '<S36>/MATLAB Function4' */
    THA_VC_Ref_B.heading_MABx = THA_VC_Ref_B.Gain;

    /*  heading angle is between -180 and 180 */
    if (THA_VC_Ref_B.Gain < -180.0F) {
      THA_VC_Ref_B.heading_MABx = THA_VC_Ref_B.Gain + 360.0F;
    }

    if (THA_VC_Ref_B.heading_MABx > 180.0F) {
      THA_VC_Ref_B.heading_MABx -= 360.0F;
    }

    /* End of MATLAB Function: '<S36>/MATLAB Function4' */

    /* Sum: '<S10>/Rpt_Ydiff' */
    THA_VC_Ref_B.Rpt_Ydiff = THA_VC_Ref_B.DifferenceInputs2_jov4 -
      THA_VC_Ref_B.MeTHA_Pnt_HitchPnt[0];

    /* Sum: '<S10>/Rpt_Xdiff' */
    THA_VC_Ref_B.Rpt_Xdiff_hala =
      THA_VC_Ref_B.OutportBufferForMeTHA_pixel_HitchLocationY -
      THA_VC_Ref_B.DifferenceInputs2_lsrk;

    /* Math: '<S36>/Square' */
    THA_VC_Ref_B.Dgain = THA_VC_Ref_B.veh_x_dot_nnwm *
      THA_VC_Ref_B.veh_x_dot_nnwm;

    /* Math: '<S36>/Square1' */
    THA_VC_Ref_B.integrator_external_saturation_table =
      THA_VC_Ref_B.veh_y_dot_p3vd * THA_VC_Ref_B.veh_y_dot_p3vd;

    /* Sum: '<S36>/Add' */
    THA_VC_Ref_B.Dgain += THA_VC_Ref_B.integrator_external_saturation_table;

    /* Sqrt: '<S36>/Square Root' */
    THA_VC_Ref_B.SquareRoot = sqrtf(THA_VC_Ref_B.Dgain);

    /* DataTypeConversion: '<S10>/Data Type Conversion8' */
    THA_VC_Ref_B.Dgain = THA_VC_Ref_B.SquareRoot;

    /* Abs: '<S10>/Abs1' */
    THA_VC_Ref_B.MeTHA_mps_KMSpeed_FW = fabsf(THA_VC_Ref_B.Dgain);

    /* UnitDelay: '<S38>/Unit Delay' */
    THA_VC_Ref_B.Dgain = THA_VC_Ref_DW.UnitDelay_DSTATE_dk0c;

    /* UnitDelay: '<S38>/Unit Delay1' */
    THA_VC_Ref_B.UnitDelay1 = THA_VC_Ref_DW.UnitDelay1_DSTATE;

    /* UnitDelay: '<S38>/Unit Delay2' */
    THA_VC_Ref_B.UnitDelay2 = THA_VC_Ref_DW.UnitDelay2_DSTATE;

    /* UnitDelay: '<S38>/Unit Delay3' */
    THA_VC_Ref_B.integrator_external_saturation_table =
      THA_VC_Ref_DW.UnitDelay3_DSTATE_ogzh;

    /* Sum: '<S38>/Add1' */
    THA_VC_Ref_B.Dgain = (((THA_VC_Ref_B.MeTHA_mps_KMSpeed_FW +
      THA_VC_Ref_B.Dgain) + THA_VC_Ref_B.UnitDelay1) + THA_VC_Ref_B.UnitDelay2)
      + THA_VC_Ref_B.integrator_external_saturation_table;

    /* Gain: '<S38>/Gain2' */
    THA_VC_Ref_B.Gain2 = 0.2F * THA_VC_Ref_B.Dgain;

    /* Outputs for Atomic SubSystem: '<S10>/STR_Control' */
    /* DataTypeConversion: '<S40>/Data Type Conversion' */
    THA_VC_Ref_B.DataTypeConversion = (real32_T)THA_VC_Ref_B.Rpt_Xdiff_hala;

    /* Abs: '<S40>/Abs' incorporates:
     *  Abs: '<S40>/Abs1'
     *  Switch: '<S40>/Switch'
     */
    v = fabsf(THA_VC_Ref_B.DataTypeConversion);
    THA_VC_Ref_B.Add1_jabu = v;

    /* S-Function (sfix_look1_dyn): '<S40>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S40>/Constant2'
     */
    /* Dynamic Look-Up Table Block: '<S40>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real32_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUpEven_real32_T_real32_T( &(THA_VC_Ref_B.LookupTableDynamic),
      &rtu_MbTHA_VrntTunParamOutData->KsTHA_k_ErrxPropGainTD[0],
      THA_VC_Ref_B.Add1_jabu, 0.0F, 4U, 50.0F);

    /* Constant: '<S40>/Constant1' */
    THA_VC_Ref_B.Add1_jabu = KeTHA_b_EnblTrlrAngStrTrqCalc ? 1.0F : 0.0F;

    /* DataTypeConversion: '<S40>/Data Type Conversion1' */
    THA_VC_Ref_B.DataTypeConversion1_dyy3 = (uint8_T)THA_VC_Ref_B.Add1_jabu;

    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Constant'
     */
    if ((int32_T)THA_VC_Ref_B.DataTypeConversion1_dyy3 != 0) {
      /* DataTypeConversion: '<S10>/Data Type Conversion4' */
      THA_VC_Ref_B.Add1 = (real32_T)THA_VC_Ref_B.Rpt_Xdiff_hala;

      /* DataTypeConversion: '<S10>/Data Type Conversion3' */
      THA_VC_Ref_B.Abs1_izan = (real32_T)THA_VC_Ref_B.Rpt_Ydiff;

      /* Trigonometry: '<S10>/Atan2' */
      THA_VC_Ref_B.Abs1_izan = atan2f(THA_VC_Ref_B.Abs1_izan, THA_VC_Ref_B.Add1);

      /* Gain: '<S34>/Gain' */
      THA_VC_Ref_B.Abs1_izan *= 57.2957802F;

      /* DataTypeConversion: '<S10>/Data Type Conversion5' */
      THA_VC_Ref_B.Add1 = THA_VC_Ref_B.heading_MABx;

      /* Sum: '<S10>/Add' */
      THA_VC_Ref_B.Add1 += MeTHA_deg_RelAngle;

      /* Sum: '<S40>/Add1' */
      THA_VC_Ref_B.Add1 -= THA_VC_Ref_B.Abs1_izan;

      /* Abs: '<S40>/Abs1' */
      THA_VC_Ref_B.Abs1_izan = v;

      /* S-Function (sfix_look1_dyn): '<S40>/Lookup Table Dynamic1' incorporates:
       *  Constant: '<S40>/Constant3'
       */
      /* Dynamic Look-Up Table Block: '<S40>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real32_T
       * Input1  Data Type:  Floating Point real32_T
       * Input2  Data Type:  Floating Point real32_T
       * Output0 Data Type:  Floating Point real32_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real32_T_real32_T( &(THA_VC_Ref_B.LookupTableDynamic1),
        &rtu_MbTHA_VrntTunParamOutData->KsTHA_k_ErrxHeadingErrTD[0],
        THA_VC_Ref_B.Abs1_izan, THA_VC_Ref_ConstP.Constant3_Value, 3U);

      /* Product: '<S40>/Product' */
      THA_VC_Ref_B.Product = THA_VC_Ref_B.Add1 *
        THA_VC_Ref_B.LookupTableDynamic1;
      THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.Product;
    } else {
      THA_VC_Ref_B.Add1_jabu = 0.0F;
    }

    /* Product: '<S40>/Product3' */
    THA_VC_Ref_B.Add1_jabu *=
      rtu_MbTHA_VrntTunParamOutData->KeTHA_k_HeadingErrGain;

    /* UnitDelay: '<S84>/Delay Input2'
     *
     * Block description for '<S84>/Delay Input2':
     *
     *  Store in Global RAM
     */
    THA_VC_Ref_B.Yk1_oc1t = THA_VC_Ref_DW.DelayInput2_DSTATE_mkva;

    /* Constant: '<S40>/Constant4' */
    THA_VC_Ref_B.Square3 = KeTHA_b_SpdCndEnable ? 1.0F : 0.0F;

    /* DataTypeConversion: '<S40>/Data Type Conversion2' */
    THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.Square3 != 0.0F);

    /* Switch: '<S40>/Switch2' incorporates:
     *  Constant: '<S40>/Constant5'
     */
    if (THA_VC_Ref_B.LogicalOperator6) {
      /* RelationalOperator: '<S81>/Compare' incorporates:
       *  Constant: '<S81>/Constant'
       */
      THA_VC_Ref_B.Compare_hqzm = (THA_VC_Ref_B.Gain2 >= KeTHA_mps_SpdThreshold);
      THA_VC_Ref_B.LogicalOperator6 = THA_VC_Ref_B.Compare_hqzm;
    } else {
      THA_VC_Ref_B.LogicalOperator6 = true;
    }

    /* End of Switch: '<S40>/Switch2' */

    /* RelationalOperator: '<S82>/Compare' incorporates:
     *  Constant: '<S82>/Constant'
     */
    THA_VC_Ref_B.Compare = ((int32_T)(THA_VC_Ref_B.MeTHA_b_VCActive ? 1 : 0) >
      (int32_T)(false ? 1 : 0));

    /* Product: '<S40>/Product2' */
    THA_VC_Ref_B.Square3 = THA_VC_Ref_B.LookupTableDynamic *
      rtu_MbTHA_VrntTunParamOutData->KeTHA_k_SteerTrqCtrlKp;

    /* Product: '<S120>/PProd Out' */
    THA_VC_Ref_B.Dgain = (real32_T)THA_VC_Ref_B.Rpt_Ydiff * THA_VC_Ref_B.Square3;

    /* DiscreteIntegrator: '<S115>/Integrator' */
    THA_VC_Ref_B.Square3 = THA_VC_Ref_DW.Integrator_DSTATE;

    /* Product: '<S109>/DProd Out' */
    THA_VC_Ref_B.integrator_external_saturation_table = (real32_T)
      THA_VC_Ref_B.Rpt_Ydiff *
      rtu_MbTHA_VrntTunParamOutData->KeTHA_k_SteerTrqCtrlKd;

    /* DiscreteIntegrator: '<S110>/Filter' */
    THA_VC_Ref_B.Filter = THA_VC_Ref_DW.Filter_DSTATE;

    /* Sum: '<S110>/SumD' */
    THA_VC_Ref_B.integrator_external_saturation_table -= THA_VC_Ref_B.Filter;

    /* Product: '<S118>/NProd Out' */
    THA_VC_Ref_B.NProdOut = THA_VC_Ref_B.integrator_external_saturation_table *
      rtu_MbTHA_VrntTunParamOutData->KeTHA_k_SteerTrqCtrlFiltCoef;

    /* Sum: '<S124>/Sum' */
    THA_VC_Ref_B.Dgain = (THA_VC_Ref_B.Dgain + THA_VC_Ref_B.Square3) +
      THA_VC_Ref_B.NProdOut;

    /* Saturate: '<S40>/StrAngleLimits' */
    if (THA_VC_Ref_B.Dgain > KeTHA_deg_UpperSteeringAngLim) {
      THA_VC_Ref_B.StrAngleLimits = KeTHA_deg_UpperSteeringAngLim;
    } else if (THA_VC_Ref_B.Dgain < KeTHA_deg_LowerSteeringAngLim) {
      THA_VC_Ref_B.StrAngleLimits = KeTHA_deg_LowerSteeringAngLim;
    } else {
      THA_VC_Ref_B.StrAngleLimits = THA_VC_Ref_B.Dgain;
    }

    /* End of Saturate: '<S40>/StrAngleLimits' */

    /* Sum: '<S40>/Add' */
    THA_VC_Ref_B.SWA_Error = THA_VC_Ref_B.StrAngleLimits -
      THA_VC_Ref_B.Saturation1;

    /* DiscreteIntegrator: '<S40>/Discrete_Time_Integrator1' */
    if ((THA_VC_Ref_B.Compare &&
         (THA_VC_Ref_DW.Discrete_Time_Integrator1_PrevResetState <= 0)) ||
        ((!THA_VC_Ref_B.Compare) &&
         (THA_VC_Ref_DW.Discrete_Time_Integrator1_PrevResetState == 1))) {
      THA_VC_Ref_DW.Discrete_Time_Integrator1_DSTATE = 0.0F;
    }

    THA_VC_Ref_B.Discrete_Time_Integrator1 =
      THA_VC_Ref_DW.Discrete_Time_Integrator1_DSTATE;

    /* End of DiscreteIntegrator: '<S40>/Discrete_Time_Integrator1' */

    /* DataTypeConversion: '<S40>/Data_Type_Conversion' */
    THA_VC_Ref_B.Data_Type_Conversion = (real32_T)
      rtu_MbTHA_VrntTunParamOutData->KeTHA_ddeg_StrRateLimInit;

    /* DataTypeConversion: '<S40>/Data_Type_Conversion1' */
    THA_VC_Ref_B.Data_Type_Conversion1 = (real32_T)
      rtu_MbTHA_VrntTunParamOutData->KeTHA_ddeg_StrRateLimFinal;

    /* MATLAB Function: '<S40>/determine_str_rate_limit' */
    /*  FUNCTION NAME: */
    /*    determine_str_rate_lim */
    /*  */
    /*  DESCRIPTION: */
    /*    Determines the maximum steering rate of the vehicle based on set */
    /*    conditions */
    /*  INPUT: */
    /*    u - (single) time passed since maneuvre started */
    /*    DataSpeedInitRL - (single) initial steering rate limit */
    /*    FinalRL - (single) final steering rate limit */
    /*  OUTPUT: */
    /*    rateLimit - (single) steering rate limit */
    /*  ASSUMPTIONS AND LIMITATIONS: */
    /*    None */
    /*  REVISION HISTORY: */
    /*    05/12/2022 - Abdulrahman Elgendy */
    /*        * Initial implementation */
    if (fabsf(THA_VC_Ref_B.SWA_Error) < 300.0F) {
      THA_VC_Ref_B.rateLimit = THA_VC_Ref_B.Data_Type_Conversion1;
    } else if (THA_VC_Ref_B.Discrete_Time_Integrator1 < 1.0F) {
      THA_VC_Ref_B.rateLimit = THA_VC_Ref_B.Data_Type_Conversion;

      /* DataSpeedInitRL; */
    } else {
      THA_VC_Ref_B.rateLimit = THA_VC_Ref_B.Data_Type_Conversion1;
    }

    /* End of MATLAB Function: '<S40>/determine_str_rate_limit' */

    /* Product: '<S40>/Product1' */
    THA_VC_Ref_B.Dgain = (THA_VC_Ref_B.LogicalOperator6 ? (real32_T)
                          (THA_VC_Ref_B.Compare ? 1.0F : 0.0F) : 0.0F) *
      THA_VC_Ref_B.rateLimit;

    /* SampleTimeMath: '<S84>/sample time'
     *
     * About '<S84>/sample time':
     *  y = K where K = ( w * Ts )
     */
    THA_VC_Ref_B.sampletime_m2db = 0.03F;

    /* Product: '<S84>/delta rise limit' */
    THA_VC_Ref_B.deltariselimit_az2v = THA_VC_Ref_B.Dgain *
      THA_VC_Ref_B.sampletime_m2db;

    /* Sum: '<S84>/Difference Inputs1'
     *
     * Block description for '<S84>/Difference Inputs1':
     *
     *  Add in CPU
     */
    THA_VC_Ref_B.UkYk1_lhs3 = THA_VC_Ref_B.StrAngleLimits -
      THA_VC_Ref_B.Yk1_oc1t;

    /* RelationalOperator: '<S130>/LowerRelop1' */
    THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.UkYk1_lhs3 >
      THA_VC_Ref_B.deltariselimit_az2v);

    /* Gain: '<S40>/Gain1' */
    THA_VC_Ref_B.Dgain *= (-1.0F);

    /* Product: '<S84>/delta fall limit' */
    THA_VC_Ref_B.deltafalllimit_embx = THA_VC_Ref_B.Dgain *
      THA_VC_Ref_B.sampletime_m2db;

    /* RelationalOperator: '<S130>/UpperRelop' */
    THA_VC_Ref_B.RelationalOperator6 = (THA_VC_Ref_B.UkYk1_lhs3 <
      THA_VC_Ref_B.deltafalllimit_embx);

    /* Switch: '<S130>/Switch' */
    if (THA_VC_Ref_B.RelationalOperator6) {
      THA_VC_Ref_B.Switch_irut = THA_VC_Ref_B.deltafalllimit_embx;
    } else {
      THA_VC_Ref_B.Switch_irut = THA_VC_Ref_B.UkYk1_lhs3;
    }

    /* End of Switch: '<S130>/Switch' */

    /* Switch: '<S130>/Switch2' */
    if (THA_VC_Ref_B.LogicalOperator6) {
      THA_VC_Ref_B.Switch2_ak0c = THA_VC_Ref_B.deltariselimit_az2v;
    } else {
      THA_VC_Ref_B.Switch2_ak0c = THA_VC_Ref_B.Switch_irut;
    }

    /* End of Switch: '<S130>/Switch2' */

    /* Sum: '<S84>/Difference Inputs2'
     *
     * Block description for '<S84>/Difference Inputs2':
     *
     *  Add in CPU
     */
    THA_VC_Ref_B.DifferenceInputs2_hyze = THA_VC_Ref_B.Switch2_ak0c +
      THA_VC_Ref_B.Yk1_oc1t;

    /* Sum: '<S40>/Add2' */
    THA_VC_Ref_B.Add1_jabu += THA_VC_Ref_B.DifferenceInputs2_hyze;

    /* Saturate: '<S40>/Angle_Saturation' */
    if (THA_VC_Ref_B.Add1_jabu > KeTHA_deg_UpperSteeringAngLim) {
      THA_VC_Ref_B.Angle_Saturation = KeTHA_deg_UpperSteeringAngLim;
    } else if (THA_VC_Ref_B.Add1_jabu < KeTHA_deg_LowerSteeringAngLim) {
      THA_VC_Ref_B.Angle_Saturation = KeTHA_deg_LowerSteeringAngLim;
    } else {
      THA_VC_Ref_B.Angle_Saturation = THA_VC_Ref_B.Add1_jabu;
    }

    /* End of Saturate: '<S40>/Angle_Saturation' */

    /* Product: '<S112>/IProd Out' */
    THA_VC_Ref_B.IProdOut = (real32_T)THA_VC_Ref_B.Rpt_Ydiff *
      rtu_MbTHA_VrntTunParamOutData->KeTHA_k_SteerTrqCtrlKi;

    /* Update for UnitDelay: '<S84>/Delay Input2'
     *
     * Block description for '<S84>/Delay Input2':
     *
     *  Store in Global RAM
     */
    THA_VC_Ref_DW.DelayInput2_DSTATE_mkva = THA_VC_Ref_B.DifferenceInputs2_hyze;

    /* Update for DiscreteIntegrator: '<S115>/Integrator' */
    THA_VC_Ref_DW.Integrator_DSTATE += 0.03F * THA_VC_Ref_B.IProdOut;

    /* Update for DiscreteIntegrator: '<S110>/Filter' */
    THA_VC_Ref_DW.Filter_DSTATE += 0.03F * THA_VC_Ref_B.NProdOut;

    /* Update for DiscreteIntegrator: '<S40>/Discrete_Time_Integrator1' */
    THA_VC_Ref_DW.Discrete_Time_Integrator1_DSTATE += THA_VC_Ref_B.Compare ?
      (real32_T)4123168604U * 7.27595761E-12F : 0.0F;
    THA_VC_Ref_DW.Discrete_Time_Integrator1_PrevResetState = (int8_T)
      (THA_VC_Ref_B.Compare ? 1 : 0);

    /* End of Outputs for SubSystem: '<S10>/STR_Control' */

    /* Product: '<S43>/Divide' incorporates:
     *  Constant: '<S10>/Constant4'
     *  Constant: '<S10>/Constant5'
     *  Constant: '<S43>/Constant1'
     */
    THA_VC_Ref_B.Dgain = 6.28318548F * KeTHA_Hz_StrCtrlLowPassFiltFreq *
      KeTHA_s_ThaSampleTime;

    /* Product: '<S43>/Product1' */
    THA_VC_Ref_B.integrator_external_saturation_table =
      THA_VC_Ref_B.Angle_Saturation * THA_VC_Ref_B.Dgain;

    /* Sum: '<S43>/Add' incorporates:
     *  Constant: '<S43>/Constant'
     */
    THA_VC_Ref_B.Dgain = 1.0F - THA_VC_Ref_B.Dgain;

    /* UnitDelay: '<S43>/Unit Delay' */
    THA_VC_Ref_B.Square3 = THA_VC_Ref_DW.UnitDelay_DSTATE_efpz;

    /* Product: '<S43>/Product' */
    THA_VC_Ref_B.Dgain *= THA_VC_Ref_B.Square3;

    /* Sum: '<S43>/Sum' */
    THA_VC_Ref_B.Sum_gpp3 = THA_VC_Ref_B.integrator_external_saturation_table +
      THA_VC_Ref_B.Dgain;

    /* Switch: '<S39>/Switch2' incorporates:
     *  Constant: '<S39>/Constant1'
     *  Constant: '<S39>/Constant2'
     */
    if (KeTHA_b_SpdCndEnable) {
      /* Gain: '<S39>/Gain1' */
      THA_VC_Ref_B.Gain1 = 3.6F * THA_VC_Ref_B.Gain2;

      /* RelationalOperator: '<S77>/Compare' incorporates:
       *  Constant: '<S77>/Constant'
       */
      THA_VC_Ref_B.Compare_kjdt = (THA_VC_Ref_B.Gain1 >= KeTHA_mps_SpdThreshold);
      THA_VC_Ref_B.LogicalOperator6 = THA_VC_Ref_B.Compare_kjdt;
    } else {
      THA_VC_Ref_B.LogicalOperator6 = true;
    }

    /* End of Switch: '<S39>/Switch2' */

    /* Logic: '<S10>/Logical Operator1' */
    THA_VC_Ref_B.LogicalOperator1 = (THA_VC_Ref_B.UnitDelay_h2xn &&
      THA_VC_Ref_B.LogicalOperator5);

    /* Outputs for Enabled SubSystem: '<S39>/Subsystem' incorporates:
     *  EnablePort: '<S79>/Enable'
     */
    if (THA_VC_Ref_B.LogicalOperator1) {
      if (!THA_VC_Ref_DW.Subsystem_MODE) {
        /* InitializeConditions for DiscreteIntegrator: '<S79>/Discrete_Time_Integrator1' */
        THA_VC_Ref_DW.Discrete_Time_Integrator1_DSTATE_m4zj = 0.0F;
        THA_VC_Ref_DW.Discrete_Time_Integrator1_PrevResetState_pyfj = 2;
        THA_VC_Ref_DW.Subsystem_MODE = true;
      }

      /* RelationalOperator: '<S80>/Compare' incorporates:
       *  Constant: '<S80>/Constant'
       */
      THA_VC_Ref_B.Compare_bgyw = ((int32_T)(THA_VC_Ref_B.MeTHA_b_VCActive ? 1 :
        0) > (int32_T)(false ? 1 : 0));

      /* DiscreteIntegrator: '<S79>/Discrete_Time_Integrator1' */
      if ((THA_VC_Ref_B.Compare_bgyw &&
           (THA_VC_Ref_DW.Discrete_Time_Integrator1_PrevResetState_pyfj <= 0)) ||
          ((!THA_VC_Ref_B.Compare_bgyw) &&
           (THA_VC_Ref_DW.Discrete_Time_Integrator1_PrevResetState_pyfj == 1)))
      {
        THA_VC_Ref_DW.Discrete_Time_Integrator1_DSTATE_m4zj = 0.0F;
      }

      THA_VC_Ref_B.Discrete_Time_Integrator1_hao2 =
        THA_VC_Ref_DW.Discrete_Time_Integrator1_DSTATE_m4zj;

      /* End of DiscreteIntegrator: '<S79>/Discrete_Time_Integrator1' */

      /* Update for DiscreteIntegrator: '<S79>/Discrete_Time_Integrator1' */
      THA_VC_Ref_DW.Discrete_Time_Integrator1_DSTATE_m4zj +=
        THA_VC_Ref_B.Compare_bgyw ? (real32_T)4123168604U * 7.27595761E-12F :
        0.0F;
      THA_VC_Ref_DW.Discrete_Time_Integrator1_PrevResetState_pyfj = (int8_T)
        (THA_VC_Ref_B.Compare_bgyw ? 1 : 0);
    } else {
      if (THA_VC_Ref_DW.Subsystem_MODE) {
        /* Disable for Outport: '<S79>/Reset_time' */
        THA_VC_Ref_B.Discrete_Time_Integrator1_hao2 = 0.0F;
        THA_VC_Ref_DW.Subsystem_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S39>/Subsystem' */

    /* Sum: '<S39>/Add' incorporates:
     *  Constant: '<S39>/Constant3'
     *  Constant: '<S39>/Constant5'
     */
    THA_VC_Ref_B.Square3 = KeTHA_s_SteerTweakTime + KeTHA_s_ThaSampleTime;

    /* RelationalOperator: '<S39>/Relational Operator' */
    THA_VC_Ref_B.RelationalOperator6 =
      (THA_VC_Ref_B.Discrete_Time_Integrator1_hao2 >= THA_VC_Ref_B.Square3);

    /* Logic: '<S39>/Logical Operator1' */
    THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.LogicalOperator6 &&
      THA_VC_Ref_B.RelationalOperator6);

    /* Switch: '<S39>/Switch' */
    if (THA_VC_Ref_B.LogicalOperator6) {
      THA_VC_Ref_B.Switch_lulz = THA_VC_Ref_B.Sum_gpp3;
    } else {
      THA_VC_Ref_B.Switch_lulz = THA_VC_Ref_B.Saturation1;
    }

    /* End of Switch: '<S39>/Switch' */

    /* RelationalOperator: '<S78>/LowerRelop1' incorporates:
     *  Constant: '<S39>/Constant'
     */
    THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.Switch_lulz >
      KeTHA_deg_UpperSteeringAngLim);

    /* Gain: '<S39>/Gain' incorporates:
     *  Constant: '<S39>/Constant'
     */
    THA_VC_Ref_B.Square3 = (-1.0F) * KeTHA_deg_UpperSteeringAngLim;

    /* RelationalOperator: '<S78>/UpperRelop' */
    THA_VC_Ref_B.RelationalOperator6 = (THA_VC_Ref_B.Switch_lulz <
      THA_VC_Ref_B.Square3);

    /* Switch: '<S78>/Switch' */
    if (THA_VC_Ref_B.RelationalOperator6) {
      THA_VC_Ref_B.Switch_ek3b = THA_VC_Ref_B.Square3;
    } else {
      THA_VC_Ref_B.Switch_ek3b = THA_VC_Ref_B.Switch_lulz;
    }

    /* End of Switch: '<S78>/Switch' */

    /* Switch: '<S78>/Switch2' incorporates:
     *  Constant: '<S39>/Constant'
     */
    if (THA_VC_Ref_B.LogicalOperator6) {
      THA_VC_Ref_B.Switch2_hj2w = KeTHA_deg_UpperSteeringAngLim;
    } else {
      THA_VC_Ref_B.Switch2_hj2w = THA_VC_Ref_B.Switch_ek3b;
    }

    /* End of Switch: '<S78>/Switch2' */

    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant4'
     */
    if (KeTHA_b_UsePreProcessor) {
      THA_VC_Ref_B.Square3 = THA_VC_Ref_B.Switch2_hj2w;
    } else {
      THA_VC_Ref_B.Square3 = THA_VC_Ref_B.Sum_gpp3;
    }

    /* End of Switch: '<S39>/Switch1' */

    /* SignalConversion: '<S39>/Signal Copy' */
    MeTHA_deg_StrAngCmd = THA_VC_Ref_B.Square3;

    /* Outputs for Enabled SubSystem: '<S10>/TrqControlOld' incorporates:
     *  EnablePort: '<S41>/Enable'
     */
    /* Sum: '<S42>/Sum1' incorporates:
     *  Sum: '<S41>/Sum1'
     */
    THA_VC_Ref_B.Sum1 = MeTHA_deg_StrAngCmd - THA_VC_Ref_B.Saturation1;

    /* End of Outputs for SubSystem: '<S10>/TrqControlOld' */

    /* UnitDelay: '<S42>/Unit Delay1' */
    THA_VC_Ref_B.Square3 = THA_VC_Ref_DW.UnitDelay1_DSTATE_njpd;

    /* Sum: '<S42>/Subtract2' */
    THA_VC_Ref_B.Square3 = THA_VC_Ref_B.Sum1 - THA_VC_Ref_B.Square3;

    /* Gain: '<S42>/inverse_dt1' */
    THA_VC_Ref_B.Square3 *= 33.3333321F;

    /* Sum: '<S42>/Sum2' */
    THA_VC_Ref_B.Square3 -= THA_VC_Ref_B.Saturation7;

    /* RelationalOperator: '<S42>/Relational Operator2' incorporates:
     *  Constant: '<S134>/Constant'
     */
    THA_VC_Ref_B.LogicalOperator6 =
      (rtu_MbTHA_ProxiMgrOutData->MePRX_e_Wheelbase == TePRX_e_Wheelbase_Type_2);

    /* RelationalOperator: '<S42>/Relational Operator' incorporates:
     *  Constant: '<S135>/Constant'
     */
    THA_VC_Ref_B.RelationalOperator =
      (rtu_MbTHA_ProxiMgrOutData->MePRX_e_SteerRatRackPinionTyp ==
       TePRX_e_SteerRatRackPinionTyp_Type_3);

    /* Logic: '<S42>/Logical Operator1' */
    THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.LogicalOperator6 &&
      THA_VC_Ref_B.RelationalOperator);

    /* Gain: '<S10>/Gain1' */
    THA_VC_Ref_B.Dgain = 3.6F * THA_VC_Ref_B.Gain2;

    /* Abs: '<S42>/Abs1' */
    THA_VC_Ref_B.Abs1 = fabsf(THA_VC_Ref_B.Dgain);

    /* RelationalOperator: '<S42>/Relational Operator1' incorporates:
     *  Constant: '<S133>/Constant'
     */
    THA_VC_Ref_B.RelationalOperator1 =
      (rtu_MbTHA_ProxiMgrOutData->MePRX_e_SteerRatRackPinionTyp ==
       TePRX_e_SteerRatRackPinionTyp_Type_2);

    /* Logic: '<S42>/Logical Operator' */
    THA_VC_Ref_B.LogicalOperator_orp3 = (THA_VC_Ref_B.RelationalOperator ||
      THA_VC_Ref_B.RelationalOperator1);

    /* Switch: '<S42>/Switch6' incorporates:
     *  Switch: '<S42>/Switch3'
     */
    if (THA_VC_Ref_B.LogicalOperator6) {
      /* Lookup_n-D: '<S42>/differential_gain_table_trx' */
      THA_VC_Ref_B.differential_gain_table_trx = look1_iflf_binlg
        (THA_VC_Ref_B.Abs1, THA_VC_Ref_ConstP.pooled25, ((real32_T *)
          &(KsTHA_k_TrqCtrlDiffGainTD_WB144_C63[0])), 3U);

      /* Product: '<S42>/Product13' incorporates:
       *  Constant: '<S42>/Constant11'
       */
      THA_VC_Ref_B.Product13 = KeTHA_k_TrqCtrlDMultiplier_WB144_CF63 *
        THA_VC_Ref_B.differential_gain_table_trx;
      THA_VC_Ref_B.Dgain = THA_VC_Ref_B.Product13;
    } else {
      if (THA_VC_Ref_B.LogicalOperator_orp3) {
        /* Lookup_n-D: '<S42>/differential_gain_table1' incorporates:
         *  Switch: '<S42>/Switch3'
         */
        THA_VC_Ref_B.differential_gain_table1 = look1_iflf_binlg
          (THA_VC_Ref_B.Abs1, THA_VC_Ref_ConstP.pooled25, ((real32_T *)
            &(KsTHA_k_TrqCtrlDiffGainTD_C60_C63[0])), 3U);

        /* Product: '<S42>/Product6' incorporates:
         *  Constant: '<S42>/Constant4'
         *  Switch: '<S42>/Switch3'
         */
        THA_VC_Ref_B.Product6 = KeTHA_k_TrqCtrlDMultiplier_CF60_CF63 *
          THA_VC_Ref_B.differential_gain_table1;

        /* Switch: '<S42>/Switch3' */
        THA_VC_Ref_B.Switch3 = THA_VC_Ref_B.Product6;
      } else {
        /* Lookup_n-D: '<S42>/differential_gain_table' incorporates:
         *  Switch: '<S42>/Switch3'
         */
        THA_VC_Ref_B.differential_gain_table = look1_iflf_binlg
          (THA_VC_Ref_B.Abs1, THA_VC_Ref_ConstP.pooled25, ((real32_T *)
            &(KsTHA_k_TrqCtrlDiffGainTD_C55[0])), 3U);

        /* Product: '<S42>/Product9' incorporates:
         *  Constant: '<S42>/Constant7'
         *  Switch: '<S42>/Switch3'
         */
        THA_VC_Ref_B.Product9 = THA_VC_Ref_B.differential_gain_table *
          KeTHA_k_TrqCtrlDMultiplier_CF55;

        /* Switch: '<S42>/Switch3' */
        THA_VC_Ref_B.Switch3 = THA_VC_Ref_B.Product9;
      }

      THA_VC_Ref_B.Dgain = THA_VC_Ref_B.Switch3;
    }

    /* End of Switch: '<S42>/Switch6' */

    /* Product: '<S42>/Product3' */
    THA_VC_Ref_B.Dgain *= THA_VC_Ref_B.Square3;

    /* Abs: '<S42>/Abs' */
    THA_VC_Ref_B.Abs = fabsf(THA_VC_Ref_B.Sum1);

    /* Switch: '<S42>/Switch4' incorporates:
     *  Switch: '<S42>/Switch'
     *  Switch: '<S42>/Switch1'
     */
    if (THA_VC_Ref_B.LogicalOperator6) {
      /* Lookup_n-D: '<S42>/P_gain_lookup_table trx' */
      THA_VC_Ref_B.P_gain_lookup_tabletrx = look2_iflf_binlg(THA_VC_Ref_B.Abs1,
        THA_VC_Ref_B.Abs, THA_VC_Ref_ConstP.pooled25, THA_VC_Ref_ConstP.pooled26,
        ((real32_T *)&(KsTHA_k_TrqCtrlPropGainTD_WB144_C63[0])),
        THA_VC_Ref_ConstP.pooled34, 4U);

      /* Product: '<S42>/Product11' incorporates:
       *  Constant: '<S42>/Constant9'
       */
      THA_VC_Ref_B.Product11 = KeTHA_k_TrqCtrlPMultiplier_WB144_CF63 *
        THA_VC_Ref_B.P_gain_lookup_tabletrx;
      THA_VC_Ref_B.Square3 = THA_VC_Ref_B.Product11;
    } else {
      if (THA_VC_Ref_B.RelationalOperator) {
        /* Lookup_n-D: '<S42>/P_gain_lookup_table98' incorporates:
         *  Switch: '<S42>/Switch'
         */
        THA_VC_Ref_B.P_gain_lookup_table98 = look2_iflf_binlg(THA_VC_Ref_B.Abs1,
          THA_VC_Ref_B.Abs, THA_VC_Ref_ConstP.pooled25,
          THA_VC_Ref_ConstP.pooled26, ((real32_T *)
          &(KsTHA_k_TrqCtrlPropGainTD_C63[0])), THA_VC_Ref_ConstP.pooled34, 4U);

        /* Product: '<S42>/Product4' incorporates:
         *  Constant: '<S42>/Constant2'
         *  Switch: '<S42>/Switch'
         */
        THA_VC_Ref_B.Product4 = KeTHA_k_TrqCtrlPMultiplier_CF63 *
          THA_VC_Ref_B.P_gain_lookup_table98;

        /* Switch: '<S42>/Switch' */
        THA_VC_Ref_B.Switch_ft0z = THA_VC_Ref_B.Product4;
      } else {
        if (THA_VC_Ref_B.RelationalOperator1) {
          /* Lookup_n-D: '<S42>/P_gain_lookup_table103' incorporates:
           *  Switch: '<S42>/Switch'
           *  Switch: '<S42>/Switch1'
           */
          THA_VC_Ref_B.P_gain_lookup_table103 = look2_iflf_binlg
            (THA_VC_Ref_B.Abs1, THA_VC_Ref_B.Abs, THA_VC_Ref_ConstP.pooled25,
             THA_VC_Ref_ConstP.pooled26, ((real32_T *)
              &(KsTHA_k_TrqCtrlPropGainTD_C60[0])), THA_VC_Ref_ConstP.pooled34,
             4U);

          /* Product: '<S42>/Product10' incorporates:
           *  Constant: '<S42>/Constant8'
           *  Switch: '<S42>/Switch'
           *  Switch: '<S42>/Switch1'
           */
          THA_VC_Ref_B.Product10 = KeTHA_k_TrqCtrlPMultiplier_CF60 *
            THA_VC_Ref_B.P_gain_lookup_table103;

          /* Switch: '<S42>/Switch1' incorporates:
           *  Switch: '<S42>/Switch'
           */
          THA_VC_Ref_B.Switch1_lajy = THA_VC_Ref_B.Product10;
        } else {
          /* Lookup_n-D: '<S42>/P_gain_lookup_table102' incorporates:
           *  Switch: '<S42>/Switch'
           *  Switch: '<S42>/Switch1'
           */
          THA_VC_Ref_B.P_gain_lookup_table102 = look2_iflf_binlg
            (THA_VC_Ref_B.Abs1, THA_VC_Ref_B.Abs, THA_VC_Ref_ConstP.pooled25,
             THA_VC_Ref_ConstP.pooled26, ((real32_T *)
              &(KsTHA_k_TrqCtrlPropGainTD_C55[0])), THA_VC_Ref_ConstP.pooled34,
             4U);

          /* Product: '<S42>/Product7' incorporates:
           *  Constant: '<S42>/Constant5'
           *  Switch: '<S42>/Switch'
           *  Switch: '<S42>/Switch1'
           */
          THA_VC_Ref_B.Product7 = THA_VC_Ref_B.P_gain_lookup_table102 *
            KeTHA_k_TrqCtrlPMultiplier_CF55;

          /* Switch: '<S42>/Switch1' incorporates:
           *  Switch: '<S42>/Switch'
           */
          THA_VC_Ref_B.Switch1_lajy = THA_VC_Ref_B.Product7;
        }

        /* Switch: '<S42>/Switch' */
        THA_VC_Ref_B.Switch_ft0z = THA_VC_Ref_B.Switch1_lajy;
      }

      THA_VC_Ref_B.Square3 = THA_VC_Ref_B.Switch_ft0z;
    }

    /* End of Switch: '<S42>/Switch4' */

    /* Product: '<S42>/Product' */
    THA_VC_Ref_B.Square3 *= THA_VC_Ref_B.Sum1;

    /* Gain: '<S42>/entire_table' */
    THA_VC_Ref_B.Square3 *= 1.0F;

    /* Lookup_n-D: '<S42>/integrator_external_saturation_table' */
    THA_VC_Ref_B.integrator_external_saturation_table = look1_iflf_binlx
      (THA_VC_Ref_B.Abs1, THA_VC_Ref_ConstP.pooled25, ((real32_T *)
        &(KsTHA_k_TrqCtrlIntExtSatTD[0])), 3U);

    /* DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
    if ((THA_VC_Ref_B.MeTHA_b_VCActive &&
         (THA_VC_Ref_DW.DiscreteTimeIntegrator_PrevResetState <= 0)) ||
        ((!THA_VC_Ref_B.MeTHA_b_VCActive) &&
         (THA_VC_Ref_DW.DiscreteTimeIntegrator_PrevResetState == 1))) {
      THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE = THA_VC_Ref_ConstB.Constant1;
      if (THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE >=
          KsTHA_k_TrqCtrlIntExtSatTD[0]) {
        THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE =
          KsTHA_k_TrqCtrlIntExtSatTD[0];
      } else {
        if (THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE <=
            -KsTHA_k_TrqCtrlIntExtSatTD[0]) {
          THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE =
            -KsTHA_k_TrqCtrlIntExtSatTD[0];
        }
      }
    }

    if (THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE >=
        KsTHA_k_TrqCtrlIntExtSatTD[0]) {
      THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE = KsTHA_k_TrqCtrlIntExtSatTD[0];
    } else {
      if (THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE <=
          -KsTHA_k_TrqCtrlIntExtSatTD[0]) {
        THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE =
          -KsTHA_k_TrqCtrlIntExtSatTD[0];
      }
    }

    THA_VC_Ref_B.DiscreteTimeIntegrator =
      THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S138>/LowerRelop1' */
    THA_VC_Ref_B.RelationalOperator6 = (THA_VC_Ref_B.DiscreteTimeIntegrator >
      THA_VC_Ref_B.integrator_external_saturation_table);

    /* Gain: '<S42>/Gain' */
    THA_VC_Ref_B.Add1_jabu = (-1.0F) *
      THA_VC_Ref_B.integrator_external_saturation_table;

    /* RelationalOperator: '<S138>/UpperRelop' */
    THA_VC_Ref_B.UnitDelay4 = (THA_VC_Ref_B.DiscreteTimeIntegrator <
      THA_VC_Ref_B.Add1_jabu);

    /* Switch: '<S138>/Switch' */
    if (THA_VC_Ref_B.UnitDelay4) {
      THA_VC_Ref_B.Switch_ctws = THA_VC_Ref_B.Add1_jabu;
    } else {
      THA_VC_Ref_B.Switch_ctws = THA_VC_Ref_B.DiscreteTimeIntegrator;
    }

    /* End of Switch: '<S138>/Switch' */

    /* Switch: '<S138>/Switch2' */
    if (THA_VC_Ref_B.RelationalOperator6) {
      THA_VC_Ref_B.Switch2_pjho =
        THA_VC_Ref_B.integrator_external_saturation_table;
    } else {
      THA_VC_Ref_B.Switch2_pjho = THA_VC_Ref_B.Switch_ctws;
    }

    /* End of Switch: '<S138>/Switch2' */

    /* Lookup_n-D: '<S42>/damping_gain_table' */
    THA_VC_Ref_B.Add1_jabu = look1_iflf_binlx(THA_VC_Ref_B.Abs1,
      THA_VC_Ref_ConstP.pooled25, ((real32_T *)&(KsTHA_k_TrqCtrlDampGainTD[0])),
      3U);

    /* Product: '<S42>/Product1' */
    THA_VC_Ref_B.Add1_jabu *= THA_VC_Ref_B.Saturation7;

    /* Sum: '<S42>/Add' */
    THA_VC_Ref_B.Square3 = ((THA_VC_Ref_B.Square3 + THA_VC_Ref_B.Switch2_pjho) +
      THA_VC_Ref_B.Dgain) + THA_VC_Ref_B.Add1_jabu;

    /* Sum: '<S42>/Add1' incorporates:
     *  Constant: '<S42>/Constant'
     */
    THA_VC_Ref_B.StrCmdTqLmtOld = 0.0F + THA_VC_Ref_B.Square3;

    /* UnitDelay: '<S136>/Delay Input2'
     *
     * Block description for '<S136>/Delay Input2':
     *
     *  Store in Global RAM
     */
    THA_VC_Ref_B.Yk1_ocsm = THA_VC_Ref_DW.DelayInput2_DSTATE_ivvk;

    /* Sum: '<S136>/Difference Inputs1'
     *
     * Block description for '<S136>/Difference Inputs1':
     *
     *  Add in CPU
     */
    THA_VC_Ref_B.UkYk1_ecnl = THA_VC_Ref_B.StrCmdTqLmtOld -
      THA_VC_Ref_B.Yk1_ocsm;

    /* SampleTimeMath: '<S136>/sample time'
     *
     * About '<S136>/sample time':
     *  y = K where K = ( w * Ts )
     */
    THA_VC_Ref_B.sampletime_a0qp = 0.03F;

    /* Product: '<S136>/delta rise limit' incorporates:
     *  Constant: '<S42>/Constant_RateLimit'
     */
    THA_VC_Ref_B.deltariselimit_h33d = KeTHA_dM_TrqCtrlSlewRate *
      THA_VC_Ref_B.sampletime_a0qp;

    /* RelationalOperator: '<S139>/LowerRelop1' */
    THA_VC_Ref_B.RelationalOperator6 = (THA_VC_Ref_B.UkYk1_ecnl >
      THA_VC_Ref_B.deltariselimit_h33d);

    /* Gain: '<S42>/Gain4' incorporates:
     *  Constant: '<S42>/Constant_RateLimit'
     */
    THA_VC_Ref_B.Add1_jabu = (-1.0F) * KeTHA_dM_TrqCtrlSlewRate;

    /* Product: '<S136>/delta fall limit' */
    THA_VC_Ref_B.deltafalllimit_avfk = THA_VC_Ref_B.Add1_jabu *
      THA_VC_Ref_B.sampletime_a0qp;

    /* RelationalOperator: '<S139>/UpperRelop' */
    THA_VC_Ref_B.UnitDelay4 = (THA_VC_Ref_B.UkYk1_ecnl <
      THA_VC_Ref_B.deltafalllimit_avfk);

    /* Switch: '<S139>/Switch' */
    if (THA_VC_Ref_B.UnitDelay4) {
      THA_VC_Ref_B.Switch_cr1i = THA_VC_Ref_B.deltafalllimit_avfk;
    } else {
      THA_VC_Ref_B.Switch_cr1i = THA_VC_Ref_B.UkYk1_ecnl;
    }

    /* End of Switch: '<S139>/Switch' */

    /* Switch: '<S139>/Switch2' */
    if (THA_VC_Ref_B.RelationalOperator6) {
      THA_VC_Ref_B.Switch2_cddq = THA_VC_Ref_B.deltariselimit_h33d;
    } else {
      THA_VC_Ref_B.Switch2_cddq = THA_VC_Ref_B.Switch_cr1i;
    }

    /* End of Switch: '<S139>/Switch2' */

    /* Sum: '<S136>/Difference Inputs2'
     *
     * Block description for '<S136>/Difference Inputs2':
     *
     *  Add in CPU
     */
    THA_VC_Ref_B.DifferenceInputs2 = THA_VC_Ref_B.Switch2_cddq +
      THA_VC_Ref_B.Yk1_ocsm;

    /* RelationalOperator: '<S137>/LowerRelop1' incorporates:
     *  Constant: '<S42>/Constant_SaturationLimit'
     */
    THA_VC_Ref_B.RelationalOperator6 = (THA_VC_Ref_B.DifferenceInputs2 >
      KeTHA_M_StrTrqValLimit);

    /* Gain: '<S42>/Gain3' incorporates:
     *  Constant: '<S42>/Constant_SaturationLimit'
     */
    THA_VC_Ref_B.Add1_jabu = (-1.0F) * KeTHA_M_StrTrqValLimit;

    /* RelationalOperator: '<S137>/UpperRelop' */
    THA_VC_Ref_B.UnitDelay4 = (THA_VC_Ref_B.DifferenceInputs2 <
      THA_VC_Ref_B.Add1_jabu);

    /* Switch: '<S137>/Switch' */
    if (THA_VC_Ref_B.UnitDelay4) {
      THA_VC_Ref_B.Switch_gyji = THA_VC_Ref_B.Add1_jabu;
    } else {
      THA_VC_Ref_B.Switch_gyji = THA_VC_Ref_B.DifferenceInputs2;
    }

    /* End of Switch: '<S137>/Switch' */

    /* Switch: '<S137>/Switch2' incorporates:
     *  Constant: '<S42>/Constant_SaturationLimit'
     */
    if (THA_VC_Ref_B.RelationalOperator6) {
      THA_VC_Ref_B.Switch2_jsai = KeTHA_M_StrTrqValLimit;
    } else {
      THA_VC_Ref_B.Switch2_jsai = THA_VC_Ref_B.Switch_gyji;
    }

    /* End of Switch: '<S137>/Switch2' */

    /* RelationalOperator: '<S35>/Compare' incorporates:
     *  Constant: '<S35>/Constant'
     */
    THA_VC_Ref_B.RelationalOperator6 = (THA_VC_Ref_B.Gain2 > 0.1F);

    /* Logic: '<S10>/Logical Operator' */
    THA_VC_Ref_B.LogicalOperator_hxxz = (THA_VC_Ref_B.MeTHA_b_VCActive &&
      THA_VC_Ref_B.RelationalOperator6);

    /* Outputs for Enabled SubSystem: '<S10>/TrqControlOld' incorporates:
     *  EnablePort: '<S41>/Enable'
     */
    if (THA_VC_Ref_B.LogicalOperator_hxxz) {
      if (!THA_VC_Ref_DW.TrqControlOld_MODE) {
        /* InitializeConditions for UnitDelay: '<S41>/Unit Delay4' */
        THA_VC_Ref_DW.UnitDelay4_DSTATE = false;

        /* InitializeConditions for DiscreteIntegrator: '<S41>/DiscreteTimeIntegrator' */
        THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE_e31n =
          THA_VC_Ref_ConstB.Constant1_it32;
        THA_VC_Ref_DW.DiscreteTimeIntegrator_PrevResetState_lsdo = 0;

        /* InitializeConditions for UnitDelay: '<S41>/Unit Delay2' */
        THA_VC_Ref_DW.UnitDelay2_DSTATE_gk31 = 0.0F;

        /* InitializeConditions for RateLimiter: '<S41>/DgainRateLimitor1' */
        THA_VC_Ref_DW.PrevY = 0.0F;

        /* SystemReset for Chart: '<S41>/Chart' */
        THA_VC_Ref_DW.is_active_c68_THA_VC_Ref = 0U;
        THA_VC_Ref_DW.is_c68_THA_VC_Ref = THA_VC_Ref_IN_NO_ACTIVE_CHILD;
        THA_VC_Ref_B.FB_I_tq = 0.0F;
        THA_VC_Ref_DW.TrqControlOld_MODE = true;
      }

      /* Sum: '<S41>/Sum1' */
      THA_VC_Ref_B.Sum1_g22q = THA_VC_Ref_B.Sum1;

      /* Gain: '<S41>/Pgain' */
      THA_VC_Ref_B.Add1_jabu = KeTHA_k_SteerTrqCtrlKp * THA_VC_Ref_B.Sum1_g22q;

      /* Abs: '<S41>/Abs1' */
      THA_VC_Ref_B.Square3 = fabsf(THA_VC_Ref_B.Sum1_g22q);

      /* RelationalOperator: '<S41>/Relational Operator1' incorporates:
       *  Constant: '<S41>/Const_IGainReset'
       */
      THA_VC_Ref_B.RelationalOperator6 = (THA_VC_Ref_B.Square3 <= 1.0F);

      /* UnitDelay: '<S41>/Unit Delay4' */
      THA_VC_Ref_B.UnitDelay4 = THA_VC_Ref_DW.UnitDelay4_DSTATE;

      /* Logic: '<S41>/Logical Operator2' incorporates:
       *  Constant: '<S41>/dummy_startflag'
       */
      THA_VC_Ref_B.LogicalOperator2_imfa = (THA_VC_Ref_B.RelationalOperator6 ||
        false || THA_VC_Ref_B.UnitDelay4);

      /* DiscreteIntegrator: '<S41>/DiscreteTimeIntegrator' */
      if (THA_VC_Ref_B.LogicalOperator2_imfa ||
          (THA_VC_Ref_DW.DiscreteTimeIntegrator_PrevResetState_lsdo != 0)) {
        THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE_e31n =
          THA_VC_Ref_ConstB.Constant1_it32;
      }

      THA_VC_Ref_B.Square3 = THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE_e31n;

      /* End of DiscreteIntegrator: '<S41>/DiscreteTimeIntegrator' */

      /* Gain: '<S41>/Igain' */
      THA_VC_Ref_B.Dgain = KeTHA_k_TrqCtrlKi * THA_VC_Ref_B.Square3;

      /* Saturate: '<S41>/igainSaturation1' */
      if (THA_VC_Ref_B.Dgain > 0.2F) {
        THA_VC_Ref_B.igainSaturation1 = 0.2F;
      } else if (THA_VC_Ref_B.Dgain < (-0.2F)) {
        THA_VC_Ref_B.igainSaturation1 = (-0.2F);
      } else {
        THA_VC_Ref_B.igainSaturation1 = THA_VC_Ref_B.Dgain;
      }

      /* End of Saturate: '<S41>/igainSaturation1' */

      /* Chart: '<S41>/Chart' incorporates:
       *  Constant: '<S41>/IgainRateLimit'
       */
      if ((uint32_T)THA_VC_Ref_DW.is_active_c68_THA_VC_Ref == 0U) {
        THA_VC_Ref_DW.is_active_c68_THA_VC_Ref = 1U;
        THA_VC_Ref_DW.is_c68_THA_VC_Ref = THA_VC_Ref_IN_Init;
        THA_VC_Ref_B.FB_I_tq = 0.0F;
        THA_VC_Ref_B.resetFlag = false;
      } else {
        switch (THA_VC_Ref_DW.is_c68_THA_VC_Ref) {
         case THA_VC_Ref_IN_I_Remove_Neg:
          if (THA_VC_Ref_B.FB_I_tq >= 0.0F) {
            THA_VC_Ref_DW.is_c68_THA_VC_Ref = THA_VC_Ref_IN_Init;
            THA_VC_Ref_B.FB_I_tq = 0.0F;
            THA_VC_Ref_B.resetFlag = false;
          } else {
            THA_VC_Ref_B.FB_I_tq += 0.01F;
            THA_VC_Ref_B.resetFlag = true;
          }
          break;

         case THA_VC_Ref_IN_I_Remove_Pos:
          if (THA_VC_Ref_B.FB_I_tq < 0.0F) {
            THA_VC_Ref_DW.is_c68_THA_VC_Ref = THA_VC_Ref_IN_Init;
            THA_VC_Ref_B.FB_I_tq = 0.0F;
            THA_VC_Ref_B.resetFlag = false;
          } else {
            THA_VC_Ref_B.FB_I_tq -= 0.01F;
            THA_VC_Ref_B.resetFlag = true;
          }
          break;

         case THA_VC_Ref_IN_I_Update_Neg:
          if (THA_VC_Ref_B.igainSaturation1 < 0.0F) {
            THA_VC_Ref_DW.is_c68_THA_VC_Ref = THA_VC_Ref_IN_I_Remove_Neg;
            THA_VC_Ref_B.FB_I_tq += 0.01F;
            THA_VC_Ref_B.resetFlag = true;
          } else {
            THA_VC_Ref_B.FB_I_tq = THA_VC_Ref_B.igainSaturation1;
            THA_VC_Ref_B.resetFlag = false;
          }
          break;

         case THA_VC_Ref_IN_I_Update_Pos:
          if (THA_VC_Ref_B.igainSaturation1 > 0.0F) {
            THA_VC_Ref_DW.is_c68_THA_VC_Ref = THA_VC_Ref_IN_I_Remove_Pos;
            THA_VC_Ref_B.FB_I_tq -= 0.01F;
            THA_VC_Ref_B.resetFlag = true;
          } else {
            THA_VC_Ref_B.FB_I_tq = THA_VC_Ref_B.igainSaturation1;
            THA_VC_Ref_B.resetFlag = false;
          }
          break;

         default:
          /* case IN_Init: */
          if (THA_VC_Ref_B.igainSaturation1 > 0.0F) {
            THA_VC_Ref_DW.is_c68_THA_VC_Ref = THA_VC_Ref_IN_I_Update_Pos;
            THA_VC_Ref_B.FB_I_tq = THA_VC_Ref_B.igainSaturation1;
            THA_VC_Ref_B.resetFlag = false;
          } else if (THA_VC_Ref_B.igainSaturation1 < 0.0F) {
            THA_VC_Ref_DW.is_c68_THA_VC_Ref = THA_VC_Ref_IN_I_Update_Neg;
            THA_VC_Ref_B.FB_I_tq = THA_VC_Ref_B.igainSaturation1;
            THA_VC_Ref_B.resetFlag = false;
          } else {
            THA_VC_Ref_B.FB_I_tq = 0.0F;
            THA_VC_Ref_B.resetFlag = false;
          }
          break;
        }
      }

      /* End of Chart: '<S41>/Chart' */

      /* UnitDelay: '<S41>/Unit Delay2' */
      THA_VC_Ref_B.Dgain = THA_VC_Ref_DW.UnitDelay2_DSTATE_gk31;

      /* Sum: '<S41>/Subtract1' */
      THA_VC_Ref_B.Dgain = THA_VC_Ref_B.Sum1_g22q - THA_VC_Ref_B.Dgain;

      /* RateLimiter: '<S41>/DgainRateLimitor1' */
      v = THA_VC_Ref_B.Dgain - THA_VC_Ref_DW.PrevY;
      if (v > 0.3F) {
        THA_VC_Ref_B.Dgain = THA_VC_Ref_DW.PrevY + 0.3F;
      } else {
        if (v < (-0.3F)) {
          THA_VC_Ref_B.Dgain = THA_VC_Ref_DW.PrevY + (-0.3F);
        }
      }

      THA_VC_Ref_DW.PrevY = THA_VC_Ref_B.Dgain;

      /* End of RateLimiter: '<S41>/DgainRateLimitor1' */

      /* Gain: '<S41>/Dgain' */
      THA_VC_Ref_B.Dgain *= KeTHA_k_TrqCtrlKd;

      /* Sum: '<S41>/Add' */
      THA_VC_Ref_B.Add1_jabu = (THA_VC_Ref_B.Add1_jabu + THA_VC_Ref_B.FB_I_tq) +
        THA_VC_Ref_B.Dgain;

      /* Sum: '<S41>/Add1' incorporates:
       *  Constant: '<S41>/Constant'
       */
      THA_VC_Ref_B.Add1_jabu += 0.0F;

      /* RelationalOperator: '<S132>/Compare' incorporates:
       *  Constant: '<S132>/Constant'
       */
      THA_VC_Ref_B.RelationalOperator6 = (MeTHA_deg_StrAngCmd != 0.0F);

      /* Product: '<S41>/Product2' */
      THA_VC_Ref_B.Product2_l505 = THA_VC_Ref_B.RelationalOperator6 ?
        THA_VC_Ref_B.Add1_jabu : 0.0F;

      /* Update for UnitDelay: '<S41>/Unit Delay4' */
      THA_VC_Ref_DW.UnitDelay4_DSTATE = THA_VC_Ref_B.resetFlag;

      /* Update for DiscreteIntegrator: '<S41>/DiscreteTimeIntegrator' */
      THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE_e31n += 0.03F *
        THA_VC_Ref_B.Sum1_g22q;
      THA_VC_Ref_DW.DiscreteTimeIntegrator_PrevResetState_lsdo = (int8_T)
        (THA_VC_Ref_B.LogicalOperator2_imfa ? 1 : 0);

      /* Update for UnitDelay: '<S41>/Unit Delay2' */
      THA_VC_Ref_DW.UnitDelay2_DSTATE_gk31 = THA_VC_Ref_B.Sum1_g22q;
    } else {
      THA_VC_Ref_DW.TrqControlOld_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S10>/TrqControlOld' */

    /* RelationalOperator: '<S37>/RelationalOperator6' incorporates:
     *  Constant: '<S76>/Constant'
     */
    THA_VC_Ref_B.RelationalOperator6 = (*rtu_MeTHA_e_THASteerTrqReq ==
      TeTHA_e_THASteerTrqReq_True);

    /* Switch: '<S37>/Switch' incorporates:
     *  Constant: '<S37>/Constant'
     */
    if (THA_VC_Ref_B.RelationalOperator6) {
      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S10>/Constant3'
       */
      if (KeTHA_b_UseNewTrqCtrl) {
        THA_VC_Ref_B.Switch_bm4p = THA_VC_Ref_B.Switch2_jsai;
      } else {
        THA_VC_Ref_B.Switch_bm4p = THA_VC_Ref_B.Product2_l505;
      }

      /* End of Switch: '<S10>/Switch' */
      THA_VC_Ref_B.Merge1 = THA_VC_Ref_B.Switch_bm4p;
    } else {
      THA_VC_Ref_B.Merge1 = 0.0F;
    }

    /* End of Switch: '<S37>/Switch' */

    /* Switch: '<S42>/Switch5' incorporates:
     *  Switch: '<S42>/Switch2'
     */
    if (THA_VC_Ref_B.LogicalOperator6) {
      /* Lookup_n-D: '<S42>/integrator_gain_table_trx' */
      THA_VC_Ref_B.integrator_gain_table_trx = look1_iflf_binlg
        (THA_VC_Ref_B.Abs1, THA_VC_Ref_ConstP.pooled25, ((real32_T *)
          &(KsTHA_k_TrqCtrlIntGainTD_WB144_C63[0])), 3U);

      /* Product: '<S42>/Product12' incorporates:
       *  Constant: '<S42>/Constant10'
       */
      THA_VC_Ref_B.Product12 = KeTHA_k_TrqCtrlIMultiplier_WB144_CF63 *
        THA_VC_Ref_B.integrator_gain_table_trx;
      THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.Product12;
    } else {
      if (THA_VC_Ref_B.LogicalOperator_orp3) {
        /* Lookup_n-D: '<S42>/integrator_gain_table1' incorporates:
         *  Switch: '<S42>/Switch2'
         */
        THA_VC_Ref_B.integrator_gain_table1 = look1_iflf_binlg(THA_VC_Ref_B.Abs1,
          THA_VC_Ref_ConstP.pooled25, ((real32_T *)
          &(KsTHA_k_TrqCtrlIntGainTD_C60_C63[0])), 3U);

        /* Product: '<S42>/Product5' incorporates:
         *  Constant: '<S42>/Constant3'
         *  Switch: '<S42>/Switch2'
         */
        THA_VC_Ref_B.Product5 = KeTHA_k_TrqCtrlIMultiplier_CF60_CF63 *
          THA_VC_Ref_B.integrator_gain_table1;

        /* Switch: '<S42>/Switch2' */
        THA_VC_Ref_B.Switch2_iy0x = THA_VC_Ref_B.Product5;
      } else {
        /* Lookup_n-D: '<S42>/integrator_gain_table' incorporates:
         *  Switch: '<S42>/Switch2'
         */
        THA_VC_Ref_B.integrator_gain_table = look1_iflf_binlg(THA_VC_Ref_B.Abs1,
          THA_VC_Ref_ConstP.pooled25, ((real32_T *)
          &(KsTHA_k_TrqCtrlIntGainTD_C55[0])), 3U);

        /* Product: '<S42>/Product8' incorporates:
         *  Constant: '<S42>/Constant6'
         *  Switch: '<S42>/Switch2'
         */
        THA_VC_Ref_B.Product8 = THA_VC_Ref_B.integrator_gain_table *
          KeTHA_k_TrqCtrlIMultiplier_CF55;

        /* Switch: '<S42>/Switch2' */
        THA_VC_Ref_B.Switch2_iy0x = THA_VC_Ref_B.Product8;
      }

      THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.Switch2_iy0x;
    }

    /* End of Switch: '<S42>/Switch5' */

    /* Product: '<S42>/Product2' */
    THA_VC_Ref_B.Product2 = THA_VC_Ref_B.Add1_jabu * THA_VC_Ref_B.Sum1;

    /* Delay: '<S73>/Delay' */
    if (THA_VC_Ref_B.LogicalOperator && ((uint32_T)
         THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_lhwz != POS_ZCSIG)) {
      THA_VC_Ref_DW.Delay_DSTATE_j2qc = 0.0F;
    }

    THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_lhwz = THA_VC_Ref_B.LogicalOperator ?
      (ZCSigState)1 : (ZCSigState)0;
    THA_VC_Ref_B.Delay_bri0 = THA_VC_Ref_DW.Delay_DSTATE_j2qc;

    /* End of Delay: '<S73>/Delay' */

    /* Product: '<S73>/Product' */
    THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.Delay_bri0 *
      THA_VC_Ref_ConstB.one_minus_alpha_kfc5;

    /* Product: '<S73>/Product1' */
    THA_VC_Ref_B.Square3 = THA_VC_Ref_B.x * THA_VC_Ref_ConstB.alpha_n3n2;

    /* Sum: '<S73>/Sum' */
    THA_VC_Ref_B.Sum_ewt2 = THA_VC_Ref_B.Square3 + THA_VC_Ref_B.Add1_jabu;

    /* DataTypeConversion: '<S10>/Data Type Conversion6' */
    THA_VC_Ref_B.DataTypeConversion6 = THA_VC_Ref_B.Sum_ewt2;

    /* Delay: '<S74>/Delay' */
    if (THA_VC_Ref_B.LogicalOperator && ((uint32_T)
         THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_pmiu != POS_ZCSIG)) {
      THA_VC_Ref_DW.Delay_DSTATE_h4yd = 0.0F;
    }

    THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_pmiu = THA_VC_Ref_B.LogicalOperator ?
      (ZCSigState)1 : (ZCSigState)0;
    THA_VC_Ref_B.Delay_atsl = THA_VC_Ref_DW.Delay_DSTATE_h4yd;

    /* End of Delay: '<S74>/Delay' */

    /* Product: '<S74>/Product' */
    THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.Delay_atsl *
      THA_VC_Ref_ConstB.one_minus_alpha_nbz0;

    /* Product: '<S74>/Product1' */
    THA_VC_Ref_B.Square3 = THA_VC_Ref_B.y * THA_VC_Ref_ConstB.alpha_nu5l;

    /* Sum: '<S74>/Sum' */
    THA_VC_Ref_B.Sum_dtuk = THA_VC_Ref_B.Square3 + THA_VC_Ref_B.Add1_jabu;

    /* DataTypeConversion: '<S10>/Data Type Conversion7' */
    THA_VC_Ref_B.DataTypeConversion7 = THA_VC_Ref_B.Sum_dtuk;

    /* DataTypeConversion: '<S10>/Data Type Conversion9' */
    THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.veh_x_dot_nnwm;

    /* Abs: '<S10>/Abs' */
    THA_VC_Ref_B.Abs_onz4 = fabsf(THA_VC_Ref_B.Add1_jabu);

    /* DataTypeConversion: '<S10>/Data Type Conversion13' */
    THA_VC_Ref_B.DataTypeConversion13 = THA_VC_Ref_B.veh_y_dot_p3vd;

    /* DataTypeConversion: '<S10>/Data Type Conversion14' */
    THA_VC_Ref_B.DataTypeConversion14 = THA_VC_Ref_B.veh_theta_dot_ktag;

    /* Math: '<S36>/Square2' */
    THA_VC_Ref_B.Add1_jabu = THA_VC_Ref_B.veh_x_dot * THA_VC_Ref_B.veh_x_dot;

    /* Math: '<S36>/Square3' */
    THA_VC_Ref_B.Square3 = THA_VC_Ref_B.veh_y_dot * THA_VC_Ref_B.veh_y_dot;

    /* Sum: '<S36>/Add1' */
    THA_VC_Ref_B.Add1_jabu += THA_VC_Ref_B.Square3;

    /* Sqrt: '<S36>/Square Root1' */
    THA_VC_Ref_B.SquareRoot1 = sqrtf(THA_VC_Ref_B.Add1_jabu);

    /* MATLAB Function: '<S36>/MATLAB Function1' */
    THA_VC_Ref_B.ds = THA_VC_Ref_B.SquareRoot1 *
      THA_VC_Ref_ConstB.DataTypeConversion27;
    THA_VC_Ref_B.dx = THA_VC_Ref_B.veh_x_dot *
      THA_VC_Ref_ConstB.DataTypeConversion27;
    THA_VC_Ref_B.dy = THA_VC_Ref_B.veh_y_dot *
      THA_VC_Ref_ConstB.DataTypeConversion27;
    THA_VC_Ref_B.dyaw = THA_VC_Ref_B.veh_theta_dot *
      THA_VC_Ref_ConstB.DataTypeConversion27;

    /* DataTypeConversion: '<S10>/Data Type Conversion10' */
    THA_VC_Ref_B.DataTypeConversion10 = THA_VC_Ref_B.dy;

    /* DataTypeConversion: '<S10>/Data Type Conversion11' */
    THA_VC_Ref_B.DataTypeConversion11 = THA_VC_Ref_B.dyaw;

    /* DataTypeConversion: '<S10>/Data Type Conversion15' */
    THA_VC_Ref_B.DataTypeConversion15 = THA_VC_Ref_B.ds;

    /* DataTypeConversion: '<S10>/Data Type Conversion16' */
    THA_VC_Ref_B.DataTypeConversion16 = THA_VC_Ref_B.dx;

    /* DataTypeConversion: '<S10>/Data Type Conversion12' */
    THA_VC_Ref_B.DataTypeConversion12 = THA_VC_Ref_B.km_err;

    /* Math: '<S36>/Hypot' */
    THA_VC_Ref_B.Hypot = rt_hypotf(THA_VC_Ref_B.veh_x_dot,
      THA_VC_Ref_B.veh_y_dot);

    /* Gain: '<S46>/Gain1' */
    THA_VC_Ref_B.Gain4 *= 0.0174532924F;

    /* Gain: '<S10>/Gain4' */
    THA_VC_Ref_B.Gain4 *= 57.2957802F;

    /* DataTypeConversion: '<S10>/Data Type Conversion17' */
    *rty_MeTHA_deg_RoadWhlAng = THA_VC_Ref_B.Gain4;

    /* Update for Delay: '<S36>/Delay One Step' */
    THA_VC_Ref_DW.DelayOneStep_DSTATE = THA_VC_Ref_B.OR;

    /* Update for Delay: '<S69>/Delay' */
    THA_VC_Ref_DW.Delay_DSTATE = THA_VC_Ref_B.Sum;

    /* Update for Delay: '<S70>/Delay' */
    THA_VC_Ref_DW.Delay_DSTATE_lu4u = THA_VC_Ref_B.Sum_pkps;

    /* Update for Delay: '<S71>/Delay' */
    THA_VC_Ref_DW.Delay_DSTATE_psr1 = THA_VC_Ref_B.Sum_jqym;

    /* Update for Delay: '<S72>/Delay' */
    THA_VC_Ref_DW.Delay_DSTATE_nkk5 = THA_VC_Ref_B.Sum_fdny;

    /* Update for Delay: '<S75>/Delay' */
    THA_VC_Ref_DW.Delay_DSTATE_pwdf = THA_VC_Ref_B.Sum_d1um;

    /* Update for UnitDelay: '<S38>/Unit Delay' */
    THA_VC_Ref_DW.UnitDelay_DSTATE_dk0c = THA_VC_Ref_B.MeTHA_mps_KMSpeed_FW;

    /* Update for UnitDelay: '<S38>/Unit Delay1' */
    THA_VC_Ref_DW.UnitDelay1_DSTATE = THA_VC_Ref_B.MeTHA_mps_KMSpeed_FW;

    /* Update for UnitDelay: '<S38>/Unit Delay2' */
    THA_VC_Ref_DW.UnitDelay2_DSTATE = THA_VC_Ref_B.UnitDelay1;

    /* Update for UnitDelay: '<S38>/Unit Delay3' */
    THA_VC_Ref_DW.UnitDelay3_DSTATE_ogzh = THA_VC_Ref_B.UnitDelay2;

    /* Update for UnitDelay: '<S43>/Unit Delay' */
    THA_VC_Ref_DW.UnitDelay_DSTATE_efpz = THA_VC_Ref_B.Sum_gpp3;

    /* Update for UnitDelay: '<S42>/Unit Delay1' */
    THA_VC_Ref_DW.UnitDelay1_DSTATE_njpd = THA_VC_Ref_B.Sum1;

    /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
    THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE += 0.03F * THA_VC_Ref_B.Product2;
    if (THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE >=
        KsTHA_k_TrqCtrlIntExtSatTD[0]) {
      THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE = KsTHA_k_TrqCtrlIntExtSatTD[0];
    } else {
      if (THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE <=
          -KsTHA_k_TrqCtrlIntExtSatTD[0]) {
        THA_VC_Ref_DW.DiscreteTimeIntegrator_DSTATE =
          -KsTHA_k_TrqCtrlIntExtSatTD[0];
      }
    }

    THA_VC_Ref_DW.DiscreteTimeIntegrator_PrevResetState = (int8_T)
      (THA_VC_Ref_B.MeTHA_b_VCActive ? 1 : 0);

    /* End of Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */

    /* Update for UnitDelay: '<S136>/Delay Input2'
     *
     * Block description for '<S136>/Delay Input2':
     *
     *  Store in Global RAM
     */
    THA_VC_Ref_DW.DelayInput2_DSTATE_ivvk = THA_VC_Ref_B.DifferenceInputs2;

    /* Update for Delay: '<S73>/Delay' */
    THA_VC_Ref_DW.Delay_DSTATE_j2qc = THA_VC_Ref_B.Sum_ewt2;

    /* Update for Delay: '<S74>/Delay' */
    THA_VC_Ref_DW.Delay_DSTATE_h4yd = THA_VC_Ref_B.Sum_dtuk;
  } else {
    if (THA_VC_Ref_DW.THA_KM_SteerTorque_Processing_MODE) {
      /* Disable for Enabled SubSystem: '<S39>/Subsystem' */
      if (THA_VC_Ref_DW.Subsystem_MODE) {
        /* Disable for Outport: '<S79>/Reset_time' */
        THA_VC_Ref_B.Discrete_Time_Integrator1_hao2 = 0.0F;
        THA_VC_Ref_DW.Subsystem_MODE = false;
      }

      /* End of Disable for SubSystem: '<S39>/Subsystem' */

      /* Disable for Enabled SubSystem: '<S10>/TrqControlOld' */
      THA_VC_Ref_DW.TrqControlOld_MODE = false;

      /* End of Disable for SubSystem: '<S10>/TrqControlOld' */

      /* Disable for Outport: '<S10>/MeTHA_deg_RoadWhlAng' */
      *rty_MeTHA_deg_RoadWhlAng = 0.0F;

      /* Disable for Outport: '<S10>/MeTHA_deg_StrAngCmd' */
      MeTHA_deg_StrAngCmd = 0.0F;
      THA_VC_Ref_DW.THA_KM_SteerTorque_Processing_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/THA_KM_SteerTorque_Processing' */

  /* Logic: '<S1>/Logical Operator7' */
  THA_VC_Ref_B.LogicalOperator6 = !THA_VC_Ref_B.LogicalOperator5;

  /* Logic: '<S1>/Logical Operator9' */
  THA_VC_Ref_B.RelationalOperator6 = !THA_VC_Ref_B.LogicalOperator3;

  /* Logic: '<S1>/Logical Operator10' */
  THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.LogicalOperator6 &&
    THA_VC_Ref_B.RelationalOperator6);

  /* Logic: '<S1>/Logical Operator8' */
  THA_VC_Ref_B.LogicalOperator8 = (THA_VC_Ref_B.MeTHA_b_ThaSmAbrtSts ||
    THA_VC_Ref_B.LogicalOperator6);

  /* Outputs for Enabled SubSystem: '<S1>/THA_MnvrAbort_SteerTorque_Processing' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (THA_VC_Ref_B.LogicalOperator8) {
    /* SignalConversion generated from: '<S11>/MeTHA_M_AbortStrTrq' incorporates:
     *  Constant: '<S11>/Constant'
     */
    THA_VC_Ref_B.Merge1 = KeTHA_M_AbortStrTrq;
  }

  /* End of Outputs for SubSystem: '<S1>/THA_MnvrAbort_SteerTorque_Processing' */

  /* UnitDelay: '<S8>/Delay Input2'
   *
   * Block description for '<S8>/Delay Input2':
   *
   *  Store in Global RAM
   */
  THA_VC_Ref_B.Yk1 = THA_VC_Ref_DW.DelayInput2_DSTATE;

  /* Sum: '<S8>/Difference Inputs1'
   *
   * Block description for '<S8>/Difference Inputs1':
   *
   *  Add in CPU
   */
  THA_VC_Ref_B.UkYk1 = THA_VC_Ref_B.Merge1 - THA_VC_Ref_B.Yk1;

  /* RelationalOperator: '<S13>/UpperRelop' */
  THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.UkYk1 <
    THA_VC_Ref_B.deltafalllimit);

  /* Switch: '<S13>/Switch' */
  if (THA_VC_Ref_B.LogicalOperator6) {
    THA_VC_Ref_B.Switch = THA_VC_Ref_B.deltafalllimit;
  } else {
    THA_VC_Ref_B.Switch = THA_VC_Ref_B.UkYk1;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Product: '<S8>/delta rise limit' */
  THA_VC_Ref_B.deltariselimit = THA_VC_Ref_B.Sum_hqju * THA_VC_Ref_B.sampletime;

  /* RelationalOperator: '<S13>/LowerRelop1' */
  THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.UkYk1 >
    THA_VC_Ref_B.deltariselimit);

  /* Switch: '<S13>/Switch2' */
  if (THA_VC_Ref_B.LogicalOperator6) {
    THA_VC_Ref_B.Switch2 = THA_VC_Ref_B.deltariselimit;
  } else {
    THA_VC_Ref_B.Switch2 = THA_VC_Ref_B.Switch;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Sum: '<S8>/Difference Inputs2'
   *
   * Block description for '<S8>/Difference Inputs2':
   *
   *  Add in CPU
   */
  *rty_IeTHA_M_THASteerTrqInfo = THA_VC_Ref_B.Switch2 + THA_VC_Ref_B.Yk1;

  /* Sum: '<S6>/Subtract' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  THA_VC_Ref_B.Sum_hqju = *rty_IeTHA_M_THASteerTrqInfo - 0.0F;

  /* Abs: '<S6>/Abs' */
  THA_VC_Ref_B.Sum_hqju = fabsf(THA_VC_Ref_B.Sum_hqju);

  /* RelationalOperator: '<S6>/RelationalOperator10' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.Sum_hqju < 0.0001F);

  /* Logic: '<S1>/Logical Operator' */
  THA_VC_Ref_B.LogicalOperator6 = !THA_VC_Ref_B.LogicalOperator6;

  /* RelationalOperator: '<S1>/RelationalOperator6' incorporates:
   *  Constant: '<S5>/Constant'
   */
  THA_VC_Ref_B.RelationalOperator6 = (*rtu_MeTHA_e_THASteerTrqReq ==
    TeTHA_e_THASteerTrqReq_True);

  /* Logic: '<S1>/Logical Operator6' */
  THA_VC_Ref_B.LogicalOperator6 = (THA_VC_Ref_B.LogicalOperator6 ||
    THA_VC_Ref_B.RelationalOperator6);

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   */
  if (THA_VC_Ref_B.LogicalOperator6) {
    *rty_IeTHA_e_THASteerTrqReq = TeTHA_e_THASteerTrqReq_True;
  } else {
    *rty_IeTHA_e_THASteerTrqReq = TeTHA_e_THASteerTrqReq_False;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Switch: '<S7>/Switch3' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S7>/Constant2'
   */
  if (THA_VC_Ref_B.MeTHA_b_VCActive) {
    THA_VC_Ref_B.Sum_hqju = KeTHA_s_ThaSampleTime;
  } else {
    THA_VC_Ref_B.Sum_hqju = 0.0F;
  }

  /* End of Switch: '<S7>/Switch3' */

  /* Sum: '<S7>/Sum' */
  THA_VC_Ref_B.Sum_hqju += THA_VC_Ref_B.Switch1;

  /* MinMax: '<S7>/MinMax' */
  THA_VC_Ref_B.MinMax = fminf(THA_VC_Ref_B.Sum_hqju,
    rtu_MbTHA_VrntTunParamOutData->KeTHA_s_SteerTweakTime);

  /* Constant: '<S1>/Constant' */
  *rty_IeTHA_pct_THAStrDamp = KeTHA_pct_StrDampDefault;

  /* RelationalOperator: '<S2>/RelationalOperator2' incorporates:
   *  Constant: '<S142>/Constant'
   */
  THA_VC_Ref_B.MeTHA_b_TrlrCplrReached = (*rtu_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Engaged_Inquiry);

  /* Saturate: '<S2>/Saturation2' */
  if (rtu_MbTHA_VehInpOutData->IeVBII_ddeg_VehYawRate > 40.0F) {
    THA_VC_Ref_B.Saturation2 = 40.0F;
  } else if (rtu_MbTHA_VehInpOutData->IeVBII_ddeg_VehYawRate < (-40.0F)) {
    THA_VC_Ref_B.Saturation2 = (-40.0F);
  } else {
    THA_VC_Ref_B.Saturation2 = rtu_MbTHA_VehInpOutData->IeVBII_ddeg_VehYawRate;
  }

  /* End of Saturate: '<S2>/Saturation2' */

  /* Update for UnitDelay: '<S7>/UnitDelay3' */
  THA_VC_Ref_DW.UnitDelay3_DSTATE = THA_VC_Ref_B.MinMax;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  THA_VC_Ref_DW.UnitDelay_DSTATE_dqs4 = THA_VC_Ref_B.LogicalOperator5;

  /* Update for UnitDelay: '<S8>/Delay Input2'
   *
   * Block description for '<S8>/Delay Input2':
   *
   *  Store in Global RAM
   */
  THA_VC_Ref_DW.DelayInput2_DSTATE = *rty_IeTHA_M_THASteerTrqInfo;
  //Dipti : Prints for Trq Controller
  #if DEBUG_PRINTS
  if((*rtu_MeTHA_e_THAStateInfo) == TeTHA_e_THAStateInfo_Engaged || (*rtu_MeTHA_e_THAStateInfo) == TeTHA_e_THAStateInfo_Engaged_Delta ||
  (*rtu_MeTHA_e_THAStateInfo) == TeTHA_e_THAStateInfo_Engaged_Inquiry || (*rtu_MeTHA_e_THAStateInfo) == TeTHA_e_THAStateInfo_Complete)
  {
    uint64_t time = 0;
    char buf[100];
    time = TimerP_getTimeInUsecs();
    sprintf(buf,"THA:%lld, %f, %f, %f\n",time,
    rtu_MbTHA_VehInpOutData->IeVBII_deg_StrWhlAng,
    MeTHA_deg_StrAngCmd,
    *rty_IeTHA_M_THASteerTrqInfo);
    UART_printf( "%s", buf );
  }
  //Dipti : WorkAround for mapping strAngCmd to RoadWhlAng and Snooping variables
  //MeTHA_deg_RoadWhlAng = MeTHA_deg_StrAngCmd;
  plot_StrAngCmd = MeTHA_deg_StrAngCmd;
  plot_THASteerTrqInfo = *rty_IeTHA_M_THASteerTrqInfo;
  #endif
}

/* Model initialize function */
void THA_VC_Ref_initialize(void)
{
  THA_VC_Ref_PrevZCX.ResettableDelay_Reset_ZCE = POS_ZCSIG;
  THA_VC_Ref_PrevZCX.ResettableDelay_Reset_ZCE_ajsj = POS_ZCSIG;
  THA_VC_Ref_PrevZCX.Delay_Reset_ZCE = POS_ZCSIG;
  THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_pnvs = POS_ZCSIG;
  THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_cdhr = POS_ZCSIG;
  THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_kvqh = POS_ZCSIG;
  THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_cqgx = POS_ZCSIG;
  THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_lhwz = POS_ZCSIG;
  THA_VC_Ref_PrevZCX.Delay_Reset_ZCE_pmiu = POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
