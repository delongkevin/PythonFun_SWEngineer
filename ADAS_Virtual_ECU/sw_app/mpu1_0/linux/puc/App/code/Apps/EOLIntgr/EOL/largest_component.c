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

	$Header: largest_component.c 1.9 2016/06/01 21:07:51IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:51IST $
	$Revision: 1.9 $

===================================================================================*/

/*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: largest_component.c  $
 Revision 1.9 2016/06/01 21:07:51IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.8 2016/05/31 16:02:44CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.7.1.1 2016/04/12 19:42:54CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.7 2016/04/08 03:48:17EDT Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Adapt EOL to coding style
 Revision 1.6.1.1 2016/04/05 13:44:47MESZ Ziehl, Roland (SAI_RZieh) 
 Adapt EOL to coding style
 Revision 1.6 2016/03/14 13:05:02MEZ Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Renamed float constants to upper-case F
 Revision 1.5.1.1 2016/03/11 10:27:58MEZ Schulte, Michael (MEE_MiSch) 
 Renamed float constants to upper-case F
 Revision 1.5 2015/08/18 16:43:23CEST Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.4 2015/06/04 00:33:15CEST Rasool, Muzammil (MEE_MRASOO) 
 ind_startup.h removed from #includes.
 Revision 1.3 2015/05/29 13:27:13CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:50CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:52CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.3 2014/05/05 04:47:09EDT Sebastian Pliefke (spliefke) 
 Fix bug in corner list reduction fuction
 Revision 1.2 2013/07/25 17:09:42MESZ Sebastian Pliefke (spliefke) 
 Remove warnings
 Revision 1.1 2013/07/09 16:52:05MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/corner/project.pj
 Revision 1.8 2012/07/12 22:28:31MESZ Marko Vico (mvico) 
 EoL algo update 4.2 Bug Fix from Hilda
 Revision 1.7 2012/06/26 12:37:16EDT Tina Behal (tbehal) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
 Revision 1.7 2012/01/23 10:45:24EST Ali Ahmed (aahmed) 
 Major system and OC changes.
 Revision 1.6 2011/10/14 12:31:31EDT Anupama Bhide (abhide) 
 QAC Misra C modifications
 Revision 1.5 2011/08/08 18:42:25EDT Anupama Bhide (abhide) 
 Misra C modifications - pclint
 Revision 1.4 2011/08/04 17:23:24EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.3 2011/08/04 10:53:04EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:27EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#include "largest_component.h"
#include <math.h>
#include <string.h>

/* --- Private Typedefinitions, Enumerations, Defines --------------------- */

/* #pragma CHECK_MISRA("required") */
/* PRQA S 4800 EOF */
/* PRQA S 7006 EOF */
/* PRQA S 7008 EOF */

/* Pointer Arithmetic Rules*/
/* PRQA S 488 EOF */
/* PRQA S 489 EOF */
/* PRQA S 491 EOF */
/* PRQA S 492 EOF */

/* --- Private Variables, Constants ------------------------------------------ */

/* --- Private Macros -------------------------------------------------------- */

/* --- Private Function Prototypes ------------------------------------------- */
static void f_getDirections_v( graph_S_NeighborList_t i_NeighborList_s, uint8_t *o_Dirs_pu8, 
                               uint8_t *o_DirsNo_pu8, uint8_t *o_Dirbits_pu8 );

/* count points in one direction */
static uint32_t f_CountOneDir_u32( graph_S_NeighborList_t *i_NeighborList_ps,  /* neighbor graph */
                                   uint32_t *b_CanIndx_pu32,  /* start point */
                                   uint8_t i_Dir_u8,  /* direction */
                                   uint32_t i_OPoints_u32 /* max counts in this directions */
);

static void f_LocateMaxPoints_v( const uint32_t *i_PointCnt_pu32, uint32_t *o_MaxCnt_pu32, 
                                 uint8_t *o_MaxIndx_pu8 );

static uint8_t f_FindMaxComponent_u8( uint32_t i_CandidateCount_u32, uint32_t *b_CornerData_pu32, 
                                      uint32_t i_Max_u32 );

static void f_calcPointsbyRim_v( graph_S_NeighborList_t *b_NeighborList_ps, uint32_t i_CandIndx_u32, 
                                 const uint8_t *i_Dirs_pu8,
                                 uint32_t *o_PointCnt_pu32,  /* output points in two directions */
                                 sint8_t *o_Fp_ps8, uint8_t i_NX_u8, uint8_t i_NY_u8 );

static sint8_t f_GridRowCol2_s8( uint32_t i_Indx_u32, uint16_t *o_Row_pu16, uint16_t *o_Col_pu16, 
                                 uint8_t i_NX_u8 );

static sint16_t f_getSeedNr_s16( uint8_t i_Dirbits_u8, uint8_t i_NX_u8, uint8_t i_NY_u8 );


static sint8_t f_GridRowCol_s8( uint32_t i_Indx_u32, io_S_Pos_t *o_Grid_ps, uint8_t i_NX_u8 );

static sint8_t f_markOneCandidate_s8( uint32_t i_CanInx_u32,  /* candidate index */
                                      graph_S_NeighborList_t i_NeighborList_s,  /* graph */
                                      uint8_t *b_StateFlag_pu8,  /* state flag */
                                      sint32_t *b_PointNr_ps32,  /* count */
                                      uint8_t *b_CornersSeen_pu32,  /* map for candidates */
                                      uint8_t i_NX_u8 );

