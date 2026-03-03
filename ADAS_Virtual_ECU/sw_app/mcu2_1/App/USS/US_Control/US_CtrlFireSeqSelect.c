/*
 * US_CtrlFireSeqSelect.c
 *
 *  Created on: Mar 11, 2021
 *      Author: jonapais
 */
#include "US_ME_Typedefs_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_Ctrl_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_SysMgr_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_Platform_Global.h"

static void UssCtrl_InitShuffleList(US_S_FireSeqCmd_t *psCurFireSeqCmd);
static uint8_t UssCtrl_uGetRandNum(uint8_t uMaxRandVal);

/*
 * Data
 */
static US_S_FireSeqCmd_t   asFireSeqCmds[US_MAX_FIRE_SEQ_CMDS];    
static uint16_t     uFireSeqDelayMs = ZERO;
static uint8_t      uNumOfFireSeqs = ZERO;
static bool_t       bUssCtrlFsmHalted = ME_TRUE;
static uint8_t      uRandSilenceMaxTime = ZERO;
static uint8_t      uListenOnlyCnt = ZERO;
static uint8_t      uListenOnlyFreq = ZERO;
static uint8_t      uListenOnlyDelay = ZERO;
static bool_t       bRestoreRegularSettings = (bool_t)ME_FALSE;
#if(QAC_WARNING_FIX == ME_FALSE)
/*===========================================================================
 * \brief Initialize fire sequence module.
 *
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_SetFireSequenceInit
 * Remarks:  DD-ID: {82D43E0B-F0E7-45d6-B075-08B6DB46B0FF}
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * Req.-ID:13411566
 * Req.-ID:13414460
 * ===========================================================================*/
void UssCtrl_SetFireSequenceInit(void)
{
    uint8_t uOpMode = US_SnrCfg_Get_OperationMode();

    UssCtrl_SetListenOnlyFreq(6u, 1u);  /* Zero = Disabled. */

    /*\UssCtrl_SetRandSilenceMaxMs(TEN);    10 ms max.  Delay times will be one of: 0,2,4,6,8,10 ms */
    UssCtrl_SetRandSilenceMaxMs(0u); /* 0 ms == Random Silence Function disabled. */
    
    UssSnrCmd_SetBurstConfigGlobally(&US_BrstCfg_Front_Rear_Fixed);

#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
    if ((uOpMode == US_NORMAL_MODE)||(uOpMode == US_DIAGNOSTIC_MODE))
    {
/* comment                                 UssCtrl_SetFireSequence(US_SnrLocs_FrntSideRear_OneAtATime_16ST,
* comment                                US_FIRE_PAT_ROUND_ROBIN,
* comment                                 US_FIRE_PAT_START_AT_ZERO,
* comment                                 US_SNRLOCS_SIXTEEN_STEP_SEQ_LEN,
* comment                                 SIXTEEN);

* comment         UssCtrl_SetFireSequence(US_SnrLocs_FrontRearSides_SameTime,    US_SnrLocs_RivianFastScan_SameTime,
* comment        US_FIRE_PAT_ROUND_ROBIN,
* comment       US_FIRE_PAT_START_AT_ZERO,
* comment         US_SNRLOCS_SIX_STEP_SEQ_LEN,
* comment         SIX);
*/
        UssCtrl_SetFireSequence(US_SnrLocs_RivianFastScan_SameTime,
        US_FIRE_PAT_ROUND_ROBIN,
        US_FIRE_PAT_START_AT_ZERO,
        US_SNRLOCS_FOUR_STEP_SEQ_LEN,
        (US_SNRLOCS_FOUR_STEP_SEQ_LEN * FOUR));  /*jwr - updated to max 16 cycle so the sequence repeats 4 times  */

        UssCtrl_SetFireSeqDelayMs(0u);  /* 0 ms delay before next measurement */
        UssCtrl_StartFireSeq();
    }
#else

    if (uOpMode == (uint8_t)US_NORMAL_MODE)
    {
        UssCtrl_StopFireSeq();
    }
    else if (uOpMode == (uint8_t)US_SNR_TEST_MODE)
    {
        UssCtrl_SetFireSequence(US_SnrLocs_FrntRear_OneAtATime_12ST,
                                US_FIRE_PAT_ROUND_ROBIN,
                                US_FIRE_PAT_START_AT_ZERO,
                                US_SNRLOCS_TWELVE_STEP_SEQ_LEN,
                                TWELVE);

        UssCtrl_SetFireSeqDelayMs(0u);  /* 0 ms delay before next measurement */
        UssCtrl_StartFireSeq();
    }
    else if (uOpMode == (uint8_t)US_NORMAL_AUTO_MODE)
    {
        UssCtrl_SetFireSequence(US_SnrLocs_FastScan_SameTime,
                                US_FIRE_PAT_ROUND_ROBIN,
                                US_FIRE_PAT_START_AT_ZERO,
                                US_SNRLOCS_FOUR_STEP_SEQ_LEN,
                                (US_SNRLOCS_FOUR_STEP_SEQ_LEN * FOUR)); /* x4 to support NFD */

        UssCtrl_SetFireSeqDelayMs(0u);  /* 0 ms delay before next measurement */
        UssCtrl_StartFireSeq();
    }
    else
    {
        ;/*Do nothing */
    }

#endif

}
#endif
/*===========================================================================
 * \brief Set a new firing sequence.
 *
 * \param none
 * \param none
 * \return
 * \remarks Controller FSM must be restarted after calling this fn.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_SetFireSequence
 * Remarks:  DD-ID: {3C1A0DE8-7811-468f-B6CA-EFDE385286D7}
 * Traceability to source Code:
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * ===========================================================================*/
void UssCtrl_SetFireSequence(const US_S_SensorLocs_t       *psSensorLocSeq,
                                US_E_FireSeqPatType_t       eFireSeqPat,
                                US_E_FireSeqPatStartType_t  eFireSeqPatStartType,
                                uint8_t                     uNumSeqSteps,
                                uint8_t                     uMaxCycleCount)
{
    bUssCtrlFsmHalted = ME_TRUE;
    uNumOfFireSeqs = ZERO;
    asFireSeqCmds[uNumOfFireSeqs].psSensorLocSeq         = psSensorLocSeq;
    asFireSeqCmds[uNumOfFireSeqs].eFireSeqPat            = eFireSeqPat;
    asFireSeqCmds[uNumOfFireSeqs].eFireSeqPatStartType   = eFireSeqPatStartType;
    asFireSeqCmds[uNumOfFireSeqs].uCurCycleCount         = ZERO;
    asFireSeqCmds[uNumOfFireSeqs].uMaxCycleCount         = uMaxCycleCount;
    asFireSeqCmds[uNumOfFireSeqs].uNumSeqSteps           = uNumSeqSteps;
    asFireSeqCmds[uNumOfFireSeqs].uCurSeqStep            = US_FS_NEEDS_INIT;
    uNumOfFireSeqs++;//PRQA S    We want variable to rollover,required behaviour
}
#if(QAC_WARNING_FIX == ME_FALSE)
/*===========================================================================
 * \brief Add an additional firing sequence.
 *
 * \param none
 * \param none
 * \return
 * \remarks Controller FSM must be restarted after calling this fn.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_AddFireSequence
 * Remarks:  DD-ID: {9C0EB734-B1E6-4704-830B-3223996B945C}
 * ===========================================================================*/
