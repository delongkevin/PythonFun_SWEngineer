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

  $Header: local_extrema.c 1.15 2017/04/25 16:14:17IST Timo Dehm (MEE_TDEHM) draft  $       
  $Author: Timo Dehm (MEE_TDEHM) $
  $Date: 2017/04/25 16:14:17IST $
  $Revision: 1.15 $

===================================================================================*/

/*
MKS change history (will be updated automatically by MKS, do not change manually)
$Log: local_extrema.c  $
Revision 1.15 2017/04/25 16:14:17IST Timo Dehm (MEE_TDEHM) 
Merge since:
fix for aggregate return type warnings
Revision 1.14.1.1 2017/04/24 09:06:08CEST Schulte, Michael (MEE_MiSch) 
fix for aggregate return type warnings
Revision 1.14 2016/12/08 15:31:49CET Dehm, Timo (MEE_TDEHM) 
correct merge
Revision 1.11 2016/06/01 17:50:57MESZ Rasool, Muzammil (MEE_MRASOO) 
naming convention
Revision 1.10 2016/06/01 17:37:40CEST Rasool, Muzammil (MEE_MRASOO) 
Naming Conventions related changes  in C files.
Revision 1.9 2016/05/31 16:04:38CEST Rasool, Muzammil (MEE_MRASOO) 
QAC changes.
Revision 1.7.1.1 2016/04/12 19:43:16CEST Wang, Hongtao (E32953) 
QAC warning removed
Revision 1.7 2016/03/14 08:05:23EDT Dehm, Timo (MEE_TDEHM) 
Merge since:
Renamed float constants to upper-case F
Revision 1.6.2.1 2016/03/11 10:27:53MEZ Schulte, Michael (MEE_MiSch) 
Renamed float constants to upper-case F
Revision 1.6 2015/08/18 16:43:12CEST Rasool, Muzammil (MEE_MRASOO) 
Removed compiled warnings.
Revision 1.5 2015/06/04 00:33:11CEST Rasool, Muzammil (MEE_MRASOO) 
ind_startup.h removed from #includes.
Revision 1.4 2015/05/29 13:27:14CEST Rasool, Muzammil (MEE_MRASOO) 
Eol with new MECL integrated.
Revision 1.3 2015/02/04 10:57:51CET Rasool, Muzammil (MEE_MRASOO) 
Eol Results are correct now.
All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
ARM FPU internally calculates floating point operations with 64-bit, 
and adds inaccuracices when rounds it down to 32-bit.
Revision 1.2 2015/02/03 11:54:09CET Rasool, Muzammil (MEE_MRASOO) 
Eol Algo intergrated. Results are not correct yet. 
Floating-point calculation results don't match on PC and ECU with same code.
Revision 1.1 2015/01/21 14:46:52CET Rasool, Muzammil (MEE_MRASOO) 
Initial revision
Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
Revision 1.4.1.3 2015/02/17 03:15:13EST Pliefke, Sebastian (MEE_SPLIEF) 
Reactivate hardware accelaration
Revision 1.4.1.2 2014/11/28 16:11:19CET Pliefke, Sebastian (MEE_SPLIEF) 
Make malloc replacement extern
Revision 1.4.1.1 2013/12/13 15:26:45CET tknudsen 
Added call to FPGA template matcher convolution function
Revision 1.4 2013/07/25 18:03:01MESZ Sebastian Pliefke (spliefke) 
Solve merging issue
Revision 1.3 2013/07/25 18:00:37MESZ Sebastian Pliefke (spliefke) 
Mergned
Revision 1.2 2013/07/18 14:47:07MESZ Sebastian Pliefke (spliefke) 
Latest changes
Revision 1.1 2013/07/09 16:52:08MESZ Sebastian Pliefke (spliefke) 
Initial revision
Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/corner/project.pj
Revision 1.24 2012/07/12 22:29:30MESZ Marko Vico (mvico) 
EoL algo update 4.2 - 'static' modifier removed from Left and Right Kernels
Revision 1.23 2012/06/26 12:37:50EDT Tina Behal (tbehal) 
Initial revision
Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
Revision 1.23 2012/03/21 16:14:51EDT Marko Vico (mvico) 
Misra C changes applied
Revision 1.22 2012/01/23 10:45:45EST Ali Ahmed (aahmed) 
Major system and OC changes.
Revision 1.21 2011/11/15 16:26:50EST Ali Ahmed (aahmed) 
EOL now looks at the variant coding to determine the roll related changes inside the processing block of EC.
Revision 1.20 2011/11/10 10:14:01EST Marko Vico (mvico) 
Convolution kernels updated according to the Matlab implementation
Revision 1.19 2011/10/27 12:15:22EDT Ali Ahmed (aahmed) 
Added more error codes.
Revision 1.18 2011/10/14 12:32:37EDT Anupama Bhide (abhide) 
QAC Misra C modifications
Revision 1.17 2011/08/12 14:47:16EDT Ali Ahmed (aahmed) 
EOL MISRA-C Changes.
Revision 1.16 2011/08/12 13:39:47EDT Ali Ahmed (aahmed) 
Added define for EOL stat collection.
Revision 1.15 2011/08/12 13:31:28EDT Ali Ahmed (aahmed) 
EOL MISRA-C Changes.
Revision 1.13 2011/08/04 17:23:08EDT Ali Ahmed (aahmed) 
EOL optimization related changes.
Revision 1.12 2011/08/04 10:53:01EDT Sala Annamalai (sannamalai) 
added official template
Revision 1.1 2011/03/25 15:37:27EDT Ron Zibman (rzibman) 
Initial revision
Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#include "local_extrema.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>


/* --- Private Typedefinitions, Enumerations, Defines ------------------------ */
/* PRQA S 4800 EOF */
/* PRQA S 7001 EOF */
/* PRQA S 7003 EOF */
/* PRQA S 7006 EOF */
/* PRQA S 7008 EOF */

/* Pointer Arithmetic Rules*/
/* PRQA S 488 EOF */
/* PRQA S 489 EOF */
/* PRQA S 491 EOF */
/* PRQA S 492 EOF */

#define D_LocalNeighbors_Extrema 6U  /* extrema over neighbors */

#ifndef UINT32_MAX
#define UINT32_MAX 0xffffffffu
#endif

#ifndef UINT64_MAX
#define UINT64_MAX 0xffffffffffffffffu
#endif
/* --- Private Variables, Constants ------------------------------------------ */
/* PRQA S 612, 1041 1 */ /* Big size is ok. Empty initializers are intended. */
sint8_t V_Candidates_as8[2*960*540] = {};
/* define 10x10 template kernel */

