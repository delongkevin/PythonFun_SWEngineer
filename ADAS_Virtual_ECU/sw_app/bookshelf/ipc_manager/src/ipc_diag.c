/**
 * @file ipc_diag.c
 * @brief IPC diag feature
 *
 * @details This file has implementation of IPC diag feature
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2014.  Magna Electronics owns all
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
 * @author ----  (---- @magna.com)
 */

/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include <stdint.h>
#include <string.h>
#include "ipc_cfg.h"
#include "ipc_lookup_table.h"
#include "ipc_lookup_table_struct.h"
#include "ipc_large_buff_mgr.h"
#include "ipc_diag.h"
#include "ipc_error.h"
#include "ipc_debug.h"
#include <ti/osal/TimerP.h>

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */


/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */
#define D_DIAG_CLEAR_LATENCY_INFO_TIME   (30U) /* 30 Sec -> Clear latency info once at startup */

/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
/* IPC Diag variable */
#if ((D_IPC_FEATURE_TX_DIAG == 1) || (D_IPC_FEATURE_RX_DIAG == 1))
static ipcDiag_t  V_ipcDiag_s;
#endif

/* ===========================================================================
*
*   Private functions prototype
*
* ========================================================================= */
static void     IPC_f_DiagFreeSmBuffCnt_v (void);
static void     IPC_f_ClearLatencyInfo_v (void);
static void     IPC_f_PrintLatencyInfo_v (void);

/* ===========================================================================
*
*   Private functions
*
* ========================================================================= */
/*
 * Purpose: Get number of free shared memory buffer for each message ID.
 * Description: Get number of free shared memory buffer for each message ID. Collect this data every second.
 * Return Type : void
*/
static void IPC_f_DiagFreeSmBuffCnt_v (void)
{
  /* DD-ID: {13AD0CE0-7426-4803-8AB1-C716A7839BE3}*/
#if (D_NUMBER_OF_TX_MESSAGES > 0)
#if (D_IPC_FEATURE_TX_DIAG == 1)
    uint8_t  v_freeSmBuffCnt_au8[D_NUMBER_OF_TX_MESSAGES];
    uint16_t v_msgIdIdx_u16;

    /* Get number of free shared memory buffer for each message ID in an array */
    IPC_F_GetFreeSmBuffCnt_v(&v_freeSmBuffCnt_au8[0]);

    /* Add above info in circular buffer */
    for(v_msgIdIdx_u16 = 0; v_msgIdIdx_u16 < D_NUMBER_OF_TX_MESSAGES; v_msgIdIdx_u16++)
    {
        IPC_F_CircularBuffAdd_v(D_CIRCULAR_BUFF_DATA_TYPE_8, D_IPC_DIAG_INFO_CAP_SIZE, 
                               (void *)V_ipcDiag_s.txDiag_as[v_msgIdIdx_u16].freeBuff_s.freeShMemBuffCnt_au8, 
                               &V_ipcDiag_s.txDiag_as[v_msgIdIdx_u16].freeBuff_s.freeBuffPtr_u8, 
                               (void *)&v_freeSmBuffCnt_au8[v_msgIdIdx_u16]);
    }
#endif
#endif
}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Initialize Diag variables.
 * Description: Initialize Diag variables.
 * Return Type : void
