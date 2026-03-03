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
 *    License Scope : The usage is restricted to CBD2101146_D12
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Fbt.c
 *   Generation Time: 2023-10-27 18:05:39
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D12
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


/* Includes **********************************************************************************************************/
#include "fbl_inc.h"

/* Global data *******************************************************************************************************/
V_MEMROM0 V_MEMROM1_FAR tFlashBlock V_MEMROM2_FAR FlashBlock[] =
{
  {
    0x00000000u /*  SBL  */ , 
    0x0007FFFFu, 
    kMioDeviceNandWrapper
  }, 
  {
    0x00080000u /*  Tifs  */ , 
    0x000BFFFFu, 
    kMioDeviceNandWrapper
  }, 
  {
    0x000C0000u /*  Boot Manager and HSM  */ , 
    0x0027FFFFu, 
    kMioDeviceNandWrapper
  }, 
  {
    0x00280000u /*  Flash Bootloader  */ , 
    0x002FFFFFu, 
    kMioDeviceNandWrapper
  }, 
  {
    0x00300000u /*  AUTOSAR Application in MCU1_0  */ , 
    0x005FFFFFu, 
    kMioDeviceNandWrapper
  }
};
V_MEMROM0 V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfFlashBlock = sizeof(FlashBlock) / sizeof(FlashBlock[0]);

V_MEMROM0 V_MEMROM1_FAR tMemDrv V_MEMROM2_FAR memDrvLst[] =
{
  {
    NandWrapperDriver_InitSync, 
    NandWrapperDriver_DeinitSync, 
    NandWrapperDriver_REraseSync, 
    NandWrapperDriver_RWriteSync, 
    NandWrapperDriver_RReadSync, 
    0x1000u /*  Segment Size  */ , 
    0xFFu /*  Erased Value  */ , 
    FALSE /*  Init Hook  */ , 
    FALSE /*  Deinit Hook  */ , 
    FALSE /*  Erase Hook  */ , 
    FALSE /*  Write Hook  */ , 
    FALSE /*  Read Hook  */ 
  }
};
V_MEMROM0 V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfMemDrv = sizeof(memDrvLst) / sizeof(memDrvLst[0]);

/* Try to check consistency between memory device driver
 * header files (e.g. flashdrv.h) and Cfg5 configuration */
#if defined( NANDWRAPPER_SEGMENT_SIZE )
# if ( NANDWRAPPER_SEGMENT_SIZE != 4096u )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif

#if defined( FBL_NANDWRAPPER_DELETED )
# if ( FBL_NANDWRAPPER_DELETED != 0xFFu )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif



