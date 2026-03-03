/****************************************************************
*
*  Filename:      D:\usr\usage\Delivery\CBD21x\CBD2100467\D01\internal\Demo\DemoFlashDrv\Build\..\FlashRom.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Thu Feb 24 16:15:18 2022

*
****************************************************************/

#ifndef __FLASHDRV__
#define __FLASHDRV__
#define FLASHDRV_GEN_RAND 5951

#define FLASHDRV_NUMBLOCKS 1

#define FLASHDRV_DECRYPTVALUE	0xCC
#define FLASHDRV_DECRYPTDATA(a)   (vuint8)((vuint8)(a) ^ (vuint8)FLASHDRV_DECRYPTVALUE)
#define FLASHDRV_BLOCK0_ADDRESS	0x0
#define FLASHDRV_BLOCK0_LENGTH	0x4
#define FLASHDRV_BLOCK0_CHECKSUM	0x5Cu

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 flashDrvBlk0[FLASHDRV_BLOCK0_LENGTH];


#endif    /* #ifdef __FLASHDRV__ */

