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
#define WDGM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* Checkpoints */
typedef enum WdgmCpid_e
{
    e_WdgmCpid_TaskSafetyBsw10msec = 0,   /* 00 */
    e_WdgmCpid_TaskAppB10msecHiPriority,  /* 01 */
    e_WdgmCpid_TaskBSWQM1msec,            /* 02 */  
    e_WdgmCpid_TaskBSWQM10msec,           /* 03 */  
   // e_WdgmCpid_TaskSafetyApp200msec,    /* 04 */
    e_WdgmCpid_cnt                        /* 05 */
} WdgmCpid_t;


#endif /* WDGM_CFG_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.h
 *********************************************************************************************************************/

