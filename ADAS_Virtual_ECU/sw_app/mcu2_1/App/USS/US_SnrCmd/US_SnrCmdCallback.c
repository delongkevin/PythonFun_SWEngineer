/*
 * US_SnrProcCallback.c
 *
 *  Created on: Apr 6, 2021
 *      Author: jonapais
 */
#include <string.h>
#include "US_ME_Typedefs_Global.h" 
#include "US_Platform_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_SnrCmd.h"
#include "US_SnrData_Typedefs_Global.h"
#include "US_Diagnostic_Global.h"

static uint32_t uSnrMeasErrCode = ME_OK;
static uint32_t uSnrMeasStartTime;
static uint32_t uSnrMeasRcvTime;

static US_S_Sensor_Temperature_t sSnrTemperature;
static US_S_Sensor_DiagnosticFlags_t sSnrDiagFlags;

#define US_SENSOR_FREQ_RESP_SIZE    (5u)

/*===========================================================================
 * \brief Callback for sensor burst command.
 *
 * \param none
 * \param none
 * \return
 * \remarks When complete sets command done flag.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_CmdCallback_SendBurst
 * Remarks:  DD-ID: {21625981-33A9-492b-80C8-C70CF71ABC85}
 * Req.-ID: 13395870
 *
 * ===========================================================================*/
void UssSnrCmd_CmdCallback_SendBurst(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData)
{
    /*KPK-QAC Fix : Need to suppress, Required to go through compilation */
    (void) uRcvSize; (void) uUserData; (void) uCmd; (void) puRcvData;

    uSnrMeasRcvTime = US_GetTimeStampTimeMs();

    /* Set error code */
    uSnrMeasErrCode = uErrorCode;
    UssSnrCmd_SetBurstCmdDone(ME_TRUE);

    US_UpdateProcTimeStats(&US_psGetTaskProcTimes()->sProcTime_SnrMeasTime, uSnrMeasStartTime);
}

/*===========================================================================
 * \brief Callback for sensor temperature request.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_CmdCallback_SnrTempCmd
 * Remarks:  DD-ID: {052DD150-B890-42be-89A0-7B131705C8EC}
 * Req.-ID: 13411731
 * Req.-ID: 13421049
 * Req.-ID: 13421051
 * ===========================================================================*/
void UssSnrCmd_CmdCallback_SnrTempCmd(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData)
{
	uint8_t uSnrIdx;
    US_S_Snr_Temperature_Fmt_t const *psTempData;
    (void) uRcvSize; (void) uUserData; (void) uCmd;  /* Unused at this time - suppresses warning.*/
    if (uErrorCode == ME_OK)
    {
        const uint8_t * pauSnrIdxList = UssCtrl_pauGetSnrIdxList();  /* Get pointer to the sensor index list.*/
        uint16_t uBytesProcessed;
        uint8_t  uRecordSize = sizeof(US_S_Snr_Temperature_Fmt_t);

        uint16_t uSpiRetLen = ((uint16_t) puRcvData[ONE] << EIGHT) | puRcvData[ZERO];

        puRcvData += TWO;
        uBytesProcessed = ZERO;
        while ((uBytesProcessed + uRecordSize) <= uSpiRetLen)
        {
            psTempData = (US_S_Snr_Temperature_Fmt_t *) puRcvData;      /* Cast data to temperature rcv format */

            /* Jump over any gaps in data */
            if (psTempData->uSnrIdx == US_D_CMD_DATA_GAP)
            {
                /* Advance to next record */
                puRcvData += uRecordSize;
                uBytesProcessed += uRecordSize;
                continue;
            }

            uSnrIdx = pauSnrIdxList[psTempData->uSnrIdx];
            if (uSnrIdx < US_D_MAX_NUM_SENSORS)
            {
                sSnrTemperature.iSnrTemperature[uSnrIdx] = (sint16_t) (((uint16_t) psTempData->uTemperatureByteH << EIGHT )|( psTempData->uTemperatureByteL));   
            }
            /*\cMELog_F_LogDebug_v("UssSnrCmd: Sensor Temperature: Idx = %d, Temp = %d", uSnrIdx, sSnrTemperature.iSnrTemperature[uSnrIdx]); */

            /* Advance to next record in SPI data. */
            puRcvData += uRecordSize;
            uBytesProcessed += uRecordSize;
        }

        sSnrTemperature.uTimeStamp = US_GetTimeStampTimeMs();
    }
}

/*===========================================================================
 * \brief Callback for sensor diagnostics request.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_CmdCallback_DiagResultCmd
 * Remarks:  DD-ID: {E63A6EAC-7A08-46a1-B679-D059BED4B50B}
 * Req.-ID: 16471226
 *Req.-ID: 13421051
 * ===========================================================================*/
