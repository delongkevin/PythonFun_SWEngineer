/*
 * US_OutputBuffer.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */
#include"US_PlatformCfg_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_SysMgr_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_ObjDet_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SnrCmd_Global.h"
#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS))
#include "US_Hsd_Global.h"
#endif




#include "USS_Library_Header.h"
#include "US_Stub.h"

typedef enum US_E_MidDistIdx_e 
{
    US_MIDDIST_NA_1 = ZERO,
    US_MIDDIST_FSOR,  
    US_MIDDIST_FOIR,  
    US_MIDDIST_FII,   
    US_MIDDIST_FIOL,  
    US_MIDDIST_FOSL,  

    US_MIDDIST_RSOR,  
    US_MIDDIST_ROIR,  
    US_MIDDIST_RII,   
    US_MIDDIST_RIOL,  
    US_MIDDIST_ROSL,  
    US_MIDDIST_NA_2, 
    US_MIDDIST_NA_3,  
    US_MIDDIST_ABR,   
    US_MIDDIST_ABL  
} US_E_MidDistIdx_t;

UssMgr_s_OutputSignals_t UssCom_sOutputBufferCopy = {0}, UssCom_sOutputBuffer = {0};
uint8_t UssCom_DataSequenceNumber = 0u;
uint8_t UssCom_PrevDataSequenceNumber = 0xFFu;
static bool_t UssCom_bIsNewDataAvailable = ME_FALSE; /* True if any new data was pushed into comm output */
static uint8_t UssCom_uNewDataCounter = ZERO; /* Number of new data groups pushed, reset on clear */
#ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
UssDBG_ExtraData_t UssDBG_Buffer = {0};
US_S_RingTime_t    UssDBGRing_Buffer[US_D_MAX_NUM_SENSORS]={0};
#endif

static void RecordSnrDataCollection(const US_S_SensorMeasRecs_t *psCurMeasRec, uint8 DataSeqNumber);
static uint32_t CalculateSnrDataChecksum(uint8* lpsCurMeasRec, uint16 length);
static void Update_LogSnrTemperature(void);
static void UssCom_UpdateSnrMeasData(void);
extern signed short US_SnrDrvCom_GetDSI3ErrCnt(void);
static void UssCom_F_SetNewDataFlag(void);
static US_S_SensorMeasRecsForLogging_t sMeasRecForLogging;
uint32_t uPrevSnrLogTimestamp;

/* ===========================================================================
 * Name: 	 aUSSCom_F_OutputDataBuffer_v
 * Remarks:  DD-ID: {A30EF255-CEDD-4b7a-9080-A65C5983B180}
 * Req.-ID: 14959893
 * Req.-ID: 16134127
 * ===========================================================================*/
void USSCom_F_OutputDataBuffer_v(void)
{
#ifdef US_D_DATA_SHARE_CALLBACKS_ENABLE
	US_ComShareOutputBuff((void*)&UssCom_sOutputBufferCopy);	
#endif
}

/* ===========================================================================
 * Name:	 RecordSnrDataCollection
 * Remarks:  DD-ID: {8587EEDA-7E0E-49ae-AC49-30F122D5061C}
 * Traceability to source Code: Req.-ID: 14996093
 * Req.-ID:14996211
 * ===========================================================================*/
