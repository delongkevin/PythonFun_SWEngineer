/**
 * @file ipc_manager.c
 * @brief Interface between software applications and IPC driver
 *
 * @details This file provides APIs to transfer data between Software applications and IPC driver of one Core to Other Core
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
#if defined (BUILD_MPU1_0)
#include <pthread.h>
#include <sys/mman.h>
typedef unsigned long  long_t;
#endif

#include <stdio.h>
#include <stdint.h>
#include <string.h>
   
#ifndef SOC_J721S2
#define SOC_J721S2
#endif

#include <ti/drv/ipc/soc/V3/ipc_soc.h>
#include <ti/drv/ipc/ipc.h>

#include "ipc_manager.h"
#if defined(BUILD_MCU1_0)
#include "Cdd_Ipc.h"
#endif

#include "ipc_crc.h"
#include "ipc_diag.h"

#if defined (BUILD_MCU1_0)
#include <ti/osal/CacheP.h>
#include <ti/osal/src/nonos/Nonos_config.h>
#include <ti/csl/soc.h>
#include <ti/csl/arch/csl_arch.h>
#endif

#if defined (BUILD_MCU2_0)
#include <utils/console_io/include/app_log.h>
#endif

#if defined (BUILD_MCU2_1)
#include <UART_stdio.h>
#endif

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* Enable this macro for ipc debug prints on UART*/
//#define IPC_VERIFY
/* ===========================================================================

*   Global variables
*
* ========================================================================= */


/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
#else

#ifndef BUILD_MCU2_0
/* Stack for the task */
static uint8_t s_Ipc_RpMsgCtrlTaskStack_au8[D_IPC_APP_TASK_STACK]            __attribute__((aligned(D_IPC_APP_TASK_STACK)));

/* Local VirtIoQueue Object */
static uint8_t  s_Ipc_SysVqBuf_au8[D_IPC_APP_VQ_BUF_SIZE]                    __attribute__((aligned(128U)));

/* Buffer to store all messages received on this core, from all cores */
static uint8_t  s_Ipc_CtrlTaskMsgBuf_au8[D_IPC_APP_TASK_STACK]               __attribute__((aligned(128U)));
#endif
/* Buffer to hold, received messages from Remote Core */
static uint8_t s_IpcRpMsgRxBuf_au8[D_IPC_APP_RPMSG_DATA_SIZE]               __attribute__((aligned(8u)));

/* Handle for send communication channel */
static RPMessage_Handle s_IpcCommChHndl_s;
#endif

/* Processor ID's and end points */
#ifdef BUILD_MCU1_0
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_MCU1_0;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
    IPC_MPU1_0, IPC_MCU1_1, IPC_MCU2_0, IPC_MCU2_1, IPC_MCU3_0, IPC_MCU3_1   , IPC_C7X_1
};

/* Local End point to be used -> Unused for MCU1_0 */
//static uint32_t s_IpcLocalEp_u32 = D_IPC_APP_LOCAL_EP_MCU1_0;
#endif

#ifdef BUILD_MPU1_0
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_MPU1_0;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
    IPC_MCU1_0, IPC_MCU1_1, IPC_MCU2_0, IPC_MCU2_1, IPC_MCU3_0, IPC_MCU3_1  , IPC_C7X_1, IPC_C7X_2
};

/* Local End point to be used */
static uint32_t s_IpcLocalEp_u32 = D_IPC_APP_LOCAL_EP_MPU1_0;
#endif

#ifdef BUILD_MCU1_1
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_MCU1_1;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
    IPC_MPU1_0, IPC_MCU1_0, IPC_MCU2_0, IPC_MCU2_1, IPC_MCU3_0, IPC_MCU3_1  , IPC_C7X_1
};
#endif

#ifdef BUILD_MCU2_0
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_MCU2_0;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
    IPC_MPU1_0, IPC_MCU1_0, IPC_MCU1_1, IPC_MCU2_1, IPC_MCU3_0, IPC_MCU3_1  , IPC_C7X_1
};

/* Local End point to be used */
static uint32_t s_IpcLocalEp_u32 = D_IPC_APP_LOCAL_EP_MCU2_0;
#endif

#ifdef BUILD_MCU2_1
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_MCU2_1;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
    IPC_MPU1_0, IPC_MCU1_0, IPC_MCU1_1, IPC_MCU2_0, IPC_MCU3_0, IPC_MCU3_1   , IPC_C7X_1
};

/* Local End point to be used */
static uint32_t s_IpcLocalEp_u32 = D_IPC_APP_LOCAL_EP_MCU2_1;
#endif

#ifdef BUILD_MCU3_0
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_MCU3_0;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
    IPC_MPU1_0, IPC_MCU1_0, IPC_MCU1_1, IPC_MCU2_0, IPC_MCU2_1, IPC_MCU3_1  , IPC_C7X_1
};

/* Local End point to be used */
static uint32_t s_IpcLocalEp_u32 = D_IPC_APP_LOCAL_EP_MCU3_0;
#endif

#ifdef BUILD_MCU3_1
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_MCU3_1;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
    IPC_MPU1_0, IPC_MCU1_0, IPC_MCU1_1, IPC_MCU2_0, IPC_MCU2_1, IPC_MCU3_0  , IPC_C7X_1
};

/* Local End point to be used -> Unused for MCU3_1 */
//static uint32_t s_IpcLocalEp_u32 = D_IPC_APP_LOCAL_EP_MCU3_1;
#endif

#ifdef BUILD_C66X_1
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_C66X_1;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
#ifndef NO_R5FS
    IPC_MPU1_0, IPC_MCU1_0, IPC_MCU1_1, IPC_MCU2_0, IPC_MCU2_1, IPC_MCU3_0, IPC_MCU3_1  , IPC_C7X_1
#else
    IPC_MPU1_0  , IPC_C7X_1
#endif
};
#endif

#ifdef BUILD_C66X_2
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_C66X_2;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
    IPC_MPU1_0, IPC_MCU1_0, IPC_MCU1_1, IPC_MCU2_0, IPC_MCU2_1, IPC_MCU3_0, IPC_MCU3_1, IPC_C7X_1
};
#endif

#ifdef BUILD_C7X_1
/* Own processor ID */
uint32_t V_IpcSelfProcId_u32 = IPC_C7X_1;

/* Valid Remote processor ID */
uint32_t V_IpcRemoteProc_u32[] =
{
    IPC_MPU1_0, IPC_MCU1_0, IPC_MCU1_1, IPC_MCU2_0, IPC_MCU2_1, IPC_MCU3_0, IPC_MCU3_1   
};
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
/* These should match what is given in linker command file */
/** \brief Length of the section used to check section corruption */
#define APP_UTILS_LINKER_FILL_LENGTH    (0x100U)
/** \brief Pattern written in each sections */
#define APP_UTILS_LINKER_FILL_PATTERN   (0xFEAA55EFU)
/** \brief Sizeof Utility macro */
#define MODULEAPP_NUM_SEC_HOLES(x)     (sizeof (x) / sizeof (x[0]))
/**< Sections defined in linker command file for IPC module */
extern uint32 __linker_cdd_ipc_text_start, __linker_cdd_ipc_text_end,
              __linker_cdd_ipc_const_start, __linker_cdd_ipc_const_end,
              __linker_cdd_ipc_init_start, __linker_cdd_ipc_init_end,
              __linker_cdd_ipc_no_init_start, __linker_cdd_ipc_no_init_end,
              __linker_cdd_ipc_no_init_align_8b_start,
              __linker_cdd_ipc_no_init_align_8b_end;
/**< Address list of sections defined in linker command file for IPC module */
static uint32 CddIpcApp_SecHoleAddrList[] =
{
    ((uint32) & __linker_cdd_ipc_text_start),
    ((uint32) & __linker_cdd_ipc_text_end) - APP_UTILS_LINKER_FILL_LENGTH,
    ((uint32) & __linker_cdd_ipc_const_start),
    ((uint32) & __linker_cdd_ipc_const_end) - APP_UTILS_LINKER_FILL_LENGTH,
    ((uint32) & __linker_cdd_ipc_init_start),
    ((uint32) & __linker_cdd_ipc_init_end) - APP_UTILS_LINKER_FILL_LENGTH,
    ((uint32) & __linker_cdd_ipc_no_init_start),
    ((uint32) & __linker_cdd_ipc_no_init_end) - APP_UTILS_LINKER_FILL_LENGTH,
    ((uint32) & __linker_cdd_ipc_no_init_align_8b_start),
    ((uint32) & __linker_cdd_ipc_no_init_align_8b_end) -
                                                APP_UTILS_LINKER_FILL_LENGTH,
};
#endif

/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */

/* ===========================================================================
*
* Private variables
*
* ========================================================================= */

/* ===========================================================================
*
*   Private functions
*
* ========================================================================= */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
static void AppUtils_CddIpcSectionInit(void);
#endif

#if ((D_NUMBER_OF_TX_MESSAGES > 0) || (D_NUMBER_OF_RX_MESSAGES > 0))
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
#else
static int32_t      IPC_f_SendData_s32              (uint32_t i_RemoteProc_u32,
                                                     uint32_t i_RemoteEp_u32,
                                                     uint8_t  *i_dataRcv_pu8,
                                                     uint16_t i_RcvDataBuffSize_u16);
#endif
#endif

#if (D_NUMBER_OF_TX_MESSAGES > 0)
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
static uint32_t IPC_f_SelectDestCoreCddChanId_u32   (uint16_t i_msgIdIdx_u16, 
                                                     uint32_t *o_destCoreChanId_pu32, 
                                                     uint16_t *o_remoteCoreBitMask_u16, 
                                                     uint16_t *o_num_core_ids_pu16);

#else
static uint32_t IPC_f_SelectDestCore_u32            (uint16_t i_msgIdIdx_u16,
                                                     uint32_t *o_destProcId_pu32, 
                                                     uint32_t *o_destEndPt_pu32,
                                                     uint16_t *o_remoteCoreBitMask_u16,
                                                     uint16_t *o_num_core_ids_pu16 );

#endif

static void          IPC_f_PrepHeader_v             (uint16_t            i_msgIdIdx_u16, 
                                                     uint8_t             *o_data_pu8, 
                                                     IPCMessage_Params_t *i_IPCMsg_ps);

static void          IPC_f_PrepSmallDataAndFooter_v (uint8_t             *o_Data_pu8, 
                                                     const IPCMessage_Params_t *i_IPCMsg_ps, 
                                                     uint16_t            *o_DataFrameSize_u16);

static uint32_t      IPC_f_PrepLargeDataAndFooter_u32(uint8_t       *o_Data_pu8,
                                                     uint16_t      i_dstCoreBitMask_u16,
                                                     IpcSmBuff_t   *i_smBuff_ps,
                                                     uint16_t      *o_DataFrameSize_u16);

static uint32_t      IPC_f_CopyDataToSm_u32         (uint16_t            i_msgIdTxIdx_u16,
                                                     const IPCMessage_Params_t *i_IPCMsg_ps, 
                                                     IpcSmBuff_t         *i_smBuff_ps);

