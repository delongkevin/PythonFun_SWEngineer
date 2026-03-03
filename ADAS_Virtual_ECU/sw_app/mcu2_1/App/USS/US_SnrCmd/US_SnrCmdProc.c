/*
 * US_SnrCmdProc.c
 *
 *  Created on: May 11, 2021
 *      Author: jonapais
 */
#include "US_ME_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_Platform_Global.h"
#include "US_SnrData_Typedefs_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_SnrCmd.h"
#include "US_SnrCmd_Global.h"
#include "US_PlatformCfg_Global.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_SnrDrv_CsmIf.h"
#endif

static void UssSnrCmd_SetSnrDisconnectFaults(uint32_t uMaskedNoSnrResponse);

static US_S_SensorMeasRcvRecs_t sSnrCmdMeasRcvRec;
static US_E_ParkingMode_t uLoggedParkingMode = US_PARKMODE_PARKING;
static uint8_t uLoggingProtocolVer = ZERO;

#if(US_CSM_ENABLE == ME_TRUE)
static UsCsm_LocalStateId_Type LocalStateId_SnrDrv = US_CSM_LOCAL_STATE_UN_INIT;
#endif

/*comment out:static uint32_t uNoRingtimeResponse = ZERO;  */

#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
US_S_DBG_AllSnsRcvRecStats_t UssDBG_sAllSnsFrameStats;
#endif

#define US_D_FREQ_SCALE (572u)
#define US_D_ECHO_STATUS_BITS (0xC0u)
#define US_D_ECHO_STATUS_BITS_SHIFT (SIX)

