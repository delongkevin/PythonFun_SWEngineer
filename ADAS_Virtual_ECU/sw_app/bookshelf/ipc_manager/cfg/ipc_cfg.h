/**
 * @file ipc_cfg.h
 * @brief configurations for ipc module
 *
 * @details This file configures IPC stack size, SCICLIENT API Timeout
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

#ifndef IPC_CFG_H_
#define IPC_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#if defined(BUILD_MPU1_0)
#include <stdint.h>
#include <sys/iofunc.h>
#include "app_mem_map.h"
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/***************   Feature Enable / Disable configuration  ***************/
#define D_IPC_FEATURE_CRC32            (0)   /* CRC32 calculate and validate in shared memory data */ 
#define D_IPC_FEATURE_TX_DIAG          (0)   /* Tx Diag enable / disable */
#define D_IPC_FEATURE_RX_DIAG          (1)   /* Tx Diag enable / disable */

#define D_IPC_FEATURE_REPORT_TO_ERRMGR   (0) 
/***************           Core bitmasks Macros            ***************/
#define CORE_BITMSK_CLR                   (0x0000U)
#define MPU1_0_BITMSK_0                   (0x0001U)
#define MCU1_0_BITMSK_1                   (0x0002U)
#define MCU2_0_BITMSK_2                   (0x0004U)
#define MCU2_1_BITMSK_3                   (0x0008U)
#define MCU3_0_BITMSK_4                   (0x0010U)
#define MCU3_1_BITMSK_5                   (0x0020U)
#define C66x_1_BITMSK_6                   (0x0040U)
#define C66x_2_BITMSK_7                   (0x0080U)
#define RESERV_BITMSK_8                   (0x0100U)
#define RESERV_BITMSK_9                   (0x0200U)

#define CORE_BIT_MASK                     (0xFFFFU)

/***************     Underlying IPC driver configuration   ***************/
#if defined (SOC_J721S2)
/* Base address of shared memory */
/* Requirement ID - 16667439 */
#define D_IPC_APP_VRING_BASE_ADDRESS   (0x9E000000)
/* Size of shared memory */
#define D_IPC_APP_VRING_BUFFER_SIZE    (0x02000000)
#endif /* SOC_J721E */

/* VRing timeout count to wait for re transmit */
#define D_IPC_VRING_TIMEOUT            (100)

/* VRing Buff count */
#define D_IPC_VRING_BUFF_CNT           (256U)

/* RP Message Object Size */
/* Requirement ID - 16667424 */
#define D_IPC_APP_RPMSG_OBJ_SIZE       (256U)

#define D_IPC_RPMESSAGE_MSG_BUFFER_SIZE  (496U + 32U)

/* Message to stored received messages. 256 messages of 516 bytes +
        space for book-keeping */
#define D_IPC_APP_RPMSG_DATA_SIZE      ((256U * D_IPC_RPMESSAGE_MSG_BUFFER_SIZE) + D_IPC_APP_RPMSG_OBJ_SIZE)
/* Space required for VirtIO Queue objects, container to hold received
        message pointer */
#define D_IPC_APP_VQ_BUF_SIZE          (2048U)

/* Total number of controller cores */
#define D_NUMBER_OF_CORES              (10U)
#define LAST_CORE_INDEX_OFFSET         (1U)

/***************        IPC Data frame configuration       ***************/
/* 
====================================================================================================================================
|                                                                 495 Byte                                                         |
====================================================================================================================================
|                                   Header                                   |       Data       |              Footer              |
====================================================================================================================================
|   2 Byte   |  1 Byte  |     1 Byte     |   4 Byte   |   2 Byte  |  2 Byte  | Up to 471 Byte   | 1 Byte |   3 Byte   |   8 Byte   |
====================================================================================================================================
| IPC MSG ID | Reserved |  Data Location | Msg Id Cnt | Data Size | Reserved | Data /           |  CRC8  |  Reserved  | Time Stamp |
|            |          | (0 -> Raw data |            |           |          | (Data ptr + Info)|        |            |            |
|            |          |  1 -> Data ptr)|            |           |          |                  |        |            |            |
====================================================================================================================================
*/

#define D_IPC_MAX_MSG_SIZE             (495U)

#define D_IPC_MSG_ID_IDX               (0U)
#define D_IPC_MSG_ID_SIZE              (2U)
#define D_IPC_HEADER_RESV_1_IDX        (2U)
#define D_IPC_HEADER_RESV_1_SIZE       (1U)
#define D_IPC_DATA_LOC_IDX             (3U)
#define D_IPC_MSG_ID_CNT_IDX           (4U)
#define D_IPC_MSG_ID_CNT_SIZE          (4U)
#define D_IPC_DATA_SIZE_IDX            (8U)
#define D_IPC_DATA_SIZE_SIZE           (2U)
#define D_IPC_HEADER_RESV_2_IDX        (10U)
#define D_IPC_HEADER_RESV_2_SIZE       (2U)
#define D_IPC_DATA_HEADER_SIZE         (12U)
#define D_IPC_DATA_IDX                 (12U)
#define D_IPC_FOOTER_CRC8_OFFSET       (0U)
#define D_IPC_FOOTER_RESV_1_OFFSET     (1U)
#define D_IPC_FOOTER_RESV_1_SIZE       (3U)
#define D_IPC_FOOTER_TIME_OFFSET       (4U)
#define D_IPC_FOOTER_TIME_SIZE         (8U)
#define D_IPC_DATA_FOOTER_SIZE         (12U)
#define D_IPC_MAX_DATA_PAYLOAD_SIZE    (D_IPC_MAX_MSG_SIZE - D_IPC_DATA_HEADER_SIZE - D_IPC_DATA_FOOTER_SIZE)

/* Data Pointer and info 

=========================================================================================
|                               Data Pointer and info (12 Byte)                         |
=========================================================================================
|      4 Byte     |    2 Byte    |     2 Byte     |    1 Byte    |   1 Byte  |  2 Byte  |
=========================================================================================
|  Shared Memory  | Remote Core  |   SM Data Pkt  |  Shared mem  | Sent Data | Reserved |
|     Address     |   Bitmask    |     Number     |  buff index  |   type    |          |
=========================================================================================
*/

#define D_IPC_DATA_PTR_IDX                 (12U)
#define D_IPC_SM_BUFF_DST_CORE_BITMASK_IDX (16U)
#define D_IPC_SM_DATA_PKT_NUMBER_IDX       (18U)
#define D_IPC_SM_BUFF_IDX                  (20U)
#define D_IPC_SENT_DATA_TYPE_IDX           (21U)
#define D_IPC_DATA_RESERVED_IDX            (22U)
#define D_IPC_DATA_RESERVED_SIZE           (2U)
#define D_IPC_DATA_PTR_INFO_SIZE           (12U)
#define D_IPC_LARGE_DATA_FOOTER_IDX        (24U)

/* Data Location type */
#define D_IPC_DATA_LOC_DATA_RAW            (0U) /* Row Data (<464 byte) */
#define D_IPC_DATA_LOC_DATA_PTR            (1U) /* Data Ptr (>464 byte) */

/* Sent data type */
#define D_IPC_SENT_DATA_TYPE_DATA          (0U) /* Data*/
#define D_IPC_SENT_DATA_TYPE_ACK           (1U) /* Ack*/

/* 
========================================
|              10240 Byte              |
========================================
|    Upto 10236 Byte    |    4 Byte    |
========================================
|     Data Payload      |    CRC32     |
========================================
*/
#define D_CRC32_SIZE                     (4U)

/***************           IPC Task configuration          ***************/
/* Stack required for the stack */
#define D_IPC_APP_TASK_STACK              (0x8000U)

