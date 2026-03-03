/*
 * File: KM.c
 *
 * Code generated for Simulink model 'KM'.
 *
 * Model version                  : 1.94
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov 29 21:10:01 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "KM.h"
#include "KM_private.h"
#include "look1_iflf_binlx.h"
#include "rt_remf_snf.h"

/* Block signals (default storage) */
B_KM_T KM_B;

/* Block states (default storage) */
DW_KM_T KM_DW;

/* External inputs (root inport signals with default storage) */
ExtU_KM_T KM_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_KM_T KM_Y;

/* Model step function */
void KM_step(void)
{
  real32_T delta_pulses_RR;
  real32_T delta_pulses_RL;
  int8_T n;
  real32_T absx;

  /* Delay: '<S1>/Delay8' */
  KM_B.Delay8[0] = KM_B.DiscreteTimeIntegrator1[0];
  KM_B.Delay8[1] = KM_B.DiscreteTimeIntegrator1[1];

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/potMap_reset_KM'
   */
  KM_B.DataTypeConversion1 = KM_U.potMap_reset_KM;

  /* Delay: '<S1>/Delay4' */
  KM_B.LogicalOperator5 = KM_DW.Delay4_DSTATE;

  /* Logic: '<S1>/Logical Operator4' */
  KM_B.LogicalOperator5 = !KM_B.LogicalOperator5;

  /* Logic: '<S1>/Logical Operator3' */
  KM_B.LogicalOperator3 = ((KM_B.DataTypeConversion1) && (KM_B.LogicalOperator5));

  /* Delay: '<S1>/Delay5' */
  KM_B.Delay5 = KM_B.reset_KM;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  KM_B.DataTypeConversion2 = (real32_T)KM_B.Delay5;

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   */
  KM_B.LogicalOperator5 = (KM_B.Delay8[0] == 0.0F);

  /* Delay: '<S1>/Delay7' */
  KM_B.Delay7 = KM_B.Compare_b42h;

  /* Delay: '<S1>/Delay6' */
  KM_B.Delay6 = KM_B.Compare;

  /* Logic: '<S1>/Logical Operator5' */
  KM_B.LogicalOperator5 = (((KM_B.LogicalOperator5) && (KM_B.Delay7)) &&
    (KM_B.Delay6));

  /* RateTransition: '<S1>/Rate Transition3' */
  KM_B.RateTransition3 = KM_B.LogicalOperator5;

  /* MATLAB Function: '<S1>/KM_Reset Decision Function' */
  KM_B.reset_KM = 0.0;
  if ((KM_B.LogicalOperator3) || (KM_B.DataTypeConversion2 != 0.0F)) {
    KM_B.reset_KM = 1.0;
  }

  if (KM_B.RateTransition3) {
    KM_B.reset_KM = 0.0;
  }

  /* End of MATLAB Function: '<S1>/KM_Reset Decision Function' */

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Constant: '<S1>/KM_reset'
   */
  KM_B.LogicalOperator1 = ((KM_B.reset_KM != 0.0) || (false));

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  if ((KM_B.LogicalOperator1) || (KM_DW.DiscreteTimeIntegrator1_PrevResetState
       != 0)) {
    KM_DW.DiscreteTimeIntegrator1_DSTATE[0] = KM_ConstB.xy_init[0];
    KM_DW.DiscreteTimeIntegrator1_DSTATE[1] = KM_ConstB.xy_init[1];
  }

  KM_B.DiscreteTimeIntegrator1[0] = KM_DW.DiscreteTimeIntegrator1_DSTATE[0];
  KM_B.DiscreteTimeIntegrator1[1] = KM_DW.DiscreteTimeIntegrator1_DSTATE[1];

  /* End of DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */

  /* Outport: '<Root>/m_Global_x ' */
  KM_Y.m_Global_x = KM_B.DiscreteTimeIntegrator1[0];

  /* Outport: '<Root>/m_Global_y ' */
  KM_Y.m_Global_y = KM_B.DiscreteTimeIntegrator1[1];

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  if ((KM_B.LogicalOperator1) || (KM_DW.DiscreteTimeIntegrator_PrevResetState !=
       0)) {
    KM_DW.DiscreteTimeIntegrator_DSTATE = KM_ConstB.heading_init;
  }

  KM_B.DiscreteTimeIntegrator = KM_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  KM_Y.heading_MABx = KM_B.DiscreteTimeIntegrator;

  /*  heading angle is between -180 and 180 */
  while (KM_Y.heading_MABx < -180.0F) {
    KM_Y.heading_MABx += 360.0F;
  }

  while (KM_Y.heading_MABx > 180.0F) {
    KM_Y.heading_MABx -= 360.0F;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function4' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Inport: '<Root>/GearEngagedData'
   */
  /*  1: Forward and -1: Backward */
  switch (KM_U.GearEngagedData) {
   case 14:
    KM_B.direction = -1.0F;
    break;

   case 13:
    KM_B.direction = 0.0F;
    break;

   default:
    KM_B.direction = 1.0F;
    break;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/IePRX_mm_TyreSize'
   */
  KM_B.MeKM_m_WhlCircum = (((real32_T)((uint16_T)33554U)) * 2.98023224E-8F) *
    ((real32_T)KM_U.IePRX_mm_TyreSize);

  /* MATLAB Function: '<S1>/Rear axle speed conversion ' incorporates:
   *  Inport: '<Root>/LHRWheelSpeedData'
   *  Inport: '<Root>/RHRWheelSpeedData'
   */
  /*  WheelCircumference_m = 2.06248; % (m/rev.) C - class */
  KM_B.speed_Rear_axle_mps = ((KM_U.RHRWheelSpeedData + KM_U.LHRWheelSpeedData) /
    2.0F) / 3.6F;

  /* Delay: '<S1>/Delay1' incorporates:
   *  Inport: '<Root>/RHR_FastPulseCounterData'
   */
  /*  (m/s) */
  if (((int32_T)KM_DW.icLoad) != 0) {
    KM_DW.Delay1_DSTATE = KM_U.RHR_FastPulseCounterData;
  }

  KM_B.Delay1 = KM_DW.Delay1_DSTATE;

  /* End of Delay: '<S1>/Delay1' */

  /* Delay: '<S1>/Delay2' incorporates:
   *  Inport: '<Root>/LHR_FastPulseCounterData'
   */
  if (((int32_T)KM_DW.icLoad_eoqx) != 0) {
    KM_DW.Delay2_DSTATE = KM_U.LHR_FastPulseCounterData;
  }

  KM_B.Delay2 = KM_DW.Delay2_DSTATE;

  /* End of Delay: '<S1>/Delay2' */

  /* Abs: '<S1>/Abs' incorporates:
   *  Inport: '<Root>/LwsAngleData'
   */
  KM_B.Abs = fabsf(KM_U.LwsAngleData);

  /* Lookup_n-D: '<S11>/steering_XXc.mat2' */
  KM_B.steering_XXcmat2 = look1_iflf_binlx(KM_B.Abs,
    KM_ConstP.steering_XXcmat2_bp01Data, KM_ConstP.steering_XXcmat2_tableData,
    8U);

  /* Signum: '<S1>/Sign' incorporates:
   *  Inport: '<Root>/LwsAngleData'
   *  Switch: '<S1>/Switch'
   */
  if (KM_U.LwsAngleData < 0.0F) {
    KM_B.Sign = -1.0F;
  } else if (KM_U.LwsAngleData > 0.0F) {
    KM_B.Sign = 1.0F;
  } else if (KM_U.LwsAngleData == 0.0F) {
    KM_B.Sign = 0.0F;
  } else {
    KM_B.Sign = (rtNaNF);
  }

  /* End of Signum: '<S1>/Sign' */

  /* MultiPortSwitch: '<S11>/Multiport Switch' incorporates:
   *  Inport: '<Root>/IePRX_e_StrRatRckPinionTyp'
   *  Switch: '<S1>/Switch'
   */
  switch (KM_U.IePRX_e_StrRatRckPinionTyp) {
   case 0:
    /* Lookup_n-D: '<S11>/steering_XXc.mat' */
    KM_B.steering_XXcmat = look1_iflf_binlx(KM_B.Abs,
      KM_ConstP.steering_XXcmat_bp01Data, KM_ConstP.steering_XXcmat_tableData,
      8U);
    KM_B.MeKM_deg_strAngtoWhlAng = KM_B.steering_XXcmat;
    break;

   case 1:
    /* Lookup_n-D: '<S11>/steering_XXc.mat1' */
    KM_B.steering_XXcmat1 = look1_iflf_binlx(KM_B.Abs,
      KM_ConstP.steering_XXcmat1_bp01Data, KM_ConstP.steering_XXcmat1_tableData,
      8U);
    KM_B.MeKM_deg_strAngtoWhlAng = KM_B.steering_XXcmat1;
    break;

   case 2:
    KM_B.MeKM_deg_strAngtoWhlAng = KM_B.steering_XXcmat2;
    break;

   default:
    KM_B.MeKM_deg_strAngtoWhlAng = KM_B.steering_XXcmat2;
    break;
  }

  /* End of MultiPortSwitch: '<S11>/Multiport Switch' */

  /* Product: '<S1>/Product' incorporates:
   *  Switch: '<S1>/Switch'
   */
  KM_B.Product = KM_B.MeKM_deg_strAngtoWhlAng * KM_B.Sign;

  /* Switch: '<S1>/Switch' */
  KM_B.whl_angl = KM_B.Product;

  /* MultiPortSwitch: '<S12>/Multiport Switch' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant2'
   *  Constant: '<S12>/Constant3'
   *  Inport: '<Root>/IePRX_e_VehWhlBase'
   */
  switch (KM_U.IePRX_e_VehWhlBase) {
   case 0:
    KM_B.MeKM_m_WhlBase = 3.5687F;
    break;

   case 1:
    KM_B.MeKM_m_WhlBase = 3.6703F;
    break;

   case 2:
    KM_B.MeKM_m_WhlBase = 3.8989F;
    break;

   default:
    KM_B.MeKM_m_WhlBase = 3.6703F;
    break;
  }

  /* End of MultiPortSwitch: '<S12>/Multiport Switch' */

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  Inport: '<Root>/LHR_FastPulseCounterData'
   *  Inport: '<Root>/RHR_FastPulseCounterData'
   */
  /*  WheelCircumference_m = single(2.06248); % (m/rev.) */
  /*  (pulses/rev.) */
  /*  Wheel_Base = single(2.84); % (m) */
  /*  (pulses/m) */
  /*  (s) */
  delta_pulses_RR = 0.0F;
  delta_pulses_RL = 0.0F;
  if (KM_B.speed_Rear_axle_mps > 0.5F) {
    KM_B.ds_Rear_axle_m = KM_B.speed_Rear_axle_mps;
  } else {
    /*  at low speed we use pulse count */
    if (KM_U.RHR_FastPulseCounterData >= KM_B.Delay1) {
      delta_pulses_RR = KM_U.RHR_FastPulseCounterData - KM_B.Delay1;
    } else {
      if (KM_U.RHR_FastPulseCounterData < KM_B.Delay1) {
        delta_pulses_RR = (KM_U.RHR_FastPulseCounterData + 254.0F) - KM_B.Delay1;
      }
    }

    if (KM_U.LHR_FastPulseCounterData >= KM_B.Delay2) {
      delta_pulses_RL = KM_U.LHR_FastPulseCounterData - KM_B.Delay2;
    } else {
      if (KM_U.LHR_FastPulseCounterData < KM_B.Delay2) {
        delta_pulses_RL = (KM_U.LHR_FastPulseCounterData + 254.0F) - KM_B.Delay2;
      }
    }

    KM_B.ds_Rear_axle_m = (((delta_pulses_RR + delta_pulses_RL) / 2.0F) *
      0.0262F) / 0.01F;
  }

  if ((rtIsInfF(KM_B.whl_angl)) || (rtIsNaNF(KM_B.whl_angl))) {
    delta_pulses_RR = (rtNaNF);
  } else {
    delta_pulses_RR = rt_remf_snf(KM_B.whl_angl, 360.0F);
    absx = fabsf(delta_pulses_RR);
    if (absx > 180.0F) {
      if (delta_pulses_RR > 0.0F) {
        delta_pulses_RR -= 360.0F;
      } else {
        delta_pulses_RR += 360.0F;
      }

      absx = fabsf(delta_pulses_RR);
    }

    if (absx <= 45.0F) {
      delta_pulses_RR *= 0.0174532924F;
      n = 0;
    } else if (absx <= 135.0F) {
      if (delta_pulses_RR > 0.0F) {
        delta_pulses_RR = 0.0174532924F * (delta_pulses_RR - 90.0F);
        n = 1;
      } else {
        delta_pulses_RR = 0.0174532924F * (delta_pulses_RR + 90.0F);
        n = -1;
      }
    } else if (delta_pulses_RR > 0.0F) {
      delta_pulses_RR = 0.0174532924F * (delta_pulses_RR - 180.0F);
      n = 2;
    } else {
      delta_pulses_RR = 0.0174532924F * (delta_pulses_RR + 180.0F);
      n = -2;
    }

    delta_pulses_RR = tanf(delta_pulses_RR);
    if ((n == 1) || (n == -1)) {
      delta_pulses_RL = 1.0F / delta_pulses_RR;
      delta_pulses_RR = -(1.0F / delta_pulses_RR);
      if ((rtIsInfF(delta_pulses_RR)) && (n == 1)) {
        delta_pulses_RR = delta_pulses_RL;
      }
    }
  }

  /* Outport: '<Root>/dyaw' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function2'
   */
  KM_Y.dyaw = (((KM_B.ds_Rear_axle_m * delta_pulses_RR) / KM_B.MeKM_m_WhlBase) *
               57.2957802F) * KM_B.direction;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Outport: '<Root>/heading_MABx'
   */
  if ((rtIsInfF(KM_Y.heading_MABx)) || (rtIsNaNF(KM_Y.heading_MABx))) {
    delta_pulses_RR = (rtNaNF);
    delta_pulses_RL = (rtNaNF);
  } else {
    delta_pulses_RL = rt_remf_snf(KM_Y.heading_MABx, 360.0F);
    delta_pulses_RR = delta_pulses_RL;
    absx = fabsf(delta_pulses_RL);
    if (absx > 180.0F) {
      if (delta_pulses_RL > 0.0F) {
        delta_pulses_RR = delta_pulses_RL - 360.0F;
      } else {
        delta_pulses_RR = delta_pulses_RL + 360.0F;
      }

      absx = fabsf(delta_pulses_RR);
    }

    if (absx <= 45.0F) {
      delta_pulses_RR *= 0.0174532924F;
      n = 0;
    } else if (absx <= 135.0F) {
      if (delta_pulses_RR > 0.0F) {
        delta_pulses_RR = 0.0174532924F * (delta_pulses_RR - 90.0F);
        n = 1;
      } else {
        delta_pulses_RR = 0.0174532924F * (delta_pulses_RR + 90.0F);
        n = -1;
      }
    } else if (delta_pulses_RR > 0.0F) {
      delta_pulses_RR = 0.0174532924F * (delta_pulses_RR - 180.0F);
      n = 2;
    } else {
      delta_pulses_RR = 0.0174532924F * (delta_pulses_RR + 180.0F);
      n = -2;
    }

    switch (n) {
     case 0:
      delta_pulses_RR = cosf(delta_pulses_RR);
      break;

     case 1:
      delta_pulses_RR = -sinf(delta_pulses_RR);
      break;

     case -1:
      delta_pulses_RR = sinf(delta_pulses_RR);
      break;

     default:
      delta_pulses_RR = -cosf(delta_pulses_RR);
      break;
    }

    absx = fabsf(delta_pulses_RL);
    if (absx > 180.0F) {
      if (delta_pulses_RL > 0.0F) {
        delta_pulses_RL -= 360.0F;
      } else {
        delta_pulses_RL += 360.0F;
      }

      absx = fabsf(delta_pulses_RL);
    }

    if (absx <= 45.0F) {
      delta_pulses_RL *= 0.0174532924F;
      n = 0;
    } else if (absx <= 135.0F) {
      if (delta_pulses_RL > 0.0F) {
        delta_pulses_RL = 0.0174532924F * (delta_pulses_RL - 90.0F);
        n = 1;
      } else {
        delta_pulses_RL = 0.0174532924F * (delta_pulses_RL + 90.0F);
        n = -1;
      }
    } else if (delta_pulses_RL > 0.0F) {
      delta_pulses_RL = 0.0174532924F * (delta_pulses_RL - 180.0F);
      n = 2;
    } else {
      delta_pulses_RL = 0.0174532924F * (delta_pulses_RL + 180.0F);
      n = -2;
    }

    switch (n) {
     case 0:
      delta_pulses_RL = sinf(delta_pulses_RL);
      break;

     case 1:
      delta_pulses_RL = cosf(delta_pulses_RL);
      break;

     case -1:
      delta_pulses_RL = -cosf(delta_pulses_RL);
      break;

     default:
      delta_pulses_RL = -sinf(delta_pulses_RL);
      break;
    }
  }

  KM_B.dx_dy_m[0] = ((-delta_pulses_RR) * KM_B.ds_Rear_axle_m) * KM_B.direction;
  KM_B.dx_dy_m[1] = ((-delta_pulses_RL) * KM_B.ds_Rear_axle_m) * KM_B.direction;

  /* End of MATLAB Function: '<S1>/MATLAB Function3' */

  /* Outport: '<Root>/dx_m' */
  KM_Y.dx_m = KM_B.dx_dy_m[0];

  /* Outport: '<Root>/dy_m' */
  KM_Y.dy_m = KM_B.dx_dy_m[1];

  /* Outport: '<Root>/ds' incorporates:
   *  Gain: '<S1>/Multiply'
   */
  KM_Y.ds = 3.6F * KM_B.ds_Rear_axle_m;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  KM_B.Compare = (KM_B.DiscreteTimeIntegrator == 0.0F);

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   */
  KM_B.Compare_b42h = (KM_B.Delay8[1] == 0.0F);

  /* Update for Delay: '<S1>/Delay4' */
  KM_DW.Delay4_DSTATE = KM_B.DataTypeConversion1;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  KM_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.01F * KM_B.dx_dy_m[0];
  KM_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.01F * KM_B.dx_dy_m[1];
  KM_DW.DiscreteTimeIntegrator1_PrevResetState = (int8_T)(KM_B.LogicalOperator1 ?
    1 : 0);

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Outport: '<Root>/dyaw'
   */
  KM_DW.DiscreteTimeIntegrator_DSTATE += 0.01F * KM_Y.dyaw;
  KM_DW.DiscreteTimeIntegrator_PrevResetState = (int8_T)(KM_B.LogicalOperator1 ?
    1 : 0);

  /* Update for Delay: '<S1>/Delay1' incorporates:
   *  Inport: '<Root>/RHR_FastPulseCounterData'
   */
  KM_DW.icLoad = 0U;
  KM_DW.Delay1_DSTATE = KM_U.RHR_FastPulseCounterData;

  /* Update for Delay: '<S1>/Delay2' incorporates:
   *  Inport: '<Root>/LHR_FastPulseCounterData'
   */
  KM_DW.icLoad_eoqx = 0U;
  KM_DW.Delay2_DSTATE = KM_U.LHR_FastPulseCounterData;
}

/* Model initialize function */
void KM_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &KM_B), 0,
                sizeof(B_KM_T));

  /* states (dwork) */
  (void) memset((void *)&KM_DW, 0,
                sizeof(DW_KM_T));

  /* external inputs */
  (void)memset(&KM_U, 0, sizeof(ExtU_KM_T));

  /* external outputs */
  (void) memset((void *)&KM_Y, 0,
                sizeof(ExtY_KM_T));

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  KM_DW.DiscreteTimeIntegrator1_DSTATE[0] = KM_ConstB.xy_init[0];
  KM_DW.DiscreteTimeIntegrator1_DSTATE[1] = KM_ConstB.xy_init[1];
  KM_DW.DiscreteTimeIntegrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  KM_DW.DiscreteTimeIntegrator_DSTATE = KM_ConstB.heading_init;
  KM_DW.DiscreteTimeIntegrator_PrevResetState = 0;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  KM_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S1>/Delay2' */
  KM_DW.icLoad_eoqx = 1U;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
