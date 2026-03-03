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
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceModifier.h
 *        \brief  Instance modifier header file
 *
 *      \details  The vMem_30_vXSpi_Nand_LL_InstanceModifier implements the state machine for write and erase jobs.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MULTIPLE INCLUSION PROTECTION
 *********************************************************************************************************************/
#if !defined (VMEM_30_VXSPI_NAND_LL_INSTANCEMODIFIER_H)
# define VMEM_30_VXSPI_NAND_LL_INSTANCEMODIFIER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformWriteAccess()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to perform a memory write access at the external flash device.
 *  \details      -
 *  \param[in]    InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \param[in]    TargetAddress       NV memory address to write to, must be valid.
 *  \param[in]    SourceAddressPtr    Application pointer to buffer with data to write to nv memory.
 *                                    Must stay valid until job is completed.
 *  \param[in]    Length              Length in bytes to write, must be valid.
 *  \return       E_OK job accepted, E_NOT_OK otherwise.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformWriteAccess(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId, vMem_30_vXSpi_Nand_AddressType TargetAddress,
    vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType SourceAddressPtr, vMem_30_vXSpi_Nand_LengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformEraseAccess()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to perform a memory erase access at the external flash device.
 *  \details      -
 *  \param[in]    InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \param[in]    TargetAddress       NV memory address to be erased, must be valid.
 *  \return       E_OK job accepted, E_NOT_OK otherwise.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformEraseAccess(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId, vMem_30_vXSpi_Nand_AddressType TargetAddress);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_Processing()
 *********************************************************************************************************************/
/*! \brief        Processes the write or erase operation for the requested instance.
 *  \details      -
 *  \param[in]    InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_Processing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_LL_INSTANCEMODIFIER_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceModifier.h
 *********************************************************************************************************************/
