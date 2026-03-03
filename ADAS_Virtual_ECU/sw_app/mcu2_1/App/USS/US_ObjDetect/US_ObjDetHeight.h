/*
 * US_ObjDetHeight.h
 *
 *  Created on: Nov 28, 2023
 *      Author: jwr3 & Jason Zalev
 */

#ifndef US_OBJDETHEIGHT_H_
#define US_OBJDETHEIGHT_H_

#include "US_ME_Typedefs_Global.h"

#define US_D_OD_HGEOM_N_SIGMA_DIV 3u
#define US_D_OD_HGEOM_SIGMA_C 0u /* center */
#define US_D_OD_HGEOM_SIGMA_L 1u /* left */
#define US_D_OD_HGEOM_SIGMA_R 2u /* right */
#if (US_D_ENABLE_OVRWR_CANDBG == ME_TRUE)
extern uint8_t   g_fGeomStats_ConfThresh_slow ; 
extern uint8_t   g_fGeomStats_ConfThresh_fast ; 
extern US_D_LAUD_QUAL float32_t g_fGeomStats_ConfThresh_kph_slow; 
extern US_D_LAUD_QUAL float32_t g_fGeomStats_ConfThresh_kph_fast; 

/* Functions shared with other OD files */
void UssOD_UpdateHeightGeomStats(uint8_t uGrpIdx, uint8_t uNumCurPnts);

uint8_t UssOD_bIsLowObject(uint8_t u_phys_grp); 

void UssOD_setArcSignal(uint32_t arcs_from_feature, uint8_t current_arc) ;
uint8_t UssOD_bIsLowObjectFront(void);
#endif
#endif /* US_OBJDETHEIGHT_H_ */