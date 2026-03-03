/**
 * @file ipc_error.h
 * @brief Monitor IPC error and report to ErrorManager
 *
 * @details This file contains IPC erro monitoring and reporting data types
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


#ifndef IPC_ERROR_H_
#define IPC_ERROR_H_
 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "ipc_lookup_table.h"
#include "ipc_cfg.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* Macro of interface to collect IPC error */
#define D_IPC_COLLECT_INIT_ERR(retVar, err)                 (retVar) = (err); \
                                                            IPC_F_CollectInitErr_v(err)

#define D_IPC_COLLECT_CMN_ERR(retVar, err)                  (retVar) = (err); \
                                                            IPC_F_CollectCmnErr_v(err)

#define D_IPC_COLLECT_TX_ERR(retVar, err, msgId, errVal)    (retVar) = (err); \
                                                            IPC_F_CollectTxErr_v(err, msgId, errVal)

#define D_IPC_COLLECT_RX_ERR(retVar, err, msgId, errVal)    (retVar) = (err); \
                                                            IPC_F_CollectRxErr_v(err, msgId, errVal)

#define D_IPC_COLLECT_ERRMON_ERR(err)                       IPC_F_CollectErrmonErr_v(err)

/* IPC Errors */
#define D_IPC_NO_ERROR                             (0x000000U)  /* No IPC error */

/* IPC Errors -> Init */
#define D_IPC_INIT_ERR_CNT                         (9U)
#define D_IPC_INIT_ERR_RPMSG_ANNOUNCE              (0x000001U)  /* IPC Init: IPC Announce failed */
#define D_IPC_INIT_ERR_MPSETCONFIG                 (0x000002U)  /* IPC Init: Ipc_mpSetConfig() failed */
#define D_IPC_INIT_ERR_IPCINIT                     (0x000004U)  /* IPC Init: Ipc_init() failed */
#define D_IPC_INIT_ERR_VIRTIO_INIT                 (0x000008U)  /* IPC Init: Ipc_initVirtIO() failed */
#define D_IPC_INIT_ERR_RPPARAMS_INIT_INIT          (0x000010U)  /* IPC Init: RPMessageParams_init() failed for RPMessage_init() */
#define D_IPC_INIT_ERR_RPMSG_INIT                  (0x000020U)  /* IPC Init: RPMessage_init() failed */
#define D_IPC_INIT_ERR_RPPARAMS_INIT_CREATE        (0x000040U)  /* IPC Init: RPMessageParams_init() failed for RPMessage_create() */
#define D_IPC_INIT_ERR_RPMSG_CREATE                (0x000080U)  /* IPC Init: Wrong end point allocated from RPMessage_create() */
#define D_IPC_INIT_ERR_INVALID_HANDLE              (0x000100U)  /* IPC Init: No handle return from RPMessage_create() */

/*IPC Errors -> Common error, independent of message id */
#define D_IPC_CMN_ERR_CNT                          (4U)
#define D_IPC_CMN_TX_ERR_LUT_CONF_TX_EMPTY         (0x000001U)  /* Tx: Lookup table for transmit is empty */
#define D_IPC_CMN_TX_ERR_LUT_CONF_MSG_NOT_FOUND    (0x000002U)  /* Tx: MSG ID requested to send not available in Tx LUT */
#define D_IPC_CMN_TX_ERR_RQST_WITH_INV_DATA_PTR    (0x000004U)  /* Tx: Tx requested by application with wrong data pointer */
#define D_IPC_CMN_RX_ERR_RPMSGRECV                 (0x000008U)  /* Rx: RPMessage_recv() failed while receiving data */

/*IPC Errors -> Tx, monitor for each message id */
#define D_IPC_TX_ERR_CNT                           (12U)
#define D_IPC_TX_ERR_LUT_CONF_INVALID_DST          (0x000001U)  /* Tx: Invalid core configured for Tx in Tx lookup table */
#define D_IPC_TX_ERR_NO_DST_CORE_FOUND             (0x000002U)  /* Tx: No destination core configured to transmit msg in Tx LUT */    
#define D_IPC_TX_ERR_RQST_WITH_INV_DATA_SIZE       (0x000004U)  /* Tx: Tx request by application with wrong data size */
#define D_IPC_TX_ERR_LUT_CONF_SM_BUFF_ST_NULL      (0x000008U)  /* Tx: Address of Shared memory buff state configured as NULL */
#define D_IPC_TX_ERR_ALL_SM_BUFF_BUSY              (0x000010U)  /* Tx: No Free shared mem available */
#define D_IPC_TX_ERR_INVALID_SH_MEM_ADDR           (0x000020U)  /* Tx: shared mem address found as NULL to transmit data */
#define D_IPC_TX_ERR_INVALID_VIR_MEM_ADDR          (0x000040U)  /* Tx: Virtual memory address of shared mem is NULL */
#define D_IPC_TX_ERR_UNMAP_VIR_MEM_ADDR            (0x000080U)  /* Tx: Unmapping of virtual memory address of shared mem is failed */
#define D_IPC_TX_ERR_RPMSGSEND                     (0x000100U)  /* Tx: RPMessage_send() failed to transmit data */
#define D_IPC_TX_ERR_ACK_INVALID_SH_MEM_ADDR       (0x000200U)  /* Tx: Addr of Sh mem buff received as NULL for received ack */
#define D_IPC_TX_ERR_LUT_CONF_RCVD_SM_BUFF_ST_NULL (0x000400U)  /* Tx: Addr of Sh mem buff state configured as NULL for received ack */
#define D_IPC_TX_ERR_ACK_NOT_RCVD                  (0x000800U)  /* Tx: Acknowledgement not received for transmitted large data */