void UssCtrl_AddFireSequence(const US_S_SensorLocs_t       *psSensorLocSeq,
                                US_E_FireSeqPatType_t       eFireSeqPat,
                                US_E_FireSeqPatStartType_t  eFireSeqPatStartType,
                                uint8_t                     uNumSeqSteps,
                                uint8_t                     uMaxCycleCount)
{
    bUssCtrlFsmHalted = ME_TRUE;
    if (uNumOfFireSeqs < (uint8_t)US_MAX_FIRE_SEQ_CMDS)
    {
        bUssCtrlFsmHalted = (bool_t)ME_TRUE;
        asFireSeqCmds[uNumOfFireSeqs].psSensorLocSeq         = psSensorLocSeq;
        asFireSeqCmds[uNumOfFireSeqs].eFireSeqPat            = eFireSeqPat;
        asFireSeqCmds[uNumOfFireSeqs].eFireSeqPatStartType   = eFireSeqPatStartType;
        asFireSeqCmds[uNumOfFireSeqs].uCurCycleCount         = ZERO;
        asFireSeqCmds[uNumOfFireSeqs].uMaxCycleCount         = uMaxCycleCount;
        asFireSeqCmds[uNumOfFireSeqs].uNumSeqSteps           = uNumSeqSteps;
        asFireSeqCmds[uNumOfFireSeqs].uCurSeqStep            = US_FS_NEEDS_INIT;
        uNumOfFireSeqs++;//PRQA S    We want variable to rollover,required behaviour
    }
}
#endif 
/*===========================================================================
 * \brief Advance or start a fire sequence set.
 *
 * \param none
 * \param none
 * \return bool_t if ME_TRUE, then delay bursting this cycle.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_SetNextFireSequenceStep
 * Remarks:  DD-ID: {BF6D8FB8-4DEC-4a8d-97F0-52C5411BBC5E}
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * ===========================================================================*/
/*KPK-QAC Fix : Need to suppress, multiple branch/loop statements doesn't lead to any complexcity */
bool_t UssCtrl_SetNextFireSequenceStep(void)
{
    uint8_t uCurFireSeqIdx;

    /*
     * Check if this is a listen only step.
     */
    if (uListenOnlyFreq != (bool_t)ZERO)
    {
        uListenOnlyCnt++;//PRQA S    We want variable to rollover,required behaviour

        if (uListenOnlyCnt >= (uListenOnlyFreq + uListenOnlyDelay)) /*We will listen/receive only this time. */
        {
            uListenOnlyCnt = ZERO;
            UssMgr_SetListenOnlySettings();
            UssSnrCmd_PopulateBurstCommand_AllRcv();
            bRestoreRegularSettings =(bool_t)ME_TRUE;
            return ME_FALSE;        /********* EARLY RETURN **********/
        }
        else if (uListenOnlyCnt >= uListenOnlyFreq)  /*We will delay some cycles prior to listen/receive only. */
        {
            return  (bool_t)ME_TRUE;         /********* EARLY RETURN **********/
        }
        else
        {
            if ( bRestoreRegularSettings == (bool_t)ME_TRUE )
            {
                UssMgr_RestoreNonListenSettings();
                bRestoreRegularSettings = (bool_t)ME_FALSE;
            }
            else
            {
                ;/*Do nothing */
            }
        }
    }
    else
      {
        ;/*Do nothing */
      }
    /*
     *  Advance all fire sequences
     */
    for (uCurFireSeqIdx = (uint8_t)0; uCurFireSeqIdx < uNumOfFireSeqs; uCurFireSeqIdx++) /*Sequence through all sequences */
    {
        US_S_FireSeqCmd_t *psCurFireSeqCmd = &asFireSeqCmds[uCurFireSeqIdx]; /*we may have multiple sequences running.  Get current. */

        psCurFireSeqCmd->uCurCycleCount++; // Advance Fire Sequence Cycle Count.

        /*If we have executed max cycles, restart/reinitialize fire sequence. */
        if (psCurFireSeqCmd->uCurCycleCount > psCurFireSeqCmd->uMaxCycleCount)
        {
            psCurFireSeqCmd->uCurSeqStep = US_FS_NEEDS_INIT; /*Request reinitialize of this sequence. */
            psCurFireSeqCmd->uCurCycleCount = ONE;
        }

        if (psCurFireSeqCmd->uCurSeqStep == US_FS_NEEDS_INIT)  /*Initialization of fire sequence has been requested */
        {
            psCurFireSeqCmd->uCurSeqStep = ZERO;

            if (psCurFireSeqCmd->eFireSeqPat == US_FIRE_PAT_SHUFFLE)
            {
                UssCtrl_InitShuffleList(psCurFireSeqCmd);
                psCurFireSeqCmd->uCurSeqRecord = psCurFireSeqCmd->auSnrIdxShuffleList[ZERO];
            }
            else if (psCurFireSeqCmd->eFireSeqPat == US_FIRE_PAT_ROUND_ROBIN_REVERSE)
            {
                psCurFireSeqCmd->uCurSeqRecord = psCurFireSeqCmd->uNumSeqSteps - ONE;
            }
            else if (psCurFireSeqCmd->eFireSeqPatStartType == US_FIRE_PAT_START_AT_ZERO)
            {
                psCurFireSeqCmd->uCurSeqRecord = ZERO;
            }
            else if (psCurFireSeqCmd->eFireSeqPatStartType == US_FIRE_PAT_START_AT_RANDOM)
            {
                psCurFireSeqCmd->uCurSeqRecord = UssCtrl_uGetRandNum(psCurFireSeqCmd->uNumSeqSteps);
            }
           else { /*empty*/}
        }
        else /*Continue to advance current fire sequence */
        {
            psCurFireSeqCmd->uCurSeqStep++; // Advance sequence

            /*Roll around to beginning.  If statement is more efficient then modulus. */
            if (psCurFireSeqCmd->uCurSeqStep >= psCurFireSeqCmd->uNumSeqSteps)
            {
                psCurFireSeqCmd->uCurSeqStep = ZERO;
            }

            if (psCurFireSeqCmd->eFireSeqPat == US_FIRE_PAT_SHUFFLE)
            {
                psCurFireSeqCmd->uCurSeqRecord = psCurFireSeqCmd->auSnrIdxShuffleList[psCurFireSeqCmd->uCurSeqStep];
            }
            else if (psCurFireSeqCmd->eFireSeqPat == US_FIRE_PAT_ROUND_ROBIN)
            {
                psCurFireSeqCmd->uCurSeqRecord = psCurFireSeqCmd->uCurSeqStep;
            }
            else if (psCurFireSeqCmd->eFireSeqPat == US_FIRE_PAT_ROUND_ROBIN_REVERSE)
            {
                psCurFireSeqCmd->uCurSeqRecord = psCurFireSeqCmd->uNumSeqSteps- ONE - psCurFireSeqCmd->uCurSeqStep;
            }
            else if (psCurFireSeqCmd->eFireSeqPat == US_FIRE_PAT_RANDOM)
            {
                psCurFireSeqCmd->uCurSeqRecord = UssCtrl_uGetRandNum(psCurFireSeqCmd->uNumSeqSteps);
            }
           else { /*empty*/}
        }
    }

    /*
     * Populate the burst command structure with current fire pattern
     */
    UssSnrCmd_PopulateBurstCommand();

    /*
     * Random silence selection:
     * Resolution is presently 2ms.  Hard-coded at present because
     * we are planning on changing to a high res timer.
     * At that time we will read the timer resolution from an
     * accessor function.
     */

    /* Right shift to divide by two milliseconds.  (See above.)*/
    if (uRandSilenceMaxTime != ZERO)
    {
        uint8_t uRandSilenceThisCycle = UssCtrl_uGetRandNum((uRandSilenceMaxTime >> ONE) + ONE);
        US_SnrDrvCom_F_SetDequeueDelay(uRandSilenceThisCycle);
        /* \cMELog_F_LogDebug_v("UssCtrl: Random silence Time = %d", uRandSilenceThisCycle << ONE); */
    }
    else
    {
        US_SnrDrvCom_F_SetDequeueDelay(ZERO); /* Skip the math, we know the answer. */
    }

    return     (bool_t)ME_FALSE;

}

