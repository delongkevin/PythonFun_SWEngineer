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
	
	$Header: general_def.h 1.10 2016/05/31 19:26:43IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/05/31 19:26:43IST $
	$Revision: 1.10 $
	
  ===================================================================================*/

 /*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: general_def.h  $
 Revision 1.10 2016/05/31 19:26:43IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 QAC changes.
 Revision 1.9 2016/04/27 13:56:12CEST Rasool, Muzammil (MEE_MRASOO) 
 QACPP Warnings removed.
 Revision 1.8 2016/04/08 09:48:15CEST Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Adapt EOL to coding style
 Revision 1.7.1.1 2016/04/05 13:44:48MESZ Ziehl, Roland (SAI_RZieh) 
 Adapt EOL to coding style
 Revision 1.7 2016/03/14 13:04:48MEZ Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Renamed float constants to upper-case F
 Revision 1.6.1.1 2016/03/11 10:28:41MEZ Schulte, Michael (MEE_MiSch) 
 Renamed float constants to upper-case F
 Revision 1.6 2016/02/19 00:38:06CET Rasool, Muzammil (MEE_MRASOO) 
 removed unused max, min macros.
 Revision 1.5 2016/02/11 05:40:24EST Becker, Michael (MEE_MBECKE) 
 Integrate 1512516
 Revision 1.4.2.1 2016/02/11 09:28:54CET Schulte, Michael (MEE_MiSch) 
 Cleaned up QACPP and also adapted naming of variables
 Revision 1.4 2015/08/18 16:43:19CEST Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.3 2015/05/29 13:27:10CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:47CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:51CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.3 2013/07/22 09:05:35EDT Sebastian Pliefke (spliefke) 
 Different seed points in reduce function
 Revision 1.2 2013/07/18 09:30:17MESZ Sebastian Pliefke (spliefke) 
 Merge with Timor
 Revision 1.1 2013/07/09 16:52:04MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/corner/project.pj
 Revision 1.25 2012/07/12 22:27:42MESZ Marko Vico (mvico) 
 EoL algo update 4.2
 Revision 1.24 2012/07/09 11:22:58EDT Tina Behal (tbehal) 
 Marko's updated changes for BR222 EOL front target grid size to 120mm
 Revision 1.22.1.2 2012/07/09 11:02:35EDT Tina Behal (tbehal) 
 EOL update for BR222 grid size for front target 120mm added by Marko
 Revision 1.22.1.1 2012/07/04 16:13:59EDT Tina Behal (tbehal) 
 Marko's updated changes for target ID
 Revision 1.22 2012/02/16 15:21:23EST Marko Vico (mvico) 
 Removed unused EOL error codes from header file.
 Revision 1.21 2012/01/27 16:22:08EST Marko Vico (mvico) 
 Added New Error codes to consolidate internal EOL algo error codes
 Revision 1.20 2012/01/18 15:13:52EST Tina Behal (tbehal) 
 changed threshold for translations from 50 to 150
 Revision 1.19 2011/12/09 10:41:54EST Ron Zibman (rzibman) 
 Changed thresholds based on PR201360
 rotational angles: +/- 6 degree
 translation: +/-50mm
 Revision 1.18 2011/11/15 16:26:52EST Ali Ahmed (aahmed) 
 EOL now looks at the variant coding to determine the roll related changes inside the processing block of EC.
 Revision 1.17 2011/10/27 12:15:21EDT Ali Ahmed (aahmed) 
 Added more error codes.
 Revision 1.16 2011/10/27 12:09:02EDT Ali Ahmed (aahmed) 
 Added EOL result codes.
 Revision 1.15 2011/08/12 16:39:37EDT Ali Ahmed (aahmed) 
 Fix for EOL crash in case of mal-formed target data.
 Revision 1.14 2011/08/12 14:47:15EDT Ali Ahmed (aahmed) 
 EOL MISRA-C Changes.
 Revision 1.13 2011/08/12 13:03:50EDT Ali Ahmed (aahmed) 
 Code cleanup.
 Revision 1.12 2011/08/10 16:21:23EDT Ali Ahmed (aahmed) 
 Changed the loop counter to 5
 Revision 1.11 2011/08/04 17:23:15EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.10 2011/08/04 11:07:44EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:32EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

/* Some QACPP/C++-rules cannot be followed, because the header is used for both C and C++,
 * hence the following rules are deactivated: */
