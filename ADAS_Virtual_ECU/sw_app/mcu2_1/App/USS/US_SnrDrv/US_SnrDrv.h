/*
 * USSDrvCom.h
 *
 *  Created on: Feb 17, 2021
 *      Author: e39960
 */

#ifndef SOURCES_SNRDRV_US_SnrDrvCom_F_H_
#define SOURCES_SNRDRV_US_SnrDrvCom_F_H_


#include "US_ME_Typedefs_Global.h"

#define MAX_USS_DRV_CMD             (64u)   /* Max cmds in the queue */
#define USSQUEUEMASK                ((uint8_t)(MAX_USS_DRV_CMD - 1u))

#define USS_DRV_CRM_HEADER          (1U)
#define USS_DRV_CRM_DATA            (2U)

#define US_SNRDEVCOM_CMD_TIMEOUT_TIME          (100U)
#define MAX_SEND_SIZE    TWENTY_FOUR

#define ME_EMPTY     (1)
#define ME_FULL      (2)

#define LOCK         (0)
#define UNLOCK       (1)

#define ME_SEMAPHORE_LOCK_FAIL   (1)

#define DSI_CRM_TRANSMIT                 (0x10U)
#define DSI_CRM_AUTOADDR                 (0x40U)
#define DSI_CMD_MASK               		 (0xF000U)
#define DSI_CMD_MASTER_REG_MASK          (0xC000U)
#define DSI_CMD_READ_MASTER_REG          (0x8000U)
#define DSI_CMD_WRITE_MASTER_REG         (0xC000U)
#define DSI_CMD_READ_MASTER_REG8         (0x80U)
#define DSI_CMD_WRITE_MASTER_REG8        (0xC0U)
#define DSI_CMD_READ_CRM_RESPONSE        (0x20U)
#define DSI_CMD_READ_PDCM_BUFFER8        (0x70U)
#define DSI_CMD_READ_PDCM_BUFFER8_DMA    (0x71U)
#define DSI_CMD_PDCM_BUFFER8_OVERLAP     (0x72U)
#define DSI_CMD_PDCM_BUFFER8_OVERLAP_DMA (0x73U)
#define DSI_CMD_CLEAR_DSI3_BUFFER        (0x74U)
#define DSI_CMD_READ_PDCM_BUFFER         (0x7000U)
#define DSI_CMD_BRC_PDCM                 (0x6000U)
#define DSI_CMD_BRC_PDCM8                (0x60U)
#define DSI_CMD_STOP_DSI3_CH0            (0xC1U)
#define DSI_CMD_STOP_DSI3_CH1            (0xC2U)

#define DSI3_CH2_OFFSET                  (0x0040U)
#define DSI3_CH1_BASE                    (0x0180U)
#define DSI3_CH2_BASE                    (0x01C0U)

#define DSI3_STOP_REG                    (0x0180U) 

#define CRM_RESPONSE_LENGTH               (18U)


typedef enum s_cmdstate
{
	CMD_IDLE = 0,
	CMD_READY,
	CMD_EXEC_CRM,
	CMD_EXEC_OP_MASTER_IC,
	CMD_EXEC_PDCM,
	CMD_EXEC_PDCM_DATA
}US_SnrDrv_cmdstate_t;


typedef union
{
	volatile uint64_t          CmdState;               /* whole cmd state*/
	struct
	{
	volatile uint8_t           SPI_CMD;              /* SPI_cmd */
	uint8_t                     Count;                /* count for spi_cmd */
	}Dev[4];
}US_SnrDrvCom_CmdState_t;


typedef struct US_SnrDrvCom_Cmd_S
{
	uint32_t          SnrMap;               /* Sensor Map bit, 1: apply to this sensor, 0: ignore this sensor*/
	uint32_t          CmdID;                /* Cmd Id, lower byte send to Sensor */
	uint32_t          UserData;             /* User data, it is just passed to call back */
	uint16_t          SndSize;              /* size of payload */
	uint16_t          RcvSize;              /* Rcv buffer size */
	uint8_t           *SndData;             /* payload buffer */
	uint8_t           *RcvData;             /* Rcv buffer */
	void            (*CallBack)(uint32_t,uint32_t,uint32_t,uint16_t,uint8_t*);            /* callback function */
}US_SnrDrvCom_Cmd_t, *pUS_SnrDrvCom_Cmd_t;

typedef struct US_SnrDrvCom_CmdTable_S
{
	uint16_t          cmd;                  /* cmdid*/
	uint16_t          PDCMPeriod;                /* PDCMPeriod */
	uint16_t          waittime;                /* waittime */
	uint16_t          PacketSize;              /* packetsize */
	uint16_t          DataLen;                 /* DataLen */
	uint16_t          nBRC;                    /*No. of BRC msg*/
	uint16_t          StartAddr;               /* data start addr in Rcv buf */
}US_SnrDrvCom_CmdTable_t, *pUS_SnrDrvCom_CmdTable_t;
extern void US_SnrDrvCom_F_SetDequeueDelay(uint8_t delay);
extern void US_SnrDrvCom_F_Set_BurstnPDCM(uint8_t nPDCM,uint8_t period);
#if(USS_COM_DATA_SHARE_ENBL_DEBUG_SIGNAL == US_STD_ON)
extern uint16_t US_SnrDrvCom_GetDSI3ErrCnt(void);
#endif
extern uint8_t *US_DSI3Drv_GetSpiSndBuffer(void);
extern uint8_t *US_DSI3Drv_GetSpiRcvBuffer(void);
extern uint8_t US_DSI3Drv_GetBusChn(uint8_t dev);


#endif /* SOURCES_SNRDRV_US_SnrDrvCom_F_H_ */
