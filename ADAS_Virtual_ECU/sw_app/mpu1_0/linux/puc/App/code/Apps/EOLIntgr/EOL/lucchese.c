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

	$Header: lucchese.c 1.8 2016/06/01 21:07:47IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:47IST $
	$Revision: 1.8 $

===================================================================================*/

/*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: lucchese.c  $
 Revision 1.8 2016/06/01 21:07:47IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.7 2016/05/31 16:06:31CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.5.1.1 2016/04/12 19:35:12CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.5 2016/03/14 08:04:56EDT Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Renamed float constants to upper-case F
 Revision 1.4.1.1 2016/03/11 10:27:04MEZ Schulte, Michael (MEE_MiSch) 
 Renamed float constants to upper-case F
 Revision 1.4 2015/08/18 16:43:19CEST Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.3 2015/05/29 13:27:15CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:52CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:53CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.2 2013/07/25 11:09:39EDT Sebastian Pliefke (spliefke) 
 Remove warnings
 Revision 1.1 2013/07/09 16:52:11MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/corner/project.pj
 Revision 1.13 2012/06/26 18:38:24MESZ Tina Behal (tbehal) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
 Revision 1.13 2011/10/14 12:33:03EDT Anupama Bhide (abhide) 
 QAC Misra C modifications
 Revision 1.12 2011/08/12 15:22:12EDT Anupama Bhide (abhide) 
 Bug Fix from Algorithm ( released code ) 
 Misra C fixes
 Revision 1.11 2011/08/10 18:02:11EDT Ali Ahmed (aahmed) 
 Taking MISRA-C changes.
 Added optimization related changes.
 Revision 1.10 2011/08/08 14:43:23EDT Marko Vico (mvico) 
 Misra C modifications
 Revision 1.9 2011/08/08 13:03:50EDT Anupama Bhide (abhide) 
 Misra C modifications - pclint
 Revision 1.8 2011/08/04 17:23:15EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.7 2011/08/04 10:53:03EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:27EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#include "lucchese.h"
#include <math.h>

/* --- Private Typedefinitions, Enumerations, Defines ------------------------ */
/* PRQA S 4800 EOF */
/* PRQA S 7006 EOF */

/* #pragma CHECK_MISRA("required") */
#define BLOCK_RADIUS_U32 5U
#define RADIUS_2xS_U32 121U
#define DIM_U32 6U
#define SUBPIXEL_LEN_F32 0.5F

static const float32_t V_E_a2f32[ DIM_U32][ 11 *11 ]={    /*PRQA S 3218 */
#include "E1.dat" /*PRQA S 5087 */
};

/* --- Private Variables, ants ------------------------------------------ */

/* --- Private Macros -------------------------------------------------------- */

/* --- Private Function Prototypes ------------------------------------------- */
static void f_getBlockMatrix_v( const uint8_t i_Img_pu8[], uint16_t i_ImgX_u16, uint16_t i_CanX_u16,  /* input selected area position X */
                                uint16_t i_CanY_u16,  /* input selected area position Y */
                                uint8_t i_BlockRad_u8,  /* input selected area radius */
                                float32_t o_Block_a2f32[][ ( BLOCK_RADIUS_U32 *2 ) + 1 ] /* output selected area data into a Matrix */
);
static void f_lucchese1Pix_v( float32_t i_Block_a2f32[][ ( BLOCK_RADIUS_U32 *2 ) + 1 ],  /* input image */
                              io_S_PosSub_t *b_Pos_ps );
static void f_getCoefficients_v(float32_t i_Block_a2f32[][ 11 ], float32_t o_Coef_a2f32[][ 1 ] );
static void f_getOffset2_v( float32_t i_Coef_a2f32[][ 1 ], float32_t *o_X_pf32, float32_t *o_Y_pf32 );

static void f_mult6x11x1_v( const float32_t i_A_a2f32[][ RADIUS_2xS_U32 ], float32_t i_B_a2f32[][ 1 ], float32_t i_C_a2f32[][ 1 ] );

/* --- Public Function Definitions ---------------------------------------- */

