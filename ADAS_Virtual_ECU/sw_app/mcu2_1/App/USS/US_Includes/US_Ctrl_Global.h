/*
 * US_Ctrl_Global.h
 *
 *  Created on: May 11, 2021
 *      Author: jonapais
 */

#ifndef US_CTRL_GLOBAL_H_
#define US_CTRL_GLOBAL_H_

#include "US_Data_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_SnrCfg_Global.h"

/* Sensor Marriage defines */
#define US_D_ALL_SENSORS_MARRIAGE_DONE_API_BITS   (0x01010101)   /* To set all status at once to Done*/
#define US_D_ALL_SENSORS_MARRIAGE_ERROR_API_BITS  (0x03030303)   /* To set all status at once to Error*/
#define US_D_ALL_SENSORS_MARRIAGE_DONE            (0x01)     /* Per bus Done */
#define US_D_ALL_SENSORS_MARRIAGE_PENDING         (0x02)     /* Per bus Pending */

#define US_D_ALL_SENSORS_MARRIAGE_DONE_NVM_BITS   (0x0F)     /* To set all status at once to Done */

#define USERINFO_NONE                             (0x00000000)

typedef enum UssCtrl_eSensorCfgState_e
{
    USSCTRL_SENSORCFG_IDLE = 0,
    USSCTRL_SENSORCFG_PENDING,
    USSCTRL_SENSORCFG_DOING
} UssCtrl_eSensorCfgState_t;

typedef enum UssCtrl_eTempAdjState_e
{
    USSCTRL_TEMPADJ_IDLE = 0,
    USSCTRL_TEMPADJ_PENDING,
    USSCTRL_TEMPADJ_DOING
} UssCtrl_eTempAdjState_t;

typedef enum US_E_FireSeqPatType_e
{
    US_FIRE_PAT_ROUND_ROBIN,
    US_FIRE_PAT_ROUND_ROBIN_REVERSE,
    US_FIRE_PAT_RANDOM,
    US_FIRE_PAT_SHUFFLE
} US_E_FireSeqPatType_t;

typedef enum US_E_FireSeqPatStartType_e
{
    US_FIRE_PAT_START_AT_ZERO,
    US_FIRE_PAT_START_AT_RANDOM

} US_E_FireSeqPatStartType_t;


typedef struct US_S_SensorLocs_s
{
    const uint8_t *psSendSnrs;
    const uint8_t *puRcvrSnrs;
    const uint8_t  uNumSendSnrs;
    const uint8_t  uNumRcvrSnrs;
} US_S_SensorLocs_t;

typedef struct US_S_FireSequence_s
{
    const US_S_SensorLocs_t    *psSensorLocs;
    US_E_FireSeqPatType_t       eFireSeqPat;
    US_E_FireSeqPatStartType_t  eFireSeqPatStartType;
    uint8_t                     uCycleCount;
} US_S_FireSequence_t;

typedef struct US_S_BurstConfig_s
{
    const uint8_t  uNumPDCM;
    const uint8_t  SnrType;
    const US_S_SendBurst17Cfg_t sSnrCfg;
} US_S_BurstConfig_t;

#define USS_MAX_NUM_STEPS_FOR_SHUFFLE   (16u)

typedef struct US_S_FireSeqCmd_s
{
    const US_S_SensorLocs_t    *psSensorLocSeq;
    US_E_FireSeqPatType_t       eFireSeqPat;
    US_E_FireSeqPatStartType_t  eFireSeqPatStartType;
    uint8_t                     uNumSeqSteps;
    uint8_t                     uMaxCycleCount;
    uint8_t                     uCurCycleCount;
    uint8_t                     uCurSeqStep;
    uint8_t                     uCurSeqRecord;
    uint8_t                     auSnrIdxShuffleList[USS_MAX_NUM_STEPS_FOR_SHUFFLE];
} US_S_FireSeqCmd_t;

#define US_D_NUM_SENSORS_FOR_THIS_PLATFORM (TWELVE)

#define US_MAX_FIRE_SEQ_CMDS    (2u)
#define US_FS_NEEDS_INIT        (0xFFu)

/* PUBLIC FUNCTION INTERFACE */
US_S_FireSeqCmd_t *UssCtrl_pasGetFireSeqCmds(void);

void UssCtrl_SetFireSequence(const US_S_SensorLocs_t       *psSensorLocSeq,
                                US_E_FireSeqPatType_t       eFireSeqPat,
                                US_E_FireSeqPatStartType_t  eFireSeqPatStartType,
                                uint8_t                     uNumSeqSteps,
                                uint8_t                     uMaxCycleCount);

void UssCtrl_AddFireSequence(const US_S_SensorLocs_t       *psSensorLocSeq,
                                US_E_FireSeqPatType_t       eFireSeqPat,
                                US_E_FireSeqPatStartType_t  eFireSeqPatStartType,
                                uint8_t                     uNumSeqSteps,
                                uint8_t                     uMaxCycleCount);