#if(USS_COM_DATA_SHARE_ENBL_DATACOLLECTION == US_STD_ON)
static void RecordSnrDataCollection(const US_S_SensorMeasRecs_t *psCurMeasRec, uint8 DataSeqNumber)
{

	uint32_t  lSnrDataChecksum;
	uint32_t lSnrExtDataChecksum = ZERO;
    uint8_t uSnrIdx;
    uint8_t uCurEchoIdx;
    uint8_t uNumEchoes;
	uint8_t *pSrc;
    /*Copy diag Data*/
    US_S_Sensor_DiagnosticFlags_t *  l_SensorDiagnosticFlagsptr = UssSnrCmd_psGetSnrDiagFlags(); /*Pointing to the received Diag Flags from the sensor*/
    uint8_t *lSnrDiagPtr_pu8 = (uint8_t *) l_SensorDiagnosticFlagsptr;
#if US_D_DATACOLLECTION_PROTOCOL_VER >= ONE
	uint8_t  *pNoiseLogPtr = (uint8_t*)&UssCom_sOutputBuffer.USSDataCollectionData.Log_PackedNoiseMeasData[ONE];

    /*Noise Data*/
    UssCom_sOutputBuffer.USSDataCollectionData.Log_PackedNoiseMeasData[0] = DataSeqNumber;
#endif

	// Common measurement data
    sMeasRecForLogging.uTimeStamp        = psCurMeasRec->uTimeStamp;
    sMeasRecForLogging.uResponseReceived = psCurMeasRec->uResponseReceived;
    sMeasRecForLogging.uSendingSensors   = psCurMeasRec->uSendingSensors;
    // Each sensor measurement data
    for (uSnrIdx = 0; uSnrIdx < TWELVE; uSnrIdx++) // Hard-coded 32 sensors max.
    {
        const US_S_SensorRec_t  *psSensorRec = &psCurMeasRec->sSensorRec[uSnrIdx];
        US_S_SensorRecForLogging_t * psSnrRecForLogging = &sMeasRecForLogging.sSensorRec[uSnrIdx];

        // Copy sensor data
        psSnrRecForLogging->eEchoTypeRequested = psSensorRec->eEchoTypeRequested;
        psSnrRecForLogging->uDiagStatus        = psSensorRec->uDiagStatus;
        psSnrRecForLogging->uFirstEchoIdx      = psSensorRec->uFirstEchoIdx;

#if US_D_DATACOLLECTION_PROTOCOL_VER >= ONE
		UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_07[49+ uSnrIdx] = psSensorRec->uMeasStatBits;
        lSnrExtDataChecksum += psSensorRec->uMeasStatBits;
#endif


       (void) memcpy(&psSnrRecForLogging->sRingTime, &psSensorRec->sRingTime, sizeof(US_S_RingTime_t));

        /*
         * The logging buffer only has space for three echoes max.
         * Just in case US_D_APP_MAX_ECHOES_BUFF were ever raised above three,
         * this code will protect it.
         */
        uNumEchoes = (psSensorRec->uNumEchoes <= THREE) ? psSensorRec->uNumEchoes : THREE;

        psSnrRecForLogging->uNumEchoes = uNumEchoes;

        (void)memset(&psSnrRecForLogging->sEcho, 0, sizeof(psSnrRecForLogging->sEcho));

        for (uCurEchoIdx = 0u; uCurEchoIdx < uNumEchoes; uCurEchoIdx++)
        {
            (void)memcpy(&psSnrRecForLogging->sEcho[uCurEchoIdx], &psSensorRec->sEcho[uCurEchoIdx], sizeof(US_S_Echo_t));
        }
#if US_D_DATACOLLECTION_PROTOCOL_VER >= ONE
        /*Copy the noise data for all sensors starting from location 1 in the array */
        (void)memcpy((uint8_t*)pNoiseLogPtr, (uint8_t*)&psSensorRec->sNoiseMeas, sizeof(US_S_NoiseMeas_t)-1u);   /* PRQA S 0311*/
        pNoiseLogPtr += (sizeof(US_S_NoiseMeas_t)-1u);
#endif
    } 

    pSrc  = (uint8_t *)&sMeasRecForLogging;
	/*Sequnce number is added for each record, first byte is filled with Sequence number*/
	/*one data byte in each message is adjusted in the 'Log_SnrMeasData_07'*/
    /*KPK-QAC : Type Casted the destination memory with uint8* */
	lSnrDataChecksum = CalculateSnrDataChecksum((uint8_t *) &sMeasRecForLogging, 420);
	UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_01[0] = DataSeqNumber;
	(void)memcpy(&UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_01[1],pSrc,63);
	pSrc += 63u;
	UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_02[0] = DataSeqNumber;
	(void)memcpy(&UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_02[1],pSrc,63);
	pSrc += 63u;
	UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_03[0] = DataSeqNumber;
	(void)memcpy(&UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_03[1],pSrc,63);
	pSrc += 63u;
	UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_04[0] = DataSeqNumber;
	(void)memcpy(&UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_04[1],pSrc,63);
	pSrc += 63u;
	UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_05[0] = DataSeqNumber;
	(void)memcpy(&UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_05[1],pSrc,63);
	pSrc += 63u;
	UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_06[0] = DataSeqNumber;
	(void)memcpy(&UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_06[1],pSrc,63);
	pSrc += 63u;
	UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_07[0] = DataSeqNumber;
	(void)memcpy(&UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_07[1],pSrc,42);

#if US_D_DATACOLLECTION_PROTOCOL_VER >= ONE
    /*Additional fields in 'Log_SnrMeasData_07' data :  The checksum is not part of array for storing the data in the Output buffer, checksum byte positions are not considered in array 'Log_SnrMeasData_07',
    since in DBC, Checksum is having a different signal - jpp changing */
    UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_07[47] = (uint8_t) US_D_DATACOLLECTION_PROTOCOL_VER;                       /*Extension to current Data collection Protocol: stored the Protocol version*/
    lSnrExtDataChecksum += (uint8_t) US_D_DATACOLLECTION_PROTOCOL_VER;
    UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_07[48] = (uint8_t) UssMgr_uGetCurParkingMode();                            /*Extension to current Data collection Protocol: Parking Mode*/
    lSnrExtDataChecksum += (uint8_t) UssMgr_uGetCurParkingMode();

    lSnrDataChecksum += lSnrExtDataChecksum;
#endif

    (void)memcpy((uint8_t*)&UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrMeasData_07[43], (uint8_t*) &lSnrDataChecksum, sizeof(uint32_t));

#if (US_D_DATACOLLECTION_PROTOCOL_VER >= ONE) && (US_D_MAX_NUM_SENSORS == TWELVE)
    /*
     * DIAG DATA
     */
    /*Sequence number for Diag Data*/
    UssCom_sOutputBuffer.USSDataCollectionData.Log_PackedDiagFlagData1_v[0] = DataSeqNumber;
    UssCom_sOutputBuffer.USSDataCollectionData.Log_PackedDiagFlagData2_v[0] = DataSeqNumber;

    (void)memcpy((uint8_t *)&UssCom_sOutputBuffer.USSDataCollectionData.Log_PackedDiagFlagData1_v[ONE],(uint8_t *) lSnrDiagPtr_pu8, 63);
    lSnrDiagPtr_pu8 += 63u;
   (void) memcpy((uint8_t *)&UssCom_sOutputBuffer.USSDataCollectionData.Log_PackedDiagFlagData2_v[ONE],(uint8_t *) lSnrDiagPtr_pu8, 41);
    /* Note:  Measurement status bits transcribed in loop above */
#endif
    
    UssCom_F_SetNewDataFlag();
}
#endif
/* ===========================================================================
 * Name:	 UssCom_UpdateSnrMeasData
 * Remarks:  DD-ID: {6A64351B-1C87-419a-9B6F-48754166152E}
 * Req.-ID: 14996093
 * Req.-ID:14996211
 * ===========================================================================*/
static void UssCom_UpdateSnrMeasData(void)
{
#ifndef PLAYBACK_SW_ENABLE
#if(USS_COM_DATA_SHARE_ENBL_DATACOLLECTION == US_STD_ON)
    const US_S_SensorMeasRecs_t * psCurMeasRec;

    psCurMeasRec = UssMgr_psGetCurSensorMeasRec();

    if(uPrevSnrLogTimestamp != UssMgr_psGetCurSensorMeasRec()->uTimeStamp)
    {
        uPrevSnrLogTimestamp = UssMgr_psGetCurSensorMeasRec()->uTimeStamp;
        RecordSnrDataCollection(psCurMeasRec, UssCom_DataSequenceNumber);

        UssCom_DataSequenceNumber++; /*Increment the sequence number for next record*/
    }
#endif
#endif
}

/* ===========================================================================
 * Name:	 Update_LogSnrTemperature
 * Remarks:  DD-ID: {E6A81BD6-F667-4ee0-B71A-59C52F028F53}
 * Req.-ID: 13424090
 * ===========================================================================*/
static void Update_LogSnrTemperature(void)
{
    US_S_Sensor_Temperature_t * psTemperatures = UssSnrCmd_psGetSnrTemperatures();
    (void)memcpy((uint8_t *)UssCom_sOutputBuffer.USSDataCollectionData.Log_SnrTemperature,(uint8_t*) psTemperatures->iSnrTemperature,((uint32_t)US_D_MAX_NUM_SENSORS*2u));

    UssCom_F_SetNewDataFlag();
}

/* ===========================================================================
 * Name:	 CalculateSnrDataChecksum
 * Remarks:  DD-ID: {914913CF-CB87-46a0-96EF-6E3CEEB856B4}
 * Req.-ID: 14996093
 * Req.-ID:14996211
 * ===========================================================================*/

static uint32_t CalculateSnrDataChecksum(uint8* lpsCurMeasRec, uint16 length)
{
	uint16 index;
	uint32 lchecksum = 0;
	for(index=0;index<length;index++)
	{
		lchecksum += lpsCurMeasRec[index];
	}
	return lchecksum;
}


/***********************************************************************************************************
 * Global Functions to Update the 'UssCom_sOutputBuffer' from various Application modules
 * *********************************************************************************************************/

/*===========================================================================
 * brief Populate distance point map in comm output buffer.
 *
 * param none
 * param none
 * return none
 * remarks
 */
