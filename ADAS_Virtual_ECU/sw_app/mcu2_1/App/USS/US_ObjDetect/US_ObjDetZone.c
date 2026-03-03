/*
 * US_ObjDetZone.c
 *
 *  Created on: Aug 9, 2021
 *      Author: jonapais
 */

#include "US_ME_Typedefs_Global.h"
#include "US_Platform_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_ObjDet_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SysMgr_Global.h"
#include "US_ObjDetZone.h"
#include "US_ObjDetTriang.h"

#if (USS_FEATURE_ZONE_INFO == US_STD_ON)


#define US_D_OD_ZONE_INDEX_UNDERFLOW  (0xFFu)
#define US_D_NO_SECTOR_MATCH  (0xFFu)

#define US_D_ZONE_CALC_DEBUG_DATA_ENABLE (ME_FALSE)

/*
 * Parameters for this function \TODO jp - Move to cals
 */
/* Zone confidence */
#define US_D_ZONE_MIN_PNT_CONF  (50u)
#if 0
#define US_D_ZONE_MIN_PNT_CONF_MOVING (30u) 
#endif

#define US_D_ZONE_ENABLE_LOW_CONF_PNTS  (ME_FALSE)
#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
    #define US_D_ZONE_LOW_MIN_PNT_CONF  (18u)
#else
    #ifdef US_D_ZONE_MIN_PNT_CONF_MOVING
        #define US_D_ZONE_LOW_MIN_PNT_CONF  US_D_ZONE_MIN_PNT_CONF_MOVING
    #else
        #define US_D_ZONE_LOW_MIN_PNT_CONF  US_D_ZONE_MIN_PNT_CONF
    #endif
#endif



/* Zone Hysteresis timings */
#define US_D_ZONE_TO_HIGHER_ZONE_DIST_CM  (10u)
#define US_D_ZONE_TO_HIGHER_ZONE_HYST_MS  (480u)
#define US_D_ZONE_DIST_REMOVAL_HYST_MS    (960u)
#if 0
#define US_D_ZONE_TO_HIGHER_ZONE_HYST_MS  (960u) 
#define US_D_ZONE_DIST_REMOVAL_HYST_MS    (1920u) 
#endif
#define US_D_ZONE_TO_HIGHER_ZONE_HYST_NOISY_MS  (960u)
#define US_D_ZONE_DIST_REMOVAL_HYST_NOISY_MS    (1920u)

#if 0
1 kph = 27.78 cm/s. 
#endif
/*Given 25 samples/sec, vehicle movement of 1 kph causes 1.11 cm of delta between samples. */
#if 0
#define US_D_ZONE_LOW_CONF_SPEED_FACTOR   (1.11f)
#endif

static uint8_t aZoneInfo[US_D_MAX_SECTORS_TOTAL];
static uint16_t uZoneMinDist[US_D_MAX_SECTORS_TOTAL];
#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
static uint16_t uZoneLowConfMinDist[US_D_MAX_SECTORS_TOTAL];
#endif
static uint16_t uPrevZoneMinDist[US_D_MAX_SECTORS_TOTAL];
static uint32_t uLastZoneMinDistTime_ms[US_D_MAX_SECTORS_TOTAL];
#endif

static uint16_t uNumCalSectors = ZERO;
static uint16_t uTotalNumSectors = ZERO;


/*
 * The first bound in each list is ZONE 1.
 * If a distance exceeds the final range in the list, then
 * the ZONE_NO_OBSTACLE is stored for this sensor.
 */
 /*
*/
/* Customer zone definition + 8cm offset to front/rears */
static US_S_ZoneBounds_t *pZoneBounds = NULL;

/*
 * This data is now in CAL data, to be assigned in init.
 */
static US_S_SectorEdge_t *pSectorEdgeCal = NULL;

#if (USS_FEATURE_ZONE_INFO == US_STD_ON)
/*
 * Storage for points and standard equations of the left and bottom lines.
 * Equation of left line for each sector matches equation of right line of next sector.
 */
