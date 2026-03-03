/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: FblMio_vMemAccM
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblMio_Cfg.h
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#ifndef FBLMIO_CFG_H
#define FBLMIO_CFG_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define FBL_MIO_DISABLE_USE_IS_BLANK 
#define FBL_MIO_DISABLE_COMPARE_AFTER_WRITE 
#define FBL_MIO_DISABLE_USER_INIT_FUNCTION 
#define FBL_MIO_DISABLE_USER_MAIN_FUNCTION 
#define FBL_MIO_DISABLE_MEM_DRIVER_READY 
#define FBL_MIO_SIZE_OF_INSTANCE_MAPPING    1u 

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

typedef struct
{
   vMemAccM_HwIdType hwId;
   boolean isHis;
   vuint8 erasedValue;
} tFblMemInstanceMapping;

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/


IO_ErrorType FlashWrapperDriver_InitSync(void * address);
IO_ErrorType FlashWrapperDriver_DeinitSync(void * address);
IO_ErrorType FlashWrapperDriver_RWriteSync(IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress);
IO_ErrorType FlashWrapperDriver_REraseSync(IO_SizeType eraseLength, IO_PositionType eraseAddress);
IO_ErrorType FlashWrapperDriver_RReadSync(IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress);

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

V_MEMROM0 extern V_MEMROM1 tFblMemInstanceMapping V_MEMROM2 FblMemInstanceMapping[FBL_MIO_SIZE_OF_INSTANCE_MAPPING];

#endif /* FBLMIO_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: FblMio_Cfg.h
 *********************************************************************************************************************/
