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
/*!        \file  Fee_30_FlexNor_Shared.h
 *        \brief  Shared functionality interface
 *      \details  Provides the interface for the functionality shared among different FEE units.
 *         \unit  Shared
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_SHARED_H)
# define FEE_30_FLEXNOR_SHARED_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"

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
 * Fee_30_FlexNor_Shared_Align()
 *********************************************************************************************************************/
/*! \brief       Aligned the given value to the also given target alignment
 *  \details     -
 *  \param[in]   value               Value that shall be aligned
 *  \param[in]   alignment           Target alignment of the value
 *  \return      The aligned value
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_Align(uint32 value, uint16 alignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_GetMarker()
 *********************************************************************************************************************/
/*! \brief       Gets a marker from a given buffer at a specified offset
 *  \details     -
 *  \param[in]   buffer             Pointer to the buffer the marker is extracted from. Must not be NULL.
 *  \param[in]   offset             Offsets that specifies where the marker starts.
 *  \return      Converted marker
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_MarkerType, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Shared_GetMarker(Fee_30_FlexNor_ConstDataPtrType buffer, 
    Fee_30_FlexNor_LengthType offset);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_SetMarker()
 *********************************************************************************************************************/
/*! \brief          Sets a marker in the given buffer
 *  \details        -
 *  \param[in]      marker             Marker that shall be set in the buffer.
 *  \param[in,out]  buffer             Pointer to the buffer the marker is set to. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Shared_SetMarker(Fee_30_FlexNor_MarkerType marker, 
    Fee_30_FlexNor_DataPtrType buffer);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_SetBufferValues()
 *********************************************************************************************************************/
/*! \brief          Sets each element of the buffer to the given value
 *  \details        -
 *  \param[in,out]  buffer               Buffer that should be set. Must not be NULL.
 *  \param[in]      bufferSize           Size of the buffer.
 *  \param[in]      value                Value that shall be set to each element.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_SetBufferValues(Fee_30_FlexNor_DataPtrType buffer, 
    Fee_30_FlexNor_LengthType bufferSize, 
    Fee_30_FlexNor_DataType value);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_GetValueFromBuffer()
 *********************************************************************************************************************/
/*! \brief       Gets the value out of a given buffer.
 *  \details     Gets the value out of a buffer.
 *  \param[in]   sourceBuffer         Start address of the source buffer. Must not be NULL.
 *  \param[in]   length               Number of bytes to copy.
 *  \param[in]   offset               Offset to use for the source buffer.
 *  \pre         Source buffer must be big enough to handle the given length + offset.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(uint32, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Shared_GetValueFromBuffer(Fee_30_FlexNor_ConstDataPtrType sourceBuffer,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_LengthType offset);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_SetValueToBuffer()
 *********************************************************************************************************************/
/*! \brief       Copies the given value to the target buffer
 *  \details     Copies the values to the target buffer starting at the given offset. The length specifies how many bytes
 *               from the given values are copies.
 *  \param[in]      value           Value to set
 *  \param[in,out]  targetBuffer    Target buffer where the value is set. Must not be NULL.
 *  \param[in]      length          Specifies how many bytes from the value are copied.
 *  \param[in]      offset          Specifies the start offset of the copy operation inside the target buffer.
 *  \pre         Target buffer must be big enough to handle the given length + offset.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_SetValueToBuffer(uint32 value,
    Fee_30_FlexNor_DataPtrType targetBuffer,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_LengthType offset);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_GetEmptyMarker()
 *********************************************************************************************************************/
/*! \brief       Returns an empty (i.e. erased) marker
 *  \details     -
 *  \param[in]   erasedValue        Erased value as uint8.
 *  \return      Empty marker
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_MarkerType, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Shared_GetEmptyMarker(uint8 erasedValue);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_CalculateChecksum()
 *********************************************************************************************************************/
/*! \brief       Calculates a checksum for the given buffer
 *  \details     Calculates the checksum starting from the given offset for the given length.
 *  \param[in]   buffer               Buffer containing the values the checksum shall be calculated for. Must not be NULL.
 *  \param[in]   offset               Offset that specifies where the calculation shall begin.
 *  \param[in]   length               Amount of bytes the checksum shall be calculated for starting from the offset.
 *  \return      The calculated checksum for the given buffer
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ChecksumType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_CalculateChecksum(Fee_30_FlexNor_ConstDataPtrType buffer, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_LengthType offset);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_IsErased()
 *********************************************************************************************************************/
/*! \brief       Checks if the given buffer is erased
 *  \details     -
 *  \param[in]   buffer               Buffer that shall be checked. Must not be NULL.
 *  \param[in]   length               Length of the buffer that shall be checked.
 *  \param[in]   erasedValue          Erased value of the flash memory.
 *  \return      TRUE                 The buffer is erased
 *               FALSE                The buffer is not erased
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_IsErased(Fee_30_FlexNor_ConstDataPtrType buffer, 
    Fee_30_FlexNor_LengthType length,
    uint8 erasedValue);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Evt_TriggerGarbageCollection()
 *********************************************************************************************************************/
/*! \brief       Explicitly triggers a garbage collection
 *  \details     Triggers a garbage collection for a specific partition as an error recovery measure.
 *  \param[in]   partitionId         Id of the partition that shall be garbage collected.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Evt_TriggerGarbageCollection(uint32 partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Evt_TriggerGarbageCollectionIncluded()
 *********************************************************************************************************************/
/*! \brief       Explicitly triggers a garbage collection including the given chunk.
 *  \details     Triggers a garbage collection for a specific partition as an error recovery measure.
 *  \param[in]   partitionId         Id of the partition that shall be garbage collected.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Evt_TriggerGarbageCollectionIncluded(uint32 partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Evt_TriggerGarbageCollectionExcluded()
 *********************************************************************************************************************/
/*! \brief       Explicitly triggers a garbage collection excluding the given chunk.
 *  \details     Triggers a garbage collection for a specific partition as an error recovery measure.
 *  \param[in]   partitionId         Id of the partition that shall be garbage collected.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Evt_TriggerGarbageCollectionExcluded(uint32 partitionId);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SHARED_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Shared.h
 *********************************************************************************************************************/
