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
/*!        \file  Fee_30_FlexNor_Sector.h
 *        \brief  Generic sector interface
 *      \details  Provides the sector definition and services.
 *         \unit  Sector
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_SECTOR_H)
# define FEE_30_FLEXNOR_SECTOR_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Fee_30_FlexNor_Types.h"
# include "Fee_30_FlexNor_Chunk.h"
# include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum 
{
    FEE_30_FLEXNOR_GC_REASON_SPACE = 1,             /*!< Garbage collection to get new space ("normal" garbage collection). */
    FEE_30_FLEXNOR_GC_REASON_RECOVERY = 2           /*!< Garbage collection to get some errors in one sector. */
} Fee_30_FlexNor_GcReasonType;

typedef enum
{
    FEE_30_FLEXNOR_SECTOR_ERROR_PROPERTIESINVALID,  /*!< Sector properties are invalid */
    FEE_30_FLEXNOR_SECTOR_ERROR_COMMITMARKERBROKEN, /*!< Sector commit marker is broken */
    FEE_30_FLEXNOR_SECTOR_ERROR_ERASEMARKERSET,     /*!< Sector erase marker is not empty */
    FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR             /*!< Sector metadata is valid */
} Fee_30_FlexNor_Sector_ErrorLocation;

typedef uint32 Fee_30_FlexNor_EraseCycleCounterType;

typedef struct Fee_30_FlexNor_Sector
{
    Fee_30_FlexNor_StructureValidityType Validity;      /*!< Information containing the validity of the structure */
    Fee_30_FlexNor_Sector_ErrorLocation ErrorLocation;  /*!< Describes the location of an error in case of an invalid sector */
    Fee_30_FlexNor_PartitionIdType PartitionId;         /*!< Id of the partition the sector belongs to */
    Fee_30_FlexNor_SectorIdType SectorId;               /*!< Id of the sector */
    Fee_30_FlexNor_ChunkLinkType LutChunkLink;          /*!< Link to the first LUT chunk */
    Fee_30_FlexNor_GcReasonType GcReason;               /*!< Reason why the garbage collection has been executed */
    Fee_30_FlexNor_LayoutOptionType Layout;             /*!< Layout (either secure or slim) of the sector */
    Fee_30_FlexNor_AddressType StartAddress;            /*!< Start address of the sector in flash */
    Fee_30_FlexNor_EraseCycleCounterType EraseCycle;    /*!< Number of erase operations that have been applied to this sector */
    Fee_30_FlexNor_SectorIdType SourceSectorId;         /*!< Id of the source sector */
    Fee_30_FlexNor_AddressType NextFreeAddress;         /*!< Next free address, during sector scan it may also contain a temporary next free address */
} Fee_30_FlexNor_SectorType;                            /*!< Structure which holds all public data and services */

typedef P2VAR(Fee_30_FlexNor_SectorType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SectorPtrType;
typedef P2CONST(Fee_30_FlexNor_SectorType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstSectorPtrType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the sector unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_IsUsed()
 *********************************************************************************************************************/
/*! \brief       Checks if the given sector is in use
 *  \details     -
 *  \param[in]   sector     Pointer to the sector that shall be checked. Must not be NULL.
 *  \return      TRUE       If the sector is in use.
 *               FALSE      In case the sector is available.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_IsUsed(Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadHeader()
 *********************************************************************************************************************/
/*! \brief         Reads and validates the sector header of the given sector
 *  \details       -
 *  \param[in,out] sector             Sector whose header shall be read. Must not be NULL.
 *  \param[in]     resultCbk          The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadHeader(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker()
 *********************************************************************************************************************/
/*! \brief         Writes the erase marker into the sector header of the given sector
 *  \details       -
 *  \param[in,out] sector             Sector whose erase marker shall be written. Must not be NULL.
 *  \param[in]     resultCbk          The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink()
 *********************************************************************************************************************/
/*! \brief         Writes the lut link into the sector header of the given sector
 *  \details       -
 *  \param[in,out] sector             Sector whose lut link shall be written. Must not be NULL.
 *  \param[in]     resultCbk          The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector()
 *********************************************************************************************************************/
/*! \brief         Writes the source sector into the sector header of the given sector
 *  \details       -
 *  \param[in,out] sector             Sector whose source sector shall be written. Must not be NULL.
 *  \param[in]     resultCbk          The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Allocate()
 *********************************************************************************************************************/
/*! \brief         Allocates a new sector
 *  \details       Writes sector properties, first chunk and the commit marker
 *  \param[in,out] sector             Sector that shall be allocated. Must not be NULL.
 *  \param[in]     firstChunk         First chunk that shall be allocated. Must not be NULL.
 *  \param[in]     firstInstance      First instance that shall be allocated inside the first chunk. Must not be NULL.
 *  \param[in]     predecessorChunk   Predecessor chunk of the first chunk that is allocated. May be NULL in case there is no predecessor.
 *  \param[in]     resultCbk          The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Allocate(Fee_30_FlexNor_SectorPtrType sector, 
    Fee_30_FlexNor_ChunkPtrType firstChunk, 
    Fee_30_FlexNor_InstancePtrType firstInstance, 
    Fee_30_FlexNor_ChunkPtrType predecessorChunk,
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Scan()
 *********************************************************************************************************************/
/*! \brief         Scans the given sector
 *  \details       Reads every chunk header in the sector and updates lut entries and the next free address.
 *  \param[in,out] sector             Sector that shall be scanned. Must not be NULL.
 *  \param[in]     resultCbk          The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Scan(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TryAllocateChunk()
 *********************************************************************************************************************/
/*! \brief       Tries to allocate the given chunk in the sector
 *  \details     Writes the given chunk at the next free address in the sector in case the sector is not marked for erase, the next free
 *               address is known and the chunk fits into it.
 *  \param[in,out] sector             Sector the chunk shall be allocated in. Must not be NULL.
 *  \param[in]     chunk              Chunk that shall be allocated. Must not be NULL.
 *  \param[in]     instance           First instance of the chunk that shall be allocated. Must not be NULL.
 *  \param[in]     predecessorChunk   Predecessor chunk of the chunk that shall be allocated. May be NULL in case there is no predecessor.
 *  \param[in]     resultCbk          The result call back that is called in case the service is complete. The callback is called with 
 *                                    FEE_30_FLEXNOR_SERVICE_OK in case the allocation succeeded and FEE_30_FLEXNOR_SERVICE_NOT_OK in case 
 *                                    the allocation failed because of an unfulfilled precondition. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TryAllocateChunk(Fee_30_FlexNor_SectorPtrType sector, 
    Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_InstancePtrType instance, 
    Fee_30_FlexNor_ChunkPtrType predecessorChunk,
    Fee_30_FlexNor_ResultCallback resultCbk);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SECTOR_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Sector.h
 *********************************************************************************************************************/
