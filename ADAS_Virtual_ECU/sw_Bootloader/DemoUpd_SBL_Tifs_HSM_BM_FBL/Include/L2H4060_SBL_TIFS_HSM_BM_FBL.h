/****************************************************************
*
*  Filename:      .\\L2H4060_SBL_TIFS_HSM_BM_FBL.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Fri Nov  3 20:52:30 2023

*
****************************************************************/

#ifndef __FBLUPDATE__
#define __FBLUPDATE__
#define FBLUPDATE_GEN_RAND 22855

#define FBLUPDATE_NUMBLOCKS 4

#define FBLUPDATE_DECRYPTDATA(a)   (vuint8)(a)

/* Definition of the structure that stores address and length info */
typedef struct _tFblUpdateBlkInfo
{
   FBL_ADDR_TYPE     blockAddress;
   FBL_MEMSIZE_TYPE  blockLength;
   V_MEMROM1  vuint8 V_MEMROM2 * V_MEMROM3 blockSource;
} tFblUpdateBlkInfo;

V_MEMROM0 extern V_MEMROM1 tFblUpdateBlkInfo V_MEMROM2 FblUpdateBlkInfo[FBLUPDATE_NUMBLOCKS];

#define FBLUPDATE_START_SEC_CONST_EXPORT
#include "MemMap.h"

#define FBLUPDATE_BLOCK0_ADDRESS	0x0
#define FBLUPDATE_BLOCK0_LENGTH	0x557CC
#define FBLUPDATE_BLOCK0_CHECKSUM	0xF55Eu

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk0[FBLUPDATE_BLOCK0_LENGTH];

#define FBLUPDATE_BLOCK1_ADDRESS	0x80000
#define FBLUPDATE_BLOCK1_LENGTH	0x27D64
#define FBLUPDATE_BLOCK1_CHECKSUM	0x2025u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk1[FBLUPDATE_BLOCK1_LENGTH];

#define FBLUPDATE_BLOCK2_ADDRESS	0xC0000
#define FBLUPDATE_BLOCK2_LENGTH	0x6AD7C
#define FBLUPDATE_BLOCK2_CHECKSUM	0x86EAu

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk2[FBLUPDATE_BLOCK2_LENGTH];

#define FBLUPDATE_BLOCK3_ADDRESS	0x280000
#define FBLUPDATE_BLOCK3_LENGTH	0x7C004
#define FBLUPDATE_BLOCK3_CHECKSUM	0x98E8u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk3[FBLUPDATE_BLOCK3_LENGTH];

#define FBLUPDATE_STOP_SEC_CONST_EXPORT
#include "MemMap.h"


#endif    /* #ifdef __FBLUPDATE__ */

