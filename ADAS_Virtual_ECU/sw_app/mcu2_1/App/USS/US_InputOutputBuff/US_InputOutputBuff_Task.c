
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0781, 0857 EOF */ /* MD_Rte_0777, MD_Rte_0779, MD_Rte_0781, MD_MSR_1.1_857 */
/* Kernel includes. */
#include "US_InputOutputBuff_Task.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_Platform_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SysMgr_Global.h"
#include "US_SnrCmd_Global.h"
#include "US_Stub.h"
#include "US_Odometry_Global.h"
#include "US_PlatformCfg_Global.h"

/* AUTOSAR 3.x compatibility */
#if !defined (STATIC)
# define STATIC static
#endif


#ifndef FALSE
#define FALSE (0U)
#endif
#ifndef TRUE
#define TRUE (1U)
#endif

#ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
    #define US_D_DEBUG_2_X_BUFFER_NAME  UssCom_sOutputBufferCopy
#if(QAC_WARNING_FIX == ME_FALSE)
    #define XDEBUG_NUM_CAN_MSGS         5u
#endif
    #define XDEBUG_STARTING_POINT_ID    48u //56u //64u
    #define XDEBUG_DIRECT_POINT_ID      48u
    #define XDEBUG_SENSOR_STARTING_ID   56u
    #define XDEBUG_ENDING_POINT_ID      95u

    extern US_S_ClusterBurstCmd_t * psGetSendBurstCfg(void);
    extern US_E_EchoType_t UssDBG_EchoType[US_D_MAX_NUM_SENSORS];
	extern US_S_RingTime_t    UssDBGRing_Buffer[US_D_MAX_NUM_SENSORS];
    extern uint8_t g_UssDbg_InterpTempIndex;
    extern uint8_t g_UssDbg_InterpChosenBin10x;
    extern uint8_t g_UssDbg_InterpBinError;
	extern uint8_t g_uArcsFromFeature[SIX];

#endif

#if 0
    extern uint16_t UssDBG_Deleted2ndEcho_Dist[US_D_MAX_NUM_SENSORS];
    extern uint16_t UssDBG_Deleted2ndEcho_Str[US_D_MAX_NUM_SENSORS];
    extern float32_t g_fBackgroundNoiseLevel;
    extern US_E_NoiseLevel_t UssDBG_RearNoiseLevel;
    extern uint8_t UssDBG_RearStateNoisyTimeDiff50;
    extern uint16_t uUssDBG_ModeInitCnt;
    extern uint16_t UssDBG_ChirpFilteredEchos_Cnt;
    extern uint8_t uSuppressCounter[US_D_PHYS_GRP_MAX];
    extern uint16_t uTravelKillCounter;
    extern sint16_t siLastKill_X;
    extern sint16_t siAccuKill_X;
	extern uint8_t uDBG_NumGrpPoints;
    extern uint8_t uDBG_ListPtIdx;
    extern uint8_t uDBG_InPtIdx;
    extern uint8_t uDBG_DeleteReason;
    extern uint8_t uDbgCapConfFlag;
    extern uint8_t eSpecialMode2_SubMode;
    extern uint8_t UssDBG_aDGESO_Str[US_D_MAX_NUM_SENSORS];
    extern uint8_t UssDBG_FrontNoiseTypeCnt[2];
    extern uint8_t UssDBG_RearNoiseTypeCnt[2];
    extern uint8_t UssDBG_US_E_NoiseType[US_D_MAX_NUM_SENSORS];
    extern uint8_t UssDBG_preFiltDebug[US_D_MAX_NUM_SENSORS][THREE];
    extern uint8_t UssMgr_uNewMitTypeConfirmations[US_D_PHYS_GRP_MAX];
    extern uint32_t UssDBG_usedFaultMap;
    extern uint8_t  UssDBG_GuessChoice[US_D_MAX_NUM_SENSORS];
    extern US_S_ClusterBurstCmd_t UssDBG_SendBurstCfgUsed;
    extern uint16_t UssDBG_NumListenEchoes;
    extern uint16_t UssDBG_aCFE_Cnt[US_D_MAX_NUM_SENSORS];
    extern uint8_t uaUssMgr_CRNFD_PassCounter[US_D_MAX_NUM_SENSORS];
    extern uint8_t uaUssMgr_CRNFD_RingHistory[US_D_MAX_NUM_SENSORS][FIVE];
    extern uint8_t g_UssDbg_ReInitEntrance;
    extern uint8_t UssDBG_NoiseLevel[6];
    extern uint8_t UssDBG_UnsureCnt[6];
    extern bool_t b_NoiseDNNActive[TWO];
    extern uint8_t g_UssDbg_InterpRunCounter;
    extern uint8_t g_UssDbg_InterpSkippedCounter;
    extern US_S_DebugTimerStat_t g_UssDbg_BlockageDNN_TimeStats;
    extern US_S_DebugTimerStat_t g_UssDbg_DNN_TimeStats;
    extern US_S_DebugTimerStat_t g_UssDbg_MgrTask_TimeStats;
    extern US_S_DebugTimerStat_t g_UssDbg_ODTask_TimeStats;
    extern  float32_t g_f_mu_last;
