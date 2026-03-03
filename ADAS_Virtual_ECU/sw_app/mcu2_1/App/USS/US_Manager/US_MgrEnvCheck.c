/*
 * US_MgrEnvCheck.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */
/*PRQA S 0816 ++ */
/*PRQA S 1011, 0857,1030, 0776 ++ */
/* PRQA S 4461++*/ /*Expected value fits  within the converted range */
/* PRQA S 1860 ++ */ /* Generated value is og unsigned type*/
/* PRQA S 0292 ++ */ /*Special characters in comments have no functional impact */

#include "US_ME_Typedefs_Global.h"
#include "US_MgrEnvCheck.h"
#include "US_MgrInterface.h"
/*#include "US_ComInputBuffer_Global.h"*/
#include "US_MgrBlockage.h"
#include "US_MgrFilter.h"
#include "US_MgrSensorProc.h"
#include "US_SysMgr_Global.h"

#define aUSS_D_LogWarning(...) \
    do{}while(0)
        
#define US_D_UNSURE_CNT_MAX     15u
#define US_D_UNSURE_HIGH_INC    10u
#define US_D_UNSURE_LOW_INC     8u
#define US_D_UNSURE_NONE_DEC    1u

#define US_D_NOISE_HMI_RANGE    300u
#define US_D_NOISE_UNREALISTIC_ECHO_ADC 200u
#define US_D_NOISE_POINT_THRESHOLD  140u  /*for no chirp?*/
#define US_D_LOW_NOISE_POINT_THRESHOLD 1u
/*#define US_D_NOISE_POINT_THRESHOLD  90u*/
#define VERY_LOW_BG_NOISE_DIST 350u /*175u*/
#define VERY_LOW_BG_NOISE_HEIGHT 35u

/* Internal Var */
static US_S_AllSnrNoiseData_t UssMgr_AllSnrNoiseData;
static US_S_AllSnrNoiseEchoHistory_t  UssMgr_AllSnrNoiseHistory;
static US_S_AllSnrChirpTypeHist_t  UssMgr_AllSnrChirpTypeHist;
/* Internal Functions */
static void DecUnsureCounter(uint8_t SensorIndex, uint8_t Amount);
static void IncUnsureCounter(uint8_t SensorIndex, uint8_t Amount);
static void NoiseBufferAddData(uint8_t Sensor_Index, uint16_t EchoDistance, uint16_t EchoHeight, US_E_EchoType_t EchoType);
static US_E_NoiseLevel_t CalcAvgNoise(uint8_t Sensor_Index);
static void GatherNoiseData(uint8_t Sensor_Index);
static US_E_NoiseType_t GuessNoiseChirpType(uint8_t Sensor_Index, bool_t bSomeEchoes);

/* globals for CVADAS debug */
static uint8_t UssGlo_UnsureCntMax = US_D_UNSURE_CNT_MAX;
uint8_t UssGlo_UnsureHighInc = US_D_UNSURE_HIGH_INC;
uint8_t UssGlo_UnsureLowInc = US_D_UNSURE_LOW_INC;
uint8_t UssGlo_UnsureNoneDec = US_D_UNSURE_NONE_DEC;

uint16_t UssGlo_NoiseHMIRange = US_D_NOISE_HMI_RANGE;
uint8_t UssGlo_NoiseUnreal = US_D_NOISE_UNREALISTIC_ECHO_ADC;
uint16_t UssGlo_NoiseThres = US_D_NOISE_POINT_THRESHOLD;
uint16_t UssGlo_LowNoiseThres = US_D_LOW_NOISE_POINT_THRESHOLD;

US_E_EchoType_t UssDBG_EchoType[US_D_MAX_NUM_SENSORS];
uint8_t         UssDBG_GuessChoice[US_D_MAX_NUM_SENSORS];
uint16_t        UssDBG_NumListenEchoes;

/*
 * Internal Functions start
 */
/* ===========================================================================
 * Name:	 IncUnsureCounter
 * Remarks:  DD-ID: {BF29092A-0F83-4db1-BC41-E94D31674F7C}
 * Req.-ID:
 * ===========================================================================*/
static void IncUnsureCounter(uint8_t SensorIndex, uint8_t Amount)
{
    if ((UssMgr_AllSnrNoiseData.sSnrNoiseData[SensorIndex].uUnsureCounter + Amount) < UssGlo_UnsureCntMax)
    {
        UssMgr_AllSnrNoiseData.sSnrNoiseData[SensorIndex].uUnsureCounter += Amount;
    }
    else
    {
        UssMgr_AllSnrNoiseData.sSnrNoiseData[SensorIndex].uUnsureCounter = UssGlo_UnsureCntMax;
    }
}
/* ===========================================================================
 * Name:	 DecUnsureCounter
 * Remarks:  DD-ID: {D26F3A57-8292-4499-A2B4-45E1B131AC7F}
 * Req.-ID:
 * ===========================================================================*/

static void DecUnsureCounter(uint8_t SensorIndex, uint8_t Amount)
{
    /* normal underflow checks aren't working, even with signed numbers...
     * I give up, using another method
     */
    uint8_t tempval;

    tempval = UssMgr_AllSnrNoiseData.sSnrNoiseData[SensorIndex].uUnsureCounter;
    if( Amount > tempval)
    {
        UssMgr_AllSnrNoiseData.sSnrNoiseData[SensorIndex].uUnsureCounter = ZERO;
    }
    else
    {
        tempval = tempval - Amount;
        UssMgr_AllSnrNoiseData.sSnrNoiseData[SensorIndex].uUnsureCounter = tempval;
    }
}
/* ===========================================================================
 * Name:	 NoiseBufferAddData
 * Remarks:  DD-ID: {8FE73B9C-297B-4576-94F3-1540436349C8}
 * Req.-ID:
 * ===========================================================================*/

/* noise buffer handlers */
static void NoiseBufferAddData(uint8_t Sensor_Index, uint16_t EchoDistance, uint16_t EchoHeight, US_E_EchoType_t EchoType)
{
    uint8_t uCircleBufIdx;

    if(EchoType == US_E_FIXED)
    {
        /*move index*/
        uCircleBufIdx = UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[Sensor_Index].uBufIndex;
        uCircleBufIdx++;
        if (uCircleBufIdx >= US_D_APP_MAX_NOISE_ECHO_BUFF)
        {
            uCircleBufIdx = ZERO;
        }
    
        /*add data*/
        UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[Sensor_Index].uNoiseDistBuf[uCircleBufIdx] = EchoDistance;
        UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[Sensor_Index].uNoiseHeightBuf[uCircleBufIdx] = EchoHeight;
        //UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[Sensor_Index].eEchoTypeBuf[uCircleBufIdx] = EchoType;
    
        /*save index*/
        UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[Sensor_Index].uBufIndex = uCircleBufIdx;
    }
    if ( (EchoType == US_E_CHIRP_DOWN) || (EchoType == US_E_CHIRP_UP) )
    {
        /*move index*/
        uCircleBufIdx = UssMgr_AllSnrChirpTypeHist.sSnrChirpTypeHist[Sensor_Index].uBufIndex;
        uCircleBufIdx++;
        if (uCircleBufIdx >= US_D_APP_MAX_CHIRP_TYPE_BUFF)
        {
            uCircleBufIdx = ZERO;
        }
    
        /*add data*/
        UssMgr_AllSnrChirpTypeHist.sSnrChirpTypeHist[Sensor_Index].eEchoTypeBuf[uCircleBufIdx] = EchoType;
    
        /*save index*/
        UssMgr_AllSnrChirpTypeHist.sSnrChirpTypeHist[Sensor_Index].uBufIndex = uCircleBufIdx;
    }
    else
    {
        /* Should not be here... */
    }
}

/* ===========================================================================
 * Name:	 CalcAvgNoise
 * Remarks:  DD-ID: {C5888CA4-E984-43ef-8390-548E0DE54198}
 * Req.-ID:
 * ===========================================================================*/

static US_E_NoiseLevel_t CalcAvgNoise(uint8_t Sensor_Index)
{
    uint32_t uAvgHeight;
    uint32_t uAvgDist;
    uint16_t uNoisePoints;
    uint8_t uCircleBufIdx;
    US_E_NoiseLevel_t eRet_NoiseLevel;
    
    eRet_NoiseLevel = US_E_NOISELEVEL_NONE;
    uNoisePoints = ZERO;
    uAvgHeight = ZERO;
    uAvgDist = ZERO;
    
    /*for loop - get all uNoiseDistBuf and avg to max US_D_APP_MAX_NOISE_ECHO_BUFF*/
    /*same for noise height*/
    for (uCircleBufIdx = ZERO; uCircleBufIdx < US_D_APP_MAX_NOISE_ECHO_BUFF; uCircleBufIdx++)
    {
        uAvgDist += UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[Sensor_Index].uNoiseDistBuf[uCircleBufIdx];
        uAvgHeight += UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[Sensor_Index].uNoiseHeightBuf[uCircleBufIdx];
    }
    uAvgDist = uAvgDist / US_D_APP_MAX_NOISE_ECHO_BUFF;
    uAvgHeight = uAvgHeight / US_D_APP_MAX_NOISE_ECHO_BUFF;
    
    /*TODO - decide on logic*/ 
    /*temp bypass of avg for dist, not looking good in tests*/
    uAvgDist = UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[Sensor_Index].uNoiseDistBuf[UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[Sensor_Index].uBufIndex];

    if (uAvgDist > UssGlo_NoiseHMIRange)
    {
        uNoisePoints = uNoisePoints + 50u;  /*Magic number are used*/
    }
    else
    {
        uNoisePoints = uNoisePoints + UssGlo_NoiseThres; /* PRQA S 4434 ++ */ /*Magic number are used*/
    }
    
    if (uAvgHeight > UssGlo_NoiseUnreal)
    {
        uNoisePoints = uNoisePoints + UssGlo_NoiseThres;
    }
    else
    {
        uNoisePoints = uNoisePoints + (uAvgHeight/2u);
    }
    
    if( (uAvgDist > VERY_LOW_BG_NOISE_DIST) && (uAvgHeight < VERY_LOW_BG_NOISE_HEIGHT) )
    {
        /*not sure how to properly calculate noise points*/
        uNoisePoints = 0;
    }

    if (uNoisePoints > UssGlo_NoiseThres) /*enough points to be high noise*/
    {
        eRet_NoiseLevel = US_E_NOISELEVEL_HIGH;
    }
    else if (uNoisePoints > UssGlo_LowNoiseThres)
    {
        eRet_NoiseLevel = US_E_NOISELEVEL_LOW;
    }
    else
    {
    	eRet_NoiseLevel = US_E_NOISELEVEL_NONE;
    	/*eRet_NoiseLevel = US_E_NOISELEVEL_VERY_LOW;*/
    }
    
    return eRet_NoiseLevel;
}

/* ===========================================================================
 * Name:	 GuessNoiseChirpType
 * Remarks:  DD-ID: {0069D86B-F771-45b3-9CA4-84EFA00B4F44}
 * Req.-ID:
 * Notes: Will set eNoiseTypeGuess directly
 * ===========================================================================*/
