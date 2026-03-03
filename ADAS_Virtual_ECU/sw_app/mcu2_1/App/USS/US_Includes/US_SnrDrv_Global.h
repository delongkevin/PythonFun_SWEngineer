/*
 * US_SnrDrv_Global.h
 *
 *  Created on: Feb 17, 2021
 *      Author: e39960
 */

#ifndef SOURCES_SNRDRV_US_SnrDrvCom_F_GLOBAL_H_
#define SOURCES_SNRDRV_US_SnrDrvCom_F_GLOBAL_H_

#ifndef    _USS_DRV_COM_GLOBAL
#define    _USS_DRV_COM_GLOBAL

#include "US_ME_Typedefs_Global.h"
#include "US_Data_Typedefs_Global.h"

#define    USSDRV_CMD_AUTOADDR                     (0x4066U)

#define    US_DSI3_BITERR_MASK                            (0xF0000000U)   
#define    US_DSI3_CH_BITERR_MASK                         (0xFFFFF000U) 
#define    ERROR_US_SNRDRVCOM_CMD_CHECKSUM_ERROR          (0xFFFFFFF0U)
#define    ERROR_US_SNRDRVCOM_RECEIVE_BUFFER_NOT_ENOUGH   (0xFFFFFFF1U)
#define    ERROR_US_SNRDRVCOM_SYSTEM_NOT_INIT             (0xFFFFFFF2U)
#define    ERROR_US_SNRDRVCOM_SEND_DATA_NOT_ENOUGH        (0xFFFFFFF3U)
#define    ERROR_US_SNRDRVCOM_INVLID_CMD                  (0xFFFFFFF4U)
#define    ERROR_US_SNRDRVCOM_PARAMETER                   (0xFFFFFFF5U)
#define    ERROR_US_SNRDRVCOM_INVLID_SNRMAP               (0xFFFFFFF6U)
#define    ERROR_US_SNRDRVCOM_DATAFORMAT_ERR              (0xFFFFFFF7U)
#define    ERROR_US_SNRDRVCOM_PDCM_END                    (0xFFFFFFF8U)
#define    ERROR_US_SNRDRVCOM_DMA_BUFFER_OVERFLOW         (0xFFFFFFF9U)        //need to extend DMA buffer size
#define    ERROR_US_SNRDRVCOM_DSI_BUS_ERROR               (0xFFFFF001U)        //0xf0xx need to stop cmd
#define    ERROR_US_SNRDRVCOM_CMD_TIMEOUT                 (0xFFFFF002U)        //0xf0xx need to stop cmd
#define    ERROR_US_SNRDRVCOM_PDCM_CH_ERR                 (0xFFFF8000U)  // bit7:SC1 bit6:SE1 bit5:UV1,bit4:CE1 bit3:SC0 bit2:SE0 bit1:UV0,bit0:CE0

#define    ERROR_US_SNRDRVCOM_DSI_SPI_UNDCMD              (BIT0)
#define    ERROR_US_SNRDRVCOM_DSI_SPI_CRC                 (BIT1)
#define    ERROR_US_SNRDRVCOM_DSI_SPI_CMDINC              (BIT2)
#define    ERROR_US_SNRDRVCOM_DSI_CLKREF                  (BIT3)
#define    ERROR_US_SNRDRVCOM_DSI_CH0_UV                  (BIT4)
#define    ERROR_US_SNRDRVCOM_DSI_CH0_CMDOVR              (BIT5)
#define    ERROR_US_SNRDRVCOM_DSI_VCCUV_RFC               (BIT6)
#define    ERROR_US_SNRDRVCOM_DSI_CH1_UV                  (BIT7)
#define    ERROR_US_SNRDRVCOM_SPI_CH1_CMDOVR              (BIT8)
#define    ERROR_US_SNRDRVCOM_SPI_OV_TEMPERATURE          (BIT9)

#define DSI3_REG_PDCMPERIOD                   (0x0182U)
#define DSI3_REG_STAT                         (0x0183U)
#define DSI3_STOP_REG_CH0                     (0x0180U)
#define DSI3_STOP_REG_CH1                     (0x01C0U)
#define DSI3_CFG_REG_CH0                      (0x0181U)
#define DSI3_CFG_REG_CH1                      (0x01C1U)
#define DSI3_CTLR_REG                         (0x2EU)

#define DSI3_SPI_IRQ_STAT                     (0x010eU)
#define DSI3_DSI_IRQ_STAT                     (0x018eU)
#define DSI3_IRQ_STAT                         (0x60U)

#define DSI3_SPI_IRQ_EN                       (0x010fU)
#define DSI3_DSI_IRQ_EN                       (0x018fU)
#define DSI3_IRQ_EN                           (0x61U)


#define REQ_CALIBRATION_CFG                          (0x81U)
#define REQ_FLASH_MEMORY_DATA                        (0x82U)
#define SET_CALIBRATION_CFG                          (0x1U)

