/*
 * US_MgrSensorProc.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#include "US_ME_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_Platform_Global.h"
#include "US_MgrInterface.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_MgrEnvCheck.h"
#include "US_MgrSensorProc.h"
#include "US_MgrUtility.h"
#include "US_MgrModeControl.h"
#include "US_MgrFilter.h"
#include "US_MgrBlockage.h"
#include "US_SysMgr_Global.h"
#include "US_MgrPlatformSpecific.h"
#include "US_Ctrl_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_MgrDiagnostic.h"
#include "US_Diagnostic_Global.h"
#include "US_MgrHeightAlgo.h"

#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
    #include "Siul2_Port_Ip.h"
    #include "Siul2_Dio_Ip.h"
    #include "Application_Header.h"
    static uint32 uDebugOutputCount;
#endif

static uint16_t UssCmd_uCalcDistFromTimeOfFlight(uint16_t uTime, float32_t fAmbientTemperature, bool_t isNFD);

static void UssMgr_CopySnrMeasRecord(US_S_SensorMeasRecs_t *psSnrMeasRec, const US_S_SensorMeasRcvRecs_t *psSnrCmdMeasRcvRecPtr);
static void UssMgr_CalulateDistFromTof(void);
static void UssMgr_SetCurSnrMeasRecIdx(uint8_t uCurSnrIdx);
static uint8_t UssMgr_uGetNextSnrMeasRecIdx(void);
static void UssMgr_PreFilterEchoes(const US_S_SensorMeasRcvRecs_t *psSnrCmdMeasRcvRecPtr);


#define US_D_MGR_PREFILTER_ENABLED
#ifdef US_D_MGR_PREFILTER_ENABLED
    //#define US_D_MGR_PREFILTER_CHIRP
#endif
/*
 * These defines will most likely be used but aren't at this moment
 */
#define aUSS_D_DistCalib              (3.0f)//(5) //cm
#define aUSS_D_DistCalibNFD           (2.5f)//(5) //cm
/*
 * END:  These defines will most likely be used but aren't at this moment
 */

//#define US_D_TIME_PER_BURST_US         ((float32_t) 1e6f / 49200.0f)
#define US_D_TOF_COMPENSATION_ENABLED  (ME_TRUE)
#define US_D_SENSOR_DEFAULT_DRV_FREQ    (49200u) // should get from calibration probably...
#define US_D_SENSOR_BURST_COEFF         (1000000u) //should be this number no matter what
#define US_D_TIME_PER_BURST_US        (US_D_SENSOR_BURST_COEFF / US_D_SENSOR_DEFAULT_DRV_FREQ)  
#define US_D_TOF_TEMP_DEFAULT           (20.0f)


/* explicitly defined for future safety values */
const static US_S_EchoCalc_t gsEmptyEchoCalc = 
{
    .uDirectDist_cm = US_D_MGR_UNKNOWN_ECHO_DIST_U16,
    .uTotalDist_cm = US_D_MGR_UNKNOWN_ECHO_DIST_U16,
#ifdef US_D_TOF_STORAGE_ENABLED
    .uTOF_us = US_D_MGR_UNKNOWN_TOF_U16,
#endif
    .uSignalStrength = US_D_MGR_UNKNOWN_SIGSTR_U16,
    .bLargeObject = ME_FALSE,
    .bLargeFAPAObject = ME_FALSE,
    .uEchoCalcFlags = US_D_CALCFLAG_DELETED,
    .uRecEchoIndex = US_D_APP_MAX_ECHOES_BUFF
};

/*
 * Main sensor echo data structure.
 */
static US_S_SensorMeasRecs_t sSnrMeasRec[US_D_APP_MAX_MEAS_BUFF_SIZE];
static US_S_SnrCalcs_t sSnrCalcs[US_D_APP_MAX_MEAS_BUFF_SIZE];

static uint8_t uNumSnrMeasRecs    = ZERO;
static uint8_t uCurSnrMeasRecIdx  = ZERO; // no valid data to start
static volatile uint8_t bIsMgrNewSnrData = ME_FALSE;

//#ifdef US_D_MGR_PREFILTER_ENABLED
static uint8_t g_auGoodEchoIndexes[US_D_MAX_NUM_SENSORS][US_D_APP_MAX_MEAS_BUFF_SIZE];
uint8_t UssDBG_preFiltDebug[US_D_MAX_NUM_SENSORS][THREE];
uint32_t UssDBG_usedFaultMap;


//#endif
static US_S_SensorMeasDist_t g_sPreProcessTotalDist;
const static uint8_t aUssMgr_ChirpCNDelayTable[EIGHT] = { 4, 6, 8, 10, 12, 12, 12, 12 };
const static uint8_t aUssMgr_ChirpCWDelayTable[EIGHT] = { 4, 6, 8, 10, 12, 14, 16, 16 };

#ifdef US_D_GATHER_RUNTIME_STATS
extern US_S_DebugTimerStat_t g_UssDbg_DNN_TimeStats;
extern US_S_DebugTimerStat_t g_UssDbg_BlockageDNN_TimeStats;
#endif
/*===========================================================================
 * \brief Copy new sensor measurement data into manager ring buffer.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Sets bIsNewSnrData when complete.
 */
