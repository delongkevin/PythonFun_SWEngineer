/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_vXSpi_Nand_IntShared.h
 *        \brief  Internal shared code for vMem_30_vXSpi_Nand.
 *      \details  Code that may be useful for all subcomponents of vMem_30_vXSpi_Nand.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_INTSHARED_H)
# define VMEM_30_VXSPI_NAND_INTSHARED_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMem_30_vXSpi_Nand_LL_Types.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_INTSHARED_LOCAL) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
# define VMEM_30_VXSPI_NAND_INTSHARED_LOCAL static
#endif

#if !defined (VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
# define VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEM_30_VXSPI_NAND_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_GetColumnAddressLength()
 *********************************************************************************************************************/
 /*!
 * \brief       Gets the column address lenght depending on the page size on the particular address.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 * \param[in]   Address           NV memory address which shall be used to find the column address length.
 * \return      Column address length in bits.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE FUNC(uint8, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_GetColumnAddressLength(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId, 
  vMem_30_vXSpi_Nand_AddressType Address);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_GetSectorIndex()
 *********************************************************************************************************************/
/*!
 * \brief       Searches for the passed address within the configuration and determined index of sector (batch) in
 *              configuration structure.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 * \param[in]   Address           NV memory address which shall be found within configured sector structure.
 * \return      Index to the sector batch, or an out of range value.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE FUNC(uint32, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_GetSectorIndex(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType Address);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_GetSectorEndAddress()
 *********************************************************************************************************************/
/*!
 * \brief       Calculates the sector batch end address of the given sector or sector batch.
 * \details     -
 * \param[in]   SectorIndex       Index of the given sector or sector batch.
 * \return      End address       End address of the sector or sector batch.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE FUNC(vMem_30_vXSpi_Nand_AddressType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_GetSectorEndAddress(
  vMem_30_vXSpi_Nand_MemSectorIterType SectorIndex
);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_ConvertAddress()
 *********************************************************************************************************************/
