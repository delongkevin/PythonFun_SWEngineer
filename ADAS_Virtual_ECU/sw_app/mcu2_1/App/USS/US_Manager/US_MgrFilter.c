/*
 * US_MgrFilter.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#include "US_ME_Typedefs_Global.h"
#include "US_Platform_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_SysMgr_Global.h"
#include "US_MgrInterface.h"
#include "US_MgrFilter.h"
#include "US_MgrSensorProc.h"
#include "US_MgrUtility.h"
#include "US_SnrCfg_Global.h"
#include "US_MgrHeightAlgo.h"
/*#include "US_MgrGrowler.h"*/

/* TODO - All this needs to go into cfg/calibration */
/* #define US_D_LOG_REJECTED_ECHOES */
/* #define US_D_USE_HEIGHT_FLAG_TO_MERGE */
#define US_D_NUMBER_OF_COPIED_ECHOES    (3u)  /*limit number of echoes put to snr calc*/ /*US_D_APP_MAX_ECHOES_BUFF*/

#define US_D_HEIGHT_MERGE_SAME_OBJ_2ND_ECHO
#ifdef US_D_HEIGHT_MERGE_SAME_OBJ_2ND_ECHO
    #define US_D_HEIGHT_ADD_2ND_ECHO_STR    (ME_TRUE)
    
    #define US_D_HEIGHT_SAVE_2ND_ECHO_DEBUG
    #define US_D_HEIGHT_DEL_GND_ECHOES_SIDE_ONLY
    #ifdef US_D_HEIGHT_DEL_GND_ECHOES_SIDE_ONLY
        #define US_D_GND_ECHO_FILTER_TABLE_LEN    (9)
        #define US_D_CAL_TIME_CONST             (300u) /* move this to something more global */
    #endif
#endif
#define US_D_HEIGHT_ADDED_2ND_ECHO_STR_DIV   (2u)  /*divide 2nd echo strength by this value and ADD to 1st echo*/

#define US_D_2ND_ECHO_REMOVE_INDIR_SIDE  /*remove all indirect echoes for Rivian side panel sensors*/
#ifdef US_D_2ND_ECHO_REMOVE_INDIR_SIDE
    #define US_D_2ND_ECHO_CLEAR_INDIR_DIST
#endif

#define US_D_CHIRP_HEIGHT_STR_FACTOR    (50u) /*divide Chirp Height by this to get "strength"*/
#define US_D_CHIRP_MAX_HEIGHT_USAGE     (20000u) /*height above this has no meaning for strength building*/
#define US_D_CHIRP_CONF_STR_FACTOR      (5u) /*multiply Chirp Conf by this to get "strength"*/

/*#define US_D_ENABLE_FIXED_IMP_FILTER*/ /*TODO jwr - filters large objects, but only half the echoes. Makes bad triag*/
#define US_D_FIXED_IMPOSSIBLE_FILT_HEIGHT    (220u)  /*echo height*/
#define US_D_FIXED_IMPOSSIBLE_FILT_ENABLE_DIST  (200u) /*200cm*/

/*#define US_D_ENABLE_CHIRP_RING_NFD */
#ifdef US_D_ENABLE_CHIRP_RING_NFD
    #define US_D_CRNFD_USE_MOVING_WINDOW
    #define US_D_CRNFD_SIMPLE_RING_THRES    (2900u) //us, only used for pass counter method
    #define US_D_CRNFD_COUNTS_NEEDED        (2u) //only used for pass counter method
    #define US_D_CRNFD_COUNTS_MAX           (3u) //only used for pass counter method
    #define US_D_CRNFD_BUFFER_WINDOW_SIZE   (4u) //fires, so 180/200ms*N
    #define US_D_CRNFD_MAX_CONF             (100u)
    #define US_D_CRNFD_PASSING_CONF         (60u)
    #define US_D_CRNFD_THRES_CONF_INC       (30u)
    #define US_D_CRNFD_MAYBE_CONF_INC       (10u)
    #define US_D_CRNFD_EXTRA_CONF_INC       (20u)
    #define US_D_CRNFD_TIME_CONF_DEC        (5u)
    #define US_D_CRNFD_PREV_CONF_DIVIDER    (100u) //CANNOT BE ZERO!!, 100u means off
    #define US_D_CRNFD_USE_CPU_EXPENSIVE_BUFFER     (ME_TRUE)
    #define US_D_CRNFD_ACTIVE_SPD_MAX       (0.5f)
    #define US_D_CRNFD_CREATE_FAKE_ECHO
    #ifdef US_D_CRNFD_CREATE_FAKE_ECHO
        #define US_D_CRNFD_FAKE_DIST        (20u) //cm
        #define US_D_CRNFD_FAKE_CONF        (12u)
        #define US_D_CRNFD_FAKE_HEIGHT      (10000u)
        #define US_D_CRNFD_FAKE_SIGSTR      (400u)
        const US_S_EchoCalc_t sCRNFD_FakeEcho =
        {
            .uDirectDist_cm = US_D_CRNFD_FAKE_DIST,
            .uTotalDist_cm = (US_D_CRNFD_FAKE_DIST * TWO),
            .uSignalStrength = US_D_CRNFD_FAKE_SIGSTR,
            .bLargeObject = ME_FALSE,
            .bLargeFAPAObject = ME_TRUE,
            .uRecEchoIndex = ZERO,
        #ifdef US_D_TOF_STORAGE_ENABLED
            .uTOF_us = ZERO,
        #endif
            .uEchoCalcFlags = US_D_CALCFLAG_FAKE | US_D_CALCFLAG_HIGH_CONF
        };
    #endif
    typedef struct US_S_ChirpRingThresTable_s
    {
        uint16_t auHighThres[US_E_SNR_TYPE_MAX];
        uint16_t auMaybeThres[US_E_SNR_TYPE_MAX];
    } US_S_ChirpRingThresTable_t;

    const US_S_ChirpRingThresTable_t sChirpRingThresholds =
    {
        /* high pdc, psm */ {3100u, 3200u},
        /* maybe pdc, psm */ {2600u, 2800u}
    };
#endif /* US_D_ENABLE_CHIRP_RING_NFD */

/*#define US_D_ENABLE_CHIRP_CLOSE_2ND_ECHO*/  /*TODO - figure out avoiding acoustic shortcut issue*/
#define US_D_CC2E_DIST_REDUCTION   (30u) /*cm*/
#define US_D_CC2E_FAKE_DIST        (15u) /*cm*/
#define US_D_CC2E_ENABLE_DIST      (70u) /*DIRECT after compensation*/
#define US_D_CC2E_CONF_MIN         (11u)
#define US_D_CC2E_HEIGHT_MIN       (1000u) /*(500u) - outside test show acoustic shortcut issue.*/
#define US_D_CC2E_HEIGHT_MAX       (2000u)

#define US_D_ENABLE_CHIRP_FILTER
#ifdef US_D_ENABLE_CHIRP_FILTER
    /*#define US_D_CHIRP_FILTER_USE_TEMPERATURE
    #define US_D_CHIRP_FILTER_USE_HARSH_VALUES*/
    #define US_D_CHIRP_ECHO_FILTER_TABLE_LEN    (9u)
    #define US_D_CHIRP_ECHO_FILTER_STR
    #define US_D_CHIRP_FILTER_SKIP_SIDES
    #if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
        volatile uint8_t g_LAUD_ChirpFilterSideOff = 1u;
    #endif
#endif

#define US_D_PREVENT_NFD_FIXED_OVERLAP /*removes fixed echoes inside NFD range */
#ifdef  US_D_PREVENT_NFD_FIXED_OVERLAP
    #define US_D_NFD_FIXED_OVERLAP_ONLY_WITH_NFD_DET
    #ifdef US_D_NFD_FIXED_OVERLAP_ONLY_WITH_NFD_DET
        #define US_D_NFD_FIXED_OVERLAP_REMOVE_MORE_FIXED
    #endif
    //#define US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
#endif
/* NFD strength boosting */
//overwrite won't work without ObjDetTriang change to bypass dir only lockout
//#define US_D_NFD_STR_BOOST_OVERWRITE_STR        (US_D_INSTANT_PT_SIGSTR)
#define US_D_NFD_STR_BOOST_NFD_FACTOR    (2u)

#ifdef US_D_ENABLE_CHIRP_FILTER
typedef struct US_S_EchoFilterTable_s
{
    uint16_t uEchoTotalDist;
    uint16_t uFilterVal;
} US_S_EchoFilterTable_t;

/* Tuned in the lab at 20C */
static const US_S_EchoFilterTable_t sUssMgr_ChirpConfTable[US_D_CHIRP_ECHO_FILTER_TABLE_LEN] =
{
    /* TotalDist, Conf */
    
#ifdef US_D_CHIRP_FILTER_USE_HARSH_VALUES
    { 100u, 13u }, //50cm and below
    { 200u, 10u },
    { 300u, 10u },
    { 400u, 10u },
    { 500u, 10u },
    { 600u, 8u  },
    { 700u, 8u  },
    { 840u, 9u  }, //301cm to 420cm
    { 1000u,15u } //15 means ignore
#else
    { 100u, 12u },
    { 200u, 9u },
    { 300u, 9u },
    { 400u, 9u },
    { 500u, 9u },
    { 600u, 7u  },
    { 700u, 7u  },
    { 840u, 8u  },
    { 1000u,15u }
#endif
};
static const US_S_EchoFilterTable_t sUssMgr_ChirpHeightTable[US_D_CHIRP_ECHO_FILTER_TABLE_LEN] =
{
    
#ifdef US_D_CHIRP_FILTER_USE_HARSH_VALUES
    { 100u, 20000u },
    { 200u, 12000u },
    { 300u, 5200u },
    { 400u, 2600u },
    { 500u, 1700u },
    { 600u, 1100u },
    { 700u, 700u  },
    { 840u, 400u  },
    { 1000u,65535u } //65535 means ignore
#else
    { 100u, 12000u },
    { 200u, 8700u },
    { 300u, 4800u },
    { 400u, 2100u },
    { 500u, 1400u },
    { 600u, 900u  },
    { 700u, 600u  },
    { 840u, 390u  },
    { 1000u,65535u }
#endif
};
#endif /* US_D_ENABLE_CHIRP_FILTER */

