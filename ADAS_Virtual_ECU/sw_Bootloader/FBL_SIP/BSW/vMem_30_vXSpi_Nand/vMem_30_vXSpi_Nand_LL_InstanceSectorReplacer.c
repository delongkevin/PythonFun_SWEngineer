/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer.c
 *        \brief  Instance sector replacer source file
 *
 *      \details  See vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer.h
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_LL_INSTANCESECTORREPLACER_SOURCE

/*********************************************************************************************************************
 *  INLCUDES
 *********************************************************************************************************************/
#include "vMem_30_vXSpi_Nand_IntShared.h"
#include "vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer.h"
#include "vMem_30_vXSpi_Nand_LL_Cbk_Int.h"
#include "vMem_30_vXSpi_Nand_LL.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Size of the address buffer of the status register */
#define VMEM_30_VXSPI_NAND_SPI_DATA_TYPE_LENGTH (8u)

#define VMEM_30_VXSPI_NAND_READ_BBM_LUT_DIE_ID_BIT_POSITION        7u
/* "BBM LUT" stands for "Bad Block Management Look Up Table". */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined(VMEM_30_VXSPI_NAND_LOCAL) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
#define VMEM_30_VXSPI_NAND_LOCAL static
#endif

/*! This enum defines the InstanceSectorReplacers states. */
typedef enum
{
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_IDLE = 0,
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_SELECT_DIE,
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_INITIATE_REPLACE_LOGICAL_SECTOR,
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_AVAILABLE_LINKS,
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_FIND_FIRST_AVAILABLE_SECTOR,
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_WRITE_ENABLE,
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_ADD_BBM_ENTRY,
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_READ_STATUS,
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_PROGRESS,
  VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_LUT
} vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ProgressType;

/*! Instance's SectorReplacer job type to group an instance's job parameters. */
typedef struct
{
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId;
  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ProgressType JobProgress;
  vMem_30_vXSpi_Nand_ReplaceSectorPtrType ReqSpecificData;
  vMem_30_vXSpi_Nand_BusyCheckTimeoutThresholdOfvMemInstanceType BusyCheckTimeoutCounter;
} vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobType;