void UssSnrCmd_CmdCallback_DiagResultCmd(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData)
{
	US_S_Snr_Diagnostics_ASIL_Fmt_t const *psDiagData;
    uint8_t uSnrIdx,uLogVer, Mode;
	uint16_t SnrVer;
	bool_t bplayback;
	const uint8_t * pauSnrIdxList = UssCtrl_pauGetSnrIdxList();  /* Get pointer to the sensor index list. */
	uint16_t uBytesProcessed;
	uint8_t  uRecordSize;
	uint16_t uSpiRetLen;
	bool_t  bIsAsilSnr;
	(void) uRcvSize; (void) uUserData; (void) uCmd; /* Unused at this time - suppresses warning. */
	bplayback  = UssCtrl_bIsSysInPlaybackMode();
	uLogVer =  UssSnrCmd_uGetLoggingProtocolVer();

    if ((bplayback == (bool_t)ME_FALSE) || (uLogVer == (uint8_t)ZERO))   /* Playback mode - Do not accept data. */
    {
        if (uErrorCode == ME_OK)
        {
             SnrVer  =     US_SnrCfg_Get_SnrFWVer();     
              Mode     =   US_SnrCfg_Get_Sensor_opmode() ;  
              bIsAsilSnr = (bool_t)((SnrVer != QM_SNR_FW_VER) && (Mode == SENSOR_OP_NORMAL));    /* for new command format*/

            (void)memset(&sSnrDiagFlags,0, sizeof(US_S_Sensor_DiagnosticFlags_t));


 
            if ((bool_t)ME_FALSE == bIsAsilSnr)
             {
                uRecordSize = sizeof(US_S_Snr_Diagnostics_F11A_Fmt_t);
            }
            else
            {
                uRecordSize = sizeof(US_S_Snr_Diagnostics_ASIL_Fmt_t);
            }

            uSpiRetLen =  ((uint16_t) puRcvData[1] << EIGHT) | puRcvData[ZERO];
            puRcvData += TWO;
            uBytesProcessed = ZERO;

            while ((uBytesProcessed + uRecordSize) <= uSpiRetLen)
            {
                /* Cast data to diagnostics rcv format (First 9 bytes are backwards-compatible with QM Sensors) */
                psDiagData = (US_S_Snr_Diagnostics_ASIL_Fmt_t const *) puRcvData;   

                /* Jump over any gaps in data */
                if (psDiagData->uSnrIdx == US_D_CMD_DATA_GAP)
                {
                    /* Advance to next record */
                    puRcvData += uRecordSize;
                    uBytesProcessed += uRecordSize;
                    continue;
                }

                uSnrIdx = pauSnrIdxList[psDiagData->uSnrIdx];

                if (uSnrIdx < US_D_MAX_NUM_SENSORS)
                {
                    sSnrDiagFlags.uResponseReceived |= (uint32_t)US_IDX_TO_BIT_LOC(uSnrIdx);  /* App layer index - response received */
					sSnrDiagFlags.uHardwareDiagFlags[uSnrIdx] = ((uint16_t) psDiagData->uHardwareDiagFlags_H << EIGHT) | (psDiagData->uHardwareDiagFlags_L);
                    sSnrDiagFlags.uMeasDiagFlags[uSnrIdx]     = ((uint16_t) psDiagData->uMeasDiagFlags_H << EIGHT )|( psDiagData->uMeasDiagFlags_L);
                    sSnrDiagFlags.uCommDiagFlags[uSnrIdx]     = ((uint16_t) psDiagData->uCommDiagFlags_H << EIGHT) |( psDiagData->uCommDiagFlags_L);

                    if ((bool_t)ME_TRUE == bIsAsilSnr)
                    {
                        sSnrDiagFlags.uAsilDiagFlags[uSnrIdx] = ((uint16_t) psDiagData->uAsilDiagFlags_H << EIGHT )| (psDiagData->uAsilDiagFlags_L);
                        sSnrTemperature.iSnrTemperature[uSnrIdx] = (sint16_t) (((uint16_t) psDiagData->uTemperatureByteH << EIGHT )|( psDiagData->uTemperatureByteL));   
                    }
                 }

                /* Advance to next record in SPI data. */
                puRcvData += uRecordSize;
                uBytesProcessed += uRecordSize;
            }

            sSnrDiagFlags.uTimeStamp = US_GetTimeStampTimeMs();

            if ((bool_t)ME_TRUE == bIsAsilSnr)
            {
                sSnrTemperature.uTimeStamp = US_GetTimeStampTimeMs();
            }
        }
    }
}

/* ===========================================================================
 * Name:	 UssSnrCmd_ReqFreqCmdCallback
 * Remarks:  DD-ID: {409A9A89-8BB4-4666-9200-72C2C47DD7E8}
 * Req.-ID: 
 * Req.-ID: 
 * Req.-ID: 
 * ===========================================================================*/
