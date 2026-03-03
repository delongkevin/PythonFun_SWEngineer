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
	
	$Header: lucchese.h 1.6 2016/06/01 21:07:45IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:45IST $
	$Revision: 1.6 $
	
  ===================================================================================*/

 /*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: lucchese.h  $
 Revision 1.6 2016/06/01 21:07:45IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.5 2016/05/31 16:07:06CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.3.1.1 2016/04/12 19:35:58CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.3 2015/05/29 07:27:15EDT Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:52CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:54CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.1 2013/07/09 10:52:12EDT Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/corner/project.pj
 Revision 1.7 2012/06/26 18:39:03MESZ Tina Behal (tbehal) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
 Revision 1.7 2011/08/12 13:03:48EDT Ali Ahmed (aahmed) 
 Code cleanup.
 Revision 1.6 2011/08/04 17:23:11EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.5 2011/08/04 11:07:41EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:32EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#ifndef LUCCHESE_H
#define LUCCHESE_H

#include "largest_component.h"

/* --- Public Typedefinitions, Enumerations, Defines ---------------------- */

/* --- Public Variables, Constants ---------------------------------------- */

/* --- Public Macros ------------------------------------------------------ */

/* --- Public Function Prototypes ----------------------------------------- */

void aSaddle_F_luccheseAll_v( const uint8_t *i_Img_pu8, uint16_t i_ImgX_u16, io_S_PosSub_t *b_CanPosSub_ps, uint32_t i_Number_u32 );
uint16_t f_aRound_u16( float32_t i_Number_f32 ); /* input float32_t number */ 



/* === End of Header File ==================================================== */

#endif /* local_extrema.h */
