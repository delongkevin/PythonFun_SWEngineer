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

	$Header: svd.c 1.9 2016/05/31 19:37:53IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/05/31 19:37:53IST $
	$Revision: 1.9 $
	
===================================================================================*/

/*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: svd.c  $
 Revision 1.9 2016/05/31 19:37:53IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 QAC changes.
 Revision 1.7.1.1 2016/04/12 19:36:43CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.7 2016/03/14 08:04:36EDT Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Renamed float constants to upper-case F
 Revision 1.6.1.1 2016/03/11 10:28:39MEZ Schulte, Michael (MEE_MiSch) 
 Renamed float constants to upper-case F
 Revision 1.6 2016/03/04 10:17:22CET Dehm, Timo (MEE_TDEHM) 
 Merge since:
 bugfix in homography estimation by utilization of SVD
 Revision 1.5.1.1 2016/03/01 12:56:28MEZ Berndt, Sven (MEE_SvBer) 
 bugfix in homography estimation by utilization of SVD
 Revision 1.5 2015/08/18 16:43:18CEST Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.4 2015/05/29 13:27:17CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.3 2015/02/04 10:57:55CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.2 2015/02/03 11:54:10CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Algo intergrated. Results are not correct yet. 
 Floating-point calculation results don't match on PC and ECU with same code.
 Revision 1.1 2015/01/21 14:46:54CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.3 2013/07/25 10:50:25EDT Sebastian Pliefke (spliefke) 
 Remove Warnings
 Revision 1.2 2013/07/18 09:21:01MESZ Sebastian Pliefke (spliefke) 
 Modification of including structure and change from double32_t to float32_t
 Revision 1.1 2013/07/09 16:51:44MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/cali/project.pj
 Revision 1.1 2013/04/26 16:21:42MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/05_MicroBlaze/project.pj
 Revision 1.11 2012/06/26 18:39:21MESZ Tina Behal (tbehal) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
 Revision 1.11 2012/03/21 16:13:50EDT Marko Vico (mvico) 
 Misra C changes applied
 Revision 1.10 2011/11/15 16:26:51EST Ali Ahmed (aahmed) 
 EOL now looks at the variant coding to determine the roll related changes inside the processing block of EC.
 Revision 1.9 2011/11/11 11:56:26EST Anupama Bhide (abhide) 
 Bug Fixed
 Revision 1.8 2011/10/14 12:38:52EDT Anupama Bhide (abhide) 
 QAC Misra C modifications
 Revision 1.7 2011/08/12 15:22:51EDT Anupama Bhide (abhide) 
 Misra C fixes
 Revision 1.6 2011/08/05 17:47:14EDT Anupama Bhide (abhide) 
 Misra C modifications-pclint
 Revision 1.5 2011/08/04 17:23:11EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.4 2011/08/04 10:53:02EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:27EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#include "svd.h"
#include <math.h>
#include "flcompare.h"
/* --- Private Typedefinitions, Enumerations, Defines --------------------- */

#define MAX_NUM_COLUMNS 20
#define MAX_MATRIX_SIZE 9u

/* --- Private Variables, Constants --------------------------------------- */

static float64_t f_max_f64( const float64_t i_A_f64, const float64_t i_B_f64 );
static float64_t f_sign_f64( const float64_t i_A_f64, const float64_t i_B_f64 );
static sint16_t f_min_s16( const sint16_t i_A_s16, const sint16_t i_B_s16 );
static float64_t f_square_f64( const float64_t i_A_f64 );
static float64_t pythag_f64( float64_t i_A_f64, float64_t i_B_f64 );


/* --- Private Function Prototypes ---------------------------------------- */

/* --- Public Function Definitions ---------------------------------------- */

