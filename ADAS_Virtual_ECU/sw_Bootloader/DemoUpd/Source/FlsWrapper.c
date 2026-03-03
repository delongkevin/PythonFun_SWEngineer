/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file  File:  FlsWrapper.c
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "FlsWrapper.h"

#include "MemIf_Types.h"
 
/**********************************************************************************************************************
 *  DEFINITION + MACROS
 *********************************************************************************************************************/
 
#define FLSWRAPPER_PAGE_SIZE 256

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

unsigned char FlsWrapper_AlignedBuffer[FLSWRAPPER_PAGE_SIZE];

unsigned long FlsWrapper_BytesToIgnore = 0;
unsigned long FlsWrapper_BytesRemaining = 0;
unsigned long FlsWrapper_BytesRead = 0;

unsigned long FlsWrapper_CurrentReadRequest = 0;

unsigned char* FlsWrapper_TargetAddressPtr = 0;

unsigned char FlsWrapper_MisalignedRequestRunning = 0;

/**********************************************************************************************************************
 *  FUNCTION DEFINITIONS
 *********************************************************************************************************************/
 
void FlsWrapper_Cancel(void)
{
  do
  {
    //Fls_MainFunction();
  } while (0/*Fls_GetStatus() == MEMIF_BUSY*/);
}

unsigned char FlsWrapper_Read(unsigned long SourceAddress, unsigned char *TargetAddressPtr, unsigned long Length)
{
  if ( ((SourceAddress % 0x100) != 0x0) ||
       ((Length % 0x100) != 0x0) )
  {
    /* misaligned */
    FlsWrapper_BytesToIgnore = SourceAddress % 0x100; /* ignore first X bytes */
    FlsWrapper_BytesRemaining = Length; /* bytes left to read */
    FlsWrapper_BytesRead = 0; /* bytes already read */
    
    FlsWrapper_CurrentReadRequest = SourceAddress - FlsWrapper_BytesToIgnore; /* page base address of current read request */
    FlsWrapper_TargetAddressPtr = TargetAddressPtr; /* store pointer where the data shall be stored */
    
    FlsWrapper_MisalignedRequestRunning = 1; /* misaligned request */
    
    return 0;//Fls_Read(FlsWrapper_CurrentReadRequest, FlsWrapper_AlignedBuffer, FLSWRAPPER_PAGE_SIZE);
  }
  else
  {
    FlsWrapper_MisalignedRequestRunning = 0; /* normal request */
    
    /* aligned access, forward to FLS */
    return 0;//Fls_Read(SourceAddress, TargetAddressPtr, Length);
  }
}



void JobEndNotificationWrapper(void)
{
  if (1 == FlsWrapper_MisalignedRequestRunning)
  {
	  unsigned long i;
    
    /* estimate boundaries */
	  unsigned long start = FlsWrapper_BytesToIgnore;
	  unsigned long end = FlsWrapper_BytesRemaining > FLSWRAPPER_PAGE_SIZE ? FLSWRAPPER_PAGE_SIZE : FlsWrapper_BytesRemaining;
    
    /* copy into intended upper layer buffer */
    for (i = start; i < end; i++)
    {
      FlsWrapper_TargetAddressPtr[FlsWrapper_BytesRead] = FlsWrapper_AlignedBuffer[i];
      FlsWrapper_BytesRead++;
      FlsWrapper_BytesRemaining--;
    }
    
    
    /* more bytes to copy? */
    if (FlsWrapper_BytesRemaining > 0)
    {
      FlsWrapper_BytesToIgnore = 0; /* we only need to ignore bytes once */
      //FlsWrapper_BytesRemaining = 0; /* already adapted in copy loop */
      //FlsWrapper_BytesRead = 0; /* already adapted in copy loop */
      
      FlsWrapper_CurrentReadRequest += 0x100; /* switch to next page */
      //FlsWrapper_TargetAddressPtr /* no change required */
      
      //FlsWrapper_MisalignedRequestRunning = 0; /* can stay at 1, we want to continue reading */
      
      /* next read request */
      //(void)Fls_Read(FlsWrapper_CurrentReadRequest, FlsWrapper_AlignedBuffer, FLSWRAPPER_PAGE_SIZE);
    }
    else
    {
      /* reset status variables */
      FlsWrapper_BytesToIgnore = 0;
      FlsWrapper_BytesRemaining = 0;
      FlsWrapper_BytesRead = 0;
      
      FlsWrapper_CurrentReadRequest = 0;
      FlsWrapper_TargetAddressPtr = 0;
      
      FlsWrapper_MisalignedRequestRunning = 0; /* go back to normal mode. next read access will determine the required mode */
    }
  }
}

void JobErrorNotificationWrapper(void)
{
  /* reset status variables */
  FlsWrapper_BytesToIgnore = 0;
  FlsWrapper_BytesRemaining = 0;
  FlsWrapper_CurrentReadRequest = 0;
  
  FlsWrapper_TargetAddressPtr = 0;
  FlsWrapper_BytesRead = 0;
  
  FlsWrapper_MisalignedRequestRunning = 0; /* go back to normal mode. next read access will determine the required mode */
}

Fls_Init(void*)
{

}

unsigned char Fls_Erase(unsigned long x, unsigned long y)
{
 return 0;
}

unsigned char Fls_Write(unsigned long x, unsigned long y, unsigned long z)
{
	return 0;
}

unsigned char Fls_Read(unsigned long x, unsigned long y, unsigned long z)
{
	return 0;
}

MemIf_StatusType Fls_GetStatus(void)
{
	return MEMIF_IDLE;
}

void Fls_MainFunction(void)
{

}

MemIf_JobResultType Fls_GetJobResult(void)
{
	return MEMIF_JOB_OK;
}