/* ===========================================================================
 * Name:	 UssCom_F_PopulatePointMap
 * Remarks:  DD-ID: {02AEAC67-A83A-44a4-8DF4-00DC7FCA0339}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssCom_F_PopulatePointMap(US_S_PointMap_t *psPointMap)
{
	(void)memcpy(&UssCom_sOutputBuffer.sPointMapOutputBuff, psPointMap, sizeof(US_S_PointMap_t));  
}

#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE
/*===========================================================================
 * brief Populate distance point diag info in comm output buffer.
 *
 * param none
 * param none
 * return none
 * remarks
 */
/* ===========================================================================
 * Name:	 UssCom_F_PopulateDebugPntInfo
 * Remarks:  DD-ID: {FC81E5CF-EA38-4209-93C4-E0AAE82B4E84}
 * ===========================================================================*/
void UssCom_F_PopulateDebugPntInfo(US_S_PntDebugInfo_t *psDebugPntInfo)
{
	/*KPK-QAC Fix : Type casted to match the pointer type for Data copy*/
    (void)memcpy((uint8_t*)&UssCom_sOutputBuffer.sPntDebugData[ZERO].u.uPntDebugData, (uint8_t*)&psDebugPntInfo[ZERO], sizeof(US_S_PntDebugInfo_t) * FOUR);
   (void) memcpy((uint8_t*)&UssCom_sOutputBuffer.sPntDebugData[ONE].u.uPntDebugData, (uint8_t*)&psDebugPntInfo[FOUR], sizeof(US_S_PntDebugInfo_t) * FOUR);
   (void) memcpy((uint8_t*)&UssCom_sOutputBuffer.sPntDebugData[TWO].u.uPntDebugData, (uint8_t*)&psDebugPntInfo[EIGHT],sizeof(US_S_PntDebugInfo_t) * FOUR);
    (void)memcpy((uint8_t*)&UssCom_sOutputBuffer.sPntDebugData[THREE].u.uPntDebugData, (uint8_t*)&psDebugPntInfo[TWELVE],sizeof(US_S_PntDebugInfo_t) * FOUR);

    UssCom_F_SetNewDataFlag();
}
#endif
/*===========================================================================
 * brief Populate Fisker firing sequence in comm output buffer.
 *
 * param none
 * param none
 * return none
 * remarks
 */
/* ===========================================================================
 * Name:	 UssCom_F_PopulateFiringSequence
 * Remarks:  DD-ID: {86651F03-0F36-4a05-B5AD-2727A910702E}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssCom_F_PopulateFiringSequence(void)
{
    UssCom_sOutputBuffer.sFiringSequence.Sig_Current_Firing_Sequence = (uint8_t) UssMgr_uGetCurParkingMode();
    UssCom_F_SetNewDataFlag();
}

/*===========================================================================
 * brief Populate point distances in comm output buffer.
 *
 * param none
 * param none
 * return none
 * remarks
 */
/* ===========================================================================
 * Name:	 UssCom_F_PopulatePointDist
 * Remarks:  DD-ID: {F78C1894-4EE1-4b01-BDCA-E7830CB5DFF4}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssCom_F_PopulatePointDist(uint32_t uTimestamp, uint16_t *uPntMinDist, uint16_t *uPntMidDist)
{
	/*KPK-QAC Fix : Match sorce & destination data type*/
    (void)memcpy(&UssCom_sOutputBuffer.sPointDistOutputBuff.minDist[0], uPntMinDist, sizeof(uint16_t) * US_D_MAX_NUM_SENSORS);

    /* TODO jpp - What order are these supposed to be in the API?  We want to use THAT order for the array on left */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[ZERO]    = uPntMidDist[US_MIDDIST_ROIR];   /*ROIR */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[ONE]     = uPntMidDist[US_MIDDIST_RSOR];   /*RSOR */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[TWO]     = uPntMidDist[US_MIDDIST_FOSL];   /*FOSL */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[THREE]   = uPntMidDist[US_MIDDIST_FIOL];   /*FIOL */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[FOUR]    = uPntMidDist[US_MIDDIST_FII];    /*FII */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[FIVE]    = uPntMidDist[US_MIDDIST_FOIR];   /*FOIR */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[SIX]     = uPntMidDist[US_MIDDIST_FSOR];   /*FSOR */
#if (US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN)
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[SEVEN]   = uPntMidDist[US_MIDDIST_ABR];    /*ABR */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[EIGHT]   = uPntMidDist[US_MIDDIST_ABL];    /*ABL */
#else
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[SEVEN]   = 511u;                           /*ABR */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[EIGHT]   = 511u;                           /*ABL */
#endif
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[NINE]    = uPntMidDist[US_MIDDIST_ROSL];   /*ROSL */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[TEN]     = uPntMidDist[US_MIDDIST_RIOL];   /*RIOL */
    UssCom_sOutputBuffer.sPointDistOutputBuff.midDist[ELEVEN]  = uPntMidDist[US_MIDDIST_RII];    /*RII */

    UssCom_sOutputBuffer.sPointDistOutputBuff.timestamp = uTimestamp;

    UssCom_F_SetNewDataFlag();
}

/*===========================================================================
 * brief Populate firing sensors in comm output buffer.
 *
 * param none
 * param none
 * return none
 * remarks
 */
/* ===========================================================================
 * Name:	 UssCom_F_PopulateFiringSensors
 * Remarks:  DD-ID: {E474839D-F72E-4c07-863B-76CE885C4F32}
 * Traceability to source Code: Req.-ID: 14996090
 * Req.-ID: 14996093
 * Req.-ID:14996211
 * ===========================================================================*/
void UssCom_F_PopulateFiringSensors(void)
{
    const US_S_SensorMeasRecs_t * psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    UssCom_sOutputBuffer.sFiringSensors.firingSensors = (uint16_t)psSnrMeasRec->uSendingSensors;
    UssCom_sOutputBuffer.sFiringSensors.timestamp = psSnrMeasRec->uTimeStamp;
    UssCom_F_SetNewDataFlag();
}

/*===========================================================================
 * brief Populate firing mode info from Controller in comm output buffer.
 *
 * param none
 * param none
 * return none
 * remarks
 */
/* ===========================================================================
 * Name:	 UssCom_F_PopulateFiringModeInfo
 * Remarks:  DD-ID: {46B50955-4650-4b5c-A6E4-25AAFA5A01AE}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssCom_F_PopulateFiringModeInfo(uint32_t timestamp, uint8_t sensorFiringMode)
{
    UssCom_sOutputBuffer.sFiringMode.sensorFiringMode = sensorFiringMode;
    UssCom_sOutputBuffer.sFiringMode.timestamp = timestamp;
}

#if(USS_FEATURE_ZONE_INFO == US_STD_ON)
/*===========================================================================
 * brief Populate zone info from Object Detection in comm output buffer.
 *
 * param none
 * param none
 * return none
 * remarks
 */
/* ===========================================================================
 * Name:	 UssCom_F_PopulateZoneInfo
 * Remarks:  DD-ID: {70AE0AC0-FC89-46c4-8C3E-BD06824EB9D7}
 * Req.-ID: 13473275
 * ===========================================================================*/
void UssCom_F_PopulateZoneInfo(uint32_t uTimestamp, uint8_t *paZoneInfo)
{
    uint8_t uSecIdx;
    for (uSecIdx = ZERO; uSecIdx < US_D_MAX_SECTORS_TOTAL; uSecIdx++)     // Scan all sensor positions
    {
        UssCom_sOutputBuffer.sZoneInfo.zoneInfo[uSecIdx] = (US_E_Zoneinfo_list_t)paZoneInfo[uSecIdx];
    }
    UssCom_sOutputBuffer.sZoneInfo.timestamp = uTimestamp;

    UssCom_F_SetNewDataFlag();
}
#endif
/*===========================================================================
 * brief Populate Blockage Bit Diagnostics info in comm output buffer.
 *
 * param none
 * param none
 * return none
 * remarks
 */
/* ===========================================================================
 * Name:	 UssCom_F_PopulateBlockageBit
 * Remarks:  DD-ID: {1CCADDEE-E329-4e52-B87A-D47A9FEA3699}
 *  Req.-ID: 13424090
 * ===========================================================================*/
void UssCom_F_PopulateBlockageBit(uint32_t uTimestamp)
{
    UssCom_sOutputBuffer.sBlockageFlags.blockageFlagBits =(uint16_t) US_Diagnostic_GetSnrMapFaultFlag(SNR_DIAG_FLG_SNR_BLOCKAGE);
    UssCom_sOutputBuffer.sBlockageFlags.timestamp = uTimestamp;

    UssCom_F_SetNewDataFlag();
}

/*===========================================================================
 * brief Populate Diagnostics info from Manager in comm output buffer.
 *
 * param none
 * param none
 * return none
 * remarks
 */
/* ===========================================================================
 * Name:	 UssCom_F_PopulateHardwareDiagnosticsInfo
 * Remarks:  DD-ID: {74F36CBD-67C8-4934-878D-4D01A27E29BE}
 * Req.-ID: 13477351
 * Req.-ID: 13477349
 * Req.-ID: 13477478
 * ===========================================================================*/
void UssCom_F_PopulateHardwareDiagnosticsInfo(uint32_t uTimestamp,
                                              uint32_t uHardwareFaultBitMap,
                                              uint32_t uCommFaultInfoBitMap,
                                              uint32_t uCommUnknownBitMap,
                                              uint32_t uOverTempFaultBitMap)
{
    UssCom_sOutputBuffer.sDiagnostics.hardwareFault = (uint16_t)uHardwareFaultBitMap;
    UssCom_sOutputBuffer.sDiagnostics.commFault     = (uint16_t)uCommFaultInfoBitMap;
    UssCom_sOutputBuffer.sDiagnostics.overTempFault = (uint16_t)uOverTempFaultBitMap;
    UssCom_sOutputBuffer.sDiagnostics.commUnknown   = (uint16_t) uCommUnknownBitMap;
    UssCom_sOutputBuffer.sDiagnostics.timestamp     = uTimestamp;
}
/* ===========================================================================
 * Name:	 UssCom_F_PopulateSystemStatusInfo
 * Remarks:  DD-ID: {B89F29CF-8E64-436c-9042-AAD9FD411741}
 * Req.-ID:14959893
 * Req.-ID:16134127
 * ===========================================================================*/

void UssCom_F_PopulateSystemStatusInfo(uint32_t uTimestamp)
{
    uint16_t uGrpIdx;
    
    for(uGrpIdx = 0; uGrpIdx < (uint16_t)USSCOM_BUMPLOC_MAX; uGrpIdx++)
    {
        UssCom_sOutputBuffer.sSysStatus.bumperStatus[uGrpIdx] = (UssCom_E_BumperState_t)UssMgr_eGetGrpState((uint8_t)uGrpIdx);
    }
    
    UssCom_sOutputBuffer.sSysStatus.timestamp = uTimestamp;
    UssCom_sOutputBuffer.sSysStatus.systemStatus = (UssCom_E_SystemState_t)UssMgr_eGetSysState();
    UssCom_sOutputBuffer.sSysStatus.systemMode = 0xAA;
}

#if(QAC_WARNING_FIX == ME_FALSE)
#define US_D_DEBUG_TEST_DATA (0u)
#endif



/*===========================================================================
 * brief Populate data for test group.
 *
 * param none
 * param none
 * return none
 * remarks
 * ==========================================================================*/
 

/* ===========================================================================
 * Name:	 UssCom_uCalcDirect
 * Remarks:  DD-ID: {B404D0B6-D6C2-429d-8E5A-5C78E274C744}
 * Req.-ID:13477648
 * ===========================================================================*/

static US_S_SnrCalcs_t *pUS_ComsSnrCalcs;
static void UssCom_uCalcDirect(uint16_t * uOutSignal_Dir0, uint16_t * uOutSignal_Dir1, uint8_t uDirSnrIdx)
{
    US_S_SnrCalcRec_t * psDirCalcRec = &pUS_ComsSnrCalcs->sSnrCalcRec[uDirSnrIdx];
#if (US_D_CUR_PLATFORM != US_D_PLATFORM_RIVIAN)     // feature team needs this function
    *uOutSignal_Dir0 = psDirCalcRec->sEchoCalc[ZERO].uTotalDist_cm;
    *uOutSignal_Dir1 = psDirCalcRec->sEchoCalc[ONE].uTotalDist_cm;
#else
    if (psDirCalcRec->eEchoClass == US_E_DIRECT)
    {
        *uOutSignal_Dir0 = psDirCalcRec->sEchoCalc[ZERO].uDirectDist_cm;
        *uOutSignal_Dir1 = psDirCalcRec->sEchoCalc[ONE].uDirectDist_cm;
    }
#endif
#ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
    UssDBG_Buffer.u1stEchoTotalDist[uDirSnrIdx] = *uOutSignal_Dir0;
    UssDBG_Buffer.u2ndEchoTotalDist[uDirSnrIdx] = *uOutSignal_Dir1;
    /* ok to always take directs, they will be 0 if not fired */
    UssDBG_Buffer.u1stEchoDirDist[uDirSnrIdx] = psDirCalcRec->sEchoCalc[ZERO].uDirectDist_cm;
    UssDBG_Buffer.u2ndEchoDirDist[uDirSnrIdx] = psDirCalcRec->sEchoCalc[ONE].uDirectDist_cm;
#endif
}

/* ===========================================================================
 * Name:	 UssCom_uCalcIndirect
 * Remarks:  DD-ID: {02E6E250-6A85-4a49-9104-F659AC8D6B9F}
 * Req.-ID:13477648
 * ===========================================================================*/

