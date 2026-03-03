/*
 * US_MgrModeControl.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#include "US_ComInputBuffer_Global.h"
#include "US_ME_Typedefs_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_MgrInterface.h"
#include "US_Ctrl_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_MgrModeControl.h"
#include "US_Diagnostic_Global.h"

#define US_D_MGRMODE_NFD_CYCLE_RATE_DEFAULT (2u) //switch to NFD every 2nd cycle

#define US_D_MGRMODE_STARTING_FIRE_MODE     FIREMODE_OFF //same action as US_PARKMODE_STANDBY

//#define US_D_USE_STRICT_CHIRP_PATH
//#define US_D_LAUD_RUNTIME_CHIRP_PATH
#ifdef US_D_LAUD_RUNTIME_CHIRP_PATH
    uint8_t g_LAUD_enableStrictPath = 0x00;
#endif
/*** Internal Enums ***/
/* Enum order is the priority order!! do not rearrange accidently */
typedef enum
{
    SILENCE_REQ_OFF = ZERO,
    SILENCE_REQ_CAUTION,
    SILENCE_REQ_CHIRP,
    SILENCE_REQ_NORMAL,
    SILENCE_REQ_MAX
} US_E_SilenceRequest_t;


#if (US_D_CUR_PLATFORM != US_D_PLATFORM_RIVIAN)
static US_E_ParkingMode_t ePrevParkingMode = US_PARKMODE_STANDBY;
#endif
static US_E_NoiseMitigationMode_t eUsedNoiseMitMode[US_D_PHYS_GRP_MAX];
static US_E_NoiseMitigationMode_t eNextNoiseMitMode[US_D_PHYS_GRP_MAX];
static US_E_SilenceRequest_t eRequestedSilence[US_D_PHYS_GRP_MAX];
static US_E_SilenceRequest_t eSilenceDecision;
static US_E_SilenceRequest_t eOldSilenceDecision;
UssMgr_E_NoiseReaction_t eOldNoiseReactionCfg;
static US_E_FireMode_t       eGlobalFireMode;
static US_E_FireMode_t       ePrevGlobalFireMode;   
static UssMgr_E_NFDMode_t       ePrevNFDReq[US_D_PHYS_GRP_MAX];
static UssMgr_E_NFDMode_t       eGlobalNFDMode;
static bool_t                   bGlobalNFDLockout;
static bool_t                   bExtNFDEnable;
static const US_S_BurstConfig_t *UsedBurstCfg[US_D_PHYS_GRP_MAX];
static US_E_ProfileType_t       UsedProfile[US_D_PHYS_GRP_MAX];
static US_E_SendType_t          UsedMeasType[US_D_PHYS_GRP_MAX];
#if (USSMGR_MODE_HSM_GEAR_BASED == ME_TRUE)
static US_E_App_Prndl_Status_e  ePrevGearStatus;
#endif
#ifdef USSMGR_MODE_HACKED_SCAN_MODES
uint8_t eSpecialMode2_SubMode = USSMGR_MODE_HSM_MODE_UNKNOWN;
#endif
US_E_NoiseCheckType_t eNoiseCheckType = NOISE_CHECK_NONE;
#ifdef USSMGR_MODE_NFD_SPEED_LIMIT_ENABLE
bool_t                          bNFDSpeedLimitOn;
#endif

#ifdef US_D_MGRMODE_DEBUG_LOGGING
    #define US_D_MGRMODE_DEBUG_LOGGING_SIZE (50u)
static uint16_t uaCycleCountHistory[US_D_MGRMODE_DEBUG_LOGGING_SIZE];
static uint16_t uaCycleCountTimestamp[US_D_MGRMODE_DEBUG_LOGGING_SIZE];
static uint8_t  uMgrModeLogIndex = ZERO;
#endif
uint16_t uUssDBG_ModeInitCnt = 0u;

/* Local functions */
void ProcessNoiseModeControl(void);
static US_E_SilenceRequest_t   FindSilenceDecision(void);
static void                    UpdateNFDMode(void);
static void                    SetFixedBurstMode(uint8_t uGrpIdx);
static void                    SetNFDBurstMode(uint8_t uGrpIdx);
static void                    UpdateFireSeq(US_E_FireMode_t Fire_Mode_Req);
static void                    InternalInitRuntime(void);
static void                    InternalInitBoot(void);
static UssMgr_E_NFDMode_t      UssMgr_GetGlobalNFDMode(void);
static US_E_FireMode_t UssMgrEXT_DetermineGlobalFireMode(void); /*temp - to be replaced with "Firing Plan" system*/

/* ===========================================================================
 * Name: US_MgrSetup_PrevParkingMode    
 * Remarks:  DD-ID: {851CB029-6253-414c-B277-8F90CB9B93D9} 
 * ===========================================================================*/

void US_MgrSetup_PrevParkingMode(US_E_ParkingMode_t mode)
{
	ePrevParkingMode = mode;
}


/* silence decision is based on gathering data from all grp requests */
/* ===========================================================================
 * Name:	 FindSilenceDecision
 * Remarks:  DD-ID: {6355593A-9FDF-4df8-9562-09277364F609}
 * Req.-ID: 14214786
 * Req.-ID: 14214192
 * Req.-ID: 17350940
 * Req.-ID: 15001879
 * ===========================================================================*/
static US_E_SilenceRequest_t FindSilenceDecision(void)
{
    uint8_t uGrpIdx;
    US_E_SilenceRequest_t eNewSilenceDecision = SILENCE_REQ_MAX;

    for( uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++ )
    {
        //priority comes from enum order!
        if( (uint8_t)eNewSilenceDecision > (uint8_t)eRequestedSilence[uGrpIdx] )
        {
            eNewSilenceDecision = eRequestedSilence[uGrpIdx];
        }
    }

    return eNewSilenceDecision;
}

