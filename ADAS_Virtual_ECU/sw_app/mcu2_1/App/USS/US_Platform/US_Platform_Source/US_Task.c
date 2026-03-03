/*
 * US_Task.c
 *
 *  Created on: Aug 9, 2021
 *      Author: jonapais
 */

/*PRQA S 3408 EOF */
#include "US_ME_Typedefs_Global.h"
#include "US_SysMgr_Global.h"
#include "US_Ctrl_Global.h"
#include "US_Platform_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_SnrDrv_Global.h" 
#include "US_ObjDet_Global.h"
#include "US_Hsd_Global.h"
#include "US_MgrHeightAlgoRNN.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#endif
/* Function execution time profiling structure */
static US_TaskProcTimes_t US_sTaskProcTimes;
static void US_InitProcTimeStat(void);
#ifdef US_D_GATHER_RUNTIME_STATS
US_S_DebugTimerStat_t g_UssDbg_DrvTask_TimeStats;
US_S_DebugTimerStat_t g_UssDbg_MgrTask_TimeStats;
US_S_DebugTimerStat_t g_UssDbg_ODTask_TimeStats;
US_S_DebugTimerStat_t g_UssDbg_CtrlTask_TimeStats;
US_S_DebugTimerStat_t g_UssDbg_InitTask_TimeStats;
US_S_DebugTimerStat_t g_UssDbg_10msTask_TimeStats;
US_S_DebugTimerStat_t g_UssDbg_DNN_TimeStats;
US_S_DebugTimerStat_t g_UssDbg_BlockageDNN_TimeStats;

uint8_t g_LAUD_TimeStats_ForceReset = 0x00;
#endif
#if(US_CSM_ENABLE == ME_TRUE)

extern void UsCsm_Init(void);
extern void UsCsm_MainFunction(void);
#endif

extern void UsDsi3Trcv_MainFunction(void);
extern void US_StubOuput_Init(void);
void US_SystemInit(void);
void UsDsi3Trcv_RequestState(uint8_t state);
uint16_t US_SnrCfg_F_GetCalData(uint16_t ReTrival);
/*===========================================================================
 * \brief Sensor Driver Layer Cyclic Task entry
 * \param none
 * \param none
 * \return
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name: US_DrvTask    
 * Remarks:  DD-ID: {72B6D0EF-BD68-4ab2-8075-87C6DC9CF122} 
 * ===========================================================================*/
void US_DrvTask(void)
{
   //comment out int32_t uFuncStartTime = US_GetTimeStampTimeMs();
	if(UssMgr_eGetSysState() != SYSMGR_SYS_INIT)
	{
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerSaveStartTime(&g_UssDbg_DrvTask_TimeStats);
#endif

		US_SnrDrvCom_F_Task();
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerUpdate(&g_UssDbg_DrvTask_TimeStats);
#endif
	}
	else
	{
	}
   // comment out US_UpdateProcTimeStats(&US_psGetTaskProcTimes()->sProcTime_Drv, uFuncStartTime);

  //comment out   UsDsi3Trcv_MainFunction();
}

/*===========================================================================
 * \brief Manager and OD Application Layer Cyclic Task entry
 * \param none
 * \param none
 * \return
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name: US_MgrAndODTask    
 * Remarks:  DD-ID: {8DF6E2BA-D9E0-489c-9064-B1492660D6B9}
 * ===========================================================================*/
void US_MgrAndODTask(void)
{
    uint32_t uFuncStartTime = 0;
	if(UssMgr_eGetSysState() != SYSMGR_SYS_INIT)
	{
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerSaveStartTime(&g_UssDbg_MgrTask_TimeStats);
#endif

		/* Execute Manager processing */
		uFuncStartTime = US_GetTimeStampTimeMs();

		UssMgr_Main();

		US_UpdateProcTimeStats(&US_psGetTaskProcTimes()->sProcTime_UssMgrTask, uFuncStartTime);
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerUpdate(&g_UssDbg_MgrTask_TimeStats);
#endif
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerSaveStartTime(&g_UssDbg_ODTask_TimeStats);
#endif
		/* Execute Object Detection processing */
		uFuncStartTime = US_GetTimeStampTimeMs();

		UssOD_Main();

		US_UpdateProcTimeStats(&US_psGetTaskProcTimes()->sProcTime_USOD, uFuncStartTime);
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerUpdate(&g_UssDbg_ODTask_TimeStats);
#endif
	}
	else
	{
	}
}

