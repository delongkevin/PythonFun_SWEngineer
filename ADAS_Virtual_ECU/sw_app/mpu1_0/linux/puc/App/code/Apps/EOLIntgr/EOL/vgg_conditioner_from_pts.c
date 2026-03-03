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

	$Header: vgg_conditioner_from_pts.c 1.8 2016/06/01 21:07:46IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:46IST $
	$Revision: 1.8 $

===================================================================================*/

/*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: vgg_conditioner_from_pts.c  $
 Revision 1.8 2016/06/01 21:07:46IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.7 2016/05/31 16:09:47CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.5.1.1 2016/04/12 19:39:14CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.5 2016/03/14 08:05:04EDT Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Renamed float constants to upper-case F
 Revision 1.4.1.1 2016/03/11 10:28:14MEZ Schulte, Michael (MEE_MiSch) 
 Renamed float constants to upper-case F
 Revision 1.4 2015/08/18 16:43:18CEST Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.3 2015/05/29 13:27:18CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:56CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:56CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.3 2013/07/25 10:46:15EDT Sebastian Pliefke (spliefke) 
 Remove warnings
 Revision 1.2 2013/07/18 09:21:04MESZ Sebastian Pliefke (spliefke) 
 Modification of including structure and change from double32_t to float32_t
 Revision 1.1 2013/07/09 16:51:50MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/cali/project.pj
 Revision 1.1 2013/04/26 16:21:49MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/05_MicroBlaze/project.pj
 Revision 1.8 2012/03/21 21:13:11MEZ Marko Vico (mvico) 
 Misra C changes applied
 Revision 1.7 2011/12/15 12:43:37EST Marko Vico (mvico) 
 Covarity error fix ( devide by zero )
 Revision 1.6 2011/11/28 10:20:32EST Marko Vico (mvico) 
 Covarity error fix ( devide by zero )
 Revision 1.5 2011/10/14 12:39:14EDT Anupama Bhide (abhide) 
 QAC Misra C modifications
 Revision 1.4 2011/08/04 17:23:14EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.3 2011/08/04 10:52:46EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:27EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#include "mecl/core/MeclTypes.h"
#include <math.h>
#include "vgg.h"

/* --- Private Typedefinitions, Enumerations, Defines --------------------- */
#define SQRT_2   (1.4142135623730951)

/* --- Private Variables, Constants --------------------------------------- */

/* --- Private Function Prototypes ---------------------------------------- */

/* --- Public Function Definitions ---------------------------------------- */

/* --- Private Function Definitions --------------------------------------- */

void vggConditionerFromPts_v(const float64_t i_PtsX_af64[], const float64_t i_PtsY_af64[], float64_t o_T_af64[], const uint32_t i_Num_u32 )
{
  /* DD-ID: {1D59E847-2DF4-4ec5-8E79-B6C609D5C720}*/
  float64_t v_Mx_f64;
  float64_t v_VarX_f64 = 1.0;
  float64_t v_VarY_f64 = 1.0;
  float64_t v_My_f64;
  float64_t v_Temp_f64;
  float64_t v_Sum_f64 = 0.0;
  uint32_t v_I_u32;

  /* calculate mean value*/
  for( v_I_u32 = 0u; v_I_u32 < i_Num_u32; v_I_u32++ )
  {
    v_Sum_f64 = v_Sum_f64 + ( i_PtsX_af64[v_I_u32] );
  }
  v_Mx_f64 = v_Sum_f64 / (float64_t)( (i_Num_u32 == 0u) ? 1e-20 : (float64_t)i_Num_u32);

  /* calculate standrad deviation*/
  /*     Pts_x_p = Pts_x_p - num; */
  v_Sum_f64 = 0.0;
  for( v_I_u32 = 0u; v_I_u32 < i_Num_u32; v_I_u32++ ) {
    v_Temp_f64 = i_PtsX_af64[v_I_u32];
    v_Sum_f64 = v_Sum_f64 + ((v_Temp_f64 - v_Mx_f64) * (v_Temp_f64 - v_Mx_f64));
    /*         Pts_x_p++; */
  }
  if( i_Num_u32 > 1u )
  {
    v_VarX_f64 = sqrt( v_Sum_f64 / (((float64_t) i_Num_u32) - 1.0 ) );
  }

  /*calculate mean value */
  v_Sum_f64 = 0.0;
  for( v_I_u32 = 0u; v_I_u32 < i_Num_u32; v_I_u32++ )
  {
    v_Sum_f64 = v_Sum_f64 + ( i_PtsY_af64[v_I_u32] );
  }
  v_My_f64 = v_Sum_f64 / (float64_t)( (i_Num_u32 == 0u) ? 1e-20 : (float64_t)i_Num_u32);

  /*calculate standrad deviation */
  /*     Pts_y_p = Pts_y_p - num; */
  v_Sum_f64 = 0.0;
  for( v_I_u32 = 0u; v_I_u32 < i_Num_u32; v_I_u32++ )
  {
    v_Temp_f64 = i_PtsY_af64[v_I_u32];
    v_Sum_f64 = v_Sum_f64 + ((v_Temp_f64 - v_My_f64 )*( v_Temp_f64 - v_My_f64));
    /*         Pts_y_p++; */
  }
  if( i_Num_u32 > 1u )
  {
    v_VarY_f64 = sqrt( v_Sum_f64 / ( ((float64_t)i_Num_u32) - 1.0 ) );
  }

  o_T_af64[0] = (float64_t)SQRT_2 / v_VarX_f64;
  o_T_af64[2] =  - ( (float64_t)SQRT_2 *v_Mx_f64 ) / v_VarX_f64;
  o_T_af64[4] = (float64_t)SQRT_2 / v_VarY_f64;
  o_T_af64[5] =  - ( (float64_t)SQRT_2 *v_My_f64 ) / v_VarY_f64;
}
/*  ---------------------------------- EOF -------------------------------------- */
