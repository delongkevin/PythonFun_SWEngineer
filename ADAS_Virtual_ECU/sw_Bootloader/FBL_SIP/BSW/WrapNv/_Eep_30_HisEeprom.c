/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         MSR-EEPROM API wrapper for FBL-EEPROM API
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
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
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/*********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define EEP_30_HISEEPROM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Eep_30_HisEeprom.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define EEP_30_HISEEPROM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_Init
 **********************************************************************************************************************/
/*! \brief      Driver initialization service
 *  \param[in]  ConfigPtr - pointer to configuration set
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
void Eep_30_HisEeprom_Init(void * ConfigPtr)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)ConfigPtr;
#endif

   (void)EepromDriver_InitSync(V_NULL);
}

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_Read
 **********************************************************************************************************************/
/*! \brief      Service for reading data from EEPROM memory
 *  \param[in]  EepromAddress - address offset in EEPROM (will be added to the EEPROM base address)
 *  \param[in]  DataBufferPtr - pointer to destination data buffer in RAM
 *  \param[in]  Length        - number of bytes to read
 *  \return     Result of request (see Std_ReturnType).
 **********************************************************************************************************************/
Std_ReturnType Eep_30_HisEeprom_Read(Eep_30_HisEeprom_AddressType EepromAddress, Eep_30_HisEeprom_BufferPtrType DataBufferPtr, Eep_30_HisEeprom_LengthType Length)
{
   Std_ReturnType result;

   if (EepromDriver_RReadSync(DataBufferPtr, Length, EepromAddress) == IO_E_OK)
   {
      result = E_OK;
   }
   else
   {
      result = E_NOT_OK;
   }

   return result;
}

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_Write
 **********************************************************************************************************************/
/*! \brief      Service for writing data to EEPROM memory
 *  \param[in]  EepromAddress - address offset in EEPROM (will be added to the EEPROM base address)
 *  \param[in]  DataBufferPtr - pointer to source data
 *  \param[in]  Length        - number of bytes to write
 *  \return     Result of request (see Std_ReturnType).
 **********************************************************************************************************************/
Std_ReturnType Eep_30_HisEeprom_Write(Eep_30_HisEeprom_AddressType EepromAddress, Eep_30_HisEeprom_BufferPtrType DataBufferPtr, Eep_30_HisEeprom_LengthType Length)
{
   Std_ReturnType result;

   if (EepromDriver_RWriteSync(DataBufferPtr, Length, EepromAddress) == IO_E_OK)
   {
      result = E_OK;
   }
   else
   {
      result = E_NOT_OK;
   }

   return result;
}

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_Erase
 **********************************************************************************************************************/
/*! \brief      Service for erasing EEPROM memory
 *  \param[in]  EepromAddress - address offset in EEPROM (will be added to the EEPROM base address)
 *  \param[in]  Length        - number of bytes to erase
 *  \return     Result of request (see Std_ReturnType).
 **********************************************************************************************************************/
Std_ReturnType Eep_30_HisEeprom_Erase(Eep_30_HisEeprom_AddressType EepromAddress, Eep_30_HisEeprom_LengthType Length)
{
   Std_ReturnType result;

   if (EepromDriver_REraseSync(Length, EepromAddress) == IO_E_OK)
   {
      result = E_OK;
   }
   else
   {
      result = E_NOT_OK;
   }

   return result;
}

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_Compare
 **********************************************************************************************************************/
/*! \brief      Service for comparing user data with data in EEPROM memory
 *  \param[in]  EepromAddress - address offset in EEPROM (will be added to the EEPROM base address)
 *  \param[in]  DataBufferPtr - pointer to data buffer (compare data)
 *  \param[in]  Length        - number of bytes to compare
 *  \return     Result of request (see Std_ReturnType).
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
Std_ReturnType Eep_30_HisEeprom_Compare(Eep_30_HisEeprom_AddressType EepromAddress, Eep_30_HisEeprom_BufferPtrType DataBufferPtr, Eep_30_HisEeprom_LengthType Length)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)EepromAddress;
   (void)DataBufferPtr;
   (void)Length;
#endif

   return E_NOT_OK;
}

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_SetMode
 **********************************************************************************************************************/
/*! \brief      Service for setting the driver's mode
 *  \param[in]  Mode - input mode
 **********************************************************************************************************************/
void Eep_30_HisEeprom_SetMode(MemIf_ModeType Mode)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)Mode;
#endif
}

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_GetStatus
 **********************************************************************************************************************/
/*! \brief      Service for retrieving the driver's state
 *  \return     EEPROM driver status (see MemIf_StatusType).
 **********************************************************************************************************************/
MemIf_StatusType Eep_30_HisEeprom_GetStatus(void)
{
   return MEMIF_IDLE;
}

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_GetJobResult
 **********************************************************************************************************************/
/*! \brief      Service for retrieving a job's result
 *  \return     EEPROM's driver last job result (see MemIf_JobResultType).
 **********************************************************************************************************************/
MemIf_JobResultType Eep_30_HisEeprom_GetJobResult(void)
{
   return MEMIF_JOB_OK;
}

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_Cancel
 **********************************************************************************************************************/
/*! \brief      Service to cancel ongoing jobs
 **********************************************************************************************************************/
void Eep_30_HisEeprom_Cancel(void)
{
}

/***********************************************************************************************************************
 * Eep_30_HisEeprom_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief         Version Information Service
 *  \param[in,out] versioninfo - pointer to where to store the version information of this module
 **********************************************************************************************************************/
void Eep_30_HisEeprom_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
  versioninfo->vendorID         = 0u;
  versioninfo->moduleID         = 0u;
  versioninfo->sw_major_version = 0u;
  versioninfo->sw_minor_version = 0u;
  versioninfo->sw_patch_version = 0u;
}

/***********************************************************************************************************************
 *  Eep_30_HisEeprom_MainFunction
 **********************************************************************************************************************/
/*! \brief      Service for asynchronous execution of jobs
 **********************************************************************************************************************/
void Eep_30_HisEeprom_MainFunction(void)
{
}

#define EEP_30_HISEEPROM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  END OF FILE: EEP_30_HISEEPROM.C
 **********************************************************************************************************************/
