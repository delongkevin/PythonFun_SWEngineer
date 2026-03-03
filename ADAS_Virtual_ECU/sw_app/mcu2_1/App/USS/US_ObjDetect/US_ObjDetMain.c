/*
 * US_ObjDetMain.c
 *
 *  Created on: Aug 9, 2021
 *      Author: jonapais
 */

/*PRQA S 0816,0857, 1053, 0776 ++ */  
/*PRQA S 1881++ */ /*Converted as well as non converted int has same relational operations*/
/* PRQA S 0292, 0314, 0315 ++ */ /*Special characters in comments have no functional impact, Implicit typecasting for standard functions like memcpy and memset */

#include "US_ME_Typedefs_Global.h"
#include "US_Platform_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_ObjDet_Global.h"
#include "US_SysMgr_Global.h"
#include "US_ObjDetZone.h"
#include "US_ObjDetPointMap.h"
#include "US_ObjDetData.h"
#include "US_ObjDetTriang.h"
#include "US_ObjDetMinDist.h"
#include "US_ObjDetMain.h"
/*#include "US_ObjDet2dObj.h"*/

/* Number of cycles it has been since a sensor has made a direct measurement */
static uint8_t uCycSinceLastMeas[US_D_MAX_NUM_SENSORS];

static bool_t UssOD_PopulateComOutputBuffer(void);
static void UssOD_ClearCycSinceLastMeas(void);
static void UssOD_UpdateSnrLastMeasCount(void);

/*===========================================================================
 * \brief Main processing for object detection.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_Main
 * Remarks:  DD-ID: {B5720702-88D8-4e34-8A6A-BBA0C3C8B1EA}
 * Req.-ID: 13396023
 * Req.-ID: 15031804
 * Req.-ID: 15002239
 * Req.-ID: 15002690
 * Req.-ID: 17275282
 * Req.-ID: 15002811
 * Req.-ID: 15755032
 * Req.-ID: 14995713
 * Req.-ID: 15755032
 *
 * ===========================================================================*/
void UssOD_Main(void)
{
    static bool_t UssOD_bNewOutputData = ME_FALSE;
    bool_t bNewSnrData = UssMgr_bIsNewSnrData();
    if (bNewSnrData == ((bool_t)ME_TRUE))  /* Exit task if no new data.*/
    {
        UssOD_UpdateSnrLastMeasCount();
        UssOD_ClearFiltDistances(ME_FALSE);
        UssOD_ResetOdCalcs(ME_FALSE);
        UssOD_PerformEchoLocation();
        UssOD_FindFiltMinDistances();
        UssOD_PopulatePointMap();

#if(USS_FEATURE_ZONE_INFO == US_STD_ON)       
        UssOD_CalcZoneDistances();
        UssOD_PerformZoneDetection();
#endif

        UssOD_bNewOutputData = ME_TRUE;
    }

    /*
     * If there is new output data then write it to com output buffer.
     * In case of semaphore take fail, try again next task cycle.
     */
    if (UssOD_bNewOutputData == (bool_t)ME_TRUE)
    {
        if (UssOD_PopulateComOutputBuffer() ==(bool_t) ME_TRUE)
        {
            UssOD_bNewOutputData = ME_FALSE;
        }
    }
}


/*===========================================================================
 * \brief Object detection initialization.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_Init
 * Remarks:  DD-ID: {CEEF04F0-0E9D-431d-9E12-0E80EE45F89E}
 * Req.-ID: 13396023
 * Req.-ID: 15031804
 * ===========================================================================*/
void UssOD_Init(void)
{
    UssOD_CreateSortIdxLists();  //added other init too for Triang.c
    UssOD_ClearCycSinceLastMeas();
    UssOD_ClearFiltDistances(ME_TRUE);

#if(USS_FEATURE_ZONE_INFO == US_STD_ON)  
    UssOD_InitZoneData();
#endif

    UssOD_InitPntMinDist();
    UssOD_ResetOdCalcs(ME_TRUE);
}

/*===========================================================================
 * \brief Populate the com output data buffer.
 *
 * \param none
 * \param none
 * \return none
 * \remarks bool_t Writing of com output buffer successful.
 */
/* ===========================================================================
 * Name:	 UssOD_PopulateComOutputBuffer
 * Remarks:  DD-ID: {88DF30A5-10A4-4c83-998F-348874444301}
 * Req.-ID: 15031804
 * Req.-ID: 13420477
 * Req.-ID: 13477648
 * ===========================================================================*/
static bool_t UssOD_PopulateComOutputBuffer(void)
{
    if (UssCom_LockOutputDataBuffer() == (bool_t)ME_TRUE)
    {
        
#if(USS_FEATURE_ZONE_INFO == US_STD_ON) 
        UssCom_F_PopulateZoneInfo(US_GetTimeStampTimeMs(), UssOD_paGetZoneInfo());
#endif
        UssCom_F_PopulatePointMap(UssOD_paGetPointMap());
        UssCom_F_PopulatePointDist(US_GetTimeStampTimeMs(), UssOD_GetPntMinDist(), UssOD_GetPntMidDist());


#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE
        UssCom_F_PopulateDebugPntInfo(UssOD_paGetDebugPntInfo());
#endif
        UssCom_UnlockOutputDataBuffer();

        return ME_TRUE;
    }
    else
    {
        return ME_FALSE;
    }
}

/*===========================================================================
 * \brief Update sensor last measurement counter for each sensor.
 *
 * \param
 * \param
 * \param
 * \return
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_UpdateSnrLastMeasCount
 * Remarks:  DD-ID: {32ACADE4-D23E-47fd-9F13-671C2D89C8B1}
 * Req.-ID: 15031804
 * ===========================================================================*/
static void UssOD_UpdateSnrLastMeasCount(void)
{
    uint8_t uSnrIdx;

    const US_S_SnrCalcs_t * psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();

    /* Scan each sensor if it was selected to measure this cycle */
    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        /* If it was a direct measurement, reset count, else increment */
        if (psSnrCalcs->sSnrCalcRec[uSnrIdx].eEchoClass == US_E_DIRECT)
        {
            uCycSinceLastMeas[uSnrIdx] = ZERO;
        }
        else /* Increment, which indicates a sensor has not been measured recently, and data may now be invalid.*/
        {
            if (uCycSinceLastMeas[uSnrIdx] < (US_D_MAX_NUM_SENSORS << ONE)) /* Just to prevent roll-over. */
            {
                uCycSinceLastMeas[uSnrIdx]++;
            }
        }
    }
}

/*===========================================================================
 * \brief Clear cycles since last measurement array.
 *
 * \param
 * \param
 * \param
 * \return
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_ClearCycSinceLastMeas
 * Remarks:  DD-ID: {EACDF95A-52F6-4417-ADFA-18839BB3A675}
 * Req.-ID: 13396023
 * ===========================================================================*/
static void UssOD_ClearCycSinceLastMeas(void)
{
    uint8_t uSnrIdx;

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        uCycSinceLastMeas[uSnrIdx] = ZERO;
    }
}

/*===========================================================================
 * \brief Returns array that contains number of cycles since a sensor has performed direct measurement.
 *
 * \param
 * \param
 * \param
 * \return uint8_t * Pointer to array that contains number of cycles since a sensor has performed direct measurement.
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_puGetCycSinceLastMeas
 * Remarks:  DD-ID: {47EE067B-2D55-45a7-B92B-E99C46A3EBCA}
 * Req.-ID: 13396023
 * ===========================================================================*/
uint8_t * UssOD_puGetCycSinceLastMeas(void)
{
    return uCycSinceLastMeas;
}
