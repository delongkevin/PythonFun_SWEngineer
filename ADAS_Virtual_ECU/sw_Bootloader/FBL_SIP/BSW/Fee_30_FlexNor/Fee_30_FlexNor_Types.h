/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_Types.h
 *        \brief  Fee_30_FlexNor types header file
 *         \unit  Fee
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_TYPES_H)
#define FEE_30_FLEXNOR_TYPES_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fls.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/* DET and runtime error types */
typedef enum 
{
    FEE_30_FLEXNOR_E_NO_ERROR                    = (0x00u),  /*!< No error was detected during check */
    FEE_30_FLEXNOR_E_UNINIT                      = (0x01u),  /*!< API service called when module was not initialized */
    FEE_30_FLEXNOR_E_INVALID_BLOCK_NO            = (0x02u),  /*!< API service called with invalid block number */
    FEE_30_FLEXNOR_E_INVALID_BLOCK_OFS           = (0x03u),  /*!< API service called with invalid block offset */
    FEE_30_FLEXNOR_E_PARAM_POINTER               = (0x04u),  /*!< API service called with invalid data pointer */
    FEE_30_FLEXNOR_E_INVALID_BLOCK_LEN           = (0x05u),  /*!< API service called with invalid length information */
    FEE_30_FLEXNOR_E_BUSY                        = (0x06u),  /*!< API service called while module is busy */
    FEE_30_FLEXNOR_E_INVALID_CANCEL              = (0x08u),  /*!< Cancel called although the module is not busy */
    FEE_30_FLEXNOR_E_INIT_FAILED                 = (0x09u),  /*!< Init function failed */
    FEE_30_FLEXNOR_E_INVALID_PARTITION_ID        = (0x09u)   /*!< API service called with invalid partition id */
} Fee_30_FlexNor_DetErrorCode;

/* ----- API service IDs ----- */
typedef enum
{
    FEE_30_FLEXNOR_SID_INIT                        = (0x00u),  /*!< Service ID: Fee_30_FlexNor_Init() */
    FEE_30_FLEXNOR_SID_SETMODE                     = (0x01u),  /*!< Service ID: Fee_30_FlexNor_SetMode() */
    FEE_30_FLEXNOR_SID_READ                        = (0x02u),  /*!< Service ID: Fee_30_FlexNor_Read() */
    FEE_30_FLEXNOR_SID_WRITE                       = (0x03u),  /*!< Service ID: Fee_30_FlexNor_Write() */
    FEE_30_FLEXNOR_SID_CANCEL                      = (0x04u),  /*!< Service ID: Fee_30_FlexNor_Cancel() */
    FEE_30_FLEXNOR_SID_GET_STATUS                  = (0x05u),  /*!< Service ID: Fee_30_FlexNor_GetStatus() */
    FEE_30_FLEXNOR_SID_GET_JOB_RESULT              = (0x06u),  /*!< Service ID: Fee_30_FlexNor_GetJobResult() */
    FEE_30_FLEXNOR_SID_INVALIDATEBLOCK             = (0x07u),  /*!< Service ID: Fee_30_FlexNor_InvalidateBlock() */
    FEE_30_FLEXNOR_SID_GET_VERSION_INFO            = (0x08u),  /*!< Service ID: Fee_30_FlexNor_GetVersionInfo() */
    FEE_30_FLEXNOR_SID_ERASEIMMEDIATEBLOCK         = (0x09u),  /*!< Service ID: Fee_30_FlexNor_EraseImmediateBlock() */
    FEE_30_FLEXNOR_SID_MAIN_FUNCTION               = (0x12u),  /*!< Service ID: Fee_30_FlexNor_MainFunction() */
    FEE_30_FLEXNOR_SID_PERSIST_LOOKUP_TABLE        = (0x13u)   /*!< Service ID: Fee_30_FlexNor_PersistLookupTable() */
} Fee_30_FlexNor_ServiceId;

/* General types */
typedef enum
{
    FEE_30_FLEXNOR_FAIL,    /*!< The requested operation failed */
    FEE_30_FLEXNOR_OK,      /*!< The requested operation was completed successfully */
    FEE_30_FLEXNOR_PENDING  /*!< The requested operation is still pending */
}Fee_30_FlexNor_ResultType; /*!< Result type for internal operations */

typedef enum
{
    FEE_30_FLEXNOR_INVALID, /*!< The structure in flash is invalid, i.e. wasn't written correctly */
    FEE_30_FLEXNOR_VALID,   /*!< The structure in flash is valid */
    FEE_30_FLEXNOR_EMPTY    /*!< The structure was not written at all, i.e. the flash is still erased */
}Fee_30_FlexNor_StructureValidityType;