typedef struct US_S_SectorEdgeLines_s
{
#if US_D_ZONE_CALC_DEBUG_DATA_ENABLE == ME_TRUE
    sint16_t  iLeftX;           /*For debug only. */
    sint16_t  iLeftY;           /*For debug only. */
    sint16_t  iLeftFarX;        /*For debug only. */
    sint16_t  iLeftFarY;        /*For debug only. */
#endif

    float32_t fLeftA;
    float32_t fLeftB;
    float32_t fLeftC;
    float32_t fBtmA;
    float32_t fBtmB;
    float32_t fBtmC;
    float32_t fTopA;
    float32_t fTopB;
    float32_t fTopC;
    float32_t fDistCalcDenom;

} US_S_SectorEdgeLines_t;

#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
static US_S_SectorEdgeLines_t sSectorEdgeLines[US_D_MAX_NUM_SECTORS_CHK];
#endif

/*===========================================================================
 * \brief Calculate zone detection from object list.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_SectorPreprocessing
 * Remarks:  DD-ID: {E89BD061-770C-47a1-9471-FD56932A7F22}
 * Req.-ID: 13517239
 * Req.-ID: 13517539
 * Req.-ID: 13517564
 * Req.-ID: 13517570
 * Req.-ID: 13517580
 * Req.-ID: 13517596
 * ===========================================================================*/
void UssOD_SectorPreprocessing(void)
{
    US_S_SectorEdgeLines_t * psSectorEdgeLine;

    /* Debugging data only */
    float32_t fLeftX;
    float32_t fLeftY;
    /* End debugging data only */

    float32_t fDeltaX;
    float32_t fDeltaY;
    float32_t fLeftAngInRad;
    uint16_t  uCalCnt;
    uint8_t   uSecIdx;
    uint8_t   uSecRightIdx;
    uint8_t   uSecLeftIdx;
	
	uNumCalSectors = ZERO;
	uTotalNumSectors = ZERO;

    pSectorEdgeCal = (US_S_SectorEdge_t*) US_SnrCfg_Get_SectorEdgeCfg(&uCalCnt);
    if(pSectorEdgeCal == NULL) 
    {
          return;
    }
    if (uCalCnt != ZERO)
    {
        uNumCalSectors =(uint16_t) ( uCalCnt / sizeof(US_S_SectorEdge_t) - ONE);
        uTotalNumSectors = uNumCalSectors << ONE;
    }
    else
    {
        return;
    }

    /* Loop through the sectors on the left side of the vehicle */
    for (uSecIdx = ZERO; uSecIdx < uNumCalSectors; uSecIdx ++)
    {
        /* Calculate left/right indices to get full sector geometry */
        uSecRightIdx = uSecIdx;
        uSecLeftIdx = uSecRightIdx + ONE;

        /* Get pointer to the right edge of the sector */
        psSectorEdgeLine =  &sSectorEdgeLines[uSecIdx];

        /* Calculate vector from bottom-left point to bottom-right point */
        fLeftX = US_D_MM_TO_CM((float32_t)  pSectorEdgeCal[uSecLeftIdx].iX);
        fLeftY = US_D_MM_TO_CM((float32_t)  pSectorEdgeCal[uSecLeftIdx].iY);

        /*For debug purposes only. */
#if US_D_ZONE_CALC_DEBUG_DATA_ENABLE == ME_TRUE
        psSectorEdgeLine->iLeftX = (sint16_t) fLeftX;
        psSectorEdgeLine->iLeftY = (sint16_t) fLeftY;
#endif

        /* Form "bottom" line vector */
        fDeltaX = US_D_MM_TO_CM((float32_t) pSectorEdgeCal[uSecRightIdx].iX) - fLeftX;
        fDeltaY = US_D_MM_TO_CM((float32_t) pSectorEdgeCal[uSecRightIdx].iY) - fLeftY;

        /* Cleaner data */
        if (fabsf(fDeltaY) < US_D_OD_EPSILON)
        {
            fDeltaY = 0.0f;
        }

        if (fabsf(fDeltaX) < US_D_OD_EPSILON)
        {
            fDeltaX = 0.0f;
        }

        /* Bottom line in standard form, coefficients: A,B,C */
        psSectorEdgeLine->fBtmA = -fDeltaY;
        psSectorEdgeLine->fBtmB =  fDeltaX;
        psSectorEdgeLine->fBtmC = -(psSectorEdgeLine->fBtmA * fLeftX + psSectorEdgeLine->fBtmB * fLeftY);

        /* Calculate the denominator of the distance formula for zone calcs */
        psSectorEdgeLine->fDistCalcDenom = sqrtf(fDeltaY * fDeltaY + fDeltaX * fDeltaX);

        /* Calculate angle of left side line, coefficients: A,B,C  */
        fLeftAngInRad = (float32_t) US_DEG2RAD(pSectorEdgeCal[uSecLeftIdx].fAngle);

        fDeltaX = (float32_t) pSectorEdgeCal[uSecLeftIdx].uDepthR * cosf(fLeftAngInRad);
        fDeltaY = (float32_t) pSectorEdgeCal[uSecLeftIdx].uDepthR * sinf(fLeftAngInRad);

        /*
         * Using left point and angle, calculate left far point of sector
         * Note we don't actually need this data, just for diagnostics purposes
         */

        /*For debug purposes only. */
#if US_D_ZONE_CALC_DEBUG_DATA_ENABLE == ME_TRUE
        psSectorEdgeLine->iLeftFarX = (sint16_t) (fLeftX + fDeltaX);
        psSectorEdgeLine->iLeftFarY = (sint16_t) (fLeftY + fDeltaY);
#endif

        /* Side line in standard form */
        psSectorEdgeLine->fLeftA = -fDeltaY;
        psSectorEdgeLine->fLeftB =  fDeltaX;
        psSectorEdgeLine->fLeftC = -(psSectorEdgeLine->fLeftA * fLeftX + psSectorEdgeLine->fLeftB * fLeftY);
	}
}

