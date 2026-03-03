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
	
	$Header: corner_graph.h 1.9 2016/06/01 21:07:52IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:52IST $
	$Revision: 1.9 $
	
  ===================================================================================*/

/*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: corner_graph.h  $
 Revision 1.9 2016/06/01 21:07:52IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.8 2016/05/31 15:50:57CEST Rasool, Muzammil (MEE_MRASOO) 
 QAC changes.
 Revision 1.6.1.1 2016/04/12 19:31:07CEST Wang, Hongtao (E32953) 
 QAC warning removed
 Revision 1.6 2016/04/08 03:48:17EDT Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Adapt EOL to coding style
 Revision 1.5.1.1 2016/04/05 13:44:44MESZ Ziehl, Roland (SAI_RZieh) 
 Adapt EOL to coding style
 Revision 1.5 2016/03/14 13:04:05MEZ Dehm, Timo (MEE_TDEHM) 
 Merge since:
 Renamed float constants to upper-case F
 Revision 1.4.1.1 2016/03/11 10:26:59MEZ Schulte, Michael (MEE_MiSch) 
 Renamed float constants to upper-case F
 Revision 1.4 2015/08/18 16:43:24CEST Rasool, Muzammil (MEE_MRASOO) 
 Removed compiled warnings.
 Revision 1.3 2015/05/29 13:27:06CEST Rasool, Muzammil (MEE_MRASOO) 
 Eol with new MECL integrated.
 Revision 1.2 2015/02/04 10:57:33CET Rasool, Muzammil (MEE_MRASOO) 
 Eol Results are correct now.
 All 32-bit Floating-point declrations have been replaced with 64-bit floating-point declrations.
 ARM FPU internally calculates floating point operations with 64-bit, 
 and adds inaccuracices when rounds it down to 32-bit.
 Revision 1.1 2015/01/21 14:46:50CET Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.1 2013/07/09 10:51:59EDT Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/corner/project.pj
 Revision 1.6 2012/06/26 18:35:24MESZ Tina Behal (tbehal) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
 Revision 1.6 2011/08/12 13:03:55EDT Ali Ahmed (aahmed) 
 Code cleanup.
 Revision 1.5 2011/08/08 18:47:45EDT Anupama Bhide (abhide) 
 Misra C modifications - pclint
 Revision 1.4 2011/08/04 17:23:27EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.3 2011/08/04 11:07:42EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:32EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */

/* Some QACPP/C++-rules cannot be followed, because the header is used for both C and C++,
 * hence the following rules are deactivated: */
/* PRQA S 2400 EOF */ /* functions in global namespace */
/* PRQA S 1021 EOF */ /* use of macros */
#ifndef CORNER_GRAPH_H
#define CORNER_GRAPH_H

#include "local_extrema.h"


/* --- Public Typedefinitions, Enumerations, Defines ---------------------- */
/* PRQA S 1025 1 */  /* C code */
#define D_Direction 4U            /* 4 neighborhood */
/* PRQA S 1020 3 */  /* C code */
#define D_LengthTh 0.5F           /* length threshold */

/* neighbor for each candidate 
 * an index + len
 */
typedef struct
{
  uint32_t index_u32;
  float32_t len_f32;
} graph_S_Neighbor_t;

/* neighbor linked list 
 * each node has four neighbors
 * each neighbor has two variables: index+len
 */
typedef struct Node_s
{
  graph_S_Neighbor_t neighbors_as[ 4 ];
} graph_S_NeighborList_t;


/* --- Public Variables, Constants ---------------------------------------- */

/* --- Public Macros ------------------------------------------------------ */

/* --- Public Function Prototypes ----------------------------------------- */

sint8_t aGraph_F_isEmptyNeighbor_s8( graph_S_NeighborList_t i_Neighbor_s, uint8_t i_Dir_u8 );

uint32_t aGraph_F_getNeighborIndx_u32( graph_S_NeighborList_t i_Neighbor_s, uint8_t i_Dir_u8 );

void aGraph_F_InitialNeighboGraph_v( graph_S_NeighborList_t *o_Nl_ps );

void aGraph_F_BuildNeighborGraph_v( const uint32_t i_CandidateCount_u32,  /* input number of candidates */
                                    const io_S_PosSub_t i_Candidates_as[],  /* input all candidates positions+value */
                                    graph_S_NeighborList_t *b_NeighborList_ps,  /* input and output of the neighbor graph */
                                    uint8_t * b_AdjMatrix_au8[aAlgoECSrc_D_MAX_CORNER_NO] /* ouput the adj matrix */
                                    );

void aGraph_F_CheckBiDirection_v( uint32_t i_CandidateCount_u32,  /* input number of candidates */
                                  graph_S_NeighborList_t *b_NeighborList_ps,  /* input and output of the neighbor graph */
                                  uint8_t * b_AdjMatrix_apu8[ aAlgoECSrc_D_MAX_CORNER_NO ] /* output adj matrix */
);
void aGraph_F_FilterCircles_v( uint32_t i_CandidateCount_u32,  /* input number of candidates */
                               graph_S_NeighborList_t *b_NeighborList_ps,  /* input and output of the neighbor graph */
                               uint8_t* b_AdjMatrix_apu8[ aAlgoECSrc_D_MAX_CORNER_NO ] /* input and ouput the adj matrix */
);
void aGraph_F_RemoveExceptionLink_v( uint32_t i_CandidateCount_u32,  /* input number of candidates */
                                     graph_S_NeighborList_t *b_NeighborList_ps,  /* input and output of the neighbor graph */
                                     uint8_t* b_AdjMatrix_apu8[ aAlgoECSrc_D_MAX_CORNER_NO ] /* output the adjacent matrix */
);
/* === End of Header File ==================================================== */

#endif /* local_extrema.h */
/*  ---------------------------------- EOF -------------------------------------- */
