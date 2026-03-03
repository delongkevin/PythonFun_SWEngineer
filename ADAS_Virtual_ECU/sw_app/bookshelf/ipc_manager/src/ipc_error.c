/**
 * @file ipc_error.c
 * @brief IPC error monitoring feature
 *
 * @details This file has implementation of IPC error monitoring feature
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
#include "ipc_lookup_table_struct.h"
#include "ipc_error.h"

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


/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
/* IPC error monitor variable */
static IpcErrSts_t     V_ipcErrSts_s;
static void IPC_F_CollectErrmonErr_v(uint32_t i_err_u32);
#if ((D_NUMBER_OF_TX_MESSAGES > 0) || (D_NUMBER_OF_RX_MESSAGES > 0))
static void IPC_F_CircularBuffAdd_v (uint8_t i_buffDataType_u8,
                              uint8_t i_buffSize_u8,
                              void *o_circularBuff_pv,
                              uint8_t *b_nextEntry_pu8,
                              void *i_data_pv);
#endif

/* Variable for error reporting to error manager */
#if (D_IPC_FEATURE_REPORT_TO_ERRMGR == 1)
static uint32_t v_ipcReportErrType[D_IPC_REPORT_ERR_CNT] = 
{
    D_IPC_REPORT_INIT_ERR,
    D_IPC_REPORT_TX_SHMEM_BUSY,
    D_IPC_REPORT_TX_FAIL,
    D_IPC_REPORT_RX_FAIL,
    D_IPC_REPORT_RX_CRC8_MISMATCH,
    D_IPC_REPORT_RX_CRC32_MISMATCH
};

static IpcReportErr_t  ipcReportErr[D_IPC_REPORT_ERR_CNT];  /* index mapped with v_ipcReportErrType */
#if (D_NUMBER_OF_TX_MESSAGES > 0)
static uint8_t         V_ipcShMemBuffBusyCntr[D_NUMBER_OF_TX_MESSAGES];
#endif
#endif

/* ===========================================================================
*
*   Private functions prototype
*
* ========================================================================= */
#if (D_NUMBER_OF_TX_MESSAGES > 0)
static uint16_t IPC_f_GetMsgIdErrIdxTx_u16 (uint16_t i_msgId_u16);
#endif

#if (D_NUMBER_OF_RX_MESSAGES > 0)
static uint16_t IPC_f_GetMsgIdErrIdxRx_u16 (uint16_t i_msgId_u16);
#endif

/* ===========================================================================
*
*   Private functions
*
* ========================================================================= */
#if (D_NUMBER_OF_TX_MESSAGES > 0)
/*
 * Purpose: Get index of corresponding msg Id in IPC error monitor structure for Tx.
 * Description: Parse Tx error monitor structure array find index of correspoding message id.
 * Return Type : uint16_t (If Msg Id found: MsgId Index, If Msg Id not found: D_NUMBER_OF_TX_MESSAGES)
 * Requirement ID - 16671171
*/
static uint16_t IPC_f_GetMsgIdErrIdxTx_u16 (uint16_t i_msgId_u16)
{
  /* DD-ID: {4EE16D9A-E924-4d0d-A938-EEA56BD17985}*/
    uint16_t v_msgIdErrIdx_u16 = 0;

    /* Find corresponding index of message id in IPC error monitor structure */
    for (v_msgIdErrIdx_u16 = 0; v_msgIdErrIdx_u16 < D_NUMBER_OF_TX_MESSAGES; v_msgIdErrIdx_u16++)
    {
        if(i_msgId_u16 == V_ipcErrSts_s.txErrSts_as[v_msgIdErrIdx_u16].msgId_u16)
        {
            /* MsgId found */
            break;
        }
    }
    return v_msgIdErrIdx_u16;
}
#endif

