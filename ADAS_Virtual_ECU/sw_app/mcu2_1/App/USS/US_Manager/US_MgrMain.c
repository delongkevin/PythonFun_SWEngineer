/*
 * US_MgrMain.c
 *
 *  Created on: Aug 9, 2021
 *      Author: jonapais
 */

#include "US_SysMgr_Global.h"
#include "US_MgrFilter.h"
#include "US_MgrSensorProc.h"
#include "US_Platform_Global.h"
#include "US_MgrEnvCheck.h"
#include "US_MgrBlockage.h"
#include "US_MgrInterface.h"
#include "US_MgrModeControl.h"
#include "US_MgrUtility.h"
#include "US_Diagnostic_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_ErrMgr_Global.h"
#include "US_MgrDataSim.h"
#include "US_SnrDrv_Global.h"
#include "US_MgrDiagnostic.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_ObjDet_CsmIf.h"
#endif


#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS))
#include "US_Hsd_Global.h"
#endif

#ifndef USSMGR_GLOBAL_CHIRP_DISABLE
    #define US_D_REACT_TO_NOISE
#endif
#ifdef US_D_REACT_TO_NOISE
    //#define US_D_ENABLE_DEGRADED_STATE
#endif
//#define US_D_FORCE_NOISY

#if defined(US_D_REACT_TO_NOISE) || defined(US_D_FORCE_NOISY)
    #define US_D_CARAVAN_NOISE_PROTECTION
#endif
#define US_D_FAULT_FLAG_DEBUG

#ifdef US_D_ENABLE_DEGRADED_STATE
	//#define US_D_REACT_IN_DEGRADED_STATE
	#ifdef US_D_REACT_IN_DEGRADED_STATE
		#define US_D_GOTO_CAUTION_IN_DEG_STATE
		//add something for OD and lone directs
	#endif
#endif

#define US_D_MGR_RECOVER_TO_PREV_STATE
/*#define US_D_MGR_OFF_TO_PREV_STATE  Not implemented yet */


#if (US_D_CUR_SW_PURPOSE == US_D_RELEASE)
	//#define US_D_SILENCE_ALL_IN_PARK
	//#define US_D_SILENCE_REAR_IN_DRIVE
#endif

//#define US_D_ONLY_REAR_SYSTEM



#define US_D_MGR_ALLOW_INSTANT_NOISY_RECOVERY   ME_FALSE
#define US_D_NOISE_HIGH_SENSORS_THRESHOLD   1u
#define US_D_NOISE_LOW_SENSORS_THRESHOLD    2u
#define US_D_NOISE_TYPE_MIN_CNT             4u
#define US_D_NOISE_DEFAULT_MITMODE          US_NOISEMIT_FILTER1
#define US_D_GRP_STATECHANGESTARTTIME_INIT      (ZERO)

/* Delays are all 1ms time */
    #define US_D_GRP_NOISY_TO_DEGRADED_DELAY    1000u
    #define US_D_GRP_DEGRADED_TO_OK_DELAY       500u
#define US_D_GRP_NOISY_TO_OK_DELAY          10000u

#define US_D_GRP_STARTUP_TEST_CYCLES    (28u) //\TODO jwr - BASED ON FIRE CYCLE!!! must change to be independent!!


/* doesn't need to be in calibration - actual local #def */
#define US_D_GRP_FAULTED    0xAAu
#define US_D_GRP_NOT_FAULTED    0x11u

/* System State */
static volatile UssMgr_e_SysState_t UssMgr_eSysState = SYSMGR_SYS_INIT;
/* Group State */
static volatile UssMgr_E_GroupState_t UssMgr_eGrpState[US_D_PHYS_GRP_MAX];
#if defined(US_D_MGR_RECOVER_TO_PREV_STATE) || defined(US_D_MGR_OFF_TO_PREV_STATE)
static UssMgr_E_GroupState_t UssMgr_ePrevGrpState[US_D_PHYS_GRP_MAX];
#endif 

static volatile bool_t  UssMgr_bSelfTestEnabled = ME_FALSE;
static volatile bool_t  UssMgr_bGrpForceDisabled[US_D_PHYS_GRP_MAX];
static uint32_t UssMgr_eGrpStateChangeStartTime[US_D_PHYS_GRP_MAX];
static US_E_NoiseLevel_t UssMgr_ePrevGrpNoiseLevel[US_D_PHYS_GRP_MAX];
static uint8_t UssMgr_uStartupTestCounter;  //sys wide counter to delay groups off in Park

/* New output data flag */
static bool_t UssMgr_bNewOutputData = ME_FALSE;

/* New diag output data flag */
static bool_t UssMgr_bNewDiagOutputData = ME_FALSE;

/* Saved noise type decision */
static UssMgr_E_NoiseReaction_t UssMgr_eNoiseReaction;
static US_E_NoiseMitigationMode_t UssMgr_eGrpNoiseMitType[US_D_PHYS_GRP_MAX];
static US_E_NoiseMitigationMode_t UssMgr_ePrevNoiseMitGuess[US_D_PHYS_GRP_MAX];
uint8_t UssMgr_uNewMitTypeConfirmations[US_D_PHYS_GRP_MAX];
static uint8_t UssMgr_uRandChecksTarget;

#if(US_CSM_ENABLE == ME_TRUE)
static UsCsm_LocalStateId_Type LocalStateId_ObjDet = US_CSM_LOCAL_STATE_UN_INIT;
#endif
US_E_NoiseLevel_t UssDBG_RearNoiseLevel = US_E_NOISELEVEL_NONE;
uint8_t UssDBG_RearStateNoisyTimeDiff50 = 0u;
uint8_t UssDBG_UnsureCnt[6] = {0u,0u,0u,0u,0u,0u};
uint8_t UssDBG_NoiseLevel[6] = {0u,0u,0u,0u,0u,0u};

uint8_t UssDBG_FrontNoiseTypeCnt[2];
uint8_t UssDBG_RearNoiseTypeCnt[2];
uint8_t UssDBG_US_E_NoiseType[US_D_MAX_NUM_SENSORS];

/* Keep this change. This is to always force noise in front mode */
uint8_t g_LAUD_ForceNoisyOn = 0u;
uint8_t g_LAUD_ForceFrontNoisy = 1u;

/* globals for CVADAS debug */
uint8_t UssGlo_HighSensorsThres = US_D_NOISE_HIGH_SENSORS_THRESHOLD;
uint8_t UssGlo_LowSensorsThres = US_D_NOISE_LOW_SENSORS_THRESHOLD;
uint32_t UssGlo_NoisyToOkDelay = US_D_GRP_NOISY_TO_OK_DELAY;

