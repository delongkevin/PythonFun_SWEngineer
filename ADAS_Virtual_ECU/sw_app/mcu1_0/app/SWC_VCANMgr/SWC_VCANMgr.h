/* ===========================================================================
* MAGNA Electronics - C O N F I D E N T I A L
* This document in its entirety is CONFIDENTIAL and may not be disclosed,
* disseminated or distributed to parties outside MAGNA Electronics
* without written permission from MAGNA Electronics.
* ===========================================================================
* SHORT:       VCAN Manager Module
* DESIGN:      2022
* DESCRIPTION: VCAN Manager Module
* ======================================================================== */

/**
* \file     SWC_VCANMgr.h
* \brief    VCAN Manager Module
* \author   Gaurav Bhimpure
* \version
* \details  h file public description of module
*/
/* ======================================================================== */

#ifndef SWC_VCANMGR_H
#define SWC_VCANMGR_H

#include "VehicleInputAdapterDataTypes.h"
#include "vstdlib.h"
#include "Enums.h"
#include "OsHooks_RpStruct.h"

/*-----------------------------------------------------------*/
/* DTC related declarations >> START */
/*-----------------------------------------------------------*/

#define D_TIME_TRIGGERED_EVENT 		0U
#define D_EXTERNAL_TRIGGERED_EVENT 	1U
#define TASKREPRATE                 10U


/* E2E Declaration below */

#define D_E2E_CRC_OFFSET_55          (0x37u)
#define D_E2E_CRC_OFFSET_23          (0x17u)
#define D_E2E_COUNTER_OFFSET_54      (0x36u)
#define D_E2E_COUNTER_OFFSET_22      (0x16u)

#define D_CONVERT_BYTE_TO_BIT           (0x08u)
#define D_COUNTER_OFFSET                (0x08u)
#define D_MAXDELTA_COUNTERINIT          (0x01u)
#define D_DES_PAM_BUSOFF_INDICATION     (0x02u)

#define D_ZERO_VAL              (0x00u)

/* CAN Signals conversion macros */
#define D_SPEED_CONV_FACTOR                    (0.0625f)
#define D_CAN_0_1_FACTOR                       (0.1f)
#define D_CAN_0_5_FACTOR                       (0.5f)
#define D_TRQ_FACTOR                           (0.0078125f)
#define D_LMD_SEGMENT_Y_FACTOR                 (0.01f)

static E2E_MEP_ConfigType	S_ConfigType_FD2_Write = {D_COUNTER_OFFSET, FALSE, FALSE, FALSE, E2E_MEP_DATAID_LOW, FALSE, D_MAXDELTA_COUNTERINIT, FALSE, FALSE };
static E2E_MEP_ConfigType	S_ConfigType_FD14_Write  = {D_COUNTER_OFFSET, FALSE, FALSE, FALSE, E2E_MEP_DATAID_LOW, FALSE, D_MAXDELTA_COUNTERINIT, FALSE, FALSE };
static E2E_MEP_ConfigType    S_ConfigType_FD2_Read = {D_COUNTER_OFFSET, FALSE, FALSE, FALSE, E2E_MEP_DATAID_LOW, FALSE, e_ONE, e_ONE, FALSE };
static E2E_MEP_ConfigType    S_ConfigType_FD14_Read = {D_COUNTER_OFFSET, FALSE, FALSE, FALSE, E2E_MEP_DATAID_LOW, FALSE, e_ONE, e_ONE, FALSE };



/*-----------------------------------------------------------*/
/* DTC related declarations >> END */
/*-----------------------------------------------------------*/


  typedef enum e_MessageID_s
  {
	FD2_BCM_FD_10_ID=0u,
	FD2_BCM_FD_12_ID,
	FD2_BCM_FD_2_ID,
	FD2_BCM_FD_27_ID,
	FD2_BCM_FD_9_ID,
	FD2_DRIVETRAIN_FD_3_ID,
	FD2_TELEMATIC_FD_5_ID,
	FD2_TRANSM_FD_1_ID,
	FD2_TRANSM_FD_2_ID,
	FD14_BRAKE_FD_2_ID,
	FD14_BRAKE_FD_3_ID,
	FD14_BRAKE_FD_5_ID,
	FD14_ENGINE_FD_2_ID,
	FD14_EPS_FD_1_ID,
	FD2_AGSM_FD_2_ID,
	FD2_BCM_FD_29_ID,
	FD2_TELEMATIC_FD_11_ID,
	FD2_TELEMATIC_FD_14_ID,
	FD2_TRANSM_FD_4_ID,
	FD2_TRSKM_FD_1_ID,
	FD14_BRAKE_FD_1_ID,
	FD14_BRAKE_FD_4_ID,
	FD14_BRAKE_FD_7_ID,
	FD14_ENGINE_FD_7_ID,
	FD14_EPS_FD_2_ID,
	FD2_ASCM_FD_1_ID,
	FD2_ASCM_FD_2_ID,
	FD2_ORC_FD_1_ID,
	LAST_MESSAGE_ID,
  }e_MessageID_t;

static E2E_MEP_CheckStateType s_E2E_State_Read[LAST_MESSAGE_ID]={
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0},
		{0,0,TRUE,0,0,0,0,0}
};

/* Debug Message CAN TX prototypes*/
void f_Send_Dbg_MCU1_0_Faultnum_CanTx(uint8 FaultNum);
void f_Send_Dbg_MCU1_0_FaultInfo_CanTx(uint16 FaultInfo);
void f_Send_Dbg_Os_hook_CanTx(ME_OsHookDebugData_t s_ME_OsHookDebugData_RPRAM_as);
void f_Send_Dbg_WdgErr_CanTx(uint16 WdgError);

#endif