static sint8_t f_countOneCorner_s8( uint32_t i_CanIndx_u32,  /* candidate index */
                                    uint32_t i_CandidateCount_u32,  /* no of candidates*/
                                    const graph_S_NeighborList_t *i_NeighborList_ps,  /* neighbor graph*/
                                    sint16_t i_SeedNr_s16,  /* corner direction */
                                    sint32_t *o_PointPerCorner_ps32,  /* corner points count */
                                    uint8_t i_NX_u8 );

static sint8_t f_validateCorners_s8( sint32_t *i_PointPerCorner_ps32,  /* point see for each corner */
                                     uint32_t i_CandidateCount_u32,  /* no of candidattes */
                                     sint32_t *o_PointNr_ps32,  /* count the nuber of candidates in each row */
                                     uint8_t i_cornerno_u8 );

static void f_checkPartialDir_v( graph_S_NeighborList_t *i_NeighborList_ps, uint32_t i_CanIndx_u32, uint32_t *o_PartialDir_pu32, uint8_t i_NX_u8, uint8_t i_NY_u8 );

static void f_removePartialDir_v( graph_S_NeighborList_t *i_NeighborList_ps, uint16_t i_ImgX_u16, uint16_t i_ImgY_u16, uint32_t i_CanIndx_u32, uint32_t *i_PartialDir_pu32, io_S_PosSub_t *i_Candidates_ps, uint32_t *b_CornerData_pu32 );

static uint16_t f_Round_u16( float32_t i_Number_f32 );


/* --- Public Function Definitions ---------------------------------------- */

/*
 * We may still have more than one component in the graph
 * the following heuristics is used to find the largest component (most nodes)
 * and determine the corner at the same time
 * Check all the corners and try to build a complete grid by going up and left or
 * left then up. Since we already have circles, this finds the largest 
 * rectangular component, even if some edge points are missing
 * in case there is more than one point with the same number of nodes and some
 * nodes are close to the edge of the image and the rig is not completely
 * visible, remove those that are close to the edge
 */
uint8_t aLComp_F_countEachComponent_v( graph_S_NeighborList_t b_NeighborList_as[],  /* neighbor graph */
                                       uint32_t i_CandidateCount_u32,  /* no of candidates */
                                       uint32_t o_CornerData_au32[],  /* corner data */
                                       uint8_t i_NX_u8, uint8_t i_NY_u8 )
{
  /* DD-ID: {30972E03-BF0D-4176-8C2E-2CE64FD2EED9}*/
  uint32_t v_I_u32;
  uint8_t v_Dirs_au8[ D_Direction ];
  uint8_t v_DirsNo_u8;
  uint8_t v_Dirbits_u8;
  uint8_t v_J_u8;
  uint32_t v_MaxCnt_u32;
  uint8_t v_MaxIndx_u8;
  sint8_t v_Fp_s8 = 0; /* false positive indicator */
  uint8_t v_CornerCount_u8 = 0U;

  uint32_t v_PointCnt_au32[ 2 ] = 
  {
   0U, 0U
  }; /* count the points in two directions */
  graph_S_NeighborList_t *v_NeighborList_ps;
  uint32_t v_Max_u32 = 0U;

  memset( o_CornerData_au32, 0, ( uint32_t )sizeof( uint32_t ) *aAlgoECSrc_D_MAX_CORNER_NO * 3U );  /*PRQA S 3200 */   /* return type is not being used	 */
  /* for each candidate */
  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    v_DirsNo_u8 = 0U;

    for( v_J_u8 = 0U; v_J_u8 < D_Direction; v_J_u8++ )
    {
      v_Dirs_au8[ v_J_u8 ] = 0U;
    }

    v_Dirbits_u8 = 0U;

    v_NeighborList_ps = &b_NeighborList_as [ v_I_u32];
    /* get directions info for this corner candidates */
    f_getDirections_v( *v_NeighborList_ps, v_Dirs_au8, &v_DirsNo_u8, &v_Dirbits_u8 );

    /* if only two directions, that is a corner */
    if( v_DirsNo_u8 == 2U )
    {
      v_Fp_s8 = 0; /* reset the false positive indicator */
      v_PointCnt_au32[ 0 ] = 0U;
      v_PointCnt_au32[ 1 ] = 0U;

      f_calcPointsbyRim_v( b_NeighborList_as, v_I_u32, v_Dirs_au8, v_PointCnt_au32, &v_Fp_s8, i_NX_u8, i_NY_u8 );

      /* p 9 starting */
      if( v_Fp_s8 == 0 )
      {
        f_LocateMaxPoints_v( v_PointCnt_au32, &v_MaxCnt_u32, &v_MaxIndx_u8 );
        /* 3 * maxcount, index v_I_u32 */
        o_CornerData_au32 [ v_I_u32 ] = v_MaxCnt_u32;
        o_CornerData_au32 [ i_CandidateCount_u32 + v_I_u32 ] = v_Dirs_au8[ v_MaxIndx_u8 ];
        o_CornerData_au32 [ ( i_CandidateCount_u32 * 2U ) + v_I_u32 ] = v_Dirbits_u8;

        v_Max_u32 = ( v_Max_u32 < v_MaxCnt_u32 ) ? v_MaxCnt_u32 : v_Max_u32;
      }
    } /*if*/
  } /*for*/

  v_CornerCount_u8 = f_FindMaxComponent_u8(i_CandidateCount_u32, o_CornerData_au32, v_Max_u32 );
  return v_CornerCount_u8;
}

/*
 * post processing on page 9
 */
