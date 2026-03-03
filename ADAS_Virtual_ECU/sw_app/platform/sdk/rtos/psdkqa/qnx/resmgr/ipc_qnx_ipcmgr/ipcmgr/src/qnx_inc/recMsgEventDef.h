/**
 * @file recMsgEventDef.h
 * @brief Main header file to handle multiple data and share data across IPC A72 to PUC
 *
 * @details This file contains brigde global data type which will be used by IPC manager
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

#ifndef RECMSGEVENTDEF_H_
#define RECMSGEVENTDEF_H_
/* ===========================================================================
 *
 *   Include Files
 *
 * ======================================================================== */

#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <string.h>
#include "PlatformDataTypes.h"
#include "ipc_main.h"
#include "ipc_lookup_table_include.h"

/* ===========================================================================
 *
 *   Defines
 *
 * ======================================================================== */

#define     D_EVENT_QUEUE_SIZE      D_NUMBER_OF_RX_MESSAGES
#define     D_READ                  1U
#define     D_WRITE                 0U
#define     D_MAX_MSGID             99U
#define     D_PUCDATAIDX            0U
#define     D_ZERO                  0U
#define     D_ONE                   1U

/* ===========================================================================
 *
 *   Global Data Types
 *
 * ======================================================================== */

typedef struct recMsgDatas_s { 
    uint8_t *recBufPtr_pu8;
    uint16_t MsgID; 
    uint16_t  MsgLen; 
}recMsgData_t; 

typedef struct recMsgEvent_s 
{ 
    recMsgData_t v_StoredData_s; 
    uint32_t recvdMsgPtr; 
    uint8_t eventFlag_u8; 
}recMsgEvent_t; 


/* ===========================================================================
 *
 *   Function Prototypes
 *
 * ========================================================================= */
 
uint8_t IPC_F_initializeEventQueue_v (void);
bool_t IPC_F_addEvent_b (uint8_t *o_event_ps, uint16_t o_msgID_u16);
bool_t IPC_F_getEvent_b(void *o_event_ps, uint16_t *o_msgID_u16, uint16_t *o_dataSize_u16);

/* ===========================================================================
*
*   Global Variables
*
* ========================================================================= */


/* ===========================================================================
*
*   Function Prototypes
*
* ========================================================================= */

/* ===========================================================================
 *
 *   End of Header File
 *
 * ======================================================================== */
#endif // RECMSGEVENTDEF_H_