/* ===========================================================================
 * Name:	 UpdateNFDMode
 * Remarks:  DD-ID: {D840F62F-8E29-4d0c-9895-9D22FB58BE5E}
 * Req.-ID: 14210760
 * Req.-ID: 14214786
 * Req.-ID: 14214192
 * Req.-ID: 17350940
 * Req.-ID: 15001879
 * ===========================================================================*/

/* Find out if we need to insert an NFD burst during this coming cycle */
static void UpdateNFDMode(void)
{
    uint8_t uFireSeqCycle;
    //uint8_t uFireSeqStepLen;
    //uint8_t uCyclesToBeNFD;
#ifdef USSMGR_MODE_NFD_SPEED_LIMIT_ENABLE
    float32_t fVehSpeed1kph;
#endif

    /* Temp override for scanning mode && override for ext option*/
    if(    (FIREMODE_SIDES_ONLY == eGlobalFireMode)
#ifdef USSMGR_MODE_HACKED_SCAN_MODES
        || (FIREMODE_SPECIAL_2 == eGlobalFireMode )
#endif
        || (ME_FALSE == bExtNFDEnable) )
    {
        eGlobalNFDMode = NFD_MODE_OFF;
        return;
    }

#ifdef USSMGR_MODE_NFD_SPEED_LIMIT_ENABLE
    fVehSpeed1kph = UssMgr_GetVehSpeed();
    if( bNFDSpeedLimitOn == (bool_t)ME_TRUE )
    {
        /* currently NFD is off due to high speed, check entering speed */
        if( fVehSpeed1kph <= USSMGR_MODE_NSL_SPEED_ENTER)
        {
            bNFDSpeedLimitOn = ME_FALSE;
            /* pass thru to normal NFD logic */
        }
        else
        {
            /* still in high speed, keep NFD off */
            eGlobalNFDMode = NFD_MODE_OFF;
            return;
        }
    }
    else
    {
        /* currently NFD is on due to low speed, check exit speed */
        if( fVehSpeed1kph >= USSMGR_MODE_NSL_SPEED_EXIT)
        {
            bNFDSpeedLimitOn = ME_TRUE;
            eGlobalNFDMode = NFD_MODE_OFF;
            return;
        }
        /* else pass thru to normal NFD logic */
    }
#endif /* USSMGR_MODE_NFD_SPEED_LIMIT_ENABLE */

    //get the cycle, NOT the step
    uFireSeqCycle = UssCtrl_uGetFireSequenceCurCycle(ZERO); 
    //only using first firing seq (ZERO) - need logic if using multiple

    //TODO - this whole logic needs to be more dynamic and based on fire seq instead of hardcoded.
    


    switch (eGlobalNFDMode)
    {
        case NFD_MODE_OFF:
        {
            if( (bGlobalNFDLockout == (bool_t)ME_FALSE) &&
                (uFireSeqCycle >= (FOUR * US_D_MGRMODE_NFD_CYCLE_RATE_DEFAULT)) )//seq hit 2 bumper cycles (4 + 4)
            {
                eGlobalNFDMode = NFD_MODE_ON;
            }
            break;
        }
        
        case NFD_MODE_ON:
        {
            if( uFireSeqCycle >= TWO )
            {
                eGlobalNFDMode = NFD_MODE_OFF;
            }
            break;
        }
    
        case NFD_MODE_UNKNOWN:
        default:
        {
            eGlobalNFDMode = NFD_MODE_OFF;
            break;
        }
    }
#ifdef USSMGR_GLOBAL_NFD_DISABLE
    eGlobalNFDMode = NFD_MODE_OFF;  // jpp - How to force NFD to be off.
#endif

#ifdef US_D_MGRMODE_DEBUG_LOGGING
    uaCycleCountHistory[uMgrModeLogIndex] = uFireSeqCycle;
    uaCycleCountTimestamp[uMgrModeLogIndex] = US_GetTimeStampTimeMs();
    uMgrModeLogIndex++;
    if(uMgrModeLogIndex >= US_D_MGRMODE_DEBUG_LOGGING_SIZE) { uMgrModeLogIndex = ZERO; }
#endif
}

/* ===========================================================================
 * Name:	 UpdateFireSeq
 * Remarks:  DD-ID: {AFBC8559-3FC7-4c3a-AFF2-7D2954355AB5}
 * Req.-ID: 13424090
 * ===========================================================================*/