#ifdef US_D_HEIGHT_DEL_GND_ECHOES_SIDE_ONLY
/*
    <SegmentGroup start="8" profile="US_E_PROFILE_A">
    <Segment time="45" th="40" step="-10" tb="0" />
    <Segment time="50" th="35" step="-10" tb="0" />
    <Segment time="55" th="35" step="-10" tb="0" />
    <Segment time="60" th="40" step="-10" tb="0" />
    </SegmentGroup>
    <SegmentGroup start="12" profile="US_E_PROFILE_A">
    <Segment time="65" th="40" step="-10" tb="0" />
    <Segment time="70" th="40" step="-10" tb="0" />
    <Segment time="75" th="35" step="-10" tb="0" />
    <Segment time="80" th="35" step="-10" tb="0" />
    </SegmentGroup>
*/
const US_S_EchoFilterTable_t sUssMgr_SideGndEchoTable[US_D_GND_ECHO_FILTER_TABLE_LEN] =
{
    /* TOF_us, new STG_val PREV BLOCK */
    { (45u * US_D_CAL_TIME_CONST), 0u },
    { (50u * US_D_CAL_TIME_CONST), 45u },
    { (55u * US_D_CAL_TIME_CONST), 45u },
    { (60u * US_D_CAL_TIME_CONST), 45u },
    { (65u * US_D_CAL_TIME_CONST), 45u },
    { (70u * US_D_CAL_TIME_CONST), 42u  },
    { (75u * US_D_CAL_TIME_CONST), 32u  },
    { (80u * US_D_CAL_TIME_CONST), 38u  },
    { 65400u, 0u } /* ignore all further */
};
#endif

const uint8_t aUssMgr_SafeFlashBlankArray[32] = {0};

#ifdef US_D_CHIRP_FILTER_USE_TEMPERATURE
    #define US_D_CHIRP_ADJUST_HEIGHT_W_TEMP
    #ifdef US_D_CHIRP_ADJUST_HEIGHT_W_TEMP
        #define US_D_CHIRP_HEIGHT_PER_10DEGC (500u)
    #endif
    //#define US_D_CHIRP_ADJUST_CONF_W_TEMP
    #ifdef US_D_CHIRP_ADJUST_CONF_W_TEMP
        #define US_D_CHIRP_CONF_PER_10DEGC (1u)
    #endif
#endif

/* End future calibration area */


/* Local var */
#ifdef US_D_LOG_REJECTED_ECHOES
typedef struct US_S_DEBUG_echodata_s
{
    uint16_t uEchoTotalDist;
    uint16_t uEchoHeight;
    uint8_t  uEchoConf;
    uint8_t  uSensorIdx;
} US_S_DEBUG_echodata_t;
#define DEBUG_REJECT_ECHOES_ARRAY_SIZE  (50u)
static US_S_DEBUG_echodata_t sDEBUG_rejectedEchoes[DEBUG_REJECT_ECHOES_ARRAY_SIZE];
static uint8_t DEBUG_rejectedEchoesIndex = ZERO;
#define US_D_LOG_INNER_CHIRP_ONLY
#endif

#ifdef US_D_ENABLE_CHIRP_RING_NFD
static uint8_t uaUssMgr_CRNFD_PassCounter[US_D_MAX_NUM_SENSORS];
static uint16_t uaUssMgr_CRNFD_RingHistory[US_D_MAX_NUM_SENSORS][US_D_CRNFD_BUFFER_WINDOW_SIZE];
#if (US_D_CRNFD_USE_CPU_EXPENSIVE_BUFFER == ME_FALSE)
static uint8_t uaUssMgr_CRNFD_RingHead[US_D_MAX_NUM_SENSORS];
#endif
uint8_t uaUssMgr_CRNFD_OutputConf[US_D_MAX_NUM_SENSORS];
#endif
#ifdef US_D_NFD_FIXED_OVERLAP_ONLY_WITH_NFD_DET
static bool_t baNFDFound[US_D_MAX_NUM_SENSORS];
#endif
#ifdef US_D_NFD_FIXED_OVERLAP_REMOVE_MORE_FIXED
static uint8_t uNFDFoundDist[US_D_MAX_NUM_SENSORS];
#endif
#ifdef US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
    #define US_D_NFD_FIXED_OVERLAP_LOG_TEST_SNR (3u)
    #define US_D_NFD_FIXED_OVERLAP_LOG_SIZE (50u)
static uint8_t uaNFDFoundHistory[US_D_NFD_FIXED_OVERLAP_LOG_SIZE];
static uint16_t uSilenceCycleCounter;
static uint16_t uNFDCycleCounter;
static uint16_t uFixedCycleCounter;
static uint16_t uOtherCycleCounter;
static uint8_t  uaActionHistory[US_D_NFD_FIXED_OVERLAP_LOG_SIZE];
static uint8_t  uNFDOverLapLogIndex;
#endif
#ifdef US_D_HEIGHT_SAVE_2ND_ECHO_DEBUG
uint16_t UssDBG_Deleted2ndEcho_Dist[US_D_MAX_NUM_SENSORS] = {0};
uint16_t UssDBG_Deleted2ndEcho_Str[US_D_MAX_NUM_SENSORS] = {0};
#endif
uint16_t UssDBG_ChirpFilteredEchos_Cnt = 0u;
uint16_t UssDBG_aCFE_Cnt[US_D_MAX_NUM_SENSORS];
uint8_t UssDBG_aDGESO_Str[US_D_MAX_NUM_SENSORS];

#if (US_D_MWH_PERSIST_FLAG == ME_TRUE)
static bool_t baUssMgr_Persistent_LargeFlag[US_D_MAX_NUM_SENSORS];
#endif
#if (US_D_MWH_REQ_OCC == ME_TRUE)
static uint8_t g_uWallOccuranceCnt[US_D_MAX_NUM_SENSORS];
static uint8_t g_uWallMissedCnt[US_D_MAX_NUM_SENSORS];
    //#ifdef US_D_LAUTERBACH_DEBUG_VARS
    bool_t g_LAUD_MWH_Enable = ME_FALSE;
    //#endif
#endif

/* Local functions */
#ifdef US_D_ENABLE_CHIRP_FILTER
static bool_t IsConfEnough(uint16_t TotalDist, uint8_t Conf);
static bool_t IsHeightEnough(uint16_t TotalDist, uint16_t Height);
#endif
#ifdef US_D_ENABLE_CHIRP_RING_NFD
static uint8_t CalcChirpRingNFD(uint8_t Sensor_Index, const US_S_SensorMeasRecs_t *psSnr_Meas_Rec);  /* Returns confidence */
    #ifdef US_D_CRNFD_USE_MOVING_WINDOW
static void AddToCRNFD_RingHistory(uint8_t Sensor_Index, uint16_t New_RingTime);
    #endif
#endif
#ifdef US_D_ENABLE_CHIRP_CLOSE_2ND_ECHO
static bool_t IsChirp2ndEcho(uint16_t TotalDist, uint8_t Conf, uint16_t Height);
#endif
#ifdef US_D_HEIGHT_DEL_GND_ECHOES_SIDE_ONLY
static bool_t IsEchoTooWeak_SideGnd(uint16_t uTOF_us, uint8_t uEcho_Height);
#endif
#if (US_D_MWH_REQ_OCC == ME_TRUE)
static bool_t UpdateOccHit(uint8_t uSnrIdx);
static void UpdateOccMiss(uint8_t uSnrIdx);
#endif

#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
volatile uint8_t g_LAUD_SideGndFilt_Enable = 1u;
#endif

/*===========================================================================
 * \brief Calculate distance [cm] from Time of Flight [us] for all echoes.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Number of echos is limited in manager to 3 echo peaks (configurable)
 */
/* ===========================================================================
 * Name:	 UssMgr_CheckMeasurementRange
 * Remarks:  DD-ID: {0CC543B5-EA7A-447b-870D-E1BA98ABAD7B}
 * Req.-ID: 13409860
 * ===========================================================================*/