static US_E_NoiseType_t GuessNoiseChirpType(uint8_t Sensor_Index, bool_t bSomeEchoes)
{
    uint8_t uCurCircleBufIdx;
    uint8_t uPrevCircleBufIdx;
    US_E_EchoType_t  eCurEchoType;
    US_E_NoiseType_t eNewNoiseType;
    US_E_NoiseType_t eCurNoiseType;
    bool_t  bTakeCurrentType = ME_FALSE;
    bool_t  bWeakenGuess = ME_FALSE;
    bool_t  bSetWeakGuess = ME_FALSE; /* these three should be 1 var... */

    eCurNoiseType = UssMgr_AllSnrNoiseData.sSnrNoiseData[Sensor_Index].eNoiseTypeGuess;

    /* Decide what to do */
    if((bool_t)ME_FALSE == bSomeEchoes) /* no noise detected */
    {
        bWeakenGuess = ME_TRUE;
        //eNewNoiseType = US_E_NOISETYPE_GENERIC;
        UssDBG_EchoType[Sensor_Index] = US_E_NOECHO;
        UssDBG_GuessChoice[Sensor_Index] = 0x01;
    }
    else
    {
        /* get the cur and prev history index */
        uCurCircleBufIdx = UssMgr_AllSnrChirpTypeHist.sSnrChirpTypeHist[Sensor_Index].uBufIndex;
        eCurEchoType = UssMgr_AllSnrChirpTypeHist.sSnrChirpTypeHist[Sensor_Index].eEchoTypeBuf[uCurCircleBufIdx];
        UssDBG_EchoType[Sensor_Index] = eCurEchoType;
        if(ZERO != uCurCircleBufIdx)
        {
            uPrevCircleBufIdx = uCurCircleBufIdx - ONE;
        }
        else
        {
            uPrevCircleBufIdx = US_D_APP_MAX_CHIRP_TYPE_BUFF - ONE;
        }
        
        if (eCurEchoType == UssMgr_AllSnrChirpTypeHist.sSnrChirpTypeHist[Sensor_Index].eEchoTypeBuf[uPrevCircleBufIdx])
        {
            /* easy case, they match. Overwrite anything prev */
            //eNewNoiseType = UssMgr_AllSnrChirpTypeHist.sSnrNoiseHistory[Sensor_Index].eEchoTypeBuf[uCurCircleBufIdx];
            bTakeCurrentType = ME_TRUE;
            UssDBG_GuessChoice[Sensor_Index] = 0x02;
        }
        else
        {
            bSetWeakGuess = ME_TRUE;
            UssDBG_GuessChoice[Sensor_Index] = 0x03;
        }
    }
    
    /* Make changes based on decisions */
    if ((bool_t)ME_TRUE == bSetWeakGuess)
    {
        switch (eCurEchoType)
        {
            case US_E_CHIRP_DOWN:
                eNewNoiseType = US_E_NOISETYPE_WEAK_DOWN;
                break;
            case US_E_CHIRP_UP:
                eNewNoiseType = US_E_NOISETYPE_WEAK_UP;
                break;
            case US_E_FIXED:
            default:
                /* Don't make any changes */
                eNewNoiseType = eCurNoiseType;
                break;
        }
    }

    if ((bool_t)ME_TRUE == bWeakenGuess)
    {
        if(US_E_NOISETYPE_STRONG_UP == eCurNoiseType)
        {
            /* do enum math in case I add more layers */
            eNewNoiseType = (US_E_NoiseType_t)((sint8_t)eCurNoiseType - ONE);
        }
        if(US_E_NOISETYPE_STRONG_DOWN == eCurNoiseType)
        {
            eNewNoiseType = (US_E_NoiseType_t)((sint8_t)eCurNoiseType + (sint8_t)ONE);
        }
        /* intentionally not changing any weak to generic */
    }

    if ((bool_t)ME_TRUE == bTakeCurrentType)
    {
        switch (eCurEchoType)
        {
            case US_E_CHIRP_DOWN:
                eNewNoiseType = US_E_NOISETYPE_STRONG_DOWN;
                break;
            case US_E_CHIRP_UP:
                eNewNoiseType = US_E_NOISETYPE_STRONG_UP;
                break;
            case US_E_FIXED:
            default:
                eNewNoiseType = US_E_NOISETYPE_GENERIC;
                break;
        }
    }

    return eNewNoiseType;
}

/* ===========================================================================
 * Name:	 GatherNoiseData
 * Remarks:  DD-ID: {DCB77D70-4418-4ec9-B53D-93E320792BCE}
 * Req.-ID:
 * ===========================================================================*/
static void GatherNoiseData(uint8_t Sensor_Index)
{
    uint16_t uNoiseDist, uNoiseHeight;
    uint8_t uEchoIdx;
    US_E_EchoType_t eEchoType;
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    const US_S_SensorRec_t  *psSensorRec;
    const US_S_SnrCalcs_t *psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    const US_S_SnrCalcRec_t *psSnrCalcRec;
    
    if(Sensor_Index < US_D_MAX_NUM_SENSORS)
    {
        psSensorRec = &psSnrMeasRec->sSensorRec[Sensor_Index];
        psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[Sensor_Index];
        
        for(uEchoIdx = 0; uEchoIdx < psSnrCalcRec->uNumEchoes; uEchoIdx++)
        {
            eEchoType = psSensorRec->sEcho[uEchoIdx].eEchoType;
            switch(eEchoType)
            {
                case US_E_NFD:
                {
                    /*do nothing*/
                    break;
                }

                case US_E_FIXED:
                case US_E_CHIRP_DOWN:
                case US_E_CHIRP_UP:
                default:
                {
                    /*psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm*/
                    uNoiseDist = psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm >> ONE;
                    uNoiseHeight = psSensorRec->sEcho[psSnrCalcRec->sEchoCalc[uEchoIdx].uRecEchoIndex].uEchoHeight;
                    NoiseBufferAddData(Sensor_Index, uNoiseDist, uNoiseHeight, eEchoType);
                    break;
                }
            }
        }
    }
}

/*
 * Public function start
 */
/* ===========================================================================
 * Name:	 UssMgr_CheckEnvironmentNoise
 * Remarks:  DD-ID: {70D4E2DF-66C2-4806-B450-D7790EF4CC14}
 * ===========================================================================*/
void UssMgr_CheckEnvironmentNoise(void)
{
    uint8_t uSnrIdx;
    /*uint8_t uEchoIdx;*/
    bool_t bNoiseChecked;
    US_E_NoiseLevel_t eNoiseGuessPerSnr[US_D_MAX_NUM_SENSORS] = {US_E_NOISELEVEL_NONE};
    /*const US_S_SnrCalcRec_t *psSnrCalcRec;*/
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    const US_S_SnrCalcs_t *psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    US_E_NoiseCheckType_t eNoiseCheckType = UssMgr_GetNoiseCheckType();

    UssDBG_NumListenEchoes = ZERO;
    
    bNoiseChecked = ME_FALSE;
    /* Check if we are in ALL silence step or normal step */
    if ( (psSnrMeasRec->uSendingSensors == ZERO) && (eNoiseCheckType == NOISE_CHECK_FIXED) )
    {
        /* Check noise during entire system silence window */
        /*psSnrCalcRec = UssMgr_psGetCurSnrCalcsRec()->sSnrCalcRec[uSnrIdx];*/
        
        for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     /* Scan all sensor positions*/
        {
            const US_S_SensorRec_t  *psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
            
            if ( psSensorRec->sRingTime.uRingTime > ZERO )
            {
                /*this should be false... */
                /*ASSERT(TRUE);*/
                /*TODO jwr flag debug*/
            }
            else
            {
                /*set initial guess*/
                eNoiseGuessPerSnr[uSnrIdx] = US_E_NOISELEVEL_NONE;
            }
            
            if ( psSnrCalcs->sSnrCalcRec[uSnrIdx].uNumEchoes > ZERO )
            {
                /*already a bad sign for noise*/
                eNoiseGuessPerSnr[uSnrIdx] = US_E_NOISELEVEL_LOW;
                
                /*check echo details to see if it gets worse*/
                GatherNoiseData(uSnrIdx);
                eNoiseGuessPerSnr[uSnrIdx] = CalcAvgNoise(uSnrIdx);
            }
            UssDBG_NumListenEchoes = UssDBG_NumListenEchoes + psSnrCalcs->sSnrCalcRec[uSnrIdx].uNumEchoes;
        }
        bNoiseChecked = ME_TRUE;
    }
    else if ( (psSnrMeasRec->uSendingSensors == ZERO) && (eNoiseCheckType == NOISE_CHECK_CHIRP) )
    {
        for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     /* Scan all sensor positions*/
        {
            const US_S_SensorRec_t  *psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
            if ( psSnrCalcs->sSnrCalcRec[uSnrIdx].uNumEchoes > ZERO )
            {
                GatherNoiseData(uSnrIdx);
                UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eNoiseTypeGuess = GuessNoiseChirpType(uSnrIdx, ME_TRUE);
            }
            else
            {
                UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eNoiseTypeGuess = GuessNoiseChirpType(uSnrIdx, ME_FALSE);
            }
        }
        /* bNoiseChecked stays false */
    }
    else
    {
        /* TODO check noise for sensor far from sending sensors */
    }
    
    /*
     * process noise flags and history 
     */
    if((bool_t)ME_TRUE == bNoiseChecked)  /*Converted as well as non converted int has same relational operations*/

    {
        for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++) /*uSnrIdx reused*/
        {
            /*result of this check*/
            US_E_NoiseLevel_t eNoisePickedThisSnr = US_E_NOISELEVEL_NONE;
            /*prev - \TODO get avg or something of circle buff*/
            US_E_NoiseLevel_t ePrevNoiseThisSnr = UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eNoiseHistory[ZERO];
            		

            /*\TODO jwr finish logic to take guess and history and make current level*/
           
            {
                /* High this time */
                if( eNoiseGuessPerSnr[uSnrIdx] == US_E_NOISELEVEL_HIGH )
                {
                    /*if( ePrevNoiseThisSnr == US_E_NOISELEVEL_HIGH )*/
                    {
                        /*high again, stay at current level*/
                        IncUnsureCounter(uSnrIdx, UssGlo_UnsureHighInc);
                        if (UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].uUnsureCounter >= UssGlo_UnsureCntMax)
                        {
                            eNoisePickedThisSnr = US_E_NOISELEVEL_HIGH;
                        }
                    }
                }
                /* Low this time */
                else if( eNoiseGuessPerSnr[uSnrIdx] == US_E_NOISELEVEL_LOW )
                {
                    if( ePrevNoiseThisSnr == US_E_NOISELEVEL_HIGH )
                    {
                        /*high before, stay at high level*/
                        //eNoisePickedThisSnr = US_E_NOISELEVEL_HIGH;
                        IncUnsureCounter(uSnrIdx, UssGlo_UnsureLowInc);
                        if (UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].uUnsureCounter >= UssGlo_UnsureCntMax)
                        {
                            eNoisePickedThisSnr = US_E_NOISELEVEL_HIGH;
                        }
                    }
                    else /*if none or low before, low is ok*/
                    {
                        //eNoisePickedThisSnr = US_E_NOISELEVEL_LOW;
                        IncUnsureCounter(uSnrIdx, UssGlo_UnsureLowInc);
                        if (UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].uUnsureCounter >= UssGlo_UnsureCntMax)
                        {
                            eNoisePickedThisSnr = US_E_NOISELEVEL_LOW;
                        }
                    }
                }
                /* None this time */
                else if( eNoiseGuessPerSnr[uSnrIdx] == US_E_NOISELEVEL_NONE )
                {
                    /*noise gone this time.. wait for unsure levels to drop*/
                    DecUnsureCounter(uSnrIdx, UssGlo_UnsureNoneDec);

                    if (UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].uUnsureCounter == ZERO)
                    {
                        eNoisePickedThisSnr = US_E_NOISELEVEL_NONE;
                    }
                    else
                    {
                        /*preserve current level (should be low or high..)*/
                        eNoisePickedThisSnr = UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eCurrentLevel;
                    }
                }
                else
                {
                    /*ASSERT(TRUE);*/
                }
            }

            /*\TODO jwr circle buffer history function*/
            UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eNoiseHistory[ZERO] = eNoiseGuessPerSnr[uSnrIdx];
            		/*UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eCurrentLevel;*/
            /*update global current*/
            UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eCurrentLevel = eNoisePickedThisSnr;
            /* update noise type guess */
            //already done in GuessNoiseType();
        }
    }
    UssMgr_AllSnrNoiseData.bNewNoiseDataAvail = bNoiseChecked;
}

/* ===========================================================================
 * Name:	 UssMgr_GetAllSnrNoiseData
 * Remarks:  DD-ID: {EF8F3AE5-CDC0-4c0a-968A-11557139D9B7}
 * ===========================================================================*/
const US_S_AllSnrNoiseData_t *UssMgr_GetAllSnrNoiseData(void)
{
    return &UssMgr_AllSnrNoiseData;
}
/* ===========================================================================
 * Name:	 UssMgr_GetAllSnrNoiseHistory
 * Remarks:  DD-ID: {F93B1DAB-E01D-4d58-91AA-9C1B24EEAEF5}
 * ===========================================================================*/
const US_S_AllSnrNoiseEchoHistory_t * UssMgr_GetAllSnrNoiseHistory(void)
{
    return &UssMgr_AllSnrNoiseHistory;
}
/* ===========================================================================
 * Name:	 UssMgr_GetAllSnrChirpTypeHist
 * Remarks:  DD-ID: {69F7215B-FA44-460d-B641-7CFB29D5403E}
 * ===========================================================================*/
const US_S_AllSnrChirpTypeHist_t * UssMgr_GetAllSnrChirpTypeHist(void)
{
    return &UssMgr_AllSnrChirpTypeHist;
}

