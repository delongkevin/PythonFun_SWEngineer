/*
 * US_SnrCfg_Calibration.h
 *
 *  Created on: Apr 9, 2021
 *      Author: e39960
 */

#ifndef SRC_US_CALIBRATION_US_SNRCFG_CALIBRATION_H_
#define SRC_US_CALIBRATION_US_SNRCFG_CALIBRATION_H_

typedef struct US_SnrCfg_CmdTable_s
{
	uint16_t          cmd;                  /* cmdid*/
	uint16_t          index_fxn;            /*specified call fxn*/
	uint32_t          (*US_Snr_Fxn)(uint32_t SnrMap,uint32_t UserData,uint16_t sndlen,uint8_t const *sndData,uint16_t rcvlen, uint8_t* rcvData,void (*CallBack)(uint32_t ErrorCode,uint32_t Cmd,uint32_t UserData,uint16_t RcvSize,uint8_t *RcvData));
	uint32_t          (*US_ECUFxn)(uint16_t CmdID,uint32_t UserData,uint32_t *Addr,uint16_t Length);
}US_SnrCfg_CmdTable_t;


#endif /* SRC_US_CALIBRATION_US_SNRCFG_CALIBRATION_H_ */
