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
 *    License Scope : The usage is restricted to CBD2101146_D09
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Fbt.c
 *   Generation Time: 2023-10-09 10:56:17
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D09
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
    0x00200000u, 
    0x0027FFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x00280000u, 
    0x002FFFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x00300000u /*  AUTOSAR Application in MCU1_0  */ , 
    0x005FFFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x00600000u /*  Lateapp1 in MCU2_0  */ , 
    0x012FFFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x01300000u /*  Arm Trusted Firmware + OPTEE  */ , 
    0x0137FFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x01380000u /*  QNX Image File system  */ , 
    0x03B7FFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x03B80000u /*  C7x DSP  */ , 
    0x0457FFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x04580000u /*  Vehicle extrinsics and calibration values  */ , 
    0x0467FFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x04680000u /*  Extended KeyRing  */ , 
    0x046BFFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x06600000u /*  Post-production Security Certificates  */ , 
    0x0663FFFFu, 
    kMioDeviceFlashWrapper
  }, 
  {
    0x06C60000u /*  EOL Data  */ , 
    0x06C7FFFFu, 
    kMioDeviceFlashWrapper
  }
};
V_MEMROM0 V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfFlashBlock = sizeof(FlashBlock) / sizeof(FlashBlock[0]);

V_MEMROM0 V_MEMROM1_FAR tMemDrv V_MEMROM2_FAR memDrvLst[] =
{
  {
    FlashWrapperDriver_InitSync, 
    FlashWrapperDriver_DeinitSync, 
    FlashWrapperDriver_REraseSync, 
    FlashWrapperDriver_RWriteSync, 
    FlashWrapperDriver_RReadSync, 
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
#if defined( FLASHWRAPPER_SEGMENT_SIZE )
# if ( FLASHWRAPPER_SEGMENT_SIZE != 4096u )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif

#if defined( FBL_FLASHWRAPPER_DELETED )
# if ( FBL_FLASHWRAPPER_DELETED != 0xFFu )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif



