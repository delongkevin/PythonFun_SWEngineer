/**
 * @file WdgM.c
 * @brief Wdg Manager for Non autosar Core
 *
 * @details This file contains Wdg Manager task which initiate all safe checkpoints
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
#include "stdint.h"
#include "PlatformDataTypes.h"
#include "WdgM_Private.h"
#include "WdgM.h"
#include "WdgM_Cfg_Private.h"
#include "WdgM_Cfg.h"
#include "WdgIf.h" 

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* File version */
#define D_WDGM_C_MAJOR_VERSION (1)
#define D_WDGM_C_MINOR_VERSION (0)
#define D_WDGM_C_PATCH_VERSION (0)

#if 0
#if defined(BUILD_MCU2_1) || defined(BUILD_MCU1_0)
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
static void WdgM_f_InitVar_v (void);

static void WdgM_f_ChkptCallbackFunc_v (portTaskHandleType i_TaskHandle_pv, 
                                        const portCharType *i_ErrStr_pu8,
                                        portBaseType i_ErrCode_s32 );

static void WdgM_f_CheckAllChkptStarted_v (void);

static void WdgM_f_CheckChkptReStarted_v (WdgmCpid_t i_cpId_e);

static void WdgM_f_logCommonErr_v (uint32_t i_err_u32);

static void WdgM_f_logChkptRespectiveErr_v (WdgmCpid_t i_cpId_e, uint32_t i_err_u32, portBaseType i_errCode_s);

static void WdgM_f_clearErrVar (void);

/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
/* Declare the stack for the checkpoint task. */
static portInt8Type V_WdgmChkptTaskStack_as8[D_WDGM_CHKPT_TASK_STACK_SIZE] __attribute__((aligned(D_WDGM_CHKPT_TASK_STACK_SIZE))) = {0};

/* Queue buffer for the checkpoints command queue. */
static portInt8Type V_WdgmChkptCmdQueueBuff[D_WDGM_CHKPT_CMD_QUEUE_BUFFER_SIZE] __attribute__((aligned(safertosapiWORD_ALIGNMENT))) = {0};

/* Wdg State machine variable */
static WdgmSts_t    V_WdgmSts_e = e_WdgmSts_UNINIT;


/* Flag to control if checking of all checkpoint started required */
static uint8_t      V_WdgmCheckAllChkptStarted_u8 = (uint8_t)TRUE;

/* Timer variable to control checking of all checkpoint started or not */
static uint16_t     v_allChkptStartTmr_u16 = 0;

/* Checkpoint violation flag */
static volatile uint8_t      V_WdgMChkptNoViolation_u8 = (uint8_t)TRUE;

/* Checkpoint id of first violation */
static WdgmCpid_t   V_firstViolationChkptId_e = e_WdgmCpid_cnt;

/* Error capturing variable */
static WdgMErrSts_t     V_wdgmErrSts_s;

/* Checkpoint runtime parameter */
static Wdgm_Chkpt_Param_t  V_WdgMChkptParam_as[e_WdgmCpid_cnt];
/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */
/* Checkpoint buffer */
checkpointControlBlockType V_wdgmChkptBuff_as[e_WdgmCpid_cnt] = {0};

/* Checkpoint handle */
checkpointHandleType       V_wdgmChkptHandle_as[e_WdgmCpid_cnt] = {0};

/* extern declaration of checkpoint configuration structure */
extern Wdgm_Chkpt_Config_t V_wdgmChkptCfg_as[];

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */
/*
 * Purpose: Initialize all global variable
 * Description: Initialize all global variable
 * Return Type: void
 */
static void WdgM_f_InitVar_v (void)
{
  /* DD-ID: {93BD9ADD-F8CD-4435-8FCA-93AA95461676}*/


    uint8_t v_chkptIdx_u8 = 0;

    for(v_chkptIdx_u8 = 0u; v_chkptIdx_u8 < (uint8_t)e_WdgmCpid_cnt; v_chkptIdx_u8++)
    {
        V_wdgmChkptHandle_as[v_chkptIdx_u8] = NULL;
        
        V_WdgMChkptParam_as[v_chkptIdx_u8].isChkptStarted_b = (bool_t)FALSE;
        V_WdgMChkptParam_as[v_chkptIdx_u8].isChkptViolationActive_b = (bool_t)FALSE;
        V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptViolationActiveTmr_u16 = 0u;
        V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptViolationCntr_u8 = 0u;
        V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptRestartTmr_u16 = 0u;
        V_WdgMChkptParam_as[v_chkptIdx_u8].isChkptReStarted_b = (bool_t)FALSE;
    }

    V_WdgmCheckAllChkptStarted_u8 = (uint8_t)TRUE;
    v_allChkptStartTmr_u16 = 0;
    V_WdgMChkptNoViolation_u8 = (uint8_t)TRUE;
    V_firstViolationChkptId_e = e_WdgmCpid_cnt;

    WdgM_f_clearErrVar();
}

