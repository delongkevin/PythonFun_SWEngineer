/*
 * US_ObjDetData.c
 *
 *  Created on: Aug 9, 2021
 *      Author: jonapais
 */

/*PRQA S 0816 ++ */
/*PRQA S 1011, 0857++ */
/* PRQA S 4462 ++  */ /*Conversion has no impact */
#include <math.h>
#include <stdio.h>
#include "US_ME_Typedefs_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_ObjDet_Global.h"
#include "US_ObjDetData.h"
#include "US_ObjDetTriang.h"
#include "US_SnrDrv_Global.h" /* why is this needed? */
#include "US_SnrCfg_Global.h"

#define US_D_SNR_FOV_OVERLAP    (0u)
#define US_D_SNR_FOV_MISMATCH   (1u)
#define US_D_SNR_OUT_OF_RANGE   (2u)
/* #define US_D_OD_VEH_WIDTH_OFFSET (10.0f) */

/*
 *  Information about the indirect sensors associated with every direct sensor
 */
static US_S_IndirSnrIdxList_t sIndirSnrList[US_D_PHYS_GRP_MAX][US_MAX_NUM_SENSORS_PER_GRP][TWO];

/* Field of view map for each sensor */
static US_S_SnrFOVCalc_t sSnrFOVCalc[US_D_OD_MAX_INDIRECT_SNR_PAIRS];

/* Angle pre-calculations for each sensor */
static US_S_SnrAngleCalcs_t sSnrAngleCalcs;

static uint8_t uNumSnrFovCalc; // Number of calculations for FOV List.

static void UssOD_PopulateFovCalcsForGroup(US_S_PlatPhysInfo_t *psPlatPhysInfo, uint8_t uGrpIdx);
static uint8_t UssOD_PopulateFovForSnrPair(uint8_t uSnrDirDataIdx, uint8_t uSnrIndirDataIdx);

static US_S_DrivingTubeInfo_t sDrivingTubeInfo;
/* ===========================================================================
 * Name:	 UssOD_psGetSnrAngleCalcs
 * Remarks:  DD-ID: {F916D69B-15E0-4f95-BEC6-CAFBA53254A9}
 * ===========================================================================*/

const US_S_SnrAngleCalcs_t * UssOD_psGetSnrAngleCalcs(void)
{
    return &sSnrAngleCalcs;
}

/*
 * TODO jp - Make function header comment
 */
/* ===========================================================================
 * Name:	 UssOD_PopulateFovForSnrPair
 * Remarks:  DD-ID: {79DD4415-0175-4e73-A3E5-95054E7298AD}
 * Req.-ID: 13514834
 * Req.-ID: 13515341
 * Req.-ID: 13515317
 * Req.-ID: 13515329
 * Req.-ID: 13515337
 * Req.-ID: 13515347
 * ===========================================================================*/