/*===========================================================================
 * \brief Get delay between fire sequence steps in milliseconds.
 *
 * \param none
 * \param none
 * \return uFireSeqDelayMs in ms.
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_uGetuFireSeqDelayMs
 * Remarks:  DD-ID: {1661CECA-68C4-4a29-84E0-D7F68B931299}
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * ===========================================================================*/
uint16_t UssCtrl_uGetuFireSeqDelayMs(void)
{
    return uFireSeqDelayMs;
}

/*===========================================================================
 * \brief Set delay between fire sequence steps in milliseconds.
 *
 * \param uFireSeqDelayMs in ms.
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_SetFireSeqDelayMs
 * Remarks:  DD-ID: {733E45B3-2368-46b1-A1D0-C707172A1852}
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * ===========================================================================*/
void UssCtrl_SetFireSeqDelayMs(uint8_t uDelayMs)
{
    uFireSeqDelayMs = uDelayMs;
}

/*===========================================================================
 * \brief Set random silence max time in milliseconds.
 *
 * \param uMaxTime Random silence max time in ms.
 * \param none
 * \return
 * \remarks Current resolution is 2 ms, needs to be improved with high res timer.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_SetRandSilenceMaxMs
 * Remarks:  DD-ID: {F2F371A1-F40B-42a7-B859-80A3F6A869C7}
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * ===========================================================================*/
void UssCtrl_SetRandSilenceMaxMs(uint8_t uMaxTime)
{
    uRandSilenceMaxTime = uMaxTime;
}

/*===========================================================================
 * \brief Set the frequency of listen only cycles.
 *
 * \param uLstOnlyFreq Number of fire cycles before listen only cycle.  Zero = Disabled.
 * \param uint8_t uCycleDelay  Numer of controller cycles (10ms) to delay prior to listen only.
 * \return
 * \remarks Current fire sequence is on hold for the listen cycle.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_SetListenOnlyFreq
 * Remarks:  DD-ID: {6410F54D-25FD-4c65-A84E-302361282CC4}
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * ===========================================================================*/
void UssCtrl_SetListenOnlyFreq(uint8_t uLstOnlyFreq, uint8_t uCycleDelay)
{
    uListenOnlyFreq = uLstOnlyFreq;
    uListenOnlyDelay = uCycleDelay;
    uListenOnlyCnt = ZERO;
}

/*===========================================================================
 * \brief Get pointer to fire sequence set.
 *
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_pasGetFireSeqCmds
 * Remarks:  DD-ID: {ABA27E8E-FF56-4278-AFAD-DC6FF43E9623}
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * ===========================================================================*/
US_S_FireSeqCmd_t *UssCtrl_pasGetFireSeqCmds(void)
{
    return asFireSeqCmds;
}

/*===========================================================================
 * \brief Get number of fire sequences in set.
 *
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_uGetNumFireSequences
 * Remarks:  DD-ID: {BC8C594B-5EF7-4967-A285-33B04190EF0E}
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * ===========================================================================*/
uint8_t UssCtrl_uGetNumFireSequences(void)
{
    return uNumOfFireSeqs;
}

/*===========================================================================
 * \brief Get current sequence number for selected fire sequences
 *
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_uGetFireSequenceCurCycle
 * Remarks:  DD-ID: {27D760D6-34E8-4c51-B0D5-2343E3E7F53B}
 * Req.-ID:17350852
 * Req.-ID:17350940
 * Req.-ID:13420461
 * ===========================================================================*/
uint8_t UssCtrl_uGetFireSequenceCurCycle(uint8_t uFireSequenceIdx)
{
    if (uFireSequenceIdx < US_MAX_FIRE_SEQ_CMDS)
    {
        US_S_FireSeqCmd_t const *psCurFireSeqCmd = &asFireSeqCmds[uFireSequenceIdx];
    
        return psCurFireSeqCmd->uCurCycleCount;
    }
    else
    {
        return  (uint8_t)0xFF;
    }
}
#if(QAC_WARNING_FIX == ME_FALSE)
/*===========================================================================
 * \brief Clear all fire sequences.
 *
 * \param none
 * \param none
 * \return
 * \remarks Do not restart controller state machine without setting a fire seq.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_ClearAllFireSequences
 * Remarks:  DD-ID: {8C52C18B-88C7-453b-8C52-CFA51BD3137E}
 * ===========================================================================*/
