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

	$Header: corner_graph.c 1.8 2016/06/01 21:07:39IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:39IST $
	$Revision: 1.8 $

===================================================================================*/

/*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: corner_graph.c  $
 Revision 1.8 2016/06/01 21:07:39IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.7 2016/05/31 15:49:10CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes
 Revision 1.6.1.1 2016/04/12 19:29:00CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.6 2016/04/08 03:48:11EDT Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Adapt EOL to coding style
 Revision 1.5.1.1 2016/04/05 13:44:49MESZ Ziehl, Roland (SAI_RZieh) 
 Adapt EOL to coding style
 Revision 1.5 2016/03/14 13:04:11MEZ Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Renamed float constants to upper-case F
 Revision 1.4.1.1 2016/03/11 10:26:57MEZ Schulte, Michael (MEE_MiSch) 
 Renamed float constants to upper-case F
 Revision 1.4 2015/08/18 16:43:12CEST Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.3 2015/05/29 13:27:06CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:32CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:49CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.2 2013/07/25 11:09:45EDT Sebastian Pliefke (spliefke) 
 Remove warnings
 Revision 1.1 2013/07/09 16:51:58MESZ Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/corner/project.pj
 Revision 1.8 2012/07/16 19:34:36MESZ Marko Vico (mvico) 
 GetDirection method modified to calculate atan2
 Revision 1.7 2012/07/12 16:26:57EDT Marko Vico (mvico) 
 EoL algo update 4.2
 Revision 1.6 2012/06/26 12:35:07EDT Tina Behal (tbehal) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
 Revision 1.6 2011/10/14 12:30:47EDT Anupama Bhide (abhide) 
 QAC Misra C modifications
 Revision 1.5 2011/08/08 18:47:42EDT Anupama Bhide (abhide) 
 Misra C modifications - pclint
 Revision 1.4 2011/08/04 17:23:07EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.3 2011/08/04 10:53:05EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:27EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

#include "corner_graph.h"
#include <math.h>

/* --- Private Typedefinitions, Enumerations, Defines ------------------------ */

/* #pragma CHECK_MISRA("required") */
/* PRQA S 4800 EOF */
/* PRQA S 7003 EOF */
/* PRQA S 7008 EOF */
/* PRQA S 488 EOF */
/* PRQA S 489 EOF */
/* PRQA S 492 EOF */

/* --- Private Variables, Constants ------------------------------------------ */

/* --- Private Macros -------------------------------------------------------- */

/* --- Private Function Prototypes ------------------------------------------- */

static void f_getDirection_v( io_S_PosSub_t i_Can1_s,  /* candidate 1 */
                              io_S_PosSub_t i_Can2_s,  /* candidate 2 */
                              uint8_t *o_Dir_pu8,  /* ouput direction from 1->2 */
                              float32_t *v_Len_pf32 /* output distance between 1&2 */
);
static void f_getAllDirection_v( graph_S_NeighborList_t i_Neighbor_s, uint8_t *o_Dirbits_pu8 );
static float32_t f_getNeighborLen_f32( graph_S_NeighborList_t i_Neighbor_s, uint8_t i_Dir_u8 );
static void f_removeNeighborInfo_v( graph_S_NeighborList_t *b_Neighbor_ps, uint8_t i_Dir_u8 );


/* --- Public Function Definitions ---------------------------------------- */

/* initialize the neighboring graph */
void aGraph_F_InitialNeighboGraph_v( graph_S_NeighborList_t *o_Nl_ps )
{
  /* DD-ID: {EB48E9E5-5717-4aa9-AEFF-7F8D1C41CE44}*/
  uint32_t v_I_u32;
  uint8_t v_J_u8;
  /* input and output of the neighbor graph */
  graph_S_NeighborList_t *v_Nl_ps = o_Nl_ps;

  for( v_I_u32 = 0U; v_I_u32 < aAlgoECSrc_D_MAX_CORNER_NO; v_I_u32++ )
  {
    for( v_J_u8 = 0U; v_J_u8 < 4U; v_J_u8++ )
    {
      v_Nl_ps->neighbors_as[ v_J_u8 ].index_u32 = 0U;
      v_Nl_ps->neighbors_as[ v_J_u8 ].len_f32 =  - 1.0F;
    }
    v_Nl_ps++;
  }
}

