/**
 * @file ipc_diag.h
 * @brief Header file for IPC diag feature
 *
 * @details This file contains API prototype for IPC diag feature
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

#ifndef IPC_DIAG_H_
#define IPC_DIAG_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#if defined(BUILD_MCU2_0) || defined(BUILD_MPU1_0)
#include "app_log.h"
#endif


/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
#define IPC_F_GetCurrentTimeStamp_u64()  GetGlobalTimeInUsec()
#else
#define IPC_F_GetCurrentTimeStamp_u64()  appLogGetGlobalTimeInUsec()
#endif

/* ===========================================================================
*
*   Global data types
*
* ========================================================================= */
/*********** Tx diag feature structures ***********/

/* Free buff (Per message Id) */
typedef struct ipcTxDiagFreeBuff_s {
    uint8_t             freeBuffPtr_u8;           /* Next entry pointer in circular buffer freeShMemBuffCnt_au8 to log diag info */
    uint8_t             freeShMemBuffCnt_au8[D_IPC_DIAG_INFO_CAP_SIZE];  /* Number of Free shared mem buff count captured per sec (Circular buff) */  
} ipcTxDiagFreeBuff_t;

/* Tx Diag structure */
typedef struct ipcTxDiag_s {
    uint16_t            msgId_u16;           /* Message ID for which diag info captured */
    ipcTxDiagFreeBuff_t freeBuff_s;          /* Free shared memory buffer */
} ipcTxDiag_t;

/*********** Rx diag feature structures ***********/

/* Common for all Rx Msg (Independent of message id) */
typedef struct ipcRxCmnDiag_s {
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    uint16_t            maxReadPerCycle[D_NUMBER_OF_CORES-1]; /* Max number of avaiable message to read */
#else
    uint16_t            maxReadPerCycle;                      /* Max number of avaiable message to read */
#endif
} ipcRxCmnDiag_t;

/* Rx Latency structure (Per message Id) */
typedef struct ipcRxDiagLatency_s {
    uint16_t            latancyOutOfRangeCnt_u16; /* latency out of range error count */ 
    uint64_t            minLatancy_u64;           /* Minimum latency (ms) of Rx message */ 
    uint64_t            maxLatancy_u64;           /* Maximum latency (ms) of Rx message */ 
    uint64_t            maxAvgLatency_u64;        /* Maximum Avg latency (ms) of Rx message */ 
    uint64_t            latencySampleCnt_u64;     /* Sample count */ 
    uint64_t            totalLatency_u64;         /* Sum of capture samples latency */
} ipcRxDiagLatency_t;

/* Rx Diag structure */
typedef struct ipcRxDiag_s {
    uint16_t            msgId_u16;     /* Message ID for which diag info captured */
    ipcRxDiagLatency_t  latency_s;     /* latency */
} ipcRxDiag_t;

/* Top IPC diag structure */
typedef struct ipcDiag_s {
#if (D_NUMBER_OF_TX_MESSAGES > 0)
    ipcTxDiag_t         txDiag_as[D_NUMBER_OF_TX_MESSAGES];  /* Tx diag */
#endif
#if (D_NUMBER_OF_RX_MESSAGES > 0)
    ipcRxDiag_t         rxDiag_as[D_NUMBER_OF_RX_MESSAGES];  /* Rx diag */
#endif
    ipcRxCmnDiag_t      rxCmn_s;                             /* Rx common diag (independent of message id) */
} ipcDiag_t;

/* ========================================================================== */
/*                          External Dependencies                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void IPC_F_InitDiag_v (void);
void IPC_F_UpdateDiagInfo_v     (void);
void IPC_F_ValidateTimestamp_v  (const uint8_t *i_DataRcv_pu8, uint16_t i_msgIdRxIdx_u16);
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
void IPC_F_DiagUpdateMaxReadCntr_v  (uint16_t i_readCntr_u16, uint32_t i_chId_u32);
#else
void IPC_F_DiagUpdateMaxReadCntr_v  (uint16_t i_readCntr_u16);
#endif


/*Need to Move this function to soc_utils.h once it is implemented on MCU1_0*/
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
uint64_t GetGlobalTimeInUsec();
#endif

 /* === End Of Header File ================================================= */
#endif  /* #define IPC_DIAG_H_ */
