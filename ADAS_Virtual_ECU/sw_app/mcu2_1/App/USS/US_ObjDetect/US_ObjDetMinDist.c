/*
 * US_ObjDetMinDist.c
 *
 *  Created on: Sep 16, 2021
 *      Author: jonapais
 */

/*PRQA S 0816 ++ */
/*PRQA S 1011, 0857 ++ */
/* PRQA S 0292 ++ */ /*Special characters in comments have no functional impact */

#include <math.h>
#include "US_ObjDetMinDist.h"
#include "US_PlatformCfg_Global.h"
#include "US_Platform_Global.h"
#include "US_SysMgr_Global.h"
#include "US_ObjDetTriang.h"
#include "US_ObjDetData.h"
#include "US_ObjDetMain.h"
#include "US_SnrCfg_Global.h"

/* Parameters for this function.  TODO jp - Add to cals */
#define US_D_OD_MIN_DIST_HYST_CM       (5u)
#define US_D_OD_MIN_DIST_TIME_HYST_MS  (480u)

/* Min Dist */
static uint16_t uPntMinDist[US_D_MAX_NUM_SENSORS];
static uint16_t uPrevPntMinDist[US_D_MAX_NUM_SENSORS];
static uint16_t uPntMinDistLowConf[US_D_MAX_NUM_SENSORS];
static uint32_t uLastMinDistTime_ms[US_D_MAX_NUM_SENSORS];


/* Mid Dist */
static uint16_t uPntMidDist[US_D_MAX_NUM_SENSORS];
static float32_t fPntMidDistSq[US_D_MAX_NUM_SENSORS];
static float32_t fPntMidDistSqLowConf[US_D_MAX_NUM_SENSORS];

static void UssOD_FindMinimumMidDist(uint8_t uGrpIdx, uint8_t uDirSnrDataIdx, uint8_t uIndirSnrDataIdx);

/*===========================================================================
 * \brief Clear filtered min/mid distances lists.
 *
 * \param uint8_t uGrpIdx
 * \param
 * \param
 * \return
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_ClearFiltDistances
 * Remarks:  DD-ID: {29628E43-4553-4359-AEEE-348EE817E872}
 *Req.-ID: 13396023
 * ===========================================================================*/
void UssOD_ClearFiltDistances(bool_t bDoInit)
{
    uint8_t uSnrIdx;
    const US_S_SnrCalcs_t * psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();  // Get echo class calculations

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        /* Set preliminary calculations to max distance */
        uPrevPntMinDist[uSnrIdx]    = uPntMinDist[uSnrIdx]; // Store last min dist, i.e. current, to previous min dist array.

        uPntMinDist[uSnrIdx]        = US_D_OD_DEFAULT_DIST;
        uPntMinDistLowConf[uSnrIdx] = US_D_OD_DEFAULT_DIST;

        /*
         * To save processing time, mid distances are only recalculated when
         * sensor fires or if it hasn't fired in an entire cycle of
         * available sensors.
         */
        uint8_t uCycSinceLastMeas = UssOD_puGetCycSinceLastMeas()[uSnrIdx];
        US_E_EchoClass_t eEchoClass = psSnrCalcs->sSnrCalcRec[uSnrIdx].eEchoClass;
        if (   (eEchoClass == US_E_DIRECT)
                || (uCycSinceLastMeas > US_D_MAX_NUM_SENSORS)
                || (bDoInit == (bool_t) ME_TRUE))
        {
            /* Set default distance of searches to max distance squared */
            fPntMidDistSq[uSnrIdx] = US_D_OD_DEFAULT_DIST_SQ;
            fPntMidDistSqLowConf[uSnrIdx] = fPntMidDistSq[uSnrIdx];

            /* Set final default distance to max distance */
            uPntMidDist[uSnrIdx] = US_D_OD_DEFAULT_DIST;
        }
    }
}


/*===========================================================================
 * \brief Compute filtered min distances for a given physical group.
 *
 * \param uint8_t uGrpIdx
 * \param
 * \param
 * \return
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_FindFiltGrpMinDistances
 * Remarks:  DD-ID: {0002BB6C-8511-4773-A13A-1356FC2B788F}
 * Req.-ID: 13517239
 * ===========================================================================*/