/* build neighbor graph from canadiate list */
void aGraph_F_BuildNeighborGraph_v( const uint32_t i_CandidateCount_u32,  /* input number of candidates */
                                    const io_S_PosSub_t i_Candidates_as[],  /* input all candidates positions+value */
                                    graph_S_NeighborList_t *b_NeighborList_ps,  /* input and output of the neighbor graph */
                                    uint8_t * b_AdjMatrix_au8[aAlgoECSrc_D_MAX_CORNER_NO] /* ouput the adj matrix */
)
{
  /* DD-ID: {D86CE473-CCBF-420f-8420-E358AAC9800B}*/
  uint32_t v_I_u32;
  uint32_t v_J_u32;
  uint8_t v_K_u8;
  graph_S_NeighborList_t *v_nlCurrent_ps;
  float32_t v_Temp_f32;

  io_S_PosSub_t v_Candidate1_s;
  io_S_PosSub_t v_Candidate2_s;
  uint8_t v_Dir_u8;
  float32_t v_Len_f32 = 0.0F;

  uint32_t v_NeighborInx_u32 = 0U; /* for building adj matrix */

  /* for each candidate */
  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    v_Candidate1_s = i_Candidates_as [v_I_u32 ];
    v_nlCurrent_ps = b_NeighborList_ps + v_I_u32;

    for( v_J_u32 = 0U; v_J_u32 < i_CandidateCount_u32; v_J_u32++ )
    {
      v_Candidate2_s = *( i_Candidates_as + v_J_u32 );

      /* if sign of two candidates are same, not neighbor */
      if( ( ( v_Candidate1_s.v_f32 > 0.0F ) && ( v_Candidate2_s.v_f32 > 0.0F ) ) ||
          ( ( v_Candidate1_s.v_f32 < 0.0F ) && ( v_Candidate2_s.v_f32 < 0.0F ) ) )
      {
        ;  /* Do nothing  */
      }
      else
      {
        /* check the direction and len from cand1 to cand 2 */
        f_getDirection_v( v_Candidate1_s, v_Candidate2_s, &v_Dir_u8, &v_Len_f32 );

        v_Temp_f32 = f_getNeighborLen_f32( *v_nlCurrent_ps, v_Dir_u8 - 1U );

        if( ( (sint32_t)aGraph_F_isEmptyNeighbor_s8( *v_nlCurrent_ps, v_Dir_u8 - 1U ) > 0 ) ||
            ( v_Temp_f32 > v_Len_f32 ) )
        {
          v_nlCurrent_ps->neighbors_as[ v_Dir_u8 - 1U ].index_u32 = v_J_u32;
          v_nlCurrent_ps->neighbors_as[ v_Dir_u8 - 1U ].len_f32 = v_Len_f32;
        }
      }
    }

    /*adjmatrix*/
    for( v_K_u8 = 0U; v_K_u8 < D_Direction; v_K_u8++ )
    {
      if( (sint32_t)aGraph_F_isEmptyNeighbor_s8( *v_nlCurrent_ps, v_K_u8 ) < 0 )
      {
        v_NeighborInx_u32 = aGraph_F_getNeighborIndx_u32( *v_nlCurrent_ps, v_K_u8 );

        b_AdjMatrix_au8[ v_I_u32][ v_NeighborInx_u32 ] = ( v_K_u8 + 1U );
      }
    }

    /*  move to next candidate */
  }
}

/* filter graph for non-bidirectional links 
 * this includes unidirectional links
 * and some topological defects
 */
