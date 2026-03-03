/* OSAL */
#include <ti/osal/osal.h>
#include <ti/osal/MutexP.h>
#include <ti/osal/SemaphoreP.h>
#include <ti/osal/TaskP.h>
#include <ti/osal/MailboxP.h>

#include <ti/drv/ipc/ipc.h>
#include "string.h"
#if 0
#include "app_log.h"
#endif
#include "TimeManagerProxyTypes.h"
#include "SignalDef.h"

#define START_ASILB_CODE_SECTION
#include "asil_memmap.h"

#define START_ASILB_DATA_SECTION
#include "asil_memmap.h"

#define START_ASILB_BSS_SECTION
#include "asil_memmap.h"

#define START_ASILB_CONST_SECTION
#include "asil_memmap.h"

/* 25ms -> 25000 us*/
#define APP_LOG_TIMEDELTA_MAX 25000u

/* 25ms -> 25000000 ns*/
#define STBM_TIMEDELTA_MAX 25000000u

/* 5ms -> 5000000 ns*/
#define CURR_TIMEDELTA_MIN 5000000u
/* 15ms -> 15000000 ns*/
#define CURR_TIMEDELTA_MAX 25000000u

volatile uint64_t TimeManagerProxy_currSyncedTime = 0u, TimeManagerProxy_prvSyncedTime = 0;
bool currSyncedTimeValid = false;

typedef struct{
  uint64_t prvAppLogTimeStamp;
  uint64_t prvStbMTimeStamp;
  uint64_t appLogDeltaTime;
  uint64_t min_appLogDeltaTime;
  uint64_t max_appLogDeltaTime;
  uint64_t StbMDeltaTime;
  uint64_t min_StbMDeltaTime;
  uint64_t max_StbMDeltaTime;
  uint64_t TimeSynctaskDeltaTime;
  uint64_t min_TimeSynctaskDeltaTime;
  uint64_t max_TimeSynctaskDeltaTime;
  uint64_t appLogTimeLocalCurr; // local applog time means reading GTC timer on core the proxy is running on
  uint64_t appLogTimeLocalPrv;
  uint64_t appLogTimeLocalDelta;
  uint64_t appLogTimeLocalDelta_Max;
} Time_PlausibilityCheck_Struct;

volatile Time_PlausibilityCheck_Struct Time_PlausibilityCheck_Obj = {0u};
volatile uint32_t Time_PlausibilityCheck_errorCounter[3] = {0u};

// check if the prev time stamp is larger than new, if it is, there is a issue
volatile uint32_t Time_PlausibilityCheck_SanityCounter[3] = {0u};