void UssCtrl_ClearAllFireSequences(void)
{
    bUssCtrlFsmHalted = (bool_t)ME_TRUE;
    uNumOfFireSeqs = ZERO;
}
#endif
/*===========================================================================
 * \brief Halt firing sensors.
 *
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_StopFireSeq
 * Remarks:  DD-ID: {F8D282EB-BD4D-4c07-8A93-08A5EB423CC2}
 * Req.-ID: 14210760
 * Req.-ID: 14214786
 * Req.-ID: 14214192
 * Req.-ID: 15001879
 * ===========================================================================*/
void UssCtrl_StopFireSeq(void)
{
    bUssCtrlFsmHalted =(bool_t) ME_TRUE;
}

/*===========================================================================
 * \brief Start firing sensors.
 *
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_StartFireSeq
 * Remarks:  DD-ID: {EDD46648-BA29-4870-A426-4A587FC8E5CE}
 * Req.-ID: 14210760
 * Req.-ID: 14214786
 * Req.-ID: 14214192
 * Req.-ID: 15001879
 * ===========================================================================*/
void UssCtrl_StartFireSeq(void)
{
    bUssCtrlFsmHalted =(bool_t) ME_FALSE;
}

/*===========================================================================
 * \brief Check if sensor firing is halted.
 *
 * \param none
 * \param none
 * \return
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_bIsCtrlFsmHalted
 * Remarks:  DD-ID: {770FB0D3-45B3-419c-ACB0-4DD769D8674F}
 * Req.-ID: 13396047
 * ===========================================================================*/
bool_t UssCtrl_bIsCtrlFsmHalted(void)
{
    return bUssCtrlFsmHalted;
}

/*===========================================================================
 * \brief Generate a random number.
 *
 * \param uMaxRandVal Max random number to be generated, non-inclusive.
 * \param none
 * \return Random number [0, uMaxRandVal)
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_uGetRandNum
 * Remarks:  DD-ID: {E947A936-0B7F-4573-A389-FE3B6347F3E5}
 * Req.-ID: 13396047
 * ===========================================================================*/
static uint8_t UssCtrl_uGetRandNum(uint8_t uMaxRandVal)
{
    uint8_t uRandVal = ONE;

    if (uMaxRandVal != ZERO)
    {
        uRandVal = (uint8_t) (UssMgr_JKISS32RandAlgo() & (uint32_t)0xff);
        uRandVal = (uRandVal % uMaxRandVal);
    }

    return uRandVal;
}

/*===========================================================================
 * \brief Generate seq list and shuffle.
 *
 * \param none
 * \param none
 * \return
 * \remarks Shuffle psCurFireSeqCmd->auSnrIdxShuffleList in place.
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_InitShuffleList
 * Remarks:  DD-ID: {88662B3E-D4E2-4fca-BB9B-72F9CED746E9}
 * Req.-ID: 13396047
 * ===========================================================================*/
static void UssCtrl_InitShuffleList(US_S_FireSeqCmd_t *psCurFireSeqCmd)
{
    uint8_t *auIdxList = psCurFireSeqCmd->auSnrIdxShuffleList;
    uint8_t n = psCurFireSeqCmd->uNumSeqSteps;
    uint8_t i, k, tmp;

    if (n > USS_MAX_NUM_STEPS_FOR_SHUFFLE)
    {
#if UART_SUPPORTED
        cMELog_F_LogDebug_v("UssCtrl: InitShuffleList - Error: Number of steps larger than alloted space.  %d > %d",
                n, USS_MAX_NUM_STEPS_FOR_SHUFFLE);
#endif
        n = USS_MAX_NUM_STEPS_FOR_SHUFFLE;  /*limit list. */
    }
    else
    {
        ;/*Do nothing */
    }

    /*Initialize index list */
    for (i = ZERO; i < n; i ++)
    {
        auIdxList[i] = i;
    }

    /*Shuffle list.  (Fisher-Yates Shuffle) */
    while (n > ONE)
    {
        k = UssCtrl_uGetRandNum(n);
        n--;

        tmp = auIdxList[n];
        auIdxList[n] = auIdxList[k];
        auIdxList[k] = tmp;
    }
}

/*
 * Old amazon sequencer - for reference - to be removed.
 */



#if 0
/*
 * Inputs:
 *
 *
 * outputs:
 * Std_ReturnType
 * sndBrtCmd_pt
 * SndCluster
 * isNeedSendBurst
 * Note:  Output to feed this bad boy... aUSSCtrl_F_SendBurstCmd_b(SndCluster, sndBrtCmd_pt, isNeedSendBurst);
 *
 * aUSSCtrlDP_F_Set_CycleEnd_v (flags)
 *
 *
 *
 */

/* comment   aUSSCtrlDP_F_GetAirTempOutsd_v(&aJobUSSCtrl_v_AirTempOutsd);
* comment   UssCtrlDP_GetNeedUpdateTempFromSnr(&aJobUSSCtrl_v_NeedUpdateTempFromSnr);
* comment   UssCtrlDP_GetReqSnrFeatureFlag(&aJobUSSCtrl_v_ReqSnrFeatureFlag);
* comment   aUSSCtrlDP_F_GetReqSnrCompGain_v(&aJobUSSCtrl_v_ReqSnrCompGain);
* comment   aUSSCtrlDP_F_GetReqSnr_v(&aJobUSSCtrl_v_ReqSnr);
* comment   aUSSCtrlDP_F_GetDSIerrFlag_v(&aJobUSSCtrl_v_DSIerr);
*/
/* ---------------- tmp ---------------
*\static uint8_t aJobUSSCtrl_v_ReqSnr;
*\extern uint8_t RTOS_Snr_Initail_AllDone;                 from Rte
*\extern static pUS_E_APAType_Mod_t UssCtrl_APAMode;
*\extern static pUS_E_APAType_Mod_t UssCtrl_PrevAPAMode;
*/
static uint32_t UssCtrl_GetRand(uint32_t Srcmaxval);

