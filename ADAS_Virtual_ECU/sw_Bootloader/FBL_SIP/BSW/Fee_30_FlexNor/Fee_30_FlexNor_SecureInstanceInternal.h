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
/*!        \file  Fee_30_FlexNor_SecureInstanceInternal.h
 *        \brief  Internal secure instance business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the secure instance implementation.
 *         \unit  SecureInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_SECUREINSTANCEINTERNAL_H)
# define FEE_30_FLEXNOR_SECUREINSTANCEINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Instance.h"
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
typedef struct Fee_30_FlexNor_SecureInstance
{
    Fee_30_FlexNor_InstanceDataPtrType InstanceData;            /*!< Pointer to the generic instance data. */
    Fee_30_FlexNor_ConstInstanceDataPtrType ConstInstanceData;  /*!< Pointer to the const generic instance data. */
    Fee_30_FlexNor_MarkerType StartMarker;                      /*!< Stores the start marker of the instance. */
    Fee_30_FlexNor_MarkerType SealMarker;                       /*!< Stores the seal marker of the instance. */
    Fee_30_FlexNor_MarkerType CommitMarker;                     /*!< Stores the commit marker of the instance. */
} Fee_30_FlexNor_SecureInstanceType;                            /*!< Holds all information about the data used by the concrete type. */

typedef struct P2VAR(Fee_30_FlexNor_SecureInstance_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SecureInstance_ContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_SecureInstance_ProcessEvt)(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_SecureInstance_FailEvt)(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_SecureInstance_State
{
    Fee_30_FlexNor_SecureInstance_ProcessEvt ProcessEvent;     /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_SecureInstance_FailEvt FailEvent;           /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_SecureInstance_StateType;                     /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_SecureInstance_StateType, AUTOMATIC) Fee_30_FlexNor_SecureInstance_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_SecureInstance_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SecureInstance_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_SecureInstance_Context
{
    Fee_30_FlexNor_SecureInstance_ConstStatePtrType CurrentState;   /*!< Current state of the state machine */   

    Fee_30_FlexNor_SecureInstanceType Instance;                     /*!< Secure instance data the unit operates on. */
    Fee_30_FlexNor_DataPtrType InstanceBuffer;                      /*!< Internal buffer to store the instance metadata read from flash. */
    Fee_30_FlexNor_LengthType PayloadWritten;                       /*!< Represents the amount of payload that was already written to flash. */ 
    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig;          /*!< Pointer to the partition configuration of the processed instance. */
        
    Fee_30_FlexNor_ResultCallback ResultCallback;                   /*!< Result callback that is used to communicate the service result back to the caller. */   
} Fee_30_FlexNor_SecureInstance_ContextType;                        /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata()
 *********************************************************************************************************************/
/*! \brief       Reads the instance metadata from flash.
 *  \details     -
 *  \param[in]   ctx        Context the instance metadata shall be read in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata()
 *********************************************************************************************************************/
/*! \brief       Validates the instance metadata
 *  \details     Validates the instance metadata previously read from flash.
 *  \param[in]   ctx            Context that contains the read metadata that shall be validated. Must not be NULL.
 *  \pre         Instance metdata must be read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteStartMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the start marker of the instance to flash
 *  \details     -
 *  \param[in]   ctx             Context that contains the instance the start marker shall be written for. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteStartMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WritePayloadStart()
 *********************************************************************************************************************/
/*! \brief       Write the first chunk of payload data
 *  \details     Write the first chunk of payload to flash, including the instance status.
 *  \param[in]   ctx             Context that contains the instance status and payload that shall be written to flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WritePayloadStart(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WritePayload()
 *********************************************************************************************************************/
/*! \brief       Writes the rest of the instance payload to flash
 *  \details     -
 *  \param[in]   ctx             Context that contains the payload that shall be written to flash. Must not be NULL.
 *  \pre         The instance status was already written to flash and there is payload left to write
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WritePayload(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteSealMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the seal marker of the instance to flash
 *  \details     -
 *  \param[in]   ctx             Context that contains the instance the seal marker shall be written for. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteSealMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the commit marker of the instance to flash
 *  \details     -
 *  \param[in]   ctx             Context that contains the instance the commit marker shall be written for. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteCommitMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStatus()
 *********************************************************************************************************************/
/*! \brief       Reads the instance status from flash.
 *  \details     -
 *  \param[in]   ctx               Context that contains the informations about the instance thats status shall be read. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStatus(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ParseInstanceStatus()
 *********************************************************************************************************************/
/*! \brief       Parses the instance status from the read instance content
 *  \details     -
 *  \param[in]   ctx               Context that contains the target instance and the buffer with the read content. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ParseInstanceStatus(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadPayload()
 *********************************************************************************************************************/
/*! \brief       Read the instance payload from flash.
 *  \details     -
 *  \param[in]   ctx               Context that contains the informations about the instance thats payload shall be read. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadPayload(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SECUREINSTANCEINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureInstanceInternal.h
 *********************************************************************************************************************/