void aSaddle_F_luccheseAll_v( const uint8_t *i_Img_pu8, uint16_t i_ImgX_u16, io_S_PosSub_t *b_CanPosSub_ps,
                              uint32_t i_Number_u32 )
{
  /* DD-ID: {8A0C7D05-7D2A-4eff-A91E-E2CCC46CD2A1}*/
  uint32_t v_I_u32;
  uint16_t v_CanX_u16, v_CanY_u16;
  float32_t v_Block_a2f32[ ( BLOCK_RADIUS_U32 *2 ) + 1][ ( BLOCK_RADIUS_U32 *2 ) + 1 ];
  io_S_PosSub_t *v_CanPosSub_ps = b_CanPosSub_ps;
  io_S_PosSub_t v_Subpixel_s;
  float32_t v_Temp_f32;

  for( v_I_u32 = 0u; v_I_u32 < i_Number_u32; v_I_u32++ )
  {
    v_Subpixel_s  = *v_CanPosSub_ps;
    v_Temp_f32 = v_CanPosSub_ps->x_f32;
    v_CanX_u16 = f_aRound_u16( v_Temp_f32 );
    v_CanY_u16 = f_aRound_u16( v_CanPosSub_ps->y_f32 );

    f_getBlockMatrix_v( i_Img_pu8, i_ImgX_u16, v_CanX_u16, v_CanY_u16, (uint8_t)BLOCK_RADIUS_U32, v_Block_a2f32 );

    f_lucchese1Pix_v( v_Block_a2f32,  /* input image */
                      &v_Subpixel_s );
    v_Temp_f32 = v_Subpixel_s.x_f32 - v_CanPosSub_ps->x_f32;                      
    v_Temp_f32 = (float32_t)fabs((float64_t)v_Temp_f32);
    if ( v_Temp_f32 < SUBPIXEL_LEN_F32 )
    {
      v_Temp_f32 = v_Subpixel_s.y_f32 - v_CanPosSub_ps->y_f32;
      v_Temp_f32 = (float32_t)fabs((float64_t)v_Temp_f32);
      if ( v_Temp_f32 < SUBPIXEL_LEN_F32 )
      {
        *v_CanPosSub_ps = v_Subpixel_s;
      }
      v_CanPosSub_ps++;  /* PRQA S 489 */  /* Pointer Arithmetic */
    }
  }
}

/* --- Private Function Definitions ------------------------------------------ */

static void f_getBlockMatrix_v( const uint8_t i_Img_pu8[], uint16_t i_ImgX_u16, uint16_t i_CanX_u16,  /* input selected area position X */
                                uint16_t i_CanY_u16,  /* input selected area position Y */
                                uint8_t i_BlockRad_u8,  /* input selected area radius */
                                float32_t o_Block_a2f32[][ ( BLOCK_RADIUS_U32 *2 ) + 1 ] /* output selected area data into a Matrix */
)
{
  /* DD-ID: {9C478017-7634-4040-9D64-2EF7C7D0876A}*/
  sint8_t v_I_s8;
  sint8_t v_J_s8;
  uint32_t v_K_u32;
  uint8_t v_temp_u8;
  sint32_t v_temp_s32, v_temp1_s32;

  for( v_I_s8 =  - ( ( sint8_t )i_BlockRad_u8 ); v_I_s8 <= ( ( sint8_t )i_BlockRad_u8 ); v_I_s8++ )
  {
    for( v_J_s8 =  - ( sint8_t )i_BlockRad_u8; v_J_s8 <= ( sint8_t )i_BlockRad_u8; v_J_s8++ )
    {
      if( ((sint16_t)i_CanY_u16+v_I_s8)<0)
      {
        ;
      }
      else
      {
        v_temp_s32 = (sint32_t)i_CanY_u16;
        v_temp_s32 += v_I_s8;
        v_K_u32 = ( ( (uint32_t)v_temp_s32 )* (uint32_t)i_ImgX_u16 );
        v_temp_s32 = (sint32_t)i_CanX_u16;
        v_temp_s32 += v_J_s8;
        v_K_u32 += (uint32_t)v_temp_s32;
        v_temp_u8 = i_Img_pu8[ v_K_u32 ];
        v_temp_s32 = v_I_s8 + (sint32_t)i_BlockRad_u8;
        v_temp1_s32 = v_J_s8 + (sint32_t)i_BlockRad_u8; 
        o_Block_a2f32[ (uint32_t)v_temp_s32][ (uint32_t)v_temp1_s32 ] = (float32_t) v_temp_u8;

      }
    }
  }
}

/*PRQA S 3673 1*/ /*const pointer wouldn't compile*/
static void f_getCoefficients_v( float32_t i_Block_a2f32[][ 11 ], float32_t o_Coef_a2f32[][ 1 ] ){
  /* DD-ID: {5C25B5F3-44AD-417d-B989-365EE69FD554}*/
  /*PRQA S 310 1*/ /*related to E1.dat*/
  f_mult6x11x1_v( V_E_a2f32, (float32_t (*)[1])&i_Block_a2f32[0][0], o_Coef_a2f32 );
}
/*PRQA S 3673 1*/ /*const pointer wouldn't compile*/
static void f_getOffset2_v( float32_t i_Coef_a2f32[][ 1 ], float32_t *o_X_pf32, float32_t *o_Y_pf32 )
{
  /* DD-ID: {B3779C6C-0A85-4840-8F93-5C856B5E0838}*/

  float32_t v_Temp1_a2f32[ 2][ 2 ];
  float32_t v_Temp_f32;
  float32_t v_Det_f32 = ( float32_t ) ( ( float32_t ) ( ( 2.0F *i_Coef_a2f32[ 0][ 0 ] )*
      ( 2.0F *i_Coef_a2f32[ 2][ 0 ] ) ) -
      ( i_Coef_a2f32[ 1][ 0 ] * i_Coef_a2f32[ 1][ 0 ] ) );
  v_Temp1_a2f32[ 0][ 0 ] = ( float32_t ) ( 2.0 *i_Coef_a2f32[ 2][ 0 ] ) / v_Det_f32;
  v_Temp_f32         =  - i_Coef_a2f32[ 1][ 0 ];
  v_Temp1_a2f32[ 0][ 1 ] =  v_Temp_f32 / v_Det_f32;
  v_Temp_f32         = - i_Coef_a2f32[ 1][ 0 ];
  v_Temp1_a2f32[ 1][ 0 ] =  v_Temp_f32 / v_Det_f32;

  v_Temp1_a2f32[ 1][ 1 ] = ( float32_t ) ( 2.0 *i_Coef_a2f32[ 0][ 0 ] ) / v_Det_f32;

  *o_X_pf32 = ( v_Temp1_a2f32[ 0][ 0 ] *i_Coef_a2f32[ 3][ 0 ] ) + ( v_Temp1_a2f32[ 0][ 1 ] *i_Coef_a2f32[ 4][ 0 ] );

  *o_Y_pf32 = ( v_Temp1_a2f32[ 1][ 0 ] *i_Coef_a2f32[ 3][ 0 ] ) + ( v_Temp1_a2f32[ 1][ 1 ] *i_Coef_a2f32[ 4][ 0 ] );

}

