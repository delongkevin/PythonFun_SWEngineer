/*
 * File: SWC_VC_private.h
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_VC_private_h_
#define RTW_HEADER_SWC_VC_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

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

extern const real_T rtCP_pooled_QUuARRNFvnTO[3];
extern const real32_T rtCP_pooled_PbjIc8rvJ5cp[9];
extern const real32_T rtCP_pooled_iwzBomKvMWkn[9];
extern const real32_T rtCP_pooled_hiFJDlfCD6yY[9];
extern const real32_T rtCP_pooled_j8V4OSoI6AEq[9];
extern const real32_T rtCP_pooled_FSdhmDWGZh5B[4];
extern const real32_T rtCP_pooled_kF1iOvhMEzBU[5];
extern const real32_T rtCP_pooled_vKCj7SqHBTw4[4];
extern const real32_T rtCP_pooled_70dlzaazdBPh[4];
extern const real32_T rtCP_pooled_sLNao8tqVsqD[9];
extern const real32_T rtCP_pooled_ojNIP6015ETV[9];
extern const real32_T rtCP_pooled_OXizejjIIxeu[6];
extern const real32_T rtCP_pooled_4Z5z8vraEcxC[6];
extern const uint32_T rtCP_pooled_nJwGcJM2ZB38[2];

#define rtCP_Fixed_Lookaheads_Value    rtCP_pooled_QUuARRNFvnTO  /* Expression: DetWP.FixedLookaheads
                                                                  * Referenced by: '<S83>/Fixed_Lookaheads'
                                                                  */
#define rtCP_steering_XXcmat1_tableData rtCP_pooled_PbjIc8rvJ5cp /* Computed Parameter: rtCP_steering_XXcmat1_tableData
                                                                  * Referenced by: '<S51>/steering_XXc.mat1'
                                                                  */
#define rtCP_steering_XXcmat1_bp01Data rtCP_pooled_iwzBomKvMWkn  /* Computed Parameter: rtCP_steering_XXcmat1_bp01Data
                                                                  * Referenced by: '<S51>/steering_XXc.mat1'
                                                                  */
#define rtCP_steering_XXcmat_tableData rtCP_pooled_hiFJDlfCD6yY  /* Computed Parameter: rtCP_steering_XXcmat_tableData
                                                                  * Referenced by: '<S51>/steering_XXc.mat'
                                                                  */
#define rtCP_steering_XXcmat_bp01Data  rtCP_pooled_j8V4OSoI6AEq  /* Computed Parameter: rtCP_steering_XXcmat_bp01Data
                                                                  * Referenced by: '<S51>/steering_XXc.mat'
                                                                  */
#define rtCP_steering_XXcmat1_tableData_l rtCP_pooled_PbjIc8rvJ5cp/* Computed Parameter: rtCP_steering_XXcmat1_tableData_l
                                                                   * Referenced by: '<S58>/steering_XXc.mat1'
                                                                   */
#define rtCP_steering_XXcmat1_bp01Data_o rtCP_pooled_iwzBomKvMWkn/* Computed Parameter: rtCP_steering_XXcmat1_bp01Data_o
                                                                  * Referenced by: '<S58>/steering_XXc.mat1'
                                                                  */
#define rtCP_steering_XXcmat_tableData_e rtCP_pooled_hiFJDlfCD6yY/* Computed Parameter: rtCP_steering_XXcmat_tableData_e
                                                                  * Referenced by: '<S58>/steering_XXc.mat'
                                                                  */
#define rtCP_steering_XXcmat_bp01Data_a rtCP_pooled_j8V4OSoI6AEq /* Computed Parameter: rtCP_steering_XXcmat_bp01Data_a
                                                                  * Referenced by: '<S58>/steering_XXc.mat'
                                                                  */
#define rtCP_integrator_gain_table_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_integrator_gain_table_bp01Data
                                                                     * Referenced by: '<S18>/integrator_gain_table'
                                                                     */
#define rtCP_P_gain_lookup_table4_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_P_gain_lookup_table4_bp01Data
                                                                    * Referenced by: '<S18>/P_gain_lookup_table4'
                                                                    */