/* ===========================================================================
 * Name:	 UssMgr_CopyNewSnrDataToBuffer
 * Remarks:  DD-ID: {8C5EA37E-6632-4c48-B7CE-ACE75B101050}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssMgr_CopyNewSnrDataToBuffer(void)
{
    if (UssCtrl_bIsNewSensorData() == (bool_t)ME_TRUE)
    {
        uint8_t uNextRecIdx = UssMgr_uGetNextSnrMeasRecIdx();
        const US_S_SensorMeasRcvRecs_t *psMeasRcvRecPtr = UssSnrCmd_psGetMeasRcvRecPtr();

        (void)UssMgr_CheckMeasurmentForErrors(psMeasRcvRecPtr);  // Check data for errors that would invalidate it.
#ifdef US_D_MGR_PREFILTER_ENABLED
        UssMgr_PreFilterEchoes(psMeasRcvRecPtr);  //check validity, mostly for chirp
#endif
        UssMgr_CopySnrMeasRecord(&sSnrMeasRec[uNextRecIdx], psMeasRcvRecPtr);  // Copy measurement data.

        (void)memset(&sSnrCalcs[uNextRecIdx], ZERO, sizeof(US_S_SnrCalcs_t));  // Clear calculation for this data.

        UssMgr_SetCurSnrMeasRecIdx(uNextRecIdx); // Update ring buffer index to point to new data.

        bIsMgrNewSnrData = ME_TRUE; // Inform application that new data is available.

#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
        // Blink the LED every 20 times valid data is received.
        // \TODO jp - Make a function for this.
#ifdef USS_DEBUG
        uDebugOutputCount++;
        if((uDebugOutputCount % TWENTY) == ZERO)
        {
            SIUL2_0->GPDO18 ^= BIT0;

            pam_uart_send_data("GDRCV:\r\n");

        }
#endif
#endif

        UssCtrl_ClearNewSensorDataFlag();  // Inform Controller that we have read the data into Mgr ring buffer.
    }
    else
    {
        bIsMgrNewSnrData = ME_FALSE; // No new data this cycle to process.
    }
}


/*===========================================================================
 * \brief Perform data processing
 *
 * \param none
 * \param none
 * \return none
 * \remarks Sets bIsNewSnrData when complete.
 */
/* ===========================================================================
 * Name:	 UssMgr_SensorDataProc
 * Remarks:  DD-ID: {558E5055-7DE9-48a7-BE1C-02EB2A983B09}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssMgr_SensorDataProc(void)
{
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec(); /* TODO Pull this data as a function input */

#ifdef US_D_GATHER_RUNTIME_STATS
    static uint8_t uDbgTimer_NeverRan = 0x00;
    if(uDbgTimer_NeverRan == 0x00) 
    {
        US_DbgTimerReset(&g_UssDbg_DNN_TimeStats);
        US_DbgTimerReset(&g_UssDbg_BlockageDNN_TimeStats);
        uDbgTimer_NeverRan = 0xFF;
    }
#endif
    /* add more info to sensor data */
    UssMgr_ClassifyMeasurementType(); //\TODO jwr - move from MgrFilter to this file
    UssMgr_CalulateDistFromTof();
    UssMgr_CalcSignalStrength();  //\TODO jwr - move from MgrFilter to this file
    /* CalcSignalStrengh needs to happen BEFORE any echo add/remove/change */

    /* Skip filtering if listen only cycle */
    if ( psSnrMeasRec->uSendingSensors > ZERO ) /* Consider making this a global flag anyone can check */
    {
        /* filter out echoes that are not needed/bad */
        UssMgr_CheckMeasurementRange();
        UssMgr_FilterGainAndCutoff();
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerSaveStartTime(&g_UssDbg_DNN_TimeStats);
#endif
        USSMgr_HeightEstimationRNN();  
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerUpdate(&g_UssDbg_DNN_TimeStats);
#endif
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerSaveStartTime(&g_UssDbg_BlockageDNN_TimeStats);
#endif
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerUpdate(&g_UssDbg_BlockageDNN_TimeStats);
#endif
    	UssMgr_HandleMultipleEchoes();
        UssMgr_AddAndAdjustEchoes();
	}

    /* handle diag and noise */
    UssMgr_CheckBlockage();
    UssMgr_CheckEnvironmentNoise();
    //UssMgr_FilterNoiseEchoes();
    UssMgr_CheckSensorTemperature();

    // Set flag for OD to operate on this data.
}



/*===========================================================================
 * \brief Return the next index in the sensor measurement ring buffer.
 *
 * \param none
 * \param none
 * \return uint8_t Index to the next storage location in ring buffer.
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_uGetNextSnrMeasRecIdx
 * Remarks:  DD-ID: {998B98BC-3FB6-4e62-BC04-97D6E2871FD0}
 * Req.-ID: 13424090
 * ===========================================================================*/
static uint8_t UssMgr_uGetNextSnrMeasRecIdx(void)
{
    uint8_t uNextRecIdx = uCurSnrMeasRecIdx;
    if (uNumSnrMeasRecs != ZERO)
    {
        uNextRecIdx++;

        if (uNextRecIdx >= US_D_APP_MAX_MEAS_BUFF_SIZE)
        {
            uNextRecIdx = ZERO;
        }
    }
    return uNextRecIdx;

}

/*===========================================================================
 * \brief Set the ring buffer index of the current sensor measurement.
 *
 * \param uint8_t Index to the latest storage location in ring buffer.
 * \param none
 * \return none
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_SetCurSnrMeasRecIdx
 * Remarks:  DD-ID: {1D8D2D52-32EE-4663-884A-96F000C61328}
 * Req.-ID: 13424090
 * ===========================================================================*/