/* Core Endpoints */
#define D_IPC_APP_LOCAL_EP_MPU1_0      (11U)
/**< End point to communicate with */
#define D_IPC_APP_LOCAL_EP_MCU1_0      (12U)
/**< End point to communicate with */
#define D_IPC_APP_LOCAL_EP_MCU2_0      (13U)
/**< End point to communicate with */
#define D_IPC_APP_LOCAL_EP_MCU2_1      (14U)
/**< End point to communicate with */
#define D_IPC_APP_LOCAL_EP_MCU3_0      (15U)
/**< End point to communicate with */
#define D_IPC_APP_LOCAL_EP_MCU3_1      (16U)
/**< End point to communicate with */
#define D_IPC_APP_LOCAL_EP_C7X_1       (17U)

/***************  Shared Memory Configuration  ***************/
/* Note 1: Change shared memory configuration in linker file */
/* Note 2: No need to check boundary condition as linker will report error if shared mem usages is more than allocated size */
/* Shared Memory configuration */
/* Core     Start Addr    Size      End Addr
 * mcu1_0   0xB6C00000  0x00080000  0xB6C7FFFF
 * mcu2_0   0xB6C80000  0x00080000  0xB6CFFFFF
 * mcu2_1   0xB6D00000  0x00080000  0xB6D7FFFF
 * mpu      0xB6D80000  0x00080000  0xB6DFFFFF
 * C7x      0xB6E00000  0x00040000  0xB6E3FFFF
 */

#if defined(BUILD_MPU1_0)
/* These are defined in app_mem_map.h*/
#define  D_IPC_SM_STORAGE_SIZE    DDR_IPC_A72_SM_STORAGE_SIZE 
#define  D_IPC_SM_PHY_ADDR        DDR_IPC_A72_SM_PHY_ADDR

typedef struct ti_ipc_ocb {
    iofunc_ocb_t ocb;
    pthread_mutex_t lock;
} res_mgr_ocb_t;

#endif

/***************  DIAG and Error monitoring configuration  ***************/
/* Capture size of Diag info buffer */
#define D_IPC_DIAG_INFO_CAP_SIZE         (200U)  /* Careful! while increasing size, U8 varaiable used to store the size*/
/* Capture size of Error info buffer */
#define D_IPC_ERRMON_CAP_SIZE            (200U)  /* Careful! while increasing size, U8 varaiable used to store the size*/
/* RX Max allowed latency time (us) */
#define D_IPC_MAX_RX_LATENCY             (20000)  /* 20ms * 1000 = 20000us */
/* Sample count for latency average */
#define D_IPC_LATENCY_SAMPLE_CNT         (1000)


/***************   Scheduled function call configuration   ***************/
#define D_IPC_SM_BUFF_PROC_FREQ       (10U)                                /* 10 ms */
#define D_IPC_LARGE_DATA_ACK_TIMEOUT  (100U / D_IPC_SM_BUFF_PROC_FREQ)     /* 100 ms / 10ms = 10 */
#define D_DIAG_UPDATE_FREQ            (1000U / D_IPC_SM_BUFF_PROC_FREQ)    /* 1000 ms / 10ms = 100 */


/***************   Scheduled function call configuration   ***************/
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
#define D_IPC_MAX_READ_PER_CYCLE       (20U)   /* Max read per cycle per core for MCU1_0 and MCU3_1 */
#else
#define D_IPC_MAX_READ_PER_CYCLE       (60U)   /* Max read per cycle for all core  */
#endif

/***************          IPC Common configuration         ***************/
#define D_IPC_U1_MAX                   (0xFFU)
#define D_IPC_U2_MAX                   (0xFFFFU)
#define D_IPC_U4_MAX                   (0xFFFFFFFFU)

#define BIT_SHIFT_ONE_BIT              (1u)

#ifdef __cplusplus
}
#endif

/* === End Of Header File ================================================= */
#endif /* #ifndef IPC_CFG_H_ */

/* @} */
