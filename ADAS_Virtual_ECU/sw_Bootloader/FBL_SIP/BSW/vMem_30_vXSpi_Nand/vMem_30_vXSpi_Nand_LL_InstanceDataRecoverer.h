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
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer.h
 *        \brief  Instance data recoverer header file
 *
 *      \details  The vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer implements the state machine for dataRecover jobs.
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
#if !defined (VMEM_30_VXSPI_NAND_LL_INSTANCE_DATA_RECOVERER_H)
# define VMEM_30_VXSPI_NAND_LL_INSTANCE_DATA_RECOVERER_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_PerformRecoverData()
 *********************************************************************************************************************/
/*! \brief        Initializes all relevant values for the processed instance to recover data and start the recover
                  data operation.
 *  \details      -
 *  \param[in]    InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \param[in]    SourceAddress       Startaddresses of the sector from which data should be recovered.
 *  \param[in]    TargetAddress       Startaddresses of the sector to which the data should be recovered.
 *  \return       E_OK job accepted, E_NOT_OK otherwise.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_PerformRecoverData(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType SourceAddress,
    vMem_30_vXSpi_Nand_AddressType TargetAddress);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_Processing()
 *********************************************************************************************************************/
/*! \brief        Processes the recover data operation for the requested instance.
 *  \details      -
 *  \param[in]    InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_Processing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_LL_INSTANCE_DATA_RECOVERER_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer.h
 *********************************************************************************************************************/
