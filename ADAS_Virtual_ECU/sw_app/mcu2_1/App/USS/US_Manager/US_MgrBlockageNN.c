#include "US_MgrBlockageNN.h"

/* ===========================================================================
* \brief Predict the blockage at frame basis
 *
 * \param features Array of 9 features

 * \return  uint16_t 1 if blockage, 0 if not
 * \remarks bool_t Writing of com output buffer successful.
 */
/* ===========================================================================
 * Name:	 USSMgr_Block_PredictTree
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
static uint8_t  USSMgr_Block_PredictTree(const USS_RandomForest_t *pRF, uint16_t uTree_Idx, const uint16_t *puFeatures)
{
    const int16_t start = (int16_t)pRF->puTreeOffsets[uTree_Idx];
    int16_t node = start;
    int16_t left;
    int16_t right;
    uint8_t u_ret_val = ZERO;
    uint8_t uDepth = ZERO;
    bool_t bFoundNode = ME_FALSE;
    
    for (uDepth = ZERO; (uDepth <= pRF->uMaxDepth) && ( (bool_t)ME_FALSE == bFoundNode); ++uDepth)
    {
        left = pRF->pChildrenLeft[node];
        right = pRF->pChildrenRight[node];
        if (left == right)
        { // Leaf node
            u_ret_val = pRF->puValues[node];
            bFoundNode = (bool_t)ME_TRUE;
        }
        else
        {
            node = ((int32_t)puFeatures[pRF->pFeatures[node]] <= (int32_t)pRF->puThresholds[node]) ? left : right;
        }
    }
    return u_ret_val;
}

/* ===========================================================================
* \brief Get the 1st Echo Distance
 *
 * \param psSnrCalcRec pointer to Calc Record

 * \return  uint16_t Echo Distance
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_BlockageGet1stDistance
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
static uint16_t USSMgr_BlockageGet1stDistance(const uint8_t uSnrIdx)
{
    uint16_t uEchoDist;
    const US_S_SensorMeasDist_t  *const psSnrMeasDist = (const US_S_SensorMeasDist_t *)UssMgr_psGetCurSnrMeasRecDist();
    const US_S_SignedDist_t *psSnrSignedDist = &psSnrMeasDist->asSensorRecDist[uSnrIdx];

    /*positive distance and limit to 100cm*/             
    uEchoDist = (uint16_t)fabs(psSnrSignedDist->aiEchoTotalDist[ZERO]);
    uEchoDist = (uEchoDist > USS_BLOCKAGE_MAX_ECHO_DIST )? ZERO : uEchoDist;        
    
    return uEchoDist;
}

/* ===========================================================================
* \brief Get the Sent Echo Type
 *
 * \param uSnrIdx uint8_t Sensor Idx 0 to 12

 * \return  uint16_t: 0 if NORMAL mode, 1 if NOISE mode
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_BlockageGetEchoType
 * Remarks:  
 * Req.-ID: 3
 * 
 * ===========================================================================*/
static uint16_t USSMgr_BlockageGetEchoType(const US_S_SensorRec_t *psSensorRec )
{
    const US_E_SendType_t eEchoType = psSensorRec->eEchoTypeRequested;
    uint16_t uEchoNoise;

    /*code the Echo Type into a binary input, Normal or Noise Type*/
    if(eEchoType >= US_E_REQ_SEND_CHIRP_UP)
    {
        uEchoNoise = ME_TRUE;
    }
    else
    {
        uEchoNoise = ME_FALSE;
    }
    return uEchoNoise;
}

