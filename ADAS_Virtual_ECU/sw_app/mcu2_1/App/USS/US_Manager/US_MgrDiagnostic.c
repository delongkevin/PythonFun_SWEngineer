/*
 * US_MgrDiagnostic.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#include "US_ME_Typedefs_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_ComOutputBuffer_Global.h"

//#define US_D_RING_FREQ_MIN  (40000u)
#define US_D_RING_FREQ_MIN  (1u)
#define US_D_RING_FREQ_MAX  (60000u)
#define US_D_DRV_FREQ_MIN   (40000u)
#define US_D_DRV_FREQ_MAX   (60000u)
#define US_D_RING_TIME_MIN  (610u) //no membrane hovers around 590 - 600
#define US_D_RING_TIME_MAX  (0xFFFEu)  //tbd - find max time possible from sensor code
#define US_D_RING_ERR_MASK_General  (0x0001)
#define US_D_RING_ERR_MASK_Ringtime (0x0010)
#define US_D_RING_ERR_MASK_RingFreq (0x0100)
#define US_D_RING_ERR_MASK_DrvFreq  (0x1000)

/* Max temp in 10 * deg C */
#define US_D_MAX_SNR_INT_TEMPERATURE (1050)
#define US_D_MIN_SNR_INT_TEMPERATURE (-350)
/* Max temp in 10 * deg C */

static uint32_t uLastDiagTimestamp = ZERO;



static uint32_t uOverTempFaultBitMap = ZERO;
static uint32_t uSnrFaultDetected = ZERO;

static US_S_AllSnrFreqData_t g_sSnrFreqData;
/* Internal Functions */
static uint16_t UssMgr_Diagnostic_RingCheck(const US_S_RingTime_t *RingDataPtr);
/* ===========================================================================
 * Name: UssMgr_DiagnosticInit
 * Remarks:  DD-ID: {F5227162-EAE9-4b7e-9066-0025D6D015FC}
 * ===========================================================================*/
void UssMgr_DiagnosticInit(void)
{
    (void)memset(&g_sSnrFreqData, 0, sizeof(US_S_AllSnrFreqData_t));
}

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
static uint8_t UssMgr_Diagnostic_CheckFlag = ME_FALSE;


/*===========================================================================
 * \brief return Diagnostic check flag.
 *
 * \param none
 * \param none
 * \return uint16_t Error code.
 * \remarks
 *
 * Req.-ID: 13396045
 * ==========================================================================
 */

uint8_t UssMgr_GetDiagnostic_CheckFlag(void)
{
	return UssMgr_Diagnostic_CheckFlag;
}
/*===========================================================================
 * \brief Perform driver level diagnostics on measurment data.
 *
 * \param none
 * \param none
 * \return uint16_t Error code.
 * \remarks
 *
 * Req.-ID: 14992484
 * ==========================================================================
 */

void UssMgr_ClearDiagnostic_CheckFlag(void)
{
	UssMgr_Diagnostic_CheckFlag = ME_FALSE;
}
#endif
/*===========================================================================
 * \brief Perform driver level diagnostics on measurment data.
 *
 * \param none
 * \param none
 * \return uint16_t Error code.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_CheckSnrForErrors
 * Remarks:  DD-ID: {8C62A585-18F4-4bca-9295-EED8C186FC7C}
 * Traceability to source Code:
 * Req.-ID:  16471383
 * Req.-ID: 16134341
 * Req.-ID: 13390672
 * Req.-ID: 14426909
 * Req.-ID: 14426911
 * Req.-ID: 14426913
 * Req.-ID: 14426915
 * Req.-ID: 14426917
 * Req.-ID: 14426919
 * Req.-ID: 14426921
 * Req.-ID: 14426923
 * Req.-ID: 14426925
 * Req.-ID: 14426928
 * Req.-ID: 14426930
 * Req.-ID: 13391060
 * Req.-ID: 14427318
 * Req.-ID: 14427321
 * Req.-ID: 14427320
 * Req.-ID: 14427331
 * Req.-ID: 14427333
 * Req.-ID: 14427335
 * Req.-ID: 14427337
 * Req.-ID: 14427339
 * Req.-ID: 14427341
 * Req.-ID: 14427343
 * Req.-ID: 14427329
 * Req.-ID: 14260349
 * Req.-ID: 14427432
 * Req.-ID: 14427430
 * Req.-ID: 14427428
 * Req.-ID: 14427434
 * Req.-ID: 14427440
 * Req.-ID: 14427438
 * Req.-ID: 14427436
 * Req.-ID: 14427442
 * Req.-ID: 14427448
 * Req.-ID: 14427446
 * Req.-ID: 14427444
 *
 * Req.-ID: 13393237
 * Req.-ID: 14427472
 * Req.-ID: 14427474
 * Req.-ID: 14427476
 * Req.-ID: 14427480
 * Req.-ID: 14427482
 * Req.-ID: 14427484
 * Req.-ID: 14427486
 * Req.-ID: 14427488
 * Req.-ID: 14427490
 * Req.-ID: 14427492
 * Req.-ID: 14427494
 * Req.-ID: 13393933
 * Req.-ID: 14427604
 * Req.-ID: 14427606
 * Req.-ID: 14427608
 * Req.-ID: 14427613
 * Req.-ID: 14427615
 * Req.-ID: 14427617
 * Req.-ID: 14427619
 * Req.-ID: 14427623
 * Req.-ID: 14427625
 * Req.-ID: 14427627
 * Req.-ID: 14427629
 * Req.-ID: 16471226
 * Req.-ID: 16471530
 * Req.-ID: 16471459
 * Req.-ID: 16471531
 * Req.-ID: 14260119
 * Req.-ID: 14260145
 * Req.-ID: 14260214
 * Req.-ID: 14260216
 * Req.-ID: 14260220
 * Req.-ID: 14260226
 * Req.-ID: 14260228
 * Req.-ID: 14260230
 * Req.-ID: 14427786
 * Req.-ID: 14427792
 * Req.-ID: 14427794
 * Req.-ID: 14427788
 * Req.-ID: 13414924
 * Req.-ID: 13424080
 * Req.-ID: 13396045
 * ===========================================================================*/