/* The original 'float32_t' has been replaced by 'float64_t' */
void svdcmp_v( float64_t *b_A_a2f64[], const uint16_t i_M_u16, const uint8_t i_N_u8, float64_t b_W_af64[], float64_t *b_V_a2f64[] )
{
  /* DD-ID: {256B4DE1-DF91-495e-B616-5C5EDACC37F9}*/
  sint32_t v_Flag_s32;
  sint32_t v_I_s32;
  sint32_t v_Its_s32;
  sint32_t v_J_s32;
  sint32_t v_JJ_s32;
  sint32_t v_K_s32;
  sint32_t v_L_s32 = 0;
  sint32_t v_NM_s32 = 0;
  float64_t v_Anorm_f64;
  float64_t v_C_f64;
  float64_t v_F_f64 = 1.0;
  float64_t v_G_f64;
  float64_t v_H_f64 = 1.0;
  float64_t v_S_f64;
  float64_t v_Scale_f64;
  float64_t v_X_f64;
  float64_t v_Y_f64 = 1.0;
  float64_t v_Z_f64;
  float64_t v_Temp_f64;
  sint16_t v_Temp_s16;
  sint32_t v_Temp_s32;

  float64_t v_RV1_af64[ MAX_NUM_COLUMNS ];

  for( v_I_s32 = 0; v_I_s32 < MAX_NUM_COLUMNS; v_I_s32++ )
  {
    v_RV1_af64[ v_I_s32 ] = 0.0;
  }
  v_G_f64     = 0.0;
  v_Scale_f64 = 0.0;
  v_Anorm_f64 = 0.0;

  for( v_I_s32 = 0; v_I_s32 < (sint32_t)i_N_u8; v_I_s32++ )
  {
    v_L_s32 = v_I_s32 + 1;
    v_RV1_af64[ v_I_s32 ] = v_Scale_f64 * v_G_f64;
    v_G_f64     = 0.0;
    v_S_f64     = 0.0;
    v_Scale_f64 = 0.0;
    if( v_I_s32 < (sint32_t)i_M_u16 )
    {
      for( v_K_s32 = v_I_s32; v_K_s32 < (sint32_t)i_M_u16; v_K_s32++ )
      {
        v_Scale_f64 += (float64_t) fabs( b_A_a2f64[ v_K_s32][ v_I_s32 ] );
        /* vm_cprintf("a[%d][%d]: %d, %d, %d\n", k, i,(sint32_t)(a[k][i]*10000000), (sint32_t)(fabs(a[k][i])*10000000), (sint32_t)(scale*10000000)); */
      }
      if( 0 != cmpNearToZeroF64_s32(v_Scale_f64) )
      {
        for( v_K_s32 = v_I_s32; v_K_s32 < (sint32_t)i_M_u16; v_K_s32++ )
        {
          v_Temp_f64 = b_A_a2f64[ v_K_s32][ v_I_s32 ];
          b_A_a2f64[ v_K_s32][ v_I_s32 ] = v_Temp_f64 / v_Scale_f64;
          v_S_f64 += b_A_a2f64[ v_K_s32][ v_I_s32 ] *b_A_a2f64[ v_K_s32][ v_I_s32 ];
        }
        v_F_f64 = b_A_a2f64[ v_I_s32][ v_I_s32 ];
        v_Temp_f64 = (float64_t) sqrt( v_S_f64 );
        v_G_f64 =  - f_sign_f64( v_Temp_f64, v_F_f64 );
        v_H_f64 = ( v_F_f64 *v_G_f64 ) - v_S_f64;
        b_A_a2f64[ v_I_s32][ v_I_s32 ] = v_F_f64 - v_G_f64;
        for( v_J_s32 = v_L_s32; v_J_s32 < (sint32_t)i_N_u8; v_J_s32++ )
        {
          v_S_f64 = 0.0;
          for( v_K_s32 = v_I_s32; v_K_s32 < (sint32_t)i_M_u16; v_K_s32++ )
          {
            v_S_f64 += b_A_a2f64[ v_K_s32][ v_I_s32 ] * b_A_a2f64[ v_K_s32][ v_J_s32 ];
          }
          v_F_f64 = v_S_f64 / v_H_f64;
          for( v_K_s32 = v_I_s32; v_K_s32 < (sint32_t)i_M_u16; v_K_s32++ )
          {
            v_Temp_f64 = v_F_f64 * b_A_a2f64[ v_K_s32][ v_I_s32 ];
            b_A_a2f64[ v_K_s32][ v_J_s32 ] = v_Temp_f64 + b_A_a2f64[ v_K_s32][ v_J_s32 ];
          }
        }
        for( v_K_s32 = v_I_s32; v_K_s32 < (sint32_t)i_M_u16; v_K_s32++ )
        {
          v_Temp_f64 = b_A_a2f64[ v_K_s32][ v_I_s32 ];
          b_A_a2f64[ v_K_s32][ v_I_s32 ] = v_Temp_f64 *  v_Scale_f64;
        }
      }
    }
    /* vm_cprintf("before: w[%d]: %d, %d, %d, %d, %d\n", i,(sint32_t)(w[ i ]*100000), (sint32_t)(scale*100000), (sint32_t)(g*100000), n, m); */
    b_W_af64[ v_I_s32 ] = v_Scale_f64 * v_G_f64;
    /* vm_cprintf("after: w[%d]: %d, %d, %d\n", i,(sint32_t)(w[ i ]*100000), (sint32_t)(scale*100000), (sint32_t)(g*100000)); */
    v_G_f64     = 0.0; 
    v_S_f64     = 0.0; 
    v_Scale_f64 = 0.0;
    if( ( v_I_s32 < (sint32_t)i_M_u16 ) && ( v_I_s32 != ( (sint32_t)i_N_u8 - 1 ) ) )
    {
      for( v_K_s32 = v_L_s32; v_K_s32 < (sint32_t)i_N_u8; v_K_s32++ )
      {
        v_Scale_f64 += (float64_t) fabs( b_A_a2f64[ v_I_s32][ v_K_s32 ] );
      }
      if( 0 != cmpNearToZeroF64_s32(v_Scale_f64) )
      {
        for( v_K_s32 = v_L_s32; v_K_s32 < (sint32_t)i_N_u8; v_K_s32++ )
        { 
          v_Temp_f64 = b_A_a2f64[ v_I_s32][ v_K_s32 ];
          b_A_a2f64[ v_I_s32][ v_K_s32 ] = v_Temp_f64 / v_Scale_f64;
          v_S_f64 += b_A_a2f64[ v_I_s32][ v_K_s32 ] *b_A_a2f64[ v_I_s32][ v_K_s32 ];
        }
        v_F_f64 = b_A_a2f64[ v_I_s32][ v_L_s32 ];
        v_Temp_f64 = (float64_t) sqrt( v_S_f64 );
        v_G_f64 =  - f_sign_f64( v_Temp_f64, v_F_f64 );
        v_H_f64 = ( v_F_f64 * v_G_f64 ) - v_S_f64;
        b_A_a2f64[ v_I_s32][ v_L_s32 ] = v_F_f64 - v_G_f64;
        for( v_K_s32 = v_L_s32; v_K_s32 < (sint32_t)i_N_u8; v_K_s32++ )
        { 
          v_Temp_f64 = b_A_a2f64[ v_I_s32][ v_K_s32 ];
          v_RV1_af64[ v_K_s32 ] = v_Temp_f64 / v_H_f64;
        }
        for( v_J_s32 = v_L_s32; v_J_s32 < (sint32_t)i_M_u16; v_J_s32++ )
        {
          v_S_f64 = 0.0;
          for( v_K_s32 = v_L_s32; v_K_s32 < (sint32_t)i_N_u8; v_K_s32++ )
          {
            v_S_f64 += b_A_a2f64[ v_J_s32][ v_K_s32 ] *b_A_a2f64[ v_I_s32][ v_K_s32 ];
          }
          for( v_K_s32 = v_L_s32; v_K_s32 < (sint32_t)i_N_u8; v_K_s32++ )
          {
            v_Temp_f64 = b_A_a2f64[ v_J_s32][ v_K_s32 ];
            b_A_a2f64[ v_J_s32][ v_K_s32 ] = v_Temp_f64 + (v_S_f64 * v_RV1_af64[ v_K_s32 ]);
          }
        }
        for( v_K_s32 = v_L_s32; v_K_s32 < (sint32_t)i_N_u8; v_K_s32++ )
        {
          v_Temp_f64 = b_A_a2f64[ v_I_s32][ v_K_s32 ];
          b_A_a2f64[ v_I_s32][ v_K_s32 ] = v_Temp_f64 * v_Scale_f64;
        }
      }
    }
    v_Temp_f64 = (float64_t) fabs( b_W_af64[ v_I_s32 ]);
    v_Temp_f64 = v_Temp_f64 +  (float64_t) fabs( v_RV1_af64[ v_I_s32 ] );
    v_Anorm_f64 = f_max_f64( v_Anorm_f64, v_Temp_f64);
  }
  for( v_I_s32 = (sint32_t)i_N_u8 - 1; v_I_s32 >= 0; v_I_s32-- )
  {
    if( v_I_s32 < (sint32_t)i_N_u8 )
    {
      if( 0 != cmpNearToZeroF64_s32(v_G_f64) )
      {
        for( v_J_s32 = v_L_s32; v_J_s32 < (sint32_t)i_N_u8; v_J_s32++ )
        {
          v_Temp_f64 = ( b_A_a2f64[ v_I_s32][ v_J_s32 ] / b_A_a2f64[ v_I_s32][ v_L_s32 ] );
          b_V_a2f64[ v_J_s32][ v_I_s32 ] = v_Temp_f64 / v_G_f64;
        }
        for( v_J_s32 = v_L_s32; v_J_s32 < (sint32_t)i_N_u8; v_J_s32++ )
        {
          v_S_f64 = 0.0;
          for( v_K_s32 = v_L_s32; v_K_s32 < (sint32_t)i_N_u8; v_K_s32++ )
          {
            v_S_f64 += b_A_a2f64[ v_I_s32][ v_K_s32 ] *b_V_a2f64[ v_K_s32][ v_J_s32 ];
          }
          for( v_K_s32 = v_L_s32; v_K_s32 < (sint32_t)i_N_u8; v_K_s32++ )
          {
            v_Temp_f64 = b_V_a2f64[ v_K_s32][ v_J_s32 ];
            b_V_a2f64[ v_K_s32][ v_J_s32 ] = v_Temp_f64 + (v_S_f64 * b_V_a2f64[ v_K_s32][ v_I_s32 ]);
          }
        }
      }
      for( v_J_s32 = v_L_s32; v_J_s32 < (sint32_t)i_N_u8; v_J_s32++ )
      {
        b_V_a2f64[ v_I_s32][ v_J_s32 ] = 0.0; 
        b_V_a2f64[ v_J_s32][ v_I_s32 ] = 0.0;
      }
    }
    b_V_a2f64[ v_I_s32][ v_I_s32 ] = 1.0;
    v_G_f64 = v_RV1_af64[ v_I_s32 ];
    v_L_s32 = v_I_s32;
  }
  v_Temp_s16 = f_min_s16( (sint16_t)i_M_u16, (sint16_t)i_N_u8 ) - 1;		
  for( v_I_s32 = v_Temp_s16; v_I_s32 >= 0; v_I_s32-- )
  {
    v_L_s32 = v_I_s32 + 1;
    v_G_f64 = b_W_af64[ v_I_s32 ];
    for( v_J_s32 = v_L_s32; v_J_s32 < (sint32_t)i_N_u8; v_J_s32++ )
    {
      b_A_a2f64[ v_I_s32][ v_J_s32 ] = 0.0;
    }
    if( 0 != cmpNearToZeroF64_s32(v_G_f64) )
    {
      v_G_f64 = 1.0 / v_G_f64;
      for( v_J_s32 = v_L_s32; v_J_s32 < (sint32_t)i_N_u8; v_J_s32++ )
      {
        v_S_f64 = 0.0;
        for( v_K_s32 = v_L_s32; v_K_s32 < (sint32_t)i_M_u16; v_K_s32++ )
        {
          v_S_f64 += b_A_a2f64[ v_K_s32][ v_I_s32 ] *b_A_a2f64[ v_K_s32][ v_J_s32 ];
        }
        v_F_f64 = ( v_S_f64 / b_A_a2f64[ v_I_s32][ v_I_s32 ] ) *v_G_f64;
        for( v_K_s32 = v_I_s32; v_K_s32 < (sint32_t)i_M_u16; v_K_s32++ )
        {
          v_Temp_f64 = b_A_a2f64[ v_K_s32][ v_J_s32 ];
          b_A_a2f64[ v_K_s32][ v_J_s32 ] = (v_Temp_f64 + (v_F_f64 * b_A_a2f64[ v_K_s32][ v_I_s32 ]));
        }
      }
      for( v_J_s32 = v_I_s32; v_J_s32 < (sint32_t)i_M_u16; v_J_s32++ )
      {
        v_Temp_f64 = b_A_a2f64[ v_J_s32][ v_I_s32 ];
        b_A_a2f64[ v_J_s32][ v_I_s32 ] = v_Temp_f64 * v_G_f64;
      }
    }
    else {
      for( v_J_s32 = v_I_s32; v_J_s32 < (sint32_t)i_M_u16; v_J_s32++ )
      {
        b_A_a2f64[ v_J_s32][ v_I_s32 ] = 0.0;
      }
    }
    ++b_A_a2f64[ v_I_s32][ v_I_s32 ];
  }
  for( v_K_s32 = (sint32_t)i_N_u8 - 1; v_K_s32 >= 0; v_K_s32-- )
  {
    for( v_Its_s32 = 1; v_Its_s32 <= 30; v_Its_s32++ )
    {
      v_Flag_s32 = 1;
      for( v_L_s32 = v_K_s32; v_L_s32 >= 0; v_L_s32-- )
      {
        bool_t v_Return_b = 0;
        v_NM_s32 = v_L_s32 - 1;
        v_Temp_f64 = (float64_t) fabs( v_RV1_af64[ v_L_s32 ] );
        v_Temp_s32 = fcmpEpsilonF64_s32(0.0, v_Temp_f64);
        if( v_Temp_s32 == 0 )
        {
          v_Flag_s32 = 0;
          v_Return_b = 1;
        }
        if(0 == v_Return_b)
        {
          v_Temp_f64 = (float64_t) fabs( b_W_af64[ v_NM_s32 ] );
          v_Temp_s32 = fcmpEpsilonF64_s32(0.0, v_Temp_f64);

          if( ( v_Temp_s32 == 0 ) || ( v_Flag_s32 == 0 ) )
          {
            v_Return_b = 1;
          }
        }
        if(1 == v_Return_b)
        {
          break;
        }
      }
      if( 0 != v_Flag_s32 )
      {
        v_C_f64 = 0.0;
        v_S_f64 = 1.0;
        for( v_I_s32 = v_L_s32; v_I_s32 <= v_K_s32; v_I_s32++ )
        {
          if( v_I_s32 >= 0 )
          {
            v_F_f64 = v_S_f64 * v_RV1_af64[ v_I_s32 ];
            v_RV1_af64[ v_I_s32 ] = v_C_f64 * v_RV1_af64[ v_I_s32 ];
          }
          v_Temp_f64 = (float64_t) fabs( v_F_f64 );
          v_Temp_s32 = fcmpEpsilonF64_s32(0.0, v_Temp_f64);
          if( v_Temp_s32 == 0 )
          {
            break;
          }
          v_G_f64 = b_W_af64[ v_I_s32 ];
          v_H_f64 = pythag_f64( v_F_f64, v_G_f64 );
          b_W_af64[ v_I_s32 ] = v_H_f64;
          v_H_f64 = 1.0 / v_H_f64;
          v_C_f64 = v_G_f64 * v_H_f64;
          v_S_f64 =  - v_F_f64 * v_H_f64;
          for( v_J_s32 = 0; v_J_s32 < (sint32_t)i_M_u16; v_J_s32++ )
          {
            v_Y_f64 = b_A_a2f64[ v_J_s32][ v_NM_s32 ];
            v_Z_f64 = b_A_a2f64[ v_J_s32][ v_I_s32 ];
            b_A_a2f64[ v_J_s32][ v_NM_s32 ] = ( v_Y_f64 *v_C_f64 ) + ( v_Z_f64 *v_S_f64 );
            b_A_a2f64[ v_J_s32][ v_I_s32 ] = ( v_Z_f64 *v_C_f64 ) - ( v_Y_f64 *v_S_f64 );
          }
        }
      }
      v_Z_f64 = b_W_af64[ v_K_s32 ];
      if( v_L_s32 == v_K_s32 )
      {
        if( v_Z_f64 < 0.0 )
        {
          b_W_af64[ v_K_s32 ] =  - v_Z_f64;
          for( v_J_s32 = 0; v_J_s32 < (sint32_t)i_N_u8; v_J_s32++ )
          {
            b_V_a2f64[ v_J_s32][ v_K_s32 ] = b_V_a2f64[ v_J_s32][ v_K_s32 ];
          }
        }
        break;
      }

      v_X_f64 = b_W_af64[ v_L_s32 ];
      v_NM_s32 = v_K_s32 - 1;
      if( v_NM_s32 >= 0 )
      {
        v_Y_f64 = b_W_af64[ v_NM_s32 ];
        v_G_f64 = v_RV1_af64[ v_NM_s32 ];
      }
      if( v_K_s32 >= 0 )
      {
        v_H_f64 = v_RV1_af64[ v_K_s32 ];
      }
      v_F_f64 = ( ( ( v_Y_f64 - v_Z_f64 )*( v_Y_f64 + v_Z_f64 ) ) + ( ( v_G_f64 - v_H_f64 )*( v_G_f64 + v_H_f64 ) ) ) / ( 2.0 *( v_H_f64 *v_Y_f64 ) );
      v_G_f64 = pythag_f64( v_F_f64, 1.0 );
      v_F_f64 = ( ( ( v_X_f64 - v_Z_f64 )*( v_X_f64 + v_Z_f64 ) ) + ( v_H_f64 *( ( v_Y_f64 / ( v_F_f64 + f_sign_f64( v_G_f64, v_F_f64 ) ) ) - v_H_f64 ) ) ) / v_X_f64;
      v_C_f64 = 1.0;
      v_S_f64 = 1.0;
      for( v_J_s32 = v_L_s32; v_J_s32 <= v_NM_s32; v_J_s32++ )
      {
        v_I_s32 = v_J_s32 + 1;
        v_G_f64 = v_RV1_af64[ v_I_s32 ];
        v_Y_f64 = b_W_af64[ v_I_s32 ];
        v_H_f64 = v_S_f64 * v_G_f64;
        v_G_f64 = v_C_f64 * v_G_f64;
        v_Z_f64 = pythag_f64( v_F_f64, v_H_f64 );
        if( v_J_s32 >= 0 )
        {
          v_RV1_af64[ v_J_s32 ] = v_Z_f64;
        }
        v_C_f64 = v_F_f64 / v_Z_f64;
        v_S_f64 = v_H_f64 / v_Z_f64;
        v_F_f64 = ( v_X_f64 *v_C_f64 ) + ( v_G_f64 *v_S_f64 );
        v_G_f64 = ( v_G_f64 *v_C_f64 ) - ( v_X_f64 *v_S_f64 );
        v_H_f64 = v_Y_f64 * v_S_f64;
        v_Y_f64 *= v_C_f64;
        for( v_JJ_s32 = 0; v_JJ_s32 < (sint32_t)i_N_u8; v_JJ_s32++ )
        {
          v_X_f64 = b_V_a2f64[ v_JJ_s32][ v_J_s32 ];
          v_Z_f64 = b_V_a2f64[ v_JJ_s32][ v_I_s32 ];
          b_V_a2f64[ v_JJ_s32][ v_J_s32 ] = ( v_X_f64 *v_C_f64 ) + ( v_Z_f64 *v_S_f64 );
          b_V_a2f64[ v_JJ_s32][ v_I_s32 ] = ( v_Z_f64 *v_C_f64 ) - ( v_X_f64 *v_S_f64 );
        }
        v_Z_f64 = pythag_f64( v_F_f64, v_H_f64 );
        b_W_af64[ v_J_s32 ] = v_Z_f64;
        if( 0 != cmpNearToZeroF64_s32(v_Z_f64) )
        {
          v_Z_f64 = 1.0 / v_Z_f64;
          v_C_f64 = v_F_f64 * v_Z_f64;
          v_S_f64 = v_H_f64 * v_Z_f64;
        }
        v_F_f64 = ( v_C_f64 *v_G_f64 ) + ( v_S_f64 *v_Y_f64 );
        v_X_f64 = ( v_C_f64 *v_Y_f64 ) - ( v_S_f64 *v_G_f64 );
        for( v_JJ_s32 = 0; v_JJ_s32 < (sint32_t)i_M_u16; v_JJ_s32++ )
        {
          v_Y_f64 = b_A_a2f64[ v_JJ_s32][ v_J_s32 ];
          v_Z_f64 = b_A_a2f64[ v_JJ_s32][ v_I_s32 ];
          b_A_a2f64[ v_JJ_s32][ v_J_s32 ] = ( v_Y_f64 *v_C_f64 ) + ( v_Z_f64 *v_S_f64 );
          b_A_a2f64[ v_JJ_s32][ v_I_s32 ] = ( v_Z_f64 *v_C_f64 ) - ( v_Y_f64 *v_S_f64 );
        }
      }
      if( v_L_s32 >= 0 )
      {
        v_RV1_af64[ v_L_s32 ] = 0.0;
      }
      if( v_K_s32 >= 0 )
      {
        v_RV1_af64[ v_K_s32 ] = v_F_f64;
        b_W_af64[ v_K_s32 ] = v_X_f64;
      }
    }
  }
}

