/**
 * @file WdgM_Intr.c
 * @brief Disable / Enable global interrupt for WdgM
 *
 * @details Disable / Enable global interrupt for WdgM for non autosar core.
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

 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include <stdint.h>
#if defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
#include <ti/osal/osal.h>
#endif

#if defined(BUILD_MCU2_0)
#include <ti/osal/TaskP.h>
#include <ti/osal/SemaphoreP.h>
#include <ti/osal/HwiP.h>
#ifndef SOC_J721E
#define SOC_J721E
#endif
#endif

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */


/* ===========================================================================

*   Global variables
*
* ========================================================================= */


/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */


/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */

/* ===========================================================================
*
* Private variables
*
* ========================================================================= */


/* ===========================================================================
*
* Private functions
*
* ========================================================================= */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if defined(BUILD_MPU1_0)
static pthread_mutex_t V_key_s = PTHREAD_MUTEX_INITIALIZER
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)  || defined(BUILD_MCU3_0)
static uintptr_t V_key_s;
#endif

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */
/*
 * Purpose: Enable interrupts
 * Description: Enable interrupts.
 * Return Type : void
*/
void WdgM_F_EnableInrerrupt_v (void)
{
  /* DD-ID: {D0CA37F9-1E01-429f-A519-8FA6B86FE72A}*/
#if defined(BUILD_MPU1_0)
    pthread_mutex_unlock(&V_key_s);
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)  || defined(BUILD_MCU3_0)
    HwiP_restore(V_key_s); /* restore interrupts */
#endif
}

/*
 * Purpose: Disable interrupts
 * Description: Disable interrupts.
 * Return Type : void
*/
void WdgM_F_DisableInrerrupt_v (void)
{
  /* DD-ID: {34067F59-45EE-49c4-9C26-2CCB97738484}*/
#if defined(BUILD_MPU1_0)
    pthread_mutex_lock(&V_key_s); /* pthread for WdgM */
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
    V_key_s = HwiP_disable(); /* disable interrupts */
#endif
}

/*===============================End Of File========================================================*/
