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
	
	$Header: largest_component.h 1.3 2016/06/01 21:07:48IST Muzammil Rasool(Disabled) (MEE_MRASOO) draft  $       
	$Author: Muzammil Rasool(Disabled) (MEE_MRASOO) $
	$Date: 2016/06/01 21:07:48IST $
	$Revision: 1.3 $
	
  ===================================================================================*/

 /*
 MKS change history (will be updated automatically by MKS, do not change manually)
 $Log: largest_component.h  $
 Revision 1.3 2016/06/01 21:07:48IST Muzammil Rasool(Disabled) (MEE_MRASOO) 
 Naming Conventions related changes  in C files.
 Revision 1.2 2016/04/27 14:39:13CEST Dehm, Timo (MEE_TDEHM) 
 update QACPP
 Revision 1.1.2.1 2016/04/13 10:37:31MESZ Blinn, Frank (SAI_FrBli) 
 Removing QACPP wanings
 Revision 1.1 2015/01/21 14:46:52MEZ Rasool, Muzammil (MEE_MRASOO) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra2/L2G101_Chrysler_BEV/Software/Hydra2/Source_Code/L2G101_RU_MY16/Xilinx_Zynq_PS/App/code/EOLIntgr/eol/project.pj
 Revision 1.1 2013/07/09 10:52:07EDT Sebastian Pliefke (spliefke) 
 Initial revision
 Member added to project /Projects/ReversAid/Hydra/Multicamera/Ford_360_L21134/Software/Calibration/00 Engineering/25_PreEmbedding/src/corner/project.pj
 Revision 1.5 2012/06/26 18:37:31MESZ Tina Behal (tbehal) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/_generic/code/own/app/algo/ec/src/project.pj
 Revision 1.5 2011/08/12 13:03:53EDT Ali Ahmed (aahmed) 
 Code cleanup.
 Revision 1.4 2011/08/04 17:23:23EDT Ali Ahmed (aahmed) 
 EOL optimization related changes.
 Revision 1.3 2011/08/04 11:07:41EDT Sala Annamalai (sannamalai) 
 added official template
 Revision 1.1 2011/03/25 15:37:32EDT Ron Zibman (rzibman) 
 Initial revision
 Member added to project /D1175/20_Engineering/30_Software_DSP/20_SwConstruction/30_BVC/templates/project.pj
 */


#ifndef LARGE_COMPONENT_H
#define LARGE_COMPONENT_H

#include "corner_graph.h"

/* --- Public Typedefinitions, Enumerations, Defines ---------------------- */

/* --- Public Variables, Constants ---------------------------------------- */

/* --- Public Macros ------------------------------------------------------ */

/* --- Public Function Prototypes ----------------------------------------- */

sint8_t aLComp_F_checkSingleCorner_s8(const graph_S_NeighborList_t *i_NeighborList_ps,  /* neighbor graph */
                                      uint32_t i_CandidateCount_u32,  /* no of candidates */
                                      uint32_t *i_CornerData_pu32,  /* corner data */
                                      sint32_t *o_PointNr_ps32,  /* counting no of canadidates */
                                      uint8_t i_NX_u8, uint8_t i_NY_u8 );

uint8_t aLComp_F_countEachComponent_v( graph_S_NeighborList_t b_NeighborList_as[],  /* neighbor graph */
                                        uint32_t i_CandidateCount_u32,  /* no of candidates */
                                        uint32_t o_CornerData_au32[],  /* corner data */
                                        uint8_t i_NX_u8, uint8_t i_NY_u8 );

sint8_t aLComp_F_regSubpixels_s8( sint32_t *i_PointNr_ps32,  /* no of canadiates in each row */
                                  io_S_PosSub_t *o_CanPosSub_ps,  /* candidate pos list */
                                  uint32_t *o_CandidateCount_pu32,  /* no of candidate */
                                  io_S_Pos_t *o_Grid_ps,  /* candidate grid list */
                                  uint8_t i_NX_u8, uint8_t i_NY_u8 );

sint8_t aLComp_F_seeComplete_s8( graph_S_NeighborList_t *i_NeighborList_ps,  /* neighbor graph */
                                uint16_t i_ImgX_u16, uint16_t i_ImgY_u16, uint32_t i_CandidateCount_u32,  /* no of candidates */
                                io_S_PosSub_t *i_Candidates_ps,  /* candidate pos list */
                                uint32_t b_CornerData_au32[],  /* corner data */
                                uint8_t i_NX_u8, uint8_t i_NY_u8 );

    /* === End of Header File ==================================================== */
#endif /* largest_component.h */
/*  ---------------------------------- EOF -------------------------------------- */
