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
	
	$Header: svd.h 1.6 2016/05/31 19:38:38IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/05/31 19:38:38IST $
	$Revision: 1.6 $
	
  ===================================================================================*/

 /*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: svd.h  $
 Revision 1.6 2016/05/31 19:38:38IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 QAC changes.
 Revision 1.4.1.1 2016/04/12 19:37:41CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.4 2015/08/18 10:43:16EDT Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.3 2015/05/29 13:27:17CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:55CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:54CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.3 2014/04/22 16:50:06EDT Wang Hongtao (E32953) 
 Add Highline + TAD calibration
 Revision 1.2 2013/07/18 03:21:02EDT Sebastian Pliefke (spliefke) 
 Modification of including structure and change from double32_t to float32_t
 Revision 1.1 2013/07/09 16:51:45MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/cali/project.pj
 Revision 1.1 2013/04/26 16:21:43MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/05_MicroBlaze/project.pj
 Revision 1.5 2012/06/26 18:39:39MESZ Tina Behal (tbehal) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
 Revision 1.5 2011/08/12 13:03:46EDT Ali Ahmed (aahmed) 
 Code cleanup.
 Revision 1.4 2011/08/04 17:23:10EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.3 2011/08/04 11:07:40EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:32EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#ifndef SVD_H
#define SVD_H

/*#include "own/prj/global.h"
#include "corner_detection.h"
#include "own/app/algo/ec/app_algo_ec.h"
*/
#include "mecl/core/MeclTypes.h"
/* --- Public Typedefinitions, Enumerations, Defines ---------------------- */

#define MAX_NUM_TARGET_POINTS 200U

/* --- Public Variables, Constants ---------------------------------------- */

/* --- Public Macros ------------------------------------------------------ */

/* --- Public Function Prototypes ----------------------------------------- */

#ifdef __cplusplus
extern "C"
{
#endif

void svdcmp_v( float64_t *b_A_a2f64[], const uint16_t i_M_u16, const uint8_t i_N_u8, float64_t b_W_af64[], float64_t *b_V_a2f64[] );
void svdreorder_v( float64_t *b_U_a2f64[], const uint16_t i_M_u16, const uint8_t i_N_u8, float64_t b_W_af64[], float64_t *b_V_a2f64[] );

#ifdef __cplusplus
}
#endif



    /* === End of Header File ==================================================== */

#else 
//  #error Multiple include of svd.h
#endif /* local_extrema.h */
/*  ---------------------------------- EOF -------------------------------------- */