/*===========================================================================
 * \brief Parse raw SPI buffer for sensor burst command.
 *
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_ProcessSensorMeasurments
 * Remarks:  DD-ID: {547E3899-348A-4a76-80BC-FDFFA456C182}
 * Req.-ID: 16471530
 * Req.-ID: 13414924
 * Req.-ID: 13427611
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch statements doesn't lead to any complexcity */
void UssSnrCmd_ProcessSensorMeasurments(void)
{
    uint16_t uSpiRetLen;
    uint16_t uBytesProcessed;
    /*comment out:uint32_t uRingTimeReceived = ZERO;  */
    uint8_t uSensorIdx;
    uint8_t uEchoIdx;
    uint8_t uEchoType;
    uint8_t  uRecordSize = sizeof(US_S_Sensor_Echo_t);
    uint8_t  uBusIdx;
    bool_t   uBufferSizeError = ME_FALSE;
    US_S_SensorRcvRec_t *psSensorRec = NULL;
    US_S_Echo_t *psEchoRec;
    US_E_SendType_t const* peReqEchoType;
    US_E_SendType_t const* peMeasEchoType;
	const uint8_t * pauSnrIdxList  = UssCtrl_pauGetSnrIdxList();  /* Get pointer to the sensor index list. */
    const uint8_t * puSpiBurstDataBuff = UssSnrCmd_puGetSpiBurstDataBuff();
	US_S_Sensor_Echo_t const *psEchoData = (US_S_Sensor_Echo_t const*) &puSpiBurstDataBuff[TWO];    /* Cast header of data buffer to header struct */
    /* Clear out echo records for new data.  */
    (void)memset(&sSnrCmdMeasRcvRec, 0, sizeof(sSnrCmdMeasRcvRec));
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
    memset(&UssDBG_sAllSnsFrameStats, 0u, sizeof(UssDBG_sAllSnsFrameStats));
#endif

    uSpiRetLen = ((uint16_t) puSpiBurstDataBuff[ONE] << EIGHT) | puSpiBurstDataBuff[ZERO];   /* Return length is first two bytes */
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
    UssDBG_sAllSnsFrameStats.uSpiDataSize = uSpiRetLen;
#endif
    

    uBytesProcessed = ZERO;
    while ((uBytesProcessed + uRecordSize) <= uSpiRetLen)
    {
        /* Jump over any gaps in data */
        if (psEchoData->uSnrIdx == US_D_CMD_DATA_GAP)
        {
            /* Advance to next record */
            psEchoData++;
            uBytesProcessed += uRecordSize;
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
            UssDBG_sAllSnsFrameStats.uSensorGaps++;
#endif
            continue;
        }

#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
        if(US_D_MAX_NUM_SENSORS < psEchoData->uSnrIdx)
        {
            /* Driver/DSI sent us a bad sensor index. It will go out of bounds of internal list */
            UssDBG_sAllSnsFrameStats.uEventFlagBitmap |= US_D_DBG_FRAME_EVT_BAD_DRVIDX;
        }
#endif
        uSensorIdx = pauSnrIdxList[psEchoData->uSnrIdx];       /* Index of sensor echo data  */
        /* Bit 0x80 is Remaining Echo Flag.  Echoes remaining in sensor buffer.  Processed after sensor bounds check. */
        /* Bit 0x40 is a flag we are not using at this layer. (Measurment Ongoing Flag) */
        uEchoIdx   = (psEchoData->uEchoIdx & 0x3fu) - ONE;     /* Echo returns index ones-based i.e [1, n], store base-0 [0,n). */

        /* Echo type (cType) :
         *  US_E_NOECHO = 0,
         *  US_E_RINGTIME = 1,
         *  US_E_FIXED = 2,
         *  US_E_CHIRP_DOWN = 3,
         *  US_E_CHIRP_UP = 4,
         *  US_E_NFD = 5,
         *  US_E_CHIRP_MAX = 6
         */
        uEchoType = (US_E_EchoType_t)(((psEchoData->t.uEchoType) >> FOUR) & 0x0Fu);  

        /* Check if sensor index and echo index are valid for buffer */
        if (uSensorIdx < US_D_MAX_NUM_SENSORS)
        {
            psSensorRec = &sSnrCmdMeasRcvRec.sSensorRec[uSensorIdx];
            if (psSensorRec->uNumEchoes >= US_D_DRV_MAX_ECHOES_BUFF)
            {
                uBufferSizeError = ME_TRUE;
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
                UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uFrameFlagBitmap |= US_D_DBG_FRAME_EVT_ECHO_FULL;
#endif
            }
        }
        else
        {
            uBufferSizeError = ME_TRUE;
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
            /* No choice but to add to first sensor since sensor index itself is bad */
            UssDBG_sAllSnsFrameStats.sFrameInfo[ZERO].uFrameFlagBitmap |= US_D_DBG_FRAME_EVT_BAD_SNSIDX;
#endif
        }

        if (uBufferSizeError == (bool_t)ME_TRUE)
        {
            /* Buffer not big enough.  Advance to next record in SPI data.  */
            psEchoData++;
            uBytesProcessed += uRecordSize;
#if UART_SUPPORTED
            cMELog_F_LogDebug_v("UssSnrCmd_callback_SendBurst: Buffer not big enough Error. SnrIdx = %d, EchoIdx = %d", uSensorIdx, uEchoIdx);
#endif
            uBufferSizeError = ME_FALSE;  /* Continue to store data when within range.  */
            continue;
        }

        /* Efficiency pointers */
        psSensorRec = &sSnrCmdMeasRcvRec.sSensorRec[uSensorIdx];
        psEchoRec = &psSensorRec->sEcho[psSensorRec->uNumEchoes];

        /* Bit 0x80 is Remaining Echo Flag.  Echoes remaining in sensor buffer;  */
        psSensorRec->uMeasStatBits = (psEchoData->uEchoIdx & US_D_ECHO_STATUS_BITS) >> US_D_ECHO_STATUS_BITS_SHIFT;

        /* Store map of received responses, for use in detecting sensor disconnects. */
        sSnrCmdMeasRcvRec.uResponseReceived |= (uint32_t)US_IDX_TO_BIT_LOC(uSensorIdx);/* App layer index - response received */

        /* Parse the remaining data */
        switch (uEchoType)
        {
            case (uint8_t)US_E_NOECHO: /* No Echo */
            {
                /* No echo received at this sensor / echo index. */
                psEchoRec->eEchoType = US_E_NOECHO;
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
                UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uNoEchoFrames++;
#endif
            }
            break;

            case (uint8_t)US_E_RINGTIME: /* Ringing Time */
            {
                /*comment out:uRingTimeReceived |= US_IDX_TO_BIT_LOC(uSensorIdx); */
                US_S_RingTime_t *psRingTime = &psSensorRec->sRingTime;

                psSensorRec->uDiagStatus = psEchoData->t.DiagStatus & 0x0Fu;
                psRingTime->uDrvFreq     = psEchoData->d.diag.DrvFreq_572  * US_D_FREQ_SCALE;
                psRingTime->uRingFreq    = psEchoData->d.diag.RingFreq_572 * US_D_FREQ_SCALE;
                psRingTime->uRingTime    = ((uint16_t)psEchoData->d.diag.EvRing_H << EIGHT) |( psEchoData->d.diag.EvRing_L); 
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
                UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uOtherFrames++;
#endif
            }
            break;

            case (uint8_t)US_E_FIXED: /* Fixed Path */
            {
                psEchoRec->eEchoType    = (US_E_EchoType_t) uEchoType;
                psEchoRec->uDistTOF_us  = ((uint16_t)psEchoData->d.fixed.Dist_H << 8u) | (psEchoData->d.fixed.Dist_L); 
                psEchoRec->uEchoHeight  = psEchoData->d.fixed.EchoHeight;
                psEchoRec->uWidth       = (uint16_t)((psEchoData->d.fixed.EchoWidth & 0x1fu) << 2u) << (psEchoData->d.fixed.EchoWidth >> FIVE);   
                psEchoRec->uConf        = ZERO;

                if (psSensorRec->uNumEchoes == ZERO)
                {
                    psSensorRec->uFirstEchoIdx = uEchoIdx;
                }
                psSensorRec->uNumEchoes++;
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
                UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uEchoFrames++;
#endif
            }
            break;

            case (uint8_t)US_E_CHIRP_DOWN: /* Filter 1 Path  */
            case (uint8_t)US_E_CHIRP_UP:   /* Filter 2 Path  */
            {
                psEchoRec->eEchoType    = (US_E_EchoType_t) uEchoType;
                psEchoRec->uDistTOF_us  = ((uint16_t)psEchoData->d.filter.Dist_H << 8) | (psEchoData->d.filter.Dist_L); 
                psEchoRec->uEchoHeight  = ((uint16_t) (psEchoData->d.filter.EchoHeight & 0x1fu) << FOUR) << (psEchoData->d.filter.EchoHeight >> FIVE); /*   S 0499,1861, 4391, 4393, 4491, 4542, 4533 */
                psEchoRec->uWidth       = ZERO;
                psEchoRec->uConf        = psEchoData->d.filter.Width_conf;

                if (psSensorRec->uNumEchoes == ZERO)
                {
                    psSensorRec->uFirstEchoIdx = uEchoIdx;
                }
                psSensorRec->uNumEchoes++;
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
                UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uEchoFrames++;
#endif
            }
            break;

            case (uint8_t)US_E_NFD:  /* NFD **** CURRENTLY SENSOR NEVER SENDS THIS!!! COMES BACK AS FIXED!!! **** */
            {
                psEchoRec->eEchoType    = (US_E_EchoType_t) uEchoType;
                psEchoRec->uDistTOF_us  = ((uint16_t)psEchoData->d.filter.Dist_H << EIGHT) | (psEchoData->d.filter.Dist_L); /*   S 0499, 4491*/
                psEchoRec->uEchoHeight  = psEchoData->d.filter.EchoHeight;
                psEchoRec->uWidth       = ZERO;
                psEchoRec->uConf        = ZERO;

                if (psSensorRec->uNumEchoes == ZERO)
                {
                    psSensorRec->uFirstEchoIdx = uEchoIdx;
                }
                psSensorRec->uNumEchoes++;
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
                UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uEchoFrames++;
#endif
            }
            break;
			
            case (uint8_t)US_E_NOISE_INFO: /* Noise monitoring information  */
            {
                US_S_NoiseMeas_t *psNoiseMeas = &psSensorRec->sNoiseMeas;

                psNoiseMeas->uSum    = ((uint16_t) psEchoData->d.noise.uSum_H << EIGHT )| (psEchoData->d.noise.uSum_L);
                psNoiseMeas->uCount  = psEchoData->d.noise.uCount;
                psNoiseMeas->uHeight = psEchoData->d.noise.uEchoHeight;
                psNoiseMeas->uATG    = psEchoData->d.noise.uATG;
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
                UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uOtherFrames++;
#endif
            }
            break;

            default:
            { /* empty */
#if UART_SUPPORTED
                cMELog_F_LogDebug_v("UssSnrCmd_callback_SendBurst: Echo Type Error. SnrIdx = %d, EchoIdx = %d", uSensorIdx, uEchoIdx);
#endif
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
                UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uOtherFrames++;
                UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uFrameFlagBitmap |= US_D_DBG_FRAME_EVT_UNKNOWN_TYPE;
#endif
            }
            break;
        }

        /* Advance to next record in SPI data.  */
        psEchoData++;

        /* Can not use pointer++ due to odd record size of seven,
         * increment Will advance 8 bytes, which will not work
         * for a packed buffer.
         */
        uBytesProcessed += uRecordSize;
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
        UssDBG_sAllSnsFrameStats.sFrameInfo[uSensorIdx].uTotalFrames++;
#endif
    }

    /* Store timestamp */
    sSnrCmdMeasRcvRec.uTimeStamp = UssSnrCmd_uGetuSnrMeasRcvTime();
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
    UssDBG_sAllSnsFrameStats.uBytesProcessed = uBytesProcessed;
    UssDBG_sAllSnsFrameStats.uTimeStamp = sSnrCmdMeasRcvRec.uTimeStamp;
#endif

    /* Store burst request type */
    sSnrCmdMeasRcvRec.uSendingSensors = UssSnrCmd_uGetSendingSensors();

    /* Transcribe requested echo type array into received data structure */
    peReqEchoType = peGetReqEchoType();
    peMeasEchoType = peGetMeasEchoType();

    for (uSensorIdx = ZERO; uSensorIdx < US_D_MAX_NUM_SENSORS; uSensorIdx++)
    {
        sSnrCmdMeasRcvRec.sSensorRec[uSensorIdx].eEchoTypeRequested = peReqEchoType[uSensorIdx];
        sSnrCmdMeasRcvRec.sSensorRec[uSensorIdx].eMeasTypeRequested = peMeasEchoType[uSensorIdx];
    }

    /*
     * If a sending sensor did not receive a ring time message, even if it sent a NO_ECHO message,
     * then is is probably disconnected.
     */

  /* comment out:  uNoRingtimeResponse &= ~sSnrCmdMeasRcvRec.uSendingSensors;   */
  /* comment out:  uNoRingtimeResponse |= (sSnrCmdMeasRcvRec.uSendingSensors ^ uRingTimeReceived);   */
  /* comment out:  sSnrCmdMeasRcvRec.uResponseReceived &= ~uNoRingtimeResponse;  */

    /* Set burst receive profiles.
     *  Note: Used for debugging only.  Not passed to Manager records.
     */
    for (uBusIdx = ZERO; uBusIdx < US_D_MAX_NUM_BUS; uBusIdx++)
    {
        sSnrCmdMeasRcvRec.eRcvProfile[uBusIdx] = UssSnrCmd_uGetRcvProfiles(uBusIdx);
    }

    /* Perform sensor disconnect checks and set diag flags.   */
    (void)UssSnrCmd_CheckSnrDisconnect(sSnrCmdMeasRcvRec.uResponseReceived, UssSnrCmd_uGetAppEnableMap());
}