void aGraph_F_CheckBiDirection_v( uint32_t i_CandidateCount_u32,  /* input number of candidates */
                                  graph_S_NeighborList_t *b_NeighborList_ps,  /* input and output of the neighbor graph */
                                  uint8_t * b_AdjMatrix_apu8[ aAlgoECSrc_D_MAX_CORNER_NO ] /* output adj matrix */
)
{
  /* DD-ID: {C5965266-3E9E-4ab6-B777-89BB215CE278}*/
  uint32_t v_I_u32;
  uint32_t v_J_u32;
  sint8_t v_Dir1_s8;
  sint8_t v_Dir2_s8;

  graph_S_NeighborList_t *v_NeighborList_ps;

  uint8_t v_Opposite_au8[ D_Direction ] = 
  {
   3U, 4U, 1U, 2U
  };

  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    for( v_J_u32 = 0U; v_J_u32 < i_CandidateCount_u32; v_J_u32++ )
    {
      v_Dir1_s8 = ( sint8_t ) ( b_AdjMatrix_apu8[ v_I_u32][ v_J_u32 ] );
      v_Dir2_s8 = ( sint8_t ) ( b_AdjMatrix_apu8[ v_J_u32][ v_I_u32 ] );

      if( v_Dir1_s8 > 0 )
      {
        if( (sint32_t)v_Opposite_au8[ v_Dir1_s8 - 1 ] != v_Dir2_s8 ) 
        {
          /* non bidirectional link, remove */
          v_NeighborList_ps = b_NeighborList_ps + v_I_u32;
          v_NeighborList_ps->neighbors_as[ v_Dir1_s8 - 1 ].index_u32 = 0U;
          v_NeighborList_ps->neighbors_as[ v_Dir1_s8 - 1 ].len_f32 =  - 1.0F;
          b_AdjMatrix_apu8[ v_I_u32][ v_J_u32 ] = 0U;

          if( v_Dir2_s8 > 0 )
          {
            v_NeighborList_ps = b_NeighborList_ps + v_J_u32;

            v_NeighborList_ps->neighbors_as[ v_Dir2_s8 - 1 ].index_u32 = 0U;
            v_NeighborList_ps->neighbors_as[ v_Dir2_s8 - 1 ].len_f32 =  - 1.0F;
            b_AdjMatrix_apu8[ v_I_u32][ v_J_u32 ] = 0U;
          }
        }
      }
    }
  }
}

/*
 * Remove all points that are not members of circles of length 4;
 * starting at that point. This is a mark and sweep algorithm.
 */
