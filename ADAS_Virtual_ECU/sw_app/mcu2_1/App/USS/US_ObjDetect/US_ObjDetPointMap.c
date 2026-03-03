/*
 * US_ObjDetDistMap.c
 *
 *  Created on: Aug 12, 2021
 *      Author: jonapais
 */
/* PRQA S 4453 ++ */ /*Conversion has no impact */
#include "US_ME_Typedefs_Global.h"
#include "US_ObjDet_Global.h"
#include "US_ObjDetPointMap.h"
#include "US_PlatformCfg_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SysMgr_Global.h"
#include "USS_Library_Header.h"
#include "US_ObjDetTriang.h"

/* Output point buffer - local */
static US_S_PointMap_t sPointMap;
/*#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE */
#if defined(DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE) && !defined(DEBUG_VISUAL_TOOL_OBJECT_MODE) /*jz: don't allocate in object mode. */
static US_S_PntDebugInfo_t sDebugPntInfo[SIXTEEN];
#endif
#define US_D_NUM_PNTS_EACH_GRP (48u) /* ((uint8_t)(96u / US_D_PHYS_GRP_MAX))*/

typedef struct US_S_OutPntDataIdx_s
{
    uint8_t uGrpIdx;    /* Group of the point linked to this output location */
    uint8_t uDataIdx;   /* Index within group data linked to this output location */
    bool_t  bActive;    /* Boolean as to weather this point is valid for output anymore */
} US_S_OutPntDataIdx_t;

typedef struct US_S_OutPntGrpAlloc_s
{
    uint8_t uStartIdx;
    uint8_t uEndIdx;
} US_S_OutPntGrpAlloc_t;