sint8_t V_TKernelL_as8[100] = {       /*PRQA S 3218 */ /* File scope static  */
                                      -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /*7/3 -- 6/4 */

                                      -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /* 6/4 -- 6/4 */

                                      -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /* 6/4  -- 6/4 */

                                      -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /* 1/4/5 -- 5/5 */

                                      -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /* 3/2/5 -- 3/2/5 */

                                      1,  1,  1,  1,  1, -1, -1, -1, -1, -1,  /* 5/2/3 -- 5/2/3 */

                                      1,  1,  1,  1,  1, -1, -1, -1, -1, -1, /*5/4/1 -- 5/5 */

                                      1,  1,  1,  1,  1, -1, -1, -1, -1, -1, /* 4/6 -- 4/6 */

                                      1,  1,  1,  1,  1, -1, -1, -1, -1, -1, /* 4/6 -- 4/6 */

                                      1,  1,  1,  1,  1, -1, -1, -1, -1, -1 }; /* 3/7 -- 4/6 */


/* define 10x10 template kernel */
sint8_t V_TKernelR_as8[100] = {      /*PRQA S 3218 */ /* File scope static  */
                                     -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /*7/3 -- 6/4 */

                                     -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /* 6/4 -- 6/4 */

                                     -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /* 6/4  -- 6/4 */

                                     -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /* 1/4/5 -- 5/5 */

                                     -1, -1, -1, -1, -1,  1,  1,  1,  1,  1, /* 3/2/5 -- 3/2/5 */

                                     1,  1,  1,  1,  1, -1, -1, -1, -1, -1,  /* 5/2/3 -- 5/2/3 */

                                     1,  1,  1,  1,  1, -1, -1, -1, -1, -1, /*5/4/1 -- 5/5 */

                                     1,  1,  1,  1,  1, -1, -1, -1, -1, -1, /* 4/6 -- 4/6 */

                                     1,  1,  1,  1,  1, -1, -1, -1, -1, -1, /* 4/6 -- 4/6 */

                                     1,  1,  1,  1,  1, -1, -1, -1, -1, -1 }; /* 3/7 -- 4/6 */
/* for aExtrema_F_InitCandidates_s8 */


/* for f_CleanCandidates_v */
/* PRQA S 1041 1 */ /* Empty initializers are intended. */
static io_S_Pos_t V_CanPos_as[ aAlgoECSrc_D_MAX_CANDIDATE_NO ] = {};  /*PRQA S 3218 */ /* File scope static  */

/* --- Private Macros -------------------------------------------------------- */

/* --- Private Function Prototypes ------------------------------------------- */

static void f_NeighborExtrema_v( const float32_t i_Data_af32[],  /* convolved image */
                                 uint16_t i_ImgX_u16, uint16_t i_ImgY_u16, float32_t i_Threshold_f32, sint8_t b_Candidates_as8[],  /* candidate map */
                                 uint32_t *o_CandCount_pu32 /* counter */
);

static void f_CleanCandidates_v( const float32_t i_ImgData_af32[],  /* convolved image */
                                 uint16_t i_ImgX_u16, uint16_t i_ImgY_u16, const sint8_t i_Candidates_as8[],  /* candidate map */
                                 io_S_PosSub_t *o_CanPosSub_ps,  /* candidate list subpixel */
                                 uint32_t *b_Candidates_pu32 /* no of candidates */
);

/* uint8_t f_inRange_u8( uint16_t i_X_u16, uint16_t i_XMax_u16 ); */

static sint8_t f_isCandidate_s8( const float32_t i_R_af32[], float32_t i_CorrThresh_f32, uint16_t i_X_u16, uint16_t i_Y_u16, uint16_t i_LineWidth_u16 );
#if 0
static io_S_PosSub_t f_FitParabolas2D_t( float32_t *i_DataRow_pf32,  /* input variable data by row for fitting */
                                         float32_t *i_DataCol_pf32,  /* input variable data by column for fitting */
                                         uint8_t i_DataX_u8,  /* input size X of the data */
                                         uint8_t i_DataY_u8 /* input size Y of the data */
);
#endif
static float32_t f_getDistance_f32( io_S_PosSub_t i_Pix1_s, io_S_PosSub_t i_Pix2_s );

static void f_Extract_v( const float32_t i_ImgData_af32[],  /* input image data */
                         uint16_t i_ImgX_u16, io_S_Pos_t i_CanPos_s,  /* input selected area position*/
                         float32_t *o_Area_pf32);

static uint32_t f_FindInitialCandidates_u32( const sint8_t b_Candidates_as8[],  /* candidate map */
                                             uint16_t i_X_u16, uint16_t i_Y_u16,  /* size of the map */
                                             io_S_Pos_t *o_CanPos_ps /* output list of candidate position */
);

static void f_BiVariantAppr_v( const float32_t i_ImgData_af32[],  /* image data */
                                        uint16_t i_ImgX_u16, io_S_Pos_t i_CanPos_s,  /* candidate position */
                                        io_S_PosSub_t *b_Res_pt);

static void f_CleanKeepSub_v( io_S_PosSub_t *o_CanPosSub_ps,  /* input and output the survived candidates */
                              uint32_t *o_Candidates_pu32 );



static void f_RegisterSubpixel_v( const sint8_t i_Candidates_as8[],  /* input candidates */
                                  uint16_t i_ImgX_u16, io_S_Pos_t i_CanPos_s,  /* input candidate position */
                                  io_S_PosSub_t i_SubPix_s,  /* input fitted subpixel value */
                                  io_S_PosSub_t *o_CanPosSub_ps,  /* input and output the survived candidates */
                                  uint32_t *o_Candidates_pu32 /* total number of output */
);

/* single float32_t precision convolution
 * calculate the 2D convolution
 * get the normalization coefficients */
static void f_ConvNorm_v(uint8_t *i_Img_pu8,  /* input image data for convolution */
                         const uint16_t i_X_u16,  /* input size of the image data in X */
                         const uint16_t i_Y_u16,  /* input size of the image data in Y */
                         sint8_t *i_TKernel_ps8,  /* input kernel for convolution */
                         /*sint8_t *i_TKernel_K2_ps8,*/  /*  for the second kernel */
                         uint16_t i_KX_u16,  /* input size of the kernel in X */
                         uint16_t i_KY_u16,  /* input size of the kernel in Y */
                         float32_t *o_Data_pf32 /* output data after the convolution */
);

static uint16_t f_MathRound_u16( float32_t i_Number_f32 );
/* +++ Public Function Definitions +++++++++++++++++++++++++++++++++++++++++++ */
/* 
 * first few steps to find the initial candidates
 * 1. do the convolution/normliaztion
 * 2. extract the extrema
 * 3. clean the extrema 
 * 4. extract all candidates and save into a list
 */