#define US_CONFIGURE_SENSOR_DELAY                    (0x0011u)
#define US_TRANCEIVER_RESET                          (0x0012u)
#define US_TRANCEIVER_RESET_CHECK                    (0x0013u)
#define US_READ_SENSORS_MARRIAGE_MAPPING             (0x0014u)

#define DSI_CMD_READ_MASTER_REG                      (0x8000U)
#define DSI_CMD_WRITE_MASTER_REG                     (0xC000U)

#define REQ_SENSOR_STOP_MEASUREMENT                  (0x7061U)
#define REQ_SENSOR_DIAGNOSTIC                        (0x7062U)
#define REQ_SENSOR_DETECTION_SAME_MEASUREMENT        (0x7063U)
#define REQ_SENSOR_DETECTION_INDIVIDUAL_MEASUREMENT  (0x7064U) // not implement
#define REQ_SENSOR_AUTO_ADDRESSING                   (0x4066U)
#define REQ_SENSOR_DETECTIPON_QUICK                  (0x7067U)
#define REQ_SENSOR_AD_VOLTAGE                        (0x7069U)
#define REQ_SENSOR_AUTOADDR_PROCESS                  (0x407FU)

#define REQ_SENSOR_FW_VER                            (0x7080U)
#define REQ_SENSOR_FC                                (0x7081U)
#define REQ_SENSOR_NORMAL_BURST_NUMBER               (0x7082U)
#define REQ_SENSOR_CHIRP_BW                          (0x7083U)
#define REQ_SENSOR_RINGINGCOMPARATOR                 (0x7084U)
#define REQ_SENSOR_BURST_TYPE_CONFIG                 (0x7085U)
#define REQ_SENSOR_CURRENT_CFG                       (0x7086U)
#define REQ_SENSOR_GAIN                              (0x7087U)
#define REQ_SENSOR_G_CAL                             (0x7088U)
#define REQ_SENSOR_ENVELOPE_CONFIG                   (0x7089U)
#define REQ_SENSOR_ENVELOPE_FILTER_CONFIG            (0x708AU)
#define REQ_SENSOR_MAX_ECHO_NUMBER                   (0x708BU)
#define REQ_SENSOR_ATG                               (0x708DU)
#define REQ_SENSOR_AATG1                             (0x708EU)
#define REQ_SENSOR_AATG2                             (0x708FU)
#define REQ_SENSOR_FTC                               (0x7090U)
#define REQ_SENSOR_STC                               (0x7091U)
#define REQ_SENSOR_STG                               (0x7092U)
#define REQ_SENSOR_FIX_PATH_CFG                      (0x7096U)
#define REQ_SENSOR_NFD                               (0x7097U)
#define REQ_SENSOR_EDI_CHANNEL                       (0x7098U)
#define REQ_SENSOR_OUTPUT_SIGNAL_SEL                 (0x7099U)
#define REQ_SENSOR_OUTPUT_SIGNAL_DATA                (0x709AU)
#define REQ_SENSOR_ID                                (0x709BU)
#define REQ_SENSOR_AMBIENT_TEMPATURE                 (0x709CU)
#define REQ_SENSOR_REGISTER                          (0x709DU)
#define REQ_SENSOR_EEPROM                            (0x709EU)
#define REQ_SENSOR_OPERATION_MODE                    (0x709FU)
#define REQ_SENSOR_TEMPATURE                         (0x70A0U)
#define REQ_SENSOR_FREQUENCY                         (0x70A1U)
#define REQ_SENSOR_RESULT                            (0x70A2U)
#define REQ_SENSOR_PROFILE                           (0x70A4U)
#define REQ_SENSOR_PROFILE_PLUS                      (0x70A6U)
#define REQ_SENSOR_GANA_MEAS_BEGIN                   (0x70A7U)
#define REQ_SENSOR_SNR_DIAGNOSTIC_RESULT_F11A        (0x70A8U)
#define REQ_SENSOR_SNR_DIAGNOSTIC_RESULT             (0x70FDU)        //(0x7081)
#define REQ_SENSOR_EEFLAG_VARCTRL                    (0x70A9U)
#define REQ_SENSOR_CPS_MEAS_GAIN                     (0x70AAU)
#define REQ_SENSOR_EEVAL_SENS_MEAS                   (0x70ABU)
#define REQ_SENSOR_RFM_CTRL                          (0x70A3U)