static void UssCom_uCalcIndirect(uint16_t * uOutSignal, uint8_t uDirSnrIdx, uint8_t uIndirSnrIdx)
{
    US_S_SnrCalcRec_t * psDirCalcRec = &pUS_ComsSnrCalcs->sSnrCalcRec[uDirSnrIdx];
    US_S_SnrCalcRec_t * psIndirCalcRec = &pUS_ComsSnrCalcs->sSnrCalcRec[uIndirSnrIdx];

    if (psDirCalcRec->eEchoClass == US_E_DIRECT)
    {
        if (psIndirCalcRec->sEchoCalc[ZERO].uTotalDist_cm >= psDirCalcRec->sEchoCalc[ZERO].uDirectDist_cm)
        {
            *uOutSignal = psIndirCalcRec->sEchoCalc[ZERO].uTotalDist_cm;   // -
                            // psDirCalcRec->sEchoCalc[ZERO].uDirectDist_cm;
        }
        else
        {
            *uOutSignal = ZERO;
        }
    }
}

/* ===========================================================================
 * Name:	 UssCom_F_PopulateTestData
 * Remarks:  DD-ID: {7FB91A8A-3FBE-4ad8-B69D-AEB6F2BFEA22}
 * Req.-ID:13477648
 * ===========================================================================*/

void UssCom_F_PopulateTestData(void)
{
    uint8_t uSnrIdx;
    const US_S_SensorMeasRecs_t * psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    UssCom_S_TestDataCluster_t * psTestData = &UssCom_sOutputBuffer.sTestData;
    US_S_SnrCalcRec_t * psDirCalcRec;
    const US_S_SensorRec_t *psSensorRec;
    
    pUS_ComsSnrCalcs = UssMgr_psGetCurSnrCalcsRec();

    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Front_Direct_v.Sig_SnrDat_FSR_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Front_Direct_2_v.Sig_SnrDat_FSR_Dir2_cm, US_D_SENSOR_FSR);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Front_Direct_v.Sig_SnrDat_FOR_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Front_Direct_2_v.Sig_SnrDat_FOR_Dir2_cm, US_D_SENSOR_FOR);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Front_Direct_v.Sig_SnrDat_FIR_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Front_Direct_2_v.Sig_SnrDat_FIR_Dir2_cm, US_D_SENSOR_FIR);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Front_Direct_v.Sig_SnrDat_FIL_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Front_Direct_2_v.Sig_SnrDat_FIL_Dir2_cm, US_D_SENSOR_FIL);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Front_Direct_v.Sig_SnrDat_FOL_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Front_Direct_2_v.Sig_SnrDat_FOL_Dir2_cm, US_D_SENSOR_FOL);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Front_Direct_v.Sig_SnrDat_FSL_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Front_Direct_2_v.Sig_SnrDat_FSL_Dir2_cm, US_D_SENSOR_FSL);


    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Direct_v.Sig_SnrDat_RSR_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Rear_Direct_2_v.Sig_SnrDat_RSR_Dir2_cm, US_D_SENSOR_RSR);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Direct_v.Sig_SnrDat_ROR_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Rear_Direct_2_v.Sig_SnrDat_ROR_Dir2_cm, US_D_SENSOR_ROR);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Direct_v.Sig_SnrDat_RIR_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Rear_Direct_2_v.Sig_SnrDat_RIR_Dir2_cm, US_D_SENSOR_RIR);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Direct_v.Sig_SnrDat_RIL_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Rear_Direct_2_v.Sig_SnrDat_RIL_Dir2_cm, US_D_SENSOR_RIL);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Direct_v.Sig_SnrDat_ROL_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Rear_Direct_2_v.Sig_SnrDat_ROL_Dir2_cm, US_D_SENSOR_ROL);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Direct_v.Sig_SnrDat_RSL_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_Rear_Direct_2_v.Sig_SnrDat_RSL_Dir2_cm, US_D_SENSOR_RSL);

#if (US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN)
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_AOL_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_AOL_Dir2_cm, US_D_SENSOR_AOL);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_BOL_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_BOL_Dir2_cm, US_D_SENSOR_BOL);

    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_AOR_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_AOR_Dir2_cm, US_D_SENSOR_AOR);
    UssCom_uCalcDirect(&UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_BOR_Dir1_cm, &UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_BOR_Dir2_cm, US_D_SENSOR_BOR);
#else
    UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_AOL_Dir1_cm  = 511u;
    UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_AOL_Dir2_cm  = 511u;
    UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_BOL_Dir2_cm  = 511u;
    UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_BOL_Dir1_cm  = 511u;
    UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_AOR_Dir1_cm = 511u;
    UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_AOR_Dir2_cm = 511u;
    UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_BOR_Dir1_cm = 511u;
    UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_BOR_Dir2_cm = 511u;
#endif

	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_1_v.Sig_SnrDat_sFSR_Indir_FOR_cm, US_D_SENSOR_FSR, US_D_SENSOR_FOR);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_1_v.Sig_SnrDat_sFOR_Indir_FSR_cm, US_D_SENSOR_FOR, US_D_SENSOR_FSR);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_1_v.Sig_SnrDat_sFOR_Indir_FIR_cm, US_D_SENSOR_FOR, US_D_SENSOR_FIR);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_1_v.Sig_SnrDat_sFIR_Indir_FOR_cm, US_D_SENSOR_FIR, US_D_SENSOR_FOR);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_1_v.Sig_SnrDat_sFIR_Indir_FIL_cm, US_D_SENSOR_FIR, US_D_SENSOR_FIL);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_1_v.Sig_SnrDat_sFIL_Indir_FIR_cm, US_D_SENSOR_FIL, US_D_SENSOR_FIR);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_2_v.Sig_SnrDat_sFIL_Indir_FOL_cm, US_D_SENSOR_FIL, US_D_SENSOR_FOL);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_2_v.Sig_SnrDat_sFOL_Indir_FIL_cm, US_D_SENSOR_FOL, US_D_SENSOR_FIL);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_2_v.Sig_SnrDat_sFOL_Indir_FSL_cm, US_D_SENSOR_FOL, US_D_SENSOR_FSL);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_2_v.Sig_SnrDat_sFSL_Indir_FOL_cm, US_D_SENSOR_FSL, US_D_SENSOR_FOL);


	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_1_v.Sig_SnrDat_sRIR_Indir_RIL_cm, US_D_SENSOR_RIR, US_D_SENSOR_RIL);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_1_v.Sig_SnrDat_sRIL_Indir_RIR_cm, US_D_SENSOR_RIL, US_D_SENSOR_RIR);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_1_v.Sig_SnrDat_sRIL_Indir_ROL_cm, US_D_SENSOR_RIL, US_D_SENSOR_ROL);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_1_v.Sig_SnrDat_sROL_Indir_RIL_cm, US_D_SENSOR_ROL, US_D_SENSOR_RIL);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_1_v.Sig_SnrDat_sROL_Indir_RSL_cm, US_D_SENSOR_ROL, US_D_SENSOR_RSL);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_1_v.Sig_SnrDat_sRSL_Indir_ROL_cm, US_D_SENSOR_RSL, US_D_SENSOR_ROL);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_2_v.Sig_SnrDat_sRSR_Indir_ROR_cm, US_D_SENSOR_RSR, US_D_SENSOR_ROR);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_2_v.Sig_SnrDat_sROR_Indir_RSR_cm, US_D_SENSOR_ROR, US_D_SENSOR_RSR);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_2_v.Sig_SnrDat_sROR_Indir_RIR_cm, US_D_SENSOR_ROR, US_D_SENSOR_RIR);
	UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_2_v.Sig_SnrDat_sRIR_Indir_ROR_cm, US_D_SENSOR_RIR, US_D_SENSOR_ROR);

