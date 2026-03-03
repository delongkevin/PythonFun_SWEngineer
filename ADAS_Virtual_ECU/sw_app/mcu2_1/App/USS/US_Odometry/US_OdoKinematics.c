/*
 * File: US_OdoKinematic.c
 *
 * Code generated for Simulink model 'Kinematic'.
 *
 * Model version                  : 1.6980
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Fri Dec  3 10:30:35 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. Traceability
 *    5. Safety precaution
 *    6. Debugging
 *    7. MISRA C:2012 guidelines
 *    8. Polyspace
 * Validation result: Not run
 */
 

#include "US_OdoKinematics.h"
#include "US_Odometry_Global.h"
#include "US_OdoKinematics_private.h"
#include "US_ComInputBuffer_Global.h"
#include "US_Platform_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_PlatformCfg_Global.h"

static UssOdo_OdoAccumOutput_t sOdoAccumOut;
static bool_t bClearAccum = ME_TRUE;

#if (US_D_ENABLE_EXT_ODOM_DEBUG == ME_TRUE)
static   UssOdo_DebugOutput_t sOdoDebugInfo;
    #define US_D_ODO_DEBUG_MAX_DIST     (32000.0f)
    #define US_D_ODO_DEBUG_MIN_DIST     (-32000.0f)
    #define US_D_ODO_DEBUG_MAX_DEG      (640.0f) /*0.02deg scale on CAN */
    #define US_D_ODO_DEBUG_MIN_DEG      (-640.0f)
#endif

#if (US_D_USE_EXTERNAL_ODOMETRY == ME_FALSE)
    static uint32_t uLastOdoTimestamp = ZERO;
#else
    static IKinematicData_t sKinematicData;
    static float32_t fLastOdoTimestamp = 0.0f;
#endif

/*60 ms */
#define US_D_MAX_DEL_TIME_PLAUSABLE  (0.060f)

#if (US_D_USE_EXTERNAL_ODOMETRY == ME_FALSE)

/* Invariant block signals (auto storage) */
const ConstB_Kinematic_T Kinematic_ConstB = {
  { 0.0F, 0.0F },                      /* '<S1>/xy_init' */
  0.0F,                                /* '<S1>/heading_init' */
  0.0375001431F,                       /* '<S1>/Jeep' */
  -0.200000048F,                       /* '<S1>/Test Based Lookup Table1' */
  -0.08166F                            /* '<S1>/whl_ang_deg' */
};

static	US_S_KinematicCfg_t *pKinematicCfg = NULL;
#if 0
/* Constant parameters (auto storage) */
const ConstP_Kinematic_T Kinematic_ConstP = {
  /* Expression: [1.67 3.47 5.38 7.25 8.97 10.57 12.18 13.88 15.67 17.41 19.00 20.45 21.82 23.18 24.58 25.99 27.34 28.59 29.70 30.68 31.56 32.35 33.05 33.68 34.23 34.70 35.07]
   * Referenced by: '<S1>/Test Based Lookup Table'
   */
  {0, 6.34, 12.65, 19.15, 25.9, 32.95, 40.45},

  /* Expression: [31.1 62.2 93.1 123.7 154.0 183.8 213.2 242.0 270.1 297.5 324.0 349.7 374.4 398.1 420.7 442.1 462.3 481.3 498.9 515.2 530.1 543.5 555.4 565.8 574.6 581.9 587.6]
   * Referenced by: '<S1>/Test Based Lookup Table'
   */
  { 0, 110, 221, 331, 442, 552, 663}
};
#endif
UssOdo_OdometryData_t USS_Oddometry_v;

/* Block signals (auto storage) */
B_Kinematic_T Kinematic_B;

/* Block states (auto storage) */
DW_Kinematic_T Kinematic_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Kinematic_T Kinematic_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Kinematic_T Kinematic_Y;

static UssOdo_OdoAccumOutput_t sOdoAccumOut;
static bool_t bClearAccum = ME_TRUE;
static uint32_t uLastOdoTimestamp = ZERO;

