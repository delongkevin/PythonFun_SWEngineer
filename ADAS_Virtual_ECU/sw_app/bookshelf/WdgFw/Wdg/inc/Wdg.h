/**
 * @file Wdg.h
 * @brief This file contains interface header for WDG MCAL driver
 *
 * @details This file contains interface header for WDG MCAL driver
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
#ifndef WDG_H_
#define WDG_H_
 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
#include "Platform_Types.h"
#else
# include "PlatformDataTypes.h"
#endif
#if !defined(BUILD_MCU2_1) && !defined(BUILD_MCU2_0)
#include "WdgIf_Types.h"
#endif


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
typedef struct WdgConfig_s
{
    uint16 timeOutCounter_u16; /* Watchdog timeOutCounter value */    
} WdgConfig_t;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void Wdg_Init(void);
void Wdg_SetTriggerCondition(uint16 timeout);
void Wdg_Trigger(void);
#if !defined(BUILD_MCU2_1) && !defined(BUILD_MCU2_0)
Std_ReturnType Wdg_SetMode(WdgIf_ModeType Mode);
#endif
#if defined(BUILD_MCU1_0)
uint16 V_wdgGetWdgErrorVal(void);
#endif
#endif  /* #ifndef WDG_H_ */

