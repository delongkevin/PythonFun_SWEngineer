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
 *            Module: Fbl
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Fbt.h
 *   Generation Time: 2024-11-25 15:00:21
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#if !defined(__FBL_APFB_H__)
#define __FBL_APFB_H__

/* Includes **********************************************************************************************************/
#include "Platform_Types.h"

/* Defines ***********************************************************************************************************/
/* Flash Block Table */
#define FLASH_BLOCK_ENTRIES              kNrOfFlashBlock

/* Memory Device Table */
#define kMioDeviceFlashWrapper          0u 
#define FBL_DISABLE_FUNC_VERIFYSYNC 
#define FBL_ENABLE_MULTIPLE_MEM_DEVICES 
#define FBL_MIO_DISABLE_HOOKS 
#define FBL_MEMDRV_SEGMENT_SIZE         4096u 

/* Typedefs **********************************************************************************************************/
typedef struct tFlashBlockTag {
  tFblAddress begin;
  tFblAddress end;
  vuint8 device;
} tFlashBlock;

typedef V_API_NEAR IO_ErrorType (*tMemDrvFctInit)( void * );
typedef V_API_NEAR IO_ErrorType (*tMemDrvFctDeinit)( void * );
typedef V_API_NEAR IO_ErrorType (*tMemDrvFctErase)( IO_SizeType, IO_PositionType );
typedef V_API_NEAR IO_ErrorType (*tMemDrvFctWrite)( IO_MemPtrType, IO_SizeType, IO_PositionType );
typedef V_API_NEAR IO_ErrorType (*tMemDrvFctRead)( IO_MemPtrType, IO_SizeType, IO_PositionType );

typedef struct tMemDrvTag {
  tMemDrvFctInit init;
  tMemDrvFctDeinit deinit;
  tMemDrvFctErase erase;
  tMemDrvFctWrite write;
  tMemDrvFctRead read;
  vuint16 segmentSize;
  vuint8 erasedValue;
  boolean initHook;
  boolean deinitHook;
  boolean eraseHook;
  boolean writeHook;
  boolean readHook;
} tMemDrv;

/* Global data *******************************************************************************************************/
V_MEMROM0 extern  V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfFlashBlock;
V_MEMROM0 extern  V_MEMROM1_FAR tFlashBlock V_MEMROM2_FAR FlashBlock[];
V_MEMROM0 extern  V_MEMROM1_FAR tMemDrv V_MEMROM2_FAR memDrvLst[];
V_MEMROM0 extern  V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfMemDrv;

#endif /* __FBL_APFB_H__ */