/*
 * Purpose: WdgM callback function
 * Description: WdgM callback function common for all checkpoint.
 *              This will be called in case of any checkpoint violation.
 * Return Type: void
 */

static void WdgM_f_ChkptCallbackFunc_v (portTaskHandleType i_TaskHandle_pv, 
                                        const portCharType *i_ErrStr_pu8,
                                        portBaseType i_ErrCode_s32 )
{
  /* DD-ID:{22EFEF45-8002-4d1e-A17B-46952174A68B}*/

	(void)i_ErrStr_pu8;
    uint8_t v_chkptIdx_u8 = 0u;
    portTickType v_xTime1 = 0x00u; 
    portBaseType v_retVal_u32;

    v_xTime1 = xTaskGetTickCount();

    if(v_xTime1 > D_WDGM_CHKPT_WAIT_TIMEOUT)
    {
    /* Parse all checkpoint by their CP task handle */
    for(v_chkptIdx_u8 = 0u; v_chkptIdx_u8 < (uint8_t)e_WdgmCpid_cnt; v_chkptIdx_u8++)
    {
        if(V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_Handle_pv == i_TaskHandle_pv)
        {
            /* Increment CP violation counter */
            V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptViolationCntr_u8++;
            /* Is CP violation counter >= configured threshold value ? */
            if(V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptViolationCntr_u8 >= V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_fail_Threshold_u8)
            {
                /* Checkpoint violation occur more than threshold value -> Mark final violation Flag */
                V_WdgMChkptNoViolation_u8 = (uint8_t)FALSE;
                /*Store checkpoint id of first violation */
                if(V_firstViolationChkptId_e == e_WdgmCpid_cnt)
                {
                    V_firstViolationChkptId_e = (WdgmCpid_t)v_chkptIdx_u8;

                    /* Log error */
                    WdgM_f_logChkptRespectiveErr_v((WdgmCpid_t)v_chkptIdx_u8, (uint32_t)D_WDGM_ERR_CP_VIOLATION_OCCURED, i_ErrCode_s32);
                }
            }
            else /* CP violation counter not reached to configured threshold value */
            {
                /* Stop checkpoint */
                v_retVal_u32 = xCheckpointStop(V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_Handle_pv, D_WDGM_CHKPT_RQST_MAX_DELAY);
                if(v_retVal_u32 != pdPASS)
                {
                    /* As a safety measure Mark final violation Flag */
                    V_WdgMChkptNoViolation_u8 = (uint8_t)FALSE;

                    /*Store checkpoint id of first violation */
                    if(V_firstViolationChkptId_e == e_WdgmCpid_cnt)
                    {
                        V_firstViolationChkptId_e = (WdgmCpid_t)v_chkptIdx_u8;
                    }

                    /* Checkpoint stop failed -> Log error */
                    WdgM_f_logChkptRespectiveErr_v((WdgmCpid_t)v_chkptIdx_u8, (uint32_t)D_WDGM_ERR_CP_STOP_FAILED, (portBaseType)0);
                }
                else
                {
                    /* Reset all counter and flag of corresponding checkpoint */
                    V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptRestartTmr_u16 = 0u;
                    V_WdgMChkptParam_as[v_chkptIdx_u8].isChkptReStarted_b = (bool_t)FALSE;
                    V_WdgMChkptParam_as[v_chkptIdx_u8].isChkptViolationActive_b = (bool_t)TRUE;   /* Violation active */
                    V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptViolationActiveTmr_u16 = 0u;
                }
            }
            
            /* break the loop */
            break;
        }
    }
    }

    /* If no handle matched*/
    if(v_chkptIdx_u8 == (uint8_t)e_WdgmCpid_cnt)
    {
        /* Log error */
        WdgM_f_logCommonErr_v((uint32_t)D_WDGM_ERR_CALLBACK_NO_HANDLE_MATCHED);
    }
}


/*
 * Purpose: Check if all checkpoint started
 * Description: Check if all checkpoint started
 * Return Type: void
 */
static void WdgM_f_CheckAllChkptStarted_v (void)
{
  /* DD-ID: {6FE1ABE7-3FC3-4f58-86D6-229D315DC732}*/


    uint8_t v_chkptIdx_u8;

    /* Iterate through all checkpoint id */
    for(v_chkptIdx_u8 = 0u; v_chkptIdx_u8 < (uint8_t)e_WdgmCpid_cnt; v_chkptIdx_u8++)
    {
        /* Is checkpoint started? */
        if(V_WdgMChkptParam_as[v_chkptIdx_u8].isChkptStarted_b == (bool_t)FALSE)
        {
            /* No This checkpoint not started ->  
               mark vioaltion flag and capture first checkpoint id */
            V_WdgMChkptNoViolation_u8 = (uint8_t)FALSE;
            V_firstViolationChkptId_e = (WdgmCpid_t)v_chkptIdx_u8;

            /* Log error */
            WdgM_f_logChkptRespectiveErr_v((WdgmCpid_t)v_chkptIdx_u8, (uint32_t)D_WDGM_ERR_CP_NOT_STARTED, (portBaseType)0);

            /* No need to check other checkpoint -> break the loop */
            break;
        }
        else
        {
            /* Nothing to do */
        }
    }

    /* This check is required only once -> mark flag */
    V_WdgmCheckAllChkptStarted_u8 = (uint8_t)FALSE;
}


/*
 * Purpose: Check if checkpoint restarted
 * Description: Check if checkpoint restarted
 * Return Type: void
 */
static void WdgM_f_CheckChkptReStarted_v (WdgmCpid_t i_cpId_e) 
{
  /* DD-ID: {56A39545-6433-43b2-870A-A7176C15F1E1}*/
    /* Is checkpoint restarted? */
    if(V_WdgMChkptParam_as[i_cpId_e].isChkptReStarted_b == (bool_t)FALSE)
    {
        /* No This checkpoint not started -> 
           mark vioaltion flag and capture first checkpoint id */
        V_WdgMChkptNoViolation_u8 = (uint8_t)FALSE;
        V_firstViolationChkptId_e = i_cpId_e;

        /* Log error */
        WdgM_f_logChkptRespectiveErr_v(i_cpId_e, (uint32_t)D_WDGM_ERR_CP_NOT_RESTARTED, (portBaseType)0);
    }
    else
    {
        /* Nothing to do */
    }
}


/*
 * Purpose: Clear error variable
 * Description: Clear error variable
 * Return Type: void
 */
static void WdgM_f_clearErrVar (void)
{
  /* DD-ID: {04654293-FD8A-4cce-94BC-8217353557A5}*/
 
    uint8_t v_idx_u8;
    V_wdgmErrSts_s.cmnErrSts_u32 = 0u;
    
    for(v_idx_u8 = 0u; v_idx_u8 < (uint8_t)e_WdgmCpid_cnt; v_idx_u8++)
    {
        V_wdgmErrSts_s.chkptErrSts_as[v_idx_u8].chkPtErr_u32 = 0u;
        V_wdgmErrSts_s.chkptErrSts_as[v_idx_u8].chkptErrCode_s = (portBaseType)0;
    }
}

/*
 * Purpose: Log common error
 * Description: Log common error
 * Return Type: void
 */
static void WdgM_f_logCommonErr_v (uint32_t i_err_u32)
{
  /* DD-ID: {FA3794AC-70E5-4651-B089-04F0F92D0955}*/
 
    V_wdgmErrSts_s.cmnErrSts_u32 |= i_err_u32;
}


/*
 * Purpose: Log checkpoint respective error
 * Description: Log checkpoint respective error
 * Return Type: void
 */