void UssOD_FindFiltGrpMinDistances(uint8_t uGrpIdx)
{
    uint8_t uPntIdx;
    uint8_t uSnrIdx;
    uint16_t uDist;
    US_S_SnrPoint_t * psSnrPntBuff;

    /*
     * Find the closest point to each sensor.
     */
    for (uPntIdx = 0; uPntIdx < US_D_POINT_BUFFER_SIZE; uPntIdx++)
    {
        psSnrPntBuff = UssOD_sGetSnrPntBuff(uGrpIdx);
        uSnrIdx = psSnrPntBuff[uPntIdx].uDirSnrIdx;

        /* Not a deleted/valid point */
        if (psSnrPntBuff[uPntIdx].uConf > ZERO)
        {
            uDist = psSnrPntBuff[uPntIdx].uLowDirDist;  // \TODO jp - Need design decision on lowest direct vs current direct

            /* Point which qualifies as a detection, barely. */
            if (uDist < uPntMinDistLowConf[uSnrIdx])
            {
                uPntMinDistLowConf[uSnrIdx] = uDist;
            }
            /*
             * Find the closest point of a -confirmed- confidence level.
             * i.e. One which has been measured more than once or is a very
             *      strong amplitude, or multiple measured, first measurement.
             */
            if (psSnrPntBuff[uPntIdx].uConf > US_D_OD_DIST_MIN_CONF_THRESH)
            {
                if (uDist < uPntMinDist[uSnrIdx])
                {
                    uPntMinDist[uSnrIdx] = uDist;
                }
            }
        }
    }

}

/*===========================================================================
 * \brief Final arbitration for min distances for all sensors.
 *
 * \param
 * \param
 * \param
 * \return
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_FindFiltMinDistances
 * Remarks:  DD-ID: {C11DE9C5-56B8-4747-9407-3604A22B4C4C}
 * Req.-ID: 15031804
 * ===========================================================================*/
void UssOD_FindFiltMinDistances(void)
{
    uint8_t uSnrIdx;
    uint32_t uCurTime;

    uCurTime = US_GetTimeStampTimeMs();

    /*
     * FAIL SAFE FOR DISTANCES
     * Choose which closest point to report.
     */
    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        /*
         * If no point at a -confirmed- confidence level
         * then take any detection closest to sensor
         */
        if (uPntMinDist[uSnrIdx] == US_D_OD_DEFAULT_DIST)
        {
            uPntMinDist[uSnrIdx] = uPntMinDistLowConf[uSnrIdx];
        }

        /* Is new min dist closer than previous min dist */
        if (uPntMinDist[uSnrIdx] <= uPrevPntMinDist[uSnrIdx])  // If so, keep.
        {
            uLastMinDistTime_ms[uSnrIdx] = uCurTime; // Mark time min distance taken.
        }
        else if (uPntMinDist[uSnrIdx] > (uPrevPntMinDist[uSnrIdx] + US_D_OD_MIN_DIST_HYST_CM))  // Check if pass of distance hysteresis.
        {
            /* Check if min time with larger distance has passed */
            if (uCurTime < (uLastMinDistTime_ms[uSnrIdx] + US_D_OD_MIN_DIST_TIME_HYST_MS))
            {
                /* We do not meet requirements for raising min distance */
                uPntMinDist[uSnrIdx] = uPrevPntMinDist[uSnrIdx];
            }
            else
            {
                /* Take the new, higher, distance, and record time */
                uLastMinDistTime_ms[uSnrIdx] = uCurTime; // Mark time min distance taken.
            }
        }
        else
        {
            /* We do not meet requirements to change min dist */
            uPntMinDist[uSnrIdx] = uPrevPntMinDist[uSnrIdx];
        }
    }

}

/*===========================================================================
 * \brief Find minimum distance point to the virtual sensor of interest.
 *
 * \param uint8_t uGrpIdx
 * \param uint8_t uDirSnrDataIdx
 * \param uint8_t uIndirSnrDataIdx
 * \return
 * \remarks The virtual sensor lives between uDirSnrDataIdx and uIndirSnrDataIdx.
 */
