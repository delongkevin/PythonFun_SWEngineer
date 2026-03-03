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
/*!        \file  vMem_30_vXSpi_Nand_LL.h
 *        \brief  vMem_30_vXSpi_Nand LowLevel header file
 *
 *      \details  The vMem_30_vXSpi_Nand LowLevel subcomponent implements all the hardware specific functionality of the
 *                vMem_30_vXSpi_Nand. It performs the actual access of the NV device. It also implements a state machine
 *                for the processing of the asynchronous jobs.
 *
 *                NOTE: For a more detailed API description please refer to vMemAccM_vMemApi.h
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_LL_H)
# define VMEM_30_VXSPI_NAND_LL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*!< Number of extended hardware specific functionality. This equals the size of the array of hardware specific functions. */
# define VMEM_30_VXSPI_NAND_EXTENDED_FUNCTION_COUNT    3u
/*!< Define for the table of hardware specific functionality. */
# define VMEM_30_VXSPI_NAND_EXTENDED_FUNCTION_TABLE    vMem_30_vXSpi_Nand_HwSpecificFunctions

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
# define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(vMemAccM_vMemHwSpecificFuncPtr, AUTOMATIC) vMem_30_vXSpi_Nand_HwSpecificFunctions[VMEM_30_VXSPI_NAND_EXTENDED_FUNCTION_COUNT];

# define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEM_30_VXSPI_NAND_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_SetProcessFlag()
 *********************************************************************************************************************/
/*! \brief       Service to set the processed flag to TRUE.
 *  \details     vMem_30_vXSpi_Nand_LL_SetProcessFlag() sets the processed flag of the vMem_30_vXSpi_Nand instance
 *               to TRUE.
 *  \param[in]   InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_SetProcessFlag(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLRead()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to read data using memcpy.
 *  \details     vMem_30_vXSpi_Nand_LLRead() returns the requested data. Parameter checks are done within core part.
 *  \param[in]   InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \param[in]   SourceAddress       NV memory address to read from, must be valid.
 *  \param[out]  TargetAddressPtr    application pointer to buffer to write to. Must stay valid until job is completed.
 *  \param[in]   Length              Length in bytes to be read, must be valid.
 *  \return      E_OK job accepted, E_NOT_OK otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLRead(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType SourceAddress,
  vMem_30_vXSpi_Nand_DataPtrType TargetAddressPtr,
  vMem_30_vXSpi_Nand_LengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLWrite()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to write data to nv memory.
 *  \details     vMem_30_vXSpi_Nand_LLWrite() writes data to nv memory. Parameter checks are done within core part.
 *  \param[in]   InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \param[in]   TargetAddress       NV memory address to write to, must be valid.
 *  \param[in]   SourceAddressPtr    application pointer to buffer with data to write to nv memory.
 *                                   Must stay valid until job is completed.
 *  \param[in]   Length              Length in bytes to write, must be valid.
 *  \return      E_OK job accepted, E_NOT_OK otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLWrite(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress,
  vMem_30_vXSpi_Nand_ConstDataPtrType SourceAddressPtr,
  vMem_30_vXSpi_Nand_LengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLErase()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to erase data from nv memory.
 *  \details     vMem_30_vXSpi_Nand_LLErase() erases data from nv memory. Parameter checks are done within core part.
 *  \param[in]   InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \param[in]   TargetAddress       NV memory address to be erased, must be valid.
 *  \param[in]   Length              Length in bytes to erase, must be valid.
 *  \return      E_OK job accepted, E_NOT_OK otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLErase(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress,
  vMem_30_vXSpi_Nand_LengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLIsBlank()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to check if a page is blank in nv memory.
 *  \details     vMem_30_vXSpi_Nand_LLIsBlank() checks if the page with the given address and length is blank, i.e valid to write to. 
 *               Parameter checks are done within core part.
 *  \param[in]   InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \param[in]   TargetAddress       Address of the flash page that is checked, must be valid.
 *  \param[in]   Length              Number of bytes to be checked (must be exactly the page size).
 *  \return      E_OK job accepted, E_NOT_OK otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLIsBlank(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress,
  vMem_30_vXSpi_Nand_LengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLGetJobResult()
 *********************************************************************************************************************/
/*! \brief       Returns the result of the last accepted job, as long as no new job is accepted.
 *  \details     -
 *  \param[in]   InstanceId          ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 *  \return      Current job result.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(vMem_30_vXSpi_Nand_JobResultType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLGetJobResult(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLProcessing()
 *********************************************************************************************************************/
/*! \brief       Processes the vMem_30_vXSpi_Nand LowLevel state machine, returns when done.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLProcessing(void);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLInit()
 *********************************************************************************************************************/
/*! \brief       Initializes LowLevel part of component.
 *  \details     -
 *  \return      E_OK initialization successful, E_NOT_OK initialization failed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLInit(void);

# define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_LL_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL.h
 *********************************************************************************************************************/