/* PRQA S 1020 EOF */ /* Use of macros */
/* PRQA S 1025 EOF */ /* Macro may be used as a literal */
/* PRQA S 1026 EOF */ /* Macro may be used as a constant expression */
/* PRQA S 2300 EOF */ /* static variables in the global scope */
/* PRQA S 2400 EOF */ /* functions in global namespace */


#ifndef GENERAL_DEF_H
#define GENERAL_DEF_H

#include "mecl/core/MeclTypes.h"

/* +++ Public Typerdefinitions, Enumerations, Defines ++++++++++++++++++++++++ */

#define aAlgoECSrc_D_PI (3.14159265358979323846264338327950)

typedef struct IoSPosSub_s{
    float32_t x_f32;
    float32_t y_f32;
    float32_t v_f32;
}io_S_PosSub_t;

typedef struct IoSPos_s{
    sint16_t x_s16;
    sint16_t y_s16;
}io_S_Pos_t;

typedef struct AAlgoECInputPara_s{
    uint16_t cropix_u16;
    uint16_t cropiy_u16; /* size of cropped image 960x540 */
    uint8_t nx_u8;
    uint8_t ny_u8; /* no of corners per row/column */
}aAlgoECInputPara_t;

#define aAlgoECSrc_D_KernelX 10U
#define aAlgoECSrc_D_KernelY 10U

#define aAlgoECSrc_D_MAX_CORNER_NO 1000U
#define aAlgoECSrc_D_MAX_CANDIDATE_NO 2000U

#define aAlgoECSrc_D_CORNER_NX_NY 200U

#define aAlgoECSrc_D_SUCCESS 1
#define aAlgoECSrc_D_ERR_FAIL (-1)
#define aAlgoECSrc_D_ERR_ZEROCORNER (-2)
#define aAlgoECSrc_D_ERR_NOTENOUGHCORNER (-3)
#define aAlgoECSrc_D_ERR_GRAPHNOTCOMPLETE (-4)
#define aAlgoECSrc_D_ERR_INVALIDCORNER (-5)
#define aAlgoECSrc_D_ERR_OUTOFRANGE (-6)
#define aAlgoECSrc_D_ERR_WRONG_EXTRINSIC_DATA (-7)
#define aAlgoECSrc_D_ERR_WRONG_TARGET_DATA (-8)
#define aAlgoECSrc_D_ERR_NOTARGET (-9)
#define aAlgoECSrc_D_ERR_WRONG_INTRINSIC_DATA (-10)
#define aAlgoECSrc_D_ERR_NO_CAMERA_ATTACHED (-11)
#define aAlgoECSrc_D_ERR_EOL_ABORTED (-12)
#define aAlgoECSrc_D_ERR_NULLSPACE (-13)
#define aAlgoECSrc_D_ERR_GROUNDTRUTH_NOTMATCH (-14)
#define aAlgoECSrc_D_ERR_WRONGCAMERAID (-15)
#define aAlgoECSrc_D_ERR_CROP_OUTOFRANGE (-17)
#define aAlgoECSrc_D_ERR_CALIB_FAIL_X (-19)
#define aAlgoECSrc_D_ERR_CALIB_FAIL_Y (-20)
#define aAlgoECSrc_D_ERR_CALIB_FAIL_Z (-21)
#define aAlgoECSrc_D_ERR_CALIB_FAIL_ROLL (-22)
#define aAlgoECSrc_D_ERR_CALIB_FAIL_YAW (-23)
#define aAlgoECSrc_D_ERR_CALIB_FAIL_PITCH (-24)
#define aAlgoECSrc_D_AVERAGE_RESULT_FAIL (-25)
#define aAlgoECSrc_D_NO_LOCAL_EXTERMA (-26)
#define aAlgoECSrc_D_NO_CLEAN_CANDIDATES (-27)
#define aAlgoECSrc_D_INTERNAL_ALGO_ERROR (-28)
#define aAlgoECSrc_D_ERR_WRONG_TARGET_TD (-29)

/* +++ Public Variables, Constants +++++++++++++++++++++++++++++++++++++++++++ */

/* +++ Public Macros +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

#define SQRT_2   (1.4142135623730951F)
/* +++ Public Function Prototypes ++++++++++++++++++++++++++++++++++++++++++++ */

/* === End of Header File ==================================================== */

#endif
/* // ---------------------------------- EOF -------------------------------------- */