/*===========================================================================
 * \brief Find sector index for given point in vehicle coordinate system.
 *
 * \param sint16_t iX
 * \param sint16_t iY
 * \param sint16_t uint8_t uCurSecIdx  0xFF = No Assigned Sector
 * \return uint8_t The sector number corresponding with point.
 * \remarks No sector found returned on no match (US_D_NO_SECTOR_MATCH)
 */
/* ===========================================================================
 * Name:	 UssOD_uFindSectorIdx
 * Remarks:  DD-ID: {ED388387-2544-47dc-8168-3296124AEE9A}
 * Req.-ID: 18237286
 * Req.-ID: 18237290
 *
 * ===========================================================================*/
uint8_t UssOD_uFindSectorIdx(float32_t fX, float32_t fY, uint8_t uCurSecIdx)
{
    const US_S_SectorEdgeLines_t * psSectorEdgeLine;
    float32_t fYonLeft = fY;  /*Assume point of LEFT side of vehicle */
    uint8_t uSecIdx;
    uint8_t uSectorIdxMatch = US_D_NO_SECTOR_MATCH;
    float32_t fResult;

    /* Mirror coord system to driver side of vehicle */
    if (fY < 0.0f)  /*Point is on RIGHT side of vehicle. */
    {
        fYonLeft = -fY; /*Put the point on the left; */
    }

    /* Do we need to double check current sector index? */
    if (uCurSecIdx != US_D_NO_SECTOR_MATCH)
    {
        /* If point has changed not changed side of vehicle, then do re-check, else just rescan all sectors. */
        if (   ((uCurSecIdx < uNumCalSectors) && (fY >= 0.0f))
            || ((uCurSecIdx >= uNumCalSectors) && (fY < 0.0f)))
        {
            if (uCurSecIdx >= uNumCalSectors)
            {
                uCurSecIdx = (uint8_t)(uTotalNumSectors - ONE - uCurSecIdx); /*Adjust sector index to Left Side of vehicle. */
            }

            psSectorEdgeLine = &sSectorEdgeLines[uCurSecIdx];

            fResult = fX * psSectorEdgeLine->fBtmA
                          + fYonLeft * psSectorEdgeLine->fBtmB
                          + psSectorEdgeLine->fBtmC;

            if (fResult >= 0.0f) /*Point lies to the LEFT of the bottom line, Thus PASS. */
            {
                /*Now check the left side of the sector for match. */
                fResult = fX * psSectorEdgeLine->fLeftA
                              + fYonLeft * psSectorEdgeLine->fLeftB
                              + psSectorEdgeLine->fLeftC;

                if (fResult <= 0.0f) /*Point lies to the RIGHT side of the left side line, thus PASS. */
                {
                    if (uCurSecIdx > ZERO)  /*If we are not in sector zero, then one additional test. */
                    {
                        uSecIdx = uCurSecIdx - ONE;  /*Look up sector before this one, to get the left side of it, which is our right side. */

                        /*Now check the right side of the sector for match. */
                        fResult = fX * psSectorEdgeLine->fLeftA
                                      + fYonLeft * psSectorEdgeLine->fLeftB
                                      + psSectorEdgeLine->fLeftC;

                        if (fResult >= 0.0f) /*Point lies to the LEFT side the right side line, Thus PASS. */
                        {
                            uSectorIdxMatch = uCurSecIdx;
                        }
                    }
                    else
                    {
                        /*uCurSecIdx is verified as #0 */
                        uSectorIdxMatch = uCurSecIdx;
                    }
                }
            }
        }
    }

    /* Current sector index is no longer valid, or we have a new point that
     * needs an initial sector index assigned.
     */
    if (uSectorIdxMatch == US_D_NO_SECTOR_MATCH)
    {
        /* Loops though all sectors on LEFT side of vehicle. */
        for (uSecIdx = ZERO; uSecIdx < uNumCalSectors; uSecIdx++)
        {
            psSectorEdgeLine = &sSectorEdgeLines[uSecIdx];

            fResult = fX * psSectorEdgeLine->fBtmA
                          + fYonLeft * psSectorEdgeLine->fBtmB
                          + psSectorEdgeLine->fBtmC;

            if (fResult >= 0.0f) /*Point lies to the LEFT of the bottom line, Thus PASS. */
            {
                /*Now check the left side of the sector for match. */
                fResult = fX * psSectorEdgeLine->fLeftA
                              + fYonLeft * psSectorEdgeLine->fLeftB
                              + psSectorEdgeLine->fLeftC;

                if (fResult >= 0.0f) /*Point lies to the LEFT side the left line, Thus FAIL. */
                {
                    continue;  /*Point must be in the next sector to the left.  Keep searching. */
                    /*if continue is here i dont even need an else statement at all!!!. */
                }  /*\TODO - jp why is this not just an else on the following line.  I don't know why i did this! */
                else if (fResult <= 0.0f) /*Point lies to the RIGHT side of the left side line. */
                {
                    /*Sector found!!  PASS!!! */
                    uSectorIdxMatch = uSecIdx;
                    break;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else
            {
                continue;  /*Point was Right of the Bottom line, so continue checking sectors. Thus FAIL. */
            }
        }
    }

    /* If we have a valid point, possibly recalculate zone for Right side of vehicle. */
    if (   (uSectorIdxMatch != US_D_NO_SECTOR_MATCH)
        && (fY < 0.0f))  /*Point is on RIGHT side of vehicle. */
    {
        uSectorIdxMatch =(uint8_t) (uTotalNumSectors - ONE - uSectorIdxMatch); /*Adjust sector index to Right Side of vehicle. */
    }

    return uSectorIdxMatch; /*Note: Could default to US_D_NO_SECTOR_MATCH; */
}

/*===========================================================================
 * \brief Scan through all points and find their minimum distance from point to sector "bottom".
 *
 * \param
 * \param
 * \return
 * \remarks Result is the array uZoneMinDist[US_D_MAX_SECTORS_TOTAL]
 */
/* ===========================================================================
 * Name:	 UssOD_CalcZoneDistances
 * Remarks:  DD-ID: {B6E1F6BC-4A6C-48c5-8517-B06DD6C07D2F}
 * Req.-ID: 15755032
 * Req.-ID: 14995713
 * Req.-ID: 15755032
 * ===========================================================================*/
void UssOD_CalcZoneDistances(void)
{
    uint8_t uGrpIdx;
    uint8_t uPntIdx;
    uint8_t uSecLookupIdx;
    uint8_t uSecIdx;
    uint8_t uMinConfToUse;
    uint16_t uDist;
    uint32_t uCurTime;
    uint16_t uInterZoneHystMs;
    uint16_t uZoneRemovalHystMs;
#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
    uint16_t uLowConfUpperHystDist_cm;
#endif
    float32_t fY;
    US_S_SnrPoint_t * psSnrPntBuff;

#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
    float32_t fVehSpeed = 0.0f;
#endif


    /* Clear all the zones min distance values to max distance */
    for (uSecIdx = ZERO; uSecIdx < (uNumCalSectors << ONE); uSecIdx ++)
    {
        uPrevZoneMinDist[uSecIdx] = uZoneMinDist[uSecIdx]; /*Keep previous zone for comparison later. */
        uZoneMinDist[uSecIdx] = US_D_OD_DEFAULT_DIST;
#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
        uZoneLowConfMinDist[uSecIdx] = US_D_OD_DEFAULT_DIST;
#endif
    }

#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
    /* Using vehicle speed, find an upper delta for sample movement in cm */
    if(UssCom_F_GetGearSpeedValidity() == US_SIGNALVALIDITY_VALID)
    {
        /*Read veh speed*/
        fVehSpeed = UssCom_F_GetVehSpeed();
    }

    uLowConfUpperHystDist_cm = (uint16_t) (fVehSpeed * US_D_ZONE_LOW_CONF_SPEED_FACTOR);

    /* Min upper movement delta set to normal higher zone hysteresis. */
    if (uLowConfUpperHystDist_cm < US_D_ZONE_TO_HIGHER_ZONE_DIST_CM)
    {
        uLowConfUpperHystDist_cm = US_D_ZONE_TO_HIGHER_ZONE_DIST_CM;
    }
#endif

#ifdef US_D_ZONE_MIN_PNT_CONF_MOVING
    if( UssMgr_IsVehicleMoving() == ME_TRUE )
    {
        uMinConfToUse = US_D_ZONE_MIN_PNT_CONF_MOVING;
    }
    else
    {
        uMinConfToUse = US_D_ZONE_MIN_PNT_CONF;
    }
#else
    uMinConfToUse = US_D_ZONE_MIN_PNT_CONF;
#endif

    /* Scan each group and all the NEW POINTS for their sector. */
    /* Note: We will need to implement a strategy to update sectors, if they change later (edge case). */
    for (uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++)
    {
        /* Retrieve this group's list of points */
        psSnrPntBuff = UssOD_sGetSnrPntBuff(uGrpIdx);
        /*puSnrPntSortIdxList = UssOD_sGetSnrPntSortIdxList(uGrpIdx);  */
       /* If we use less than all the points, we need to use the sorted list. */

        /* Loop though all points in group */
        for (uPntIdx = ZERO; uPntIdx < US_D_POINT_BUFFER_SIZE; uPntIdx++)
        {
            /* Check confidence against minimum for zone consideration */
            if (psSnrPntBuff[uPntIdx].uConf > US_D_ZONE_LOW_MIN_PNT_CONF)
            {
                uSecIdx = psSnrPntBuff[uPntIdx].uSectorIdx;
                if (uSecIdx >= US_D_MAX_SECTORS_TOTAL)
                {
                    uSecIdx = ZERO;
                }

                /* If this point is in a valid sector */
                if (uSecIdx != US_D_NO_SECTOR_MATCH)
                {
                    fY = psSnrPntBuff[uPntIdx].fY;

                    /* Find the mirror on the left side for sector check, if needed */
                    uSecLookupIdx = uSecIdx;

                    if (uSecLookupIdx >= uNumCalSectors)
                    {
                        uSecLookupIdx =(uint8_t) (uTotalNumSectors - ONE - uSecLookupIdx);
                        fY = -fY;
                    }

                    /* Find the perpendicular distance from the bottom line to point */
                    uDist = (uint16_t) (fabsf(psSnrPntBuff[uPntIdx].fX * sSectorEdgeLines[uSecLookupIdx].fBtmA
                                          + fY * sSectorEdgeLines[uSecLookupIdx].fBtmB
                                          + sSectorEdgeLines[uSecLookupIdx].fBtmC) / sSectorEdgeLines[uSecLookupIdx].fDistCalcDenom);

                    /* If the lowest distance, store it for analysis.  May revert to previous distance, if doesn't pass hysteresis.. */
                    if (uDist < uZoneMinDist[uSecIdx])
                    {
                        if (psSnrPntBuff[uPntIdx].uConf > uMinConfToUse)
                        {
                            uZoneMinDist[uSecIdx] = uDist;
                        }
#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
                        else
                        {
                            uZoneLowConfMinDist[uSecIdx] = uDist;  /*Fail-safe for low confidence detections. */
                        }
#endif
                    }
                }
            }
        }
    }

    /*
     * DEBOUNCE / HYSTERESIS CALCS FOR ZONE SELECTION
     */
    uCurTime = US_GetTimeStampTimeMs();
    
    if(UssMgr_IsAnyGroupNoisy() ==(bool_t) ME_TRUE)
    {
        uInterZoneHystMs = US_D_ZONE_TO_HIGHER_ZONE_HYST_NOISY_MS;
        uZoneRemovalHystMs = US_D_ZONE_DIST_REMOVAL_HYST_NOISY_MS;
    }
    else
    {
        uInterZoneHystMs = US_D_ZONE_TO_HIGHER_ZONE_HYST_MS;
        uZoneRemovalHystMs = US_D_ZONE_DIST_REMOVAL_HYST_MS;
    }

    /* Post processing to make final determination and perform hysteresis checks */
    for (uSecIdx = ZERO; uSecIdx < uTotalNumSectors; uSecIdx ++)
    {
#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
        /*
         * If detection is lost at good confidence, but distance is detected,
         * with similar or lower distance to previous detection,
         * then attempt to keep sector alive.
         */
        if (   (uZoneMinDist[uSecIdx] == US_D_OD_DEFAULT_DIST)          /*No detection at higher confidence. */
            && (uZoneLowConfMinDist[uSecIdx] != US_D_OD_DEFAULT_DIST))  /*But you do have a low confidence detection. */
        {
            uint16_t uUpperDistTheshold = uPrevZoneMinDist[uSecIdx] + uLowConfUpperHystDist_cm;

            if (uUpperDistTheshold > US_D_OD_DEFAULT_DIST)
            {
                uUpperDistTheshold = US_D_OD_DEFAULT_DIST;  /*Never take points over max dist. */
            }

            /*If low conf det is in range of last det, given veh speed, take it. */
            if (uZoneLowConfMinDist[uSecIdx] <= uUpperDistTheshold)
            {
                uZoneMinDist[uSecIdx] = uZoneLowConfMinDist[uSecIdx];
            }
        }
#endif

        /* New closest distance.  Take right away and set timeouts. */
        if (uZoneMinDist[uSecIdx] <= uPrevZoneMinDist[uSecIdx])
        {
            uLastZoneMinDistTime_ms[uSecIdx] = uCurTime;
        }
        else if (uZoneMinDist[uSecIdx] == US_D_OD_DEFAULT_DIST)  /*No detection */
        {
            /* Check if no distance for minimum time */
            if (uCurTime < (uLastZoneMinDistTime_ms[uSecIdx] + uZoneRemovalHystMs))
            {
                /*Revert to previous distance.  No timeout update. */
                uZoneMinDist[uSecIdx] = uPrevZoneMinDist[uSecIdx];
            }
        }
        else if (uZoneMinDist[uSecIdx] > (uPrevZoneMinDist[uSecIdx] + US_D_ZONE_TO_HIGHER_ZONE_DIST_CM)) /*New point is further away by more than some distance. */
        {
            /* Check if further point condition persists for some time before taking */
            if (uCurTime < (uLastZoneMinDistTime_ms[uSecIdx] + uInterZoneHystMs))
            {
                /* Timeout not achieved, revert to previous.  No time update. */
                uZoneMinDist[uSecIdx] = uPrevZoneMinDist[uSecIdx];
            }
            else /*We are taking new further distance as new distance.  Set timeouts. */
            {
                uLastZoneMinDistTime_ms[uSecIdx] = uCurTime;
            }
        }
        else /*No conditions to change are met. */
        {
            /* Timeout not achieved, revert to previous.  No time update. */
            uZoneMinDist[uSecIdx] = uPrevZoneMinDist[uSecIdx];
        }
    }
}


/*===========================================================================
 * \brief Calculate zone detection from point list.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Will eventually be based on objects, not points.
 */
/* ===========================================================================
 * Name:	 UssOD_PerformZoneDetection
 * Remarks:  DD-ID: {C1707990-C297-4fa9-B23C-104FD8A48C63}
 * Req.-ID: 15755032
 * ===========================================================================*/
void UssOD_PerformZoneDetection(void)
{
       uint16_t uDist_cm;
    uint8_t uZoneIdx;
    uint8_t uSecIdx;
    uint8_t uSecLookupIdx;
	if(pZoneBounds != NULL)
	{
       for (uSecIdx = ZERO; uSecIdx < uTotalNumSectors; uSecIdx++)
      {
        /* Find the mirror on the left side of vehicle for bottom line lookup */
        uSecLookupIdx = uSecIdx;
        if (uSecLookupIdx >= uNumCalSectors)
        {
            uSecLookupIdx  = (uint8_t)(uTotalNumSectors - ONE - uSecLookupIdx);
        }

        aZoneInfo[uSecIdx] = (uint8_t)ZONE_NO_OBSTACLE;  /*Default condition. */

        /* Get min distance for sensor */
        uDist_cm = uZoneMinDist[uSecIdx];

        /*
         * If distance is out of range, don't bother checking it.
         * If no zones defined, also skip checking.
         * Will underflow for ZONE One, will hit zero for zone n-2
         * Result is [1, n)
         */
        if (   (uDist_cm <= US_D_OD_DEFAULT_DIST)
            && (pZoneBounds[uSecLookupIdx].uNumZones != ZERO))
        {
            /*
             * Work backwards through zones until we exceed the zone on the low boundary, by one.
             * Loop will run (uNumZones, ZERO], finishes with underflow of 0xFF
             */
            for (uZoneIdx = pZoneBounds[uSecLookupIdx].uNumZones; uZoneIdx-- > ZERO; )
            {
                if ((float32_t) uDist_cm > pZoneBounds[uSecLookupIdx].fZoneUpperBound[uZoneIdx])
                {
                    break;
                }
            }

            /*
             * We underflowed, which means we are in the first zone, because
             * we passed the upper boundary check for the first zone.
             */
            if (uZoneIdx == US_D_OD_ZONE_INDEX_UNDERFLOW)
            {
                aZoneInfo[uSecIdx] = ONE; /*It is the first zone. */
            }
            else if (uZoneIdx < (pZoneBounds[uSecLookupIdx].uNumZones - ONE)) /*If (Zone Index == uNumZones - 1) was further than last upper bound, stick to DEFAULT_DIST */
            {
                /*
                 * We are Two zone indices less than we want to be,
                 * because we passed the top threshold for the zone,
                 * so that makes one to add back in,
                 * and zones start at one, not zero, so add one more.
                 */
                aZoneInfo[uSecIdx] = uZoneIdx + TWO;
            }
            else
            {
                /* Do Nothing */
            }
        }
      }
	}
}

/* ===========================================================================
 * Name:	 UssOD_paGetZoneInfo
 * Remarks:  DD-ID: {002C6B8E-8D27-4baf-BB41-F4D3DBB9BB4E}
 * Req.-ID: 15031804
 * ===========================================================================*/
uint8_t *UssOD_paGetZoneInfo(void)
{
    return aZoneInfo;
}

/*===========================================================================
 * \brief Init zone data.
 *
 * \param none
 * \param none
 * \return
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_InitZoneData
 * Remarks:  DD-ID: {E706C424-2932-4467-8759-2D445037E7AA}
 * Req.-ID: 15031804
 * ===========================================================================*/
void UssOD_InitZoneData(void)
{
    uint8_t uSecIdx;
    for (uSecIdx = ZERO; uSecIdx < US_D_MAX_SECTORS_TOTAL; uSecIdx ++)
    {
        uPrevZoneMinDist[uSecIdx] = US_D_OD_DEFAULT_DIST;
        uZoneMinDist[uSecIdx] = US_D_OD_DEFAULT_DIST;
#if (US_D_ZONE_ENABLE_LOW_CONF_PNTS == ME_TRUE)
        uZoneLowConfMinDist[uSecIdx] = US_D_OD_DEFAULT_DIST;
#endif
        uLastZoneMinDistTime_ms[uSecIdx] = ZERO;
    }
}
#endif

/*===========================================================================
 * \brief initiaize zone & sector coordinate .
 *
 * \param none
 * \param none
 * \return none
 * \remarks Will eventually be based on objects, not points.
 */
/* ===========================================================================
 * Name:     UssOD_InitCalData
 * Remarks:  DD-ID: {CF559164-F7E7-4942-B6FA-5EB7418029AC}
 * ===========================================================================*/
void UssOD_InitCalData(void)
{
#if (USS_FEATURE_ZONE_INFO == US_STD_ON)
    uint16_t len = ZERO;
    pZoneBounds = (US_S_ZoneBounds_t*)US_SnrCfg_Get_ZoneBoundsCfg(&len);
    uNumCalSectors = ZERO;
    uTotalNumSectors = ZERO;
    pSectorEdgeCal = (US_S_SectorEdge_t*) US_SnrCfg_Get_SectorEdgeCfg(&len);
     if (len != ZERO)
    {
        uNumCalSectors = (uint16_t) (len / sizeof(US_S_SectorEdge_t) - ONE);
        uTotalNumSectors = uNumCalSectors << ONE;
    }
#endif
 }
