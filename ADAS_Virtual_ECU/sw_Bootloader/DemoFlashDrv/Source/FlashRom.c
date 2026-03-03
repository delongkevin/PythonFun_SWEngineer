/****************************************************************
*
*  Filename:      D:\usr\usage\Delivery\CBD21x\CBD2100467\D01\internal\Demo\DemoFlashDrv\Build\..\FlashRom.c
*  Project:       C-Array of Flash-Driver
*  File created:  Thu Feb 24 16:15:18 2022

*
****************************************************************/

#include <fbl_inc.h>
#include <FlashRom.h>

#if (FLASHDRV_GEN_RAND!=5951)
# error "Generated header and C-File inconsistent!!"
#endif

V_MEMROM0 V_MEMROM1  vuint8 V_MEMROM2 flashDrvBlk0[FLASHDRV_BLOCK0_LENGTH] = {
	0xCC, 0xCC, 0xCC, 0x90
};