uint16_t UssMgr_CheckMeasurmentForErrors(const US_S_SensorMeasRcvRecs_t *psSnrCmdMeasRecPtr)
{
    uint32_t uBitMask;
    uint32_t uDisconnectMap;
    uint16_t uReturn = ME_OK;
    uint16_t uRingFlags; //not sensor bitmask
    uint8_t  uSnrIdx;
    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();

    /* Goal of this flag is to ignore sensor data from bad sensors */
    uSnrFaultDetected = ZERO;
    
    #if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
    uDisconnectMap = US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SENSOR_DISCONNECT) |
    		US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_COMM_UNKNOWN) |
			US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_FAIL);
#else
    uDisconnectMap = US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SENSOR_DISCONNECT) |
    		US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_COMM_UNKNOWN);

#endif
    /*KPK core Diag - need to change the strategy*/
    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {
        uBitMask = (uint32_t)US_IDX_TO_BIT_LOC(uSnrIdx);
		/* Don't check conditions if sensor isn't even connected - to avoid setting odd flags */
		if ((uDisconnectMap & uBitMask) != ZERO)
		{
            uSnrFaultDetected |= uBitMask;
			continue;
		}

        /* Diagnostics to only check when sensor tried to fire
         * 
         * Most items in uMeasDiagFlags
         * Anything related to drive & ring time/freq
         */
        if (   ((psSnrCmdMeasRecPtr->uSendingSensors & uBitMask) != ZERO)     // Sending Sensor
            && ((psPlatPhysInfo->uInstSnrAppIdxBitMask & uBitMask) != ZERO))  // Is installed sensor
        {
            /** DTC_SNR_TRANSDUCER_ERR **/
            /* Check for diagnostic status errors from sensor */
            if (psSnrCmdMeasRecPtr->sSensorRec[uSnrIdx].uDiagStatus != ZERO)
            {
                /* \TODO Jwr - diag status needs to break out into individual flags */
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
            	US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_TRANSDUCER_ERR, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_TRANSDUCER_ERR, uSnrIdx);
#endif
                uSnrFaultDetected |= uBitMask;
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
            	US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_TRANSDUCER_ERR, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_TRANSDUCER_ERR, uSnrIdx);
#endif
            }
            
            uRingFlags = UssMgr_Diagnostic_RingCheck(&psSnrCmdMeasRecPtr->sSensorRec[uSnrIdx].sRingTime);

            if ( uRingFlags != ZERO )
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_BAD_RING_TIME, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_BAD_RING_TIME, uSnrIdx);
#endif
                uSnrFaultDetected |= uBitMask;
            }
           else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
            	US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_BAD_RING_TIME, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_BAD_RING_TIME, uSnrIdx);
#endif
            }
        } 
	}/* For loop all sensors */

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
    UssMgr_Diagnostic_CheckFlag = ME_TRUE;
#endif

    if (uSnrFaultDetected != ZERO)
    {
        uReturn = ME_ERROR;
    }
	
    return uReturn;
}

	
/*===========================================================================
 * \brief Perform driver level diagnostics on diag message data.
 *
 * \param none
 * \param none
 * \return bool_t New diag data?
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_CheckSnrForErrors
 * Remarks:  DD-ID: {E8265E06-3F16-4fc1-8F8A-FE893718ED25}
 * Traceability to source Code:
 * Req.-ID:  16471383
 * Req.-ID: 16134341
 * Req.-ID: 13390672
 * Req.-ID: 14426909
 * Req.-ID: 14426911
 * Req.-ID: 14426913
 * Req.-ID: 14426915
 * Req.-ID: 14426917
 * Req.-ID: 14426919
 * Req.-ID: 14426921
 * Req.-ID: 14426923
 * Req.-ID: 14426925
 * Req.-ID: 14426928
 * Req.-ID: 14426930
 * Req.-ID: 13391060
 * Req.-ID: 14427318
 * Req.-ID: 14427321
 * Req.-ID: 14427320
 * Req.-ID: 14427331
 * Req.-ID: 14427333
 * Req.-ID: 14427335
 * Req.-ID: 14427337
 * Req.-ID: 14427339
 * Req.-ID: 14427341
 * Req.-ID: 14427343
 * Req.-ID: 14427329
 * Req.-ID: 14260349
 * Req.-ID: 14427432
 * Req.-ID: 14427430
 * Req.-ID: 14427428
 * Req.-ID: 14427434
 * Req.-ID: 14427440
 * Req.-ID: 14427438
 * Req.-ID: 14427436
 * Req.-ID: 14427442
 * Req.-ID: 14427448
 * Req.-ID: 14427446
 * Req.-ID: 14427444
 *
 * Req.-ID: 13393237
 * Req.-ID: 14427472
 * Req.-ID: 14427474
 * Req.-ID: 14427476
 * Req.-ID: 14427480
 * Req.-ID: 14427482
 * Req.-ID: 14427484
 * Req.-ID: 14427486
 * Req.-ID: 14427488
 * Req.-ID: 14427490
 * Req.-ID: 14427492
 * Req.-ID: 14427494
 * Req.-ID: 13393933
 * Req.-ID: 14427604
 * Req.-ID: 14427606
 * Req.-ID: 14427608
 * Req.-ID: 14427613
 * Req.-ID: 14427615
 * Req.-ID: 14427617
 * Req.-ID: 14427619
 * Req.-ID: 14427623
 * Req.-ID: 14427625
 * Req.-ID: 14427627
 * Req.-ID: 14427629
 * Req.-ID: 16471226
 * Req.-ID: 16471530
 * Req.-ID: 16471459
 * Req.-ID: 16471531
 * Req.-ID: 14260119
 * Req.-ID: 14260145
 * Req.-ID: 14260214
 * Req.-ID: 14260216
 * Req.-ID: 14260220
 * Req.-ID: 14260226
 * Req.-ID: 14260228
 * Req.-ID: 14260230
 * Req.-ID: 14427786
 * Req.-ID: 14427792
 * Req.-ID: 14427794
 * Req.-ID: 14427788
 * Req.-ID: 13414924
 * Req.-ID: 13424080
 * Req.-ID: 13396045
 * ===========================================================================*/
