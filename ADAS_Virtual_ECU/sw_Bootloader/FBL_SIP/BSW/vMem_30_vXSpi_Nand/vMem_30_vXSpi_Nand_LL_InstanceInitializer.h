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
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceInitializer.h
 *        \brief  Instance initializer header file
 *
 *      \details  The Hw initializer is responsible of initializing the underlying flash device.
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
#if !defined (VMEM_30_VXSPI_NAND_LL_INSTANCEINITIALIZER_H)
# define VMEM_30_VXSPI_NAND_LL_INSTANCEINITIALIZER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized()
 *********************************************************************************************************************/
/*! \brief        Indicates if the requested instance is already initialized or not.
 *  \details      -
 *  \param[in]    InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \return       TRUE                The instance is initialized.
 *  \return       FALSE               The instance is not yet initialized.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(boolean, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_Init()
 *********************************************************************************************************************/
/*! \brief        Initializes all internal parameters of this sub-component Hw initializer.
 *  \details      -
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_Init(void);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance()
 *********************************************************************************************************************/
/*! \brief        Triggers the Hw initialization for the passed instance.
 *  \details      -
 *  \param[in]    InstanceId         ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \return       E_OK               The instance is initialized.
 *  \return       E_NOT_OK           The instance is not yet initialized.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_Processing()
 *********************************************************************************************************************/
/*! \brief        This function is cyclically called. It's processing the instance-specific Hw initialization.
 *  \details      -
 *  \param[in]    InstanceId         ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_Processing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_LL_INSTANCEINITIALIZER_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceInitializer.h
 *********************************************************************************************************************/
