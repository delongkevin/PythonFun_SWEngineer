/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Flash Driver wrapper Template
 *
 *  \note          Please note, that this file contains a collection of template functions to be used with the
 *                 Flash Bootloader. These functions may influence the behavior of the bootloader in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "fbl_inc.h"

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define FLASH_WRAPPER_OFFSET 0x97000000

#define RAM_DRV_POLLING_INTERVAL 64u
#define RAM_DRV_POLLING_FUNCTION FblLookForWatchdogVoid
/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *   LOCAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FlashWrapperDriver_InitSync
 **********************************************************************************************************************/
/*! \brief       Initializes the flash driver
 *  \details     This function copies the flash driver to RAM if it is stored in a ROM image and calls the
 *               initialization routine in RAM.
 *  \pre         Flash driver has to be copied to RAM if a downloadable flash driver is used.
 *  \param[in]   *address Unused parameter to implement HIS interface.
 *  \return      Reports if initialization was successful or not.
 **********************************************************************************************************************/
IO_ErrorType FlashWrapperDriver_InitSync( void * address )
{
  /* Flash Driver using FLS is able to be initialized multiple times
     even if the FBL already initialized it due to various reasons, no issue due to double init */
  return FlashDriver_InitSync(address);
}

/***********************************************************************************************************************
 *  FlashWrapperDriver_DeinitSync
 **********************************************************************************************************************/
/*! \brief       Deinitializes the flash driver
 *  \details     This function calls the deinitialization routine in RAM and removes the flash driver
 *               from the RAM buffer.
 *  \pre         Flash driver is initialized.
 *  \param[in]   *address Unused parameter to implement HIS interface.
 *  \return      Reports if deinitialization was successful or not.
 **********************************************************************************************************************/
IO_ErrorType FlashWrapperDriver_DeinitSync( void* address )
{
  /* Flash Driver using FLS is able to be initialized multiple times
     even if the FBL already initialized it due to various reasons, no issue due to double init */
  return FlashDriver_DeinitSync(address);
}

/***********************************************************************************************************************
 *  FlashWrapperDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief       Writes data to flash memory.
 *  \details     This function programs flash memory by calling the flash driver routine stored in RAM.
 *  \pre         Flash driver is initialized, memory to be programmed is erased.
 *  \param[in]   writeBuffer Pointer to input data buffer.
 *  \param[in]   writeLength Data length.
 *  \param[in]   writeAddress Write target address ( in flash memory ).
 *  \return      Reports write success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashWrapperDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress )
{
  IO_ErrorType retVal;
  
  retVal = FlashDriver_RWriteSync(writeBuffer, writeLength, writeAddress - FLASH_WRAPPER_OFFSET);
  
  if (IO_E_OK == retVal)
  {
    /* read back to RAM */
    retVal = FlashDriver_RReadSync((IO_MemPtrType)writeAddress, writeLength, writeAddress - FLASH_WRAPPER_OFFSET);
  }
  
  return retVal;
}

/***********************************************************************************************************************
 *  FlashWrapperDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief       Erases area in flash memory.
 *  \details     This function erases one or more logical sectors in flash memory.
 *  \pre         Flash driver is initialized.
 *  \param[in]   eraseLength Length of memory to be erased. The length has to be aligned to the length
 *               of one or more flash sectors. The flash area has to be contiguous - gaps in must not
 *               be included.
 *  \param[in]   eraseAddress Start address of erase area. The start address has to be the start
 *               address of a logical flash sector.
 *  \return      Reports erase success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashWrapperDriver_REraseSync(IO_SizeType eraseLength, IO_PositionType eraseAddress)
{



  IO_ErrorType retVal;
  vuint32 idx;
  vuint8 * erasePtr = (vuint8 *) eraseAddress;
  
  retVal = FlashDriver_REraseSync(eraseLength, eraseAddress - FLASH_WRAPPER_OFFSET);
  
  if (IO_E_OK == retVal)
  {
    for(idx = 0u; idx < eraseLength; idx++)
	{
		 if (0u == (idx & (RAM_DRV_POLLING_INTERVAL - 1u)))
         {
            RAM_DRV_POLLING_FUNCTION();
         }
		erasePtr[idx] = 0xFFu;
	}
  }
  
  return retVal;



}

/***********************************************************************************************************************
 *  FlashWrapperDriver_RReadSync
 **********************************************************************************************************************/
/*! \brief       Reads data from flash memory.
 *  \details     This function reads data from flash memory. It can be configured to report ECC errors to the
 *               calling function.
 *  \param[out]  readBuffer Pointer to read target buffer. The buffer size must be at least readLength Bytes.
 *  \param[in]   readLength Size of data to be read.
 *  \param[in]   readAddress Start address of data to be read.
 *  \return      Reports read success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashWrapperDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress )
{
	uint32 idx;
	uint8 * readAccessBuffer = (uint8 *) readAddress;
#if 0 
 return RamDriver_RReadSync(readBuffer, readLength, readAddress);
#endif


    for(idx = 0u; idx < readLength; idx++)
	{
		 if (0u == (idx & (RAM_DRV_POLLING_INTERVAL - 1u)))
         {
            RAM_DRV_POLLING_FUNCTION();
         }
		readBuffer[idx] = readAccessBuffer[idx];
	}

	return kFblOk;
}

/***********************************************************************************************************************
 *  END OF FILE: FBL_FLIO.C
 **********************************************************************************************************************/