bool_t UssMgr_CheckSnrForErrors(void)
{
    uint32_t uBitMask;
    uint32_t uDisconnectMap;
    uint16_t uReturn = ME_FALSE;
    uint16_t uHwDiagFlags, uMeasDiagFlags, uCommDiagFlags, uAsilDiagFlags;
    uint8_t  uSnrIdx;
    bool_t   bInStandby =( bool_t)(UssMgr_uGetCurParkingMode() == US_PARKMODE_STANDBY);
    US_S_Sensor_DiagnosticFlags_t *psSnrDiagFlags = UssSnrCmd_psGetSnrDiagFlags();
    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    const US_S_SensorMeasRecs_t * psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    const US_S_Sensor_Temperature_t * psSnrTemperatures = UssSnrCmd_psGetSnrTemperatures();

    /* Check if new diag data */
    if (uLastDiagTimestamp != psSnrDiagFlags->uTimeStamp)
    {
#if(US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)   /* Fisker has IDLE mode, need to check sensor connection, CVADAS/PAM does not           */
       UssSnrCmd_CheckSnrDisconnect(psSnrDiagFlags->uResponseReceived, psPlatPhysInfo->uInstSnrAppIdxBitMask);
#endif
#if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
        uDisconnectMap = US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SENSOR_DISCONNECT) |
        US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_COMM_UNKNOWN) |
        US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_FAIL);
#else
        uDisconnectMap = US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SENSOR_DISCONNECT) |
                US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_COMM_UNKNOWN);

#endif
        /*KPK core Diag - need to change the strategy*/
        for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
        {
            uBitMask = (uint32_t)US_IDX_TO_BIT_LOC(uSnrIdx);
            /* Don't check conditions if sensor isn't even connected - to avoid setting odd flags */
            if ((uDisconnectMap & uBitMask) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                /*Clear all the HW faults associated with sensor which got disconnected*/
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_TRANSDUCER_ERR, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_BAD_RING_TIME, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_RING_COMPARATOR_ZERO, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VSUP_OVER_VOLTAGE, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_BURST_ABORT_DURING_BURST, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_PROGRAM_EEPROM, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SRAM_PARITY_ERROR, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, uBitMask);
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_FW_MISMATCH, uBitMask);
#else
                /*Clear all the HW faults associated with sensor which got disconnected*/
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_TRANSDUCER_ERR, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_BAD_RING_TIME, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_RING_COMPARATOR_ZERO, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VSUP_OVER_VOLTAGE, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_BURST_ABORT_DURING_BURST, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_PROGRAM_EEPROM, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SRAM_PARITY_ERROR, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, uSnrIdx);
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_FW_MISMATCH, uSnrIdx);
#endif
                continue;
            }

            /* Check diagnostics flags */

            uHwDiagFlags   = psSnrDiagFlags->uHardwareDiagFlags[uSnrIdx];
            uMeasDiagFlags = psSnrDiagFlags->uMeasDiagFlags[uSnrIdx];
            uCommDiagFlags = psSnrDiagFlags->uCommDiagFlags[uSnrIdx];
            uAsilDiagFlags = psSnrDiagFlags->uAsilDiagFlags[uSnrIdx];  // Only populated by sensors ver > F11A

    #if 0
            if ((uHwDiagFlags   & (uint16_t)ERR_ADA_MEASURE_TIMEOUT)          ||
                (uHwDiagFlags   & (uint16_t)ERR_SNR_TEMPERATURE_OUT_OF_RANGE) ||
                (uMeasDiagFlags & (uint16_t)ERR_GET_RING_FREQUENCY_FAILURE)   ||
                (uMeasDiagFlags & (uint16_t)ERR_RING_COMPARATOR_ZERO)         ||
                (uMeasDiagFlags & (uint16_t)ERR_GET_DRV_FREQUENCY_FAILURE)    ||
                (uMeasDiagFlags & (uint16_t)ERR_DRV_FREQUENCY_OUT_OF_RANGE)   ||
                (uMeasDiagFlags & (uint16_t)ERR_RING_FREQUENCY_OUT_OF_RANGE)  ||
                (uMeasDiagFlags & (uint16_t)ERR_DRV1_FAILURE_DURING_BURST)    ||
                (uMeasDiagFlags & (uint16_t)ERR_DRV2_FAILURE_DURING_BURST)    ||
                (uMeasDiagFlags & (uint16_t)ERR_DRVS_FAILURE_DURING_BURST)       )
                /*(bSensorSending && (uRingFlags != ZERO))               )*/
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uSnrIdx);
#endif
            }
    #endif
            if((uHwDiagFlags & (uint16_t)ERR_ADA_MEASURE_TIMEOUT) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT, uSnrIdx);
#endif
            }
            if((uHwDiagFlags & (uint16_t)ERR_SNR_TEMPERATURE_OUT_OF_RANGE) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, uSnrIdx);