static void UpdateFireSeq(US_E_FireMode_t Fire_Mode_Req)
{
    UssMgr_E_NFDMode_t  eNFDMode = UssMgr_GetGlobalNFDMode();
    
    switch (Fire_Mode_Req)
    {
        case FIREMODE_OFF:
        {
            eSpecialMode2_SubMode = USSMGR_MODE_HSM_MODE_UNKNOWN;
            UssCtrl_StopFireSeq();
            (void)UssCtrl_CheckForSnrCalChange();
            break;
        }
        
        case FIREMODE_PSM_ONLY:
        case FIREMODE_SIDES_ONLY:
        {
            //no NFD in this mode - ignore global setting
            UssCtrl_SetFireSequence(US_SnrLocs_AllSidesOnly_SameTime,
                                    US_FIRE_PAT_ROUND_ROBIN,
                                    US_FIRE_PAT_START_AT_ZERO,
                                    US_SNRLOCS_ONE_STEP_SEQ_LEN,
                                    100u);
            UssCtrl_StartFireSeq();
            break;
        }

        case FIREMODE_SPECIAL_2:
        {
#ifdef USSMGR_MODE_HACKED_SCAN_MODES
            if( eSpecialMode2_SubMode == USSMGR_MODE_HSM_MODE_MIXMODE )
            {
    #if (USSMGR_MODE_HSM_GEAR_BASED == ME_TRUE)
                US_E_App_Prndl_Status_e eGearStatus = UssCom_F_GetVehPrndl();
                if ( US_PRNDL_REVERSE == eGearStatus )
                {
                    UssCtrl_SetFireSequence(US_SnrLocs_FastScan_SameTime_FrontSide_RearAll,
                                            US_FIRE_PAT_SHUFFLE,
                                            US_FIRE_PAT_START_AT_ZERO,
                                            US_SNRLOCS_FOUR_STEP_SEQ_LEN,
                                            (US_SNRLOCS_FOUR_STEP_SEQ_LEN * FOUR));
                    UssCtrl_StartFireSeq();

                }
                else /* all other gears.. drive/park/neutral */
    #endif
                {
                    UssCtrl_SetFireSequence(US_SnrLocs_FastScan_SameTime_FrontAll_RearSide,
                                            US_FIRE_PAT_SHUFFLE,
                                            US_FIRE_PAT_START_AT_ZERO,
                                            US_SNRLOCS_FOUR_STEP_SEQ_LEN,
                                            (US_SNRLOCS_FOUR_STEP_SEQ_LEN * FOUR));
                    UssCtrl_StartFireSeq();
                }
            }
            else if ( eSpecialMode2_SubMode == USSMGR_MODE_HSM_MODE_SIDEONLY )
            {
                UssCtrl_SetFireSequence(US_SnrLocs_AllSidesOnly_SameTime,
                                        US_FIRE_PAT_ROUND_ROBIN,
                                        US_FIRE_PAT_START_AT_ZERO,
                                        US_SNRLOCS_ONE_STEP_SEQ_LEN,
                                        100u);
                UssCtrl_StartFireSeq();
            }
            else
            {
                /* not in an approved submode! throw some error */
            }
#endif
            break;
        }
        
        case FIREMODE_NORMAL: //"Parking"
        case FIREMODE_SPECIAL:
        case FIREMODE_DEFAULT:
        default:
        {
            if (eNFDMode == NFD_MODE_OFF) //we could have been in NFD before, change fire seq
            {
                UssCtrl_SetFireSequence(US_SnrLocs_FastScan_SameTime,
                                        US_FIRE_PAT_SHUFFLE,
                                        US_FIRE_PAT_START_AT_ZERO,
                                        US_SNRLOCS_FOUR_STEP_SEQ_LEN,
                                        (US_SNRLOCS_FOUR_STEP_SEQ_LEN * FOUR));
                UssCtrl_StartFireSeq();
            }
            else if( eNFDMode == NFD_MODE_ON)
            {
                UssCtrl_SetFireSequence(US_SnrLocs_NFDScan_SameTime,
                                        US_FIRE_PAT_ROUND_ROBIN,
                                        US_FIRE_PAT_START_AT_ZERO,
                                        US_SNRLOCS_TWO_STEP_SEQ_LEN,
                                        (US_SNRLOCS_TWO_STEP_SEQ_LEN * TWO));
                UssCtrl_StartFireSeq();
            }
            else
            {
                //nothing
            }
            break;
        }
    }
}

/*************************************/
/* functions for firing mode calls */
/* ===========================================================================
 * Name:	 SetFixedBurstMode
 * Remarks:  DD-ID: {CA9FACCE-9337-4407-9F20-2FEB49FBF669}
 *Req.-ID: 14214786
 * Req.-ID: 14214192
 * Req.-ID: 17350940
 * Req.-ID: 15001879
 * ===========================================================================*/
static void SetFixedBurstMode(uint8_t uGrpIdx)
{
    /* clear any previous silence conditions */
    UssSnrCmd_ClrGrpForSilence(uGrpIdx);
    
    /* set fire seq modifiers */
    eRequestedSilence[uGrpIdx] = SILENCE_REQ_NORMAL;
    //comment out  UssCtrl_SetFireSeqDelayMs(0u);   // 0 ms delay before next measurement
    //comment out  UssCtrl_SetListenOnlyFreq(3u, 1u);
    //comment out  UssCtrl_SetRandSilenceMaxMs(0u); // 10 ms max.  Delay times will be one of: 0,2,4,6,8,10 ms

    /* set the sensor burst cfg (filter path, nBRC, etc) */;
    UsedBurstCfg[uGrpIdx] = &US_BrstCfg_Front_Rear_Fixed;
    UssSnrCmd_SetBurstConfigByGroupID(uGrpIdx, UsedBurstCfg[uGrpIdx]);

    /* set the sensor tuning profile (A,B,C - all calibration values) */
    UsedProfile[uGrpIdx] = US_E_PROFILE_A;
    UssSnrCmd_SetRcvProfilesByGroupID(uGrpIdx, UsedProfile[uGrpIdx]);

    /* set the burst send type (Fixed, Chirp, etc ) */
    UsedMeasType[uGrpIdx] = US_E_REQ_SEND_NORMAL;
    UssSnrCmd_SetMeasEchoTypeByGroupIdx(uGrpIdx, UsedMeasType[uGrpIdx]);

    //comment out  UssCtrl_StartFireSeq();
}

/* ===========================================================================
 * Name:	 SetNFDBurstMode
 * Remarks:  DD-ID: {810DBB99-3C1F-44fa-B4B0-AA50553D6B57}
 * Req.-ID: 13424090
 * ===========================================================================*/