/****** Internal functions *******/
static void UssMgr_InitGroupState(void);
static void UssMgr_RunGroupStateUpdate(void);
static void UssMgr_Main_UpdateInputs(void);

/* State machine transition functions */

static void UssMgr_GrpTrans_Any_To_Ok(uint8_t GroupIndex);
static void UssMgr_GrpTrans_Any_To_Faulted(uint8_t GroupIndex);
#ifdef US_D_ENABLE_DEGRADED_STATE
static void UssMgr_GrpTrans_Any_To_Deg(uint8_t GroupIndex);
#endif
static void UssMgr_GrpTrans_Any_To_Noisy(uint8_t GroupIndex);
static void UssMgr_GrpTrans_Any_To_Off(uint8_t GroupIndex);
static void UssMgr_TriggerStartupTest(void);


static US_E_NoiseLevel_t UssMgr_SnrToGrp_CheckNoise(uint8_t GroupIndex);
static uint8_t UssMgr_SnrToGrp_CheckFaults(uint8_t GroupIndex);

static uint8_t USS_GetBumperEnable(void);

/*===========================================================================
 * \brief USS manager main task execution.
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_Main
 * Remarks:  DD-ID: {28FCCB25-46EA-44de-83A9-CAD9E4A0D515}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssMgr_Main(void)
{
    bool_t bNewSnrData;
    const bool_t bPopulateComOutputBuffer  = UssMgr_PopulateComOutputBuffer();
    const bool_t bPopulateDiagFlagsInComOutBuff =  UssMgr_PopulateDiagFlagsInComOutBuff() ;

    /* Run any housekeeping or cyclic input updates */
    UssMgr_Util_UpdateInputs();
    UssMgr_Main_UpdateInputs();
   /*
    * *************** BUFFER INPUT DATA MODULE ****************
    */
    UssMgr_CopyNewSnrDataToBuffer();

       bNewSnrData  =   UssMgr_bIsNewSnrData();
    /* Run these functions only if new sensor data is available */
    if (bNewSnrData != ((bool_t)ME_FALSE))
    {
        /*
        * *************** SENSOR DATA PROCESSING MODULE ****************
        */
        UssMgr_SensorDataProc();

        /* Group Status Statemachine */
        UssMgr_RunGroupStateUpdate();


        /* Mgr done */
        UssMgr_bNewOutputData = ME_TRUE;

#if US_D_SIMULATION_ACTIVE == ME_TRUE
        UssMgr_CreateSimulationMeas();
#endif
    }

    /* Check if new diagnostics message information has been received */
    if ((bool_t)ME_FALSE == UssMgr_bNewDiagOutputData)
    {
        UssMgr_bNewDiagOutputData = UssMgr_CheckSnrForErrors();
    }

    /*
     * If there is new output data then write it to com output buffer.
     * In case of semaphore take fail, try again next task cycle.
     */
    if (UssMgr_bNewOutputData == (bool_t)ME_TRUE)
    {
        if (bPopulateComOutputBuffer == (bool_t)ME_TRUE)
        {
            UssMgr_bNewOutputData = ME_FALSE;
            UssMgr_bNewDiagOutputData = ME_FALSE;  // Diag flags are also populated here. No need to do twice.
        }
    }
	
    /* If new diag data, even if no measurement, such as in standby, then populate diag flags */
    if (UssMgr_bNewDiagOutputData == (bool_t)ME_TRUE)
    {
        if (bPopulateDiagFlagsInComOutBuff == (bool_t)ME_TRUE)
        {
            UssMgr_bNewDiagOutputData = ME_FALSE;
        }
    }
	/* TODO JWR: Why aren't these two in controller? */
    UssHsd_F_StateMachine();
    US_SnrDrv_DSI3_Check();
/*These functions are place here to call them periodically after every 10 msec, can be place in other task */
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
    US_ECUDiagFlagCheckMain();
    US_SnrDiagFlagCheckMain();
#endif

}
/*===========================================================================
 * \brief USS manager initialization.
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_ManagerInit
 * Remarks:  DD-ID: {155CE5DE-086F-4095-9B5B-09313B95E7D8}
 * Req.-ID: 13396023
 * ===========================================================================*/
void UssMgr_ManagerInit(void)
{
    UssMgr_BlockageInit();
    UssMgr_EnvCheckInit();
    UssMgr_FilterInit();
    UssMgr_ModeControlInit();
    UssMgr_DiagnosticInit();
    
    /* local */
    UssMgr_InitGroupState();
}

/*===========================================================================
 * brief USS manager cyclic input gathering.
 * remarks Any cyclic input updates for MgrMain. Could be called outside MgrMain
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_Main_UpdateInputs
 * Remarks:  DD-ID: {4206A126-D87B-4b59-8644-598FB6A00637}
 * Req.-ID: 
 * ===========================================================================*/
static void UssMgr_Main_UpdateInputs(void)
{
    UssMgr_E_NoiseReaction_t eCfgNoiseReaction;

    eCfgNoiseReaction = US_SnrCfg_Get_NoiseReaction();
    if (SYSMGR_NOISEREACT_MAX > eCfgNoiseReaction)
    {
        UssMgr_eNoiseReaction = eCfgNoiseReaction;
    }
    else
    {
        /* Configuration returned a bad value, use default */
        UssMgr_eNoiseReaction = SYSMGR_NOISEREACT_STATIC_CHIRP;
    }
}


/* ===========================================================================
 * Name:	 UssMgr_SnrToGrp_CheckFaults
 * Remarks:  DD-ID: {655DFC90-9EDD-4f07-8212-677CD262725C}
 *  Req.-ID: 14959513
 *  Req.-ID: 14959555
 *  Req.-ID: 14959230
 *  Req.-ID: 13393741
 *  Req.-ID: 13396016
 *  Req.-ID: 14959476
 *  Req.-ID: 14959513
 * ===========================================================================*/

static uint8_t UssMgr_SnrToGrp_CheckFaults(uint8_t GroupIndex)
{
	uint16_t snrgroup = 0;
    uint32_t snrmap =0;
    uint8_t snrfault;
    uint8_t eRet_FaultStatus = US_D_GRP_NOT_FAULTED;

    const US_S_PlatPhysInfo_t * psPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();

/*Read sensor group*/
    snrgroup = psPlatPhysInfo->psSnrPhysGrp[GroupIndex].uGrpSnrIdxBitMap;

    /*Check sensor failures for below faults */   
    for(snrfault = 0;snrfault <(uint8_t)SNR_DIAG_FLG_SNR_FLAG_MAX_CODE;snrfault++)
    {

#if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)||(US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER))

 	if((snrfault == (uint8_t)SNR_DIAG_FLG_SENSOR_DISCONNECT) || (snrfault == (uint8_t)SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT) 
	     || (snrfault == (uint8_t)SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE) || (snrfault == (uint8_t)SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE)
	     || (snrfault == (uint8_t)SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST) || (snrfault == (uint8_t)SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST)
	     || (snrfault == (uint8_t)SNR_DIAG_FLG_RING_COMPARATOR_ZERO) || (snrfault == (uint8_t)SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE)
	     || (snrfault == (uint8_t)SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST) || (snrfault == (uint8_t)SNR_DIAG_FLG_BAD_RING_TIME) || (snrfault == (uint8_t)SNR_DIAG_FLG_SNR_FAIL))
#else
 		if((snrfault == (uint8_t)SNR_DIAG_FLG_SENSOR_DISCONNECT) || (snrfault == (uint8_t)SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT) 
	     || (snrfault == (uint8_t)SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE) || (snrfault == (uint8_t)SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE)
	     || (snrfault == (uint8_t)SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST) || (snrfault == (uint8_t)SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST)
	     || (snrfault == (uint8_t)SNR_DIAG_FLG_RING_COMPARATOR_ZERO) || (snrfault == S(uint8_t)NR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE)
	     || (snrfault == (uint8_t)SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST))

#endif			
    	{
    		snrmap = US_Diagnostic_IsSnrFaultFlagPending((US_E_SnrFaultReason_t)snrfault);

    		if(snrmap!= (uint32_t)0)
    		{
    			break;
    		}
    	}

    }

        /* Check which group sensor is disconnected and raise the faulty bumper flag.*/
        if((snrgroup & snrmap)!= (uint32_t)0)
        {
        	eRet_FaultStatus = US_D_GRP_FAULTED;
        }

    return eRet_FaultStatus;
}

/* ===========================================================================
 * Name:	 UssMgr_SnrToGrp_CheckNoise
 * Remarks:  DD-ID: {47152E4B-6FB0-46e4-A884-19E77464837C}
 * Req.-ID: 13396047
 * Req.-ID: 13396023
 * Req.-ID: 13395860
 * Req.-ID: 13395865
 * Req.-ID: 13395881
 * Req.-ID: 13395886
 * ===========================================================================*/
static US_E_NoiseLevel_t UssMgr_SnrToGrp_CheckNoise(uint8_t GroupIndex)
{
    uint8_t uNumSnrsInGrpLocal;
    uint8_t uGrpSnrIdx;
    uint8_t uAppSnrIdx;
    const US_S_AllSnrNoiseData_t *psSnrNoise;
    const US_S_AllSnrChirpTypeHist_t *psSnrChirpHist;
    const US_S_PlatPhysInfo_t *psGrpLayout;
    uint8_t uHighNoiseCnt, uLowNoiseCnt;
    US_E_NoiseLevel_t eRet_OverallNoise = US_E_NOISELEVEL_NONE;
    US_E_NoiseMitigationMode_t eOverallNoiseMitType = US_NOISEMIT_MAX;
    uint8_t uUpNoiseCnt = ZERO;
    uint8_t uDownNoiseCnt = ZERO;
    /* Keep this change. This is to always force noise in front mode */
    if( g_LAUD_ForceNoisyOn == 1u ) { return US_E_NOISELEVEL_HIGH; }
    if( g_LAUD_ForceFrontNoisy == 1u ) { if(GroupIndex == US_D_PHYS_GRP_FRNT) {return US_E_NOISELEVEL_HIGH;} }
    if( GroupIndex < US_D_PHYS_GRP_MAX )
    {
        psSnrNoise = UssMgr_GetAllSnrNoiseData();
        psSnrChirpHist = UssMgr_GetAllSnrChirpTypeHist();
        psGrpLayout = UssCtrl_psGetPlatPhysInfo();

        uNumSnrsInGrpLocal = psGrpLayout->psSnrPhysGrp[GroupIndex].uNumSnrsInGrp;
        uHighNoiseCnt = ZERO;
        uLowNoiseCnt = ZERO;
        
        if(uNumSnrsInGrpLocal != ZERO)
        {
            //Perform for each sensor in physical group
            for (uGrpSnrIdx = ZERO; uGrpSnrIdx < uNumSnrsInGrpLocal; uGrpSnrIdx++)
            {
                /* Gather general sensor noise level */
                uAppSnrIdx = psGrpLayout->psSnrPhysGrp[GroupIndex].uSnrDataIdx[uGrpSnrIdx];
                if (psSnrNoise->sSnrNoiseData[uAppSnrIdx].eCurrentLevel == US_E_NOISELEVEL_HIGH)
                {                
                    if(uHighNoiseCnt  < UINT8_MAX)
                    {
                        uHighNoiseCnt++;
                    }
                    else{}
                }
                if (psSnrNoise->sSnrNoiseData[uAppSnrIdx].eCurrentLevel == US_E_NOISELEVEL_LOW)
                {
                     if(uHighNoiseCnt  < UINT8_MAX)
                    {
                        uHighNoiseCnt++;
                    }
                    else{}
                }

                if (SYSMGR_NOISEREACT_DYN_CHIRP == UssMgr_eNoiseReaction)
                {
                    /* Check sensor's chirp type guess and add to overall cnt - for UP */
                    if (psSnrNoise->sSnrNoiseData[uAppSnrIdx].eNoiseTypeGuess > US_E_NOISETYPE_GENERIC)
                    {
                        uUpNoiseCnt = uUpNoiseCnt + (uint8_t)psSnrNoise->sSnrNoiseData[uAppSnrIdx].eNoiseTypeGuess;
                    }
                    /* Check sensor's chirp type guess and add to overall cnt - for DOWN */
                    if (psSnrNoise->sSnrNoiseData[uAppSnrIdx].eNoiseTypeGuess < US_E_NOISETYPE_GENERIC)
                    {
                        uDownNoiseCnt = uDownNoiseCnt + (uint8_t)((sint8_t)psSnrNoise->sSnrNoiseData[uAppSnrIdx].eNoiseTypeGuess * (-1));
                    }
                }
                UssDBG_US_E_NoiseType[uAppSnrIdx] = (uint8_t)psSnrNoise->sSnrNoiseData[uAppSnrIdx].eNoiseTypeGuess + 3u;
            }

            /* Determine overall general noise level */
         
            if (uHighNoiseCnt >= UssGlo_HighSensorsThres)
            {
                eRet_OverallNoise = US_E_NOISELEVEL_HIGH;
            }
        
            else if (uLowNoiseCnt >= UssGlo_LowSensorsThres)  //this assumes no high!!
            {
                eRet_OverallNoise = US_E_NOISELEVEL_LOW;
            }
            else
            {
                eRet_OverallNoise = US_E_NOISELEVEL_NONE;
            }
            uint8_t i=0u;
            for (i=6u;i<12u;i++)
            {
                UssDBG_UnsureCnt[i] = psSnrNoise->sSnrNoiseData[i].uUnsureCounter;
                UssDBG_NoiseLevel[i] = psSnrNoise->sSnrNoiseData[i].eCurrentLevel;
            }
            

            if (SYSMGR_NOISEREACT_DYN_CHIRP == UssMgr_eNoiseReaction)
            {
                /* Check the accumulated count of each chirp type, see which is higher AND passes minimum for action */
                if ((uDownNoiseCnt > uUpNoiseCnt) && (uDownNoiseCnt >= US_D_NOISE_TYPE_MIN_CNT))
                {
                    /* we see down, switch to up */
                    eOverallNoiseMitType = US_NOISEMIT_FILTER2; //UP
                }
                else if ((uUpNoiseCnt > uDownNoiseCnt) && (uUpNoiseCnt >= US_D_NOISE_TYPE_MIN_CNT))
                {
                    eOverallNoiseMitType = US_NOISEMIT_FILTER1; //DOWN
                }
                else
                {
                    /* Minimums failed, keep default */
                    eOverallNoiseMitType = US_NOISEMIT_MAX;
                }

                /* add random pause/confirmations to avoid two systems switching at the same time */
                if (eOverallNoiseMitType == UssMgr_ePrevNoiseMitGuess[GroupIndex])
                {
                    UssMgr_uNewMitTypeConfirmations[GroupIndex]++;
                }
                else /* different chirp type seen, abort and start new */
                {
                    UssMgr_uNewMitTypeConfirmations[GroupIndex] = ZERO;
                UssMgr_uRandChecksTarget = (uint8_t)(UssMgr_JKISS32RandAlgo() & 0x03u); //zero is ok
                }
                UssMgr_ePrevNoiseMitGuess[GroupIndex] = eOverallNoiseMitType;
                /* Enough confirmations, change sent chirp type */
                if(UssMgr_uNewMitTypeConfirmations[GroupIndex] >= UssMgr_uRandChecksTarget)
                {
                    UssMgr_eGrpNoiseMitType[GroupIndex] = UssMgr_ePrevNoiseMitGuess[GroupIndex];
                }
            }
        }
    }
    else
    {
        eRet_OverallNoise = US_E_NOISELEVEL_NONE;
      
    }
    
    if (GroupIndex == US_D_PHYS_GRP_REAR)
    {
        UssDBG_RearNoiseLevel = eRet_OverallNoise;
        UssDBG_RearNoiseTypeCnt[0] = uDownNoiseCnt;
        UssDBG_RearNoiseTypeCnt[1] = uUpNoiseCnt;
    }
    else
    {
        UssDBG_FrontNoiseTypeCnt[0] = uDownNoiseCnt;
        UssDBG_FrontNoiseTypeCnt[1] = uUpNoiseCnt;
    }
    return eRet_OverallNoise;
}

/* ===========================================================================
 * Name:	 UssMgr_InitGroupState
 * Remarks:  DD-ID: {E340C713-54B6-42cf-9321-8A3D665C3729}
 * Req.-ID: 13396023
 * ===========================================================================*/
static void UssMgr_InitGroupState(void)
{
    uint8_t uGrpIdx;

    for( uGrpIdx = 0; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++ )
    {
        UssMgr_eGrpState[uGrpIdx] = SYSMGR_GRPSTATE_OFF;
        UssMgr_eGrpStateChangeStartTime[uGrpIdx] = US_D_GRP_STATECHANGESTARTTIME_INIT;
        
        UssMgr_bGrpForceDisabled[uGrpIdx] = ME_FALSE;

#if defined(US_D_MGR_RECOVER_TO_PREV_STATE) || defined(US_D_MGR_OFF_TO_PREV_STATE)
        UssMgr_ePrevGrpState[uGrpIdx] = SYSMGR_GRPSTATE_OFF;
#endif
        /* Chirp up/down init */
        UssMgr_eNoiseReaction = SYSMGR_NOISEREACT_MAX;
        UssMgr_eGrpNoiseMitType[uGrpIdx] = US_NOISEMIT_MAX;
        UssMgr_ePrevNoiseMitGuess[uGrpIdx] = US_NOISEMIT_MAX;
        UssMgr_uNewMitTypeConfirmations[uGrpIdx] = ZERO;
        UssMgr_uRandChecksTarget = TWO;
    }
    //if there is a SysMgr init, but this there instead
    UssMgr_TriggerStartupTest();
}


// Off to OK might be needed in the future
/* ===========================================================================
 * Name:	 UssMgr_GrpTrans_Any_To_Ok
 * Remarks:  DD-ID: {C55481FF-FE9D-4f70-A8F3-733EB112AA2C}
 * Req.-ID: 13424090
 * ===========================================================================*/

static void UssMgr_GrpTrans_Any_To_Ok(uint8_t GroupIndex)
{
    if( GroupIndex < US_D_PHYS_GRP_MAX )
    {
        //set normal burst
        UssMgr_SetNextNoiseMitMode(GroupIndex, US_NOISEMIT_NONE);
        
        //change state
        UssMgr_eGrpState[GroupIndex] = SYSMGR_GRPSTATE_OK;
        //reset general timer
        UssMgr_eGrpStateChangeStartTime[GroupIndex] = US_D_GRP_STATECHANGESTARTTIME_INIT;
    }
    else
    {
        //ASSERT(TRUE)
    }
}
/* ===========================================================================
 * Name:	 UssMgr_GrpTrans_Any_To_Faulted
 * Remarks:  DD-ID: {4755808E-C4F4-463d-AD4A-31F8819A12F4}
 * Req.-ID: 13424090
 * ===========================================================================*/