void UssMgr_CheckMeasurementRange(void)
{
    uint8_t uSnrIdx;
    uint8_t uEchoIdx;
    uint16_t uDist_cm;
    US_S_SnrCalcs_t *psSnrCalcs;
#ifdef US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
    bool_t  bFixedHappened = ME_FALSE;
    bool_t  bNFDHappened = ME_FALSE;
    bool_t  bFixedRemoved = ME_FALSE;
    bool_t  bLogSnrFired = ME_FALSE;
#endif
    
    /* jwr - to fix noise not being detected. */
    //\todo - jwr: Need to instead change order of echo processing
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    /* Check if we are in ALL silence step */
    if ( psSnrMeasRec->uSendingSensors == ZERO )
    {
#ifdef US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
        uSilenceCycleCounter++;
#endif
        return; //yup, skip this entire thing
    }

     psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {
        US_S_SnrCalcRec_t *psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];
        
        if( psSnrCalcRec->uNumEchoes != ZERO )
        {
            switch( psSnrCalcRec->eEchoType )
            {
                case US_E_FIXED:
                case US_E_CHIRP_DOWN:
                case US_E_CHIRP_UP:
                {
                    if( psSnrCalcRec->eEchoClass == US_E_DIRECT )
                    {
#ifdef US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
                        bFixedHappened = ME_TRUE;
                        if (uSnrIdx == US_D_NFD_FIXED_OVERLAP_LOG_TEST_SNR){bLogSnrFired = ME_TRUE;}
#endif
                        /** MUST GO BACKWARDS!!!
                         * The echo deletion will change uNumEchoes and shift echo indexes
                         * Therefore echo index 0 might be replaced with echo index 1
                         * if deletion happens from 0 -> max
                         * if instead deletion happens from max -> 0, then this issue is avoided
                         */
                        for(uEchoIdx = (psSnrCalcRec->uNumEchoes - ONE); uEchoIdx > (uint8_t)ZERO; uEchoIdx--)
                        {
                            //\TODO jwr - is this needed in general for fixed/chirp?
                            //Needed for NFD overlap at least
                            uDist_cm = psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm;
                            //\TODO jwr - include indirects in this filtering?
#ifdef US_D_PREVENT_NFD_FIXED_OVERLAP
    #ifdef US_D_NFD_FIXED_OVERLAP_ONLY_WITH_NFD_DET
                            if ( (psSnrCalcRec->eEchoType == US_E_FIXED) && (baNFDFound[uSnrIdx] == (bool_t)ME_TRUE) )
    #else
                            if ( psSnrCalcRec->eEchoType == US_E_FIXED )
    #endif
                            {
    #ifndef US_D_NFD_FIXED_OVERLAP_REMOVE_MORE_FIXED
                                if (   (uDist_cm < US_D_MAX_SENSOR_NFD_RANGE)
    #else
                                if (   (uDist_cm < ((uint16_t)uNFDFoundDist[uSnrIdx] * 3u))
    #endif
                                    || (uDist_cm > US_D_MAX_SENSOR_FIXED_RANGE))
                                {
                                    
                                    UssMgr_DeleteEchoFromCalcRecord(uSnrIdx, uEchoIdx);
    #ifdef US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
                                    if (uSnrIdx == US_D_NFD_FIXED_OVERLAP_LOG_TEST_SNR){ bFixedRemoved = ME_TRUE;}
    #endif
                                }
                            }
                            else
                            {
#endif                                
                                if (   (uDist_cm < US_D_MIN_SENSOR_FIXED_RANGE)
                                    || (uDist_cm > US_D_MAX_SENSOR_FIXED_RANGE))
                                {
                                    //psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm = ZERO;
                                    UssMgr_DeleteEchoFromCalcRecord(uSnrIdx, uEchoIdx);
                                }
#ifdef US_D_PREVENT_NFD_FIXED_OVERLAP
                            }
#endif
                        }
                    }
                    else /* indirect */
                    {
#ifdef US_D_2ND_ECHO_REMOVE_INDIR_SIDE
                        /*KPK-QAC Fix : Need to suppress,Intentional implementaion */
                        if( uSnrIdx > US_D_SENSOR_RSL ) /* PRQA S 2992, 2996 */ //AOx and BOx are after RSL
                        {
    #if (US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN) && (US_D_MAX_NUM_SENSORS > 12u)
                            psSnrCalcRec->uNumEchoes = ZERO;
        #ifdef US_D_2ND_ECHO_CLEAR_INDIR_DIST
                            for(uEchoIdx = ZERO; uEchoIdx < US_D_NUMBER_OF_COPIED_ECHOES; uEchoIdx++)
                            {
                            	psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm = ZERO;
                            }
        #endif
    #endif
                        }
#endif
                    }
                    break;
                }
                
                case US_E_NFD:
                {
                    if ( psSnrCalcRec->eEchoClass == US_E_DIRECT )
                    {
#ifdef US_D_NFD_FIXED_OVERLAP_ONLY_WITH_NFD_DET
                        baNFDFound[uSnrIdx] = ME_FALSE;
#endif
#ifdef US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
                        bNFDHappened = ME_TRUE;
#endif
                        for(uEchoIdx = (psSnrCalcRec->uNumEchoes - ONE); uEchoIdx > (uint8_t)ZERO; uEchoIdx--)
                        {
                            uDist_cm = psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm;
                            
                            if (   (uDist_cm < US_D_MIN_SENSOR_NFD_RANGE)
                                || (uDist_cm > US_D_MAX_SENSOR_NFD_RANGE))
                            {
                                UssMgr_DeleteEchoFromCalcRecord(uSnrIdx, uEchoIdx);
                            }
                        }
#ifdef US_D_NFD_FIXED_OVERLAP_ONLY_WITH_NFD_DET                  
                        if ( psSnrCalcRec->uNumEchoes > ZERO ) /* PRQA S 2991,2995 *///need to supress this warning, echoes remain
                        {
                            baNFDFound[uSnrIdx] = ME_TRUE;
    #ifdef US_D_NFD_FIXED_OVERLAP_REMOVE_MORE_FIXED
                            uNFDFoundDist[uSnrIdx] = psSnrCalcRec->sEchoCalc[ZERO].uDirectDist_cm;
    #endif
                        }
#endif
                    }
                    else //US_E_INDIRECT
                    {
                        //remove ALL indirects from NFD
                        //\TODO jwr - research usages for NFD indirects
                        //psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm = ZERO;
                        psSnrCalcRec->uNumEchoes = ZERO;
#ifdef US_D_2ND_ECHO_CLEAR_INDIR_DIST
                        psSnrCalcRec->sEchoCalc[ZERO].uTotalDist_cm = ZERO;
#endif
                    }
                    break;
                }
                
                default:
                    //do nothing
                    break;
            }
        }
#ifdef US_D_NFD_FIXED_OVERLAP_ONLY_WITH_NFD_DET
        else
        {
        	/* if NFD was fired, but no object detected, mark the found flag false */
        	if( US_E_NFD == psSnrCalcRec->eEchoType )
        	{
        		baNFDFound[uSnrIdx] = ME_FALSE;
#ifdef US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
        		bNFDHappened = ME_TRUE;
#endif
        	}
        	else
        	{
#ifdef US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
                bFixedHappened = ME_TRUE;
#endif
        	}
        }
#endif
    }
#ifdef US_D_NFD_FIXED_OVERLAP_LOG_DEBUG
    uaNFDFoundHistory[uNFDOverLapLogIndex] = baNFDFound[US_D_NFD_FIXED_OVERLAP_LOG_TEST_SNR];
    if (bLogSnrFired){uaActionHistory[uNFDOverLapLogIndex] = bFixedRemoved;}
    else {uaActionHistory[uNFDOverLapLogIndex] = 0xAA;}
    if (bFixedHappened) {uFixedCycleCounter++;}
    if (bNFDHappened) {uNFDCycleCounter++;}
    uNFDOverLapLogIndex++;
    if(uNFDOverLapLogIndex >= US_D_NFD_FIXED_OVERLAP_LOG_SIZE) { uNFDOverLapLogIndex = ZERO; }
#endif
    //\TODO make this all configurable - also remove MIN dist if NFD stuff is happening
}

/*===========================================================================
 * \brief Do some sort of filtering - TBD
 *
 * \param none
 * \param none
 * \return none
 * \remarks Number of echos is limited in manager to 3 echo peaks (configurable)
 */
/* ===========================================================================
 * Name:	 UssMgr_FilterGainAndCutoff
 * Remarks:  DD-ID: {F495ED4F-DBFA-4b74-A680-A97FCAD4D087}
 * Req.-ID: 13409860
 * ===========================================================================*/
