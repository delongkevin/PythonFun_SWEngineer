/**
 * @file ipc_global.h
 * @brief Maintains look up table
 *
 * @details This file contains IPC global data type which will be used by software components
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


#ifndef IPC_GLOBAL_H_
#define IPC_GLOBAL_H_
 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#if defined (BUILD_MPU1_0)
#include <stdint.h>
#include <devctl.h>
#elif defined (BUILD_MCU1_0)
#include <stdint.h>
#endif

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */

/* ===========================================================================
*
*   Global data types
*
* ========================================================================= */
/* enum for error status */
typedef enum status_e
{
    NO_ERROR,

    INIT_ERR_RPMSG_ANNOUNCE,         /* At IPC Init: IPC Announce failed */
    INIT_ERR_INVALID_HANDLE,         /* At IPC Init: No handle return from RPMessage_create() */
    INIT_ERR_RPMSG_CREATE,           /* At IPC Init: Wrong end point allocated from RPMessage_create() */
    INIT_ERR_RPPARAMS_INIT,          /* At IPC Init: RPMessageParams_init() failed */
    INIT_ERR_RPMSG_INIT,             /* At IPC Init: RPMessage_init() failed */
    INIT_ERR_VIRTIO_INIT,            /* At IPC Init: Ipc_initVirtIO() failed */
    INIT_ERR_IPCINIT,                /* At IPC Init: Ipc_init() failed */
    INIT_ERR_MPSETCONFIG,            /* At IPC Init: Ipc_mpSetConfig() failed */

    TX_ERR_LUT_CONF_MSG_NOT_FOUND,   /* At Tx: MSG ID requested to send not available in LUT (either or both) */
    TX_ERR_LUT_CONF_TX_EMPTY,        /* At Tx: Lookup table for transmit is empty */
    TX_ERR_LUT_CONF_SM_BUFF_ST_NULL, /* At Tx: Address of Shared memory buff state configured as NULL */
    TX_ERR_RQST_WITH_INV_DATA_SIZE,  /* At Tx: Tx request by application with wrong data size */
    TX_ERR_RQST_WITH_INV_DATA_PTR,   /* At Tx: Tx request by application with wrong data pointer */  
    TX_ERR_NO_DST_CORE_FOUND,        /* At Tx: No destination core configured to transmit msg in Tx lookup table */    
    TX_ERR_ALL_SM_BUFF_BUSY,         /* At Tx: No Free shared mem avaiable */    
    TX_ERR_INVALID_SH_MEM_ADDR,      /* At Tx: shared mem address found as NULL to transmit data */
    TX_ERR_RPMSGSEND,                /* At Tx: RPMessage_send() failed to transmit data */

    RX_ERR_RPMSGRECV,                /* At Rx: RPMessage_recv() failed while receiving data */
    RX_ERR_LUT_CONF_SM_BUFF_ST_NULL, /* At Rx: Address of Shared memory buff state configured as NULL */
    RX_ERR_RCVD_DATA_SIZE_INVALID,   /* At Rx: Received data size is not matching with configured data size */
    RX_ERR_RCVD_DATA_LOC_INVALID,    /* At Rx: Received data loc type is invalid for large data (Neither row data, nor data pointer ) */
    RX_ERR_RCVD_DATA_TYPE_INVALID,   /* At Rx: Received data type is invalid for large data (Neither data, nor acknowledgement ) */
    RX_ERR_CRC8_MISMATCH,            /* At Rx: Calculated CRC8 and received CRC8 in IPC message not matched */ 
    RX_ERR_CRC32_MISMATCH,           /* At Rx: Calculated CRC32 and received CRC32 in IPC message not matched */   
    RX_ERR_INVALID_SH_MEM_ADDR,      /* At Rx: Shared mem address received as NULL in vRing */
    RX_ERR_LUT_CONF_NO_CALLBACK,     /* At Rx: No callback function configured for received message */
    RX_ERR_MISSED_PREV_MSG,          /* At Rx: Missed previous message to receive */
    RX_ERR_ACK_RPMSGSEND,            /* At Rx: RPMessage_send() failed to transmit Acknowledgement  */

    DIAG_ERR_TX_MSGID_CONFIG,        /* At Diag: Message id not configured in DIAG table for Tx */
    DIAG_ERR_RX_MSGID_CONFIG,        /* At Diag: Message id not configured in DIAG table for Rx */
    DIAG_ERR_TX_INVALID_PTR,         /* At Diag: NULL pointer passed as data pointer to log error for Tx */
    DIAG_ERR_RX_INVALID_PTR          /* At Diag: NULL pointer passed as data pointer to log error for Rx */
} errorStatus_t;

/* Structure for Data recv */

/* ===========================================================================
*
*   Function Prototypes
*
* ========================================================================= */
/* Function to be used by Application to send data to other Cores */
uint32_t IPC_F_WrapperSend_u32(IPCMessage_Params_t *i_IPCMsg_ps);

 /* === End Of Header File ================================================= */
 #endif /*IPC_GLOBAL_H_ */