/*===========================================================================
 * \brief Initialize noise algo counts.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssMgr_EnvCheckInit
 * Remarks:  DD-ID: {B7F859BE-2374-4dfc-8A79-6DF452020EC3}
 * ===========================================================================*/
void UssMgr_EnvCheckInit(void)
{
    uint8_t uSnrIdx;
    uint8_t uHistoryIdx;

    /* clear all */
    for(uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++ )
    {
        for(uHistoryIdx = ZERO; uHistoryIdx < US_D_APP_MAX_NOISE_ECHO_BUFF; uHistoryIdx++)
        {
            UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eNoiseHistory[uHistoryIdx] = US_E_NOISELEVEL_NONE;

            UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[uSnrIdx].uNoiseDistBuf[uHistoryIdx] = ZERO;
            UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[uSnrIdx].uNoiseHeightBuf[uHistoryIdx] = ZERO;
            /* comment for now UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[uSnrIdx].eEchoTypeBuf[uHistoryIdx] = US_E_NOECHO; */
        }
        for(uHistoryIdx = ZERO; uHistoryIdx < US_D_APP_MAX_CHIRP_TYPE_BUFF; uHistoryIdx++)
        {
            UssMgr_AllSnrChirpTypeHist.sSnrChirpTypeHist[uSnrIdx].eEchoTypeBuf[uHistoryIdx] = US_E_NOECHO;
        }
        
        UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eCurrentLevel = US_E_NOISELEVEL_NONE;
        UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].uUnsureCounter = ZERO;

        UssMgr_AllSnrNoiseHistory.sSnrNoiseHistory[uSnrIdx].uBufIndex = ZERO;
        UssMgr_AllSnrChirpTypeHist.sSnrChirpTypeHist[uSnrIdx].uBufIndex = ZERO;

        UssMgr_AllSnrNoiseData.sSnrNoiseData[uSnrIdx].eNoiseTypeGuess = US_E_NOISETYPE_GENERIC;
    }
}



/*****************************************************/
/**** Below is all old Taiwan stuff for reference ****/
/*****************************************************/


/*
 * Input: EchoDistance, RingTime
 * Output: Flag_NArrowSpace
 * 1.Check Sensor Ringtime is OK
 * 2.Check EchoDistance longer than Narrow MAX
 * 3.output Flag_NarrowSpace
 * */
#define NarrowMAX     (40)
#define NarrowMIN     (5)
#define NarrowRINGTIME  (5000)
uint8_t aUSSMgr_F_NarrowCheck_testcnt = 0;
#if 0

uint8_t aUSSMgr_F_NarrowCheck(uint8_t is_narrow)
{
    uint8_t idx = 0, idMax = 12, idMin = 0;
    is_narrow = ME_FALSE;
    aUSSMgr_F_NarrowCheck_testcnt++;
  #if 0
    if (aUSS_D_RUNNING_CLUSTER == pUS_E_REAR_ID || aUSS_D_RUNNING_CLUSTER == pUS_E_ALL_ID)
    {
        idMin = 7;
        idMax = 11;
        for (idx = idMin; idx < idMax; idx++)
        {
            if (UssMgr_sInterfaceData.OD_DireDist_pt->DistToSensor_at[idx] < NarrowMAX
                    && UssMgr_sInterfaceData.OD_DireDist_pt->DistToSensor_at[idx] > NarrowMIN)
            {
                is_narrow = ME_TRUE;
            }
            else if (UssMgr_sLegacySnrRecR->SensorRec_at[idx - 6].RingingTime_t.EvRing_u16 > NarrowRINGTIME)
            {
                is_narrow = ME_TRUE;
            }
        }
    }

    if (aUSS_D_RUNNING_CLUSTER == pUS_E_FRONT_ID || aUSS_D_RUNNING_CLUSTER == pUS_E_ALL_ID)
    {
        idMin = 1;
        idMax = 5;
        for (idx = idMin; idx < idMax; idx++)
        {
            if (UssMgr_sInterfaceData.OD_DireDist_pt->DistToSensor_at[idx] < NarrowMAX
                    && UssMgr_sInterfaceData.OD_DireDist_pt->DistToSensor_at[idx] > NarrowMIN)
            {
                is_narrow = ME_TRUE;
            }
            else if (UssMgr_sLegacySnrRecF->SensorRec_at[idx].RingingTime_t.EvRing_u16 > NarrowRINGTIME)
            {
                is_narrow = ME_TRUE;
            }
        }
    }
  #endif
    return is_narrow;
}
#endif

#if 0
void aUSSMgr_F_EnvCheckHandler(void)
{
    uint8 is_narrow = 0;
    switch (UssMgr_sInterfaceData.USSC_EnvStage_CountBackUp)
    {
        case (e_aJobUSSCtrl_CheckNarrowSpace):
        {
            is_narrow = aUSSMgr_F_NarrowCheck(is_narrow);
            if (is_narrow)
            {
                UssMgr_sInterfaceData.USSC_GroundType = pUS_E_NRWSP;
            }
            else
            {
                UssMgr_sInterfaceData.USSC_GroundType = pUS_E_FLAT;
            }
            aJobUSSMgr_NSMode = UssMgr_sInterfaceData.USSC_GroundType;

            break;
        }
        case (e_aJobUSSCtrl_CheckGroundType_1st0rPrfD):
            UssMgr_sInterfaceData.OD_Blockage_SndBurstCnt = 0;
            UssMgr_sInterfaceData.OD_Blockage_AllSnrLockRS = 0;
            UssMgr_sInterfaceData.USSC_Blockage_LockRS = pUS_E_BlockageUnlock;
            UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_NOSND;
            UssMgr_sInterfaceData.OD_Blockage_SingleBlockageRS = pUS_E_NoBlockage;
            UssMgr_sInterfaceData.USSC_GroundType = pUS_E_FLAT;
            UssMgr_sInterfaceData.OD_Blockage_ValidJudge = ME_FALSE;
            for (int i = 0; i < 12; i++)
            {
                UssMgr_sInterfaceData.OD_SingleSnrBlockage[i] = pUS_E_NOUSE;
            }
            break;
        case (e_aJobUSSCtrl_CheckGroundType_1st1rPrfD):
            UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_ODDSNR;
            aUSSMgr_F_SaveSnrRcvData();
            break;
        case (e_aJobUSSCtrl_CheckGroundType):
            UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_EVENSNR;
            aUSSMgr_F_SaveSnrRcvData();
            UssMgr_sInterfaceData.USSC_GroundType = aUSSMgr_F_GroundCheck();
            if (UssMgr_sInterfaceData.USSC_GroundType_ConfirmRocky && UssMgr_sInterfaceData.USSC_GroundType_DiffCnt < BT_GroundTypeDiffLim)
            {
                if (UssMgr_sInterfaceData.USSC_GroundType == pUS_E_ROCKY)
                {
                    if (UssMgr_sInterfaceData.USSC_GroundType_DiffCnt != 0)
                    {
                        UssMgr_sInterfaceData.USSC_GroundType_DiffCnt--;
                    }
                }
                else
                {
                    UssMgr_sInterfaceData.USSC_GroundType_DiffCnt++;
                }
            }
            else if (UssMgr_sInterfaceData.USSC_GroundType_ConfirmRocky && UssMgr_sInterfaceData.USSC_GroundType_DiffCnt >= BT_GroundTypeDiffLim
                    && UssMgr_sInterfaceData.USSC_GroundType == pUS_E_FLAT)
            {
                UssMgr_sInterfaceData.USSC_GroundType_DiffCnt = 0;
                UssMgr_sInterfaceData.USSC_GroundType_ConfirmRocky = ME_FALSE;
                for (int i = 0; i < 12; i++)
                {
                    UssMgr_sInterfaceData.OD_BlockageTrack[i].BlockageTrack_Cnt = 0;
                }
            }
            else if (!UssMgr_sInterfaceData.USSC_GroundType_ConfirmRocky && UssMgr_sInterfaceData.USSC_GroundType == pUS_E_ROCKY)
            {
                UssMgr_sInterfaceData.USSC_GroundType_ConfirmRocky = ME_TRUE;
            }
#if Amazon_Blockage_Log
            if (UssMgr_sInterfaceData.USSC_GroundType == pUS_E_ROCKY)
            {
                aUSS_D_LogWarning("[BLOCKAGE] Ground Type : pUS_E_ROCKY ");
            }
            else
            {
                aUSS_D_LogWarning("[BLOCKAGE] Ground Type : pUS_E_FLAT ");
            }
            aUSS_D_LogWarning("[BLOCKAGE] Confirm Rocky : %d ", UssMgr_sInterfaceData.USSC_GroundType_ConfirmRocky);
            aUSS_D_LogWarning("[BLOCKAGE] Ground type difference count : %d ", UssMgr_sInterfaceData.USSC_GroundType_DiffCnt);
#endif
            break;
        case (e_aJobUSSCtrl_CheckBlockage_3st0rPrfD):
        case (e_aJobUSSCtrl_CheckBlockage_4st0rPrfD):
        case (e_aJobUSSCtrl_CheckBlockage_5st0rPrfD):
        case (e_aJobUSSCtrl_CheckBlockage_6st0rPrfD):
            UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_EVENSNR;
            aUSSMgr_F_SaveSnrRcvData();
            aUSSMgr_F_BlockageCheck(UssMgr_sInterfaceData.USSC_GroundType);
            UssMgr_sInterfaceData.OD_Blockage_SndBurstCnt++;
            break;
        case (e_aJobUSSCtrl_CheckBlockage_2st0rPrfD):
            UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_NOSND;
            break;
        case (e_aJobUSSCtrl_CheckBlockage_2st1rPrfD):
        case (e_aJobUSSCtrl_CheckBlockage_3st1rPrfD):
        case (e_aJobUSSCtrl_CheckBlockage_4st1rPrfD):
        case (e_aJobUSSCtrl_CheckBlockage_5st1rPrfD):
        case (e_aJobUSSCtrl_CheckBlockage_6st1rPrfD):
            UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_ODDSNR;
            aUSSMgr_F_SaveSnrRcvData();
            aUSSMgr_F_BlockageCheck(UssMgr_sInterfaceData.USSC_GroundType);
            break;
        case (e_aJobUSSCtrl_CheckBlockage):
            UssMgr_sInterfaceData.OD_Blockage_ValidJudge = ME_TRUE;
            UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_EVENSNR;
            aUSSMgr_F_SaveSnrRcvData();
            aUSSMgr_F_BlockageCheck(UssMgr_sInterfaceData.USSC_GroundType);
            if (UssMgr_sInterfaceData.OD_Blockage_AllSnrLockRS > 0)
            {
                UssMgr_sInterfaceData.USSC_Blockage_LockRS = pUS_E_BlockageLock;
                UssMgr_sInterfaceData.USSC_GroundType = pUS_E_ROCKY;
            }
            else
            {
                UssMgr_sInterfaceData.USSC_Blockage_LockRS = pUS_E_BlockageUnlock;
                UssMgr_sInterfaceData.USSC_GroundType = pUS_E_FLAT;
            }
            UssMgr_sInterfaceData.OD_Blockage_SndBurstCnt = 0;
            UssMgr_sInterfaceData.OD_Blockage_ValidJudge = ME_FALSE;

#if Amazon_Blockage_Log
            for (int i = 0; i < 12; i++)
            {
                aUSS_D_LogWarning("[BLOCKAGE] Snr[%d].BT_Lock = %d ", i, UssMgr_sInterfaceData.OD_BlockageTrack[i].BlockageTrack_Lock);
                aUSS_D_LogWarning("[BLOCKAGE] Snr[%d].BT_Cnt  = %d ", i, UssMgr_sInterfaceData.OD_BlockageTrack[i].BlockageTrack_Cnt);
            }
            aUSS_D_LogWarning("[BLOCKAGE] SingleBlockageRS = %d ", UssMgr_sInterfaceData.OD_Blockage_SingleBlockageRS);
#endif
            break;
        case (e_aJobUSSCtrl_Check_Finished):
            //Vehicle spped from 0 to >0, it will brake the sequence. Init all of parameter except for blockage information
            UssMgr_sInterfaceData.OD_Blockage_SndBurstCnt = 0;
            UssMgr_sInterfaceData.USSC_GroundType = pUS_E_FLAT;
            UssMgr_sInterfaceData.OD_Blockage_ValidJudge = ME_FALSE;
            UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_NOSND;
            UssMgr_sInterfaceData.OD_Blockage_SingleBlockageRS = pUS_E_NoBlockage;
            for (int i = 0; i < 12; i++)
            {
                UssMgr_sInterfaceData.OD_SingleSnrBlockage[i] = pUS_E_NOUSE;
            }
            break;
        case (e_aJobUSSCtrl_Check_FinalRS):
        default:
            UssMgr_sInterfaceData.USSC_SndSensor = pUS_E_NOSND;
            break;
    }
    if (UssMgr_sInterfaceData.USSC_EnvStage_CountBackUp_pre != e_aJobUSSCtrl_Check_Finished
            || UssMgr_sInterfaceData.USSC_EnvStage_CountBackUp != e_aJobUSSCtrl_Check_Finished)
    {
        MEUssMgr_v_BlockageDebugFlag.Debug_Blockage_7 = ME_TRUE;
        MEUssMgr_v_BlockageDebugFlag.Debug_Blockage_8 = ME_TRUE;
    }
    UssMgr_sInterfaceData.USSC_EnvStage_CountBackUp_pre = UssMgr_sInterfaceData.USSC_EnvStage_CountBackUp;
}
#endif
/*
 * Input: EchoDistance, SendingSensor, Flag_NarrowSpace, EchoHeight
 * Output: GroundType
 * 1.Check Flag_NarrowSpace
 * 2.Check EchoDistance with sendingsensor for direct echo
 * 3.Check EchoHeight for confirm the groundtype
 * 4.output the groundtype
 * */