void aExtrema_F_getConvImg_v( uint8_t *i_ImgData_pu8, const uint16_t i_ImgX_u16, const uint16_t i_ImgY_u16, float32_t o_NormImg_af32[])
{
  /* DD-ID: {71240EDD-4083-41d2-9F1A-5D521B0969BB}*/
  f_ConvNorm_v( i_ImgData_pu8, i_ImgX_u16, i_ImgY_u16, V_TKernelL_as8, /*TKernel_R_s8, */aAlgoECSrc_D_KernelX, aAlgoECSrc_D_KernelY, o_NormImg_af32);

  /* aAppl_F_ConvNorm_v((uint32_t*)i_ImgData_pu8, o_NormImg_pf32, i_ImgX_u16, i_ImgY_u16); */
}

/* ------------------------------------------------------------------------- */
sint8_t aExtrema_F_InitializeCandiates_s8( const float32_t i_NormImg_pf32[], uint16_t i_ImgX_u16, uint16_t i_ImgY_u16, float32_t i_threshold_f32, io_S_PosSub_t *o_CanPosSub1_ps,  /* output candidates list */
                                          uint32_t *o_CanCount_pu32 /* output no of candidates */
)
{
  /* DD-ID: {97D70B2D-CAB0-45fc-B808-5403D7F740C6}*/
  io_S_PosSub_t *v_CanPosSub_ps; /* subpixel */
  sint8_t v_ErrCode_s8 = aAlgoECSrc_D_SUCCESS;
  /* find local extrema */
  f_NeighborExtrema_v( i_NormImg_pf32, i_ImgX_u16, i_ImgY_u16, i_threshold_f32,V_Candidates_as8, o_CanCount_pu32 );

  if( *o_CanCount_pu32 == 0U )
  {
    v_ErrCode_s8 = aAlgoECSrc_D_NO_LOCAL_EXTERMA;
  }
  else
  {
    /* clean the extrema */
    v_CanPosSub_ps = o_CanPosSub1_ps;

    f_CleanCandidates_v( i_NormImg_pf32, i_ImgX_u16, i_ImgY_u16, V_Candidates_as8, v_CanPosSub_ps, o_CanCount_pu32 );

    if( *o_CanCount_pu32 == 0U )
    {
      v_ErrCode_s8 = aAlgoECSrc_D_NO_CLEAN_CANDIDATES;
    }
  }
  return v_ErrCode_s8;

}

/* --- Private Function Definitions ------------------------------------------ */



/* Remove multiple candidates in a small neighborhood
 * given by a threshold
 * keep only the maximized/minimized one
 */
static void f_CleanCandidates_v( const float32_t i_ImgData_af32[],  /* convolved image */
                                 uint16_t i_ImgX_u16, uint16_t i_ImgY_u16, const sint8_t i_Candidates_as8[],  /* candidate map */
                                 io_S_PosSub_t *o_CanPosSub_ps,  /* candidate list subpixel */
                                 uint32_t *b_Candidates_pu32 /* no of candidates */
)
{
  /* DD-ID: {939BBBC8-A166-4201-A291-739106C4914E}*/
  uint16_t v_I_u16; /* iteration variables */
  uint16_t v_iX_u16 = i_ImgX_u16;
  uint16_t v_iY_u16 = i_ImgY_u16; /* image size */

  uint32_t v_CanCouter_u32; /* counter 2 */
  uint32_t v_CanCouter2_u32 = 0U;

  /*  Marko Added - 'What if number of candidates excede 2000? ' SYSTEM CHRASHES RIGHT NOW */
  io_S_Pos_t *v_CanPos_ps = V_CanPos_as;				

  /* Fit parabola values, and positions in X and Y */
  io_S_PosSub_t v_SubPixelFit_s;

  /* find all initial candidates */
  v_CanCouter_u32 = f_FindInitialCandidates_u32( i_Candidates_as8, v_iX_u16, v_iY_u16, v_CanPos_ps );

  ( *b_Candidates_pu32 ) = 0U;
  /* for each candidates */
  for( v_I_u16 = 0U; v_I_u16 < v_CanCouter_u32; v_I_u16++ )
  {
    /* Bi-variate square approximation */
    f_BiVariantAppr_v( i_ImgData_af32, i_ImgX_u16, *v_CanPos_ps, &v_SubPixelFit_s);

    /* modification maybe because of access bug SEBI */
    /* v_SubPixelFit_t.x_f32 = 0; */
    /* v_SubPixelFit_t.y_f32 = 0; */
    /* SEBI */

    f_RegisterSubpixel_v( i_Candidates_as8,  /* input candidates */
                          i_ImgX_u16, *v_CanPos_ps,  /* input candidate position */
                          v_SubPixelFit_s,  /* input fitted subpixel value */
                          o_CanPosSub_ps,  /* input and output the survived candidates */
                          &v_CanCouter2_u32 /* total number of output */
    );
    v_CanPos_ps++;
  }
  f_CleanKeepSub_v( o_CanPosSub_ps,  /* input and output the survived candidates */
                    &v_CanCouter2_u32 );
  ( *b_Candidates_pu32 ) = v_CanCouter2_u32;
}

/* ------------------------------------------------------------------------- */

static void f_NeighborExtrema_v( const float32_t i_Data_af32[],  /* convolved image */
                                 uint16_t i_ImgX_u16, uint16_t i_ImgY_u16, float32_t i_Threshold_f32, sint8_t b_Candidates_as8[],  /* candidate map */
                                 uint32_t *o_CandCount_pu32 /* counter */
)
{
  /* DD-ID: {CB74C9D3-4EB4-4afe-B794-06A8D4F9CE64}*/
  uint16_t v_I_u16;
  uint16_t v_J_u16; /* iteration variables */
  sint8_t v_K_s8;
  /*memset( b_Candidates_ps8, 0, sizeof( sint8_t ) *aAlgoECSrc_D_ImageY_Cut * aAlgoECSrc_D_ImageX_Cut );*/  /*PRQA S 3200 */   /* return type is not being used	 */
  memset( b_Candidates_as8, 0, sizeof( sint8_t ) *i_ImgX_u16 * i_ImgY_u16 );  /*PRQA S 3200 */   /* return type is not being used	 */

  for( v_I_u16 = 4U; v_I_u16 < ( i_ImgY_u16 - 4U ); v_I_u16++ )
  {
    /* for each pixel */
    for( v_J_u16 = 4U; v_J_u16 < ( i_ImgX_u16 - 4U ); v_J_u16++ )
    {
      /* counter: how many pixels is larger or smaller 
            than the center pixel? */
      v_K_s8 = f_isCandidate_s8( i_Data_af32, i_Threshold_f32, v_J_u16, v_I_u16, i_ImgX_u16);

      b_Candidates_as8[ (v_I_u16*i_ImgX_u16)+v_J_u16 ] = v_K_s8;

      ( *o_CandCount_pu32 ) += (uint32_t)abs( (sint32_t)v_K_s8 );

    }
  }
}



