/*
 * US_SnrData_Typedefs_Global.h
 *
 *  Created on: Apr 6, 2021
 *      Author: jonapais
 */

#ifndef US_SNRPROC_TYPEDEFS_GLOBAL_H_
#define US_SNRPROC_TYPEDEFS_GLOBAL_H_

#include "US_ME_Typedefs_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"

#define US_D_MAX_SENSOR_PER_CLUSTER  (6u)
#define US_D_DRV_MAX_ECHOES_BUFF     (20u)
#define US_D_APP_MAX_ECHOES_BUFF     (3u)
#define US_D_APP_MAX_MEAS_BUFF_SIZE  (3u)

#define US_D_APP_MAX_NOISE_ECHO_BUFF (3u)
#define US_D_APP_MAX_CHIRP_TYPE_BUFF (3u)


typedef enum USSMgr_E_BlockageVars_e
{
    BLOCKAGE_FILTERED_FLAG,
    BLOCKAGE_FRAME_PREDICTION,
    BLOCKAGE_CALLED_FLAG,
    BLOCKAGE_COUNTER
}USSMgr_E_BlockageVars_t;


typedef enum US_E_EchoClass_e
{
    US_E_DIRECT = 0,
    US_E_INDIRECT = 1,
    US_E_LISTEN_ONLY = 2
} US_E_EchoClass_t;

typedef enum US_E_EchoType_e
{
    US_E_NOECHO = 0,
    US_E_RINGTIME = 1,
    US_E_FIXED = 2,
    US_E_CHIRP_DOWN = 3,
    US_E_CHIRP_UP = 4,
    US_E_NFD = 5,
    US_E_NOISE_INFO = 6,
    US_E_SIG_PATH_RESULTS = 7
} US_E_EchoType_t;

typedef struct US_S_Echo_s
{
    US_E_EchoType_t eEchoType; /* Echo Type */
    uint8_t  uConf;
    uint16_t uEchoHeight;
    uint16_t uWidth;
    uint16_t uDistTOF_us;
} US_S_Echo_t;

typedef struct US_S_RingTime_s
{
    uint16_t uRingTime;
    uint16_t uDrvFreq;
    uint16_t uRingFreq;
} US_S_RingTime_t;

typedef struct US_S_SnrFreq_s
{
    uint16_t uDrvFreq_1Hz;
    uint16_t uRingFreq_1Hz;
} US_S_SnrFreq_t;

typedef struct US_S_AllSnrFreqData_s
{
    uint32_t uTimestamp;
    US_S_SnrFreq_t saSnrFreqData[US_D_MAX_NUM_SENSORS];
} US_S_AllSnrFreqData_t;

typedef struct US_S_NoiseMeas_s
{
    uint16_t uSum;
    uint8_t  uCount;
    uint8_t  uHeight;
    uint8_t  uATG;
    uint8_t  uReserved;
} US_S_NoiseMeas_t;

typedef enum US_E_SnrType_e
{
    US_E_SNR_TYPE_PDC = ZERO,
    US_E_SNR_TYPE_PSM,
    US_E_SNR_TYPE_MAX
} US_E_SnrType_t;

/* 
 * Noise data types
 *
 */
typedef enum US_E_NoiseLevel_e
{
    US_E_NOISELEVEL_NONE = ZERO,
    US_E_NOISELEVEL_LOW,
    US_E_NOISELEVEL_HIGH
} US_E_NoiseLevel_t;

typedef enum US_E_NoiseType_e
{
    US_E_NOISETYPE_STRONG_DOWN = -2,
    US_E_NOISETYPE_WEAK_DOWN = -1,
    US_E_NOISETYPE_GENERIC = ZERO,
    US_E_NOISETYPE_WEAK_UP,
    US_E_NOISETYPE_STRONG_UP
} US_E_NoiseType_t;

typedef struct US_S_NoiseEchoHistory_s
{
    uint16_t        uNoiseHeightBuf[US_D_APP_MAX_NOISE_ECHO_BUFF];
    uint16_t        uNoiseDistBuf[US_D_APP_MAX_NOISE_ECHO_BUFF];
    /* Maybe needed US_E_EchoType_t eEchoTypeBuf[US_D_APP_MAX_NOISE_ECHO_BUFF]; */
    uint8_t         uBufIndex;
} US_S_NoiseEchoHistory_t;

