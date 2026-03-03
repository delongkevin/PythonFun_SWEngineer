/*
 * US_ObjDetMinDist.h
 *
 *  Created on: Sep 16, 2021
 *      Author: jonapais
 */

#ifndef US_OBJDETMINDIST_H_
#define US_OBJDETMINDIST_H_

#include "US_ME_Typedefs_Global.h"

void UssOD_InitPntMinDist(void);
void UssOD_FindFiltGrpMinDistances(uint8_t uGrpIdx);
void UssOD_FindFiltMinDistances(void);
void UssOD_FindFiltMidDistances(uint8_t uGrpIdx);

#endif /* US_OBJDETMINDIST_H_ */