/*IPC Errors -> Rx, monitor for each message id */
#define D_IPC_RX_ERR_CNT                           (11U)
#define D_IPC_RX_ERR_RCVD_DATA_SIZE_INVALID        (0x000001U)  /* Rx: Received data size not matching with configured data size in Rx LUT */
#define D_IPC_RX_ERR_RCVD_DATA_LOC_INVALID         (0x000002U)  /* Rx: Received data loc type is invalid (Neither row data, nor data pointer ) */
#define D_IPC_RX_ERR_RCVD_DATA_TYPE_INVALID        (0x000004U)  /* Rx: Received data type is invalid for large data (Neither data, nor acknowledgement) */
#define D_IPC_RX_ERR_CRC8_MISMATCH                 (0x000008U)  /* Rx: Calculated CRC8 and received CRC8 in IPC message not matched */
#define D_IPC_RX_ERR_CRC32_MISMATCH                (0x000010U)  /* Rx: Calculated CRC32 and received CRC32 for large data in shared memory not matched */
#define D_IPC_RX_ERR_INVALID_SH_MEM_ADDR           (0x000020U)  /* Rx: Shared mem address received as NULL in IPC message */
#define D_IPC_RX_ERR_INVALID_VIR_MEM_ADDR          (0x000040U)  /* Rx: Virtual memory address of shared mem is NULL */
#define D_IPC_RX_ERR_UNMAP_VIR_MEM_ADDR            (0x000080U)  /* Rx: Unmapping of virtual memory address of shared mem is failed */
#define D_IPC_RX_ERR_LUT_CONF_NO_CALLBACK          (0x000100U)  /* Rx: No callback function configured for received message */
#define D_IPC_RX_ERR_MISSED_PREV_MSG               (0x000200U)  /* Rx: Missed previous message to receive */
#define D_IPC_RX_ERR_ACK_RPMSGSEND                 (0x000400U)  /* Rx: RPMessage_send() failed to transmit ack for received large data */

/*IPC Errors -> While error monitoring */
#define D_IPC_ERRMON_ERR_CNT                       (4U)
#define D_IPC_ERRMON_ERR_TX_MSGID_CONFIG           (0x000001U)  /* ErrMon: Message id not found in ErrMon array for Tx */
#define D_IPC_ERRMON_ERR_RX_MSGID_CONFIG           (0x000002U)  /* ErrMon: Message id not found in ErrMon array for Rx */
#define D_IPC_ERRMON_ERR_TX_INVALID_PTR            (0x000004U)  /* ErrMon: NULL pointer passed as data pointer to log error for Tx */
#define D_IPC_ERRMON_ERR_RX_INVALID_PTR            (0x000008U)  /* ErrMon: NULL pointer passed as data pointer to log error for Rx */

/* Common for errormon and Diag feature */
/* Circular buffer data type */
#define D_CIRCULAR_BUFF_DATA_TYPE_8                (1U)
#define D_CIRCULAR_BUFF_DATA_TYPE_16               (2U)
#define D_CIRCULAR_BUFF_DATA_TYPE_32               (3U)

/* ===========================================================================
*
*   Global data types
*
* ========================================================================= */
/* Individual Error parameter structure -> Missed messages */
typedef struct ipcRxErrMonMissedMsg_s {    
    uint16_t       msgCnt_u16;               /* Missed message count */
    uint32_t       startMsgCntr_u32;         /* First missed message counter */
} ipcRxErrMonMissedMsg_t;

/* Errormon Structure for IPC init */
typedef struct IpcInitErrSts_s
{
    uint8_t           isInitErr_u8;            /* Any error occured during Init? */
    uint32_t          initErrIds_u32;          /* Bitwise error info */
}IpcInitErrSts_t;

