/*===================================================================================
      __  ___                           _    __          __       _          
     /  |/  /___ _____ _____  ____ _   | |  / /__  _____/ /______(_)_________
    / /|_/ / __ `/ __ `/ __ \/ __ `/   | | / / _ \/ ___/ __/ ___/ / ___/ ___/
   / /  / / /_/ / /_/ / / / / /_/ /    | |/ /  __/ /__/ /_/ /  / / /__(__  ) 
  /_/  /_/\__,_/\__, /_/ /_/\__,_/     |___/\___/\___/\__/_/  /_/\___/____/  
               /____/                                                        


                            copyright (c) 2010, Magna Vectrics
                                 all rights reserved

  ===================================================================================

	LICENSE INFORMATION
	...

  ===================================================================================

	$Header: flcompare.c 1.7 2016/06/01 21:07:43IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:43IST $
	$Revision: 1.7 $

===================================================================================*/

/*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: flcompare.c  $
 Revision 1.7 2016/06/01 21:07:43IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.6 2016/05/31 15:55:30CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.4.1.1 2016/04/12 19:42:35CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.4 2015/08/18 10:43:16EDT Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.3 2015/05/29 13:27:09CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:46CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:50CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.4 2014/04/29 07:00:20EDT Sebastian Pliefke (spliefke) 
 Bugfix for occasual failure
 Revision 1.3 2013/07/25 16:47:20MESZ Sebastian Pliefke (spliefke) 
 Remove warnings
 Revision 1.2 2013/07/18 09:20:59MESZ Sebastian Pliefke (spliefke) 
 Modification of including structure and change from double32_t to float32_t
 Revision 1.1 2013/07/09 16:51:41MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/cali/project.pj
 Revision 1.2 2013/05/08 10:42:43MESZ Sebastian Pliefke (spliefke) 
 Remove warning because of Misra Pragma
 Revision 1.1 2013/04/26 16:21:34MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/05_MicroBlaze/project.pj
 Revision 1.4 2011/10/03 20:13:12MESZ Anupama Bhide (abhide) 
 Misra C modifications using QAC
 Revision 1.3 2011/08/02 16:52:46EDT Sala Annamalai (sannamalai) 
 rearranged code to match official template
 Revision 1.2 2011/07/29 13:58:59EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:27EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#include <math.h>
#include "mecl/core/MeclTypes.h"
#include "flcompare.h"

/* --- Private Typedefinitions, Enumerations, Defines --------------------- */

/* --- Private Variables, Constants --------------------------------------- */

/* --- Private Function Prototypes ---------------------------------------- */

/* --- Public Function Definitions ---------------------------------------- */

/* --- Private Function Definitions --------------------------------------- */

sint32_t fcmpEpsilonF64_s32(const float64_t i_X_f64, const float64_t i_Y_f64)
{
  /* DD-ID: {5DB19BAD-F164-4883-A703-A08B3AAF4880}*/
  sint32_t v_Exp_s32 = 0;
  float64_t v_Delta_f64;
  float64_t v_Diff_f64;
  float64_t v_XAbs_f64;
  float64_t v_YAbs_f64;
  float64_t v_Max_f64;
  float64_t v_Temp_f64;
  float64_t v_Eps_f64 = DOUBLE_EPSILON;

  sint32_t v_Result_s32;

  v_XAbs_f64 = (float64_t) fabs(i_X_f64);
  v_YAbs_f64 = (float64_t) fabs(i_Y_f64);
  v_Diff_f64 = i_X_f64 - i_Y_f64;

  if (v_XAbs_f64 > v_YAbs_f64)
  {
    v_Max_f64 = i_X_f64; 
  }
  else
  {
    v_Max_f64 = i_Y_f64;
  }
  frexp((float64_t)v_Max_f64, (sint32_t*)&v_Exp_s32);   /*PRQA S 3200 */ /* Return expression (significant) not used */
  v_Temp_f64 = (float64_t)((uint32_t)1u << v_Exp_s32);
  v_Delta_f64 = v_Eps_f64 * v_Temp_f64;

  if (v_Diff_f64 > v_Delta_f64)
  { /* x > y */
    v_Result_s32 = GREATER_THAN;
  }
  else if (v_Diff_f64 < -v_Delta_f64)
  {  /* x < y */
    v_Result_s32 = LESS_THAN;
  }
  else
  {
    v_Result_s32 = EQUAL_TO; /* x == y */
  }
  return v_Result_s32;
}

