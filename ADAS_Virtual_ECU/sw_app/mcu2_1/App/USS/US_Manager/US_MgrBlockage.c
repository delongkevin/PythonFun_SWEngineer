/*
 *  US_MgrBlockage.c
 *  Ver 1.20.01.B
 *
 *  Created on: Sep 28, 2021
 *      Author: jonapais
 *  Updated: 2023-04-05, JWR3
 */

#include "US_MgrBlockage.h"
#include "US_SysMgr_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_SnrData_Typedefs_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_Platform_Global.h"
#if (US_D_MGR_BLOCKAGE_ENABLE_HAILMARY == ME_ON)
#include "US_MgrUtility.h"
#endif


/* File unique defines (not cal, not options) */
#define US_D_MBLK_IGNORE_VAL                ZERO   /* value that means check should be ignored/skipped */
#define US_D_MGR_BLOCKAGE_IGNORE_ZERO_RING
#define US_D_MGR_BLOCKAGE_IGNORE_NFD               /* temp until NFD ringtime values are studied */
#define US_BLOCKAGE_MEAS_FIXED              ZERO
#define US_BLOCKAGE_MEAS_CHIRP              ONE
#define US_BLOCKAGE_MEAS_NFD                TWO
#define US_BLOCKAGE_MEAS_MAX                THREE

#if 0
/* Usage Options - should go in calibration */
/* TODO jwr - convert all this into a calibration input*/
#define US_MGR_BLOCKAGE_USE_ICE_RANGE
#define US_D_MGR_BLOCKAGE_IGNORE_NOISY
#define US_D_MGR_BLOCKAGE_USE_HIGH_RING
#define US_D_MGR_BLOCKAGE_USE_DRV_FREQ
#endif

static uint8_t uBlockageCnt[US_D_MAX_NUM_SENSORS];
static uint8_t uBlockageClrCnt[US_D_MAX_NUM_SENSORS];

#if (US_D_MGR_BLOCKAGE_ENABLE_HAILMARY == ME_ON)
uint8_t auHailBlockageConf[US_D_MAX_NUM_SENSORS];
US_Mgr_HailBlockData_t asHailBlockData[US_D_MAX_NUM_SENSORS];
#endif

typedef enum
{
    US_BLOCKAGE_TEMP_TYPE_MUD = ZERO,
    US_BLOCKAGE_TEMP_TYPE_ICE,
    US_BLOCKAGE_TEMP_TYPE_MAX
} US_E_BlockageTempType_t;

/* Sensor type defined in US_SnrData_Typedefs_Global.h */

typedef struct
{
    uint16_t uRingTimeLow_us;
    uint16_t uRingTimeHigh_us;
    uint16_t uDrvFreqLow_Hz;
    uint16_t uDrvFreqHigh_Hz;
    uint16_t uRingFreqLow_Hz;
    uint16_t uRingFreqHigh_Hz;
} US_S_BlockageCals_t;

/* \TODO jwr - these const tables should need to go in calibration */
#ifdef US_MGR_BLOCKAGE_USE_ICE_RANGE
typedef enum
{
    US_TEMPLIM_SNR_TMP = ZERO,
    US_TEMPLIM_AMB_TMP,
    US_TEMPLIM_MAX
} US_E_TempLimitType_t;
/*
 * Remember that internal sensor temperatures have
 * an implied decimal point for the 10ths.
 * ie. 25.2 deg = 252
 */
static sint8_t uTemperatureLimit[US_TEMPLIM_MAX] = {
        [US_TEMPLIM_SNR_TMP] = 50u,
        [US_TEMPLIM_AMB_TMP] = -5u
};
#endif

/* ===========================================================================
Traceability to source Code:
* Req.-ID: 14992373
* Req.-ID: 14992383
 * ===========================================================================*/
#ifdef US_D_MGR_BLOCKAGE_IGNORE_NFD
    #define US_D_OD_BLOCKAGE_SET_COUNT_MAX  (22u)
    #define US_D_OD_BLOCKAGE_CLR_COUNT_MAX  (45u)

