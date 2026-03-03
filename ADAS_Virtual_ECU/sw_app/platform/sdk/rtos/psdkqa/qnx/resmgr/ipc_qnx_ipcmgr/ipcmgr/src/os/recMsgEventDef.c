/**
 * @file recMsgEventDef.c
 * @brief Main header file to handle multiple data and share data across IPC A72 to PUC
 *
 * @details This file contains brigde global data type which will be used by IPC manager
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2021. Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status. Magna Electronics
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
 * @author ---- (---- @magna.com)
 */

/* ===========================================================================
 *
 *   Fisker_L2H5010_IPC_SignalDef.xlsm Version
 *
 * ======================================================================== */
/*
 * Excel file Version:  36.0
 * Excel file Mod Date: 2022-09-06 00:00:00
 * Generated on:        2022-09-15 18:47:15
 */

/* ===========================================================================
 *
 *   Include Files
 *
 * ======================================================================== */
#include "recMsgEventDef.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */


/* ===========================================================================
 *
 *   Function Prototypes
 *
 * ========================================================================= */
static uint16_t IPC_f_GetMsgIdRxIdx_u16 (uint16_t i_msgId_u16);
static void IPC_f_InitRxVarBuf_v(void) ;
static uint8_t IPC_f_ClearBuf_v(uint16_t o_dataIdx_u16);
static void IPC_f_AddMsgIDFooter_v(uint16_t o_msgID_u16, uint16_t o_msgIDX_u16);
static uint16_t IPC_f_SmallestMsgCntrIdxToFetch_u16(void);

/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */
/* Initialize Object of each Rx Massages */

