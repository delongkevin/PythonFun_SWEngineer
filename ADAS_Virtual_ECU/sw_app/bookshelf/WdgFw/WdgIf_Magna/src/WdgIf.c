/**
 * @file WdgIf.c
 * @brief Wdg Interface for Non autosar Core
 *
 * @details This file contains Wdg interface (WdgIf) module implementation
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
#include "WdgIf.h"
#include "Wdg.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* File version */
#define D_WDGIF_C_MAJOR_VERSION (1)
#define D_WDGIF_C_MINOR_VERSION (0)
#define D_WDGIF_C_PATCH_VERSION (0)

#if 0
#if defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
#define START_ASILB_CODE_SECTION
#include "asil_memmap.h"
#define START_ASILB_DATA_SECTION
#include "asil_memmap.h"
#define START_ASILB_BSS_SECTION
#include "asil_memmap.h"
#define START_ASILB_CONST_SECTION
#include "asil_memmap.h"
#endif
#endif

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


/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Set WdgIf trigger condition
 * Description: Set WdgIf trigger condition by calling Wdg's interface and providing timeout passed by WdgM
 * Return Type: void
 */
void WdgIf_F_SetTriggerCondition_v(uint8_t i_wdgmRefreshTimeout_u8)
{
  /* DD-ID: {850E7893-9FB0-429e-AB0D-E7203BC940C8}*/

    Wdg_SetTriggerCondition((uint16)i_wdgmRefreshTimeout_u8);
}

#if 0
#if defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
#define STOP_ASILB_CODE_SECTION
#include "asil_memmap.h"
#define STOP_ASILB_DATA_SECTION
#include "asil_memmap.h"
#define STOP_ASILB_BSS_SECTION
#include "asil_memmap.h"
#define STOP_ASILB_CONST_SECTION
#include "asil_memmap.h"
#endif
#endif
/*******************************************************************************************
 *                        Revision history
 *******************************************************************************************
 * Rev No.       Date       Author        Change Description
 * ------    -----------   --------       ------------------
 * 1.0.0     03-Mar-2023  Pramod Kumar    First Verion
 *
 *******************************************************************************************/
/**********************************************************************************************************************
 *  END OF FILE: WdgIf.c
 *********************************************************************************************************************/