/*!
 * \brief       Converts a 32 bit address into seperate parts.
 * \details     Converts a 32 bit address into seperate 16 bit addresses: A page address (sector start address + page 
 *              address offset), a column address and a sector address (sector start address without offset).
 * \param[in]   InstanceId        ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 * \param[in]   Address           Address that will be converted.
 * \param[out]  Pointer           Pointer to a variable of type vMem_30_vXSpi_Nand_ConvertedAddressType.
*               After job is processed contains converted address information.
 * \return      Converted Address
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_ConvertAddress(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType Address,
  vMem_30_vXSpi_Nand_ConvertedAddressPtrType ConvertedAddressPtr
);

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_GetColumnAddressLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE FUNC(uint8, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_GetColumnAddressLength(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType Address)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(InstanceId, Address);
  uint32 pageSize = vMem_30_vXSpi_Nand_LL_CfgSector_GetPageSizeOfMemSector(sectorIndex);
  uint8 columnLenght = 0;

  /* Endless loop is not possible here because the pageSize always has at least one binary digit 1. */
  while((((uint32)1u<<(columnLenght)) & pageSize) == 0u)
  {
    columnLenght++;
  }

  return columnLenght;
}

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_GetSectorIndex()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE FUNC(uint32, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_GetSectorIndex( /* PRQA S 3219 */ /* MD_CRC_2.1_StaticFunctionNotUsed */ /* COV_VMEM_30_VXSPI_NAND_UTILITYCODE_UNUSED */
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType Address)
{
  vMem_30_vXSpi_Nand_MemSectorIterType result = vMem_30_vXSpi_Nand_GetSizeOfMemSector();
  vMem_30_vXSpi_Nand_MemSectorIterType sectorIndex;
  vMem_30_vXSpi_Nand_MemSectorStartIdxOfvMemInstanceType sectorStartIndex =
      vMem_30_vXSpi_Nand_GetMemSectorStartIdxOfvMemInstance(InstanceId);
  vMem_30_vXSpi_Nand_MemSectorEndIdxOfvMemInstanceType sectorEndIndex =
      vMem_30_vXSpi_Nand_GetMemSectorEndIdxOfvMemInstance(InstanceId);

  for (sectorIndex = sectorStartIndex; sectorIndex < sectorEndIndex; sectorIndex++)
  {
    /* The address may be equal to the start address or even higher. It shall also be lower than the
     * end of the sector (batch). -1 takes care about overflows - the sector batch may be located
     * at the end of the address range. */
    vMem_30_vXSpi_Nand_AddressType sectorBatchStartAddress =
        vMem_30_vXSpi_Nand_GetStartAddressOfMemSector(sectorIndex);
    vMem_30_vXSpi_Nand_AddressType sectorBatchEndAddress = vMem_30_vXSpi_Nand_GetSectorEndAddress(sectorIndex);

    if ((Address >= sectorBatchStartAddress) && (Address <= sectorBatchEndAddress))
    {
      result = sectorIndex;
      break;
    }
  }
  return result;
}

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_GetSectorEndAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE FUNC(vMem_30_vXSpi_Nand_AddressType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_GetSectorEndAddress( /* PRQA S 3219 */ /* MD_CRC_2.1_StaticFunctionNotUsed */ /* COV_VMEM_30_VXSPI_NAND_UTILITYCODE_UNUSED */
  vMem_30_vXSpi_Nand_MemSectorIterType SectorIndex
)
{
  vMem_30_vXSpi_Nand_AddressType sectorBatchEndAddress;
  vMem_30_vXSpi_Nand_AddressType sectorBatchStartAddress =
      vMem_30_vXSpi_Nand_GetStartAddressOfMemSector(SectorIndex);
  vMem_30_vXSpi_Nand_NrOfSectorsOfMemSectorType sectorBatchNumberOfSectors =
      vMem_30_vXSpi_Nand_GetNrOfSectorsOfMemSector(SectorIndex);
  vMem_30_vXSpi_Nand_SectorSizeOfMemSectorType sectorSize =
      vMem_30_vXSpi_Nand_GetSectorSizeOfMemSector(SectorIndex);
  vMem_30_vXSpi_Nand_LengthType sectorBatchSize;

  sectorBatchSize = (vMem_30_vXSpi_Nand_LengthType)sectorBatchNumberOfSectors * sectorSize;
  sectorBatchEndAddress = sectorBatchStartAddress + ((vMem_30_vXSpi_Nand_AddressType)sectorBatchSize - 1u);

  return sectorBatchEndAddress;
}

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_ConvertAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_INTSHARED_LOCAL_INLINE FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_ConvertAddress( /* PRQA S 3219 */ /* MD_CRC_2.1_StaticFunctionNotUsed */ /* COV_VMEM_30_VXSPI_UTILITYCODE_UNUSED */
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType Address,
  vMem_30_vXSpi_Nand_ConvertedAddressPtrType ConvertedAddressPtr
)
{
  uint8 columnAddressLength = vMem_30_vXSpi_Nand_GetColumnAddressLength(InstanceId, Address);

  ConvertedAddressPtr->PageAddress = (vMem_30_vXSpi_Nand_FlsAddressType)(Address >> columnAddressLength);
  ConvertedAddressPtr->ColumnAddress = (uint16)VMEM_30_VXSPI_NAND_COLUMN_ADDRESS_BITMASK(columnAddressLength) & ((vMem_30_vXSpi_Nand_FlsAddressType)Address);
  ConvertedAddressPtr->SectorStartAddress = (ConvertedAddressPtr->PageAddress) & VMEM_30_VXSPI_NAND_SECTOR_ADDRESS_BITMASK;
}/* vMem_30_vXSpi_Nand_ConvertAddress */

# define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_INTSHARED_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_IntShared.h
 *********************************************************************************************************************/