static uint16_t      IPC_f_GetMsgIdTxIdx_u16        (uint16_t i_msgId_u16);
#endif

/* Function to be called by IPC_F_IpcManager_v() to Read data from other Cores and provide to signal handler using callback function*/
static uint32_t      IPC_f_WrapperRcv_u32           (void);
static uint16_t      IPC_f_GetMsgId_u16             (const uint8_t *i_DataRcv_pu8);
#if (D_NUMBER_OF_RX_MESSAGES > 0)
static void          IPC_f_ProcessCallback_v        (uint16_t v_msgIdRxIdx_u16, void *i_IpcRcvdData_pv, uint8_t i_DataLoc);
static void          IPC_f_ValidateMsgIdCnt_v       (uint16_t i_msgIdRxIdx_u16, const uint8_t *i_DataRcv_pu8);
static uint16_t      IPC_f_GetMsgIdRxIdx_u16        (uint16_t i_msgId_u16);
static uint16_t      IPC_f_GetRcvdDataSize_u16      (const uint8_t *i_DataRcv_pu8);
#endif

#ifdef BUILD_MPU1_0
static int8_t        IPC_f_GetVirAddr_s8            (long_t i_PhysicalMemoryAddr_t, long_t i_Size_t, void **o_VirtualMemoryAddr_ppv);
static int8_t        IPC_f_ClearVirAddr_s8          (void* i_physicalAddr_pu32, long_t i_Size_t);
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
/** \brief Utility used to initialize memory sections word wise */
static void AppUtils_MemsetWord(uint32 *memPtr, uint32 pattern, uint32 length)
{
  /* DD-ID: {84D5B0C4-030D-433f-9772-348B9758B863}*/
    while (length > 0U)
    {
        *memPtr = pattern;
        memPtr++;
        length--;
    }

    return;
}
/** \brief Utility used to initialize memory sections.
 *   This API is used to initialize fixed size(APP_UTILS_LINKER_FILL_LENGTH)
 *   before start of each section and before end of each section. i.e
 *      .=align(4);
 *       __linker_spi_text_start = .;
 *      . += APP_UTILS_LINKER_FILL_LENGTH; (This portion is initialized)
 *      *(SPI_TEXT_SECTION)
 *      .=align(4);
 *      . += APP_UTILS_LINKER_FILL_LENGTH; (This portion is initialized)
 *      __linker_spi_text_end = .;
 *
 *   This API should be called during module start up code.
 */
static void AppUtils_SectionInit(uint32 *pAppUtils_SecHoleAddrList, uint32 secCnt)
{
  /* DD-ID: {7B2D3C4E-153E-4aaa-A9FC-A11268A35A7B}*/
    uint32 index;

    for (index = 0U; index < secCnt; index++)
    {
        AppUtils_MemsetWord(
            ((uint32 *)pAppUtils_SecHoleAddrList[index]),
            APP_UTILS_LINKER_FILL_PATTERN,
            (APP_UTILS_LINKER_FILL_LENGTH / sizeof (uint32)));
    }

    return;
}
/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */
/** \brief Utility used to initialize memory sections.
 *   This API is used to initialize fixed size(APP_UTILS_LINKER_FILL_LENGTH)
 *   before start of each section and before end of each section. i.e
 *      .=align(4);
 *       __linker_cdd_ipc_text_start = .;
 *      . += APP_UTILS_LINKER_FILL_LENGTH; (This portion is initialized)
 *      *(ADC_TEXT_SECTION)
 *      .=align(4);
 *      . += APP_UTILS_LINKER_FILL_LENGTH; (This portion is initialized)
 *      __linker_cdd_ipc_text_end = .;
 *
 *   This API should be called during module start up code.
 */
static void AppUtils_CddIpcSectionInit(void)
{
  /* DD-ID: {75806436-854D-4a5c-A0F3-4107305BB953}*/
    /* Initialize memory sections  */
    AppUtils_SectionInit(&CddIpcApp_SecHoleAddrList[0U],
        MODULEAPP_NUM_SEC_HOLES(CddIpcApp_SecHoleAddrList));
}
#endif


/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */

/*
 * Purpose: IPC manager mailbox initialization 
 * Description: To initialize MailBox Interrupt.
 * Return Type : void
*/

#if defined(BUILD_MCU1_0)
void Os_Isr_IPC_mailbox1 (void)
{
  /* DD-ID:{BA753EB2-B885-47ff-A8AD-52AECB8FC728}*/
    Ipc_newMessageIsr(CDD_IPC_CORE_MPU1_0);
}

void Os_Isr_IPC_mailbox2 (void)
{
  /* DD-ID: {2D243846-7A6E-4d6d-B512-41569CE67094}*/
    Ipc_newMessageIsr(CDD_IPC_CORE_MCU2_0);
}
#endif

#if defined(BUILD_MCU3_1)
void Os_Isr_IPC_mailbox1 (void)
{
  /* DD-ID: {940F1874-702F-4f9f-AA57-AE1E5E35DF4D}*/
    Ipc_newMessageIsr(CDD_IPC_CORE_MCU1_0);
}

void Os_Isr_IPC_mailbox2 (void)
{
  /* DD-ID:{3578A977-C9CA-4de2-AFC4-0B921B661AA5}*/
    Ipc_newMessageIsr(CDD_IPC_CORE_MPU1_0);
}
#endif

/*
 * Purpose: IPC manager initializing
 * Description: To initialize processor cores, VirtIO, RPmessage_params, vring address, Buffer size.
                 Initializing EndPoint and Announce RPMessage for All cores.
 * Return Type : uint32_t
*/
uint32_t IPC_F_ManagerInit_u32(void)
{
  /* DD-ID: {212D76C7-B44D-4cf0-B745-19EBB0EA2C30}*/
    uint32_t v_errSts_u32 = D_IPC_NO_ERROR;
    const char announceMsg[32U] = "Ready for service";
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    Std_ReturnType v_rtnVal_u8 = E_NOT_OK;
#if (STD_ON == CDD_IPC_ANNOUNCE_API)
    uint32 coreIdx, comId, rCoreId;
#endif
    /* Initialize memory sections  */
    AppUtils_CddIpcSectionInit();
    Cdd_IpcInit();
#if (STD_ON == CDD_IPC_ANNOUNCE_API)
    /* For every remote core, Announce once */
    for (coreIdx = 0U; coreIdx < CddIpcConfiguraions_PC.coreIds.numProcs; coreIdx++)
    {
        rCoreId = CddIpcConfiguraions_PC.coreIds.remoteProcID[coreIdx];
        for (comId = 0U; comId < CddIpcConfiguraions_PC.channelCount; comId++)
        {
            if (rCoreId == CddIpcConfiguraions_PC.pChCfg[comId].remoteProcId)
            {
                v_rtnVal_u8 = Cdd_IpcAnnounce(announceMsg, CddIpcConfiguraions_PC.pChCfg[comId].id);
                if(v_rtnVal_u8 != E_OK)
                {
                    /* IPC announce failed -> collect error */
                    D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_RPMSG_ANNOUNCE);
                }
            }
        }
    }
#endif
#else
    int32_t  v_rtnVal_s32 = IPC_SOK;
    uint32_t v_myAllocEp_u32;
    RPMessage_Params comChParam_s;

#ifndef BUILD_MCU2_0
    RPMessage_Params cntrlParam_s;
    Ipc_VirtIoParams vqParam_s;
    /* Number of remote processors */
    static uint16_t  s_IpcNumProc_u16 = sizeof(V_IpcRemoteProc_u32)/sizeof(uint32_t);
#endif

    /* Is a 3 Step initialization Sequence
        1. Initialize Processor ID's
        2. Initialize IPC and VirtIO
        3. Initialize Control EP for RP MSG
        3.1. Annouce availability
        Communication can start now
    */
    /* Step 1 */
#ifndef BUILD_MCU2_0
    v_rtnVal_s32 = Ipc_mpSetConfig(V_IpcSelfProcId_u32,
                             s_IpcNumProc_u16,
                             &V_IpcRemoteProc_u32[0U]);

    /* Step 2 */
    if (IPC_SOK == v_rtnVal_s32)
    {
        /* Requirement ID - 16062150 */
        v_rtnVal_s32 = Ipc_init(NULL);
        /* Init VirtIO */
        if (IPC_SOK == v_rtnVal_s32)
        {
            vqParam_s.vqObjBaseAddr = (void*)s_Ipc_SysVqBuf_au8;
            vqParam_s.vqBufSize     = s_IpcNumProc_u16 * Ipc_getVqObjMemoryRequiredPerCore();
            vqParam_s.vringBaseAddr = (void*)D_IPC_APP_VRING_BASE_ADDRESS; /* PRQA S 0326 */
            vqParam_s.vringBufSize  = D_IPC_APP_VRING_BUFFER_SIZE;
            vqParam_s.timeoutCnt    = D_IPC_VRING_TIMEOUT;  /* Wait for re transmit counts */
            /* Requirement ID - 16667439 */
            v_rtnVal_s32 = Ipc_initVirtIO(&vqParam_s);

            if (IPC_SOK == v_rtnVal_s32)
            {
                /* Step 3 */
                /* Control EP */
                /* Requirement ID - 16667424 */
                v_rtnVal_s32 = RPMessageParams_init(&cntrlParam_s);

                if (IPC_SOK == v_rtnVal_s32)
                {
                    cntrlParam_s.buf         = &s_Ipc_CtrlTaskMsgBuf_au8[0U];
                    cntrlParam_s.bufSize     = D_IPC_APP_RPMSG_DATA_SIZE;
                    cntrlParam_s.stackBuffer = &s_Ipc_RpMsgCtrlTaskStack_au8[0U];
                    cntrlParam_s.stackSize   = D_IPC_APP_TASK_STACK;
                    /* Requirement ID - 16667424 */
                    v_rtnVal_s32 = RPMessage_init(&cntrlParam_s);
#endif

                    if (IPC_SOK == v_rtnVal_s32)
                    {
                        /* Requirement ID - 16667424 */
                        v_rtnVal_s32 = RPMessageParams_init(&comChParam_s);
                        if (IPC_SOK == v_rtnVal_s32)
                        {
                            comChParam_s.numBufs = D_IPC_VRING_BUFF_CNT;
                            comChParam_s.buf = s_IpcRpMsgRxBuf_au8;
                            comChParam_s.bufSize = D_IPC_APP_RPMSG_DATA_SIZE;
                            comChParam_s.requestedEndpt = s_IpcLocalEp_u32;
                            /* Requirement ID - 16667424 */
                            s_IpcCommChHndl_s = RPMessage_create(&comChParam_s, &v_myAllocEp_u32);

                            /* Step 3 */
                            /* Communication EP */
                            if (NULL == s_IpcCommChHndl_s)
                            {
                                /* Invalid handle -> Collect error */
                                D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_INVALID_HANDLE);
                            }
                            else if (v_myAllocEp_u32 != s_IpcLocalEp_u32)
                            {
                                /* Allocated local endpoint not matched with configured local endpoint -> Collect error */
                                D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_RPMSG_CREATE);
                            }
                            else
                            {
                                /* Step 3.1 Announce availability */
                                /* Requirement ID - 16667424 */
                                v_rtnVal_s32 = RPMessage_announce(RPMESSAGE_ALL,
                                                                     v_myAllocEp_u32,
                                                                     announceMsg);
                                if(v_rtnVal_s32 != IPC_SOK)
                                {
                                   /* IPC announce failed -> collect error */
                                   D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_RPMSG_ANNOUNCE);
                                }
                            }
                        }
                        else
                        {
                            /* RPMessageParams_init failed -> Collect error */
                            D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_RPPARAMS_INIT_CREATE);
                        }
                    }
                    else
                    {
                        /* RPMessage_init failed -> Collect error */
                        D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_RPMSG_INIT);
                    }
