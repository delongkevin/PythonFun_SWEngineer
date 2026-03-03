/**
 * @file ipc_large_buff_mgr.h
 * @brief Main header file for IPC large buff manager to share large data across different core
 *
 * @details This file contains IPC large buffer global data type which will be used by IPC manager
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2014.  Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status.  Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author ----  (---- @magna.com)
 */

#ifndef IPC_LARGE_BUFF_MGR_H_
#define IPC_LARGE_BUFF_MGR_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#ifndef BUILD_MCU2_0
#include <ti/drv/ipc/ipc.h>
#endif

#include "ipc_error.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */

/* ===========================================================================
*
*   Global data types
*
* ========================================================================= */
/* Structure for IPC shared memory buffer info */
typedef struct IpcSmBuff_s
{
    void     *addr_pv;
    uint16_t dstCoreBitMask_u16;
    uint16_t pktNum_u16;
    uint8_t  buffIdx_u8;
    uint8_t  sendDataType;
    uint8_t  reserved_u8[2];
} IpcSmBuff_t;

/* Structure to keep track of current state of all buffer in shared memory */
typedef struct IpcSmBuffState_s
{
    uint16_t buffInUse_u16;     /* Bit wise use of remote core */
    uint8_t  timer_u8;          /* To track elapsed time after sending large data and waiting for acknowledgement */
    uint16_t currPktNum_u16;    /* Packet number sent by individual shared memory buffer */
} IpcSmBuffState_t;

/* ========================================================================== */
/*                          External Dependencies                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

void       IPC_F_SmBuffInit_v (void);
uint32_t   IPC_F_GetSmBuff_u32 (uint16_t i_msgIdIdx_u16, IpcSmBuff_t *i_smBuff_ps);
uint32_t   IPC_F_ReleaseSmBuff_u32 (uint16_t i_msgIdIdx_u16, IpcSmBuff_t i_SmBuff_s);
void       IPC_F_UpdateSmBuffState_v (void);
void       IPC_F_GetFreeSmBuffCnt_v (uint8_t *o_buffCnt_pu8);

#if defined(BUILD_MPU1_0)
int8_t    init_Shmem();
int8_t    deinit_Shmem();
#endif

#endif  /* #define IPC_BUFF_MGR_H_ */
