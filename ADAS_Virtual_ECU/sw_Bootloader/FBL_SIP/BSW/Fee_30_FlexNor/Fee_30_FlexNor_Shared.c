/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_Shared.c
 *        \brief  Shared functionality
 *      \details  Implementation of the shared unit functionality.
 *         \unit  Shared
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_SHARED_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Fee_30_FlexNor_Shared.h"
# include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_SHARED_SINGLESHIFTSIZE (0x08u)
#define FEE_30_FLEXNOR_SHARED_BYTEMASK (0xFFu)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_Align()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_Align(uint32 value, uint16 alignment)
{
    uint32 alignedValue = value;

    if((value % alignment) != 0u)
    {
        alignedValue = value + alignment - (value % alignment);
    }
    
    return alignedValue;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_GetMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_MarkerType, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Shared_GetMarker(Fee_30_FlexNor_ConstDataPtrType buffer,
    Fee_30_FlexNor_LengthType offset)
{
    uint8 index;
    uint8 markerSize = sizeof(Fee_30_FlexNor_MarkerType);
    Fee_30_FlexNor_MarkerType marker = 0u;
    
    for(index=0u; index < markerSize; index++)
    {
        /* The byte order of the markers is big endian, therefore the first byte discovered needs to be shifted left the most. */
        uint8 totalShiftSize = (markerSize-1u-index) * FEE_30_FLEXNOR_SHARED_SINGLESHIFTSIZE;
        marker |= ((Fee_30_FlexNor_MarkerType)buffer[offset + index]) << totalShiftSize;
    }

    return marker;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_SetMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Shared_SetMarker(Fee_30_FlexNor_MarkerType marker, 
    Fee_30_FlexNor_DataPtrType buffer)
{
    uint8 index;
    uint8 markerSize = sizeof(Fee_30_FlexNor_MarkerType);
    
    for(index = 0u; index < markerSize; index++)
    {
        uint8 totalShiftSize = (markerSize-1u-index) * FEE_30_FLEXNOR_SHARED_SINGLESHIFTSIZE;
        buffer[index] = (Fee_30_FlexNor_DataType)((marker >> totalShiftSize) & FEE_30_FLEXNOR_SHARED_BYTEMASK); /* SBSW_Fee_30_FlexNor_ModifyGivenArray */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_SetBufferValues()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_SetBufferValues(Fee_30_FlexNor_DataPtrType buffer, 
    Fee_30_FlexNor_LengthType bufferSize,
    Fee_30_FlexNor_DataType value)
{
    Fee_30_FlexNor_LengthType index;
    for(index = 0u; index < bufferSize; index++)
    {
        buffer[index] = value; /* SBSW_Fee_30_FlexNor_ModifyGivenArray */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_GetValueFromBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Shared_GetValueFromBuffer(Fee_30_FlexNor_ConstDataPtrType sourceBuffer,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_LengthType offset)
{
    uint32 retVal = 0u;
    Fee_30_FlexNor_LengthType index;
    
    for(index = 0u; index < length; index++)
    {
        retVal += ((uint32)sourceBuffer[index+offset]) << ((length-index-1u) * FEE_30_FLEXNOR_SHARED_SINGLESHIFTSIZE);
    }
    
    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_SetValueToBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_SetValueToBuffer(uint32 value,
    Fee_30_FlexNor_DataPtrType targetBuffer,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_LengthType offset)
{
    Fee_30_FlexNor_LengthType index;
    Fee_30_FlexNor_DataType shiftedValue;

    for(index = 0u; index < length; index++)
    {
        shiftedValue = (Fee_30_FlexNor_DataType)((value >> ((length-index-1u) * FEE_30_FLEXNOR_SHARED_SINGLESHIFTSIZE)) & FEE_30_FLEXNOR_SHARED_BYTEMASK);
        targetBuffer[index + offset] = shiftedValue; /* SBSW_Fee_30_FlexNor_ModifyGivenArray */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_GetEmptyMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_MarkerType, FEE_30_FLEXNOR_CODE)  Fee_30_FlexNor_Shared_GetEmptyMarker(uint8 erasedValue)
{
    uint32 mask = (uint32) erasedValue;
    return (Fee_30_FlexNor_MarkerType)((mask << 24u) | (mask << 16u) | (mask << 8u) | mask);
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_CalculateChecksum()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ChecksumType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_CalculateChecksum(Fee_30_FlexNor_ConstDataPtrType buffer,
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_LengthType offset)
{
    Fee_30_FlexNor_LengthType index;
    Fee_30_FlexNor_ChecksumType checksum = 0u;

    for(index = 0u; index < length; index++)
    {
        checksum += buffer[index + offset];
    }

    return checksum;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Shared_IsErased()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Shared_IsErased(Fee_30_FlexNor_ConstDataPtrType buffer, 
    Fee_30_FlexNor_LengthType length,
    uint8 erasedValue)
{
    Fee_30_FlexNor_LengthType index;
    boolean isErased = TRUE;

    for(index = 0u; index < length; index++)
    {
        if(buffer[index] != erasedValue)
        {
            isErased = FALSE;
            break;
        }
    }

    return isErased;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Evt_TriggerGarbageCollection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Evt_TriggerGarbageCollection(uint32 partitionId)
{
    /* Dummy implementation until the units are created that can process this event. */
    FEE_DUMMY_STATEMENT(partitionId);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Evt_TriggerGarbageCollectionIncluded()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Evt_TriggerGarbageCollectionIncluded(uint32 partitionId)
{
    /* Dummy implementation until the units are created that can process this event. */
    FEE_DUMMY_STATEMENT(partitionId);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Evt_TriggerGarbageCollectionExcluded()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Evt_TriggerGarbageCollectionExcluded(uint32 partitionId)
{
    /* Dummy implementation until the units are created that can process this event. */
    FEE_DUMMY_STATEMENT(partitionId);
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Shared.c
 *********************************************************************************************************************/