static void TimeManagerProxy_PlausibilityCheck(uint64_t newStbMTimeStamp, uint64_t newApplogTimeStamp)
{
  /* DD-ID: {498296E8-0727-4860-8656-AD5D12675D41}*/
    #if(1)
  /* VCAST Jenkins requirement - do not modify */
  /* VCAST Jenkins requirement - do not modify */
  if ( ((uint64_t)0 != Time_PlausibilityCheck_Obj.prvAppLogTimeStamp) && ((uint64_t)0 != Time_PlausibilityCheck_Obj.prvStbMTimeStamp) )
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
  {
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if ( newApplogTimeStamp >= Time_PlausibilityCheck_Obj.prvAppLogTimeStamp )
    {
        Time_PlausibilityCheck_Obj.appLogDeltaTime = newApplogTimeStamp - Time_PlausibilityCheck_Obj.prvAppLogTimeStamp;
    }
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    else if ( newApplogTimeStamp < Time_PlausibilityCheck_Obj.prvAppLogTimeStamp )
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        Time_PlausibilityCheck_SanityCounter[0]++;
    }

    if ( Time_PlausibilityCheck_Obj.appLogDeltaTime > Time_PlausibilityCheck_Obj.max_appLogDeltaTime ){
        Time_PlausibilityCheck_Obj.max_appLogDeltaTime = Time_PlausibilityCheck_Obj.appLogDeltaTime;
    }

    if ( Time_PlausibilityCheck_Obj.appLogDeltaTime < Time_PlausibilityCheck_Obj.min_appLogDeltaTime ){
        Time_PlausibilityCheck_Obj.min_appLogDeltaTime = Time_PlausibilityCheck_Obj.appLogDeltaTime;
    }
   // applogTimeDelta = (float32)(Time_PlausibilityCheck_Obj.appLogDeltaTime/1000.0);

    if ( newStbMTimeStamp >= Time_PlausibilityCheck_Obj.prvStbMTimeStamp )
    {
        Time_PlausibilityCheck_Obj.StbMDeltaTime = newStbMTimeStamp - Time_PlausibilityCheck_Obj.prvStbMTimeStamp;
    }
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    else if ( newStbMTimeStamp < Time_PlausibilityCheck_Obj.prvStbMTimeStamp  )
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        Time_PlausibilityCheck_SanityCounter[1]++;
    }

    if ( Time_PlausibilityCheck_Obj.StbMDeltaTime > Time_PlausibilityCheck_Obj.max_StbMDeltaTime ){
        Time_PlausibilityCheck_Obj.max_StbMDeltaTime = Time_PlausibilityCheck_Obj.StbMDeltaTime;
    }

    if ( Time_PlausibilityCheck_Obj.StbMDeltaTime < Time_PlausibilityCheck_Obj.min_StbMDeltaTime ){
        Time_PlausibilityCheck_Obj.min_StbMDeltaTime = Time_PlausibilityCheck_Obj.StbMDeltaTime;
    }
    //stbmTimeDelta = (float32)(Time_PlausibilityCheck_Obj.StbMDeltaTime/1000000.0);

    /* check to see if the time delta of the two time stamps is ok */

    if ( Time_PlausibilityCheck_Obj.appLogDeltaTime > APP_LOG_TIMEDELTA_MAX )
    {
        Time_PlausibilityCheck_errorCounter[0u]++;
    }
    if ( Time_PlausibilityCheck_Obj.StbMDeltaTime > STBM_TIMEDELTA_MAX )
    {
        Time_PlausibilityCheck_errorCounter[1u]++;
    }
  }

  Time_PlausibilityCheck_Obj.prvAppLogTimeStamp = newApplogTimeStamp;
  Time_PlausibilityCheck_Obj.prvStbMTimeStamp = newStbMTimeStamp; 
  #endif

  if ( 0u != TimeManagerProxy_prvSyncedTime )
  {
    if ( TimeManagerProxy_currSyncedTime >= TimeManagerProxy_prvSyncedTime )
    {
        Time_PlausibilityCheck_Obj.TimeSynctaskDeltaTime = TimeManagerProxy_currSyncedTime - TimeManagerProxy_prvSyncedTime;
        if ( Time_PlausibilityCheck_Obj.TimeSynctaskDeltaTime > Time_PlausibilityCheck_Obj.max_TimeSynctaskDeltaTime )
        {
            Time_PlausibilityCheck_Obj.max_TimeSynctaskDeltaTime = Time_PlausibilityCheck_Obj.TimeSynctaskDeltaTime;
        }
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if ( (Time_PlausibilityCheck_Obj.TimeSynctaskDeltaTime < CURR_TIMEDELTA_MIN) || (Time_PlausibilityCheck_Obj.TimeSynctaskDeltaTime > CURR_TIMEDELTA_MAX) )
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
            Time_PlausibilityCheck_errorCounter[2u]++;
        }
    }

    if ( TimeManagerProxy_currSyncedTime < TimeManagerProxy_prvSyncedTime  )
    {
        Time_PlausibilityCheck_SanityCounter[2]++;
    }
  }
#if 0
  Time_PlausibilityCheck_Obj.appLogTimeLocalCurr = appLogGetGlobalTimeInUsec();