void UssMgr_FilterGainAndCutoff(void)
{
    uint8_t uSnrIdx;
    uint8_t uEchoIdx;
#ifdef US_D_ENABLE_CHIRP_FILTER
    bool_t bFilterPassed_1 = ME_FALSE;
    bool_t bFilterPassed_2 = ME_FALSE;
    #ifdef US_D_ENABLE_CHIRP_CLOSE_2ND_ECHO
    bool_t bFilterPassed_3 = ME_FALSE;
    #endif
#endif

    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    US_S_SnrCalcs_t *psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {
        const US_S_SensorRec_t  *psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
        US_S_SnrCalcRec_t *psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];

        /* must go backwards for deletion */
        //for(uEchoIdx = 0; uEchoIdx < psSnrCalcRec->uNumEchoes; uEchoIdx++)
        for(uEchoIdx = (psSnrCalcRec->uNumEchoes - ONE); uEchoIdx > (uint8_t)ZERO; uEchoIdx--)
        {
            switch(psSensorRec->sEcho[uEchoIdx].eEchoType)
            {
                case US_E_CHIRP_DOWN:
                case US_E_CHIRP_UP:
                {
#ifdef US_D_ENABLE_CHIRP_FILTER
    #ifdef US_D_CHIRP_FILTER_SKIP_SIDES
        #if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
                    if ( g_LAUD_ChirpFilterSideOff == 1u )
        #endif
                    {
                        if(UssMgr_IsSensSide(uSnrIdx) == ME_TRUE)
                        {
                            break;
                        }
                    }
    #endif
                    /* filter of chirp echoes to avoid noise */
    #ifdef US_D_CHIRP_ECHO_FILTER_STR
                    bFilterPassed_1 = IsHeightEnough(psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm , psSensorRec->sEcho[uEchoIdx].uEchoHeight);
    #else
                    bFilterPassed_1 = ME_TRUE;
    #endif
                    bFilterPassed_2 = IsConfEnough(psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm , psSensorRec->sEcho[uEchoIdx].uConf);
    #ifdef US_D_ENABLE_CHIRP_CLOSE_2ND_ECHO
                    bFilterPassed_3 = IsChirp2ndEcho(psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm , psSensorRec->sEcho[uEchoIdx].uConf, psSensorRec->sEcho[uEchoIdx].uEchoHeight);
                    if ( bFilterPassed_3 == ME_TRUE )
                    {
        #ifdef US_D_LOG_REJECTED_ECHOES
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoTotalDist = psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm;
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoHeight = psSensorRec->sEcho[uEchoIdx].uEchoHeight;
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoConf = psSensorRec->sEcho[uEchoIdx].uConf;;
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uSensorIdx = uSnrIdx + 100u;
                        DEBUG_rejectedEchoesIndex++;
                        if(DEBUG_rejectedEchoesIndex >= DEBUG_REJECT_ECHOES_ARRAY_SIZE) { DEBUG_rejectedEchoesIndex = ZERO; }
        #endif
                        if ( US_D_CC2E_DIST_REDUCTION < psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm )
                        {
                            psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm -= US_D_CC2E_DIST_REDUCTION;
                            //psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm -= (US_D_CC2E_DIST_REDUCTION * TWO);
                        }
                        else
                        {
                            psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm = US_D_CC2E_FAKE_DIST;
                            //psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm = (US_D_CC2E_FAKE_DIST * TWO);
                        }
                    }
                    else if ( (bFilterPassed_1 == ME_FALSE) || (bFilterPassed_2 == ME_FALSE) )
    #else
                    if ( (bFilterPassed_1 ==(bool_t) ME_FALSE) || (bFilterPassed_2 == (bool_t)ME_FALSE) ) //both filters need to pass to skip deletion
    #endif
                    {
    #ifdef US_D_LOG_REJECTED_ECHOES
                        if(psSensorRec->sEcho[uEchoIdx].uDistTOF_us < 9001 )
                        {
                            sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoTotalDist = psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm;
                            sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoHeight = psSensorRec->sEcho[uEchoIdx].uEchoHeight;
                            sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoConf = psSensorRec->sEcho[uEchoIdx].uConf;;
                            sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uSensorIdx = uSnrIdx;
                            DEBUG_rejectedEchoesIndex++;
                            if(DEBUG_rejectedEchoesIndex >= DEBUG_REJECT_ECHOES_ARRAY_SIZE) { DEBUG_rejectedEchoesIndex = ZERO; }
                        }
    #endif
                        //psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm = ZERO;
                        //psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm = ZERO;
                        UssMgr_DeleteEchoFromCalcRecord(uSnrIdx, uEchoIdx);
                        UssDBG_ChirpFilteredEchos_Cnt++;
                        UssDBG_aCFE_Cnt[uSnrIdx]++;
                    }
                    else
                    {
                        //do nothing
                    }
#endif
#ifdef US_D_LOG_INNER_CHIRP_ONLY
                    if( ((uSnrIdx == 2u) || (uSnrIdx == 3u))
                            && (psSnrCalcRec->eEchoClass == US_E_DIRECT) )
                    {
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoTotalDist = psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm;
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoHeight = psSensorRec->sEcho[uEchoIdx].uEchoHeight;
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoConf = psSensorRec->sEcho[uEchoIdx].uConf;;
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uSensorIdx = uSnrIdx + 120u;
                        DEBUG_rejectedEchoesIndex++;
                        if(DEBUG_rejectedEchoesIndex >= DEBUG_REJECT_ECHOES_ARRAY_SIZE) { DEBUG_rejectedEchoesIndex = ZERO; }
                    }
#endif
                    break;
                }
                
                case US_E_FIXED:
                default: //normal and nfd can be done the same - along with whatever else falls in here
                {
#ifdef US_D_ENABLE_FIXED_IMP_FILTER
                    /* insert noise filter items here - mostly high height echoes that are FAR away */
                    /* \TODO - Use STG/STC to help define values */
                    if ( (psSensorRec->sEcho[uEchoIdx].uEchoHeight > US_D_FIXED_IMPOSSIBLE_FILT_HEIGHT) &&
                       ( (psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm > US_D_FIXED_IMPOSSIBLE_FILT_ENABLE_DIST)
                        || (psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm > (US_D_FIXED_IMPOSSIBLE_FILT_ENABLE_DIST * TWO)) ) )
                    {
    #ifdef US_D_LOG_REJECTED_ECHOES
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoTotalDist = psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm;
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoHeight = psSensorRec->sEcho[uEchoIdx].uEchoHeight;
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uEchoConf = 0xFE;
                        sDEBUG_rejectedEchoes[DEBUG_rejectedEchoesIndex].uSensorIdx = uSnrIdx;
                        DEBUG_rejectedEchoesIndex++;
                        if(DEBUG_rejectedEchoesIndex >= DEBUG_REJECT_ECHOES_ARRAY_SIZE) { DEBUG_rejectedEchoesIndex = ZERO; }
    #endif
                        psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm = ZERO;
                        psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm = ZERO;
                    }
#endif /* US_D_ENABLE_FIXED_IMP_FILTER */
                    break;
                }
            }
        }
    }
}

/*===========================================================================
 * \brief merge 1st and 2nd echoes from the same obj, remove double echoes, 
 *           remove weak 3rd echoes, etc
 *
 * \param none
 * \return none
 * \remarks Only for fixed echoes currently. Runs after noise filtered out in UssMgr_FilterGainAndCutoff
 */
/* ===========================================================================
 * Name:	 UssMgr_HandleMultipleEchoes
 * Remarks:  DD-ID: {D7B73D93-82FD-438f-8468-BC3018E51297}
 * Req.-ID: 13395835
 * Req.-ID: 13395860
 * Req.-ID: 13395865
 * Req.-ID: 13395865
 * Req.-ID: 13395881
 * Req.-ID: 13395886
 * ===========================================================================*/