uint8_t rxBuf_SvsToTHADet                               [sizeof(SvsToTHADet_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_ScreenRequest                             [sizeof(ScreenRequest_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_ME_VehInpo_IpcSignals_f                   [sizeof(ME_VehInp_to_IpcSignals_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_Detection_Inputs_fromRSC                  [sizeof(TRSC_Inputs_from_TrailerDetection_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_PpSR_State_MCU2_State_2_0                 [sizeof(SSM_2_0_CoreStatus)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_PpSR_State_MCU2_State_2_1                 [sizeof(SSM_2_1_CoreStatus)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_SSM_SystemState                           [sizeof(SSM_SystemState)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_CalDataProvider_MPU_1_0_Def               [sizeof(CalDataProvider_MPU_1_0_Def)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_FunctionalSettingsNVMToSVSCalibSM_t       [sizeof(TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_TbSVS_e_DiagMgrOutputToSVSCamCalibSM      [sizeof(TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_PpFeatureOutputsTHAbTHASmVc_FeatureOutputs[sizeof(TbTHASmVc_FeatureOutputs_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_IFPAInfoToPLD                             [sizeof(IFPAInfoToPLD_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_IKinematict                               [sizeof(IKinematicData_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_TbAP_DriveAssistStatOut_t                 [sizeof(TbAP_DriveAssistStatOut_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_FID_STRUCT_QM            					[sizeof(FID_STRUCT_QM)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_FID_STRUCT_B                 	            [sizeof(FID_STRUCT_B)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_PpUSS_BlockageBit_US_S_BlockageBit        [sizeof(US_S_BlockageBit_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_PpUSSErrorDiagUS_S_USSErrorDiagt          [sizeof(US_S_USSErrorDiagData_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_THARelated_ScreenReq                      [sizeof(THARelated_ScreenReq_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_ME_ProxiToMPU1_0_Def_t                    [sizeof(ME_ProxiToMPU1_0_Def_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_TRSCDebug_ScrReq_t                 		[sizeof(TRSCDebug_ScrReq_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_ME_CanDebugRIDStatus_t                 	[sizeof(ME_CanDebugRIDStatus_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_THA_Calibration_data_MPU1_0_t             [sizeof(THA_Calibration_data_MPU1_0_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_APA_Calibration_data_MPU1_0_t             [sizeof(APA_Calibration_data_MPU1_0_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_LMD_Calibration_data_t                	[sizeof(LMD_Calibration_data_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_TRSC_Calibration_data_MPU1_0_t            [sizeof(TRSC_Calibration_data_MPU1_0_t)+D_EXTRA_MSG_LEN];

uint8_t rxBuf_TRSC_CalibrationClear_t                   [sizeof(TRSC_CalibrationClear_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_PerformanceStatsEnable_t                  [sizeof(PerformanceStatsEnable_t)+D_EXTRA_MSG_LEN];
uint8_t rxBuf_CamHotplugStatus_t                        [sizeof(CamHotplugStatus_t)+D_EXTRA_MSG_LEN];
/* ===========================================================================
*
* Private variables
*
* ========================================================================= */

static uint8_t v_flagToEnqueue_u8 = 0U; 
/*Local Buffer & global Variables to store data locally */
uint32_t v_recMsgDataPtr_au32[D_NUMBER_OF_RX_MESSAGES];
recMsgEvent_t msgEventQueue[D_NUMBER_OF_RX_MESSAGES];
static uint32_t v_msgCntr_u32 = 0U; 
pthread_mutex_t eventQueueChangeMutex = PTHREAD_MUTEX_INITIALIZER; 

/* ===========================================================================
 *
 *   Global Data Types
 *
 * ======================================================================== */


/* ===========================================================================
*
*   Private functions definition
*
* ========================================================================= */


/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Initialize all global variables accessed by pointer in recMsgEventDef.
 * Description: IPC manager will call this function to initiaize all global variable used
 *              by recMsgEventDef
 * Return Type : void
*/
static void IPC_f_InitRxVarBuf_v(void) 
{ 
	uint32_t i=0;
    pthread_mutex_lock(&eventQueueChangeMutex); 
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_SvsToTHADet                               [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_ScreenRequest                             [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_ME_VehInpo_IpcSignals_f                   [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_Detection_Inputs_fromRSC                  [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_PpSR_State_MCU2_State_2_0                 [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_PpSR_State_MCU2_State_2_1                 [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_SSM_SystemState                           [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_CalDataProvider_MPU_1_0_Def               [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_FunctionalSettingsNVMToSVSCalibSM_t       [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_TbSVS_e_DiagMgrOutputToSVSCamCalibSM      [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8  = &rxBuf_PpFeatureOutputsTHAbTHASmVc_FeatureOutputs[0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_IFPAInfoToPLD                             [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_IKinematict                               [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_TbAP_DriveAssistStatOut_t                 [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_FID_STRUCT_QM            				    [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_FID_STRUCT_B                              [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_PpUSS_BlockageBit_US_S_BlockageBit        [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_PpUSSErrorDiagUS_S_USSErrorDiagt          [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_THARelated_ScreenReq                      [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_ME_ProxiToMPU1_0_Def_t                    [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_TRSCDebug_ScrReq_t                        [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_ME_CanDebugRIDStatus_t                    [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_THA_Calibration_data_MPU1_0_t             [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_APA_Calibration_data_MPU1_0_t             [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_LMD_Calibration_data_t                    [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_TRSC_Calibration_data_MPU1_0_t            [0];

    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_TRSC_CalibrationClear_t                   [0];
	msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_PerformanceStatsEnable_t                      [0];
    msgEventQueue[i++].v_StoredData_s.recBufPtr_pu8 =  &rxBuf_CamHotplugStatus_t                      [0];
    pthread_mutex_unlock(&eventQueueChangeMutex);
}

/*
 * Purpose: Get index of corresponding msg Id in IPC look table for Rx attr. 
 * Description: Parse V_ipcLutAttrRx_as[] lookup table and find index of correspoding message id. 
 * Return Type : uint16_t (If Msg Id found: MsgId Index, If Msg Id not found: D_NUMBER_OF_RX_MESSAGES) 
*/
static uint16_t IPC_f_GetMsgIdRxIdx_u16 (uint16_t i_msgId_u16)
{
    uint16_t v_msgIdIdx_u16 = 0U;

    /* Find corresponding index of message id in IPC msg counter lookup table*/
    for (v_msgIdIdx_u16 = 0U; v_msgIdIdx_u16 < D_NUMBER_OF_RX_MESSAGES; v_msgIdIdx_u16++)
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
 * Purpose: IPC manager Queue initializing
 * Description: To initialize all Receiver Buffers and allocate them proper size,
 *              and default values of MSGId, DataSize, etc.
 * Return Type : uint8_t
*/
uint8_t IPC_F_initializeEventQueue_v(void)
{
    uint8_t v_retVal_u8 = 0U;
    uint8_t v_InitIdx_u8 = 0U;

    /* Initialize Mutex */
    pthread_mutex_init(&eventQueueChangeMutex, NULL);
 
    /* Initialize Rx Buffer */
    IPC_f_InitRxVarBuf_v();

    for (v_InitIdx_u8 = 0U; v_InitIdx_u8 < D_EVENT_QUEUE_SIZE; ++v_InitIdx_u8)
    {
        /* Initialize recBuf , MsgID, MsgLen with Default Values */
        if (TRUE == IPC_f_ClearBuf_v(v_InitIdx_u8))
        {
            v_retVal_u8 = 1U;
        }
        else
        {
            /* Initialize recvdMsgPtr & eventFlag with default 0 value */
            pthread_mutex_lock(&eventQueueChangeMutex);
            msgEventQueue[v_InitIdx_u8].recvdMsgPtr = 0U;
            msgEventQueue[v_InitIdx_u8].eventFlag_u8 = 0U;
            pthread_mutex_unlock(&eventQueueChangeMutex);
        }
    }
    return v_retVal_u8;
}

/*
 * Purpose: To Store Data Received from all other cores.
 * Description: To store Received data Buffers as per msgID.
* Return Type : bool_t
*/
bool_t IPC_F_addEvent_b (uint8_t *o_event_ps, uint16_t o_msgID_u16)
{
    bool_t v_retValue_b = FALSE;
    recMsgEvent_t *v_EnqueueEvent_ps = NULL;
    uint16_t v_MsgIdx_u16 = 0U, v_dataLen_u16 = 0;

    /* Check if Data is proper or not */
    if(o_event_ps == NULL)
    { 
        /* Error Condition */ 
        v_retValue_b = TRUE;
    }
    else if((o_msgID_u16 < D_ERR_MSGID) || (o_msgID_u16 > e_IpcMsgId_MAX_COUNT))
    {
        /* Error Condition */ 
        v_retValue_b = TRUE;
    }
    else
    {
        if((o_msgID_u16 > e_IpcMsgId_data_UnknownMsg_t) && (o_msgID_u16 <= e_IpcMsgId_MAX_COUNT))
        {
            /* Lock Mutex to Update Data */
            pthread_mutex_lock(&eventQueueChangeMutex);
            v_flagToEnqueue_u8 = TRUE;
            pthread_mutex_unlock(&eventQueueChangeMutex);
        }
    
        /* Check for the filtered Message Received Flag is Set or not */
        if(v_flagToEnqueue_u8 == TRUE)
        {
            /* Get Index of Rx Buffer to Store Incomming Data to Rx Buffers */
            v_MsgIdx_u16 = IPC_f_GetMsgIdRxIdx_u16(o_msgID_u16);

            /* Check the collected MsgIdx is within the proper range or not */ 
            if(D_NUMBER_OF_RX_MESSAGES > v_MsgIdx_u16)
            {
                /* Get Data Size from Configuration */ 
                v_dataLen_u16 =  V_ipcLutAttrRx_as[v_MsgIdx_u16].dataSize_u16; 
                /* Lock Mutex to Update Data */
                pthread_mutex_lock(&eventQueueChangeMutex);

                v_EnqueueEvent_ps = &msgEventQueue[v_MsgIdx_u16];
                /* Increase the msgCntr, inorder to notify incomming Data */
                ++v_msgCntr_u32;
                /* Change eventFlag to respective index as per Incomming MSGID with D_READ */ 
                v_EnqueueEvent_ps->eventFlag_u8 = D_READ;
                /* OverWrite current msgCntr to recvdMsgPtr with respect to Index and MSGID */
                v_EnqueueEvent_ps->recvdMsgPtr = v_msgCntr_u32;
                /* Unlock Mutex to share with other resource */ 
                pthread_mutex_unlock(&eventQueueChangeMutex); 
                /* Copy MsgId and Size to RX Buffer */
                IPC_f_AddMsgIDFooter_v(o_msgID_u16, v_MsgIdx_u16);
                /* Lock Mutex to Update Data */
                pthread_mutex_lock(&eventQueueChangeMutex);
                /* Copy the Incomming Data to Rx Buffers MSGId Wise */
                memcpy(&v_EnqueueEvent_ps->v_StoredData_s.recBufPtr_pu8[2U],o_event_ps,v_dataLen_u16);

#if defined(DEBUG_MSG)
                printf("\n ********************** recMsgEventDef.c :: IPC_F_addEvent_b() : ID : %u ! \
                *************\n",v_EnqueueEvent_ps->v_StoredData_s.MsgID);
#endif
                /* Unlock Mutex to share with other resource */ 
                pthread_mutex_unlock(&eventQueueChangeMutex);
            }
            else
            {
                /* Error Condition */ 
                v_retValue_b = TRUE;
#if defined(DEBUG_MSG)
                printf("\n ********************** recMsgEventDef.c :: IPC_F_addEvent_b() : ID : %u ! \
                *************\n",v_EnqueueEvent_ps->v_StoredData_s.MsgID);
#endif
            }
        }
        else
        {

        }
    }
    return v_retValue_b;
}

/*
* Purpose: To Add MsgID at starting bytes of Rx Buffers & Update size of MsgLen.
* Description: To Add MsgID at starting bytes of Rx Buffers & Update size of MsgLen
*              this will required for PUC to extract data likewise.
* Return Type : void 
*/
static void IPC_f_AddMsgIDFooter_v(uint16_t o_msgID_u16, uint16_t o_msgIDX_u16)
{
    uint8_t v_0_u8 = 0, v_1_u8 = 0;
    if(o_msgID_u16 > D_ERR_MSGID && o_msgID_u16 < e_IpcMsgId_MAX_COUNT)
    {
        /* Lock Mutex to Update Data */ 
        pthread_mutex_lock(&eventQueueChangeMutex);

        /* Take MsgId into two differant bytes (MSB & LSB) to store it with Data */
        v_0_u8 = (uint8_t)(o_msgID_u16      & 0xFF);
        v_1_u8 = (uint8_t)((o_msgID_u16 >> 8) & 0xFF);

        /* Copy LSB of MSGID into 0th Index of DataBuffer */
        msgEventQueue[o_msgIDX_u16].v_StoredData_s.recBufPtr_pu8[D_IPC_MSG_ID_IDX] = v_1_u8;
        
        /* Copy MSB of MSGID into 1th Index of DataBuffer */
        msgEventQueue[o_msgIDX_u16].v_StoredData_s.recBufPtr_pu8[D_IPC_MSG_ID_IDX + 1] = v_0_u8;

        /* Copy received MsgId with respect to Queue with respect to Index */
        msgEventQueue[o_msgIDX_u16].v_StoredData_s.MsgID = o_msgID_u16;

        /* Copy received MsgSize + PUC Required 2 Bytes to Queue with respect to Index */
        msgEventQueue[o_msgIDX_u16].v_StoredData_s.MsgLen = D_EXTRA_MSG_LEN + V_ipcLutAttrRx_as[o_msgIDX_u16].dataSize_u16;
        
        /* Unlock Mutex to share with other resource */ 
        pthread_mutex_unlock(&eventQueueChangeMutex);
    }
}

/*
 * Purpose: To Take Data from preallocated Receiver Buffers and share it with PUC.
 * Description: To extract data from ReceiverBuffers as per msgID and Size and 
 *              share that data with PUC.
 * Return Type : bool_t
*/
bool_t IPC_F_getEvent_b(void *o_event_ps, uint16_t *o_msgID_u16, uint16_t *o_dataSize_u16)
{
    bool_t v_retValue_b = FALSE;
    recMsgEvent_t *v_dequeueEvent_ps = NULL;
    uint32_t v_SmallestMsgCntrIdx_u32 = 0U;

    /* Check the event buffer is proper or not */
    if (o_event_ps == NULL)
    {
        /* Error Condition */ 
        v_retValue_b = TRUE;
    }
    else
    {
        /* Calculate the Smallest MsgCntr Index to Collect Next received Data */
        v_SmallestMsgCntrIdx_u32 = IPC_f_SmallestMsgCntrIdxToFetch_u16();

        /* Check Collected Index is within proper range or not! */ 
        if(v_SmallestMsgCntrIdx_u32 >= D_NUMBER_OF_RX_MESSAGES)
        {
            /* Error Condition */ 
            v_retValue_b = TRUE;
        }
        else
        {
             /* Lock Mutex to Update/Extract Shared Data */ 
             pthread_mutex_lock(&eventQueueChangeMutex);

             v_dequeueEvent_ps = &msgEventQueue[v_SmallestMsgCntrIdx_u32];
             /* Check address get with respect to Index is NULL or Not! */
             if(v_dequeueEvent_ps != NULL)
             {
                 /* Copy Data From Rx Buffers to eventBuffer */
                 memcpy((uint8_t *) o_event_ps, v_dequeueEvent_ps->v_StoredData_s.recBufPtr_pu8 ,v_dequeueEvent_ps->v_StoredData_s.MsgLen);
                 /* Copy Data Length from Rx Buffer */
                 *o_dataSize_u16 = v_dequeueEvent_ps->v_StoredData_s.MsgLen;
                 /* Copy MsgId from Rx Buffers */
                 *o_msgID_u16 = v_dequeueEvent_ps->v_StoredData_s.MsgID;
                 /* Clear EventFlag to D_WRITE In Order to Write Data on Rx Buffer for next incomming data */
                 v_dequeueEvent_ps->eventFlag_u8 = D_WRITE;
             }
             else
             {
                 v_retValue_b = TRUE;
                 /* Do Nothing */
             }

             /* Unlock Mutex to share data with other Parllel task */
             pthread_mutex_unlock(&eventQueueChangeMutex);

             if(v_retValue_b == FALSE)
             {
                 /* Clear the Rx buffer */
                 v_retValue_b = (bool_t) IPC_f_ClearBuf_v(v_SmallestMsgCntrIdx_u32);
                 /* Check if ClearBuf Status for Fail Conditions */
                 if(v_retValue_b == TRUE)
                 {
                      /* Error Condition */ 
#if defined(DEBUG_MSG)
                     printf("\n ********************** recMsgEventDef.c :: getEvent failed \
                     could not able to clear data *************\n");
#endif
                 }
                 else
                 {
#if defined(DEBUG_MSG)
                     printf("\n ********************** recMsgEventDef.c :: getEvent :: \
                     ID : %u *************\n",*o_msgID_u16);
#endif
                     v_retValue_b = 0U;
                 }
             }

        }
        /* Check Received MsgID is Proper or Not */
        if((*o_msgID_u16 <= D_ERR_MSGID) || (*o_msgID_u16 > e_IpcMsgId_MAX_COUNT))
        {
             /* Return Error Condition */
             v_retValue_b = 1U;
        }

     }
     return v_retValue_b;
}

/*
 * Purpose: To clear Data from Receiver Buffers, which is extracted and shared to PUC.
 * Description: To clear the extracted and allready used data from Receiver Buffers.
 * Return Type : uint8_t
*/
static uint8_t IPC_f_ClearBuf_v(uint16_t o_dataIdx_u16)
{
    uint8_t v_retVal_u8 = 0U;
    recMsgData_t *v_ClearEvent_ps = NULL;
 
    /* Check Idx is Valid or Not */
    if(o_dataIdx_u16 < D_NUMBER_OF_RX_MESSAGES)
    {
        /* Lock Mutex to Update/Extract Shared Data */ 
        pthread_mutex_lock(&eventQueueChangeMutex);

        v_ClearEvent_ps = &msgEventQueue[o_dataIdx_u16].v_StoredData_s;

        /* Clear Rx buffer with default value 0 */
        memset(&v_ClearEvent_ps->recBufPtr_pu8[0U], 0, v_ClearEvent_ps->MsgLen);
        /* Clear MsgLen to default value 0 */
        v_ClearEvent_ps->MsgLen = 0U;
        /* Clear MsgID to default value 0 */
        v_ClearEvent_ps->MsgID = 0x00;
        /* Clear the Stored Counter! */ 
        msgEventQueue[o_dataIdx_u16].recvdMsgPtr = 0; 
 
        /* Unlock Mutex to share data with other Parllel task */
        pthread_mutex_unlock(&eventQueueChangeMutex);
    }
    else
    {
        /* Error Condition */ 
        v_retVal_u8 = TRUE;
    }
    return v_retVal_u8;
}

/*
 * Purpose: To Smallest MsgCntr buffer Index.
 * Description: Finding Smallest MsgCntr in Receiver Buffers and calculating it Index.
 *              In-order to get next received data coming from other cores
 * Return Type : uint16_t
*/
static uint16_t IPC_f_SmallestMsgCntrIdxToFetch_u16(void)
{
    uint16_t v_fetchIdx_u16 = 0U; 
    uint16_t v_SmallesMsgCntr_Idx_u16 = 0U;
    uint8_t v_startIdxFound = FALSE;
    uint32_t v_prev_sCntr_u32 = 0U;

    /* Lock Mutex to Update/Extract Shared Data */ 
    pthread_mutex_lock(&eventQueueChangeMutex);

    /* Get first index having read flag */ 
    for(v_fetchIdx_u16 = 0U; v_fetchIdx_u16 < D_EVENT_QUEUE_SIZE; ++v_fetchIdx_u16)
    {
        /* Check the Read Flag is set or not */
        if(D_READ == msgEventQueue[v_fetchIdx_u16].eventFlag_u8) 
        { 
            /* Collect Previous */
            v_prev_sCntr_u32 = msgEventQueue[v_fetchIdx_u16].recvdMsgPtr; 
            v_startIdxFound = TRUE; 
            break; 
        } 
    }
 
    /* Atleast one message found with Read flag */ 
    if(v_startIdxFound == TRUE) 
    {
        /* Travel over Rx buffer to calculate Index of Smallest MsgCntr value in Rx Buffer */
        for(v_fetchIdx_u16 = 0U; v_fetchIdx_u16 < D_EVENT_QUEUE_SIZE; ++v_fetchIdx_u16)
        {
            /* Check the Read Flag is set or not */
            if(D_READ == msgEventQueue[v_fetchIdx_u16].eventFlag_u8) 
            { 
                /* Check the Previous MsgCntr with Rx Buffers MsgCntr */
                if(v_prev_sCntr_u32 < msgEventQueue[v_fetchIdx_u16].recvdMsgPtr)
                {
                    /* Take Index of Smallest MsgCntr Rx Buffer */
                    if((msgEventQueue[v_fetchIdx_u16].recvdMsgPtr - v_prev_sCntr_u32) < D_EVENT_QUEUE_SIZE)
                    {
                        /* We have already got SmallestIndex, Do Nothing */
                    }
                    else
                    {
                        v_prev_sCntr_u32 = msgEventQueue[v_fetchIdx_u16].recvdMsgPtr;
                        v_SmallesMsgCntr_Idx_u16 = v_fetchIdx_u16;
                    }
                }
                else
                {
                    /* Check Previous Cntr with Current MsgCntr for Fail Condition */
                    if((v_prev_sCntr_u32 - msgEventQueue[v_fetchIdx_u16].recvdMsgPtr) < D_EVENT_QUEUE_SIZE)
                    {   
                        v_prev_sCntr_u32 = msgEventQueue[v_fetchIdx_u16].recvdMsgPtr;
                        v_SmallesMsgCntr_Idx_u16 = v_fetchIdx_u16;
                    }
                    else
                    {
                        /* We have already got SmallestIndex, Do Nothing */
                    }
                }
            }
        }
    }
    else 
    { 
        v_SmallesMsgCntr_Idx_u16 = D_EVENT_QUEUE_SIZE; 
    }
    /* Unlock Mutex to share data with other Parllel task */
    pthread_mutex_unlock(&eventQueueChangeMutex);
    return v_SmallesMsgCntr_Idx_u16;
}


/* ===========================================================================
 *
 *   End of Code File
 *
 * ======================================================================== */
