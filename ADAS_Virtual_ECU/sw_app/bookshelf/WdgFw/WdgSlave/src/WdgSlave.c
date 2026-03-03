/**
 * @file WdgSlave.c
 * @brief Watch dog slave to receive status of other core's Wdg driver
 *
 * @details WdgSlave is applicable only for MCU1_0. WdgSlave read Wdg status 
 *          of other core and reset HW watchdog through PMIC on any violation.
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
#include "WdgM.h"
//#include "Rte_SWC_WdgFw.h"
#include "Rte_CDD_WDG.h"
#include "WdgSlave.h"
#include "Wdg_Cfg.h"
#include "Rte_SWC_ProxiConfigMgr_Type.h" //BhagwanP : Remove After Error Manager Implementetion
//#include "app_log_Boot.h"
#ifdef BUILD_MCU1_0
#include "fusa_application.h"
#endif


/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* Configuration */
/* Init wait time */
#define D_WDGSLAVE_INIT_DELAY_TIME      (150)  /* 1.5 Sec */

/* Keep Calling Checkpoint reached function, if last status received within 1000ms */
#define D_WDGSLAVE_WDG_STS_RCVD_TIMEOUT (100)   /* 1000ms */

/* ===========================================================================

*   Global variables
*
* ========================================================================= */

/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
/* Variable to store CP vioaltion status of other core */
static wdgOtherCoreCpViolation_t v_wdgOtherCoreCpViolInfo_as[D_WDG_CORE_CNT];

/* Lookup table having multiple attribute for respective core */
static const wdgCheckOtherCoreCpSts_t v_wdgCheckOtherCoreCpSts_as[D_WDG_CORE_CNT] =
{
/* isStatusCheckReq_u8             coreSE_u16                                       coreCP_u16                          errorId_u32                           */
        /* 0,          WdgMConf_WdgMSupervisedEntity_WdgM_SE_MPU1_0, WdgMConf_WdgMCheckpoint_WdgMAliveCP_MPU1_0, D_WDG_REPORT_CP_VIOLATION_ERR_MPU1_0,*/ /* MPU1_0 */
        /* 1,          WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU2_0, WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU2_0, D_WDG_REPORT_CP_VIOLATION_ERR_MCU2_0,*/ /* MCU2_0 */
        {1u,          WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU2_1, WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU2_1, D_WDG_REPORT_CP_VIOLATION_ERR_MCU2_1}, /* MCU2_1 */
        /* 0,          WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU3_0, WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU3_0, D_WDG_REPORT_CP_VIOLATION_ERR_MCU3_0,*/ /* MCU3_0 */
        /* 1,          WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU3_1, WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU3_1, D_WDG_REPORT_CP_VIOLATION_ERR_MCU3_1*/  /* MCU3_1 */
};


/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */
/* Wdg Slave state machine to monitor other core checkpoint status */
typedef enum WdgSlaveOtherCoreMonSt_e
{
    e_WdgSlaveOtherCoreMonSt_UNINIT = 1 ,  /* 01 */
    e_WdgSlaveOtherCoreMonSt_INIT       ,  /* 02 */
    e_WdgSlaveOtherCoreMonSt_NORMAL     ,  /* 03 */
} WdgSlaveOtherCoreMonSt_t;

/* ===========================================================================
*
* Private variables
*
* ========================================================================= */
static uint16                   V_WdgSlaveInitDelayTmr_u16 = 0u;
static WdgSlaveOtherCoreMonSt_t V_WdgSlaveOtherCoreMonSmSt_e = e_WdgSlaveOtherCoreMonSt_UNINIT;

/* ===========================================================================
*
* Private functions
*
* ========================================================================= */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */
/*
 * Purpose: Function to initialize all global variable associated with WdgSlave
 * Description: Function to initialize all global variable associated with WdgSlave.
 * Precondition: None
 * Return Type : void
*/
void WdgSlave_F_Init_v(void)
{
	/* DD-ID: {FE2E0EFD-E4B7-4116-AD0E-7FD300440D11}*/
    uint8 v_idx_u8;

    for(v_idx_u8 = 0u; v_idx_u8 < (uint8)D_WDG_CORE_CNT; v_idx_u8++)
    {
        v_wdgOtherCoreCpViolInfo_as[v_idx_u8].isViolation_u8 = (uint8)0;
        v_wdgOtherCoreCpViolInfo_as[v_idx_u8].seid_u16 = (uint16)0;
        v_wdgOtherCoreCpViolInfo_as[v_idx_u8].errorId_u32 = v_wdgCheckOtherCoreCpSts_as[v_idx_u8].errorId_u32;
    }

    /* Initialize all global variable */
    V_WdgSlaveInitDelayTmr_u16 = 0u;
    V_WdgSlaveOtherCoreMonSmSt_e = e_WdgSlaveOtherCoreMonSt_INIT;
}