typedef struct US_S_TypeHist_s
{
    US_E_EchoType_t eEchoTypeBuf[US_D_APP_MAX_CHIRP_TYPE_BUFF];
    uint8_t         uBufIndex;
} US_S_TypeHist_t;

typedef struct US_S_AllSnrNoiseEchoHistory_s
{
    US_S_NoiseEchoHistory_t     sSnrNoiseHistory[US_D_MAX_NUM_SENSORS];
} US_S_AllSnrNoiseEchoHistory_t;

typedef struct US_S_AllSnrChirpTypeHist_s
{
    US_S_TypeHist_t     sSnrChirpTypeHist[US_D_MAX_NUM_SENSORS];
} US_S_AllSnrChirpTypeHist_t;

typedef struct US_S_SensorNoiseData_s
{
    US_E_NoiseLevel_t     eNoiseHistory[US_D_APP_MAX_NOISE_ECHO_BUFF];  //max echo buff not directly related
    US_E_NoiseLevel_t     eCurrentLevel;
    US_E_NoiseType_t      eNoiseTypeGuess;
    uint8_t               uUnsureCounter;
} US_S_SensorNoiseData_t;

typedef struct US_S_AllSnrNoiseData_s
{
    US_S_SensorNoiseData_t sSnrNoiseData[US_D_MAX_NUM_SENSORS];
    bool_t                 bNewNoiseDataAvail;
} US_S_AllSnrNoiseData_t;


/*
 * The following two structures are used to store sensor measurements in
 * manager.  The difference between received data and record data is due
 * to the number of echo peaks stored.  The number of peaks is reduced in manager.
 * Up to 3 echo peaks are supported.
 */
typedef enum US_E_SendType_e
{
    US_E_REQ_STANDBY,
    US_E_REQ_SEND_NORMAL,
    US_E_REQ_SEND_CHIRP_UP,
    US_E_REQ_SEND_CHIRP_DOWN,
    US_E_REQ_SEND_NFD,
    US_E_REQ_RECEIVE
} US_E_SendType_t;

typedef struct US_S_SensorRec_s
{
    US_E_SendType_t  eEchoTypeRequested; // Could pack profile into this byte.
    uint8_t          uDiagStatus;
    uint8_t          uNumEchoes;
    uint8_t          uFirstEchoIdx;
    uint8_t          uMeasStatBits;
    US_S_RingTime_t  sRingTime;
    US_S_NoiseMeas_t sNoiseMeas;
    US_S_Echo_t      sEcho[US_D_APP_MAX_ECHOES_BUFF];
} US_S_SensorRec_t;

typedef struct US_S_SensorMeasRecs_s
{
    uint32_t         uTimeStamp;
    uint32_t         uSendingSensors;
    uint32_t         uResponseReceived;
    US_S_SensorRec_t sSensorRec[US_D_MAX_NUM_SENSORS];
} US_S_SensorMeasRecs_t;
typedef struct US_S_SignedDist_s
{
    sint16_t    aiEchoTotalDist[US_D_APP_MAX_ECHOES_BUFF];
} US_S_SignedDist_t;
typedef struct US_S_SensorMeasDist_s
{
    US_S_SignedDist_t asSensorRecDist[US_D_MAX_NUM_SENSORS];
} US_S_SensorMeasDist_t;
 
typedef struct US_S_SensorRecForLogging_s
{
    US_E_SendType_t  eEchoTypeRequested; // Could pack profile into this byte.
    uint8_t          uDiagStatus;
    uint8_t          uNumEchoes;
    uint8_t          uFirstEchoIdx;
    US_S_RingTime_t  sRingTime;
    US_S_Echo_t      sEcho[THREE];
} US_S_SensorRecForLogging_t;