/* ------------------------------------------------------------------------- */



static void f_lucchese1Pix_v( float32_t i_Block_a2f32[][ ( BLOCK_RADIUS_U32 *2 ) + 1 ],  /* input image */
                              io_S_PosSub_t *b_Pos_ps )
{
  /* DD-ID: {D8C850BD-DD03-490e-9613-F43CCCF345CA}*/
  io_S_PosSub_t *v_Pos_ps = b_Pos_ps;
  float32_t v_Ox_f32 = 0.0F;
  float32_t v_Oy_f32 = 0.0F;
  uint16_t v_I_u16;

  /* block */
  float32_t v_Coef_a2f32[ DIM_U32][ 1 ];

  for( v_I_u16 = 0u; v_I_u16 < DIM_U32; v_I_u16++)
  {
    v_Coef_a2f32[ v_I_u16 ][ 0 ] = 0.0F;
  }


  f_getCoefficients_v( i_Block_a2f32, v_Coef_a2f32 );

  f_getOffset2_v( v_Coef_a2f32, &v_Ox_f32, &v_Oy_f32 );

  v_Pos_ps->x_f32 = (float32_t)f_aRound_u16( v_Pos_ps->x_f32 ) - v_Ox_f32;
  v_Pos_ps->y_f32 = (float32_t)f_aRound_u16( v_Pos_ps->y_f32 ) - v_Oy_f32;
}

/*PRQA S 3673 1*/ /*const pointer wouldn't compile*/
static void f_mult6x11x1_v(  const float32_t i_A_a2f32[][ RADIUS_2xS_U32 ], float32_t i_B_a2f32[][ 1 ], float32_t i_C_a2f32[][ 1 ] )
{
  /* DD-ID: {7774F79A-39B2-43b0-9F92-DB6010E7F07F}*/
  uint16_t v_I_u16;
  uint16_t v_J_u16;
  uint16_t v_K_u16;

  for( v_I_u16 = 0u; v_I_u16 < DIM_U32; v_I_u16++ )
  {
    for( v_J_u16 = 0u; v_J_u16 < 1u; v_J_u16++ )
    {
      i_C_a2f32[ v_I_u16][ v_J_u16 ] = 0.0F;
      for( v_K_u16 = 0u; v_K_u16 < RADIUS_2xS_U32; v_K_u16++ )
      {
        i_C_a2f32[ v_I_u16][ v_J_u16 ] += i_A_a2f32[ v_I_u16][ v_K_u16 ] *i_B_a2f32[ v_K_u16][ v_J_u16 ];
      }
    }
  }
}

uint16_t f_aRound_u16( float32_t i_Number_f32 ) /* input float32_t number */
{
  /* DD-ID: {D28B39F7-6433-4b96-BD78-0B2BFB2751D5}*/
  uint16_t v_Number_u16;

  float32_t v_NumberSub_f32 = i_Number_f32 - ( float32_t )floor( (float64_t)i_Number_f32 );
  v_Number_u16 = ( uint16_t )floor( (float64_t)i_Number_f32 );

  if( ( i_Number_f32 > 0.0F ) && ( v_NumberSub_f32 >= 0.5F ) )
  {
    v_Number_u16 = ( uint16_t )floor( (float64_t)i_Number_f32 ) + 1u;
  }
  else if( ( i_Number_f32 < 0.0F ) && ( v_NumberSub_f32 > 0.5F ) )
  {
    v_Number_u16 = ( uint16_t )floor( (float64_t)i_Number_f32 ) + 1u;
  }
  else
  {
    /* Do nothing */  
  }

  return v_Number_u16;
}
/*  ---------------------------------- EOF -------------------------------------- */
