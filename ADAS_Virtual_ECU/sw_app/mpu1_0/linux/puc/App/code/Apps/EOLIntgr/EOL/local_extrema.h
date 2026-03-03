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
  
  $Header: local_extrema.h 1.9 2016/06/01 21:21:24IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
  $Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
  $Date: 2016/06/01 21:21:24IST $
  $Revision: 1.9 $
  
===================================================================================*/

/*
MKS change history (will be updated automatically by MKS, do not change manually)
$Log: local_extrema.h  $
Revision 1.9 2016/06/01 21:21:24IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
QACPP + QAC Changes
Revision 1.8 2016/06/01 17:37:38CEST Rasool, Muzammil (MEE_MRASOO) 
Naming Conventions related changes  in C files.
Revision 1.7 2016/05/31 16:05:21CEST Rasool, Muzammil (MEE_MRASOO) 
QAC changes.
Revision 1.5.1.1 2016/04/12 19:43:34CEST Wang, Hongtao (E32953) 
QAC warning removed
Revision 1.5 2015/08/18 10:43:11EDT Rasool, Muzammil (MEE_MRASOO) 
Removed compiled warnings.
Revision 1.4 2015/05/29 13:27:14CEST Rasool, Muzammil (MEE_MRASOO) 
Eol with new MECL integrated.
Revision 1.3 2015/02/04 10:57:51CET Rasool, Muzammil (MEE_MRASOO) 
Eol Results are correct now.
All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
ARM FPU internally calculates floating point operations with 64-bit, 
and adds inaccuracices when rounds it down to 32-bit.
Revision 1.2 2015/02/03 11:54:08CET Rasool, Muzammil (MEE_MRASOO) 
Eol Algo intergrated. Results are not correct yet. 
Floating-point calculation results don't match on PC and ECU with same code.
Revision 1.1 2015/01/21 14:46:53CET Rasool, Muzammil (MEE_MRASOO) 
Initial revision
Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
Revision 1.3 2014/11/28 10:11:21EST Pliefke, Sebastian (MEE_SPLIEF) 
Make malloc replacement extern
Revision 1.2 2014/11/28 16:07:09CET Pliefke, Sebastian (MEE_SPLIEF) 
Remove malloc
Revision 1.1 2013/07/09 16:52:10CEST spliefke 
Initial revision
Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/corner/project.pj
Revision 1.8 2012/06/26 18:38:07MESZ Tina Behal (tbehal) 
Initial revision
Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
Revision 1.8 2011/08/12 13:31:27EDT Ali Ahmed (aahmed) 
EOL MISRA-C Changes.
Revision 1.7 2011/08/12 13:03:43EDT Ali Ahmed (aahmed) 
Code cleanup.
Revision 1.6 2011/08/12 12:21:45EDT Ali Ahmed (aahmed) 
EOL Changes.
Revision 1.5 2011/08/11 18:59:48EDT Anupama Bhide (abhide) 
Misra C modifications & Indentation formatting
Revision 1.4 2011/08/04 17:23:06EDT Ali Ahmed (aahmed) 
EOL optimization related changes.
Revision 1.3 2011/08/04 11:07:40EDT Sala Annamalai (sannamalai) 
added official template
Revision 1.1 2011/03/25 15:37:32EDT Ron Zibman (rzibman) 
Initial revision
Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */


#ifndef LOCA_EXTREMA_H
#define LOCA_EXTREMA_H

#include "general_def.h"

/* --- Public Typedefinitions, Enumerations, Defines ---------------------- */

/* --- Public Variables, Constants ---------------------------------------- */
/* PRQA S 2300 3 */ /* C Code */
extern sint8_t V_Candidates_as8[2*960*540];
extern sint8_t V_TKernelL_as8[100];
extern sint8_t V_TKernelR_as8[100];
/* --- Public Macros ------------------------------------------------------ */

/* --- Public Function Prototypes ----------------------------------------- */

sint8_t aExtrema_F_InitCandidates_s8(uint8_t *i_ImgData_pu8, 
                                     uint16_t i_ImgX_u16,
                                     uint16_t i_ImgY_u16,
                                     float32_t i_threshold_f32,
                                     io_S_PosSub_t *o_CanPosSub1_ps,  /* output candidates list */
                                     uint32_t *o_CanCount_pu32 /* output no of candidates */
);

void aExtrema_F_getConvImg_v(uint8_t *i_ImgData_pu8,
                             const uint16_t i_ImgX_u16,
                             const uint16_t i_ImgY_u16,
                             float32_t o_NormImg_af32[]
);

sint8_t aExtrema_F_InitializeCandiates_s8( const float32_t i_NormImg_pf32[], uint16_t i_ImgX_u16, uint16_t i_ImgY_u16, float32_t i_threshold_f32, io_S_PosSub_t *o_CanPosSub1_ps,  /* output candidates list */
                                          uint32_t *o_CanCount_pu32 /* output no of candidates */
);
#endif /* local_extrema.h */
/* === End of Header File ==================================================== */