#endif
            }
            else if((psSnrTemperatures->iSnrTemperature[uSnrIdx] <= US_D_MAX_SNR_INT_TEMPERATURE)&&(psSnrTemperatures->iSnrTemperature[uSnrIdx] >= US_D_MIN_SNR_INT_TEMPERATURE))
			{
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, uSnrIdx);
#endif
            }
	    else
	    {
		/* Do nothing */
	    }

            /* Measurement Flags */
            if (   ((psSnrMeasRec->uSendingSensors & uBitMask) != ZERO) // Only evaluate if this is a sending sensor
                && (bInStandby ==(bool_t) ME_FALSE))  // And not in standby
            {
                if(((uMeasDiagFlags & (uint16_t)ERR_GET_RING_FREQUENCY_FAILURE) != ZERO)||((uMeasDiagFlags & (uint16_t)ERR_RING_FREQUENCY_OUT_OF_RANGE) != ZERO))
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, uSnrIdx);
    #endif
                }
                if((uMeasDiagFlags & (uint16_t)ERR_RING_COMPARATOR_ZERO) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_RING_COMPARATOR_ZERO, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_RING_COMPARATOR_ZERO, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_RING_COMPARATOR_ZERO, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_RING_COMPARATOR_ZERO, uSnrIdx);
    #endif
                }
                if(((uMeasDiagFlags & (uint16_t)ERR_GET_DRV_FREQUENCY_FAILURE) != ZERO)||((uMeasDiagFlags & (uint16_t)ERR_DRV_FREQUENCY_OUT_OF_RANGE)!= ZERO))
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE, uSnrIdx);
    #endif
                }
                 if((uMeasDiagFlags & (uint16_t)ERR_DRV1_FAILURE_DURING_BURST) != ZERO )
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                     US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST, uBitMask);
    #else
                     US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST, uSnrIdx);
    #endif
                }

                if((uMeasDiagFlags & (uint16_t)ERR_DRV2_FAILURE_DURING_BURST) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST, uSnrIdx);
    #endif
                }
                if((uMeasDiagFlags & (uint16_t)ERR_DRVS_FAILURE_DURING_BURST) != ZERO )
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST, uSnrIdx);
    #endif
                }

                if((uMeasDiagFlags & (uint16_t)ERR_VTANK_OVER_VOLTAGE_DURING_BURST) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST, uSnrIdx);
    #endif
                }
                if((uMeasDiagFlags & (uint16_t)ERR_BURST_ABORT_DURING_BURST) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_BURST_ABORT_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_BURST_ABORT_DURING_BURST, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_BURST_ABORT_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_BURST_ABORT_DURING_BURST, uSnrIdx);
    #endif
                }
            }
            /* End Meas Diag Flags */

    #if 0
            if ((uHwDiagFlags   & (uint16_t)ERR_VSUP_OVER_VOLTAGE)               ||
                (uHwDiagFlags   & (uint16_t)ERR_VTANK_OVER_VOLTAGE)              ||
                (uMeasDiagFlags & (uint16_t)ERR_VTANK_OVER_VOLTAGE_DURING_BURST) ||
                (uMeasDiagFlags & (uint16_t)ERR_BURST_ABORT_DURING_BURST))
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uSnrIdx);
#endif
            }
    #endif

            if((uHwDiagFlags   & (uint16_t)ERR_VSUP_OVER_VOLTAGE) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VSUP_OVER_VOLTAGE, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VSUP_OVER_VOLTAGE, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VSUP_OVER_VOLTAGE, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VSUP_OVER_VOLTAGE, uSnrIdx);
#endif
            }
            if((uHwDiagFlags   & (uint16_t)ERR_VTANK_OVER_VOLTAGE) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_OVERVOLTAGE, uSnrIdx);
#endif
            }

    #if 0
            if ((uHwDiagFlags & (uint16_t)ERR_VSUP_UNDER_VOLTAGE) ||
                (uHwDiagFlags & (uint16_t)ERR_VTANK_UNDER_VOLTAGE))
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uSnrIdx);
#endif
            }
    #endif
            if((uHwDiagFlags & (uint16_t)ERR_VSUP_UNDER_VOLTAGE) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE, uSnrIdx);
#endif
            }
            if((uHwDiagFlags & (uint16_t)ERR_VTANK_UNDER_VOLTAGE) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, uSnrIdx);
#endif
            }

    #if 0
            if ((uHwDiagFlags & (uint16_t)ERR_PROGRAM_EEPROM) ||
                (uHwDiagFlags & (uint16_t)ERR_CRC_MISMATCH_IN_EEPROM_A1) ||
                (uHwDiagFlags & (uint16_t)ERR_CRC_MISMATCH_IN_EEPROM_A2))
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_PROGRAM_EEPROM, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_PROGRAM_EEPROM, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_PROGRAM_EEPROM, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_PROGRAM_EEPROM, uSnrIdx);
#endif
            }
    #endif
            if((uHwDiagFlags & (uint16_t)ERR_PROGRAM_EEPROM) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_PROGRAM_EEPROM, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_PROGRAM_EEPROM, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_PROGRAM_EEPROM, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_PROGRAM_EEPROM, uSnrIdx);
#endif
            }
            if((uHwDiagFlags & (uint16_t)ERR_CRC_MISMATCH_IN_EEPROM_A1)  != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1, uSnrIdx);
#endif
            }
            if((uHwDiagFlags & (uint16_t)ERR_CRC_MISMATCH_IN_EEPROM_A2) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2, uSnrIdx);
#endif
            }


            if ((uHwDiagFlags & (uint16_t)ERR_SRAM_PARITY_ERROR) != ZERO)
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SRAM_PARITY_ERROR, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SRAM_PARITY_ERROR, uSnrIdx);
#endif
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SRAM_PARITY_ERROR, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SRAM_PARITY_ERROR, uSnrIdx);
#endif
            }

            // \TODO jp - Check communications flags.  (At present ERR_CRM_TYPE_ERROR & (uint16_t)ERR_PDCM_PULSE_INVALID appear frequently.)

            //if (uCommDiagFlags & 0xFFD5) // & (uint16_t)ERR_CRC_OF_RECEIVED_COMMAND_INVALID)  // \TODO jp - Receiving 0x0028 and 0x002A - Debug
            if ((uCommDiagFlags & (uint16_t)ERR_COMMAND_NOT_SUPPORTED) != ZERO)   //testing only 1 for now...
            {
                //cMELog_F_LogDebug_v("UssMgrDiagnostics: Communications Error = 0x%04x", uCommDiagFlags);
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_RECEIVED_COMMAND_INVALID, uBitMask);
#else
                US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_RECEIVED_COMMAND_INVALID, uSnrIdx);
#endif
                //James_Debug[16] |= uBitMask;
                //James_Debug[16] = uCommDiagFlags;
            }
            else
            {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_RECEIVED_COMMAND_INVALID, uBitMask);
#else
                US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_RECEIVED_COMMAND_INVALID, uSnrIdx);