static uint8_t UssOD_PopulateFovForSnrPair(uint8_t uSnrDirDataIdx, uint8_t uSnrIndirDataIdx)
{
    float32_t fDeltaX;          // Distance between X's
    float32_t fDeltaY;          // Distance between Y's
#ifdef US_D_OD_USE_Z_COORD
    float32_t fDeltaZ;          // Distance between Z's
#endif
    float32_t fSnrDist;         // Distance between two sensors.
    float32_t fHalfSnrDist;     // Half the distance between two sensors.
    float32_t fMinTotalDist;    // Shortest indirect TOF distance that FOVs overlap.
    float32_t fThetaD;          // Theta opposite to sensor distance side of triangle.
    float32_t fThetaR;          // Angle on right side of triangle.
    float32_t fThetaL;          // Angle on left side of triangle.
    float32_t fThetaRfl;        // Theta Right minus 1/2 FOV
    float32_t fThetaLfr;        // Theta Right plus 1/2 FOV
    float32_t fRightFOV;        // Right sensor 1/2 FOV
    float32_t fLeftFOV;         // Left sensor 1/2 FOV
    float32_t fSideR = 0.0f;    // Side length opposite to right sensor theta.
    float32_t fSideL = 0.0f;    // Side length opposite to left sensor theta.
    float32_t fTriHeight;       // Storage for height of triangle height
    float32_t fArea;            // Area of a triangle
    float32_t fSnrAng;          // Angle of the sensor in vehicle coord system (autosar)
    float32_t fSnrPairAng;      // Angle of the sensor pair with respect to the vehcile coord system (autosar)
    float32_t fLeftFovMaxAng;   // Max angle of point (left sensor) to be within fov in sensor pair coord system.
    float32_t fLeftFovMinAng;   // Min angle of point (left sensor) to be within fov in sensor pair coord system.
    float32_t fRightFovMaxAng;  // Max angle of point (right sensor) to be within fov in sensor pair coord system.
    float32_t fRightFovMinAng;  // Min angle of point (right sensor) to be within fov in sensor pair coord system.
    float32_t fSqFovPdcMinDist;
    float32_t fSqFovPsmMinDist;
    float32_t fSqFovPdcX;
    float32_t fSqFovPsmX;
    bool_t  bIsDirInnerSensor;
    bool_t  bIsIndirInnerSensor;

    const uint8_t * uSnrType = UssCtrl_psGetSensorType();

    US_S_SensorsCfg_t *pSnrCfg	= US_SnrCfg_F_Get_SnrCfg();
    const US_S_Sensor_coordinate_t * pSnrCoord = NULL;

    if (pSnrCfg != NULL)
    {
        pSnrCoord = pSnrCfg->pSnrCoordinate;      /* Get the address of sensor coordinates in Calibration data */
    }
    if (pSnrCoord == NULL) 
    {
      return US_D_SNR_FOV_MISMATCH;      //check if data is exist
    }

    /* Calculate distance between sensors - order matters R - L*/
    fDeltaX = pSnrCoord[uSnrIndirDataIdx].fX - pSnrCoord[uSnrDirDataIdx].fX;
    fDeltaY = pSnrCoord[uSnrIndirDataIdx].fY - pSnrCoord[uSnrDirDataIdx].fY;

#ifdef US_D_OD_USE_Z_COORD
    fDeltaZ = pSnrCoord[uSnrIndirDataIdx].fZ - pSnrCoord[uSnrDirDataIdx].fZ;
    fSnrDist = sqrtf(fDeltaX * fDeltaX + fDeltaY * fDeltaY + fDeltaZ * fDeltaZ); // Calculate distance between sensors.
#else
    fSnrDist = sqrtf(fDeltaX * fDeltaX + fDeltaY * fDeltaY); // Calculate distance between sensors.
#endif


    bIsDirInnerSensor =    (bool_t)((uSnrDirDataIdx == US_D_SENSOR_FIR)
                        || (uSnrDirDataIdx == US_D_SENSOR_FIL)
                        || (uSnrDirDataIdx == US_D_SENSOR_RIR)
                        || (uSnrDirDataIdx == US_D_SENSOR_RIL));

    bIsIndirInnerSensor =   (bool_t)((uSnrIndirDataIdx == US_D_SENSOR_FIR)
                         || (uSnrIndirDataIdx == US_D_SENSOR_FIL)
                         || (uSnrIndirDataIdx == US_D_SENSOR_RIR)
                         || (uSnrIndirDataIdx == US_D_SENSOR_RIL));

    /*
     * Calculate FOV for sensors based on type PDM or PSM
     */

    // Calculate rectangular FOV values for both PDC and PSM sensors.
    if ((bIsDirInnerSensor ==(bool_t) ME_TRUE) && (bIsIndirInnerSensor == (bool_t)ME_TRUE))
    {
        fLeftFOV = (float32_t)SNR_PDC_INNER_FOV_2_RAD;
    }
    else
    {
        fLeftFOV = (float32_t)SNR_PDC_FOV_2_RAD;
    }

    fSqFovPdcMinDist = US_D_OD_SQARE_FOV_Y_DIST / sinf(fLeftFOV);
    fSqFovPdcX = fSqFovPdcMinDist * cosf(fLeftFOV);

    fSqFovPsmMinDist = (float32_t)(US_D_OD_SQARE_FOV_Y_DIST / sinf(SNR_PSM_FOV_2_RAD));
    fSqFovPsmX = (float32_t)(fSqFovPsmMinDist * cosf(SNR_PSM_FOV_2_RAD));

    //SNR_PDC_INNER_FOV_2_RAD


    // Direct FOV Calc - Direct is defines left FOV because Direct is always Left of Indirect
    if (uSnrType[uSnrDirDataIdx] == SNR_TYPE_PDC)
    {
        if ((bIsDirInnerSensor == (bool_t)ME_TRUE) && (bIsIndirInnerSensor == (bool_t)ME_TRUE))
        {
            fLeftFOV =(float32_t) SNR_PDC_FOV_2_RAD;
        }
        else
        {
            fLeftFOV = (float32_t)SNR_PDC_INNER_FOV_2_RAD;
        }
        sSnrFOVCalc[uNumSnrFovCalc].fSqFovDirMinDist = fSqFovPdcMinDist;
        sSnrFOVCalc[uNumSnrFovCalc].fSqFovDirX = fSqFovPdcX;
    }
    else
    {
        fLeftFOV =(float32_t) SNR_PSM_FOV_2_RAD;
        sSnrFOVCalc[uNumSnrFovCalc].fSqFovDirMinDist = fSqFovPsmMinDist;
        sSnrFOVCalc[uNumSnrFovCalc].fSqFovDirX = fSqFovPsmX;
    }


    // Indirect FOV Calc - Indirect always defines right FOV because Inidrect is always Right of Direct
    if (uSnrType[uSnrIndirDataIdx] == SNR_TYPE_PDC)
    {
        if ((bIsDirInnerSensor == (bool_t)ME_TRUE) && (bIsIndirInnerSensor == (bool_t)ME_TRUE))
        {
            fRightFOV = (float32_t)SNR_PDC_INNER_FOV_2_RAD;
        }
        else
        {
            fRightFOV = (float32_t)SNR_PDC_FOV_2_RAD;
        }

        sSnrFOVCalc[uNumSnrFovCalc].fSqFovIndirMinDist = fSqFovPdcMinDist;
        sSnrFOVCalc[uNumSnrFovCalc].fSqFovIndirX = -fSqFovPdcX + fSnrDist;
    }
    else
    {
        fRightFOV = (float32_t)SNR_PSM_FOV_2_RAD;
        sSnrFOVCalc[uNumSnrFovCalc].fSqFovIndirMinDist = fSqFovPsmMinDist;
        sSnrFOVCalc[uNumSnrFovCalc].fSqFovIndirX = -fSqFovPsmX + fSnrDist;
    }

    /* Slope angle of sensor pair, as viewed from leftmost sensor */
    fSnrPairAng = atan2f(fDeltaY, fDeltaX);  // Store for later coordinate transformations

    if (fSnrPairAng >= M_2PI)
    {
        fSnrPairAng -= M_2PI;
    }

    sSnrFOVCalc[uNumSnrFovCalc].fSnrPairAng = fSnrPairAng;

    fSnrAng =  sSnrAngleCalcs.fSnrAngInVehCoords_rad[uSnrDirDataIdx];  // Angle of left sensor in vehicle coordinate system.
    fSnrAng -= fSnrPairAng;                                            // Angle of left sensor in sensor-pair coordinate system.

    if (fSnrAng > M_2PI)
    {
        fSnrAng -= M_2PI;
    }

    fLeftFovMaxAng = fSnrAng + fLeftFOV;
    fLeftFovMinAng = fSnrAng - fLeftFOV;

    if (fLeftFovMaxAng >  M_PI)
    {
        fLeftFovMaxAng = (float32_t) M_PI;
    }

    if (fLeftFovMinAng < 0.0f)
    {
        fLeftFovMinAng = 0.0f;
    }

    fSnrAng =  sSnrAngleCalcs.fSnrAngInVehCoords_rad[uSnrIndirDataIdx];  // Angle of right sensor in vehicle coordinate system.
    fSnrAng -= fSnrPairAng;                                              // Angle of right sensor in sensor-pair coordinate system.

    if (fSnrAng > M_2PI)
    {
        fSnrAng -= M_2PI;
    }

    fRightFovMaxAng = fSnrAng + fRightFOV;
    fRightFovMinAng = fSnrAng - fRightFOV;

    if (fRightFovMaxAng > M_PI)
    {
        fRightFovMaxAng = (float32_t) M_PI;
    }

    if (fRightFovMinAng < 0.0f)
    {
        fRightFovMinAng = 0.0f;
    }

    /* Store pre-computed FOV angle checks, in sensor-pair coord system */
    sSnrFOVCalc[uNumSnrFovCalc].fLeftFovMaxAng  = fLeftFovMaxAng;
    sSnrFOVCalc[uNumSnrFovCalc].fLeftFovMinAng  = fLeftFovMinAng;
    sSnrFOVCalc[uNumSnrFovCalc].fRightFovMaxAng = fRightFovMaxAng;
    sSnrFOVCalc[uNumSnrFovCalc].fRightFovMinAng = fRightFovMinAng;


    /* Calculate the angles for the edges of the FOVs that face each other */
//    fThetaLfr = fSnrAng - fLeftFOV;      // Theta left, FOV right side.
//    fThetaRfl = fSnrAng + fRightFOV;     // Theta right, FOV left side.

    fThetaLfr = fLeftFovMinAng;      // Theta left, FOV right side.
    fThetaRfl = fRightFovMaxAng;     // Theta right, FOV left side.

    /*
     * Calculate the missing angle of the triangle, where FOVs meet.
     * Adjust into quadrant #1/2 so it's easier to do the trigonometry.
     * Reduction of: 180.0 - (fThetaL + (fThetaR + M_PI));
     * We don't even need to calculate the inner angles if not necessary.
     */
    fThetaD = fThetaRfl - fThetaLfr;

    /* Check if angle opposite to sensor distance is valid for FOV overlap */
    if (fThetaD > 0.0f && fThetaD < M_PI)
    {

        /* Create inner angles of FOV triangle */
        fThetaL = fThetaLfr;
        fThetaR =(float32_t)( M_PI - fThetaRfl);

        /* Rotate FOV triangle to quadrants 1 & 2, if necessary */
        if (fThetaL < 0.0f)
        {
            fThetaL -= fThetaL;
            fThetaR -= fThetaL;
        }

        if (fThetaR < 0.0f)
        {
            fThetaL -= fThetaR;
            fThetaR -= fThetaR;
        }

        /* Calculate right side length */
        if (fThetaD != M_PI_2) // Condition impossible.  Safety guard.
        {
            fSideR = (fSnrDist / sinf(fThetaD)) * sinf(fThetaR);
        }

        /* Calculate left side length */
        if (fThetaD != M_PI_2) // Condition impossible.  Safety guard.
        {
            fSideL = (fSnrDist / sinf(fThetaD)) * sinf(fThetaL);
        }

        /* Find minimum indirect TOF distance to overlap of FOV */
        fMinTotalDist = fSideR + fSideL;

        /* It is more useful to know the 1/2 distance than the distance */
        fHalfSnrDist = fSnrDist / 2.0f;

        /* Find minimum area of triangulation triangle to be within FOV overlap */
        if (((uint16_t) fSideR != ZERO) && ((uint16_t) fSideL != ZERO))
        {
            sSnrFOVCalc[uNumSnrFovCalc].fMinAreaSq = UssOD_CalcTriangAreaSq(fHalfSnrDist, (uint16_t) fSideR, (uint16_t) fSideL);
            if (sSnrFOVCalc[uNumSnrFovCalc].fMinAreaSq < 0.0f)
            {
                sSnrFOVCalc[uNumSnrFovCalc].fMinAreaSq = 0.0f;
            }
        }
        else
        {
            sSnrFOVCalc[uNumSnrFovCalc].fMinAreaSq = 0.0f;
        }

        /* Find maximum area of triangulation triangle to be within FOV overlap */
        fTriHeight = sqrtf(((float32_t) US_D_MAX_SENSOR_RANGE * (float32_t) US_D_MAX_SENSOR_RANGE) + (fHalfSnrDist * fHalfSnrDist));
        fArea =  0.5f * fHalfSnrDist * fTriHeight;
        sSnrFOVCalc[uNumSnrFovCalc].fMaxAreaSq = fArea * fArea;

        /*
         * Find angle of each sensor pair.
         * Will calculate considering left sensor as datum point.
         */
        sSnrFOVCalc[uNumSnrFovCalc].fSnrDistSq = fSnrDist * fSnrDist;

        /* Check for implausible detection and store data */
        if (fMinTotalDist < (float32_t) (US_D_MAX_SENSOR_RANGE << ONE))
        {
            /* Store distance between sensors for triangulation calculation */
            sSnrFOVCalc[uNumSnrFovCalc].fHalfSnrDist =  fHalfSnrDist;
            sSnrFOVCalc[uNumSnrFovCalc].fMinTotalDist = fMinTotalDist;
#if US_D_OD_FOVCALC_DEBUG
            /* Store FOV Diagnostics data */
            sSnrFOVCalc[uNumSnrFovCalc].fThetaD  = (float32_t)US_RAD2DEG(fThetaD);
            sSnrFOVCalc[uNumSnrFovCalc].fThetaL  = (float32_t)US_RAD2DEG(fThetaL);
            sSnrFOVCalc[uNumSnrFovCalc].fThetaR  = (float32_t)US_RAD2DEG(fThetaR);
            sSnrFOVCalc[uNumSnrFovCalc].uSnrIdx1 = uSnrDirDataIdx;
            sSnrFOVCalc[uNumSnrFovCalc].uSnrIdx2 = uSnrIndirDataIdx;
            sSnrFOVCalc[uNumSnrFovCalc].fSideR   = fSideR;
            sSnrFOVCalc[uNumSnrFovCalc].fSideL   = fSideL;
#endif

            return US_D_SNR_FOV_OVERLAP;
        }
        else
        {
            return US_D_SNR_OUT_OF_RANGE;
        }
    }

    return US_D_SNR_FOV_MISMATCH;
}