#define rtCP_P_gain_lookup_table4_bp02Data rtCP_pooled_kF1iOvhMEzBU/* Computed Parameter: rtCP_P_gain_lookup_table4_bp02Data
                                                                    * Referenced by: '<S18>/P_gain_lookup_table4'
                                                                    */
#define rtCP_P_gain_lookup_table3_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_P_gain_lookup_table3_bp01Data
                                                                    * Referenced by: '<S18>/P_gain_lookup_table3'
                                                                    */
#define rtCP_P_gain_lookup_table3_bp02Data rtCP_pooled_kF1iOvhMEzBU/* Computed Parameter: rtCP_P_gain_lookup_table3_bp02Data
                                                                    * Referenced by: '<S18>/P_gain_lookup_table3'
                                                                    */
#define rtCP_P_gain_lookup_table2_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_P_gain_lookup_table2_bp01Data
                                                                    * Referenced by: '<S18>/P_gain_lookup_table2'
                                                                    */
#define rtCP_P_gain_lookup_table2_bp02Data rtCP_pooled_kF1iOvhMEzBU/* Computed Parameter: rtCP_P_gain_lookup_table2_bp02Data
                                                                    * Referenced by: '<S18>/P_gain_lookup_table2'
                                                                    */
#define rtCP_P_gain_lookup_table_Veh98_Veh54_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_P_gain_lookup_table_Veh98_Veh54_bp01Data
                                                                      * Referenced by: '<S18>/P_gain_lookup_table_Veh98_Veh54'
                                                                      */
#define rtCP_P_gain_lookup_table_Veh98_Veh54_bp02Data rtCP_pooled_kF1iOvhMEzBU/* Computed Parameter: rtCP_P_gain_lookup_table_Veh98_Veh54_bp02Data
                                                                      * Referenced by: '<S18>/P_gain_lookup_table_Veh98_Veh54'
                                                                      */
#define rtCP_differential_gain_table_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_differential_gain_table_bp01Data
                                                                      * Referenced by: '<S18>/differential_gain_table'
                                                                      */
#define rtCP_input_rate_limit_table_tableData rtCP_pooled_vKCj7SqHBTw4/* Computed Parameter: rtCP_input_rate_limit_table_tableData
                                                                      * Referenced by: '<S18>/input_rate_limit_table'
                                                                      */
#define rtCP_input_rate_limit_table_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_input_rate_limit_table_bp01Data
                                                                      * Referenced by: '<S18>/input_rate_limit_table'
                                                                      */
#define rtCP_input_rate_limit_table1_tableData rtCP_pooled_70dlzaazdBPh/* Computed Parameter: rtCP_input_rate_limit_table1_tableData
                                                                      * Referenced by: '<S18>/input_rate_limit_table1'
                                                                      */
#define rtCP_input_rate_limit_table1_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_input_rate_limit_table1_bp01Data
                                                                      * Referenced by: '<S18>/input_rate_limit_table1'
                                                                      */
#define rtCP_steering_XXcmat1_tableData_g rtCP_pooled_iwzBomKvMWkn/* Computed Parameter: rtCP_steering_XXcmat1_tableData_g
                                                                   * Referenced by: '<S92>/steering_XXc.mat1'
                                                                   */
#define rtCP_steering_XXcmat1_bp01Data_l rtCP_pooled_PbjIc8rvJ5cp/* Computed Parameter: rtCP_steering_XXcmat1_bp01Data_l
                                                                  * Referenced by: '<S92>/steering_XXc.mat1'
                                                                  */
#define rtCP_steering_XXcmat_tableData_p rtCP_pooled_j8V4OSoI6AEq/* Computed Parameter: rtCP_steering_XXcmat_tableData_p
                                                                  * Referenced by: '<S92>/steering_XXc.mat'
                                                                  */
#define rtCP_steering_XXcmat_bp01Data_n rtCP_pooled_hiFJDlfCD6yY /* Computed Parameter: rtCP_steering_XXcmat_bp01Data_n
                                                                  * Referenced by: '<S92>/steering_XXc.mat'
                                                                  */
