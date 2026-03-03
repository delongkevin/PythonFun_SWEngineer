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

	$Header: vgg_condition_2d.c 1.8 2016/06/01 21:07:37IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:37IST $
	$Revision: 1.8 $

===================================================================================*/

/*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: vgg_condition_2d.c  $
 Revision 1.8 2016/06/01 21:07:37IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.7 2016/05/31 16:09:11CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.5.1.1 2016/04/12 19:38:33CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.5 2016/03/14 08:05:39EDT Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Renamed float constants to upper-case F
 Revision 1.4.1.1 2016/03/11 10:26:17MEZ Schulte, Michael (MEE_MiSch) 
 Renamed float constants to upper-case F
 Revision 1.4 2015/08/18 16:43:11CEST Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.3 2015/05/29 13:27:17CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:55CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:56CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.3 2013/07/25 10:46:13EDT Sebastian Pliefke (spliefke) 
 Remove warnings
 Revision 1.2 2013/07/18 09:21:03MESZ Sebastian Pliefke (spliefke) 
 Modification of including structure and change from double32_t to float32_t
 Revision 1.1 2013/07/09 16:51:49MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/cali/project.pj
 Revision 1.1 2013/04/26 16:21:47MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/05_MicroBlaze/project.pj
 Revision 1.5 2011/10/14 18:39:10MESZ Anupama Bhide (abhide) 
 QAC Misra C modifications
 Revision 1.4 2011/08/04 17:23:05EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.3 2011/08/04 10:52:47EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:27EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#include "mecl/core/MeclTypes.h"
#include "vgg.h"

/* --- Private Typedefinitions, Enumerations, Defines --------------------- */

/* --- Private Variables, Constants --------------------------------------- */

/* --- Private Function Prototypes ---------------------------------------- */

/* --- Public Function Definitions ---------------------------------------- */

/* --- Private Function Definitions --------------------------------------- */

/* p_x is a pointer to a vector with length num:
C is pointer to a 1x9 vector */
void vggCondition2d_v( float64_t b_X_af64[], float64_t b_Y_af64[], const float64_t i_C_af64[], const uint8_t i_Num_u8 )
{
  /* DD-ID: {1C334C58-17A0-496f-B182-2A67540FB3A8}*/
  uint8_t v_I_u8;
  float64_t v_C00_f64 =  i_C_af64[0];
  float64_t v_C01_f64 =  i_C_af64[1];
  float64_t v_C02_f64 =  i_C_af64[2];

  float64_t v_C10_f64 =  i_C_af64[3];
  float64_t v_C11_f64 =  i_C_af64[4];
  float64_t v_C12_f64 =  i_C_af64[5];

  for( v_I_u8 = 0U; v_I_u8 < i_Num_u8; v_I_u8++ )
  {
    b_X_af64[v_I_u8] = ( v_C00_f64 *( b_X_af64[v_I_u8] ) ) + ( ( v_C01_f64 *( b_X_af64[v_I_u8] ) ) + ( v_C02_f64 *1.0 ) );
    /*         p_x++; */
    b_Y_af64[v_I_u8] = ( v_C10_f64 *( b_Y_af64[v_I_u8] ) ) + ( ( v_C11_f64 *( b_Y_af64[v_I_u8] ) ) + ( v_C12_f64 *1.0 ) );
    /*         p_y++; */
  }

}
/*  ---------------------------------- EOF -------------------------------------- */