void UssMgr_HandleMultipleEchoes(void)
{
    uint8_t uSnrIdx;
    bool_t  b2ndEchoFromSameObj;

    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    US_S_SnrCalcs_t *psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {
        const US_S_SensorRec_t  *psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
        US_S_SnrCalcRec_t *psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];

        switch(psSnrCalcRec->eEchoType)
        {
            case US_E_CHIRP_DOWN:
            case US_E_CHIRP_UP:
            {
                /* add 2nd echo handling case */
                //2nd echo in this case can happen without 1st showing due to chirp's HIGH ringtime
                //2nd echo is classified by extra HIGH conf but low height
                /*
                for(uEchoIdx = 0; uEchoIdx < psSnrCalcRec->uNumEchoes; uEchoIdx++)
                {

                } 
                */          
#if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__HIGH)
                uint8_t uEchoIndex;
                for(uEchoIndex = ZERO; uEchoIndex < US_D_APP_MAX_ECHOES_BUFF; uEchoIndex++)
                {
                    psSnrCalcRec->sEchoCalc[uEchoIndex].bLargeObject = ME_TRUE;
                }
#endif
                /* Fill in FAPA used large obj flag */
                UssMgr_Reset_2ndEchoSameObjFlag();
                (void)UssMgr_Calc_2ndEchoSameObjFlag(psSnrCalcRec);
                b2ndEchoFromSameObj = UssMgr_Get_2ndEchoSameObjFlag();
                if (b2ndEchoFromSameObj != ME_FALSE)
                {
                    /* JR: Why aren't we merging and deleting 2nd echoes like Fixed mode? Not sure. TBD */
                    psSnrCalcRec->sEchoCalc[ZERO].bLargeFAPAObject = ME_TRUE;
#ifdef US_D_MGR_WALL_HIGH_FLAGS
                    if(psSnrCalcRec->eEchoClass == US_E_DIRECT)
                    {
    #if (US_D_MWH_REQ_OCC == ME_TRUE)
                        /* This both updates the Occ counters AND returns pass/fail */
                        if( UpdateOccHit(uSnrIdx) == ME_TRUE )
                        {
                            psSnrCalcRec->sEchoCalc[ZERO].bLargeObject = ME_TRUE;
                        }
    #else
                        psSnrCalcRec->sEchoCalc[ZERO].bLargeObject = ME_TRUE;
    #endif
                    }
#endif
                }
                else
                {
                    psSnrCalcRec->sEchoCalc[ZERO].bLargeFAPAObject = ME_FALSE;
    #ifdef US_D_MGR_WALL_HIGH_FLAGS
                    if(psSnrCalcRec->sEchoCalc[ZERO].uDirectDist_cm < US_D_MWH_AUTO_HIGH_DIST)
                    {
                        psSnrCalcRec->sEchoCalc[ZERO].bLargeObject = ME_TRUE;
                    }
                    else
                    {
        #if (US_D_MWH_REQ_OCC == ME_TRUE)
                        /* Being here already implies a valid 1st echo exists - just need to check if it's direct or not */
                        if(psSnrCalcRec->eEchoClass == US_E_DIRECT)
                        {
                            UpdateOccMiss(uSnrIdx);
                        }
        #endif
                        psSnrCalcRec->sEchoCalc[ZERO].bLargeObject = ME_FALSE;
                    }
    #endif
                }

    #if (US_D_MWH_PERSIST_FLAG == ME_TRUE)
                if(psSnrCalcRec->eEchoClass == US_E_DIRECT)
                {
                    baUssMgr_Persistent_LargeFlag[uSnrIdx] = psSnrCalcRec->sEchoCalc[ZERO].bLargeObject;
                }
    #endif
                break;
            }
            
            case US_E_NFD:
            {
                /* super special, needs research */
#if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__HIGH)
                uint8_t uEchoIndex;
                for(uEchoIndex = ZERO; uEchoIndex < US_D_APP_MAX_ECHOES_BUFF; uEchoIndex++)
                {
                    psSnrCalcRec->sEchoCalc[uEchoIndex].bLargeObject = ME_TRUE;
                }
#endif  
                break;
            }
            
            case US_E_FIXED:
            {
#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_TYPE__LINEAR_SCALE)
                //clear 2nd echo flag - already done in UssMgr_UpdateHeightGuessForSensor
                //UssMgr_Reset_2ndEchoSameObjFlag();
                
                /* Running height guess for only direct for now...
                 * Need to look at deleting 2nd indirect echoes if things are large...
                 */
                (void)UssMgr_UpdateHeightGuessForSensor(psSnrCalcRec, (US_S_SensorRec_t *)psSensorRec); //ignoring return from this for now
#else
    #if (US_D_HEIGHT_ALGO_DEFAULT_MODE == HEIGHT_ALGO_DEFAULT__HIGH)
                uint8_t uEchoIndex;
                for(uEchoIndex = ZERO; uEchoIndex < US_D_APP_MAX_ECHOES_BUFF; uEchoIndex++)
                {
                    psSnrCalcRec->sEchoCalc[uEchoIndex].bLargeObject = ME_TRUE;
                }
    #endif
                UssMgr_Reset_2ndEchoSameObjFlag();
                (void)UssMgr_Calc_2ndEchoSameObjFlag(psSnrCalcRec);
#endif /* US_D_USE_HEIGHT_ESTIMATION */
#ifdef US_D_HEIGHT_MERGE_SAME_OBJ_2ND_ECHO
                b2ndEchoFromSameObj = UssMgr_Get_2ndEchoSameObjFlag();
                    if (b2ndEchoFromSameObj != (bool_t)ME_FALSE)
                {
    #if (US_D_HEIGHT_ADD_2ND_ECHO_STR == ME_TRUE)
                    uint16_t uStrBoost;
                    //increase str if enabled
                    uStrBoost = (psSnrCalcRec->sEchoCalc[ONE].uSignalStrength / US_D_HEIGHT_ADDED_2ND_ECHO_STR_DIV);
                    psSnrCalcRec->sEchoCalc[ZERO].uSignalStrength += uStrBoost;
    #endif
    #ifdef US_D_MGR_WALL_HIGH_FLAGS
                    if(psSnrCalcRec->eEchoClass == US_E_DIRECT)
                    {
        #if (US_D_MWH_REQ_OCC == ME_TRUE)
                        /* This both updates the Occ counters AND returns pass/fail */
                        if( UpdateOccHit(uSnrIdx) == ME_TRUE )
                        {
                            psSnrCalcRec->sEchoCalc[ZERO].bLargeObject = ME_TRUE;
                        }
        #else
                        psSnrCalcRec->sEchoCalc[ZERO].bLargeObject = ME_TRUE;
        #endif
                    }
    #endif
                    psSnrCalcRec->sEchoCalc[ZERO].bLargeFAPAObject = ME_TRUE;
    #ifdef US_D_HEIGHT_SAVE_2ND_ECHO_DEBUG
                    //save for debug
                    UssDBG_Deleted2ndEcho_Dist[uSnrIdx] = psSnrCalcRec->sEchoCalc[ONE].uTotalDist_cm;
                    UssDBG_Deleted2ndEcho_Str[uSnrIdx] = psSensorRec->sEcho[psSnrCalcRec->sEchoCalc[ONE].uRecEchoIndex].uEchoHeight;
    #endif
                    //delete always
                    UssMgr_DeleteEchoFromCalcRecord(uSnrIdx, ONE);
                }
                else
                {
                    //2nd echo doesn't directly tell us it's high
                    psSnrCalcRec->sEchoCalc[ZERO].bLargeFAPAObject = ME_FALSE;
    #ifdef US_D_MGR_WALL_HIGH_FLAGS
                    if(psSnrCalcRec->sEchoCalc[ZERO].uDirectDist_cm < US_D_MWH_AUTO_HIGH_DIST)
                    {
                        psSnrCalcRec->sEchoCalc[ZERO].bLargeObject = ME_TRUE;
                    }
                    else
                    {
        #if (US_D_MWH_REQ_OCC == ME_TRUE)
                        /* Being here already implies a valid 1st echo exists - just need to check if it's direct or not */
                        if(psSnrCalcRec->eEchoClass == US_E_DIRECT)
                        {
                            UpdateOccMiss(uSnrIdx);
                        }
        #endif
                        psSnrCalcRec->sEchoCalc[ZERO].bLargeObject = ME_FALSE;
                    }
    #endif
    #ifdef US_D_HEIGHT_DEL_GND_ECHOES_SIDE_ONLY
        #if (US_D_LAUTERBACH_DEBUG_VARS == ME_TRUE)
                  if (g_LAUD_SideGndFilt_Enable == 1u)
        #endif  
                  {
				  
                    /* This is to patch an issue where 1st echoes from large obj are weaker than 2nd echoes.
                     * so weak that calibration STG has to be lower than normal.
                     * this leads to gnd echoes.
                     * This filter is to try and delete those ground echoes
                     */
                    /* if not a large obj then we might need to delete weak 1st echoes */
                    switch (uSnrIdx)
                    {
                        case US_D_SENSOR_FSL:
                        case US_D_SENSOR_FSR:
                        case US_D_SENSOR_RSL:
                        case US_D_SENSOR_RSR:
                        {
                            uint8_t echo_str;
                            uint16_t echo_tof;
                            /* assume "1st" echo is still around and didn't get filtered by other things */
                            echo_tof = psSensorRec->sEcho[psSnrCalcRec->sEchoCalc[ZERO].uRecEchoIndex].uDistTOF_us;
                            echo_str = psSensorRec->sEcho[psSnrCalcRec->sEchoCalc[ZERO].uRecEchoIndex].uEchoHeight;
                            if (ME_TRUE == IsEchoTooWeak_SideGnd(echo_tof, echo_str))
                            {
                                UssMgr_DeleteEchoFromCalcRecord(uSnrIdx, ZERO);
                                UssDBG_aDGESO_Str[uSnrIdx] = echo_str;
                            }
                            else
                            {
                                UssDBG_aDGESO_Str[uSnrIdx] = 1u;
                            }
                            break;
                        }

                        default:  //Do Nothing

                            break;
                    }
                  }
    #endif /* US_D_HEIGHT_DEL_GND_ECHOES_SIDE_ONLY */
                }
#endif /* US_D_HEIGHT_MERGE_SAME_OBJ_2ND_ECHO */
    #if (US_D_MWH_PERSIST_FLAG == ME_TRUE)
                if(psSnrCalcRec->eEchoClass == US_E_DIRECT)
                {
                    baUssMgr_Persistent_LargeFlag[uSnrIdx] = psSnrCalcRec->sEchoCalc[ZERO].bLargeObject;
                }
    #endif
                break;
            }
            
            default: 
            {
                /* Do nothing for no echo or other cases */
                /* Reset flags are persistent */
#if (US_D_MWH_PERSIST_FLAG == ME_TRUE)
                baUssMgr_Persistent_LargeFlag[uSnrIdx] = ME_FALSE;
#endif
#if (US_D_MWH_REQ_OCC == ME_TRUE)
                if(psSnrCalcRec->eEchoClass == US_E_DIRECT)
                {
                    UpdateOccMiss(uSnrIdx);
                }
#endif
                break;
            }
        }
    }
}

/*===========================================================================
 * \brief Calculate cross sectional signal strength (relative) for all echoes.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Number of echos is limited in manager to 3 echo peaks (configurable)
 */
/* ===========================================================================
 * Name:	 UssMgr_CalcSignalStrength
 * Remarks:  DD-ID: {089FA6E6-EEA8-42b8-93EF-D3D37AC65C93}
 * Req.-ID: 13395835
 * Req.-ID: 13395860
 * Req.-ID: 13395865
 * Req.-ID: 13395865
 * Req.-ID: 13395881
 * Req.-ID: 13395886
 * ===========================================================================*/
void UssMgr_CalcSignalStrength(void)
{
    uint8_t uSnrIdx;
    uint8_t uEchoIdx;

    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    US_S_SnrCalcs_t *psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {
        const US_S_SensorRec_t  *psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
        US_S_SnrCalcRec_t *psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];

        for(uEchoIdx = ZERO; uEchoIdx < psSnrCalcRec->uNumEchoes; uEchoIdx++)
        {
            if( (psSnrCalcRec->sEchoCalc[uEchoIdx].uTotalDist_cm != ZERO) || (psSnrCalcRec->sEchoCalc[uEchoIdx].uDirectDist_cm != ZERO) )
            {
                switch(psSnrCalcRec->eEchoType)
                {
                    case US_E_CHIRP_DOWN:
                    case US_E_CHIRP_UP:
                    {
                        psSnrCalcRec->sEchoCalc[uEchoIdx].uSignalStrength = (uint16_t)(psSensorRec->sEcho[uEchoIdx].uConf * (uint16_t)US_D_CHIRP_CONF_STR_FACTOR);
                        
                        if (psSensorRec->sEcho[uEchoIdx].uEchoHeight < US_D_CHIRP_MAX_HEIGHT_USAGE)
                        {
                            psSnrCalcRec->sEchoCalc[uEchoIdx].uSignalStrength += psSensorRec->sEcho[uEchoIdx].uEchoHeight / US_D_CHIRP_HEIGHT_STR_FACTOR;
                        }
                        else
                        {
                            psSnrCalcRec->sEchoCalc[uEchoIdx].uSignalStrength += US_D_CHIRP_MAX_HEIGHT_USAGE / US_D_CHIRP_HEIGHT_STR_FACTOR;
                        }
                        break;
                    }
                    
                    case US_E_NFD:
#ifdef US_D_NFD_STR_BOOST_NFD_FACTOR
                    {
                        psSnrCalcRec->sEchoCalc[uEchoIdx].uSignalStrength = (psSensorRec->sEcho[uEchoIdx].uEchoHeight * US_D_NFD_STR_BOOST_NFD_FACTOR);
                        break;
                    }
#endif
#ifdef US_D_NFD_STR_BOOST_OVERWRITE_STR
                    {
                        psSnrCalcRec->sEchoCalc[uEchoIdx].uSignalStrength = US_D_NFD_STR_BOOST_OVERWRITE_STR;
                        break;
                    }
#endif
                    case US_E_FIXED:
                    default: //normal and nfd can be done the same - along with whatever else falls in here
                    {
                        /*
                         * \TODO jp - Formula that amplifies square drop off
                         *            Consider STC gain prior to applying formula.
                         */
                        psSnrCalcRec->sEchoCalc[uEchoIdx].uSignalStrength = psSensorRec->sEcho[uEchoIdx].uEchoHeight;
                        break;
                    }
                }
            }
        }
    }
}
/*===========================================================================
 * \brief Calculate distance [cm] from Time of Flight [us] for all echoes.
 *
 * \param none
 * \param none
 * \return none
 * \remarks Number of echos is limited in manager to 3 echo peaks (configurable)
 */