#ifndef BUILD_MCU2_0
                }
                else
                {
                    /* RPMessageParams_init failed -> Collect error */
                    D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_RPPARAMS_INIT_INIT);
                }
            }
            else
            {
                /* Ipc_initVirtIO failed -> Collect error */
                D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_VIRTIO_INIT);
            }
        }
        else
        {
            /* Ipc_init failed -> Collect error */
            D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_IPCINIT);
        }
    }
    else
    {
        /* Ipc_mpSetConfig failed -> Collect error */
        D_IPC_COLLECT_INIT_ERR(v_errSts_u32, D_IPC_INIT_ERR_MPSETCONFIG);
    }
#endif
#endif

    /* Initialize IPC lookuptable pointers */
    IPC_F_lookupTblInit_v ();
    
    /* Initialize error monitor variables  */
    IPC_F_InitErrormon_v();
    
    /* Initialize diag variables  */
    IPC_F_InitDiag_v();

    return v_errSts_u32;
}

#if (D_NUMBER_OF_TX_MESSAGES > 0)
/*
 * Purpose: Select Destination core and endpoint
 * Description: Select destination ChannelID and Endpoint from message id for specific Remote
 * Return Type : uint32_t
 * Requirement ID - 13731861
*/
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
static uint32_t IPC_f_SelectDestCoreCddChanId_u32(uint16_t i_msgIdIdx_u16, 
                                                  uint32_t *o_destCoreChanId_pu32, 
                                                  uint16_t *o_remoteCoreBitMask_pu16, 
                                                  uint16_t *o_num_core_ids_pu16)
{
    /* DD-ID: {4785FA93-2511-46ab-B5E7-A8BB3F43C450}*/
    /* v_coreIdx_u8 used for indexing */
    uint8_t  v_coreIdx_u8;
    uint8_t  v_destCoreIDfound_u8 = (uint8_t)FALSE;
    uint8_t  v_noDestCoreIDfound_u8 = (uint8_t)TRUE;
    uint16_t v_coreBitPos_u16;
    uint32_t v_errSts_u32 = D_IPC_NO_ERROR;

    /* If MsgId index is valid */
    if(i_msgIdIdx_u16 < D_NUMBER_OF_TX_MESSAGES)
    {
        for(v_coreIdx_u8 = 0; v_coreIdx_u8 < D_NUMBER_OF_CORES; v_coreIdx_u8++)
        {
            v_coreBitPos_u16 = ((uint16_t)BIT_SHIFT_ONE_BIT << (uint16_t)v_coreIdx_u8);

            /* Check CORES which are going to receive the data */
            if((V_ipcLutAttrTx_as[i_msgIdIdx_u16].dstCores_u16 & v_coreBitPos_u16) == v_coreBitPos_u16)
            {
                /* Destination core found */
                v_destCoreIDfound_u8 = (uint8_t)TRUE;

                /*DO NOT CHANGE THE ORDER OF SWITCH: as this depends on user defined lookup tabel */
                switch(v_coreBitPos_u16)
                {
                    case MPU1_0_BITMSK_0:
                    {
                        *o_destCoreChanId_pu32 = CddIpcConf_IpcComChanId_Cdd_IpcMpu1_0; /**< ARM A72 - VM0 */
                        break;
                    }
#ifndef BUILD_MCU1_0
                    case MCU1_0_BITMSK_1:
                    {
                        *o_destCoreChanId_pu32 = CddIpcConf_IpcComChanId_Cdd_IpcMcu1_0; /**< ARM MCU  R5F - core0 */
                        break;
                    }
#endif
                    case MCU2_0_BITMSK_2:
                    {
                        *o_destCoreChanId_pu32= CddIpcConf_IpcComChanId_Cdd_IpcMcu2_0; /**< ARM Main R5F - core0 */
                        break;
                    }
                    case MCU2_1_BITMSK_3:
                    {
                        *o_destCoreChanId_pu32 = CddIpcConf_IpcComChanId_Cdd_IpcMcu2_1; /**< ARM Main R5F - core3 */
                        break;
                    }
                    case MCU3_0_BITMSK_4:
                    {
                        *o_destCoreChanId_pu32 = CddIpcConf_IpcComChanId_Cdd_IpcMcu3_0; /**< ARM Main R5F - core2 */
                        break;
                    }
#ifndef BUILD_MCU3_1
                    case MCU3_1_BITMSK_5:
                    {
                        *o_destCoreChanId_pu32 = CddIpcConf_IpcComChanId_Cdd_IpcMcu3_1; /**< ARM Main R5F - core2 */
                        break;
                    }
#endif
                    default:
                    {
                        /* Configured destination core not matched with any expected destination core */
                        v_destCoreIDfound_u8 = (uint8_t)FALSE;

                        /* Collect error */
                        D_IPC_COLLECT_TX_ERR(v_errSts_u32, D_IPC_TX_ERR_LUT_CONF_INVALID_DST, V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgId_u16, NULL);

                        break;
                    }
                }

                if(TRUE == v_destCoreIDfound_u8)
                {
                    /* At least one destination core found */
                    v_noDestCoreIDfound_u8 = (uint8_t)FALSE;
                    
                    /* Collect destination core bitmask and increment pointer */
                    *o_remoteCoreBitMask_pu16 = v_coreBitPos_u16;
                    o_remoteCoreBitMask_pu16++;

                    /* Point to next address for next destination core */
                    (o_destCoreChanId_pu32)++;

                    /* Increment destination core count */
                    (*o_num_core_ids_pu16)++;
                }
            }
        }
    }

    /* If No destination core found in lookup table */
    if(TRUE == v_noDestCoreIDfound_u8)
    {
        /* Set Error in Core Selection */
        D_IPC_COLLECT_TX_ERR(v_errSts_u32, D_IPC_TX_ERR_NO_DST_CORE_FOUND, V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgId_u16, NULL);
    }

    return v_errSts_u32;
}
#else

/*
 * Purpose: Select Destination core and endpoint
 * Description: Select destination core and Endpoint from message id for specific Remote
 * Return Type : uint32_t
 * Requirement ID - 13731861
*/
static uint32_t IPC_f_SelectDestCore_u32(uint16_t i_msgIdIdx_u16,
                                         uint32_t *o_destProcId_pu32, 
                                         uint32_t *o_destEndPt_pu32,
                                         uint16_t *o_remoteCoreBitMask_pu16,
                                         uint16_t *o_num_core_ids_pu16 )
{
    /* DD-ID: {6E0E53DB-B7A1-4d24-91E2-E770C6582809}*/
    uint32_t v_errSts_u32 = D_IPC_NO_ERROR;
 
    /* v_coreIdx_u8 used for indexing */
    uint8_t  v_coreIdx_u8;
    uint8_t  v_destCoreIDfound_u8 = FALSE;
    uint8_t  v_noDestCoreIDfound_u8 = TRUE;
    uint16_t v_coreBitPos_u16;


    /* If MsgId index is valid */
    if(i_msgIdIdx_u16 < D_NUMBER_OF_TX_MESSAGES)
    {
        for(v_coreIdx_u8 = 0; v_coreIdx_u8 < D_NUMBER_OF_CORES; v_coreIdx_u8++)
        {
            v_coreBitPos_u16 = (uint16_t)(BIT_SHIFT_ONE_BIT << v_coreIdx_u8);

            /* Check CORES which are going to receive the data */
            if((V_ipcLutAttrTx_as[i_msgIdIdx_u16].dstCores_u16 & v_coreBitPos_u16) == v_coreBitPos_u16)
            {
                /* Destination core found */
                v_destCoreIDfound_u8 = TRUE;

                /*DO NOT CHANGE THE ORDER OF SWITCH: as this depends on user defined lookup tabel */
                switch(v_coreBitPos_u16)
                {
                    case MPU1_0_BITMSK_0:
                    {
                        *o_destProcId_pu32 = IPC_MPU1_0;
                        *o_destEndPt_pu32 = D_IPC_APP_LOCAL_EP_MPU1_0; /**< ARM A72 - VM0 */
                        break;
                    }
                    case MCU1_0_BITMSK_1:
                    {
                        *o_destProcId_pu32 = IPC_MCU1_0;
                        *o_destEndPt_pu32 = D_IPC_APP_LOCAL_EP_MCU1_0; /**< ARM MCU  R5F - core0 */
                        break;
                    }
                    case MCU2_0_BITMSK_2:
                    {
                        *o_destProcId_pu32 = IPC_MCU2_0;
                        *o_destEndPt_pu32 = D_IPC_APP_LOCAL_EP_MCU2_0; /**< ARM Main R5F - core0 */
                        break;
                    }
                    case MCU2_1_BITMSK_3:
                    {
                        *o_destProcId_pu32 = IPC_MCU2_1;
                        *o_destEndPt_pu32 = D_IPC_APP_LOCAL_EP_MCU2_1; /**< ARM Main R5F - core3 */
                        break;
                    }
                    case MCU3_0_BITMSK_4:
                    {
                        *o_destProcId_pu32 = IPC_MCU3_0;
                        *o_destEndPt_pu32 = D_IPC_APP_LOCAL_EP_MCU3_0; /**< ARM Main R5F - core2 */
                        break;
                    }
                    case MCU3_1_BITMSK_5:
                    {
                        *o_destProcId_pu32 = IPC_MCU3_1;
                        *o_destEndPt_pu32 = D_IPC_APP_LOCAL_EP_MCU3_1; /**< ARM Main R5F - core2 */
                        break;
                    }
                    default:
                    {
                        /* Configured destination core not matched with any expected destination core */
                        v_destCoreIDfound_u8 = FALSE;

                        /* Collect error */
                        D_IPC_COLLECT_TX_ERR(v_errSts_u32, D_IPC_TX_ERR_LUT_CONF_INVALID_DST, V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgId_u16, NULL);

                        break;
                    }
                }

                if(TRUE == v_destCoreIDfound_u8)
                {
                    /* At least one destination core found */
                    v_noDestCoreIDfound_u8 = FALSE;
                    
                    /* Collect destination core bitmask and increment pointer */
                    *o_remoteCoreBitMask_pu16 = v_coreBitPos_u16;
                    o_remoteCoreBitMask_pu16++;

                    /* Point to next address for next destination core and endpoint*/
                    (o_destProcId_pu32)++;
                    (o_destEndPt_pu32)++;

                    /* Increment destination core count */
                    (*o_num_core_ids_pu16)++;
                }
            }
        }
    }

    /* If No destination core found in lookup table */
    if(TRUE == v_noDestCoreIDfound_u8)
    {
        /* Set Error in Core Selection */
        D_IPC_COLLECT_TX_ERR(v_errSts_u32, D_IPC_TX_ERR_NO_DST_CORE_FOUND, V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgId_u16, NULL);
    }

    return v_errSts_u32;
}
#endif
#endif

