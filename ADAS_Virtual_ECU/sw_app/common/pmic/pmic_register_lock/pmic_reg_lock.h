/**
 * @file pmic_reg_lock.h
 * @brief Header file for register lock monitoring  
 *
 * @details This file contains pmic register lock monitoring interface
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
 * @author Varun Kwatra  (Varun.Kwatra@magna.com)
 */
 
#ifndef __PMIC_REGISTER_LOCK_H
#define __PMIC_REGISTER_LOCK_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* Key to write to REGISTER_LOCK register to unlock registers */
#define D_PMIC_REG_LOCK_KEY       (0x01)   /* Locking registers: write anything else than 0x9B to this address */
#define D_PMIC_REG_UNLOCK_KEY     (0x9B)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void Pmic_F_RegLockMon_v(void);
int32_t Pmic_F_RegUnLockMon_v(uint8_t device);

/* === End Of Header File ================================================= */
#endif  /* __PMIC_REGISTER_LOCK_H */
