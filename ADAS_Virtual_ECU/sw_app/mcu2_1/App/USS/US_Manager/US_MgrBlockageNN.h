#ifndef US_MGR_BLOCKAGENN_H
#define US_MGR_BLOCKAGENN_H
#include "US_SysMgr_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_MgrZeroDistRFModel.h"
#include "US_Diagnostic_Global.h"
#include "US_MgrMath.h"
#include "US_Odometry_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_Diagnostic_Global.h"

#define USS_BLOCKAGE_RINGTIME_VAR_SCALE (25.0f)
#define USS_BLOCKAGE_MAX_ECHO_DIST (100u)
#define USS_BLOCKAGE_LOWER_ALPHA_TH (0.6f)
#define USS_BLOCKAGE_UPPER_ALPHA_TH (0.95f)
#define USS_BLOCKAGE_MAX_CTR_TH (10u)
#define SNR_TMP_RESOLUTION (10.0f)
#define USS_BLOCKAGE_TEMP_TH (10)


#if 0
#define US_D_TOF_TEMP_DEFAULT           (20.0f)
#endif
#ifdef USS_SIM_DBUG
typedef enum US_E_SNR_TYPE_e
{
    US_SNR_TYPE_PSM =ZERO,
    US_SNR_TYPE_PDC,    
    US_SNR_TYPE_MAX
} US_E_SNR_TYPE_t;
#endif

typedef struct USS_RandomForest_s
{    
    uint8_t uMaxDepth;
    const uint16_t *puTreeOffsets;
    const int16_t *pChildrenLeft;
    const int16_t *pChildrenRight;
    const int8_t *pFeatures;
    const uint16_t *puThresholds;
    const uint8_t *puValues;
} USS_RandomForest_t;

USS_RandomForest_t uss_blockage_model = {
    .uMaxDepth = USS_BLOCKAGE_RF_MAX_DEPTH,
    .puTreeOffsets = USS_BLOCKAGE_RF_TREE_OFFSETS,
    .pChildrenLeft = USS_BLOCKAGE_RF_CHILDREN_LEFT,
    .pChildrenRight = USS_BLOCKAGE_RF_CHILDREN_RIGHT,
    .pFeatures = USS_BLOCKAGE_RF_FEATURES,
    .puThresholds = USS_BLOCKAGE_RF_THRESHOLDS,
    .puValues = USS_BLOCKAGE_RF_VALUES
};

static float32_t afBlockageFilterBuffer[US_D_MAX_NUM_SENSORS];
static uint8_t auBlockage[US_D_MAX_NUM_SENSORS];
static uint8_t auBlockageCtr[US_D_MAX_NUM_SENSORS];
#ifndef USS_SIM_DBUG
static float32_t fBlockageStatus[US_D_MAX_NUM_SENSORS][TWO];
#endif
#ifdef USS_SIM_DBUG
uint16_t gBlockageInput[US_D_MAX_NUM_SENSORS][USS_BLOCKAGE_RF_N_FEATURES];
extern uint8_t  g_variant;
float32_t fBlockageStatus[US_D_MAX_NUM_SENSORS][TWO];
#endif

#if (BLOCKAGE_DEBUG == ME_TRUE)
static uint8_t auPrediction[US_D_MAX_NUM_SENSORS];
static uint8_t auBlockageCalled[US_D_MAX_NUM_SENSORS];
#endif

/* STATIC FN PROTOTYPES */
static uint8_t  USSMgr_Block_PredictTree(const USS_RandomForest_t *pRF, uint16_t uTree_Idx, const uint16_t *puFeatures);
static uint16_t USSMgr_BlockageGet1stDistance(const uint8_t uSnrIdx);
static uint16_t USSMgr_BlockageGetEchoType(const US_S_SensorRec_t *psSensorRec );
static uint16_t USSMgr_BlockageGetRingTimeVar(const uint8_t uSnrIdx, const uint16_t uCurrRingTime);
static bool_t USSMgr_BlockageEstimationNN_Input(const uint8_t uSnrIdx, uint16_t aBlockageInput[USS_BLOCKAGE_RF_N_FEATURES]);
static void USSMgr_BlockageFilteredDecision(const uint8_t uSnrIdx, const uint8_t uPrediction);
static float32_t USSMgr_BlockageGetTemperature(void);
static uint8_t USSMgr_BlockageGetSensorType(const uint8_t uSnrIdx);
extern US_S_ClusterBurstCmd_t * psGetSendBurstCfg(void);
static uint16_t USSMgr_BlockageGetSnremperature(const uint8_t uSnrIdx);
#endif