void UssSnrCmd_ReqFreqCmdCallback(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData)
{
    uint8_t uSnrDrvIdx, uSnrIdx;
    
    (void) uRcvSize;  (void) uCmd;  (void)uUserData; /* Unused at this time - suppresses warning.*/
    /* can check if uCmd matches REQ_SENSOR_FREQUENCY */
    /* can check if uUserData matches US_D_SENSORS_FREQ_DATA_PWD */

    /* Grab the correct buffer */
    US_S_AllSnrFreqData_t * psFreqData = UssMgr_GetSnrFreqData();

    if ( (uErrorCode == ME_OK) && (psFreqData != NULL) )
    {
        const uint8_t * pauSnrIdxList = UssCtrl_pauGetSnrIdxList();  /* Get pointer to the sensor index list.*/
        uint16_t uBytesProcessed;
        uint16_t uSpiRetLen = ((uint16_t) puRcvData[ONE] << EIGHT) | puRcvData[ZERO];

        puRcvData += TWO;
        uBytesProcessed = ZERO;
        while ((uBytesProcessed + US_SENSOR_FREQ_RESP_SIZE) <= uSpiRetLen)
        {
            uSnrDrvIdx =  puRcvData[uBytesProcessed] & 0x3f;      /* Sensor Index */

            /* Jump over any gaps in data */
            if (uSnrDrvIdx == US_D_CMD_DATA_GAP)
            {
                /* Advance to next record */
                uBytesProcessed += US_SENSOR_FREQ_RESP_SIZE;
                continue;
            }

            uSnrIdx = pauSnrIdxList[uSnrDrvIdx];
            if (uSnrIdx < US_D_MAX_NUM_SENSORS)
            {
                /* byte 0 is sensor index (used by now) */
                /* byte 1 - 2 is driving freq */
                psFreqData->saSnrFreqData[uSnrIdx].uDrvFreq_1Hz = (puRcvData[uBytesProcessed + ONE] << EIGHT) | (puRcvData[uBytesProcessed + TWO]);
                /* byte 3 - 4 is ring freq */
                psFreqData->saSnrFreqData[uSnrIdx].uRingFreq_1Hz = (puRcvData[uBytesProcessed + THREE] << EIGHT) | (puRcvData[uBytesProcessed + FOUR]);
            }

            /* Advance to next record in SPI data. */
            uBytesProcessed += US_SENSOR_FREQ_RESP_SIZE;
        }

        psFreqData->uTimestamp = US_GetTimeStampTimeMs();
    }
    /* Update cmd waiting count */
    //UssSnrCmd_DecESDCmdCnt();

}

/*===========================================================================
 * \brief Generic callback for all unimplemented commands.
 *
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_CmdCallback_NotImplemented
 * Remarks:  DD-ID: {22E4D614-A813-4d34-A04C-982A7B2E58A9}
 * ===========================================================================*/
void UssSnrCmd_CmdCallback_NotImplemented(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData)
{
    (void) uErrorCode; (void) puRcvData; (void) uRcvSize; (void) uUserData; (void) uCmd; 

    /* Does nothing. */
}

/*===========================================================================
 * \brief Get diagnostics flags for all sensors.
 *
 * \param none
 * \param none
 * \return US_S_Sensor_DiagnosticFlags_t pointer.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_psGetSnrDiagFlags
 * Remarks:  DD-ID: {D4067DF4-5E5D-449b-86BF-B5A2675C0F4B}
 * Req.-ID: 13396045
 * ===========================================================================*/
US_S_Sensor_DiagnosticFlags_t * UssSnrCmd_psGetSnrDiagFlags(void)
{
    return &sSnrDiagFlags;
}

/*===========================================================================
 * \brief Get temperature for all sensors.
 *
 * \param none
 * \param none
 * \return US_S_Sensor_Temperature_t pointer.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_psGetSnrTemperatures
 * Remarks:  DD-ID: {F9E2E36F-90F9-42cf-B4C0-CAA61B069256}
 * Req.-ID: 18517486
 * ===========================================================================*/
US_S_Sensor_Temperature_t * UssSnrCmd_psGetSnrTemperatures(void)
{
    return &sSnrTemperature;
}
/*===========================================================================
 * \brief Get sensor burst command error code.
 *
 * \param none
 * \param none
 * \return uint16_t Error code.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_uGetuSnrMeasErrCode
 * Remarks:  DD-ID: {BD86D121-AB0F-40b5-9AFE-5556D75D2404}
 * Req.-ID: 13396047
 * ===========================================================================*/
uint32_t UssSnrCmd_uGetuSnrMeasErrCode(void)
{
    return uSnrMeasErrCode;
}

/*===========================================================================
 * \brief Get sensor measurement receive time.
 * \param none
 * \param none
 * \return uint32_t measurement receive time.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_uGetuSnrMeasRcvTime
 * Remarks:  DD-ID: {9D66326B-8ED4-4743-921D-22508CC171C3}
 * Req.-ID: 13420748
 * Req.-ID: 13395870
 * Req.-ID: 13395873
 * Req.-ID: 13395888
 * Req.-ID: 13511361
 * ===========================================================================*/
uint32_t UssSnrCmd_uGetuSnrMeasRcvTime(void)
{
    return uSnrMeasRcvTime;
}

/*===========================================================================
 * \brief Start timer to profile sensor measurement time.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssSnrCmd_StartSnrMeasTimer
 * Remarks:  DD-ID: {5A3F07A7-CB9C-47a8-8E1F-A825D9F93D62}
 * Req.-ID: 13396080
 * ===========================================================================*/
void UssSnrCmd_StartSnrMeasTimer(void)
{
 	uSnrMeasStartTime = US_GetTimeStampTimeMs();
}
