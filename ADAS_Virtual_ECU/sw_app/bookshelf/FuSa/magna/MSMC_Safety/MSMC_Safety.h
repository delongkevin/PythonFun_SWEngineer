/**
 * @file MSMC_Safety.h
 * @brief Header file for MSMC safety module
 *
 * @details This file contains MSMC safety module interface
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2023.  Magna Electronics owns all
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
 * @author Fengyi Chen (fengyi.chen@magna.com)
 */

#ifndef __MSMC_SAFETY_H
#define __MSMC_SAFETY_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
typedef enum _required_regs {
    CACHE_CTRL = 0,
    RT_WAY_SELECT,
    NRT_WAY_SELECT,
    COHCTRL,
    SMEDCC,
    SMESTAT,
    SBNDCOH0,
    SBNDCOH1,
    SBNDCOH2,
    SBNDCOH3,
    SBNDCOH4,
    SBNDCOH5,
    SBNDCOH6,
    SBNDCOH7,
    SBNDCOH8,
    SBNDCOH9,
    SBNDCOH10,
    SBNDCOH11,
    SBNDCOH12,
    SBNDDRU,
    SBNDRESP,
    MSMC_REG_MAX,
} required_regs;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void Sdl_Application_MSMC_init(void);
void Sdl_Application_MSMC_Safety(void);
/* === End Of Header File ================================================= */
#endif  /* __MSMC_SAFETY_H*/
