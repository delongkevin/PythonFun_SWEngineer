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
	
	$Header: flcompare.h 1.6 2016/06/01 21:07:42IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:42IST $
	$Revision: 1.6 $
	
  ===================================================================================*/

 /*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: flcompare.h  $
 Revision 1.6 2016/06/01 21:07:42IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.5 2016/05/31 15:56:25CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.3.1.1 2016/04/12 19:42:45CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.3 2015/05/29 07:27:10EDT Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:47CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:51CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.2 2013/07/18 03:21:00EDT Sebastian Pliefke (spliefke) 
 Modification of including structure and change from double32_t to float32_t
 Revision 1.1 2013/07/09 16:51:42MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/cali/project.pj
 Revision 1.1 2013/04/26 16:21:35MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/05_MicroBlaze/project.pj
 Revision 1.4 2011/08/02 23:25:58MESZ Sala Annamalai (sannamalai) 
 rearranged code to match official template
 Revision 1.3 2011/07/29 14:03:47EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:32EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#ifndef flcompare_h
#define flcompare_h

/* --- Public Typedefinitions, Enumerations, Defines ---------------------- */

/* Function returns  0 if x=y */
#define EQUAL_TO      (0)
/* Function returns  1 if x>y */
#define GREATER_THAN  (1)
/* Function returns -1 if x<y */
#define LESS_THAN     (-1)
/*PRQA S 4800 EOF */
#define FLOAT_EPSILON   1.192092896E-07F
#define DOUBLE_EPSILON  2.2204460492503131E-16

/* --- Public Variables, Constants ---------------------------------------- */

/* --- Public Macros ------------------------------------------------------ */

/* --- Public Function Prototypes ----------------------------------------- */

/* To comapre float values */
sint32_t fcmpEpsilonF32_s32(const float32_t i_X_f32, const float32_t i_Y_f32);
sint32_t cmpNearToZeroF32_s32(const float32_t i_X_f32 );
/* To comapre double values */
sint32_t fcmpEpsilonF64_s32(const float64_t i_X_f64, const float64_t i_Y_f64);
sint32_t cmpNearToZeroF64_s32(const float64_t i_X_f64);

#endif
