/*
 * US_MgrHeightAlgo.c
 *
 *  Created on: Aug(8), 10, 2022
 *      Author: jwreynolds
 */
/*PRQA S 0816, 1011 ++ */
/*PRQA S  0776, 0792  ++ */ 
/*PRQA S 1850 ++*/  /*conversion is expected from model based generated code */
/*PRQA S 1862, 4558, 4548 ++ */  /*Converted as well as non converted int has same relational operations */
/* PRQA S 1860 ++ */ /* Generated value is og unsigned type*/

/* PRQA S  3408, 3344, 2012, 2982, 4116, 3415, 2742, 1330, 4115, 3224 ++ */ /* Listed warning have no functional impact */
/* PRQA S 1891,4461, 4533, 4393, 4404, 2896,1843, 1800, 4443 ++ */ /* Conversion has no impact */
/* PRQA S 1503 ++ */ /* Carried over from core project but kept same to keep the file structure same */
/* PRQA S 0715 ++ */ /* Functionality as expected */

#include <math.h>
#include <stdlib.h>
#include "US_ME_Typedefs_Global.h"
#include "US_MgrHeightAlgo.h"
#include "US_SysMgr_Global.h"

#define US_D_HEIGHT_ALGO_DEBUG_LOG_ENABLED      (ME_FALSE)

#if (US_D_HEIGHT_ALGO_DEBUG_LOG_ENABLED == ME_TRUE)
typedef enum
{
    US_E_HEIGHT_ALGO_STEP__INIT = ZERO,
    US_E_HAS__CLOSE_RANGE_FOV_ASSUMPTION,
    US_E_HAS__CLOSE_2ND_ECHO_CHECK,
    US_E_HAS__FAR_2ND_ECHO_CHECK,
    US_E_HAS__MULTI_REFLECT_ECHO_CHECK,
    US_E_HAS__SINGLE_ECHO_CHECK,
    US_E_HAS__ECHO_STRENGTH_CHECK,
    US_E_HAS__ECHO_WIDTH_CHECK,
    US_E_HEIGHT_ALGO_STEP__END
} US_E_HeightAlgoStep_t;
#endif

typedef enum
{
    US_E_HAD_NONE = ZERO,
    US_E_HAD_UP,
    US_E_HAD_DOWN
} US_E_HeightAlgoDir_t;

typedef struct
{
    uint16_t uEchoDirDist;
    uint16_t uFilterVal;
} US_S_HeightAlgoCalTable1_t;

typedef struct
{
    uint16_t uEchoDirDist;
    uint16_t uFilterVal1;
    uint16_t uFilterVal2;
} US_S_HeightAlgoCalTable2_t;


/*
    Height Confidence Scale
    3bit value: Min 0 :: Max 7
    |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
    |       Low       |  Unknown  |       High      |   <-- For default: Unknown
    |                 Low               |    High   |   <-- For default: Low
    |    Low    |               High                |   <-- For default: High

*/
//behavior on failure
#define US_D_HEIGHT_ALGO_SET_TO_DEFAULT_ON_FAIL     (ME_TRUE)
//algo step limits - doesn't need to be in cal
#define US_D_HEIGHT_ALGO_MAX_ALGO_STEPS     (9u)
//final str adjustment
#define US_D_HEIGHT_ADD_2ND_ECHO_STR    (ME_TRUE)

/* default mode handling & range cal */
#if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__UNKNOWN)
    #define US_D_HEIGHT_ALGO_SCALE_MIN  (0u)
    #define US_D_HEIGHT_ALGO_SCALE_MAX  (7u)
    #define US_D_HEIGHT_ALGO_STARTING_CONF (4u)
    /* height conf to final height determination, zero based*/
    #define US_D_HEIGHT_ALGO_LOW_MAX    (2u)
    #define US_D_HEIGHT_ALGO_HIGH_MIN   (5u)
#endif
#if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__LOW)
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
    #define US_D_HEIGHT_ALGO_SCALE_MIN  (0u)
#endif    
    #define US_D_HEIGHT_ALGO_SCALE_MAX  (7u)
    #define US_D_HEIGHT_ALGO_STARTING_CONF (1u)
    #define US_D_HEIGHT_ALGO_LOW_MAX    (5u)
    #define US_D_HEIGHT_ALGO_HIGH_MIN   (6u)
#endif
#if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__HIGH)
    #define US_D_HEIGHT_ALGO_SCALE_MIN  (0u)
    #define US_D_HEIGHT_ALGO_SCALE_MAX  (7u)
    #define US_D_HEIGHT_ALGO_STARTING_CONF (6u)
    #define US_D_HEIGHT_ALGO_LOW_MAX    (1u)
    #define US_D_HEIGHT_ALGO_HIGH_MIN   (2u)
#endif


#if (US_D_HEIGHT_ALGO_DEBUG_LOG_ENABLED == ME_TRUE)
    #define DEBUG_HAS_HISTORY_ARRAY_SIZE    US_D_HEIGHT_ALGO_MAX_ALGO_STEPS
static US_E_HeightAlgoStep_t eaDEBUG_heightAlgoStepHistory[DEBUG_HAS_HISTORY_ARRAY_SIZE];
static sint16_t eaDEBUG_heightAlgoValHistory[DEBUG_HAS_HISTORY_ARRAY_SIZE];
#endif

/* height algo calibration/tuning values */
//--------US_E_HAS__CLOSE_RANGE_FOV_ASSUMPTION
#define US_D_HEIGHT_ALGO_CLOSE_RANGE_DIST_CM    (70u) //may need to be per sensor
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
#define US_D_HEIGHT_ALGO_CLOSE_RANGE_PASS_ADJ   (US_D_HEIGHT_ALGO_SCALE_MAX)
#endif
#define US_D_HEIGHT_ALGO_CLOSE_RANGE_FAIL_ADJ   (0u)

#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
    const US_S_HeightAlgoCalTable1_t sUssMgr_Far2ndEchoTable[US_D_HEIGHT_ALGO_FAR_2ND_TABLE_LEN] =
    {
        { 100u, 50u }, //direcho, dist between 1st/2nd echo
        { 200u, 70u },
        { 300u, 70u },
        { 500u, 70u }
    };
    #endif
//--------US_E_HAS__CLOSE_2ND_ECHO_CHECK
//#define US_D_HEIGHT_ALGO_CLOSE_2ND_CM           (15u)
#define US_D_HEIGHT_ALGO_CLOSE_2ND_TABLE_LEN    (4u)  //not cal

#define US_D_HEIGHT_ALGO_CLOSE_2ND_PASS_ADJ     (6u)
#define US_D_HEIGHT_ALGO_CLOSE_2ND_FAIL_ADJ     (0u)

//--------US_E_HAS__FAR_2ND_ECHO_CHECK
#define US_D_HEIGHT_ALGO_FAR_2ND_TABLE_LEN    (4u)  //not cal

#define US_D_HEIGHT_ALGO_FAR_2ND_PASS_ADJ   (-2)
#define US_D_HEIGHT_ALGO_FAR_2ND_FAIL_ADJ   (0u)

//--------US_E_HAS__MULTI_REFLECT_ECHO_CHECK
#define US_D_HEIGHT_ALGO_MULTI_REFLECT_TABLE_LEN    (4u)  //not cal

#define US_D_HEIGHT_ALGO_MULTI_REFLECT_PASS_ADJ     (5u)  /*PRQA S 0791 */ /* No need to change */
#define US_D_HEIGHT_ALGO_MULTI_REFLECT_FAIL_ADJ     (0u)  /*PRQA S 0791 */ /* No need to change */

//--------US_E_HAS__SINGLE_ECHO_CHECK
#define US_D_HEIGHT_ALGO_SINGLE_ECHO_PASS_ADJ       (-2)
#define US_D_HEIGHT_ALGO_SINGLE_ECHO_FAIL_ADJ       (0u)

//--------US_E_HAS__ECHO_STRENGTH_CHECK - needs adjustment based on temperature OR used STG
#define US_D_HEIGHT_ALGO_STRENGTH_DISABLE       (ME_TRUE)
#define US_D_HEIGHT_ALGO_STRENGTH_TABLE_LEN    (8u)  //not cal
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
const US_S_HeightAlgoCalTable2_t sUssMgr_HA_StrLowTable[US_D_HEIGHT_ALGO_STRENGTH_TABLE_LEN] =
{
    { 100u, 100u, 10u}, //direcho, echo adc val, adc val step for more confidence
    { 150u, 70u , 7u},
    { 200u, 60u , 5u },
    { 250u, 50u , 5u },
    { 300u, 50u , 5u },
    { 350u, 45u , 4u },
    { 400u, 45u , 4u },
    { 450u, 40u , 4u }
};
#define US_D_HEIGHT_ALGO_STRENGTH_LOW_PASS_START    (-2)
#define US_D_HEIGHT_ALGO_STRENGTH_LOW_PASS_MAX      (-4) /*PRQA S 0791 */ /* No need to change */

const US_S_HeightAlgoCalTable2_t sUssMgr_HA_StrHighTable[US_D_HEIGHT_ALGO_STRENGTH_TABLE_LEN] =
{
    { 100u, 170u, 20u}, //direcho, echo adc val, adc val step for more confidence
    { 150u, 160u, 20u},
    { 200u, 150u, 20u },
    { 250u, 150u, 10u },
    { 300u, 150u, 10u },
    { 350u, 100u, 10u },
    { 400u, 80u , 5u },
    { 450u, 70u , 5u }
};
#define US_D_HEIGHT_ALGO_STRENGTH_HIGH_PASS_START   (2u)
#define US_D_HEIGHT_ALGO_STRENGTH_HIGH_PASS_MAX     (4u) /*PRQA S 0791 */ /* No need to change */
#define US_D_HEIGHT_ALGO_STRENGTH_BOTH_FAIL_ADJ     (0u)