sint8_t aLComp_F_seeComplete_s8( graph_S_NeighborList_t *i_NeighborList_ps,  /* neighbor graph */
                                 uint16_t i_ImgX_u16, uint16_t i_ImgY_u16, uint32_t i_CandidateCount_u32,  /* no of candidates */
                                 io_S_PosSub_t *i_Candidates_ps,  /* candidate pos list */
                                 uint32_t b_CornerData_au32[],  /* corner data */
                                 uint8_t i_NX_u8, uint8_t i_NY_u8 )
{
  /* DD-ID: {8B165F7F-192F-441c-95AC-E03AC9A2A7D4}*/
  uint32_t v_I_u32;
  uint32_t *v_CornerData_pu32 = &b_CornerData_au32[0];
  sint8_t v_SeeComplete_s8 =  - 1;
  sint8_t v_J_s8;

  uint32_t v_PartialDir_au32[ D_Direction ];
  for( v_J_s8 = 0; v_J_s8 < (sint8_t)D_Direction; v_J_s8++ )
  {
    v_PartialDir_au32[ v_J_s8 ] = 0U;
  }

  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    if( (uint32_t)(i_NX_u8 *i_NY_u8) == *(v_CornerData_pu32 + v_I_u32 ) )
    {
      v_SeeComplete_s8 = 1;
    }
    else if( 0U != v_CornerData_pu32 [ v_I_u32 ] )
    {
      /* only partially */
      f_checkPartialDir_v( i_NeighborList_ps, v_I_u32, v_PartialDir_au32, i_NX_u8, i_NY_u8 );

      /* prune the direction which is only partially */
      f_removePartialDir_v( i_NeighborList_ps, i_ImgX_u16, i_ImgY_u16, v_I_u32, v_PartialDir_au32, i_Candidates_ps, b_CornerData_au32 );
    }
    else
    {
      /* Do Nothing  */
    }  /*ifelse*/ 

  }
  return ( v_SeeComplete_s8 );
}

/* 
 * in case there are more than one corner?
 * be paranoid and check if an enumeration of all yields the same results 
 * if not, we have use different component 
 */
sint8_t aLComp_F_checkSingleCorner_s8( const graph_S_NeighborList_t *i_NeighborList_ps,  /* neighbor graph */
                                       uint32_t i_CandidateCount_u32,  /* no of candidates */
                                       uint32_t *i_CornerData_pu32,  /* corner data */
                                       sint32_t *o_PointNr_ps32,  /* counting no of canadidates */
                                       uint8_t i_NX_u8, uint8_t i_NY_u8 )
{
  /* DD-ID: {1C1F286E-5E3E-46cc-A173-946ACF84B879}*/
  uint32_t v_I_u32;
  uint8_t v_K_u8 = 0U;
  uint32_t v_Temp_u32;
  sint8_t v_ErrCode_s8;
  uint32_t *v_CornerData_pu32 = i_CornerData_pu32;

  uint8_t v_Dirbits_u8 = 0;
  sint16_t v_SeedNr_s16 = -1;

  sint32_t v_PointPerCorner_as32[(uint32_t) D_Direction * aAlgoECSrc_D_MAX_CORNER_NO ] = {0};
  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    if( *v_CornerData_pu32 == 0U )
    {
      v_CornerData_pu32++;
    }
    else
    {
      v_CornerData_pu32++;
      /* not a corner. go continue */
      v_Temp_u32 = ( ( (uint32_t)2U *i_CandidateCount_u32 ) + v_I_u32 );
      v_Dirbits_u8 = ( uint8_t ) ( *( i_CornerData_pu32 + v_Temp_u32 ) );
      v_SeedNr_s16 = f_getSeedNr_s16( v_Dirbits_u8, i_NX_u8, i_NY_u8 );

      if( v_SeedNr_s16 >= 0 )
      {
        v_Temp_u32 = i_CandidateCount_u32 * v_K_u8;
        if(v_Temp_u32 > (aAlgoECSrc_D_MAX_CORNER_NO*3)){
          v_Temp_u32 = aAlgoECSrc_D_MAX_CORNER_NO*3;
        }
        v_ErrCode_s8 = f_countOneCorner_s8( v_I_u32, i_CandidateCount_u32, i_NeighborList_ps, v_SeedNr_s16, 
            &v_PointPerCorner_as32 [ v_Temp_u32],
            i_NX_u8 );
        v_K_u8++;                             
      } /*if*/
    }
  } /*for */
  v_ErrCode_s8 = f_validateCorners_s8( v_PointPerCorner_as32, i_CandidateCount_u32, o_PointNr_ps32, v_K_u8 );
  return v_ErrCode_s8;  
}

/* ------------------------------------------------------------------------- */

sint8_t aLComp_F_regSubpixels_s8( sint32_t *i_PointNr_ps32,  /* no of canadiates in each row */
                                  io_S_PosSub_t *o_CanPosSub_ps,  /* candidate pos list */
                                  uint32_t *o_CandidateCount_pu32,  /* no of candidate */
                                  io_S_Pos_t *o_Grid_ps,  /* candidate grid list */
                                  uint8_t i_NX_u8, uint8_t i_NY_u8 )
{
  /* DD-ID: {0AA29CB7-21B1-49a0-BA11-35D37A3A8CE7}*/
  uint32_t v_I_u32;
  uint32_t v_J_u32 = 0U;
  sint32_t *v_PointNr_ps32 = i_PointNr_ps32;
  io_S_PosSub_t *v_CanSub_ps = o_CanPosSub_ps;
  io_S_Pos_t *v_Grid_ps = o_Grid_ps;
  sint8_t v_errcode_s8 = aAlgoECSrc_D_SUCCESS;

  for( v_I_u32 = 0U; ( v_I_u32 <  (( uint32_t )i_NX_u8 *i_NY_u8 ) ); v_I_u32++ )
  {
    o_Grid_ps[ v_I_u32 ].x_s16 = -1; 
    o_Grid_ps[ v_I_u32 ].y_s16 = -1;
  }

  for( v_I_u32 = 0U; v_I_u32 <  *o_CandidateCount_pu32; v_I_u32++ )
  {
    if( 0 <= *(v_PointNr_ps32 + v_I_u32 ) )
    {
      ( v_CanSub_ps + v_J_u32 )->x_f32 = ( v_CanSub_ps + v_I_u32 )->x_f32;
      ( v_CanSub_ps + v_J_u32 )->y_f32 = ( v_CanSub_ps + v_I_u32 )->y_f32;
      ( v_CanSub_ps + v_J_u32 )->v_f32 = ( v_CanSub_ps + v_I_u32 )->v_f32;
      if( (sint32_t)f_GridRowCol_s8( ( uint32_t ) ( v_PointNr_ps32[ v_I_u32 ] ), v_Grid_ps, i_NX_u8 ) < 0 )
      {
        v_errcode_s8 = aAlgoECSrc_D_ERR_FAIL;
        break;
      }
      v_Grid_ps++;
      v_J_u32++;
    }
  }
  if (v_errcode_s8 != aAlgoECSrc_D_ERR_FAIL)
  {
    *o_CandidateCount_pu32 = v_J_u32;
    v_errcode_s8 = aAlgoECSrc_D_SUCCESS;
  }
  return v_errcode_s8;
}