static void UssMgr_SetCurSnrMeasRecIdx(uint8_t uCurSnrIdx)
{
    uCurSnrMeasRecIdx = uCurSnrIdx;

    /* Only active for the first cycles of storage while ring buffer fills */
    if (uNumSnrMeasRecs < US_D_APP_MAX_MEAS_BUFF_SIZE)
    {
        uNumSnrMeasRecs++;
    }
}

/*===========================================================================
 * \brief Set the ring buffer index of the current sensor measurement.
 *
 * \param none
 * \param none
 * \return uint8_t Index to the current sensor measurement in ring buffer.
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssMgr_uGetCurSnrMeasRecIdx
 * Remarks:  DD-ID: {40F03F61-1D1B-4e94-BF4C-52BA4D764C46}
 * ===========================================================================*/
uint8_t UssMgr_uGetCurSnrMeasRecIdx(void)
{
    return uCurSnrMeasRecIdx;
}

/*===========================================================================
 * \brief Returns number of measurements in the ring buffer.
 *
 * \param none
 * \param none
 * \return uint8_t Number of sensor measurements in ring buffer.
 * \remarks After initial cycles, remains at max records in ring buffer.
 */
/* ===========================================================================
 * Name:	 UssMgr_uGetNumSnrMeasRecs
 * Remarks:  DD-ID: {21DDB869-490C-4422-9270-F5CF2F276041}
 * ===========================================================================*/
uint8_t UssMgr_uGetNumSnrMeasRecs(void)
{
    return uNumSnrMeasRecs;
}

/*===========================================================================
 * \brief Returns pointer to measurement in the ring buffer by index.
 *
 * \param uint8_t Index to desired measurement in the ring buffer.
 * \param none
 * \return  US_S_VehicleSensorRecs_t * pointer to desired measurement in the ring buffer.
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssMgr_psGetSnrMeasRec
 * Remarks:  DD-ID: {3B7A3CC4-2D53-48b3-B095-3E0D106E5C24}
 * ===========================================================================*/
const US_S_SensorMeasRecs_t *UssMgr_psGetSnrMeasRec(uint8_t uRecIdx)
{
    return &sSnrMeasRec[uRecIdx];
}

/*===========================================================================
 * \brief Returns pointer to current measurement in the ring buffer.
 *
 * \param none
 * \param none
 * \return US_S_VehicleSensorRecs_t * pointer to current measurement in the ring buffer.
 * \remarks The main vehicle sensor record data, accessor for application - Read only
 */
/* ===========================================================================
 * Name:	 UssMgr_psGetCurSensorMeasRec
 * Remarks:  DD-ID: {50A771CE-C086-4d0e-B9FC-A310EE1FDB2E}
 * Req.-ID: 14996093
 * Req.-ID:14996211
 * ===========================================================================*/
const US_S_SensorMeasRecs_t *UssMgr_psGetCurSensorMeasRec(void)
{
    return &sSnrMeasRec[uCurSnrMeasRecIdx];
}

/*===========================================================================
 * \brief Returns pointer to current measurement calculations in the ring buffer.
 *
 * \param none
 * \param none
 * \return US_S_SnrCalcs_t * pointer to current measurement calculations in the ring buffer.
 * \remarks The main vehicle sensor record calc data, accessor for application - Read/Write
 */
/* ===========================================================================
 * Name:	 UssMgr_psGetSnrCalcsRec
 * Remarks:  DD-ID: {FAFD3CD4-3785-4ae8-AD07-E8EA40942E7E}
 * ===========================================================================*/
US_S_SnrCalcs_t *UssMgr_psGetSnrCalcsRec(uint8_t uRecIdx)
{
    return &sSnrCalcs[uRecIdx];
}

/*===========================================================================
 * \brief Returns pointer measurement calculations in the ring buffer by index.
 *
 * \param none
 * \param none
 * \return US_S_SnrCalcs_t * pointer to measurement calculations in the ring buffer by index.
 * \remarks The main vehicle sensor record calc data, accessor for application - Read/Write
 */
/* ===========================================================================
 * Name:	 UssMgr_psGetCurSnrCalcsRec
 * Remarks:  DD-ID: {8EFA3723-679F-4093-B1E0-03DB1E51454A}
 * Req.-ID:13477648
 * ===========================================================================*/
US_S_SnrCalcs_t *UssMgr_psGetCurSnrCalcsRec(void)
{
    return &sSnrCalcs[uCurSnrMeasRecIdx];
}

/*===========================================================================
 * \brief Returns pointer to pre processed sensor measurement distance
 *
 * \param none
 * \param none
 * \return US_S_SensorMeasDist_t * pointer
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssMgr_psGetCurSnrMeasRecDist
 * Remarks:  DD-ID: {8C47E8F5-0B48-4031-B9A3-236206797E8B}
 * Req.-ID:
 * ===========================================================================*/
const US_S_SensorMeasDist_t *UssMgr_psGetCurSnrMeasRecDist(void)
{
    return &g_sPreProcessTotalDist;
}
/*===========================================================================
 * \brief Is new sensor measurement available.
 *
 * param none
 * param none
 * return bool_t  Is new sensor measurement available.
 * remarks
 */
/* ===========================================================================
 * Name:	 UssMgr_bIsNewSnrData
 * Remarks:  DD-ID: {57089491-0ED8-4c89-946E-5136334D0530}
 * Req.-ID: 13424090
 * ===========================================================================*/
bool_t UssMgr_bIsNewSnrData(void)
{
    return bIsMgrNewSnrData;
}