//--------US_E_HAS__ECHO_WIDTH_CHECK
#define US_D_HEIGHT_ALGO_WIDTH_TABLE_LEN    (4u)  //not cal
const US_S_HeightAlgoCalTable1_t sUssMgr_HA_WidthLowTable[US_D_HEIGHT_ALGO_WIDTH_TABLE_LEN] =
{
    { 200u, 700u }, //direcho, echo width us
    { 300u, 700u },
    { 400u, 700u },
    { 500u, 700u }
};
#define US_D_HEIGHT_ALGO_WIDTH_LOW_PASS_ADJ     (-4)

//there is no low fail, both low + high have to fail together
const US_S_HeightAlgoCalTable1_t sUssMgr_HA_WidthHighTable[US_D_HEIGHT_ALGO_WIDTH_TABLE_LEN] =
{
    { 200u, 750u },
    { 300u, 750u },
    { 400u, 750u },
    { 500u, 750u }
};
#endif
#define US_D_HEIGHT_ALGO_WIDTH_HIGH_PASS_ADJ     (3)
#define US_D_HEIGHT_ALGO_WIDTH_BOTH_FAIL_ADJ     (0u)



/* Local functions */
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
static uint8_t DetermineHeightConf(US_S_SnrCalcRec_t * sOneSensorCalcs, US_S_SensorRec_t * sOneSensorRec, uint8_t uStartingConf);
#endif
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
static sint16_t RunHeightAlgo(US_E_HeightAlgoStep_t eAlgoStep, US_S_SnrCalcRec_t * sOneSensorCalcs, US_S_SensorRec_t * sOneSensorRec);
static US_E_HeightAlgoStep_t SelectNextHeightAlgo(US_E_HeightAlgoStep_t eAlgoStep, US_E_HeightAlgoDir_t eAlgoDir);
#endif
static uint16_t HeightAlgoDistTable1Lookup(uint16_t uLookupDist, US_S_HeightAlgoCalTable1_t * psaTable, uint8_t uTableLen);
#if (US_D_HEIGHT_ALGO_STRENGTH_DISABLE == ME_FALSE)
static uint16_t HeightAlgoDistTable2Lookup(uint16_t uLookupDist, US_S_HeightAlgoCalTable2_t * psaTable, uint8_t uTableLen);
#endif

#if US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__ML_ADV
static void computeDecisionTree(const uint16_t dist1_cm, const uint16_t dist2_cm, const uint16_t dist3_cm, 
                         const uint16_t width1_us, const uint16_t width2_us, const uint16_t width3_us,
                         const uint16_t h1, const uint16_t h2, const uint16_t h3, 
                         bool_t *isHigh, uint8_t *puProbHigh); 
#endif
/* Global var */
static bool_t   b2ndEchoFromSameObj;
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
static bool_t   bOnlyCheckDbl_DontContinue;
#endif

/*** Public Functions ***/
/* ===========================================================================
 * Name:	 UssMgr_Reset_2ndEchoSameObjFlag
 * Remarks:  DD-ID: {5989FD2D-B088-46de-8BE3-80543A2AB2EF}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssMgr_Reset_2ndEchoSameObjFlag(void)
{
    b2ndEchoFromSameObj = ME_FALSE;
}
/* ===========================================================================
 * Name:	 UssMgr_Get_2ndEchoSameObjFlag
 * Remarks:  DD-ID: {D6031807-A189-4c7d-A98F-305ACCC960DC}
 * Req.-ID: 13424090
 * ===========================================================================*/
bool_t UssMgr_Get_2ndEchoSameObjFlag(void)
{
    return b2ndEchoFromSameObj;
}

/* ===========================================================================
 * Name:	 UssMgr_UpdateHeightGuessForSensor
 * Remarks:  DD-ID: {5382B93B-CD44-4f21-90DE-E02B333232B0}
 * Req.-ID: 13424090
 * ===========================================================================*/
bool_t UssMgr_UpdateHeightGuessForSensor(US_S_SnrCalcRec_t * sOneSensorCalcs, US_S_SensorRec_t * sOneSensorRec)
{
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
    bool_t  bRetStatus = E_NOT_OK;
    uint8_t uHeightConf;
    uint8_t uStartingConf = US_D_HEIGHT_ALGO_STARTING_CONF;
    US_S_SnrCalcRec_t   sOneSensorCalcs_copy;
    US_S_SensorRec_t    sOneSensorRec_copy;

    b2ndEchoFromSameObj = ME_FALSE;
    bOnlyCheckDbl_DontContinue = ME_FALSE;
    //make copy of echo data to prevent corruption of original data
    sOneSensorCalcs_copy = *sOneSensorCalcs;
    sOneSensorRec_copy = *sOneSensorRec;
    
    //TODO - do all this again, but after shifting echoes down 1, so 2nd echoes can be processed
    //   only if 1st/2nd did come from the same obj + there is a 3rd echo available

    //get height conf value
    uHeightConf = DetermineHeightConf(&sOneSensorCalcs_copy, &sOneSensorRec_copy, uStartingConf);

    if( (uHeightConf > US_D_HEIGHT_ALGO_SCALE_MAX) || (uHeightConf < US_D_HEIGHT_ALGO_SCALE_MIN) )
    {
        //well something went wrong
        bRetStatus = ME_NOT_OK;
    #if (US_D_HEIGHT_ALGO_SET_TO_DEFAULT_ON_FAIL == ME_TRUE)
        #if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__LOW)
        sOneSensorCalcs->sEchoCalc[ZERO].bLargeObject = ME_FALSE;
        #endif
        #if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__HIGH)
        sOneSensorCalcs->sEchoCalc[ZERO].bLargeObject = ME_TRUE;
        #endif
    #endif
    }
    else
    {
        if (uHeightConf <= US_D_HEIGHT_ALGO_LOW_MAX)
        {
            sOneSensorCalcs->sEchoCalc[ZERO].bLargeObject = ME_FALSE;

            //other echoes should already be low...
            //BUT
    #if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__HIGH)
            {
                uint8_t uEchoIndex;
                for( uEchoIndex = ONE; uEchoIndex < US_D_APP_MAX_ECHOES_BUFF; uEchoIndex++)
                {
                    sOneSensorCalcs->sEchoCalc[uEchoIndex].bLargeObject = ME_TRUE;
                }
            }
    #endif
        }
        /* Using another if instead of 'else if' in case 
        * someone makes High Min and Low Max the same value. 
        * If so I want high to be set even if default is unknown/low
        */
        if (uHeightConf >= US_D_HEIGHT_ALGO_HIGH_MIN)
        {
            /* 2nd/3rd/etc echoes can never be high with this.
            * which is OK since if the 2nd echo exists - means it's a different object,
            * and we don't have enough info for that
            */
    #if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__HIGH)
            {
                uint8_t uEchoIndex;
                for( uEchoIndex = ZERO; uEchoIndex < US_D_APP_MAX_ECHOES_BUFF; uEchoIndex++)
                {
                    sOneSensorCalcs->sEchoCalc[uEchoIndex].bLargeObject = ME_TRUE;
                }
            }
    #else
            sOneSensorCalcs->sEchoCalc[ZERO].bLargeObject = ME_TRUE;
    #endif
        }
        bRetStatus = E_OK;
    }
#endif //HEIGHT_ALGO_TYPE__LINEAR_SCALE

#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__ML_ADV)
    bool_t  bRetStatus = ME_NOT_OK;    
    bool_t  bIsHigh_Return = ME_FALSE;
    uint8_t puProbHigh_Return;
    US_S_SnrCalcRec_t   sOSC_copy;    
    US_S_Echo_t sEchoData[US_D_APP_MAX_ECHOES_BUFF];
    uint8_t uEchoIdx;

    b2ndEchoFromSameObj = ME_FALSE;
    //make copy of echo data to prevent corruption of original data
    sOSC_copy = *sOneSensorCalcs;
  
    /* if echo is deleted, uRecEchoIndex goes out of bounds - big bug if not handled like this */
    for (uEchoIdx = ZERO; uEchoIdx < US_D_APP_MAX_ECHOES_BUFF; uEchoIdx++)
    {
        if(sOSC_copy.sEchoCalc[uEchoIdx].uRecEchoIndex < US_D_APP_MAX_ECHOES_BUFF) //bound check
        {
            sEchoData[uEchoIdx] = sOneSensorRec->sEcho[sOSC_copy.sEchoCalc[uEchoIdx].uRecEchoIndex];
        }
        else
        {
            /* lazy way since only 2 struct items are used. If more are used, need to use struct copy to predefined blank */
            sEchoData[uEchoIdx].uWidth = ZERO;
            sEchoData[uEchoIdx].uEchoHeight = ZERO;
        }
    }
    //call ML algo
    computeDecisionTree(sOSC_copy.sEchoCalc[ZERO].uDirectDist_cm, sOSC_copy.sEchoCalc[ONE].uDirectDist_cm, sOSC_copy.sEchoCalc[TWO].uDirectDist_cm,
                        sEchoData[ZERO].uWidth, sEchoData[ONE].uWidth, sEchoData[TWO].uWidth,
                        sEchoData[ZERO].uEchoHeight, sEchoData[ONE].uEchoHeight, sEchoData[TWO].uEchoHeight,
                        &bIsHigh_Return, &puProbHigh_Return);

    //need to get 2nd echo info independently, it auto updates global
    (void)UssMgr_Calc_2ndEchoSameObjFlag(&sOSC_copy);

    //Save high/low status to echo data
    sOneSensorCalcs->sEchoCalc[ZERO].bLargeObject = bIsHigh_Return;    
    //handle the rest of the echoes based on default
    {
        uint8_t uEchoIndex;
        for( uEchoIndex = ONE; uEchoIndex < US_D_APP_MAX_ECHOES_BUFF; uEchoIndex++)
        {
    #if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__HIGH)
            sOneSensorCalcs->sEchoCalc[uEchoIndex].bLargeObject = ME_TRUE;  /* PRQA S 2841  */ 
    #endif
    #if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__LOW)
            sOneSensorCalcs->sEchoCalc[uEchoIndex].bLargeObject = ME_FALSE;
    #endif
            //sOneSensorCalcs->sEchoCalc[uEchoIndex].uHeightDebugInfo = 0xFE;
        }
    }

    bRetStatus = ME_OK;
    return bRetStatus
#endif //HEIGHT_ALGO_TYPE__ML_SIMPLE

    return ME_OK;
}


