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
	
	$Header: vgg.h 1.6 2016/06/01 21:07:46IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:46IST $
	$Revision: 1.6 $
	
  ===================================================================================*/

 /*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: vgg.h  $
 Revision 1.6 2016/06/01 21:07:46IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.5 2016/05/31 16:11:44CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.3.1.1 2016/04/12 19:40:44CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.3 2015/05/29 07:27:19EDT Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:57CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:55CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.2 2013/07/18 03:21:06EDT Sebastian Pliefke (spliefke) 
 Modification of including structure and change from double32_t to float32_t
 Revision 1.1 2013/07/09 16:51:47MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/cali/project.pj
 Revision 1.1 2013/04/26 16:21:45MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/05_MicroBlaze/project.pj
 Revision 1.2 2011/10/14 19:07:18MESZ Anupama Bhide (abhide) 
 Adding Official template
 Revision 1.2 2011/08/04 11:09:17EDT Sala Annamalai (sannamalai) 
 replaced "+" by "-"
 Revision 1.1 2011/03/25 15:37:32EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#ifndef VGG_H_
#define VGG_H_

#ifdef __cplusplus
extern "C" {
#endif


/* --- Public Typedefinitions, Enumerations, Defines ---------------------- */

/* --- Public Variables, Constants ---------------------------------------- */

/* --- Public Macros ------------------------------------------------------ */

/* --- Public Function Prototypes ----------------------------------------- */

void 	vggCondition2d_v( float64_t b_X_af64[], float64_t b_Y_af64[], const float64_t i_C_af64[], const uint8_t i_Num_u8 );
void  vggConditionerFromPts_v(const float64_t i_PtsX_af64[], const float64_t i_PtsY_af64[], float64_t o_T_af64[], const uint32_t i_Num_u32 );
sint8_t vggHFromXLin_s8( float64_t b_Xs1X_af64[], float64_t b_Xs1Y_af64[], float64_t b_Xs2X_af64[],
                         float64_t b_Xs2Y_af64[], float64_t o_H1_af64[], uint8_t i_M_u8 );

#ifdef __cplusplus
}
#endif

#endif /* _VGG_H_ */
