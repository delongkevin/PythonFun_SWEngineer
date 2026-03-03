/**
 * @file WdgGlobal.h
 * @brief This file contains interface header for WDG timeout status to communicate to MCU1_0
 *
 * @details This file contains interface header for WDG timeout status to communicate to MCU1_0
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
#ifndef WDG_GLOBAL_H_
#define WDG_GLOBAL_H_
 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#if defined(BUILD_MCU2_1) || defined(BUILD_MPU1_0) || defined(BUILD_MCU2_0)   
#include "PlatformDataTypes.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
typedef struct WdgCheckpointStatus_s
{
    uint16_t timeoutCntr_u16;
    uint16_t seid_s;
    uint32_t wdgDataLiveCntr_u32;
    //WdgM_SupervisedEntityIdType seid_s;
    //WdgM_ViolationType          violation_s;
    //uint8                       resv_u8[3];
}WdgCheckpointStatus_t;
#endif

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

#endif  /* #ifndef WDG_GLOBAL_H_ */