static void UssMgr_GrpTrans_Any_To_Faulted(uint8_t GroupIndex)
{
    if( GroupIndex < US_D_PHYS_GRP_MAX )
    {
        //enable/disable fault suppression?
        //change OD behavior?
        
        //if noise reaction is to disable firing, enable firing just in case we came from OFF state
        UssMgr_E_NoiseReaction_t eNoiseReaction = US_SnrCfg_Get_NoiseReaction();
        if (SYSMGR_NOISEREACT_SILENCE == eNoiseReaction)
        {
            UssMgr_SetNextNoiseMitMode(GroupIndex, US_NOISEMIT_NONE);
        }

#ifdef US_D_MGR_RECOVER_TO_PREV_STATE
        /* save previous state for recovery */
        UssMgr_ePrevGrpState[GroupIndex] = UssMgr_eGrpState[GroupIndex];
#endif
        // change state
        UssMgr_eGrpState[GroupIndex] = SYSMGR_GRPSTATE_FAULTED;
        //reset general timer
        UssMgr_eGrpStateChangeStartTime[GroupIndex] = US_D_GRP_STATECHANGESTARTTIME_INIT;
    }
    else
    {
        //ASSERT(TRUE)
    }
}
/* ===========================================================================
 * Name:	 UssMgr_GrpTrans_Any_To_Deg
 * Remarks:  DD-ID: {8A5E78B5-F485-40eb-A7C3-27A2021A108B}
 * Req.-ID: 13424090
 * ===========================================================================*/

#ifdef US_D_ENABLE_DEGRADED_STATE
static void UssMgr_GrpTrans_Any_To_Deg(uint8_t GroupIndex)
{
    if( GroupIndex < US_D_PHYS_GRP_MAX )
    {
        //insert enable setter for enabling echo filtering?
        
#ifdef US_D_REACT_IN_DEGRADED_STATE
    #ifdef US_D_GOTO_CAUTION_IN_DEG_STATE
        //change firing seq (more aggressive noise check? chirp mix?)?
        UssMgr_SetNextNoiseMitMode(GroupIndex, US_NOISEMIT_CAUTION);
    #else
        //set normal burst cfg in case we came from noisy state
        UssMgr_SetNextNoiseMitMode(GroupIndex, US_NOISEMIT_NONE);
    #endif
#else
        //do nothing, treat as transition state
#endif
        
        // change state
        UssMgr_eGrpState[GroupIndex] = SYSMGR_GRPSTATE_DEGRADED;
        //reset general timer
        UssMgr_eGrpStateChangeStartTime[GroupIndex] = US_D_GRP_STATECHANGESTARTTIME_INIT;
    }
    else
    {
        //ASSERT(TRUE)
    }
}
#endif
/* ===========================================================================
 * Name:	 UssMgr_GrpTrans_Any_To_Noisy
 * Remarks:  DD-ID: {F95DDAE9-117A-4948-B68E-52CC045942CE}
 * Req.-ID: 13424090
 * ===========================================================================*/

static void UssMgr_GrpTrans_Any_To_Noisy(uint8_t GroupIndex)
{
    UssMgr_E_NoiseReaction_t eNoiseReaction = US_SnrCfg_Get_NoiseReaction();
    if( GroupIndex < US_D_PHYS_GRP_MAX )
    {
        switch( eNoiseReaction )
        {
            case SYSMGR_NOISEREACT_STATIC_CHIRP:
            {
                //enable full time chirp fire seq
#ifdef US_D_CARAVAN_NOISE_PROTECTION
                switch(GroupIndex)
                {
                    case US_D_PHYS_GRP_FRNT:
                        UssMgr_SetNextNoiseMitMode(GroupIndex, US_NOISEMIT_FILTER1); /*DOWN*/
                        break;
                        
                    case US_D_PHYS_GRP_REAR:
                    default:
                        UssMgr_SetNextNoiseMitMode(GroupIndex, US_NOISEMIT_FILTER2); /*UP*/
                        break;
                }
#else
                UssMgr_SetNextNoiseMitMode(GroupIndex, US_D_NOISE_DEFAULT_MITMODE);
#endif
                break;
            }
            case SYSMGR_NOISEREACT_DYN_CHIRP:
            {
                if (UssMgr_eGrpNoiseMitType[GroupIndex] != US_NOISEMIT_MAX)
                {
                    UssMgr_SetNextNoiseMitMode(GroupIndex, UssMgr_eGrpNoiseMitType[GroupIndex]);
                }
                else
                {
                    UssMgr_SetNextNoiseMitMode(GroupIndex, US_D_NOISE_DEFAULT_MITMODE);
                }
                break;
            }
            case SYSMGR_NOISEREACT_SILENCE:
            default:
            {
                //silence group
                UssMgr_SetNextNoiseMitMode(GroupIndex, US_NOISEMIT_LISTEN_ONLY);
                break;
            }
        }
        // change state
        UssMgr_eGrpState[GroupIndex] = SYSMGR_GRPSTATE_NOISY;
        //reset general timer
        UssMgr_eGrpStateChangeStartTime[GroupIndex] = US_D_GRP_STATECHANGESTARTTIME_INIT;
    }
    else
    {
        //ASSERT(TRUE)
    }
}

/* ===========================================================================
 * Name:	 UssMgr_GrpTrans_Any_To_Off
 * Remarks:  DD-ID: {99C8FC0E-5041-4545-800C-C65B459AEFF7}
 * Req.-ID: 13424090
 * ===========================================================================*/
static void UssMgr_GrpTrans_Any_To_Off(uint8_t GroupIndex)
{
    if( GroupIndex < US_D_PHYS_GRP_MAX )
    {
        //init everything?
        
        //silence group as the "off" condition
        UssMgr_SetNextNoiseMitMode(GroupIndex, US_NOISEMIT_LISTEN_ONLY);
                
        //change state
        UssMgr_eGrpState[GroupIndex] = SYSMGR_GRPSTATE_OFF;
        //reset general timer
        UssMgr_eGrpStateChangeStartTime[GroupIndex] = US_D_GRP_STATECHANGESTARTTIME_INIT;
    }
    else
    {
        //ASSERT(TRUE)
    }
}
/* ===========================================================================
 * Name:	 UssMgr_RunGroupStateUpdate
 * Remarks:  DD-ID: {76F9750C-A811-4092-89BE-4A329C82C4EC}
 * Req.-ID: 13424090
 * ===========================================================================*/

