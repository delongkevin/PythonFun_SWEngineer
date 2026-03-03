/**
 * @file ipc_lookup_table_struct.h
 * @brief Maintains look up table structures
 *
 * @details This file includes prototype of all strucrues used by IPC lookup table
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2021. Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status. Magna Electronics
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
 * @author ---- (---- @magna.com)
 */

#ifndef IPC_LOOKUP_TABLE_STRUCT_H_
#define IPC_LOOKUP_TABLE_STRUCT_H_
/* ===========================================================================
 *
 *   Include Files
 *
 * ======================================================================== */

#include <stdio.h>
#include <stdint.h>
#include "ipc_large_buff_mgr.h"

/* ===========================================================================
 *
 *   Defines
 *
 * ======================================================================== */

/* ===========================================================================
 *
 *   Global Data Types
 *
 * ======================================================================== */
/* Structure for lookup table to control messages transmittion */
typedef struct ipcLutAttrTx_s {
    uint16_t          msgId_u16;                     /* Message ID to transmit */
    uint16_t          dstCores_u16;                  /* Destination cores (Bit wise stored) to transmit data of corresponding message id */
    uint8_t           *baseAddr_pu8;                 /* Address of first shared mem buffer of corresponding msgId */
    uint16_t          smBuffSize_u16;                /* Sizeof shared memory buff of corresponding msgId */
    uint16_t          dataSize_u16;                  /* Sizeof data of corresponding msgId */
    uint8_t           buffCnt_u8;                    /* Shared memory Buff count */
    uint32_t          *msgIdCntr_pu32;               /* Message counter for corresponding message id */
    IpcSmBuffState_t  *buffStateAddr_ps;             /* Address of first shared memory buffer state */
} ipcLutAttrTx_t;

/* Structure for lookup table to control messages reception */
typedef struct ipcLutAttrRx_s {
    uint16_t          msgId_u16;                     /* Message ID to transmit or receive*/
    uint16_t          dataSize_u16;                  /* Sizeof data of corresponding msgId */
    uint32_t          *msgIdCntrPrev_pu32;           /* Message counter for corresponding message id */
    void              (*ipc_callback_func)(const void* );  /* Callback function to provide data to signal handler */
} ipcLutAttrRx_t;

/* ===========================================================================
*
*   Global Variables
*
* ========================================================================= */

/* Lookup table */
extern const ipcLutAttrTx_t  V_ipcLutAttrTx_as[];
extern const ipcLutAttrRx_t  V_ipcLutAttrRx_as[];

/* ===========================================================================
*
*   Function Prototypes
*
* ========================================================================= */

void IPC_F_lookupTblInit_v (void);

/* ===========================================================================
 *
 *   End of Header File
 *
 * ======================================================================== */
#endif // IPC_LOOKUP_TABLE_H_