void aGraph_F_FilterCircles_v( uint32_t i_CandidateCount_u32,  /* input number of candidates */
                               graph_S_NeighborList_t *b_NeighborList_ps,  /* input and output of the neighbor graph */
                               uint8_t * b_AdjMatrix_apu8[ aAlgoECSrc_D_MAX_CORNER_NO ] /* input and ouput the adj matrix */
)
{
  /* DD-ID: {D4BCF955-958F-4b2c-B909-C771876E1FFF}*/
  uint32_t v_I_u32;
  uint32_t v_J_u32;
  uint8_t v_D_u8;
  uint8_t v_W_u8;
  uint8_t v_K_u8;
  uint8_t v_Turns_au8[ 8 ] = 
  {
   2U, 3U, 4U, 1U, 4U, 1U, 2U, 3U
  };
  uint8_t v_Dir_u8;
  uint8_t v_RDir_u8; /* directions */
  uint8_t v_Valid_au8[ aAlgoECSrc_D_MAX_CORNER_NO ] = {0U};

  graph_S_NeighborList_t *v_NeighborList_ps; /* work pointer */

  /*     memset(v_Valid_s8, 0, (uint32_t)sizeof(uint8_t)*aAlgoECSrc_D_MAX_CORNER_NO); */

  /* Mark */
  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    /* for each candidate */
    for( v_D_u8 = 0U; v_D_u8 < D_Direction; v_D_u8++ )
    {
      /* for each direction */
      v_NeighborList_ps = b_NeighborList_ps + v_I_u32;
      if( (sint32_t)aGraph_F_isEmptyNeighbor_s8( *( v_NeighborList_ps ), v_D_u8 ) > 0 )
      {
        ;
      }
      else
      {
        for( v_W_u8 = 0U; v_W_u8 < 2U; v_W_u8++ )
        {
          /* for two directions */
          v_J_u32 = v_I_u32;
          v_Dir_u8 = v_D_u8 + 1U;

          for( v_K_u8 = 1U; v_K_u8 <= D_Direction; v_K_u8++ )
          {
            v_NeighborList_ps = b_NeighborList_ps + v_J_u32;
            v_J_u32 = aGraph_F_getNeighborIndx_u32( *v_NeighborList_ps, v_Dir_u8 - 1U );
            v_Dir_u8 = v_Turns_au8[ ( v_W_u8 *D_Direction ) + ( v_Dir_u8 - 1U ) ];

            v_NeighborList_ps = b_NeighborList_ps + v_J_u32;
            /* link fell out here, not a circle */
            if( (sint32_t)aGraph_F_isEmptyNeighbor_s8( *( v_NeighborList_ps ), v_Dir_u8 - 1U ) > 0 )
            {
              break;
            }
          }

          if( ( v_K_u8 == ( D_Direction + 1U ) ) && ( v_J_u32 == v_I_u32 ) )
          {
            /* correct circle */
            v_J_u32 = v_I_u32;
            v_Dir_u8 = v_D_u8 + 1U;

            /* mark all validate points */
            for( v_K_u8 = 1U; v_K_u8 <= D_Direction; v_K_u8++ )
            {
              *( v_Valid_au8 + v_J_u32 ) = 1U;
              v_NeighborList_ps = b_NeighborList_ps + v_J_u32;
              v_J_u32 = aGraph_F_getNeighborIndx_u32( *v_NeighborList_ps, v_Dir_u8 - 1U );
              v_Dir_u8 = v_Turns_au8[ ( v_W_u8 *D_Direction ) + ( v_Dir_u8 - 1U ) ];
            }
          }
        }
      }  
    }
  }

  /* sweep */
  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    /* for each candidate */
    /*         if( *( v_Valid_s8 + v_I_u32 ) == 1U ) { */
    if( (uint32_t)v_Valid_au8 [ v_I_u32 ] == 1U )
    {
      ; /* valid points move on */
    }
    else
    {
      for( v_D_u8 = 0U; v_D_u8 < D_Direction; v_D_u8++ )
      {
        /* for each direction */
        v_NeighborList_ps = b_NeighborList_ps + v_I_u32;
        if( (sint32_t)aGraph_F_isEmptyNeighbor_s8( *v_NeighborList_ps, v_D_u8 ) > 0 )
        {
          ;  /* Do nothing */
        }
        else
        {
          v_J_u32 = aGraph_F_getNeighborIndx_u32( *v_NeighborList_ps, v_D_u8 );

          v_RDir_u8 = b_AdjMatrix_apu8[ v_J_u32][ v_I_u32 ];

          b_AdjMatrix_apu8[ v_J_u32][ v_I_u32 ] = 0U;
          b_AdjMatrix_apu8[ v_I_u32][ v_J_u32 ] = 0U;

          f_removeNeighborInfo_v( b_NeighborList_ps + v_I_u32, v_D_u8 );
          f_removeNeighborInfo_v( b_NeighborList_ps + v_J_u32, v_RDir_u8 - 1U );
        }
      }
    }
  }
}


/* Filter graph for exceptionally long or short links
 * Due to the shearing of the rig
 * we handle left/right and up/down separately
 * remove the longer one as it points off board
 */