/* Real-time model */
RT_MODEL_Kinematic_T Kinematic_M_;
RT_MODEL_Kinematic_T *const Kinematic_M = &Kinematic_M_;
static void rate_scheduler(void);
real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[], uint32_T
                   maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = (maxIndex >> 1U);
    iLeft = 0U;
    iRght = maxIndex;
    while ((iRght - iLeft) > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = ((iRght + iLeft) >> 1U);
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  return ((table[iLeft + 1U] - table[iLeft]) * frac) + table[iLeft];
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Kinematic_M->Timing.TaskCounters.TID[1])++;
  if ((Kinematic_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.02s, 0.0s] */
    Kinematic_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Kinematic_M->Timing.TaskCounters.TID[2])++;
  if ((Kinematic_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Kinematic_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_remd(real_T u0, real_T u1)
{
  real_T y;
  real_T q;
  if ((u1 != 0.0) && (u1 != trunc(u1))) {
    q = fabs(u0 / u1);
    if (fabs(q - floor(q + 0.5)) <= (ME_DBL_EPSILON * q)) {
      y = 0.0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

real32_T rt_remf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T q;
  if ((u1 != 0.0F) && (u1 != truncf(u1))) {
    q = fabsf(u0 / u1);
    if (fabsf(q - floorf(q + 0.5F)) <= (ME_FLT_EPSILON * q)) {
      y = 0.0F;
    } else {
      y = fmodf(u0, u1);
    }
  } else {
    y = fmodf(u0, u1);
  }

  return y;
}

/* Model step function */
void Kinematic_step(void)
{
  real32_T pulse_counter_RR;
  real32_T pulse_counter_RL;
  int8_T n;
  real_T absx;
  real32_T b_absx;
  real_T u;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/potMap_reset_KM'
   */
  Kinematic_B.DataTypeConversion1 = (Kinematic_U.potMap_reset_KM != 0.0);

  /* Delay: '<S1>/Delay4' */
  Kinematic_B.Delay4 = Kinematic_DW.Delay4_DSTATE;

  /* Logic: '<S1>/Logical Operator4' */
  Kinematic_B.LogicalOperator4 = !Kinematic_B.Delay4;

  /* Logic: '<S1>/Logical Operator3' */
  Kinematic_B.LogicalOperator3 = ((Kinematic_B.DataTypeConversion1) &&
    (Kinematic_B.LogicalOperator4));

  /* Delay: '<S1>/Delay5' */
  Kinematic_B.Delay5 = Kinematic_DW.Delay5_DSTATE;

  /* RateTransition: '<S1>/Rate Transition3' */
  if (Kinematic_M->Timing.TaskCounters.TID[1] == 0) {
    Kinematic_B.RateTransition3 = Kinematic_DW.RateTransition3_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition3' */

  /* MATLAB Function: '<S1>/KM_Reset Decision Function' */
  Kinematic_B.reset_KM = 0.0F;
  if ((Kinematic_B.LogicalOperator3) || (Kinematic_B.Delay5 != 0.0F)) {
    Kinematic_B.reset_KM = 1.0F;
  }

  if (Kinematic_B.RateTransition3) {
    Kinematic_B.reset_KM = 0.0F;
  }

  /* End of MATLAB Function: '<S1>/KM_Reset Decision Function' */

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Constant: '<S1>/KM_reset'
   */
  Kinematic_B.LogicalOperator1 = (Kinematic_B.reset_KM != 0.0F);
  if (Kinematic_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
    if ((Kinematic_B.LogicalOperator1) ||
        (Kinematic_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Kinematic_DW.DiscreteTimeIntegrator1_DSTATE[0] = Kinematic_ConstB.xy_init
        [0];
      Kinematic_DW.DiscreteTimeIntegrator1_DSTATE[1] = Kinematic_ConstB.xy_init
        [1];
    }

    Kinematic_B.DiscreteTimeIntegrator1[0] =
      Kinematic_DW.DiscreteTimeIntegrator1_DSTATE[0];
    Kinematic_B.DiscreteTimeIntegrator1[1] =
      Kinematic_DW.DiscreteTimeIntegrator1_DSTATE[1];

    /* End of DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */

    /* Outport: '<Root>/X_MABx' */
    Kinematic_Y.X_MABx = Kinematic_B.DiscreteTimeIntegrator1[0];

    /* Outport: '<Root>/Y_MABx' */
    Kinematic_Y.Y_MABx = Kinematic_B.DiscreteTimeIntegrator1[1];

    /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    if ((Kinematic_B.LogicalOperator1) ||
        (Kinematic_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
      Kinematic_DW.DiscreteTimeIntegrator_DSTATE = Kinematic_ConstB.heading_init;
    }

    Kinematic_B.DiscreteTimeIntegrator =
      Kinematic_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    for (pulse_counter_RR = Kinematic_B.DiscreteTimeIntegrator; pulse_counter_RR
         < 0.0F; pulse_counter_RR += 360.0F) {
    }

    while (pulse_counter_RR > 360.0F) {
      pulse_counter_RR -= 360.0F;
    }

    Kinematic_B.heading_MABx = pulse_counter_RR;

    /* End of MATLAB Function: '<S1>/MATLAB Function4' */

    /* Outport: '<Root>/heading_MABx' */
    Kinematic_Y.heading_MABx = Kinematic_B.heading_MABx;

    /* MATLAB Function: '<S1>/Rear axle speed conversion ' incorporates:
     *  Constant: '<S1>/whl_circum'
     *  Inport: '<Root>/WheelSpeed_Report.RL'
     *  Inport: '<Root>/WheelSpeed_Report.RR'
     */
    Kinematic_B.speed_Rear_axle_mps = ((real32_T)((real_T)(((Kinematic_U.RR +
      Kinematic_U.RL) / 7.2))));

    /* Delay: '<S1>/Delay1' incorporates:
     *  Inport: '<Root>/WheelPosition_Report.RR'
     */
    if (((int32_T)Kinematic_DW.icLoad) != 0) {
      Kinematic_DW.Delay1_DSTATE = Kinematic_U.RR_p;
    }

    Kinematic_B.Delay1 = Kinematic_DW.Delay1_DSTATE;

    /* End of Delay: '<S1>/Delay1' */

    /* Delay: '<S1>/Delay2' incorporates:
     *  Inport: '<Root>/WheelPosition_Report.RL'
     */
    if (((int32_T)Kinematic_DW.icLoad_b) != 0) {
      Kinematic_DW.Delay2_DSTATE = Kinematic_U.RL_p;
    }

    Kinematic_B.Delay2 = Kinematic_DW.Delay2_DSTATE;

    /* End of Delay: '<S1>/Delay2' */

    /* Signum: '<S1>/Sign' incorporates:
     *  Inport: '<Root>/Steering_Report.ANGLE'
     *  Switch: '<S1>/Switch'
     */
    u = Kinematic_U.ANGLE;
    if (u < 0.0) {
      Kinematic_B.Sign = -1.0;
    } else if (u > 0.0) {
      Kinematic_B.Sign = 1.0;
    } else {
      Kinematic_B.Sign = u;
    }
    /* End of Signum: '<S1>/Sign' */

    /* Abs: '<S1>/Abs' incorporates:
     *  Inport: '<Root>/Steering_Report.ANGLE'
     *  Switch: '<S1>/Switch'
     */
    Kinematic_B.Abs = fabs(Kinematic_U.ANGLE);
    /* Lookup_n-D: '<S1>/Test Based Lookup Table' incorporates:
     *  Switch: '<S1>/Switch'
     */
    /*
    Kinematic_B.TestBasedLookupTable = look1_binlx(Kinematic_B.Abs,
      Kinematic_ConstP.TestBasedLookupTable_bp01Data,
      Kinematic_ConstP.TestBasedLookupTable_tableData, 26U);
	*/
	if(pKinematicCfg != NULL)
	{
       Kinematic_B.TestBasedLookupTable=look1_binlx(Kinematic_B.Abs,
    		(const real_T*)pKinematicCfg->TestBasedLookupTable_bp01Data,
			(const real_T*)pKinematicCfg->TestBasedLookupTable_tableData,7U);
	}
    /* Product: '<S1>/Product' incorporates:
     *  Switch: '<S1>/Switch'
     */

    Kinematic_B.Product = Kinematic_B.TestBasedLookupTable * Kinematic_B.Sign;

    /* Switch: '<S1>/Switch' */
    Kinematic_B.whl_angl = Kinematic_B.Product;

    /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
     *  Inport: '<Root>/Gear_Report.Gear_RPT_STATE'
     */
    Kinematic_B.direction = 0;
    switch (Kinematic_U.Gear_RPT_STATE) {
     case 2:
      Kinematic_B.direction = -1;
      break;

     case 4:
      Kinematic_B.direction = 1;
      break;

     default:
      /* no actions */
      break;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function' */
  }

  if (Kinematic_M->Timing.TaskCounters.TID[2] == 0) {
    /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
     *  Constant: '<S1>/whl_base'
     *  Constant: '<S1>/whl_circum'
     *  Inport: '<Root>/WheelPosition_Report.RL'
     *  Inport: '<Root>/WheelPosition_Report.RR'
     */
    pulse_counter_RR = 0.0F;
    pulse_counter_RL = 0.0F;
    if (Kinematic_B.speed_Rear_axle_mps != 0.0F) {
      pulse_counter_RR = Kinematic_B.speed_Rear_axle_mps;
    } else {
      if ((((real32_T)Kinematic_U.RR_p)) > (((real32_T)
            Kinematic_B.Delay1))) {
        pulse_counter_RR = (((real32_T)Kinematic_U.RR_p)) -
          (((real32_T)Kinematic_B.Delay1));
      } else {
        if ((((real32_T)Kinematic_U.RR_p)) < (((real32_T)
              Kinematic_B.Delay1))) {
          pulse_counter_RR = ((Kinematic_U.max_Tick - (((real32_T)Kinematic_B.Delay1))) + 1.0F) + (((real32_T)Kinematic_U.RR_p));
        }
      }

      if ((((real32_T)Kinematic_U.RL_p)) > (((real32_T)
            Kinematic_B.Delay2))) {
        pulse_counter_RL = (((real32_T)Kinematic_U.RL_p)) -
          (((real32_T)Kinematic_B.Delay2));
      } else {
        if ((((real32_T)Kinematic_U.RL_p)) < (((real32_T)
              Kinematic_B.Delay2))) {
          pulse_counter_RL = ((Kinematic_U.max_Tick - (((real32_T)Kinematic_B.Delay2))) + 1.0F) + (((real32_T)Kinematic_U.RL_p));
        }
      }

      pulse_counter_RR = (((pulse_counter_RR + pulse_counter_RL) / 2.0F) /
                          (Kinematic_U.num_Pulses / Kinematic_U.whl_Circum)) / 0.1F;
    }

    u = rt_remd(Kinematic_B.whl_angl, 360.0);
    absx = fabs(u);
    if (absx > 180.0) {
      if (u > 0.0) {
        u -= 360.0;
      } else {
        u += 360.0;
      }

      absx = fabs(u);
    }

    if (absx <= 45.0) {
      u *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (u > 0.0) {
        u = (u - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        u = (u + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (u > 0.0) {
      u = (u - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      u = (u + 180.0) * 0.017453292519943295;
      n = -2;
    }

    u = tan(u);
    if ((n == 1) || (n == -1)) {
      u = -(1.0 / u);
    }

    Kinematic_B.d_heading_deg = ((pulse_counter_RR * ((real32_T)u)) / Kinematic_U.whl_Base) *
      57.2957802F*Kinematic_B.direction;
    Kinematic_B.ds_Rear_axle_m = pulse_counter_RR;

    /* End of MATLAB Function: '<S1>/MATLAB Function2' */
  }

  if (Kinematic_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (Kinematic_M->Timing.TaskCounters.TID[2] == 0) {
  }

  if (Kinematic_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (Kinematic_M->Timing.TaskCounters.TID[2] == 0) {
  }

  if (Kinematic_M->Timing.TaskCounters.TID[1] == 0) {
    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    Kinematic_B.Compare = (Kinematic_B.DiscreteTimeIntegrator == 0.0F);

    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     */
    Kinematic_B.Compare_c = (Kinematic_B.DiscreteTimeIntegrator1[0] == 0.0F);

    /* RelationalOperator: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant'
     */
    Kinematic_B.Compare_l = (Kinematic_B.DiscreteTimeIntegrator1[1] == 0.0F);

    /* Logic: '<S1>/Logical Operator5' */
    Kinematic_B.LogicalOperator5 = (((Kinematic_B.Compare_c) &&
      (Kinematic_B.Compare_l)) && (Kinematic_B.Compare));

    /* MATLAB Function: '<S1>/MATLAB Function3' */
    pulse_counter_RR = rt_remf(Kinematic_B.d_heading_deg, 360.0F);
    pulse_counter_RL = fabsf(pulse_counter_RR);
    if (pulse_counter_RL > 180.0F) {
      if (pulse_counter_RR > 0.0F) {
        pulse_counter_RR -= 360.0F;
      } else {
        pulse_counter_RR += 360.0F;
      }

      pulse_counter_RL = fabsf(pulse_counter_RR);
    }

    if (pulse_counter_RL <= 45.0F) {
      pulse_counter_RR *= 0.0174532924F;
      n = 0;
    } else if (pulse_counter_RL <= 135.0F) {
      if (pulse_counter_RR > 0.0F) {
        pulse_counter_RR = (pulse_counter_RR - 90.0F) * 0.0174532924F;
        n = 1;
      } else {
        pulse_counter_RR = (pulse_counter_RR + 90.0F) * 0.0174532924F;
        n = -1;
      }
    } else if (pulse_counter_RR > 0.0F) {
      pulse_counter_RR = (pulse_counter_RR - 180.0F) * 0.0174532924F;
      n = 2;
    } else {
      pulse_counter_RR = (pulse_counter_RR + 180.0F) * 0.0174532924F;
      n = -2;
    }

    switch (n) {
     case 0:
      pulse_counter_RR = cosf(pulse_counter_RR);
      break;

     case 1:
      pulse_counter_RR = -sinf(pulse_counter_RR);
      break;

     case -1:
      pulse_counter_RR = sinf(pulse_counter_RR);
      break;

     default:
      pulse_counter_RR = -cosf(pulse_counter_RR);
      break;
    }

    pulse_counter_RL = rt_remf(Kinematic_B.d_heading_deg, 360.0F);
    b_absx = fabsf(pulse_counter_RL);
    if (b_absx > 180.0F) {
      if (pulse_counter_RL > 0.0F) {
        pulse_counter_RL -= 360.0F;
      } else {
        pulse_counter_RL += 360.0F;
      }

      b_absx = fabsf(pulse_counter_RL);
    }

    if (b_absx <= 45.0F) {
      pulse_counter_RL *= 0.0174532924F;
      n = 0;
    } else if (b_absx <= 135.0F) {
      if (pulse_counter_RL > 0.0F) {
        pulse_counter_RL = (pulse_counter_RL - 90.0F) * 0.0174532924F;
        n = 1;
      } else {
        pulse_counter_RL = (pulse_counter_RL + 90.0F) * 0.0174532924F;
        n = -1;
      }
    } else if (pulse_counter_RL > 0.0F) {
      pulse_counter_RL = (pulse_counter_RL - 180.0F) * 0.0174532924F;
      n = 2;
    } else {
      pulse_counter_RL = (pulse_counter_RL + 180.0F) * 0.0174532924F;
      n = -2;
    }

    switch (n) {
     case 0:
      pulse_counter_RL = sinf(pulse_counter_RL);
      break;

     case 1:
      pulse_counter_RL = cosf(pulse_counter_RL);
      break;

     case -1:
      pulse_counter_RL = -cosf(pulse_counter_RL);
      break;

     default:
      pulse_counter_RL = -sinf(pulse_counter_RL);
      break;
    }

    Kinematic_B.dx_dy_m[0] = (pulse_counter_RR) * Kinematic_B.ds_Rear_axle_m*Kinematic_B.direction;
    Kinematic_B.dx_dy_m[1] = (pulse_counter_RL) * Kinematic_B.ds_Rear_axle_m*Kinematic_B.direction;

    /* End of MATLAB Function: '<S1>/MATLAB Function3' */
  }

  /* Delay: '<S1>/Delay3' */
  Kinematic_B.Delay3 = Kinematic_DW.Delay3_DSTATE;

  /* Sum: '<S1>/Counter' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Kinematic_B.Counter = 1.0 + Kinematic_B.Delay3;
  if (Kinematic_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outport: '<Root>/Outport1' */
    Kinematic_Y.Outport1 = Kinematic_B.ds_Rear_axle_m;

    /* Outport: '<Root>/Outport4' */
    Kinematic_Y.Outport4 = Kinematic_B.d_heading_deg;
  }

  if (Kinematic_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/Outport2' */
    Kinematic_Y.Outport2 = Kinematic_B.dx_dy_m[0];

    /* Outport: '<Root>/Outport3' */
    Kinematic_Y.Outport3 = Kinematic_B.dx_dy_m[1];
  }

  /* Update for Delay: '<S1>/Delay4' */
  Kinematic_DW.Delay4_DSTATE = Kinematic_B.DataTypeConversion1;

  /* Update for Delay: '<S1>/Delay5' */
  Kinematic_DW.Delay5_DSTATE = Kinematic_B.reset_KM;

  /* Update for RateTransition: '<S1>/Rate Transition3' */
  if (Kinematic_M->Timing.TaskCounters.TID[1] == 0) {
    Kinematic_DW.RateTransition3_Buffer0 = Kinematic_B.LogicalOperator5;

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
    Kinematic_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.02F *
      Kinematic_B.dx_dy_m[0];
    Kinematic_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.02F *
      Kinematic_B.dx_dy_m[1];
    Kinematic_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Kinematic_B.LogicalOperator1 ? 1 : 0);

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    Kinematic_DW.DiscreteTimeIntegrator_DSTATE += 0.02F *
      Kinematic_B.d_heading_deg;
    Kinematic_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      (Kinematic_B.LogicalOperator1 ? 1 : 0);

    /* Update for Delay: '<S1>/Delay1' incorporates:
     *  Inport: '<Root>/WheelPosition_Report.RR'
     */
    Kinematic_DW.icLoad = 0U;
    Kinematic_DW.Delay1_DSTATE = Kinematic_U.RR_p;

    /* Update for Delay: '<S1>/Delay2' incorporates:
     *  Inport: '<Root>/WheelPosition_Report.RL'
     */
    Kinematic_DW.icLoad_b = 0U;
    Kinematic_DW.Delay2_DSTATE = Kinematic_U.RL_p;
  }

  /* End of Update for RateTransition: '<S1>/Rate Transition3' */

  /* Update for Delay: '<S1>/Delay3' */
  Kinematic_DW.Delay3_DSTATE = Kinematic_B.Counter;
  rate_scheduler();
}

/* Model initialize function */
void Kinematic_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Kinematic_M, 0,
                sizeof(RT_MODEL_Kinematic_T));

  /* block I/O */
  (void) memset(((void *) &Kinematic_B), 0,
                sizeof(B_Kinematic_T));

  /* states (dwork) */
  (void) memset((void *)&Kinematic_DW, 0,
                sizeof(DW_Kinematic_T));

  /* external inputs */
  (void)memset((void *)(&Kinematic_U), 0, sizeof(ExtU_Kinematic_T));

  /* external outputs */
  (void) memset((void *)&Kinematic_Y, 0,
                sizeof(ExtY_Kinematic_T));

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  Kinematic_DW.DiscreteTimeIntegrator1_DSTATE[0] = Kinematic_ConstB.xy_init[0];
  Kinematic_DW.DiscreteTimeIntegrator1_DSTATE[1] = Kinematic_ConstB.xy_init[1];
  Kinematic_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Kinematic_DW.DiscreteTimeIntegrator_DSTATE = Kinematic_ConstB.heading_init;
  Kinematic_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  Kinematic_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S1>/Delay2' */
  Kinematic_DW.icLoad_b = 1U;
}

/* Model terminate function */
void Kinematic_terminate(void)
{
  /* (no terminate code required) */
}

void UssOdo_PerformNextOdometryStep(void)
{
    float32_t fDelTimestamp;
    uint32_t  uCurTimestamp;
    US_E_WheelDir_e eWheelDirRightRear;
    US_E_WheelDir_e eWheelDirLeftRear;

    

    /* Disable interrupts here */

    /* Check for overrun */
 

    

    /* Save FPU context here (if necessary) */
    /* Re-enable timer or interrupt here */
    /* Set model inputs here */

    
    Kinematic_U.RR=UssCom_F_GetWSpeedRightRear();
    Kinematic_U.RL=UssCom_F_GetWSpeedLeftRear();
    Kinematic_U.RR_p=UssCom_F_GetWheelPulseRightRear();
    Kinematic_U.RL_p=UssCom_F_GetWheelPulseLeft_Rear();
    Kinematic_U.ANGLE=UssCom_F_GetSASStatusAngleSafe()*180.0f/M_PI;


    eWheelDirRightRear = UssCom_F_GetWheelDirRightRear();
    eWheelDirLeftRear = UssCom_F_GetWheelDirLeftRear();

    /* If wheel dir is available, use it, otherwise use PRNDL */
    if (   (eWheelDirRightRear != US_WHEEL_DIR_NOT_DEFINED)
      && (eWheelDirLeftRear != US_WHEEL_DIR_NOT_DEFINED)
      && (eWheelDirLeftRear == eWheelDirRightRear))
    {
      if(eWheelDirLeftRear == US_WHEEL_DIR_BACKWARD)
      {
          Kinematic_U.Gear_RPT_STATE=2;
      }
      else if(eWheelDirLeftRear == US_WHEEL_DIR_FORWARD)
      {
          Kinematic_U.Gear_RPT_STATE=4;
      }
      else
      {
          Kinematic_U.Gear_RPT_STATE=1;
      }
    }
    else
    {
        if(UssCom_F_GetVehPrndl()==US_PRNDL_REVERSE)
        {
            Kinematic_U.Gear_RPT_STATE=2;
        }
        else if(UssCom_F_GetVehPrndl()==US_PRNDL_DRIVE)
        {
            Kinematic_U.Gear_RPT_STATE=4;
        }
        else
        {
            Kinematic_U.Gear_RPT_STATE=1;
        }
    }

    /* Step the model for base rate */
    Kinematic_step();
    /* Get model outputs here */
    USS_Oddometry_v.X_MABx        =   Kinematic_Y.X_MABx;
    USS_Oddometry_v.Y_MABx        =   Kinematic_Y.Y_MABx;
    USS_Oddometry_v.heading_MABx  =   Kinematic_Y.heading_MABx;
    USS_Oddometry_v.rearAxleSpeed =   Kinematic_Y.Outport1;  /* Speed of axel */
    USS_Oddometry_v.xVelocity     =   Kinematic_Y.Outport2;  /* dx [m]  autosar coord */
    USS_Oddometry_v.yVelocity     =   Kinematic_Y.Outport3;  /* dy [m]  autosar coord */
    USS_Oddometry_v.dAngle        =   Kinematic_Y.Outport4;  /* dheading [degrees], autosar coord*/

    if (ME_TRUE == bClearAccum)
    {
      sOdoAccumOut.fAngleDelta = 0.0f;
      sOdoAccumOut.fXdelta = 0.0f;
      sOdoAccumOut.fYdelta = 0.0f;
      bClearAccum = ME_FALSE;
    }

    uCurTimestamp = US_GetTimeStampTimeMs();
    fDelTimestamp = (float32_t) (uCurTimestamp - uLastOdoTimestamp) / 1E3;
    uLastOdoTimestamp = uCurTimestamp;

    if((fDelTimestamp > ZERO) && (fDelTimestamp < US_D_MAX_DEL_TIME_PLAUSABLE)) /* Delta time plausibility check. */
    {
        sOdoAccumOut.fAngleDelta += (Kinematic_Y.Outport4 / 180.0f * M_PI)  * fDelTimestamp;
        sOdoAccumOut.fXdelta += ((float32_t) Kinematic_Y.Outport2 * 100.0f) * fDelTimestamp;
        sOdoAccumOut.fYdelta += ((float32_t) Kinematic_Y.Outport3 * 100.0f) * fDelTimestamp;
    }
    else
    {
        sOdoAccumOut.fAngleDelta = 0.0f;
        sOdoAccumOut.fXdelta = 0.0f;
        sOdoAccumOut.fYdelta = 0.0f;
    }
    /* Indicate task complete */
    

    /* Disable interrupts here */
    /* Restore FPU context here (if necessary) */
    /* Enable interrupts here */

    UssCom_PopulateOddometry((UssOdo_OdometryData_t *)&USS_Oddometry_v);
}

#else
/* ===========================================================================
 * Name: UssOdo_OdometryInit    
 * Remarks:  DD-ID: {F9EE56A3-5780-42ec-9F88-8AFC4989DB49}
 * ===========================================================================*/
void UssOdo_OdometryInit(void)
{

#if (US_D_USE_EXTERNAL_ODOMETRY == ME_FALSE)
	uint16_t len;
    Kinematic_initialize();
   	pKinematicCfg = (US_S_KinematicCfg_t*)US_SnrCfg_Get_KinematicCfg(&len);
	if((pKinematicCfg !=NULL)&&(len != ZERO))
	{
	    Kinematic_U.whl_Base   =  pKinematicCfg ->whl_Base;
        Kinematic_U.whl_Circum =  pKinematicCfg ->whl_Circum;
        Kinematic_U.max_Tick   =  pKinematicCfg ->max_Tick;
        Kinematic_U.num_Pulses =  pKinematicCfg ->num_Pulses;
	}

	uLastOdoTimestamp = US_GetTimeStampTimeMs();

#else
    fLastOdoTimestamp = 0.0f;
#endif

	sOdoAccumOut.fAngleDelta = 0.0f;
    sOdoAccumOut.fXdelta = 0.0f;
    sOdoAccumOut.fYdelta = 0.0f;

#if (US_D_ENABLE_EXT_ODOM_DEBUG == ME_TRUE)
    sOdoDebugInfo.fGlobalX = 0.0f;
    sOdoDebugInfo.fGlobalY = 0.0f;
    sOdoDebugInfo.fAngleCur = 0.0f;
    sOdoDebugInfo.fAccuX = 0.0f;
    sOdoDebugInfo.fAccuY = 0.0f;
    sOdoDebugInfo.fAngleAvg = 0.0f;
#endif
}

#define US_D_ODOMETRY_M_TO_CM    (100.0f)

void UssOdo_PerformNextOdometryStep(void)
{
    /*
     * mcu2_1 to mcu3_0, A72
     * typedef struct KinematicData_s
     * {
     *     float32_t dx_m;
     *     float32_t dy_m;
     *     float32_t dyaw_rad;
     *     float32_t timestamp_s;
     *
     *     float32_t m_Global_dx;
     *     float32_t m_Global_dy;
     *     float32_t m_Global_dyaw_rad;
     * } IKinematicData_t;
     */

    float32_t fDelTimestamp = 0.0f;
    float32_t fCurTimestamp = 0.0f;
    float32_t fCos = 0.0f;
    float32_t fSin = 0.0f;
    float32_t fDx = 0.0f;
    float32_t fDy = 0.0f;

    if ((bool_t)ME_TRUE == bClearAccum)
    {
        sOdoAccumOut.fAngleDelta = 0.0f;
        sOdoAccumOut.fXdelta = 0.0f;
        sOdoAccumOut.fYdelta = 0.0f;
        bClearAccum = (bool_t)ME_FALSE;
    }

    US_Com_GetKinematicData(&sKinematicData);

    fCurTimestamp = sKinematicData.timestamp_s;

    /* If timestamp valid, then kinematics has run at least once */
    if (fCurTimestamp > 0.0f)
    {
        /* Compute delta timestamp */
        if (fCurTimestamp > fLastOdoTimestamp)  /*Ensure positive movement in time (data corruption protection). */
        {
            fDelTimestamp = fCurTimestamp - fLastOdoTimestamp;
        }
        else
        {
            fDelTimestamp = 0.0f;
        }

        /* If timestamp as advanced then accept data for analysis. */
        if (fDelTimestamp > 0.0001f)
        {
            /* Check plausability of data */
            if (fDelTimestamp < US_D_MAX_DEL_TIME_PLAUSABLE) /*Check if too much time has elapsed to use existing data. */
            {
                if (fabs(sKinematicData.dx_m * fDelTimestamp) < 1.5f)    /* check for plausible movement for time-step (deal with wheel tick issues) */
                {
                    /* m_Global_dyaw_rad is angle of the vehicle in inertial coordinate system.
                     * Find rotation necessary to put movement rates in vehicle coordinate system. */
                    fCos = cosf(-sKinematicData.m_Global_dyaw_rad);
                    fSin = sinf(-sKinematicData.m_Global_dyaw_rad);

                    /*
                     * Rotate dx/dt, and dy/dt from inertial coordinate system to vehicle coordinate system.
                     */
                    fDx = (sKinematicData.dx_m * fCos) - (sKinematicData.dy_m * fSin);
                    fDy = (sKinematicData.dx_m * fSin) + (sKinematicData.dy_m * fCos);

                    /*
                     * Negate dx/dt to change coordinate systems.
                     * Negate dy/dt to change coordinate systems.
                     * Rotate dx/dt, and dy/dt from inertial coordinate system to vehicle coordinate system.
                     */
                    fDx = -fDx;
                    fDy = -fDy;

                    sOdoAccumOut.fAngleDelta += sKinematicData.dyaw_rad * fDelTimestamp;  /* Integrate dyaw/dt and then accumulate dyaw values in [rad] */
                    sOdoAccumOut.fXdelta += fDx * fDelTimestamp * US_D_ODOMETRY_M_TO_CM;  /* Integrate dx/dt and then accumulate dx values in [cm] */
                    sOdoAccumOut.fYdelta += fDy * fDelTimestamp * US_D_ODOMETRY_M_TO_CM;  /* Integrate dy/dt and then accumulate dy values in [cm] */
                }
            }
            else
            {
                sOdoAccumOut.fAngleDelta = 0.0f;
                sOdoAccumOut.fXdelta = 0.0f;
                sOdoAccumOut.fYdelta = 0.0f;
            }
            sOdoAccumOut.fTimestamp_s = fCurTimestamp;
        }

        fLastOdoTimestamp = fCurTimestamp;  /*New data came, thus update timestamp, regardless if the data was used. */
    }

#if (US_D_ENABLE_EXT_ODOM_DEBUG == ME_TRUE)
    /* gather some info */
    sOdoDebugInfo.fGlobalX = sKinematicData.m_Global_dx * US_D_ODOMETRY_M_TO_CM;  /*no idea what min/max is... */
    sOdoDebugInfo.fGlobalY = sKinematicData.m_Global_dy * US_D_ODOMETRY_M_TO_CM;
    sOdoDebugInfo.fAngleCur = (float32_t)US_RAD2DEG(sKinematicData.m_Global_dyaw_rad);
    sOdoDebugInfo.fAccuX += fDx * fDelTimestamp * US_D_ODOMETRY_M_TO_CM;
    /*debug overflow is 32meters (32000cm) in either direction */
    if (sOdoDebugInfo.fAccuX > US_D_ODO_DEBUG_MAX_DIST)     {sOdoDebugInfo.fAccuX -= US_D_ODO_DEBUG_MAX_DIST;}
    if (sOdoDebugInfo.fAccuX < US_D_ODO_DEBUG_MIN_DIST)     {sOdoDebugInfo.fAccuX -= US_D_ODO_DEBUG_MIN_DIST;}
    sOdoDebugInfo.fAccuY += fDy * fDelTimestamp * US_D_ODOMETRY_M_TO_CM ;
    if (sOdoDebugInfo.fAccuY > US_D_ODO_DEBUG_MAX_DIST)     {sOdoDebugInfo.fAccuY -= US_D_ODO_DEBUG_MAX_DIST;}
    if (sOdoDebugInfo.fAccuY < US_D_ODO_DEBUG_MIN_DIST)     {sOdoDebugInfo.fAccuY -= US_D_ODO_DEBUG_MIN_DIST;}
    /*debug overflow is 640deg (640deg x 0.02 deg scale => 32000 value on CAN) in either direction */
    sOdoDebugInfo.fAngleAvg += (float32_t)US_RAD2DEG(sKinematicData.dyaw_rad * fDelTimestamp);   /*PRQA S 1892 */
    if (sOdoDebugInfo.fAngleAvg > US_D_ODO_DEBUG_MAX_DEG)     {sOdoDebugInfo.fAngleAvg -= US_D_ODO_DEBUG_MAX_DEG;}
    if (sOdoDebugInfo.fAngleAvg < US_D_ODO_DEBUG_MIN_DEG)     {sOdoDebugInfo.fAngleAvg -= US_D_ODO_DEBUG_MIN_DEG;}
#endif
}

#endif /* if US_D_USE_EXTERNAL_ODOMETRY -> else  */
/* ===========================================================================
 * Name: UssOdo_psGetOdoAccumOut    
 * Remarks:  DD-ID: {E75621F4-26F5-40fc-B53C-7739880E1D5A}
 * ===========================================================================*/
UssOdo_OdoAccumOutput_t * UssOdo_psGetOdoAccumOut(void)
{
    return &sOdoAccumOut;
}
/* ===========================================================================
 * Name: UssOdo_ClearAccumulators    
 * Remarks:  DD-ID: {70CA8300-6AFC-45cc-915E-AB630421E132}
 * ===========================================================================*/
void UssOdo_ClearAccumulators(void)
{
    bClearAccum = ME_TRUE;
}

#if (US_D_ENABLE_EXT_ODOM_DEBUG == ME_TRUE)
/* ===========================================================================
 * Name: UssOdo_psGetOdoDebug	
 * Remarks:  DD-ID: {CC909F51-8E4B-46d1-AA1A-D20FBEABECC4}
 * ===========================================================================*/
UssOdo_DebugOutput_t* UssOdo_psGetOdoDebug(void)
{
    return &sOdoDebugInfo;
}
#endif

 /*
 * File trailer for generated code.
 *
 * [EOF]
 */
/*#endif */
