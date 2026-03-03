/**
 * @file ipc_config.h
 * @brief configurations for ipc module
 *
 * @details This file configures IPC stack size, SCICLIENT API Timeout
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
#ifndef IPC_MAIN_H_
#define IPC_MAIN_H_

#ifdef __cplusplus
extern "C" {
#endif


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <sys/dispatch.h>
#include <ti/osal/osal.h>

#include "ipc_manager.h"

#ifdef BUILD_MPU1_0
#include "res_mgr.h"
#define RESMGR_DEVICE_NAME       "/dev/resMgr1"
#endif

#include "ipc_large_buff_mgr.h"
#include "ipc_global.h"
#include "ipc_lookup_table.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define D_ERR_SAT_TASK_STACKSIZE  0x2000U
#define D_ERR_MSGID               0x00U
#define D_MIN_MESSAGE_PDU_SIZE    3U
#define D_CORE_IN_TEST            9U
#define D_EXTRA_MSG_LEN           2U
#define D_DEBUG_INFO              printf

#endif