/* ===========================================================================
* \brief Get the  Sensor Ring Time Variance, obtained by comparing previous to new signal
 *
 * \param uSnrIdx uint8_t Sensor Idx 0 to 12

 * \return  uint16_t: ring time variance
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_BlockageGetRingTimeVar
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
static uint16_t USSMgr_BlockageGetRingTimeVar(const uint8_t uSnrIdx, const uint16_t uCurrRingTime)
{
    uint16_t uRingTimeVar = ZERO;
    float32_t f_delta;

    if (fBlockageStatus[uSnrIdx][ZERO] > 0.0f)
    {
        /*delta between current and previous RingTime*/
        f_delta = (float32_t)fabsf(fBlockageStatus[uSnrIdx][0] - (float32_t)uCurrRingTime); 
        /*filter the delta*/
        fBlockageStatus[uSnrIdx][1] = exp_moving_avg(fBlockageStatus[uSnrIdx][1], f_delta, USS_BLOCKAGE_RF_POSTIVE_THRESHOLDS); 
        /*sclae the variance*/
        uRingTimeVar = (uint16_t)((float32_t)USS_BLOCKAGE_RINGTIME_VAR_SCALE * (float32_t)fBlockageStatus[uSnrIdx][1]); // Update ring time variance
    }
    else    {/*DO NOTHING*/    }
    #if ( BLOCKAGE_DEBUG == ME_TRUE)
    fBlockageStatus[uSnrIdx][ZERO] = (float32_t)uCurrRingTime;//store ringTime for next cycle
    #endif
    return uRingTimeVar;
}

/* ===========================================================================
* \brief Get the  Sensor temperature
 *
 * \param none

 * \return  float32_t : Sensor Temperature 
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_BlockageGetSnremperature
 * Remarks:  Sensor Temperature is in 0.1C resolution
 * Req.-ID: 
 * ===========================================================================*/
 static uint16_t USSMgr_BlockageGetSnremperature(const uint8_t uSnrIdx)
{
   const US_S_Sensor_Temperature_t * psTemperatures = UssSnrCmd_psGetSnrTemperatures();
   /*sensor temperature is in 0.1C resolution*/
   const float32_t fTmp = ((float32_t)psTemperatures->iSnrTemperature[uSnrIdx] )/ SNR_TMP_RESOLUTION;
   sint16_t iSnrTmp;
   uint16_t uRet;

   if( fTmp > 0.0f) 
   {
    iSnrTmp = (sint16_t)(fTmp + 0.5f);/*round up to the nearest integer*/
   }
   else
   {
    iSnrTmp = (sint16_t)(fTmp - 0.5f);/*round up to the nearest integer*/
   }
   /*code Sensor temperature into a binary input
   0 if temp is below 10C
   1 if temp is above or equal to 10*/
   if(iSnrTmp >= USS_BLOCKAGE_TEMP_TH)
   {
    uRet = ONE;
   }
   else
   {
    uRet = ZERO;
   }
   return uRet;
}

/* ===========================================================================
* \brief Get the  Sensor Type, PSM or PDC
 *
  * \param uSnrIdx uint8_t Sensor Idx 0 to 12

 * \return  uint8_t Sensor Type, PDC 1, PSM 0
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_BlockageGetSensorType
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
static uint8_t USSMgr_BlockageGetSensorType(const uint8_t uSnrIdx)
{    
    uint8_t const *pSnrType = UssCtrl_psGetSensorType();                   
    return (uint8_t)pSnrType[uSnrIdx];
}

/* ===========================================================================
* \brief Get the  Sensor Type, PSM or PDC
 *
  * \param uSnrIdx uint8_t Sensor Idx 0 to 12
  * \param uBlockageInput uint16_t array where the sensor inputs/features will be stored

 * \return  bool_t Succesfull Sensor Input TRUE, Inputs not correctly loaded FALSE
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_BlockageEstimationNN_Input
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
static bool_t USSMgr_BlockageEstimationNN_Input(const uint8_t uSnrIdx, uint16_t aBlockageInput[USS_BLOCKAGE_RF_N_FEATURES])
{        
    uint32_t uBitMap;
    bool_t bCheckSnr = ME_FALSE;    
    uint8_t uIdx;
             
    const US_S_SensorRec_t *psSensorRec;
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    
    uBitMap = (uint32_t)US_IDX_TO_BIT_LOC(uSnrIdx);
    psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];    
    
    /*clear ML input every time */
    for(uIdx=0u; uIdx < USS_BLOCKAGE_RF_N_FEATURES; uIdx++)
    {
        aBlockageInput[uIdx] = ZERO;
    }
    
    /* Blockage is not execute for NFD frames
       or if the sensor was not fired*/
    if (((psSnrMeasRec->uSendingSensors & uBitMap) != ZERO) &&
        (psSensorRec->eEchoTypeRequested != US_E_REQ_SEND_NFD) &&
        (psSensorRec->sRingTime.uDrvFreq > ZERO))
    {
        aBlockageInput[ZERO] = USSMgr_BlockageGet1stDistance(uSnrIdx);
        aBlockageInput[ONE] = psSensorRec->sRingTime.uRingTime;
        aBlockageInput[TWO] = USSMgr_BlockageGetRingTimeVar(uSnrIdx, aBlockageInput[1]);
        aBlockageInput[THREE] = psSensorRec->sRingTime.uRingFreq;
        aBlockageInput[FOUR] = USSMgr_BlockageGetEchoType(psSensorRec);
        aBlockageInput[FIVE] = USSMgr_BlockageGetSensorType(uSnrIdx);
        aBlockageInput[SIX]  = USSMgr_BlockageGetSnremperature(uSnrIdx);
        bCheckSnr = ME_TRUE;
    }  
    else    {/*DO NOTHING*/    }  
    /*minimum inputs required to Execute Blockage ML are: RingTime and RingFrequency*/
    if(( aBlockageInput[ONE] == ZERO) || ( aBlockageInput[THREE] == ZERO) )
    {
        bCheckSnr = ME_FALSE;
    }
    else    {/*DO NOTHING*/    }
    #ifdef USS_SIM_DBUG
    for(uint8_t i=0; i< USS_BLOCKAGE_RF_N_FEATURES; i++)
    {
        gBlockageInput[uSnrIdx][i] = aBlockageInput[i];
    }
    #endif
    
    return bCheckSnr;
}

