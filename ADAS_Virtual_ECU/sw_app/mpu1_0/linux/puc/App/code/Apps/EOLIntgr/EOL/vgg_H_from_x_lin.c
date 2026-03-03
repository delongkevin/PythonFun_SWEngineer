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

	$Header: vgg_H_from_x_lin.c 1.10 2016/06/01 21:07:43IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:43IST $
	$Revision: 1.10 $

===================================================================================*/

/*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: vgg_H_from_x_lin.c  $
 Revision 1.10 2016/06/01 21:07:43IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.9 2016/05/31 16:10:52CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.7.1.1 2016/04/12 19:40:03CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.7 2016/03/14 08:05:21EDT Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Renamed float constants to upper-case F
 Revision 1.6.1.1 2016/03/11 10:27:35MEZ Schulte, Michael (MEE_MiSch) 
 Renamed float constants to upper-case F
 Revision 1.6 2016/02/19 00:37:50CET Rasool, Muzammil (MEE_MRASOO) 
 printf update
 Revision 1.5 2015/08/18 10:43:15EDT Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.4 2015/05/29 13:27:18CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.3 2015/02/04 10:57:56CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.2 2015/02/03 11:54:13CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Algo intergrated. Results are not correct yet. 
 Floating-point calculation results don't match on PC and ECU with same code.
 Revision 1.1 2015/01/21 14:46:55CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.2 2013/07/18 03:21:05EDT Sebastian Pliefke (spliefke) 
 Modification of including structure and change from double32_t to float32_t
 Revision 1.1 2013/07/09 16:51:48MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/cali/project.pj
 Revision 1.1 2013/04/26 16:21:46MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/05_MicroBlaze/project.pj
 Revision 1.8 2011/10/14 18:39:19MESZ Anupama Bhide (abhide) 
 QAC Misra C modifications
 Revision 1.7 2011/08/05 16:37:01EDT Anupama Bhide (abhide) 
 Misra C modifications - pclint
 Revision 1.6 2011/08/04 17:23:09EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.5 2011/08/04 10:53:06EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:27EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#include "svd.h"
#include "vgg.h"
/*#include "vm.h"*/

/* Pointer Arithmetic Rules*/
/* PRQA S 488 EOF */
/* PRQA S 489 EOF */

/* --- Private Typedefinitions, Enumerations, Defines --------------------- */

/* --- Private Variables, Constants --------------------------------------- */
static float64_t aAlgo_f_CalcDetMat3x3_f64(  float64_t i_M_a2f64[][ 3 ] );
static void aAlgo_f_CalcInvMat3x3_v( float64_t b_M_a2f64[][ 3 ] );
static void aAlgo_f_CalcMulMat3x3_3x3_v(  float64_t i_A_a2f64[][ 3 ],  float64_t i_B_a2f64[][ 3 ], float64_t o_C_a2f64[][ 3 ] );

/* --- Private Function Prototypes ---------------------------------------- */

/* --- Public Function Definitions ---------------------------------------- */

/* --- Private Function Definitions --------------------------------------- */

sint8_t vggHFromXLin_s8( float64_t b_Xs1X_af64[], float64_t b_Xs1Y_af64[], float64_t b_Xs2X_af64[],
                         float64_t b_Xs2Y_af64[], float64_t o_H1_af64[], uint8_t i_M_u8 )
{
  /* DD-ID: {8D9B93D9-7B38-40cd-A5B0-5A2EA235165C}*/
  uint16_t v_I_u16;
  uint8_t v_K_u8;
  uint8_t v_J_u8;
  sint8_t v_ErrCode_s8 = 0;

  float64_t v_D_a2f64[ 2U *MAX_NUM_TARGET_POINTS][ 9U ];
  float64_t *v_D_apf64[ 2U *MAX_NUM_TARGET_POINTS ];
  float64_t *v_D1_pf64;
  float64_t *v_D2_pf64;
  float64_t *v_D3_pf64;
  float64_t *v_D4_pf64;
  float64_t *v_D5_pf64;
  float64_t *v_D6_pf64;

  float64_t v_Xs1_af64[ 3 ] = { 0.0, 0.0, 1.0 };
  float64_t v_Xs2_af64[ 3 ] = { 0.0, 0.0, 1.0 };

  float64_t v_V_a2f64[ 9][ 9 ];
  float64_t *v_V_apf64[ 9 ];
  float64_t v_W_af64[ 9 ] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  float64_t v_H_a2f64[ 3][ 3 ];
  float64_t v_TempH_a2f64[ 3][ 3 ] = { {0.0, 0.0, 0.0},
                                       {0.0, 0.0, 0.0},
                                       {0.0, 0.0, 0.0}};

  float64_t v_C1_af64[ 9 ] =
  {
   0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0
  };
  float64_t *v_C1_pf64 = v_C1_af64;
  float64_t v_C1M_a2f64[ 3][ 3 ];

  float64_t v_C2_af64[ 9 ] =
  {
   0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0
  };
  float64_t *v_C2_pf64 = v_C2_af64;
  float64_t v_C2Inv_a2f64[ 3][ 3 ];
  float64_t v_Temp_f64;
  sint32_t v_Temp_s32;

  /* vm_cprintf("vgg_H_from_x_lin 1\n"); */

  for( v_I_u16 = 0U; v_I_u16 < ( MAX_NUM_TARGET_POINTS *2U ); v_I_u16++ )
  {
    v_D_apf64[ v_I_u16 ] = v_D_a2f64[ v_I_u16 ];
    for( v_J_u8 = 0U; v_J_u8 < 9U; v_J_u8++ )
    {
      v_D_apf64[ v_I_u16][ v_J_u8 ] = 0.0;
    }
  }

  /* vm_cprintf("vgg_H_from_x_lin 2\n"); */
  for( v_I_u16 = 0U; v_I_u16 < 9U; v_I_u16++ )
  {
    for( v_J_u8 = 0U; v_J_u8 < 9U; v_J_u8++ )
    {
      v_V_a2f64[ v_I_u16][ v_J_u8 ] = 0.0;
    }
    v_V_apf64[ v_I_u16 ] = v_V_a2f64[ v_I_u16 ];
    /* vm_cprintf("*v_p[%d]: %d, %p, %p, %p, %d\n",i,(sint32_t)(*v_p[i]*10000), v_p[i], v_p[i]+1,v_p[i]+8,(sint32_t)(v_p[i][8]*10000)); */
    /* vm_cprintf("v[%d][8]: %d\n",i,(sint32_t)((v[i][8])*10000)); */
  }

  for(v_K_u8=0; v_K_u8<9; v_K_u8++)
  {
    /* vm_cprintf("C1_p[%d]: %d\n",k,(sint32_t)(C1_p[k]*10000)); */
    /* vm_cprintf("C2_p[%d]: %d\n",k,(sint32_t)(C2_p[k]*10000)); */
  }
  for(v_K_u8=0; v_K_u8<i_M_u8; v_K_u8++)
  {
    /* vm_cprintf("xs1_x_p[%d]: %d,xs1_y_p: %d\n",k,(sint32_t)(xs1_x_p[k]*10000),(sint32_t)(xs1_y_p[k]*10000)); */
    /* vm_cprintf("xs2_x_p[%d]: %d,xs2_y_p: %d\n",k,(sint32_t)(xs2_x_p[k]*10000),(sint32_t)(xs2_y_p[k]*10000)); */
  }
  vggConditionerFromPts_v( b_Xs1X_af64, b_Xs1Y_af64, v_C1_pf64, (uint32_t)i_M_u8 );
  vggConditionerFromPts_v( b_Xs2X_af64, b_Xs2Y_af64, v_C2_pf64, (uint32_t)i_M_u8 );
  vggCondition2d_v( b_Xs1X_af64, b_Xs1Y_af64, v_C1_pf64, i_M_u8 );
  vggCondition2d_v( b_Xs2X_af64, b_Xs2Y_af64, v_C2_pf64, i_M_u8 );

  for(v_K_u8=0; v_K_u8<9; v_K_u8++)
  {
    /* vm_cprintf("C1_p[%d]: %d\n",k,(sint32_t)(C1_p[k]*10000)); */
    /* vm_cprintf("C2_p[%d]: %d\n",k,(sint32_t)(C2_p[k]*10000)); */
  }
  for(v_K_u8=0; v_K_u8<i_M_u8; v_K_u8++)
  {
    /* vm_cprintf("xs1_x_p[%d]: %d,xs1_y_p: %d\n",k,(sint32_t)(xs1_x_p[k]*10000),(sint32_t)(xs1_y_p[k]*10000)); */
    /* vm_cprintf("xs2_x_p[%d]: %d,xs2_y_p: %d\n",k,(sint32_t)(xs2_x_p[k]*10000),(sint32_t)(xs2_y_p[k]*10000)); */
  }
  for( v_K_u8 = 0U; v_K_u8 < i_M_u8; v_K_u8++ )
  {
    v_D1_pf64 = v_D_apf64[ v_K_u8 *2U ];
    v_D2_pf64 = v_D_apf64[ v_K_u8 *2U ] + 3;
    v_D3_pf64 = v_D_apf64[ v_K_u8 *2U ] + 6;
    v_D4_pf64 = v_D_apf64[ ( v_K_u8 *2U ) + 1U ];
    v_D5_pf64 = v_D_apf64[ ( v_K_u8 *2U ) + 1U ] + 3;
    v_D6_pf64 = v_D_apf64[ ( v_K_u8 *2U ) + 1U ] + 6;
    v_Xs1_af64[ 0U ] = b_Xs1X_af64 [ v_K_u8 ];
    v_Xs1_af64[ 1U ] = b_Xs1Y_af64 [ v_K_u8 ];
    v_Xs2_af64[ 0U ] = b_Xs2X_af64 [ v_K_u8 ];
    v_Xs2_af64[ 1U ] = b_Xs2Y_af64 [ v_K_u8 ];

    for( v_I_u16 = 0U; v_I_u16 < 3U; v_I_u16++ )
    {
      *v_D1_pf64 = v_Xs1_af64[ v_I_u16 ];
      *v_D2_pf64 = 0.0;
      *v_D3_pf64 =  - ( v_Xs1_af64[ v_I_u16 ] *v_Xs2_af64[ 0 ] );

      *v_D4_pf64 = 0.0;
      *v_D5_pf64 = v_Xs1_af64[ v_I_u16 ];
      *v_D6_pf64 =  - ( v_Xs1_af64[ v_I_u16 ] *v_Xs2_af64[ 1 ] );
      /* vm_cprintf("%d, %d, %d, %d, %d, %d\n",(sint32_t)(*D1_p*10000), (sint32_t)(*D2_p*10000), (sint32_t)(*D3_p*10000), (sint32_t)(*D4_p*10000), (sint32_t)(*D5_p*10000), (sint32_t)(*D6_p*10000)); */

      v_D1_pf64++;
      v_D2_pf64++;
      v_D3_pf64++;
      v_D4_pf64++;
      v_D5_pf64++;
      v_D6_pf64++;
      /* vm_cprintf("%d, %d, %d, %d, %d, %d\n",(sint32_t)(*D1_p*10000), (sint32_t)(*D2_p*10000), (sint32_t)(*D3_p*10000), (sint32_t)(*D4_p*10000), (sint32_t)(*D5_p*10000), (sint32_t)(*D6_p*10000)); */
    }
  }
  for(v_I_u16 = 0; v_I_u16<9; v_I_u16++)
  {
    /* vm_cprintf("w[%d]: %d\n",i,(sint32_t)(w[i]*10000)); */
  }
  svdcmp_v( v_D_apf64, (uint16_t)i_M_u8 *2U, 9U, v_W_af64, v_V_apf64 );
  for(v_I_u16 = 0; v_I_u16<9; v_I_u16++)
  {
    /* vm_cprintf("*v_p[%d]: %d, %p, %p, %d\n",i,(sint32_t)(*v_p[i]*10000), v_p[i], v_p[i]+8,(sint32_t)(v_p[i][8]*10000)); */
    /* vm_cprintf("v[%d][8]: %d, w: %d\n",i,(sint32_t)(v[i][8]*10000),(sint32_t)(w[i]*10000)); */
  }

  if( i_M_u8 > 9U ) {
    i_M_u8 = 9U;
  }
  svdreorder_v( v_D_apf64, (uint16_t)i_M_u8 *2U, 9U, v_W_af64, &( v_V_apf64[ 0 ] ) );
  for(v_I_u16 = 0; v_I_u16<9; v_I_u16++)
  {
    /* vm_cprintf("*v_p[%d]: %d, %p, %p, %d\n",i,(sint32_t)(*v_p[i]*10000), v_p[i], v_p[i]+8,(sint32_t)(v_p[i][8]*10000)); */
    /* vm_cprintf("v[%d][8]: %d, w: %d\n",i,(sint32_t)(v[i][8]*10000),(sint32_t)(w[i]*10000)); */
  }
  for( v_I_u16 = 1U; v_I_u16 < 9U; v_I_u16++ ) {
    /*       if( w[ i ] < ( ( (float64_t)2.2204F * w[ 1U ] )* ( 10 ^ ( -13 ) ) ) ) */
    v_Temp_s32 = -7;                        /* 10 ^ (  - 13 ) = -7 */
    v_Temp_f64 = v_W_af64[ 1U ];
    v_Temp_f64 *= (float64_t)v_Temp_s32;
    v_Temp_f64 *= (float64_t)2.2204F;

    if( v_Temp_f64 > v_W_af64[ v_I_u16 ] ) {
      /* printf("Nullspace is a bit roomy");*/
      v_ErrCode_s8 = 0x42;
      break; 
    }
  }

  if (v_ErrCode_s8 != 0x42) { 
    v_H_a2f64[ 0][ 0 ] = v_V_a2f64[ 0][ 8 ];
    v_H_a2f64[ 0][ 1 ] = v_V_a2f64[ 1][ 8 ];
    v_H_a2f64[ 0][ 2 ] = v_V_a2f64[ 2][ 8 ];
    v_H_a2f64[ 1][ 0 ] = v_V_a2f64[ 3][ 8 ];
    v_H_a2f64[ 1][ 1 ] = v_V_a2f64[ 4][ 8 ];
    v_H_a2f64[ 1][ 2 ] = v_V_a2f64[ 5][ 8 ];
    v_H_a2f64[ 2][ 0 ] = v_V_a2f64[ 6][ 8 ];
    v_H_a2f64[ 2][ 1 ] = v_V_a2f64[ 7][ 8 ];
    v_H_a2f64[ 2][ 2 ] = v_V_a2f64[ 8][ 8 ];

    for( v_I_u16 = 0U; v_I_u16 < 3U; v_I_u16++ )
    {
      for( v_K_u8 = 0U; v_K_u8 < 3U; v_K_u8++ )
      {
        v_C2Inv_a2f64[ v_I_u16][ v_K_u8 ] = v_C2_af64[ (v_I_u16 *3U)+v_K_u8 ];
        v_C1M_a2f64[ v_I_u16][ v_K_u8 ] = v_C1_af64[ (v_I_u16 *3U)+v_K_u8 ];
        /* vm_cprintf("C2_inv[%d][%d]: %d\n", i, k, (sint32_t)(C2_inv[ i][ k ]*10000)); */
        /* vm_cprintf("C1_m[%d][%d]: %d\n", i, k, (sint32_t)(C1_m[ i][ k ]*10000)); */
      }
    }
    aAlgo_f_CalcInvMat3x3_v( v_C2Inv_a2f64 );
    for( v_I_u16 = 0U; v_I_u16 < 3U; v_I_u16++ )
    {
      for( v_K_u8 = 0U; v_K_u8 < 3U; v_K_u8++ )
      {
        /* vm_cprintf("C2_inv[%d][%d]: %d\n", i, k, (sint32_t)(C2_inv[ i][ k ]*10000)); */
        /* vm_cprintf("v_tempH_d32[%d][%d]: %d\n", i, k, (sint32_t)(v_tempH_d32[ i][ k ]*10000)); */
        /* vm_cprintf("H[%d][%d]: %d\n", i, k, (sint32_t)(H[ i][ k ]*10000)); */
      }
    }

    /*     aAlgo_f_CalcMulMat3x3_3x3_v( C2_inv, H, v_tempH_d32 );   */
    /*     memcpy(H, v_tempH_d32, (uint32_t)sizeof(float64_t)*9U); */
    /*                                                              */
    /*     aAlgo_f_CalcMulMat3x3_3x3_v( H, C1_m, v_tempH_d32 );     */
    /*     memcpy(H, v_tempH_d32, (uint32_t)sizeof(float64_t)*9U); */

    aAlgo_f_CalcMulMat3x3_3x3_v( v_C2Inv_a2f64, v_H_a2f64, v_TempH_a2f64 );
    for( v_I_u16 = 0U; v_I_u16 < 3U; v_I_u16++ )
    {
      for( v_K_u8 = 0U; v_K_u8 < 3U; v_K_u8++ )
      {
        /* vm_cprintf("C2_inv[%d][%d]: %d\n", i, k, (sint32_t)(C2_inv[ i][ k ]*10000)); */
        /* vm_cprintf("v_tempH_d32[%d][%d]: %d\n", i, k, (sint32_t)(v_tempH_d32[ i][ k ]*10000)); */
        /* vm_cprintf("H[%d][%d]: %d\n", i, k, (sint32_t)(H[ i][ k ]*10000)); */
      }
    }
    aAlgo_f_CalcMulMat3x3_3x3_v( v_TempH_a2f64, v_C1M_a2f64, v_H_a2f64 );
    for( v_I_u16 = 0U; v_I_u16 < 3U; v_I_u16++ )
    {
      for( v_K_u8 = 0U; v_K_u8 < 3U; v_K_u8++ )
      {
        /* vm_cprintf("C1_m[%d][%d]: %d\n", i, k, (sint32_t)(C1_m[ i][ k ]*10000)); */
        /* vm_cprintf("v_tempH_d32[%d][%d]: %d\n", i, k, (sint32_t)(v_tempH_d32[ i][ k ]*10000)); */
        /* vm_cprintf("H[%d][%d]: %d\n", i, k, (sint32_t)(H[ i][ k ]*10000)); */
      }
    }

    v_J_u8 = 0U;
    for( v_I_u16 = 0U; v_I_u16 < 3U; v_I_u16++ )
    {
      for( v_K_u8 = 0U; v_K_u8 < 3U; v_K_u8++ )
      {
        v_H_a2f64[ v_I_u16][ v_K_u8 ] = v_H_a2f64[ v_I_u16][ v_K_u8 ] / v_H_a2f64[ 2][ 2 ];
        /* vm_cprintf("FINAL: H[%d][%d]: %d\n", i, k, (sint32_t)(H[ i][ k ]*10000)); */
        o_H1_af64[v_J_u8] = v_H_a2f64[ v_I_u16][ v_K_u8 ];
        /* vm_cprintf("FINAL: H1[%d]: %d\n", j, (sint32_t)(H1[j]*10000)); */
        v_J_u8++;
      }
    }
  }
  return v_ErrCode_s8;
}