/* whether the pixel is a candidate */
static sint8_t f_isCandidate_s8( const float32_t i_R_af32[], float32_t i_CorrThresh_f32, uint16_t i_X_u16, uint16_t i_Y_u16, uint16_t i_LineWidth_u16 )
{
  /* DD-ID: {F59469AA-CBC7-4338-82E1-E1B23E5A106D}*/
  uint8_t v_LargeCounter_u8 = 0U;
  uint8_t v_SmallCounter_u8 = 0U;
  sint8_t v_res_s8 = 0;
  uint16_t v_Pixel11_u16;
  uint16_t v_Pixel12_u16;
  uint16_t v_Pixel13_u16;
  uint16_t v_Pixel21_u16;
  uint16_t v_Pixel23_u16;
  uint16_t v_Pixel31_u16;
  uint16_t v_Pixel32_u16;
  uint16_t v_Pixel33_u16;
  float32_t v_V_f32;

  v_Pixel11_u16 =  ((i_Y_u16 - 1U)*i_LineWidth_u16) + (i_X_u16 - 1U);
  v_Pixel12_u16 =  ((i_Y_u16 - 1U)*i_LineWidth_u16) + (i_X_u16 - 0U);
  v_Pixel13_u16 =  ((i_Y_u16 - 1U)*i_LineWidth_u16) + (i_X_u16 + 1U);
  v_Pixel21_u16 =  ((i_Y_u16 - 0U)*i_LineWidth_u16) + (i_X_u16 - 1U);
  v_Pixel23_u16 =  ((i_Y_u16 - 0U)*i_LineWidth_u16) + (i_X_u16 + 1U);
  v_Pixel31_u16 =  ((i_Y_u16 + 1U)*i_LineWidth_u16) + (i_X_u16 - 1U);
  v_Pixel32_u16 =  ((i_Y_u16 + 1U)*i_LineWidth_u16) + (i_X_u16 - 0U);
  v_Pixel33_u16 =  ((i_Y_u16 + 1U)*i_LineWidth_u16) + (i_X_u16 + 1U);

  v_V_f32 = i_R_af32[ (i_Y_u16*i_LineWidth_u16)+i_X_u16 ]; /* value */
  if( fabs( (float64_t)v_V_f32 ) > i_CorrThresh_f32 )
  {

    if( i_R_af32[v_Pixel11_u16 ] > v_V_f32 )
    {
      v_SmallCounter_u8++;
    }
    if( i_R_af32[v_Pixel11_u16] < v_V_f32 )
    {
      v_LargeCounter_u8++;
    }

    if( i_R_af32[v_Pixel12_u16] > v_V_f32 )
    {
      v_SmallCounter_u8++;
    }
    if( i_R_af32[v_Pixel12_u16 ] < v_V_f32 )
    {
      v_LargeCounter_u8++;
    }

    if( i_R_af32[v_Pixel13_u16] > v_V_f32 )
    {
      v_SmallCounter_u8++;
    }
    if( i_R_af32[v_Pixel13_u16] < v_V_f32 )
    {
      v_LargeCounter_u8++;
    }

    if( i_R_af32[v_Pixel21_u16] > v_V_f32 )
    {
      v_SmallCounter_u8++;
    }
    if( i_R_af32[v_Pixel21_u16] < v_V_f32 )
    {
      v_LargeCounter_u8++;
    }

    if( i_R_af32[v_Pixel23_u16] > v_V_f32 )
    {
      v_SmallCounter_u8++;
    }
    if( i_R_af32[v_Pixel23_u16] < v_V_f32 )
    {
      v_LargeCounter_u8++;
    }

    if( i_R_af32[v_Pixel31_u16] > v_V_f32 )
    {
      v_SmallCounter_u8++;
    }
    if( i_R_af32[v_Pixel31_u16] < v_V_f32 )
    {
      v_LargeCounter_u8++;
    }

    if( i_R_af32[v_Pixel32_u16] > v_V_f32 )
    {
      v_SmallCounter_u8++;
    }
    if( i_R_af32[v_Pixel32_u16] < v_V_f32 )
    {
      v_LargeCounter_u8++;
    }

    if( i_R_af32[v_Pixel33_u16] > v_V_f32 )
    {
      v_SmallCounter_u8++;
    }
    if( i_R_af32[v_Pixel33_u16] < v_V_f32 )
    {
      v_LargeCounter_u8++;
    }

    if( v_LargeCounter_u8 > D_LocalNeighbors_Extrema )
    {
      v_res_s8 = 1;
    }
    else if( v_SmallCounter_u8 > D_LocalNeighbors_Extrema )
    {
      v_res_s8 =  - 1;
    }
    else
    {
    }
  }

  return v_res_s8;
}

/* check whether a pixel is within the valid range */
/*
uint8_t f_inRange_u8( uint16_t i_X_u16, uint16_t i_XMax_u16 )
{
  uint8_t v_res_u8;
  if( i_X_u16 > i_XMax_u16 )
  {
    v_res_u8 = 0U;
  }
  else
  {
    v_res_u8 = 1U;
  }
  return v_res_u8;
}
 */

static void f_FitParabolas2D_v( float32_t *i_DataRow_pf32, io_S_PosSub_t *v_Res_pt);
/* bi-variant approximate by a radius */
static void f_BiVariantAppr_v( const float32_t i_ImgData_af32[],  /* image data */
                                        uint16_t i_ImgX_u16, io_S_Pos_t i_CanPos_s, io_S_PosSub_t *v_Res_pt
)
{
  /* DD-ID: {CBFA5022-9DBF-4a53-9745-AF40BFB59629}*/
  float32_t v_AreaRow_af32[ 25 ];

  v_Res_pt->x_f32 = -1.0F;
  v_Res_pt->y_f32 = -1.0F;
  v_Res_pt->v_f32 = -1.0F;

  /* Bi-variate square approximation */
  f_Extract_v( i_ImgData_af32, i_ImgX_u16, i_CanPos_s, v_AreaRow_af32);

  f_FitParabolas2D_v( v_AreaRow_af32, v_Res_pt);
}

/* output unsigned short integer */
static uint16_t f_MathRound_u16( float32_t i_Number_f32 ) /* input float32_t number */
{
  /* DD-ID: {BC92B1CD-97F4-4e01-B97F-F031FAE3F743}*/

  /* return (uint16_t)round((float64_t)i_Number_f32); */		/*  <<Sebi */
  return (uint16_t)(i_Number_f32+0.5F);						/*  >>Sebi */
}