/* Errormon Structure for IPC Tx/Rx (independent of message id) */
typedef struct IpcCmnErrSts_s
{
    uint8_t           isCmnErr_u8;             /* Any error occured during Tx/Rx (independent of message id)? */
    uint32_t          cmnErrIds_u32;           /* Bitwise error info */
}IpcCmnErrSts_t;

/* Errormon Structure for IPC Tx dynamic error for each message id */
typedef struct IpcTxDynErrSts_s
{
    uint16_t          NoFreeBuffCnt_u16;       /* Count of no free SM buff avaiable, captured during each transmission */
    uint16_t          txFailCnt_u16;           /* Count of error return from RPMessage_send() during msg transmit */
    uint16_t          ackNotRcvdCnt_u16;       /* Count of ack not received from dst core */
    uint8_t           ackNotRcvdBuffPtr_u8;    /* Next entry pointer in circular buffer ackNotRcvdFromDst_au16 to log error */
    uint16_t          ackNotRcvdFromDst_au16[D_IPC_ERRMON_CAP_SIZE]; /* Dst cores from which ack not received (Circular buff) */
}IpcTxDynErrSts_t;

/* Errormon Structure for IPC Tx */
typedef struct IpcTxErrSts_s
{
    uint16_t          msgId_u16;               /* Message id */
    uint8_t           isTxErr_u8;              /* Any error occured during Tx? */
    uint32_t          txErrIds_u32;            /* Bitwise error info */
    IpcTxDynErrSts_t  txDynErrInfo_s;          /* Tx Dynamic error */
}IpcTxErrSts_t;

/* Errormon Structure for IPC Rx dynamic error for each message id */
typedef struct IpcRxDynErrSts_s
{
    uint16_t          crc8MismatchCnt_u16;     /* Count of CRC8 mismatch in received msg */
    uint16_t          crc32MismatchCnt_u16;    /* Count of CRC32 mismatch in received msg */
    uint16_t          missedMsgCnt_u16;        /* Count of messages missed */
    uint8_t           missedMsgBuffPtr_u8;     /* Next entry pointer in circular buffer missedMsgIdMsgCntr_u32 to log error  buffer */
    uint32_t          missedMsgIdMsgCntr_u32[D_IPC_ERRMON_CAP_SIZE]; /* Missed messge counter (Circular buffer) */
}IpcRxDynErrSts_t;

/* Errormon Structure for IPC Rx */
typedef struct IpcRxErrSts_s
{
    uint16_t          msgId_u16;               /* Message id */
    uint8_t           isRxErr_u8;              /* Any error occured during Rx? */
    uint32_t          rxErrIds_u32;            /* Bitwise error info */
    IpcRxDynErrSts_t  rxDynErrInfo_s;          /* Rx Dynamic error */
}IpcRxErrSts_t;

/* Errormon Structure for IPC errormon */
typedef struct IpcErrmonErrSts_s
{
    uint8_t           isErrmonErr_u8;          /* Any error occured during errormon? */
    uint32_t          errmonErrIds_u32;        /* Bitwise error info */
}IpcErrmonErrSts_t;

/* Top Errormon Structure for IPC error */
typedef struct IpcErrSts_s
{

    IpcInitErrSts_t   initErrSts_s;                         /* Init error */
    IpcCmnErrSts_t    cmnErrSts_s;                          /* Common error */
#if (D_NUMBER_OF_TX_MESSAGES > 0)
    IpcTxErrSts_t     txErrSts_as[D_NUMBER_OF_TX_MESSAGES]; /* Tx error */
#endif
#if (D_NUMBER_OF_RX_MESSAGES > 0)
    IpcRxErrSts_t     rxErrSts_as[D_NUMBER_OF_RX_MESSAGES]; /* Rx error */
#endif
    IpcErrmonErrSts_t errmonErrSts_s;                       /* Errormon error */
}IpcErrSts_t;


/* ===========================================================================
*
*   Function Prototypes
*
* ========================================================================= */
void IPC_F_InitErrormon_v    (void);
void IPC_F_CollectInitErr_v  (uint32_t i_err_u32);
void IPC_F_CollectCmnErr_v   (uint32_t i_err_u32);
void IPC_F_CollectTxErr_v    (uint32_t i_err_u32, uint16_t i_msgId_u16, void *i_errVal_pv);
void IPC_F_CollectRxErr_v    (uint32_t i_err_u32, uint16_t i_msgId_u16, void *i_errVal_pv);

 /* === End Of Header File ================================================= */
 #endif /*IPC_ERROR_H_ */