/*
 * Purpose: WdgSlave scheduled function
 * Description: WdgSlave scheduled function to handle Wdg status of other core.
 * Precondition: WDG must be initialized
 * Return Type : void
*/
#define INCREMENT_BY_ONE            (1u)
#define DECREMENT_BY_ONE            (1u)
void WdgSlave_F_MainFunc_v(void)  /* PRQA S 5700 */ /* Not possible to implement within 2 level deep if-else */
{
    /* RTE interface to report error to error manager for respective core */
    static Std_ReturnType (*WdgSlave_F_ReadWdgStsFromOtherCore_U32[D_WDG_CORE_CNT])(WdgCheckpointStatus_t *) = 
    {
    /* Rte_Read_SWC_WdgFw_R_WdgCheckpointStatus_Mpu1_0_Core, */
    /* Rte_Read_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t, */
        Rte_Read_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t,
    /* Rte_Read_SWC_WdgFw_R_WdgCheckpointStatus_Mcu3_0_Core, */
    /* Rte_Read_SWC_WdgFw_R_WdgCheckpointStatus_Mcu3_1_Core */
    };     
    WdgCheckpointStatus_t v_WdgCheckpointStatusOtherCore_t[D_WDG_CORE_CNT] = {0u};

	/* DD-ID: {62044103-D86B-426d-88BF-BA6B9DCAC4CC}*/
    static uint32         v_wdgDataLiveCntrPrev_au32[D_WDG_CORE_CNT] = {0u};
    static uint8          V_WdgSlaveChkptStsRcvdTmr_au8[D_WDG_CORE_CNT] = {0u};
    uint8                 v_idx_u8;
#ifdef BUILD_MCU1_0
    uint16 TSDStatus;
#endif /*BUILD_MCU1_0*/
  

    switch(V_WdgSlaveOtherCoreMonSmSt_e)
    {
        case e_WdgSlaveOtherCoreMonSt_INIT:
        {            
            /* 1. Call Checkpoint reached function for all cores */
            for(v_idx_u8 = 0u; v_idx_u8 < (uint8)D_WDG_CORE_CNT; v_idx_u8++)
            {
                (void)WdgM_CheckpointReached(v_wdgCheckOtherCoreCpSts_as[v_idx_u8].coreSE_u16, v_wdgCheckOtherCoreCpSts_as[v_idx_u8].coreCP_u16);
            }
            
            /* 2. Increment init delay timer */
            V_WdgSlaveInitDelayTmr_u16 = V_WdgSlaveInitDelayTmr_u16 + INCREMENT_BY_ONE;

            if (V_WdgSlaveInitDelayTmr_u16 >= (uint16)D_WDGSLAVE_INIT_DELAY_TIME)
            {
                /* Move to next state */
                V_WdgSlaveOtherCoreMonSmSt_e = e_WdgSlaveOtherCoreMonSt_NORMAL;
            } else{ /* Do Nothing */ }

            break;
        }

        case e_WdgSlaveOtherCoreMonSt_NORMAL:
        {
            /* Iterate through all core to receive Wdg status over IPC */
            for(v_idx_u8 = 0u; v_idx_u8 < (uint8)D_WDG_CORE_CNT; v_idx_u8++)
            {
#ifdef BUILD_MCU1_0
            	TSDStatus = Cdd_Safety_GetTSDStatus();
#endif /*BUILD_MCU1_0*/
                /* Check if core for respective index need to check CP violation status */
                if((v_wdgCheckOtherCoreCpSts_as[v_idx_u8].isStatusCheckReq_u8 == (uint8)1u)
#ifdef BUILD_MCU1_0
        		&& (((uint16)SDL_VTM_TSD_REQ != TSDStatus)
        		 && ((uint16)SDL_VTM_TSD_DONE != TSDStatus))/* Note: Mask Alive monitoring of remote cores in case of Thermal-Shutdown */
#endif /*BUILD_MCU1_0*/
        		)
                {
                    /* Read checkpoint status from other core */
                    WdgSlave_F_ReadWdgStsFromOtherCore_U32[v_idx_u8](&v_WdgCheckpointStatusOtherCore_t[v_idx_u8]);

                    /* Check freshness of data */
                    if (v_WdgCheckpointStatusOtherCore_t[v_idx_u8].wdgDataLiveCntr_u32 != v_wdgDataLiveCntrPrev_au32[v_idx_u8])
                    {
                        /* Update previous counter same as new */
                        v_wdgDataLiveCntrPrev_au32[v_idx_u8] = v_WdgCheckpointStatusOtherCore_t[v_idx_u8].wdgDataLiveCntr_u32;

                        /* If any checkpoint violation, update flag to stop refreshing Wdg */
                        if (v_WdgCheckpointStatusOtherCore_t[v_idx_u8].timeoutCntr_u16 == (uint16)0u)
                        {
                            /* Save CP violation info of other core */
                            v_wdgOtherCoreCpViolInfo_as[v_idx_u8].isViolation_u8 = (uint8)1u;
                            v_wdgOtherCoreCpViolInfo_as[v_idx_u8].seid_u16 = v_WdgCheckpointStatusOtherCore_t[v_idx_u8].seid_s;
                        }
                        else  /* Call checkpoint reached for respective core */
                        {
                            /* No checkpoint violation occured -> Refresh Wdg */
                            (void)WdgM_CheckpointReached(v_wdgCheckOtherCoreCpSts_as[v_idx_u8].coreSE_u16, v_wdgCheckOtherCoreCpSts_as[v_idx_u8].coreCP_u16);

                            /* Wdg status received for other core through IPC -> Start timer */
                            V_WdgSlaveChkptStsRcvdTmr_au8[v_idx_u8] = (uint8)D_WDGSLAVE_WDG_STS_RCVD_TIMEOUT;
                        }
                    }
                    else
                    {
                        /* No new data (Wdg status) received */
                        if(V_WdgSlaveChkptStsRcvdTmr_au8[v_idx_u8] > (uint8)0u)
                        {
                            /* Decrement Wdg status recived timer */
                            V_WdgSlaveChkptStsRcvdTmr_au8[v_idx_u8] = V_WdgSlaveChkptStsRcvdTmr_au8[v_idx_u8] - DECREMENT_BY_ONE;

                            /* Call checkpoint reached function (If Wdg status received in last 100ms) */
                            (void)WdgM_CheckpointReached(v_wdgCheckOtherCoreCpSts_as[v_idx_u8].coreSE_u16, v_wdgCheckOtherCoreCpSts_as[v_idx_u8].coreCP_u16);
                        } else{ /* Do Nothing */ }
                    }
                }
                else  /* No need to check CP vioaltion status of respective core  */
                {
                    /* Call Checkpoint reached function for respective core without bothering for its CP violation status -> To avoid Wdg Reset */
                    (void)WdgM_CheckpointReached(v_wdgCheckOtherCoreCpSts_as[v_idx_u8].coreSE_u16, v_wdgCheckOtherCoreCpSts_as[v_idx_u8].coreCP_u16);
                }
            }

            break;
        }

        default:
        {
            /* Do Nothing */
            break;
        }
    }
}

