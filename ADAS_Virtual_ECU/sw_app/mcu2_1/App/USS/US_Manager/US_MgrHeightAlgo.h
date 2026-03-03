/*
 * US_MgrHeightAlgo.h
 *
 *  Created on: Aug(8), 10, 2022
 *      Author: jwreynolds
 */

#ifndef USSMGR_SRC_US_MGRHEIGHTALGO_H_
#define USSMGR_SRC_US_MGRHEIGHTALGO_H_

#include "US_SysMgr_Global.h"
#include "US_ME_Typedefs_Global.h"
#include "ProxiMgrIpcDataTypes.h"

//#define LOG_DNN_TIME
#define ENABLE_FRONT_DNN_BUMPER

/* height mode enums & selection */
#define HEIGHT_ALGO_DEFAULT__UNKNOWN    (1u)
#define HEIGHT_ALGO_DEFAULT__LOW        (2u)
#define HEIGHT_ALGO_DEFAULT__HIGH       (3u)
#define US_D_HEIGHT_ALGO_DEFAULT_MODE   HEIGHT_ALGO_DEFAULT__LOW

/* height algo selection enums & selection */
#define HEIGHT_ALGO_TYPE__LINEAR_SCALE  (1u)
#define HEIGHT_ALGO_TYPE__ML_SIMPLE     (2u)
#define HEIGHT_ALGO_TYPE__ML_ADV        (3u)
#define HEIGHT_ALGO_DNN                 (4u)
#define HEIGHT_ALGO_RNN                 (5u)
#define US_D_HEIGHT_ALGO_TYPE_TO_USE    HEIGHT_ALGO_RNN
#define HEIGHT_ALGO_NUM_SENSORS (4u)
#define HEIGHT_ALGO_NUM_INPUTS (7u)
#define HEIGHT_ALGO_NUM_INPUTS_NOISE (6u)
#define HEIGHT_ALGO_NUM_CLASSES (5u)

#define HEIGHT_ALGO_NUM_ECHOES     (3u)
#define USSCOM_BUMPLOC_REAR (US_D_PHYS_GRP_REAR)
#define USSCOM_BUMPLOC_FRONT (US_D_PHYS_GRP_FRNT)

typedef struct
{
    int16_t sDist3;
    float32_t fHeight3;
    uint16_t uWidth2;    
    float32_t fHeight2;
    int16_t sDist2;
    uint16_t uWidth1;  
    float32_t fHeight1;
    int16_t sDist1;
    uint16_t uConf1;
    uint8_t echo1Idx;
    uint8_t echo2Idx;
    uint8_t echo3Idx;
    uint8_t numEchoes;
    
} US_S_HeightAlgoInput_t;


/* Function to run the main height algo
 * Will modify bLargeObject flag in sOneSensorCalcs
 * returns status
 * E_OK - algo ran fine
 * E_NOT_OK - algo gave an invalid value so default was set
 */
bool_t UssMgr_UpdateHeightGuessForSensor(US_S_SnrCalcRec_t * sOneSensorCalcs, US_S_SensorRec_t * sOneSensorRec);

/* Auto reset when UssMgr_UpdateHeightGuessForSensor as well */
void UssMgr_Reset_2ndEchoSameObjFlag(void);
/* extra data from height algo - might get expanded */
bool_t UssMgr_Get_2ndEchoSameObjFlag(void);
/* force same obj calc also return the result at the same time */
bool_t UssMgr_Calc_2ndEchoSameObjFlag(US_S_SnrCalcRec_t * sOneSensorCalcs);
#if  US_D_HEIGHT_ALGO_TYPE_TO_USE ==   HEIGHT_ALGO_RNN

void USSMgr_HeightEstimationRNN(void);
#endif
#ifdef HEIGHT_ALGO_DNN
void Height_Algo_DNN(void);
#endif
#endif