#else
    #define US_D_OD_BLOCKAGE_SET_COUNT_MAX  (30u)
    #define US_D_OD_BLOCKAGE_CLR_COUNT_MAX  (60u)
#endif

#if (US_D_MGR_BLOCKAGE_ENABLE_HAILMARY == ME_ON)
const static US_Mgr_HailBlockData_t sHailBlockDataInitVals = {
    .uNormalDistRAvg_10cm = ZERO,
    .uNormalDistRAvgMax_10cm = ZERO,
    .uNormalDistRAvgMin_10cm = 255u,
    #if (US_D_MGR_BHM_FULL_TIME_NFD == ME_ON)
    .uNormalRingMax_20us = ZERO,
    .uNFDRingCur_20us = ZERO,
    .uNFDDistCur_10cm = ZERO
    #else
    .uSamplesTaken = ZERO
    #endif /* US_D_MGR_BHM_FULL_TIME_NFD */
};
void CheckHailMaryBlockage(uint8_t sensor_index);
#endif /* US_D_MGR_BLOCKAGE_ENABLE_HAILMARY */

/*===========================================================================
 * \brief Perform blockage checking algorithm.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Result in US_Diagnostic_SetDTCCode(DTC_SNR_BLOCKAGE)
 */
/* ===========================================================================
 * Name:	 UssMgr_CheckBlockage
 * Remarks:  DD-ID: {60CB3D06-ED3B-41bf-87C0-717D279BD466}
 * Traceability to source Code: Req.-ID: 14992414
 * Req.-ID: 14992434
 * Req.-ID: 14992433
 * Req.-ID: 14992440
 * Req.-ID: 14992448
 * Req.-ID: 14992447
 * Req.-ID: 14992404
 * Req.-ID: 14992403
 * Req.-ID: 14992383
 * Req.-ID: 14992373
 * Req.-ID: 13420729
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexcity */
void UssMgr_CheckBlockage(void)/* PRQA S 2755 */
{
   static const US_S_BlockageCals_t sBlockageCals[US_E_SNR_TYPE_MAX][US_BLOCKAGE_MEAS_MAX][US_BLOCKAGE_TEMP_TYPE_MAX] = 
   {
      [US_E_SNR_TYPE_PDC] = {
            [US_BLOCKAGE_MEAS_FIXED] =
            {
                [US_BLOCKAGE_TEMP_TYPE_MUD] = {.uRingTimeLow_us = 912u, .uRingTimeHigh_us = 1704u, .uDrvFreqLow_Hz = US_D_MBLK_IGNORE_VAL},
                [US_BLOCKAGE_TEMP_TYPE_ICE] = {.uRingTimeLow_us = 960u, .uRingTimeHigh_us = 1704u, .uDrvFreqLow_Hz = US_D_MBLK_IGNORE_VAL}
            },

            [US_BLOCKAGE_MEAS_CHIRP] =
            {
                [US_BLOCKAGE_TEMP_TYPE_MUD] = {.uRingTimeLow_us = 1840u, .uRingTimeHigh_us = 4000u, .uDrvFreqLow_Hz = 48000u},
                [US_BLOCKAGE_TEMP_TYPE_ICE] = {.uRingTimeLow_us = 1840u, .uRingTimeHigh_us = 4000u, .uDrvFreqLow_Hz = 48000u}
            },

            [US_BLOCKAGE_MEAS_NFD] =
            {
                [US_BLOCKAGE_TEMP_TYPE_MUD] = {.uRingTimeLow_us = 0, .uRingTimeHigh_us = 4000u, .uDrvFreqLow_Hz = US_D_MBLK_IGNORE_VAL},
                [US_BLOCKAGE_TEMP_TYPE_ICE] = {.uRingTimeLow_us = 0, .uRingTimeHigh_us = 4000u, .uDrvFreqLow_Hz = US_D_MBLK_IGNORE_VAL}
            }
    },

    [US_E_SNR_TYPE_PSM] = {
            [US_BLOCKAGE_MEAS_FIXED] =
            {
                [US_BLOCKAGE_TEMP_TYPE_MUD] = {.uRingTimeLow_us = 1072u, .uRingTimeHigh_us = 1864u, .uDrvFreqLow_Hz = US_D_MBLK_IGNORE_VAL},
                [US_BLOCKAGE_TEMP_TYPE_ICE] = {.uRingTimeLow_us = 1120u, .uRingTimeHigh_us = 1864u, .uDrvFreqLow_Hz = US_D_MBLK_IGNORE_VAL}
            },

            [US_BLOCKAGE_MEAS_CHIRP] =
            {
                [US_BLOCKAGE_TEMP_TYPE_MUD] = {.uRingTimeLow_us = 1820u, .uRingTimeHigh_us = 4000u, .uDrvFreqLow_Hz = 48000u},
                [US_BLOCKAGE_TEMP_TYPE_ICE] = {.uRingTimeLow_us = 1820u, .uRingTimeHigh_us = 4000u, .uDrvFreqLow_Hz = 48000u}
            },

            [US_BLOCKAGE_MEAS_NFD] =
            {
                [US_BLOCKAGE_TEMP_TYPE_MUD] = {.uRingTimeLow_us = 0, .uRingTimeHigh_us = 4000u, .uDrvFreqLow_Hz = US_D_MBLK_IGNORE_VAL},
                [US_BLOCKAGE_TEMP_TYPE_ICE] = {.uRingTimeLow_us = 0, .uRingTimeHigh_us = 4000u, .uDrvFreqLow_Hz = US_D_MBLK_IGNORE_VAL}
            }
    }
    };
    bool_t bIgnoreThisTime;
    uint8_t uSnrIdx;
    uint8_t eMeasType;
	uint8_t const *uSnrType;
    uint32_t uBitMap;
    uint8_t uBlockageOld[US_D_MAX_NUM_SENSORS];
    US_E_SnrType_t eSnrType;
    US_E_BlockageTempType_t eBlockageTempType;
    US_S_BlockageCals_t * psBlockageBounds;
    US_E_SendType_t eSendType;
#ifdef US_MGR_BLOCKAGE_USE_ICE_RANGE
	US_E_TempLimitType_t eTempLimitType;
	float32_t	fAmbTemperature;
#endif


    const US_S_RingTime_t * psRingTime;
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    uSnrType = UssCtrl_psGetSensorType();

#ifdef US_MGR_BLOCKAGE_USE_ICE_RANGE
    const US_S_Sensor_Temperature_t * psSnrTemperatures;

    if ( UssCom_F_GetAmbientTempValidity() == US_TEMPVALID_VALID )
	{
		fAmbTemperature = UssCom_F_GetAmbientTemp();
        eTempLimitType = US_TEMPLIM_AMB_TMP;
	}
	else
	{
		/* use sensor temperature instead */
		psSnrTemperatures = UssSnrCmd_psGetSnrTemperatures();
        eTempLimitType = US_TEMPLIM_SNR_TMP;
	}
#endif

#ifdef US_D_MGR_BLOCKAGE_IGNORE_NOISY
    if( UssMgr_IsAnyGroupNoisy() == ME_FALSE )
    {
#endif
        /* Init selections */
        bIgnoreThisTime = ME_FALSE; //init ignore flag
        eMeasType = (uint8_t)US_BLOCKAGE_MEAS_FIXED;
        eSnrType = US_E_SNR_TYPE_PDC;
        eBlockageTempType = US_BLOCKAGE_TEMP_TYPE_MUD;
        eSendType = US_E_REQ_SEND_NORMAL;
        
        /* Loop though all the sensors */
        for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     /* Scan all sensor positions */
        {
            uBitMap = (uint32_t)US_IDX_TO_BIT_LOC(uSnrIdx);

            /* Are we receiving, if not then nothing to check */
            if (   ((psSnrMeasRec->uSendingSensors & uBitMap) != ZERO)
                && ((psSnrMeasRec->uResponseReceived & uBitMap) != ZERO) )
            {
#if (US_D_MGR_BLOCKAGE_ENABLE_HAILMARY == ME_ON)
                CheckHailMaryBlockage(uSnrIdx);
#endif
                /* Get the ring time and sensor type */
                psRingTime = &psSnrMeasRec->sSensorRec[uSnrIdx].sRingTime;
                eSnrType = (US_E_SnrType_t)uSnrType[uSnrIdx];
                eSendType = psSnrMeasRec->sSensorRec[uSnrIdx].eEchoTypeRequested;
#ifdef US_D_MGR_BLOCKAGE_IGNORE_NFD
                if( eSendType == US_E_REQ_SEND_NFD ) {bIgnoreThisTime = ME_TRUE;}
#endif
#ifdef US_D_MGR_BLOCKAGE_IGNORE_ZERO_RING
                if( psRingTime->uRingTime == ZERO ) {bIgnoreThisTime = ME_TRUE;}
#endif
                if((bool_t) ME_FALSE == bIgnoreThisTime )
                {
#ifdef US_MGR_BLOCKAGE_USE_ICE_RANGE
                    /* select which temperature source to use */ 
                    if ( US_TEMPLIM_AMB_TMP == eTempLimitType )
                    {
                        if( fAmbTemperature > uTemperatureLimit[US_TEMPLIM_AMB_TMP] )
                        {
                            eBlockageTempType = US_BLOCKAGE_TEMP_TYPE_MUD;
                        }
                        else
                        {
                            eBlockageTempType = US_BLOCKAGE_TEMP_TYPE_ICE;
                        }
                    }
                    else /*assume external*/
                    {
                        /* This else protects psSnrTemperatures from being accessed without being set */
                        if (   (psSnrTemperatures->iSnrTemperature[uSnrIdx] > uTemperatureLimit[US_TEMPLIM_SNR_TMP])
                            || (psSnrTemperatures->uTimeStamp == ZERO))           /* Temperature hasn't been measured yet */
                        {
                            eBlockageTempType = US_BLOCKAGE_TEMP_TYPE_MUD;
                        }
                        else
                        {
                            eBlockageTempType = US_BLOCKAGE_TEMP_TYPE_ICE;
                        }
                    }
#else
                    /* without temp information, use MUD cases */
                    eBlockageTempType = US_BLOCKAGE_TEMP_TYPE_MUD;
#endif

                /*
                 * Check for blockage and set counts accordingly.
                 */
                if (eSendType == US_E_REQ_SEND_NORMAL)
                {
                    eMeasType = (uint8_t) US_BLOCKAGE_MEAS_FIXED;
                }
                else if (   (eSendType == US_E_REQ_SEND_CHIRP_UP)
                         || (eSendType == US_E_REQ_SEND_CHIRP_DOWN))
                {
                    eMeasType = (uint8_t)US_BLOCKAGE_MEAS_CHIRP;
                }
                else if (eSendType == US_E_REQ_SEND_NFD)/* PRQA S 2992,2996,1575 *//*KPK-QAC Fix : Need to suppress,dead code at present */
                {
                    eMeasType = (uint8_t) US_BLOCKAGE_MEAS_NFD;
                }
                else
                {
                           /*Do Nothing*/
                }

                /* Find the bounds, given sensor type, measurement type, and temperature based bounds */
                psBlockageBounds = (US_S_BlockageCals_t *)&sBlockageCals[eSnrType][eMeasType][eBlockageTempType];

#ifdef US_D_MGR_BLOCKAGE_USE_HIGH_RING
                /* Check failure of blockage test */
                if (   (psRingTime->uRingTime < psBlockageBounds->uRingTimeLow_us)
                    || (psRingTime->uRingTime > psBlockageBounds->uRingTimeHigh_us))
#else
				if ( psRingTime->uRingTime < psBlockageBounds->uRingTimeLow_us )
#endif
                {
                    uBlockageCnt[uSnrIdx]++;
                    if (uBlockageCnt[uSnrIdx] >= US_D_OD_BLOCKAGE_SET_COUNT_MAX)
                    {
                        uBlockageCnt[uSnrIdx] = US_D_OD_BLOCKAGE_SET_COUNT_MAX; /* Limit max */
                        uBlockageClrCnt[uSnrIdx] = ZERO;                        /* Clear the blockage clear counter */

                        /*
                         * WE HAVE BLOCKAGE
                         */
                        /*KPK core Diag */
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                        US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_BLOCKAGE, US_IDX_TO_BIT_LOC(uSnrIdx));
#else                         
                        US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_BLOCKAGE, uSnrIdx);
                        uBlockageOld[uSnrIdx] = 1;
#endif
                    }
                }
                else /* Normal conditions/recovery handling. */
                {
                    if (uBlockageCnt[uSnrIdx] > ZERO)
                    {
                        uBlockageClrCnt[uSnrIdx]++;
                        if (uBlockageClrCnt[uSnrIdx] >= US_D_OD_BLOCKAGE_CLR_COUNT_MAX)
                        {
                            uBlockageClrCnt[uSnrIdx] = ZERO; /* Reset clear count if case of intermittent blockage. */
                            uBlockageCnt[uSnrIdx] = ZERO;    /* Clear the blockage counter */

                            /*
                             * BLOCKAGE CLEARED
                             */
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                            US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_BLOCKAGE, US_IDX_TO_BIT_LOC(uSnrIdx));
#else                       
                            US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_BLOCKAGE, uSnrIdx);
                            uBlockageOld[uSnrIdx] = 0;

#endif

                        }
                    }
                    else /* blockage isn't intermittent, clear DTC continuously */
                    {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    	US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_BLOCKAGE, US_IDX_TO_BIT_LOC(uSnrIdx));
#else                          
                        US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_BLOCKAGE, uSnrIdx);
                        uBlockageOld[uSnrIdx] = 0;
#endif
                     }
                  }
                }
            }
        } /* for loop */
