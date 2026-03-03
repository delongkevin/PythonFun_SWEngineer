/**
 * @file ipc_large_buff_mgr.c
 * @brief Allocates and frees buffer in shared memory for large data Inter Core Communication purposes
 *
 * @details This file provide API to get and release buffer allocated in shared memory for Inter Core Communication purposes which will be used by IPC manager
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

#if defined(BUILD_MCU2_1)  || defined(BUILD_MCU3_0)
#include <ti/osal/osal.h>

#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
#include "Os.h"

#elif defined(BUILD_MCU2_0)
#include <ti/osal/TaskP.h>
#include <ti/osal/SemaphoreP.h>
#include <ti/osal/HwiP.h>
#ifndef SOC_J721S2
#define SOC_J721S2
#endif

#include <stdio.h>
#include <string.h>
#include <utils/console_io/include/app_log.h>
#include <utils/ethfw/include/app_ethfw.h>
#include <ti/drv/ipc/ipc.h>

#elif defined(BUILD_MPU1_0)
#include <pthread.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include<stdio.h>
#include <sys/mman.h>
#endif

#include "ipc_large_buff_mgr.h"
#include "ipc_lookup_table.h"
#include "ipc_lookup_table_struct.h"
#include "ipc_cfg.h"
#include "ipc_diag.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#if defined(BUILD_MPU1_0)
#define  D_INTR_PARAM_DATA_TYPE   pthread_mutex_t
#define  D_INTR_PARAM_INIT        v_key_s = PTHREAD_MUTEX_INITIALIZER
#else
#define  D_INTR_PARAM_DATA_TYPE   uintptr_t
#define  D_INTR_PARAM_INIT        v_key_s
#endif

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */
#if defined(BUILD_MPU1_0)
/* Shared Memory 2MB (Same for all core) */
void*   v_ipcSmDataBuff_au8 = NULL;

static int32_t   shm_Fd = 0;

#if (D_NUMBER_OF_TX_MESSAGES > 0)
static uint8_t *v_mpuShmBuff_u8[ D_NUMBER_OF_TX_MESSAGES ];
#endif

#endif


/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */

/* ===========================================================================
*
*   Private functions
*
* ========================================================================= */
#if (D_NUMBER_OF_TX_MESSAGES > 0)
static void IPC_f_EnableInrerrupt_v (D_INTR_PARAM_DATA_TYPE *i_Key_ps);
static void IPC_f_DisableInrerrupt_v (D_INTR_PARAM_DATA_TYPE *i_Key_ps);
#endif

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */

/*
 * Purpose:     Get free IPC shared memory buffer to transmit large data to different core
 * Description: IPC Manager will call this function to see if any shared memory
 *              buffer is free to tranmit large data to different core
 * Return Type: uint32_t
 * Requirement ID - 13731852, 16671169
*/
uint32_t IPC_F_GetSmBuff_u32 (uint16_t i_msgIdIdx_u16, IpcSmBuff_t *i_smBuff_ps)
{
  /* DD-ID: {D5176140-BAF2-4f98-BD2D-0B4052707FEA}*/
    uint32_t v_ret_u32 = D_IPC_NO_ERROR;

#if (D_NUMBER_OF_TX_MESSAGES > 0) 
    uint8_t           *v_buffAddr_pu8;
    uint16_t          v_buffSize_u16;
    uint8_t           v_index_u8;
    uint16_t          v_pktNum_u16 = 0U;
    IpcSmBuffState_t  *v_smBuffSt_ps;

    D_INTR_PARAM_DATA_TYPE   D_INTR_PARAM_INIT;

    if (V_ipcLutAttrTx_as[i_msgIdIdx_u16].buffStateAddr_ps != NULL)
    {
        /* Disable interrupt */
        IPC_f_DisableInrerrupt_v (&v_key_s);

        /* Get address of shared memory buffer state of corresponding message id and buffer index */
        v_smBuffSt_ps = V_ipcLutAttrTx_as[i_msgIdIdx_u16].buffStateAddr_ps;

        /* Find free shared memory buffer for corresponding message id */
        for (v_index_u8 = 0; v_index_u8 < V_ipcLutAttrTx_as[i_msgIdIdx_u16].buffCnt_u8; v_index_u8++)
        {
            if (v_smBuffSt_ps[v_index_u8].buffInUse_u16 == 0U)
            {
                v_smBuffSt_ps[v_index_u8].buffInUse_u16 = V_ipcLutAttrTx_as[i_msgIdIdx_u16].dstCores_u16;
                v_smBuffSt_ps[v_index_u8].timer_u8 = 0;
                ++v_smBuffSt_ps[v_index_u8].currPktNum_u16; 
                v_pktNum_u16 = v_smBuffSt_ps[v_index_u8].currPktNum_u16; /* Allow rollover */
                break;  /* Break loop */
            }
        }

        /* Enable interrupt */
        IPC_f_EnableInrerrupt_v (&v_key_s);

        /* If Free shared mem buffer found*/
        if (v_index_u8 < V_ipcLutAttrTx_as[i_msgIdIdx_u16].buffCnt_u8)
        {
#if defined(BUILD_MPU1_0)
            v_buffAddr_pu8 = v_mpuShmBuff_u8[i_msgIdIdx_u16];
#else
            v_buffAddr_pu8 = V_ipcLutAttrTx_as[i_msgIdIdx_u16].baseAddr_pu8;
#endif
            v_buffSize_u16 = V_ipcLutAttrTx_as[i_msgIdIdx_u16].smBuffSize_u16;

            i_smBuff_ps->addr_pv = (void *)(v_buffAddr_pu8 + (v_index_u8 * v_buffSize_u16));
            i_smBuff_ps->dstCoreBitMask_u16 = 0;
            i_smBuff_ps->pktNum_u16 = v_pktNum_u16;
            i_smBuff_ps->buffIdx_u8 = v_index_u8;
            i_smBuff_ps->sendDataType = D_IPC_SENT_DATA_TYPE_DATA;
            i_smBuff_ps->reserved_u8[0] = 0;
            i_smBuff_ps->reserved_u8[1] = 0;
        }
        else  /* No free buffer avaiable */
        {
            /* No free buffer found -> Collect error */            
            D_IPC_COLLECT_TX_ERR(v_ret_u32, D_IPC_TX_ERR_ALL_SM_BUFF_BUSY, V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgId_u16, NULL);
        }
    }
    else
    {
        /* Invalid config -> Collect error */
        D_IPC_COLLECT_TX_ERR(v_ret_u32, D_IPC_TX_ERR_LUT_CONF_SM_BUFF_ST_NULL, V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgId_u16, NULL);
    }
#endif
    return v_ret_u32;
}

