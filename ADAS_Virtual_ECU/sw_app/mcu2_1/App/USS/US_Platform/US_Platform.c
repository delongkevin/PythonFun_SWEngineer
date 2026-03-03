/*
 * US_F_Wrapper.c
 *
 *  Created on: Feb 26, 2021
 *      Author: e39960
 */
#include <ti/osal/TimerP.h>
#include <ti/osal/TaskP.h>

#include "US_ME_Typedefs_Global.h"
#include "US_SnrDrv_Global.h" 
#include "US_Platform_Global.h"
#include "US_Diagnostic_Global.h"

/**                       Year,Week,Day,build   */
static uint8_t SWRev[] = {8u,25u,46u,5u,0u,0u,0u,0u,0u}; 
/**
 * \brief   Get Software version
 */
#if(QAC_WARNING_FIX == ME_FALSE)
uint32_t US_GetTimeStampTimeUS(void);
#endif
/* ===========================================================================
 * Name:	 GetSoftwareVersion
 * Remarks:  DD-ID: {F25EEBF5-44EC-47d1-8EFF-4BD47282F91D}
 * ===========================================================================*/

uint8_t *GetSoftwareVersion(void)
{
   return (uint8_t*)SWRev;
}
void LED_output(uint32_t value);
/* ===========================================================================
 * Name:	 ME_LED_Lighting
 * Remarks:  DD-ID: {EEA2C589-22DB-4730-9CC6-05D2392B00BA}
 * ===========================================================================*/
void ME_LED_Lighting(void)
{

#if(1)
 static uint8_t ledout = 0u,led_count = 0u;
 // LED will flash 7 times after boot up, if in SW development mode.
 if((uint8_t)(led_count % 10u) == 0u)
  {
	ledout = (uint8_t)(!ledout); /* PRQA S 4116, 4558 */
	LED_output(ledout);
  }
  if(led_count < ((uint8_t)0xFF))
  {
   led_count++;
  }
  else{
   led_count = ZERO; /* Overflow error handling */
  }
#endif
}
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================*/
/**Port_E_ISR1.
* used to process command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SnrDrvCom_INTB_ISR
 * Remarks:  DD-ID: {3CCDFFB9-6029-4f67-8726-170CB87D7A82}
 * ===========================================================================*/
void US_SnrDrvCom_INTB_ISR(void)
{
	

}

/* ===========================================================================*/
/**Port_E_ISR1.
* used to process command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SnrDrvCom_DSI3_ISR
 * Remarks:  DD-ID: {A2F164F2-E46F-4928-B6D8-3896F34AE369}
 * ===========================================================================*/
void US_SnrDrvCom_DSI3_ISR(void)
{

}
#endif

/* ===========================================================================*/
/**US_SemaphoreCreate.
* Wrap SemaphoreCreate.
* \param none
* \return Sempahore Handle
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SemaphoreCreate
 * Remarks:  DD-ID: {EC2C994A-E33C-4c09-A799-A81EE214A654}
 * ===========================================================================*/
US_SemaphoreHandle_t US_SemaphoreCreate(uint32_t type)
{
       US_SemaphoreHandle_t Semaphore =NULL;
       SemaphoreP_Params   sem_params;
       SemaphoreP_Params_init(&sem_params);
       sem_params.mode = SemaphoreP_Mode_BINARY;
	   type = (type>ZERO)?ONE:ZERO;
	   Semaphore = SemaphoreP_create(type,&sem_params);
	   return Semaphore;
}

/* ===========================================================================*/
/**US_SemaphorePend.
* Wrap SemaphoreLock.
* \param Sempahore Handle
* \return true if it is successful to lock semaphore,else false
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name: US_SemaphorePend     
 * Remarks:  DD-ID: {21783307-F56B-4f0f-A260-4F1C1640078D}
 * ===========================================================================*/