/* --- Private Function Definitions ------------------------------------------ */

/* check whether a corner is valid */
static sint8_t f_validateCorners_s8( sint32_t *i_PointPerCorner_ps32,  /* point see for each corner */
                                     uint32_t i_CandidateCount_u32,  /* no of candidattes */
                                     sint32_t *o_PointNr_ps32,  /* count the nuber of candidates in each row */
                                     uint8_t i_cornerno_u8 )
{
  /* DD-ID: {9DFE35D2-FD1D-47ec-8D54-5122305D298C}*/
  uint32_t v_I_u32;
  uint8_t v_K_u8;
  sint32_t *v_PointPerCorner1_pu16 = i_PointPerCorner_ps32;
  sint8_t v_errcode_s8 = aAlgoECSrc_D_SUCCESS;
  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    for( v_K_u8 = 1U; v_K_u8 < i_cornerno_u8; v_K_u8++ )
    {

      if( ( *( v_PointPerCorner1_pu16 ) != *( v_PointPerCorner1_pu16 + (i_CandidateCount_u32 * v_K_u8 ) ) ) )
      {
        v_errcode_s8 = aAlgoECSrc_D_ERR_INVALIDCORNER;
        break;
      }
    }
    if (v_errcode_s8 == aAlgoECSrc_D_ERR_INVALIDCORNER) {
      break;
    }
    else
    {
      v_PointPerCorner1_pu16++;
    }
  }

  if (v_errcode_s8 != aAlgoECSrc_D_ERR_INVALIDCORNER)
  {
    for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
    {
      o_PointNr_ps32[ v_I_u32 ] = i_PointPerCorner_ps32[ v_I_u32 ];
    }

    v_errcode_s8 = aAlgoECSrc_D_SUCCESS;
  }

  return v_errcode_s8;
}

/* count the no of points see from a corner */
static sint8_t f_countOneCorner_s8( uint32_t i_CanIndx_u32,  /* candidate index */
                                    uint32_t i_CandidateCount_u32,  /* no of candidates*/
                                    const graph_S_NeighborList_t *i_NeighborList_ps,  /* neighbor graph*/
                                    sint16_t i_SeedNr_s16,  /* corner direction */
                                    sint32_t *o_PointPerCorner_ps32,  /* corner points count */
                                    uint8_t i_NX_u8 )
{
  /* DD-ID: {00166F09-402B-4373-A57C-44777FBCE49E}*/
  uint8_t v_Found_u8 = 1U;
  uint8_t v_Front_u8 = 1U;
  uint8_t v_Done_u8 = 2U;
  uint32_t v_J_u32;
  sint32_t v_PointNr_as32[ aAlgoECSrc_D_MAX_CORNER_NO ];
  sint8_t v_errcode_s8;

  uint8_t v_CornersSeen_au8[ aAlgoECSrc_D_CORNER_NX_NY ] = {0U};
  uint8_t v_StateFlag_au8[ aAlgoECSrc_D_MAX_CORNER_NO ];

  for( v_J_u32 = 0U; v_J_u32 < aAlgoECSrc_D_MAX_CORNER_NO; v_J_u32++ )
  {
    v_StateFlag_au8[ v_J_u32 ] = 0U;
    v_PointNr_as32[ v_J_u32 ] =  - 1;
  }

  v_PointNr_as32[ i_CanIndx_u32 ] = i_SeedNr_s16;
  *( v_StateFlag_au8 + i_CanIndx_u32 ) = v_Front_u8;
  v_CornersSeen_au8[ i_SeedNr_s16 ] = ( uint8_t )i_CanIndx_u32 + 1U;
  while( v_Found_u8 == 1U )
  {
    v_Found_u8 = 0U;

    for( v_J_u32 = 0U; v_J_u32 < i_CandidateCount_u32; v_J_u32++ )
    {
      if( v_Front_u8 != *( v_StateFlag_au8 + v_J_u32 ) )
      {
      }
      else
      {
        v_errcode_s8 = f_markOneCandidate_s8( v_J_u32, i_NeighborList_ps[ v_J_u32 ], v_StateFlag_au8, v_PointNr_as32, v_CornersSeen_au8, i_NX_u8 );
        v_StateFlag_au8[ v_J_u32 ] = v_Done_u8;
        v_Found_u8 = 1U;
      }
    } /*for */
  } /*while */

  memcpy(o_PointPerCorner_ps32, v_PointNr_as32, (uint32_t)sizeof(sint32_t)*aAlgoECSrc_D_MAX_CORNER_NO);  /*PRQA S 3200 */   /* return type is not being used	 */
  v_errcode_s8 = aAlgoECSrc_D_SUCCESS;
  return v_errcode_s8;
}

