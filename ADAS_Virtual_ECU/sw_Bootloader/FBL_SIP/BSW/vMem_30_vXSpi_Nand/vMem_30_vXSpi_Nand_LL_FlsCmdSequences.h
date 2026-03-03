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
/*!        \file  vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h
 *        \brief  Flash command sequences header file
 *
 *      \details  The vMem_30_vXSpi_Nand_LL_FlsCmdSequences implements the generation and execution of the
 *                necessary flash command sequences for the interaction with the flash device.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_LL_FLSCMDSEQUENCES_H)
# define  VMEM_30_VXSPI_NAND_LL_FLSCMDSEQUENCES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define  VMEM_30_VXSPI_NAND_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteEnableSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the write enable command sequence.
 *  \details     This function sets up the write enable transaction by the underlying vXSpi driver
 *               for the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteEnableSequence(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteEraseSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the erase command sequence for erase access.
 *  \details     This function sets up the erase transaction by the underlying vXSpi driver
 *               for the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   TargetAddress       Address of the nv sector that shall be erased.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteEraseSequence(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecutePageDataReadSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the page data read command sequence for read access.
 *  \details     This function sets up the page data read transaction by the underlying vXSpi. This sequence is used
 *               to transfer the data of a specified memory page into the Data Buffer of the flash device.
 *               The flash device is identified by the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   SourceAddress       Address to read from.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecutePageDataReadSequence(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType SourceAddress);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the read command sequence for read access.
 *  \details     This functions sets up the read transaction by the underlying vXSpi. This sequence is used
 *               to read data from the Data Buffer of the flash device identified by the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   SourceAddress       Address to read from.
 *  \param[in]   TargetAddressPtr    Application pointer to buffer to write to.
 *  \param[in]   Length              Length to be read.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadSequence(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType SourceAddress,
  vMem_30_vXSpi_Nand_vXSpiDataPtrType TargetAddressPtr,
  vMem_30_vXSpi_Nand_vXSpiDataLengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramDataLoadSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the program data load command sequence for write access.
 *  \details     This function sets up the program data load transaction by the underlying vXSpi. This sequence
 *               is used to load the data into the Data Buffer of the flash device identified by the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   TargetAddress       Address to write to.
 *  \param[in]   SourceAddressPtr    Application pointer to buffer with data to write to the Data Buffer of the 
 *                                   flash device.
 *  \param[in]   Length              Length to write.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramDataLoadSequence(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress,
  vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType SourceAddressPtr,
  vMem_30_vXSpi_Nand_vXSpiDataLengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramExecuteSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the program execute command sequence for write access.
 *  \details     This function sets up the program data load transaction by the underlying vXSpi. This sequence
 *               is used to write data from the Data Buffer to the specified memory address of the flash device
 *               identified by the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   TargetAddress       NV memory address to write to.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramExecuteSequence(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadBbmLutSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the read BBM LUT command sequence for reading the look up table used for bad block management.
 *  \details     This function sets up the read bad block management look up table transaction by the underlying vXSpi.
 *               This sequence is used to read the look up table with the links between replaced
 *               and replacement sectors of the flash device identified by the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   TargetAddress       Address (die index) of Look Up Table to be read.
 *  \param[in]   TargetAddressPtr    Application pointer to buffer to write to.
 *  \param[in]   Length              Length to be read.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadBbmLutSequence(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress,
  vMem_30_vXSpi_Nand_vXSpiDataPtrType TargetAddressPtr,
  vMem_30_vXSpi_Nand_vXSpiDataLengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the command sequence for reading the status register of the flash device.
 *  \details     This function sets up the read status register transaction by the underlying vXSpi.
 *               prepared sequence of commands that is used to read the status register of the flash device 
 *               identified by the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   SourceAddress       Address of the status register that shall be read.
 *  \param[in]   TargetAddressPtr    Application pointer to buffer the register content is written to.
 *  \param[in]   Length              Length of the status register that shall be read.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType SourceAddress,
    vMem_30_vXSpi_Nand_vXSpiDataPtrType TargetAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length);
    
/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadVolatileConfigurationRegisterSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the command sequence for reading the volatile configuration register of the flash device.
 *  \details     This function sets up the read volatile configuration register transaction by the underlying vXSpi.
 *               prepared sequence of commands that is used to read the volatile configuration register of the flash device 
 *               identified by the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   SourceAddress       Address of the volatile configuration register that shall be read.
 *  \param[in]   TargetAddressPtr    Application pointer to buffer the register content is written to.
 *  \param[in]   Length              Length of the volatile configuration register that shall be read.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadVolatileConfigurationRegisterSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType SourceAddress,
    vMem_30_vXSpi_Nand_vXSpiDataPtrType TargetAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteStatusRegisterSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the command sequence for writing to the status register of the flash device.
 *  \details     This function sets up the write status register transaction by the underlying vXSpi.
 *               This sequence is used to write to the status register of the  flash device identified
 *               by the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   TargetAddress       Address of the status register that shall be written to.
 *  \param[in]   SourceAddressPtr    Application pointer to buffer with data to write to the status register of the
 *                                   flash device.
 *  \param[in]   Length              Length of the status register that shall be written.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteStatusRegisterSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetAddress,
    vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType SourceAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteVolatileConfigurationRegisterSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the command sequence for writing to the volatile configuration register of the flash device.
 *  \details     This function sets up the write volatile configuration register transaction by the underlying vXSpi.
 *               This sequence is used to write to the volatile configuration register of the  flash device identified
 *               by the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   TargetAddress       Address of the volatile configuration register that shall be written to.
 *  \param[in]   SourceAddressPtr    Application pointer to buffer with data to write to the volatile configuration register of the
 *                                   flash device.
 *  \param[in]   Length              Length of the volatile configuration register that shall be written.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteVolatileConfigurationRegisterSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetAddress,
    vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType SourceAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReplaceSectorSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the command sequence for replacing a sector of the flash device.
 *  \details     This function sets up the replace sector transaction by the underlying vXSpi.
 *               This transaction is used to replace a broken sector of the flash device.
 *  \param[in]   InstanceId                ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   TargetSectorAddress       Address of the broken sector which shall be replaced.
 *  \param[in]   ReplacingSectorAddress    Address of the sector which shall be used to replace the broken sector.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReplaceSectorSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetSectorAddress,
    vMem_30_vXSpi_Nand_AddressType ReplacingSectorAddress);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence()
 *********************************************************************************************************************/
/*! \brief       Executes the command sequence for selecting a die of the flash device.
 *  \details     This function sets up the the die select transaction by the underlying vXSpi.
 *               This transaction is used to select a die of the flash device.
 *  \param[in]   InstanceId                ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   DieIndex                  Index of the die that needs to be selected.
 *  \return      E_OK - Sequence successfully executed
 *  \return      E_NOT_OK - Sequence could not be executed. Other sequence is pending.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DieIndexType DieIndex);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetResult()
 *********************************************************************************************************************/
/*! \brief       Returns the result of the sequence for the given instance Id.
 *  \details     This function returns the result of the sequence for the given instance Id.
 *  \param[in]   InstanceId                ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \return      Current result of the sequence.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(vMem_30_vXSpi_Nand_FlsCmdSequenceResultType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetResult(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_Processing()
 *********************************************************************************************************************/
/*! \brief       Processes the sequences.
 *  \details     This function processes the sequences of given instance.
 *  \return      Current result of the sequence.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_Processing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

# define  VMEM_30_VXSPI_NAND_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /*  VMEM_30_VXSPI_NAND_LL_FLSCMDSEQUENCES_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h
 *********************************************************************************************************************/