/* #undef NRANSI */
/* (C) Copr. 1986-92 Numerical Recipes Software v%1jw#<0(9p#3,5_5.){. */

static float64_t pythag_f64( float64_t i_A_f64, float64_t i_B_f64 )
{
  /* DD-ID: {BF3487A4-523F-4c0e-A884-8E2D95B48F9B}*/
  float64_t v_AbsA_f64;
  float64_t v_AbsB_f64;
  float64_t v_Res_f64;
  float64_t v_Temp_f64;

  v_AbsA_f64 = (float64_t) fabs( i_A_f64 );
  v_AbsB_f64 = (float64_t) fabs( i_B_f64 );
  if( v_AbsA_f64 > v_AbsB_f64 )
  {
    v_Temp_f64 = f_square_f64( v_AbsB_f64 / v_AbsA_f64 );
    v_Res_f64 = v_AbsA_f64 * (float64_t) sqrt( 1.0 + v_Temp_f64 );
  }
#if 1

  else
    if( v_AbsB_f64 > v_AbsA_f64 )
    {
      v_Temp_f64 = f_square_f64( v_AbsA_f64 / v_AbsB_f64 );
      v_Res_f64 = v_AbsB_f64 * (float64_t) sqrt( 1.0 + v_Temp_f64 );
    }
    else
    {
      /*
       * this variant has an other behavior with values close to zero
       */
      v_Res_f64 = v_AbsA_f64 * (float64_t) sqrt( 2.0 );
    }
#else
  else
  {
    v_Temp_f64 = f_square_f64( v_AbsA_f64 / v_AbsB_f64 );
    v_temp_s32 = fcmpEpsilonF64_s32(0.0, v_AbsB_f64);
    v_Res_f64 = ( ( v_temp_s32 == 0 ) ? 0.0 : ( v_AbsB_f64 *(float64_t) sqrt( 1.0 + v_Temp_f64 ) ) );
  }
#endif
  return v_Res_f64;
}