/* ===========================================================================
 * Name:	UssMgr_Calc_2ndEchoSameObjFlag
 * Remarks:  DD-ID: {FFD1D59C-4447-4866-9811-3B8401B09DEC}
 * Req.-ID:
 * Req.-ID: 13424090
 * ===========================================================================*/

/* !!This updates global b2ndEchoFromSameObj!! */
bool_t UssMgr_Calc_2ndEchoSameObjFlag(US_S_SnrCalcRec_t * sOneSensorCalcs)
{
    bool_t bIsSameObj = ME_FALSE;
    uint16_t uEchoDiff;
    uint16_t uDiffCal;
    uint16_t uToleranceCal;
    
const US_S_HeightAlgoCalTable1_t sUssMgr_MultiReflectTolTable[US_D_HEIGHT_ALGO_MULTI_REFLECT_TABLE_LEN] =
    {
        { 100u, 20u }, //direcho, tolerance(+/-) for 2x echo dist 
        { 200u, 30u },
        { 300u, 30u },
        { 500u, 30u }
    };
const US_S_HeightAlgoCalTable1_t sUssMgr_Close2ndEchoTable[US_D_HEIGHT_ALGO_CLOSE_2ND_TABLE_LEN] =
{
    { 100u, 30u }, //direcho, dist between 1st/2nd echo
    { 200u, 50u },
    { 300u, 50u },
    { 500u, 50u }
};

    if (sOneSensorCalcs->uNumEchoes > ONE)
    {
        uEchoDiff = sOneSensorCalcs->sEchoCalc[ONE].uDirectDist_cm - sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm;

        /* Look at close 2nd echo */
        uDiffCal = HeightAlgoDistTable1Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                (US_S_HeightAlgoCalTable1_t*)sUssMgr_Close2ndEchoTable, US_D_HEIGHT_ALGO_CLOSE_2ND_TABLE_LEN); /* PRQA S 0311 */ /* Write operations are not conducted on pointer */ 
        if( uEchoDiff <= uDiffCal )
        {
            //echoes close enough, passing
            bIsSameObj = ME_TRUE;
        }
        
        /* Look at double reflect echoes */
        uToleranceCal = HeightAlgoDistTable1Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                (US_S_HeightAlgoCalTable1_t*)sUssMgr_MultiReflectTolTable, US_D_HEIGHT_ALGO_MULTI_REFLECT_TABLE_LEN); /* PRQA S 0311 */ /* Write operations are not conducted on pointer */ 
        if( (uEchoDiff < (sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm + uToleranceCal))
            && (uEchoDiff > (sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm - uToleranceCal)) )
        {
            bIsSameObj = ME_TRUE;
        }

        /* Look at triple reflect echoes */
        uToleranceCal = HeightAlgoDistTable1Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                (US_S_HeightAlgoCalTable1_t*)sUssMgr_MultiReflectTolTable, US_D_HEIGHT_ALGO_MULTI_REFLECT_TABLE_LEN); /* PRQA S 0311 */ /* Write operations are not conducted on pointer */ 
        if( (uEchoDiff < ( (sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm * TWO) + uToleranceCal))
            && (uEchoDiff > ( (sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm * TWO) - uToleranceCal)) )
        {
            bIsSameObj = ME_TRUE;
        }
    }
    //save result to global
    b2ndEchoFromSameObj = bIsSameObj;

    return bIsSameObj;
}

#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
/*** Internal/Local only functions ***/
/* ===========================================================================
 * Name:	 UssMgr_DetermineHeightConf
 * Remarks:  DD-ID: {9B15A6DF-74AE-4a27-962B-0186A13D0337}
 * Req.-ID: 13424090
 * ===========================================================================*/
static uint8_t DetermineHeightConf(US_S_SnrCalcRec_t * sOneSensorCalcs, US_S_SensorRec_t * sOneSensorRec, uint8_t uStartingConf)
{
    uint8_t  uFinalConf;
    /* signed value remove needing under/overflow checks */
    sint16_t sCurrentConf = ZERO;
    sint16_t sAlgoResults;
    US_E_HeightAlgoStep_t   eAlgoStep = US_E_HEIGHT_ALGO_STEP__INIT;
    uint8_t uStepCnt;
    US_E_HeightAlgoDir_t    eAlgoDir = US_E_HAD_NONE;

#if (US_D_HEIGHT_ALGO_DEBUG_LOG_ENABLED == ME_TRUE)
    memset(&eaDEBUG_heightAlgoStepHistory, 0, DEBUG_HAS_HISTORY_ARRAY_SIZE*sizeof(US_E_HeightAlgoStep_t));
    memset(&eaDEBUG_heightAlgoValHistory, 0, DEBUG_HAS_HISTORY_ARRAY_SIZE*sizeof(sint16_t));
#endif

    //go through algo like a state machine
    for( uStepCnt = ZERO; uStepCnt < US_D_HEIGHT_ALGO_MAX_ALGO_STEPS; uStepCnt++)
    {
#if (US_D_HEIGHT_ALGO_DEBUG_LOG_ENABLED == ME_TRUE)
        eaDEBUG_heightAlgoStepHistory[uStepCnt] = eAlgoStep;
#endif
        //exit early if we hit the end
        if (eAlgoStep == US_E_HEIGHT_ALGO_STEP__END)
        {
            break;
        }
        //get the increase/decrease in height conf
        sAlgoResults = RunHeightAlgo(eAlgoStep, sOneSensorCalcs, sOneSensorRec);
#if (US_D_HEIGHT_ALGO_DEBUG_LOG_ENABLED == ME_TRUE)
        eaDEBUG_heightAlgoValHistory[uStepCnt] = sAlgoResults;
#endif
        //figure what direction that was
        if      (sAlgoResults > (sint16_t)ZERO)   {eAlgoDir = US_E_HAD_UP;}
        else if (sAlgoResults < (sint16_t)ZERO)   {eAlgoDir = US_E_HAD_DOWN;}
        else    /* is zero */           {eAlgoDir = US_E_HAD_NONE;}
        //save results
        sCurrentConf += sAlgoResults;
        //get next algo to run
        eAlgoStep = SelectNextHeightAlgo(eAlgoStep, eAlgoDir);
    }


    //add the starting conf for the current default mode
    sCurrentConf = sCurrentConf + uStartingConf;
    //check boundaries
    if      (sCurrentConf < (sint16_t)US_D_HEIGHT_ALGO_SCALE_MIN) { uFinalConf = US_D_HEIGHT_ALGO_SCALE_MIN;}
    else if (sCurrentConf > (sint16_t)US_D_HEIGHT_ALGO_SCALE_MAX) { uFinalConf = US_D_HEIGHT_ALGO_SCALE_MAX;}
    else    /* is within range already */
    {
        uFinalConf = (uint8_t)sCurrentConf;
    }

    return uFinalConf;
}

/* Runs the different types of height considerations in a modular way.
 * if more things get more complicated (indirects, prev step knowledge, etc) change
 * the eAlgoStep to a struct and pass all that info
 */
/* ===========================================================================
 * Name:	 UssMgr_RunHeightAlgo
 * Remarks:  DD-ID: {DF968102-AF80-4a70-BF95-F203F256758C}
 * Req.-ID: 13424090
 * ===========================================================================*/