#endif
                //James_Debug[16] &= ~uBitMask;
                //James_Debug[16] &= ~uCommDiagFlags;
            }
    #if 0
            ERR_CRC_OF_RECEIVED_COMMAND_INVALID          = 0x0001,
           // ERR_PDCM_PULSE_INVALID                       = 0x0002,
            ERR_DISCOVERY_PULSE_INVALID                  = 0x0004,
          //  ERR_FCC_ERROR_STATE                          = 0x0008,
          //  ERR_INVALID_START_EDGE_DETECTED              = 0x0010,
            ERR_SYNCHRONISATION_COUNTER_ERROR_DETECTED   = 0x0020,
            ERR_CRM_TYPE_ERROR                           = 0x0040,
            ERR_COMMAND_NOT_SUPPORTED                    = 0x0080
    #endif

            if ((US_SnrCfg_Get_SnrFWVer() != QM_SNR_FW_VER)&& (US_SnrCfg_Get_Sensor_opmode() == SENSOR_OP_NORMAL))
            {
                if ((uAsilDiagFlags & (uint16_t)ERR_CRC_MISMATCH_IN_OTP) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_MISMATCH_IN_OTP, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_MISMATCH_IN_OTP, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_MISMATCH_IN_OTP, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_MISMATCH_IN_OTP, uSnrIdx);
    #endif
                }

                if ((uAsilDiagFlags & (uint16_t)ERR_DSP_CONFIG_REGISTER_MISMATCH) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_DSP_CONFIG_REGISTER_MISMATCH, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_DSP_CONFIG_REGISTER_MISMATCH, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_DSP_CONFIG_REGISTER_MISMATCH, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_DSP_CONFIG_REGISTER_MISMATCH, uSnrIdx);
    #endif
                }

                if ((uAsilDiagFlags & (uint16_t)ERR_CPU_CONFIG_REGISTER_MISMATCH) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CPU_CONFIG_REGISTER_MISMATCH, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CPU_CONFIG_REGISTER_MISMATCH, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CPU_CONFIG_REGISTER_MISMATCH, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CPU_CONFIG_REGISTER_MISMATCH, uSnrIdx);
    #endif
                }

                if ((uAsilDiagFlags & (uint16_t)ERR_NOISE_DURING_BURST) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_NOISE_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_NOISE_DURING_BURST, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_NOISE_DURING_BURST, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_NOISE_DURING_BURST, uSnrIdx);
    #endif
                }


                if ((uAsilDiagFlags & (uint16_t)ERR_VREF_OUT_OF_RANGE) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VREF_OUT_OF_RANGE, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VREF_OUT_OF_RANGE, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VREF_OUT_OF_RANGE, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VREF_OUT_OF_RANGE, uSnrIdx);
    #endif
                }


                if ((uAsilDiagFlags & (uint16_t)ERR_VREF_OTP_OUT_OF_RANGE) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VREF_OTP_OUT_OF_RANGE, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VREF_OTP_OUT_OF_RANGE, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VREF_OTP_OUT_OF_RANGE, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VREF_OTP_OUT_OF_RANGE, uSnrIdx);
    #endif
                }


                if ((uAsilDiagFlags & (uint16_t)ERR_VDDD_OUT_OF_RANGE) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_VDDD_OUT_OF_RANGE, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_VDDD_OUT_OF_RANGE, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_VDDD_OUT_OF_RANGE, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_VDDD_OUT_OF_RANGE, uSnrIdx);
    #endif
                }

                if ((uAsilDiagFlags & (uint16_t)ERR_WD_COUNTER_DESYNC)!= ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_WD_COUNTER_DESYNC, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_WD_COUNTER_DESYNC, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_WD_COUNTER_DESYNC, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_WD_COUNTER_DESYNC, uSnrIdx);
    #endif
                }


                if ((uAsilDiagFlags & (uint16_t)ERR_WD_CLOCK_FAIL) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_WD_CLOCK_FAIL, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_WD_CLOCK_FAIL, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_WD_CLOCK_FAIL, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_WD_CLOCK_FAIL, uSnrIdx);
    #endif
                }


                if ((uAsilDiagFlags & ((uint16_t)ERR_CRC_BLOCK_CFG1|(uint16_t)ERR_CRC_BLOCK_CFG2)) == ((uint16_t)ERR_CRC_BLOCK_CFG1|(uint16_t)ERR_CRC_BLOCK_CFG2))
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG1, uBitMask);
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG2, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG1, uSnrIdx);
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG2, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG1, uBitMask);
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG2, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG1, uSnrIdx);
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG2, uSnrIdx);
    #endif
                }

#if 0
                if ((uAsilDiagFlags & (uint16_t)ERR_CRC_BLOCK_CFG2) != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG2, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG2, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG2, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_CFG2, uSnrIdx);
    #endif
                }
#endif

                if ((uAsilDiagFlags & ((uint16_t)ERR_CRC_BLOCK_MFG1|(uint16_t)ERR_CRC_BLOCK_MFG2)) == ((uint16_t)ERR_CRC_BLOCK_MFG1|(uint16_t)ERR_CRC_BLOCK_MFG2))
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG1, uBitMask);
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG2, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG1, uSnrIdx);
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG2, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG1, uBitMask);
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG2, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG1, uSnrIdx);
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG2, uSnrIdx);
    #endif
                }
#if 0
                if ((uAsilDiagFlags & (uint16_t)ERR_CRC_BLOCK_MFG2)  != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG2, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG2, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG2, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_BLOCK_MFG2, uSnrIdx);
    #endif
                }
#endif
                if ((uAsilDiagFlags & ((uint16_t)ERR_CRC_OP_MODE1|(uint16_t)ERR_CRC_OP_MODE2)) == ((uint16_t)ERR_CRC_OP_MODE1|(uint16_t)ERR_CRC_OP_MODE2))
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE1, uBitMask);
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE2, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE1, uSnrIdx);
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE2, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE1, uBitMask);
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE2, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE1, uSnrIdx);
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE2, uSnrIdx);
    #endif
                }
#if 0
                if ((uAsilDiagFlags & (uint16_t)ERR_CRC_OP_MODE2)   != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE2, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE2, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE2, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_CRC_OP_MODE2, uSnrIdx);
    #endif
                }
#endif
                if ((uAsilDiagFlags & (uint16_t)ERR_SIGNAL_PATH_FAILURE)  != ZERO)
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SIGNAL_PATH_FAILURE, uBitMask);
    #else
                    US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SIGNAL_PATH_FAILURE, uSnrIdx);
    #endif
                }
                else
                {
    #if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
                    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SIGNAL_PATH_FAILURE, uBitMask);
    #else
                    US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SIGNAL_PATH_FAILURE, uSnrIdx);
    #endif
                }
            }
        } /* For loop all sensors */

	    uLastDiagTimestamp = psSnrDiagFlags->uTimeStamp;
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
        UssMgr_Diagnostic_CheckFlag = ME_TRUE;