*/
void IPC_F_InitDiag_v (void)
{
  /* DD-ID: {6AC0BEE3-BF24-4a64-922B-0BB65BBE7BE1}*/
  /* DD-ID:{D9742B38-0F66-4156-9012-F7DDCFA5C748}*/

#if ((D_NUMBER_OF_TX_MESSAGES > 0) || (D_NUMBER_OF_RX_MESSAGES > 0))
#if ((D_IPC_FEATURE_TX_DIAG == 1) || (D_IPC_FEATURE_RX_DIAG == 1))
    uint16_t v_idx_u16;
#endif
#endif

#if (D_NUMBER_OF_TX_MESSAGES > 0)
#if (D_IPC_FEATURE_TX_DIAG == 1)
    uint8_t  v_index_u8;
#endif
#endif

    /* Initialize Tx Diag variables */
#if (D_NUMBER_OF_TX_MESSAGES > 0)
#if (D_IPC_FEATURE_TX_DIAG == 1)
    for (v_idx_u16 = 0; v_idx_u16 < D_NUMBER_OF_TX_MESSAGES; v_idx_u16++)
    {
        V_ipcDiag_s.txDiag_as[v_idx_u16].msgId_u16 = V_ipcLutAttrTx_as[v_idx_u16].msgId_u16;
        V_ipcDiag_s.txDiag_as[v_idx_u16].freeBuff_s.freeBuffPtr_u8 = 0;
        for (v_index_u8 = 0; v_index_u8 < D_IPC_DIAG_INFO_CAP_SIZE; v_index_u8++)
        {
            V_ipcDiag_s.txDiag_as[v_idx_u16].freeBuff_s.freeShMemBuffCnt_au8[v_index_u8] = 0xFF;
        }
    }
#endif
#endif

#if (D_IPC_FEATURE_RX_DIAG == 1)
    /* Initialize Rx Diag variables */
#if (D_NUMBER_OF_RX_MESSAGES > 0)
    for (v_idx_u16 = 0; v_idx_u16 < D_NUMBER_OF_RX_MESSAGES; v_idx_u16++)
    {
        V_ipcDiag_s.rxDiag_as[v_idx_u16].msgId_u16 = V_ipcLutAttrRx_as[v_idx_u16].msgId_u16;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.minLatancy_u64 = D_IPC_MAX_RX_LATENCY;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.maxLatancy_u64 = 0;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.latancyOutOfRangeCnt_u16 = 0;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.maxAvgLatency_u64 = 0;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.latencySampleCnt_u64 = 0;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.totalLatency_u64 = 0;
    }
#endif

    /* Initialize Rx Common Diag variables */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    for (v_idx_u16 = 0; v_idx_u16 < (uint16_t)(D_NUMBER_OF_CORES-LAST_CORE_INDEX_OFFSET); v_idx_u16++)
    {
        V_ipcDiag_s.rxCmn_s.maxReadPerCycle[v_idx_u16] = 0;
    }
#else
    V_ipcDiag_s.rxCmn_s.maxReadPerCycle = 0;
#endif
#endif
}


/*
 * Purpose: Update diag info in scheduled 10ms task.
 * Description: Update diag info in scheduled 10ms task.
 * Return Type : void
*/
void IPC_F_UpdateDiagInfo_v (void)
{
  /* DD-ID: {AD5EAFDA-29CF-4208-951B-A82849FF6003}*/
    static uint8_t  v_timer_u8 = 0;
    static uint16_t v_ClearLatencyTmr_u16 = 0;

    v_timer_u8++;

    /* Update diag info at every 1 sec interval */
    if(v_timer_u8 >= D_DIAG_UPDATE_FREQ)
    {
        v_timer_u8 = 0;
        
        /* Get number of free shared buff per message */
        IPC_f_DiagFreeSmBuffCnt_v();   /* PRQA S 2987 */ /* By Default Diag Feature is disabled */

        IPC_f_PrintLatencyInfo_v();
        
        if(v_ClearLatencyTmr_u16 < D_DIAG_CLEAR_LATENCY_INFO_TIME)
        {
            v_ClearLatencyTmr_u16++;   /* Increment timer */
        }
        else if(v_ClearLatencyTmr_u16 == D_DIAG_CLEAR_LATENCY_INFO_TIME)
        {
            v_ClearLatencyTmr_u16++;   /* Don't clear timer, latency info need to clear only once */
            IPC_f_ClearLatencyInfo_v();
        }
        else
        {
            /* Do nothing */
        }
    }
}


/*
 * Purpose: Clear diag latency info.
 * Description: Clear diag latency info.
 * Return Type : void
*/
static void IPC_f_ClearLatencyInfo_v(void)
{
  /* DD-ID:{9BE1C38C-1C1E-44dc-9EBB-E590DDB2D4DB}*/
#if (D_NUMBER_OF_RX_MESSAGES > 0)
#if (D_IPC_FEATURE_RX_DIAG == 1)
    uint16_t v_idx_u16 = 0;
    for (v_idx_u16 = 0; v_idx_u16 < D_NUMBER_OF_RX_MESSAGES; v_idx_u16++)
    {
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.maxLatancy_u64 = 0;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.minLatancy_u64 = D_IPC_MAX_RX_LATENCY;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.latancyOutOfRangeCnt_u16 = 0;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.maxAvgLatency_u64 = 0;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.latencySampleCnt_u64 = 0;
        V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.totalLatency_u64 = 0;
    }
#endif
#endif
}

/*
 * Purpose: Print diag latency info.
 * Description: Print diag latency info.
 * Return Type : void
*/
static void IPC_f_PrintLatencyInfo_v(void)
{
 /* DD-ID:{13091534-2C41-46ee-B31D-B31F5AE055CE}*/
#if (D_NUMBER_OF_RX_MESSAGES > 0)
#if (D_IPC_FEATURE_RX_DIAG == 1)
    uint16_t v_idx_u16 = 0;

    for (v_idx_u16 = 0; v_idx_u16 < D_NUMBER_OF_RX_MESSAGES; v_idx_u16++)
    {
        IPC_DBG_MSG_2("msgId_u16 = %d, maxLatancy_u64 = %d, latancyOutOfRangeCnt_u16 = %d\n", V_ipcDiag_s.rxDiag_as[v_idx_u16].msgId_u16, V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.maxLatancy_u64, V_ipcDiag_s.rxDiag_as[v_idx_u16].latency_s.latancyOutOfRangeCnt_u16);
    }
#endif
#endif
}