/*===========================================================================
 * \brief Controller Cyclic Task entry
 * \param none
 * \param none
 * \return
 * \remarks none
 * ==========================================================================
 */
/* ===========================================================================
 * Name: US_ControllerTask    
 * Remarks:  DD-ID: {48A1C26A-5C31-41fa-B287-CA39722AE094}
 * ===========================================================================*/
void US_ControllerTask(void)
{
    uint32_t uFuncStartTime = 0;
	uint16_t uGetCalData = (uint16_t)0;
	uint8_t uCheckOnStatus = (uint8_t)0;
	uint8_t uTransResetState = (uint8_t)0;
#ifdef US_D_GATHER_RUNTIME_STATS
    US_DbgTimerSaveStartTime(&g_UssDbg_10msTask_TimeStats);
#endif
#if(US_CSM_ENABLE == ME_TRUE)
    UsCsm_MainFunction();
#endif
	/* JWR3: Using Mgr main state in controller without having mgr change the state
	 * does not make any sense...
	 * These states are also not used anywhere except here and driver
	 * would make more sense to have controller unique init/cfg states 
	 * while Mgr (and other parts of the system) stay in "Init" if not
	 * then the entire SW needs to check all three of these states */
    UssMgr_e_SysState_t SysState;
	SysState = UssMgr_eGetSysState();

	if(SysState == SYSMGR_SYS_INIT)
	{
#ifdef US_D_GATHER_RUNTIME_STATS
            US_DbgTimerReset(&g_UssDbg_InitTask_TimeStats);
            US_DbgTimerSaveStartTime(&g_UssDbg_InitTask_TimeStats);
#endif
		US_SystemInit();
	}
	else if(SysState ==  SYSMGR_SYS_INIT_CALIDATA)
	{
		uGetCalData = US_SnrCfg_F_GetCalData((uint16_t)ME_TRUE);
		if(uGetCalData == ((uint16_t)ME_OK))
		{
			UssMgr_SetSysState(SYSMGR_SYS_POWERON);
		}
	}
	else if(SysState ==  SYSMGR_SYS_POWERON)
	{
		uCheckOnStatus = UssHsd_F_CheckOnStatus();
         if(uCheckOnStatus == (uint8_t)ME_TRUE)
		 {
			   UssMgr_SetSysState(SYSMGR_SYS_CFGTRCVR);
			   US_SnrDrv_Start_DSI3Transceiver_Reset();
 		 }
	}
	else if(SysState ==  SYSMGR_SYS_CFGTRCVR)
	{
		uTransResetState = US_SnrDrv_Check_TransceiverResetState();
         if(uTransResetState == (uint8_t)ME_FALSE)
		 {
			   UssMgr_SetSysState(SYSMGR_SYS_CONFIG);
			   UssCtrl_TriggerSnrCfg();
 		 }
#ifdef US_D_GATHER_RUNTIME_STATS
            US_DbgTimerUpdate(&g_UssDbg_InitTask_TimeStats);
#endif
	}
	else
	{
		/*
		* *************** ULTRASONIC CONTROLLER MODULE ****************
		*/
		uFuncStartTime = US_GetTimeStampTimeMs();
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerSaveStartTime(&g_UssDbg_CtrlTask_TimeStats);
#endif

		(void) UssCtrl_Main();

		US_UpdateProcTimeStats(&US_psGetTaskProcTimes()->sProcTime_Ctrl, uFuncStartTime);
#ifdef US_D_GATHER_RUNTIME_STATS
        US_DbgTimerUpdate(&g_UssDbg_CtrlTask_TimeStats);
#endif
	}
 }

/*===========================================================================
 * \brief USS system initialization.
 * \param none
 * \param none
 * \return
 * \remarks Sets Current system state (UssMgr_e_SysState_t)
 * ==========================================================================
 */
void US_InputOutputBuff_Init(void);
void US_Diagnostic_Init(void);
void UssSnrCmd_Init();          /*PRQA S 3001*/
/* ===========================================================================
 * Traceability to source Code: Req.-ID: 13396023
 * ===========================================================================*/
/* ===========================================================================
 * Name: US_SystemInit    
 * Remarks:  DD-ID: {AF84BFB3-DAB4-433c-86CD-033D3C273F13}
 * ===========================================================================*/
void US_SystemInit(void)
{
#if(US_CSM_ENABLE == ME_TRUE)
	UsCsm_Init();
#endif
    
    UssMgr_SetSysState(SYSMGR_SYS_INIT);
    /* Perform system initialization */
	US_StubOuput_Init();
    US_Diagnostic_Init();
    US_System_Init();
    (void)US_SnrDrvCom_F_Init();
	UssSnrCmd_Init();
    US_InputOutputBuff_Init();
    UssMgr_ManagerInit();
    UssCtrl_MainInit();
    UssOD_Init();
    US_InitProcTimeStat();
	(void)US_SnrCfg_F_Init();
    (void)US_SnrCfg_Calib_F_Init();
 
  	//comment out UssHsd_F_SetOnOffRequest(Uss_Hsd_Channel_PWR_A,SetOnOffRequest_ON);
    //comment out UssHsd_F_SetOnOffRequest(Uss_Hsd_Channel_PWR_B,SetOnOffRequest_ON);
    UssMgr_SetSysState(SYSMGR_SYS_INIT_CALIDATA);
 

 }
/*Req.-ID: 13396023
 */
/* ===========================================================================
 * Name: US_psGetTaskProcTimes    
 * Remarks:  DD-ID: {32D04992-FD69-4113-A933-0180A452A250}
 * ===========================================================================*/
US_TaskProcTimes_t * US_psGetTaskProcTimes(void)
{
    return &US_sTaskProcTimes;
}
/*Req.-ID: 13396023
 *
 */
/* ===========================================================================
 * Name: US_InitProcTimeStat    
 * Remarks:  DD-ID: {9C3C924B-1A50-44fb-8945-6BD39B271014}
 * ===========================================================================*/
static void US_InitProcTimeStat(void)
{
    US_sTaskProcTimes.sProcTime_CanTask.uMaxTime = ZERO;
    US_sTaskProcTimes.sProcTime_CanTask.uLastTime = ZERO;
    US_sTaskProcTimes.sProcTime_CanTask.uMinTime = 0xFFu;

    US_sTaskProcTimes.sProcTime_Ctrl.uMaxTime = ZERO;
    US_sTaskProcTimes.sProcTime_Ctrl.uLastTime = ZERO;
    US_sTaskProcTimes.sProcTime_Ctrl.uMinTime = 0xFFu;

    US_sTaskProcTimes.sProcTime_Drv.uMaxTime = ZERO;
    US_sTaskProcTimes.sProcTime_Drv.uLastTime = ZERO;
    US_sTaskProcTimes.sProcTime_Drv.uMinTime = 0xFFu;

    US_sTaskProcTimes.sProcTime_SnrMeasTime.uMaxTime = ZERO;
    US_sTaskProcTimes.sProcTime_SnrMeasTime.uLastTime = ZERO;
    US_sTaskProcTimes.sProcTime_SnrMeasTime.uMinTime = 0xFFu;

    US_sTaskProcTimes.sProcTime_USOD.uMaxTime = ZERO;
    US_sTaskProcTimes.sProcTime_USOD.uLastTime = ZERO;
    US_sTaskProcTimes.sProcTime_USOD.uMinTime = 0xFFu;

    US_sTaskProcTimes.sProcTime_UssMgrTask.uMaxTime = ZERO;
    US_sTaskProcTimes.sProcTime_UssMgrTask.uLastTime = ZERO;
    US_sTaskProcTimes.sProcTime_UssMgrTask.uMinTime = 0xFFu;

    US_sTaskProcTimes.sProcTime_SnrFireTime.uMaxTime = ZERO;
    US_sTaskProcTimes.sProcTime_SnrFireTime.uLastTime = ZERO;
    US_sTaskProcTimes.sProcTime_SnrFireTime.uMinTime = 0xFFu;
    #ifdef US_D_GATHER_RUNTIME_STATS
    US_DbgTimerReset(&g_UssDbg_DrvTask_TimeStats);
    US_DbgTimerReset(&g_UssDbg_MgrTask_TimeStats);
    US_DbgTimerReset(&g_UssDbg_ODTask_TimeStats);
    US_DbgTimerReset(&g_UssDbg_CtrlTask_TimeStats);
    US_DbgTimerReset(&g_UssDbg_10msTask_TimeStats);
    US_DbgTimerReset(&g_UssDbg_DNN_TimeStats);
    US_DbgTimerReset(&g_UssDbg_BlockageDNN_TimeStats);
    #endif
}