static sint16_t RunHeightAlgo(US_E_HeightAlgoStep_t eAlgoStep, US_S_SnrCalcRec_t * sOneSensorCalcs, US_S_SensorRec_t * sOneSensorRec)
{
    sint16_t sRetConfChange = ZERO;

    //algo only works on direct echoes currently
    if ( sOneSensorCalcs->eEchoClass != US_E_DIRECT )
    {
        //sRetConfChange = error?
        return sRetConfChange;
    }

    switch(eAlgoStep)
    {
        case US_E_HEIGHT_ALGO_STEP__INIT:
        {
            //do nothing - there is no cal loading or anything currently
            //could look at taking the calc data and load all filter values? since it won't change at this stage.
            break;
        }

        case US_E_HAS__CLOSE_RANGE_FOV_ASSUMPTION:
        {
            //see if we're inside the high only area at close range
            if (sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm < US_D_HEIGHT_ALGO_CLOSE_RANGE_DIST_CM)
            {
                //nothing low can show up this close.
                sRetConfChange = US_D_HEIGHT_ALGO_CLOSE_RANGE_PASS_ADJ;
            }
            else
            {
                //it's further, apply that value.
                sRetConfChange = US_D_HEIGHT_ALGO_CLOSE_RANGE_FAIL_ADJ;
            }
            break;
        }

        case US_E_HAS__CLOSE_2ND_ECHO_CHECK:
        {
            uint16_t uEchoDiff;
            uint16_t uDiffCal;

            if (sOneSensorCalcs->uNumEchoes > ONE)
            {
                uEchoDiff = sOneSensorCalcs->sEchoCalc[ONE].uDirectDist_cm - sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm;
                uDiffCal = HeightAlgoDistTable1Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                        (US_S_HeightAlgoCalTable1_t*)sUssMgr_Close2ndEchoTable, US_D_HEIGHT_ALGO_CLOSE_2ND_TABLE_LEN);
                if( uEchoDiff <= uDiffCal )
                {
                    //echoes close enough, passing
                    sRetConfChange = US_D_HEIGHT_ALGO_CLOSE_2ND_PASS_ADJ;
                    b2ndEchoFromSameObj = ME_TRUE;
                }
                else
                {
                    sRetConfChange = US_D_HEIGHT_ALGO_CLOSE_2ND_FAIL_ADJ;
                }
            }
            break;
        }

        case US_E_HAS__FAR_2ND_ECHO_CHECK:
        {
            uint16_t uEchoDiff;
            uint16_t uDiffCal;

            if (sOneSensorCalcs->uNumEchoes > ONE)
            {
                uEchoDiff = sOneSensorCalcs->sEchoCalc[ONE].uDirectDist_cm - sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm;
                uDiffCal = HeightAlgoDistTable1Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                        (US_S_HeightAlgoCalTable1_t*)sUssMgr_Far2ndEchoTable, US_D_HEIGHT_ALGO_FAR_2ND_TABLE_LEN);
                if( uEchoDiff >= uDiffCal )
                {
                    //echoes far enough, passing
                    sRetConfChange = US_D_HEIGHT_ALGO_FAR_2ND_PASS_ADJ;
                }
                else
                {
                    sRetConfChange = US_D_HEIGHT_ALGO_FAR_2ND_FAIL_ADJ;
                }
            }
            break;
        }

        case US_E_HAS__MULTI_REFLECT_ECHO_CHECK:
        {
            uint16_t uEchoDiff;
            uint16_t uToleranceCal;

            if (sOneSensorCalcs->uNumEchoes > ONE)
            {
                uEchoDiff = sOneSensorCalcs->sEchoCalc[ONE].uDirectDist_cm - sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm;
                uToleranceCal = HeightAlgoDistTable1Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                        (US_S_HeightAlgoCalTable1_t*)sUssMgr_MultiReflectTolTable, US_D_HEIGHT_ALGO_MULTI_REFLECT_TABLE_LEN);
                if( (uEchoDiff < (sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm + uToleranceCal))
                    && (uEchoDiff > (sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm - uToleranceCal)) )
                {
                    //looks like double reflection, passing
                    sRetConfChange = US_D_HEIGHT_ALGO_MULTI_REFLECT_PASS_ADJ;
                    b2ndEchoFromSameObj = ME_TRUE;
                }
                else
                {
                    sRetConfChange = US_D_HEIGHT_ALGO_MULTI_REFLECT_FAIL_ADJ;
                }
            }
            break;
        }

        case US_E_HAS__SINGLE_ECHO_CHECK:
        {
            if (sOneSensorCalcs->uNumEchoes == ONE)
            {
                //only 1 echo, pass
                sRetConfChange = US_D_HEIGHT_ALGO_SINGLE_ECHO_PASS_ADJ;
            }
            else
            {
                sRetConfChange = US_D_HEIGHT_ALGO_SINGLE_ECHO_FAIL_ADJ;
            }
            break;
        }

        case US_E_HAS__ECHO_STRENGTH_CHECK:
        {
#if (US_D_HEIGHT_ALGO_STRENGTH_DISABLE == ME_TRUE)
            sRetConfChange = US_D_HEIGHT_ALGO_STRENGTH_BOTH_FAIL_ADJ;
#else
            //HeightAlgoDistTable2Lookup
            uint16_t uStrengthCal;
            uint16_t uStrengthSteps;
            uint8_t  uCalIndex;
            uint8_t  uRecIndex;

            uRecIndex = sOneSensorCalcs->sEchoCalc[ZERO].uRecEchoIndex;
            /* Check low */
            uCalIndex = HeightAlgoDistTable2Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                        sUssMgr_HA_StrLowTable, US_D_HEIGHT_ALGO_STRENGTH_TABLE_LEN);

            uStrengthCal = sUssMgr_HA_StrLowTable[uCalIndex].uFilterVal1;
            uStrengthSteps = sUssMgr_HA_StrLowTable[uCalIndex].uFilterVal2;

            if (sOneSensorRec->sEcho[uRecIndex].uEchoHeight <= uStrengthCal)
            {
                //weak enough, pass low
                sRetConfChange = US_D_HEIGHT_ALGO_STRENGTH_LOW_PASS_START;
                //check if echo strength is lower than cal + cal step, if so update conf change
                //step until strength is not lower or max strength adj is reached
                for (; sRetConfChange > US_D_HEIGHT_ALGO_STRENGTH_LOW_PASS_MAX; sRetConfChange--)
                {
                    if( (uStrengthCal - uStrengthSteps) < sOneSensorRec->sEcho[uRecIndex].uEchoHeight)
                    {
                        //strength is no longer lower, exit
                        break;
                    }
                }
            }
            else
            {
                //check high
                uCalIndex = HeightAlgoDistTable2Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                            sUssMgr_HA_StrHighTable, US_D_HEIGHT_ALGO_STRENGTH_TABLE_LEN);

                uStrengthCal = sUssMgr_HA_StrHighTable[uCalIndex].uFilterVal1;
                uStrengthSteps = sUssMgr_HA_StrHighTable[uCalIndex].uFilterVal2;

                if (sOneSensorRec->sEcho[uRecIndex].uEchoHeight >= uStrengthCal)
                {
                    //strong enough, pass high
                    sRetConfChange = US_D_HEIGHT_ALGO_STRENGTH_HIGH_PASS_START;
                    //check if steps possible
                    for (; sRetConfChange < (sint16_t)US_D_HEIGHT_ALGO_STRENGTH_HIGH_PASS_MAX; sRetConfChange++)
                    {
                        if( (uStrengthCal + uStrengthSteps) > sOneSensorRec->sEcho[uRecIndex].uEchoHeight)
                        {
                            //strength is not higher, exit
                            break;
                        }
                    }
                }
                else
                {
                    //between strong and weak, fail both
                    sRetConfChange = US_D_HEIGHT_ALGO_STRENGTH_BOTH_FAIL_ADJ;
                }
            }
#endif
            break;
        }

        case US_E_HAS__ECHO_WIDTH_CHECK:
        {
            uint16_t uWidthCal;
            uint8_t  uRecIndex;

            uRecIndex = sOneSensorCalcs->sEchoCalc[ZERO].uRecEchoIndex;
            /* Check low */
            uWidthCal = HeightAlgoDistTable1Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                        (US_S_HeightAlgoCalTable1_t*)sUssMgr_HA_WidthLowTable, US_D_HEIGHT_ALGO_WIDTH_TABLE_LEN);
            if (sOneSensorRec->sEcho[uRecIndex].uWidth <= uWidthCal)
            {
                //narrow enough, pass low
                sRetConfChange = US_D_HEIGHT_ALGO_WIDTH_LOW_PASS_ADJ;
            }
            else
            {
                //check high
                uWidthCal = HeightAlgoDistTable1Lookup(sOneSensorCalcs->sEchoCalc[ZERO].uDirectDist_cm, 
                                                            (US_S_HeightAlgoCalTable1_t*)sUssMgr_HA_WidthHighTable, US_D_HEIGHT_ALGO_WIDTH_TABLE_LEN);
                if (sOneSensorRec->sEcho[uRecIndex].uWidth >= uWidthCal)
                {
                    //wide enough, pass high
                    sRetConfChange = US_D_HEIGHT_ALGO_WIDTH_HIGH_PASS_ADJ;
                }
                else
                {
                    //between narrow and wide, fail both
                    sRetConfChange = US_D_HEIGHT_ALGO_WIDTH_BOTH_FAIL_ADJ;
                }
            }
            break;
        }

        case US_E_HEIGHT_ALGO_STEP__END:
        default:
        {
            //nothing so far. Not even called by upper function
            //maybe clean up and such in the future
            break;
        }
    }

    return sRetConfChange;
}
#endif
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
/* ===========================================================================
 * Name:	 UssMgr_SelectNextHeightAlgo
 * Remarks:  DD-ID: {639047C6-5C0B-4e0d-8DA2-6680353206E6}
 * Req.-ID: 13424090
 * ===========================================================================*/
static US_E_HeightAlgoStep_t SelectNextHeightAlgo(US_E_HeightAlgoStep_t eAlgoStep, US_E_HeightAlgoDir_t eAlgoDir)
{
    US_E_HeightAlgoStep_t eNextAlgoStep;

    switch(eAlgoStep)
    {
        case US_E_HEIGHT_ALGO_STEP__INIT:
        {
            //check default mode? for now everyone starts at close range
            eNextAlgoStep = US_E_HAS__CLOSE_RANGE_FOV_ASSUMPTION;
            break;
        }

        case US_E_HAS__CLOSE_RANGE_FOV_ASSUMPTION:
        {
            if(eAlgoDir != US_E_HAD_UP)
            {
                eNextAlgoStep = US_E_HAS__SINGLE_ECHO_CHECK;
            }
            else
            {
                bOnlyCheckDbl_DontContinue = ME_TRUE;                
                eNextAlgoStep = US_E_HAS__MULTI_REFLECT_ECHO_CHECK;
            }
            break;
        }

        case US_E_HAS__CLOSE_2ND_ECHO_CHECK:
        {
            eNextAlgoStep = US_E_HAS__MULTI_REFLECT_ECHO_CHECK;
            break;
        }

        case US_E_HAS__FAR_2ND_ECHO_CHECK:
        {
            eNextAlgoStep = US_E_HAS__ECHO_STRENGTH_CHECK;
            break;
        }

        case US_E_HAS__MULTI_REFLECT_ECHO_CHECK:
        {
            if(eAlgoDir == US_E_HAD_UP) //pass
            {
                if (bOnlyCheckDbl_DontContinue == ME_TRUE)
                {
                    eNextAlgoStep = US_E_HEIGHT_ALGO_STEP__END;
                }
                else
                {
                    eNextAlgoStep = US_E_HAS__ECHO_STRENGTH_CHECK;
                }
            }
            else
            {
                eNextAlgoStep = US_E_HAS__FAR_2ND_ECHO_CHECK;
            }
            break;
        }

        case US_E_HAS__SINGLE_ECHO_CHECK:
        {
            if(eAlgoDir == US_E_HAD_DOWN) //pass
            {
                eNextAlgoStep = US_E_HAS__ECHO_STRENGTH_CHECK;
            }
            else
            {
                eNextAlgoStep = US_E_HAS__CLOSE_2ND_ECHO_CHECK;
            }
            break;
        }

        case US_E_HAS__ECHO_STRENGTH_CHECK:
        {
            eNextAlgoStep = US_E_HAS__ECHO_WIDTH_CHECK;
            break;
        }

        case US_E_HAS__ECHO_WIDTH_CHECK:
        {
            eNextAlgoStep = US_E_HEIGHT_ALGO_STEP__END;
            break;
        }

        case US_E_HEIGHT_ALGO_STEP__END:
        default:
        {
            //nothing so far. Not even called by upper function
            //maybe clean up and such in the future
            eNextAlgoStep = US_E_HEIGHT_ALGO_STEP__END;
            break;
        }
    }

    return eNextAlgoStep;
}
#endif
/* ===========================================================================
 * Name:	 HeightAlgoDistTable1Lookup
 * Remarks:  DD-ID: {B896ED0A-C60B-49c6-BE76-F7EA7237AC4A}
 * Req.-ID: 13424090
 * ===========================================================================*/