typedef P2VAR(vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType;
typedef P2CONST(vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConstInstanceJobPtrType;

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Defines a buffer for each configured flash device to store the content of read device registers. */
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_vXSpiDataType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_RegisterDataBuffers[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()][VMEM_30_VXSPI_NAND_REGISTER_DATA_BUFFER_LENGTH];

/*! Defines a buffer for each configured flash device to store the content of the Bad Block Management Look Up Table.  */
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_vXSpiDataType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_LutDataBuffers[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()][VMEM_30_VXSPI_NAND_LUT_DATA_BUFFER_LENGTH];

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobInfo[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertPhysicalToUserAddress()
 *********************************************************************************************************************/
/*! \brief        Converts a physical memory address to the corresponding memory address in the user address mapping.
 *  \details      -
 *  \param[in]    InstanceId                    Instance Id
 *  \param[in,out] AddressPtr                   Pointer to the address to be converted.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertPhysicalToUserAddress(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressPtrType AddressPtr);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertUserToPhysicalAddress()
 *********************************************************************************************************************/
/*! \brief        Converts a user memory address to the corresponding memory address in the physical address mapping.
 *  \details      -
 *  \param[in]    InstanceId                    Instance Id
 *  \param[in,out] AddressPtr                   Pointer to the address to be converted.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertUserToPhysicalAddress(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressPtrType AddressPtr);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLutGetAddress()
 *********************************************************************************************************************/
/*! \brief        Calculates and returns the address for read bad block management sequence.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \return       Address for the read  bad block management sequence.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_AddressType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLutGetAddress(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConstInstanceJobPtrType ProcessedReplacerInstance);


/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobSucceeded()
 *********************************************************************************************************************/
/*! \brief        Resets the instance specific state machine and notifies the vMem_LL about the successfully finished
                  erase operation.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobSucceeded(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed()
 *********************************************************************************************************************/
/*! \brief        Resets the instance specific state machine and notifies the vMem_LL about the failed erase operation.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadStatusRegister()
 *********************************************************************************************************************/
/*! \brief        Initiates the "Read Status Register"-sequence and triggers its execution.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadStatusRegister(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConstInstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLut()
 *********************************************************************************************************************/
/*! \brief        Initiates the "Read Bbm Lut"-sequence and triggers its execution.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLut(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConstInstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_AddBbmLutEntry()
 *********************************************************************************************************************/
/*! \brief        Initiates the "Replace Sector"-sequence and triggers its execution.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_AddBbmLutEntry(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_IsReplacementSectorUsed()
 *********************************************************************************************************************/
/*! \brief        Determines if the passed replacement sector address is already used in the BBM LUT.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \param[in]    ReplacementSectorAddress            Address of the replacement sector.
 *  \param[in]    UsedReplacementSectorAddresses      Addresses in the BBM LUT.
 *  \return       TRUE replacement sector had already been used in the BBM LUT, FALSE otherwise.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(boolean, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_IsReplacementSectorUsed(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConstInstanceJobPtrType ProcessedReplacerInstance,
    vMem_30_vXSpi_Nand_AddressType ReplacementSectorAddress,
    vMem_30_vXSpi_Nand_FlsAddressPtrType UsedReplacementSectorAddresses);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_FindFirstAvailableReplacingSectorAddress()
 *********************************************************************************************************************/
/*! \brief        Searches for an unused sector startaddress which is available for sector replacement.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \return       E_OK available replacing sector found, E_NOT_OK otherwise.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_FindFirstAvailableReplacingSectorAddress(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckBbmLut()
 *********************************************************************************************************************/
/*! \brief        Checks if a new entry in the LUT was successfully written according to the requested replacement job.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckBbmLut(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckAvailableLinks()
 *********************************************************************************************************************/
/*! \brief        Checks if there are available replacement sectors remaining according to the status register.
 *  \details      If there are available replacement sectors remaining, Initiates the "ReadBbmLut"-sequence and triggers
 *                its execution.
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckAvailableLinks(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckProgress()
 *********************************************************************************************************************/
/*! \brief        Checks if device is in progress according to the status register.
 *  \details      If device is not in progress, Initiates the "ReadBbmLut"-sequence and triggers 
 *                its execution.
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckProgress(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_SelectDie()
 *********************************************************************************************************************/
/*! \brief         the Spi sequence to select another die.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_SelectDie(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_WriteEnable()
 *********************************************************************************************************************/
/*! \brief         the Spi sequence to enable the write.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_WriteEnable(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InitiateReplaceLogicalSector()
 *********************************************************************************************************************/
/*! \brief        Triggers the transmission of the Spi sequence to read the status register and sets the next
 *                job progress state.
 *  \details      -
 *  \param[in]    ProcessedReplacerInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InitiateReplaceLogicalSector(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance);
    
/*********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertPhysicalToUserAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertPhysicalToUserAddress(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId, 
    vMem_30_vXSpi_Nand_AddressPtrType AddressPtr)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(InstanceId, *AddressPtr);
  vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);
  *AddressPtr += vMem_30_vXSpi_Nand_LL_CfgDie_GetDieStartAddressOfvMemDie(dieIndex); /* VCA_VXSPI_VALID_ADDRESS */
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertPhysicalToUserAddress */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertUserToPhysicalAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertUserToPhysicalAddress(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressPtrType AddressPtr)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(InstanceId, *AddressPtr);
  vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);
  *AddressPtr -= vMem_30_vXSpi_Nand_LL_CfgDie_GetDieStartAddressOfvMemDie(dieIndex); /* VCA_VXSPI_VALID_ADDRESS */
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertUserToPhysicalAddress */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLutGetAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_AddressType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLutGetAddress(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConstInstanceJobPtrType ProcessedReplacerInstance)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(ProcessedReplacerInstance->InstanceId,
      ProcessedReplacerInstance->ReqSpecificData->TargetSectorAddress);
  vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);
  vMem_30_vXSpi_Nand_AddressType address = 0;

  /* The address phase (1 Byte) was added to be compatible to hybrid and non hybrid NAND devices. For hybrid devices like W25N02JW the
   * Read BBM Look Up Table sequence is different from non hybrid devices like W25M02GV. For non hybrid devices address is always 0.
   * This complies to the required 8 dummy cycles. For hybrid devices the MSB of the address specifies the selected die. */

  if(!(vMem_30_vXSpi_Nand_LL_CfgInstance_IsSoftwareDieSelectUsed(ProcessedReplacerInstance->InstanceId)))
  {
    address = ((vMem_30_vXSpi_Nand_AddressType)dieIndex) << VMEM_30_VXSPI_NAND_READ_BBM_LUT_DIE_ID_BIT_POSITION;
  }

  return address;
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLutGetAddress */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobSucceeded()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobSucceeded(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_IDLE; /* SBSW_vMem_30_vXSpi_Nand_WriteToInstanceStateMachinePtrParameter */
  vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReplacerInstance->InstanceId, VMEM_JOB_OK, VMEM_30_VXSPI_NAND_NO_FAIL);
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobSucceeded */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_IDLE; /* SBSW_vMem_30_vXSpi_Nand_WriteToInstanceStateMachinePtrParameter */
  vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReplacerInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_IsReplacementSectorUsed()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(boolean, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_IsReplacementSectorUsed(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConstInstanceJobPtrType ProcessedReplacerInstance,
    vMem_30_vXSpi_Nand_AddressType ReplacementSectorAddress,
    vMem_30_vXSpi_Nand_FlsAddressPtrType UsedReplacementSectorAddresses) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  boolean sectorUsed = FALSE;
  uint8 lutEntryId = 0u;
  vMem_30_vXSpi_Nand_InstanceIdType instanceIdx= ProcessedReplacerInstance->InstanceId;
  vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType lutDataPtr = vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_LutDataBuffers[instanceIdx];

  while ((lutEntryId < vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutMaxEntries(instanceIdx)) && (sectorUsed == FALSE))
  {
    /* A replacing sector has only actually been used, if the first LUT status byte is set. */
    vMem_30_vXSpi_Nand_FlsAddressType lutTargetSectorAddress;
    lutTargetSectorAddress = ((vMem_30_vXSpi_Nand_FlsAddressType)lutDataPtr[lutEntryId * vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutEntryLength(instanceIdx)] << VMEM_30_VXSPI_NAND_SPI_DATA_TYPE_LENGTH)
                              | (vMem_30_vXSpi_Nand_FlsAddressType)lutDataPtr[(lutEntryId * vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutEntryLength(instanceIdx)) + 1u];
    if (((lutTargetSectorAddress & VMEM_30_VXSPI_NAND_LUT_STATUS_FLAG_1_BITMASK) == VMEM_30_VXSPI_NAND_LUT_STATUS_FLAG_1_BITMASK) && 
        (ReplacementSectorAddress == UsedReplacementSectorAddresses[lutEntryId]))
    {
      sectorUsed = TRUE;
    }
    lutEntryId++;
  }
  return sectorUsed;
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_IsReplacementSectorUsed */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_FindFirstAvailableReplacingSectorAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_FindFirstAvailableReplacingSectorAddress(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  Std_ReturnType retVal = E_NOT_OK;
  vMem_30_vXSpi_Nand_InstanceIdType instanceIdx = ProcessedReplacerInstance->InstanceId;
  vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType lutDataPtr = vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_LutDataBuffers[instanceIdx];

  vMem_30_vXSpi_Nand_AddressType replacingSectorAddress;
  vMem_30_vXSpi_Nand_FlsAddressType usedReplacingSectorAddresses[VMEM_30_VXSPI_NAND_LUT_MAX_ENTRIES];
  uint8 lutEntryId;
  uint8 sectorIdx = vMem_30_vXSpi_Nand_LL_CfgInstance_GetMemSectorStartIdxOfvMemInstance(instanceIdx);
  uint8 columnAddressLength = vMem_30_vXSpi_Nand_GetColumnAddressLength(ProcessedReplacerInstance->InstanceId, ProcessedReplacerInstance->ReqSpecificData->TargetSectorAddress);
  boolean foundAvailableSector = FALSE;

  /* Fill usedReplacingSectorAddresses array with the sector addresses of the BBM LUT. */
  for(lutEntryId = 0u; lutEntryId < vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutMaxEntries(instanceIdx); lutEntryId++)
  {
    usedReplacingSectorAddresses[lutEntryId] = ((vMem_30_vXSpi_Nand_FlsAddressType)lutDataPtr[(lutEntryId * vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutEntryLength(instanceIdx)) /* VCA_VXSPI_VALID_INSTANCE_ID, VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_RX */
                                 + vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutAddressLength(instanceIdx)] << VMEM_30_VXSPI_NAND_SPI_DATA_TYPE_LENGTH) 
                              | (vMem_30_vXSpi_Nand_FlsAddressType)lutDataPtr[(lutEntryId * vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutEntryLength(instanceIdx)) 
                                 + vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutAddressLength(instanceIdx) + 1u]; 
  }

  /* Search for first available replacement sector, which is not already used. */
  while((sectorIdx < vMem_30_vXSpi_Nand_GetMemSectorEndIdxOfvMemInstance(instanceIdx)) && (foundAvailableSector == FALSE))
  {
    /* The MemSector must be configured as replacement sector and must be located on the same die as the target sector to be a suitable replacement. */
    uint32 sectorIdxOfTargetSector = vMem_30_vXSpi_Nand_GetSectorIndex(instanceIdx, ProcessedReplacerInstance->ReqSpecificData->TargetSectorAddress);
    if (vMem_30_vXSpi_Nand_LL_CfgSector_IsReplacementSector(sectorIdx) && 
        (vMem_30_vXSpi_Nand_GetvMemDieIdxOfMemSector(sectorIdx) == vMem_30_vXSpi_Nand_GetvMemDieIdxOfMemSector(sectorIdxOfTargetSector)))
    {

      /* Iterate over all sectors in the MemSector. */
      uint16 sectorIterator = 0u;
      while ((sectorIterator < vMem_30_vXSpi_Nand_GetNrOfSectorsOfMemSector(sectorIdx)) && (foundAvailableSector == FALSE))
      {
        replacingSectorAddress = vMem_30_vXSpi_Nand_LL_CfgSector_GetStartAddressOfMemSector(sectorIdx) + (sectorIterator * vMem_30_vXSpi_Nand_LL_CfgSector_GetSectorSizeOfMemSector(sectorIdx));
        /* Convert the address into the User address mapping. */
        vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertUserToPhysicalAddress(instanceIdx, &replacingSectorAddress);
        /* Convert the full address to the sector address. */
        replacingSectorAddress = replacingSectorAddress >> (columnAddressLength + VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH);
        /* Store the result in ReqSpecificData. */
        ProcessedReplacerInstance->ReqSpecificData->ReplacingSectorAddress = replacingSectorAddress << (columnAddressLength + VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH); /* VCA_VXSPI_VALID_REQ_SPECIFIC_DATA */
        
        if (vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_IsReplacementSectorUsed(ProcessedReplacerInstance, replacingSectorAddress, usedReplacingSectorAddresses) == FALSE)
        {
          foundAvailableSector = TRUE;
        }
        sectorIterator++;
      }
    }
    sectorIdx++;
  }

  if (foundAvailableSector == TRUE)
  {
    retVal = E_OK;
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(ProcessedReplacerInstance);
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_FindFirstAvailableReplacingSectorAddress */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckBbmLut()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckBbmLut(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  uint8 lutEntryId;
  boolean jobSucceeded = FALSE;

  vMem_30_vXSpi_Nand_FlsAddressType lutTargetSectorAddress;
  vMem_30_vXSpi_Nand_FlsAddressType lutReplacingSectorAddress;
  boolean lutStatusFlag1;
  boolean lutStatusFlag2;
  vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType LutDataPtr = vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_LutDataBuffers[ProcessedReplacerInstance->InstanceId];
  uint8 columnAddressLength = vMem_30_vXSpi_Nand_GetColumnAddressLength(ProcessedReplacerInstance->InstanceId, ProcessedReplacerInstance->ReqSpecificData->TargetSectorAddress);
 
  if(ProcessedReplacerInstance->ReqSpecificData->LastJobError == VMEM_30_VXSPI_NAND_P_FAIL)
  {
    ProcessedReplacerInstance->ReqSpecificData->RecoverDataSourceAddress = ProcessedReplacerInstance->ReqSpecificData->ReplacingSectorAddress; /* VCA_VXSPI_VALID_INSTANCE_ID */
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertPhysicalToUserAddress(ProcessedReplacerInstance->InstanceId, &(ProcessedReplacerInstance->ReqSpecificData->RecoverDataSourceAddress));
  }
  for(lutEntryId = 0u; lutEntryId <  vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutMaxEntries(ProcessedReplacerInstance->InstanceId); lutEntryId++)
  {
    lutTargetSectorAddress = ((vMem_30_vXSpi_Nand_FlsAddressType)LutDataPtr[lutEntryId * vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutEntryLength(ProcessedReplacerInstance->InstanceId)] << VMEM_30_VXSPI_NAND_SPI_DATA_TYPE_LENGTH)
                                | (vMem_30_vXSpi_Nand_FlsAddressType)LutDataPtr[(lutEntryId * vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutEntryLength(ProcessedReplacerInstance->InstanceId)) + 1u];
    lutStatusFlag1 = ((lutTargetSectorAddress & VMEM_30_VXSPI_NAND_LUT_STATUS_FLAG_1_BITMASK) == 0x00u) ? FALSE : TRUE;
    lutStatusFlag2 = ((lutTargetSectorAddress & VMEM_30_VXSPI_NAND_LUT_STATUS_FLAG_2_BITMASK) == 0x00u) ? FALSE : TRUE;
    lutTargetSectorAddress = lutTargetSectorAddress & VMEM_30_VXSPI_NAND_LUT_STATUS_BITMASK;
    
    if(((((vMem_30_vXSpi_Nand_AddressType)lutTargetSectorAddress) << (columnAddressLength + VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH)) == ProcessedReplacerInstance->ReqSpecificData->TargetSectorAddress) &&
        (lutStatusFlag1 == TRUE))
    {
      lutReplacingSectorAddress = ((vMem_30_vXSpi_Nand_FlsAddressType)LutDataPtr[(lutEntryId * vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutEntryLength(ProcessedReplacerInstance->InstanceId))
                                  + vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutAddressLength(ProcessedReplacerInstance->InstanceId)] << VMEM_30_VXSPI_NAND_SPI_DATA_TYPE_LENGTH) 
                                  | ((vMem_30_vXSpi_Nand_FlsAddressType)LutDataPtr[(lutEntryId * vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutEntryLength(ProcessedReplacerInstance->InstanceId))
                                  + vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutAddressLength(ProcessedReplacerInstance->InstanceId) + 1u]);
      if(lutStatusFlag2 == FALSE)
      {
        if((((vMem_30_vXSpi_Nand_AddressType)lutReplacingSectorAddress) << (columnAddressLength + VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH))
          == ProcessedReplacerInstance->ReqSpecificData->ReplacingSectorAddress)
        {
          jobSucceeded = TRUE;
          break;
        }
      }
      else if(ProcessedReplacerInstance->ReqSpecificData->LastJobError == VMEM_30_VXSPI_NAND_P_FAIL)
      {
        ProcessedReplacerInstance->ReqSpecificData->RecoverDataSourceAddress = ((vMem_30_vXSpi_Nand_AddressType)lutReplacingSectorAddress) << (columnAddressLength + VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH);
        vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertPhysicalToUserAddress(ProcessedReplacerInstance->InstanceId, &(ProcessedReplacerInstance->ReqSpecificData->RecoverDataSourceAddress));
      }
      else
      {
        /* Intentionally left empty. */
      }
    }
  }

  /* Convert the sector addresses to the corresponding address in the user's address mapping. */
  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertPhysicalToUserAddress(ProcessedReplacerInstance->InstanceId, &(ProcessedReplacerInstance->ReqSpecificData->TargetSectorAddress));
  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertPhysicalToUserAddress(ProcessedReplacerInstance->InstanceId, &(ProcessedReplacerInstance->ReqSpecificData->ReplacingSectorAddress));

  if(jobSucceeded == TRUE)
  {
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobSucceeded(ProcessedReplacerInstance);
  }
  else
  {
    ProcessedReplacerInstance->BusyCheckTimeoutCounter--;
    if(ProcessedReplacerInstance->BusyCheckTimeoutCounter > 0u)
    {
      ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_PROGRESS;
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(ProcessedReplacerInstance);
    }
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckBbmLut */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckAvailableLinks()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckAvailableLinks(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  /* If available replacing sectors are remaining, try to read the look up table */
  if ((((*vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_RegisterDataBuffers[ProcessedReplacerInstance->InstanceId])) 
      & (vMem_30_vXSpi_Nand_vXSpiDataType)vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterLutFBitMask(ProcessedReplacerInstance->InstanceId)) == 0x00u)
  {
    ProcessedReplacerInstance->ReqSpecificData->AvailableSectorInfo = VMEM_30_VXSPI_NAND_SECTOR_REPLACEABLE; /* VCA_VXSPI_VALID_REQ_SPECIFIC_DATA */
    if (vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLut(ProcessedReplacerInstance) == E_OK)
    {
      ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_FIND_FIRST_AVAILABLE_SECTOR;
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(ProcessedReplacerInstance);
    }
  }
  else
  /* If no available replacing sector is remaining, finalize job unsuccessful. */
  {
    ProcessedReplacerInstance->ReqSpecificData->AvailableSectorInfo = VMEM_30_VXSPI_NAND_NO_AVAILABLE_SECTOR_REMAINING; /* VCA_VXSPI_VALID_REQ_SPECIFIC_DATA */
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(ProcessedReplacerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckAvailableLinks */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckProgress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckProgress(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  /* Check if device is idle. */
  if ((((*vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_RegisterDataBuffers[ProcessedReplacerInstance->InstanceId])) 
      & (vMem_30_vXSpi_Nand_vXSpiDataType)vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterBusyFlagBitMask(ProcessedReplacerInstance->InstanceId)) == 0x00u)
  {
    /* Read BadblockManagement Look up table. */
    if (vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLut(ProcessedReplacerInstance) == E_OK)
    {
      ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_LUT;
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(ProcessedReplacerInstance);
    }
  }
  else /* Device still busy. */
  {
    /* Check timeout. */
    ProcessedReplacerInstance->BusyCheckTimeoutCounter--;
    if (ProcessedReplacerInstance->BusyCheckTimeoutCounter > 0u)
    {
      /* Read Status Register. */
      if (vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadStatusRegister(ProcessedReplacerInstance) == E_OK)
      {
        ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_PROGRESS;
      }
      else
      {
        vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(ProcessedReplacerInstance);
      }
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(ProcessedReplacerInstance);
    }
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckProgress */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadStatusRegister()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadStatusRegister(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConstInstanceJobPtrType ProcessedReplacerInstance)
{
  return vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
      ProcessedReplacerInstance->InstanceId,
      (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedReplacerInstance->InstanceId),
      vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_RegisterDataBuffers[ProcessedReplacerInstance->InstanceId],
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedReplacerInstance->InstanceId));

} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadStatusRegister */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLut()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLut(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConstInstanceJobPtrType ProcessedReplacerInstance)
{
 return vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadBbmLutSequence(
     ProcessedReplacerInstance->InstanceId,
     vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLutGetAddress(ProcessedReplacerInstance),
     vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_LutDataBuffers[ProcessedReplacerInstance->InstanceId],
     (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutDataBufferLength(ProcessedReplacerInstance->InstanceId));

} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadBbmLut */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_AddBbmLutEntry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_AddBbmLutEntry(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReplaceSectorSequence(
      ProcessedReplacerInstance->InstanceId,
      ProcessedReplacerInstance->ReqSpecificData->TargetSectorAddress,
      ProcessedReplacerInstance->ReqSpecificData->ReplacingSectorAddress);

  if (sequenceResult == E_OK)
  {
    ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_READ_STATUS;
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(ProcessedReplacerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_AddBbmLutEntry */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InitiateReplaceLogicalSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InitiateReplaceLogicalSector(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  /* Convert the target sector address to the corresponding physical memory address. */
  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ConvertUserToPhysicalAddress(ProcessedReplacerInstance->InstanceId, &(ProcessedReplacerInstance->ReqSpecificData->TargetSectorAddress));

  if (vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadStatusRegister(ProcessedReplacerInstance) == E_OK)
  {
    ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_AVAILABLE_LINKS;
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(ProcessedReplacerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InitiateReplaceLogicalSector */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_SelectDie()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_SelectDie(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(ProcessedReplacerInstance->InstanceId,
      ProcessedReplacerInstance->ReqSpecificData->TargetSectorAddress);
  vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);

  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence(
      ProcessedReplacerInstance->InstanceId, dieIndex);

  if (sequenceResult == E_OK)
  {
    vMem_30_vXSpi_Nand_ActiveDie[ProcessedReplacerInstance->InstanceId] = dieIndex; /* VCA_VXSPI_VALID_INSTANCE_ID */
    ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_INITIATE_REPLACE_LOGICAL_SECTOR;
  }
  else
  {
    ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReplacerInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }

} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_SelectDie */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_WriteEnable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_WriteEnable(
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType ProcessedReplacerInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteEnableSequence(
      ProcessedReplacerInstance->InstanceId);

  if (sequenceResult == E_OK)
  {
    ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_ADD_BBM_ENTRY;
  }
  else
  {
    ProcessedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReplacerInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }

} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_WriteEnable */

/*********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_PerformReplaceLogicalSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_PerformReplaceLogicalSector(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_ReplaceSectorPtrType ReqSpecificData
    )
{
  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType processedReplacerInstance =
      &vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobInfo[InstanceId];

  /* Store the job parameters. */
  processedReplacerInstance->InstanceId = InstanceId; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedReplacerInstance->ReqSpecificData = ReqSpecificData; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedReplacerInstance->BusyCheckTimeoutCounter = /* VCA_VXSPI_VALID_INSTANCE_ID */
    vMem_30_vXSpi_Nand_LL_CfgInstance_GetBusyCheckTimeoutThresholdOfvMemInstance(InstanceId);

  processedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_SELECT_DIE; /* VCA_VXSPI_VALID_INSTANCE_ID */

  return E_OK;
} /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_PerformReplaceLogicalSector() */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_Processing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_Processing(vMem_30_vXSpi_Nand_InstanceIdType InstanceId) /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */ /* vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_Processing */
{
  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobPtrType processedReplacerInstance =
      &vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InstanceJobInfo[InstanceId];

  switch (processedReplacerInstance->JobProgress)
  {
  case VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_SELECT_DIE:
  {
    uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(processedReplacerInstance->InstanceId, processedReplacerInstance->ReqSpecificData->TargetSectorAddress);
    vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);

    if((vMem_30_vXSpi_Nand_LL_CfgInstance_IsSoftwareDieSelectUsed(processedReplacerInstance->InstanceId))
        && (vMem_30_vXSpi_Nand_ActiveDie[processedReplacerInstance->InstanceId] != dieIndex))
    {
      vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_SelectDie(processedReplacerInstance);
    }
    else
    {
      processedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_INITIATE_REPLACE_LOGICAL_SECTOR;
      vMem_30_vXSpi_Nand_LL_SetProcessFlag(InstanceId);
    }
  }
  break;
  case VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_INITIATE_REPLACE_LOGICAL_SECTOR:
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_InitiateReplaceLogicalSector(processedReplacerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_AVAILABLE_LINKS:
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckAvailableLinks(processedReplacerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_FIND_FIRST_AVAILABLE_SECTOR:
    if (vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_FindFirstAvailableReplacingSectorAddress(processedReplacerInstance) == E_OK)
    {
      processedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_WRITE_ENABLE;
      vMem_30_vXSpi_Nand_LL_SetProcessFlag(InstanceId);
    }
    break;
  case VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_WRITE_ENABLE:
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_WriteEnable(processedReplacerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_ADD_BBM_ENTRY:
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_AddBbmLutEntry(processedReplacerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_READ_STATUS:
    if (vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_ReadStatusRegister(processedReplacerInstance) == E_OK)
    {
      processedReplacerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_PROGRESS;
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_JobFailed(processedReplacerInstance);
    }
    break;
  case VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_PROGRESS:
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckProgress(processedReplacerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCESECTORREPLACER_CHECK_LUT:
    vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_CheckBbmLut(processedReplacerInstance);
    break;
  default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE */
    break;
  }
}

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer.c
 *********************************************************************************************************************/
