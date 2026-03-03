/**
 * @file WdgSlave.h
 * @brief This file contains interface header for WDG slave
 *
 * @details This file contains interface header for WDG slave
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2022.  Magna Electronics owns all
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
 * @author Pramod Kumar (Pramod.kumar1@magna.com)
 */
#ifndef WDG_SLAVE_H_
#define WDG_SLAVE_H_
 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define D_WDG_CORE_CNT        (1U)
#define D_WDG_CORE_MPU1_0     (0U)
#define D_WDG_CORE_MCU2_0     (1U)
#define D_WDG_CORE_MCU2_1     (2U)

/* Other core checkpoint violation info */
typedef struct wdgOtherCoreCpViolation_s {
    uint8  isViolation_u8;  /* is there any violation */
    uint16 seid_u16;        /* Which seid violated? */
    uint32 errorId_u32;     /* Error manager error ID (To pass error id to Wdg.c)*/
} wdgOtherCoreCpViolation_t;

/* Structure to check other core CP status */
typedef struct wdgCheckOtherCoreCpSts_s {
    uint8                       isStatusCheckReq_u8;  /* is required to check status, 1 -> Yes, 0 -> No */
    WdgM_SupervisedEntityIdType coreSE_u16;        /* Respective core Supervise entity */
    WdgM_CheckpointIdType       coreCP_u16;        /* Respective core checkpoint */
    uint32                      errorId_u32;       /* Error manager error ID (Define error)*/
} wdgCheckOtherCoreCpSts_t;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void WdgSlave_F_MainFunc_v(void);
void WdgSlave_F_Init_v(void);
void WdgSlave_F_GetOtherCoreCpViolInfo_v(wdgOtherCoreCpViolation_t *i_CpViolationInfo_ps);

#endif  /* #ifndef WDG_SLAVE_H_ */

