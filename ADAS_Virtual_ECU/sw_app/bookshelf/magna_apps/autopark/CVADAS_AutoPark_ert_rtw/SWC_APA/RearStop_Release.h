/*
 * File: RearStop_Release.h
 *
 * Code generated for Simulink model 'SWC_APA'.
 *
 * Model version                  : 1.594
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov 12 18:11:22 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RearStop_Release_h_
#define RTW_HEADER_RearStop_Release_h_
#ifndef SWC_APA_COMMON_INCLUDES_
# define SWC_APA_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_APA_COMMON_INCLUDES_ */

#include "SWC_APA_types.h"

/* Child system includes */
#ifndef SWC_APA_MDLREF_HIDE_CHILD_
#define Rear_ObjectDection_MDLREF_HIDE_CHILD_
#include "Rear_ObjectDection.h"
#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

#include "rtGetInf.h"
#include "rtGetNaN.h"

extern void SWC_APA_RPAwithBrk_Init(void);
extern void SWC_APA_RPAwithBrk_Disable(void);
extern void SWC_APA_RPAwithBrk(void);

#endif                                 /* RTW_HEADER_RearStop_Release_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