/* mark the no of candidates see from a corner */
static sint8_t f_markOneCandidate_s8( uint32_t i_CanInx_u32,  /* candidate index */
                                      graph_S_NeighborList_t i_NeighborList_s,  /* graph */
                                      uint8_t *b_StateFlag_pu8,  /* state flag */
                                      sint32_t *b_PointNr_ps32,  /* count */
                                      uint8_t *b_CornersSeen_pu32,  /* map for candidates */
                                      uint8_t i_NX_u8 )
{
  /* DD-ID: {4EFA0E1C-068A-499f-94F7-056CFD9777D9}*/
  uint8_t v_D_u8;
  sint16_t v_Temp_s16;
  sint16_t v_Temp1_s16;
  uint32_t v_K_u32;
  uint32_t v_Temp_u32;
  uint8_t v_UnTouched_u8 = 0U;
  uint8_t v_Front_u8 = 1U;
  uint8_t v_Done_u8 = 2U;
  sint32_t v_NewPtNr_s32 =  -1;
  sint8_t v_RowColOffs_as8[ 8 ] = 
  {
   0, 1, 0,  - 1, 1, 0,  - 1, 0
  };
  sint8_t v_res_s8 = 1;
  uint16_t v_Row_u16;
  uint16_t v_Col_u16;
  uint16_t v_Row2_u16;
  uint16_t v_Col2_u16;
  sint16_t v_DirOffs_as16[ 4 ] = 
  {
   1, 9,  - 1,  - 9
  };
  sint8_t v_Temp_s8;
  v_DirOffs_as16[ 1 ] = (sint16_t)i_NX_u8;
  v_DirOffs_as16[ 3 ] =  - (sint16_t)i_NX_u8;

  for( v_D_u8 = 0U; v_D_u8 < 4U; v_D_u8++ )
  {
    if( (sint32_t)aGraph_F_isEmptyNeighbor_s8( i_NeighborList_s, v_D_u8 ) > 0 )
    {

    }
    else
    {
      v_K_u32 = aGraph_F_getNeighborIndx_u32( i_NeighborList_s, v_D_u8 );

      if( (uint32_t)v_UnTouched_u8 == b_StateFlag_pu8[ v_K_u32 ] )
      {
        v_NewPtNr_s32 = b_PointNr_ps32[ i_CanInx_u32 ] + v_DirOffs_as16[ v_D_u8 ];

        v_res_s8 = f_GridRowCol2_s8( ( uint32_t )b_PointNr_ps32[ i_CanInx_u32 ], 
            &v_Row_u16, &v_Col_u16, i_NX_u8 );
        v_Temp_s8 = f_GridRowCol2_s8( ( uint32_t )v_NewPtNr_s32, &v_Row2_u16, &v_Col2_u16, i_NX_u8 );
        if( (0 != v_res_s8) && ( v_Temp_s8 == 1) )
        {
          v_Temp_s16 = (sint16_t)v_Row_u16;
          v_Temp_s16 += v_RowColOffs_as8[ v_D_u8 ];

          v_Temp1_s16 = (sint16_t)v_Col_u16;
          v_Temp1_s16 += v_RowColOffs_as8[ 4U+v_D_u8 ];

          if(    ( v_Row2_u16 == (uint16_t)v_Temp_s16  )
              && ( v_Col2_u16 == (uint16_t)v_Temp1_s16 ) )
          {
            if( 0U < b_CornersSeen_pu32[ (uint32_t)v_NewPtNr_s32 ] )
            {
              v_Temp_u32 = b_CornersSeen_pu32[ v_NewPtNr_s32];
              b_PointNr_ps32[ v_Temp_u32 - 1U] =  -1;
              b_PointNr_ps32[ v_K_u32 ] =  - 1;
              b_StateFlag_pu8[ v_K_u32 ] = v_Done_u8;
              /*Changed for 4.2*/
              b_StateFlag_pu8[ v_Temp_u32 - 1U] = v_Done_u8;
            }
            else
            {
              b_PointNr_ps32[ v_K_u32 ] = v_NewPtNr_s32;
              b_StateFlag_pu8[ v_K_u32 ] = v_Front_u8;
              b_CornersSeen_pu32[ v_NewPtNr_s32 ] = ( uint8_t )v_K_u32 + 1U;
            }
          }
        }
      } /*if*/
    }
  } /*for */
  return aAlgoECSrc_D_SUCCESS;
}