/*===========================================================================
 * \brief Clear new sensor measurement available flag to indicate manager has processed it.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssMgr_ClearNewSnrDataFlag
 * Remarks:  DD-ID: {E7A59E99-DF03-47ef-B5A0-4DB8F06B4ED3}
 * ===========================================================================*/
void UssMgr_ClearNewSnrDataFlag(void)
{
    bIsMgrNewSnrData = ME_FALSE;
}

/*===========================================================================
 * \brief Calculate total distance [cm] from Time of Flight [us] for all echoes.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Number of echos is limited in manager to 3 echo peaks (configurable)
 *          Also, UssMgr_ClassifyMeasurementType() must be run first in order to
 *          get correct distance calculation for direct vs. indirect.
 */
/* ===========================================================================
 * Name:	 UssMgr_CalulateDistFromTof
 * Remarks:  DD-ID: {885A88BE-7251-4a52-A718-C1AF82FF7EB8}
 * Traceability to source Code:
 * Req.-ID: 13395860
 * Req.-ID: 13395865
 * Req.-ID: 13395881
 * Req.-ID: 13395886
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexcity */
static void UssMgr_CalulateDistFromTof(void)/* PRQA S 2755 */
{
    uint8_t uSnrIdx;
    uint8_t uEchoIdx;
    uint16_t uDistTOF_us;
    uint16_t uTOFCompensation_us;
    uint16_t uTotalDist;
    float32_t fAmbientTemperature;

    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    const US_S_SensorRec_t  *psSensorRec;
    //const US_S_SensorsCfg_t *pSnrCfg = US_SnrCfg_F_Get_SnrCfg();

    US_S_SnrCalcs_t *psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    US_S_SnrCalcRec_t *psSnrCalcRec;

    if ( UssCom_F_GetAmbientTempValidity() != US_TEMPVALID_VALID )
    {
        fAmbientTemperature = US_D_TOF_TEMP_DEFAULT;
    }
    else
    {
        fAmbientTemperature = UssCom_F_GetAmbientTemp();
    }

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {
        psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
        psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];

        for(uEchoIdx = 0; uEchoIdx < psSnrCalcRec->uNumEchoes; uEchoIdx++)
        {
            uDistTOF_us = psSensorRec->sEcho[uEchoIdx].uDistTOF_us;
            //save SnrMeasRec index in SnrCalcRec
            psSnrCalcRec->sEchoCalc[uEchoIdx].uRecEchoIndex = uEchoIdx;

            /* To remove burst time from TOF raw data */
#if (US_D_TOF_COMPENSATION_ENABLED == ME_TRUE)
            switch(psSensorRec->sEcho[uEchoIdx].eEchoType)
            {
                case US_E_CHIRP_DOWN:
                case US_E_CHIRP_UP:
                {
                    uTOFCompensation_us = (uint16_t)US_D_TIME_PER_BURST_US * (uint16_t)US_D_FAR_BURSTNUM_CHIRP; /* TODO jwr REPLACE WITH REAL CAL DATA!!! */
                    /* \TODO jwr REPLACE MAGIC NUMBERS WITH REAL CAL DATA!!!! */
                    uTOFCompensation_us += (uint16_t)((aUssMgr_ChirpCWDelayTable[2] * aUssMgr_ChirpCNDelayTable[2] * US_D_SENSOR_BURST_COEFF) / US_D_SENSOR_DEFAULT_DRV_FREQ );  /*PRQA S 1891 */
                    break;
                }
                case US_E_FIXED:
                default: //normal and nfd can be done the same - along with whatever else falls in here
                {
                    uTOFCompensation_us = (uint16_t)US_D_TIME_PER_BURST_US * (uint16_t)US_D_FAR_BURSTNUM_FIX; /* TODO jwr REPLACE WITH REAL CAL DATA!!! */
                    break;
                }
            }
            
            if (uDistTOF_us > uTOFCompensation_us)
            {
                uDistTOF_us -= uTOFCompensation_us;
            }
            //save TOF for future use
            psSnrCalcRec->sEchoCalc[uEchoIdx].uTOF_us = uDistTOF_us;


#endif /* US_D_TOF_COMPENSATION_ENABLED */
            
            psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm = ZERO;

            if (uDistTOF_us != ZERO)
            {
                uTotalDist = UssCmd_uCalcDistFromTimeOfFlight(uDistTOF_us, fAmbientTemperature, ME_FALSE);
                psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm = uTotalDist;

                if (psSnrCalcRec->eEchoClass == US_E_DIRECT)
                {
                    psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm = uTotalDist >> ONE; // Direct distance is total distance / 2.
                    g_sPreProcessTotalDist.asSensorRecDist[uSnrIdx].aiEchoTotalDist[uEchoIdx] = (sint16_t)uTotalDist;
                }
                else
                {
                    g_sPreProcessTotalDist.asSensorRecDist[uSnrIdx].aiEchoTotalDist[uEchoIdx] = ((sint16_t)uTotalDist * -1);
                }
            }
        }
    }
}

/*===========================================================================
 * \brief Copy sensor echo measurement data into manager buffer.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Number of echos is limited in manager to 3 echo peaks (configurable)
 */
/* ===========================================================================
 * Name:	 UssMgr_CopySnrMeasRecord
 * Remarks:  DD-ID: {FC86B110-68D5-4f41-9487-CC2869B734E9}
 * Traceability to source Code:
 * Req.-ID: 13395870
 * Req.-ID: 13395873
 * Req.-ID: 13395888
 * Req.-ID: 13511361
 * Req.-ID: 17270514
 * Req.-ID: 14996090
 * ===========================================================================*/