#if (D_NUMBER_OF_RX_MESSAGES > 0)
/*
 * Purpose: Validate time stamp in received message.
 * Description: Validate time stamp in received message and capture latency.
 * Return Type : void
*/
void IPC_F_ValidateTimestamp_v (const uint8_t *i_DataRcv_pu8, uint16_t i_msgIdRxIdx_u16)
{
  /* DD-ID: {6B349B03-7B4A-49c4-806F-69227D68FC90}*/
#if (D_IPC_FEATURE_RX_DIAG == 1)
    uint64_t v_rxTime_u64;
    uint64_t v_diffTime_u64 = 0;
    uint64_t v_avgLatency_u64;

    /* Get time stamp in received message data frame */
    (void)memcpy((void *)&v_rxTime_u64, &i_DataRcv_pu8[0], D_IPC_FOOTER_TIME_SIZE);

    /* Calculate duration of data transfer (Latency) */
    v_diffTime_u64 = IPC_F_GetCurrentTimeStamp_u64() - v_rxTime_u64;

    /* Is latency crossed previous min latency? -> Update new data */
    if (v_diffTime_u64 < V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.minLatancy_u64)
    {
        V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.minLatancy_u64 = v_diffTime_u64;
    }
    
    /* Is latency crossed previous max latency? -> Update new data */
    if (v_diffTime_u64 > V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.maxLatancy_u64)
    {
        V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.maxLatancy_u64 = v_diffTime_u64;
    }

    /* Is latency crossed allowed limit -> Increment error counter */
    if ((v_diffTime_u64 > (uint64_t)D_IPC_MAX_RX_LATENCY) && (V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.latancyOutOfRangeCnt_u16 < (uint16_t)D_IPC_U2_MAX))
    {
        V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.latancyOutOfRangeCnt_u16++;
    }

    /* If required Sample count captured to calculate avg latency */
    if(V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.latencySampleCnt_u64 == (uint64_t)D_IPC_LATENCY_SAMPLE_CNT)
    {
        /* Calculate avg of latancy samples */
        v_avgLatency_u64 =  V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.totalLatency_u64 / (uint64_t)D_IPC_LATENCY_SAMPLE_CNT;

        /* Is avg latency is more than previous avg max latency */
        if(v_avgLatency_u64 > V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.maxAvgLatency_u64)
        {
            V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.maxAvgLatency_u64 = v_avgLatency_u64;
        }

        V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.totalLatency_u64 = 0;
        V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.latencySampleCnt_u64 = 0;
    }

    /* Collect latency sample */
    V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.totalLatency_u64 += v_diffTime_u64;
    V_ipcDiag_s.rxDiag_as[i_msgIdRxIdx_u16].latency_s.latencySampleCnt_u64++;

#endif
}
#endif

/*
 * Purpose: Update diag info common to all message id.
 * Description: Update diag info common to all message id.
 * Return Type : void
*/
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
void IPC_F_DiagUpdateMaxReadCntr_v (uint16_t i_readCntr_u16, uint32_t i_chId_u32)
{
  /* DD-ID:{B9B600C5-0356-4729-84A3-9FACBF692AA1}*/
#if (D_IPC_FEATURE_RX_DIAG == 1)
    if(V_ipcDiag_s.rxCmn_s.maxReadPerCycle[i_chId_u32] < i_readCntr_u16)
    {
        V_ipcDiag_s.rxCmn_s.maxReadPerCycle[i_chId_u32] = i_readCntr_u16;
    }
#endif
}
#else
void IPC_F_DiagUpdateMaxReadCntr_v (uint16_t i_readCntr_u16)
{
  /* DD-ID:{2E71CC38-9B00-49f2-8B40-FB5319F22797}*/
#if (D_IPC_FEATURE_RX_DIAG == 1)
    if(V_ipcDiag_s.rxCmn_s.maxReadPerCycle < i_readCntr_u16)
    {
        V_ipcDiag_s.rxCmn_s.maxReadPerCycle = i_readCntr_u16;
    }
#endif
}
#endif

/*Need to Move this function to soc_utils.c once it is implemented on MCU1_0*/
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
uint64_t GetGlobalTimeInUsec()
{
  /* DD-ID:{3294F0A9-B548-4edd-8EA4-39F393025721}*/
    return TimerP_getTimeInUsecs();
}
#endif

/*===============================End Of File========================================================*/