static void UssMgr_RunGroupStateUpdate(void)
{
    uint8_t uGrpIdx;
#ifdef US_D_SILENCE_ALL_IN_PARK
    US_E_App_Prndl_Status_e ePrndl;
#endif
    uint32_t uStateMachineNowTime;
    US_E_NoiseLevel_t eGrpNoise;
    uint8_t eGrpFaults = ZERO;
    bool_t  bDisableGrp;
   const US_E_GenericSignalValidityFlag_e eGearSpeedValid  = UssCom_F_GetGearSpeedValidity();
   const   uint8_t  uBumperEnable = USS_GetBumperEnable();
   const UssMgr_E_NoiseReaction_t eNoiseReaction = US_SnrCfg_Get_NoiseReaction();

    uStateMachineNowTime = US_GetTimeStampTimeMs();
    /* look at startup case for self test */
    if( UssMgr_uStartupTestCounter < US_D_GRP_STARTUP_TEST_CYCLES)
    {
        //force on - using this flag instead of bDisableGrp = ME_FALSE overwrite
        // in case there are other factors tied to the self test flag
        UssMgr_bSelfTestEnabled = ME_TRUE;
        UssMgr_uStartupTestCounter++; //reset from external source
    }
    else
    {
        //\TODO - validate if this will block external self test triggers early
        UssMgr_bSelfTestEnabled = ME_FALSE;
    }

    for( uGrpIdx = 0; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++ )
    {
        eGrpNoise = US_E_NOISELEVEL_NONE;
        eGrpFaults = US_D_GRP_NOT_FAULTED;
#ifdef US_D_ONLY_REAR_SYSTEM
        bDisableGrp = ME_TRUE; //start with all off - handles neutral cases
#else        
        bDisableGrp = ME_FALSE;
#endif
        
        /*** pre check group status for immediate state change */
        //check forced cmd inputs
        if(UssMgr_bGrpForceDisabled[uGrpIdx] ==(bool_t) ME_TRUE)
        {
            bDisableGrp = ME_TRUE;
        }
        //check gear status -> if Park -> off state
        else if(( eGearSpeedValid == US_SIGNALVALIDITY_VALID ) && !(((bool_t)ME_TRUE == uBumperEnable)))
        {

#ifdef US_D_SILENCE_ALL_IN_PARK
            /*Read Gear status*/
            ePrndl = UssCom_F_GetVehPrndl();

            if(ePrndl == US_PRNDL_PARK)
            {
                bDisableGrp = ME_TRUE;
            }

#endif
#ifdef US_D_SILENCE_REAR_IN_DRIVE
            else if( (ePrndl == US_PRNDL_DRIVE) && (uGrpIdx == US_D_PHYS_GRP_REAR) )
            {
                bDisableGrp = ME_TRUE;
            }
#endif
#ifdef US_D_ONLY_REAR_SYSTEM
            else if( ePrndl == US_PRNDL_REVERSE ) 
            {
                if( uGrpIdx != US_D_PHYS_GRP_REAR )
                {
                    bDisableGrp = ME_TRUE;
                }
                else
                {
                    bDisableGrp = ME_FALSE;
                }
            }
#endif            
            
        }
        else
        {
#ifdef US_D_ONLY_REAR_SYSTEM
            if( uGrpIdx != US_D_PHYS_GRP_REAR )
            {
                bDisableGrp = ME_TRUE;
            }
            else
#endif
            {
                bDisableGrp = ME_FALSE;
            }
        }
        
        /**** TEMP DEBUG - frontonly--test **/
  

        // check if forced disable was set
        if(  (bDisableGrp == (bool_t)ME_TRUE) && (UssMgr_bSelfTestEnabled == (bool_t)ME_FALSE) )
        {
            if( UssMgr_eGrpState[uGrpIdx] != SYSMGR_GRPSTATE_OFF ) /*PRQA S 2841 */ /* Sanity Check applied before usage */
            {
                UssMgr_GrpTrans_Any_To_Off(uGrpIdx);
                continue;  //this will skip normal handling
            }
        }
        
        // prevent overwritting fault state by checking first
        if ( UssMgr_eGrpState[uGrpIdx] != SYSMGR_GRPSTATE_FAULTED )
        {
            //check faults -> if true -> SYSMGR_GRPSTATE_FAULTED
            eGrpFaults = UssMgr_SnrToGrp_CheckFaults(uGrpIdx);
            if( eGrpFaults ==(uint8_t) US_D_GRP_FAULTED )
            {
                UssMgr_GrpTrans_Any_To_Faulted(uGrpIdx);
                continue;
            }
        }
        
        /*** normal state machine checks */
        switch(UssMgr_eGrpState[uGrpIdx])
        {
            case SYSMGR_GRPSTATE_OFF:
            {                
                //check request states
                if( (bDisableGrp == (bool_t)ME_FALSE) || (UssMgr_bSelfTestEnabled == (bool_t)ME_TRUE) )
                {
                    UssMgr_GrpTrans_Any_To_Ok(uGrpIdx);
                }
                break;
            }
            
            case SYSMGR_GRPSTATE_OK:
            {                                
                //check noise
#ifdef US_D_REACT_TO_NOISE
                eGrpNoise = UssMgr_SnrToGrp_CheckNoise(uGrpIdx);
#else
                eGrpNoise = US_E_NOISELEVEL_NONE;
#endif
#ifdef US_D_FORCE_NOISY
                eGrpNoise = US_E_NOISELEVEL_HIGH;
#endif
#ifdef US_D_ENABLE_DEGRADED_STATE
                if(eGrpNoise == US_E_NOISELEVEL_HIGH)
#else
                if( (eGrpNoise == US_E_NOISELEVEL_HIGH) || (eGrpNoise == US_E_NOISELEVEL_LOW) )
#endif
                {
                    UssMgr_GrpTrans_Any_To_Noisy(uGrpIdx);
                    break;
                }
#ifdef US_D_ENABLE_DEGRADED_STATE
                else if(eGrpNoise == US_E_NOISELEVEL_LOW)
                {
                    UssMgr_GrpTrans_Any_To_Deg(uGrpIdx);
                    break;
                }
#endif
                else
                {
                    //do nothing
                }
                
                break;
            }
            
            case SYSMGR_GRPSTATE_NOISY:
            {                               
                //check if group can exit noisy
                //check noise
                eGrpNoise = UssMgr_SnrToGrp_CheckNoise(uGrpIdx);
#ifdef US_D_FORCE_NOISY
                eGrpNoise = US_E_NOISELEVEL_HIGH;
#endif
                //go back to OK
                if(eGrpNoise == US_E_NOISELEVEL_NONE)
                {
#if (US_D_MGR_ALLOW_INSTANT_NOISY_RECOVERY == ME_TRUE)
                    UssMgr_GrpTrans_Any_To_Ok(uGrpIdx);
                    break;
#else
                    if ( (UssMgr_eGrpStateChangeStartTime[uGrpIdx] == US_D_GRP_STATECHANGESTARTTIME_INIT)
                        || (eGrpNoise != UssMgr_ePrevGrpNoiseLevel[uGrpIdx]) )
                    {
                        UssMgr_eGrpStateChangeStartTime[uGrpIdx] = uStateMachineNowTime;
                    }
                    /* doing ((now - start) > delay) because (now > (start + delay)) is not rollover proof */
                    if((uStateMachineNowTime - UssMgr_eGrpStateChangeStartTime[uGrpIdx]) > UssGlo_NoisyToOkDelay)
                    {
                        UssDBG_RearStateNoisyTimeDiff50 = (uint8_t)((uStateMachineNowTime - UssMgr_eGrpStateChangeStartTime[uGrpIdx]) / 50u);
                        UssMgr_GrpTrans_Any_To_Ok(uGrpIdx);
                        break;
                    }
                    else
                    {
                        //No Action
                    }
#endif
                }
#ifdef US_D_ENABLE_DEGRADED_STATE
                else if(eGrpNoise == US_E_NOISELEVEL_LOW)
                {
                    if ( (UssMgr_eGrpStateChangeStartTime[uGrpIdx] == US_D_GRP_STATECHANGESTARTTIME_INIT)
                        || (eGrpNoise != UssMgr_ePrevGrpNoiseLevel[uGrpIdx]) )
                    {
                        UssMgr_eGrpStateChangeStartTime[uGrpIdx] = uStateMachineNowTime;
                    }
                    /* doing ((now - start) > delay) because (now > (start + delay)) is not rollover proof */
                    if((uStateMachineNowTime - UssMgr_eGrpStateChangeStartTime[uGrpIdx]) > US_D_GRP_NOISY_TO_DEGRADED_DELAY)
                    {
                        UssMgr_GrpTrans_Any_To_Deg(uGrpIdx);
                        break;
                    }
                    else
                    {
                        //No Action
                    }
                }
#endif
                else
                {
                    //do nothing - we are staying in this state
                    UssMgr_eGrpStateChangeStartTime[uGrpIdx] = US_D_GRP_STATECHANGESTARTTIME_INIT;
                }
                //save noise level to see if it changes next time
                UssMgr_ePrevGrpNoiseLevel[uGrpIdx] = eGrpNoise;

                if ((UssMgr_eGrpNoiseMitType[uGrpIdx] != US_NOISEMIT_MAX) 
                    &&(eNoiseReaction == SYSMGR_NOISEREACT_DYN_CHIRP))
                {
                    UssMgr_SetNextNoiseMitMode(uGrpIdx, UssMgr_eGrpNoiseMitType[uGrpIdx]);
                }

                break;
            }
            
            case SYSMGR_GRPSTATE_DEGRADED:
            {
#ifdef US_D_ENABLE_DEGRADED_STATE
                //check if group can exit degraded
                //check noise
                eGrpNoise = UssMgr_SnrToGrp_CheckNoise(uGrpIdx);
                //go back to OK
                if(eGrpNoise == US_E_NOISELEVEL_NONE)
                {
                    if(UssMgr_eGrpStateChangeStartTime[uGrpIdx] == US_D_GRP_STATECHANGESTARTTIME_INIT)
                    {
                        UssMgr_eGrpStateChangeStartTime[uGrpIdx] = uStateMachineNowTime;
                    }
                    /* doing ((now - start) > delay) because (now > (start + delay)) is not rollover proof */
                    if((uStateMachineNowTime - UssMgr_eGrpStateChangeStartTime[uGrpIdx]) > US_D_GRP_DEGRADED_TO_OK_DELAY)
                    {
                        UssMgr_GrpTrans_Any_To_Ok(uGrpIdx);
                        break;
                    }
                    else
                    {
                        //No Action
                    }
                }
                else if(eGrpNoise == US_E_NOISELEVEL_HIGH)
                {
                    UssMgr_GrpTrans_Any_To_Noisy(uGrpIdx);
                    break;
                }
                else
                {
                    //do nothing
                    UssMgr_eGrpStateChangeStartTime[uGrpIdx] = US_D_GRP_STATECHANGESTARTTIME_INIT;
                }
#else
                UssMgr_GrpTrans_Any_To_Noisy(uGrpIdx);
#endif
                break;
            }
            
            case SYSMGR_GRPSTATE_FAULTED:
            {
                //check if group can exit faulted
                //check faults
                eGrpFaults = UssMgr_SnrToGrp_CheckFaults(uGrpIdx);
                if(eGrpFaults ==(uint8_t) US_D_GRP_NOT_FAULTED)
                {
#ifdef US_D_MGR_RECOVER_TO_PREV_STATE
                    switch(UssMgr_ePrevGrpState[uGrpIdx])
                    {
                        case SYSMGR_GRPSTATE_OK:
                            UssMgr_GrpTrans_Any_To_Ok(uGrpIdx);
                            break;
                        case SYSMGR_GRPSTATE_NOISY:
                            UssMgr_GrpTrans_Any_To_Noisy(uGrpIdx);
                            break;
    #ifdef US_D_ENABLE_DEGRADED_STATE
                        case SYSMGR_GRPSTATE_DEGRADED:
                            UssMgr_GrpTrans_Any_To_Deg(uGrpIdx);
                            break;
    #endif    
                        case SYSMGR_GRPSTATE_FAULTED:
                        case SYSMGR_GRPSTATE_OFF:
                        default:
                            //just go to off anyways
                            UssMgr_GrpTrans_Any_To_Off(uGrpIdx);
                            break;
                    }
#else
                    //go back to OFF
                    UssMgr_GrpTrans_Any_To_Off(uGrpIdx);
#endif
                    break;
                }
                else
                {
                    //no action
                }
                break;
            }
            
            default:
            {
                //should never be here
                UssMgr_GrpTrans_Any_To_Off(uGrpIdx);
               
                break;
            }
        }
    }
}