static void WdgM_f_logChkptRespectiveErr_v (WdgmCpid_t i_cpId_e, uint32_t i_err_u32, portBaseType i_errCode_s)
{
  /* DD-ID: {587683F4-8A0E-4c22-BBC0-76B087B6BC9F}*/

    if(i_cpId_e < e_WdgmCpid_cnt)
    {
        V_wdgmErrSts_s.chkptErrSts_as[i_cpId_e].chkPtErr_u32 |= i_err_u32;

        /* Log error only for checkpoint violation */
        if(i_errCode_s != 0)
        {
            V_wdgmErrSts_s.chkptErrSts_as[i_cpId_e].chkptErrCode_s = i_errCode_s;
        }
    }
    else
    {
        /* No need to log any error */
    }
}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Init checkpoint features in WdgM module
 * Description: Inialize checkpoint features for WdgM
 * Return Type: void
 */
void WdgM_F_InitCheckpointFeature_v(void)
{
  /* DD-ID: {F54DF2AE-DFE4-44c2-8A4C-2BCF7E47939A}*/
  
    portBaseType v_retVal_u32;

    /* Init all global variable */
    WdgM_f_InitVar_v();

    /*1. Make Sure Scheduler is initialized with xTaskInitializeScheduler() */

    /* 2. Initialise the Checkpoints module */
    v_retVal_u32 = xCheckpointInitialiseFeature( D_WDGM_CHKPT_PRIORITY,
                                                 D_WDGM_CHKPT_TASK_STACK_SIZE,
                                                 V_WdgmChkptTaskStack_as8,
                                                 D_WDGM_CHKPT_CMD_QUEUE_LEN,
                                                 D_WDGM_CHKPT_CMD_QUEUE_BUFFER_SIZE,
                                                 V_WdgmChkptCmdQueueBuff );
                                                     
    if(v_retVal_u32 == pdPASS)
    {
        /* No error -> Move WdgM state to INIT */
        V_WdgmSts_e = e_WdgmSts_FEATURE_INIT;
    }
    else
    {
        /* Feature init failed -> Log error */
        WdgM_f_logCommonErr_v((uint32_t)D_WDGM_ERR_INIT_FEATURE_FAILED);
    }
}

/*
 * Purpose: Init WdgM module
 * Description: Inialize and create all checkpoint for WdgM
 * Return Type: void
 */
void WdgM_F_Init_v(void)
{
  /* DD-ID: {D200E1C1-46CD-4ca8-89BC-792CDA762396}*/
  
    uint8_t v_chkptIdx_u8;
    portBaseType v_retVal_u32 = pdPASS;
    portBaseType v_tempRetVal_u32;

    /*1. If checkpoint feature initialized */
    if(V_WdgmSts_e == e_WdgmSts_FEATURE_INIT)
    {
        /* 3. Create all checkpoint timer to monitor respective task */
        for(v_chkptIdx_u8 = 0u; v_chkptIdx_u8 < (uint8_t)e_WdgmCpid_cnt; v_chkptIdx_u8++)
        {
            v_tempRetVal_u32 = xCheckpointCreate( V_wdgmChkptCfg_as[v_chkptIdx_u8].ChkptName_pu8,
                                            chkpntMODE_PERIODIC_RELATIVE,
                                            V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_Mon_period_u32,
                                            V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_Mon_min_tol_u32,
                                            V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_Mon_max_tol_u32,
                                            V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_buffer_ps,
                                            WdgM_f_ChkptCallbackFunc_v,
                                            &V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_Handle_pv );
                                            
            if (v_tempRetVal_u32 != pdPASS)
            {
                /* Checkpoint creation failed -> Log error */
                v_retVal_u32 = v_tempRetVal_u32;
                WdgM_f_logChkptRespectiveErr_v((WdgmCpid_t)v_chkptIdx_u8, (uint32_t)D_WDGM_ERR_INIT_CP_CREATE_FAILED, (portBaseType)0);
            }
        }
        if(v_retVal_u32 == pdPASS)
        {
            /* No error -> Move WdgM state to INIT */
            V_WdgmSts_e = e_WdgmSts_INIT;
        }
        else
        {
            /* error -> Already logged */
        }
    }
    else
    {
        /* error -> Already logged */
    }
}


/*
 * Purpose: WdgM Scheduled function
 * Description: WdgM Scheduled function, should be called in 10ms task
 * Return Type: void
 */
