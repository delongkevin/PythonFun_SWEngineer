/**
 * @file pmic_voltmon.h
 * @brief Header file for pmic voltage monitoring
 *
 * @details This file contains pmic voltage monitoring interface
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
 
#ifndef __PMIC_VOLTMON_H
#define __PMIC_VOLTMON_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "pmic_voltmon_cfg.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define D_PMIC_VOLTMON_CFG_STEP_1    (1)  /* PMIC voltmon configuration Step 1 */
#define D_PMIC_VOLTMON_CFG_STEP_2    (2)  /* PMIC voltmon configuration Step 2 */

/* PMIC regulator type */
#define D_PMIC_REGULATOR_TYPE_BUCK   (1)  /* BUCK */
#define D_PMIC_REGULATOR_TYPE_LDO    (2)  /* LDO */

/* PMIC monitor type */
#define D_PMIC_MON_TYPE_VOLT         (1)  /* Voltage monitor */
#define D_PMIC_MON_TYPE_CURR         (2)  /* Current monitor */
#define D_PMIC_MON_TYPE_RV           (3)  /* Residual voltage / Short circuit monitor */
#define D_PMIC_MON_TYPE_VCCA         (4)  /* VCCA voltage monitor */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void Pmic_F_VoltmonConfigStep_v(uint8_t i_step_u8);
void Pmic_F_Voltmon_v(void);

/* === End Of Header File ================================================= */
#endif  /* __PMIC_VOLTMON_H */