typedef struct US_S_SensorMeasRecsForLogging_s
{
    uint32_t uTimeStamp;
    uint32_t uSendingSensors;
    uint32_t uResponseReceived;
    US_S_SensorRecForLogging_t sSensorRec[TWELVE];
    uint32_t uChecksum; // not used.
    uint8_t uProtocolVersionNum;
    uint8_t uParkingMode;
    uint8_t auMeasStatusBits[TWELVE];
} US_S_SensorMeasRecsForLogging_t;

/*
 * End Data Logging Types
 */

/*
 * Data structures for receipt of sensor data.
 * Up to 20 echo peaks are supported.
 */
typedef struct US_S_SensorRcvRec_s
{
    US_E_SendType_t  eEchoTypeRequested;
    US_E_SendType_t  eMeasTypeRequested; //Send type without send/recv logic
    uint8_t          uDiagStatus;
    uint8_t          uNumEchoes;
    uint8_t          uFirstEchoIdx;
    uint8_t          uMeasStatBits;
    US_S_RingTime_t  sRingTime;
    US_S_NoiseMeas_t sNoiseMeas;
    US_S_Echo_t      sEcho[US_D_DRV_MAX_ECHOES_BUFF];
} US_S_SensorRcvRec_t;

typedef struct US_S_SensorMeasRcvRecs_s
{
    uint32_t             uTimeStamp;
    uint32_t             uSendingSensors;
    uint32_t             uResponseReceived;
    US_S_SensorRcvRec_t  sSensorRec[US_D_MAX_NUM_SENSORS];
    US_E_ProfileType_t   eRcvProfile[US_D_MAX_NUM_BUS];
} US_S_SensorMeasRcvRecs_t;

typedef struct US_S_Sensor_Temperature_s
{
    uint32_t  uTimeStamp;
    sint16_t  iSnrTemperature[US_D_MAX_NUM_SENSORS];
} US_S_Sensor_Temperature_t;

typedef struct US_S_Sensor_DiagnosticFlags_s
{
    uint32_t  uTimeStamp;
    uint32_t  uResponseReceived;
    uint16_t  uHardwareDiagFlags[US_D_MAX_NUM_SENSORS];
    uint16_t  uMeasDiagFlags[US_D_MAX_NUM_SENSORS];
    uint16_t  uCommDiagFlags[US_D_MAX_NUM_SENSORS];
    uint16_t  uAsilDiagFlags[US_D_MAX_NUM_SENSORS];
} US_S_Sensor_DiagnosticFlags_t;


/*
 * **************  CALCULATION STORAGE ****************
 */

#define US_D_TOF_STORAGE_ENABLED

/* US_S_EchoCalc_t -> uEchoCalcFlags bitmap values */
#define US_D_CALCFLAG_NULL              (ZERO)
#define US_D_CALCFLAG_FAKE              (BIT0)
#define US_D_CALCFLAG_HIGH_CONF         (BIT1)
#define US_D_CALCFLAG_NOISY             (BIT2)
//#define US_D_CALCFLAG_#####             (BIT3)
#define US_D_CALCFLAG_DELETED           (BIT7)
 
typedef struct US_S_EchoCalc_s
{
    uint16_t uDirectDist_cm;
    uint16_t uTotalDist_cm;
#ifdef US_D_TOF_STORAGE_ENABLED
    uint16_t uTOF_us;       // For diagnostics purposes.
#endif
    uint16_t uSignalStrength;
    bool_t   bLargeObject;
    bool_t   bLargeFAPAObject;
    uint8_t  uEchoCalcFlags;
    uint8_t  uRecEchoIndex; //gives index of sEcho inside sSensorRec
} US_S_EchoCalc_t;

typedef struct US_S_SnrCalcRec_s
{
    uint8_t uNumEchoes;
    US_E_EchoType_t eEchoType; /* The echo type of the FIRST echo */
    US_E_EchoClass_t eEchoClass;
    US_S_EchoCalc_t  sEchoCalc[US_D_APP_MAX_ECHOES_BUFF];
} US_S_SnrCalcRec_t;

typedef struct US_S_SnrCalcs_s
{
    US_S_SnrCalcRec_t sSnrCalcRec[US_D_MAX_NUM_SENSORS];
} US_S_SnrCalcs_t;

#endif /* US_SNRPROC_TYPEDEFS_GLOBAL_H_ */