#endif

/* Pole extractor signals */
extern  float32_t g_fSigmaY_rear;
extern  float32_t g_fSigmaY_front;
extern  float32_t g_f_sigma_sq_last;
extern  uint8_t   g_uGeomStats_PoleDecision[3][US_D_PHYS_GRP_MAX];
extern  uint8_t   g_uGeomStats_PoleDBGFlag[3][US_D_PHYS_GRP_MAX];
extern  float32_t g_DEBUG_fPointDistToBumper_sigma[US_D_PHYS_GRP_MAX];
extern  float32_t g_PrevSigma[US_D_PHYS_GRP_MAX];

/* Debug counters for Checking the values during crash, checkpoints the dynamic cal reading functionality */
extern  uint16_t  UssDynAdj_STC_DoAdjustCntr;
extern  uint16_t  UssDynAdj_STG_DoAdjustCntr;
extern  uint16_t  UssDynAdj_ProfileA_DoAdjustCntr;
extern  uint16_t  UssCtrl_TriggerSnrCfgCntr1;
extern  uint16_t  UssCtrl_CheckForSnrCalChangeCntr;

/* Checklist for giving the final binary */
extern boolean KeAP_b_HeightFlagEnabled;
extern uint8 KeAP_b_EnVehStandstillArcBlip;
extern uint8 KeAP_b_CruisAgeBasedGhsObjDet;

static bool_t bUSS_Data_Copied = ME_FALSE;
static volatile US_SemaphoreHandle_t UssCom_sOutputBuffSemaphore;

uint8_t * UssMgr_uGetBlockCntArray(void);
uint8_t * UssMgr_uGetBlockClrCntArray(void);
void US_InputOutputBuff_Task( void );
extern void ComInput_Init(void);

#ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
static void InjectDebugData(void);
static void InjectDebugData_2B(void);
static void InjectDebugData_32(void);
volatile uint8_t g_LaudCANDebugVer =0x2B;
#endif


/* ===========================================================================
 * Name:	 US_InputOutputBuff_Init
 * Remarks:  DD-ID: {99FAD18D-5915-4fee-8932-6BEFA075938F}
 * Req.-ID: 13396023
 * ===========================================================================*/
void US_InputOutputBuff_Init(void)
{
  (void)memset(&UssCom_sOutputBuffer,(int)ZERO,sizeof(UssCom_sOutputBuffer));    
 (void)memset(&UssCom_sOutputBufferCopy,(int)ZERO,sizeof(UssCom_sOutputBufferCopy));   
  UssCom_sOutputBuffSemaphore = US_SemaphoreCreate(ONE);
  ComInput_Init(); 
#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS))
  ME_US_F_RegisterDataCopyCallBackInput();
#endif
}
/* ===========================================================================
 * Name:	 UssCom_F_Get_OutDataCopiedFlag
 * Remarks:  DD-ID: {E3C926CB-00C7-4f2a-B8FC-88D29CBB4F8D}
 * Req.-ID: 
 * ===========================================================================*/
