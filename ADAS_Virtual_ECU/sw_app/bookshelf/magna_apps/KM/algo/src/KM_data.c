/*
 * File: KM_data.c
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

/* Invariant block signals (default storage) */
const ConstB_KM_T KM_ConstB = {
  0.0F,                                /* '<S1>/heading_init' */

  { 0.0F, 0.0F }                       /* '<S1>/xy_init' */
};

/* Constant parameters (default storage) */
const ConstP_KM_T KM_ConstP = {
  /* Computed Parameter: steering_XXcmat1_tableData
   * Referenced by: '<S11>/steering_XXc.mat1'
   */
  { 0.0F, 4.36F, 8.78F, 13.66F, 18.24F, 23.2F, 28.23F, 33.32F, 40.58F },

  /* Computed Parameter: steering_XXcmat1_bp01Data
   * Referenced by: '<S11>/steering_XXc.mat1'
   */
  { 0.0F, 70.0F, 145.0F, 220.0F, 295.0F, 370.0F, 445.0F, 520.0F, 614.73F },

  /* Computed Parameter: steering_XXcmat_tableData
   * Referenced by: '<S11>/steering_XXc.mat'
   */
  { 0.0F, 4.59F, 9.02F, 13.81F, 18.32F, 23.64F, 28.41F, 33.75F, 40.69F },

  /* Computed Parameter: steering_XXcmat_bp01Data
   * Referenced by: '<S11>/steering_XXc.mat'
   */
  { 0.0F, 80.0F, 160.0F, 240.0F, 320.0F, 405.0F, 485.0F, 565.0F, 669.8F },

  /* Computed Parameter: steering_XXcmat2_tableData
   * Referenced by: '<S11>/steering_XXc.mat2'
   */
  { 0.0F, 4.4F, 8.53F, 13.49F, 17.87F, 22.74F, 27.64F, 32.7F, 39.58F },

  /* Computed Parameter: steering_XXcmat2_bp01Data
   * Referenced by: '<S11>/steering_XXc.mat2'
   */
  { 0.0F, 67.2F, 134.4F, 207.2F, 274.4F, 347.2F, 414.4F, 487.2F, 575.14F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