/*===========================================================================
 * \brief Check for sensor disconnect in measurement data.
 * \param none
 * \param none
 * \return uint16_t Error code.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_CheckSnrDisconnect
 * Remarks:  DD-ID: {082D16E9-3819-456d-A099-E6AB7CFC8F3F}
 * Traceability to source Code: Req.-ID: 13393744
 * Req.-ID: 15222448
 * Req.-ID: 15222445
 * ===========================================================================*/
uint16_t UssSnrCmd_CheckSnrDisconnect(uint32_t uResponseReceived, uint32_t uAppSnrEnableMap)
{
    uint16_t uReturn = ME_OK;
    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_FALSE)
    uint8_t  uSnrIdx;
#endif

    /* Check for disconnected sensor */
    uint32_t uMaskedNoSnrResponse = ~uResponseReceived; /* Application index based no response.  */

    /* Don't expect a response from sensors that were put into standby, or are uninstalled.
     * Note: If we ever move over the limit of 16 sensors, some bitmaps must be upgraded to 32 bit
     */
    uMaskedNoSnrResponse &= (uAppSnrEnableMap & psPlatPhysInfo->uInstSnrAppIdxBitMask);

    if (uMaskedNoSnrResponse != ZERO)
    {
        /* Driver index based no response, driver enable map considered later.  */
        UssSnrCmd_SetSnrDisconnectFaults(uMaskedNoSnrResponse);

        uReturn = ME_ERROR;
    }
    else
    {
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
	    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SENSOR_DISCONNECT, US_D_ALL_SNR_BITMAP); /* Clear resolved disconnects.  */
		US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_COMM_UNKNOWN, US_D_ALL_SNR_BITMAP); /* Clear resolved unknowns.  */
    #if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
        US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_FAIL, US_D_ALL_SNR_BITMAP);         /* Clear resolved sensor failures.  */
    #endif