static void UssMgr_CopySnrMeasRecord(US_S_SensorMeasRecs_t *psSnrMeasRec, const US_S_SensorMeasRcvRecs_t *psSnrCmdMeasRcvRecPtr)
{
    uint32_t uBitMask;
    uint8_t  uSnrIdx;
    uint8_t  uCurEchoIdx;
    /*debug vars */



    // Clear old data
    (void)memset(psSnrMeasRec, ZERO, sizeof(US_S_SensorMeasRecs_t));
    (void)memset(&g_sPreProcessTotalDist, 0, sizeof(US_S_SensorMeasDist_t));

    // Common data
    psSnrMeasRec->uTimeStamp        = psSnrCmdMeasRcvRecPtr->uTimeStamp;
    psSnrMeasRec->uResponseReceived = psSnrCmdMeasRcvRecPtr->uResponseReceived;
    psSnrMeasRec->uSendingSensors   = psSnrCmdMeasRcvRecPtr->uSendingSensors;

    uint32_t uSnrFaultBitmap = UssMgr_GetSnrFaultBitMap();
    UssDBG_usedFaultMap = uSnrFaultBitmap;
    
    uBitMask = BIT0;
    for (uSnrIdx = 0; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        if ((uSnrFaultBitmap & uBitMask) == ZERO)   // Don't copy data from sensors with a fault of any kind.
        {
            US_S_SensorRec_t          * psSensorRec    = &psSnrMeasRec->sSensorRec[uSnrIdx];
            const US_S_SensorRcvRec_t * psSensorRcvRec = &psSnrCmdMeasRcvRecPtr->sSensorRec[uSnrIdx];

            // Copy sensor data
            psSensorRec->eEchoTypeRequested = psSensorRcvRec->eEchoTypeRequested;
            psSensorRec->uDiagStatus        = psSensorRcvRec->uDiagStatus;
            psSensorRec->uFirstEchoIdx      = psSensorRcvRec->uFirstEchoIdx;
            psSensorRec->uMeasStatBits      = psSensorRcvRec->uMeasStatBits;

            (void)memcpy(&psSensorRec->sRingTime, &psSensorRcvRec->sRingTime, sizeof(US_S_RingTime_t));
            (void)memcpy(&psSensorRec->sNoiseMeas, &psSensorRcvRec->sNoiseMeas, sizeof(US_S_NoiseMeas_t));

            /*
             * Only copy a limited number of echo peaks.  Presently 3 of the 20 echo peaks available.
             * This partial copy is the reason we are not using memcpy for the entire measurement struct.
             */
            psSensorRec->uNumEchoes = (psSensorRcvRec->uNumEchoes <= US_D_APP_MAX_ECHOES_BUFF) ? psSensorRcvRec->uNumEchoes : US_D_APP_MAX_ECHOES_BUFF;

            for (uCurEchoIdx = 0u; uCurEchoIdx < US_D_APP_MAX_ECHOES_BUFF; uCurEchoIdx++)
            {
#ifdef US_D_MGR_PREFILTER_ENABLED
                (void)memcpy(&psSensorRec->sEcho[uCurEchoIdx], &psSensorRcvRec->sEcho[g_auGoodEchoIndexes[uSnrIdx][uCurEchoIdx]], sizeof(US_S_Echo_t));
#else
                (void)memcpy(&psSensorRec->sEcho[uCurEchoIdx], &psSensorRcvRec->sEcho[uCurEchoIdx], sizeof(US_S_Echo_t));
#endif
            }
        }
        uBitMask <<= ONE;
/* DEBUG AREA START */
        //always valid in this system



/* DEBUG AREA END */        
    }
}

#define US_D_USE_BINARY_MATH_FOR_TOF  (ME_FALSE)

#if US_D_USE_BINARY_MATH_FOR_TOF == ME_TRUE

/* ===========================================================================
 * Name:	 UssCmd_uCalcDistFromTimeOfFlight
 * Remarks:  DD-ID: {7AA07846-96EB-45c1-A656-19DF90464CF9}
 * Req.-ID: 13395860
 * Req.-ID: 13395865
 * Req.-ID: 13395881
 * Req.-ID: 13395886
 * ===========================================================================*/
static uint16_t UssCmd_uCalcDistFromTimeOfFlight(uint16_t uTime, bool_t isNFD)
{
    uint16_t  uTemperature = 20u;

    /*
     * For reference:
     * Time of flight to dist formula:  time (us) / 2.0 * 0.00001 (unit convert) * speed of sound
     * Speed of sound = 331.0f (at 0 deg C) + 0.6f * fTemperature
     * Floating point calculation:
     * fDistanceInCm = ((float32_t) uTime * 0.0001f * 0.5f) * (331.0f + (0.6f * fTemperature));
     */

    if (isNFD)
    {
        //
    }

    /*
     * Using only integer math: (Complicated)
     * Convert speed of sound at 0 deg C (331 bin 16) and multiply by 0.6 (bin 16)
     */
    uint32_t uSpeedOfSound = (331u << 16u) + (39312u * uTemperature);  // 39312L is 0.6 in bin 16

    /*
     * Unit Conversion * half time of flight: 0.0001 * 0.5 = 0.00005 => 838 in bin 24
     * Total Conversion factor : uSpeedOfSound (reduced to bin 8) * unit_conversion (838 bin 24) => bin 32 result
     * uDistanceInCm (bin 16) = uTime (bin 0) * Conversion Factor (reduced to bin 16)
     * Round result.
     * Then finally reduce distance to bin 0 for return.
     */

    uint32_t uDistanceInCm = (uint32_t) uTime * (((uSpeedOfSound >> 8u) * 838u) >> 16u); // 838u is unit conversion in bin 24
    uDistanceInCm += 0x7fff; // Round result: +0.5f is 0x7fff in bin 16

    return (uDistanceInCm >> 16u); // Reduce bin 16 to bin 0 for return.
}