/* ===========================================================================
* \brief Apply an alpha filter to the frame prediction and clear or set the blockage
 * flag if the hysteresis thresholds are met
  * \param uSnrIdx uint8_t Sensor Idx 0 to 12
  * \param uPprediction uint8_t frame prediction for blockage

 * \return  bool_t Succesfull Sensor Input TRUE, Inputs not correctly loaded FALSE
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_BlockageFilteredDecision
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
static void USSMgr_BlockageFilteredDecision(const uint8_t uSnrIdx, const uint8_t uPrediction)
{
    float32_t uPred;
    /*group blockage classes: Mud, Ice, Snow into a binary group:
    Blockage or No Blockage*/
    if(uPrediction >= ONE)
    {
        uPred = 1.0f;
    }
    else
    {
        uPred = 0.0f;
    }
    /*filter the frame prediction*/
    afBlockageFilterBuffer[uSnrIdx] = exp_moving_avg(afBlockageFilterBuffer[uSnrIdx], (float32_t)uPred, USS_BLOCKAGE_RF_POSTIVE_THRESHOLDS);
    /*add additional filtering to the filtered predicition to lower FPs
    due to toggling signal*/
    if  (  afBlockageFilterBuffer[uSnrIdx] < USS_BLOCKAGE_LOWER_ALPHA_TH ) 
    {
        auBlockage[uSnrIdx] = ZERO;
        US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_BLOCKAGE, uSnrIdx);        
        auBlockageCtr[uSnrIdx] = ZERO;
    }
    else    {/*DO NOTHING*/    }

    if (afBlockageFilterBuffer[uSnrIdx] >= USS_BLOCKAGE_UPPER_ALPHA_TH)
    {        
        if( auBlockageCtr[uSnrIdx] > USS_BLOCKAGE_MAX_CTR_TH )
        {
            US_Diagnostic_SetSnrFaultFlagByIdx(SNR_DIAG_FLG_SNR_BLOCKAGE, uSnrIdx);
            auBlockage[uSnrIdx] = ONE;   
            auBlockageCtr[uSnrIdx] = USS_BLOCKAGE_MAX_CTR_TH;     
        }
        else
        {
            auBlockageCtr[uSnrIdx]++;
        }
    }
    else
    {               
        auBlockageCtr[uSnrIdx] = ZERO;        
    }
    
}