#else
       for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
       {
           if ((psPlatPhysInfo->uInstSnrAppIdxBitMask & (uint32_t) US_IDX_TO_BIT_LOC(uSnrIdx)) != ZERO)    /* Sensor is calibrated as installed */
           {
               US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_COMM_UNKNOWN, uSnrIdx);  /* Clear resolved unknowns. */
               US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SENSOR_DISCONNECT, uSnrIdx); /* Clear resolved disconnects. */

    #if (((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
               US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_FAIL, uSnrIdx); /* Clear resolved sensor failures. */
    #endif
           }
       }
#endif
    }

    return uReturn;
}

/*===========================================================================
 * \brief Set sensor disconnect faults.
 * \param uint32_t uMaskedNoSnrResponse - App indexing bitmap of installed sensors that did not respond.
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_SetSnrDisconnectFaults
 * Remarks:  DD-ID: {D6D55256-CD8A-412b-B757-96A6AF47013E}
 * Traceability to source Code: Req.-ID: 15222460
 * Req.-ID: 15003087
 * Req.-ID: 15003128
 * Req.-ID: 15222448
 * Req.-ID: 13393741
 * ===========================================================================*/
static void UssSnrCmd_SetSnrDisconnectFaults(uint32_t uMaskedNoSnrResponse)
{
    uint16_t uSnrUnknownBitmap = ZERO;
    uint16_t uSnrDisconnectBitmap = ZERO;
#if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
    uint16_t uSnrFailBitmap = ZERO;
#endif
    uint32_t uAppBitMask;
    uint32_t uPrevUknAppBitMask;
    uint8_t  uSnrDvrIdx;
    uint8_t  uCurBusIdx;
    bool_t   bWasPrevNoResp;
    bool_t	 bWasPrevfail = ME_FALSE;
    bool_t   bIsNoMoreDisconnects;
    bool_t   bLastSensorOnBus;
    bool_t   bIsSensorInstalled;
#if (US_D_FAULT_DEBOUNCE_BY_TIME != ME_TRUE)
    uint8_t  uSnrIdx;
#endif

    const uint8_t * puSnrBusList = UssCtrl_pauGetSnrBusList();
    const uint8_t * pauSnrCfgIdxList = UssCtrl_pauGetSnrCfgIdxList();    /* Get pointer to the config app index list. */
    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    US_S_Sensor_Temperature_t * psTemperatures = UssSnrCmd_psGetSnrTemperatures();

    /* Initial states */
	
    uCurBusIdx = puSnrBusList[pauSnrCfgIdxList[ZERO]];
    bWasPrevNoResp = ME_FALSE;
    bIsNoMoreDisconnects = ME_FALSE;
    bLastSensorOnBus = ME_FALSE;
    uPrevUknAppBitMask = ZERO;
    uAppBitMask = ZERO;

    /* Traverse sensor list in driver configuration order.
     * Lower indexes are towards the tip of the bus wires for a bus.
     * Thus we are traversing tip to ecu along each bus.
     */
    for (uSnrDvrIdx = ZERO; uSnrDvrIdx < US_D_MAX_NUM_SENSORS; uSnrDvrIdx++)
    {
        /* Note if sensor is installed */
        bIsSensorInstalled  = (bool_t)((psPlatPhysInfo->uInstSnrAppIdxBitMask & US_IDX_TO_BIT_LOC(pauSnrCfgIdxList[uSnrDvrIdx])) != ZERO); 

        if (bIsSensorInstalled == (bool_t)ME_TRUE) /* This sensor IS installed, do disconnect logic. */
        {
            uAppBitMask = (uint32_t)US_IDX_TO_BIT_LOC(pauSnrCfgIdxList[uSnrDvrIdx]); /* Calculate current Application Bit Mask for sensor */

            /* Check if sensor is responding */
            if ((uMaskedNoSnrResponse & uAppBitMask) == ZERO)  /* If this sensor was measured, installed, and in use. */
            {
                if (bWasPrevNoResp == (bool_t)ME_TRUE) /* If the previous sensor was not measured */
                {
                    /* Upgrade unknown to confirmed disconnect */
                    uSnrUnknownBitmap    &= (uint16_t)(~uPrevUknAppBitMask);    
				 
                 	/* Avoid setting of sensor disconnect when orginally it was only a sensor fail */
                 	if(bWasPrevfail != (bool_t)ME_TRUE) 
                 	{
                		uSnrDisconnectBitmap |= (uint16_t)uPrevUknAppBitMask;    
                 	}
                 	bWasPrevfail = ME_FALSE;
                }

                 bWasPrevNoResp = ME_FALSE;
                 bIsNoMoreDisconnects = ME_TRUE;
            }
            else  /* This sensor IS installed but not measured. */
            {
                /* Clear temperature of broken/disconnected sensors. */
                psTemperatures->iSnrTemperature[pauSnrCfgIdxList[uSnrDvrIdx]] = 0;  /* Clear temperature of broken/disconnected sensors. */

                /*
                 * If this is the last disconnect or just a broken sensor then mark now.
                 */
                if (bIsNoMoreDisconnects == (bool_t)ME_TRUE)
                {
                    /* No more disconnects so set to fault right away.  */
#if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
                    uSnrFailBitmap |= (uint16_t)uAppBitMask;    
                    bWasPrevfail = ME_TRUE;
#else
                    uSnrDisconnectBitmap |= uAppBitMask;
#endif
                }
                else /* Set to unknown for now.  */
                {
                    uSnrUnknownBitmap |= (uint16_t)uAppBitMask;    
                }

                bWasPrevNoResp = ME_TRUE;
                uPrevUknAppBitMask = uAppBitMask;    /* Store last unknown sensor index */
            }
        }
        /* Check for end of bus logic */
        if (uSnrDvrIdx == (US_D_MAX_NUM_SENSORS - ONE))  /* Last sensor is automatically end of bus, even if uninstalled. */
        {
            bLastSensorOnBus = ME_TRUE;
        }
        else if (   (0xFFu != puSnrBusList[pauSnrCfgIdxList[uSnrDvrIdx]])         /* If next sensor is not installed, we're done. */
                 && (uCurBusIdx != puSnrBusList[pauSnrCfgIdxList[uSnrDvrIdx + ONE]]))  /* If so, check for bus index change. */
        { 
        	bLastSensorOnBus = ME_TRUE;
        }
        else{ /* Do Nothing */ }
		
		/* Process end of bus */
        if (bLastSensorOnBus == (bool_t)ME_TRUE)
        {
            if (bWasPrevNoResp == (bool_t)ME_TRUE)
            {
                /* Upgrade unknown to confirmed disconnect */
                if ((psPlatPhysInfo->uInstSnrAppIdxBitMask & uPrevUknAppBitMask) != ZERO) /* Double check, safety. */
                {
#if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
                    if (bIsNoMoreDisconnects == (bool_t)ME_TRUE)  /* Other platforms distinguish between disconnects and faulted sensors. */
                    {
                        uSnrFailBitmap |= (uint16_t)uPrevUknAppBitMask;
                    }
                    else
                    {
                        uSnrUnknownBitmap    &= ~(uint16_t)uPrevUknAppBitMask;
                        uSnrDisconnectBitmap |= (uint16_t)uPrevUknAppBitMask;
                    }
#else
                    uSnrUnknownBitmap    &= ~uPrevUknAppBitMask;
                    uSnrDisconnectBitmap |= uPrevUknAppBitMask;  /* Rivian uses same comm fault for disconnects as well as faulted sensors. */
#endif
				 }
            }

            /* Get the loop ready for the next series of sensors on a bus. */
            bWasPrevNoResp = ME_FALSE;
            bIsNoMoreDisconnects = ME_FALSE;
            bLastSensorOnBus = ME_FALSE;

            if (uSnrDvrIdx != (US_D_MAX_NUM_SENSORS - ONE))
            {
                uCurBusIdx = puSnrBusList[pauSnrCfgIdxList[uSnrDvrIdx + ONE]];  /* Advance to next bus index. */
            }
        }
    }

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)

    /***KPK core Diag- need to have different strategy*/
    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_COMM_UNKNOWN, ~uSnrUnknownBitmap);  /* Clear resolved unknowns. */
    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_COMM_UNKNOWN, uSnrUnknownBitmap);   /* Set unknowns. */

    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SENSOR_DISCONNECT, ~uSnrDisconnectBitmap); /* Clear resolved disconnects. */
    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SENSOR_DISCONNECT, uSnrDisconnectBitmap);  /* Set confirmed  disconnects. */