/*===========================================================================
 * \brief Set USS system initialization state.
 * \param Current system state (UssMgr_e_SysState_t)
 * \param none
 * \return
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_SetSysState
 * Remarks:  DD-ID: {BA2FA7DC-6007-41b9-AD59-57213CF5A5C6}
 * Req.-ID: 14959893
 * ===========================================================================*/
void UssMgr_SetSysState(UssMgr_e_SysState_t eState)
{
    UssMgr_eSysState = eState;
}


/*===========================================================================
 * \brief Get USS system initialization state.
 * \param none
 * \param none
 * \return Current system state (UssMgr_e_SysState_t)
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_eGetSysState
 * Remarks:  DD-ID: {DB0E212E-5CC9-4a51-B81A-9B7B94B6C002}
 * Req.-ID:14959893
 * Req.-ID:16134127
 * ===========================================================================*/
UssMgr_e_SysState_t UssMgr_eGetSysState(void)
{
    return UssMgr_eSysState;
}

/* ===========================================================================
 * Name:	 UssMgr_eGetGrpState
 * Remarks:  DD-ID: {2D9C34BA-14A8-4fb6-9E38-6C9500497399}
 * Req.-ID:14959893
 * Req.-ID:16134127
 * ===========================================================================*/

/* Group state get/set */
UssMgr_E_GroupState_t UssMgr_eGetGrpState(uint8_t GroupIdx)
{
    UssMgr_E_GroupState_t eRet_GrpIdx;
    
    if( GroupIdx < US_D_PHYS_GRP_MAX )
    {
        eRet_GrpIdx = UssMgr_eGrpState[GroupIdx];
    }
    else
    {
        eRet_GrpIdx = SYSMGR_GRPSTATE_OFF;
    }
    
    return eRet_GrpIdx; 
}