#if (D_NUMBER_OF_RX_MESSAGES > 0)
/*
 * Purpose: Get index of corresponding msg Id in IPC error monitor structure for Rx.
 * Description: Parse Rx error monitor structure array find index of correspoding message id.
 * Return Type : uint16_t (If Msg Id found: MsgId Index, If Msg Id not found: D_NUMBER_OF_RX_MESSAGES)
 * Requirement ID - 16671171
*/
static uint16_t IPC_f_GetMsgIdErrIdxRx_u16 (uint16_t i_msgId_u16)
{
  /* DD-ID: {6F772DAD-9FA5-46b4-9FA3-A906DE843126}*/
    uint16_t v_msgIdErrIdx_u16 = 0;

    /* Find corresponding index of message id in IPC error monitor structure */
    for (v_msgIdErrIdx_u16 = 0; v_msgIdErrIdx_u16 < D_NUMBER_OF_RX_MESSAGES; v_msgIdErrIdx_u16++)
    {
        if(i_msgId_u16 == V_ipcErrSts_s.rxErrSts_as[v_msgIdErrIdx_u16].msgId_u16)
        {
            /* MsgId found */
            break;
        }
    }

    return v_msgIdErrIdx_u16;
}
#endif

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Initialize error monitor related variables.
 * Description: Initialize error monitor related variables.
 * Return Type : void
*/
void IPC_F_InitErrormon_v (void)
{
  /* DD-ID: {07143996-7965-4f37-9728-DB935880C0AA}*/
#if ((D_NUMBER_OF_TX_MESSAGES > 0) || (D_NUMBER_OF_RX_MESSAGES > 0))
    uint16_t v_idx_u16;
    uint8_t  v_index_u8;
#endif

    /* Initialize error monitor variables for Init */
    V_ipcErrSts_s.initErrSts_s.isInitErr_u8 = 0;
    V_ipcErrSts_s.initErrSts_s.initErrIds_u32 = 0;

    /* Initialize error monitor variables for Common */
    V_ipcErrSts_s.cmnErrSts_s.isCmnErr_u8 = 0;
    V_ipcErrSts_s.cmnErrSts_s.cmnErrIds_u32 = 0;

#if (D_NUMBER_OF_TX_MESSAGES > 0)    
    /* Initialize error monitor variables for Tx */
    for (v_idx_u16 = 0; v_idx_u16 < D_NUMBER_OF_TX_MESSAGES; v_idx_u16++)
    {
        V_ipcErrSts_s.txErrSts_as[v_idx_u16].msgId_u16 = V_ipcLutAttrTx_as[v_idx_u16].msgId_u16;
        V_ipcErrSts_s.txErrSts_as[v_idx_u16].isTxErr_u8 = 0;
        V_ipcErrSts_s.txErrSts_as[v_idx_u16].txErrIds_u32 = 0;
        V_ipcErrSts_s.txErrSts_as[v_idx_u16].txDynErrInfo_s.NoFreeBuffCnt_u16 = 0;
        V_ipcErrSts_s.txErrSts_as[v_idx_u16].txDynErrInfo_s.txFailCnt_u16 = 0;
        V_ipcErrSts_s.txErrSts_as[v_idx_u16].txDynErrInfo_s.ackNotRcvdCnt_u16 = 0;
        V_ipcErrSts_s.txErrSts_as[v_idx_u16].txDynErrInfo_s.ackNotRcvdBuffPtr_u8 = 0;
        for (v_index_u8 = 0; v_index_u8 < D_IPC_ERRMON_CAP_SIZE; v_index_u8++)
        {
            V_ipcErrSts_s.txErrSts_as[v_idx_u16].txDynErrInfo_s.ackNotRcvdFromDst_au16[v_index_u8] = 0;
        }
    }
#endif

#if (D_NUMBER_OF_RX_MESSAGES > 0)
    /* Initialize error monitor variables for Rx */
    for (v_idx_u16 = 0; v_idx_u16 < D_NUMBER_OF_RX_MESSAGES; v_idx_u16++)
    {
        V_ipcErrSts_s.rxErrSts_as[v_idx_u16].msgId_u16 = V_ipcLutAttrRx_as[v_idx_u16].msgId_u16;
        V_ipcErrSts_s.rxErrSts_as[v_idx_u16].isRxErr_u8 = 0;
        V_ipcErrSts_s.rxErrSts_as[v_idx_u16].rxErrIds_u32 = 0;        
        V_ipcErrSts_s.rxErrSts_as[v_idx_u16].rxDynErrInfo_s.crc8MismatchCnt_u16 = 0;
        V_ipcErrSts_s.rxErrSts_as[v_idx_u16].rxDynErrInfo_s.crc32MismatchCnt_u16 = 0;
        V_ipcErrSts_s.rxErrSts_as[v_idx_u16].rxDynErrInfo_s.missedMsgCnt_u16 = 0;
        V_ipcErrSts_s.rxErrSts_as[v_idx_u16].rxDynErrInfo_s.missedMsgBuffPtr_u8 = 0;
        for (v_index_u8 = 0; v_index_u8 < D_IPC_ERRMON_CAP_SIZE; v_index_u8++)
        {
            V_ipcErrSts_s.rxErrSts_as[v_idx_u16].rxDynErrInfo_s.missedMsgIdMsgCntr_u32[v_index_u8] = 0;
        }
    }
#endif

    /* Initialize error monitor variables for Erromon */
    V_ipcErrSts_s.errmonErrSts_s.isErrmonErr_u8 = 0;
    V_ipcErrSts_s.errmonErrSts_s.errmonErrIds_u32 = 0;


#if (D_IPC_FEATURE_REPORT_TO_ERRMGR == 1)
    /* Initialize variable associated with error reporting to error manager */
    for (v_idx_u16 = 0; v_idx_u16 < D_IPC_REPORT_ERR_CNT; v_idx_u16++)
    {
        ipcReportErr[v_idx_u16].errType = v_ipcReportErrType[v_idx_u16];
        for (v_index_u8 = 0; v_index_u8 < D_IPC_ERR_REPORT_BUFF_SIZE; v_index_u8++)
        {
            ipcReportErr[v_idx_u16].currErrInfo[v_index_u8] = 0;
            ipcReportErr[v_idx_u16].reportedErrInfo[v_index_u8] = 0;
        }
    }
#if (D_NUMBER_OF_TX_MESSAGES > 0)
    for (v_idx_u16 = 0; v_idx_u16 < D_NUMBER_OF_TX_MESSAGES; v_idx_u16++)
    {
        V_ipcShMemBuffBusyCntr[v_idx_u16] = 0;
    }
#endif
#endif
}

