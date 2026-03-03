/**
 * @file WdgM_Cfg.c
 * @brief Watchdog manager config file
 *
 * @details This file contain configuration of all checkpoint
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2023. Magna Electronics owns all
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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "stdint.h"
#include "WdgM_Private.h" 
#include "WdgM.h"
#include "WdgM_Cfg.h"


extern checkpointControlBlockType V_wdgmChkptBuff_as[];
extern checkpointHandleType       V_wdgmChkptHandle_as[];

Wdgm_Chkpt_Config_t V_wdgmChkptCfg_as[e_WdgmCpid_cnt] = 
{
    /*       name            Mon Period      Min Tol      Max Tol        Checkpoint                                                         Checkpoint                                     Checkpoint        Checkpoint fail      Time to check       */
    /*                         (Ticks)       (Ticks)      (Ticks)         Buffer                                                              handle                                       Fail threshold     Dematuration time   Checkpoint Restart  */
    /* =================    ============    =========    =========    ========================= 	                               =========================================             ================    ==================  ================     */
     { "TaskBSWSafety10msec",    10,            9,           20,      &V_wdgmChkptBuff_as[e_WdgmCpid_TaskSafetyBsw10msec],        &V_wdgmChkptHandle_as[e_WdgmCpid_TaskSafetyBsw10msec] ,      2,               500,                10          }, /* e_WdgmCpid_TaskSafetyBsw10msec */
     { "TaskAppB10msecHiPrio",   30,            28,          60,      &V_wdgmChkptBuff_as[e_WdgmCpid_TaskAppB10msecHiPriority],   &V_wdgmChkptHandle_as[e_WdgmCpid_TaskAppB10msecHiPriority],  2,               500,                10          }, /* e_WdgmCpid_TaskAppB10msecHiPriority */
     { "TaskBSWQM1msec",         10,            9,           20,      &V_wdgmChkptBuff_as[e_WdgmCpid_TaskBSWQM1msec],             &V_wdgmChkptHandle_as[e_WdgmCpid_TaskBSWQM1msec] ,           2,               500,                10          }, /* e_WdgmCpid_TaskBSWQM1msec */
     { "TaskBSWQM10msec",        10,            9,           20,      &V_wdgmChkptBuff_as[e_WdgmCpid_TaskBSWQM10msec],            &V_wdgmChkptHandle_as[e_WdgmCpid_TaskBSWQM10msec] ,          2,               500,                10          }, /* e_WdgmCpid_TaskBSWQM10msec */

};
/**********************************************************************************************************************                                                                  
 *  END OF FILE: WdgM_Cfg.c
 *********************************************************************************************************************/

