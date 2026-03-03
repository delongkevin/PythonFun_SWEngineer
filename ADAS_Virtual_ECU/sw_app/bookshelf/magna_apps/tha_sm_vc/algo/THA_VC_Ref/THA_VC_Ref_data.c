/*
 * File: THA_VC_Ref_data.c
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

/* Constant parameters (default storage) */
const ConstP_THA_VC_Ref_T THA_VC_Ref_ConstP = {
  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S17>/1-D Lookup Table'
   */
  { 60.0F, 112.0F, 137.0F, 147.0F, 155.0F, 164.0F },

  /* Expression: Steering_Data_55C(:,4) % 4 represents left
   * Referenced by: '<S64>/1D_LUT_LEFT_55C'
   */
  { 0.08F, 4.54F, 9.07F, 14.05F, 18.79F, 24.47F, 29.64F, 35.49F, 43.2F },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S64>/1D_LUT_CENTER_55C'
   *   '<S64>/1D_LUT_LEFT_55C'
   *   '<S64>/1D_LUT_RIGHT_55C'
   */
  { 0.0F, 80.0F, 160.0F, 240.0F, 320.0F, 405.0F, 485.0F, 565.0F, 669.8F },

  /* Expression: Steering_Data_55C(:,3) % 3 represents right
   * Referenced by: '<S64>/1D_LUT_RIGHT_55C'
   */
  { 0.08F, 4.63F, 8.97F, 13.58F, 17.85F, 22.81F, 27.19F, 32.01F, 38.19F },

  /* Expression: Steering_Correction_55C(:,2) % 2 represents correction
   * Referenced by: '<S64>/1D_LUT_CORRECTION_55C'
   */
  { 1.0F, 1.0404F, 1.0404F, 1.04448402F, 1.06708896F, 1.0816F, 1.08993602F,
    1.07122505F },

  /* Expression: Steering_Correction_55C(:,1) % 1 represents steer
   * Referenced by: '<S64>/1D_LUT_CORRECTION_55C'
   */
  { 0.0F, 310.0F, 360.0F, 410.0F, 460.0F, 510.0F, 560.0F, 610.0F },

  /* Expression: Steering_Data_55C(:,2) % 2 represents center
   * Referenced by: '<S64>/1D_LUT_CENTER_55C'
   */
  { 0.0F, 4.59F, 9.02F, 13.81F, 18.32F, 23.64F, 28.41F, 33.75F, 40.69F },

  /* Expression: Steering_Data_60C(:,4) % 4 represents left
   * Referenced by: '<S62>/1D_LUT_LEFT_60C'
   */
  { 0.11F, 4.28F, 8.8F, 13.87F, 18.7F, 23.99F, 29.45F, 35.05F, 43.13F },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S62>/1D_LUT_CENTER_60C'
   *   '<S62>/1D_LUT_LEFT_60C'
   *   '<S62>/1D_LUT_RIGHT_60C'
   */
  { 0.0F, 70.0F, 145.0F, 220.0F, 295.0F, 370.0F, 445.0F, 520.0F, 614.73F },

  /* Expression: Steering_Data_60C(:,3) % 3 represents right
   * Referenced by: '<S62>/1D_LUT_RIGHT_60C'
   */
  { 0.11F, 4.43F, 8.76F, 13.46F, 17.79F, 22.4F, 27.01F, 31.59F, 38.04F },

  /* Expression: Steering_Correction_60C(:,2) % 2 represents correction
   * Referenced by: '<S62>/1D_LUT_CORRECTION_60C'
   */
  { 1.0F, 1.01606405F, 1.02819598F, 1.0404F, 1.05267596F, 1.07329595F,
    1.08784902F, 1.06708896F },

  /* Expression: Steering_Correction_60C(:,1) % 1 represents steer
   * Referenced by: '<S62>/1D_LUT_CORRECTION_60C'
   */
  { 0.0F, 260.0F, 310.0F, 360.0F, 410.0F, 460.0F, 510.0F, 558.5F },

  /* Expression: Steering_Data_60C(:,2) % 2 represents center
   * Referenced by: '<S62>/1D_LUT_CENTER_60C'
   */
  { 0.0F, 4.36F, 8.78F, 13.66F, 18.24F, 23.2F, 28.23F, 33.32F, 40.58F },

  /* Pooled Parameter (Expression: Steering_Data_63C(:,4) % 4 represents left)
   * Referenced by:
   *   '<S61>/1D_LUT_LEFT_63C'
   *   '<S63>/1D_LUT_LEFT_63C'
   */
  { 0.11F, 4.33F, 8.55F, 13.69F, 18.3F, 23.5F, 28.8F, 34.36F, 42.0F },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S61>/1D_LUT_CENTER_63C'
   *   '<S61>/1D_LUT_LEFT_63C'
   *   '<S61>/1D_LUT_RIGHT_63C'
   *   '<S63>/1D_LUT_CENTER_63C'
   *   '<S63>/1D_LUT_LEFT_63C'
   *   '<S63>/1D_LUT_RIGHT_63C'
   */
  { 0.0F, 67.2F, 134.4F, 207.2F, 274.4F, 347.2F, 414.4F, 487.2F, 575.14F },

  /* Pooled Parameter (Expression: Steering_Data_63C(:,3) % 3 represents right)
   * Referenced by:
   *   '<S61>/1D_LUT_RIGHT_63C'
   *   '<S63>/1D_LUT_RIGHT_63C'
   */
  { 0.11F, 4.48F, 8.52F, 13.29F, 17.44F, 21.98F, 26.47F, 31.04F, 37.15F },

  /* Pooled Parameter (Expression: Steering_Correction_63C(:,2) % 2 represents correction)
   * Referenced by:
   *   '<S61>/1D_LUT_CORRECTION_63C'
   *   '<S63>/1D_LUT_CORRECTION_63C'
   */
  { 1.0F, 1.02921021F, 1.03836095F, 1.05062497F, 1.05472898F, 1.09202504F,
    1.10007501F },

  /* Pooled Parameter (Expression: Steering_Correction_63C(:,1) % 1 represents steer)
   * Referenced by:
   *   '<S61>/1D_LUT_CORRECTION_63C'
   *   '<S63>/1D_LUT_CORRECTION_63C'
   */
  { 0.0F, 270.0F, 320.0F, 370.0F, 420.0F, 470.0F, 522.0F },

  /* Pooled Parameter (Expression: Steering_Data_63C(:,2) % 2 represents center)
   * Referenced by:
   *   '<S61>/1D_LUT_CENTER_63C'
   *   '<S63>/1D_LUT_CENTER_63C'
   */
  { 0.0F, 4.4F, 8.53F, 13.49F, 17.87F, 22.74F, 27.64F, 32.7F, 39.58F },

  /* Expression: single([0 50 150 200])
   * Referenced by: '<S40>/Constant3'
   */
  { 0.0F, 50.0F, 150.0F, 200.0F },

  /* Pooled Parameter (Expression: [0,2,5,10])
   * Referenced by:
   *   '<S42>/P_gain_lookup_table trx'
   *   '<S42>/P_gain_lookup_table102'
   *   '<S42>/P_gain_lookup_table103'
   *   '<S42>/P_gain_lookup_table98'
   *   '<S42>/damping_gain_table'
   *   '<S42>/differential_gain_table'
   *   '<S42>/differential_gain_table1'
   *   '<S42>/differential_gain_table_trx'
   *   '<S42>/integrator_external_saturation_table'
   *   '<S42>/integrator_gain_table'
   *   '<S42>/integrator_gain_table1'
   *   '<S42>/integrator_gain_table_trx'
   */
  { 0.0F, 2.0F, 5.0F, 10.0F },

  /* Pooled Parameter (Expression: [0,25,50,100,570])
   * Referenced by:
   *   '<S42>/P_gain_lookup_table trx'
   *   '<S42>/P_gain_lookup_table102'
   *   '<S42>/P_gain_lookup_table103'
   *   '<S42>/P_gain_lookup_table98'
   */
  { 0.0F, 25.0F, 50.0F, 100.0F, 570.0F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S42>/P_gain_lookup_table trx'
   *   '<S42>/P_gain_lookup_table102'
   *   '<S42>/P_gain_lookup_table103'
   *   '<S42>/P_gain_lookup_table98'
   */
  { 3U, 4U }
};

/* Invariant block signals (default storage) */
const ConstB_THA_VC_Ref_hb4t_T THA_VC_Ref_ConstB = {
  0.03F,                               /* '<S10>/Data Type Conversion27' */
  0.141371667F,                        /* '<S69>/Divide' */
  0.858628333F,                        /* '<S69>/Add' */
  0.141371667F,                        /* '<S70>/Divide' */
  0.858628333F,                        /* '<S70>/Add' */
  0.141371667F,                        /* '<S71>/Divide' */
  0.858628333F,                        /* '<S71>/Add' */
  0.141371667F,                        /* '<S72>/Divide' */
  0.858628333F,                        /* '<S72>/Add' */
  0.141371667F,                        /* '<S73>/Divide' */
  0.858628333F,                        /* '<S73>/Add' */
  0.141371667F,                        /* '<S74>/Divide' */
  0.858628333F,                        /* '<S74>/Add' */
  0.141371667F,                        /* '<S75>/Divide' */
  0.858628333F,                        /* '<S75>/Add' */
  0.0F,                                /* '<S42>/Constant1' */
  0.0F,                                /* '<S41>/Constant1' */
  1U                                   /* '<S10>/Data Type Conversion36' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