/*
 * Purpose: Collect IPC init error.
 * Description: Collect IPC init error.
 * Return Type : void
 * Requirement ID - 16671171
*/
void IPC_F_CollectInitErr_v(uint32_t i_err_u32)
{
  /* DD-ID: {CA6CA441-A6E4-4a12-87DE-6A879445D348}*/
    if (i_err_u32 < (BIT_SHIFT_ONE_BIT << D_IPC_INIT_ERR_CNT))
    {
        /* Init error occured -> set corresponding flag */
        V_ipcErrSts_s.initErrSts_s.isInitErr_u8 = 1;

        /* ORed Init error info */
        V_ipcErrSts_s.initErrSts_s.initErrIds_u32 |= i_err_u32;
    }
}

/*
 * Purpose: Collect IPC common error (independent of message id).
 * Description: Collect IPC common error (independent of message id).
 * Return Type : void
 * Requirement ID - 16671171
*/
void IPC_F_CollectCmnErr_v(uint32_t i_err_u32)
{
  /* DD-ID: {5D80F95A-7315-47ce-82ED-3C0C8AC579E5}*/
    if (i_err_u32 < (BIT_SHIFT_ONE_BIT << D_IPC_CMN_ERR_CNT))
    {
        /* Common error occured -> set corresponding flag */
        V_ipcErrSts_s.cmnErrSts_s.isCmnErr_u8 = 1;

        /* ORed Common error info */
        V_ipcErrSts_s.cmnErrSts_s.cmnErrIds_u32 |= i_err_u32;
    }
}