#if (((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
    US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_SNR_FAIL, ~uSnrFailBitmap); /* Clear resolved sensor failures.  */
    US_Diagnostic_SetSnrFaultFlag(SNR_DIAG_FLG_SNR_FAIL, uSnrFailBitmap);  /* Set confirmed  sensor failures.  */
#endif

#else
    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
       uAppBitMask = (uint32_t) US_IDX_TO_BIT_LOC(uSnrIdx);              

       if ((psPlatPhysInfo->uInstSnrAppIdxBitMask & uAppBitMask) != ZERO)   /* Sensor is calibrated as installed */
       {
           if ((uSnrUnknownBitmap & uAppBitMask) != ZERO)
           {
               US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_COMM_UNKNOWN, uSnrIdx);   /* Set unknowns. */
           }
           else
           {
               US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_COMM_UNKNOWN, uSnrIdx);  /* Clear resolved unknowns. */
           }

           if ((uSnrDisconnectBitmap & uAppBitMask) != ZERO)
           {
               US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SENSOR_DISCONNECT, uSnrIdx);  /* Set confirmed  disconnects. */
           }
           else
           {
               US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SENSOR_DISCONNECT, uSnrIdx); /* Clear resolved disconnects. */
           }

#if (((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS) || ((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM) == US_D_PLATFORM_DTPAM))
           if ((uSnrFailBitmap & uAppBitMask) != ZERO)
           {
               US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_FAIL, uSnrIdx);  /* Set confirmed  sensor failures. */
           }
           else
           {
               US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_FAIL, uSnrIdx); /* Clear resolved sensor failures. */
           }
