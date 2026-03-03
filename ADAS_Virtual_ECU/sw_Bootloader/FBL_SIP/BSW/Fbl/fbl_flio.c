/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Flash Driver wrapper functions using an Autosar Fls driver
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2018-08-15  vistbe  -                Initial version
 *  01.01.00   2020-08-12  visrie  FBL-1953         Add support for downloadable driver
 *  01.02.00   2022-01-21  visjdn  FBL-4535         Support secondary/tertiary use-case
 *                                                  Added/adapted MemMap sections
 **********************************************************************************************************************/

#define FBL_FLIO_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "fbl_flio.h"
#include "fbl_flio_cfg.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if (FBLWRAPPERFLASH_ASRFLSHIS_VERSION         != 0x0102u) || \
    (FBLWRAPPERFLASH_ASRFLSHIS_RELEASE_VERSION != 0x00u)
# error "Error in fbl_flio.c: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/** Flash driver state handling */
typedef enum
{
   kFlashInitState_Uninit = 0u,  /**< Flash driver has not be initialized yet */
   kFlashInitState_ReadDriver,   /**< Read-only flash driver is active/initialized */
   kFlashInitState_FullDriver    /**< Full flash driver (read, write and erase) is active/initialized */
} tFlashInitState;

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLFLIO_FLASHCODE_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 flashCode[FLASH_SIZE];
#define FBLFLIO_FLASHCODE_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FBLFLIO_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/** Current initialization state of the flash driver */
V_MEMRAM0 static V_MEMRAM1 tFlashInitState V_MEMRAM2 initState;
#define FBLFLIO_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLFLIO_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

static IO_ErrorType FlashDriver_PollFls( void );

/***********************************************************************************************************************
 *   LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FlashDriver_PollFls
 **********************************************************************************************************************/
/*! \brief       Executes operation and polls the status
 *  \details     Calls the Fls main function and polls the status of the flash operation
 *  \pre         Flash driver/Fls is initialized, operation has been started
 *  \return      IO_E_OK in case of success, otherwise IO_E_NOT_OK
 **********************************************************************************************************************/
static IO_ErrorType FlashDriver_PollFls( void )
{
   IO_ErrorType returnValue;
   tFlashUint32 i;

   returnValue = IO_E_NOT_OK;
   i = 0u;

   while (FBL_FLASHFLS_GETSTATUS() == MEMIF_BUSY)
   {
      /* Poll the watchdog frequently */ /* PRQA S 2991, 2995 1 */ /* MD_FblWrapperFlash_2991_2995 */
      if ((i & (FBL_FLASHFLS_WD_POLLING_INTERVAL - 1u)) == 0x00u)
      {
         FblLookForWatchdogVoid();
      }
      i++;
      FBL_FLASHFLS_MAINFUNCTION();
   }

   if (FBL_FLASHFLS_GETJOBRESULT() == MEMIF_JOB_OK)
   {
      returnValue = IO_E_OK;
   }

   return returnValue;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FlashDriver_InitPowerOnSync
 **********************************************************************************************************************/
/*! \brief       Initialize modules variables and read-only driver
 *  \return      The return code shows the success of the initialization
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_InitPowerOnSync(void)
{
   IO_ErrorType returnValue;

   initState = kFlashInitState_Uninit;
   returnValue = IO_E_NOT_OK;

   FBL_FLASHFLS_INITMEMORY();
   FBL_FLASHFLS_INIT();

   if (FBL_FLASHFLS_GETJOBRESULT() == MEMIF_JOB_OK)
   {
      initState = kFlashInitState_ReadDriver;
      returnValue = IO_E_OK;
   }

   return returnValue;
}

/***********************************************************************************************************************
 *  FlashDriver_InitSync
 **********************************************************************************************************************/
/*! \brief       Initializes the flash driver
 *  \details     Initializes the Fls module
 *  \pre         None
 *  \param[in]   *address Unused parameter to implement HIS interface
 *  \return      IO_E_OK in case of success, otherwise IO_E_NOT_OK
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
IO_ErrorType FlashDriver_InitSync( void* address )
{
   IO_ErrorType returnValue;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)address;
#endif

   /* Verify if flashcode signature is correct */ /* PRQA S 0488 3 */ /* MD_FblWrapperFlash_0488 */
   if (   (FLASH_DRIVER_MCUTYPE(flashCode)   != FLASH_DRIVER_VERSION_MCUTYPE)
       || (FLASH_DRIVER_MASKTYPE(flashCode)  != FLASH_DRIVER_VERSION_MASKTYPE)
       || (FLASH_DRIVER_INTERFACE(flashCode) != FLASH_DRIVER_VERSION_INTERFACE)
      )
   {
      /* Flash driver signature mismatch, wrong flash driver */
      returnValue = IO_E_NOT_OK;
   }
   else
   {
      initState = kFlashInitState_FullDriver;
      returnValue = IO_E_OK;
   }

   return returnValue;
}

/***********************************************************************************************************************
 *  FlashDriver_DeinitSync
 **********************************************************************************************************************/