/* ===========================================================================
 * Name:	 UssMgr_ClassifyMeasurementType
 * Remarks:  DD-ID: {1A27804E-6400-4297-A04F-859D57CAD4D8}
 * Req.-ID: 13409860
 * ===========================================================================*/
void UssMgr_ClassifyMeasurementType(void)
{
    uint8_t uSnrIdx;
    uint32_t uBitMap;
    uint8_t uGrpIdx; //used for 3 different items in this function. Warning
    uint8_t bNFDGrpFound[US_D_PHYS_GRP_MAX];
    const US_S_PlatPhysInfo_t *psGrpLayout;
    uint8_t uNumSnrsInGrpLocal;
    uint8_t uGrpSnrIdx;
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    US_S_SnrCalcs_t *psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    US_S_SnrCalcRec_t *psSnrCalcRec;
    
    for (uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++)
    {
        bNFDGrpFound[uGrpIdx] = ME_FALSE;
    }

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {
        /* Copy number of echos to calc structure for future modification */
        if ( psSnrMeasRec->sSensorRec[uSnrIdx].uNumEchoes > US_D_NUMBER_OF_COPIED_ECHOES )
        {
            psSnrCalcs->sSnrCalcRec[uSnrIdx].uNumEchoes = US_D_NUMBER_OF_COPIED_ECHOES;
        }
        else
        {
            psSnrCalcs->sSnrCalcRec[uSnrIdx].uNumEchoes = psSnrMeasRec->sSensorRec[uSnrIdx].uNumEchoes;
        }

        uBitMap = (uint32_t)US_IDX_TO_BIT_LOC(uSnrIdx);
        psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];

        if ((psSnrMeasRec->uSendingSensors & uBitMap) != ZERO) // This is a sending sensor
        {
            psSnrCalcRec->eEchoClass = US_E_DIRECT;
        }
        else // need to check FOV indices for listen only condition
        {
            psSnrCalcRec->eEchoClass = US_E_INDIRECT;
        }
        //else
        // \TODO jp - these really need to be arbitrated in the order currently shown.  immutable presidence.  Just remember it is for this meas only.
        // for to see if listen only to pick indirect or listen only
        // there is an expectation that no other sensor direct signal is impacting the sensing diaphragm at this time!!!
        //US_E_LISTEN_ONLY - Need sensor FOV data in system info to calc if listen only 0 \TODO jp - i can do this now!!!  Need to implement
        
        /* Copy echo type to calc struct */
        psSnrCalcRec->eEchoType = psSnrMeasRec->sSensorRec[uSnrIdx].sEcho[ZERO].eEchoType;
        //assumption is that all echoes from 1 sensor is only ONE type. Taking from first echo
        //if it's NO_ECHO, that's fine too
        //special NFD case:
        if( psSnrMeasRec->sSensorRec[uSnrIdx].eEchoTypeRequested == US_E_REQ_SEND_NFD )
        {
            psSnrCalcRec->eEchoType = US_E_NFD;
            
            uGrpIdx = UssCtrl_GetGroupIdxFromSensorIdx(uSnrIdx);
            bNFDGrpFound[uGrpIdx] = ME_TRUE; 
        }
    }
    
    /* patch for NFD special case */
    //\TODO jwr - tie this into fire seq? if NFD and Fixed is ever mixed, this will break
    //if there is at least 1 sending NFD in a group, all listens need to become NFD
    psGrpLayout = UssCtrl_psGetPlatPhysInfo();

    for( uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++)
    {
        if (bNFDGrpFound[uGrpIdx] == (bool_t)ME_TRUE)
        {
            uNumSnrsInGrpLocal = psGrpLayout->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;
            for (uGrpSnrIdx = ZERO; uGrpSnrIdx < uNumSnrsInGrpLocal; uGrpSnrIdx++)
            {
                uSnrIdx = psGrpLayout->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uGrpSnrIdx];
                //change all FIXED to NFD
                if(psSnrCalcs->sSnrCalcRec[uSnrIdx].eEchoType == US_E_FIXED)
                {
                    psSnrCalcs->sSnrCalcRec[uSnrIdx].eEchoType = US_E_NFD;
                }
            }
        }
    }
}


/* ===========================================================================
 * Name:	 UssMgr_AddAndAdjustEchoes
 * Remarks:  DD-ID: {3AC5558F-4644-4184-A3C9-15D615E4315C}
 *  Req.-ID: ?
 * ===========================================================================*/
void UssMgr_AddAndAdjustEchoes(void)
{
#ifdef US_D_ENABLE_CHIRP_RING_NFD
    uint8_t uSnrIdx;
    bool_t  bAddedEcho = ME_FALSE;
    uint8_t uChirpRingNFDConf;
#endif
#ifdef US_D_CRNFD_CREATE_FAKE_ECHO
    US_S_EchoCalc_t sNewEcho;
#endif
#ifdef US_D_ENABLE_CHIRP_RING_NFD
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();

    for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {
        /* Check various conditions for add/adjust */

        uChirpRingNFDConf = CalcChirpRingNFD(uSnrIdx, psSnrMeasRec);
    #ifdef US_D_CRNFD_CREATE_FAKE_ECHO
        if( (US_D_CRNFD_PASSING_CONF <= uChirpRingNFDConf) && (psSnrMeasRec->sSensorRec[uSnrIdx].eEchoTypeRequested != US_E_REQ_RECEIVE)
    #if (US_D_USE_FAPA_API == ME_TRUE)
            && (UssMgr_IsFeatureInFAPA() == ME_TRUE)
    #endif
         )
        {
            UssMgr_InsertFirstEchoIntoCalcRecord(uSnrIdx, &sCRNFD_FakeEcho);
            bAddedEcho = ME_TRUE;
    #endif /* US_D_CRNFD_CREATE_FAKE_ECHO */
        }
    }
#endif /* US_D_ENABLE_CHIRP_RING_NFD */
}

/* ===========================================================================
 * Name:	 UssMgr_FilterInit
 * Remarks:  DD-ID: {A5715D0A-8461-4cdf-ABAE-592C170C0413}
 *  Req.-ID: 13409860
 * ===========================================================================*/
void UssMgr_FilterInit(void)
{
#ifdef US_D_ENABLE_CHIRP_RING_NFD
    memset(uaUssMgr_CRNFD_PassCounter, ZERO, sizeof(uaUssMgr_CRNFD_PassCounter));
    memset(uaUssMgr_CRNFD_RingHistory, ZERO, sizeof(uaUssMgr_CRNFD_RingHistory));
    memset(uaUssMgr_CRNFD_OutputConf, ZERO, sizeof(uaUssMgr_CRNFD_OutputConf));
    #if (US_D_CRNFD_USE_CPU_EXPENSIVE_BUFFER == ME_FALSE)
    memset(uaUssMgr_CRNFD_RingHead, ZERO, sizeof(uaUssMgr_CRNFD_RingHead));
    #endif
#endif

#if (US_D_MWH_PERSIST_FLAG == ME_TRUE)
    (void)memset(baUssMgr_Persistent_LargeFlag, ME_FALSE, sizeof(bool_t)*US_D_MAX_NUM_SENSORS);
#endif
#if (US_D_MWH_REQ_OCC == ME_TRUE)
    (void)memset(g_uWallOccuranceCnt, ZERO, sizeof(g_uWallOccuranceCnt));
    (void)memset(g_uWallMissedCnt, ZERO, sizeof(g_uWallMissedCnt));
#endif
/* replace memset with a for loop?*/
}

/** Internal functions **/
#ifdef US_D_ENABLE_CHIRP_FILTER
/* ===========================================================================
 * Name:	 IsConfEnough
 * Remarks:  DD-ID: {AEDA6A08-F1B0-407b-8FB4-887C2B3CA9F2}
 * Req.-ID: 13395835
 * Req.-ID: 13395860
 * Req.-ID: 13395865
 * Req.-ID: 13395865
 * Req.-ID: 13395881
 * Req.-ID: 13395886
 * ===========================================================================*/
static bool_t IsConfEnough(uint16_t TotalDist, uint8_t Conf)
{
    uint8_t uTableIdx;
    bool_t  bRet_EchoGood = ME_FALSE;

    for (uTableIdx = 0; uTableIdx < US_D_CHIRP_ECHO_FILTER_TABLE_LEN; uTableIdx++)
    {
        if ( TotalDist < sUssMgr_ChirpConfTable[uTableIdx].uEchoTotalDist )
        {
            if (Conf >= sUssMgr_ChirpConfTable[uTableIdx].uFilterVal)
            {
                bRet_EchoGood = ME_TRUE;
            }
            else
            {
                bRet_EchoGood = ME_FALSE;
            }
            break; //exit loop, matching table entry found
        }
    }
    return bRet_EchoGood;
}

/* ===========================================================================
 * Name:	 IsHeightEnough
 * Remarks:  DD-ID: {2F7207A4-7D2B-46e7-83FD-C37C1BAB8A5F}
 * Req.-ID: 13395835
 * Req.-ID: 13395860
 * Req.-ID: 13395865
 * Req.-ID: 13395865
 * Req.-ID: 13395881
 * Req.-ID: 13395886
 * ===========================================================================*/