/*
 * Purpose: Release IPC buffer in shared memory after reception of acknowledgement from different core
 * Description: IPC Manager will call this function to release used buffer in shared memory after acknowlwdgement reception.
 * Important Note: This function must be called from same core who sends data.
 * Return Type : uint32_t
*/
uint32_t IPC_F_ReleaseSmBuff_u32 (uint16_t i_msgIdIdx_u16, IpcSmBuff_t i_SmBuff_s)
{
  /* DD-ID: {251A6FA5-1A2C-47e3-8BC6-DE4627ABF330}*/
    uint32_t v_errorStatus_u32 = D_IPC_NO_ERROR;
#if (D_NUMBER_OF_TX_MESSAGES > 0)
    uint8_t   v_buffStIdx_u8;
    IpcSmBuffState_t  *v_smBuffSt_ps;

    D_INTR_PARAM_DATA_TYPE   D_INTR_PARAM_INIT;

    /* shared memory buffer index */
    v_buffStIdx_u8 = i_SmBuff_s.buffIdx_u8;

    if (V_ipcLutAttrTx_as[i_msgIdIdx_u16].buffStateAddr_ps != NULL)
    {
        /* Disable interrupt */
        IPC_f_DisableInrerrupt_v (&v_key_s);

        /* Get address of shared memory buffer state of corresponding message id and buffer index */
        v_smBuffSt_ps = &V_ipcLutAttrTx_as[i_msgIdIdx_u16].buffStateAddr_ps[v_buffStIdx_u8];

        /* Release buffer only if
         * 1. Buffer is in use
         * 2. Received acknowledgemnt of current sent packet (confirm by packet number)
         * 3. Acknowledgement received before timeout */
        if ((v_smBuffSt_ps->buffInUse_u16 != 0U) &&
            (v_smBuffSt_ps->currPktNum_u16 == i_SmBuff_s.pktNum_u16) &&
            (v_smBuffSt_ps->timer_u8 < D_IPC_LARGE_DATA_ACK_TIMEOUT))
        {
            /* Clear buff in use bit of corresponding dst core */
            v_smBuffSt_ps->buffInUse_u16 &= (uint16_t)(~i_SmBuff_s.dstCoreBitMask_u16);

            /* If acknowledgment from all dst core received and buff in use is 0, then reset timer */
            if (v_smBuffSt_ps->buffInUse_u16 == 0U)
            {
                v_smBuffSt_ps->timer_u8 = 0;
            }
        }

        /* Enable interrupt */
        IPC_f_EnableInrerrupt_v (&v_key_s);

    }
    else
    {
        /* Invalid address -> Collect error */
        D_IPC_COLLECT_TX_ERR(v_errorStatus_u32, D_IPC_TX_ERR_LUT_CONF_RCVD_SM_BUFF_ST_NULL, V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgId_u16, NULL);
    }

#endif

    return v_errorStatus_u32;

}


/*
 * Purpose: Release shared memory buffer after timeout if acknowledgement not received
 * Description: Process IPC shared memory buff periodically and after timeout release buffer
 * Return Type : void
*/
void IPC_F_UpdateSmBuffState_v (void)
{
  /* DD-ID: {0CD2C254-9109-499c-9767-BB76D1A7CEC9}*/
#if (D_NUMBER_OF_TX_MESSAGES > 0)
    uint16_t  v_msgIdIdx_u16;
    uint8_t   v_buffIdx_u8;
    uint8_t   v_buffCnt_u8;
    IpcSmBuffState_t  *v_buffStateAddr_ps;

    D_INTR_PARAM_DATA_TYPE   D_INTR_PARAM_INIT;

    /* Check for all Message id */
    for(v_msgIdIdx_u16 = 0; v_msgIdIdx_u16 < D_NUMBER_OF_TX_MESSAGES; v_msgIdIdx_u16++)
    {
        /* Shared memory buffer count for corresponding message id */
        v_buffCnt_u8 = V_ipcLutAttrTx_as[v_msgIdIdx_u16].buffCnt_u8;

        /* Shared memory buffer address for corresponding message id (first index) */
        v_buffStateAddr_ps = V_ipcLutAttrTx_as[v_msgIdIdx_u16].buffStateAddr_ps;

        if(v_buffStateAddr_ps != NULL)
        {
            /* Check for all buffer */
            for(v_buffIdx_u8 = 0; v_buffIdx_u8 < v_buffCnt_u8; v_buffIdx_u8++)
            {
                /* Disable interrupt */
                IPC_f_DisableInrerrupt_v (&v_key_s);

                /* If buffer is in use */
                if(v_buffStateAddr_ps[v_buffIdx_u8].buffInUse_u16 != 0U)
                {
                    /* Timer expired */
                    if(v_buffStateAddr_ps[v_buffIdx_u8].timer_u8 >= D_IPC_LARGE_DATA_ACK_TIMEOUT)
                    {
                        /* Collect error */
                        IPC_F_CollectTxErr_v(D_IPC_TX_ERR_ACK_NOT_RCVD, 
                                             V_ipcLutAttrTx_as[v_msgIdIdx_u16].msgId_u16, 
                                             (void *)&v_buffStateAddr_ps[v_buffIdx_u8].buffInUse_u16);

                        /* Free buffer */
                        v_buffStateAddr_ps[v_buffIdx_u8].buffInUse_u16 = 0; /* Release buffer */
                        v_buffStateAddr_ps[v_buffIdx_u8].timer_u8 = 0;      /* Reset timer */
                    }
                    else
                    {
                        /* Increment timer */
                        v_buffStateAddr_ps[v_buffIdx_u8].timer_u8++;
                    }
                }

                /* Enable interrupt */
                IPC_f_EnableInrerrupt_v (&v_key_s);

            }
        }
    }
#endif
}