bool_t UssCom_F_Get_OutDataCopiedFlag(void)
{
	return bUSS_Data_Copied;
}
/* ===========================================================================
 * Name:	 UssCom_F_Clr_OutDataCopiedFlag
 * Remarks:  DD-ID: {B063479E-A6A6-49fc-BA37-56912086B44C}
 * Req.-ID: 
 * ===========================================================================*/
void UssCom_F_Clr_OutDataCopiedFlag(void)
{
	bUSS_Data_Copied = ME_FALSE;
}
/**********************************************************************************************************************
 * Comm Task function
 *********************************************************************************************************************/



/* ===========================================================================
 * Name:	 US_InputOutputBuff_Task
 * Remarks:  DD-ID: {FEE6EE72-8639-4494-884A-5384A7A5EBB3}
 * Req.-ID:14959893
 * Req.-ID:16134127
 * ===========================================================================*/
/*just keeping the variables global: as stack overrun possible vehicle is 2K*/
void US_InputOutputBuff_Task(void)
{
    uint32_t uFuncStartTime;
    if(UssMgr_eGetSysState() != SYSMGR_SYS_INIT)
    {
      uFuncStartTime = US_GetTimeStampTimeMs();

        /* COM output data double buffer */
        if (UssCom_LockOutputDataBuffer() == (bool_t)ME_TRUE)
        {
            UssCom_F_PopulateDebugMsg();
			/* Perform quick copy and unlock the semaphore */
            (void)memcpy(&UssCom_sOutputBufferCopy,&UssCom_sOutputBuffer,sizeof(UssCom_sOutputBuffer));
			bUSS_Data_Copied = ME_TRUE;
            
#ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
            InjectDebugData();
#endif
            UssCom_UnlockOutputDataBuffer();
        }
      
      /*Function for scheduling the periodic events for sharing the data*/
      UssCom_F_OutputDataShareMain();
      UssCom_F_InputDataShareMain();
      US_SnrCfg_F_Cali_task();
      
      US_UpdateProcTimeStats(&US_psGetTaskProcTimes()->sProcTime_CanTask, uFuncStartTime);
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/* ===========================================================================
 * Name:	 UssCom_LockOutputDataBuffer
 * Remarks:  DD-ID: {64D6DC98-F709-4693-A3A7-CE7F6F58D7BB}
 * Req.-ID: 13424090
 * ===========================================================================*/
bool_t UssCom_LockOutputDataBuffer(void)
{
    bool_t bRet = US_SemaphoreLock(UssCom_sOutputBuffSemaphore);
    return bRet;
}

/* ===========================================================================
 * Name:	 UssCom_UnlockOutputDataBuffer
 * Remarks:  DD-ID: {63A1ADDF-5DF8-41c2-A78B-6CE6F1B60C12}
 * Req.-ID: 13424090
 * ===========================================================================*/
void UssCom_UnlockOutputDataBuffer(void)
{
	US_SemaphoreUnlock(UssCom_sOutputBuffSemaphore);
}

#ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
/* Internal function */
/* ===========================================================================
 * Name:	 InjectDebugData_32
 * Remarks:  DD-ID: {7D5314D7-7572-4dba-98E0-4513BC64F59B}
 
 * ===========================================================================*/
static void InjectDebugData_32(void)
{
    uint8_t         sensor_index,  sensor_point_id;
    const US_S_SensorMeasRecs_t * psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();  
    const US_S_SensorMeasDist_t * psSnrMeasDist = UssMgr_psGetCurSnrMeasRecDist();          
        
    /* DEBUGGG 2.x START */
    /* cycle through sensors and add to appropriate debug for sensor data */
    for(sensor_index = ZERO; sensor_index < US_D_MAX_NUM_SENSORS; sensor_index++)
    {
        /* each sensor takes THREE point IDs */
        sensor_point_id = sensor_index * 3U;
        /* 1st echo dist - even number ID     */           
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + sensor_point_id)].x = psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[ZERO]; 
        /* 1st echo str - even number IDs */
        if( psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[ZERO] < 0 )
        {
            US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + sensor_point_id)].y = (((sint16_t)psSnrMeasRec->sSensorRec[sensor_index].sEcho[ZERO].uEchoHeight) * -1);
        }
        else
        {
            US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + sensor_point_id)].y = (sint16_t)psSnrMeasRec->sSensorRec[sensor_index].sEcho[ZERO].uEchoHeight;
        }
        /* 1st echo width */
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + sensor_point_id)].age = (uint8_t) (psSnrMeasRec->sSensorRec[sensor_index].sEcho[ZERO].uWidth/10u);
        /* 1st echo confidence */
        
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + sensor_point_id)].Cruising_Age = psSnrMeasRec->sSensorRec[sensor_index].sEcho[ZERO].uConf;


        /* 2nd echo dist - odd number IDs */
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 1u))].x = psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[ONE];
        /* 2nd echo str - odd number IDs */
        if( psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[ONE] < 0 )
        {
            US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 1u))].y = (((sint16_t)psSnrMeasRec->sSensorRec[sensor_index].sEcho[ONE].uEchoHeight) * -1);
        }
        else
        {
            US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 1u))].y = (sint16_t)psSnrMeasRec->sSensorRec[sensor_index].sEcho[ONE].uEchoHeight;
        }
        /* 2nd echo width */
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 1u))].age = (uint8_t) (psSnrMeasRec->sSensorRec[sensor_index].sEcho[ONE].uWidth/10u);
        /* 2nd echo confidence   */     
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 1u))].Cruising_Age = psSnrMeasRec->sSensorRec[sensor_index].sEcho[ONE].uConf; 
        
        
        /* 3rd echo dist */
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 2u))].x = psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[TWO];
        /* 3rd echo strength */
        if( psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[TWO] < 0 )
        {
            US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 2u))].y = (((sint16_t)psSnrMeasRec->sSensorRec[sensor_index].sEcho[TWO].uEchoHeight) * -1);
        }
        else
        {
            US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 2u))].y = (sint16_t)psSnrMeasRec->sSensorRec[sensor_index].sEcho[TWO].uEchoHeight;
        }
        /* 3rd echo width */
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 2u))].age = (uint8_t)(psSnrMeasRec->sSensorRec[sensor_index].sEcho[TWO].uWidth/10u);
        /* 3d echo confidence */
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_SENSOR_STARTING_ID + (sensor_point_id + 2u))].Cruising_Age = psSnrMeasRec->sSensorRec[sensor_index].sEcho[TWO].uConf;

        /* filtered direct echoes for potmap, use both x/y to fit 12 sensor on 6 signal groups */
        if((sensor_index % 2u) == 0u)
        {
            /*1st echo dist, to x */
            if (UssDBG_Buffer.u1stEchoDirDist[sensor_index] == ZERO)
            {
                US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_STARTING_POINT_ID + (sensor_index/2u))].x = ( ((sint16_t)UssDBG_Buffer.u1stEchoTotalDist[sensor_index]) * -1);
            }
            else
            {
                US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_STARTING_POINT_ID + (sensor_index/2u))].x = (sint16_t)UssDBG_Buffer.u1stEchoTotalDist[sensor_index];
            }
            /* to y */
            if (UssDBG_Buffer.u1stEchoDirDist[sensor_index + 1u] == ZERO)
            {
                US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_STARTING_POINT_ID + (sensor_index/2u))].y = ( ((sint16_t)UssDBG_Buffer.u1stEchoTotalDist[sensor_index + 1u]) * -1);
            }
            else
            {
                US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_STARTING_POINT_ID + (sensor_index/2u))].y = (sint16_t)UssDBG_Buffer.u1stEchoTotalDist[sensor_index + 1u];
            }
            /* other info */
            }
    }

    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[89].x = (sint16_t)g_fSigmaY_rear;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[89].y = (sint16_t)g_uGeomStats_PoleDBGFlag[0][US_D_PHYS_GRP_REAR];
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[73].height = (uint8_t)g_uGeomStats_PoleDecision[0][US_D_PHYS_GRP_REAR]+1u; //center
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[74].height = (uint8_t)g_uGeomStats_PoleDecision[1][US_D_PHYS_GRP_REAR]+1u; //left
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[75].height = (uint8_t)g_uGeomStats_PoleDecision[2][US_D_PHYS_GRP_REAR]+1u; //right
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[91].y = (uint16_t)g_DEBUG_fPointDistToBumper_sigma[US_D_PHYS_GRP_REAR];
    /* Pole Extractor Debug Signals Front */
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[90].x = (sint16_t)g_fSigmaY_front;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[90].y = (sint16_t)g_uGeomStats_PoleDBGFlag[0][US_D_PHYS_GRP_FRNT];
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[76].height =(uint8_t) g_uGeomStats_PoleDecision[0][US_D_PHYS_GRP_FRNT]+1u; //center
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[77].height =(uint8_t) g_uGeomStats_PoleDecision[1][US_D_PHYS_GRP_FRNT]+1u; //left
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[78].height = (uint8_t)g_uGeomStats_PoleDecision[2][US_D_PHYS_GRP_FRNT]+1u; //right
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[91].x = (uint16_t)g_DEBUG_fPointDistToBumper_sigma[US_D_PHYS_GRP_FRNT];

    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[58].x = (sint16_t)g_PrevSigma[US_D_PHYS_GRP_FRNT];
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[58].y = (sint16_t)g_PrevSigma[US_D_PHYS_GRP_REAR];
    
	/* Check DNN Output */
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[87].height = USSMgr_Height_GetUnfilteredHeightFlag(US_D_PHYS_GRP_REAR);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[90].height = USSMgr_Height_GetFilteredHeightFlag(US_D_PHYS_GRP_REAR);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[89].height = USSMgr_Height_GetHeightClass(US_D_PHYS_GRP_REAR);
    
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[93].height = USSMgr_Height_GetUnfilteredHeightFlag(US_D_PHYS_GRP_FRNT);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[94].height = USSMgr_Height_GetFilteredHeightFlag(US_D_PHYS_GRP_FRNT);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[95].height = USSMgr_Height_GetHeightClass(US_D_PHYS_GRP_FRNT);

     /* wall debug */
    #ifdef US_D_MGR_WALL_HIGH_FLAGS
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[55].y = (sint16_t)(UssMgr_uGetWallFlagsByGroup(US_D_PHYS_GRP_REAR) | (UssMgr_uGetWallFlagsByGroup(US_D_PHYS_GRP_FRNT) << 8u));
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[65].height = UssMgr_bGetWallGuessbyBumper(US_D_PHYS_GRP_FRNT);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[66].height = UssMgr_bGetWallGuessbyBumper(US_D_PHYS_GRP_REAR);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[67].height = UssMgr_bGetWallGuessbyBumper_Persist(US_D_PHYS_GRP_FRNT);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[68].height = UssMgr_bGetWallGuessbyBumper_Persist(US_D_PHYS_GRP_REAR);
    #endif
    /*Blockage */
    #if BLOCKAGE_NN
    for(sensor_index = ZERO; sensor_index < US_D_MAX_NUM_SENSORS/2u; sensor_index++)
    {        
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[49u+sensor_index].height = USSMgr_BlockageGetDbgVar(BLOCKAGE_FILTERED_FLAG, sensor_index);        
    }
    for(sensor_index = US_D_MAX_NUM_SENSORS/2u; sensor_index < US_D_MAX_NUM_SENSORS; sensor_index++)
    {
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[81u+sensor_index-(US_D_MAX_NUM_SENSORS/2u)].height = USSMgr_BlockageGetDbgVar(BLOCKAGE_FILTERED_FLAG, sensor_index);        
    } 
    #endif

    /* Debug counters for Checking the values during crash, checkpoints the dynamic cal reading functionality */
	US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[48].x = (sint16_t)UssDynAdj_STC_DoAdjustCntr;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[48].y = (sint16_t)UssDynAdj_STG_DoAdjustCntr;
	US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[49].x = (sint16_t)UssDynAdj_ProfileA_DoAdjustCntr;
	US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[49].y = (sint16_t)UssCtrl_TriggerSnrCfgCntr1;
	US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[50].x = (sint16_t)UssCtrl_CheckForSnrCalChangeCntr;
}