#define rtCP_steering_XXcmat2_tableData rtCP_pooled_sLNao8tqVsqD /* Computed Parameter: rtCP_steering_XXcmat2_tableData
                                                                  * Referenced by: '<S92>/steering_XXc.mat2'
                                                                  */
#define rtCP_steering_XXcmat2_bp01Data rtCP_pooled_ojNIP6015ETV  /* Computed Parameter: rtCP_steering_XXcmat2_bp01Data
                                                                  * Referenced by: '<S92>/steering_XXc.mat2'
                                                                  */
#define rtCP_uDLookupTable_tableData   rtCP_pooled_OXizejjIIxeu  /* Computed Parameter: rtCP_uDLookupTable_tableData
                                                                  * Referenced by: '<S115>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data    rtCP_pooled_4Z5z8vraEcxC  /* Computed Parameter: rtCP_uDLookupTable_bp01Data
                                                                  * Referenced by: '<S115>/1-D Lookup Table'
                                                                  */
#define rtCP_steering_XXcmat2_tableData_c rtCP_pooled_ojNIP6015ETV/* Computed Parameter: rtCP_steering_XXcmat2_tableData_c
                                                                   * Referenced by: '<S58>/steering_XXc.mat2'
                                                                   */
#define rtCP_steering_XXcmat2_bp01Data_p rtCP_pooled_sLNao8tqVsqD/* Computed Parameter: rtCP_steering_XXcmat2_bp01Data_p
                                                                  * Referenced by: '<S58>/steering_XXc.mat2'
                                                                  */
#define rtCP_steering_XXcmat2_tableData_f rtCP_pooled_ojNIP6015ETV/* Computed Parameter: rtCP_steering_XXcmat2_tableData_f
                                                                   * Referenced by: '<S51>/steering_XXc.mat2'
                                                                   */
#define rtCP_steering_XXcmat2_bp01Data_m rtCP_pooled_sLNao8tqVsqD/* Computed Parameter: rtCP_steering_XXcmat2_bp01Data_m
                                                                  * Referenced by: '<S51>/steering_XXc.mat2'
                                                                  */
#define rtCP_integrator_external_saturation_table_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_integrator_external_saturation_table_bp01Data
                                                                      * Referenced by: '<S18>/integrator_external_saturation_table'
                                                                      */
#define rtCP_differential_gain_table1_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_differential_gain_table1_bp01Data
                                                                      * Referenced by: '<S18>/differential_gain_table1'
                                                                      */
#define rtCP_damping_gain_table_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_damping_gain_table_bp01Data
                                                                  * Referenced by: '<S18>/damping_gain_table'
                                                                  */
#define rtCP_integrator_gain_table1_bp01Data rtCP_pooled_FSdhmDWGZh5B/* Computed Parameter: rtCP_integrator_gain_table1_bp01Data
                                                                      * Referenced by: '<S18>/integrator_gain_table1'
                                                                      */
#define rtCP_P_gain_lookup_table4_maxIndex rtCP_pooled_nJwGcJM2ZB38/* Computed Parameter: rtCP_P_gain_lookup_table4_maxIndex
                                                                    * Referenced by: '<S18>/P_gain_lookup_table4'
                                                                    */
#define rtCP_P_gain_lookup_table3_maxIndex rtCP_pooled_nJwGcJM2ZB38/* Computed Parameter: rtCP_P_gain_lookup_table3_maxIndex
                                                                    * Referenced by: '<S18>/P_gain_lookup_table3'
                                                                    */
#define rtCP_P_gain_lookup_table2_maxIndex rtCP_pooled_nJwGcJM2ZB38/* Computed Parameter: rtCP_P_gain_lookup_table2_maxIndex
                                                                    * Referenced by: '<S18>/P_gain_lookup_table2'
                                                                    */
#define rtCP_P_gain_lookup_table_Veh98_Veh54_maxIndex rtCP_pooled_nJwGcJM2ZB38/* Computed Parameter: rtCP_P_gain_lookup_table_Veh98_Veh54_maxIndex
                                                                      * Referenced by: '<S18>/P_gain_lookup_table_Veh98_Veh54'
                                                                      */

extern const ConstB_SWC_VC_h_T SWC_VC_ConstB;

#endif                                 /* RTW_HEADER_SWC_VC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