/*
 * Purpose: Get number of free shared memory buffer per message id
 * Description: Get number of free shared memory buffer per message id
 * Return Type : void
*/
void IPC_F_GetFreeSmBuffCnt_v (uint8_t *o_buffCnt_pu8)
{
  /* DD-ID: {993EA710-AB75-40bb-B4A9-EB9CDF6EA5F9}*/
#if (D_NUMBER_OF_TX_MESSAGES > 0)
#if (D_IPC_FEATURE_TX_DIAG == 1)
    uint16_t  v_msgIdIdx_u16;
    uint8_t   v_buffIdx_u8;
    uint8_t   v_buffCnt_u8;
    uint8_t   v_freeBuffCnt_u8;
    IpcSmBuffState_t  *v_buffStateAddr_ps;

    D_INTR_PARAM_DATA_TYPE   D_INTR_PARAM_INIT;

    /* Check for all Message id */
    for(v_msgIdIdx_u16 = 0; v_msgIdIdx_u16 < D_NUMBER_OF_TX_MESSAGES; v_msgIdIdx_u16++)
    {
        /* Shared memory buffer count for corresponding message id */
        v_buffCnt_u8 = V_ipcLutAttrTx_as[v_msgIdIdx_u16].buffCnt_u8;
        
        /* Shared memory buffer address for corresponding message id (first index) */
        v_buffStateAddr_ps = V_ipcLutAttrTx_as[v_msgIdIdx_u16].buffStateAddr_ps;

        /* Reset counter variable */
        v_freeBuffCnt_u8 = 0;

        if(v_buffStateAddr_ps != NULL)
        {
            /* Check for all buffer */
            for(v_buffIdx_u8 = 0; v_buffIdx_u8 < v_buffCnt_u8; v_buffIdx_u8++)
            {
                /* Disable interrupt */
                IPC_f_DisableInrerrupt_v (&v_key_s);

                /* If buffer is in use? -> No -> Increment counter */
                if(v_buffStateAddr_ps[v_buffIdx_u8].buffInUse_u16 == 0)
                {
                    v_freeBuffCnt_u8++;
                }

                /* Enable interrupt */
                IPC_f_EnableInrerrupt_v (&v_key_s);
            }

            /* Copy number of free shared memory buff array */
            o_buffCnt_pu8[v_msgIdIdx_u16] = v_freeBuffCnt_u8;
        }
    }
#endif
#endif
}

#if (D_NUMBER_OF_TX_MESSAGES > 0)
/*
 * Purpose: Enable interrupts
 * Description: Enable interrupts.
 * Return Type : void
*/
#if defined(BUILD_MPU1_0)
static void IPC_f_EnableInrerrupt_v (pthread_mutex_t *i_mutex_ps)
{
  /* DD-ID: {A0BBDF64-E3C6-4e15-90BB-7892416336FE}*/
    pthread_mutex_unlock(i_mutex_ps);
}
#else

static void IPC_f_EnableInrerrupt_v (uintptr_t *i_Key_ps)
{
  /* DD-ID: {A0BBDF64-E3C6-4e15-90BB-7892416336FE}*/
#if defined(BUILD_MCU2_0)  || defined(BUILD_MCU2_1)  || defined(BUILD_MCU3_0)
    HwiP_restore(*i_Key_ps); /* restore interrupts */

#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    ResumeAllInterrupts();

#endif
}
#endif