#if 0
uint8_t aUSSMgr_F_GroundCheck(void)
{
    uint8_t Ground = 0, TotalSnr = 0;
    uint8_t idx = 0, idMax = 12, idMin = 0;
//  if(loc_ground == pUS_E_ROCKY)
//  {
//    return loc_ground;
//  }
    if (aUSS_D_RUNNING_CLUSTER == pUS_E_REAR_ID || aUSS_D_RUNNING_CLUSTER == pUS_E_ALL_ID)
    {
        idMin = 6; //7
        idMax = 11;  //12
        for (idx = idMin; idx <= idMax; idx++)
        {
            if (AllSnrData_TimeDist[idx] > Blockage_CHKGround_DistMIN)
            {
                if (AllSnrData_TimeDist[idx] < Blockage_CHKGround_DistMAX)
                {
                    Ground++;
#if Amazon_Blockage_Log
                    aUSS_D_LogWarning("R GroundCase_1 , Snr%d , GndCnt %d , TimeDist %d , RingTime %d", idx, Ground, AllSnrData_TimeDist[idx],
                            AllSnrData_RingTime[idx]);
#endif
                }
                else
                {
                    if (AllSnrData_RingTime[idx] > Blockage_CHKGround_RingTimeMAX) //Maybe is blockage
                    {
                        Ground++;
#if Amazon_Blockage_Log
                        aUSS_D_LogWarning("R GroundCase_2 , Snr%d , GndCnt %d , TimeDist %d , RingTime %d", idx, Ground, AllSnrData_TimeDist[idx],
                                AllSnrData_RingTime[idx]);
#endif
                    }
                    else
                    {
#if Amazon_Blockage_Log
                        aUSS_D_LogWarning("R ERR_1 , Snr%d , TimeDist %d , RingTime %d", idx, AllSnrData_TimeDist[idx], AllSnrData_RingTime[idx]);
#endif
                    }
                }
            }
            else
            {
                if (AllSnrData_TimeDist[idx] == 0) //no echo
                {
                    if (AllSnrData_RingTime[idx] > Blockage_CHKGround_RingTimeMIN && AllSnrData_TimeDist[idx] < Blockage_CHKGround_DistZeroRingTime) //In normal case, it should be not no echo
                    {
#if Amazon_Blockage_Log
                        aUSS_D_LogWarning("R ERR_2 , Snr%d , TimeDist %d , RingTime %d", idx, AllSnrData_TimeDist[idx], AllSnrData_RingTime[idx]);
#endif
                    }
                    else
                    {
                        Ground++;
#if Amazon_Blockage_Log
                        aUSS_D_LogWarning("R GroundCase_3 , Snr%d , GndCnt %d , TimeDist %d , RingTime %d", idx, Ground, AllSnrData_TimeDist[idx],
                                AllSnrData_RingTime[idx]);
#endif
                    }
                }
                else //Maybe Blockage
                {
                    Ground++;
#if Amazon_Blockage_Log
                    aUSS_D_LogWarning("R GroundCase_4 , Snr%d , GndCnt %d , TimeDist %d , RingTime %d", idx, Ground, AllSnrData_TimeDist[idx],
                            AllSnrData_RingTime[idx]);
#endif
                }
            }
            TotalSnr++;
        }
    }
    if (aUSS_D_RUNNING_CLUSTER == pUS_E_FRONT_ID || aUSS_D_RUNNING_CLUSTER == pUS_E_ALL_ID)
    {
        idMin = 0; //1
        idMax = 5; //6
        for (idx = idMin; idx <= idMax; idx++)
        {
            if (AllSnrData_TimeDist[idx] > Blockage_CHKGround_DistMIN)
            {
                if (AllSnrData_TimeDist[idx] < Blockage_CHKGround_DistMAX)
                {
                    Ground++;
#if Amazon_Blockage_Log
                    aUSS_D_LogWarning("F GroundCase_1 , Snr%d , GndCnt %d , TimeDist %d , RingTime %d", idx, Ground, AllSnrData_TimeDist[idx],
                            AllSnrData_RingTime[idx]);
#endif
                }
                else
                {
                    if (AllSnrData_RingTime[idx] > Blockage_CHKGround_RingTimeMAX) //Maybe is blockage
                    {
                        Ground++;
#if Amazon_Blockage_Log
                        aUSS_D_LogWarning("F GroundCase_2 , Snr%d , GndCnt %d , TimeDist %d , RingTime %d", idx, Ground, AllSnrData_TimeDist[idx],
                                AllSnrData_RingTime[idx]);
#endif
                    }
                    else
                    {
#if Amazon_Blockage_Log
                        aUSS_D_LogWarning("F ERR_1 , Snr%d , TimeDist %d , RingTime %d", idx, AllSnrData_TimeDist[idx], AllSnrData_RingTime[idx]);
#endif
                    }
                }
            }
            else
            {
                if (AllSnrData_TimeDist[idx] == 0) //no echo
                {
                    if (AllSnrData_RingTime[idx] > Blockage_CHKGround_RingTimeMIN && AllSnrData_TimeDist[idx] < Blockage_CHKGround_DistZeroRingTime) //In normal case, it should be not no echo
                    {
#if Amazon_Blockage_Log
                        aUSS_D_LogWarning("F ERR_2 , Snr%d , TimeDist %d , RingTime %d", idx, AllSnrData_TimeDist[idx], AllSnrData_RingTime[idx]);
#endif
                    }
                    else
                    {
                        Ground++;
#if Amazon_Blockage_Log
                        aUSS_D_LogWarning("F GroundCase_3 , Snr%d , GndCnt %d , TimeDist %d , RingTime %d", idx, Ground, AllSnrData_TimeDist[idx],
                                AllSnrData_RingTime[idx]);
#endif
                    }
                }
                else //Maybe Blockage
                {
                    Ground++;
#if Amazon_Blockage_Log
                    aUSS_D_LogWarning("F GroundCase_4 , Snr%d , GndCnt %d , TimeDist %d , RingTime %d", idx, Ground, AllSnrData_TimeDist[idx],
                            AllSnrData_RingTime[idx]);
#endif
                }
            }
            TotalSnr++;
        }
    }
    return Ground >= (Blockage_CHKGround_JudgeCriteria / 12) * TotalSnr ? pUS_E_ROCKY : pUS_E_FLAT;
}
#endif

/*
 * 1.Get temperature data from vehicle
 * if gain =127 ignore using other get average
 * 2.According to the temperature reference table TEMP_GAIN update the delta_gain
 * 3.Sending the delta_gain to sensor to update the gain value before sending burst.
 *  (humidity setting default to 50)
 *  (Temperature default is 23)
 * */

#if 0
#define AIRTEMP_OUTSD_INIT_VALUE         (24.0f)
#define HUMIDITY_OUTSD_INIT_VALUE        (50U)

#define TEMPLOG_MAX 60
#define TEMP_DEFAULT AIRTEMP_OUTSD_INIT_VALUE
#define HUMIDITY_DEFAULT  HUMIDITY_OUTSD_INIT_VALUE//50
static sint8_t aUSSMgr_V_Temp[TEMPLOG_MAX];
static uint8_t aUSSMgr_V_TempLogCnt = 0;
static sint8_t aUSSMgr_V_Temp_AVG = (sint8_t) TEMP_DEFAULT;
static sint16_t aUSSMgr_V_Temp_SUM = (sint16_t) TEMP_DEFAULT;
static bool_t aUSSMgr_V_TempLogFull = ME_FALSE;
static uint8_t aUSSMgr_V_TempCurrCnt = 0;
static sint8_t aUSSMgr_V_TempLast = 0;
static sint8_t aUSSMgr_V_Humi[TEMPLOG_MAX];
static sint8_t aUSSMgr_V_Humi_AVG = HUMIDITY_DEFAULT;
static sint16_t aUSSMgr_V_Humi_SUM = HUMIDITY_DEFAULT;
static sint8_t aUSSMgr_V_HumiLast = 0;


//change temperature table to hum and temp table
#if HUMIDITY_DEFAULT
typedef struct s_MEUssMgr_TempHum_s
{
    uint16_t humi;
    sint8_t temp;
    sint8_t gain;
} S_MEUssMgr_TempHum_t;

//default temp = 23 humi = 50 distance is 2m

