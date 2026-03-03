/*PRQA S ALL EOF */

/*
 * File: US_OdoKinematic_private.h
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
#ifndef RTW_HEADER_Kinematic_private_h_
#define RTW_HEADER_Kinematic_private_h_
#include "US_OdoRtwType.h"
#include "US_PlatformCfg_Global.h"

#if (US_D_USE_EXTERNAL_ODOMETRY == ME_FALSE)

extern real_T rt_remd(real_T u0, real_T u1);
extern real32_T rt_remf(real32_T u0, real32_T u1);
extern real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);


#endif

#endif                                 /* RTW_HEADER_Kinematic_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