/* Returns filter value of matching table item */
static uint16_t HeightAlgoDistTable1Lookup(uint16_t uLookupDist, US_S_HeightAlgoCalTable1_t * psaTable, uint8_t uTableLen)
{
    uint8_t uTableIdx;
    uint16_t uRetTableVal = ZERO;  //no safe default option available

    for (uTableIdx = 0; uTableIdx < uTableLen; uTableIdx++)
    {
        if ( uLookupDist < psaTable[uTableIdx].uEchoDirDist )
        {
            uRetTableVal = psaTable[uTableIdx].uFilterVal;
            break; //exit loop, matching table entry found
        }
    }
    return uRetTableVal;
}

#if (US_D_HEIGHT_ALGO_STRENGTH_DISABLE == ME_FALSE)
/* ===========================================================================
 * Name:	 HeightAlgoDistTable2Lookup
 * Remarks:  DD-ID: {7E4AFA66-12B7-4bf5-B0A9-60AF32D63C05}
 * Req.-ID: 13424090
 * ===========================================================================*/
/* Returns index of matching table item */
static uint16_t HeightAlgoDistTable2Lookup(uint16_t uLookupDist, US_S_HeightAlgoCalTable2_t * psaTable, uint8_t uTableLen)
{
    uint8_t uTableIdx = ZERO;

    for (uTableIdx = 0; uTableIdx < uTableLen; uTableIdx++)
    {
        if ( uLookupDist < psaTable[uTableIdx].uEchoDirDist )
        {
            break; //exit loop, matching table entry found
        }
    }
    return uTableIdx;
}
#endif
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__ML_ADV)
/*
  Automatically generated decision tree for height estimation
     generated on: 2023-10-12 22:16:49.383753
*/

/*   DECISION FEATURES
----------------------------------------------------------------------

         dist1_cm                      
         dist2_cm                      
         h1                            
         h2                            
         h1-h2                         
         abs(dist2_cm-dist1_cm)        
         abs(dist2_cm-2*dist1_cm)      
         abs(dist3_cm-2*dist1_cm)      
         abs(dist3_cm-2*dist2_cm)      
         dist2_cm-dist1_cm             
----------------------------------------------------------------------
*/
/*PRQA S 0816 ++ */


#include "US_MgrHeightAlgo.h"

#define H_THRESH_00_                   104
#define H_THRESH_00_L                  82
#define H_THRESH_00_R                  630
#define H_THRESH_00_RL                 380
#define H_THRESH_00_RR                 75
#define H_THRESH_00_RRL                730
#define H_THRESH_00_LL                 134
#define H_THRESH_00_LLL                98
#define H_THRESH_00_LLLL               152
#define H_THRESH_00_LLLR               179
#define H_THRESH_00_LLLRR              37
#define H_THRESH_00_RLL                302
#define H_THRESH_00_RLLL               -99
#define H_THRESH_00_RLLLL              69
#define H_THRESH_00_RLLLR              169

void computeDecisionTree_00(const uint16_t dist1_cm, const uint16_t dist2_cm, const uint16_t dist3_cm, 
                         const uint16_t width1_us, const uint16_t width2_us, const uint16_t width3_us,
                         const uint16_t h1, const uint16_t h2, const uint16_t h3, 
                         bool_t *isHigh, uint8_t *puProbHigh) 
{
   bool_t node_00_L       = (abs(dist2_cm-dist1_cm) <= H_THRESH_00_); //threshold=104
   bool_t node_00_R       = !node_00_L;
   bool_t node_00_LL      = node_00_L && (abs(dist2_cm-dist1_cm) <= H_THRESH_00_L); //threshold=82
   bool_t node_00_LR      = node_00_L && !node_00_LL; //leaf_id=4, prob_high = 0.701
   bool_t node_00_RL      = node_00_R && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_00_R); //threshold=630  
   bool_t node_00_RR      = node_00_R && !node_00_RL;
   bool_t node_00_RLL     = node_00_RL && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_00_RL); //threshold=380
   bool_t node_00_RLR     = node_00_RL && !node_00_RLL; //leaf_id=11, prob_high = 0.273
   bool_t node_00_RRL     = node_00_RR && (h1-h2 <= H_THRESH_00_RR); //threshold=75
   bool_t node_00_RRR     = node_00_RR && !node_00_RRL; //leaf_id=1, prob_high = 0.402
   bool_t node_00_RRLL    = node_00_RRL && (abs(dist3_cm-2*dist1_cm) <= H_THRESH_00_RRL); //threshold=730, leaf_id=2, prob_high = 0.378
   bool_t node_00_RRLR    = node_00_RRL && !node_00_RRLL; //leaf_id=3, prob_high = 0.899
   bool_t node_00_LLL     = node_00_LL && (h1 <= H_THRESH_00_LL); //threshold=134
   bool_t node_00_LLR     = node_00_LL && !node_00_LLL; //leaf_id=5, prob_high = 0.979
   bool_t node_00_LLLL    = node_00_LLL && (dist2_cm <= H_THRESH_00_LLL); //threshold=98
   bool_t node_00_LLLR    = node_00_LLL && !node_00_LLLL;
   bool_t node_00_LLLLL   = node_00_LLLL && (abs(dist3_cm-2*dist1_cm) <= H_THRESH_00_LLLL); //threshold=152, leaf_id=6, prob_high = 0.961
   bool_t node_00_LLLLR   = node_00_LLLL && !node_00_LLLLL; //leaf_id=7, prob_high = 0.527
   bool_t node_00_LLLRL   = node_00_LLLR && (dist2_cm <= H_THRESH_00_LLLR); //threshold=179, leaf_id=8, prob_high = 0.389
   bool_t node_00_LLLRR   = node_00_LLLR && !node_00_LLLRL;
   bool_t node_00_LLLRRL  = node_00_LLLRR && (dist2_cm-dist1_cm <= H_THRESH_00_LLLRR); //threshold=37, leaf_id=9, prob_high = 0.849
   bool_t node_00_LLLRRR  = node_00_LLLRR && !node_00_LLLRRL; //leaf_id=10, prob_high = 0.210
   bool_t node_00_RLLL    = node_00_RLL && (dist2_cm-dist1_cm <= H_THRESH_00_RLL); //threshold=302
   bool_t node_00_RLLR    = node_00_RLL && !node_00_RLLL; //leaf_id=12, prob_high = 0.151
   bool_t node_00_RLLLL   = node_00_RLLL && (dist2_cm-dist1_cm <= H_THRESH_00_RLLL); //threshold=-99
   bool_t node_00_RLLLR   = node_00_RLLL && !node_00_RLLLL;
   bool_t node_00_RLLLLL  = node_00_RLLLL && (h1 <= H_THRESH_00_RLLLL); //threshold=69, leaf_id=15, prob_high = 0.498
   bool_t node_00_RLLLLR  = node_00_RLLLL && !node_00_RLLLLL; //leaf_id=16, prob_high = 0.317
   bool_t node_00_RLLLRL  = node_00_RLLLR && (h1 <= H_THRESH_00_RLLLR); //threshold=169, leaf_id=13, prob_high = 0.318
   bool_t node_00_RLLLRR  = node_00_RLLLR && !node_00_RLLLRL; //leaf_id=14, prob_high = 0.886

   *isHigh = node_00_RRLR || node_00_LR || node_00_LLR || node_00_LLLLL || node_00_LLLLR || node_00_LLLRRL || node_00_RLLLRR;

   if (0) {}
   else if (node_00_RRR)                   {*puProbHigh = 102u;}//0.402
   else if (node_00_RRLL)                  {*puProbHigh =  96u;}//0.378
   else if (node_00_RRLR)                  {*puProbHigh = 229u;}//0.899
   else if (node_00_LR)                    {*puProbHigh = 178u;}//0.701
   else if (node_00_LLR)                   {*puProbHigh = 249u;}//0.979
   else if (node_00_LLLLL)                 {*puProbHigh = 245u;}//0.961
   else if (node_00_LLLLR)                 {*puProbHigh = 134u;}//0.527
   else if (node_00_LLLRL)                 {*puProbHigh =  99u;}//0.389
   else if (node_00_LLLRRL)                {*puProbHigh = 216u;}//0.849
   else if (node_00_LLLRRR)                {*puProbHigh =  53u;}//0.210
   else if (node_00_RLR)                   {*puProbHigh =  69u;}//0.273
   else if (node_00_RLLR)                  {*puProbHigh =  38u;}//0.151
   else if (node_00_RLLLRL)                {*puProbHigh =  81u;}//0.318
   else if (node_00_RLLLRR)                {*puProbHigh = 225u;}//0.886
   else if (node_00_RLLLLL)                {*puProbHigh = 127u;}//0.498
   else if (node_00_RLLLLR)                {*puProbHigh =  80u;} /*0.317*/  /* PRQA S 2991, 2995 */ /*Sanity purpose */
   else                                    {*puProbHigh = 127u;}
}