static void SetNFDBurstMode(uint8_t uGrpIdx)
{
    /* clear any previous silence conditions */
    UssSnrCmd_ClrGrpForSilence(uGrpIdx);
    
    /* set fire seq modifiers */
    eRequestedSilence[uGrpIdx] = SILENCE_REQ_NORMAL;

    /* set the sensor burst cfg (filter path, nBRC, etc) */;
    UsedBurstCfg[uGrpIdx] = &US_BrstCfg_NFD;
    UssSnrCmd_SetBurstConfigByGroupID(uGrpIdx, UsedBurstCfg[uGrpIdx]);

    /* set the sensor tuning profile (A,B,C - all calibration values) */
    UsedProfile[uGrpIdx] = US_E_PROFILE_B;
    UssSnrCmd_SetRcvProfilesByGroupID(uGrpIdx, UsedProfile[uGrpIdx]);

    /* set the burst send type (Fixed, Chirp, etc ) */
    UsedMeasType[uGrpIdx] = US_E_REQ_SEND_NFD;
    UssSnrCmd_SetMeasEchoTypeByGroupIdx(uGrpIdx, UsedMeasType[uGrpIdx]);

    //comment out  UssCtrl_StartFireSeq();
}
/* ===========================================================================
 * Name: InternalInitRuntime    
 * Remarks:  DD-ID: {50CF511E-8250-46f1-9A0C-1BB70F43F050}
 * ===========================================================================*/
static void InternalInitRuntime(void)
{
    uint8_t uGrpIdx;
    
    for( uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++ )
    {
        //important!! set to unused value so startup will update it
        eUsedNoiseMitMode[uGrpIdx] = US_NOISEMIT_MAX;
        //avoid starting at high prio state
        eRequestedSilence[uGrpIdx] = SILENCE_REQ_NORMAL;
        //not important
        ePrevNFDReq[uGrpIdx] = NFD_MODE_OFF;
    }
    eGlobalFireMode = US_D_MGRMODE_STARTING_FIRE_MODE;
#if (US_D_CUR_PLATFORM != US_D_PLATFORM_RIVIAN)
    ePrevParkingMode = US_PARKMODE_MAX; /* must update if eGlobalFireMode is cleared */
#endif
    eSilenceDecision = SILENCE_REQ_MAX;
    eOldSilenceDecision = SILENCE_REQ_MAX; //VERY IMPORTANT TO BE MAX/unused value!!
    eGlobalNFDMode = NFD_MODE_UNKNOWN;
    bGlobalNFDLockout = ME_FALSE;
#if (USSMGR_MODE_HSM_GEAR_BASED == ME_TRUE)
    ePrevGearStatus = US_PRNDL_UNKNOWN;
#endif
#ifdef USSMGR_MODE_NFD_SPEED_LIMIT_ENABLE
    bNFDSpeedLimitOn = ME_FALSE;
#endif
}
/* ===========================================================================
 * Name: InternalInitBoot    
 * Remarks:  DD-ID: {99F57C02-F8C4-40a1-8525-2770B8D28EDA}
 * ===========================================================================*/
static void InternalInitBoot(void)
{
    uint8_t uGrpIdx;
    
    for( uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++ )
    {
        /* Set by MgrMain, don't clear during runtime */
        eNextNoiseMitMode[uGrpIdx] = US_NOISEMIT_NONE;
        /* Needed for possible recovery */
        UsedBurstCfg[uGrpIdx] = NULL;
        UsedProfile[uGrpIdx] = US_E_PROFILE_A;
        UsedMeasType[uGrpIdx] = US_E_REQ_SEND_NORMAL;
    }
    /* Set by external source, don't clear */
    bExtNFDEnable = ME_TRUE;

}



/*** Public Functions ***/

/* Module init function */
/* ===========================================================================
 * Name:	 UssMgr_ModeControlInit
 * Remarks:  DD-ID: {3739C00C-B864-4d1f-A11C-7BAF614B1664}
 *  Req.-ID: 13396023
 * ===========================================================================*/
void UssMgr_ModeControlInit(void)
{
    InternalInitBoot();
    InternalInitRuntime();
}
/* ===========================================================================
 * Name: UssMgr_MgrModePublicInit    
 * Remarks:  DD-ID: {B96DD715-9816-42c4-ABDA-0A93F738D988}
 * ===========================================================================*/
void UssMgr_MgrModePublicInit(void)
{
    InternalInitRuntime();
}

/*===========================================================================
 * \brief Simple mode control to select fire sequence from CAN input.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_ProcessModeControl
 * Remarks:  DD-ID: {60288E01-1D40-4423-A70A-46B1B6EA093E}
 * Traceability to source Code:
 * Req.-ID: 14210760
 * Req.-ID: 14214786
 * Req.-ID: 14214192
 * Req.-ID: 15001879
 * ===========================================================================*/
