/*
 * US_Platform_Global.h
 *
 *  Created on: Feb 26, 2021
 *      Author: e39960
 */

#ifndef SOURCES_US_INCLUDES_US_PLATFORM_GLOBAL_H_
#define SOURCES_US_INCLUDES_US_PLATFORM_GLOBAL_H_

#include <stdio.h>
#include <ti/osal/SemaphoreP.h> 
#include "US_ME_Typedefs_Global.h"
#include "US_FeatureConf.h"
#include "US_PlatformCfg_Global.h"
#if US_D_CUR_PLATFORM == US_D_PLATFORM_AMAZON
 /*  #include "US_UART_Global.h"   Not bothering to include the file at all for Rivian.*/
#endif

#define US_CSM_ENABLE  ME_TRUE


#define US_D_GATHER_RUNTIME_STATS
typedef  SemaphoreP_Handle   US_SemaphoreHandle_t;
#define WAIT_FOREVER       (SemaphoreP_WAIT_FOREVER)
/*
 * Process execution time profiling.
 */
typedef struct US_S_TaskProcTimeStat_s
{
    uint8_t uMinTime;
    uint8_t uLastTime;
    uint8_t uMaxTime;
} US_S_TaskProcTimeStat_t;


typedef struct US_S_DebugTimerStat_s
{
    uint32_t uMinTime;
    uint32_t uLastTime;
    uint32_t uMaxTime;
    uint32_t uSavedTime;
    uint32_t uSavedCount;
    uint32_t uSaveDeltaTime;
    uint32_t uSaveMaxTime;
    uint32_t uUpdateCount;
} US_S_DebugTimerStat_t;

typedef struct UssMgr_TaskProcTimes_s
{
    US_S_TaskProcTimeStat_t sProcTime_CanTask       ;
    US_S_TaskProcTimeStat_t sProcTime_UssMgrTask    ;
    US_S_TaskProcTimeStat_t sProcTime_USOD          ;
    US_S_TaskProcTimeStat_t sProcTime_Ctrl          ;
    US_S_TaskProcTimeStat_t sProcTime_SnrMeasTime   ;
    US_S_TaskProcTimeStat_t sProcTime_Drv;
    US_S_TaskProcTimeStat_t sProcTime_SnrFireTime   ;
} US_TaskProcTimes_t;

#if(QAC_WARNING_FIX == ME_FALSE)
extern void US_SnrDrvCom_INTB_ISR(void);
extern void US_SnrDrvCom_DSI3_ISR(void);
#endif
extern bool_t US_SemaphoreLock( US_SemaphoreHandle_t Semaphore );
extern void US_SemaphoreUnlock( US_SemaphoreHandle_t Semaphore );
extern US_SemaphoreHandle_t US_SemaphoreCreate(uint32_t);
extern uint16_t US_DSI3Drv_triggerDmaSpiTxRx(uint8_t nDev,uint8_t *snd_buffer,uint8_t *rcv_buffer,uint32_t size);
extern void US_System_Init(void);
extern uint32_t US_GetTimeStampTimeMs(void);
extern void UssMgr_SetSnrMeasTime(uint32_t uDeltaTime);
extern void US_Sleep(uint32_t nMs);
extern bool_t US_TakeSnrDataSemaphore(void);
extern void US_GiveSnrDataSemaphore(void);
extern uint64_t get_usec_timestamp(void);
extern uint8_t *GetSoftwareVersion(void);
extern uint16_t US_DSI3Drv_init(void);
extern void ME_LED_Lighting(void);
extern uint16_t US_can_tx_packet(uint32_t can_id, uint8_t len, uint8_t *data);
US_TaskProcTimes_t * US_psGetTaskProcTimes(void);
extern void US_UpdateProcTimeStats(US_S_TaskProcTimeStat_t *psProcTimeStat, uint32_t uStartTimestamp);
extern void US_ResetMaxProcTime(US_S_TaskProcTimeStat_t *psProcTimeStat);
void US_SemaphorePost( US_SemaphoreHandle_t Semaphore,uint8_t FromISR );
bool_t US_SemaphorePend( US_SemaphoreHandle_t Semaphore, uint32_t WaitTime );

#ifdef US_D_GATHER_RUNTIME_STATS
extern uint32_t US_GetTimeStampTimeUS(void);
void US_DbgTimerReset(US_S_DebugTimerStat_t *psTimerData);
void US_DbgTimerUpdate(US_S_DebugTimerStat_t *psTimerData);
void US_DbgTimerSaveStartTime(US_S_DebugTimerStat_t *psTimerData);
#endif
#define UssCom_LogD(...)    
#endif /* SOURCES_US_INCLUDES_US_PLATFORM_GLOBAL_H_ */