#ifdef BUILD_MPU1_0

/*
 * Purpose: Convert & Map Physical Address to Virtual Address
 * Description: calling mmap_device_memory() to Map Virtual Address .
 * Return Type: int8_t (Error = -1)
*/
static int8_t IPC_f_GetVirAddr_s8(long_t i_PhysicalMemoryAddr_t, long_t i_Size_t, void **o_VirtualMemoryAddr_ppv)
{
   /* DD-ID: {BE379482-9B13-476b-8C9C-55E8B21BACD8}*/
    int8_t v_Result_s8 = -1;

    if (NULL != o_VirtualMemoryAddr_ppv)
    {
        *o_VirtualMemoryAddr_ppv = mmap_device_memory(NULL,
                                                      i_Size_t,
                                                      PROT_READ | PROT_WRITE | PROT_NOCACHE,
                                                      0,
                                                      i_PhysicalMemoryAddr_t);

        if (*o_VirtualMemoryAddr_ppv != NULL)
        {
            v_Result_s8 = 0;
        }
    }
    return v_Result_s8;
}

/*
 * Purpose: Unmap the Mapped Virtual Memory.
 * Description: calling munmap_device_memory() to UnMap Virtual Address.
 * Return Type: int8_t (Error = -1)
*/
static int8_t IPC_f_ClearVirAddr_s8(void* i_physicalAddr_pu32, long_t i_Size_t)
{
     /* DD-ID: {4388D00B-15A4-4d6f-A813-8CEE5BE4FC41}*/
    int8_t v_Result_s8 = -1;

    if (NULL != i_physicalAddr_pu32)
    {
        v_Result_s8 = munmap_device_memory(i_physicalAddr_pu32, i_Size_t);
    }
    return v_Result_s8;
}
#endif

/*
 * Purpose: Receiver Function to receive data from other core.
 * Description: calling RPMessage_recvNb() to receive data coming from other cores .
 * Return Type : uint32_t
 * Requirement ID - 13738635 
*/
static uint32_t IPC_f_WrapperRcv_u32 (void)
{
  /* DD-ID: {F63A6D89-9E4E-4239-B49C-89EF4231AEEC}*/
    int32_t       v_rcvRtnVal_s32 = IPC_EFAIL;
    uint32_t      v_errorStatus_u32 = D_IPC_NO_ERROR;
    unsigned long v_rcvDataBuffSize_u32 = D_IPC_MAX_MSG_SIZE;
    uint8_t       v_dataRcv_au8[D_IPC_MAX_MSG_SIZE] __attribute__((aligned (4)));
    uint16_t      v_ipcMsgID_u16;
    uint16_t      v_readCntr_u16 = 0;
#if (D_NUMBER_OF_TX_MESSAGES > 0) || (D_NUMBER_OF_RX_MESSAGES > 0)
    IpcSmBuff_t   v_smBuff_s;
#endif
#if (D_NUMBER_OF_TX_MESSAGES > 0)
    uint16_t      v_msgIdTxIdx_u16;
#endif
#if (D_NUMBER_OF_RX_MESSAGES > 0)
    uint16_t      v_rcvdDataSize_u16;
    uint8_t       v_crc8_u8;
    uint16_t      v_msgIdRxIdx_u16;
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    Std_ReturnType  v_sendErr_s32 = E_OK;
#else
    int32_t v_sendErr_s32 = IPC_SOK;
#endif
#endif
#if defined (BUILD_MPU1_0)
    long_t *i_vAdd_pl = NULL;
    long_t i_pAdd_pl;
    int8_t i_retVal_s8 = 0;
#endif

    /* Read till max number of read limit reached or no data avaiable*/
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    uint32 v_chId_u32 = 0;

    while(v_chId_u32 < CddIpcConfiguraions_PC.channelCount)
    {
        /* Check if max number of read limit reached */
        if (v_readCntr_u16 < D_IPC_MAX_READ_PER_CYCLE)
        {
            v_rcvDataBuffSize_u32 = D_IPC_MAX_MSG_SIZE;
            v_rcvRtnVal_s32 = (int32_t)Cdd_IpcReceiveMsg(v_chId_u32, &v_dataRcv_au8[D_IPC_MSG_ID_IDX], &v_rcvDataBuffSize_u32);

#else
    {
        uint32_t v_remoteProc_u32, v_remoteEp_u32;

        /* Check if max number of read limit reached */
        while (v_readCntr_u16 < D_IPC_MAX_READ_PER_CYCLE)
        {
#if defined (BUILD_MPU1_0)
            /* Requirement ID - 16667424 */
            v_rcvRtnVal_s32 = RPMessage_recv(s_IpcCommChHndl_s, &v_dataRcv_au8[D_IPC_MSG_ID_IDX],
                                          (uint16_t *)&v_rcvDataBuffSize_u32, &v_remoteEp_u32, &v_remoteProc_u32,
                                          /* 0 will make this a RpMessage Nonblocking call */
                                          0
                                          );
#else
            /* Requirement ID - 16667424 */
            v_rcvRtnVal_s32 = RPMessage_recvNb(s_IpcCommChHndl_s, &v_dataRcv_au8[D_IPC_MSG_ID_IDX],
                                       (uint16_t *)&v_rcvDataBuffSize_u32, &v_remoteEp_u32, &v_remoteProc_u32);
#endif
#endif
            if (IPC_SOK == v_rcvRtnVal_s32)
            {
                /* Increament read counter on sucessfull read (Data avaiable) */
                v_readCntr_u16++;

                /* Diag -> Update max read counter */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
                IPC_F_DiagUpdateMaxReadCntr_v(v_readCntr_u16, v_chId_u32);
#else
                IPC_F_DiagUpdateMaxReadCntr_v(v_readCntr_u16);
#endif
                
                /* Extract MessageID */
                v_ipcMsgID_u16 = IPC_f_GetMsgId_u16 (&v_dataRcv_au8[0]);
#ifdef IPC_VERIFY                
#ifdef BUILD_MCU2_0
                appLogPrintf("[MCU2_0]v_ipcMsgID_u16:%d, v_rcvDataBuffSize_u32:%d\n", v_ipcMsgID_u16, (uint16_t)v_rcvDataBuffSize_u32);
#endif

#ifdef BUILD_MPU1_0
                printf("[MPU1_0]v_ipcMsgID_u16:%d,v_rcvDataBuffSize_u32:%d\n", v_ipcMsgID_u16, (uint16_t)v_rcvDataBuffSize_u32);
#endif
#ifdef BUILD_MCU2_1
                UART_printf("[MCU2_1]v_ipcMsgID_u16:%d,v_rcvDataBuffSize_u32:%d\n", v_ipcMsgID_u16, (uint16_t)v_rcvDataBuffSize_u32);
#endif
#endif

                /* Validate CRC8 of received data */
                /* Requirement ID - 16062146 */
                v_errorStatus_u32 = IPC_F_validateCrc8_u32(v_ipcMsgID_u16, &v_dataRcv_au8[0], (uint16_t)(v_rcvDataBuffSize_u32 - D_IPC_DATA_FOOTER_SIZE));

                if(D_IPC_NO_ERROR == v_errorStatus_u32)
                {
#if (D_NUMBER_OF_RX_MESSAGES > 0)
                    /* Get corresponding index of message id in IPC lookup table for Rx attr */
                    v_msgIdRxIdx_u16 = IPC_f_GetMsgIdRxIdx_u16(v_ipcMsgID_u16);

                    /* If MsgId found in lookup tables for Rx attr */
                    if(v_msgIdRxIdx_u16 < D_NUMBER_OF_RX_MESSAGES)
                    {
                        /* Extract received data size */
                        v_rcvdDataSize_u16 = IPC_f_GetRcvdDataSize_u16(&v_dataRcv_au8[0]);
                        
                        /*If received data size is same as configured in IPC lookup table for Rx attr */
                        if(v_rcvdDataSize_u16 == V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].dataSize_u16)
                        {
                            /* Extract and validate timestamp */
                            IPC_F_ValidateTimestamp_v (&v_dataRcv_au8[v_rcvDataBuffSize_u32 - D_IPC_FOOTER_TIME_SIZE], v_msgIdRxIdx_u16);

                            /* Check if received data is Raw data in IPC buffer */
                            if(v_dataRcv_au8[D_IPC_DATA_LOC_IDX] == D_IPC_DATA_LOC_DATA_RAW)
                            {
                                /* Requirement ID - 16671056 */
                                /* Validate MessageID counter*/
                                IPC_f_ValidateMsgIdCnt_v (v_msgIdRxIdx_u16, &v_dataRcv_au8[0]);

                                /* Call callback function to inform signal handler / RTE */
                                IPC_f_ProcessCallback_v(v_msgIdRxIdx_u16, (void *)&v_dataRcv_au8[ D_IPC_DATA_IDX ], D_IPC_DATA_LOC_DATA_RAW);
                            }

                            /*Check if received data is data pointer in IPC buffer -> data is avaiable in shared memory buffer*/
                            else if (v_dataRcv_au8[D_IPC_DATA_LOC_IDX] == D_IPC_DATA_LOC_DATA_PTR)
                            {
                                /* Requirement ID - 16671060 */
                                /* Get shared memory buffer information (Shared memory address, buffer index, Remote core SM ID etc) */
                                (void)memcpy((uint8_t *)&v_smBuff_s, &v_dataRcv_au8[D_IPC_DATA_IDX], sizeof(v_smBuff_s));

                                /* Check if received data is data or acknowledgement? */
                                if (v_dataRcv_au8[D_IPC_SENT_DATA_TYPE_IDX] == D_IPC_SENT_DATA_TYPE_DATA)
                                {
                                    /* This is data -> Consume data and send acknowledgement */

                                    /* Validate MessageID counter*/
                                    IPC_f_ValidateMsgIdCnt_v (v_msgIdRxIdx_u16, &v_dataRcv_au8[0]);

                                    if (v_smBuff_s.addr_pv != NULL)
                                    {
#if defined(BUILD_MPU1_0)
                                        memcpy(&i_pAdd_pl, &v_smBuff_s.addr_pv, sizeof(int));

                                        i_retVal_s8 = IPC_f_GetVirAddr_s8(i_pAdd_pl, V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].dataSize_u16, (void**) &i_vAdd_pl);
                                        
                                        if( i_retVal_s8 != -1)
                                        {
                                            /* Requirement ID - 16671766 */
                                            v_errorStatus_u32 = IPC_F_validateCrc32_u32(v_ipcMsgID_u16, (uint8_t *)i_vAdd_pl,
                                                                            V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].dataSize_u16);

                                            i_retVal_s8 = IPC_f_ClearVirAddr_s8(i_vAdd_pl,V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].dataSize_u16);
                                        
                                            if(i_retVal_s8 == -1)
                                            {
                                                /* unmap virtual address failed -> Collect error */
                                                D_IPC_COLLECT_RX_ERR(v_errorStatus_u32, D_IPC_RX_ERR_UNMAP_VIR_MEM_ADDR, v_ipcMsgID_u16, NULL);
                                            }
                                        }
                                        else
                                        {
                                            /* Get virtual address failed -> Collect error */
                                            D_IPC_COLLECT_RX_ERR(v_errorStatus_u32, D_IPC_RX_ERR_INVALID_VIR_MEM_ADDR, v_ipcMsgID_u16, NULL);
                                        }
#else
#if defined(BUILD_MCU1_0)
                                        /* Invalidate Cache before reading data from sh mem (Work around for sh mem corruption issue (Defect id 16751023) */
                                        CacheP_Inv((void *)v_smBuff_s.addr_pv, ((int32_t)V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].dataSize_u16 + (int32_t)D_CRC32_SIZE));
#endif
                                        /* Validate CRC32 of received data in shared memory */
                                        /* Requirement ID - 16671766 */
                                        v_errorStatus_u32 = IPC_F_validateCrc32_u32(v_ipcMsgID_u16, (uint8_t *)v_smBuff_s.addr_pv, 
                                                                            V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].dataSize_u16);
#endif

                                        if(D_IPC_NO_ERROR == v_errorStatus_u32)
                                        {
                                            /* Call callback function to inform signal handler / RTE (Before sending ack back)*/
                                            IPC_f_ProcessCallback_v(v_msgIdRxIdx_u16, (void *)v_smBuff_s.addr_pv, D_IPC_DATA_LOC_DATA_PTR);

                                            /* Send acknowledgement */

                                            /* Write Ack byte */
                                            v_dataRcv_au8[D_IPC_SENT_DATA_TYPE_IDX] = D_IPC_SENT_DATA_TYPE_ACK;

                                            /* Copy CRC8 into IPC buffer */
                                            /* Requirement ID - 16062146 */
                                            v_crc8_u8 = IPC_F_CalcCrc8_u8(v_dataRcv_au8, D_IPC_LARGE_DATA_FOOTER_IDX);
                                            v_dataRcv_au8[D_IPC_LARGE_DATA_FOOTER_IDX + D_IPC_FOOTER_CRC8_OFFSET] = v_crc8_u8;

                                            /* send ack to REMOTE_CORES */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
                                            v_sendErr_s32 = Cdd_IpcSendMsg(v_chId_u32, &v_dataRcv_au8[0U], v_rcvDataBuffSize_u32);
                                            if (E_OK != v_sendErr_s32)
#else
                                            v_sendErr_s32 = IPC_f_SendData_s32(v_remoteProc_u32, v_remoteEp_u32, 
                                                                               &v_dataRcv_au8[0U],(uint16_t)v_rcvDataBuffSize_u32);
                                            if (IPC_SOK != v_sendErr_s32)
#endif
                                            {
                                                /* Transmission Failed -> Collect error */
                                                D_IPC_COLLECT_RX_ERR(v_errorStatus_u32, D_IPC_RX_ERR_ACK_RPMSGSEND, v_ipcMsgID_u16, NULL);
                                            }
                                        }
                                        else
                                        {
                                            /* CRC 32 error -> Error already set */
                                        }
                                    }
                                    else
                                    {
                                        /* Received shared memory address for large data is NULL -> Collect error */
                                        D_IPC_COLLECT_RX_ERR(v_errorStatus_u32, D_IPC_RX_ERR_INVALID_SH_MEM_ADDR, v_ipcMsgID_u16, NULL);
                                    }
                                }
                                else
                                {
                                    /* Wrong data type received -> Collect error */
                                    D_IPC_COLLECT_RX_ERR(v_errorStatus_u32, D_IPC_RX_ERR_RCVD_DATA_TYPE_INVALID, v_ipcMsgID_u16, NULL);
                                }
                            }
                            else
                            {
                                /* Wrong data location type received -> Collect error */
                                D_IPC_COLLECT_RX_ERR(v_errorStatus_u32, D_IPC_RX_ERR_RCVD_DATA_LOC_INVALID, v_ipcMsgID_u16, NULL);
                            }
                        }
                        else
                        {
                            /* Wrong data size received -> Collect error */
                            D_IPC_COLLECT_RX_ERR(v_errorStatus_u32, D_IPC_RX_ERR_RCVD_DATA_SIZE_INVALID, v_ipcMsgID_u16, NULL);
                        }
                    }
                    else /* This may be acknowledgement */
                    {
#endif
#if (D_NUMBER_OF_TX_MESSAGES > 0)

                        /* Get corresponding index of message id in IPC lookup table for Tx*/
                        v_msgIdTxIdx_u16 = IPC_f_GetMsgIdTxIdx_u16 (v_ipcMsgID_u16);

                        if ((v_msgIdTxIdx_u16 < D_NUMBER_OF_TX_MESSAGES) && 
                            (v_dataRcv_au8[D_IPC_DATA_LOC_IDX] == D_IPC_DATA_LOC_DATA_PTR) &&
                            (v_dataRcv_au8[D_IPC_SENT_DATA_TYPE_IDX] == D_IPC_SENT_DATA_TYPE_ACK)
                           )
                        {
                            /* Get shared memory buffer information (Shared memory address, buffer index, Remote core SM ID etc) */
                            (void)memcpy((uint8_t *)&v_smBuff_s, &v_dataRcv_au8[D_IPC_DATA_IDX], sizeof(v_smBuff_s));
                            if (v_smBuff_s.addr_pv != NULL)
                            {
                                /* This is Ack -> Release SM buffer*/
                                IPC_F_ReleaseSmBuff_u32(v_msgIdTxIdx_u16, v_smBuff_s);
                            }
                            else
                            {
                                /* Received shared memory address for large data Ack is NULL -> Collect error */
                                D_IPC_COLLECT_TX_ERR(v_errorStatus_u32, D_IPC_TX_ERR_ACK_INVALID_SH_MEM_ADDR, v_ipcMsgID_u16, NULL);
                            }
                        }
                        else
                        {
                            /* Ignore received message */
                        }
#endif
#if (D_NUMBER_OF_RX_MESSAGES > 0)
                    }
#endif
                }
                else
                {
                    /* CRC 8 error (error already set) */
                }
            }
            else
            {
                /* Unsuccessful read */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
                v_chId_u32++;           /* Start reading from next core */
                v_readCntr_u16 = 0;     /* Reset read counter for next core*/
#else
                v_readCntr_u16 = D_IPC_MAX_READ_PER_CYCLE;     /* Set read counter to max limit to break while loop */
#endif
                /*If RPMessage_recv() or RPMessage_recvNb() failed other than timeout */
	    	/* TO DO -> QAC needs to be fixed */
                if (IPC_ETIMEOUT != v_rcvRtnVal_s32) /* PRQA S 2991, 2995 */
                {
                    /* Set Error Msg for Data not received */
                    D_IPC_COLLECT_CMN_ERR(v_errorStatus_u32, D_IPC_CMN_RX_ERR_RPMSGRECV);
                }
            }
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
        }
        else    /* Max read limit reached */
        {
            v_chId_u32++;           /* Start reading from next core */
            v_readCntr_u16 = 0;     /* Reset read counter for next core*/
#endif
        }
    }

    return v_errorStatus_u32;
}

/*
 * Purpose: Sender Function to send data to other core.
 * Description: calling selectDestCore() to select destination core and
 *              send data to other cores
 * Return Type : uint32_t
 * Requirement ID - 13738635, 16670973
*/
uint32_t IPC_F_WrapperSend_u32 (IPCMessage_Params_t *i_IPCMsg_ps)
{
  /* DD-ID: {A01900E7-47F6-4422-92C0-1599A4D72262}*/
    uint32_t v_errorStatus_u32 = D_IPC_NO_ERROR;

#if (D_NUMBER_OF_TX_MESSAGES > 0)
    uint32_t v_tempErrorStatus_u32 = D_IPC_NO_ERROR;
    uint8_t  v_coreSeq_u8 = 0;
    uint8_t  v_data_au8[D_IPC_MAX_MSG_SIZE] = {0};
    uint16_t v_sendDataLen_u16 = 0;
    uint16_t v_numCoreIds_u16 = 0;
    uint16_t v_msgIdTxIdx_u16;
    IpcSmBuff_t v_smBuff_s;

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
    uint32_t v_cddIpcChanId_au32[CDD_IPC_MAX_CHANNEL_CFG] = {D_IPC_U4_MAX,D_IPC_U4_MAX,D_IPC_U4_MAX,D_IPC_U4_MAX,D_IPC_U4_MAX,D_IPC_U4_MAX};
    Std_ReturnType  v_sendErr_s32 = E_OK;
#else
    /* Array to Store Remote Cores and Endpoints */
    uint32_t v_remoteCore_au32[D_NUMBER_OF_CORES] = {0};
    uint32_t v_remoteEndPt_au32[D_NUMBER_OF_CORES] = {0};
    int32_t v_sendErr_s32 = IPC_SOK;
#endif
    uint16_t v_remoteCoreBitMask_u16[D_NUMBER_OF_CORES] = {0};

    if(NULL != i_IPCMsg_ps->IpcMsgData_v)
    {
        /* Get corresponding index of message id in IPC lookup table for Tx*/
        v_msgIdTxIdx_u16 = IPC_f_GetMsgIdTxIdx_u16 (i_IPCMsg_ps->IpcMsgID_u16);

        /* If MsgId found in Tx lookup tables */
        if(v_msgIdTxIdx_u16 < D_NUMBER_OF_TX_MESSAGES)
        {
            /*If intended Tx data size is same as configured in IPC lookup table for Tx attr */
            if(i_IPCMsg_ps->IpcMsgSize_u16 == V_ipcLutAttrTx_as[v_msgIdTxIdx_u16].dataSize_u16)
            {
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
                /* Invoke IPC_f_SelectDestCoreCddChanId_u32 to select Destination Core (REMOTE_CORE) and its EndPoints */
                v_errorStatus_u32 = IPC_f_SelectDestCoreCddChanId_u32(v_msgIdTxIdx_u16, &v_cddIpcChanId_au32[0], &v_remoteCoreBitMask_u16[0], &v_numCoreIds_u16);
#else
                /* Invoke IPC_f_SelectDestCore_u32 to select Destination Core (REMOTE_CORE) and its EndPoints */
                v_errorStatus_u32 = IPC_f_SelectDestCore_u32(v_msgIdTxIdx_u16, &v_remoteCore_au32[0] , &v_remoteEndPt_au32[0], &v_remoteCoreBitMask_u16[0], &v_numCoreIds_u16);
#endif
                /* Check error status of selectDestCore */
                if(D_IPC_NO_ERROR == v_errorStatus_u32)
                {
                    /* Prapare Header for IPC data frame */
                    IPC_f_PrepHeader_v(v_msgIdTxIdx_u16, &v_data_au8[0U], i_IPCMsg_ps);

                    /* If Msg Id is configured as small data in IPC lookup table */
                    if(V_ipcLutAttrTx_as[v_msgIdTxIdx_u16].baseAddr_pu8 == NULL)
                    {
                        /* Small Data -> Prapare Data and Footer for IPC data frame */
                        /* Requirement ID - 16671056 */
                        IPC_f_PrepSmallDataAndFooter_v(&v_data_au8[0U], i_IPCMsg_ps, &v_sendDataLen_u16);
                    }
                    else  /* Large Data */
                    {
                        /* Copy data to shared memory */
                        /* Requirement ID - 16671060 */
                        v_errorStatus_u32 = IPC_f_CopyDataToSm_u32(v_msgIdTxIdx_u16, i_IPCMsg_ps, &v_smBuff_s);
                    }

                    if(D_IPC_NO_ERROR == v_errorStatus_u32)
                    {
                        /* Loop for sending Data to MULTIPLE CORES */
                        for(v_coreSeq_u8 = 0; v_coreSeq_u8 < v_numCoreIds_u16; v_coreSeq_u8++)
                        {
                            /* If Msg Id is configured as large data in IPC lookup table */ 
                            if(V_ipcLutAttrTx_as[v_msgIdTxIdx_u16].baseAddr_pu8 != NULL)
                            {
                                /* Large Data -> Prapare Data and Footer for IPC data frame */
                                v_tempErrorStatus_u32 = IPC_f_PrepLargeDataAndFooter_u32(&v_data_au8[0], 
                                                                                     v_remoteCoreBitMask_u16[v_coreSeq_u8], 
                                                                                     &v_smBuff_s, &v_sendDataLen_u16);
                            }

                            if(D_IPC_NO_ERROR == v_tempErrorStatus_u32)
                            {
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
                                v_sendErr_s32 = Cdd_IpcSendMsg(v_cddIpcChanId_au32[v_coreSeq_u8], &v_data_au8[0U],(uint32_t)v_sendDataLen_u16);
                                if (E_OK != v_sendErr_s32)
#else
                                /* send data to REMOTE_CORES */
                                v_sendErr_s32 = IPC_f_SendData_s32(v_remoteCore_au32[v_coreSeq_u8], v_remoteEndPt_au32[v_coreSeq_u8],
                                                                   &v_data_au8[0U], v_sendDataLen_u16);
                                if (IPC_SOK != v_sendErr_s32)
#endif
                                {
                                    /* Message send failed -> collect error */
                                    D_IPC_COLLECT_TX_ERR(v_errorStatus_u32, D_IPC_TX_ERR_RPMSGSEND, i_IPCMsg_ps->IpcMsgID_u16, NULL);
                                }
                            }
                            else
                            {
                                /* Error while preparing large data and footer -> collect error */
                                D_IPC_COLLECT_TX_ERR(v_errorStatus_u32, v_tempErrorStatus_u32, i_IPCMsg_ps->IpcMsgID_u16, NULL);
                            }
                        }
                    }
                    else
                    {
                        /* Error already set */
                    }
                }
                else
                {
                    /* Error already set by return type of function */
                }
            }
            else
            {
                /* Tx request with invalid data size -> Collect error */
                D_IPC_COLLECT_TX_ERR(v_errorStatus_u32, D_IPC_TX_ERR_RQST_WITH_INV_DATA_SIZE, i_IPCMsg_ps->IpcMsgID_u16, NULL);
            }
        }
        else
        {
            /* Requested message id to transmit not configured in TX LUT -> Collect error */
            D_IPC_COLLECT_CMN_ERR(v_errorStatus_u32, D_IPC_CMN_TX_ERR_LUT_CONF_MSG_NOT_FOUND);
        }
    }
    else
    {
        /* NULL provided as data pointer to tranmit -> COllect error */
        D_IPC_COLLECT_CMN_ERR(v_errorStatus_u32, D_IPC_CMN_TX_ERR_RQST_WITH_INV_DATA_PTR);
    }
#else
    /* Tx LUT is empty */
    /* Requirement ID - 16670991 */
    D_IPC_COLLECT_CMN_ERR(v_errorStatus_u32, D_IPC_CMN_TX_ERR_LUT_CONF_TX_EMPTY);
#endif
    return v_errorStatus_u32;
}

