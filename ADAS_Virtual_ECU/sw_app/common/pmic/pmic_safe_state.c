/**
 * @file pmic_safe_state.c
 * @brief Safe state implementation for PMIC driver
 *
 * @details Safe state implementation for PMIC driver
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
 * @author Pramod Kumar (Pramod.kumar1@magna.com)
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include <ti/drv/sciclient/sciclient.h>
#include "pmic_cfg.h"
#include "pmic_utils.h"
#include "Os.h"
#include "pmic.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */


/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */


/* ===========================================================================
*
* Private functions
*
* ========================================================================= */


/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */


/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */


/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */
/*
 * Purpose: Switch to Safe state 2
 * Description: Switch to Safe state 2 by performing Pmic soft reset.
 * Return Type: void
 */
void Pmic_F_SafeState2_v(uint8_t SafeStateReason)
{
    /* DD-ID:{B8D71DAC-568E-428a-8ED2-907108149872}*/
#ifdef ENABLE_PMIC_EXTWDG
    Pmic_utils_SoftReboot(SafeStateReason);
#endif
}