#ifdef US_D_MGR_BLOCKAGE_IGNORE_NOISY
    }
#endif
}

#if (US_D_MGR_BLOCKAGE_ENABLE_HAILMARY == ME_ON)
/* Experimental Hail mary blockage for movement */
/* Called after sensor is checked to have fired */
/* ===========================================================================
 * Name: CheckHailMaryBlockage	
 * Remarks:  DD-ID: {1EA1F9F6-D047-4467-91A0-99D33D32D1AD}
 * ===========================================================================*/
void CheckHailMaryBlockage(uint8_t sensor_index)
{
    US_E_SendType_t eSendType;
    /* const US_S_RingTime_t * psRingTime; */
    uint16_t uRingTime1us;
    /* extern sint16_t UssDBG_preProcessTotalDistArray[US_D_MAX_NUM_SENSORS][THREE]; */
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    const US_S_SensorMeasDist_t *const psSnrMeasDist = UssMgr_psGetCurSnrMeasRecDist();
    uint16_t u16Temp, uNewDist = ZERO;

    if( UssMgr_IsSensSide(sensor_index) == ME_TRUE ) { return; /* SKIPPPP */}
    if( UssMgr_GetVehSpeed() < US_D_MGR_BHM_ENABLE_SPEED ) { return; /* SKIPPPP */}
    eSendType = psSnrMeasRec->sSensorRec[sensor_index].eEchoTypeRequested;
    /* psRingTime = &psSnrMeasRec->sSensorRec[uSnrIdx].sRingTime; */
    uRingTime1us = psSnrMeasRec->sSensorRec[sensor_index].sRingTime.uRingTime;

    #if (US_D_MGR_BHM_FULL_TIME_NFD == ME_ON)
    /* is this Normal? just Collect data */
    if(eSendType == US_E_REQ_SEND_NORMAL)
    {
        /* saving only highest ring example - no need to avg */
        if(asHailBlockData[sensor_index].uNormalRingMax_20us < (uRingTime1us / 20u))
        {
            asHailBlockData[sensor_index].uNormalRingMax_20us = (uRingTime1us / 20u);
        }
        /* Clean input */
        if(UssDBG_preProcessTotalDistArray[sensor_index][ZERO] > ZERO)
        {
            uNewDist = (uint16_t)(UssDBG_preProcessTotalDistArray[sensor_index][ZERO] / 20); /* div 20 from div10 + div2 */
        }
        if(uNewDist != ZERO)
        {
            /* Check if any current avg exist - then update. Simple running avg with no history */
            if(asHailBlockData[sensor_index].uNormalDistRAvg_10cm == ZERO)
            {
                asHailBlockData[sensor_index].uNormalDistRAvg_10cm = uNewDist;
            }
            else
            {
                u16Temp = uNewDist + asHailBlockData[sensor_index].uNormalDistRAvg_10cm;
                asHailBlockData[sensor_index].uNormalDistRAvg_10cm = (uint8_t)(u16Temp / 2u);
            }
            if(asHailBlockData[sensor_index].uNormalDistRAvgMin_10cm > asHailBlockData[sensor_index].uNormalDistRAvg_10cm) 
            {
                asHailBlockData[sensor_index].uNormalDistRAvgMin_10cm = asHailBlockData[sensor_index].uNormalDistRAvg_10cm;
            }
            if(asHailBlockData[sensor_index].uNormalDistRAvgMax_10cm < asHailBlockData[sensor_index].uNormalDistRAvg_10cm) 
            {
                asHailBlockData[sensor_index].uNormalDistRAvgMax_10cm = asHailBlockData[sensor_index].uNormalDistRAvg_10cm;
            }
        }
    }
    /* is this NFD? do the main logic */
    if(eSendType == US_E_REQ_SEND_NFD)
    {
        sint8_t uConfGrowth = 0;
        /* Does normal ringtime tell us there is a close obj but not touching? */
        if(asHailBlockData[sensor_index].uNormalRingMax_20us >= US_D_MGR_BHM_BAD_NORM_RING_20us)
        {
            uConfGrowth++;
        }
        /* Does the normal dist stay steady even though vehicle is moving? */
        if(asHailBlockData[sensor_index].uNormalDistRAvg_10cm <= US_D_MGR_BHM_CLOSE_NORM_RANGE_10cm)
        {
            u16Temp = (asHailBlockData[sensor_index].uNormalDistRAvgMax_10cm - asHailBlockData[sensor_index].uNormalDistRAvgMin_10cm);
            if(u16Temp <= US_D_MGR_BHM_AVG_FLUX_10cm)
            {
                uConfGrowth++;
            }
        }
        /* Do we have NFD echoes even though vehicle is moving? */
        if(UssDBG_preProcessTotalDistArray[sensor_index][ZERO] > ZERO)
        {
            uConfGrowth++;
        }
        /* Do we also have a high NFD ringtime telling us there is a close obj? */
        asHailBlockData[sensor_index].uNFDRingCur_20us = uRingTime1us;
        if(asHailBlockData[sensor_index].uNFDRingCur_20us >= US_D_MGR_BHM_BAD_NFD_RING_20us)
        {
            uConfGrowth++;
        }
        
        /* Turn collected passes into actual conf adjustment */
        /*  4/4 pass -> +2 Grow blocked confidence
            3/4 pass -> +1 Grow
            2/4 pass -> +0 / No action
            0/4 or 1/4 pass -> -1 loss
        */
        uConfGrowth = (uConfGrowth - 2);
        if(uConfGrowth < -1) {uConfGrowth = -1;}
        /* use uConfGrowth to hold total for a bit */
        if( (auHailBlockageConf[sensor_index] > ZERO)
        || ((auHailBlockageConf[sensor_index] == ZERO) && (uConfGrowth > ZERO)) )
        {
            auHailBlockageConf[sensor_index] = uConfGrowth + (sint8_t)auHailBlockageConf[sensor_index];
        }
        if(auHailBlockageConf[sensor_index] > US_D_MGR_BHM_CONF_MAX) {auHailBlockageConf[sensor_index] = US_D_MGR_BHM_CONF_MAX;}

        //reset some normal data
        asHailBlockData[sensor_index].uNormalDistRAvgMin_10cm = 255u;
        asHailBlockData[sensor_index].uNormalDistRAvgMax_10cm = ZERO;
    }
    /* else chirp - skip for now */
    #else /* #if (US_D_MGR_BHM_FULL_TIME_NFD == ME_ON) */
    /* Logic if NFD is limited to crawling speed only */
    if(eSendType == US_E_REQ_SEND_NORMAL)
    {
        sint8_t uConfGrowth = 0;
        /* Clean input */
        if(psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[ZERO] > ZERO)
        {
            uNewDist = (uint16_t)(psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[ZERO] / 20); /* div 20 from div10 + div2 */
        }
        if(uNewDist != ZERO)
        {
            /* Check if any current avg exist - then update. Simple running avg with no history */
            if(asHailBlockData[sensor_index].uNormalDistRAvg_10cm == ZERO)
            {
                asHailBlockData[sensor_index].uNormalDistRAvg_10cm = uNewDist;
            }
            else
            {
                u16Temp = uNewDist + asHailBlockData[sensor_index].uNormalDistRAvg_10cm;
                asHailBlockData[sensor_index].uNormalDistRAvg_10cm = (uint8_t)(u16Temp / 2u);
            }
            if(asHailBlockData[sensor_index].uNormalDistRAvgMin_10cm > asHailBlockData[sensor_index].uNormalDistRAvg_10cm) 
            {
                asHailBlockData[sensor_index].uNormalDistRAvgMin_10cm = asHailBlockData[sensor_index].uNormalDistRAvg_10cm;
            }
            if(asHailBlockData[sensor_index].uNormalDistRAvgMax_10cm < asHailBlockData[sensor_index].uNormalDistRAvg_10cm) 
            {
                asHailBlockData[sensor_index].uNormalDistRAvgMax_10cm = asHailBlockData[sensor_index].uNormalDistRAvg_10cm;
            }
            asHailBlockData[sensor_index].uSamplesTaken++;
        }
        else 
        {
            /*if(asHailBlockData[sensor_index].uSamplesTaken > ZERO) { asHailBlockData[sensor_index].uSamplesTaken--; }*/
        }
        
        /* Enough samples exist, start evaluation */
        if(asHailBlockData[sensor_index].uSamplesTaken >= US_D_MGR_BHM_NORM_MIN_SAMPLES)
        {
            /* Does normal ringtime tell us there is a close obj but not touching? */
            if(uRingTime1us >= (US_D_MGR_BHM_BAD_NORM_RING_20us * 20u))
            {
                uConfGrowth++;
            }
            if(uNewDist != ZERO)
            {
                /* Does the normal dist stay steady even though vehicle is moving? */
                if(asHailBlockData[sensor_index].uNormalDistRAvg_10cm <= US_D_MGR_BHM_CLOSE_NORM_RANGE_10cm)
                {
                    u16Temp = (asHailBlockData[sensor_index].uNormalDistRAvgMax_10cm - asHailBlockData[sensor_index].uNormalDistRAvgMin_10cm);
                    if(u16Temp <= US_D_MGR_BHM_AVG_FLUX_10cm)
                    {
                        uConfGrowth++;
                    }
                }
                /* Do we have maxed out echo height? */
                if(psSnrMeasRec->sSensorRec[sensor_index].sEcho[ZERO].uEchoHeight == 255u)
                {
                    uConfGrowth++;
                }
            }
            /* Turn collected passes into actual conf adjustment
                3/3 pass -> +1 Grow
                2/3 pass -> +0 / No action
                0/3 or 1/3 pass -> -1 loss
            */
            uConfGrowth = (uConfGrowth - 2);
            if(uConfGrowth < -1) {uConfGrowth = -1;}
            /* use uConfGrowth to hold total for a bit */
            if( (auHailBlockageConf[sensor_index] > ZERO)
            && ((auHailBlockageConf[sensor_index] == ZERO) && (uConfGrowth > ZERO)) )
            {
                auHailBlockageConf[sensor_index] = uConfGrowth + (sint8_t)auHailBlockageConf[sensor_index];
            }
            if(auHailBlockageConf[sensor_index] > US_D_MGR_BHM_CONF_MAX) {auHailBlockageConf[sensor_index] = US_D_MGR_BHM_CONF_MAX;}
        }

        /* reset some normal data if max samples taken OR samples drop to zero */
        if( (asHailBlockData[sensor_index].uSamplesTaken >= US_D_MGR_BHM_NORM_RESET_SAMPLES) 
        || (asHailBlockData[sensor_index].uSamplesTaken == ZERO) )
        {
            u16Temp = asHailBlockData[sensor_index].uNormalDistRAvg_10cm;
            asHailBlockData[sensor_index] = sHailBlockDataInitVals;
            asHailBlockData[sensor_index].uNormalDistRAvg_10cm = u16Temp;
        }
    } /* US_E_REQ_SEND_NORMAL */
    #endif /* #if (US_D_MGR_BHM_FULL_TIME_NFD == ME_ON) */
}

