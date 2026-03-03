/**
 * @file ipc_lookup_table_include.h
 * @brief Include file for ipc_lookup_table.c
 *
 * @details This file keep include files for ipc_lookup_table.c
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

#ifndef IPC_LOOKUP_TABLE_INCLUDE_H_
#define IPC_LOOKUP_TABLE_INCLUDE_H_
/* ===========================================================================
 *
 *   Important Note -> This file should be included only in ipc_lookup_table.c
 *
 * ======================================================================== */

/* ===========================================================================
 *
 *   Include Files
 *
 * ======================================================================== */
#include "ipc_lookup_table.h"
#include "ipc_lookup_table_struct.h"
#include "ipc_cfg.h"

#if defined(BUILD_MCU2_0)
#include <ti/drv/ipc/soc/V3/ipc_soc.h>
#else
#include <ti/drv/ipc/ipc.h>
#endif

#include "SignalDef.h"


#if defined(BUILD_MPU1_0)
#include <sys/iomsg.h>
#include "res_mgr.h"
#endif

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
#endif // IPC_LOOKUP_TABLE_INCLUDE_H_
