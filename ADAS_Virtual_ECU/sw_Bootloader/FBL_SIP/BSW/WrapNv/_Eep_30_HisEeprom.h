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
 *  Version    Date        Author  Change Id        Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  02.03.00   2017-09-19  visrie  -                Initial version
 *  02.04.00   2017-11-29  visrie  ESCAN00096851    No changes
 *                                 ESCAN00097590    No changes
 *                                 ESCAN00097591    No changes
 *  02.04.01   2018-01-11  visrie  ESCAN00097944    No changes
 *                                 ESCAN00097953    No changes
 *  02.05.00   2018-02-08  visrie  ESCAN00097770    No changes
 *  02.06.00   2018-03-21  visrie  ESCAN00098860    No changes
 *  02.06.01   2018-04-06  visrie  ESCAN00099015    No changes
 *  02.06.02   2018-04-19  visrie  ESCAN00099155    Fixed function of Eep_30_HisEeprom_GetJobResult
 *                                 ESCAN00101194    No changes
 *  03.00.00   2020-04-02  visrie  FBL-1331         No changes
 *  04.00.00   2020-05-26  visrie  FBL-1016         No changes
 *  04.00.01   2020-07-16  visrie  FBL-2160         No changes
 *  04.00.02   2021-04-01  visrcn  FBL-3009         No changes
 *                                 FBL-3095         No changes
 *  04.01.00   2022-07-11  vistmo  FBL-5336         No changes
 *  04.01.01   2024-07-08  visrie  ESCAN00117458    No changes
 *********************************************************************************************************************/

#ifndef EEP_30_HISEEPROM_H
#define EEP_30_HISEEPROM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "MemIf_Types.h"
#include "fbl_inc.h"
#include "EepInc.h"

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

/* Type for passing EEPROM address and length arguments to the API services */
#define Eep_30_HisEeprom_AddressType      IO_SizeType
#define Eep_30_HisEeprom_LengthType       IO_PositionType
#define Eep_30_HisEeprom_BufferPtrType    IO_MemPtrType

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define EEP_30_HISEEPROM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

void Eep_30_HisEeprom_Init(void * ConfigPtr);
Std_ReturnType Eep_30_HisEeprom_Read(Eep_30_HisEeprom_AddressType EepromAddress, Eep_30_HisEeprom_BufferPtrType DataBufferPtr,
   Eep_30_HisEeprom_LengthType Length);
Std_ReturnType Eep_30_HisEeprom_Write(Eep_30_HisEeprom_AddressType EepromAddress, Eep_30_HisEeprom_BufferPtrType DataBufferPtr,
   Eep_30_HisEeprom_LengthType Length);
Std_ReturnType Eep_30_HisEeprom_Erase(Eep_30_HisEeprom_AddressType EepromAddress, Eep_30_HisEeprom_LengthType Length);
Std_ReturnType Eep_30_HisEeprom_Compare(Eep_30_HisEeprom_AddressType EepromAddress, Eep_30_HisEeprom_BufferPtrType DataBufferPtr,
   Eep_30_HisEeprom_LengthType Length);
void Eep_30_HisEeprom_SetMode(MemIf_ModeType Mode);
MemIf_StatusType Eep_30_HisEeprom_GetStatus(void);
MemIf_JobResultType Eep_30_HisEeprom_GetJobResult(void);
void Eep_30_HisEeprom_Cancel(void);
void Eep_30_HisEeprom_GetVersionInfo(Std_VersionInfoType * versioninfo);
void Eep_30_HisEeprom_MainFunction(void);

#define EEP_30_HISEEPROM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* EEP_30_HISEEPROM_H */

/**********************************************************************************************************************
 *  END OF FILE: EEP_30_HISEEPROM.H
 *********************************************************************************************************************/