/* load all initial candidates from candidate map */
static uint32_t f_FindInitialCandidates_u32( const sint8_t b_Candidates_as8[],  /* candidate map */
                                             uint16_t i_X_u16, uint16_t i_Y_u16,  /* size of the map */
                                             io_S_Pos_t *o_CanPos_ps /* output list of candidate position */
)
{
  /* DD-ID: {D0CF9960-C953-464b-84EB-88EB9F408E15}*/
  uint16_t v_I_u16;
  uint16_t v_J_u16; /* iteration variables */
  uint32_t v_CanCouter_u32 = 0U;
  io_S_Pos_t *v_CanPos_ps = o_CanPos_ps;
  /* find all initial candidates */
  for( v_I_u16 = 0U; v_I_u16 < i_Y_u16; v_I_u16++ )
  {
    for( v_J_u16 = 0U; v_J_u16 < i_X_u16; v_J_u16++ )
    {
      if( b_Candidates_as8[ (v_I_u16*i_X_u16)+v_J_u16 ] != 0 )
      {
        v_CanPos_ps->y_s16 = ( sint16_t )v_I_u16;
        v_CanPos_ps->x_s16 = ( sint16_t )v_J_u16;
        /*  Marko Added - > if this pointer excedes 2000 SYSTEM CHRASHES */
        v_CanPos_ps++;
        v_CanCouter_u32++;

        if(v_CanCouter_u32>=aAlgoECSrc_D_MAX_CANDIDATE_NO)
        {
          break;
        }
      }
    }
    /*  Marko Added */
    if(v_CanCouter_u32>=aAlgoECSrc_D_MAX_CANDIDATE_NO)
    {
      break;
    }
  }
  return v_CanCouter_u32;
}

/* extract by row */
static void f_Extract_v( const float32_t i_ImgData_af32[],  /* input image data */
                         uint16_t i_ImgX_u16, io_S_Pos_t i_CanPos_s,  /* input selected area position*/
                         float32_t *o_Area_pf32)
{
  /* DD-ID: {F71CF5CC-3F73-43d4-9549-06684EACF183}*/
  uint16_t v_I_u16;
  uint16_t v_J_u16; /* iteration variables */
  uint16_t v_RowMin_u16;
  uint16_t v_ColMin_u16; /* starting position, row/col */
  uint16_t v_RowMax_u16;
  uint16_t v_ColMax_u16; /* end position of the area */
  float32_t *v_AreaW_pf32; /* work pointer for output */

  uint16_t i_pX_u16 = (uint16_t)i_CanPos_s.x_s16, i_pY_u16 = (uint16_t)i_CanPos_s.y_s16; /* image size */

  v_RowMin_u16 = i_pY_u16 - 2U; /* r_min = max(1, r-rad); */
  v_ColMin_u16 = i_pX_u16 - 2U; /* c_min = max(1, c-rad); */
  /* r_max = min(MAXROW, r+rad); */
  v_RowMax_u16 = i_pY_u16 + 2U;
  /* c_max = min(MAXCOL, c+rad); */
  v_ColMax_u16 = i_pX_u16 + 2U;

  v_AreaW_pf32 = o_Area_pf32;
  /* count by row */
  for( v_I_u16 = v_RowMin_u16; v_I_u16 <= v_RowMax_u16; v_I_u16++ )
  {
    for( v_J_u16 = v_ColMin_u16; v_J_u16 <= v_ColMax_u16; v_J_u16++ )
    {
      *v_AreaW_pf32 = i_ImgData_af32[ (v_I_u16*i_ImgX_u16)+v_J_u16 ];
      v_AreaW_pf32++;
    }
  }
}


/* 
 * Check the position validation
 * keep all the subpixel position and value
 * removed invalid candiates
 */
static void f_RegisterSubpixel_v( const sint8_t i_Candidates_as8[],  /* input candidates */
                                  uint16_t i_ImgX_u16, io_S_Pos_t i_CanPos_s,  /* input candidate position */
                                  io_S_PosSub_t i_SubPix_s,  /* input fitted subpixel value */
                                  io_S_PosSub_t *o_CanPosSub_ps,  /* input and output the survived candidates */
                                  uint32_t *o_Candidates_pu32 /* total number of output */
)
{
  /* DD-ID: {6ABE6BB3-59DA-410a-B672-9C4184EE674A}*/
  uint32_t v_I_u32;

  float32_t v_pSubX_f32;
  float32_t v_pSubY_f32; /* subpixel position */
  uint16_t v_pX1_u16;
  uint16_t v_pY1_u16; /* round to integer position */
  uint16_t v_pX2_u16;
  uint16_t v_pY2_u16; /* round to integer position */

  uint32_t v_CanNo_u32 = ( *o_Candidates_pu32 ); /* no of valid candidates */

  io_S_PosSub_t v_pix1_s; /* two pixels in subpixel */

  sint32_t v_found_s32 =  - 2;
  float64_t v_Temp001_f64;
  float64_t v_Temp002_f64;

  v_pSubX_f32 = ( ( float32_t )i_CanPos_s.x_s16 + i_SubPix_s.x_f32 );
  v_pSubY_f32 = ( ( float32_t )i_CanPos_s.y_s16 + i_SubPix_s.y_f32 );
  v_pX1_u16 = f_MathRound_u16( v_pSubX_f32 );
  v_pY1_u16 = f_MathRound_u16( v_pSubY_f32 );

  /* if( ( f_inRange_u8( v_pX1_u16, i_ImgX_u16 ) == 1 ) && ( f_inRange_u8( v_pY1_u16, i_ImgY_u16 ) == 1 ) ) */
  {
    /* inside image */
    /* SEBI if( i_Candidates_ps8[ v_pY1_u16*i_ImgX_u16+v_pX1_u16 ] != 0 ) */
    if( i_Candidates_as8[ (i_CanPos_s.y_s16*i_ImgX_u16)+i_CanPos_s.x_s16 ] != 0 )
    {
      /* is a candidate */
      v_pix1_s.v_f32 = i_SubPix_s.v_f32;
      v_pix1_s.x_f32 = ( float32_t ) ( v_pSubX_f32 + 0.5 );
      v_pix1_s.y_f32 = ( float32_t ) ( v_pSubY_f32 + 0.5 );

      for( v_I_u32 = 0U; v_I_u32 < v_CanNo_u32; v_I_u32++ )
      {
        v_pX2_u16 = f_MathRound_u16( o_CanPosSub_ps[ v_I_u32 ].x_f32 );
        v_pY2_u16 = f_MathRound_u16( o_CanPosSub_ps[ v_I_u32 ].y_f32 );

        if( (v_pY1_u16 == v_pY2_u16) && (v_pX1_u16 == v_pX2_u16) )
        {
          v_found_s32 = (sint32_t)v_I_u32;
          v_Temp001_f64 = fabs( (float64_t)v_pix1_s.v_f32 );
          v_Temp002_f64 = fabs( (float64_t)o_CanPosSub_ps[ v_I_u32 ].v_f32 );
          if( v_Temp001_f64 > v_Temp002_f64 ) {
            o_CanPosSub_ps[ v_I_u32 ] = v_pix1_s;

          } /*if*/
        } /*if*/
      } /*for*/

      if( v_found_s32 < 0 )
      {
        o_CanPosSub_ps[ v_CanNo_u32 ] = v_pix1_s;
        v_CanNo_u32++;
      }
    } /* if */
  } /*if*/
  ( *o_Candidates_pu32 ) = v_CanNo_u32;
}