/*
 * Purpose: Function to return Wdg checkpoint violation status of all other core
 * Description: Function to return Wdg checkpoint violation status of all other core
 * Precondition: WDG must be initialized
 * Return Type : void
*/
void WdgSlave_F_GetOtherCoreCpViolInfo_v(wdgOtherCoreCpViolation_t *i_CpViolationInfo_ps)
{
	/* DD-ID: {8A46FF6A-F990-4cbc-ABD9-278F0C924F68}*/
    uint8 v_idx_u8;

    if (i_CpViolationInfo_ps != NULL_PTR)
    {
        for(v_idx_u8 = 0u; v_idx_u8 < (uint8)D_WDG_CORE_CNT; v_idx_u8++)
        {
            i_CpViolationInfo_ps[v_idx_u8].isViolation_u8 = v_wdgOtherCoreCpViolInfo_as[v_idx_u8].isViolation_u8;
            i_CpViolationInfo_ps[v_idx_u8].seid_u16 = v_wdgOtherCoreCpViolInfo_as[v_idx_u8].seid_u16;
            i_CpViolationInfo_ps[v_idx_u8].errorId_u32 = v_wdgCheckOtherCoreCpSts_as[v_idx_u8].errorId_u32;
          
        }
    } else{ /* Do Nothing */ }
}

/*===============================End Of File========================================================*/