#if (US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN)
    UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_sAOL_Indir_BOL_cm, US_D_SENSOR_AOL, US_D_SENSOR_BOL);
    UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_sBOL_Indir_AOL_cm, US_D_SENSOR_BOL, US_D_SENSOR_AOL);

    UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_sAOR_Indir_BOR_cm, US_D_SENSOR_AOR, US_D_SENSOR_BOR);
    UssCom_uCalcIndirect(&UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_sBOR_Indir_AOR_cm, US_D_SENSOR_BOR, US_D_SENSOR_AOR);
#else
    UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_sAOL_Indir_BOL_cm = 511u;
    UssCom_sOutputBuffer.sSnsDat_LeftSidePanel_Echoes_v.Sig_SnrDat_sBOL_Indir_AOL_cm = 511u;
    UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_sAOR_Indir_BOR_cm = 511u;
    UssCom_sOutputBuffer.sSnsDat_RightSidePanel_Echoes_v.Sig_SnrDat_sBOR_Indir_AOR_cm = 511u;
#endif

	psDirCalcRec = &pUS_ComsSnrCalcs->sSnrCalcRec[US_D_SENSOR_FSL];
	UssCom_sOutputBuffer.sSnsDat_FrontPSM_Echoes_v.Sig_SnsDat_FSL_DirEcho1_cm      = psDirCalcRec->sEchoCalc[ZERO].uDirectDist_cm; // Direct 0
	UssCom_sOutputBuffer.sSnsDat_FrontPSM_Echoes_v.Sig_SnsDat_FSL_DirEcho2_cm      = psDirCalcRec->sEchoCalc[ZERO].bLargeFAPAObject; // Direct 1
	UssCom_sOutputBuffer.sSnsDat_FrontPSM_Echoes_v.Sig_SnsDat_FSL_Timestamp_us 	   = (uint16_t)(psSnrMeasRec->uTimeStamp & 0xffff);


	psDirCalcRec            								   					   = &pUS_ComsSnrCalcs->sSnrCalcRec[US_D_SENSOR_FSR];
	UssCom_sOutputBuffer.sSnsDat_FrontPSM_Echoes_v.Sig_SnsDat_FSR_DirEcho1_cm      = psDirCalcRec->sEchoCalc[ZERO].uDirectDist_cm; // Direct 0
	UssCom_sOutputBuffer.sSnsDat_FrontPSM_Echoes_v.Sig_SnsDat_FSR_DirEcho2_cm      = psDirCalcRec->sEchoCalc[ZERO].bLargeFAPAObject; 
	UssCom_sOutputBuffer.sSnsDat_FrontPSM_Echoes_v.Sig_SnsDat_FSR_Timestamp_us 	   = (uint16_t)(psSnrMeasRec->uTimeStamp & 0xffff);


	psDirCalcRec            													   = &pUS_ComsSnrCalcs->sSnrCalcRec[US_D_SENSOR_RSL];
	UssCom_sOutputBuffer.sSnsDat_RearSide_Echoes_v.Sig_SnsDat_RSL_DirEcho1_cm      = psDirCalcRec->sEchoCalc[ZERO].uDirectDist_cm; // Direct 0
	UssCom_sOutputBuffer.sSnsDat_RearSide_Echoes_v.Sig_SnsDat_RSL_DirEcho2_cm      = psDirCalcRec->sEchoCalc[ZERO].bLargeFAPAObject; 
	UssCom_sOutputBuffer.sSnsDat_RearSide_Echoes_v.Sig_SnsDat_RSL_Timestamp_us 	   = (uint16_t)(psSnrMeasRec->uTimeStamp & 0xffff);

	psDirCalcRec            								  					   = &pUS_ComsSnrCalcs->sSnrCalcRec[US_D_SENSOR_RSR];
	UssCom_sOutputBuffer.sSnsDat_RearSide_Echoes_v.Sig_SnsDat_RSR_DirEcho1_cm      = psDirCalcRec->sEchoCalc[ZERO].uDirectDist_cm; // Direct 0
	UssCom_sOutputBuffer.sSnsDat_RearSide_Echoes_v.Sig_SnsDat_RSR_DirEcho2_cm      = psDirCalcRec->sEchoCalc[ZERO].bLargeFAPAObject; 
	UssCom_sOutputBuffer.sSnsDat_RearSide_Echoes_v.Sig_SnsDat_RSR_Timestamp_us	   = (uint16_t)(psSnrMeasRec->uTimeStamp & 0xffff);

	/* Front */
	UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_FSR_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_FSR].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_FOR_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_FOR].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_FIR_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_FIR].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_FIL_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_FIL].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_FOL_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_FOL].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_FSL_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_FSL].uFirstEchoIdx;

    /* Rear */
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_RSR_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_RSR].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_ROR_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_ROR].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_RIR_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_RIR].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_RIL_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_RIL].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_ROL_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_ROL].uFirstEchoIdx;
    UssCom_sOutputBuffer.sSnsDat_EchoIndex_v.Sig_SnrDat_RSL_EchoIndex = psSnrMeasRec->sSensorRec[US_D_SENSOR_RSL].uFirstEchoIdx;

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
        UssDBGRing_Buffer[uSnrIdx] = psSensorRec->sRingTime;
    }
  

#ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
    /*capture send/recv*/
    UssDBG_Buffer.uSendingSensors = psSnrMeasRec->uSendingSensors;
    UssDBG_Buffer.uReceivedSensors = psSnrMeasRec->uResponseReceived;