static bool_t IsHeightEnough(uint16_t TotalDist, uint16_t Height)
{
    uint8_t uTableIdx;
    bool_t bRet_EchoGood = ME_FALSE;

    for (uTableIdx = 0; uTableIdx < US_D_CHIRP_ECHO_FILTER_TABLE_LEN; uTableIdx++)
    {
        if ( TotalDist < sUssMgr_ChirpHeightTable[uTableIdx].uEchoTotalDist )
        {
            if (Height >= sUssMgr_ChirpHeightTable[uTableIdx].uFilterVal)
            {
                bRet_EchoGood = ME_TRUE;
            }
            else
            {
                bRet_EchoGood = ME_FALSE;
            }
            break; //exit loop, matching table entry found
        }
    }
    return bRet_EchoGood;
}
#endif
#ifdef US_D_ENABLE_CHIRP_CLOSE_2ND_ECHO
static bool_t IsChirp2ndEcho(uint16_t TotalDist, uint8_t Conf, uint16_t Height)
{
    bool_t bRet_EchoGood = ME_FALSE;

    if ( TotalDist < US_D_CC2E_ENABLE_DIST )
    {
        if ( (Conf >= US_D_CC2E_CONF_MIN) && ((Height > US_D_CC2E_HEIGHT_MIN) && (Height < US_D_CC2E_HEIGHT_MAX)) )
        {
            bRet_EchoGood = ME_TRUE;
        }
        else
        {
            bRet_EchoGood = ME_FALSE;
        }
    }
    return bRet_EchoGood;
}
#endif

#ifdef US_D_HEIGHT_DEL_GND_ECHOES_SIDE_ONLY
/* ===========================================================================
 * Name:	 IsEchoTooWeak_SideGnd
 * Remarks:  DD-ID: {05281DA7-544C-432c-A366-BB0739E949A5}
 * Req.-ID: 13396045
 * ===========================================================================*/
static bool_t IsEchoTooWeak_SideGnd(uint16_t uTOF_us, uint8_t uEcho_Height)
{
    uint8_t uTableIdx;
    bool_t bRet_EchoBad = ME_FALSE;

    for (uTableIdx = 0; uTableIdx < US_D_GND_ECHO_FILTER_TABLE_LEN; uTableIdx++)
    {
        if ( uTOF_us < sUssMgr_SideGndEchoTable[uTableIdx].uEchoTotalDist )
        {
            if (uEcho_Height >= sUssMgr_SideGndEchoTable[uTableIdx].uFilterVal)
            {
                bRet_EchoBad = ME_FALSE;
            }
            else
            {
                bRet_EchoBad = ME_TRUE;
            }
            break; //exit loop, matching table entry found
        }
    }
    return bRet_EchoBad;
}
#endif

#ifdef US_D_ENABLE_CHIRP_RING_NFD
/* ===========================================================================
 * Name:	CalcChirpRingNFD
 * Remarks:  DD-ID: {F7B7882B-B782-4ddb-8DDE-C00C170CEFC7}
 * Req.-ID: 13396045
 * ===========================================================================*/
static uint8_t CalcChirpRingNFD(uint8_t Sensor_Index, const US_S_SensorMeasRecs_t *psSnr_Meas_Rec)
{
    const US_S_SensorRec_t  *psSensorRec = &psSnr_Meas_Rec->sSensorRec[Sensor_Index];
    US_E_SendType_t eEchoTypeSent;
    uint8_t uConfReductionVal = ZERO;
    uint16_t uPossibleConf;
#ifdef US_D_CRNFD_USE_MOVING_WINDOW
    uint8_t uBuffIndex;
    uint8_t uPassCnt, uMaybeCnt, uFailCnt;
    uint8_t const *pSnrTypeList;
    uint16_t uHighThres, uMaybeThres;
    uint16_t uTempRing;
#endif

    //US_S_SnrCalcs_t *psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    eEchoTypeSent = psSensorRec->eEchoTypeRequested;
    /* Normally use psSensorRec->sEcho[uEchoIdx].eEchoType, but no echoes exist*/

    if( (UssMgr_GetVehSpeed() <= US_D_CRNFD_ACTIVE_SPD_MAX) )
    {
        /* eEchoTypeRequested is only for firing sensors, any receive sensors will have "US_E_REQ_RECEIVE" */
        if( (eEchoTypeSent == US_E_REQ_SEND_CHIRP_DOWN) || (eEchoTypeSent == US_E_REQ_SEND_CHIRP_UP) )
        {
#ifdef US_D_CRNFD_USE_MOVING_WINDOW
            //add to ring history window
            AddToCRNFD_RingHistory(Sensor_Index, psSensorRec->sRingTime.uRingTime);
            //clear counts
            uPassCnt = ZERO; uMaybeCnt = ZERO; uFailCnt = ZERO;
            //get correct thresholds
            pSnrTypeList = UssCtrl_psGetSensorType();
            uHighThres = sChirpRingThresholds.auHighThres[(US_E_SnrType_t)pSnrTypeList[Sensor_Index]];
            uMaybeThres = sChirpRingThresholds.auMaybeThres[(US_E_SnrType_t)pSnrTypeList[Sensor_Index]];
            /* TODO jwr, add adjustment of thres (or ringtime) based on amb temperature */
            //check history window and determine passes, maybes, and fails
            for(uBuffIndex = ZERO; uBuffIndex < US_D_CRNFD_BUFFER_WINDOW_SIZE; uBuffIndex++)
            {
                uTempRing = uaUssMgr_CRNFD_RingHistory[Sensor_Index][uBuffIndex];
                if (uTempRing >= uHighThres) {uPassCnt++;}
                if ( (uTempRing < uHighThres) && (uTempRing >= uMaybeThres) ) {uMaybeCnt++;}
                if (uTempRing < uMaybeThres) {uFailCnt++;}
            }
            /* Confidence calculation */
            uPossibleConf = (uaUssMgr_CRNFD_OutputConf[Sensor_Index] / US_D_CRNFD_PREV_CONF_DIVIDER); //start with a faction of the prev conf as boost
            uPossibleConf = uPossibleConf + (uPassCnt * US_D_CRNFD_THRES_CONF_INC);
            uPossibleConf = uPossibleConf + (uMaybeCnt * US_D_CRNFD_MAYBE_CONF_INC);
            //No adjustment for uFailCnt
            //TBD other hints (indirect?, last good echo, neighbor ringtime, 2nd threshold) adds US_D_CRNFD_EXTRA_CONF_INC
#else
            /* TODO Some difference needed for PSM and temperature */
            if( psSensorRec->sRingTime.uRingTime > US_D_CRNFD_SIMPLE_RING_THRES )
            {
                if(uaUssMgr_CRNFD_PassCounter[Sensor_Index] < US_D_CRNFD_COUNTS_MAX)
                {
                    uaUssMgr_CRNFD_PassCounter[Sensor_Index]++;
                }
            }
            else
            {
                if(uaUssMgr_CRNFD_PassCounter[Sensor_Index] > ZERO)
                {
                    uaUssMgr_CRNFD_PassCounter[Sensor_Index]--;
                }
            }
            /* Confidence value update, 0% - 90% */
            uPossibleConf = uaUssMgr_CRNFD_PassCounter[Sensor_Index] * US_D_CRNFD_THRES_CONF_INC;
#endif /* if/else US_D_CRNFD_USE_MOVING_WINDOW */
        }
        else if( (eEchoTypeSent == US_E_REQ_SEND_NORMAL) || (eEchoTypeSent == US_E_REQ_SEND_NFD) )
        {
            /* we exited chirp? drastic conf reduction */
            uConfReductionVal = (US_D_CRNFD_TIME_CONF_DEC * 3u);
        }
        else /* Sensor not fired - take some action to decrease conf */
        {
            uConfReductionVal = US_D_CRNFD_TIME_CONF_DEC;
        }
    }
    else
    {
        /* Overspeed, unlikely to get real ringtime info or unable to use the info */
        uConfReductionVal = US_D_CRNFD_MAX_CONF; /* sets uPossibleConf to zero later */
    }

    if (uConfReductionVal != ZERO)
    {
        uPossibleConf = uaUssMgr_CRNFD_OutputConf[Sensor_Index];
        if (uPossibleConf > uConfReductionVal)
        {
            uPossibleConf = uPossibleConf - uConfReductionVal;
        }
        else
        {
            uPossibleConf = ZERO;
        }
    }

    //cap conf to max
    if(uPossibleConf > US_D_CRNFD_MAX_CONF) {uPossibleConf = US_D_CRNFD_MAX_CONF;}
    //save globally for reporting and history
    uaUssMgr_CRNFD_OutputConf[Sensor_Index] = (uint8_t)uPossibleConf;

    return (uint8_t)uPossibleConf; //uaUssMgr_CRNFD_OutputConf[SensorIndex];
}
#endif /* US_D_ENABLE_CHIRP_RING_NFD */

#ifdef US_D_CRNFD_USE_MOVING_WINDOW
/* ===========================================================================
 * Name:	 AddToCRNFD_RingHistory
 * Remarks:  DD-ID: {F7ECE665-DB09-4271-B2E8-59BD6CC91AE1}
 * ===========================================================================*/
static void AddToCRNFD_RingHistory(uint8_t Sensor_Index, uint16_t New_RingTime)
{
#if (US_D_CRNFD_USE_CPU_EXPENSIVE_BUFFER == ME_TRUE)
    uint8_t uBuffIndex;
    /* shift all values down one index */
    for(uBuffIndex = (US_D_CRNFD_BUFFER_WINDOW_SIZE - ONE); uBuffIndex > ZERO; uBuffIndex--)
    {
        /* data[n-1] -> data[n] */
        uaUssMgr_CRNFD_RingHistory[Sensor_Index][uBuffIndex] = uaUssMgr_CRNFD_RingHistory[Sensor_Index][(uBuffIndex - ONE)];
    }
    /* add new to zero index */
    uaUssMgr_CRNFD_RingHistory[Sensor_Index][ZERO] = New_RingTime;
#else
    uaUssMgr_CRNFD_RingHistory[Sensor_Index][uaUssMgr_CRNFD_RingHead[Sensor_Index]];

#endif 
}
#endif /* # US_D_CRNFD_USE_MOVING_WINDOW */