void UssMgr_ProcessModeControl(void)
{
    uint8_t                     uGrpIdx;
    US_E_NoiseMitigationMode_t  eNoiseMitMode;
    bool_t                      bAtLeastOneModeChange = ME_FALSE;
    bool_t                      bFireSeqNeedsChange = ME_FALSE;
    bool_t                      bAtLeastOneMitigation = ME_FALSE;
    UssMgr_E_NFDMode_t          eNFDMode;
    UssMgr_E_NoiseReaction_t    eNoiseReactionCfg;
#if (USSMGR_MODE_HSM_GEAR_BASED == ME_TRUE)
    US_E_App_Prndl_Status_e     eGearStatus;
#endif
#if (USSMGR_MODE_HSM_SPEED_BASED == ME_TRUE)
    float32_t                   fVehSpeed1kph;
#endif
    //US_E_FireMode_t             eGlobalFireMode;
    
    US_E_OPERATION_MODE_t eOpMode = (US_E_OPERATION_MODE_t)US_SnrCfg_Get_OperationMode();
    eGlobalFireMode = UssMgrEXT_DetermineGlobalFireMode(); /* \TODO - this should become an external interface - temporary */

    if( (eOpMode != US_SNR_TEST_MODE) && //added because I didn't see how SNR_TEST fire seq doesn't get override here
        (eGlobalFireMode != FIREMODE_OFF) ) //\TODO replace this with Sys Mode when available
    {
        UpdateNFDMode(); //run once per mode/seq update.
        eNFDMode = eGlobalNFDMode;

        /* figure out mode PER bumper/group */
        for( uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++ )
        {
            /*** Noise Mitigation Mode action ***/
            eNoiseMitMode = eNextNoiseMitMode[uGrpIdx];

            if (eNoiseMitMode != eUsedNoiseMitMode[uGrpIdx])
            {
                bAtLeastOneModeChange = ME_TRUE;
            
                switch(eNoiseMitMode)
                {
                    case US_NOISEMIT_NONE:
                    {
                        SetFixedBurstMode(uGrpIdx);
                        break;
                    }
                    
                    case US_NOISEMIT_FILTER1:
                    {
                        UssSnrCmd_ClrGrpForSilence(uGrpIdx);
                        
                        eRequestedSilence[uGrpIdx] = SILENCE_REQ_CHIRP;
#ifndef US_D_LAUD_RUNTIME_CHIRP_PATH
    #ifdef US_D_USE_STRICT_CHIRP_PATH
                        UsedBurstCfg[uGrpIdx] = &US_BrstCfg_Chirp_Down_Strict;
    #else
                        UsedBurstCfg[uGrpIdx] = &US_BrstCfg_Chirp_Down;
    #endif
#else
                        if(g_LAUD_enableStrictPath == 0x00)
                        {
                            UsedBurstCfg[uGrpIdx] = &US_BrstCfg_Chirp_Down;
                        }
                        else
                        {
                            UsedBurstCfg[uGrpIdx] = &US_BrstCfg_Chirp_Down_Strict;
                        }
#endif
                        UssSnrCmd_SetBurstConfigByGroupID(uGrpIdx, UsedBurstCfg[uGrpIdx]);
                        UsedProfile[uGrpIdx] = US_E_PROFILE_C;
                        UssSnrCmd_SetRcvProfilesByGroupID(uGrpIdx, UsedProfile[uGrpIdx]);
                        UsedMeasType[uGrpIdx] = US_E_REQ_SEND_CHIRP_DOWN;
                        UssSnrCmd_SetMeasEchoTypeByGroupIdx(uGrpIdx, UsedMeasType[uGrpIdx]);
                        
                        //comment out  UssCtrl_StartFireSeq();
                        
                        bAtLeastOneMitigation = ME_TRUE;
                        break;
                    }
                    
                    case US_NOISEMIT_FILTER2:
                    {
                        UssSnrCmd_ClrGrpForSilence(uGrpIdx);
                        
                        eRequestedSilence[uGrpIdx] = SILENCE_REQ_CHIRP;
#ifndef US_D_LAUD_RUNTIME_CHIRP_PATH
    #ifdef US_D_USE_STRICT_CHIRP_PATH
                        UsedBurstCfg[uGrpIdx] = &US_BrstCfg_Chirp_Up_Strict;
    #else
                        UsedBurstCfg[uGrpIdx] = &US_BrstCfg_Chirp_Up;
    #endif
#else
                        if(g_LAUD_enableStrictPath == 0x00)
                        {
                            UsedBurstCfg[uGrpIdx] = &US_BrstCfg_Chirp_Up;
                        }
                        else
                        {
                            UsedBurstCfg[uGrpIdx] = &US_BrstCfg_Chirp_Up_Strict;
                        }
#endif
                        UssSnrCmd_SetBurstConfigByGroupID(uGrpIdx, UsedBurstCfg[uGrpIdx]);
                        UsedProfile[uGrpIdx] = US_E_PROFILE_C;
                        UssSnrCmd_SetRcvProfilesByGroupID(uGrpIdx, UsedProfile[uGrpIdx]);
                        UsedMeasType[uGrpIdx] = US_E_REQ_SEND_CHIRP_UP;
                        UssSnrCmd_SetMeasEchoTypeByGroupIdx(uGrpIdx, UsedMeasType[uGrpIdx]);
                        
                        //comment out  UssCtrl_StartFireSeq();
                        
                        bAtLeastOneMitigation = ME_TRUE;
                        break;
                    }
                    
                    case US_NOISEMIT_CAUTION:
                    {
                        UssSnrCmd_ClrGrpForSilence(uGrpIdx);
                        
                        eRequestedSilence[uGrpIdx] = SILENCE_REQ_CAUTION;
                        break;
                    }
                    
                    case US_NOISEMIT_LISTEN_ONLY:
                    {
                        /* No need to update these items */
                        /*
comment out                          UssCtrl_SetFireSeqDelayMs(0u);    0 ms delay before next measurement 
comment out                          UssCtrl_SetRandSilenceMaxMs(0u);  10 ms max.  Delay times will be one of: 0,2,4,6,8,10 ms
  comment out                        UssSnrCmd_SetBurstConfig(&US_BrstCfg_Front_Rear_Fixed); profile type
 comment out                         UssCtrl_SetListenOnlyFreq(1u, 0u);    Zero = Disabled.
                        
comment out                          UssCtrl_StartFireSeq();
                        */
                        UssSnrCmd_SetGrpForSilence(uGrpIdx);
                        UssSnrCmd_SetGrpSilenceRate(US_D_CMD_ALWAYS_LISTENING);
                        break;
                    }
                    
                    default:
                    {
                        /*do nothing*/
                        /*comment out  ASSERT(ME_TRUE);*/
                        break;
                    }
                }
                /* update previous */
                eUsedNoiseMitMode[uGrpIdx] = eNoiseMitMode;
                /* clearly not in NFD because we changed noise modes - update history */
                ePrevNFDReq[uGrpIdx] = NFD_MODE_OFF;
                eGlobalNFDMode = NFD_MODE_OFF;
                bFireSeqNeedsChange = ME_TRUE;
            } /* if request change */
            else
            {
                /* Every cycle, need to check if it's time to switch to NFD */
                if ( eNoiseMitMode == US_NOISEMIT_NONE ) //only care in normal mode - ignore in chirp
                {
                    if (eNFDMode != ePrevNFDReq[uGrpIdx])  //no need to update if no change needed
                    {
                        if (eNFDMode == NFD_MODE_ON)
                        {
                            SetNFDBurstMode(uGrpIdx);
                            //comment out  SetNFDFireSeq();
                        }
                        else
                        {
                            SetFixedBurstMode(uGrpIdx);
                            //comment out  SetNormalFireSeq();
                        }
                        bFireSeqNeedsChange = ME_TRUE;
                    }
                    ePrevNFDReq[uGrpIdx] = eNFDMode;
                    bGlobalNFDLockout = ME_FALSE;
                }
                else if ( eNoiseMitMode == US_NOISEMIT_LISTEN_ONLY )
                {
                    //It's noise mitigation - but not really. Listen only is used for just shutting off bumper
                    //do nothing for NFD and other flags
                    //\TODO - move listen only / "group quiet" mode OUT of noise mitigation and into it's own state.
                }
                else
                {
                    /* there is some noise mitigation happening */
                    //quick lockout of NFD mode - \todo: update to true state machine
                    eGlobalNFDMode = NFD_MODE_OFF;
                    bAtLeastOneMitigation = ME_TRUE;
                }
            } /* if/else on mit mode change */

            /* Action for special FAPA firing modes */
#if (USSMGR_MODE_HSM_GEAR_BASED == ME_TRUE)
            eGearStatus = UssCom_F_GetVehPrndl();
            if (eGearStatus != ePrevGearStatus)
            {
                bFireSeqNeedsChange = ME_TRUE;
            }
            ePrevGearStatus = eGearStatus;
#endif
#if (USSMGR_MODE_HSM_SPEED_BASED == ME_TRUE)
            fVehSpeed1kph = UssMgr_GetVehSpeed();
            if ((fVehSpeed1kph >= USSMGR_MODE_HSM_SPD_UP_LIMIT) && (eSpecialMode2_SubMode != USSMGR_MODE_HSM_MODE_SIDEONLY))
            {
                /* Above park assist speed, use only side sensors while staying in "special mode 2" */
                eSpecialMode2_SubMode = USSMGR_MODE_HSM_MODE_SIDEONLY;
                bFireSeqNeedsChange = ME_TRUE;
            }
            else if ((fVehSpeed1kph <= USSMGR_MODE_HSM_SPD_DN_LIMIT) && (eSpecialMode2_SubMode != USSMGR_MODE_HSM_MODE_MIXMODE))
            {
                /* Below park assist speed, use mixed mode based on gear (if optioned) */
                eSpecialMode2_SubMode = USSMGR_MODE_HSM_MODE_MIXMODE;
                bFireSeqNeedsChange = ME_TRUE;
            }
            else
            {
                  //DO Nothing
            }
#endif
        } /* for loop of groups*/

        /* Update fire sequence modifiers that are global */
        eNoiseReactionCfg = UssMgr_GetNoiseReactionCfg();
        if( (bAtLeastOneModeChange == ME_TRUE) || (eNoiseReactionCfg != eOldNoiseReactionCfg) )/* just to save excessive calls */
        {
            eSilenceDecision = FindSilenceDecision();
            /* If this section is called often, resets listen only and it doesn't work - only call when needed */
            if( (eSilenceDecision != eOldSilenceDecision) || (eNoiseReactionCfg != eOldNoiseReactionCfg) )
            {
                switch(eSilenceDecision)
                {
                    case SILENCE_REQ_OFF:
                    {
                        UssCtrl_SetFireSeqDelayMs(0u);   // 0 ms delay before next measurement
                        UssCtrl_SetListenOnlyFreq(0u, 0u); //zero is disabled
                        UssCtrl_SetRandSilenceMaxMs(0u); // 10 ms max.  Delay times will be one of: 0,2,4,6,8,10 ms
                        break;
                    }
                    case SILENCE_REQ_CAUTION:
                    {
                        UssCtrl_SetFireSeqDelayMs(0u);   // 0 ms delay before next measurement
                        UssCtrl_SetListenOnlyFreq(2u, 2u); //zero is disabled
                        UssCtrl_SetRandSilenceMaxMs(6u); // 10 ms max.  Delay times will be one of: 0,2,4,6,8,10 ms
                        break;
                    }
                    case SILENCE_REQ_CHIRP:
                    {
                        UssCtrl_SetFireSeqDelayMs(0u);   // 0 ms delay before next measurement
                        if (SYSMGR_NOISEREACT_DYN_CHIRP == eNoiseReactionCfg)
                        {
                            UssCtrl_SetListenOnlyFreq(6u, 2u); //zero is disabled
                        }
                        else
                        {
                            UssCtrl_SetListenOnlyFreq(13u, 2u); //zero is disabled
                        }
                        UssCtrl_SetRandSilenceMaxMs(6u); // 10 ms max.  Delay times will be one of: 0,2,4,6,8,10 ms
                        break;
                    }
                    case SILENCE_REQ_NORMAL:
                    default:
                    {
                        UssCtrl_SetFireSeqDelayMs(0u);   // 0 ms delay before next measurement
                        UssCtrl_SetListenOnlyFreq(6u, 1u); //zero is disabled
                        UssCtrl_SetRandSilenceMaxMs(0u); // 10 ms max.  Delay times will be one of: 0,2,4,6,8,10 ms
                        break;
                    }
                }
                eOldSilenceDecision = eSilenceDecision;
            }
            eOldNoiseReactionCfg = eNoiseReactionCfg;
        }
        
        /* if any noise mitigation is active - don't allow NFD */
        if (bAtLeastOneMitigation == (bool_t)ME_TRUE)
        {
            bGlobalNFDLockout = ME_TRUE;
        }
        else
        {
            bGlobalNFDLockout = ME_FALSE;
        }
        
        /* If something above requires a global fire seq change, resolve here */
        if ((bFireSeqNeedsChange ==(bool_t) ME_TRUE) || (ePrevGlobalFireMode != eGlobalFireMode))
        {
             (void)UpdateFireSeq(eGlobalFireMode);
        }
    }
    else
    {   
        //Add items here if US_SNR_TEST_MODE need to take special actions
        (void)UpdateFireSeq(eGlobalFireMode); /*mostly for global OFF*/
    }

    ePrevGlobalFireMode = eGlobalFireMode;
}