/* Remove multiple candidates in a small neighborhood
 * given by a threshold
 * keep only the maximized/minimized one
 */
static void f_CleanKeepSub_v( io_S_PosSub_t *o_CanPosSub_ps,  /* input and output the survived candidates */
                              uint32_t *o_Candidates_pu32 )
{
  /* DD-ID: {234BC02F-63F3-4666-8E7F-7C372455C165}*/
  sint32_t v_I_s32;
  sint32_t v_J_s32;
  io_S_PosSub_t v_Pix1_s;
  io_S_PosSub_t v_Pix2_s;
  io_S_PosSub_t *v_PosSub_ps = o_CanPosSub_ps;
  io_S_PosSub_t *v_PosSub1_ps;
  sint32_t v_CanCouter_s32 =  (sint32_t)*o_Candidates_pu32;
  float32_t v_Dist_f32;
  sint8_t v_Survive_as8[ aAlgoECSrc_D_MAX_CANDIDATE_NO ];
  float64_t v_Temp001_f64;
  float64_t v_Temp002_f64;
  memset(v_Survive_as8, 1, sizeof(v_Survive_as8));  /*PRQA S 3200 */   /* return type is not being used	 */

  for( v_I_s32 = 0; v_I_s32 < (v_CanCouter_s32-1); v_I_s32++ )
  {
    v_Pix1_s = *( v_PosSub_ps + v_I_s32 );

    for( v_J_s32 = v_I_s32+1; v_J_s32 < v_CanCouter_s32; v_J_s32++ )
    {
      v_Pix2_s = *( v_PosSub_ps + v_J_s32 );

      if(  *( v_Survive_as8 + v_J_s32 ) > 0)
      {
        v_Dist_f32 = f_getDistance_f32( v_Pix1_s, v_Pix2_s );
        if(( v_Dist_f32 <= 2.25 ))
        {
          v_Temp001_f64 = fabs( (float64_t)v_Pix1_s.v_f32 );
          v_Temp002_f64 = fabs( (float64_t)v_Pix2_s.v_f32 );
          if( v_Temp001_f64 < v_Temp002_f64 )
          {
            v_Survive_as8[ v_I_s32 ] =  - 1;
          }else
          {
            v_Survive_as8[ v_J_s32 ] =  - 1;
          }
        }
      }
    }
  }

  *o_Candidates_pu32 = 0U;
  v_PosSub_ps = ( v_PosSub1_ps = o_CanPosSub_ps );
  for( v_I_s32 = 0; v_I_s32 < v_CanCouter_s32; v_I_s32++ )
  {
    if( ( *( v_Survive_as8 + v_I_s32 ) ) == 1 )
    {
      v_PosSub_ps->x_f32 = ( v_PosSub1_ps + v_I_s32 )->x_f32;
      v_PosSub_ps->y_f32 = ( v_PosSub1_ps + v_I_s32 )->y_f32;
      v_PosSub_ps->v_f32 = ( v_PosSub1_ps + v_I_s32 )->v_f32;
      v_PosSub_ps++;

      ( *o_Candidates_pu32 )++;
    }
  }
}


/*
 * Function: Fit a parabola to one dimension
 * return both the value and pos for this dimension
 * call twice for 2D
 * input: data in 1D either by row or by column D_FilterSize*D_FilterSize
 *        datasize, D_FilterSize*D_FilterSize
 * output: value and position
 */
/*
 * Function: Fit a parabola to one dimension
 * return both the value and pos for this dimension
 * call twice for 2D
 * input: data in 1D either by row or by column D_FilterSize*D_FilterSize
 *        datasize, D_FilterSize*D_FilterSize
 * output: value and position
 */

static const uint8_t V_DX2_au8[25] = { 1U, 4U, 9U, 16U, 25U,    /*PRQA S 3218 */ /* File scope static  */
                                       1U, 4U, 9U, 16U, 25U,
                                       1U, 4U, 9U, 16U, 25U,
                                       1U, 4U, 9U, 16U, 25U,
                                       1U, 4U, 9U, 16U, 25U};
static const uint8_t V_DX2T_au8[25] = {1U, 1U, 1U, 1U, 1U,     /*PRQA S 3218 */ /* File scope static  */
                                       4U, 4U, 4U, 4U, 4U,
                                       9U, 9U, 9U, 9U, 9U,
                                       16U, 16U, 16U, 16U, 16U,
                                       25U, 25U, 25U, 25U, 25U};
static const uint8_t V_DX_au8[25] = {1U, 2U, 3U, 4U, 5U,      /*PRQA S 3218 */ /* File scope static  */
                                     1U, 2U, 3U, 4U, 5U,
                                     1U, 2U, 3U, 4U, 5U,
                                     1U, 2U, 3U, 4U, 5U,
                                     1U, 2U, 3U, 4U, 5U};
static const uint8_t V_DXT_au8[25] = { 1U, 1U, 1U, 1U, 1U,    /*PRQA S 3218 */ /* File scope static  */
                                       2U, 2U, 2U, 2U, 2U,
                                       3U, 3U, 3U, 3U, 3U,
                                       4U, 4U, 4U, 4U, 4U,
                                       5U, 5U, 5U, 5U, 5U};

