/**
 * @file WdgM_Cfg_Private.h
 * @brief Watchdog manager config private header file
 *
 * @details This is config file for watchdog manager (available only to WdgM)
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

#if !defined (WDGM_CFG_PRIVATE_H)
#define WDGM_CFG_PRIVATE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* Checkpoint feature Config */
#define D_WDGM_CHKPT_PRIORITY         ( configMAX_PRIORITIES - 1U )
#define D_WDGM_CHKPT_TASK_STACK_SIZE  ( 512U )
#define D_WDGM_CHKPT_CMD_QUEUE_LEN    (2U * (uint8)e_WdgmCpid_cnt)  /* Try to keep double of number of checkpoints */
#define D_WDGM_CHKPT_CMD_QUEUE_BUFFER_SIZE \
                ((D_WDGM_CHKPT_CMD_QUEUE_LEN * sizeof(timerQueueMessageType)) + safertosapiQUEUE_OVERHEAD_BYTES)
                
#define D_WDGM_CHKPT_RQST_MAX_DELAY    (0x00U)  /* Tick count, 1 Tick -> 1ms */

/* WDGM init delay */
#define D_WDGM_INIT_WAIT_TIME          (100U)    /* 100ms */ 

/* WDGM refresh timeout */
#define D_WDGM_REFRESH_TIMEOUT         (10U)   /* 100ms */

/* Timeout after which, check if all checkpoint started */
#define D_WDGM_ALL_CHKPT_START_TIMEOUT (1000U)  /* 10 Sec */

/*Timeout after which, checkpoint monitoring will start till then ignore the missed checkpoints */
#define D_WDGM_CHKPT_WAIT_TIMEOUT       (5000U)  /* 5 Sec */

/* Calling freq of function WdgM_F_MainFunction_v() */
#define D_WDGM_MAIN_TASK_FREQ          (10U)    /* 10ms */

#endif /* WDGM_CFG_PRIVATE_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.h
 *********************************************************************************************************************/