/*===========================================================================
 * \brief Return current parking mode.
 *
 * \param none
 * \param none
 * \return US_E_ParkingMode_t Current parking mode.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssMgr_uGetCurParkingMode
 * Remarks:  DD-ID: {EB87F0B9-A3D6-4cea-A8F4-EA17F858D4A7}
 * Req.-ID: 13424090
 * ===========================================================================*/
US_E_ParkingMode_t UssMgr_uGetCurParkingMode(void)
{
#if(US_D_CUR_PLATFORM != US_D_PLATFORM_RIVIAN)
    return ePrevParkingMode; // Previous parking mode is actually current, once it has been executed.
#else
    return ZERO;
#endif
}

/* \TODO - Parking mode as a concept is Fisker only - move out of Mgr */
/* ===========================================================================
 * Name:	 UssMgrEXT_DetermineGlobalFireMode
 * Remarks:  DD-ID: {E1580927-CAAA-4c88-B376-497C13E83528}
 * Req.-ID: 13424090
 * ===========================================================================*/
static US_E_FireMode_t UssMgrEXT_DetermineGlobalFireMode(void)
{
    uint8_t uSnrIdx;
	US_E_FireMode_t eRetFireMode = FIREMODE_DEFAULT;
    US_E_ParkingMode_t eParkingMode;
     
#if(US_D_CUR_PLATFORM != US_D_PLATFORM_RIVIAN)
    //get current parking mode
    if ((UssCtrl_bIsSysInPlaybackMode() == (bool_t)ME_FALSE) || (UssSnrCmd_uGetLoggingProtocolVer() == ZERO)) /* Playback mode */
    {
        eParkingMode = (US_E_ParkingMode_t)UssCom_F_GetParkingMode();
    }
    else
    {
        eParkingMode = UssSnrCmd_eGetLoggedParkingMode();
    }

    //translate to appropriate firing mode
    if (eParkingMode != ePrevParkingMode) //do we care? no big action only logic assignment here
    {
        switch(eParkingMode)
        {
            case US_PARKMODE_STANDBY:
            case US_PARKMODE_MAX:
            {
                eRetFireMode = FIREMODE_OFF;
			  // comment out   UssCtrl_CheckForSnrCalChange();
                break;
            }

            case US_PARKMODE_PARKING:
            {
                eRetFireMode = FIREMODE_DEFAULT;
                break;
            }

            case US_PARKMODE_SCANNING:
            {
                /* hacked away eRetFireMode = FIREMODE_SIDES_ONLY; */
                eRetFireMode = FIREMODE_SPECIAL_2;
                break;
            }
            case US_PARKMODE_TEST:
            {
                eRetFireMode = FIREMODE_SPECIAL;
                break;
            }
            default:
            {
                eRetFireMode = FIREMODE_OFF;
                break;
            }
        }
        ePrevParkingMode = eParkingMode;
	    UssMgr_SetClearTestDataReq();
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
        US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_TRANSDUCER_ERR, 0xFFFFu);
        US_Diagnostic_ClrSnrFaultFlag(SNR_DIAG_FLG_BAD_RING_TIME,  0xFFFFu);
#else
       for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
       {
               US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_BAD_RING_TIME, uSnrIdx);  // Clear resolved unknowns.
               US_Diagnostic_ClrSnrFaultFlagByIdx(SNR_DIAG_FLG_TRANSDUCER_ERR, uSnrIdx); // Clear resolved disconnects.
       }
