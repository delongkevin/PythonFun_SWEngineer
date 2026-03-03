/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Flash Driver wrapper for TI NAND
 *
 *  \note         
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 
 *  \endverbatim
 */
/**********************************************************************************************************************/


/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/


IO_ErrorType NandWrapperDriver_InitSync( void * address );
IO_ErrorType NandWrapperDriver_DeinitSync( void* address );
IO_ErrorType NandWrapperDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress );
IO_ErrorType NandWrapperDriver_REraseSync(IO_SizeType eraseLength, IO_PositionType eraseAddress);
IO_ErrorType NandWrapperDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress );

