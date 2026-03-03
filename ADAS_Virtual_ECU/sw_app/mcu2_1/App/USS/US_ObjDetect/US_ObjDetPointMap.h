/*
 * US_ObjDetPointMap.h
 *
 *  Created on: Aug 12, 2021
 *      Author: jonapais
 */

#ifndef US_OBJDETPOINTMAP_H_
#define US_OBJDETPOINTMAP_H_
#include "US_ObjDet_Global.h"
#include "US_ComOutputBuffer_Global.h"

#define US_D_OD_UNUSED_OUTPUT_IDX  (0xFFu)

void UssOD_PopulatePointMap(void);
US_S_PointMap_t *UssOD_paGetPointMap(void);
#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE
US_S_PntDebugInfo_t *UssOD_paGetDebugPntInfo(void);
#endif
#endif /* US_OBJDETPOINTMAP_H_ */