/*
 * TODO jp - Make function header comment
 */
/* ===========================================================================
 * Name:	 UssOD_PopulateFovCalcsForGroup
 * Remarks:  DD-ID: {C0696B46-A610-41af-9D7E-398F49DD7CA0}
 * ===========================================================================*/
static void UssOD_PopulateFovCalcsForGroup(US_S_PlatPhysInfo_t *psPlatPhysInfo, uint8_t uGrpIdx)
{
    uint8_t uSnrDirIdx;
    uint8_t uSnrIndirIdx;
    uint8_t uNumSnrsInGrp;
    uint8_t uSnrDirDataIdx;
    uint8_t uSnrIndirDataIdx;

    uNumSnrsInGrp = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;

    if (uNumSnrsInGrp  >= TWO)
    {
        /* Left most sensor has no left indirect */
        sIndirSnrList[uGrpIdx][ZERO][US_INDIR_LEFT].uIndirSnrDataIdx = US_D_OD_NO_INDIR_SNR;
        sIndirSnrList[uGrpIdx][ZERO][US_INDIR_LEFT].uFovCalcIdx = US_D_OD_NO_INDIR_SNR;

        /* Rightmost sensor has no right indirect */
        sIndirSnrList[uGrpIdx][uNumSnrsInGrp - ONE][US_INDIR_RIGHT].uIndirSnrDataIdx = US_D_OD_NO_INDIR_SNR;
        sIndirSnrList[uGrpIdx][uNumSnrsInGrp - ONE][US_INDIR_RIGHT].uFovCalcIdx = US_D_OD_NO_INDIR_SNR;

        /*
         * Compare each sensor with right neighbor, for FOV overlap and range of overlap.
         * Build table of indirects and closest overlap distances.
         * Physical groups MUST be defined from Left (autosar +Y) to Right (autosar -Y) or
         * function may not compare FOV overlap correctly.
         *
         */
        for (uSnrDirIdx = ZERO; uSnrDirIdx < (uNumSnrsInGrp - ONE); uSnrDirIdx++)     // Scan all sensor positions in group
        {

            /* Group index of indirect to the right of this sensor */
            uSnrIndirIdx = uSnrDirIdx + ONE;

            /* Get sensor data indices */
            uSnrDirDataIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uSnrDirIdx];
            uSnrIndirDataIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uSnrIndirIdx];

            /* Try to pair sensors */
            /*uint8_t uResult = */ (void)UssOD_PopulateFovForSnrPair(uSnrDirDataIdx, uSnrIndirDataIdx);

            /*
             * If there is a match each sensor can see each other, so store both,
             * but use the same data storage for info.
             *
             */
            #if 1
           /* if (ME_TRUE) uResult == US_D_SNR_FOV_OVERLAP)*/
            {
                /* Store the data for this sensor's indirect to the right */
                sIndirSnrList[uGrpIdx][uSnrDirIdx][US_INDIR_RIGHT].uIndirSnrDataIdx = uSnrIndirDataIdx;
                sIndirSnrList[uGrpIdx][uSnrDirIdx][US_INDIR_RIGHT].uFovCalcIdx = uNumSnrFovCalc;

                /* Store the same data for the indirect sensor's indirect to the left */
                sIndirSnrList[uGrpIdx][uSnrIndirIdx][US_INDIR_LEFT].uIndirSnrDataIdx = uSnrDirDataIdx;
                sIndirSnrList[uGrpIdx][uSnrIndirIdx][US_INDIR_LEFT].uFovCalcIdx = uNumSnrFovCalc;

                //Passive limit, but guarded for safety
                if (uNumSnrFovCalc < US_D_OD_MAX_INDIRECT_SNR_PAIRS)
                {
                    uNumSnrFovCalc++;
                }
            }
            #endif
            #if 0
            else
            {
                sIndirSnrList[uGrpIdx][uSnrDirIdx][US_INDIR_RIGHT].uIndirSnrDataIdx = US_D_OD_NO_INDIR_SNR;  /* PRQA S 2880 */ /* For future usage */
                sIndirSnrList[uGrpIdx][uSnrIndirDataIdx][US_INDIR_LEFT].uIndirSnrDataIdx = US_D_OD_NO_INDIR_SNR; /* PRQA S 1573 */ /* For future usage */
            }
            #endif
        }
    }
}

/*
 * TODO jp - Make function header comment
 */
/* ===========================================================================
 * Name:	 UssOD_FovPreprocessing
 * Remarks:  DD-ID: {02756674-458E-4318-A842-C9EAB643363E}
 * Req.-ID: 13515341
 * ===========================================================================*/
void UssOD_FovPreprocessing(void)
{
    uint8_t   uSnrIdx;
    uint8_t   uGrpIdx;
    float32_t fSnrAngDeg;
    float32_t fY;
    float32_t fX;

    US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();

    US_S_SensorsCfg_t *pSnrCfg	= NULL;
    const US_S_Sensor_coordinate_t * pSnrCoord = NULL;

    uNumSnrFovCalc = ZERO; // Reset array count

    /* Get the address of sensor coordinates in Calibration data */
    pSnrCfg = US_SnrCfg_F_Get_SnrCfg();			//Todo Sam

    if (pSnrCfg == NULL) 
    {
        return;
    }
    pSnrCoord = pSnrCfg->pSnrCoordinate;

    if (pSnrCoord == NULL) 
    {
        return;
    }

    sDrivingTubeInfo.fTubeEdgeY    = 0.0f;
    sDrivingTubeInfo.fRearBumperX  = 0.0f;
    sDrivingTubeInfo.fRearSnrClsX  = -1000.0f;
    sDrivingTubeInfo.fFrontBumperX = 0.0f;
    sDrivingTubeInfo.fFrontSnrClsX = 1000.0f;
    /*
     * Convert calibrations, in degrees, to radians.
     * Also, Calculate Theta for each sensor. (Move to quadrant 1 & 2).
     *
     */
    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {
        /* Make all sensor angles in [0, 2*PI] range. */
        fSnrAngDeg = pSnrCoord[uSnrIdx].fAngDeg;
        if (fSnrAngDeg < 0.0f)
        {
            fSnrAngDeg += 360.0f;
        }
        sSnrAngleCalcs.fSnrAngInVehCoords_rad[uSnrIdx] = (float32_t)US_DEG2RAD(fSnrAngDeg);  // Store angle of sensor in radians.

        /* Calculate vehicle width.  Use as vehicle corridor/tube/tunnel */
        /* If not installed, sensor coords will be zero.  Don't need to check. */
        fY = pSnrCoord[uSnrIdx].fY;
        fX = pSnrCoord[uSnrIdx].fX;

        /* Take absolute value of Y */
        if (fY < 0.0f)
        {
            fY = -fY;
        }

        if (fY > sDrivingTubeInfo.fTubeEdgeY)
        {
            sDrivingTubeInfo.fTubeEdgeY = fY;
        }

        if (fX < sDrivingTubeInfo.fRearBumperX)
        {
            sDrivingTubeInfo.fRearBumperX = fX;
        }

        if (fX > sDrivingTubeInfo.fFrontBumperX)
        {
            sDrivingTubeInfo.fFrontBumperX = fX;
        }

        if (   (fX > 0.0f)
            && (fX < sDrivingTubeInfo.fFrontSnrClsX))
        {
            sDrivingTubeInfo.fFrontSnrClsX = fX;
        }

        if (   (fX < 0.0f)
            && (fX > sDrivingTubeInfo.fRearSnrClsX))
        {
            sDrivingTubeInfo.fRearSnrClsX = fX;
        }
    }

    /* comment out sDrivingTubeInfo.fTubeEdgeY += US_D_OD_VEH_WIDTH_OFFSET; */

    for (uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++)     // Scan all groups
    {
        UssOD_PopulateFovCalcsForGroup(psPlatPhysInfo, uGrpIdx);
    }
}