/* ===========================================================================
 * Name:	 UssOD_FindMinimumMidDist
 * Remarks:  DD-ID: {6CA86D2B-C334-419a-A1D2-A94D11529FED}
 * Req.-ID: 13517239
 * ===========================================================================*/
static void UssOD_FindMinimumMidDist(uint8_t uGrpIdx, uint8_t uDirSnrDataIdx, uint8_t uIndirSnrDataIdx)
{
    uint8_t uPntIdx;
    uint8_t uGrpNumPnts = US_D_POINT_BUFFER_SIZE;  //uNumPnts[uGrpIdx]; \TODO - jp Calulate this after sort
    float32_t fVirtSnrX ;
    float32_t fVirtSnrY;
    float32_t fX;
    float32_t fY;
    float32_t fDeltaX;
    float32_t fDeltaY;
    float32_t fDistSq;

    US_S_SensorsCfg_t *pSnrCfg	= NULL;
    const US_S_Sensor_coordinate_t * pSnrCoord = NULL;

    /* Get the address of Sendor Coordiation in Calibration data */
    pSnrCfg = US_SnrCfg_F_Get_SnrCfg();			//Todo Sam
    pSnrCoord = pSnrCfg->pSnrCoordinate;

    if(pSnrCoord != NULL)    // check if the data is exist
	{   
    US_S_SnrPoint_t * psSnrPntBuff = UssOD_sGetSnrPntBuff(uGrpIdx);

    /* Calculate coordinate of Mid point virtual sensor */
    fVirtSnrX = ((pSnrCoord[uIndirSnrDataIdx].fX - pSnrCoord[uDirSnrDataIdx].fX) / 2.0f )+ pSnrCoord[uDirSnrDataIdx].fX;
    fVirtSnrY = ((pSnrCoord[uIndirSnrDataIdx].fY - pSnrCoord[uDirSnrDataIdx].fY) / 2.0f )+ pSnrCoord[uDirSnrDataIdx].fY;

    /*
     * Scan all points in this group's point map, who utilized this
     * direct or this indirect sensor for it's detection.
     */
    for (uPntIdx = 0; uPntIdx < uGrpNumPnts; uPntIdx++)
    {
        /* Is this an active point */
        if (psSnrPntBuff[uPntIdx].uConf > ZERO)
        {
            /* Either the direct or the indirect sensor may have measured it last */
            /* Since this is mid-dist between the two, we need to check both against this sensor */
            if (   (psSnrPntBuff[uPntIdx].uDirSnrIdx == uDirSnrDataIdx)
                || (psSnrPntBuff[uPntIdx].uIndirSnrIdx == uDirSnrDataIdx))
            {
                /*
                 * Now to perform expensive distance calculations.
                 */
                fX = psSnrPntBuff[uPntIdx].fX;
                fY = psSnrPntBuff[uPntIdx].fY;

                fDeltaX = fVirtSnrX - fX;
                fDeltaY = fVirtSnrY - fY;

                /* Calculate distance squared */
                fDistSq = (fDeltaX * fDeltaX) + (fDeltaY * fDeltaY);

                /*
                 * Find lowest Low Confident distance squared as well as each "better" confidence distance squared.
                 * Note: Store the virtual sensor data in the location of the direct sensor
                 *       for each pair of points used to form the virtual sensor
                 *
                 */
                if (fDistSq < fPntMidDistSq[uDirSnrDataIdx]) // Check if lowest distance squared to virtual sensor.
                {
                    fPntMidDistSqLowConf[uDirSnrDataIdx] = fDistSq;
                }

                /*
                 * Store lowest distance squared for points of good confidence.
                 */
                if (psSnrPntBuff[uPntIdx].uConf > US_D_OD_DIST_MIN_CONF_THRESH)
                {
                    fPntMidDistSq[uDirSnrDataIdx] = fDistSq;
                }
            }
        }
    }

    /*
     * Do final calculation for lowest distance for this virtual sensor.
     * Time to pay-the-piper and take the square root for the closest point
     * to the virtual sensor.
     */
    if (fPntMidDistSq[uDirSnrDataIdx] < US_D_OD_DEFAULT_DIST_SQ)
    {
        uPntMidDist[uDirSnrDataIdx] = (uint16_t) sqrtf(fPntMidDistSq[uDirSnrDataIdx]);
    }
    else
    {
        uPntMidDist[uDirSnrDataIdx] = (uint16_t) sqrtf(fPntMidDistSqLowConf[uDirSnrDataIdx]);
    }
 }

}

/*===========================================================================
 * \brief Compute filtered mid distances for a given physical group.
 *
 * \param uint8_t uGrpIdx
 * \param
 * \param
 * \return
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_FindFiltMidDistances
 * Remarks:  DD-ID: {544E00B1-EE1D-4211-A9AB-EAD6D705E061}
 * Req.-ID: 13517239
 * ===========================================================================*/
void UssOD_FindFiltMidDistances(uint8_t uGrpIdx)
{
    const US_S_IndirSnrIdxList_t * psIndirSnrList;
    uint8_t  uDirSnrDataIdx;
    uint8_t  uIndirSnrDataIdx;
    uint8_t  uDirSnrGrpIdx;
    uint8_t  uNumSnrsInGrp;

    const US_S_SnrCalcs_t * psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();

    /*
     * FIND MID DISTANCE
     */
    uNumSnrsInGrp = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;

    /* Perform for each sensor in physical group */
    if (uNumSnrsInGrp >= TWO)
    {
        for (uDirSnrGrpIdx = ZERO; uDirSnrGrpIdx < (uNumSnrsInGrp - ONE); uDirSnrGrpIdx++)
        {
            /* Retrieve direct index */
            uDirSnrDataIdx = psPlatPhysInfo->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uDirSnrGrpIdx];

            /*
             * If this is a firing sensor perform scan for lowest distance
             * to virtual (mid) sensor, for this direct sensor and the sensor
             * to the right of it, in this physical group.
             * We only want to perform this calculation for the direct sensor that
             * is firing currently as the other sensor data for mid distance will not
             * change on a non-firing cycle.
             */
            if (psSnrCalcs->sSnrCalcRec[uDirSnrDataIdx].eEchoClass == US_E_DIRECT)
            {
                /* Look up indirect sensor index, to the right of this direct sensor */
                psIndirSnrList = UssOD_psGetIndirSnrList(uGrpIdx, uDirSnrGrpIdx);
                uIndirSnrDataIdx = psIndirSnrList[US_INDIR_RIGHT].uIndirSnrDataIdx;

                /*
                 * If this sensor actually has an indirect sensor to the right of it,
                 * then perform scan.
                 */
                if (uIndirSnrDataIdx != US_D_OD_NO_INDIR_SNR)
                {
                    UssOD_FindMinimumMidDist(uGrpIdx, uDirSnrDataIdx, uIndirSnrDataIdx);
                }
            }
        }
    }
}



/*===========================================================================
 * \brief Return pointer to mid distance array
 *
 * \param
 * \param
 * \param
 * \return uint16_t * pointer to mid distance array
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_GetPntMidDist
 * Remarks:  DD-ID: {3BF19172-B3F8-4fe4-8E20-5E78D8537910}
 * ===========================================================================*/
uint16_t * UssOD_GetPntMidDist(void)
{
    return uPntMidDist;
}

/*===========================================================================
 * \brief Return pointer to min distance array
 *
 * \param
 * \param
 * \param
 * \return uint16_t * pointer to min distance array
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_GetPntMinDist
 * Remarks:  DD-ID: {3D3A702B-2348-422d-A667-457D6AAA053D}
 * Req.-ID: 13396023
 * ===========================================================================*/
uint16_t * UssOD_GetPntMinDist(void)
{
    return uPntMinDist;
}

/*===========================================================================
 * \brief Initialize point min dist values.
 *
 * \param
 * \param
 * \param
 * \return
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_InitPntMinDist
 * Remarks:  DD-ID: {D5C3D1C2-B1E8-482f-A3F8-C1596A797525}
 * ===========================================================================*/
void UssOD_InitPntMinDist(void)
{
    uint8_t uSnrIdx;

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        uPntMinDist[uSnrIdx] = US_D_OD_DEFAULT_DIST;
        uPrevPntMinDist[uSnrIdx] = US_D_OD_DEFAULT_DIST;
        uLastMinDistTime_ms[uSnrIdx] = ZERO;
    }
}