void WdgM_F_MainFunction_v(void)
{
  /* DD-ID: {0D46E56A-800B-4e0a-AC9A-CED5D3D591A9}*/
      
    static uint8_t v_initWaitTmr_u8 = 0;
           uint8_t v_chkptIdx_u8 = 0;

    /* If no checkpoint vioaltion -> pass this information to WdgIf */
    if(V_WdgMChkptNoViolation_u8 == (uint8_t)TRUE)
    {
        WdgIf_F_SetTriggerCondition_v((uint8_t)D_WDGM_REFRESH_TIMEOUT);
    }
    else /* If checkpoint violation detected then no need wait for another 100ms */
    {
     //   WdgIf_F_SetTriggerCondition_v(0); // Will be taken As part of Aniketes PR of PMIC and WDG improvment 
    }
    switch (V_WdgmSts_e)
    {
        /* Init state is required to wait for scheduler to stablized
         * During first few cycle tolarnce is more 
         * e.g: 10ms task called at 0, 7, 8, 10, 10 
         *      30ms task called to 0, 22, 25, 30, 27, 30, 30, 29, 30
         */
        case e_WdgmSts_UNINIT:
        case e_WdgmSts_FEATURE_INIT:
        {
            /* If WdgM initialization failed -> report error on UART */
           //  appLogPrintf("WDGM init failed\n");  // Will be taken As part of Aniketes PR of PMIC and WDG improvment 

            /* Perform immediate reset*/
          //  WdgIf_F_SetTriggerCondition_v(0); // Will be taken As part of Aniketes PR of PMIC and WDG improvment 
            
            /* No need to change state */
            break;
        }
        case e_WdgmSts_INIT:
        {
            /* Ignore any request from application in init state */

            /* Wiat for init delay to stablize all task */
            if(v_initWaitTmr_u8 <= (uint8_t)D_WDGM_INIT_WAIT_TIME)
            {
                /* Init delay time is not over -> Increment timer variable */
                v_initWaitTmr_u8++;
            }
            else
            {
                /* Init delay time is over -> Move WdgM state to INIT_OVER */
                V_WdgmSts_e = e_WdgmSts_INIT_WAIT_OVER;
            }

            break;
        }
        case e_WdgmSts_INIT_WAIT_OVER:
        {
            /* Now WdgM is ready to accept any request from application */

            /* Is check required for all checkpoint started or not ?*/
            if(V_WdgmCheckAllChkptStarted_u8 == (uint8_t)TRUE)
            {
                /* Wait for timeout before checking all checkpoint started */
                if(v_allChkptStartTmr_u16 <= D_WDGM_ALL_CHKPT_START_TIMEOUT)
                {
                    /* TImeout not occured -> Increment timer variable */
                    v_allChkptStartTmr_u16++;
                }
                else
                {
                    /* Required timeout elapsed -> call function to check if all checkpoint started */
                    WdgM_f_CheckAllChkptStarted_v();
                }
            }
            

            /* After CP violation check if CP restarted correctly */

            /* Parse all CP */
            for(v_chkptIdx_u8 = 0u; v_chkptIdx_u8 < (uint8_t)e_WdgmCpid_cnt; v_chkptIdx_u8++)
            {
                /* Is CP violation active? */
                if(V_WdgMChkptParam_as[v_chkptIdx_u8].isChkptViolationActive_b == (bool_t)TRUE)
                {
                    /* Wait for configured timeout before checking if stoped checkpoint restarted */
                    if(V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptRestartTmr_u16 <= ( V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_Mon_period_u32  + 
                                                                                   V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_Mon_max_tol_u32 +
                                                                                   V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_restart_check_time_u16))
                    {
                        /* Configured timeout not reached -> Increment CP restart timer */
                        V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptRestartTmr_u16 += (uint8_t)D_WDGM_MAIN_TASK_FREQ;
                    }
                    else
                    {
                        /* Configured timeout reached -> Check if stopped CP resarted */
                        WdgM_f_CheckChkptReStarted_v((WdgmCpid_t)v_chkptIdx_u8);
                    }

                    /* Is CP violation active till configured demature time? */
                    if(V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptViolationActiveTmr_u16 < ( V_wdgmChkptCfg_as[v_chkptIdx_u8].Chkpt_fail_demature_Time_u16))
                    {
                        /* Increment CP violation timer */
                        V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptViolationActiveTmr_u16 += (uint8_t)D_WDGM_MAIN_TASK_FREQ;
                    }
                    else
                    {
                        /* Clear CP violation flag and timer */
                        /* Note: Clear CP violation counter (Don't decrement by 1). Because No new CP violation detected in last configured dematuration time */
                        V_WdgMChkptParam_as[v_chkptIdx_u8].ChkptViolationCntr_u8 = 0;                        
                        V_WdgMChkptParam_as[v_chkptIdx_u8].isChkptViolationActive_b = (bool_t)FALSE;
                    }
                }
            }

            break;
        }

        default:
        {
            /* Nothing to do -> just log error */
            WdgM_f_logCommonErr_v((uint32_t)D_WDGM_ERR_WDGM_SM_REACHED_DEFAULT_ST);
            break;
        }
    }
}