/* ------------------------------------------------------------------------- */

/* #undef NRANSI */
/* (C) Copr. 1986-92 Numerical Recipes Software v%1jw#<0(9p#3,5_5.){. */

void svdreorder_v( float64_t *b_U_a2f64[], const uint16_t i_M_u16, const uint8_t i_N_u8, float64_t b_W_af64[], float64_t *b_V_a2f64[] )
{
  /* DD-ID: {DD208F1A-7B1E-459b-9010-7315D3B486AB}*/
  /* 2016-03-01
   * The SVD produce not in any case positive singular values.
   * This reimplementation is a bubble sort variant. It reorders the values
   * and considers the absolute values.
   */
  uint8_t v_I_u8;
  uint8_t v_J_u8;
  uint16_t v_Row_u16;

  for( v_I_u8 = 0u; v_I_u8 < (i_N_u8-1); v_I_u8++ )
  {
    for( v_J_u8 = v_I_u8+1u; v_J_u8 < i_N_u8; v_J_u8++ )
    {
      if( fabs(b_W_af64[v_I_u8]) < fabs(b_W_af64[v_J_u8]) )
      {
        float64_t v_Temp_f64 = b_W_af64[v_I_u8];
        b_W_af64[v_I_u8] = b_W_af64[v_J_u8];
        b_W_af64[v_J_u8] = v_Temp_f64;

        for( v_Row_u16 = 0u; v_Row_u16 < i_M_u16; v_Row_u16++ )
        {
          v_Temp_f64 = b_U_a2f64[ v_Row_u16][ v_I_u8 ];
          b_U_a2f64[ v_Row_u16][ v_I_u8 ] = b_U_a2f64[ v_Row_u16][ v_J_u8 ];
          b_U_a2f64[ v_Row_u16][ v_J_u8 ] = v_Temp_f64;
        }
        for( v_Row_u16 = 0u; v_Row_u16 < i_N_u8; v_Row_u16++ )
        {
          v_Temp_f64 = b_V_a2f64[ v_Row_u16][ v_I_u8 ];
          b_V_a2f64[ v_Row_u16][ v_I_u8 ] = b_V_a2f64[ v_Row_u16][ v_J_u8 ];
          b_V_a2f64[ v_Row_u16][ v_J_u8 ] = v_Temp_f64;
        }

      }
    }
  }

}

/* ------------------------------------------------------------------------- */

static float64_t f_max_f64( const float64_t i_A_f64, const float64_t i_B_f64 )
{
  /* DD-ID: {1FF7680E-FEA5-4c6c-BE47-A14FA6794015}*/
  float64_t v_Max_f64;
  if( i_A_f64 > i_B_f64 )
  {
    v_Max_f64 = i_A_f64;
  }
  else
  {
    v_Max_f64 = i_B_f64;
  }
  return v_Max_f64;
}


static float64_t f_sign_f64( const float64_t i_A_f64, const float64_t i_B_f64 )
{
  /* DD-ID: {BC5298A4-B95C-4015-B3FA-F3F9CC863849}*/
  float64_t v_Max_f64;
  if( i_B_f64 >= 0.0 )
  {
    v_Max_f64 = (float64_t) fabs( i_A_f64 );
  }
  else
  {
    v_Max_f64 =  - (float64_t) fabs( i_A_f64 );
  }
  return v_Max_f64;
}

/*#define IMIN(a,b) (iminarg1=(a),iminarg2=(b),(iminarg1) < (iminarg2) ?\
(iminarg1) : (iminarg2))*/
static sint16_t f_min_s16( const sint16_t i_A_s16, const sint16_t i_B_s16 )
{
  /* DD-ID: {CF03E727-F640-47da-9290-B8CD8AEDF6F2}*/
  sint16_t v_Min_s16;
  if( i_A_s16 < i_B_s16 )
  {
    v_Min_s16 = i_A_s16;
  }
  else
  {
    v_Min_s16 = i_B_s16;
  }
  return v_Min_s16;
}

/* ------------------------------------------------------------------------- */

static float64_t f_square_f64( const float64_t i_A_f64 )
{
  /* DD-ID: {25E56573-6616-45ae-906B-977BD8B8FA30}*/
  return ( i_A_f64 *i_A_f64 );
}
/*  ---------------------------------- EOF -------------------------------------- */