#endif
    /* Populate Multiplexed CAN Data */
    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
        psDirCalcRec = &pUS_ComsSnrCalcs->sSnrCalcRec[uSnrIdx];

        if(psDirCalcRec->sEchoCalc[0u].uRecEchoIndex < US_D_APP_MAX_ECHOES_BUFF)
        {
            /*indirects str too*/
            psTestData->sDataMux[uSnrIdx].uEchoHeight = psSensorRec->sEcho[psDirCalcRec->sEchoCalc[0u].uRecEchoIndex].uEchoHeight;
#ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
            /*height classification*/
    #ifndef US_D_OD_HEIGHT_FILTER_SMOOTING
            
            UssDBG_Buffer.u1stEchoLarge[uSnrIdx] = psSensorRec->sEcho[psDirCalcRec->sEchoCalc[0u].uRecEchoIndex].uConf;
    #else
            UssDBG_Buffer.u1stEchoLarge[uSnrIdx] = psDirCalcRec->sEchoCalc[0u].uLargeObject;
    #endif
        }
        else
        {
            psTestData->sDataMux[uSnrIdx].uEchoHeight = ZERO;
            UssDBG_Buffer.u1stEchoLarge[uSnrIdx] = ZERO;
        }

        if(psDirCalcRec->sEchoCalc[1u].uRecEchoIndex < US_D_APP_MAX_ECHOES_BUFF)
        {
            UssDBG_Buffer.u2ndEchoStr[uSnrIdx] = psSensorRec->sEcho[psDirCalcRec->sEchoCalc[1u].uRecEchoIndex].uEchoHeight;
    #ifndef US_D_OD_HEIGHT_FILTER_SMOOTING            
            UssDBG_Buffer.u2ndEchoLarge[uSnrIdx] = psSensorRec->sEcho[psDirCalcRec->sEchoCalc[1u].uRecEchoIndex].uConf;
    #else
            UssDBG_Buffer.u2ndEchoLarge[uSnrIdx] = psDirCalcRec->sEchoCalc[1u].uLargeObject;
    #endif
        }
        else
        {
            UssDBG_Buffer.u2ndEchoStr[uSnrIdx] = ZERO;
            UssDBG_Buffer.u2ndEchoLarge[uSnrIdx] = ZERO;
        }
#endif /* US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X */
        
        if (psDirCalcRec->eEchoClass == US_E_DIRECT) // This is a sending sensor
        {
            psTestData->sDataMux[uSnrIdx].uDirEcho    = psDirCalcRec->sEchoCalc[ZERO].uDirectDist_cm;  // Direct 1
#ifndef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
            psTestData->sDataMux[uSnrIdx].uEchoHeight = psSensorRec->sEcho[0u].uEchoHeight;
#endif
            psTestData->sDataMux[uSnrIdx].uRingTime   = psSensorRec->sRingTime.uRingTime;
            psTestData->sDataMux[uSnrIdx].uDrvFreq    = psSensorRec->sRingTime.uDrvFreq / 572u;
            psTestData->sDataMux[uSnrIdx].uRingFreq   = psSensorRec->sRingTime.uRingFreq / 572u;

           
        }
    }

 
    UssCom_F_SetNewDataFlag();
}

/* ===========================================================================
 * Name:	 UssCom_PopulateLogData
 * Remarks:  DD-ID: {6DA0A01B-D71E-41ca-B865-EA0915E35BB3}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssCom_PopulateLogData(void)
{
    UssCom_UpdateSnrMeasData();  // Need to add noise meas to data, event based
    Update_LogSnrTemperature();  // Effectively periodic.
    // Need to add diagnostics messages logging if they want to test disconnects/faults.
}

/* ===========================================================================
 * Name:	 UssCom_F_PopulateDebugMsg
 * Remarks:  DD-ID: {C3F0062C-6437-4304-B55E-0A4A2AB87709}
 * ===========================================================================*/


void UssCom_F_PopulateDebugMsg(void)
{
#if(USS_COM_DATA_SHARE_ENBL_DEBUG_SIGNAL == US_STD_ON)
        UssCom_sOutputBuffer.sDebugMsg_v.Sig_Debug_Signal[0] = (signed short)UssCom_F_GetAmbientTemp();
        UssCom_sOutputBuffer.sDebugMsg_v.Sig_Debug_Signal[1] = (signed short)UssCtrl_Get_Temperature_Index();
        UssCom_sOutputBuffer.sDebugMsg_v.Sig_Debug_Signal[2] = (signed short)UssCom_F_GetParkingMode();
		UssCom_sOutputBuffer.sDebugMsg_v.Sig_Debug_Signal[3] = US_SnrDrvCom_GetDSI3ErrCnt();
#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS))

        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[0] = UssHsd_F_psGet_Pwr_Vtg_mV((uint8_t)Uss_Hsd_Channel_PWR_A);
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[1] = UssHsd_F_psGet_Pwr_Vtg_mV((uint8_t)Uss_Hsd_Channel_PWR_B);
       
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[2] = UssHsd_F_psGet_Pwr_Ct_mA((uint8_t)Uss_Hsd_Channel_PWR_A);         
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[3] = UssHsd_F_psGet_Pwr_Ct_mA((uint8_t)Uss_Hsd_Channel_PWR_B);         
#endif		 
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[8] = (uint16_t)(US_SnrCfg_F_Get_CaliVer() & 0xffffu);
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[9] = (uint16_t)((US_SnrCfg_F_Get_CaliVer()>>16) & 0xffffu);   /*PRQA S 2985 */
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[10] = US_SnrCfg_Get_Variant();

#ifdef PLAYBACK_SW_ENABLE
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[4] = (uint16_t)(UssCan_GetChecksumFailCount() & 0xffffu);
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[5] = (uint16_t)((UssCan_GetChecksumFailCount()>>16) & 0xffffu);
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[6] = (uint16_t)(UssCan_GetChecksumPassCount() & 0xffffu);
        UssCom_sOutputBuffer.sDebugMsg_v.Unsig_Debug_Signal[7] = (uint16_t)((UssCan_GetChecksumPassCount()>>16) & 0xffffu);
#endif
#endif
    /* This debug function is called every 10ms no matter what, messes with the new data flag system */
    /* Need different solution if time critical data is here */

}


/* ===========================================================================
 * Name:	 UssCom_F_PopulateSensorSensitivityFlagList
 * Remarks:  DD-ID: {CCFCBCF2-A399-4aa1-8763-57DC35DA1C47}
 * Req.-ID:15740708
 * Req.-ID:15740739
 * Req.-ID:18517515
 * Req.-ID:18517546
 * Req.-ID:18517579
 * ===========================================================================*/

void UssCom_F_PopulateSensorSensitivityFlagList(void)
{
	uint8_t uSnrIdx;

	const uint64_t * NewSnrIDList = US_SnrCfg_F_Get_uNewSnrIDList();

	for(uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS_CONFIGURABLE; uSnrIdx++)
	{
        /*Quick fix. THere is a bug on sensor disconnect. Sensor value shows 1 byte value. */
		if((NewSnrIDList[uSnrIdx] & 0xFFFFFFFFFFFFu) > 0xFFFFFFFFu)
		{
			UssCom_sOutputBuffer.sSnrSensitivity.sensor_sensitivity[uSnrIdx] = ONE;
		}
		else
		{
			UssCom_sOutputBuffer.sSnrSensitivity.sensor_sensitivity[uSnrIdx] = ZERO;
		}

	}
}

#define US_D_M_PER_SEC_TO_CM_PER_TEN_MS  (100.0f / 100.0f)  // 1.0
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================
 * Name:	 UssCom_PopulateOddometry
 * Remarks:  DD-ID:{5462AF2C-0357-46ac-95E8-4ECFC98E221F}
 * Req.-ID:14959893
 * Req.-ID:16134127