void aGraph_F_RemoveExceptionLink_v( uint32_t i_CandidateCount_u32,  /* input number of candidates */
                                     graph_S_NeighborList_t *b_NeighborList_ps,  /* input and output of the neighbor graph */
                                     uint8_t * b_AdjMatrix_apu8[ aAlgoECSrc_D_MAX_CORNER_NO ] /* output the adjacent matrix */
)
{
  /* DD-ID: {5C77432E-060E-4005-8652-55ABF80066EC}*/
  uint32_t v_I_u32;
  uint32_t v_J_u32;
  uint8_t v_D_u8;
  uint8_t v_Dirbits_u8;
  uint8_t v_Removebits_u8;
  float32_t v_Len1_f32;
  float32_t v_Len2_f32;
  float32_t v_LenMax_f32;

  uint8_t v_RDir_u8;

  graph_S_NeighborList_t *v_NeighborList_ps = b_NeighborList_ps; /* work pointer */

  for( v_I_u32 = 0U; v_I_u32 < i_CandidateCount_u32; v_I_u32++ )
  {
    v_NeighborList_ps = b_NeighborList_ps + v_I_u32;
    v_Dirbits_u8 = 0U;

    f_getAllDirection_v( b_NeighborList_ps[ v_I_u32 ], &v_Dirbits_u8 );

    v_Removebits_u8 = 0U;
    if( ( v_Dirbits_u8 & 0x14U ) == 0x14U )
    {
      /* up and down */
      v_Len1_f32 = v_NeighborList_ps->neighbors_as[ 1 ].len_f32;
      v_Len2_f32 = v_NeighborList_ps->neighbors_as[ 3 ].len_f32;

      v_LenMax_f32 = ( v_Len1_f32 > v_Len2_f32 ) ? v_Len1_f32 : v_Len2_f32;

      if( ( fabs((float64_t) (v_Len1_f32 - v_Len2_f32) ) / v_LenMax_f32 ) > D_LengthTh )
      {
        if( v_Len1_f32 > v_Len2_f32 )
        {
          v_Removebits_u8 = 4U;
        }
        else
        {
          v_Removebits_u8 = 16U;
        }
      }
    }
    if( ( v_Dirbits_u8 & 0x0Au ) == 0x0Au )
    {
      /* left and right */
      v_Len1_f32 = v_NeighborList_ps->neighbors_as[ 0 ].len_f32;
      v_Len2_f32 = v_NeighborList_ps->neighbors_as[ 2 ].len_f32;

      v_LenMax_f32 = ( v_Len1_f32 > v_Len2_f32 ) ? v_Len1_f32 : v_Len2_f32;

      if( ( fabs( (float64_t)(v_Len1_f32 - v_Len2_f32) ) / v_LenMax_f32 ) > D_LengthTh )
      {
        if( v_Len1_f32 > v_Len2_f32 )
        {
          v_Removebits_u8 += 2U;
        }
        else
        {
          v_Removebits_u8 += 8U;
        }
      }
    }

    for( v_D_u8 = 0U; v_D_u8 < D_Direction; v_D_u8++ )
    {
      if( ( v_Removebits_u8 & ( uint8_t )pow( (float64_t)2.0F, ((float64_t) v_D_u8 + 1.0F ) ) ) != 0U )
      {
        v_J_u32 = v_NeighborList_ps->neighbors_as[ v_D_u8 ].index_u32;

        v_RDir_u8 = b_AdjMatrix_apu8[ v_J_u32][ v_I_u32 ];
        b_AdjMatrix_apu8[ v_J_u32][ v_I_u32 ] = 0U;
        b_AdjMatrix_apu8[ v_I_u32][ v_J_u32 ] = 0U;

        f_removeNeighborInfo_v( b_NeighborList_ps + v_I_u32, v_D_u8 );
        f_removeNeighborInfo_v( b_NeighborList_ps + v_J_u32, v_RDir_u8 - 1U );
      }
    }
  }
}

/* check whether have a neighbor at one direction */
sint8_t aGraph_F_isEmptyNeighbor_s8( graph_S_NeighborList_t i_Neighbor_s,  /* graph */
                                     uint8_t i_Dir_u8 /* direction, 0-3 */
)
{
  /* DD-ID: {3F34E3A8-3E92-4c2b-B4C5-A0026E9BC2E5}*/
  sint8_t v_Res_s8;
  if( i_Neighbor_s.neighbors_as[ i_Dir_u8 ].len_f32 > 0.0F )
  {
    /* not empty */
    v_Res_s8 =  - 1;
  }
  else
  {
    v_Res_s8 = 1;
  }
  return v_Res_s8;
}

/* --- Private Function Definitions ------------------------------------------ */


/* get the index of one candidate */
uint32_t aGraph_F_getNeighborIndx_u32( graph_S_NeighborList_t i_Neighbor_s,  /* current node */
                                       uint8_t i_Dir_u8 /* direction, 0-3 */
)
{
  /* DD-ID: {01C51F39-94EA-4159-B797-67ADADFB69D5}*/
  return i_Neighbor_s.neighbors_as[ i_Dir_u8 ].index_u32;
}