#endif
        uReturn = ME_TRUE;
    }


    return (bool_t)uReturn;
}

/*===========================================================================
 * \brief Check sensor internal temperatures and set diag flags.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_CheckSensorTemperature
 * Remarks:  DD-ID: {614FF2F7-3449-4be5-A205-58945E250FD4}
 * Traceability to source Code:
 * Req.-ID: 16471383
 * Req.-ID: 16134341
 * ===========================================================================*/
void UssMgr_CheckSensorTemperature(void)
{
    uint8_t uSnrIdx;
    uint16_t uTempOutofRange;
    static uint32_t prvtimestamp =ZERO;
    const US_S_Sensor_Temperature_t * psSnrTemperatures = UssSnrCmd_psGetSnrTemperatures();
    if(prvtimestamp != psSnrTemperatures->uTimeStamp)
	{
		for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
		{
			if (psSnrTemperatures->iSnrTemperature[uSnrIdx] > US_D_MAX_SNR_INT_TEMPERATURE)
			{
				uOverTempFaultBitMap |= US_IDX_TO_BIT_LOC(uSnrIdx);  // Set error flag for this sensor
	#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
				US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, US_IDX_TO_BIT_LOC(uSnrIdx));
	#else
				US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, uSnrIdx);
	#endif

			}
			else if(psSnrTemperatures->iSnrTemperature[uSnrIdx] > US_D_MIN_SNR_INT_TEMPERATURE)
			{
				uOverTempFaultBitMap &= ~US_IDX_TO_BIT_LOC(uSnrIdx); // Clear error flag for this sensor
	#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
				US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, US_IDX_TO_BIT_LOC(uSnrIdx));
	#else
				US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE, uSnrIdx);
	#endif
			}
			else
			{
				/*empty  */
			}
		}
	   prvtimestamp = psSnrTemperatures->uTimeStamp;	
	}
}

/*===========================================================================
 * \brief Copy sensor diagnostics flags to output buffer.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_PopulateHardwareDiagnosticsInfo
 * Remarks:  DD-ID: {4DE53BDF-F025-47ed-91F9-2782B0D016AE}
 * Traceability to source Code:
 * Req.-ID: 13477351
 * Req.-ID: 13477349
 * Req.-ID: 13477478
 * ===========================================================================*/
void UssMgr_PopulateHardwareDiagnosticsInfo(void)
{
  static uint32_t uHardwareFaultBitMap = ZERO;
  static uint32_t uCommFaultBitMap = ZERO;
  static uint32_t uCommUnknownBitMap = ZERO;
	/* overwrite fault flags with US_Diagnostics debounced DTCs */
	uint32_t uTempFaultBitMap = ZERO;
	
	/* HW Faults */
#if 0
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(SNR_DIAG_FLG_VTANK_OVERVOLTAGE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1);
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(SNR_DIAG_FLG_SRAM_PARITY_ERROR);
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST);
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(SNR_DIAG_FLG_RING_COMPARATOR_ZERO);
	
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(SNR_DIAG_FLG_SNR_FW_MISMATCH);
#endif
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_BURST_ABORT_DURING_BURST);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_RING_COMPARATOR_ZERO);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_SRAM_PARITY_ERROR);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_PROGRAM_EEPROM);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_VTANK_OVERVOLTAGE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_VTANK_UNDERVOLTAGE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_VSUP_OVER_VOLTAGE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_BAD_RING_TIME);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_TRANSDUCER_ERR);

	/* ASIL Flags */
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRC_MISMATCH_IN_OTP);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_DSP_CONFIG_REGISTER_MISMATCH);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CPU_CONFIG_REGISTER_MISMATCH);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_NOISE_DURING_BURST);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_VREF_OUT_OF_RANGE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_VREF_OTP_OUT_OF_RANGE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_VDDD_OUT_OF_RANGE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_WD_COUNTER_DESYNC);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_WD_CLOCK_FAIL);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG1);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_CFG2);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG1);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRC_BLOCK_MFG2);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE1);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRC_OP_MODE2);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_SIGNAL_PATH_FAILURE);
  uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_SNR_FAIL);
	
	uHardwareFaultBitMap = uTempFaultBitMap;
	
	/* Comm Faults */
	uTempFaultBitMap = ZERO;
#if 0
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(SNR_DIAG_FLG_SENSOR_DISCONNECT);
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(DTC_SNR_COMM_ERR);
	uTempFaultBitMap |= US_Diagnostic_GetSnrFaultFlag(DTC_SNR_NO_RESPONSE);
#endif
	


	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_SENSOR_DISCONNECT);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_RECEIVED_COMMAND_INVALID);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_PDCM_PULSE_INVALID);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_DISCOVERY_PULSE_INVALID);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_FCC_ERROR_STATE);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_INVALID_START_EDGE_DETECTED);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_SYNCHRONISATION_COUNTER_ERROR_DETECTED);
	uTempFaultBitMap |= US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_CRM_TYPE_ERROR);

	uCommFaultBitMap = uTempFaultBitMap;

	uCommUnknownBitMap = US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_SNR_COMM_UNKNOWN);


	/* Over Temp - no need to overwrite */

    UssCom_F_PopulateHardwareDiagnosticsInfo(uLastDiagTimestamp,
                                             uHardwareFaultBitMap,
                                             uCommFaultBitMap,
                                             uCommUnknownBitMap,
                                             uOverTempFaultBitMap);
}

