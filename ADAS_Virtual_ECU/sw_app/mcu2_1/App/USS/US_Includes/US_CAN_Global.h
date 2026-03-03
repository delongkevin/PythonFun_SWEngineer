/************************************************************************************************************************
* \file      US_CAN_Global.h
* \brief     This file contain function prototypes of CanIf.c.
* \author    Amol Gore
* \version   1.00
* \copyright MAGNA Electronics - C O N F I D E N T I A L
*            This document in its entirety is CONFIDENTIAL and may not be disclosed,disseminated or distributed to parties
*			 outside MAGNA Electronics without written permission from MAGNA Electronics.
************************************************************************************************************************/
#ifndef US_CAN_GLOBAL_H
	#define US_CAN_GLOBAL_H


/************************************************************************************************************************
* CAN MSG struct
************************************************************************************************************************/
typedef struct {
    uint32_t msgId;
    uint8_t data[64];
    uint8_t dataLen;
}US_Can_msg_t;

/************************************************************************************************************************
* Function prototypes
************************************************************************************************************************/
   void US_CanIf_RxIndication(void * lCANRecvdMsgbuff);
   void US_CanIf_TxConfirmation(void);

#endif /* CAN_IF_H*/