/* ------------------------------------------------------------------------- */
/*PRQA S 3673 1*/ /* The input parameter is converted to this array type */
static float64_t aAlgo_f_CalcDetMat3x3_f64(  float64_t i_M_a2f64[][ 3 ] )
{
  /* DD-ID: {78A3E3CB-2B3D-4606-B625-43139C7E3AAD}*/
  uint8_t v_I_u8;
  float64_t v_Det_f64 = 0.0;

  for( v_I_u8 = 0U; v_I_u8 < 3U; v_I_u8++ )
  {
    v_Det_f64 +=     (i_M_a2f64[0][v_I_u8])
                   * (   (i_M_a2f64[1][(v_I_u8 + 1) % 3] * i_M_a2f64[2][(v_I_u8 + 2) % 3])
                       - (i_M_a2f64[1][(v_I_u8 + 2) % 3] * i_M_a2f64[2][(v_I_u8 + 1) % 3])
                   );
  }

  return v_Det_f64;
}

/* ------------------------------------------------------------------------- */

static void aAlgo_f_CalcInvMat3x3_v( float64_t b_M_a2f64[][ 3 ] )
{
  /* DD-ID: {9A61A0E1-836C-4c2b-B64D-E6CEF74AA778}*/
  uint8_t v_I_u8;
  uint8_t v_J_u8;
  float64_t v_Det_f64;
  float64_t v_M_a2f64[ 3][ 3 ];
  float64_t v_Temp_f64;

  for( v_I_u8 = 0U; v_I_u8 < 3U; v_I_u8++ )
  {
    for( v_J_u8 = 0U; v_J_u8 < 3U; v_J_u8++ )
    {
      v_M_a2f64[ v_I_u8][ v_J_u8 ] = b_M_a2f64[ v_I_u8][ v_J_u8 ];
    }
  }


  v_Det_f64 = aAlgo_f_CalcDetMat3x3_f64( v_M_a2f64 );


  for( v_I_u8 = 0U; v_I_u8 < 3U; v_I_u8++ )
  {
    for( v_J_u8 = 0U; v_J_u8 < 3U; v_J_u8++ )
    {

      v_Temp_f64 =
          ( (v_M_a2f64[ ( v_J_u8 + 1U ) % 3U][ ( v_I_u8 + 1U ) % 3U ] *
              v_M_a2f64[ ( v_J_u8 + 2U ) % 3U][ ( v_I_u8 + 2U ) % 3U ]) -
              (v_M_a2f64[ ( v_J_u8 + 1U ) % 3U][ ( v_I_u8 + 2U ) % 3U ] *
                  v_M_a2f64[ ( v_J_u8 + 2U ) % 3U][ ( v_I_u8 + 1U ) % 3U ]) );
      b_M_a2f64[ v_I_u8][ v_J_u8 ] = v_Temp_f64 / v_Det_f64;
    }
  }
}