/*===========================================================================
 * \brief Check ring/drv freq and time limits. Needs calibration input later
 *
 * \param US_S_RingTime_t
 * \return uint16_t Fault bitmap.
 * \remarks intended for 1 set of ring data
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_Diagnostic_RingCheck
 * Remarks:  DD-ID: {3943E0A6-F23F-4e40-B04F-0E853AC02245}
 * Req.-ID:  16471383
 * Req.-ID: 16134341
 * Req.-ID: 13390672
 * Req.-ID: 14426909
 * Req.-ID: 14426911
 * Req.-ID: 14426913
 * Req.-ID: 14426915
 * Req.-ID: 14426917
 * Req.-ID: 14426919
 * Req.-ID: 14426921
 * Req.-ID: 14426923
 * Req.-ID: 14426925
 * Req.-ID: 14426928
 * Req.-ID: 14426930
 * Req.-ID: 13391060
 * Req.-ID: 14427318
 * Req.-ID: 14427321
 * Req.-ID: 14427320
 * Req.-ID: 14427331
 * Req.-ID: 14427333
 * Req.-ID: 14427335
 * Req.-ID: 14427337
 * Req.-ID: 14427339
 * Req.-ID: 14427341
 * Req.-ID: 14427343
 * Req.-ID: 14427329
 * Req.-ID: 14260349
 * Req.-ID: 14427432
 * Req.-ID: 14427430
 * Req.-ID: 14427428
 * Req.-ID: 14427434
 * Req.-ID: 14427440
 * Req.-ID: 14427438
 * Req.-ID: 14427436
 * Req.-ID: 14427442
 * Req.-ID: 14427448
 * Req.-ID: 14427446
 * Req.-ID: 14427444
 *
 * Req.-ID: 13393237
 * Req.-ID: 14427472
 * Req.-ID: 14427474
 * Req.-ID: 14427476
 * Req.-ID: 14427480
 * Req.-ID: 14427482
 * Req.-ID: 14427484
 * Req.-ID: 14427486
 * Req.-ID: 14427488
 * Req.-ID: 14427490
 * Req.-ID: 14427492
 * Req.-ID: 14427494
 * Req.-ID: 13393933
 * Req.-ID: 14427604
 * Req.-ID: 14427606
 * Req.-ID: 14427608
 * Req.-ID: 14427613
 * Req.-ID: 14427615
 * Req.-ID: 14427617
 * Req.-ID: 14427619
 * Req.-ID: 14427623
 * Req.-ID: 14427625
 * Req.-ID: 14427627
 * Req.-ID: 14427629
 * Req.-ID: 16471226
 * Req.-ID: 16471530
 * Req.-ID: 16471459
 * Req.-ID: 16471531
 * Req.-ID: 14260119
 * Req.-ID: 14260145
 * Req.-ID: 14260214
 * Req.-ID: 14260216
 * Req.-ID: 14260220
 * Req.-ID: 14260226
 * Req.-ID: 14260228
 * Req.-ID: 14260230
 * Req.-ID: 14427786
 * Req.-ID: 14427792
 * Req.-ID: 14427794
 * Req.-ID: 14427788
 * Req.-ID: 13414924
 * Req.-ID: 13424080
 * Req.-ID: 13396045
 * ===========================================================================*/
static uint16_t UssMgr_Diagnostic_RingCheck(const US_S_RingTime_t *RingDataPtr)
{
    uint16_t uErrorBitMask;
    
    /* Clear output */
    uErrorBitMask = ZERO;

    /* Check ring time flag */
    if (RingDataPtr->uRingTime > US_D_RING_TIME_MAX)
    {
        // \TODO: jp - Call register command.  I have to see if this is a valid measurement or not in old code.
        uErrorBitMask |= (uint16_t)US_D_RING_ERR_MASK_General;
    }
    else /* Check ring and driver frequencies */
    {
        // ring time here for future - when ringtime of 0xFFFF is figured out
        /*KPK-QAC Fix : Need to suppress,Intentional implemenation */
        if ( (RingDataPtr->uRingTime > US_D_RING_TIME_MAX) || (RingDataPtr->uRingTime < US_D_RING_TIME_MIN) )
        {
            uErrorBitMask |= (uint16_t) US_D_RING_ERR_MASK_Ringtime;
        }

        if ((RingDataPtr->uRingFreq > US_D_RING_FREQ_MAX)
            || (RingDataPtr->uRingFreq < US_D_RING_FREQ_MIN ))
        {
            uErrorBitMask |=  (uint16_t)US_D_RING_ERR_MASK_RingFreq;
        }

        if (( RingDataPtr->uDrvFreq > US_D_DRV_FREQ_MAX)
            || (RingDataPtr->uDrvFreq < US_D_DRV_FREQ_MIN ))
        {
            uErrorBitMask |= (uint16_t)US_D_RING_ERR_MASK_DrvFreq;
        }
    }
    
    return uErrorBitMask;
}

/*===========================================================================
 * \brief Return sensor fault bitmap.
 *
 * \param none
 * \param none
 * \return uint32_t Fault bitmap.
 * \remarks Any fault will set corresponding sensor bit.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_GetSnrFaultBitMap
 * Remarks:  DD-ID: {0794045F-90EC-4cd7-8818-590F40BAE041}
 * Req.-ID: 13395870
 * Req.-ID: 13395873
 * Req.-ID: 13395888
 * Req.-ID: 13511361
 * Req.-ID: 17270514
 * Req.-ID: 14996090
 * ===========================================================================*/
uint32_t UssMgr_GetSnrFaultBitMap(void)
{
    return uSnrFaultDetected;
}
/* ===========================================================================
 * Name: UssMgr_GetSnrFreqData	
 * Remarks:  DD-ID: {CF27CEB0-A1C8-4258-8D6E-FA60763784DC}
 * ===========================================================================*/
US_S_AllSnrFreqData_t * UssMgr_GetSnrFreqData(void)
{
    return &g_sSnrFreqData;
}

/*********************** Buzzer control start ***************************/
#ifdef BUZZER_ACTIVE
void aUSSMgr_f_DiagnosticBuzzer_v(pUS_E_ClusterID_t CID, uint8_t failCnt)
{
  if (CID > pUS_E_REAR_ID)    return;
  if(CID == pUS_E_REAR_ID)
  {
    aUSSMgr_f_StopBuzzer_v(pUS_E_FRONT_ID);
  }
  else if(CID == pUS_E_FRONT_ID)
  {
    aUSSMgr_f_StopBuzzer_v(pUS_E_REAR_ID);
  }
  if(failCnt > 0)
  {
    //drv_BuzzerAlarm(CID, 3,  ERROR2_TONE);//sensor error buzzer
  }
}