#if (US_D_MWH_REQ_OCC == ME_TRUE)
/* ===========================================================================
 * Name: UpdateOccHit	
 * Remarks:  DD-ID: {4AF7B75D-0F37-4851-910E-484703923482}
 * ===========================================================================*/
static bool_t UpdateOccHit(uint8_t uSnrIdx)
{
    bool_t bOccPassed = ME_FALSE;

    if(g_uWallOccuranceCnt[uSnrIdx] >= US_D_MWH_OCC_VALUE_NEEDED)
    {
        bOccPassed = ME_TRUE;
    }

    /* update values AFTER */
    if(g_uWallOccuranceCnt[uSnrIdx] < US_D_MWH_OCC_MAX_VAL){g_uWallOccuranceCnt[uSnrIdx]++;}
    g_uWallMissedCnt[uSnrIdx] = ZERO;

//#ifdef US_D_LAUTERBACH_DEBUG_VARS
    if(g_LAUD_MWH_Enable == ME_FALSE) { bOccPassed = ME_FALSE; }
//#endif
    return bOccPassed;
}
/* ===========================================================================
 * Name: UpdateOccMiss	
 * Remarks:  DD-ID: {53ECD175-FFE8-4a13-BAE1-F1F739E3E176} 
 * ===========================================================================*/
static void UpdateOccMiss(uint8_t uSnrIdx)
{
    /* Update missed count for this sensor, avoid overflow */
    if(g_uWallMissedCnt[uSnrIdx] < US_D_MWH_OCC_MAX_VAL){g_uWallMissedCnt[uSnrIdx]++;}

    /* Check if we've missed too many times in a row */
    /* UpdateOccHit() function will reset missed cnt to guarantee "in a row" */
    if(g_uWallMissedCnt[uSnrIdx] > US_D_MWH_OCC_MISSED_ALLOWED)
    {
        g_uWallOccuranceCnt[uSnrIdx] = ZERO;
        g_uWallMissedCnt[uSnrIdx] = ZERO;
    }
    /* If under the missed allowed threshold, just do normal miss handling */
    else if(g_uWallOccuranceCnt[uSnrIdx] > ZERO)
    {
        if(g_uWallOccuranceCnt[uSnrIdx] >= US_D_MWH_OCC_DEFAULT_DECRATE)
        {
            g_uWallOccuranceCnt[uSnrIdx] -= US_D_MWH_OCC_DEFAULT_DECRATE;
        }
        else
        {
            g_uWallOccuranceCnt[uSnrIdx] = ZERO;
        }
    }
    else
    {
        /* misses not passed threshold and no occ cnt to decrement - do nothing? */
    }
}
#endif /* #if (US_D_MWH_REQ_OCC == ME_TRUE) */


/* External set/get functions */

/* ===========================================================================
 * Name:	 UssMgr_uGetCRNFDConf
 * Remarks:  DD-ID: {654D4459-DF7A-4de1-9928-5EE609B1C835}
 * Req.-ID: ?
 * ===========================================================================*/
const uint8_t * UssMgr_uGetCRNFDConf(void)
{
#ifdef US_D_ENABLE_CHIRP_RING_NFD
    return uaUssMgr_CRNFD_OutputConf;
#else
    return aUssMgr_SafeFlashBlankArray;
#endif
}

#ifdef US_D_MGR_WALL_HIGH_FLAGS
/* ===========================================================================
 * Name:	 UssMgr_uGetWallFlagByGroup
 * Remarks:  DD-ID: {1CC125FF-C708-4562-AD57-196C86E2ACE1}
 * Req.-ID: ?
 * ===========================================================================*/
uint8_t UssMgr_uGetWallFlagsByGroup(uint8_t uGrpIdx)
{
    const US_S_PlatPhysInfo_t *psGrpLayout;
    const US_S_SnrCalcs_t *psSnrCalcs;
    uint8_t uNumSnrsInGrpLocal;
    uint8_t uGrpSnrIdx, uSnrIdx;
    uint8_t ubitWallFlags;

    psGrpLayout = UssCtrl_psGetPlatPhysInfo();
    uNumSnrsInGrpLocal = psGrpLayout->psSnrPhysGrp[uGrpIdx].uNumSnrsInGrp;
    if( uNumSnrsInGrpLocal < FOUR )
    {
        /* this group is not compatible */
        return ME_FALSE;
    }

    psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    ubitWallFlags = ZERO;
    /* Gather high flags as bits */
    for (uGrpSnrIdx = ZERO; uGrpSnrIdx < uNumSnrsInGrpLocal; uGrpSnrIdx++)
    {
        uSnrIdx = psGrpLayout->psSnrPhysGrp[uGrpIdx].uSnrDataIdx[uGrpSnrIdx];
        if(psSnrCalcs->sSnrCalcRec[uSnrIdx].sEchoCalc[ZERO].bLargeObject == ME_TRUE)
        {
            ubitWallFlags |= (ONE<<uGrpSnrIdx);
        }
    }

    return ubitWallFlags;
}
/* ===========================================================================
 * Name: UssMgr_bGetWallGuessbyBumper	
 * Remarks:  DD-ID: {CBC5EA68-EC9B-43a7-83DA-33A3444844F6}
 * lazy function based on sensor position names only 
 * ===========================================================================*/
bool_t UssMgr_bGetWallGuessbyBumper(uint8_t uBumperIndex)
{
    bool_t bIsGuessHigh = ME_FALSE;
    uint8_t uNumOfHigh = ZERO;
    const US_S_SnrCalcs_t *psSnrCalcs;

    psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    if(uBumperIndex == US_D_PHYS_GRP_FRNT)
    {
        uNumOfHigh += (uint8_t)psSnrCalcs->sSnrCalcRec[US_D_SENSOR_FIL].sEchoCalc[ZERO].bLargeObject;
        uNumOfHigh += (uint8_t)psSnrCalcs->sSnrCalcRec[US_D_SENSOR_FIR].sEchoCalc[ZERO].bLargeObject;
#if (US_D_MWH_USE_INNER_ONLY == ME_FALSE)
        uNumOfHigh += (uint8_t)psSnrCalcs->sSnrCalcRec[US_D_SENSOR_FOL].sEchoCalc[ZERO].bLargeObject;
        uNumOfHigh += (uint8_t)psSnrCalcs->sSnrCalcRec[US_D_SENSOR_FOR].sEchoCalc[ZERO].bLargeObject;
#endif
    }

    if(uBumperIndex == US_D_PHYS_GRP_REAR)
    {
        uNumOfHigh += (uint8_t)psSnrCalcs->sSnrCalcRec[US_D_SENSOR_RIL].sEchoCalc[ZERO].bLargeObject;
        uNumOfHigh += (uint8_t)psSnrCalcs->sSnrCalcRec[US_D_SENSOR_RIR].sEchoCalc[ZERO].bLargeObject;
#if (US_D_MWH_USE_INNER_ONLY == ME_FALSE)
        uNumOfHigh += (uint8_t)psSnrCalcs->sSnrCalcRec[US_D_SENSOR_ROL].sEchoCalc[ZERO].bLargeObject;
        uNumOfHigh += (uint8_t)psSnrCalcs->sSnrCalcRec[US_D_SENSOR_ROR].sEchoCalc[ZERO].bLargeObject;
#endif
    }

    if( (uNumOfHigh * (uint8_t)ME_TRUE) >= ((uint8_t)US_D_MWH_NEEDED_HIGH_SENSORS))
    {
        bIsGuessHigh = ME_TRUE;
    }

    return bIsGuessHigh;
}
/* ===========================================================================
 * Name: UssMgr_bGetWallGuessbyBumper_Persist	
 * Remarks:  DD-ID: {3380FBE6-7985-4449-8877-7B9982EF3AA4}
 * ==========================================================================*/
bool_t UssMgr_bGetWallGuessbyBumper_Persist(uint8_t uBumperIndex)
{
    bool_t bIsGuessHigh = ME_FALSE;
    uint8_t uNumOfHigh = ZERO;
    //const US_S_SnrCalcs_t *psSnrCalcs;

#if (US_D_MWH_PERSIST_FLAG == ME_TRUE)
    //psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    if(uBumperIndex == US_D_PHYS_GRP_FRNT)
    {
        uNumOfHigh += (uint8_t)baUssMgr_Persistent_LargeFlag[US_D_SENSOR_FIL];
        uNumOfHigh += (uint8_t)baUssMgr_Persistent_LargeFlag[US_D_SENSOR_FIR];
#if (US_D_MWH_USE_INNER_ONLY == ME_FALSE)
        uNumOfHigh += (uint8_t)baUssMgr_Persistent_LargeFlag[US_D_SENSOR_FOL];
        uNumOfHigh += (uint8_t)baUssMgr_Persistent_LargeFlag[US_D_SENSOR_FOR];
#endif
    }

    if(uBumperIndex == US_D_PHYS_GRP_REAR)
    {
        uNumOfHigh += (uint8_t)baUssMgr_Persistent_LargeFlag[US_D_SENSOR_RIL];
        uNumOfHigh += (uint8_t)baUssMgr_Persistent_LargeFlag[US_D_SENSOR_RIR];
#if (US_D_MWH_USE_INNER_ONLY == ME_FALSE)
        uNumOfHigh += (uint8_t)baUssMgr_Persistent_LargeFlag[US_D_SENSOR_ROL];
        uNumOfHigh += (uint8_t)baUssMgr_Persistent_LargeFlag[US_D_SENSOR_ROR];
#endif
    }

    if( (uNumOfHigh * (uint8_t)ME_TRUE) >= ((uint8_t)US_D_MWH_NEEDED_HIGH_SENSORS))
    {
        bIsGuessHigh = ME_TRUE;
    }
#endif /* # (US_D_MWH_PERSIST_FLAG ) */

    return bIsGuessHigh;
}
#endif /* US_D_MGR_WALL_HIGH_FLAGS */