/*! \brief       Deinitializes the flash driver
 *  \details     No functionality, just to satisfy interface
 *  \pre         None
 *  \param[in]   *address Unused parameter to implement HIS interface
 *  \return      Always IO_E_OK
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
IO_ErrorType FlashDriver_DeinitSync( void* address )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)address;
#endif

   return IO_E_OK;
}

/***********************************************************************************************************************
 *  FlashDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief       Writes data to flash memory
 *  \details     This function programs flash memory by calling the Fls write routine
 *  \pre         Flash driver/Fls is initialized, memory to be programmed is erased
 *  \param[in]   writeBuffer Pointer to input data buffer.
 *  \param[in]   writeLength Data length
 *  \param[in]   writeAddress Write target address
 *  \return      IO_E_OK in case of success, otherwise IO_E_NOT_OK
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
IO_ErrorType FlashDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress )
{
   IO_ErrorType returnValue;

   /* Verify if flashcode signature is correct */ /* PRQA S 0488 3 */ /* MD_FblWrapperFlash_0488 */
   if (   (FLASH_DRIVER_MCUTYPE(flashCode)   != FLASH_DRIVER_VERSION_MCUTYPE)
       || (FLASH_DRIVER_MASKTYPE(flashCode)  != FLASH_DRIVER_VERSION_MASKTYPE)
       || (FLASH_DRIVER_INTERFACE(flashCode) != FLASH_DRIVER_VERSION_INTERFACE)
      )
   {
      /* Flash driver signature mismatch, wrong flash driver */
      returnValue = IO_E_NOT_OK;
   }
   else
   {
      if (initState != kFlashInitState_FullDriver)
      {
         /* Driver was not initialized yet */
         returnValue = IO_E_NOT_OK;
      }
      else
      {
         if (FBL_FLASHFLS_WRITE(writeAddress, writeBuffer, writeLength) == E_OK)
         {
            returnValue = FlashDriver_PollFls();
         }
         else
         {
            returnValue = IO_E_NOT_OK;
         }
      }
   }

   return returnValue;
}

/***********************************************************************************************************************
 *  FlashDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief       Erases area in flash memory
 *  \details     This function erases one or more logical sectors
 *  \pre         Flash driver/Fls is initialized
 *  \param[in]   eraseLength Length of memory to be erased. The length has to be aligned to the length
 *               of one or more flash sectors
 *  \param[in]   eraseAddress Start address of erase area. The start address has to be the start
 *               address of a logical flash sector
 *  \return      IO_E_OK in case of success, otherwise IO_E_NOT_OK
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_REraseSync( IO_SizeType eraseLength, IO_PositionType eraseAddress )
{
   IO_ErrorType returnValue;

   /* Verify if flashcode signature is correct */ /* PRQA S 0488 3 */ /* MD_FblWrapperFlash_0488 */
   if (   (FLASH_DRIVER_MCUTYPE(flashCode)   != FLASH_DRIVER_VERSION_MCUTYPE)
       || (FLASH_DRIVER_MASKTYPE(flashCode)  != FLASH_DRIVER_VERSION_MASKTYPE)
       || (FLASH_DRIVER_INTERFACE(flashCode) != FLASH_DRIVER_VERSION_INTERFACE)
      )
   {
      /* Flash driver signature mismatch, wrong flash driver */
      returnValue = IO_E_NOT_OK;
   }
   else
   {
      if (initState != kFlashInitState_FullDriver)
      {
         /* Driver was not initialized yet */
         returnValue = IO_E_NOT_OK;
      }
      else
      {
         if (FBL_FLASHFLS_ERASE(eraseAddress, eraseLength) == E_OK)
         {
            returnValue = FlashDriver_PollFls();
         }
         else
         {
            /* Erase request failed */
            returnValue = IO_E_NOT_OK;
         }
      }
   }

   return returnValue;
}

/***********************************************************************************************************************
 *  FlashDriver_RReadSync
 **********************************************************************************************************************/
/*! \brief       Reads data from flash memory
 *  \details     This function reads data from flash memory by calling the Fls Read function
 *  \pre         Flash driver/Fls is initialized
 *  \param[out]  readBuffer Pointer to read target buffer. The buffer size must be at least readLength Bytes
 *  \param[in]   readLength Size of data to be read
 *  \param[in]   readAddress Start address of data to be read
 *  \return      IO_E_OK in case of success, otherwise IO_E_NOT_OK
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress )
{
   IO_ErrorType returnValue;

   returnValue = IO_E_NOT_OK;

   if (initState != kFlashInitState_Uninit)
   {
      if (FBL_FLASHFLS_READ(readAddress, readBuffer, readLength) == E_OK)
      {
         returnValue = FlashDriver_PollFls();
      }
   }

   return returnValue;
}

#define FBLFLIO_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* module specific MISRA deviations:

   MD_FblWrapperFlash_0488
      Reason:     Performing pointer arithmetic to get version information of flash driver from flash code buffer.
      Risk:       If "unsigned char" doesn't have a size of 1 Byte, the comparison will lead to wrong results.
      Prevention: Check if "unsigned char" has a size of 1 Byte on used platform.

   MD_FblWrapperFlash_2991_2995:
      Reason:     The value of the if-controlling expression depends on the configuration.
      Risk:       No risk.
      Prevention: No prevention necessary.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_FLIO.C
 **********************************************************************************************************************/