static bool_t aJobUSSCtrl_v_NeedUpdateTempFromSnr;
static bool_t aJobUSSCtrl_v_ReqSnrFeatureFlag;
static bool_t aJobUSSCtrl_v_ReqSnrCompGain;
static pUS_E_AmazonSetCmd_t aJobUSSCtrl_v_SetCmd_e = pUS_E_AMZ_SetCmd_None;
pUS_E_EchoInfoType_t aJobUSSCtrl_Filter_Mode = pUS_E_CombinePath;
static uint8_t aJobUSSCtrl_v_EnvelopeSendingSnr_u8 = 0;
static pUS_E_ProfileType_t aJobUSSCtrl_v_EnvelopeProfile_e = pUS_E_PF_USER_DEFINE;
pUS_E_ProfileType_t aJobUSSCtrl_profileTypeF = pUS_E_PROFILE_A;
pUS_E_ProfileType_t aJobUSSCtrl_profileTypeR = pUS_E_PROFILE_A;
static uint32_t USS_cycle_log_cnt = 0;

/* TODO: jp - all of the following should be put into headers where they belong */
extern pUS_E_DEGROWLER_MOD_t aJobUSSCtrl_DeGrowlerMod;  /*from US_CtrlGrowlerFsm.c */
extern pUS_E_SnrErrState_t aUSS_v_SnrNeedGetErrCode;    /*from manager */
extern uint8_t FlexCan_v_EnvBurst_u8;                   /*from flexcanCom.c */
extern pUS_S_EDICfg_t USSSENS_v_Basic_EDI_t;            /*from driver */
extern pUS_S_NFDCfg_t USSSENS_v_Basic_NFD_t;            /*from driver */
extern Std_ReturnType aUSSCtrl_F_SendBurstCmd_b(pUS_E_ClusterID_t ClusterID, pUS_S_ClusterBurstCmd_t* Cmd_pt, bool_t isNeedSendBurst); /*from burst \todo jp - add to header for burst */
extern void aJobUSOD_f_SensorBlockage(void);  /*from OD */
extern void aJobUSOD_f_SensorBlockage(void);  /*from OD */

