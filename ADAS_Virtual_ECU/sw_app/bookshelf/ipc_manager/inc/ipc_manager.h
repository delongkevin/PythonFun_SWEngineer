/**
 * @file ipc_manager.h
 * @brief Interface between software applications and IPC driver
 *
 * @details This file provides APIs to transfer data between Software applications and IPC driver
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
#ifndef IPC_MANAGER_H_
#define IPC_MANAGER_H_
 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "ipc_cfg.h"
#include "ipc_large_buff_mgr.h"
#include "ipc_error.h"
#include "ipc_lookup_table.h"
#include "ipc_lookup_table_struct.h"

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
/* Structure for Data recv */
typedef struct IPCMessage_Params_s
{
    uint16_t IpcMsgID_u16;
    uint16_t IpcMsgSize_u16;
    uint8_t* IpcMsgData_v;
    uint16_t IpcMsgBufSize_u16;

} IPCMessage_Params_t;

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
/* Init Function to initialize IPC Driver, set Local and Remote Cores, Initialize VirtIos, RPMessage  */
uint32_t IPC_F_ManagerInit_u32(void);

/* Ipc manager scheduled function*/
void IPC_F_IpcManager_v(void);

/* Function to be used by Application to send data to other Cores */
uint32_t IPC_F_WrapperSend_u32(IPCMessage_Params_t *i_IPCMsg_ps);

 /* === End Of Header File ================================================= */
 #endif /*IPC_MANAGER_H_*/