const S_MEUssMgr_TempHum_t aUSSMgr_V_Temp_Hum_Table[] =
{
{ 10, -50, -7 },
{ 20, -50, -7 },
{ 30, -50, -7 },
{ 40, -50, -7 },
{ 50, -50, -7 },
{ 60, -50, -7 },
{ 70, -50, -7 },
{ 80, -50, -7 },
{ 90, -50, -7 },
{ 100, -50, -7 },
{ 10, -49, -7 },
{ 20, -49, -7 },
{ 30, -49, -7 },
{ 40, -49, -7 },
{ 50, -49, -7 },
{ 60, -49, -7 },
{ 70, -49, -7 },
{ 80, -49, -7 },
{ 90, -49, -7 },
{ 100, -49, -7 },
{ 10, -48, -7 },
{ 20, -48, -7 },
{ 30, -48, -7 },
{ 40, -48, -7 },
{ 50, -48, -7 },
{ 60, -48, -7 },
{ 70, -48, -7 },
{ 80, -48, -7 },
{ 90, -48, -7 },
{ 100, -48, -7 },
{ 10, -47, -7 },
{ 20, -47, -7 },
{ 30, -47, -7 },
{ 40, -47, -7 },
{ 50, -47, -7 },
{ 60, -47, -7 },
{ 70, -47, -7 },
{ 80, -47, -7 },
{ 90, -47, -7 },
{ 100, -47, -7 },
{ 10, -46, -7 },
{ 20, -46, -7 },
{ 30, -46, -7 },
{ 40, -46, -7 },
{ 50, -46, -7 },
{ 60, -46, -7 },
{ 70, -46, -7 },
{ 80, -46, -7 },
{ 90, -46, -7 },
{ 100, -46, -7 },
{ 10, -45, -7 },
{ 20, -45, -7 },
{ 30, -45, -7 },
{ 40, -45, -7 },
{ 50, -45, -7 },
{ 60, -45, -7 },
{ 70, -45, -7 },
{ 80, -45, -7 },
{ 90, -45, -7 },
{ 100, -45, -7 },
{ 10, -44, -7 },
{ 20, -44, -7 },
{ 30, -44, -7 },
{ 40, -44, -7 },
{ 50, -44, -7 },
{ 60, -44, -7 },
{ 70, -44, -7 },
{ 80, -44, -7 },
{ 90, -44, -7 },
{ 100, -44, -7 },
{ 10, -43, -7 },
{ 20, -43, -7 },
{ 30, -43, -7 },
{ 40, -43, -7 },
{ 50, -43, -7 },
{ 60, -43, -7 },
{ 70, -43, -7 },
{ 80, -43, -7 },
{ 90, -43, -7 },
{ 100, -43, -7 },
{ 10, -42, -7 },
{ 20, -42, -7 },
{ 30, -42, -7 },
{ 40, -42, -7 },
{ 50, -42, -7 },
{ 60, -42, -7 },
{ 70, -42, -7 },
{ 80, -42, -7 },
{ 90, -42, -7 },
{ 100, -42, -7 },
{ 10, -41, -7 },
{ 20, -41, -7 },
{ 30, -41, -7 },
{ 40, -41, -7 },
{ 50, -41, -7 },
{ 60, -41, -7 },
{ 70, -41, -7 },
{ 80, -41, -7 },
{ 90, -41, -7 },
{ 100, -41, -7 },
{ 10, -40, -7 },
{ 20, -40, -7 },
{ 30, -40, -7 },
{ 40, -40, -7 },
{ 50, -40, -7 },
{ 60, -40, -7 },
{ 70, -40, -7 },
{ 80, -40, -7 },
{ 90, -40, -7 },
{ 100, -40, -7 },
{ 10, -39, -7 },
{ 20, -39, -7 },
{ 30, -39, -7 },
{ 40, -39, -7 },
{ 50, -39, -7 },
{ 60, -39, -7 },
{ 70, -39, -7 },
{ 80, -39, -7 },
{ 90, -39, -7 },
{ 100, -39, -7 },
{ 10, -38, -7 },
{ 20, -38, -7 },
{ 30, -38, -7 },
{ 40, -38, -7 },
{ 50, -38, -7 },
{ 60, -38, -7 },
{ 70, -38, -7 },
{ 80, -38, -7 },
{ 90, -38, -7 },
{ 100, -38, -7 },
{ 10, -37, -7 },
{ 20, -37, -7 },
{ 30, -37, -7 },
{ 40, -37, -7 },
{ 50, -37, -7 },
{ 60, -37, -7 },
{ 70, -37, -7 },
{ 80, -37, -7 },
{ 90, -37, -7 },
{ 100, -37, -7 },
{ 10, -36, -7 },
{ 20, -36, -7 },
{ 30, -36, -7 },
{ 40, -36, -7 },
{ 50, -36, -7 },
{ 60, -36, -7 },
{ 70, -36, -7 },
{ 80, -36, -7 },
{ 90, -36, -7 },
{ 100, -36, -7 },
{ 10, -35, -7 },
{ 20, -35, -7 },
{ 30, -35, -7 },
{ 40, -35, -7 },
{ 50, -35, -7 },
{ 60, -35, -7 },
{ 70, -35, -7 },
{ 80, -35, -7 },
{ 90, -35, -7 },
{ 100, -35, -7 },
{ 10, -34, -7 },
{ 20, -34, -7 },
{ 30, -34, -7 },
{ 40, -34, -7 },
{ 50, -34, -7 },
{ 60, -34, -7 },
{ 70, -34, -7 },
{ 80, -34, -7 },
{ 90, -34, -7 },
{ 100, -34, -7 },
{ 10, -33, -7 },
{ 20, -33, -7 },
{ 30, -33, -7 },
{ 40, -33, -7 },
{ 50, -33, -7 },
{ 60, -33, -7 },
{ 70, -33, -7 },
{ 80, -33, -7 },
{ 90, -33, -7 },
{ 100, -33, -7 },
{ 10, -32, -7 },
{ 20, -32, -7 },
{ 30, -32, -7 },
{ 40, -32, -7 },
{ 50, -32, -7 },
{ 60, -32, -7 },
{ 70, -32, -7 },
{ 80, -32, -7 },
{ 90, -32, -7 },
{ 100, -32, -7 },
{ 10, -31, -7 },
{ 20, -31, -7 },
{ 30, -31, -7 },
{ 40, -31, -7 },
{ 50, -31, -7 },
{ 60, -31, -7 },
{ 70, -31, -7 },
{ 80, -31, -7 },
{ 90, -31, -7 },
{ 100, -31, -7 },
{ 10, -30, -7 },
{ 20, -30, -7 },
{ 30, -30, -7 },
{ 40, -30, -7 },
{ 50, -30, -7 },
{ 60, -30, -7 },
{ 70, -30, -7 },
{ 80, -30, -7 },
{ 90, -30, -7 },
{ 100, -30, -7 },
{ 10, -29, -7 },
{ 20, -29, -7 },
{ 30, -29, -7 },
{ 40, -29, -7 },
{ 50, -29, -7 },
{ 60, -29, -7 },
{ 70, -29, -7 },
{ 80, -29, -7 },
{ 90, -29, -7 },
{ 100, -29, -7 },
{ 10, -28, -7 },
{ 20, -28, -7 },
{ 30, -28, -7 },
{ 40, -28, -7 },
{ 50, -28, -7 },
{ 60, -28, -7 },
{ 70, -28, -7 },
{ 80, -28, -7 },
{ 90, -28, -7 },
{ 100, -28, -7 },
{ 10, -27, -7 },
{ 20, -27, -7 },
{ 30, -27, -7 },
{ 40, -27, -7 },
{ 50, -27, -7 },
{ 60, -27, -7 },
{ 70, -27, -7 },
{ 80, -27, -7 },
{ 90, -27, -7 },
{ 100, -27, -7 },
{ 10, -26, -7 },
{ 20, -26, -7 },
{ 30, -26, -7 },
{ 40, -26, -7 },
{ 50, -26, -7 },
{ 60, -26, -7 },
{ 70, -26, -7 },
{ 80, -26, -7 },
{ 90, -26, -7 },
{ 100, -26, -7 },
{ 10, -25, -7 },
{ 20, -25, -7 },
{ 30, -25, -7 },
{ 40, -25, -7 },
{ 50, -25, -7 },
{ 60, -25, -7 },
{ 70, -25, -7 },
{ 80, -25, -7 },
{ 90, -25, -7 },
{ 100, -25, -7 },
{ 10, -24, -7 },
{ 20, -24, -7 },
{ 30, -24, -7 },
{ 40, -24, -7 },
{ 50, -24, -7 },
{ 60, -24, -7 },
{ 70, -24, -7 },
{ 80, -24, -7 },
{ 90, -24, -7 },
{ 100, -24, -7 },
{ 10, -23, -7 },
{ 20, -23, -7 },
{ 30, -23, -7 },
{ 40, -23, -7 },
{ 50, -23, -7 },
{ 60, -23, -7 },
{ 70, -23, -7 },
{ 80, -23, -7 },
{ 90, -23, -7 },
{ 100, -23, -7 },
{ 10, -22, -7 },
{ 20, -22, -7 },
{ 30, -22, -7 },
{ 40, -22, -7 },
{ 50, -22, -7 },
{ 60, -22, -7 },
{ 70, -22, -7 },
{ 80, -22, -7 },
{ 90, -22, -7 },
{ 100, -22, -7 },
{ 10, -21, -7 },
{ 20, -21, -7 },
{ 30, -21, -7 },
{ 40, -21, -7 },
{ 50, -21, -7 },
{ 60, -21, -7 },
{ 70, -21, -7 },
{ 80, -21, -7 },
{ 90, -21, -7 },
{ 100, -21, -7 },
{ 10, -20, -7 },
{ 20, -20, -7 },
{ 30, -20, -7 },
{ 40, -20, -7 },
{ 50, -20, -7 },
{ 60, -20, -7 },
{ 70, -20, -7 },
{ 80, -20, -7 },
{ 90, -20, -7 },
{ 100, -20, -7 },
{ 10, -19, -7 },
{ 20, -19, -7 },
{ 30, -19, -7 },
{ 40, -19, -7 },
{ 50, -19, -7 },
{ 60, -19, -7 },
{ 70, -19, -7 },
{ 80, -19, -7 },
{ 90, -19, -7 },
{ 100, -19, -7 },
{ 10, -18, -7 },
{ 20, -18, -7 },
{ 30, -18, -7 },
{ 40, -18, -7 },
{ 50, -18, -7 },
{ 60, -18, -7 },
{ 70, -18, -7 },
{ 80, -18, -7 },
{ 90, -18, -7 },
{ 100, -18, -7 },
{ 10, -17, -7 },
{ 20, -17, -7 },
{ 30, -17, -7 },
{ 40, -17, -7 },
{ 50, -17, -7 },
{ 60, -17, -7 },
{ 70, -17, -7 },
{ 80, -17, -7 },
{ 90, -17, -7 },
{ 100, -17, -7 },
{ 10, -16, -7 },
{ 20, -16, -7 },
{ 30, -16, -7 },
{ 40, -16, -7 },
{ 50, -16, -7 },
{ 60, -16, -7 },
{ 70, -16, -7 },
{ 80, -16, -7 },
{ 90, -16, -7 },
{ 100, -16, -7 },
{ 10, -15, -7 },
{ 20, -15, -7 },
{ 30, -15, -7 },
{ 40, -15, -7 },
{ 50, -15, -7 },
{ 60, -15, -7 },
{ 70, -15, -7 },
{ 80, -15, -7 },
{ 90, -15, -7 },
{ 100, -15, -7 },
{ 10, -14, -7 },
{ 20, -14, -7 },
{ 30, -14, -7 },
{ 40, -14, -7 },
{ 50, -14, -7 },
{ 60, -14, -7 },
{ 70, -14, -7 },
{ 80, -14, -7 },
{ 90, -14, -7 },
{ 100, -14, -7 },
{ 10, -13, -7 },
{ 20, -13, -7 },
{ 30, -13, -7 },
{ 40, -13, -7 },
{ 50, -13, -7 },
{ 60, -13, -7 },
{ 70, -13, -7 },
{ 80, -13, -7 },
{ 90, -13, -7 },
{ 100, -13, -7 },
{ 10, -12, -7 },
{ 20, -12, -7 },
{ 30, -12, -7 },
{ 40, -12, -7 },
{ 50, -12, -7 },
{ 60, -12, -7 },
{ 70, -12, -7 },
{ 80, -12, -7 },
{ 90, -12, -7 },
{ 100, -12, -7 },
{ 10, -11, -7 },
{ 20, -11, -7 },
{ 30, -11, -7 },
{ 40, -11, -7 },
{ 50, -11, -7 },
{ 60, -11, -7 },
{ 70, -11, -7 },
{ 80, -11, -7 },
{ 90, -11, -7 },
{ 100, -11, -7 },
{ 10, -10, -7 },
{ 20, -10, -7 },
{ 30, -10, -7 },
{ 40, -10, -7 },
{ 50, -10, -7 },
{ 60, -10, -7 },
{ 70, -10, -7 },
{ 80, -10, -7 },
{ 90, -10, -7 },
{ 100, -10, -7 },
{ 10, -9, -7 },
{ 20, -9, -7 },
{ 30, -9, -7 },
{ 40, -9, -7 },
{ 50, -9, -7 },
{ 60, -9, -7 },
{ 70, -9, -7 },
{ 80, -9, -7 },
{ 90, -9, -7 },
{ 100, -9, -6 },
{ 10, -8, -7 },
{ 20, -8, -7 },
{ 30, -8, -7 },
{ 40, -8, -7 },
{ 50, -8, -7 },
{ 60, -8, -7 },
{ 70, -8, -7 },
{ 80, -8, -7 },
{ 90, -8, -6 },
{ 100, -8, -6 },
{ 10, -7, -7 },
{ 20, -7, -7 },
{ 30, -7, -7 },
{ 40, -7, -7 },
{ 50, -7, -7 },
{ 60, -7, -7 },
{ 70, -7, -7 },
{ 80, -7, -6 },
{ 90, -7, -6 },
{ 100, -7, -6 },
{ 10, -6, -7 },
{ 20, -6, -7 },
{ 30, -6, -7 },
{ 40, -6, -7 },
{ 50, -6, -7 },
{ 60, -6, -7 },
{ 70, -6, -7 },
{ 80, -6, -6 },
{ 90, -6, -6 },
{ 100, -6, -6 },
{ 10, -5, -7 },
{ 20, -5, -7 },
{ 30, -5, -7 },
{ 40, -5, -7 },
{ 50, -5, -7 },
{ 60, -5, -7 },
{ 70, -5, -6 },
{ 80, -5, -6 },
{ 90, -5, -6 },
{ 100, -5, -6 },
{ 10, -4, -7 },
{ 20, -4, -7 },
{ 30, -4, -7 },
{ 40, -4, -7 },
{ 50, -4, -7 },
{ 60, -4, -6 },
{ 70, -4, -6 },
{ 80, -4, -6 },
{ 90, -4, -6 },
{ 100, -4, -6 },
{ 10, -3, -7 },
{ 20, -3, -7 },
{ 30, -3, -7 },
{ 40, -3, -7 },
{ 50, -3, -7 },
{ 60, -3, -6 },
{ 70, -3, -6 },
{ 80, -3, -6 },
{ 90, -3, -6 },
{ 100, -3, -5 },
{ 10, -2, -7 },
{ 20, -2, -7 },
{ 30, -2, -7 },
{ 40, -2, -7 },
{ 50, -2, -6 },
{ 60, -2, -6 },
{ 70, -2, -6 },
{ 80, -2, -6 },
{ 90, -2, -5 },
{ 100, -2, -5 },
{ 10, -1, -7 },
{ 20, -1, -7 },
{ 30, -1, -7 },
{ 40, -1, -7 },
{ 50, -1, -6 },
{ 60, -1, -6 },
{ 70, -1, -6 },
{ 80, -1, -5 },
{ 90, -1, -5 },
{ 100, -1, -5 },
{ 10, 0, -7 },
{ 20, 0, -7 },
{ 30, 0, -7 },
{ 40, 0, -7 },
{ 50, 0, -6 },
{ 60, 0, -6 },
{ 70, 0, -6 },
{ 80, 0, -5 },
{ 90, 0, -5 },
{ 100, 0, -5 },
{ 10, 1, -7 },
{ 20, 1, -7 },
{ 30, 1, -7 },
{ 40, 1, -6 },
{ 50, 1, -6 },
{ 60, 1, -6 },
{ 70, 1, -5 },
{ 80, 1, -5 },
{ 90, 1, -5 },
{ 100, 1, -4 },
{ 10, 2, -7 },
{ 20, 2, -7 },
{ 30, 2, -7 },
{ 40, 2, -6 },
{ 50, 2, -6 },
{ 60, 2, -6 },
{ 70, 2, -5 },
{ 80, 2, -5 },
{ 90, 2, -4 },
{ 100, 2, -4 },
{ 10, 3, -7 },
{ 20, 3, -7 },
{ 30, 3, -7 },
{ 40, 3, -6 },
{ 50, 3, -6 },
{ 60, 3, -5 },
{ 70, 3, -5 },
{ 80, 3, -4 },
{ 90, 3, -4 },
{ 100, 3, -4 },
{ 10, 4, -7 },
{ 20, 4, -7 },
{ 30, 4, -6 },
{ 40, 4, -6 },
{ 50, 4, -6 },
{ 60, 4, -5 },
{ 70, 4, -5 },
{ 80, 4, -4 },
{ 90, 4, -4 },
{ 100, 4, -3 },
{ 10, 5, -7 },
{ 20, 5, -7 },
{ 30, 5, -6 },
{ 40, 5, -6 },
{ 50, 5, -5 },
{ 60, 5, -5 },
{ 70, 5, -4 },
{ 80, 5, -4 },
{ 90, 5, -3 },
{ 100, 5, -3 },
{ 10, 6, -7 },
{ 20, 6, -7 },
{ 30, 6, -6 },
{ 40, 6, -6 },
{ 50, 6, -5 },
{ 60, 6, -5 },
{ 70, 6, -4 },
{ 80, 6, -4 },
{ 90, 6, -3 },
{ 100, 6, -3 },
{ 10, 7, -7 },
{ 20, 7, -7 },
{ 30, 7, -6 },
{ 40, 7, -5 },
{ 50, 7, -5 },
{ 60, 7, -4 },
{ 70, 7, -4 },
{ 80, 7, -3 },
{ 90, 7, -3 },
{ 100, 7, -3 },
{ 10, 8, -7 },
{ 20, 8, -7 },
{ 30, 8, -6 },
{ 40, 8, -5 },
{ 50, 8, -5 },
{ 60, 8, -4 },
{ 70, 8, -3 },
{ 80, 8, -3 },
{ 90, 8, -3 },
{ 100, 8, -2 },
{ 10, 9, -7 },
{ 20, 9, -6 },
{ 30, 9, -6 },
{ 40, 9, -5 },
{ 50, 9, -4 },
{ 60, 9, -4 },
{ 70, 9, -3 },
{ 80, 9, -3 },
{ 90, 9, -2 },
{ 100, 9, -2 },
{ 10, 10, -7 },
{ 20, 10, -6 },
{ 30, 10, -6 },
{ 40, 10, -5 },
{ 50, 10, -4 },
{ 60, 10, -3 },
{ 70, 10, -3 },
{ 80, 10, -2 },
{ 90, 10, -2 },
{ 100, 10, -2 },
{ 10, 11, -7 },
{ 20, 11, -6 },
{ 30, 11, -5 },
{ 40, 11, -4 },
{ 50, 11, -4 },
{ 60, 11, -3 },
{ 70, 11, -2 },
{ 80, 11, -2 },
{ 90, 11, -2 },
{ 100, 11, -2 },
{ 10, 12, -7 },
{ 20, 12, -6 },
{ 30, 12, -5 },
{ 40, 12, -4 },
{ 50, 12, -3 },
{ 60, 12, -3 },
{ 70, 12, -2 },
{ 80, 12, -2 },
{ 90, 12, -1 },
{ 100, 12, -1 },
{ 10, 13, -7 },
{ 20, 13, -6 },
{ 30, 13, -5 },
{ 40, 13, -4 },
{ 50, 13, -3 },
{ 60, 13, -2 },
{ 70, 13, -2 },
{ 80, 13, -1 },
{ 90, 13, -1 },
{ 100, 13, -1 },
{ 10, 14, -7 },
{ 20, 14, -6 },
{ 30, 14, -5 },
{ 40, 14, -4 },
{ 50, 14, -3 },
{ 60, 14, -2 },
{ 70, 14, -1 },
{ 80, 14, -1 },
{ 90, 14, -1 },
{ 100, 14, -1 },
{ 10, 15, -7 },
{ 20, 15, -6 },
{ 30, 15, -4 },
{ 40, 15, -3 },
{ 50, 15, -2 },
{ 60, 15, -2 },
{ 70, 15, -1 },
{ 80, 15, -1 },
{ 90, 15, -1 },
{ 100, 15, -1 },
{ 10, 16, -7 },
{ 20, 16, -5 },
{ 30, 16, -4 },
{ 40, 16, -3 },
{ 50, 16, -2 },
{ 60, 16, -1 },
{ 70, 16, -1 },
{ 80, 16, -1 },
{ 90, 16, -1 },
{ 100, 16, -1 },
{ 10, 17, -6 },
{ 20, 17, -5 },
{ 30, 17, -4 },
{ 40, 17, -3 },
{ 50, 17, -2 },
{ 60, 17, -1 },
{ 70, 17, -1 },
{ 80, 17, -1 },
{ 90, 17, -1 },
{ 100, 17, -1 },
{ 10, 18, -6 },
{ 20, 18, -5 },
{ 30, 18, -3 },
{ 40, 18, -2 },
{ 50, 18, -1 },
{ 60, 18, -1 },
{ 70, 18, -1 },
{ 80, 18, -1 },
{ 90, 18, -1 },
{ 100, 18, -1 },
{ 10, 19, -6 },
{ 20, 19, -5 },
{ 30, 19, -3 },
{ 40, 19, -2 },
{ 50, 19, -1 },
{ 60, 19, -1 },
{ 70, 19, 0 },
{ 80, 19, -1 },
{ 90, 19, -1 },
{ 100, 19, -1 },
{ 10, 20, -6 },
{ 20, 20, -4 },
{ 30, 20, -3 },
{ 40, 20, -1 },
{ 50, 20, -1 },
{ 60, 20, 0 },
{ 70, 20, 0 },
{ 80, 20, -1 },
{ 90, 20, -1 },
{ 100, 20, -1 },
{ 10, 21, -6 },
{ 20, 21, -4 },
{ 30, 21, -2 },
{ 40, 21, -1 },
{ 50, 21, 0 },
{ 60, 21, 0 },
{ 70, 21, 0 },
{ 80, 21, -1 },
{ 90, 21, -1 },
{ 100, 21, -1 },
{ 10, 22, -6 },
{ 20, 22, -4 },
{ 30, 22, -2 },
{ 40, 22, -1 },
{ 50, 22, 0 },
{ 60, 22, 0 },
{ 70, 22, 0 },
{ 80, 22, -1 },
{ 90, 22, -1 },
{ 100, 22, -1 },
{ 10, 23, -6 },
{ 20, 23, -3 },
{ 30, 23, -2 },
{ 40, 23, 0 },
{ 50, 23, 0 },
{ 60, 23, 0 },
{ 70, 23, 0 },
{ 80, 23, -1 },
{ 90, 23, -1 },
{ 100, 23, -1 },
{ 10, 24, -6 },
{ 20, 24, -3 },
{ 30, 24, -1 },
{ 40, 24, 0 },
{ 50, 24, 0 },
{ 60, 24, 0 },
{ 70, 24, 0 },
{ 80, 24, -1 },
{ 90, 24, -1 },
{ 100, 24, -2 },
{ 10, 25, -5 },
{ 20, 25, -3 },
{ 30, 25, -1 },
{ 40, 25, 0 },
{ 50, 25, 0 },
{ 60, 25, 0 },
{ 70, 25, 0 },
{ 80, 25, -1 },
{ 90, 25, -1 },
{ 100, 25, -2 },
{ 10, 26, -5 },
{ 20, 26, -2 },
{ 30, 26, 0 },
{ 40, 26, 0 },
{ 50, 26, 0 },
{ 60, 26, 0 },
{ 70, 26, 0 },
{ 80, 26, -1 },
{ 90, 26, -1 },
{ 100, 26, -2 },
{ 10, 27, -5 },
{ 20, 27, -2 },
{ 30, 27, 0 },
{ 40, 27, 1 },
{ 50, 27, 0 },
{ 60, 27, 0 },
{ 70, 27, -1 },
{ 80, 27, -1 },
{ 90, 27, -2 },
{ 100, 27, -2 },
{ 10, 28, -5 },
{ 20, 28, -2 },
{ 30, 28, 0 },
{ 40, 28, 1 },
{ 50, 28, 0 },
{ 60, 28, 0 },
{ 70, 28, -1 },
{ 80, 28, -1 },
{ 90, 28, -2 },
{ 100, 28, -2 },
{ 10, 29, -5 },
{ 20, 29, -1 },
{ 30, 29, 1 },
{ 40, 29, 1 },
{ 50, 29, 0 },
{ 60, 29, 0 },
{ 70, 29, -1 },
{ 80, 29, -1 },
{ 90, 29, -2 },
{ 100, 29, -2 },
{ 10, 30, -4 },
{ 20, 30, -1 },
{ 30, 30, 1 },
{ 40, 30, 1 },
{ 50, 30, 0 },
{ 60, 30, 0 },
{ 70, 30, -1 },
{ 80, 30, -2 },
{ 90, 30, -2 },
{ 100, 30, -2 },
{ 10, 31, -4 },
{ 20, 31, 0 },
{ 30, 31, 1 },
{ 40, 31, 1 },
{ 50, 31, 0 },
{ 60, 31, 0 },
{ 70, 31, -1 },
{ 80, 31, -2 },
{ 90, 31, -2 },
{ 100, 31, -3 },
{ 10, 32, -4 },
{ 20, 32, 0 },
{ 30, 32, 1 },
{ 40, 32, 1 },
{ 50, 32, 0 },
{ 60, 32, -1 },
{ 70, 32, -1 },
{ 80, 32, -2 },
{ 90, 32, -2 },
{ 100, 32, -3 },
{ 10, 33, -3 },
{ 20, 33, 0 },
{ 30, 33, 1 },
{ 40, 33, 1 },
{ 50, 33, 0 },
{ 60, 33, -1 },
{ 70, 33, -1 },
{ 80, 33, -2 },
{ 90, 33, -2 },
{ 100, 33, -3 },
{ 10, 34, -3 },
{ 20, 34, 1 },
{ 30, 34, 2 },
{ 40, 34, 1 },
{ 50, 34, 0 },
{ 60, 34, -1 },
{ 70, 34, -2 },
{ 80, 34, -2 },
{ 90, 34, -3 },
{ 100, 34, -3 },
{ 10, 35, -3 },
{ 20, 35, 1 },
{ 30, 35, 2 },
{ 40, 35, 1 },
{ 50, 35, 0 },
{ 60, 35, -1 },
{ 70, 35, -2 },
{ 80, 35, -2 },
{ 90, 35, -3 },
{ 100, 35, -3 },
{ 10, 36, -2 },
{ 20, 36, 1 },
{ 30, 36, 2 },
{ 40, 36, 1 },
{ 50, 36, 0 },
{ 60, 36, -1 },
{ 70, 36, -2 },
{ 80, 36, -2 },
{ 90, 36, -3 },
{ 100, 36, -3 },
{ 10, 37, -2 },
{ 20, 37, 2 },
{ 30, 37, 2 },
{ 40, 37, 1 },
{ 50, 37, 0 },
{ 60, 37, -1 },
{ 70, 37, -2 },
{ 80, 37, -3 },
{ 90, 37, -3 },
{ 100, 37, -3 },
{ 10, 38, -1 },
{ 20, 38, 2 },
{ 30, 38, 2 },
{ 40, 38, 1 },
{ 50, 38, -1 },
{ 60, 38, -1 },
{ 70, 38, -2 },
{ 80, 38, -3 },
{ 90, 38, -3 },
{ 100, 38, -4 },
{ 10, 39, -1 },
{ 20, 39, 2 },
{ 30, 39, 2 },
{ 40, 39, 0 },
{ 50, 39, -1 },
{ 60, 39, -2 },
{ 70, 39, -2 },
{ 80, 39, -3 },
{ 90, 39, -3 },
{ 100, 39, -4 },
{ 10, 40, -1 },
{ 20, 40, 2 },
{ 30, 40, 2 },
{ 40, 40, 0 },
{ 50, 40, -1 },
{ 60, 40, -2 },
{ 70, 40, -2 },
{ 80, 40, -3 },
{ 90, 40, -3 },
{ 100, 40, -4 },
{ 10, 41, 0 },
{ 20, 41, 3 },
{ 30, 41, 1 },
{ 40, 41, 0 },
{ 50, 41, -1 },
{ 60, 41, -2 },
{ 70, 41, -3 },
{ 80, 41, -3 },
{ 90, 41, -4 },
{ 100, 41, -4 },
{ 10, 42, 0 },
{ 20, 42, 3 },
{ 30, 42, 1 },
{ 40, 42, 0 },
{ 50, 42, -1 },
{ 60, 42, -2 },
{ 70, 42, -3 },
{ 80, 42, -3 },
{ 90, 42, -4 },
{ 100, 42, -4 },
{ 10, 43, 1 },
{ 20, 43, 3 },
{ 30, 43, 1 },
{ 40, 43, 0 },
{ 50, 43, -1 },
{ 60, 43, -2 },
{ 70, 43, -3 },
{ 80, 43, -3 },
{ 90, 43, -4 },
{ 100, 43, -4 },
{ 10, 44, 1 },
{ 20, 44, 3 },
{ 30, 44, 1 },
{ 40, 44, 0 },
{ 50, 44, -2 },
{ 60, 44, -2 },
{ 70, 44, -3 },
{ 80, 44, -3 },
{ 90, 44, -4 },
{ 100, 44, -4 },
{ 10, 45, 2 },
{ 20, 45, 3 },
{ 30, 45, 1 },
{ 40, 45, -1 },
{ 50, 45, -2 },
{ 60, 45, -3 },
{ 70, 45, -3 },
{ 80, 45, -4 },
{ 90, 45, -4 },
{ 100, 45, -4 },
{ 10, 46, 2 },
{ 20, 46, 3 },
{ 30, 46, 1 },
{ 40, 46, -1 },
{ 50, 46, -2 },
{ 60, 46, -3 },
{ 70, 46, -3 },
{ 80, 46, -4 },
{ 90, 46, -4 },
{ 100, 46, -4 },
{ 10, 47, 2 },
{ 20, 47, 3 },
{ 30, 47, 1 },
{ 40, 47, -1 },
{ 50, 47, -2 },
{ 60, 47, -3 },
{ 70, 47, -3 },
{ 80, 47, -4 },
{ 90, 47, -4 },
{ 100, 47, -4 },
{ 10, 48, 3 },
{ 20, 48, 3 },
{ 30, 48, 0 },
{ 40, 48, -1 },
{ 50, 48, -2 },
{ 60, 48, -3 },
{ 70, 48, -3 },
{ 80, 48, -4 },
{ 90, 48, -4 },
{ 100, 48, -4 },
{ 10, 49, 3 },
{ 20, 49, 3 },
{ 30, 49, 0 },
{ 40, 49, -1 },
{ 50, 49, -2 },
{ 60, 49, -3 },
{ 70, 49, -4 },
{ 80, 49, -4 },
{ 90, 49, -4 },
{ 100, 49, -4 },
{ 10, 50, 4 },
{ 20, 50, 2 },
{ 30, 50, 0 },
{ 40, 50, -1 },
{ 50, 50, -2 },
{ 60, 50, -3 },
{ 70, 50, -4 },
{ 80, 50, -4 },
{ 90, 50, -4 },
{ 100, 50, -4 },
{ 10, 51, 4 },
{ 20, 51, 2 },
{ 30, 51, 0 },
{ 40, 51, -2 },
{ 50, 51, -3 },
{ 60, 51, -3 },
{ 70, 51, -4 },
{ 80, 51, -4 },
{ 90, 51, -4 },
{ 100, 51, -5 },
{ 10, 52, 4 },
{ 20, 52, 2 },
{ 30, 52, 0 },
{ 40, 52, -2 },
{ 50, 52, -3 },
{ 60, 52, -3 },
{ 70, 52, -4 },
{ 80, 52, -4 },
{ 90, 52, -4 },
{ 100, 52, -5 },
{ 10, 53, 4 },
{ 20, 53, 2 },
{ 30, 53, 0 },
{ 40, 53, -2 },
{ 50, 53, -3 },
{ 60, 53, -3 },
{ 70, 53, -4 },
{ 80, 53, -4 },
{ 90, 53, -4 },
{ 100, 53, -5 },
{ 10, 54, 5 },
{ 20, 54, 2 },
{ 30, 54, -1 },
{ 40, 54, -2 },
{ 50, 54, -3 },
{ 60, 54, -4 },
{ 70, 54, -4 },
{ 80, 54, -4 },
{ 90, 54, -4 },
{ 100, 54, -5 },
{ 10, 55, 5 },
{ 20, 55, 2 },
{ 30, 55, -1 },
{ 40, 55, -2 },
{ 50, 55, -3 },
{ 60, 55, -4 },
{ 70, 55, -4 },
{ 80, 55, -4 },
{ 90, 55, -4 },
{ 100, 55, -5 },
{ 10, 56, 5 },
{ 20, 56, 1 },
{ 30, 56, -1 },
{ 40, 56, -2 },
{ 50, 56, -3 },
{ 60, 56, -4 },
{ 70, 56, -4 },
{ 80, 56, -4 },
{ 90, 56, -5 },
{ 100, 56, -5 },
{ 10, 57, 5 },
{ 20, 57, 1 },
{ 30, 57, -1 },
{ 40, 57, -2 },
{ 50, 57, -3 },
{ 60, 57, -4 },
{ 70, 57, -4 },
{ 80, 57, -4 },
{ 90, 57, -5 },
{ 100, 57, -5 },
{ 10, 58, 5 },
{ 20, 58, 1 },
{ 30, 58, -1 },
{ 40, 58, -3 },
{ 50, 58, -3 },
{ 60, 58, -4 },
{ 70, 58, -4 },
{ 80, 58, -4 },
{ 90, 58, -5 },
{ 100, 58, -5 },
{ 10, 59, 5 },
{ 20, 59, 1 },
{ 30, 59, -1 },
{ 40, 59, -3 },
{ 50, 59, -3 },
{ 60, 59, -4 },
{ 70, 59, -4 },
{ 80, 59, -4 },
{ 90, 59, -5 },
{ 100, 59, -5 },
{ 10, 60, 5 },
{ 20, 60, 1 },
{ 30, 60, -2 },
{ 40, 60, -3 },
{ 50, 60, -3 },
{ 60, 60, -4 },
{ 70, 60, -4 },
{ 80, 60, -4 },
{ 90, 60, -5 },
{ 100, 60, -5 },
{ 10, 61, 5 },
{ 20, 61, 0 },
{ 30, 61, -2 },
{ 40, 61, -3 },
{ 50, 61, -4 },
{ 60, 61, -4 },
{ 70, 61, -4 },
{ 80, 61, -4 },
{ 90, 61, -5 },
{ 100, 61, -5 },
{ 10, 62, 5 },
{ 20, 62, 0 },
{ 30, 62, -2 },
{ 40, 62, -3 },
{ 50, 62, -4 },
{ 60, 62, -4 },
{ 70, 62, -4 },
{ 80, 62, -4 },
{ 90, 62, -5 },
{ 100, 62, -5 },
{ 10, 63, 5 },
{ 20, 63, 0 },
{ 30, 63, -2 },
{ 40, 63, -3 },
{ 50, 63, -4 },
{ 60, 63, -4 },
{ 70, 63, -4 },
{ 80, 63, -4 },
{ 90, 63, -5 },
{ 100, 63, -5 },
{ 10, 64, 5 },
{ 20, 64, 0 },
{ 30, 64, -2 },
{ 40, 64, -3 },
{ 50, 64, -4 },
{ 60, 64, -4 },
{ 70, 64, -4 },
{ 80, 64, -4 },
{ 90, 64, -4 },
{ 100, 64, -5 },
{ 10, 65, 4 },
{ 20, 65, 0 },
{ 30, 65, -2 },
{ 40, 65, -3 },
{ 50, 65, -4 },
{ 60, 65, -4 },
{ 70, 65, -4 },
{ 80, 65, -4 },
{ 90, 65, -4 },
{ 100, 65, -4 },
{ 10, 66, 4 },
{ 20, 66, 0 },
{ 30, 66, -2 },
{ 40, 66, -3 },
{ 50, 66, -4 },
{ 60, 66, -4 },
{ 70, 66, -4 },
{ 80, 66, -4 },
{ 90, 66, -4 },
{ 100, 66, -4 },
{ 10, 67, 4 },
{ 20, 67, -1 },
{ 30, 67, -2 },
{ 40, 67, -3 },
{ 50, 67, -4 },
{ 60, 67, -4 },
{ 70, 67, -4 },
{ 80, 67, -4 },
{ 90, 67, -4 },
{ 100, 67, -4 },
{ 10, 68, 4 },
{ 20, 68, -1 },
{ 30, 68, -3 },
{ 40, 68, -3 },
{ 50, 68, -4 },
{ 60, 68, -4 },
{ 70, 68, -4 },
{ 80, 68, -4 },
{ 90, 68, -4 },
{ 100, 68, -4 },
{ 10, 69, 4 },
{ 20, 69, -1 },
{ 30, 69, -3 },
{ 40, 69, -3 },
{ 50, 69, -4 },
{ 60, 69, -4 },
{ 70, 69, -4 },
{ 80, 69, -4 },
{ 90, 69, -4 },
{ 100, 69, -4 },
{ 10, 70, 4 },
{ 20, 70, -1 },
{ 30, 70, -3 },
{ 40, 70, -4 },
{ 50, 70, -4 },
{ 60, 70, -4 },
{ 70, 70, -4 },
{ 80, 70, -4 },
{ 90, 70, -4 },
{ 100, 70, -4 },
{ 10, 71, 3 },
{ 20, 71, -1 },
{ 30, 71, -3 },
{ 40, 71, -4 },
{ 50, 71, -4 },
{ 60, 71, -4 },
{ 70, 71, -4 },
{ 80, 71, -4 },
{ 90, 71, -4 },
{ 100, 71, -4 },
{ 10, 72, 3 },
{ 20, 72, -1 },
{ 30, 72, -3 },
{ 40, 72, -4 },
{ 50, 72, -4 },
{ 60, 72, -4 },
{ 70, 72, -4 },
{ 80, 72, -4 },
{ 90, 72, -4 },
{ 100, 72, -4 },
{ 10, 73, 3 },
{ 20, 73, -1 },
{ 30, 73, -3 },
{ 40, 73, -4 },
{ 50, 73, -4 },
{ 60, 73, -4 },
{ 70, 73, -4 },
{ 80, 73, -4 },
{ 90, 73, -4 },
{ 100, 73, -4 },
{ 10, 74, 3 },
{ 20, 74, -2 },
{ 30, 74, -3 },
{ 40, 74, -4 },
{ 50, 74, -4 },
{ 60, 74, -4 },
{ 70, 74, -4 },
{ 80, 74, -4 },
{ 90, 74, -4 },
{ 100, 74, -4 },
{ 10, 75, 2 },
{ 20, 75, -2 },
{ 30, 75, -3 },
{ 40, 75, -4 },
{ 50, 75, -4 },
{ 60, 75, -4 },
{ 70, 75, -4 },
{ 80, 75, -4 },
{ 90, 75, -4 },
{ 100, 75, -4 },
{ 10, 76, 2 },
{ 20, 76, -2 },
{ 30, 76, -3 },
{ 40, 76, -4 },
{ 50, 76, -4 },
{ 60, 76, -4 },
{ 70, 76, -4 },
{ 80, 76, -4 },
{ 90, 76, -4 },
{ 100, 76, -4 },
{ 10, 77, 2 },
{ 20, 77, -2 },
{ 30, 77, -3 },
{ 40, 77, -4 },
{ 50, 77, -4 },
{ 60, 77, -4 },
{ 70, 77, -4 },
{ 80, 77, -4 },
{ 90, 77, -4 },
{ 100, 77, -3 },
{ 10, 78, 2 },
{ 20, 78, -2 },
{ 30, 78, -3 },
{ 40, 78, -4 },
{ 50, 78, -4 },
{ 60, 78, -4 },
{ 70, 78, -4 },
{ 80, 78, -4 },
{ 90, 78, -3 },
{ 100, 78, -3 },
{ 10, 79, 2 },
{ 20, 79, -2 },
{ 30, 79, -3 },
{ 40, 79, -4 },
{ 50, 79, -4 },
{ 60, 79, -4 },
{ 70, 79, -4 },
{ 80, 79, -3 },
{ 90, 79, -3 },
{ 100, 79, -3 },
{ 10, 80, 1 },
{ 20, 80, -2 },
{ 30, 80, -3 },
{ 40, 80, -4 },
{ 50, 80, -4 },
{ 60, 80, -4 },
{ 70, 80, -3 },
{ 80, 80, -3 },
{ 90, 80, -3 },
{ 100, 80, -3 } };
#else
const sint8_t aUSSMgr_V_Temp_Table[22][2]=
{
    {   -6,-14},
    {   2,-13},
    {   6,-12},
    {   8,-11},
    {   11,-10},
    {   13,-9},
    {   14,-8},
    {   16,-7},
    {   17,-6},
    {   18,-5},
    {   19,-4},
    {   20,-3},
    {   21,-2},
    {   22,-1},
    {   23,0},
    {   28,-1},
    {   30,-2},
    {   33,-3},
    {   35,-4},
    {   39,-5},
    {   42,-6},
    {   46,-7}}; // now according biggest humidity at each temperature each dac value
#endif

#if 0
void aUSSMgr_F_TemperatureMain(void)
{
    uint8_t change_temp = ME_FALSE;
    pUS_E_USSCtrl_TempState = pUS_E_USSCtrl_TempState_Init;
    while (pUS_E_USSCtrl_TempState != pUS_E_USSCtrl_TempState_Finished)

    {
        switch (pUS_E_USSCtrl_TempState)
        {
            case pUS_E_USSCtrl_TempState_Init:
                if (pUS_E_TempRunning_Flg == pUS_E_USSCtrl_Temprun_Init)
                {
                    aUSSMgr_F_Temperature_Init();
                }
                pUS_E_USSCtrl_TempState = pUS_E_USSCtrl_TempState_GetTemp;
                pUS_E_TempRunning_Flg = pUS_E_USSCtrl_Temprun_running;
                break;
            case pUS_E_USSCtrl_TempState_GetTemp:
                /*get temperature from CAN function*/
                pUS_E_TempRunning_Flg = pUS_E_USSCtrl_Temprun_running;
                aUSSMgr_F_TemperatureReceive();
                pUS_E_USSCtrl_TempState = pUS_E_USSCtrl_TempState_CheckTemp;
                pUS_E_TempRunning_Flg = pUS_E_USSCtrl_Temprun_stop;
                break;
            case pUS_E_USSCtrl_TempState_CheckTemp:
                pUS_E_TempRunning_Flg = pUS_E_USSCtrl_Temprun_running;
                change_temp = aUSSMgr_F_TempHumiCheck();
                //if different temperature goto SetDeltaGain
                if (change_temp)
                {
                    pUS_E_USSCtrl_TempState = pUS_E_USSCtrl_TempState_SetDeltaGain;
                }
                //if same temperature goto finished
                else
                {
                    pUS_E_USSCtrl_TempState = pUS_E_USSCtrl_TempState_Finished;
                }

                pUS_E_TempRunning_Flg = pUS_E_USSCtrl_Temprun_stop;
                break;
            case pUS_E_USSCtrl_TempState_SetDeltaGain:
                pUS_E_TempRunning_Flg = pUS_E_USSCtrl_Temprun_running;
                aUSSMgr_F_TemperatureDeltaGainSet();
                pUS_E_USSCtrl_TempState = pUS_E_USSCtrl_TempState_Finished;
                pUS_E_TempRunning_Flg = pUS_E_USSCtrl_Temprun_stop;
                break;
            case pUS_E_USSCtrl_TempState_Finished:
            default:

                pUS_E_USSCtrl_TempState = pUS_E_USSCtrl_TempState_Finished;
                pUS_E_TempRunning_Flg = pUS_E_USSCtrl_Temprun_stop;
                break;
        }
    }
}
#endif