/*--------------------------------------- */
Std_ReturnType UssCtrl_FireSequenceSelection(void)
{
    Std_ReturnType rval = E_OK;
    pUS_S_ClusterBurstCmd_t *sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ALLRcvFixPath_at[0]);
    pUS_E_ClusterID_t SndCluster = aUSS_D_RUNNING_CLUSTER;
    static uint8_t PureModPostion = 1;
    uint8_t ParkFixRound = Uss_D_NFD_Fix_Round;  /*20 */
    uint8_t BlockFixRound = Uss_D_Block_Fix_Round; /*2 */
    uint8_t GroundFixRound = Uss_D_Ground_Fix_Round; /*2 */
    uint8_t NFDRound = Uss_D_NFD_Round; /*7 */

    return rval; /*\TODO jp - temp short circuit to skip driver */

    aJobUSSCtrl_v_NeedUpdateTempFromSnr = UssMgr_bGetIsTempSnrUpdateNeeded();
    aJobUSSCtrl_v_ReqSnrFeatureFlag = UssMgr_bGetReqSnrFeatureFlag();
    aJobUSSCtrl_v_ReqSnrCompGain = UssMgr_bGetReqSnrCompGain();

    if (aJobUSSCtrl_v_SetCmd_e == pUS_E_AMZ_SetCmd_None)
    {
        aJobUSSCtrl_v_SetCmd_e = UssMgr_eGetSetCmd();
    }
    if (aJobUSSCtrl_v_SetCmd_e == pUS_E_AMZ_SetCmd_EdiConfig)
    {
        UssMgr_psGetEdiConfig(&USSSENS_v_Basic_EDI_t);
    }
    if (aJobUSSCtrl_v_SetCmd_e == pUS_E_AMZ_SetCmd_NFDConfig)
    {
        UssMgr_psGetNFDConfig(&USSSENS_v_Basic_NFD_t);
    }

    /*need command - whole other thing */

    /*get essential info */

    cMELog_F_LogDebug_v("Jon - Sensburst: APA Mode = %d, Degrowler = %d", UssCtrl_APAMode, aJobUSSCtrl_DeGrowlerMod);

    if (_fg_NFD == ME_FALSE)
    {
        ParkFixRound = Uss_D_Park_Fix_Round;
    }
    /* Uss_Frnt_SndBrtCmd_SrchFar_at
     * Uss_Rear_SndBrtCmd_SrchFar_at
     * Uss_ALL_SndBrtCmd_PrkFar_at
     * Uss_ALL_SndBrtCmd_ParkNear_at
     * Uss_ALL_SndBrtCmd_SrchNear_at*/

   /* jp - i have no idea what these different modes are, apparently envelope mode does not fire anything of env burst is anything other than 0 or 1
    * can only find a setting to zero in the code
*/
    if (UssCtrl_APAMode == pUS_E_APA_Envelope && FlexCan_v_EnvBurst_u8 > 1) /* WTF is this doing - figure it out */
    {
        return rval;
    }

    /* if we neet to get error data or ring data or temp, feature flag, or comp gain, or we have a set command 
   * it is just going to use the default: Uss_ALL_17SndBrtCmd_ALLRcvFixPath_at[0]
*/
    if (((aUSS_v_SnrNeedGetErrCode & pUS_E_SnrErr_NeedGetData) /* mgr uses this  */
    || (aUSS_v_SnrNeedGetErrCode & pUS_E_SnrErr_NeedGetRing)) /* mgr uses this */
    || (aJobUSSCtrl_v_NeedUpdateTempFromSnr == ME_TRUE)  /*local*/
            || (aJobUSSCtrl_v_ReqSnrFeatureFlag == ME_TRUE)  /*local*/
            || (aJobUSSCtrl_v_ReqSnrCompGain == ME_TRUE) /*local*/
            || (aJobUSSCtrl_v_SetCmd_e != pUS_E_AMZ_SetCmd_None)) /*local*/
    {
        rval = aUSSCtrl_F_SendBurstCmd_b(SndCluster, sndBrtCmd_pt, ME_TRUE);
        return rval;
    }
    else if (aJobUSSCtrl_DeGrowlerMod == pUS_E_NO_DEGROWLER)
    {
        switch (UssCtrl_APAMode)
        {
            case pUS_E_APA_IDLE:
            {
                if (aJobUSSCtrl_ENVMode == pUS_E_NRWSP)
                {
                    eUssCtrl_CheckEnvStage = e_aJobUSSCtrl_Check_Finished;
                    sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_NFDCmd_at[Uss_ALL_RoundCnt_NFD_Max6]);

                    Uss_ALL_RoundCnt_NFD_Max6 = (Uss_ALL_RoundCnt_NFD_Max6 + 1) % NFDRound;
                    if (Uss_ALL_RoundCnt_NFD_Max6 == 0)
                        UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                    else
                        UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);
                    if (USS_cycle_log_cnt > 50)
                    {
                        aUSS_D_LogWarning("[USS] FireSequece on IDLE NRW ");
                        USS_cycle_log_cnt = 0;
                    }
                    else
                    {
                        USS_cycle_log_cnt++;
                    }
                }
                else
                {
                    /* Blockage check and GroundType check */
                    if (aJobUSSMgr_ChkBlock == pUS_E_CHK_GROUND)
                    {
                        sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_GroundFix_at[Uss_ALL_RoundCnt_GroundFix_Max2]);
                        /* rand to send ALLRcv Mod */

                        /*PureReceive */
                        Uss_ALL_RoundCnt_GroundFix_Max2 = (Uss_ALL_RoundCnt_GroundFix_Max2 + 1) % GroundFixRound;

                        if (Uss_ALL_RoundCnt_GroundFix_Max2 == 0)
                            UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                        else
                            UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                        if (USS_cycle_log_cnt > 50)
                        {
                            aUSS_D_LogWarning("[USS] FireSequece on IDLE Ground check ");
                            USS_cycle_log_cnt = 0;
                        }
                        else
                        {
                            USS_cycle_log_cnt++;
                        }
                    }
                    else if (aJobUSSMgr_ChkBlock == pUS_E_CHK_BLOCK)
                    {
                        sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_BlockFix_at[Uss_ALL_RoundCnt_BlockFix_Max2]);
                        /* rand to send ALLRcv Mod               PureReceive */
                        Uss_ALL_RoundCnt_BlockFix_Max2 = (Uss_ALL_RoundCnt_BlockFix_Max2 + 1) % BlockFixRound;

                        if (Uss_ALL_RoundCnt_BlockFix_Max2 == 0)
                            UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                        else
                            UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);
                        if (USS_cycle_log_cnt > 50)
                        {
                            aUSS_D_LogWarning("[USS] FireSequece on IDLE Blockage check ");
                            USS_cycle_log_cnt = 0;
                        }
                        else
                        {
                            USS_cycle_log_cnt++;
                        }
                    }
                }
                break;
            }
            case pUS_E_APA_SEARCH:
            {
                break;
            }
            case pUS_E_APA_PARK:
            {
               /* only fix */
                break;
            }
            case pUS_E_APA_RAEB:
            {
                cMELog_F_LogDebug_v("Jon - Sensburst, *** RAEB ***");
                switch (aJobUSSCtrl_Filter_Mode)
                {
                    case pUS_E_CombinePath:
                        break;
                    case pUS_E_FixPath:
                    {
                        if (_fg_NFD == ME_FALSE)
                        {
                            cMELog_F_LogDebug_v("Jon - Sensburst, RAEB/Fix, NFD=F");
                            sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_ParkFix_at[Uss_ALL_RoundCnt_ParkFix_Max6]);
                            if (Uss_ALL_RoundCnt_ParkFix_Max6 == 0)
                            {
                                PureModPostion = UssCtrl_GetRand((ParkFixRound - 1));
                            }
                            if (Uss_ALL_RoundCnt_ParkFix_Max6 == PureModPostion)
                            {
                                sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ALLRcvFixPath_at[0]);
                                PureModPostion = 0;
                            }
                            else
                            {
                                Uss_ALL_RoundCnt_ParkFix_Max6 = (Uss_ALL_RoundCnt_ParkFix_Max6 + 1) % ParkFixRound;
                            }

                            if (Uss_ALL_RoundCnt_ParkFix_Max6 == 0)
                                UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                            else
                                UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                            if (USS_cycle_log_cnt > 100)
                            {
                                cMELog_F_LogDebug_v("[USS] FireSequece on RAEB Fix, Pure at %d ", PureModPostion);
                                USS_cycle_log_cnt = 0;
                            }
                            else
                            {
                                USS_cycle_log_cnt++;
                            }
                        }
                        else
                        {
                            uint8_t temp;
                            cMELog_F_LogDebug_v("Jon - Sendburst, RAEB/Fix, NFD=T, PureModPostion=%d", PureModPostion);

                            sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_ParkFixNFD_at[Uss_ALL_RoundCnt_ParkFix_Max6]);
                            /* rand to send ALLRcv Mod*/
                            if ((Uss_ALL_RoundCnt_ParkFix_Max6 == 0))
                            {
                                PureModPostion = UssCtrl_GetRand(((ParkFixRound / 2) - 1));
                                for (temp = 0; temp < 10; temp++)
                                {
                                    if ((Uss_ALL_SndBrtCmd_ParkFix_at[PureModPostion - 1].ProfileTypeF == pUS_E_PROFILE_B)
                                            || (Uss_ALL_SndBrtCmd_ParkFix_at[PureModPostion - 1].ProfileTypeR == pUS_E_PROFILE_B))
                                    {
                                        PureModPostion = UssCtrl_GetRand(((ParkFixRound / 2) - 1));
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                                if (temp == 10)
                                {
                                    cMELog_F_LogDebug_v("[USS] GetRound Fail! %d ", PureModPostion);
                                    PureModPostion = 0;
                                }
                            }
                            if (Uss_ALL_RoundCnt_ParkFix_Max6 == ParkFixRound / 2)
                            {
                                PureModPostion = UssCtrl_GetRand(((ParkFixRound / 2) - 1));
                                for (temp = 0; temp < 10; temp++)
                                {
                                    if ((Uss_ALL_SndBrtCmd_ParkFix_at[(ParkFixRound / 2) + PureModPostion - 1].ProfileTypeF == pUS_E_PROFILE_B)
                                            || (Uss_ALL_SndBrtCmd_ParkFix_at[(ParkFixRound / 2) + PureModPostion - 1].ProfileTypeR == pUS_E_PROFILE_B))
                                    {
                                        PureModPostion = UssCtrl_GetRand(((ParkFixRound / 2) - 1));
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                                if (temp == 10)
                                {
                                    cMELog_F_LogDebug_v("[USS] GetRound Fail! %d ", (ParkFixRound / 2) + PureModPostion);
                                    PureModPostion = 0;
                                }
                            }
                            if (Uss_ALL_RoundCnt_ParkFix_Max6 == PureModPostion)
                            {
                                sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ALLRcvFixPath_at[0]);
                                PureModPostion = 0;
                                UssMgr_SetRandomSilenceFlag(ME_TRUE);
                            }
                            else if (Uss_ALL_RoundCnt_ParkFix_Max6 == PureModPostion + (ParkFixRound / 2))
                            {
                                sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ALLRcvFixPath_at[0]);
                                PureModPostion = 0;
                                UssMgr_SetRandomSilenceFlag(ME_TRUE);
                            }
                            else
                            {
                                Uss_ALL_RoundCnt_ParkFix_Max6 = (Uss_ALL_RoundCnt_ParkFix_Max6 + 1) % ParkFixRound;
                                UssMgr_SetRandomSilenceFlag(ME_FALSE);
                            }

                            if (Uss_ALL_RoundCnt_ParkFix_Max6 == 0 || Uss_ALL_RoundCnt_ParkFix_Max6 == ParkFixRound / 2)
                                UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                            else
                                UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                            if (USS_cycle_log_cnt > 100)
                            {
                                cMELog_F_LogDebug_v("[USS] JON2 FireSequece on RAEB Fix NFD, Pure at %d ", PureModPostion);
                                USS_cycle_log_cnt = 0;
                            }
                            else
                            {
                                USS_cycle_log_cnt++;
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case pUS_E_APA_EMI:
            {
                sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_EMI_at[Uss_ALL_RoundCnt_EMI_Max6]);
                Uss_ALL_RoundCnt_EMI_Max6 = (Uss_ALL_RoundCnt_EMI_Max6 + 1) % Uss_D_EMI_Round;

                if (Uss_ALL_RoundCnt_EMI_Max6 == 0)
                    UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                else
                    UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                if (USS_cycle_log_cnt > 100)
                {
                    cMELog_F_LogDebug_v("[USS] FireSequece on EMI test");
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
                break;
            }
            case pUS_E_APA_EMS:
            {
                sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ALLRcvFixPath_at[0]);
                UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                if (USS_cycle_log_cnt > 100)
                {
                    cMELog_F_LogDebug_v("[USS] FireSequece on EMS test");
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
                break;
            }
            case pUS_E_APA_Malfunction:
            {
                sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_Malfunction_at[Uss_ALL_Malfunction_Max2]);

                Uss_ALL_Malfunction_Max2 = (Uss_ALL_Malfunction_Max2 + 1) % Uss_D_Malfunction_Round;

                if (Uss_ALL_Malfunction_Max2 == 0)
                    UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                else
                    UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                if (USS_cycle_log_cnt > 100)
                {
                    cMELog_F_LogDebug_v("[USS] FireSequece on Malfunction");
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
                break;
            }
            case pUS_E_APA_Envelope:
            {
                if (aJobUSSCtrl_v_EnvelopeSendingSnr_u8 == 0
                        || (aJobUSSCtrl_v_EnvelopeProfile_e != pUS_E_PROFILE_A && aJobUSSCtrl_v_EnvelopeProfile_e != pUS_E_PROFILE_B
                                && aJobUSSCtrl_v_EnvelopeProfile_e != pUS_E_PROFILE_C))
                    return rval;
                uint8_t snr = aJobUSSCtrl_v_EnvelopeSendingSnr_u8 - 1;
                pUS_E_ClusterID_t CID = pUS_E_FRONT_ID;
                if (snr >= 6)
                {
                    CID = pUS_E_REAR_ID;
                    snr = snr - 6;
                }
                if (FlexCan_v_EnvBurst_u8 == 0)
                {
                    FlexCan_v_EnvBurst_u8 = 1;
                    if (snr >= 6)
                        snr = snr - 6;
                    Uss_ALL_SndBrtCmd_Envelope_at[snr].ProfileTypeF = aJobUSSCtrl_v_EnvelopeProfile_e;
                    Uss_ALL_SndBrtCmd_Envelope_at[snr].ProfileTypeR = aJobUSSCtrl_v_EnvelopeProfile_e;
/*  \         UssCom_LogD("SnrNum = %d", snr); */
                    sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_Envelope_at[snr]);
                }
                else if (FlexCan_v_EnvBurst_u8 == 1)
                {
                    uint8_t SnrBitMap = 0x1;
                    SnrBitMap = SnrBitMap << snr;
/* \          UssCom_LogD("SnrBitMap = %d", SnrBitMap); */
                    UssMgr_Queue.Buffer[0].Command_e = UssDrv_Req_Output_Signal_Data;
                    UssMgr_Queue.Buffer[0].ClusterID_t = CID;
                    UssMgr_Queue.Buffer[0].SensorBitMap_u8 = SnrBitMap;
                    UssMgr_Queue.Buffer[0].AryIdx = -1;
                    FlexCan_v_EnvBurst_u8 = 2;
                    USSDrv_ReSetQueCmdAccomplished();
                    return rval;
                }
                else
                    return rval;

                if (USS_cycle_log_cnt > 100)
                {
                    cMELog_F_LogDebug_v("[USS] FireSequece on Envelope");
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
                break;
            }
            case pUS_E_APA_CHECKENV:
            {
                sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_ParkFix_at[Uss_ALL_RoundCnt_ParkFix_Max6]);
                /* \ rand to send ALLRcv Mod */
                if (Uss_ALL_RoundCnt_ParkFix_Max6 == 0)
                {
                    PureModPostion = UssCtrl_GetRand((ParkFixRound - 1));
                }
                if (Uss_ALL_RoundCnt_ParkFix_Max6 == PureModPostion)
                {
                    sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ALLRcvFixPath_at[0]);
                    PureModPostion = 0;
                }
                else
                {
                    Uss_ALL_RoundCnt_ParkFix_Max6 = (Uss_ALL_RoundCnt_ParkFix_Max6 + 1) % ParkFixRound;
                }
                if (Uss_ALL_RoundCnt_ParkFix_Max6 == 0)
                    UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                else
                    UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);
                if (USS_cycle_log_cnt > 100)
                {
                    cMELog_F_LogDebug_v("[USS] FireSequece on CHECKENV Fix, Pure at %d ", PureModPostion);
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
                break;
            }
            case pUS_E_APA_BLOCK:
            {
                sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_BlockFix_at[Uss_ALL_RoundCnt_BlockFix_Max2]);
                Uss_ALL_RoundCnt_BlockFix_Max2 = (Uss_ALL_RoundCnt_BlockFix_Max2 + 1) % Uss_D_Block_Fix_Round;

                if (Uss_ALL_RoundCnt_BlockFix_Max2 == 0)
                    UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                else
                    UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                if (USS_cycle_log_cnt > 100)
                {
                    aUSS_D_LogWarning("[USS] FireSequece on BLOCK ");
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
#if  Amazon_Blockage_Algo
                aJobUSOD_f_SensorBlockage();
#else
                aJobUSOD_f_SensorBlock();
#endif
                break;
            }
            default:
            {
                break;
            }
        }
    }

    else
    {
        switch (aJobUSSCtrl_DeGrowlerMod)
        {
            case pUS_E_FU_RD_DEGROWLER:
            {
                sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_GrowlerFtUpRrDown_at[Uss_ALL_RoundCnt_Growler_Max7]);

                /*  rand to send ALLRcv Mod */
                if (Uss_ALL_RoundCnt_Growler_Max7 == 0)
                {
                    PureModPostion = UssCtrl_GetRand((Uss_D_Degrowler_Round - 1));
                }
                if (Uss_ALL_RoundCnt_Growler_Max7 == PureModPostion)
                {
                    sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ChirpRcv_at[0]);
                    PureModPostion = 0;
                    UssMgr_SetRandomSilenceFlag(ME_TRUE);
                }
                else
                {
                    Uss_ALL_RoundCnt_Growler_Max7 = (Uss_ALL_RoundCnt_Growler_Max7 + 1) % Uss_D_Degrowler_Round;
                    UssMgr_SetRandomSilenceFlag(ME_FALSE);
                }

                if (Uss_ALL_RoundCnt_Growler_Max7 == 0)
                    UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                else
                    UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                if (USS_cycle_log_cnt > 100)
                {
                    cMELog_F_LogDebug_v("[USS] FireSequece on Chirp Rear Down Front UP  DeGlower  ");
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
                break;
            }
            case pUS_E_FD_RU_DEGROWLER:
            {
                sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_GrowlerFtDownRrUp_at[Uss_ALL_RoundCnt_Growler_Max7]);

                /*  rand to send ALLRcv Mod */
                if (Uss_ALL_RoundCnt_Growler_Max7 == 0)
                {
                    PureModPostion = UssCtrl_GetRand((Uss_D_Degrowler_Round - 1));
                }
                if (Uss_ALL_RoundCnt_Growler_Max7 == PureModPostion)
                {
                    sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ChirpRcv_at[0]);
                    PureModPostion = 0;
                    UssMgr_SetRandomSilenceFlag(ME_TRUE);
                }
                else
                {
                    Uss_ALL_RoundCnt_Growler_Max7 = (Uss_ALL_RoundCnt_Growler_Max7 + 1) % Uss_D_Degrowler_Round;
                    UssMgr_SetRandomSilenceFlag(ME_FALSE);
                }

                if (Uss_ALL_RoundCnt_Growler_Max7 == 0)
                    UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                else
                    UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                if (USS_cycle_log_cnt > 100)
                {
                    cMELog_F_LogDebug_v("[USS] FireSequece on Chirp Rear UP Front Donw  DeGlower  ");
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
                break;
            }
            case pUS_E_DOWN_DEGROWLER:
            {
                sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_GrowlerDown_at[Uss_ALL_RoundCnt_Growler_Max7]);

                /*/ rand to send ALLRcv Mod */
                if (Uss_ALL_RoundCnt_Growler_Max7 == 0)
                {
                    PureModPostion = UssCtrl_GetRand((Uss_D_Degrowler_Round - 1));
                }
                if (Uss_ALL_RoundCnt_Growler_Max7 == PureModPostion)
                {
                    sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ChirpRcv_at[0]);
                    PureModPostion = 0;
                    UssMgr_SetRandomSilenceFlag(ME_TRUE);
                }
                else
                {
                    Uss_ALL_RoundCnt_Growler_Max7 = (Uss_ALL_RoundCnt_Growler_Max7 + 1) % Uss_D_Degrowler_Round;
                    UssMgr_SetRandomSilenceFlag(ME_FALSE);
                }

                if (Uss_ALL_RoundCnt_Growler_Max7 == 0)
                    UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                else
                    UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                if (USS_cycle_log_cnt > 100)
                {
                    cMELog_F_LogDebug_v("[USS] FireSequece on Chirp All Donw  DeGlower  ");
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
                break;
            }
            case pUS_E_UP_DEGROWLER:
            {
                sndBrtCmd_pt = &(Uss_ALL_SndBrtCmd_GrowlerUp_at[Uss_ALL_RoundCnt_Growler_Max7]);

                /*rand to send ALLRcv Mod */
                if (Uss_ALL_RoundCnt_Growler_Max7 == 0)
                {
                    PureModPostion = UssCtrl_GetRand((Uss_D_Degrowler_Round - 1));
                }
                if (Uss_ALL_RoundCnt_Growler_Max7 == PureModPostion)
                {
                    sndBrtCmd_pt = &(Uss_ALL_17SndBrtCmd_ChirpRcv_at[0]);
                    PureModPostion = 0;
                    UssMgr_SetRandomSilenceFlag(ME_TRUE);
                }
                else
                {
                    Uss_ALL_RoundCnt_Growler_Max7 = (Uss_ALL_RoundCnt_Growler_Max7 + 1) % Uss_D_Degrowler_Round;
                    UssMgr_SetRandomSilenceFlag(ME_FALSE);
                }

                if (Uss_ALL_RoundCnt_Growler_Max7 == 0)
                    UssMgr_SetCycleEndFlags(ME_TRUE, ME_TRUE);
                else
                    UssMgr_SetCycleEndFlags(ME_FALSE, ME_FALSE);

                if (USS_cycle_log_cnt > 100)
                {
                    cMELog_F_LogDebug_v("[USS] FireSequece on Chirp All Up  DeGlower  ");
                    USS_cycle_log_cnt = 0;
                }
                else
                {
                    USS_cycle_log_cnt++;
                }
                break;
            }
            case pUS_E_NO_DEGROWLER:
            default:
            {
                break;
            }

        }
    }

    bool_t isNeedSendBurst = !(aJobUSSMgr_ChkBlock == pUS_E_CHK_NONE && UssCtrl_APAMode == pUS_E_APA_IDLE);

    rval = aUSSCtrl_F_SendBurstCmd_b(SndCluster, sndBrtCmd_pt, isNeedSendBurst);
    if (UssCtrl_APAMode == pUS_E_APA_IDLE)
    {
        aJobUSSCtrl_profileTypeF = pUS_E_PROFILE_A;
        aJobUSSCtrl_profileTypeR = pUS_E_PROFILE_A;
    }
    else
    {
        aJobUSSCtrl_profileTypeF = sndBrtCmd_pt->ProfileTypeF;
        aJobUSSCtrl_profileTypeR = sndBrtCmd_pt->ProfileTypeR;
    }

    return rval;
}

#endif