/* ===========================================================================
 * Name:	 InjectDebugData_2B
 * Remarks:  
 * Req.-ID:
 * ===========================================================================*/
static void InjectDebugData_2B(void)
{
    uint8_t         sensor_index, sensor_point_id;
    /*uint8_t tmp;
    US_S_Sensor_Temperature_t * psTemperatures = UssSnrCmd_psGetSnrTemperatures();*/
    const US_S_SensorMeasRecs_t * psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();  
    const US_S_SensorMeasDist_t * psSnrMeasDist = UssMgr_psGetCurSnrMeasRecDist();              

    for(sensor_index = ZERO; sensor_index < US_D_MAX_NUM_SENSORS; sensor_index++)
    {                
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_STARTING_POINT_ID + (sensor_index))].x = (sint16_t)UssDBGRing_Buffer[sensor_index].uRingTime;
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_STARTING_POINT_ID + (sensor_index))].y = (sint16_t)UssDBGRing_Buffer[sensor_index].uRingFreq;
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_STARTING_POINT_ID + (sensor_index))].age = (uint8_t)(UssDBGRing_Buffer[sensor_index].uDrvFreq/572u);
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(XDEBUG_STARTING_POINT_ID + (sensor_index))].Cruising_Age = (uint8_t)UssDBG_EchoType[sensor_index]; 
    }
    /* cycle through sensors and add to appropriate debug for sensor data */
    for(sensor_index = ZERO; sensor_index < US_D_MAX_NUM_SENSORS; sensor_index++)
    {
        /* each sensor takes ONE point IDs */
        sensor_point_id = sensor_index;
        /* 1st echo dist - even number IDs */
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(72u + sensor_point_id)].x = psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[ZERO]; 
        /* 1st echo str - even number IDs */
        if( psSnrMeasDist->asSensorRecDist[sensor_index].aiEchoTotalDist[ZERO] < 0 )
        {
            US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(72u + sensor_point_id)].y = (((sint16_t)(psSnrMeasRec->sSensorRec[sensor_index].sEcho[ZERO].uEchoHeight) * -1));
        }
        else
        {
            US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(72u + sensor_point_id)].y = (sint16_t)(psSnrMeasRec->sSensorRec[sensor_index].sEcho[ZERO].uEchoHeight);
        }        
        
        /* 1st echo confidence */
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[(72u + sensor_point_id)].Cruising_Age = psSnrMeasRec->sSensorRec[sensor_index].sEcho[ZERO].uConf;      
    }
 
    uint8_t * puBlockCntArray =  UssMgr_uGetBlockCntArray();
    uint8_t * puBlockClrCntArray = UssMgr_uGetBlockClrCntArray();
    for(sensor_index = 0; sensor_index < US_D_MAX_NUM_SENSORS; sensor_index++)
    {               
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[60u+ (sensor_index)].age =  puBlockCntArray[sensor_index];
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[60u+ (sensor_index)].Cruising_Age  =  puBlockClrCntArray[sensor_index];
    }
}