/*
 * Purpose: Collect run time IPC error for Tx.
 * Description: Collect run time IPC error for Tx.
 * Return Type : void
 * Requirement ID - 16671171
*/
void IPC_F_CollectTxErr_v(uint32_t i_err_u32, uint16_t i_msgId_u16, void *i_errVal_pv)
{
  /* DD-ID: {BE292956-C6C4-4daf-B9E5-E8AA94EADB3F}*/
    uint16_t                v_msgIdIdx_u16;
    IpcTxDynErrSts_t        *v_txDynErr_sp;
        
    if (i_err_u32 < (BIT_SHIFT_ONE_BIT << D_IPC_TX_ERR_CNT))
    {
        /* Get corresponding index of message id in IPC Tx error structure array */
        v_msgIdIdx_u16 = IPC_f_GetMsgIdErrIdxTx_u16 (i_msgId_u16);

        /* If MsgId found in IPC error structure array */
        if(v_msgIdIdx_u16 < D_NUMBER_OF_TX_MESSAGES)
        {
            /* Tx error occured -> set corresponding flag */
            V_ipcErrSts_s.txErrSts_as[v_msgIdIdx_u16].isTxErr_u8 = 1;
            
            /* ORed Tx error info */
            V_ipcErrSts_s.txErrSts_as[v_msgIdIdx_u16].txErrIds_u32 |= i_err_u32;
            
            /* Get address of TX dynamic array info */
            v_txDynErr_sp = &V_ipcErrSts_s.txErrSts_as[v_msgIdIdx_u16].txDynErrInfo_s;

            /* Process Tx dynamic error info */
            switch (i_err_u32)
            {
                case D_IPC_TX_ERR_ALL_SM_BUFF_BUSY:
                {
                    /* No free SM buffer during Tx data -> Increment counter */
                    if (v_txDynErr_sp->NoFreeBuffCnt_u16 < D_IPC_U2_MAX) /* Roll over not allowed */
                    {
                        v_txDynErr_sp->NoFreeBuffCnt_u16++;
                    }
                    break;
                }
                case D_IPC_TX_ERR_RPMSGSEND:
                {
                    /* Tx Failed -> Increment counter */
                    if (v_txDynErr_sp->txFailCnt_u16 < D_IPC_U2_MAX) /* Roll over not allowed */
                    {
                        v_txDynErr_sp->txFailCnt_u16++;
                    }
                    break;
                }
                case D_IPC_TX_ERR_ACK_NOT_RCVD:
                {
                    /* Ack not received */
                    
                    /* Increment counter */
                    if (v_txDynErr_sp->ackNotRcvdCnt_u16 < D_IPC_U2_MAX) /* Roll over not allowed */
                    {
                        v_txDynErr_sp->ackNotRcvdCnt_u16++;
                    }
                    
                    /* Add dst core from which ack not received in circular buffer */
                    if(i_errVal_pv != NULL)
                    {
                        IPC_F_CircularBuffAdd_v(D_CIRCULAR_BUFF_DATA_TYPE_16, D_IPC_ERRMON_CAP_SIZE, 
                                               (void *)v_txDynErr_sp->ackNotRcvdFromDst_au16, 
                                               &v_txDynErr_sp->ackNotRcvdBuffPtr_u8, i_errVal_pv);
                    }
                    else
                    {
                        D_IPC_COLLECT_ERRMON_ERR(D_IPC_ERRMON_ERR_TX_INVALID_PTR);
                    }
                    break;
                }
                default:
                	/* Do Nothing */
                {
                    break;
                }
            }
        }
        else
        {
            D_IPC_COLLECT_ERRMON_ERR(D_IPC_ERRMON_ERR_TX_MSGID_CONFIG);
        }
    } 
}

