/**
 * @file WdgM_Private.h
 * @brief WdgM private header file
 *
 * @details This file contain Wdg Manager interface (Available only for WdgM)
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

#ifndef WDGM_PRIVATE_H_ 
#define WDGM_PRIVATE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* SafeRTOS includes */
#include "SafeRTOS_API.h"
#include "WdgM_Cfg.h"
#include "PlatformDataTypes.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* Error capturing Macros */
/* common error */
#define D_WDGM_ERR_INIT_FEATURE_FAILED              (0x000001U)  /* xCheckpointInitialiseFeature() failed */
#define D_WDGM_ERR_CALLBACK_NO_HANDLE_MATCHED       (0x000002U)  /* WdgM callback function called with invalid WdgM handle */
#define D_WDGM_ERR_WDGM_SM_REACHED_DEFAULT_ST       (0x000004U)  /* WdgM state machine reached to default state */
#define D_WDGM_ERR_RQST_FOR_INVALID_CP              (0x000008U)  /* Appl called WdgM_F_CheckpointReached_v() with invalid check point ID */

/* Error per checkpoint */
#define D_WDGM_ERR_INIT_CP_CREATE_FAILED            (0x000001U)  /* xCheckpointCreate() failed */
#define D_WDGM_ERR_CP_START_FAILED                  (0x000002U)  /* xCheckpointStart() failed */
#define D_WDGM_ERR_CP_MARK_PROGRESS_FAILED          (0x000004U)  /* xCheckpointMarkProgress() failed */
#define D_WDGM_ERR_CP_NOT_STARTED                   (0x000008U)  /* Checkpoint not started */
#define D_WDGM_ERR_CP_NOT_RESTARTED                 (0x000010U)  /* Checkpoint not restarted */
#define D_WDGM_ERR_CP_VIOLATION_OCCURED             (0x000020U)  /* Checkpoint violation occured */
#define D_WDGM_ERR_CP_STOP_FAILED                   (0x000040U)  /* xCheckpointStop() failed */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/* WdgM checkpoint configuration structure */
typedef struct Wdgm_Chkpt_Config_s
{
    portCharType               *ChkptName_pu8;               /* Checkpoint name */
    portTickType               Chkpt_Mon_period_u32;         /* Checkpoint monitor period in Ticks */
    portTickType               Chkpt_Mon_min_tol_u32;        /* Checkpoint monitor minimum tolerance in Ticks */
    portTickType               Chkpt_Mon_max_tol_u32;        /* Checkpoint monitor maximum tolerance in Ticks */
    checkpointControlBlockType *Chkpt_buffer_ps;             /* Checkpoint buffer */
    checkpointHandleType       Chkpt_Handle_pv;              /* Checkpoint handle */
    uint8_t                    Chkpt_fail_Threshold_u8;      /* Checkpoint fail threshold count */
    uint16_t                   Chkpt_fail_demature_Time_u16; /* Checkpoint fail dematuration time (*10ms) */
    uint16_t                   Chkpt_restart_check_time_u16; /* After CP violation check if CP restarted after 
                                                              * Chkpt_Mon_period_u32 + Chkpt_Mon_max_tol_u32 + 
                                                              * Chkpt_start_recheck_time */
} Wdgm_Chkpt_Config_t;

/* WdgM checkpoint runtime parameter */
typedef struct Wdgm_Chkpt_Param_s
{
    bool_t                       isChkptStarted_b;             /* Flag to check if checkpoint started */
    bool_t                       isChkptViolationActive_b;     /* Flag to check if checkpoint violation Active */
    uint16_t                   ChkptViolationActiveTmr_u16;  /* Checkpoint violation counter */
    uint8_t                    ChkptViolationCntr_u8;        /* Checkpoint violation counter */
    uint16_t                   ChkptRestartTmr_u16;          /* Checkpoint restart timer */    
    bool_t                       isChkptReStarted_b;           /* Flag to check if checkpoint restarted */
} Wdgm_Chkpt_Param_t;

/* WdgM state machine's states enum */
typedef enum WdgmSts_e
{
    e_WdgmSts_UNINIT = 1 ,   /* 01 */
    e_WdgmSts_FEATURE_INIT,  /* 02 */
    e_WdgmSts_INIT,          /* 03 */
    e_WdgmSts_INIT_WAIT_OVER /* 04 */
} WdgmSts_t;

/* Checkpoint error */
typedef struct WdgMChkPtErrSts_s
{

    uint32_t       chkPtErr_u32;                 /* Checkpoint Error */
    portBaseType   chkptErrCode_s;               /* Error per checkpoint */
} WdgMChkPtErrSts_t;

/* WdgM error capturing structure */
typedef struct WdgMErrSts_s
{
    uint32_t          cmnErrSts_u32;                   /* Common error */
    WdgMChkPtErrSts_t chkptErrSts_as[e_WdgmCpid_cnt];  /* Error per checkpoint */
} WdgMErrSts_t;


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


/* === End Of Header File ================================================= */
#endif /* #ifndef WDGM_PRIVATE_H_ */