static  void f_FitParabolas2D_v( float32_t *i_DataRow_pf32, io_S_PosSub_t *b_Res_pt)
{
  /* DD-ID: {C4B3DCF4-7E7C-4d97-97EC-D85C1928EB93}*/
  float32_t v_SubpixelPosition_f32; /* temporary parameter for subpixel position */
  uint8_t v_I_u8;
  float32_t *v_DataY_pf32 = i_DataRow_pf32; /* work pointer for x points */
  float32_t v_SumY_f32 = 0.0F;
  float32_t v_SumXY_f32 = 0.0F;
  float32_t v_SumX2Y_f32 = 0.0F; /* temporary variables for summation of x, x*y, and x^2*y */
  float32_t v_SumXYt_f32 = 0.0F;
  float32_t v_SumX2Yt_f32 = 0.0F; /* temporary variables for summation of x, x*y, and x^2*y */
  float32_t v_ParaA1_f32;
  float32_t v_ParaB1_f32;
  float32_t v_ParaA2_f32;
  float32_t v_ParaB2_f32;
  float32_t v_ParaC2_f32;

  for( v_I_u8 = 0U; v_I_u8 < 25U; v_I_u8++ )
  {
    v_SumY_f32 += v_DataY_pf32[ v_I_u8 ]; /* summation of all y points */
    v_SumXY_f32 += (float32_t)V_DX_au8[v_I_u8] *v_DataY_pf32[ v_I_u8 ]; /* summation of all x*y */
    v_SumX2Y_f32 += (float32_t)V_DX2_au8[ v_I_u8 ] * v_DataY_pf32[ v_I_u8 ]; /* summation of all x^2*y */
    v_SumXYt_f32 += (float32_t)V_DXT_au8[ v_I_u8 ] *v_DataY_pf32[ v_I_u8 ]; /* summation of all x*y */
    v_SumX2Yt_f32 += (float32_t)V_DX2T_au8[ v_I_u8 ] *v_DataY_pf32[ v_I_u8 ]; /* summation of all x^2*y */
  }

  v_ParaB1_f32 = ( 25.0F*( ( v_SumXY_f32 *4895.0F ) - ( 1125.0F *v_SumX2Y_f32 ) ) )
       - ( ( v_SumY_f32*( ( 75.0F * 4895.0F ) - ( 1125.0F *275.0F ) ) )  + ( 275.0F*( ( 75.0F *v_SumX2Y_f32 ) - ( v_SumXY_f32 *275.0F ) ) ));

  v_ParaA1_f32 = ( ( 25.0F*( ( 275.0F *v_SumX2Y_f32 ) - ( v_SumXY_f32 *1125.0F ) ) )
      - ( 75.0F*( ( 75.0F *v_SumX2Y_f32 ) - ( v_SumXY_f32 *275.0F ) ) ) ) + ( v_SumY_f32*( ( 75.0F *1125.0F ) - ( 275.0F *275.0F ) ) );

  b_Res_pt->x_f32 = (v_ParaB1_f32 / (  - 2.0F * v_ParaA1_f32 )) - 3.0F;

  v_ParaC2_f32 = ( ( v_SumY_f32*( ( 275.0F *4895.0F ) - ( 1125.0F *1125.0F ) ) ) - ( 75.0F*( ( v_SumXYt_f32 *4895.0F ) - ( v_SumX2Yt_f32 *1125.0F ) ) ) ) +
      ( 275.0F*( ( v_SumXYt_f32 *1125.0F ) - ( 275.0F *v_SumX2Yt_f32 ) ) );

  v_ParaB2_f32 = ( 25.0F*( ( v_SumXYt_f32 *4895.0F ) - ( 1125.0F *v_SumX2Yt_f32 ) ) )
       - (( v_SumY_f32*( ( 75.0F * 4895.0F ) - ( 1125.0F *275.0F ) ) )  + ( 275.0F*( ( 75.0F *v_SumX2Yt_f32 ) - ( v_SumXYt_f32 *275.0F ) ) ));

  v_ParaA2_f32 = ( ( 25.0F*( ( 275.0F *v_SumX2Yt_f32 ) - ( v_SumXYt_f32 *1125.0F ) ) )
      - ( 75.0F*( ( 75.0F *v_SumX2Yt_f32 ) - ( v_SumXYt_f32 *275.0F ) ) ) ) + ( v_SumY_f32*( ( 75.0F *1125.0F ) - ( 275.0F *275.0F ) ) );


  v_SubpixelPosition_f32 = v_ParaB2_f32 / (  - 2.0F * v_ParaA2_f32 ) ;
  b_Res_pt->v_f32 = (((v_ParaB2_f32 *v_SubpixelPosition_f32)/2.0F) + v_ParaC2_f32)/87500.0F;
  b_Res_pt->y_f32 = v_SubpixelPosition_f32 - 3.0F;
}

/* ------------------------------------------------------------------------- */

static float32_t f_getDistance_f32( io_S_PosSub_t i_Pix1_s, io_S_PosSub_t i_Pix2_s )
{
  /* DD-ID: {67A32EDC-4B2C-4f82-8776-B2AB7E1E577E}*/
  float32_t v_P1X_f32 = i_Pix1_s.x_f32, v_P1Y_f32 = i_Pix1_s.y_f32; /* first candidate pixel */
  float32_t v_P2X_f32 = i_Pix2_s.x_f32, v_P2Y_f32 = i_Pix2_s.y_f32; /* second candidate pixel */

  return ( float32_t )( ( ( v_P1X_f32 - v_P2X_f32 )*( v_P1X_f32 - v_P2X_f32 ) ) + ( ( v_P1Y_f32 - v_P2Y_f32 )*( v_P1Y_f32 - v_P2Y_f32 ) ) );
}
/*
inline uint32_t inverse_sqrt(uint32_t x){
  _iq24	b;
  b = (_iq24)1.25 - ( x / 4);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  b = (_iq24)b * ((_iq24)1.5 - (_iq24)x * (_iq24)b * (_iq24)b / 2);
  return b;
}
 */
/*inline*/ /*static uint16_t isqrt2_u32(uint32_t x){
  register uint32_t r,h,xx;
  r  = ((uint32_t)UINT32_MAX >> 2U) + 1U;
  h  = ((uint32_t)UINT32_MAX >> 3U) + 1U;
  xx = ((uint32_t)UINT32_MAX >> 2U) + 1U;  // x^2
  do{
    if(x > xx){
      xx = xx + r + ( h >> 1 );
      r = (r + h) >> 1;
    }else{
      xx = (xx + (h>>1)) - r;
      r = (r - h) >> 1;
    }
    h >>= 2;
  }while( h != 0U );
  if (x <= (xx - r)){
    r--;
  }else if (x > (xx + r) ){
    r++;
  }else{
  }
  return (uint16_t )r;
}*/
/*
 * template matching and normalization
 */
