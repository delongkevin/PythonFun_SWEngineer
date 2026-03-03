/*
 * US_ObjDetZone.h
 *
 *  Created on: Aug 9, 2021
 *      Author: jonapais
 */

#ifndef US_OBJDETZONE_H_
#define US_OBJDETZONE_H_

#define US_D_NUM_ZONE_STEPS     (SIXTEEN)

/* Range and Steps is in cm */
#define US_D_ZONE_MAX_RANGE     (550u)
#define US_D_ZONE_MIN_RANGE     (15u)
#define US_D_ZONE_SIZE_STEP     ((US_D_ZONE_MAX_RANGE - US_D_ZONE_MIN_RANGE) / US_D_NUM_ZONE_STEPS)

void UssOD_InitZoneData(void);
void UssOD_PerformZoneDetection(void);
void UssOD_CalcZoneDistances(void);
uint8_t *UssOD_paGetZoneInfo(void);

#endif /* US_OBJDETZONE_H_ */