/* count no of points along the rims */
static void f_calcPointsbyRim_v( graph_S_NeighborList_t *b_NeighborList_ps, uint32_t i_CandIndx_u32, 
                                 const uint8_t *i_Dirs_pu8,
                                 uint32_t *o_PointCnt_pu32,  /* output points in two directions */
                                 sint8_t *o_Fp_ps8, uint8_t i_NX_u8, uint8_t i_NY_u8 )
{
  /* DD-ID: {9C6A56A1-B3BE-47a3-83C3-F392BD42D80D}*/
  uint32_t v_J_u32;
  uint32_t v_OJ_u32;
  uint8_t v_D_u8;
  uint8_t v_Dir_u8;
  uint8_t v_ODir_u8;
  uint8_t v_Temp_u8;
  uint32_t v_Flag_u32;

  uint8_t v_Opposite_au8[ D_Direction ] = 
  {
   3U, 4U, 1U, 2U
  };

  uint32_t v_Points_u32 = 0U;
  uint32_t v_OPoints_u32 = 0U;
  sint8_t v_Temp_s8;

  uint32_t *v_PointCnt_pu32 = o_PointCnt_pu32;
  graph_S_NeighborList_t *v_NeighborList_ps;
  uint32_t v_NDir_au32[ 4 ]; /* points number in each directions */

  v_NDir_au32[ 0 ] = i_NX_u8;
  v_NDir_au32[ 1 ] = i_NY_u8;
  v_NDir_au32[ 2 ] = i_NX_u8;
  v_NDir_au32[ 3 ] = i_NY_u8;

  /* for each direction */
  for( v_D_u8 = 0U; v_D_u8 < 2U; v_D_u8++ )
  {
    v_Flag_u32 = 0U;
    v_Dir_u8 = i_Dirs_pu8[ v_D_u8 ];
    v_ODir_u8 = i_Dirs_pu8[ 1U-v_D_u8 ];
    v_J_u32 = i_CandIndx_u32;
    v_Points_u32 = v_NDir_au32[ v_Dir_u8 - 1U ];
    v_OPoints_u32 = v_NDir_au32[ v_ODir_u8 - 1U ];

    for( ;; )
    {
      v_NeighborList_ps = b_NeighborList_ps + v_J_u32;
      v_Temp_u8 = v_ODir_u8 - 1U;
      v_Temp_u8 = v_Opposite_au8[v_Temp_u8];
      if( 0 > aGraph_F_isEmptyNeighbor_s8( *v_NeighborList_ps, (uint8_t)v_Temp_u8 - 1U ) )
      {
        ( *o_Fp_ps8 ) = 1;
        v_Flag_u32 = 1U;
      }
      if (v_Flag_u32 == 0U)
      {
        v_OJ_u32 = v_J_u32;
        v_PointCnt_pu32[ v_D_u8 ] += f_CountOneDir_u32( b_NeighborList_ps, &v_OJ_u32, v_ODir_u8 - 1U, v_OPoints_u32 );

        /* if there is another link, something is very wrong */
        v_NeighborList_ps = b_NeighborList_ps + v_OJ_u32;
        if( 0 > aGraph_F_isEmptyNeighbor_s8( *v_NeighborList_ps, v_ODir_u8 - 1U ) )
        {
          ( *o_Fp_ps8 ) = 1;
        }

        /* go to next point in this direction */
        v_Points_u32--;
        v_NeighborList_ps = b_NeighborList_ps + v_J_u32;
        v_Temp_s8 = aGraph_F_isEmptyNeighbor_s8( *v_NeighborList_ps, ( v_Dir_u8 - 1U ) );
        if( ( v_Points_u32 == 0U ) || ( v_Temp_s8 > 0 ) )
        {
          v_Flag_u32 = 1U;
        }
        if (v_Flag_u32 == 0U)
        {
          v_J_u32 = aGraph_F_getNeighborIndx_u32( *v_NeighborList_ps, v_Dir_u8 - 1U );
        }
      }
      if ( v_Flag_u32 ==1U )
      {
        break;
      }
    } /* while */

    if( ( *o_Fp_ps8 ) == 1 )
    {
      break;
    }
  }
}
/* ------------------------------------------------------------------------- */

static void f_getDirections_v( graph_S_NeighborList_t i_NeighborList_s, uint8_t *o_Dirs_pu8, 
                               uint8_t *o_DirsNo_pu8, uint8_t *o_Dirbits_pu8 )
{
  /* DD-ID: {CA369395-FFF2-48bb-B2F6-F04292DACF44}*/
  uint8_t v_D_u8;
  sint32_t v_I_s32;
  graph_S_NeighborList_t v_NeighborList_s;
  uint8_t *v_Dirs_pu8 = o_Dirs_pu8;

  for (v_I_s32=0; v_I_s32<4; v_I_s32++)
  {
    v_NeighborList_s.neighbors_as[v_I_s32].index_u32 = i_NeighborList_s.neighbors_as[v_I_s32].index_u32;
    v_NeighborList_s.neighbors_as[v_I_s32].len_f32   = i_NeighborList_s.neighbors_as[v_I_s32].len_f32;
  }

  *o_Dirbits_pu8 = 0U;

  for( v_D_u8 = 0U; v_D_u8 < D_Direction; v_D_u8++ )
  {
    if( 0 > aGraph_F_isEmptyNeighbor_s8( v_NeighborList_s, v_D_u8 ) )
    {
      *v_Dirs_pu8 = v_D_u8 + 1U; /* all directions in one array, 1,2,3,4 */
      v_Dirs_pu8++;
      ( *o_DirsNo_pu8 )++; /* no of directions */
      ( *o_Dirbits_pu8 ) = ( uint8_t )pow((float64_t)2.0F, (float64_t)v_D_u8 + 1.0F )
                              + ( *o_Dirbits_pu8 ); /* all directions added to one number */
    }
  }
}


/* count points in one direction */
static uint32_t f_CountOneDir_u32( graph_S_NeighborList_t *i_NeighborList_ps,  /* neighbor graph */
                                   uint32_t *b_CanIndx_pu32,  /* start point */
                                   uint8_t i_Dir_u8,  /* direction */
                                   uint32_t i_OPoints_u32 /* max counts in this directions */
)
{
  /* DD-ID: {5DDEF356-29C8-4b8e-B2E7-D0FDA571F84E}*/
  uint32_t v_I_u32;
  uint32_t *v_CanIndx_pu32 = b_CanIndx_pu32;
  graph_S_NeighborList_t *v_NeighborList_ps;
  uint32_t v_PointCnt_u32 = 0U;

  for( v_I_u32 = 0U; v_I_u32 < i_OPoints_u32; v_I_u32++ )
  {
    v_PointCnt_u32++;
    v_NeighborList_ps = i_NeighborList_ps + ( *v_CanIndx_pu32 );

    if( 0 < aGraph_F_isEmptyNeighbor_s8(*v_NeighborList_ps, i_Dir_u8 ) )
    {
      break;
    }

    ( *v_CanIndx_pu32 ) = aGraph_F_getNeighborIndx_u32( *v_NeighborList_ps, i_Dir_u8 );

  }

  return v_PointCnt_u32;
}