typedef enum
{
    FEE_30_FLEXNOR_SERVICE_FAIL,    /*!< The service failed */
    FEE_30_FLEXNOR_SERVICE_OK,      /*!< The service ended successfully */
    FEE_30_FLEXNOR_SERVICE_NOT_OK   /*!< The service ended with a negative result */
}Fee_30_FlexNor_ServiceResult;

typedef enum 
{
    FEE_30_FLEXNOR_SECURELAYOUT = 1, /*!< Secure layout is used */
    FEE_30_FLEXNOR_SLIMLAYOUT = 2    /*!< Slim layout is used */
}Fee_30_FlexNor_LayoutOptionType;

typedef P2VAR(Std_VersionInfoType, AUTOMATIC, FEE_30_FLEXNOR_APPL_VAR) Fee_30_FlexNor_VersionInfoPtrType;

typedef P2VAR(Fee_30_FlexNor_ResultType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ResultPtrType;
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_ResultCallback)(Fee_30_FlexNor_ServiceResult result);

typedef uint8 Fee_30_FlexNor_PartitionIdType;       /* Type of the partition id. Valid for all values up to the number of configured partitions. */
typedef uint8 Fee_30_FlexNor_ChecksumType;
typedef uint8 Fee_30_FlexNor_SectorIdType;          /* Type of the sector id. Valid for all values up to the number of configured sectors. */
typedef uint16 Fee_30_FlexNor_BlockNumberType;
typedef uint16 Fee_30_FlexNor_BlockIdType;
typedef uint16 Fee_30_FlexNor_BlockOffsetType;
typedef uint16 Fee_30_FlexNor_PayloadSizeType;
typedef uint32 Fee_30_FlexNor_PayloadIndexType;

typedef uint32 Fee_30_FlexNor_PagebasedOffsetType;   /* Relative page based offset */
typedef uint32 Fee_30_FlexNor_ChunkLocationType;     /* Combines the sector id and page based inner sector chunk offset to one type */
typedef uint8 Fee_30_FlexNor_FlagContainerType;      /* Container type for managing bit flags */

typedef P2VAR(Fee_30_FlexNor_ChunkLocationType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ChunkLocationPtrType;
typedef P2VAR(Fee_30_FlexNor_FlagContainerType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_FlagContainerPtrType;

/* State machine types */
typedef enum
{
    FEE_30_FLEXNOR_STOP_SCHEDULE,       /*!< Stop the scheduling */
    FEE_30_FLEXNOR_CONTINUE_SCHEDULE    /*!< Continue with the scheduling */
}Fee_30_FlexNor_ScheduleBehaviorType;   /*!< Controls the behavior of the scheduler */

typedef enum
{
    FEE_30_FLEXNOR_IDLE,            /*!< The component is idle */
    FEE_30_FLEXNOR_BUSY,            /*!< The component is busy */
    FEE_30_FLEXNOR_CANCELLING       /*!< The component is busy with processing a job that shall be cancelled */
}Fee_30_FlexNor_StatusType;         /*!< Encodes the internal component state */

/* Structure types */
typedef uint32 Fee_30_FlexNor_MarkerType;
typedef CONST(Fee_30_FlexNor_MarkerType, AUTOMATIC) Fee_30_FlexNor_MarkerConstType;

/* Flash related types */
typedef uint32 Fee_30_FlexNor_AddressType;
typedef uint32 Fee_30_FlexNor_LengthType;
typedef uint8 Fee_30_FlexNor_DataType;

typedef P2VAR(Fee_30_FlexNor_DataType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_DataPtrType;
typedef P2CONST(Fee_30_FlexNor_DataType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstDataPtrType;

typedef P2CONST(void, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstParamPtrType;

/* Job related types  */
typedef struct Fee_30_FlexNor_Job
{
    Fee_30_FlexNor_ServiceId Service;                               /*!< Type of job currently processing or which was last processed. */
    Fee_30_FlexNor_PartitionIdType PartitionId;                     /*!< Id of the partition the current job runs in */
    Fee_30_FlexNor_BlockIdType BlockId;                             /*!< Id of the block that is affected by the current job */
    Fee_30_FlexNor_LengthType Length;                               /*!< Length of the data that shall be read or written in bytes */

    /* Read data */
    Fee_30_FlexNor_LengthType Offset;                               /*!< Read offset in bytes */
    Fee_30_FlexNor_DataPtrType ReadBuffer;                          /*!< Pointer to the block read buffer */

    /* Write data */
    Fee_30_FlexNor_ConstDataPtrType WriteBuffer;                    /*!< Pointer to the block write buffer */

    /* Job result */
    MemIf_JobResultType JobResult;                                  /*!< Job Result */
} Fee_30_FlexNor_JobType;                                           /*!< Represents the context for the current job */

typedef P2VAR(struct Fee_30_FlexNor_Job, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_JobPtrType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif  /* FEE_30_FLEXNOR_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Types.h
 **********************************************************************************************************************/