/*===========================================================================
 * \brief Calculate distance point map from sensor data.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_PopulatePointMap
 * Remarks:  DD-ID: {0AA7D828-B00A-4001-8D45-7F0BCA1B8E63}
 * Traceability to source Code: Req.-ID: 13420477
 * Req.-ID: 15002811
 * Req.-ID: 15002839
 * Req.-ID: 17275272
 * Req.-ID: 17275275
 * Req.-ID: 17270853
 * Req.-ID: 17272021
 * Req.-ID: 17272048
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch statements doesn't lead to any complexcity */
void UssOD_PopulatePointMap(void)/* PRQA S 2755 */
{

    static US_S_OutPntGrpAlloc_t sOutPntGrpAlloc[US_D_PHYS_GRP_MAX] =
    {
           [US_D_PHYS_GRP_FRNT]       = {.uStartIdx = 0,    .uEndIdx = 96},
           [US_D_PHYS_GRP_REAR]       = {.uStartIdx = 0xFF, .uEndIdx = 96},
#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN		   
           [US_D_PHYS_GRP_LEFT_SIDE]  = {.uStartIdx = 48,   .uEndIdx = 96},
           [US_D_PHYS_GRP_RIGHT_SIDE] = {.uStartIdx = 0xFF, .uEndIdx = 96}
#endif
     };

     /* List of output points */
    static US_S_OutPntDataIdx_t sOutPntIdxList[US_D_POINTMAP_OUT_SIZE];         

    uint8_t uGrpIdx;
    uint8_t uPntIdx;
    uint8_t uOutPntIdx;
    uint8_t uPntSortIdx;
#if (DEBUG_VISUAL_GRP_CHOICE == US_D_PHYS_GRP_DBG_SPLIT)
    uint8_t uCurDbgGrp = ZERO;
    uint8_t uCurDbgCntMax = SIXTEEN >> ONE;
#else
    uint8_t uCurDbgGrp = DEBUG_VISUAL_GRP_CHOICE;
#endif
    US_S_SnrPoint_t * psPnt;
    US_S_Point_t * psOutPnt;
    US_S_SnrPoint_t * psSnrPntBuff;
    uint8_t * puSnrPntSortIdxList;
/*#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE */
#if defined(DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE) && !defined(DEBUG_VISUAL_TOOL_OBJECT_MODE)
    uint8_t uDebugPntCnt;
#endif

    /* Start by reseting all active output points to FALSE */
    for (uOutPntIdx = ZERO; uOutPntIdx < US_D_POINTMAP_OUT_SIZE; uOutPntIdx++)
    {
        sOutPntIdxList[uOutPntIdx].bActive = ME_FALSE;
    }

    /*
     * Scan for all exiting points which still qualify to be output on API and/or CAN.
     * Mark IDs as active, who are already assigned to data, so the data
     * doesn't change index position on API and/or CAN.
     */
    for (uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++)
    {
        psSnrPntBuff = UssOD_sGetSnrPntBuff(uGrpIdx);
        puSnrPntSortIdxList = UssOD_sGetSnrPntSortIdxList(uGrpIdx);

        for (uPntIdx = ZERO; uPntIdx < US_D_NUM_PNTS_EACH_GRP; uPntIdx++)
        {
            uPntSortIdx = puSnrPntSortIdxList[uPntIdx];
            psPnt = &psSnrPntBuff[uPntSortIdx];

            if (   (psPnt->uConf != ZERO)
                && (psPnt->uOutputId != US_D_OD_UNUSED_OUTPUT_IDX))
            {
                sOutPntIdxList[psPnt->uOutputId].bActive = ME_TRUE;
            }
        }
    }

    /*
     * Disconnect, from group point list, any point previously output that is no longer going to be output,
     * to the API and/or CAN.
     */
    for (uOutPntIdx = ZERO; uOutPntIdx < US_D_POINTMAP_OUT_SIZE; uOutPntIdx++)
    {
        if (    (sOutPntIdxList[uOutPntIdx].bActive == (bool_t)ME_FALSE)
             && (psPnt->uOutputId != US_D_OD_UNUSED_OUTPUT_IDX))
        {
            /* Mark in point as well, for future checks if point is attached to an output */
            psSnrPntBuff = UssOD_sGetSnrPntBuff(sOutPntIdxList[uOutPntIdx].uGrpIdx);
            psPnt = &psSnrPntBuff[sOutPntIdxList[uOutPntIdx].uDataIdx];

            /* Free up index for another point to output */
            psPnt->uOutputId = US_D_OD_UNUSED_OUTPUT_IDX;
        }
    }

    /* Set up advanced debug list */
/*#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE */
#if defined(DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE) && !defined(DEBUG_VISUAL_TOOL_OBJECT_MODE)
    for (uDebugPntCnt = ZERO; uDebugPntCnt < SIXTEEN; uDebugPntCnt++)
    {
        sDebugPntInfo[uDebugPntCnt].uOutputId = 0xFFu;
    }

    uDebugPntCnt = ZERO;
#endif
    /*
     * Finally, add all new points to the output buffer and connect them to a
     * specific output index.
     */
    uOutPntIdx = ZERO; /* Used to place new points efficiently */

    for (uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++)
    {
        psSnrPntBuff = UssOD_sGetSnrPntBuff(uGrpIdx);
        puSnrPntSortIdxList = UssOD_sGetSnrPntSortIdxList(uGrpIdx);

        if (sOutPntGrpAlloc[uGrpIdx].uStartIdx != 0xFFu)
        {
            uOutPntIdx = sOutPntGrpAlloc[uGrpIdx].uStartIdx;
        }

        /* Set up current debug group */
#if (DEBUG_VISUAL_GRP_CHOICE == US_D_PHYS_GRP_DBG_SPLIT)
        if (uGrpIdx != uCurDbgGrp)
        {
            uCurDbgCntMax += (SIXTEEN >> ONE);
            uCurDbgGrp = uGrpIdx;
        }
#endif

        /* Check if each point qualifies to be on output list */
        for (uPntIdx = ZERO; uPntIdx < US_D_NUM_PNTS_EACH_GRP; uPntIdx++)
        {
            uPntSortIdx = puSnrPntSortIdxList[uPntIdx];
            psPnt = &psSnrPntBuff[uPntSortIdx];

            if (psPnt->uConf != ZERO)
            {
                if (psPnt->uOutputId == US_D_OD_UNUSED_OUTPUT_IDX)
                {
                    /*
                     * Search for an unused location in out buffer to tie to point.
                     * For efficiency, pick up where we last left off in list.
                     * Everything before has already been searched.
                     */
                    for (; uOutPntIdx < sOutPntGrpAlloc[uGrpIdx].uEndIdx; uOutPntIdx++)
                    {
                        if (sOutPntIdxList[uOutPntIdx].bActive == (bool_t)ME_FALSE)
                        {
                            break; /* We found an unused point, exit loop. */
                        }
                    }

                    /* Tie output buffer location to point */
                    if (uOutPntIdx < sOutPntGrpAlloc[uGrpIdx].uEndIdx) /* Should never exceed.  Just for safety. */
                    {
                        sOutPntIdxList[uOutPntIdx].uGrpIdx = uGrpIdx;
                        sOutPntIdxList[uOutPntIdx].uDataIdx = uPntSortIdx;
                        psPnt->uOutputId = uOutPntIdx;
                        sOutPntIdxList[uOutPntIdx].bActive = ME_TRUE;
                    }
                }

                /* Update all output data from group points lists */
                if (psPnt->uOutputId != US_D_OD_UNUSED_OUTPUT_IDX)

                {
                    /* Valid point to add to API/CAN output list, store point. */
                    psOutPnt = &sPointMap.sPointMap[psPnt->uOutputId];

                    psOutPnt->x            = psPnt->fX;  /* + 0.5f; need to round and cast */
                    psOutPnt->y            = psPnt->fY;  /* + 0.5f; */
                    psOutPnt->age          = psPnt->uAge;
                    if (UssMgr_eGetGrpState(uGrpIdx) == SYSMGR_GRPSTATE_OK)
                    {
	                	if (psPnt->uConf >= 20u)
	                    {
	                        psOutPnt->confidence   = psPnt->uConf - 20u;
	                        if (psOutPnt->confidence < 10u)
	                        {
	                            psOutPnt->confidence = 10u;
	                        }
	                    }
	                    else
	                    {

	                        psOutPnt->confidence   = 10u;
	                    }
                    }
                    else
                    {   
                        psOutPnt->confidence   = psPnt->uConf;
                    }

                    psOutPnt->height       = psPnt->uHeight;

#if 0 /*US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN */
                    psOutPnt->cruising_age = ZERO;
#else
                    psOutPnt->cruising_age = psPnt->uCruisingAge;
#endif



/*#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE */
#if defined(DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE) && !defined(DEBUG_VISUAL_TOOL_OBJECT_MODE)
                    if (  
#if (DEBUG_VISUAL_GRP_CHOICE == US_D_PHYS_GRP_DBG_SPLIT)
                        (uDebugPntCnt < uCurDbgCntMax)&&
#endif
                        (uDebugPntCnt < SIXTEEN))
                    {
                        sDebugPntInfo[uDebugPntCnt].uCmdId        = 0x02;
                        sDebugPntInfo[uDebugPntCnt].uOutputId     = psPnt->uOutputId;

                        sDebugPntInfo[uDebugPntCnt].uDirSnrIdx    = psPnt->uDirSnrIdx;;
                        sDebugPntInfo[uDebugPntCnt].uIndirSnrIdx  = psPnt->uIndirSnrIdx;

                        /* uGrpPntIdx (4 bits) | uGrpPntIdx (4 bits)*/
                        sDebugPntInfo[uDebugPntCnt].uGrpIdx     = sOutPntIdxList[psPnt->uOutputId].uGrpIdx;
                        sDebugPntInfo[uDebugPntCnt].uPntIdx     = sOutPntIdxList[psPnt->uOutputId].uDataIdx;
                        sDebugPntInfo[uDebugPntCnt].uLowDirDist = psPnt->uLowDirDist;
                        sDebugPntInfo[uDebugPntCnt].uIndirDist  = psPnt->uIndirDist;
                        sDebugPntInfo[uDebugPntCnt].uBaseDist   = psPnt->uBaseDist;
                        sDebugPntInfo[uDebugPntCnt].uPntStat    = psPnt->uPntStat;         /* Bit encoded.  See US_D_PNTSTAT_ * */
                        sDebugPntInfo[uDebugPntCnt].uSectorIdx  = psPnt->uSectorIdx;
                        uDebugPntCnt++;
                    }
#endif
                }
            }
        }
    }

    /* Clear output data for unused points - for clarity that they are dead points */
    for (uOutPntIdx = ZERO; uOutPntIdx < US_D_POINTMAP_OUT_SIZE; uOutPntIdx++)
    {
        psOutPnt = &sPointMap.sPointMap[uOutPntIdx];

        if (sOutPntIdxList[uOutPntIdx].bActive == (bool_t)ME_FALSE)
        {
            /* Clear out unused points */
            (void)memset(psOutPnt, ZERO, sizeof(US_S_Point_t)); /* PRQA S 1291 */
        }
    }
}

/*===========================================================================
 * \brief Get pointer to distance point map.
 *
 * \param none
 * \param none
 * \return pointer to distance point map
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_paGetPointMap
 * Remarks:  DD-ID: {47E45ADD-403D-44a8-A0CC-48B1034F1A04}
 * Req.-ID: 13420477
 * Req.-ID: 15002811
 * Req.-ID: 15002839
 * Req.-ID: 17275272
 * Req.-ID: 17275275
 * Req.-ID: 17270853
 * Req.-ID: 17272021
 * Req.-ID: 17272048
 * ===========================================================================*/
US_S_PointMap_t *UssOD_paGetPointMap(void)
{
    return &sPointMap;
}

#if defined(DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE) && !defined(DEBUG_VISUAL_TOOL_OBJECT_MODE)
/* For visualization/Analysis tool only!!! */
/*===========================================================================
 * \brief Get pointer to distance point map.
 *
 * \param none
 * \param none
 * \return pointer to distance point map
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_paGetDebugPntInfo
 * Remarks:  DD-ID: {368EF636-8A9A-4e81-BC18-9822FFBECAE8}
 * Req.-ID: 13420477
 * ===========================================================================*/
US_S_PntDebugInfo_t *UssOD_paGetDebugPntInfo(void)
{
    return sDebugPntInfo;
}
#endif