#else

/* ===========================================================================
 * Name:	 UssCmd_uCalcDistFromTimeOfFlight
 * Remarks:  DD-ID:
 * Traceability to source Code:
 * Req.-ID:13395835
 * ===========================================================================*/
static uint16_t UssCmd_uCalcDistFromTimeOfFlight(uint16_t uTime, float32_t fAmbientTemperature, bool_t isNFD)
{
    /*KPK-QAC Fix : Need to suppress,Required for compilation */
    (void) isNFD;/* PRQA S 3119 */ // Unused at this time - suppresses warning.

    float32_t fTime = (float32_t) uTime;

    /*
     * 1. uTime: Time of Flight in microseconds.
     * 2. Convert time from us -> s  (1E-6)
     * 3. Convert m -> cm (100.0)
     *
     * Combined constant: 1E-6 * 100.0 = 0.0001 [(s/us) * (m/cm)]
     * Dist [cm] = TOF [us] * 0.0001 * Speed Of Sound [m/s]
     *
     * Speed of sound is 331.0 [m/s] at 0 deg C.
     * Speed of sound is adjusted by 0.6 [m/s] for every degree C
     * Speed of sound is 343.0 [m/s] at 20 deg C
     *
     * Returned value will be total time of flight for returned and direct.
     * Direct is 1/2 TOF, Indirect is TOF - 1/2 direct TOF!
     */

    float32_t fDistanceInCm = (fTime * 0.0001f) * (331.0f + (0.6f * fAmbientTemperature));
    (void) isNFD; // Unused at this time - suppresses warning.
    return (uint16_t) (fDistanceInCm + 0.5f);
}

#endif

/*===========================================================================
 * \brief Insert echo into calc record.  Shift existing echoes forward.
 *
 * \param uint8_t uSnrIdx sensor of interest.
 * \param uint16_t uDirectDist_cm to be inserted.
 * \param uint16_t uSignalStrength to be inserted.
 * \return none
 * \remarks Generally used for NFD.
 */
/* ===========================================================================
 * Name:	 UssMgr_InsertFirstEchoIntoCalcRecord
 * Remarks:  DD-ID: {C3788A8F-6914-46b6-9301-4FE559127C42}
 * Req.-ID:13477648
 * ===========================================================================*/
void UssMgr_InsertFirstEchoIntoCalcRecord(uint8_t uSnrIdx, const US_S_EchoCalc_t * sNewEcho)
{
    uint8_t uEchoIdx;
    US_S_SnrCalcs_t *psSnrCalcs;          
    US_S_SnrCalcRec_t *psSnrCalcRec;        


    /* input range checks */
    if (uSnrIdx >= US_D_MAX_NUM_SENSORS) { return; }

    psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];


    /*
     * Insert position is assumed to be echo index zero.
     * If we already have US_D_APP_MAX_ECHOES_BUFF echos, then ignore the last one, shift others up.
     */
    for (uEchoIdx = US_D_APP_MAX_ECHOES_BUFF; uEchoIdx-- > ONE; )
    {
        psSnrCalcRec->sEchoCalc[uEchoIdx] = psSnrCalcRec->sEchoCalc[uEchoIdx - ONE];
    }

    // New echo data goes into first echo position.
    psSnrCalcRec->sEchoCalc[ZERO] = *sNewEcho;

    //adjust total echoes number if needed
    psSnrCalcRec->uNumEchoes = ((psSnrCalcRec->uNumEchoes + ONE) <= US_D_APP_MAX_ECHOES_BUFF) ? (psSnrCalcRec->uNumEchoes + ONE) : US_D_APP_MAX_ECHOES_BUFF;
}

/*===========================================================================
 * \brief Replace one echo calc in calc record
 *
 * \param uint8_t uSnrIdx sensor of interest.
 * \param uint8_t uEchoRepIdx echo of interest
 * \param US_S_EchoCalc_t * sNewEcho to be inserted.
 * \return none
 * \remarks Generally used for NFD.
 */
/* ===========================================================================
 * Name:	 UssMgr_ReplaceCalcRecordsWithDirEcho
 * Remarks:  DD-ID: {385B81A1-4C7C-4c28-B5DD-48FFCC21421A}
 * Req.-ID:13477648
 * ===========================================================================*/
void UssMgr_ReplaceCalcRecordsWithEcho(uint8_t uSnrIdx, uint8_t uEchoRepIdx, const US_S_EchoCalc_t * sNewEcho)
{
    US_S_SnrCalcs_t *psSnrCalcs;
    US_S_SnrCalcRec_t *psSnrCalcRec;

    /* input range checks */
    if (uEchoRepIdx >= US_D_APP_MAX_ECHOES_BUFF) { return; }
    if (uSnrIdx >= US_D_MAX_NUM_SENSORS) { return; }

    psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];

    // New echo data goes into first echo position.
    psSnrCalcRec->sEchoCalc[uEchoRepIdx] = *sNewEcho;

    /* Since this function could be used to insert echoes that did NOT exist before, need to update uNumEchoes */
    if ((uEchoRepIdx + ONE) > psSnrCalcRec->uNumEchoes) //check to see if we just added an echo that wasn't there before
    {
        psSnrCalcRec->uNumEchoes = (uEchoRepIdx + ONE); //assume this echo is the last one
        //if someone replaces an echo earlier than this, this won't run again and uNumEchoes should be accurate
    }
}

