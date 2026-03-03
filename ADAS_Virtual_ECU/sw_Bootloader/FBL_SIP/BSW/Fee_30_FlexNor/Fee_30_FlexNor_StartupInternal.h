/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_StartupInternal.h
 *        \brief  Internal startup business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the startup implementation.
 *         \unit  Startup
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_STARTUPINTERNAL_H)
# define FEE_30_FLEXNOR_STARTUPINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Sector.h"
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(struct Fee_30_FlexNor_Startup_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Startup_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_Startup_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Startup_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_Startup_ProcessEvt)(Fee_30_FlexNor_Startup_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Startup_FailEvt)(Fee_30_FlexNor_Startup_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_Startup_State
{
    Fee_30_FlexNor_Startup_ProcessEvt ProcessEvent;     /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_Startup_FailEvt FailEvent;           /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_Startup_StateType;                     /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_Startup_StateType, AUTOMATIC) Fee_30_FlexNor_Startup_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_Startup_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Startup_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_Startup_Context
{
    Fee_30_FlexNor_Startup_ConstStatePtrType CurrentState;           /*!< Current state of the state machine */
    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig;      /*!< Partition for which the startup shall be performed */
    Fee_30_FlexNor_SectorPtrType NextSectorToProcess;                /*!< Pointer to the next sector that shall be read. NULL in case there is no further sector */
    Fee_30_FlexNor_ResultCallback ResultCallback;                    /*!< Result callback that is used to communicate the service result back to the caller */
    boolean LoadingLutSucceeded;                                     /*!< Indicates if the lut was loaded successfuly */
} Fee_30_FlexNor_Startup_ContextType;                                /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_ReadNextSectorHeader()
 *********************************************************************************************************************/
/*! \brief       Read the next sector header.
 *  \details     -
 *  \param[in]   ctx               Context of the service the sector header read shall be triggered for.
 *                                 Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_ReadNextSectorHeader(Fee_30_FlexNor_Startup_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_TriggerLutLoading()
 *********************************************************************************************************************/
/*! \brief       Triggers the loading of the lookup table.
 *  \details     -
 *  \param[in]   ctx               Context of the service the lookup table loading shall be triggered for.
 *                                 Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_TriggerLutLoading(Fee_30_FlexNor_Startup_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Startup_TriggerLutRecovery()
 *********************************************************************************************************************/
/*! \brief       Triggers the recovery of the lookup table.
 *  \details     -
 *  \param[in]   ctx               Context of the service the lookup table recovery shall be triggered for.
 *                                 Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Startup_TriggerLutRecovery(Fee_30_FlexNor_Startup_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_CHUNKINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkInternal.h
 *********************************************************************************************************************/
