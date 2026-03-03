/*
 * US_SnrCmd_Global.h
 *
 *  Created on: May 11, 2021
 *      Author: jonapais
 */

#ifndef US_SNRCMD_GLOBAL_H_
#define US_SNRCMD_GLOBAL_H_

#include "US_Ctrl_Global.h"
#include "US_SnrData_Typedefs_Global.h"

#define US_D_CMD_ALWAYS_LISTENING  (0xFFu)

// Related to measurement data field uMeasStatBits.
#define US_D_MEAS_STAT_MEAS_ONGOING_BIT   (0x01u)
#define US_D_MEAS_STAT_REMAINING_ECHO_BIT (0x02u)

#define US_D_DEBUG_CAPTURE_FRAME_CNT    (ME_FALSE)
#if (US_D_DEBUG_CAPTURE_FRAME_CNT == ME_TRUE)
typedef struct US_S_DBG_SnsRcvRecInfo_s
{
    uint8_t     uTotalFrames;
    uint8_t     uEchoFrames;
    uint8_t     uOtherFrames;
    uint8_t     uNoEchoFrames;
    uint8_t     uFrameFlagBitmap;
} US_S_DBG_SnsRcvRecInfo_t;

typedef struct US_S_DBG_AllSnsRcvRecStats_s
{
    uint32_t    uTimeStamp;
    uint16_t    uSpiDataSize;
    uint16_t    uBytesProcessed;
    US_S_DBG_SnsRcvRecInfo_t    sFrameInfo[US_D_MAX_NUM_SENSORS];
    uint8_t     uSensorGaps;
    uint8_t     uEventFlagBitmap;
} US_S_DBG_AllSnsRcvRecStats_t;

#define US_D_DBG_FRAME_EVT_NULL         (ZERO)
#define US_D_DBG_FRAME_EVT_ECHO_FULL    (BIT0)
#define US_D_DBG_FRAME_EVT_BAD_SNSIDX   (BIT1)
#define US_D_DBG_FRAME_EVT_UNKNOWN_TYPE (BIT2)
#define US_D_DBG_FRAME_EVT_BAD_DRVIDX   (BIT3)
//#define US_D_DBG_FRAME_EVT_X    (BIT4)
//#define US_D_DBG_FRAME_EVT_X    (BIT5)
//#define US_D_DBG_FRAME_EVT_X    (BIT6)
//#define US_D_DBG_FRAME_EVT_X    (BIT7)

#endif

void UssSnrCmd_Init(void);

bool_t UssSnrCmd_bIsCmdDone(void);
void UssSnrCmd_SetBurstCmdDone(bool_t _bBurstCmdDone);

bool_t UssSnrCmd_bIsQueueCmdDone(void);
void UssSnrCmd_Set_QueueCmdDone(bool_t _bQueueCmdDone);

uint16_t UssSnrCmd_CheckSnrDisconnect(uint32_t uResponseReceived, uint32_t uAppSnrEnableMap);

const US_S_SensorMeasRcvRecs_t *UssSnrCmd_psGetMeasRcvRecPtr(void);
US_E_ParkingMode_t UssSnrCmd_eGetLoggedParkingMode(void);
uint8_t UssSnrCmd_uGetLoggingProtocolVer(void);
/* why is this global? US_E_SendType_t * peGetReqEchoType(void); */
/* why is this global? US_E_SendType_t * peGetMeasEchoType(void); */
void UssSnrCmd_PopulateSnrAddrIdxList(void);

void UssSnrCmd_SetBurstConfig(uint8_t uBusNum, const US_S_BurstConfig_t *psBurstConfig);
void UssSnrCmd_SetBurstConfigByGroupID(uint8_t uGrpIdx, const US_S_BurstConfig_t *psBurstConfig);
void UssSnrCmd_SetBurstConfigGlobally(const US_S_BurstConfig_t *psBurstConfig);

void UssSnrCmd_PopulateBurstCommand(void);
void UssSnrCmd_PopulateBurstCommand_AllRcv(void);
uint32_t UssSnrCmd_uGetuSnrMeasErrCode(void);
uint32_t UssSnrCmd_uGetuSnrMeasRcvTime(void);
void UssSnrCmd_ProcessSensorMeasurments(void);
uint16_t UssSnrCmd_CheckSnrMeasData(void);
US_S_Sensor_Temperature_t * UssSnrCmd_psGetSnrTemperatures(void);
US_S_Sensor_DiagnosticFlags_t * UssSnrCmd_psGetSnrDiagFlags(void);
uint32_t UssSnrCmd_uGetDvrEnableMap(void);
uint32_t UssSnrCmd_uGetAppEnableMap(void);
void UssSnrCmd_CopyPlaybackMeasRecord(const US_S_SensorMeasRecsForLogging_t *psSnrMeasLogRec,
                                      uint8_t const *Replay_NoiseDataRecs);
void UssSnrCmd_CopyPlaybackHwDiagRecord(US_S_Sensor_DiagnosticFlags_t const * Replay_DiagDataRecs);

void UssSnrCmd_SetGrpForSilence(uint8_t uGrpIdx);
void UssSnrCmd_ClrGrpForSilence(uint8_t uGrpIdx);
void UssSnrCmd_SetGrpSilenceRate(uint8_t uSilenceRate);
void UssSnrCmd_SetRcvProfilesByGroupID(uint8_t uGrpIdx, US_E_ProfileType_t eReceiveProfile);
void UssSnrCmd_SetRcvProfiles(uint8_t uBusNum, US_E_ProfileType_t eReceiveProfile);
void UssSnrCmd_SetMeasEchoTypeByGroupIdx(uint8_t uGrpIdx, US_E_SendType_t eSndType);

/* Driver command interfaces */
uint32_t UssSnrCmd_SendBurst(void);
uint32_t UssSnrCmd_ReqSensorTempCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqDiagnosticResultsCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqAATG1Cmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqAATG2Cmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqBurstTypeCfgCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqCalGainCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqChirpBWCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqCPSMeasGainCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqCurrentCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqEDIChannelCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqEnvCfgCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqEnvDataCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqEnvFiltCfgCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqFCCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqFixPathCfgCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqFTCCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqGainCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqGanaMeasBeginCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqMaxEchoNumCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqNFDCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqNormalBurstNumCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqProfileCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqProfilePlusCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqRingingCompCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqSendBurstWDelayCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqSensorEEFlagCTRLCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqSensorEEPROMCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqSensorFreqCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqSensorOPModeCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqSensorRegisterCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqSTCCmd(uint32_t uSnrMap);
uint32_t UssSnrCmd_ReqSTGCmd(uint32_t uSnrMap);

#endif /* SNRCMD_GLOBAL_H_ */