/*
 * Purpose: Receiver Function to receive data from other core.
 * Description: calling RPMessage_recvNb() to receive data coming from other cores .
 * Lookup Table Logic will be added after basic communication test
 * Return Type : void
*/
void IPC_F_IpcManager_v(void)
{
  /* DD-ID: {D164E8BE-1DA3-4250-9C45-6484C29EB38E}*/
    uint32_t errorStatus_u32 = D_IPC_NO_ERROR;
    
    /* Requirement ID - 16670979 */
    errorStatus_u32 = IPC_f_WrapperRcv_u32();
    if(D_IPC_NO_ERROR == errorStatus_u32)
    {
        /* Do nothing */
    }

    IPC_F_UpdateSmBuffState_v();    /* Update use status of shared memory buffer after timeout */

    IPC_F_UpdateDiagInfo_v();       /* Update Diag info */
    
}

#if (D_NUMBER_OF_TX_MESSAGES > 0)
/*
 * Purpose: Prepare Header of IPC data frame.
 * Description: Prepare Header of IPC data frame, This is common function for small and large data.
 * Precondition: i_msgIdIdx_u16 should be valid (Less than max limit)
 * Return Type : void
*/
static void IPC_f_PrepHeader_v(uint16_t i_msgIdIdx_u16, uint8_t *o_Data_pu8, IPCMessage_Params_t *i_IPCMsg_ps)
{
  /* DD-ID: {50E6105D-1676-474b-8967-799F6914914E}*/
    uint32_t v_msgIdcnt_u32;
    uint32_t v_resvData_u32 = 0;

    /* Copy MsgId into Ipc buffer */    
    (void)memcpy(&o_Data_pu8[D_IPC_MSG_ID_IDX],  (uint8_t *)&i_IPCMsg_ps->IpcMsgID_u16, D_IPC_MSG_ID_SIZE);

    /* Copy Header reserved 1 byte into IPC buffer */
    (void)memcpy(&o_Data_pu8[D_IPC_HEADER_RESV_1_IDX],  (uint8_t *)&v_resvData_u32, D_IPC_HEADER_RESV_1_SIZE);

    /* Check if this Msg Id is configured as small data or Large Data in IPC lookup table */
    if(V_ipcLutAttrTx_as[i_msgIdIdx_u16].baseAddr_pu8 == NULL)
    {
        /* Small Data -> Copy Data location (Raw data) into IPC buffer */
        o_Data_pu8[D_IPC_DATA_LOC_IDX] = D_IPC_DATA_LOC_DATA_RAW;
    }
    else
    {
        /* Large Data -> Copy Data location (Data Pointer) into IPC buffer */
        o_Data_pu8[D_IPC_DATA_LOC_IDX] = D_IPC_DATA_LOC_DATA_PTR;
    }

    /* Copy Msg Id counter into IPC buffer */       
    if (V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgIdCntr_pu32 != NULL)
    {
        ++(*V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgIdCntr_pu32);
        v_msgIdcnt_u32 = (*V_ipcLutAttrTx_as[i_msgIdIdx_u16].msgIdCntr_pu32);
    }
    else
    {
        v_msgIdcnt_u32 = 0;
        /*Error -> Wrong configuration*/
    }
    (void)memcpy(&o_Data_pu8[D_IPC_MSG_ID_CNT_IDX], (uint8_t *)&v_msgIdcnt_u32, D_IPC_MSG_ID_CNT_SIZE);
    
    /* Copy data size into IPC buffer */
    (void)memcpy(&o_Data_pu8[D_IPC_DATA_SIZE_IDX], (uint8_t *)&i_IPCMsg_ps->IpcMsgSize_u16, D_IPC_DATA_SIZE_SIZE);

    /* Copy Header reserved 2 byte into IPC buffer */
    (void)memcpy(&o_Data_pu8[D_IPC_HEADER_RESV_2_IDX], (uint8_t *)&v_resvData_u32, D_IPC_HEADER_RESV_2_SIZE);
}


/*
 * Purpose: Prepare Data and Footer of IPC data frame for small data.
 * Description: Prepare Data and Footer of IPC data frame for small data.
 * Return Type : void
*/
static void IPC_f_PrepSmallDataAndFooter_v(uint8_t *o_Data_pu8, const IPCMessage_Params_t *i_IPCMsg_ps, uint16_t *o_DataFrameSize_u16)
{
  /* DD-ID: {82538408-7C7E-4ce7-83B3-B8DF5757A910}*/
    uint8_t  v_crc8_u8;
    uint16_t v_footerIdx_u16;
    uint32_t v_ResvData_u32 = 0;
    uint64_t v_timeStamp_u64;

    /* Copy data into IPC buffer */
    (void)memcpy(&o_Data_pu8[D_IPC_DATA_IDX], &i_IPCMsg_ps->IpcMsgData_v[0], (uint32_t)i_IPCMsg_ps->IpcMsgSize_u16);

    /* Footer start index */
    v_footerIdx_u16 = D_IPC_DATA_HEADER_SIZE + i_IPCMsg_ps->IpcMsgSize_u16;

    /* Copy CRC8 into IPC buffer */
    /* Requirement ID - 16062146 */
    v_crc8_u8 = IPC_F_CalcCrc8_u8(o_Data_pu8, v_footerIdx_u16);
    o_Data_pu8[v_footerIdx_u16 + D_IPC_FOOTER_CRC8_OFFSET] = v_crc8_u8;  /* PRQA S 2985 */

    /* Set reserved byte to 0 into IPC buffer */
    (void)memcpy(&o_Data_pu8[v_footerIdx_u16 + D_IPC_FOOTER_RESV_1_OFFSET], (uint8_t *)&v_ResvData_u32, D_IPC_FOOTER_RESV_1_SIZE);

    /* Copy current timestamp into IPC buffer */
    v_timeStamp_u64 = IPC_F_GetCurrentTimeStamp_u64();
    (void)memcpy(&o_Data_pu8[v_footerIdx_u16 + D_IPC_FOOTER_TIME_OFFSET], (uint8_t *)&v_timeStamp_u64, D_IPC_FOOTER_TIME_SIZE);

    /* Data frame length */
    *o_DataFrameSize_u16 = D_IPC_DATA_HEADER_SIZE + i_IPCMsg_ps->IpcMsgSize_u16 + D_IPC_DATA_FOOTER_SIZE;
}