#endif
       }
    }
#endif
}

#if (QAC_WARNING_FIX  ==  ME_FALSE)
/*===========================================================================
 * \brief Copy sensor echo measurement data from playback into sensor measurement buffer.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_CopyPlaybackMeasRecord
 * Remarks:  DD-ID: {138B8527-01EF-47d6-9911-5ECEE2A347A7}
 * Traceability to source Code: Req.-ID:14995521
 * ===========================================================================*/
void UssSnrCmd_CopyPlaybackMeasRecord(const US_S_SensorMeasRecsForLogging_t *psSnrMeasLogRec,
                                      uint8_t const *Replay_NoiseDataRecs)
{
    uint8_t uSnrIdx;
    uint8_t uNoiseDataIndex;
	uint8_t uCurEchoIdx;
	uint8_t uLocalLoggingProtocolVer = psSnrMeasLogRec->uProtocolVersionNum;

    /* Common data */
    sSnrCmdMeasRcvRec.uTimeStamp        = psSnrMeasLogRec->uTimeStamp;
    sSnrCmdMeasRcvRec.uResponseReceived = psSnrMeasLogRec->uResponseReceived;
    sSnrCmdMeasRcvRec.uSendingSensors   = psSnrMeasLogRec->uSendingSensors;

    for (uSnrIdx = 0; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++) /* Hard-coded 32 sensors max. */
    {
        US_S_SensorRcvRec_t  * psSensorRcvRec = &sSnrCmdMeasRcvRec.sSensorRec[uSnrIdx];
        const US_S_SensorRecForLogging_t * psSensorRec = &psSnrMeasLogRec->sSensorRec[uSnrIdx];

        /* Copy sensor data */
        psSensorRcvRec->eEchoTypeRequested = psSensorRec->eEchoTypeRequested;
        psSensorRcvRec->uDiagStatus        = psSensorRec->uDiagStatus;
        psSensorRcvRec->uFirstEchoIdx      = psSensorRec->uFirstEchoIdx;


        (void)memcpy(&psSensorRcvRec->sRingTime, &psSensorRec->sRingTime, sizeof(US_S_RingTime_t));

        psSensorRcvRec->uNumEchoes = psSensorRec->uNumEchoes;

        (void)memset(&psSensorRcvRec->sEcho, 0, sizeof(psSensorRcvRec->sEcho));

        for (uCurEchoIdx = ZERO; uCurEchoIdx < psSensorRcvRec->uNumEchoes; uCurEchoIdx++)
        {
            (void)memcpy(&psSensorRcvRec->sEcho[uCurEchoIdx], &psSensorRec->sEcho[uCurEchoIdx], sizeof(US_S_Echo_t));
        }

        if (uLocalLoggingProtocolVer != ZERO)
        {
            /* Meas stat bits  */
            psSensorRcvRec->uMeasStatBits = psSnrMeasLogRec->auMeasStatusBits[uSnrIdx];

            /* Noise Records */
            if (Replay_NoiseDataRecs != NULL)
            {
                uNoiseDataIndex = (uSnrIdx * (sizeof(US_S_NoiseMeas_t)-1u));
                /* \ memcpy((uint8_t *) (&psSensorRcvRec->sNoiseMeas), (uint8_t *) (&(((US_S_NoiseMeas_t *) Replay_NoiseDataRecs)[uSnrIdx])), sizeof(US_S_NoiseMeas_t)); */
                (void)memcpy((uint8_t*)&psSensorRcvRec->sNoiseMeas.uSum, &Replay_NoiseDataRecs[uNoiseDataIndex], sizeof(uint16_t));
                psSensorRcvRec->sNoiseMeas.uCount = Replay_NoiseDataRecs[uNoiseDataIndex + TWO];
                psSensorRcvRec->sNoiseMeas.uHeight = Replay_NoiseDataRecs[uNoiseDataIndex + THREE];
                psSensorRcvRec->sNoiseMeas.uATG = Replay_NoiseDataRecs[uNoiseDataIndex + FOUR];
            }
        }
        else
        {
            psSensorRcvRec->uMeasStatBits = ZERO;   /* Default meas bits */
            (void)memset((uint8_t *) (&psSensorRcvRec->sNoiseMeas), 0, sizeof(US_S_NoiseMeas_t)); /* Default noise record */
        }

    }

    /* Set logged parking mode to be picked up by manager mode controller later */
    UssCtrl_SetNewSnrPlaybackDataFlag();
}
/* ===========================================================================
 * Name: UssSnrCmd_CopyPlaybackHwDiagRecord    
 * Remarks:  DD-ID: {09D45CC7-E964-406a-8040-608B139DF94C}
 * ===========================================================================*/