/* ===========================================================================
 * Name: US_UpdateProcTimeStats    
 * Remarks:  DD-ID: {E9C8476B-9EF9-42b1-A52E-731D0AB55D80}
 * ===========================================================================*/
void US_UpdateProcTimeStats(US_S_TaskProcTimeStat_t *psProcTimeStat, uint32_t uStartTimestamp)
{
    uint32_t uCurTimestamp = US_GetTimeStampTimeMs();
    uint32_t uDeltaTime = uCurTimestamp - uStartTimestamp;

    if (uDeltaTime > 0xFFu)
    {
        uDeltaTime = 0xFFu;
    }

    psProcTimeStat->uLastTime = (uint8_t)uDeltaTime;

    if( (UssMgr_eGetSysState() == SYSMGR_SYS_READY)
       || (UssMgr_eGetSysState() == SYSMGR_SYS_DIAGNOSTIC) ) /* PRQA S 3415 */
    {

        if (uDeltaTime > psProcTimeStat->uMaxTime)
        {
            psProcTimeStat->uMaxTime = (uint8_t)uDeltaTime;
        }

        if (uDeltaTime < psProcTimeStat->uMinTime)
        {
            psProcTimeStat->uMinTime = (uint8_t)uDeltaTime;
        }
    }
}
/* ===========================================================================
 * Name: US_ResetMaxProcTime    
 * Remarks:  DD-ID: {03258835-0B08-47a5-8CEB-2B3CCC7B4BF2}
 * ===========================================================================*/
void US_ResetMaxProcTime(US_S_TaskProcTimeStat_t *psProcTimeStat)
{
    psProcTimeStat->uMaxTime = ZERO;
}
#ifdef US_D_GATHER_RUNTIME_STATS
/* ===========================================================================
 * Name: US_DbgTimerSaveStartTime	
 * Remarks:  DD-ID: {37B336B2-4A75-484f-8EB7-A406678C1F06}
 * ===========================================================================*/
void US_DbgTimerSaveStartTime(US_S_DebugTimerStat_t *psTimerData)
{
    uint32_t uCurTimestamp = US_GetTimeStampTimeUS();
    uint32_t uDeltaTime = uCurTimestamp - psTimerData->uSavedTime;
    psTimerData->uSaveDeltaTime = uDeltaTime;
    psTimerData->uSavedTime = uCurTimestamp;
    psTimerData->uSavedCount++;
    if (uDeltaTime > psTimerData->uSaveMaxTime)
    {
        psTimerData->uSaveMaxTime = uDeltaTime;
    }
}
void US_DbgTimerUpdate(US_S_DebugTimerStat_t *psTimerData)
{
    uint32_t uCurTimestamp = US_GetTimeStampTimeUS();
    uint32_t uDeltaTime = uCurTimestamp - psTimerData->uSavedTime;
    psTimerData->uLastTime = uDeltaTime;
    psTimerData->uUpdateCount++;
    if (uDeltaTime > psTimerData->uMaxTime)
    {
        psTimerData->uMaxTime = uDeltaTime;
    }
    if (uDeltaTime < psTimerData->uMinTime)
    {
        psTimerData->uMinTime = uDeltaTime;
    }
    if (g_LAUD_TimeStats_ForceReset != 0x00)
    {
        US_DbgTimerReset(psTimerData);
    }
}
void US_DbgTimerReset(US_S_DebugTimerStat_t *psTimerData)
{
    psTimerData->uMaxTime = ZERO;
    psTimerData->uMinTime = UINT32_MAX;
    psTimerData->uLastTime = ZERO;
    psTimerData->uSavedCount = ZERO;
    psTimerData->uSavedTime = US_GetTimeStampTimeUS();
    psTimerData->uSaveDeltaTime = ZERO;
    psTimerData->uSaveMaxTime = ZERO;
    psTimerData->uUpdateCount = ZERO;
}
#endif /* #ifdef US_D_GATHER_RUNTIME_STATS */
