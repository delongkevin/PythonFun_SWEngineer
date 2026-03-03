/**
 * @file WdgM_Cfg.h
 * @brief Watchdog manager config header file
 *
 * @details This is generated config file for watchdog manager
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2022. Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status. Magna Electronics
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

#if !defined (WDGM_CFG_H)
# define WDGM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "WdgM_Types.h"


/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/
#define WDGM_CFG_MAJOR_VERSION (6u)
#define WDGM_CFG_MINOR_VERSION (0u)
#define WDGM_CFG_PATCH_VERSION (1u)

#ifndef WDGM_DUMMY_STATEMENT
#define WDGM_DUMMY_STATEMENT(v) (v)=(v)
#endif


/* Module config related defines */
# define WDGM_NR_OF_CHECKPOINTS           (1u)
# define WDGM_NR_OF_ENTITIES              (1u)
# define WDGM_NR_OF_ALLOWED_CALLERS       (1u)
# define WDGM_NR_OF_GLOBAL_TRANSITIONS    (0u)
# define WDGM_NR_OF_LOCAL_TRANSITIONS     (0u)
# define WDGM_NR_OF_WATCHDOGS_CORE0       (1u)
# define WDGM_NR_OF_TRIGGER_MODES_CORE0   (1u)

/* Checkpoints for supervised entities */
# define WdgMConf_WdgMCheckpoint_TaskBswB10msec_Alive_CP (0u)

/* Supervised entities */
# define WdgMConf_WdgMSupervisedEntity_TaskBswB10msec_SE (0u)


extern CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0;

#endif /* WDGM_CFG_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.h
 *********************************************************************************************************************/