/*
 * Purpose: Disable interrupts
 * Description: Disable interrupts.
 * Return Type : void
*/
#if defined(BUILD_MPU1_0)
static void IPC_f_DisableInrerrupt_v (pthread_mutex_t *i_mutex_ps)
{
  /* DD-ID: {1F1B2655-4D75-478b-B505-D529C0BAAA08}*/
    pthread_mutex_lock(i_mutex_ps); /* pthread for IPC */
}
#else

static void IPC_f_DisableInrerrupt_v (uintptr_t *i_Key_ps)
{
  /* DD-ID: {1F1B2655-4D75-478b-B505-D529C0BAAA08}*/
#if defined(BUILD_MCU2_0)  || defined(BUILD_MCU2_1)  || defined(BUILD_MCU3_0)
    *i_Key_ps = HwiP_disable(); /* disable interrupts */

#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    SuspendAllInterrupts();

#endif
}
#endif
#endif

#if defined(BUILD_MPU1_0)

/*
 * Purpose: Initilaize shared memory base addr for all Tx message id.
 * Description: Initilaize shared memory base addr for all Tx message id.
 * Return Type : void
*/

void IPC_F_MpuInitShmemBaseAddr_v(void)
{
  /* DD-ID: {41F1030C-AA04-4251-B5C8-9C8CDA2E50A7}*/
#if (D_NUMBER_OF_TX_MESSAGES > 0)
    uint16_t v_idx_u16;
    uint32_t v_size_u32 = 0;		 /* Total allocated size of all previous msg id */
    for(v_idx_u16 = 0; v_idx_u16 < D_NUMBER_OF_TX_MESSAGES; v_idx_u16++)
    {
    	/* shared mem base address */
        v_mpuShmBuff_u8[v_idx_u16] = (uint8_t *) v_ipcSmDataBuff_au8 + v_size_u32;
        
        /* Total allocated size of all previous msg id */
        v_size_u32 += V_ipcLutAttrTx_as[v_idx_u16].smBuffSize_u16 * V_ipcLutAttrTx_as[v_idx_u16].buffCnt_u8;
    }
#endif
}
/*
 * Purpose: init shared memory
 * Description: init shared memory.
 * Return Type : status
*/
int8_t init_Shmem()
{
  /* DD-ID: {0E4615F5-25D0-4df3-B3EA-0E74B6FA2BB1}*/
    int8_t ret = 0;
    int32_t v_Result_s32 = 0;

    shm_Fd = shm_open((char*)"icc_data_buffer" , ( O_RDWR | O_TRUNC | O_CREAT ), 0400);
    if (shm_Fd == -1)
    {
        ret = -1;
    }
    else
    {
        v_Result_s32 = ftruncate(shm_Fd, (off_t)D_IPC_SM_STORAGE_SIZE);

        if(v_Result_s32 !=0)
        {
            ret = -2;
        }
        else
        {
            v_ipcSmDataBuff_au8 =  mmap((void*)D_IPC_SM_PHY_ADDR,  D_IPC_SM_STORAGE_SIZE , (PROT_NOCACHE | PROT_READ | PROT_WRITE), MAP_SHARED, shm_Fd , 0);
            
            if ( v_ipcSmDataBuff_au8 == MAP_FAILED)
            {
                ret = -3;
            }
            else
            {
                IPC_F_MpuInitShmemBaseAddr_v();
            }
        }
    }

    return ret;
}
/*
 * Purpose: deinit shared memory
 * Description: deinit shared memory.
 * Return Type : status
*/

int8_t deinit_Shmem()
{
  /* DD-ID: {A5C975E1-15BB-45f4-B6E1-CBF36B2B852B}*/
    int8_t ret = 0;

    ret = munmap((void*)D_IPC_SM_PHY_ADDR, D_IPC_SM_STORAGE_SIZE);
    if(ret == 0U)
    {
    }
    else
    {
        ret = shm_unlink((char*)"icc_data_buffer");
        if(ret == 0U)
        {
        }
        else
        {
        }
    }
    close(shm_Fd);
    return ret;
}
#endif

/*===============================End Of File========================================================*/
