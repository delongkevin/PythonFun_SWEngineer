/*
 * File: Rear_ObjectDection_private.h
 *
 * Code generated for Simulink model 'Rear_ObjectDection'.
 *
 * Model version                  : 1.200
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:48:47 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rear_ObjectDection_private_h_
#define RTW_HEADER_Rear_ObjectDection_private_h_
#include "rtwtypes.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real32_T rtCP_pooled_PbjIc8rvJ5cp[9];
extern const real32_T rtCP_pooled_iwzBomKvMWkn[9];
extern const real32_T rtCP_pooled_hiFJDlfCD6yY[9];
extern const real32_T rtCP_pooled_j8V4OSoI6AEq[9];
extern const real32_T rtCP_pooled_ojNIP6015ETV[9];
extern const real32_T rtCP_pooled_sLNao8tqVsqD[9];

#define rtCP_steering_XXcmat1_tableData rtCP_pooled_PbjIc8rvJ5cp /* Computed Parameter: rtCP_steering_XXcmat1_tableData
                                                                  * Referenced by: '<S10>/steering_XXc.mat1'
                                                                  */
#define rtCP_steering_XXcmat1_bp01Data rtCP_pooled_iwzBomKvMWkn  /* Computed Parameter: rtCP_steering_XXcmat1_bp01Data
                                                                  * Referenced by: '<S10>/steering_XXc.mat1'
                                                                  */
#define rtCP_steering_XXcmat_tableData rtCP_pooled_hiFJDlfCD6yY  /* Computed Parameter: rtCP_steering_XXcmat_tableData
                                                                  * Referenced by: '<S10>/steering_XXc.mat'
                                                                  */
#define rtCP_steering_XXcmat_bp01Data  rtCP_pooled_j8V4OSoI6AEq  /* Computed Parameter: rtCP_steering_XXcmat_bp01Data
                                                                  * Referenced by: '<S10>/steering_XXc.mat'
                                                                  */
#define rtCP_steering_XXcmat2_tableData rtCP_pooled_ojNIP6015ETV /* Computed Parameter: rtCP_steering_XXcmat2_tableData
                                                                  * Referenced by: '<S10>/steering_XXc.mat2'
                                                                  */
#define rtCP_steering_XXcmat2_bp01Data rtCP_pooled_sLNao8tqVsqD  /* Computed Parameter: rtCP_steering_XXcmat2_bp01Data
                                                                  * Referenced by: '<S10>/steering_XXc.mat2'
                                                                  */

extern const ConstB_Rear_ObjectDection_h_T Rear_ObjectDection_ConstB;

#endif                            /* RTW_HEADER_Rear_ObjectDection_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