* ===========================================================================*/
void UssCom_PopulateOdometry(float32_t fDx, float32_t fDy, float32_t fDyaw_rad, float32_t fTimestamp_s)
{	
    UssCom_sOutputBuffer.UssOddometry_v.dx_m=fDx;
    UssCom_sOutputBuffer.UssOddometry_v.dy_m=fDy;
    UssCom_sOutputBuffer.UssOddometry_v.dyaw_rad=fDyaw_rad;
    UssCom_sOutputBuffer.UssOddometry_v.timestamp_s = (uint64_t) (fTimestamp_s * 1E6);
}
#endif

/* ===========================================================================
 * Name:	 UssCom_ClearDirectAndIndirOutBuffs
 * Remarks:  DD-ID: {C271BD66-06AA-4794-9F7C-F7209E4CBFE5}
 *  Req.-ID: 14210760
 * Req.-ID: 14214786
 * Req.-ID: 14214192
 * Req.-ID: 17350940
 * Req.-ID: 15001879
 * ===========================================================================*/
void UssCom_ClearTestDataOutputs(void)
{
	uint8_t uSnrIdx;
	
	UssCom_S_TestDataCluster_t * psTestData = &UssCom_sOutputBuffer.sTestData;
    (void) memset(&UssCom_sOutputBuffer.sSnsDat_FrontPSM_Echoes_v, 0, sizeof(US_ME_SnsDat_FrontPSM_Echoes_t));
    (void)memset(&UssCom_sOutputBuffer.sSnsDat_RearSide_Echoes_v, 0, sizeof(US_ME_SnsDat_RearSide_Echoes_t));

   (void) memset(&UssCom_sOutputBuffer.sSnsDat_Front_Direct_v, 0, sizeof(US_ME_SnsDat_Front_Direct_t));
   (void) memset(&UssCom_sOutputBuffer.sSnsDat_Rear_Direct_v,  0, sizeof(US_ME_SnsDat_Rear_Direct_t));
   (void) memset(&UssCom_sOutputBuffer.sSnsDat_Front_Direct_2_v, 0, sizeof(US_ME_SnsDat_Front_Direct_2_t));
   (void) memset(&UssCom_sOutputBuffer.sSnsDat_Rear_Direct_2_v, 0, sizeof(US_ME_SnsDat_Rear_Direct_2_t));

    (void)memset(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_1_v, 0, sizeof(US_S_SnsDat_Front_Indirect_1_t));
   (void) memset(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_1_v, 0, sizeof(US_S_SnsDat_Rear_Indirect_1_t));
   (void) memset(&UssCom_sOutputBuffer.sSnsDat_Front_Indirect_2_v, 0, sizeof(US_S_SnsDat_Front_Indirect_2_t));
  (void) memset(&UssCom_sOutputBuffer.sSnsDat_Rear_Indirect_2_v, 0, sizeof(US_S_SnsDat_Rear_Indirect_2_t));
	
	(void)memset(&UssCom_sOutputBuffer.sPointDistOutputBuff,0,sizeof(US_S_PointDistOutputBuff_t));
	
	(void)memset(&UssCom_sOutputBuffer.sPointMapOutputBuff.pointMap[ZERO], 0, sizeof(US_S_Point_t) * 96u);
	UssCom_sOutputBuffer.sPointMapOutputBuff.timestamp = US_GetTimeStampTimeMs();
	
	UssCom_sOutputBuffer.sFiringSensors.firingSensors = ZERO;
    UssCom_sOutputBuffer.sFiringSensors.timestamp = ZERO;
	
	/* Populate Multiplexed CAN Data */
    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
		psTestData->sDataMux[uSnrIdx].uDirEcho    = ZERO;
		psTestData->sDataMux[uSnrIdx].uEchoHeight = ZERO;
		psTestData->sDataMux[uSnrIdx].uRingTime   = ZERO;
		psTestData->sDataMux[uSnrIdx].uDrvFreq    = ZERO;
		psTestData->sDataMux[uSnrIdx].uRingFreq   = ZERO;
    }
}
/* ===========================================================================
 * Name:	 UssCom_F_IsNewDataAvailable
 * Remarks:  DD-ID: {08E3A217-5311-45e0-865D-36462626C90D}
 * ===========================================================================*/
bool_t UssCom_F_IsNewDataAvailable(void)
{
    return UssCom_bIsNewDataAvailable;
}

void UssCom_F_ClearNewDataFlag(void)
{
    UssCom_bIsNewDataAvailable = ME_FALSE;
    UssCom_uNewDataCounter = ZERO;
}

/* ===========================================================================
 * Name:	 UssCom_F_SetNewDataFlag
 * Remarks:  DD-ID: {F40137C2-ACCE-49cf-ACF8-BC43AB668351}
 * ===========================================================================*/
static void UssCom_F_SetNewDataFlag(void)
{
    UssCom_bIsNewDataAvailable = ME_TRUE;
	if(UssCom_uNewDataCounter < 255u)
	{
      UssCom_uNewDataCounter++;
	}else{
		UssCom_uNewDataCounter = ZERO;
	}
}

/* ===========================================================================
 * for EOL test
 * 
 * ===========================================================================*/

#if(0 != (US_D_CUR_CAN_PLATFORM & US_D_CAN_PLATFORM_EOL_TESTER))

void UssCom_F_PopulateSnrType(void)   /*ID: 0x44  periodic */
{
	/*UssCom_E_SnrType *psSnrType =  &UssCom_sOutputBuffer.sSnrType; */
    uint8_t * pSnrTypeList = US_SnrCfg_F_Get_uSnrTypeList();
    memcpy(((uint8_t *)&UssCom_sOutputBuffer.sSnrType),pSnrTypeList, US_D_MAX_NUM_SENSORS * sizeof(uint8_t));

}
 
void UssCom_F_PopulateSnrID(void)   /*ID: 0x43  periodic */
{
	uint32_t * psSnrIDList = US_SnrCfg_F_Get_uSnrIDList();
	memcpy(&UssCom_sOutputBuffer.UssCom_SnrCfg_SensorID,psSnrIDList, US_D_MAX_NUM_SENSORS * sizeof(uint32_t));
}

void UssCom_F_PopulateMurataSerialNo(void)   /*ID: 0x43  periodic */
{
	uint64_t *psSnrMurataSNFront = &UssCom_sOutputBuffer.UssCom_SnrCfg_MurataSN_FrontBumper;
	uint64_t *psSnrMurataSNRear = &UssCom_sOutputBuffer.UssCom_SnrCfg_MurataSN_RearBumper;
	uint64_t * psSnrMurataSNList = US_SnrCfg_F_Get_uSnrMurataSN();
	memcpy(psSnrMurataSNFront,psSnrMurataSNList, SIX * sizeof(uint64_t));
	memcpy(psSnrMurataSNRear,&psSnrMurataSNList[SIX], SIX * sizeof(uint64_t));
}
#endif