#define H_THRESH_01_                   188
#define H_THRESH_01_L                  79
#define H_THRESH_01_R                  312
#define H_THRESH_01_LR                 266
#define H_THRESH_01_LRL                223
#define H_THRESH_01_LRLL               147
#define H_THRESH_01_LRLR               129
#define H_THRESH_01_LRLLL              201
#define H_THRESH_01_RL                 113
#define H_THRESH_01_RR                 485
#define H_THRESH_01_LRLLLL             101
#define H_THRESH_01_RRL                140
#define H_THRESH_01_RRLL               367
#define H_THRESH_01_RLL                58
#define H_THRESH_01_RLR                124

void computeDecisionTree_01(const uint16_t dist1_cm, const uint16_t dist2_cm, const uint16_t dist3_cm, 
                         const uint16_t width1_us, const uint16_t width2_us, const uint16_t width3_us,
                         const uint16_t h1, const uint16_t h2, const uint16_t h3, 
                         bool_t *isHigh, uint8_t *puProbHigh) 
{
   bool_t node_01_L       = (abs(dist2_cm-dist1_cm) <= H_THRESH_01_); //threshold=188
   bool_t node_01_R       = !node_01_L;
   bool_t node_01_LL      = node_01_L && (dist1_cm <= H_THRESH_01_L); //threshold=79, leaf_id=1, prob_high = 0.968
   bool_t node_01_LR      = node_01_L && !node_01_LL;
   bool_t node_01_RL      = node_01_R && (dist1_cm <= H_THRESH_01_R); //threshold=312
   bool_t node_01_RR      = node_01_R && !node_01_RL;
   bool_t node_01_LRL     = node_01_LR && (dist1_cm <= H_THRESH_01_LR); //threshold=266
   bool_t node_01_LRR     = node_01_LR && !node_01_LRL; //leaf_id=2, prob_high = 0.956
   bool_t node_01_LRLL    = node_01_LRL && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_01_LRL); //threshold=223
   bool_t node_01_LRLR    = node_01_LRL && !node_01_LRLL;
   bool_t node_01_LRLLL   = node_01_LRLL && (h1 <= H_THRESH_01_LRLL); //threshold=147
   bool_t node_01_LRLLR   = node_01_LRLL && !node_01_LRLLL; //leaf_id=3, prob_high = 0.951
   bool_t node_01_LRLRL   = node_01_LRLR && (h1-h2 <= H_THRESH_01_LRLR); //threshold=129, leaf_id=9, prob_high = 0.393
   bool_t node_01_LRLRR   = node_01_LRLR && !node_01_LRLRL; //leaf_id=10, prob_high = 0.227
   bool_t node_01_LRLLLL  = node_01_LRLLL && (abs(dist3_cm-2*dist2_cm) <= H_THRESH_01_LRLLL); //threshold=201
   bool_t node_01_LRLLLR  = node_01_LRLLL && !node_01_LRLLLL; //leaf_id=4, prob_high = 0.236
   bool_t node_01_RLL     = node_01_RL && (h1 <= H_THRESH_01_RL); //threshold=113
   bool_t node_01_RLR     = node_01_RL && !node_01_RLL;
   bool_t node_01_RRL     = node_01_RR && (dist1_cm <= H_THRESH_01_RR); //threshold=485
   bool_t node_01_RRR     = node_01_RR && !node_01_RRL; //leaf_id=7, prob_high = 0.699
   bool_t node_01_LRLLLLL = node_01_LRLLLL && (h1 <= H_THRESH_01_LRLLLL); //threshold=101, leaf_id=5, prob_high = 0.504
   bool_t node_01_LRLLLLR = node_01_LRLLLL && !node_01_LRLLLLL; //leaf_id=6, prob_high = 0.861
   bool_t node_01_RRLL    = node_01_RRL && (h1-h2 <= H_THRESH_01_RRL); //threshold=140
   bool_t node_01_RRLR    = node_01_RRL && !node_01_RRLL; //leaf_id=8, prob_high = 0.308
   bool_t node_01_RRLLL   = node_01_RRLL && (abs(dist2_cm-dist1_cm) <= H_THRESH_01_RRLL); //threshold=367, leaf_id=15, prob_high = 0.412
   bool_t node_01_RRLLR   = node_01_RRLL && !node_01_RRLLL; //leaf_id=16, prob_high = 0.652
   bool_t node_01_RLLL    = node_01_RLL && (h1 <= H_THRESH_01_RLL); //threshold=58, leaf_id=13, prob_high = 0.504
   bool_t node_01_RLLR    = node_01_RLL && !node_01_RLLL; //leaf_id=14, prob_high = 0.273
   bool_t node_01_RLRL    = node_01_RLR && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_01_RLR); //threshold=124, leaf_id=11, prob_high = 0.764
   bool_t node_01_RLRR    = node_01_RLR && !node_01_RLRL; //leaf_id=12, prob_high = 0.117

   *isHigh = node_01_LL || node_01_LRR || node_01_LRLLR || node_01_LRLLLLL || node_01_LRLLLLR || node_01_RRR || node_01_RLRL || node_01_RLLL || node_01_RRLLR;

   if (0) {}
   else if (node_01_LL)                    {*puProbHigh = 246u;}//0.968
   else if (node_01_LRR)                   {*puProbHigh = 243u;}//0.956
   else if (node_01_LRLLR)                 {*puProbHigh = 242u;}//0.951
   else if (node_01_LRLLLR)                {*puProbHigh =  60u;}//0.236
   else if (node_01_LRLLLLL)               {*puProbHigh = 128u;}//0.504
   else if (node_01_LRLLLLR)               {*puProbHigh = 219u;}//0.861
   else if (node_01_RRR)                   {*puProbHigh = 178u;}//0.699
   else if (node_01_RRLR)                  {*puProbHigh =  78u;}//0.308
   else if (node_01_LRLRL)                 {*puProbHigh = 100u;}//0.393
   else if (node_01_LRLRR)                 {*puProbHigh =  57u;}//0.227
   else if (node_01_RLRL)                  {*puProbHigh = 194u;}//0.764
   else if (node_01_RLRR)                  {*puProbHigh =  29u;}//0.117
   else if (node_01_RLLL)                  {*puProbHigh = 128u;}//0.504
   else if (node_01_RLLR)                  {*puProbHigh =  69u;}//0.273
   else if (node_01_RRLLL)                 {*puProbHigh = 104u;}//0.412
   else if (node_01_RRLLR)                 {*puProbHigh = 166u;}/*0.652 */ /* PRQA S 2991, 2995 */ /*Sanity purpose */
   else                                    {*puProbHigh = 127u;}
}

#define H_THRESH_02_                   118
#define H_THRESH_02_L                  125
#define H_THRESH_02_R                  348
#define H_THRESH_02_LR                 179
#define H_THRESH_02_RL                 126
#define H_THRESH_02_RR                 -141
#define H_THRESH_02_LRL                101
#define H_THRESH_02_LRR                120
#define H_THRESH_02_LRRL               130
#define H_THRESH_02_RRL                1070
#define H_THRESH_02_RLR                1
#define H_THRESH_02_RLRR               351
#define H_THRESH_02_RRLL               84
#define H_THRESH_02_RRLLL              371
#define H_THRESH_02_LRRLL              107