/*
 * Purpose: Collect run time IPC error for Rx.
 * Description: Collect run time IPC error for Rx.
 * Return Type : void
 * Requirement ID - 16671171
*/
void IPC_F_CollectRxErr_v(uint32_t i_err_u32, uint16_t i_msgId_u16, void *i_errVal_pv)
{
  /* DD-ID: {E4CE7BD8-F2DB-4767-874F-4188655F0F1C}*/
    uint16_t                v_msgIdIdx_u16;
    uint16_t                v_Idx_u16;
    uint32_t                v_msdCnt_u32;
    uint32_t                v_msdCntr_u32;
    IpcRxDynErrSts_t        *v_rxDynErr_sp;
    ipcRxErrMonMissedMsg_t  *v_msdMsgInfo_ps; 
        
    if (i_err_u32 < (BIT_SHIFT_ONE_BIT << D_IPC_RX_ERR_CNT))
    {
        /* Get corresponding index of message id in IPC Rx error structure array */
        v_msgIdIdx_u16 = IPC_f_GetMsgIdErrIdxRx_u16 (i_msgId_u16);

        /* If MsgId found in IPC error structure array */
        if(v_msgIdIdx_u16 < D_NUMBER_OF_RX_MESSAGES)
        {
            /* Rx error occured -> set corresponding flag */
            V_ipcErrSts_s.rxErrSts_as[v_msgIdIdx_u16].isRxErr_u8 = 1;
            
            /* ORed Rx error info */
            V_ipcErrSts_s.rxErrSts_as[v_msgIdIdx_u16].rxErrIds_u32 |= i_err_u32;
            
            /* Get address of RX dynamic array info */
            v_rxDynErr_sp = &V_ipcErrSts_s.rxErrSts_as[v_msgIdIdx_u16].rxDynErrInfo_s;
            
            /* Process Rx dynamic error info */
            switch (i_err_u32)
            {
                case D_IPC_RX_ERR_CRC8_MISMATCH:
                {
                    /* Note: There is chances of wrong Message ID, because message id extracted before CRC8 validation */
                    
                    /* CRC8 mismatch in Rx data -> Increment counter */
                    if (v_rxDynErr_sp->crc8MismatchCnt_u16 < D_IPC_U2_MAX) /* Roll over not allowed */
                    {
                        v_rxDynErr_sp->crc8MismatchCnt_u16++;
                    }
                    break;
                }
                case D_IPC_RX_ERR_CRC32_MISMATCH:
                {
                    /* CRC32 mismatch in Rx data -> Increment counter */
                    if (v_rxDynErr_sp->crc32MismatchCnt_u16 < D_IPC_U2_MAX) /* Roll over not allowed */
                    {
                        v_rxDynErr_sp->crc32MismatchCnt_u16++;
                    }
                    break;
                }
                case D_IPC_RX_ERR_MISSED_PREV_MSG:
                {
                    /* Some message missed (Not received) */
                    if (i_errVal_pv != NULL)
                    {
                        v_msdMsgInfo_ps = (ipcRxErrMonMissedMsg_t *)i_errVal_pv;

                        /* Increment counter */
                        v_msdCnt_u32 =  ((uint32_t)v_rxDynErr_sp->missedMsgCnt_u16 + (uint32_t)v_msdMsgInfo_ps->msgCnt_u16);
                        if (v_msdCnt_u32 < (uint32_t)D_IPC_U2_MAX) /* Roll over not allowed */
                        {
                            v_rxDynErr_sp->missedMsgCnt_u16 =(uint16_t)v_msdCnt_u32;
                        }
                        else
                        {
                            v_rxDynErr_sp->missedMsgCnt_u16 =(uint16_t)D_IPC_U2_MAX;
                        }

                        /* Add missed message counter in circular buffer */
                        for(v_Idx_u16 = 0; v_Idx_u16 < v_msdMsgInfo_ps->msgCnt_u16; v_Idx_u16++)
                        {
                            v_msdCntr_u32 = (uint32_t)(v_msdMsgInfo_ps->startMsgCntr_u32 + v_Idx_u16);
                            
                            IPC_F_CircularBuffAdd_v(D_CIRCULAR_BUFF_DATA_TYPE_32, D_IPC_ERRMON_CAP_SIZE, 
                                                   (void *)v_rxDynErr_sp->missedMsgIdMsgCntr_u32, 
                                                   &v_rxDynErr_sp->missedMsgBuffPtr_u8, (void *)&v_msdCntr_u32);
                        }
                    }
                    else
                    {
                        D_IPC_COLLECT_ERRMON_ERR(D_IPC_ERRMON_ERR_RX_INVALID_PTR);
                    }
                    break;
                }
                default:
                	/* Do Nothing */
                {
                    break;
                }
            }
        }
        else
        {
            D_IPC_COLLECT_ERRMON_ERR(D_IPC_ERRMON_ERR_RX_MSGID_CONFIG);
        }
    }
}