bool_t US_SemaphorePend( US_SemaphoreHandle_t Semaphore, uint32_t WaitTime )
{
   bool_t ret = ME_FALSE;
   if(Semaphore != NULL)
    {
     if( SemaphoreP_pend(Semaphore, WaitTime) == SemaphoreP_OK )
 	 {
	 	ret = ME_TRUE;
  	 }
    else
    {
      ;/* No Action */
    }
   }
   else
   {
      ;/* No Action */
   }
   return ret;
}
/* ===========================================================================*/
/**US_SemaphorePost.
* Wrap SemaphoreLock.
* \param Sempahore Handle
* \return true if it is successful to lock semaphore,else false
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name: US_SemaphorePost     
 * Remarks:  DD-ID: {92DFC20A-FA24-4214-93DD-D74174DB582F}
 * ===========================================================================*/
void US_SemaphorePost( US_SemaphoreHandle_t Semaphore, uint8_t FromISR )
{
  (void)FromISR;
   if(Semaphore != NULL)
   {
        (void)SemaphoreP_post(Semaphore);
  }
  else
  {
   ;/* No Action */
  }
 
}

/* ===========================================================================*/
/**US_SemaphoreUnlock.
* Wrap SemaphoreLock.
* \param none
* \return Sempahore Handle
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_SemaphoreLock
 * Remarks:  DD-ID: {1416B911-F89A-4b53-B3D8-8106752AA625}
 * ===========================================================================*/

bool_t US_SemaphoreLock( US_SemaphoreHandle_t Semaphore )
{
   bool_t ret = ME_FALSE;
   if(Semaphore != NULL)
   {
     if( SemaphoreP_pend(Semaphore, SemaphoreP_NO_WAIT) == SemaphoreP_OK )
     {
	     ret = ME_TRUE;
     }
     else
     {
      ;/* No Action */
     }
   }
   else
   {
      ;/* No Action */
   }
   return ret;
}
/* ===========================================================================*/
/**US_SemaphoreUnlock.
* Wrap SemaphoreLock.
* \param none
* \return Sempahore Handle
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_SemaphoreUnlock
 * Remarks:  DD-ID: {49F73101-D096-4b10-BF89-63EA5A72909E}
 * ===========================================================================*/
void US_SemaphoreUnlock( US_SemaphoreHandle_t Semaphore )
{
     if(Semaphore != NULL)
     {
       (void)SemaphoreP_post(Semaphore);
     }
     else
     {
      ;/* No Action */
     }
}


/* ===========================================================================*/
/**US_CheckDSI3Ready.
* used to Check if DSI3 is ready.
* \param None
* \return True if ready
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_GetTimeStampTimeMs
 * Remarks:  DD-ID: {99EB75F8-33C9-49d9-B99E-CD2EBD7D0363}
 * ===========================================================================*/
uint32_t US_GetTimeStampTimeMs(void)
{
   uint32_t timestamp = 0;
    timestamp = (uint32_t)((TimerP_getTimeInUsecs()/1000U)& 0xffffffffu);
  
   return timestamp;
}
/* JWR3 I'm going to use this soon #if(QAC_WARNING_FIX == ME_FALSE) */
/* ===========================================================================
 * Name:	US_GetTimeStampTimeUS
 * Remarks:  DD-ID:{04962667-B31B-4e74-9FC9-650A0942C883}
 * ===========================================================================*/
uint32_t US_GetTimeStampTimeUS(void)
{
   uint32_t timestamp = 0;
    timestamp = (uint32_t)((TimerP_getTimeInUsecs()) & 0xffffffffu);
  
   return timestamp;
}
/* for QAC macro #endif */
/* ===========================================================================*/
/**USS_System_Init.
* used to Initialize USS system.
* \param None
* \return True if ready
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_System_Init
 * Remarks:  DD-ID: {7F5B7EAD-DC80-47d3-9F3D-9D3B2295E5B9}
 * Traceability to source Code: Req.-ID: 16134166
 * ===========================================================================*/

void US_System_Init(void)
{
	uint16_t status;
     status = US_DSI3Drv_init();
    if(status != ME_OK)
	{
        US_Diagnostic_SetECUFlag((US_E_ECUFaultReason_t)status);
   }	
   else
   {
      ;/* No Action */
   }
}

/* ===========================================================================*/
/**US_Sleep.
* used to wrap task sleep.
* \param sleep ms
* \return void
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_Sleep
 * Remarks:  DD-ID: {1D10245D-18CA-41be-B176-65C5FA203DDA}
 * ===========================================================================*/
void US_Sleep(uint32_t nMs)
{
	TaskP_sleep(nMs);	
}