/* get the distance between a candidate and its neighbor in one direction */
static float32_t f_getNeighborLen_f32( graph_S_NeighborList_t i_Neighbor_s,  /* current node */
                                       uint8_t i_Dir_u8 /* direction, 0-3*/
)
{
  /* DD-ID: {3308B100-94C3-42cf-B015-E7AAE182A979}*/
  return i_Neighbor_s.neighbors_as[ i_Dir_u8 ].len_f32;
}


/* get the direction and distance from 1 pixel to the 2nd pixel */
static void f_getDirection_v( io_S_PosSub_t i_Can1_s,  /* candidate 1 */
                              io_S_PosSub_t i_Can2_s,  /* candidate 2 */
                              uint8_t *o_Dir_pu8,  /* ouput direction from 1->2 */
                              float32_t *v_Len_pf32 /* output distance between 1&2 */
)
{
  /* DD-ID: {FA89621F-8BC9-498d-A183-53969BEEB9B9}*/
  float64_t v_Angle_f64;

  float32_t v_KernelAngle_f32 = 0.0F;
  float32_t v_AspectRatio_f32 = 0.0F;

  float32_t v_Can1X_f32 = i_Can1_s.x_f32;
  float32_t v_Can1Y_f32 = i_Can1_s.y_f32;
  float32_t v_Can2X_f32 = i_Can2_s.x_f32;
  float32_t v_Can2Y_f32 = i_Can2_s.y_f32;

  /* difference in horizon and vertical */
  float32_t v_DiffX_f32 = (v_Can2X_f32 - v_Can1X_f32);
  float32_t v_DiffY_f32 = (v_Can2Y_f32 - v_Can1Y_f32);

  *v_Len_pf32 = (float32_t) fabs((float64_t)v_DiffX_f32) +  (float32_t) fabs((float64_t)v_DiffY_f32);

  v_AspectRatio_f32 = 1.0F;
  v_Angle_f64 = ((atan2((float64_t)(v_AspectRatio_f32*v_DiffY_f32),(float64_t)v_DiffX_f32)*180.0)/aAlgoECSrc_D_PI) - v_KernelAngle_f32;

  if((-135.0<v_Angle_f64) && (v_Angle_f64<=-45.0) )
  {
    *o_Dir_pu8 = 2U;
  }
  else if( (-45.0<v_Angle_f64) && (v_Angle_f64<=45.0) )
  {
    *o_Dir_pu8 = 1U;
  }
  else if( (45.0<v_Angle_f64) && (v_Angle_f64<=135.0) )
  {
    *o_Dir_pu8 = 4U;
  }
  else
  {
    *o_Dir_pu8 = 3U;
  }

}

/* remove related info on one direction
 * in the neighboring list
 * len+index
 */
static void f_removeNeighborInfo_v( graph_S_NeighborList_t *b_Neighbor_ps,  /* graph */
                                    uint8_t i_Dir_u8 /* direction, 0-3 */
)
{
  /* DD-ID: {45A4656F-D33E-487e-A84C-36A8242D2DCB}*/
  b_Neighbor_ps->neighbors_as[ i_Dir_u8 ].index_u32 = 0U;
  b_Neighbor_ps->neighbors_as[ i_Dir_u8 ].len_f32 =  - 1.0F;
}

/* get the direction info for one pixel */
static void f_getAllDirection_v( graph_S_NeighborList_t i_Neighbor_s, uint8_t *o_Dirbits_pu8 )
{
  /* DD-ID: {EF7617BB-C1A8-4d41-9E37-7F85E9FA9BE6}*/
  uint8_t v_D_u8;
  float32_t v_Temp_f32;

  for( v_D_u8 = 0U; v_D_u8 < D_Direction; v_D_u8++ )
  {
    if( (sint32_t)aGraph_F_isEmptyNeighbor_s8( i_Neighbor_s, v_D_u8 ) < 0 )
    {
      v_Temp_f32 = (float32_t)pow( (float64_t)2.0F, ( (float64_t)v_D_u8 + 1.0F ) );
      (*o_Dirbits_pu8) = (*o_Dirbits_pu8) + (uint8_t)v_Temp_f32;
    }
  }
}
/* ---------------------------------- EOF -------------------------------------- */