#endif

    }
    else
    {
        eRetFireMode = eGlobalFireMode;
    }
#else
    eRetFireMode = FIREMODE_DEFAULT;
#endif
    return eRetFireMode;
}

/* ===========================================================================
 * Name:	 UssMgr_SetNextNoiseMitMode
 * Remarks:  DD-ID: {9BB4C12C-6A42-4f6f-8AD4-B8693C753150}
 * Req.-ID: 13424090
 * ===========================================================================*/
/* Set/Get functions for noise mitigation firing modes */
void UssMgr_SetNextNoiseMitMode(uint8_t Group_Index, US_E_NoiseMitigationMode_t Requested_Mode)
{
    if((Requested_Mode < US_NOISEMIT_MAX) && (Group_Index < US_D_PHYS_GRP_MAX))
    {
        eNextNoiseMitMode[Group_Index] = Requested_Mode;
    }
}

/* ===========================================================================
 * Name:	 UssMgr_GetUsedNoiseMitMode
 * Remarks:  DD-ID: {CC67C5C6-4E5B-4814-9EDD-37274A587B95}
 * ===========================================================================*/
US_E_NoiseMitigationMode_t UssMgr_GetUsedNoiseMitMode(uint8_t Group_Index)
{
    //comment out  return eNextNoiseMitMode;
    return eUsedNoiseMitMode[Group_Index];
}
/* ===========================================================================
 * Name:	 UssMgr_IsGroupInNFDMode
 * Remarks:  DD-ID: {E69167BA-955D-4204-9FCE-C7B75E70A7A2}
 * ===========================================================================*/