static void f_ConvNorm_v( uint8_t *i_Img_pu8,  /* input image data for convolution */
                          const uint16_t i_X_u16,  /* input size of the image data in X */
                          const uint16_t i_Y_u16,  /* input size of the image data in Y */
                          sint8_t *i_TKernel_ps8,  /* input kernel for convolution */
                          /*sint8_t *i_TKernel_K2_ps8,*/  /*  for the second kernel */
                          uint16_t i_KX_u16,  /* input size of the kernel in X */
                          uint16_t i_KY_u16,  /* input size of the kernel in Y */
                          float32_t *o_Data_pf32 /* output data after the convolution */)
{
  /* DD-ID: {B8C35273-54FC-4829-857B-4BD744E3B25F}*/
  uint16_t v_I_u16;
  uint16_t v_J_u16;
  uint16_t v_M_u16;
  uint16_t v_N_u16; /* iteration variables */
  uint8_t *v_ImgData1_pu8;
  uint8_t *v_ImgData2_pu8;
  float32_t *v_OData_pf32;
  sint8_t *v_Kernel1_ps8; /* pointers for each data */
  /*sint8_t *v_Kernel1_K2_ps8;*/  /*  for the second kernel */
  uint16_t v_KCenterX_u16;
  uint16_t v_KCenterY_u16; /* center of the template */
  sint16_t v_YMin_s16;
  sint16_t v_YMax_s16; /* boundary check for the input image data */
  sint16_t v_XMin_s16;
  sint16_t v_XMax_s16;
  sint32_t v_Temp1_s32;
  uint32_t v_Temp2_u32;
  uint32_t v_Temp3_u32;
  /*sint32_t v_temp1_K2;*/				/*  for the second kernel */
  uint8_t v_PixelData_u8;
  uint16_t v_X2_u16 = ( aAlgoECSrc_D_KernelX *aAlgoECSrc_D_KernelY ); /* coefficients for normalization */
  float64_t v_Test_f64;
  float64_t v_Max_f64=0.0;
  float64_t v_Min_f64=0.0;

  /* half size, to find the center of the kernel */
  v_KCenterX_u16 = i_KX_u16 >> 1;
  v_KCenterY_u16 = i_KY_u16 >> 1;
  /* work pointers for image data, kernel and output */
  v_ImgData1_pu8 = ( v_ImgData2_pu8 = &( i_Img_pu8[ 0 ] ) + ( ( i_X_u16 *v_KCenterY_u16 ) + v_KCenterX_u16 ) ); /* note that  it is shifted (kCenterX, kCenterY), */
  v_OData_pf32 = o_Data_pf32;
  v_Kernel1_ps8 = i_TKernel_ps8;
  /* v_Kernel1_K2_ps8 = i_TKernel_K2_ps8;*/ /*  for the second kernel */
  /* convolution */
  for (v_I_u16 = 0U; v_I_u16 < i_Y_u16; ++v_I_u16)
  {
    /* current range of the convolution */
    v_YMax_s16 = (( sint16_t ) v_I_u16 + ( sint16_t ) v_KCenterY_u16);
    v_YMin_s16 = ((( sint16_t ) v_I_u16 - ( sint16_t ) i_Y_u16) + ( sint16_t ) v_KCenterY_u16);
    for (v_J_u16 = 0U; v_J_u16 < i_X_u16; ++v_J_u16)
    {
      /* current range of the convolution */
      v_XMax_s16 = (( sint16_t ) v_J_u16 + ( sint16_t ) v_KCenterX_u16);
      v_XMin_s16 = ((( sint16_t ) v_J_u16 - ( sint16_t ) i_X_u16) + ( sint16_t ) v_KCenterX_u16);
      v_Temp1_s32 = 0;
      v_Temp2_u32 = 0U;
      v_Temp3_u32 = 0U;
      /*v_temp1_K2 = 0;*/ /*  for second kernel needed */
      /* multiply each kernel value with underlying input data             */
      for (v_M_u16 = 0U; v_M_u16 < i_KY_u16; ++v_M_u16)
      {/* kernel rows */
        /* check if the index is out of bound of input array */
        if (((sint32_t) v_M_u16 <= v_YMax_s16) && ((sint32_t) v_M_u16 > v_YMin_s16))
        {
          for (v_N_u16 = 0U; v_N_u16 < i_KX_u16; ++v_N_u16)
          {
            /* check the boundary of array */
            if (((sint32_t) v_N_u16 <= v_XMax_s16) && ((sint32_t) v_N_u16 > v_XMin_s16))
            {
              v_PixelData_u8 = (*(v_ImgData1_pu8 - v_N_u16));
              if (*v_Kernel1_ps8 > 0)
              {
                v_Temp1_s32 += (sint32_t) v_PixelData_u8;
              }
              else
              {
                v_Temp1_s32 -= (sint32_t) v_PixelData_u8;
              }
              /*if( *v_Kernel1_K2_ps8 > 0 ){
               v_temp1_K2 += (sint32_t)v_pixeldata_u8;
               }else{
               v_temp1_K2 -= (sint32_t)v_pixeldata_u8;
               }
               */
              v_Temp2_u32 += ((uint32_t) v_PixelData_u8 * v_PixelData_u8);
              v_Temp3_u32 += (v_PixelData_u8);
            }
            ++v_Kernel1_ps8; /* next kernel */
            /*++v_Kernel1_K2_ps8;*/ /* next kernel */
          }
        }
        else
        {
          v_Kernel1_ps8 += i_KX_u16; /* out of bound, move to next row of kernel */
          /*v_Kernel1_K2_ps8 += i_KX_u16;*/ /* out of bound, move to next row of kernel */
        }
        v_ImgData1_pu8 -= i_X_u16; /* move input data 1 row up */
      }
      v_Kernel1_ps8 = i_TKernel_ps8; /* reset kernel to (0,0) */
      /* v_Kernel1_K2_ps8 = i_TKernel_K2_ps8; */ /* reset kernel to (0,0) */
      ++v_ImgData2_pu8;
      v_ImgData1_pu8 = v_ImgData2_pu8; /* next input */

      v_Temp2_u32 = (v_Temp2_u32 * v_X2_u16) - (v_Temp3_u32 * v_Temp3_u32);
      if ((v_Temp2_u32 != 0U) && (v_Temp1_s32 != 0))
      {
        /* *v_OData_pf32++ = _IQ16toF(_sshl(v_temp1, 16U) / isqrt2_u32(v_temp2));*/		/* <<Sebi */
        /* *v_OData_pf32++ = (float32_t)((v_temp1<<16U) / isqrt2_u32(v_temp2));	*/ 	/*>>Sebi*/
        /* *v_OData_pf32++ = v_temp1 / _IQ0toF(_IQ0sqrt(v_temp2)); */
        v_Test_f64 = ((float32_t)v_Temp1_s32) / sqrt((float32_t)v_Temp2_u32);
        *v_OData_pf32 = ((float32_t)v_Temp1_s32) / (float32_t) sqrt((float32_t)v_Temp2_u32);
        v_OData_pf32++;


        if (v_Test_f64 < v_Min_f64)
        {
          v_Min_f64 = v_Test_f64;
        }
        if (v_Test_f64 > v_Max_f64)
        {
          v_Max_f64 = v_Test_f64;
        }
      }
      else
      {
        *v_OData_pf32 = 0.0000001F;
        v_OData_pf32++;
      }
    }
    /* v_OData_pf32 += (aAlgoECSrc_D_ImageX_Cut - i_X_u16); */
  }
}

/*  ---------------------------------- EOF -------------------------------------- */