/* ------------------------------------------------------------------------- */


static void f_LocateMaxPoints_v( const uint32_t *i_PointCnt_pu32, uint32_t *o_MaxCnt_pu32, 
                                 uint8_t *o_MaxIndx_pu8 )
{
  /* DD-ID: {16A72BA7-35B6-4d7a-B5A8-4C849BF4A6EF}*/
  *o_MaxCnt_pu32 = ( i_PointCnt_pu32[ 0 ] > i_PointCnt_pu32[ 1 ] ) ? i_PointCnt_pu32[ 0 ]: i_PointCnt_pu32[ 1 ];
  *o_MaxIndx_pu8 = ( i_PointCnt_pu32[ 0 ] > i_PointCnt_pu32[ 1 ] ) ? 0U : 1U;
}

/* ------------------------------------------------------------------------- */

static uint8_t f_FindMaxComponent_u8( uint32_t i_CandidateCount_u32, uint32_t *b_CornerData_pu32, 
                                      uint32_t i_Max_u32 )
{
  /* DD-ID: {FE9EF95C-D9B2-46f7-A774-029530D52032}*/
  uint32_t v_I_u32;
  uint32_t *v_CornerData_pu32 = b_CornerData_pu32;
  uint8_t v_Num_u8 = 0U;

  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    if( *v_CornerData_pu32 != 0U )
    {
      if( *v_CornerData_pu32 != i_Max_u32 )
      {
        *v_CornerData_pu32 = 0U;
      }
      else
      {
        v_Num_u8++;
      }
    }
    v_CornerData_pu32++;
  }
  return v_Num_u8;

}

/* ------------------------------------------------------------------------- */

static void f_removePartialDir_v( graph_S_NeighborList_t *i_NeighborList_ps, uint16_t i_ImgX_u16, 
                                  uint16_t i_ImgY_u16, uint32_t i_CanIndx_u32, uint32_t *i_PartialDir_pu32,
                                  io_S_PosSub_t *i_Candidates_ps, uint32_t *b_CornerData_pu32 )
{
  /* DD-ID: {7B743DD9-E7F3-49c4-9DE7-3211EFFD42B0}*/
  uint8_t v_D_u8;
  uint32_t v_J_u32;
  uint32_t *v_PartialDir_pu32 = i_PartialDir_pu32;
  uint16_t v_Row_u16;
  uint16_t v_Col_u16;
  io_S_PosSub_t *v_Candidates_ps;

  graph_S_NeighborList_t *v_NeighborList_ps = i_NeighborList_ps + i_CanIndx_u32;
  for( v_D_u8 = 0U; v_D_u8 < D_Direction; v_D_u8++ )
  {
    if( 0U == v_PartialDir_pu32[ v_D_u8 ])
    {
      ;
    }
    else
    {
      v_J_u32 = aGraph_F_getNeighborIndx_u32( *v_NeighborList_ps, ( uint8_t ) ( v_PartialDir_pu32[ v_D_u8 ] ) );

      v_Candidates_ps = i_Candidates_ps + i_CanIndx_u32;
      v_Row_u16 = f_Round_u16( v_Candidates_ps->y_f32 );
      v_Col_u16 = f_Round_u16( v_Candidates_ps->x_f32 );
      v_Row_u16 *= 2U;
      v_Col_u16 *= 2U;
      v_Candidates_ps = (i_Candidates_ps + v_J_u32) - 1;
      v_Row_u16 -= f_Round_u16( v_Candidates_ps->y_f32 );
      v_Col_u16 -= f_Round_u16( v_Candidates_ps->x_f32 );

      if( !( ( v_Row_u16 >= 1U ) &&
          ( v_Row_u16 <= i_ImgY_u16 ) &&
          ( v_Col_u16 >= 1U ) &&
          ( v_Col_u16 <= i_ImgX_u16 ) ) )
      {
        *( b_CornerData_pu32 + i_CanIndx_u32 ) = 0U;
      }
    }
  }
}

/* ------------------------------------------------------------------------- */