bool_t UssCtrl_SetNextFireSequenceStep(void);
void UssCtrl_SetFireSequenceInit(void);
uint8_t UssCtrl_uGetNumFireSequences(void);
uint8_t UssCtrl_uGetFireSequenceCurCycle(uint8_t uFireSequenceIdx); /*NOT the step*/
bool_t UssCtrl_bIsNewSensorData(void);
void UssCtrl_ClearNewSensorDataFlag(void);
void UssCtrl_ClearAllFireSequences(void);
void UssCtrl_StopFireSeq(void);
void UssCtrl_StartFireSeq(void);
bool_t UssCtrl_bIsCtrlFsmHalted(void);
uint16_t UssCtrl_uGetuFireSeqDelayMs(void);
void UssCtrl_SetFireSeqDelayMs(uint8_t uDelayMs);
void UssCtrl_SetRandSilenceMaxMs(uint8_t uMaxTime);
void UssCtrl_SetListenOnlyFreq(uint8_t uLstOnlyFreq, uint8_t uCycleDelay);
#if (QAC_WARNING_FIX  ==  ME_FALSE)
void UssCtrl_SetNewSnrPlaybackDataFlag(void);
#endif
bool_t UssCtrl_bIsSysInPlaybackMode(void);
void UssCtrl_MainInit(void);
void UssCtrl_Main(void);
uint8_t UssCtrl_GetSnrCfgIndex(void);
uint8_t UssCtrl_CheckForSnrCalChange(void);
float32_t UssCtrl_Get_fTempBinFraction(void);
void UssCtrl_SetTemAdjState(UssCtrl_eTempAdjState_t eState);
uint16_t UssCtrl_uGetSnrCalAdjState(void);
void UssCtrl_TriggerSnrCfg(void);
uint16_t UssCtrl_Get_Temperature_Index(void);
void UssCtrl_ClearReceiveErrorCnt(void);
/*
 * CONTROLLER GLOBAL DATA - Consider accessor or moving some items to local header.
 */
#define US_SNRLOCS_ONE_STEP_SEQ_LEN     (1u)
#define US_SNRLOCS_TWO_STEP_SEQ_LEN     (2u)
#define US_SNRLOCS_FOUR_STEP_SEQ_LEN    (4u)
#define US_SNRLOCS_SIX_STEP_SEQ_LEN     (6u)
#define US_SNRLOCS_TWELVE_STEP_SEQ_LEN  (12u)
#define US_SNRLOCS_SIXTEEN_STEP_SEQ_LEN (16u)

/* Fire sequence definitions */
extern const US_S_SensorLocs_t US_SnrLocs_FrntRear_OneAtATime_12ST[US_SNRLOCS_TWELVE_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_FrontAndRear_SameTime[US_SNRLOCS_SIX_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_FastScan_SameTime[US_SNRLOCS_FOUR_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_FastScan_SameTime_FrontSide_RearAll[US_SNRLOCS_FOUR_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_FastScan_SameTime_FrontAll_RearSide[US_SNRLOCS_FOUR_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_FrontRearSides_SameTime[US_SNRLOCS_SIX_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_Rear_OneAtATime[US_SNRLOCS_SIX_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_Front_OneAtATime[US_SNRLOCS_SIX_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_FrontSidesOnly_OneAtATime[US_SNRLOCS_TWO_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_FrontSidesOnly_SameTime[US_SNRLOCS_ONE_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_AllSidesOnly_SameTime[US_SNRLOCS_ONE_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_NFDScan_SameTime[US_SNRLOCS_TWO_STEP_SEQ_LEN];
extern const US_S_SensorLocs_t US_SnrLocs_RivianFastScan_SameTime[US_SNRLOCS_FOUR_STEP_SEQ_LEN];

#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
    extern const US_S_SensorLocs_t US_SnrLocs_FrntSideRear_OneAtATime_16ST[US_SNRLOCS_SIXTEEN_STEP_SEQ_LEN];
#endif

extern const US_S_BurstConfig_t US_BrstCfg_Front_Rear_Fixed;
extern const US_S_BurstConfig_t US_BrstCfg_NFD;
extern const US_S_BurstConfig_t US_BrstCfg_Chirp_Up;
extern const US_S_BurstConfig_t US_BrstCfg_Chirp_Up_Strict;
extern const US_S_BurstConfig_t US_BrstCfg_Chirp_Down;
extern const US_S_BurstConfig_t US_BrstCfg_Chirp_Down_Strict;
extern const US_S_BurstConfig_t US_BrstCfg_Chirp_Both;

#endif /* US_CTRL_GLOBAL_H_ */
