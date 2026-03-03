/*
 * US_ObjDetData.h
 *
 *  Created on: Aug 25, 2021
 *      Author: jonapais
 */

#ifndef US_OBJDETDATA_H_
#define US_OBJDETDATA_H_

#include "US_ObjDet_Global.h"

#define US_D_OD_FOVCALC_DEBUG   (1u)

#define US_D_OD_MAX_INDIRECT_SNR_PAIRS  ((US_D_PHYS_GRP_MAX * (US_MAX_NUM_SENSORS_PER_GRP - ONE) * TWO) >> ONE)

typedef struct US_S_SnrFOVCalc_s
{
#if US_D_OD_FOVCALC_DEBUG
    uint8_t   uSnrIdx1;         // Sensor #1
    uint8_t   uSnrIdx2;         // Sensor #2
    float32_t fThetaL;          // Left side triangle angle
    float32_t fThetaR;          // Right side triangle angle
    float32_t fThetaD;          // D (sensor distance) side triangle angle
    float32_t fSideL;           // Left side triangle length
    float32_t fSideR;           // Right side triangle length
#endif
    float32_t fHalfSnrDist;     // Half the distance between sensors.
    float32_t fSnrDistSq;       // Square of the distance between sensors.  Used to quickly detect obtuse point angles.
    float32_t fMinTotalDist;    // Min total distance an indirect echo must travel to be within FOV.
    float32_t fMinAreaSq;       // Min Square Area for a point to be in the FOV intersected by direct/indirect echoes.
    float32_t fMaxAreaSq;       // Max Square Area for a point to be in the FOV intersected by direct/indirect echoes.
    float32_t fSnrPairAng;      // Angle of sensor pair in vehicle coordinate system.
    float32_t fLeftFovMaxAng;   // Max angle of point (left sensor) to be within fov in sensor pair coord system.
    float32_t fLeftFovMinAng;   // Min angle of point (left sensor) to be within fov in sensor pair coord system.
    float32_t fRightFovMaxAng;  // Max angle of point (right sensor) to be within fov in sensor pair coord system.
    float32_t fRightFovMinAng;  // Min angle of point (right sensor) to be within fov in sensor pair coord system.
    float32_t fSqFovDirMinDist;
    float32_t fSqFovIndirMinDist;
    float32_t fSqFovDirX;
    float32_t fSqFovIndirX;
} US_S_SnrFOVCalc_t;

void UssOD_FovPreprocessing(void);
const US_S_SnrFOVCalc_t * UssOD_psGetFOVCalcInfo(void);

#endif /* SRC_US_OBJDETECT_US_OBJDETDATA_H_ */