static void f_checkPartialDir_v( graph_S_NeighborList_t *i_NeighborList_ps, uint32_t i_CanIndx_u32, 
                                 uint32_t *o_PartialDir_pu32, uint8_t i_NX_u8, uint8_t i_NY_u8 )
{
  /* DD-ID: {27ABC4EB-A112-4dfc-9575-6B15970C0899}*/
  uint8_t v_D_u8;
  uint32_t v_PointsCnt_u32 = 0U;
  uint32_t v_J_u32;
  uint32_t *v_PartialDir_pu32 = o_PartialDir_pu32;
  graph_S_NeighborList_t *v_NeighborList_ps;
  uint32_t v_NDir_au32[ 4 ]; /* points number in each directions */
  sint8_t v_Temp_s8;

  v_NDir_au32[ 0 ] = i_NX_u8;
  v_NDir_au32[ 1 ] = i_NY_u8;
  v_NDir_au32[ 2 ] = i_NX_u8;
  v_NDir_au32[ 3 ] = i_NY_u8;

  for( v_D_u8 = 0U; v_D_u8 < D_Direction; v_D_u8++ )
  {
    v_NeighborList_ps = i_NeighborList_ps + i_CanIndx_u32;
    if( (sint32_t)aGraph_F_isEmptyNeighbor_s8( *v_NeighborList_ps, v_D_u8 ) < 0 )
    {
      v_PointsCnt_u32 = v_NDir_au32[ v_D_u8 ];
      v_J_u32 = i_CanIndx_u32;
      /* loop over all points */
      for( ;; )
      {
        /* go to the next point in the direction */
        v_PointsCnt_u32--;
        v_NeighborList_ps = i_NeighborList_ps + v_J_u32;
        v_Temp_s8 = aGraph_F_isEmptyNeighbor_s8( *v_NeighborList_ps, v_D_u8 );
        if( ( v_PointsCnt_u32 == 0U ) || ( (sint32_t)v_Temp_s8 > 0 ) )
        {
          break;
        }

        v_J_u32 = aGraph_F_getNeighborIndx_u32( *v_NeighborList_ps, v_D_u8 );
      }

      if( v_PointsCnt_u32 != 0U )
      {
        *v_PartialDir_pu32 = v_D_u8;
        v_PartialDir_pu32++;
      }
    } /*if*/
  } /*for*/
}

/* ------------------------------------------------------------------------- */




static sint16_t f_getSeedNr_s16( uint8_t i_Dirbits_u8, uint8_t i_NX_u8, uint8_t i_NY_u8 )
{
  /* DD-ID: {B7D53BF4-2393-4ea5-935B-0C402E660803}*/
  sint16_t v_SeedNr_s8 =  - 1;
  switch( i_Dirbits_u8 )
  {
    case 6U:
      /* lower left */
      v_SeedNr_s8 = 0;
      break;
    case 12U:
      v_SeedNr_s8 = (sint16_t)i_NX_u8 - 1;
      break;
    case 24U:
      v_SeedNr_s8 = ( (sint16_t)i_NX_u8 - 1 ) + ( (sint16_t)i_NX_u8 *( (sint16_t)i_NY_u8 - 1 ) );
      break;
    case 18U:
      v_SeedNr_s8 = (sint16_t)i_NX_u8 *( (sint16_t)i_NY_u8 - 1 );
      break;
    default:
      v_SeedNr_s8 =  - 1;
      break;
  }
  return v_SeedNr_s8;
}

/* ------------------------------------------------------------------------- */

static sint8_t f_GridRowCol2_s8( uint32_t i_Indx_u32, uint16_t *o_Row_pu16, uint16_t *o_Col_pu16, 
                                 uint8_t i_NX_u8 )
{
  /* DD-ID: {88FA0147-0F20-41e1-90D3-D8564C3799CC}*/
  sint8_t v_ErrCode_s8;
  if( i_Indx_u32 > ( aAlgoECSrc_D_CORNER_NX_NY ) )
  {
    *o_Row_pu16 = 0U;
    *o_Col_pu16 = 0U;
    v_ErrCode_s8 = aAlgoECSrc_D_ERR_OUTOFRANGE;
  }
  else
  {
    *o_Row_pu16 = ( uint16_t )floor( ( float64_t )i_Indx_u32 / ( float64_t )i_NX_u8 );
    *o_Col_pu16 = ( uint16_t )i_Indx_u32 % i_NX_u8;
    v_ErrCode_s8 = aAlgoECSrc_D_SUCCESS;
  }
  return v_ErrCode_s8;
}

/* ------------------------------------------------------------------------- */

static sint8_t f_GridRowCol_s8( uint32_t i_Indx_u32, io_S_Pos_t *o_Grid_ps, uint8_t i_NX_u8 )
{ 
  /* DD-ID: {E843990B-6FCA-4854-8EE7-C096E2E215D6}*/
  sint8_t v_ErrCode_s8;
  if( i_Indx_u32 > ( aAlgoECSrc_D_CORNER_NX_NY ) )
  {
    o_Grid_ps->x_s16 = 0;
    o_Grid_ps->y_s16 = 0;
    v_ErrCode_s8 = aAlgoECSrc_D_ERR_OUTOFRANGE;
  }
  else
  {
    o_Grid_ps->y_s16 = (sint16_t)floor( ( float64_t )i_Indx_u32 / ( float64_t )i_NX_u8 );
    o_Grid_ps->x_s16 = (sint16_t)i_Indx_u32 % (sint16_t)i_NX_u8;
    v_ErrCode_s8 = aAlgoECSrc_D_SUCCESS;
  }
  return v_ErrCode_s8;
}

/* output unsigned short integer */
static uint16_t f_Round_u16( float32_t i_Number_f32 ) /* input float32_t number */

{
  /* DD-ID: {7E52596F-6785-45da-8B18-8CC6B7D17459}*/
  uint16_t v_Number_u16;

  float32_t v_NumberSub_f32 = i_Number_f32 - ( float32_t )floor( (float64_t)i_Number_f32 );
  v_Number_u16 = ( uint16_t )floor( (float64_t)i_Number_f32 );

  if( ( i_Number_f32 > 0.0F ) && ( v_NumberSub_f32 >= 0.5F ) )
  {
    v_Number_u16 = ( uint16_t ) floor( (float64_t)i_Number_f32 ) + 1U;
  }
  else if( ( i_Number_f32 < 0.0F ) && ( v_NumberSub_f32 > 0.5F ) )
  {
    v_Number_u16 = ( uint16_t )floor( (float64_t)i_Number_f32 ) + 1U;
  } else {
    /* Do Nothing */
  }


  return v_Number_u16;
}
/*  ---------------------------------- EOF -------------------------------------- */