/* ===========================================================================
* \brief Main Interface Function for the Random Forest Blockage
 *
 * \param None

 * \return  None
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_BlockageEstimationNN
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
void USSMgr_BlockageEstimationNN(void)
{
    uint8_t uPprediction;
    uint8_t uSnrIdx;    
    uint16_t aBlockageInput[USS_BLOCKAGE_RF_N_FEATURES];
    bool_t b_checkBlockage;
        
    #if ( BLOCKAGE_DEBUG == ME_TRUE)
    (void)memset(&auBlockageCalled, 0, sizeof(uint8_t) * US_D_MAX_NUM_SENSORS);    
    #endif
    /*run Blockage logic for every sensor*/
    for( uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
    {
        /*1. Get Blockage Inputs*/
        b_checkBlockage = USSMgr_BlockageEstimationNN_Input(uSnrIdx, aBlockageInput);
            
        if ((bool_t)ME_TRUE == b_checkBlockage )
        {
            /*2. single frame prediction*/
            uPprediction = USSMgr_Block_PredictTree(&uss_blockage_model, ZERO, aBlockageInput); 
            /*3. Final blockage decision and Clear/Set fault condition*/
            USSMgr_BlockageFilteredDecision(uSnrIdx, uPprediction);
            #if ( BLOCKAGE_DEBUG == ME_TRUE)
                auBlockageCalled[uSnrIdx] =1;
                auPrediction[uSnrIdx] = uPprediction;
            #endif
        }
        else    {/*DO NOTHING*/    }
    }    
}

/* ===========================================================================
* \brief Main Interface Function to init  internal variables for the Random Forest Blockage
 *
 * \param None

 * \return  None
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_InitBlockageEstimationNN
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
void USSMgr_InitBlockageEstimationNN(void)
{    
    (void)memset(&auBlockage, 0, sizeof(uint8_t) * US_D_MAX_NUM_SENSORS);    
    (void)memset(&auBlockageCtr, 0, sizeof(uint8_t) * US_D_MAX_NUM_SENSORS);    
    (void)memset(&afBlockageFilterBuffer, 0, sizeof(float32_t) * US_D_MAX_NUM_SENSORS);    
    (void)memset(&fBlockageStatus, 0, sizeof(float32_t) * TWO*US_D_MAX_NUM_SENSORS);    
    
#if ( BLOCKAGE_DEBUG == ME_TRUE)
    (void)memset(&auBlockageCalled, 0, sizeof(uint8_t) * US_D_MAX_NUM_SENSORS);    
    (void)memset(&auPrediction, 0, sizeof(uint8_t) * US_D_MAX_NUM_SENSORS);    
#endif
}

#if ( BLOCKAGE_DEBUG == ME_TRUE)
/* ===========================================================================
* \brief Retriever function to get the debug variable for the alpha filter 
* model
 *
 * \param None

 * \return  None
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_InitBlockageEstimationNN
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
float32_t USSMgr_BlockageGeAlphaFilterVal( const uint8_t uSnrIdx)
{
    return  afBlockageFilterBuffer[uSnrIdx];
}

/* ===========================================================================
* \brief Retriever function to get the debug variables for Blockage internal state
 *
 * \param uDbgID: BLOCKAGE_FILTERED_FLAG, BLOCKAGE_FRAME_PREDICTION, BLOCKAGE_CALLED_FLAG
 *  uSnrIdx uint8_t Sensor Idx 0 to 12
 * \return  uint8_t
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_InitBlockageEstimationNN
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/
uint8_t USSMgr_BlockageGetDbgVar(const USSMgr_E_BlockageVars_t uDbgID, const uint8_t uSnrIdx)
{
    uint8_t uRet;
    switch (uDbgID)
    {
    case BLOCKAGE_FILTERED_FLAG:
        uRet = auBlockage[uSnrIdx];
        break;
    case BLOCKAGE_FRAME_PREDICTION:
        uRet = auPrediction[uSnrIdx];
        break;
    case BLOCKAGE_CALLED_FLAG:
        uRet = auBlockageCalled[uSnrIdx];
        break;    
    case BLOCKAGE_COUNTER:
        uRet = auBlockageCtr[uSnrIdx];
        break;
    default:
        uRet=ZERO;
        break;
    }
    return uRet;
}
#endif

/* ===========================================================================
* \brief Retriever function to get the Active Blockage Flag
 *
 * \param None
 * \return  uint8_t
 * \remarks 
 */
/* ===========================================================================
 * Name:	 USSMgr_BlockageGetActiveFlag
 * Remarks:  
 * Req.-ID: 
 * ===========================================================================*/

uint8_t USSMgr_BlockageGetActiveFlag(void)
{
    return ME_TRUE;
}