bool_t UssMgr_IsGroupInNFDMode(uint8_t Group_Index)
{
    bool_t bRetVal = ME_FALSE;
    
    if (ePrevNFDReq[Group_Index] == NFD_MODE_ON)
    {
        bRetVal = ME_TRUE;
    }
    return bRetVal; 
}
/* ===========================================================================
 * Name:	 UssMgr_GetGlobalNFDMode
 * Remarks:  DD-ID: {7E33D627-B0E7-41ea-878A-962FA1A9299A}
 * Req.-ID: 13424090
 * ===========================================================================*/

static UssMgr_E_NFDMode_t UssMgr_GetGlobalNFDMode(void)
{
    return eGlobalNFDMode;
}

/**** External option interface ***/
Std_ReturnType UssMgr_ModeControl_NFDOption(bool_t Enabled)
{
    bExtNFDEnable = Enabled;
#ifdef USSMGR_GLOBAL_NFD_DISABLE
    return ME_NOT_OK;
#else
    return ME_OK;
#endif
}

/* ===========================================================================
 * Name:	 UssMgr_RestoreNonListenSettings

 * Remarks:  DD-ID: {052C8277-BD94-4128-89A3-C005F4B1EE46}
 * Req.-ID: 
 * ===========================================================================*/
void UssMgr_RestoreNonListenSettings(void)
{
    uint8_t uGrpIdx;

    for( uGrpIdx = ZERO; uGrpIdx < US_D_PHYS_GRP_MAX; uGrpIdx++ )
    {
        if (UsedBurstCfg[uGrpIdx] != NULL)
        {
            UssSnrCmd_SetBurstConfigByGroupID(uGrpIdx, UsedBurstCfg[uGrpIdx]);
        }
        else
        {
            /* Should only be here after boot - how did get called so early? */
            UssSnrCmd_SetBurstConfigByGroupID(uGrpIdx, &US_BrstCfg_Front_Rear_Fixed);
        }
        UssSnrCmd_SetRcvProfilesByGroupID(uGrpIdx, UsedProfile[uGrpIdx]);
        UssSnrCmd_SetMeasEchoTypeByGroupIdx(uGrpIdx, UsedMeasType[uGrpIdx]);
    }
}

/* ===========================================================================
 * Name:	 UssMgr_SetListenOnlySettings
 * Remarks:  DD-ID: {9D8199CF-473E-4317-9C2E-71877E68E1A4}
 * Req.-ID: 
 * ===========================================================================*/
void UssMgr_SetListenOnlySettings(void)
{
    uint8_t uBusIdx;

    if ( (SILENCE_REQ_CHIRP == eSilenceDecision) && (NOISE_CHECK_FIXED == eNoiseCheckType)
         && (UssMgr_GetNoiseReactionCfg() == SYSMGR_NOISEREACT_DYN_CHIRP) )
    {
        eNoiseCheckType = NOISE_CHECK_CHIRP;
        UssSnrCmd_SetBurstConfigGlobally(&US_BrstCfg_Chirp_Both);
        /* faster to do by bus when setting globally */
        for (uBusIdx = ZERO; uBusIdx < US_D_MAX_NUM_BUS; uBusIdx++)
        {
            UssSnrCmd_SetRcvProfiles(uBusIdx, US_E_PROFILE_C);
            UssSnrCmd_SetMeasEchoTypeByGroupIdx(uBusIdx, US_E_REQ_RECEIVE);
        }
    }
    else
    {
        eNoiseCheckType = NOISE_CHECK_FIXED;
        UssSnrCmd_SetBurstConfigGlobally(&US_BrstCfg_Front_Rear_Fixed);
        /* faster to do by bus when setting globally */
        for (uBusIdx = ZERO; uBusIdx < US_D_MAX_NUM_BUS; uBusIdx++)
        {
            UssSnrCmd_SetRcvProfiles(uBusIdx, US_E_PROFILE_A);
            UssSnrCmd_SetMeasEchoTypeByGroupIdx(uBusIdx, US_E_REQ_RECEIVE);
        }
    }
}
/* ===========================================================================
 * Name:	 UssMgr_GetNoiseCheckType
 * Remarks:  DD-ID: {4D7EB4C8-50A6-4cff-B308-6819FE45B9D5}
 * Req.-ID: 
 * ===========================================================================*/
US_E_NoiseCheckType_t UssMgr_GetNoiseCheckType(void)
{
    return eNoiseCheckType;
}

