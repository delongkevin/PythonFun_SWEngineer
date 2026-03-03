/**
 * @file WdgM.h
 * @brief WdgM header file
 *
 * @details This file contain Wdg Manager interface
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
 * @author Pramod Kumar  (pramod.kumar1@magna.com)
 */

#ifndef WDGM_H_ 
#define WDGM_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "WdgM_Cfg.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void WdgM_F_InitCheckpointFeature_v(void);
void WdgM_F_Init_v(void);
void WdgM_F_MainFunction_v(void);
void WdgM_F_CheckpointReached_v(WdgmCpid_t i_wdgmCpid_e);
void WdgM_F_GetFirstExpiredCpid (unsigned short *i_cpid_pu16);

/* === End Of Header File ================================================= */
#endif /* #ifndef WDGM_H_ */