/* ===========================================================================
 * Name:	 UssMgr_SetGrpState
 * Remarks:  DD-ID: {81BE5315-9315-493f-8BAB-324FFDC72FB0}
 * ===========================================================================*/
void UssMgr_SetGrpState(uint8_t GroupIdx, UssMgr_E_GroupState_t NewState)
{
    (void) NewState; // Not presently used.
    (void)GroupIdx ;

}
/* ===========================================================================
 * Name:	 UssMgr_IsAnyGroupNoisy
 * Remarks:  DD-ID: {D7E0D58E-D9BE-4241-82BF-AB9C3232F884}
 * Req.-ID: 14992414
 * Req.-ID: 14992434
 * Req.-ID: 14992433
 * Req.-ID: 14992440
 * Req.-ID: 14992448
 * Req.-ID: 14992447
 * Req.-ID: 13475233
 * Req.-ID: 16132055
 * Req.-ID: 14992404
 * Req.-ID: 14992403
 * Req.-ID: 14992382
 * Req.-ID: 14992381
 * Req.-ID: 14992384
 * Req.-ID: 14992385
 * Req.-ID: 14992383
 * Req.-ID: 14992373
 * Req.-ID: 13420729
 * ===========================================================================*/

bool_t UssMgr_IsAnyGroupNoisy(void)
{
    uint8_t uGrpIdx;
    bool_t bRetVal = ME_FALSE;
    
    /* This area can be used for any complex logic for 
     * deciding if the system should behave differently 
     */
    for( uGrpIdx = 0; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++ )
    {
        if( SYSMGR_GRPSTATE_NOISY == UssMgr_eGrpState[uGrpIdx] )
        {
            bRetVal = ME_TRUE;
        }
    }
    
    return bRetVal;
}

/* ===========================================================================
 * Name:	 UssMgr_TriggerStartupTest
 * Remarks:  DD-ID: {15A2E845-7941-4e0b-80AF-701C56784D0C}
 * Req.-ID: 13396023
 * ===========================================================================*/
static void UssMgr_TriggerStartupTest(void)
{
    UssMgr_uStartupTestCounter = ZERO;
}

/** CUSTOMER API FUNCTIONS **/
/* ===========================================================================
 * Name:	 USS_SetSelfTestEnable
 * Remarks:  DD-ID: {D41583B5-3F9E-42a1-935F-439E22623A4F}
 * Req.-ID: 13396023
 * ===========================================================================*/

void USS_SetSelfTestEnable(uint32_t EnableOrDisable)
{
    //input is basically magna bool_t
 

    //instead of direct control, have api trigger test with timer
    if((bool_t)EnableOrDisable == ME_TRUE)
    {
        UssMgr_bSelfTestEnabled = ME_TRUE;
        UssMgr_TriggerStartupTest();
    }
}

/* ===========================================================================
 * Name:	 USS_SetBumperEnable
 * Remarks:  DD-ID: {21695358-4A6B-4108-AD53-8F67E83C9323}
 * ===========================================================================*/
void USS_SetBumperEnable(/*ME_US_E_BumperLocation_t*/ uint32_t SelectedBumper, uint32_t EnableOrDisable)
{
    uint8_t uGrpIdx = (uint8_t)SelectedBumper;
    
    if( uGrpIdx < US_D_PHYS_GRP_MAX )
    {
        //assign boolean
        UssMgr_bGrpForceDisabled[uGrpIdx] = (bool_t)EnableOrDisable;
    }
}
/* ===========================================================================
 * Name:	 USS_GetBumperEnable
 * Remarks:  DD-ID: {294F5A58-3642-425a-90FE-F3E6BEAA76EC}
 * Req.-ID: 13424090
 * ===========================================================================*/

static uint8_t  USS_GetBumperEnable(void)
{
	uint8_t count = 0;
	uint8_t status = ME_FALSE;

	for(count = 0;count < US_D_PHYS_GRP_MAX;count++)
	{
		if(UssMgr_bGrpForceDisabled[count] == 0x01u)
		{
			status = ME_TRUE;
		}
	}

    return status;
}

/* ===========================================================================
 * Name:	 UssMgr_GetNoiseReactionCfg
 * Remarks:  DD-ID: {4BEA45F9-1EB1-42b7-B3CF-7A95668420C9}
 * Req.-ID: 
 * ===========================================================================*/
UssMgr_E_NoiseReaction_t UssMgr_GetNoiseReactionCfg(void)
{
    return UssMgr_eNoiseReaction;
}


#if(US_CSM_ENABLE == ME_TRUE)
/* ===========================================================================
 * Name:	 Us_ObjDetMngr_ReqState_Csm
 * Remarks:  DD-ID: {DA3A6688-3EBB-4e50-997B-8DB0CB1915EA}
 * Req.-ID: 
 * ===========================================================================*/
 UsCsm_StdReturn_Type Us_ObjDetMngr_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState)
 {
	(void)instanceId;
    LocalStateId_ObjDet = reqState;
    return US_CSM_STD_RET_OK;
 }
/* ===========================================================================
 * Name:	 Us_ObjDetMngr_GetState_Csm
 * Remarks:  DD-ID: {88ACD0D0-7DDA-48ce-A466-AE3487DCCE07}
 * Req.-ID: 
 * ===========================================================================*/
 UsCsm_LocalStateId_Type Us_ObjDetMngr_GetState_Csm(UsCsm_InstanceId_Type instanceId)
 {
   (void)instanceId;
    return LocalStateId_ObjDet;
 }
#endif