/*
 * Purpose: Collect IPC error for errormon.
 * Description: Collect IPC error for errormon.
 * Return Type : void
 * Requirement ID - 16671171
*/
static void IPC_F_CollectErrmonErr_v(uint32_t i_err_u32)
{
  /* DD-ID: {1811B32F-C599-4a72-9573-E725DA59083B}*/
    if (i_err_u32 < (BIT_SHIFT_ONE_BIT << D_IPC_ERRMON_ERR_CNT))
    {
        /* Errormon error occured -> set corresponding flag */
        V_ipcErrSts_s.errmonErrSts_s.isErrmonErr_u8 = 1;

        /* ORed errormon error info */
        V_ipcErrSts_s.errmonErrSts_s.errmonErrIds_u32 |= i_err_u32;
    }
}


#if ((D_NUMBER_OF_TX_MESSAGES > 0) || (D_NUMBER_OF_RX_MESSAGES > 0))
/*
 * Purpose: Add data in circular data buffer.
 * Description: Add data in circular data buffer.
 * Return Type : void
*/
static void IPC_F_CircularBuffAdd_v(uint8_t i_buffDataType_u8, uint8_t i_buffSize_u8, void *o_circularBuff_pv, uint8_t *b_nextEntry_pu8, void *i_data_pv)
{
  /* DD-ID: {355088A3-87AB-4d3c-9651-6D885E9F3128}*/
    uint8_t   v_nextEntry_u8;

    /* Entry point in circular buffer */
    v_nextEntry_u8 = *b_nextEntry_pu8;

    /* If entry point reached end of circular buffer */
    if( v_nextEntry_u8 >= i_buffSize_u8)
    {
        /* Restart entry from index 0 */
        v_nextEntry_u8 = 0;
    }

    /* Add data based on data type */
    switch (i_buffDataType_u8)
    {
        case D_CIRCULAR_BUFF_DATA_TYPE_8:
        {
            /* Data type is uint8_t */
            ((uint8_t *)o_circularBuff_pv)[v_nextEntry_u8] = *(uint8_t *)i_data_pv;
            break;
        }
        case D_CIRCULAR_BUFF_DATA_TYPE_16:
        {
            /* Data type is uint16_t */
            ((uint16_t *)o_circularBuff_pv)[v_nextEntry_u8] = *(uint16_t *)i_data_pv;
            break;
        }
        case D_CIRCULAR_BUFF_DATA_TYPE_32:
        {
            /* Data type is uint32_t */
            ((uint32_t *)o_circularBuff_pv)[v_nextEntry_u8] = *(uint32_t *)i_data_pv;
            break;
        }
        default:
        	/* Do Nothing */
        {
            break;
        }
    }

    /* Increment data entry pointer to next entry */
    v_nextEntry_u8++;
    *b_nextEntry_pu8 = v_nextEntry_u8;
}
#endif

/*===============================End Of File========================================================*/