/*
 * Purpose: Copy data to shared memory.
 * Description: Copy data to shared memory.
 * Precondition: i_msgIdTxIdx_u16 should be valid (Less than max limit)
 * Return Type : uint32_t
*/
static uint32_t IPC_f_CopyDataToSm_u32 (uint16_t i_msgIdTxIdx_u16, const IPCMessage_Params_t *i_IPCMsg_ps, IpcSmBuff_t *i_smBuff_ps)
{
  /* DD-ID: {F3315649-3A82-4b3b-8D6E-891DFBD3469B}*/
    uint32_t v_ret_u32 = D_IPC_NO_ERROR;
    uint32_t v_crc32_u32;
#if defined(BUILD_MPU1_0)
    long_t *i_vAdd_send_pl = NULL;
    long_t *i_pAdd_send_pl = NULL;
    int8_t i_retVal_s8 = 0;
#endif

    /*Get free buffer in shared memory*/
    v_ret_u32 = IPC_F_GetSmBuff_u32(i_msgIdTxIdx_u16, i_smBuff_ps);

    if (D_IPC_NO_ERROR == v_ret_u32)
    {
        if (i_smBuff_ps->addr_pv != NULL)
        {
            /* Calculate CRC32 of shared memory data */
            /* Requirement ID - 16671766 */
            v_crc32_u32 = IPC_F_CalcCrc32_u32(&i_IPCMsg_ps->IpcMsgData_v[0], i_IPCMsg_ps->IpcMsgSize_u16);

#if defined(BUILD_MPU1_0)
            /* Write data to shared memory buffer */
            memcpy(&i_pAdd_send_pl, &i_smBuff_ps->addr_pv, sizeof(uint32_t));
            
            i_retVal_s8 = IPC_f_GetVirAddr_s8((long_t) i_pAdd_send_pl,i_IPCMsg_ps->IpcMsgSize_u16,(void**)&i_vAdd_send_pl);
            if(i_retVal_s8 != -1)
            {
                memcpy(((uint8_t *)i_vAdd_send_pl), i_IPCMsg_ps->IpcMsgData_v, i_IPCMsg_ps->IpcMsgSize_u16);

                i_retVal_s8 = IPC_f_ClearVirAddr_s8(i_vAdd_send_pl,i_IPCMsg_ps->IpcMsgSize_u16);
                
                if(i_retVal_s8 == -1)
                {
                    /* unmap virtual address failed -> Collect error */
                    D_IPC_COLLECT_TX_ERR(v_ret_u32, D_IPC_TX_ERR_UNMAP_VIR_MEM_ADDR, V_ipcLutAttrTx_as[i_msgIdTxIdx_u16].msgId_u16, NULL);
                }

                /*Write CRC32 to shared memory buffer*/
                i_pAdd_send_pl = (long_t *) ((uint8_t *)i_smBuff_ps->addr_pv + V_ipcLutAttrTx_as[i_msgIdTxIdx_u16].dataSize_u16);
                i_retVal_s8 = IPC_f_GetVirAddr_s8((long_t)i_pAdd_send_pl,i_IPCMsg_ps->IpcMsgSize_u16,(void**)&i_vAdd_send_pl);
            
                if( i_retVal_s8 != -1)
                {
                    /* Write CRC32 to shared memory buffer */
                    memcpy(((uint8_t *)i_vAdd_send_pl ), &v_crc32_u32, D_CRC32_SIZE);

                    i_retVal_s8 = IPC_f_ClearVirAddr_s8(i_vAdd_send_pl,i_IPCMsg_ps->IpcMsgSize_u16);
                
                    if(i_retVal_s8 == -1)
                    {
                        /* unmap virtual address failed -> Collect error */
                        D_IPC_COLLECT_TX_ERR(v_ret_u32, D_IPC_TX_ERR_UNMAP_VIR_MEM_ADDR, V_ipcLutAttrTx_as[i_msgIdTxIdx_u16].msgId_u16, NULL);
                    }
                }
                else
                {
                    /* Get virtual address failed -> Collect error */
                    D_IPC_COLLECT_TX_ERR(v_ret_u32, D_IPC_TX_ERR_INVALID_VIR_MEM_ADDR, V_ipcLutAttrTx_as[i_msgIdTxIdx_u16].msgId_u16, NULL);
                }
            }
            else
            {
                /* Get virtual address failed -> Collect error */
                D_IPC_COLLECT_TX_ERR(v_ret_u32, D_IPC_TX_ERR_INVALID_VIR_MEM_ADDR, V_ipcLutAttrTx_as[i_msgIdTxIdx_u16].msgId_u16, NULL);
            }
#else
            /*Write data to shared memory buffer*/
            (void)memcpy(((uint8_t *)i_smBuff_ps->addr_pv), &i_IPCMsg_ps->IpcMsgData_v[0], (uint32_t)i_IPCMsg_ps->IpcMsgSize_u16);

#if defined(BUILD_MCU1_0)
            /* Write back cache (Work around for shared memory curruption issue (Defect id 16751023))*/
            CSL_armR5CacheWb((void *)i_smBuff_ps->addr_pv, (int32_t)i_IPCMsg_ps->IpcMsgSize_u16, (bool)TRUE);
#endif
            /*Write CRC32 to shared memory buffer*/
            (void)memcpy((uint8_t *)((uint8_t *)(i_smBuff_ps->addr_pv) + V_ipcLutAttrTx_as[i_msgIdTxIdx_u16].dataSize_u16 ), (uint8_t *)&v_crc32_u32, D_CRC32_SIZE);
#if defined(BUILD_MCU1_0)
            /* Write back cache (Work around for shared memory curruption issue (Defect id 16751023))*/
            CSL_armR5CacheWb((void *)((uint8_t *)(i_smBuff_ps->addr_pv) + V_ipcLutAttrTx_as[i_msgIdTxIdx_u16].dataSize_u16 ), (int32_t)D_CRC32_SIZE, (bool)TRUE);
#endif
#endif
        }
        else
        {
            /*No buffer free in shared memory -> Collect error */
            D_IPC_COLLECT_TX_ERR(v_ret_u32, D_IPC_TX_ERR_INVALID_SH_MEM_ADDR, V_ipcLutAttrTx_as[i_msgIdTxIdx_u16].msgId_u16, NULL);
        }
    }
    else
    {
        /* Error already set */
    }

    return v_ret_u32;
}

/*
 * Purpose: Prepare Data and Footer of IPC data frame for Large data.
 * Description: Copy large data to shared memory and Prepare Data and Footer of IPC data frame.
 * Return Type : uint32_t
*/
static uint32_t IPC_f_PrepLargeDataAndFooter_u32 (uint8_t       *o_Data_pu8,
                                                uint16_t      i_dstCoreBitMask_u16,
                                                IpcSmBuff_t   *i_smBuff_ps,
                                                uint16_t      *o_DataFrameSize_u16)
{
    /* DD-ID: {110C519D-6E22-4d58-AC58-1983F6EBBB19}*/
    uint32_t v_ret_u32 = D_IPC_NO_ERROR;
    uint32_t v_ResvData_u32 = 0;
    uint8_t  v_crc8_u8;
    uint64_t v_timeStamp_u64;

    if (i_smBuff_ps->addr_pv != NULL)
    {
        /* Get dst core bit mask */
        i_smBuff_ps->dstCoreBitMask_u16 = i_dstCoreBitMask_u16;

        /* Copy shared memory buffer information (Data of IPC dataframe) to IPC data frame */
        (void)memcpy(&o_Data_pu8[D_IPC_DATA_IDX],(uint8_t *)i_smBuff_ps, sizeof(IpcSmBuff_t));

        /* Start preparing footer */ 
        /* Copy CRC8 into IPC buffer */
        /* Requirement ID - 16062146 */
        v_crc8_u8 = IPC_F_CalcCrc8_u8(o_Data_pu8, D_IPC_LARGE_DATA_FOOTER_IDX);
        o_Data_pu8[D_IPC_LARGE_DATA_FOOTER_IDX + D_IPC_FOOTER_CRC8_OFFSET] = v_crc8_u8;

        /* Set reserved byte to 0 into IPC buffer */
        (void)memcpy(&o_Data_pu8[D_IPC_LARGE_DATA_FOOTER_IDX + D_IPC_FOOTER_RESV_1_OFFSET], (uint8_t *)&v_ResvData_u32, D_IPC_FOOTER_RESV_1_SIZE); 

        /* Copy current timestamp into IPC buffer */
        v_timeStamp_u64 = IPC_F_GetCurrentTimeStamp_u64();
        (void)memcpy(&o_Data_pu8[D_IPC_LARGE_DATA_FOOTER_IDX + D_IPC_FOOTER_TIME_OFFSET],  (uint8_t *)&v_timeStamp_u64, D_IPC_FOOTER_TIME_SIZE);
    
        /* Data frame length */
        *o_DataFrameSize_u16 = D_IPC_DATA_HEADER_SIZE + D_IPC_DATA_PTR_INFO_SIZE + D_IPC_DATA_FOOTER_SIZE;
    }
    else
    {
        /*No buffer free in shared memory*/
        v_ret_u32 = D_IPC_TX_ERR_INVALID_SH_MEM_ADDR;
    }

    return v_ret_u32;
}


/*
 * Purpose: Get index of corresponding msg Id in IPC look table for Tx attr.
 * Description: Parse V_ipcLutAttrTx_as[] lookup table and find index of correspoding message id.
 * Return Type : uint16_t (If Msg Id found: MsgId Index, If Msg Id not found: D_NUMBER_OF_TX_MESSAGES)
*/
static uint16_t IPC_f_GetMsgIdTxIdx_u16 (uint16_t i_msgId_u16)
{
  /* DD-ID: {99D931EF-CEF2-40dc-9915-E05760C4EC8F}*/
    uint16_t v_msgIdIdx_u16 = 0;

    /* Find corresponding index of message id in IPC lookup table for Tx attr */
    for (v_msgIdIdx_u16 = 0; v_msgIdIdx_u16 < D_NUMBER_OF_TX_MESSAGES; v_msgIdIdx_u16++)
    {
        if(i_msgId_u16 == V_ipcLutAttrTx_as[v_msgIdIdx_u16].msgId_u16)
        {
            /* MsgId found in lookup table*/
            break;
        }
    }

    return v_msgIdIdx_u16;
}
#endif

