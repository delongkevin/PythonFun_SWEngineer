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
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor.h
 *        \brief  Instance read accessor header file
 *
 *      \details  The vMem_30_vXSpi_Nand_LL_InstanceReadAccessor implements the state machine for read jobs.
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
#if !defined (VMEM_30_VXSPI_NAND_LL_INSTANCEREADACCESSOR_H)
# define VMEM_30_VXSPI_NAND_LL_INSTANCEREADACCESSOR_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_PerformReadAccess()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to perform a memory read access at the external flash device.
 *  \details      -
 *  \param[in]    InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \param[in]    SourceAddress       NV memory address to read from, must be valid.
 *  \param[in]    TargetAddressPtr    Application pointer to buffer where the data should be read to.
 *                                    Must stay valid until job is completed.
 *  \param[in]    Length              Length in bytes to read, must be valid.
 *  \return       E_OK job accepted, E_NOT_OK otherwise.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_PerformReadAccess(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId, vMem_30_vXSpi_Nand_AddressType SourceAddress,
    vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType TargetAddressPtr, vMem_30_vXSpi_Nand_LengthType Length);


/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_Processing()
 *********************************************************************************************************************/
/*! \brief        Processes the read operation for the requested instance.
 *  \details      -
 *  \param[in]    InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_Processing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_LL_INSTANCEREADACCESSOR_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceReadAccessor.h
 *********************************************************************************************************************/
