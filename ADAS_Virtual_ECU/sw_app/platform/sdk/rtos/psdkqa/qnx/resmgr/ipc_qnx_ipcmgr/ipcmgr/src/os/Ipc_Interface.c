/**
  @file Ipc_Interface.c
 * @brief Main header file for Testing and verifying interface data between PUC & IPC A72
 *
 * @details This file contains brigde global data type which will be used by IPC manager
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

 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ipc_main.h"
#include "PlatformSpecsQnx64.h"
#include "ipc_lookup_table.h"
#include "ipc_lookup_table_struct.h"
#include "Ipc_Interface.h"

/* ===========================================================================
*
*   Function Prototypes
*
* ========================================================================= */

static uint16_t IPC_f_GetMsgIdTxIdx1_u16 (uint16_t i_msgId_u16)
{
    uint16_t v_msgIdIdx_u16 = 0;

    /* Find corresponding index of message id in IPC lookup table for Tx attr */
    for (v_msgIdIdx_u16 = 0; v_msgIdIdx_u16 < D_NUMBER_OF_TX_MESSAGES; v_msgIdIdx_u16++)
    {
        if(i_msgId_u16 == V_ipcLutAttrTx_as[v_msgIdIdx_u16].msgId_u16)
        {
            /* MsgId found in lookup table*/
            break;
        }
    }

    return v_msgIdIdx_u16;
}

uint8_t IPC_f_IsSizeMatch(uint16_t i_MsgIdMatch, uint16_t i_SizeMatch_u16)
{
    uint16_t v_msgIdTxIdx_u16 = IPC_f_GetMsgIdTxIdx1_u16 (i_MsgIdMatch);
    uint8_t v_retVal_u8 = 0;

    if( V_ipcLutAttrTx_as[v_msgIdTxIdx_u16].dataSize_u16 == i_SizeMatch_u16)
    {
	    v_retVal_u8 = 1;
    }
    else
    {
#if defined(DEBUG_MSG)
            printf(" ********* Send Size Mis-Match :: PUC Send Size : [ %u ] \
            and Required Size : [ %u ] ********** ",i_SizeMatch_u16,  \
            V_ipcLutAttrTx_as[v_msgIdTxIdx_u16].dataSize_u16);
#endif
        v_retVal_u8 = 0;
    }
    
    return v_retVal_u8;
}