/* public debug func */
/* ===========================================================================
 * Name: UssMgr_DBG_uGetBHM_DistRAvg	
 * Remarks:  DD-ID:{BB064AF7-09A8-439c-93C4-8B7AC34A3E13}
 * ===========================================================================*/
uint8_t UssMgr_DBG_uGetBHM_DistRAvg(uint8_t sensor_index)
{
    return asHailBlockData[sensor_index].uNormalDistRAvg_10cm;
}
#endif /* US_D_MGR_BLOCKAGE_ENABLE_HAILMARY */


/*===========================================================================
 * \brief Initialize blockage algo counts.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssMgr_BlockageInit
 * Remarks:  DD-ID: {8C157D94-72FF-4c30-9D03-B3D56FC2CFC4}
 * Req.-ID: 14992447
 * ===========================================================================*/
void UssMgr_BlockageInit(void)
{
    uint8_t uSnrIdx;

    /* Reset blockage counters */
    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        uBlockageCnt[uSnrIdx] = ZERO;
        uBlockageClrCnt[uSnrIdx] = ZERO;
#if (US_D_MGR_BLOCKAGE_ENABLE_HAILMARY == ME_ON)
        auHailBlockageConf[uSnrIdx] = US_D_MGR_BHM_CONF_INIT;
        asHailBlockData[uSnrIdx] = sHailBlockDataInitVals;
#endif /* US_D_MGR_BLOCKAGE_ENABLE_HAILMARY */
    }


}

/* ===========================================================================
 * Name:	 UssMgr_uGetBlockCntArray
 * Remarks:  DD-ID: {C3EC61AE-66A2-4ce0-B007-E25388C765CF}
 * Req.-ID:14992373
 * ===========================================================================*/
uint8_t * UssMgr_uGetBlockCntArray(void)
{
    return uBlockageCnt;
}

/* ===========================================================================
 * Name:	 UssMgr_uGetBlockClrCntArray
 * Remarks:  DD-ID: {B1B6E270-2E8E-4b5c-A23E-5F2776244D0A}
 * Req.-ID:14992383
 * ===========================================================================*/
uint8_t * UssMgr_uGetBlockClrCntArray(void)
{
    return uBlockageClrCnt;
}