sint32_t fcmpEpsilonF32_s32(const float32_t i_X_f32, const float32_t i_Y_f32)
{
  /* DD-ID: {471C4AC2-22FD-42b3-BF19-CCE22A971B1D}*/
  sint32_t v_Exp_s32 = 0;
  float32_t v_Delta_f32;
  float32_t v_Diff_f32;
  float32_t v_XAbs_f32;
  float32_t v_YAbs_f32;
  float32_t v_Max_f32;
  float32_t v_Epsilon_f32 = FLOAT_EPSILON;

  sint32_t v_Result_s32;

  v_XAbs_f32 = (float32_t)fabs((float64_t)i_X_f32);
  v_YAbs_f32 = (float32_t)fabs((float64_t)i_Y_f32);
  v_Diff_f32 = i_X_f32 - i_Y_f32;

  if (v_XAbs_f32 > v_YAbs_f32)
  {
    v_Max_f32 = i_X_f32; 
  }
  else
  {
    v_Max_f32 = i_Y_f32;
  }

  frexp((float64_t)v_Max_f32, &v_Exp_s32);    /*PRQA S 3200 */ /* Return expression (significant) not used */
  v_Delta_f32 = v_Epsilon_f32 * (float32_t)((uint32_t)1u<< v_Exp_s32);

  if (v_Diff_f32 > v_Delta_f32)
  { /* x > y */
    v_Result_s32 = GREATER_THAN;
  }
  else if (v_Diff_f32 < /*-*/v_Delta_f32)
  {  /* x < y */
    v_Result_s32 = LESS_THAN;
  }
  else
  {
    v_Result_s32 = EQUAL_TO; /* x == y */
  }
  return v_Result_s32;
}


/*
 * strict test to zero
 * better results than fcmpEpsilonF32_s32
 */
sint32_t cmpNearToZeroF32_s32(const float32_t i_X_f32 )
{
  /* DD-ID: {048B4D44-DADE-419b-B03F-DE82FED53B45}*/
#if 0
  return fcmpEpsilonF32_s32( 0.0, i_X_f32 );
#else
  float32_t v_PosEpsilon_f32  ;
  float32_t v_NegEpsilon_f32  ;
  sint32_t v_Ret_s32 = 0;

  v_PosEpsilon_f32  = FLOAT_EPSILON*FLOAT_EPSILON;
  v_NegEpsilon_f32  = -1.0F * v_PosEpsilon_f32;

  if(i_X_f32 > v_PosEpsilon_f32)
  {
    v_Ret_s32 = GREATER_THAN;
  }
  else if(i_X_f32 < v_NegEpsilon_f32)
  {
    v_Ret_s32 = LESS_THAN;
  }
  else
  {
    v_Ret_s32 = EQUAL_TO;
  }
  return v_Ret_s32;
#endif
}

/*
 * strict test to zero
 * better results than fcmpEpsilonF64_s32
 */
sint32_t cmpNearToZeroF64_s32(const float64_t i_X_f64 )
{
  /* DD-ID: {96FA517D-C7E0-4d0a-88C6-C3CFEB981FF6}*/
#if 0
  return fcmpEpsilonF64_s32( 0.0, i_X_f64 );
#else
  float64_t v_PosEpsilon_f64  ;
  float64_t v_NegEpsilon_f64  ;
  sint32_t v_Ret_s32 = 0;

  v_PosEpsilon_f64  = DOUBLE_EPSILON*DOUBLE_EPSILON;
  v_NegEpsilon_f64  = -1.0 * v_PosEpsilon_f64;

  if(i_X_f64 > v_PosEpsilon_f64)
  {
    v_Ret_s32 = GREATER_THAN;
  }
  else if(i_X_f64 < v_NegEpsilon_f64)
  {
    v_Ret_s32 = LESS_THAN;
  }
  else
  {
    v_Ret_s32 = EQUAL_TO;
  }
  return v_Ret_s32;
#endif
}