void UssSnrCmd_CopyPlaybackHwDiagRecord(US_S_Sensor_DiagnosticFlags_t const * Replay_DiagDataRecs)
{
    US_S_Sensor_DiagnosticFlags_t *psSnrDiagFlags = UssSnrCmd_psGetSnrDiagFlags();
    (void)memcpy((uint8_t *) psSnrDiagFlags, (uint8_t *) Replay_DiagDataRecs, sizeof(US_S_Sensor_DiagnosticFlags_t));
}
#endif
/*===========================================================================
 * \brief Get the sensor measurement record pointer.
 *
 * \param none
 * \param none
 * \return US_S_VehicleSensorRecs_t * pointer to measurement record.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_psGetMeasRcvRecPtr
 * Remarks:  DD-ID: {3CB44E79-4DBF-4f20-91B9-A15263DB553A}
 * Req.-ID: 13396080
 * ===========================================================================*/
const US_S_SensorMeasRcvRecs_t *UssSnrCmd_psGetMeasRcvRecPtr(void)
{
    return &sSnrCmdMeasRcvRec;
}

#if(US_CSM_ENABLE == ME_TRUE)

/* ===========================================================================
 * Name: Us_SnrDrv_ReqState_Csm    
 * Remarks:  DD-ID: {D940FEAC-CB5F-4ffc-81E5-89F632B17D69}
 * ===========================================================================*/
 UsCsm_StdReturn_Type Us_SnrDrv_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState)
 {
	(void)instanceId;
    LocalStateId_SnrDrv = reqState;
    return US_CSM_STD_RET_OK;
 }

/* ===========================================================================
 * Name: Us_SnrDrv_GetState_Csm    
 * Remarks:  DD-ID: {F81BCB64-C980-45e3-ADE5-BDDBE5747ADD}
 * ===========================================================================*/
 UsCsm_LocalStateId_Type Us_SnrDrv_GetState_Csm(UsCsm_InstanceId_Type instanceId)
 {
	(void)instanceId;
    return LocalStateId_SnrDrv;
 }
#endif

/* ===========================================================================
 * Name: UssSnrCmd_eGetLoggedParkingMode    
 * Remarks:  DD-ID: {A562BCEB-6FAE-499a-98D9-9AADAD0D2906}
 * ===========================================================================*/
US_E_ParkingMode_t UssSnrCmd_eGetLoggedParkingMode(void)
{
    return (const US_E_ParkingMode_t) uLoggedParkingMode;
}

/* ===========================================================================
 * Name: UssSnrCmd_uGetLoggingProtocolVer    
 * Remarks:  DD-ID: {99DB6823-FAA8-4411-852B-58C6EA5E5A35} 
 * ===========================================================================*/
uint8_t UssSnrCmd_uGetLoggingProtocolVer(void)
{
    return (const uint8_t) uLoggingProtocolVer;
}