/* ------------------------------------------------------------------------- */
/*PRQA S 3673 1*/ /* The input parameter is converted to this array type */
static void aAlgo_f_CalcMulMat3x3_3x3_v(  float64_t i_A_a2f64[][ 3 ],  float64_t i_B_a2f64[][ 3 ], float64_t o_C_a2f64[][ 3 ] )
{
  /* DD-ID: {3A841708-5A80-4a4f-9F93-32905BC06C89}*/
  uint8_t v_I_u8;
  uint8_t v_J_u8;
  uint8_t v_K_u8;
  float64_t v_D_a2f64[ 3][ 3 ] =
  {
   {
    0.0, 0.0, 0.0
   }

   ,
   {
    0.0, 0.0, 0.0
   }

   ,
   {
    0.0, 0.0, 0.0
   }
  };
  for( v_I_u8 = 0U; v_I_u8 < 3U; v_I_u8++ )
  {
    for( v_J_u8 = 0U; v_J_u8 < 3U; v_J_u8++ )
    {
      for( v_K_u8 = 0U; v_K_u8 < 3U; v_K_u8++ )
      {
        v_D_a2f64[ v_I_u8][ v_J_u8 ] = v_D_a2f64[ v_I_u8][ v_J_u8 ] + (i_A_a2f64[ v_I_u8][ v_K_u8 ] *i_B_a2f64[ v_K_u8][ v_J_u8 ]);
      }
    }
  }
  for( v_I_u8 = 0U; v_I_u8 < 3U; v_I_u8++ )
  {
    for( v_J_u8 = 0U; v_J_u8 < 3U; v_J_u8++ )
    {
      o_C_a2f64[ v_I_u8][ v_J_u8 ] = v_D_a2f64[ v_I_u8][ v_J_u8 ];
    }
  }
}



/*  ---------------------------------- EOF -------------------------------------- */