void computeDecisionTree_02(const uint16_t dist1_cm, const uint16_t dist2_cm, const uint16_t dist3_cm, 
                         const uint16_t width1_us, const uint16_t width2_us, const uint16_t width3_us,
                         const uint16_t h1, const uint16_t h2, const uint16_t h3, 
                         bool_t *isHigh, uint8_t *puProbHigh) 
{
   bool_t node_02_L       = (dist1_cm <= H_THRESH_02_); //threshold=118
   bool_t node_02_R       = !node_02_L;
   bool_t node_02_LL      = node_02_L && (abs(dist3_cm-2*dist1_cm) <= H_THRESH_02_L); //threshold=125, leaf_id=1, prob_high = 0.976
   bool_t node_02_LR      = node_02_L && !node_02_LL;
   bool_t node_02_RL      = node_02_R && (dist1_cm <= H_THRESH_02_R); //threshold=348
   bool_t node_02_RR      = node_02_R && !node_02_RL;
   bool_t node_02_LRL     = node_02_LR && (abs(dist3_cm-2*dist1_cm) <= H_THRESH_02_LR); //threshold=179
   bool_t node_02_LRR     = node_02_LR && !node_02_LRL;
   bool_t node_02_RLL     = node_02_RL && (h1-h2 <= H_THRESH_02_RL); //threshold=126, leaf_id=6, prob_high = 0.388
   bool_t node_02_RLR     = node_02_RL && !node_02_RLL;
   bool_t node_02_RRL     = node_02_RR && (dist2_cm-dist1_cm <= H_THRESH_02_RR); //threshold=-141
   bool_t node_02_RRR     = node_02_RR && !node_02_RRL; //leaf_id=5, prob_high = 0.986
   bool_t node_02_LRLL    = node_02_LRL && (h1-h2 <= H_THRESH_02_LRL); //threshold=101, leaf_id=3, prob_high = 0.567
   bool_t node_02_LRLR    = node_02_LRL && !node_02_LRLL; //leaf_id=4, prob_high = 0.993
   bool_t node_02_LRRL    = node_02_LRR && (h1-h2 <= H_THRESH_02_LRR); //threshold=120
   bool_t node_02_LRRR    = node_02_LRR && !node_02_LRRL; //leaf_id=2, prob_high = 0.870
   bool_t node_02_LRRLL   = node_02_LRRL && (dist2_cm-dist1_cm <= H_THRESH_02_LRRL); //threshold=130
   bool_t node_02_LRRLR   = node_02_LRRL && !node_02_LRRLL; //leaf_id=14, prob_high = 0.109
   bool_t node_02_RRLL    = node_02_RRL && (abs(dist3_cm-2*dist1_cm) <= H_THRESH_02_RRL); //threshold=1070
   bool_t node_02_RRLR    = node_02_RRL && !node_02_RRLL; //leaf_id=10, prob_high = 0.882
   bool_t node_02_RLRL    = node_02_RLR && (h2 <= H_THRESH_02_RLR); //threshold=1, leaf_id=7, prob_high = 0.159
   bool_t node_02_RLRR    = node_02_RLR && !node_02_RLRL;
   bool_t node_02_RLRRL   = node_02_RLRR && (abs(dist2_cm-dist1_cm) <= H_THRESH_02_RLRR); //threshold=351, leaf_id=8, prob_high = 0.861
   bool_t node_02_RLRRR   = node_02_RLRR && !node_02_RLRRL; //leaf_id=9, prob_high = 0.001
   bool_t node_02_RRLLL   = node_02_RRLL && (h1 <= H_THRESH_02_RRLL); //threshold=84
   bool_t node_02_RRLLR   = node_02_RRLL && !node_02_RRLLL; //leaf_id=11, prob_high = 0.387
   bool_t node_02_RRLLLL  = node_02_RRLLL && (abs(dist2_cm-dist1_cm) <= H_THRESH_02_RRLLL); //threshold=371, leaf_id=12, prob_high = 0.361
   bool_t node_02_RRLLLR  = node_02_RRLLL && !node_02_RRLLLL; //leaf_id=13, prob_high = 0.879
   bool_t node_02_LRRLLL  = node_02_LRRLL && (abs(dist2_cm-dist1_cm) <= H_THRESH_02_LRRLL); //threshold=107, leaf_id=15, prob_high = 0.522
   bool_t node_02_LRRLLR  = node_02_LRRLL && !node_02_LRRLLL; //leaf_id=16, prob_high = 0.278

   *isHigh = node_02_LL || node_02_LRRR || node_02_LRLL || node_02_LRLR || node_02_RRR || node_02_RLRRL || node_02_RRLR || node_02_RRLLLR || node_02_LRRLLL;

   if (0) {}
   else if (node_02_LL)                    {*puProbHigh = 248u;}//0.976
   else if (node_02_LRRR)                  {*puProbHigh = 221u;}//0.870
   else if (node_02_LRLL)                  {*puProbHigh = 144u;}//0.567
   else if (node_02_LRLR)                  {*puProbHigh = 253u;}//0.993
   else if (node_02_RRR)                   {*puProbHigh = 251u;}//0.986
   else if (node_02_RLL)                   {*puProbHigh =  98u;}//0.388
   else if (node_02_RLRL)                  {*puProbHigh =  40u;}//0.159
   else if (node_02_RLRRL)                 {*puProbHigh = 219u;}//0.861
   else if (node_02_RLRRR)                 {*puProbHigh =   0u;}//0.001
   else if (node_02_RRLR)                  {*puProbHigh = 224u;}//0.882
   else if (node_02_RRLLR)                 {*puProbHigh =  98u;}//0.387
   else if (node_02_RRLLLL)                {*puProbHigh =  92u;}//0.361
   else if (node_02_RRLLLR)                {*puProbHigh = 224u;}//0.879
   else if (node_02_LRRLR)                 {*puProbHigh =  27u;}//0.109
   else if (node_02_LRRLLL)                {*puProbHigh = 133u;}//0.522
   else if (node_02_LRRLLR)                {*puProbHigh =  70u;}/*0.278 */ /* PRQA S 2991 */ /*Sanity purpose */
   else                                    {*puProbHigh = 127u;}
}

#define H_THRESH_03_                   222
#define H_THRESH_03_L                  128
#define H_THRESH_03_R                  507
#define H_THRESH_03_LR                 177
#define H_THRESH_03_LRL                144
#define H_THRESH_03_LRLL               45
#define H_THRESH_03_RL                 84
#define H_THRESH_03_RLL                252
#define H_THRESH_03_RLR                801
#define H_THRESH_03_RLLR               51
#define H_THRESH_03_RLRL               83
#define H_THRESH_03_RLRR               98
#define H_THRESH_03_LRLLR              121
#define H_THRESH_03_LRLLRL             60
#define H_THRESH_03_LRLLRLR            110

void computeDecisionTree_03(const uint16_t dist1_cm, const uint16_t dist2_cm, const uint16_t dist3_cm, 
                         const uint16_t width1_us, const uint16_t width2_us, const uint16_t width3_us,
                         const uint16_t h1, const uint16_t h2, const uint16_t h3, 
                         bool_t *isHigh, uint8_t *puProbHigh) 
{
   bool_t node_03_L       = (abs(dist3_cm-2*dist1_cm) <= H_THRESH_03_); //threshold=222
   bool_t node_03_R       = !node_03_L;
   bool_t node_03_LL      = node_03_L && (abs(dist3_cm-2*dist1_cm) <= H_THRESH_03_L); //threshold=128, leaf_id=1, prob_high = 0.952
   bool_t node_03_LR      = node_03_L && !node_03_LL;
   bool_t node_03_RL      = node_03_R && (dist1_cm <= H_THRESH_03_R); //threshold=507
   bool_t node_03_RR      = node_03_R && !node_03_RL; //leaf_id=4, prob_high = 0.897
   bool_t node_03_LRL     = node_03_LR && (abs(dist2_cm-dist1_cm) <= H_THRESH_03_LR); //threshold=177
   bool_t node_03_LRR     = node_03_LR && !node_03_LRL; //leaf_id=2, prob_high = 0.144
   bool_t node_03_LRLL    = node_03_LRL && (h1 <= H_THRESH_03_LRL); //threshold=144
   bool_t node_03_LRLR    = node_03_LRL && !node_03_LRLL; //leaf_id=3, prob_high = 0.991
   bool_t node_03_LRLLL   = node_03_LRLL && (h1 <= H_THRESH_03_LRLL); //threshold=45, leaf_id=10, prob_high = 0.952
   bool_t node_03_LRLLR   = node_03_LRLL && !node_03_LRLLL;
   bool_t node_03_RLL     = node_03_RL && (abs(dist2_cm-dist1_cm) <= H_THRESH_03_RL); //threshold=84
   bool_t node_03_RLR     = node_03_RL && !node_03_RLL;
   bool_t node_03_RLLL    = node_03_RLL && (dist2_cm <= H_THRESH_03_RLL); //threshold=252, leaf_id=5, prob_high = 0.444
   bool_t node_03_RLLR    = node_03_RLL && !node_03_RLLL;
   bool_t node_03_RLRL    = node_03_RLR && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_03_RLR); //threshold=801
   bool_t node_03_RLRR    = node_03_RLR && !node_03_RLRL;
   bool_t node_03_RLLRL   = node_03_RLLR && (abs(dist2_cm-dist1_cm) <= H_THRESH_03_RLLR); //threshold=51, leaf_id=13, prob_high = 0.947
   bool_t node_03_RLLRR   = node_03_RLLR && !node_03_RLLRL; //leaf_id=14, prob_high = 0.288
   bool_t node_03_RLRLL   = node_03_RLRL && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_03_RLRL); //threshold=83, leaf_id=8, prob_high = 0.657
   bool_t node_03_RLRLR   = node_03_RLRL && !node_03_RLRLL; //leaf_id=9, prob_high = 0.320
   bool_t node_03_RLRRL   = node_03_RLRR && (h1 <= H_THRESH_03_RLRR); //threshold=98, leaf_id=6, prob_high = 0.819
   bool_t node_03_RLRRR   = node_03_RLRR && !node_03_RLRRL; //leaf_id=7, prob_high = 0.364
   bool_t node_03_LRLLRL  = node_03_LRLLR && (h1 <= H_THRESH_03_LRLLR); //threshold=121
   bool_t node_03_LRLLRR  = node_03_LRLLR && !node_03_LRLLRL; //leaf_id=11, prob_high = 0.867
   bool_t node_03_LRLLRLL = node_03_LRLLRL && (h1 <= H_THRESH_03_LRLLRL); //threshold=60, leaf_id=12, prob_high = 0.805
   bool_t node_03_LRLLRLR = node_03_LRLLRL && !node_03_LRLLRLL;
   bool_t node_03_LRLLRLRL = node_03_LRLLRLR && (h1 <= H_THRESH_03_LRLLRLR); //threshold=110, leaf_id=15, prob_high = 0.354
   bool_t node_03_LRLLRLRR = node_03_LRLLRLR && !node_03_LRLLRLRL; //leaf_id=16, prob_high = 0.932

   *isHigh = node_03_LL || node_03_LRLR || node_03_RR || node_03_RLRRL || node_03_RLRLL || node_03_LRLLL || node_03_LRLLRR || node_03_LRLLRLL || node_03_RLLRL || node_03_LRLLRLRR;

   if (0) {}
   else if (node_03_LL)                    {*puProbHigh = 242u;}//0.952
   else if (node_03_LRR)                   {*puProbHigh =  36u;}//0.144
   else if (node_03_LRLR)                  {*puProbHigh = 252u;}//0.991
   else if (node_03_RR)                    {*puProbHigh = 228u;}//0.897
   else if (node_03_RLLL)                  {*puProbHigh = 113u;}//0.444
   else if (node_03_RLRRL)                 {*puProbHigh = 208u;}//0.819
   else if (node_03_RLRRR)                 {*puProbHigh =  92u;}//0.364
   else if (node_03_RLRLL)                 {*puProbHigh = 167u;}//0.657
   else if (node_03_RLRLR)                 {*puProbHigh =  81u;}//0.320
   else if (node_03_LRLLL)                 {*puProbHigh = 242u;}//0.952
   else if (node_03_LRLLRR)                {*puProbHigh = 221u;}//0.867
   else if (node_03_LRLLRLL)               {*puProbHigh = 205u;}//0.805
   else if (node_03_RLLRL)                 {*puProbHigh = 241u;}//0.947
   else if (node_03_RLLRR)                 {*puProbHigh =  73u;}//0.288
   else if (node_03_LRLLRLRL)              {*puProbHigh =  90u;}//0.354
   else if (node_03_LRLLRLRR)              {*puProbHigh = 237u;}/*0.932*/  /* PRQA S 2991, 2995 */ /*Sanity purpose */
   else                                    {*puProbHigh = 127u;}
}