void aUSSMgr_F_Temperature_Init(void)
{
    uint8_t i = 0;
    for (i = 0; i < TEMPLOG_MAX; i++)
    {
        aUSSMgr_V_Temp[i] = 127;
        aUSSMgr_V_Humi[i] = 50;
    }
    aUSSMgr_V_TempLogCnt = 0;
    aUSSMgr_V_TempLogFull = ME_FALSE;
    aUSSMgr_V_TempCurrCnt = 0;
    aUSSMgr_V_Temp_SUM = 0;
    aUSSMgr_V_TempLast = 0;

    aUSSMgr_V_Humi_SUM = 0;
    aUSSMgr_V_HumiLast = 0;

}
sint8_t curr_temp = (sint8_t) TEMP_DEFAULT;
uint8_t curr_humi = HUMIDITY_DEFAULT; //humidity
void aUSSMgr_F_TemperatureReceive(void)
{

    if (aUSSMgr_V_TempLogFull == ME_TRUE)
    {
        aUSSMgr_V_Temp_SUM = aUSSMgr_V_Temp_SUM - aUSSMgr_V_Temp[aUSSMgr_V_TempLogCnt];
        aUSSMgr_V_Humi_SUM = aUSSMgr_V_Humi_SUM - aUSSMgr_V_Humi[aUSSMgr_V_TempLogCnt];
    }

    curr_temp = (sint8_t) MEUssMgr_v_AirTempOutsd;
    if (curr_temp > 80)
    {
        curr_temp = 80;
    }
    else if (curr_temp < -50)
    {
        curr_temp = -50;
    }

    curr_humi = MEUssMgr_v_AirHumiOutsd;
    if (curr_humi > 100)
    {
        curr_humi = 100;
    }

    aUSSMgr_V_Temp[aUSSMgr_V_TempLogCnt] = curr_temp; //get temperature from CAN bus now set default 24
    aUSSMgr_V_Temp_SUM = aUSSMgr_V_Temp_SUM + curr_temp;
    aUSSMgr_V_Humi[aUSSMgr_V_TempLogCnt] = curr_humi; //get temperature from CAN bus now set default 24
    aUSSMgr_V_Humi_SUM = aUSSMgr_V_Humi_SUM + curr_humi;
    aUSSMgr_F_TempratureCNT();
}