#endif
  if ( Time_PlausibilityCheck_Obj.appLogTimeLocalPrv != 0 )
  {
    Time_PlausibilityCheck_Obj.appLogTimeLocalDelta = Time_PlausibilityCheck_Obj.appLogTimeLocalCurr - Time_PlausibilityCheck_Obj.appLogTimeLocalPrv;

    if ( Time_PlausibilityCheck_Obj.appLogTimeLocalDelta_Max < Time_PlausibilityCheck_Obj.appLogTimeLocalDelta)
    {
        Time_PlausibilityCheck_Obj.appLogTimeLocalDelta_Max = Time_PlausibilityCheck_Obj.appLogTimeLocalDelta;
    }
  }

  Time_PlausibilityCheck_Obj.appLogTimeLocalPrv = Time_PlausibilityCheck_Obj.appLogTimeLocalCurr;
}

// TODO: Should this be in a critical section since this is non atomic?
static void TimeManagerProxy_ProcessTimeStampData(TimeManagerProxy_TimeStamp_t* currTimeStamp)
{
  /* DD-ID: {EA0EA99C-C0F4-4139-9982-B8E7EF2F75C2}*/
#if 0 
    TimeManagerProxy_currSyncedTime = currTimeStamp->StbmTimeStamp + 1000*( appLogGetGlobalTimeInUsec() - currTimeStamp->appLogTimeStamp );
#endif
    TimeManagerProxy_PlausibilityCheck(currTimeStamp->StbmTimeStamp, currTimeStamp->appLogTimeStamp);
    currSyncedTimeValid = true;

    TimeManagerProxy_prvSyncedTime = TimeManagerProxy_currSyncedTime;
}

void TimeManagerProxy_InitEndPoint()
{
  /* DD-ID: {5FD7C80B-FD50-43f4-90C3-6FE550A8AB64}*/
}

void TimeManagerProxy_MainFunction(void)
{
  /* DD-ID: {3C6241CE-AB09-4b24-8BC3-5482EA84D82A}*/
    TimeManagerProxy_TimeStamp_t remoteTimeStamp;
    SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(&remoteTimeStamp);  
    TimeManagerProxy_ProcessTimeStampData(&remoteTimeStamp);
}

uint64_t TimeManagerProxy_GetCurrSyncedTime(void)
{
  /* DD-ID: {FCA034AD-6125-4eb4-AD83-A74A07E66143}*/
    uint64_t currtimeStmap = 0u;
    TimeManagerProxy_TimeStamp_t remoteTimeStamp;
    if ( true == currSyncedTimeValid )
    {

        SigMgr_Data_TimeManagerProxy_TimeStamp_t_Get(&remoteTimeStamp);        
#if 0        
        currtimeStmap = (uint64_t)(remoteTimeStamp.StbmTimeStamp + 1000*( appLogGetGlobalTimeInUsec() - remoteTimeStamp.appLogTimeStamp ));
#endif        
    }
    else 
    {
        currtimeStmap = (uint64_t)0;
    }

    return currtimeStmap;
}

uint64_t TimeManagerProxy_CalcCurrSyncedTime(uint64_t stbmTimeStamp, uint64_t appLogTimeStamp)
{
  /* DD-ID: {83097904-C2A6-4bce-A397-D6BD4A458CA3}*/
    uint64_t calculatedTimeStamp = 0u;
#if 0     
    //calculatedTimeStamp = (uint64_t)(stbmTimeStamp+ 1000*( appLogGetGlobalTimeInUsec() - appLogTimeStamp ));
#endif
    return calculatedTimeStamp;
}
#define STOP_ASILB_CODE_SECTION
#include "asil_memmap.h"

#define STOP_ASILB_DATA_SECTION
#include "asil_memmap.h"

#define STOP_ASILB_BSS_SECTION
#include "asil_memmap.h"

#define STOP_ASILB_CONST_SECTION
#include "asil_memmap.h"