/*===========================================================================
 * \brief Delete echo from calc record.  Shift existing echoes back.
 *
 * \param uint8_t uSnrIdx sensor of interest.
 * \param uint8_t uEchoDelIdx to be deleted.
 * \return none
 * \remarks none
 */
/* ===========================================================================
 * Name:	 UssMgr_DeleteEchoFromCalcRecord
 * Remarks:  DD-ID: {C550864D-CE34-48ea-9C1C-510762266626}
 * Req.-ID:13477648
 * ===========================================================================*/
void UssMgr_DeleteEchoFromCalcRecord(uint8_t uSnrIdx, uint8_t uEchoDelIdx)
{
    uint8_t uEchoIdx;
    US_S_SnrCalcs_t *psSnrCalcs;
    US_S_SnrCalcRec_t *psSnrCalcRec;
    uint8_t uSavedRecIndex;

    /* input range checks */
    if (uEchoDelIdx >= US_D_APP_MAX_ECHOES_BUFF) { return; }
    if (uSnrIdx >= US_D_MAX_NUM_SENSORS) { return; }

    psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];
    if (psSnrCalcRec->uNumEchoes < ONE) { return; } //Nothing to do here

    /* Check if this is the last echo */
    if (uEchoDelIdx < (psSnrCalcRec->uNumEchoes - ONE) )
    {
        /* 1st step - shift all the echoes up to avoid confusing gaps */
        /* If we already have US_D_APP_MAX_ECHOES_BUFF echos, then ignore the last one, shift others up. */
        for (uEchoIdx = uEchoDelIdx; uEchoIdx < (psSnrCalcRec->uNumEchoes - ONE); uEchoIdx++)
        {
            /* Copy entire US_S_EchoCalc_t struct */
            psSnrCalcRec->sEchoCalc[uEchoIdx] = psSnrCalcRec->sEchoCalc[uEchoIdx + ONE];
            //memcpy(psSnrCalcRec->sEchoCalc[uEchoIdx] , psSnrCalcRec->sEchoCalc[uEchoIdx + ONE], sizeof(US_S_EchoCalc_t));
        }
        /* 2nd step - clear the unused echo idx. Using resulting index from for loop!!*/
        uSavedRecIndex = psSnrCalcRec->sEchoCalc[uEchoIdx].uRecEchoIndex;
        psSnrCalcRec->sEchoCalc[uEchoIdx] = gsEmptyEchoCalc;
        psSnrCalcRec->sEchoCalc[uEchoIdx].uRecEchoIndex = uSavedRecIndex;

        /* Even if 1st echo got deleted and now 2nd echo is the new 1st
         * there is no need to update calc echotype or echoclass, those should remain true */
        /* If ALL echoes are deleted, then this needs to change - done at the end of function */
    }
    else
    {
        /* 1st step - actually delete the echo chosen */
        uSavedRecIndex = psSnrCalcRec->sEchoCalc[uEchoDelIdx].uRecEchoIndex;
        psSnrCalcRec->sEchoCalc[uEchoDelIdx] = gsEmptyEchoCalc;
        psSnrCalcRec->sEchoCalc[uEchoDelIdx].uRecEchoIndex = uSavedRecIndex;
    }

    /* Last step - reduce the echo count */
    psSnrCalcRec->uNumEchoes--;
    /* Last last step - update calcs properties if we're down to no echoes */
    if(psSnrCalcRec->uNumEchoes == ZERO)
    {
        UssMgr_UpdateCalcProperties(uSnrIdx, US_E_NOECHO, psSnrCalcRec->eEchoClass);
    }

}

/*===========================================================================
 * \brief Delete all echo calcs from calc record.
 *
 * \param uint8_t uSnrIdx sensor of interest.
 * \return none
 * \remarks none
 */
/* ===========================================================================
 * Name:	 UssMgr_DeleteAllEchoesFromCalcRecord
 * Remarks:  DD-ID: {842891A6-9BE3-4104-A18B-F88916A33D67} 
 * ===========================================================================*/
void UssMgr_DeleteAllEchoesFromCalcRecord(uint8_t uSnrIdx)
{
    uint8_t uEchoIdx;
    US_S_SnrCalcs_t *psSnrCalcs;
    US_S_SnrCalcRec_t *psSnrCalcRec;

    /* input range checks */
    if (uSnrIdx >= US_D_MAX_NUM_SENSORS) { return; }

    psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];

    /* \TODO jwr - decide if this should be skipped if psSnrCalcRec->uNumEchoes == 0 */

    /* If we already have US_D_APP_MAX_ECHOES_BUFF echos, then ignore the last one, shift others up. */
    for (uEchoIdx = ZERO; uEchoIdx < US_D_APP_MAX_ECHOES_BUFF; uEchoIdx++)
    {
       psSnrCalcRec->sEchoCalc[uEchoIdx] = gsEmptyEchoCalc;
    }

    psSnrCalcRec->uNumEchoes = ZERO;
}