/*
 * Purpose: WdgM checkpoint reached function for tasks to mark progress
 * Description: WdgM checkpoint reached function for tasks to mark progress
 * Return Type: void
 */
void WdgM_F_CheckpointReached_v(WdgmCpid_t i_wdgmCpid_e)
{
  /* DD-ID: {0F7B87F8-CCEB-4edf-9E07-F57A09428569}*/
    
    portBaseType v_retVal_u32;

    /* If init wait time is over then only accept request */
    if(V_WdgmSts_e == e_WdgmSts_INIT_WAIT_OVER)
    {
        /* If request received for valid check point id? */ 
        if(i_wdgmCpid_e < e_WdgmCpid_cnt)
        {
            /* If checkpoint is already started? or restarted after last vioaltion? */
            if((V_WdgMChkptParam_as[i_wdgmCpid_e].isChkptStarted_b == (bool_t)FALSE) || 
               ((V_WdgMChkptParam_as[i_wdgmCpid_e].isChkptViolationActive_b == (bool_t)TRUE) && (V_WdgMChkptParam_as[i_wdgmCpid_e].isChkptReStarted_b == (bool_t)FALSE)))
            {
                /* Checkpoint not started -> start it */
                v_retVal_u32 = xCheckpointStart(V_wdgmChkptCfg_as[i_wdgmCpid_e].Chkpt_Handle_pv, D_WDGM_CHKPT_RQST_MAX_DELAY); 
                if(v_retVal_u32 == pdPASS)
                {
                    /* Is this CP start request at init? */
                    if(V_WdgMChkptParam_as[i_wdgmCpid_e].isChkptStarted_b == (bool_t)FALSE)
                    {
                        /* Checkpoint started -> Mark the CP start flag true */
                        V_WdgMChkptParam_as[i_wdgmCpid_e].isChkptStarted_b = (bool_t)TRUE;
                    }
                    else /* Is this CP restart request after CP vioaltion? */
                    {
                        /* Checkpoint restarted after last violation -> Mark the CP restart flag true */
                        V_WdgMChkptParam_as[i_wdgmCpid_e].isChkptReStarted_b = (bool_t)TRUE;
                    }
                }
                else
                {
                    /* Checkpoint start failed -> Log error */
                    WdgM_f_logChkptRespectiveErr_v(i_wdgmCpid_e, (uint32_t)D_WDGM_ERR_CP_START_FAILED, (portBaseType)0);
                }
            }
            else
            {
                /* Checkpoint started -> Mark it progress */
                v_retVal_u32 = xCheckpointMarkProgress(V_wdgmChkptCfg_as[i_wdgmCpid_e].Chkpt_Handle_pv, D_WDGM_CHKPT_RQST_MAX_DELAY);

                if(v_retVal_u32 != pdPASS)
                {
                    /* Checkpoint Mark progress failed -> Log error */
                    WdgM_f_logChkptRespectiveErr_v(i_wdgmCpid_e, (uint32_t)D_WDGM_ERR_CP_MARK_PROGRESS_FAILED, (portBaseType)0);
                }
            }
        }
        else
        {
            /* Invalid checkpoint id -> Log error */
            WdgM_f_logCommonErr_v((uint32_t)D_WDGM_ERR_RQST_FOR_INVALID_CP);
        }
    }
    else
    {
        /* ignore request -> No need to log error */
    }
}

/*
 * Purpose: Provide check point ID of first expired checkpoint
 * Description: Provide check point ID of first expired checkpoint
 * Return Type: void
 */
void WdgM_F_GetFirstExpiredCpid (unsigned short *i_cpid_pu16)
{
  /* DD-ID: {3B7E3589-D6ED-473b-B0D9-B3B073D3B406}*/
  
    *i_cpid_pu16 = (unsigned short)V_firstViolationChkptId_e;
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
 *  END OF FILE: WdgM.c
 *********************************************************************************************************************/