void aUSSMgr_F_TempratureCNT(void)
{
    aUSSMgr_V_TempLogCnt++;
    if (aUSSMgr_V_TempLogCnt >= TEMPLOG_MAX)
    {
        aUSSMgr_V_TempLogCnt = 0;
        aUSSMgr_V_TempLogFull = ME_TRUE;
    }
    else
    {
        aUSSMgr_V_TempCurrCnt = aUSSMgr_V_TempLogCnt;
    }
    if (aUSSMgr_V_TempLogFull == ME_TRUE)
        aUSSMgr_V_TempCurrCnt = TEMPLOG_MAX;
}

uint8_t aUSSMgr_F_TempHumiCheck(void)
{
    aUSSMgr_V_Temp_AVG = aUSSMgr_V_Temp_SUM / aUSSMgr_V_TempCurrCnt;
    aUSSMgr_V_Humi_AVG = aUSSMgr_V_Humi_SUM / aUSSMgr_V_TempCurrCnt;
//  aUSS_D_LogWarning("AVG,%d",aUSSMgr_V_Temp_AVG);
    if (aUSSMgr_V_TempLast != aUSSMgr_V_Temp_AVG)
    {
        aUSSMgr_V_TempLast = aUSSMgr_V_Temp_AVG;
        return ME_TRUE;
    }
    else if (!aUSSMgr_V_TempLogFull)
    {
        return ME_TRUE;
    }
    else
    {
        if (aUSSMgr_V_HumiLast != aUSSMgr_V_Humi_AVG)
        {
            aUSSMgr_V_HumiLast = aUSSMgr_V_Humi_AVG;
            return ME_TRUE;
        }
        else
        {
            return ME_FALSE;
        }

    }
}

#if HUMIDITY_DEFAULT
#if 0
void aUSSMgr_F_TemperatureDeltaGainSet(void)
{
    uint16_t i = 0;
    UssMgr_sInterfaceData.USS_TempGainType = ME_FALSE;
    uint8_t loc_humi_avg[] =
    { 15, 25, 35, 45, 55, 65, 75, 85, 95 };
    uint8_t loc_humi = 50;
    sint8_t loc_temp = aUSSMgr_V_Temp_AVG;
    if (loc_temp > 80)
    {
        loc_temp = 80;
    }
    else if (loc_temp < -50)
    {
        loc_temp = -50;
    }

    if (aUSSMgr_V_Humi_AVG >= loc_humi_avg[8])
    {
        loc_humi = 100;
    }
    else
    {
        for (i = 0; i < 9; i++)
        {
            if (aUSSMgr_V_Humi_AVG < loc_humi_avg[i])
            {
                loc_humi = loc_humi_avg[i] - 5;
                break;
            }
        }
    }

    for (i = 0; i < 1310; i++)
    {
        if (loc_temp == aUSSMgr_V_Temp_Hum_Table[i].temp)
        {
            if (loc_humi == aUSSMgr_V_Temp_Hum_Table[i].humi)
            {
                aUSS_D_LogWarning("TEMP,%d,HUMI,%d,GAIN,%d", aUSSMgr_V_Temp_Hum_Table[i].temp, aUSSMgr_V_Temp_Hum_Table[i].humi,
                        aUSSMgr_V_Temp_Hum_Table[i].gain);
                if (aUSSMgr_V_GainLast == aUSSMgr_V_Temp_Hum_Table[i].gain)
                {
                    //same delta gain so nothing need to update
                    aUSS_D_LogWarning("Same GAIN,%d", aUSSMgr_V_GainLast);
                    UssMgr_sInterfaceData.USS_TempGainType = ME_FALSE;
                }
                else
                {
                    UssMgr_sInterfaceData.USS_TempGainType = ME_TRUE;
                    aUSSMgr_V_GainLast = aUSSMgr_V_Temp_Hum_Table[i].gain;
                    UssMgr_sInterfaceData.USS_TempGain_Mod = aUSSMgr_V_GainLast;
                    aUSS_D_LogWarning("update GAIN,%d", aUSSMgr_V_GainLast);
                }
                break;
            }
        }
    }
}
#endif
#else
void aUSSMgr_F_TemperatureDeltaGainSet(void)
{
    uint8_t i = 0;
    UssMgr_sInterfaceData.USS_TempGainType = ME_FALSE;
    for(i=0;i<22;i++)
    {
        if(aUSSMgr_V_Temp_AVG < aUSSMgr_V_Temp_Table[i][0])
        {
            if(aUSSMgr_V_GainLast == aUSSMgr_V_Temp_Table[i][1])
            {
                //same delta gain so nothing need to update
//        aUSS_D_LogWarning("Same GAIN,%d",aUSSMgr_V_GainLast);
                break;
            }
            else
            {
                UssMgr_sInterfaceData.USS_TempGainType = ME_TRUE;
                aUSSMgr_V_GainLast = aUSSMgr_V_Temp_Table[i][1];
                UssMgr_sInterfaceData.USS_TempGain_Mod = aUSSMgr_V_GainLast;
//        aUSS_D_LogWarning("update GAIN,%d",aUSSMgr_V_GainLast);
                break;
            }
        }
    }
}
/*Temperature DeltaGain*/
#endif
#endif