#define SETUP_SENSOR_FC                          (0x1001U)
#define SETUP_SENSOR_NORMAL_BURST_NUMBER         (0x1002U)
#define SETUP_SENSOR_CHIRP_BW                    (0x1003U)
#define SETUP_SENSOR_BURST_TYPE_CONFIG           (0x1005U)
#define SETUP_SENSOR_CURRENT_CFG                 (0x1006U)
#define SETUP_SENSOR_GAIN                        (0x1007U)
#define SETUP_SENSOR_G_CAL                       (0x1008U)
#define SETUP_SENSOR_ENVELOPE_CONFIG             (0x1009U)
#define SETUP_SENSOR_ENVELOPE_FILTER_CONFIG      (0x100AU)
#define SETUP_SENSOR_MAX_ECHO_NUMBER             (0x100BU)
#define SETUP_SENSOR_ATG                         (0x100DU)
#define SETUP_SENSOR_AATG1                       (0x100EU)
#define SETUP_SENSOR_AATG2                       (0x100FU)
#define SETUP_SENSOR_FTC                         (0x1010U)
#define SETUP_SENSOR_STC                         (0x1011U)
#define SETUP_SENSOR_STG                         (0x1012U)
#define SETUP_SENSOR_FIX_PATH_CFG                (0x1016U)
#define SETUP_SENSOR_NFD                         (0x1017U)
#define SETUP_SENSOR_EDI_CHANNEL                 (0x1018U)
#define SETUP_SENSOR_OUTPUT_SIGNAL_SEL           (0x1019U)
#define SETUP_SENSOR_ID                          (0x101BU)
#define SETUP_SENSOR_AMBIENT_TEMPERATURE         (0x101CU)
#define SETUP_SENSOR_REGISTER                    (0x101DU)
#define SETUP_SENSOR_EEPROM                      (0x101EU)
#define SETUP_SENSOR_OPERATURE_MODE              (0x101FU)
#define SETUP_SENSOR_PROFILE                     (0x1024U)
#define SETUP_SENSOR_GANA_MEAS_BEGIN             (0x1027U)
#define SETUP_SENSOR_EEFLAG_VARCTRL              (0x1029U)
#define SETUP_SENSOR_EEVAL_SENS_MEAS             (0x102BU) 
#define SETUP_SENSOR_ENABLE_ADDRBYEEP            (0x1025U)

#define SETUP_SENSOR_PROFILE_PLUS                (0x1026U)

#define MAX_DSI3_BUS                             (8U)
#define MAX_NUM_SENSORS                          (32u)

#define US_DSI3_DEV0             (0)
#define US_DSI3_DEV1             (1)
#define US_DSI3_DEV2             (2)
#define US_DSI3_DEV3             (3)

#define DSI3_CHANNEL_ENABLED                  ZERO                 //DSI3 channel enabled
#define DSI3_CHANNEL_DISABLED                 ONE                  //DSI3 channel disabled(either one channel)

#define DSI3DRV_SEND_BUFFER_SIZE                 (512u+64u)
#define DSI3DRV_RECEIVE_BUFFER_SIZE              (512u+64u)

extern uint16_t US_SnrDrvCom_F_Init(void);
extern void US_SnrDrvCom_F_Task(void);
extern uint32_t US_SnrDrvCom_F_CmdSnd(uint32_t SnrMap,uint32_t UserData,uint32_t CmdID,uint16_t SndSize,uint8_t *SndData,uint16_t RcvSize,uint8_t *RcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));
extern uint16_t US_SnrDrvCom_F_CountSnr(uint8_t nBus, uint8_t *nSnrBus,uint8_t *TotalSnr, uint32_t SnrMap, uint8_t isActual);
extern void US_SnrDrvCom_F_SPIDMACall(uint8_t dev);
extern uint16_t US_SnrDrvCom_F_SPIDCRProcess(uint8_t dev);
extern void US_DSI3Drv_SetCurBusFlag(uint8_t dev,uint8_t value);
extern uint8_t US_DSI3Drv_GetCurBusFlag(uint8_t dev);
extern void US_SnrDrvCom_F_SetDequeueDelay(uint8_t delay);
extern void US_SnrDrvCom_F_AddAdditionalDequeueDelay(uint8_t delay);
extern void US_SnrDrvCom_F_SetCalCfg(void);
extern void US_Reset_DSI3Tranceiver(void);
extern void US_Release_Reset_DSI3Tranceiver(void);
extern uint8_t US_CheckDSI3Ready(void);
void US_SnrDrv_DSI3_Clear_INTB(void);
uint8_t US_SnrDrv_Check_INTB(void);
void US_SnrDrv_Start_DSI3Transceiver_Reset(void);
uint8_t US_SnrDrv_GetChnStatus(void);
void US_SnrDrv_DSI3_Check(void);
uint8_t US_SnrDrv_Check_TransceiverResetState(void);
uint8_t US_DSI3_Check_INTB_State(void);
void US_SnrDrvCom_F_SendCRM_ByEvent(uint8_t dev,uint8_t const* Data,uint16_t inLen,uint16_t outLen);

#endif


#endif /* SOURCES_SNRDRV_US_SnrDrvCom_F_GLOBAL_H_ */
