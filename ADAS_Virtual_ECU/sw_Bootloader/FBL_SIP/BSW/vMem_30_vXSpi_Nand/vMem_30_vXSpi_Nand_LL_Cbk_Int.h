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
/*!        \file  vMem_30_vXSpi_Nand_LL_Cbk_Int.h
 *        \brief  -
 *
 *      \details  Defines vMem_30_vXSpi_Nand_LL callbacks for internal notification about finished jobs.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_LL_CBK_INT_H)
# define VMEM_30_VXSPI_NAND_LL_CBK_INT_H

/*********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_InitSucceeded()
 *********************************************************************************************************************/
/*! \brief        Trigger the previously setup user job.
 *  \details      Calls local function to execute previously store user job.
 *  \param[in]    InstanceId       Index of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_vXSpi_Nand_CODE) vMem_30_vXSpi_Nand_LL_Cbk_InitSucceeded(
  vMem_30_vXSpi_Nand_InstanceIdType instanceId
  );

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_SequenceEndNotification()
 *********************************************************************************************************************/
/*! \brief        Callback service to notify the vMem module about a finished sequence.
 *  \details      -
 *  \param[in]    InstanceId      Id and index of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_Cbk_SequenceEndNotification(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_JobFinished()
 *********************************************************************************************************************/
/*! \brief        Notifies the vMem_30_vXSpi_Nand_LL about a finished job and handles further actions.
 *  \details      Resets the jobProgress, saves JobResult and JobError if no further actions are required.
 *                Triggers subsequent sub state machines if further jobs shall be executed automatically. 
 *  \param[in]    InstanceId       Index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]    JobResult        vMem job result of the finished job.
 *  \param[in]    JobError         Error type of the finished job.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_JobResultType JobResult,
  vMem_30_vXSpi_Nand_JobErrorType JobError);

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_LL_CBK_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_Cbk_Int.h
 *********************************************************************************************************************/