#if ((D_NUMBER_OF_TX_MESSAGES > 0) || (D_NUMBER_OF_RX_MESSAGES > 0))
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
#else
/*
 * Purpose: Send Data to remote core.
 * Description: Send Data to remote core, Use only in core MCU2_1 and MCU3_0.
 * Return Type : uint32_t
*/
static int32_t IPC_f_SendData_s32  (uint32_t i_RemoteProc_u32,
                                    uint32_t i_RemoteEp_u32,
                                    uint8_t  *i_data_pu8,
                                    uint16_t i_dataSize_u16)
{
    /* DD-ID: {F69C7E03-C0B5-409b-9997-487DF24ADCF3}*/
    int32_t v_sendRtnVal_s32 = IPC_SOK;

    /* Invoke RPMessage_send to send data to REMOTE_CORES */
    if(i_RemoteProc_u32 == IPC_MCU1_0 || i_RemoteProc_u32 == IPC_MCU3_1)
    {
        /* Requirement ID - 16667424 */
        v_sendRtnVal_s32 = RPMessage_send(s_IpcCommChHndl_s, i_RemoteProc_u32, s_IpcLocalEp_u32,
                                   s_IpcLocalEp_u32, (Ptr)i_data_pu8, i_dataSize_u16);
    }
    else
    {
        /* Requirement ID - 16667424 */
        v_sendRtnVal_s32 = RPMessage_send(s_IpcCommChHndl_s, i_RemoteProc_u32, i_RemoteEp_u32,
                                   s_IpcLocalEp_u32, (Ptr)i_data_pu8, i_dataSize_u16);
    }

    return v_sendRtnVal_s32;
}
#endif
#endif
/*
 * Purpose: Retrieve Message ID from received data over IPC.
 * Description: Retrieve Message ID from received data over IPC.
 * Return Type : uint16_t
*/
static uint16_t IPC_f_GetMsgId_u16 (const uint8_t *i_DataRcv_pu8)
{
  /* DD-ID: {3A4C2CC3-D83B-43c9-9613-D015946BB461}*/
    uint16_t v_msgId_u16 = 0;

    /* Copy MSB of MessageID */
    v_msgId_u16 = i_DataRcv_pu8[ D_IPC_MSG_ID_IDX + 1 ];

    v_msgId_u16 <<= 8;

    /* Copy LSB of MessageID */
    v_msgId_u16 |= (uint8_t) i_DataRcv_pu8[ D_IPC_MSG_ID_IDX ];

    return v_msgId_u16;

}

#if (D_NUMBER_OF_RX_MESSAGES > 0)
/*
 * Purpose: Get index of corresponding msg Id in IPC look table for Rx attr.
 * Description: Parse V_ipcLutAttrRx_as[] lookup table and find index of correspoding message id.
 * Return Type : uint16_t (If Msg Id found: MsgId Index, If Msg Id not found: D_NUMBER_OF_RX_MESSAGES)
*/
static uint16_t IPC_f_GetMsgIdRxIdx_u16 (uint16_t i_msgId_u16)
{
  /* DD-ID: {83D5690D-4D81-4f85-9EA4-6B70A1F8BE8F}*/
    uint16_t v_msgIdIdx_u16 = 0;

    /* Find corresponding index of message id in IPC msg counter lookup table*/
    for (v_msgIdIdx_u16 = 0; v_msgIdIdx_u16 < D_NUMBER_OF_RX_MESSAGES; v_msgIdIdx_u16++)
    {
        if(i_msgId_u16 == V_ipcLutAttrRx_as[v_msgIdIdx_u16].msgId_u16)
        {
            /* MsgId found in lookup table*/
            break;
        }
    }
    return v_msgIdIdx_u16;
}

/*
 * Purpose: Retrieve Data size from received data over IPC.
 * Description: Retrieve Data size from received data over IPC.
 * Return Type : uint16_t
*/
static uint16_t IPC_f_GetRcvdDataSize_u16 (const uint8_t *i_DataRcv_pu8)
{
  /* DD-ID: {DD04B358-F4A3-4b31-ACF8-96DD97CAC802}*/
    uint16_t v_DataSize_u16 = 0;

    if(NULL != i_DataRcv_pu8)
    {
        /* Copy Data size */
        (void)memcpy((uint8_t *)&v_DataSize_u16, &i_DataRcv_pu8[D_IPC_DATA_SIZE_IDX], D_IPC_DATA_SIZE_SIZE);
    }
    return v_DataSize_u16;
}

/*
 * Purpose: Process callback function of corresponding MsgId on data reception.
 * Description: Process Callback func of corresponding MsgId on data reception to provide data to signal handler / RTE.
 * Precondition: v_msgIdRxIdx_u16 should be valid (Less than max limit)
 * Return Type : void
*/
static void IPC_f_ProcessCallback_v (uint16_t v_msgIdRxIdx_u16, void *i_IpcRcvdData_pv, uint8_t i_DataLoc)
{
   /* DD-ID: {9A5F0BD6-FB0F-48d5-83E4-5E11CED7C7A1}*/
#if defined (BUILD_MPU1_0)
    long_t *i_virAdd_pl = NULL;
    long_t *i_phyAdd_pl = NULL;
    int8_t i_retVal_s8 = 0;
#endif
    (void)i_DataLoc;
    /* If callback function pointer is not NULL */
    if (V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].ipc_callback_func != NULL)
    {
#if defined(BUILD_MPU1_0)
        /* Check if data size is small (Raw data) or large(Data pointer) */
        if(D_IPC_DATA_LOC_DATA_RAW == i_DataLoc)
        {
            /* Call callback function */
            /* Requirement ID - 16671056 */
            V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].ipc_callback_func(i_IpcRcvdData_pv);
        }
        else  /* D_IPC_DATA_LOC_DATA_PTR */
        {
            /* Requirement ID - 16671060 */
            memcpy(&i_phyAdd_pl, &i_IpcRcvdData_pv, sizeof(uint32_t));

            i_retVal_s8 = IPC_f_GetVirAddr_s8((long_t) i_phyAdd_pl,V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].dataSize_u16,(void**)&i_virAdd_pl);
            if( i_retVal_s8 != -1)
            {
                /* Call callback function */
                V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].ipc_callback_func(i_virAdd_pl);


                i_retVal_s8 = IPC_f_ClearVirAddr_s8(i_virAdd_pl,V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].dataSize_u16);

                if(i_retVal_s8 == -1)
                {
                    /* unmap virtual address failed -> Collect error */
                    IPC_F_CollectRxErr_v(D_IPC_RX_ERR_UNMAP_VIR_MEM_ADDR, V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].msgId_u16, NULL);
                }
            }
            else
            {
                /* Get virtual address failed -> Collect error */
                IPC_F_CollectRxErr_v(D_IPC_RX_ERR_INVALID_VIR_MEM_ADDR, V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].msgId_u16, NULL);
            }
        }
#else
        /* Call callback function */
        V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].ipc_callback_func(i_IpcRcvdData_pv);
#endif
    }
    else
    {
        /* No callback configured for received message Id -> Collect error */
        IPC_F_CollectRxErr_v(D_IPC_RX_ERR_LUT_CONF_NO_CALLBACK, V_ipcLutAttrRx_as[v_msgIdRxIdx_u16].msgId_u16, NULL);
    }
}

/*
 * Purpose: Validate counter of received message id.
 * Description: Validate counter of received message id to check if any message missed.
 * Precondition: i_msgIdRxIdx_u16 should be valid (Less than max limit)
 * Return Type : void
*/
static void IPC_f_ValidateMsgIdCnt_v (uint16_t i_msgIdRxIdx_u16, const uint8_t *i_DataRcv_pu8)
{
    /* DD-ID: {71D71923-3DD9-4311-BFCF-95EA6DC7C280}*/
    uint32_t               v_msgIdcnt_u32;
    uint32_t               v_missedcnt_u32;
    ipcRxErrMonMissedMsg_t v_msdMsgInfo_s;

    if ((V_ipcLutAttrRx_as[i_msgIdRxIdx_u16].msgIdCntrPrev_pu32 != NULL) &&
        (i_DataRcv_pu8 != NULL)
        )
    {
        /* Extract Msg id counter from received data */
        (void)memcpy((uint8_t *)&v_msgIdcnt_u32, &i_DataRcv_pu8[D_IPC_MSG_ID_CNT_IDX], D_IPC_MSG_ID_CNT_SIZE);

        /* Validate if received message id counter is 1 more than last received message id counter */
        if (*V_ipcLutAttrRx_as[i_msgIdRxIdx_u16].msgIdCntrPrev_pu32 == D_IPC_U4_MAX)             /* Counter roll over */
        {
            if (v_msgIdcnt_u32 != 0)
            {
                /* Missed previous message */
                /* Set error to RX_ERR_MISSED_PREV_MSG */

                /* Number of messages missed */
                if(v_msgIdcnt_u32 > D_IPC_U2_MAX)  /* More than 0xFFFF msg missed */
                {
                    v_msdMsgInfo_s.msgCnt_u16 = D_IPC_U2_MAX;
                }
                else
                {
                    v_msdMsgInfo_s.msgCnt_u16 =(uint16_t) v_msgIdcnt_u32;
                }
                /* Missed first msg counter */
                v_msdMsgInfo_s.startMsgCntr_u32 = 0; 

                /* Collect error */
                IPC_F_CollectRxErr_v(D_IPC_RX_ERR_MISSED_PREV_MSG, 
                                     V_ipcLutAttrRx_as[i_msgIdRxIdx_u16].msgId_u16, (void *)&v_msdMsgInfo_s);

            }
        }
        else if (*V_ipcLutAttrRx_as[i_msgIdRxIdx_u16].msgIdCntrPrev_pu32 + 1 != v_msgIdcnt_u32) /* Counter not Rolled over */
        {
            /* Missed previous message */
            /* Set error to RX_ERR_MISSED_PREV_MSG */
            /* Number of messages missed */
            v_missedcnt_u32 = v_msgIdcnt_u32 - (*V_ipcLutAttrRx_as[i_msgIdRxIdx_u16].msgIdCntrPrev_pu32) - 1;
            if(v_missedcnt_u32 > D_IPC_U2_MAX)   /* More than 0xFFFF msg missed */
            {
                v_msdMsgInfo_s.msgCnt_u16 = D_IPC_U2_MAX;
            }
            else
            {
                v_msdMsgInfo_s.msgCnt_u16 = (uint16_t)v_missedcnt_u32;
            }
            /* Missed first msg counter */
            v_msdMsgInfo_s.startMsgCntr_u32 = (*V_ipcLutAttrRx_as[i_msgIdRxIdx_u16].msgIdCntrPrev_pu32) + 1; 

            /* Collect error */
            IPC_F_CollectRxErr_v(D_IPC_RX_ERR_MISSED_PREV_MSG, 
                                 V_ipcLutAttrRx_as[i_msgIdRxIdx_u16].msgId_u16, (void *)&v_msdMsgInfo_s);
        }
        else
        {
        	/* Do Nothing */
        }

        /* Update message id couter to recevied message id counter*/
        *V_ipcLutAttrRx_as[i_msgIdRxIdx_u16].msgIdCntrPrev_pu32 = v_msgIdcnt_u32;
    }
}

#endif
/*===============================End Of File========================================================*/