/*===========================================================================
 * \brief Updates some properties of a calc record
 *
 * \param uint8_t uSnrIdx sensor of interest.
 * \param US_E_EchoType_t eNewEchoType to be inserted.
 * \param US_E_EchoClass_t eNewEchoClass to be inserted.
 * \return none
 * \remarks none
 */
/* ===========================================================================
 * Name:	 UssMgr_UpdateCalcProperties
 * Remarks:  DD-ID: {719FACF4-9C20-4f00-8506-ED52316ECC86}
 * ===========================================================================*/
void UssMgr_UpdateCalcProperties(uint8_t uSnrIdx, US_E_EchoType_t eNewEchoType, US_E_EchoClass_t eNewEchoClass)
{
    US_S_SnrCalcs_t *psSnrCalcs;
    US_S_SnrCalcRec_t *psSnrCalcRec;

    /* input range checks */
    if (uSnrIdx >= US_D_MAX_NUM_SENSORS) { return; }

    psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];

    psSnrCalcRec->eEchoType = eNewEchoType;
    psSnrCalcRec->eEchoClass = eNewEchoClass;
}

/*===============================================================================
 * brief Checks ALL the echoes to see which are "good", also gathers chirp data
 *
 * param const US_S_SensorMeasRcvRecs_t *psSnrCmdMeasRecPtr, cur fire echo data.
 * param none
 * param none
 * return none
 * output global valid echo list array
 * remarks none
 */
/* ===============================================================================
 * Name:	 UssMgr_PreFilterEchoes
 * Remarks:  DD-ID: {05160F1D-A847-42e3-8E1F-609D81474310} 
 * Remarks:  
 * ===============================================================================*/
#ifdef US_D_MGR_PREFILTER_ENABLED
static void UssMgr_PreFilterEchoes(const US_S_SensorMeasRcvRecs_t *psSnrCmdMeasRcvRecPtr)
{
    uint8_t uSnrIdx;
    uint8_t uEchoIdx;
    #ifdef US_D_MGR_PREFILTER_CHIRP
    US_E_EchoType_t eMatchingEchoType;
    bool_t  bIsChirpType = ME_FALSE;
    #endif
    
    /* 12 sensors x 20 echoes max -> 240 loops max...  */
    /* realistically: 12 sensors x 5 echoes -> 60 loops */
    for (uSnrIdx = 0; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        const US_S_SensorRcvRec_t * psSensorRcvRec = &psSnrCmdMeasRcvRecPtr->sSensorRec[uSnrIdx];

        //Clear old data - is zero valid? should be max+1?
        /*
        for (uEchoIdx = 0; uEchoIdx < US_D_APP_MAX_MEAS_BUFF_SIZE; uEchoIdx++)
        {
            g_auGoodEchoIndexes[uSnrIdx][uEchoIdx] = 0xFF;
        }
        */
#ifdef US_D_MGR_PREFILTER_CHIRP
        /* Determine type of echoes to expect */
        switch (psSensorRcvRec.eMeasTypeRequested)
        {
            case US_E_REQ_SEND_CHIRP_UP:
                bIsChirpType = ME_TRUE;
                eMatchingEchoType = US_E_CHIRP_UP;
                break;
            case US_E_REQ_SEND_CHIRP_DOWN:
                bIsChirpType = ME_TRUE;
                eMatchingEchoType = US_E_CHIRP_DOWN;
                break;
            default:
                bIsChirpType = ME_FALSE;
                eMatchingEchoType = US_E_FIXED;
                break;
        }

        /* Send type isn't enough data, need to handle recv as well */
        /*if ( (psSensorRcvRec.eMeasTypeRequested == US_E_REQ_SEND_CHIRP_UP) ||
             (psSensorRcvRec.eMeasTypeRequested == US_E_REQ_SEND_CHIRP_DOWN)
            )
        {
        */
        if (ME_TRUE == bIsChirpType)
        {
            for (uEchoIdx = 0; uEchoIdx < psSensorRcvRec->uNumEchoes; uEchoIdx++)
            {
                /* check if echo has the correct chirp type */
                if (psSensorRcvRec->sEcho[uEchoIdx].eEchoType == eMatchingEchoType)
                {
                    /* Use for processing */
                    if (uEchoIdx < US_D_APP_MAX_MEAS_BUFF_SIZE)
                    {
                        g_auGoodEchoIndexes[uSnrIdx][uEchoIdx] = uEchoIdx;
                    }
                    UssDBG_preFiltDebug[uSnrIdx][ONE]++;
                }
                else
                {
                    /* skip it */
                    //Not sure if any meta data is needed. Maybe positive data to stay in this chirp?
                    UssDBG_preFiltDebug[uSnrIdx][TWO]++;
                }

                /* if sensor is far from sending and can be used for noise detect, check here */
                //get noise check firing seq table
                //ref against current step? have US_Control send the step + table?
                //treat any echoes as noise? Maybe minimum str to avoid self / closed space cases
            }
        }
        else
#endif /* US_D_MGR_PREFILTER_CHIRP */
        {
            /* default action to take first 3 echoes */
            for (uEchoIdx = 0; uEchoIdx < US_D_APP_MAX_MEAS_BUFF_SIZE; uEchoIdx++)
            {
                g_auGoodEchoIndexes[uSnrIdx][uEchoIdx] = uEchoIdx;
            }
            UssDBG_preFiltDebug[uSnrIdx][ZERO] = psSensorRcvRec->uNumEchoes;
        }
    }
}
#endif /* #ifdef US_D_MGR_PREFILTER_ENABLED */