/* ===========================================================================
 * Name:	 UssOD_psGetDrivingTubeInfo
 * Remarks:  DD-ID: {43175C56-BCC5-40cb-A647-ABC65E83BB1C}
 * ===========================================================================*/
US_S_DrivingTubeInfo_t * UssOD_psGetDrivingTubeInfo(void)
{
    return &sDrivingTubeInfo;
}

/* ===========================================================================
 * Name:	 UssOD_psGetIndirSnrList
 * Remarks:  DD-ID: {7AF35A87-0588-4f04-8EA8-7E75FBA9F625}
 * Req.-ID: 13519803
 * Req.-ID: 13519818
 * Req.-ID: 13519824
 * Req.-ID: 13519827
 * Req.-ID: 13519829
 * Req.-ID: 13519831
 * Req.-ID: 13519834
 * Req.-ID: 13519836
 * Req.-ID: 13519838
 * Req.-ID: 13519841
 * Req.-ID: 13519843
 * Req.-ID: 13519845
 * Req.-ID: 13519853
 * Req.-ID: 13519855
 * Req.-ID: 13519857
 * Req.-ID: 13519859
 * Req.-ID: 13519861
 * Req.-ID: 13519863
 * Req.-ID: 13519865
 * Req.-ID: 13519867
 * Req.-ID: 13519869
 * Req.-ID: 13519871
 * Req.-ID: 13519873
 * Req.-ID: 13519875
 * ===========================================================================*/
const US_S_IndirSnrIdxList_t * UssOD_psGetIndirSnrList(uint8_t uGrpIdx, uint8_t uGroupSnrIdx)
{
    return sIndirSnrList[uGrpIdx][uGroupSnrIdx];
}

/* ===========================================================================
 * Name:	 UssOD_psGetFOVCalcInfo
 * Remarks:  DD-ID: {F3B528E8-8CC0-4b95-A5E1-C3D7660D3F0E}
 * Req.-ID: 13409860
 * Req.-ID: 13427611
 * ===========================================================================*/
const US_S_SnrFOVCalc_t * UssOD_psGetFOVCalcInfo(void)
{
    return sSnrFOVCalc;
}
