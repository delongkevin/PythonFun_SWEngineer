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
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer.h
 *        \brief  Instance secotr replacer header file
 *
 *      \details  The vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer implements the state machine for replaceLogicalSector 
 *                jobs
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
#if !defined (VMEM_30_VXSPI_NAND_LL_INSTANCE_SECTOR_REPLACER_H)
# define VMEM_30_VXSPI_NAND_LL_INSTANCE_SECTOR_REPLACER_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_PerformReplaceLogicalSector()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to perform a replace logical sector access at the external
                  flash device.
 *  \details      -
 *  \param[in]    
 *  \return       E_OK job accepted, E_NOT_OK otherwise.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_PerformReplaceLogicalSector(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_ReplaceSectorPtrType ReqSpecificData);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_Processing()
 *********************************************************************************************************************/
/*! \brief        Processes the replace logical sector operation for the requested instance.
 *  \details      -
 *  \param[in]    InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_Processing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_LL_INSTANCE_SECTOR_REPLACER_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer.h
 *********************************************************************************************************************/