/* ===========================================================================
 * Name:	 aUSSMgr_f_PasOnBuzzer_v
 * Remarks:  DD-ID: {3839B164-BC51-4c31-8143-8667E918F431}
 * ===========================================================================*/
void aUSSMgr_f_PasOnBuzzer_v(pUS_E_ClusterID_t CID)//Roger beep
{
  if (CID > pUS_E_REAR_ID)
  {
    return;
  }
  drv_BuzzerAlarm(CID, 1, START_TONE);
}

void aUSSMgr_f_StopBuzzer_v(pUS_E_ClusterID_t CID)
{
  if (CID > pUS_E_REAR_ID)
  {
    return;
  }
  drv_BuzzerDisable(CID);
}

bool_t aUSSMgr_f_GetRogerEnd_b(pUS_E_ClusterID_t CID)
{
  if(CID == pUS_E_FRONT_ID)
  {
    return aUSS_v_FrontDetectStart_b;
  }
  else
  {
    return aUSS_v_RearDetectStart_b;
  }
}

void aUSSMgr_f_SetRogerEnd_v(pUS_E_ClusterID_t CID, bool_t isEnd)
{
  if(CID == pUS_E_FRONT_ID)
  {
    aUSS_v_FrontDetectStart_b = isEnd;
  }
  else
  {
    aUSS_v_RearDetectStart_b = isEnd;
  }
}

void aUSSMgr_f_PASOnAlarm_v(void)
{
  if(MEUssMgr_v_IntermediateSignals_t.USSC_SysStatus == E_aJobUSSCtrl_RUNNING)
  {
    if((aUSS_D_RUNNING_CLUSTER==pUS_E_ALL_ID ||
        aUSS_D_RUNNING_CLUSTER==pUS_E_REAR_ID) &&
        aUSS_v_NeedRogerBeep)
    {
      aUSSMgr_f_StopBuzzer_v(pUS_E_FRONT_ID);
      aUSSMgr_f_PasOnBuzzer_v(pUS_E_REAR_ID);
      aUSS_v_NeedRogerBeep = ME_FALSE;
    }
    else if(aUSS_D_RUNNING_CLUSTER==pUS_E_FRONT_ID &&
            aUSS_v_NeedRogerBeep)
    {
      aUSSMgr_f_StopBuzzer_v(pUS_E_REAR_ID);
      aUSSMgr_f_PasOnBuzzer_v(pUS_E_FRONT_ID);
      aUSS_v_NeedRogerBeep = ME_FALSE;
    }
  }
}

void MEUssMgr_f_BuzzerSegment_v(uint8_t segment_F, uint8_t segment_R)
{
  pUS_E_ClusterID_t CID;

  if(aUSS_D_RUNNING_CLUSTER == pUS_E_REAR_ID)
  {
    CID = pUS_E_REAR_ID;
    if((aUSSMgr_f_GetRogerEnd_b(pUS_E_REAR_ID) == ME_FALSE) || (segment_bk == segment_R && CID_bk == CID))
    {
      return;
    }
    else
    {
      //drv_BuzzerSetting(pUS_E_FRONT_ID, BEEP_MUTE, 1024);
      segment_bk = segment_R;
      CID_bk = CID;
    }
  }
  else if(aUSS_D_RUNNING_CLUSTER == pUS_E_FRONT_ID)
  {
    CID = pUS_E_FRONT_ID;
    if((aUSSMgr_f_GetRogerEnd_b(pUS_E_FRONT_ID) == ME_FALSE) || (segment_bk == segment_F && CID_bk == CID))
    {
      return;
    }
    else
    {
      //drv_BuzzerSetting(pUS_E_REAR_ID, BEEP_MUTE, 1024);
      segment_bk = segment_F;
      CID_bk = CID;
    }
  }
  else if(aUSS_D_RUNNING_CLUSTER == pUS_E_ALL_ID)
  {
    if(aUSSMgr_f_GetRogerEnd_b(pUS_E_REAR_ID) == ME_FALSE)
    {
      return;
    }
    if(segment_R == 0 && segment_F == 0)
    {
      CID = pUS_E_CLUSTER_ID_MAX;
      if(segment_bk == segment_R && CID_bk == CID)
      {
        return;
      }
      else
      {
        drv_BuzzerSetting(pUS_E_FRONT_ID, BEEP_MUTE, 1024);
        drv_BuzzerSetting(pUS_E_REAR_ID, BEEP_MUTE, 1024);
        segment_bk = segment_R;
        CID_bk = CID;
      }
    }
    else if((segment_R && segment_R <= segment_F) || segment_F == 0)
    {
      CID = pUS_E_REAR_ID;
      if(segment_bk == segment_R && CID_bk == CID)
      {
        return;
      }
      else
      {
        drv_BuzzerSetting(pUS_E_FRONT_ID, BEEP_MUTE, 1024);
        segment_bk = segment_R;
        CID_bk = CID;
      }
    }
    else
    {
      CID = pUS_E_FRONT_ID;
      if(segment_bk == segment_F && CID_bk == CID)
      {
        return;
      }
      else
      {
        drv_BuzzerSetting(pUS_E_REAR_ID, BEEP_MUTE, 1024);
        segment_bk = segment_F;
        CID_bk = CID;
      }
    }
  }
  else
  {
    return;
  }
  

  switch(segment_bk)
  {
    case 1://danger zone
        drv_BuzzerSetting(CID, CONTINUES_BEEP, 15);
      break;

    case 2://detection zone
        drv_BuzzerSetting(CID, INTERVAL_BEEP, 30);
      break;

    case 3://detection zone
        drv_BuzzerSetting(CID, INTERVAL_BEEP, 55);
      break;

    case 4://detection zone
        drv_BuzzerSetting(CID, INTERVAL_BEEP, 80);
      break;;

    case 5://detection zone
        drv_BuzzerSetting(CID, INTERVAL_BEEP, 105);
      break;;

    case 6://detection zone
        drv_BuzzerSetting(CID, INTERVAL_BEEP, 135);
      break;;

    case 7://detection zone
        drv_BuzzerSetting(CID, INTERVAL_BEEP, 175);
      break;;

    default:
        drv_BuzzerSetting(CID, BEEP_MUTE, 0);
      break;
  }
}
#endif