#define H_THRESH_04_                   66
#define H_THRESH_04_L                  8
#define H_THRESH_04_R                  836
#define H_THRESH_04_LR                 225
#define H_THRESH_04_LRR                122
#define H_THRESH_04_RL                 214
#define H_THRESH_04_RR                 1042
#define H_THRESH_04_RLL                343
#define H_THRESH_04_RLR                131
#define H_THRESH_04_RLLL               213
#define H_THRESH_04_RLLR               54
#define H_THRESH_04_RLLLL              159
#define H_THRESH_04_RLLLLL             175
#define H_THRESH_04_RLLLLR             51
#define H_THRESH_04_RLLRL              743

void computeDecisionTree_04(const uint16_t dist1_cm, const uint16_t dist2_cm, const uint16_t dist3_cm, 
                         const uint16_t width1_us, const uint16_t width2_us, const uint16_t width3_us,
                         const uint16_t h1, const uint16_t h2, const uint16_t h3, 
                         bool_t *isHigh, uint8_t *puProbHigh) 
{
   bool_t node_04_L       = (abs(dist2_cm-dist1_cm) <= H_THRESH_04_); //threshold=66
   bool_t node_04_R       = !node_04_L;
   bool_t node_04_LL      = node_04_L && (abs(dist2_cm-dist1_cm) <= H_THRESH_04_L); //threshold=8, leaf_id=1, prob_high = 0.500
   bool_t node_04_LR      = node_04_L && !node_04_LL;
   bool_t node_04_RL      = node_04_R && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_04_R); //threshold=836
   bool_t node_04_RR      = node_04_R && !node_04_RL;
   bool_t node_04_LRL     = node_04_LR && (abs(dist3_cm-2*dist2_cm) <= H_THRESH_04_LR); //threshold=225, leaf_id=2, prob_high = 0.958
   bool_t node_04_LRR     = node_04_LR && !node_04_LRL;
   bool_t node_04_LRRL    = node_04_LRR && (h1 <= H_THRESH_04_LRR); //threshold=122, leaf_id=3, prob_high = 0.494
   bool_t node_04_LRRR    = node_04_LRR && !node_04_LRRL; //leaf_id=4, prob_high = 0.988
   bool_t node_04_RLL     = node_04_RL && (h1 <= H_THRESH_04_RL); //threshold=214
   bool_t node_04_RLR     = node_04_RL && !node_04_RLL;
   bool_t node_04_RRL     = node_04_RR && (abs(dist3_cm-2*dist1_cm) <= H_THRESH_04_RR); //threshold=1042, leaf_id=15, prob_high = 0.526
   bool_t node_04_RRR     = node_04_RR && !node_04_RRL; //leaf_id=16, prob_high = 0.891
   bool_t node_04_RLLL    = node_04_RLL && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_04_RLL); //threshold=343
   bool_t node_04_RLLR    = node_04_RLL && !node_04_RLLL;
   bool_t node_04_RLRL    = node_04_RLR && (dist1_cm <= H_THRESH_04_RLR); //threshold=131, leaf_id=5, prob_high = 0.929
   bool_t node_04_RLRR    = node_04_RLR && !node_04_RLRL; //leaf_id=6, prob_high = 0.186
   bool_t node_04_RLLLL   = node_04_RLLL && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_04_RLLL); //threshold=213
   bool_t node_04_RLLLR   = node_04_RLLL && !node_04_RLLLL; //leaf_id=7, prob_high = 0.345
   bool_t node_04_RLLRL   = node_04_RLLR && (h1-h2 <= H_THRESH_04_RLLR); //threshold=54
   bool_t node_04_RLLRR   = node_04_RLLR && !node_04_RLLRL; //leaf_id=10, prob_high = 0.301
   bool_t node_04_RLLLLL  = node_04_RLLLL && (dist2_cm-dist1_cm <= H_THRESH_04_RLLLL); //threshold=159
   bool_t node_04_RLLLLR  = node_04_RLLLL && !node_04_RLLLLL;
   bool_t node_04_RLLLLLL = node_04_RLLLLL && (h1 <= H_THRESH_04_RLLLLL); //threshold=175, leaf_id=13, prob_high = 0.651
   bool_t node_04_RLLLLLR = node_04_RLLLLL && !node_04_RLLLLLL; //leaf_id=14, prob_high = 0.997
   bool_t node_04_RLLLLRL = node_04_RLLLLR && (abs(dist2_cm-2*dist1_cm) <= H_THRESH_04_RLLLLR); //threshold=51, leaf_id=8, prob_high = 0.775
   bool_t node_04_RLLLLRR = node_04_RLLLLR && !node_04_RLLLLRL; //leaf_id=9, prob_high = 0.160
   bool_t node_04_RLLRLL  = node_04_RLLRL && (abs(dist3_cm-2*dist1_cm) <= H_THRESH_04_RLLRL); //threshold=743, leaf_id=11, prob_high = 0.432
   bool_t node_04_RLLRLR  = node_04_RLLRL && !node_04_RLLRLL; //leaf_id=12, prob_high = 0.962

   *isHigh = node_04_LL || node_04_LRL || node_04_LRRR || node_04_RLRL || node_04_RLLLLRL || node_04_RLLRLR || node_04_RLLLLLL || node_04_RLLLLLR || node_04_RRL || node_04_RRR;

   if (0) {}
   else if (node_04_LL)                    {*puProbHigh = 127u;}//0.500
   else if (node_04_LRL)                   {*puProbHigh = 244u;}//0.958
   else if (node_04_LRRL)                  {*puProbHigh = 126u;}//0.494
   else if (node_04_LRRR)                  {*puProbHigh = 252u;}//0.988
   else if (node_04_RLRL)                  {*puProbHigh = 236u;}//0.929
   else if (node_04_RLRR)                  {*puProbHigh =  47u;}//0.186
   else if (node_04_RLLLR)                 {*puProbHigh =  87u;}//0.345
   else if (node_04_RLLLLRL)               {*puProbHigh = 197u;}//0.775
   else if (node_04_RLLLLRR)               {*puProbHigh =  40u;}//0.160
   else if (node_04_RLLRR)                 {*puProbHigh =  76u;}//0.301
   else if (node_04_RLLRLL)                {*puProbHigh = 110u;}//0.432
   else if (node_04_RLLRLR)                {*puProbHigh = 245u;}//0.962
   else if (node_04_RLLLLLL)               {*puProbHigh = 166u;}//0.651
   else if (node_04_RLLLLLR)               {*puProbHigh = 254u;}//0.997
   else if (node_04_RRL)                   {*puProbHigh = 134u;}//0.526
   else if (node_04_RRR)                   {*puProbHigh = 227u;}/*0.891 */ /* PRQA S 2991, 2995 */ /*Sanity purpose */
   else                                    {*puProbHigh = 127u;}
}
void computeDecisionTree(const uint16_t dist1_cm, const uint16_t dist2_cm, const uint16_t dist3_cm, 
                         const uint16_t width1_us, const uint16_t width2_us, const uint16_t width3_us,
                         const uint16_t h1, const uint16_t h2, const uint16_t h3, 
                         bool_t *isHigh, uint8_t *puProbHigh) 
{
   uint16_t count = 0;
   bool_t high;
   uint8_t uProbHigh;
   float32_t fProbHigh_total=0.0f;

   computeDecisionTree_00(dist1_cm, dist2_cm, dist3_cm, width1_us, width2_us, width3_us, h1, h2, h3, &high, &uProbHigh);
   if (high) {count++;}
   fProbHigh_total += uProbHigh;

   computeDecisionTree_01(dist1_cm, dist2_cm, dist3_cm, width1_us, width2_us, width3_us, h1, h2, h3, &high, &uProbHigh);
   if (high) {count++;}
   fProbHigh_total += uProbHigh;

   computeDecisionTree_02(dist1_cm, dist2_cm, dist3_cm, width1_us, width2_us, width3_us, h1, h2, h3, &high, &uProbHigh);
   if (high) {count++;}
   fProbHigh_total += uProbHigh;

   computeDecisionTree_03(dist1_cm, dist2_cm, dist3_cm, width1_us, width2_us, width3_us, h1, h2, h3, &high, &uProbHigh);
   if (high) {count++;}
   fProbHigh_total += uProbHigh;

   computeDecisionTree_04(dist1_cm, dist2_cm, dist3_cm, width1_us, width2_us, width3_us, h1, h2, h3, &high, &uProbHigh);
   if (high) {count++;}
   fProbHigh_total += uProbHigh;


   *isHigh=(count>2);
   *puProbHigh = fProbHigh_total/(5.0f); /* PRQA S 4454 */ /*Conversion has no impact */
}


#endif

