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
/*!        \file  Fee_30_FlexNor_SlimChunk.h
 *        \brief  Slim chunk interface
 *      \details  Provides the slim layout specific chunk services.
 *         \unit  SlimChunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_SLIMCHUNK_H)
# define FEE_30_FLEXNOR_SLIMCHUNK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Chunk.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the chunk unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadHeader()
 *********************************************************************************************************************/
/*! \brief          Read the chunk header and validate it. The chunk header consists of metadata and the chunk link.
 *  \details        -
 *  \param[in,out]  chunk                  Pointer to the chunk whose header shall be read and validated. Must not be NULL.
 *  \param[in]      resultCbk              The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadHeader(
    Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetHeaderSize()
 *********************************************************************************************************************/
/*! \brief          Get the size of the header. Includes metadata and chunk link.
 *  \details        -
 *  \param[in]      chunk                  Pointer to the chunk whose header size shall be calculated. Must not be NULL.
 *  \pre            -
 *  \return         Size of the header in bytes.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetHeaderSize(
    Fee_30_FlexNor_ConstChunkPtrType chunk);
    
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetTotalSize()
 *********************************************************************************************************************/
/*! \brief       Get the total size of the chunk
 *  \details     Calculates the total aligned size of the chunk in flash. This includes the management data as well as 
                 the space reserved for the instances that are managed by the chunk.
 *  \param[in]   chunk               Pointer to the chunk the size shall be calculated for. Must not be NULL.
 *  \return      The total size of the chunk in bytes
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetTotalSize(Fee_30_FlexNor_ConstChunkPtrType chunk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_Allocate()
 *********************************************************************************************************************/
/*! \brief       Allocates a new chunk in flash.
 *  \details     Uses the given chunk, predecessor chunk and instance to allocate a chunk in flash.
 *  \param[in]   chunk              Chunk data that shall be used for the allocation. Must not be NULL.
 *  \param[in]   predecessorChunk   Predecessor chunk that link will be updated. Must not be NULL.
 *  \param[in]   instanceToWrite    First instance to write to the chunk. Must not be NULL.
 *  \param[in]   resultCbk          The result call back that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_Allocate(
    Fee_30_FlexNor_ConstChunkPtrType chunk, 
    Fee_30_FlexNor_ChunkPtrType predecessorChunk, 
    Fee_30_FlexNor_InstancePtrType instanceToWrite, 
    Fee_30_FlexNor_ResultCallback resultCbk);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SLIMCHUNK_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimChunk.h
 *********************************************************************************************************************/