/* ===========================================================================
 * Name:	 InjectDebugData
 * Remarks:  DD-ID: {C9960D81-7E6F-4fe0-9782-CD63E52CF90C}
 * Req.-ID:
 * ===========================================================================*/
static void InjectDebugData(void)
{
    static uint16_t pause_counter = 0;
    static uint16_t u40ms_counter = 0;    
    static uint32_t cal_version32 = 0x12345678;    
    uint8_t         debug_index ;
    
 #if   (US_D_ENABLE_EXT_ODOM_DEBUG == ME_TRUE)
    UssOdo_DebugOutput_t * odom_debug;
#endif

    /* DEBUGGG 2.x START */
    
    pause_counter++;
    /* Checklist for giving the final binary */
	#if(US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS)/* DT CVADAS Platform */
	#if((KeAP_b_HeightFlagEnabled==1)&&(KeAP_b_EnVehStandstillArcBlip==1)&&(KeAP_b_CruisAgeBasedGhsObjDet==1))/* Ghost Filter Enabled */
	{
		#error "Ghost Filter Enabled"
	}
	#endif
	#if(US_D_MIN_SENSOR_FIXED_RANGE == 10)/* False Arc fix should be 20 */
	{
		#error "False arc need to be fixed"
	}
	#endif
	#if(g_LAUD_MWH_Enable == ME_TRUE)/* Wall Extractor Check*/
    {
		#error "Wall Extractor Enabled"
	}
	#endif
	#if(US_D_HEIGHT_ALGO_TYPE_TO_USE!=HEIGHT_ALGO_RNN)/* DNN vs ML checkup*/
    {
		#error "DNN not updated"
	}
	#endif
    #if(g_LAUD_ForceFrontNoisy) /* Check Force Noise mode */
    {
		#error "Enable Force Noise for front for DT CVADAS"
	}
	#endif
	#endif
    if((pause_counter % 4) == 0u)
    {
        u40ms_counter++;
    }
    if(0x400u < pause_counter) //~10sec pause  (1024 * 10ms)
    {
        cal_version32 = US_SnrCfg_F_Get_CaliVer(); //horrible while loop lookup in here
        pause_counter = ZERO;
    }
#ifndef XDEBUG_ONLY_STATUS_MSG 
    switch(g_LaudCANDebugVer) 
    {  
        case 0x32:
            InjectDebugData_32();
            break;
        case 0x2B:
            InjectDebugData_2B();
            break;
        default:
			InjectDebugData_32();
            break;
    }

    /* SW version number */
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[59].height = 0x02; //2bits
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[60].height = 0x01; //2bits
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[61].height = 0x00; //2bits
    /* USS sw debug */
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[92].x = (sint16_t)cal_version32;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[92].y = (sint16_t)(cal_version32 >> 16);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[92].Cruising_Age = g_LaudCANDebugVer; //DEBUG LAYOUT VER    
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[93].Cruising_Age = (uint8_t)UssMgr_eGetGrpState(US_D_PHYS_GRP_FRNT);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[94].Cruising_Age = (uint8_t)UssMgr_eGetGrpState(US_D_PHYS_GRP_REAR);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[95].Cruising_Age = (uint8_t)UssMgr_eGetSysState();
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[92].age = US_psGetTaskProcTimes()->sProcTime_SnrFireTime.uLastTime;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[93].age = US_psGetTaskProcTimes()->sProcTime_SnrMeasTime.uLastTime;
    
#if (US_D_ENABLE_EXT_ODOM_DEBUG == ME_TRUE)
    odom_debug = UssOdo_psGetOdoDebug();
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[93].x = (sint16_t)odom_debug->fAccuX;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[93].y = (sint16_t)odom_debug->fAccuY;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[94].x = (sint16_t)(odom_debug->fAngleAvg * 50.0f); //0.02deg scale
#endif 
    /* cfg details */
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[94].age = (uint8_t)uUsed_Cal_Data_Set; //global from US_SnrCfg.c
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[92].height = UssCom_F_GetReCfgAllowFlag();    
    /* cfg interp */
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[95].age = g_UssDbg_InterpBinError;
   
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[58].height = g_UssDbg_InterpTempIndex;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[94].y = (sint16_t)g_UssDbg_InterpChosenBin10x;

	/* Check DNN Output */
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[87].height = USSMgr_Height_GetUnfilteredHeightFlag(US_D_PHYS_GRP_REAR);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[90].height = USSMgr_Height_GetFilteredHeightFlag(US_D_PHYS_GRP_REAR);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[89].height = USSMgr_Height_GetHeightClass(US_D_PHYS_GRP_REAR);
    
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[93].height = USSMgr_Height_GetUnfilteredHeightFlag(US_D_PHYS_GRP_FRNT);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[94].height = USSMgr_Height_GetFilteredHeightFlag(US_D_PHYS_GRP_FRNT);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[95].height = USSMgr_Height_GetHeightClass(US_D_PHYS_GRP_FRNT);

    
    
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[62].height = g_uArcsFromFeature[0];
	US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[63].height = g_uArcsFromFeature[1];
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[69].height = g_uArcsFromFeature[2];
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[70].height = g_uArcsFromFeature[3];
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[71].height = g_uArcsFromFeature[4];
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[91].height = g_uArcsFromFeature[5];			   
    

    /* Sensor firing info */
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[54].x = (sint16_t)(UssDBG_Buffer.uSendingSensors & 0xFFFFu);
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[54].y = (sint16_t)((US_D_DEBUG_2_X_BUFFER_NAME.sFiringSensors.timestamp) & 0xFFFFu);
    
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[54].Cruising_Age = (uint8_t)UssMgr_uGetCurParkingMode();
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[55].age =           (psGetSendBurstCfg()->Cfg[USSCOM_BUMPLOC_FRONT].EchoInfo) + 1u;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[55].Cruising_Age =  (psGetSendBurstCfg()->Cfg[USSCOM_BUMPLOC_REAR].EchoInfo) + 1u;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[54].age = (uint8_t)(UssCom_F_GetAmbientTemp() + 20.0f);

    /* wall debug */
    #ifdef US_D_MGR_WALL_HIGH_FLAGS
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[55].y = (sint16_t)(UssMgr_uGetWallFlagsByGroup(US_D_PHYS_GRP_REAR) | (UssMgr_uGetWallFlagsByGroup(US_D_PHYS_GRP_FRNT) << 8u));
    #endif
    /* wall debug */
    #endif

#if (XDEBUG_STARTING_POINT_ID < 64u)
    //msg sync counters - first cruising age from each msg
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[40].height = (uint8_t)u40ms_counter; //XDEBUG_STARTING_POINT_ID
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[48].height = (uint8_t)u40ms_counter; //XDEBUG_STARTING_POINT_ID
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[56].height = (uint8_t)u40ms_counter; //XDEBUG_STARTING_POINT_ID
#endif 
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[64].height = (uint8_t)u40ms_counter; //XDEBUG_SENSOR_STARTING_ID
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[72].height = (uint8_t)u40ms_counter;
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[80].height = (uint8_t)u40ms_counter;
//  XDEBUG_ONLY_STATUS_MSG 
    US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[88].height = (uint8_t)u40ms_counter;

    

    //zero all confidence to PA doesn't use these points
    for(debug_index = XDEBUG_STARTING_POINT_ID; debug_index < (XDEBUG_ENDING_POINT_ID + 1u); debug_index++)
    {
        US_D_DEBUG_2_X_BUFFER_NAME.sPointMapOutputBuff.pointMap[debug_index].confidence = ZERO;
    }
}
#endif /* #ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X */


