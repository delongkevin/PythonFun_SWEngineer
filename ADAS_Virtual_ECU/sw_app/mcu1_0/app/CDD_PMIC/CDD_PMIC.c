/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  CDD_PMIC.c
 *           Config:  D:/Git/L2H5250_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  CDD_PMIC
 *  Generation Time:  2024-02-26 15:43:37
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <CDD_PMIC>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * DeviceAddress
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CDD_PMIC.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CDD_PMIC.h"
#include "Enums.h"
#include <stdint.h>
#include "pmic.h"
#include "pmic_cfg.h"
#include "board_power.h"
#include <ti/drv/pmic/src/pmic_io_priv.h>

#if defined( BUILD_MCU1_0 )
#define CDD_PMIC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_PMIC_MemMap.h"
#endif

static uint8 s_I2C0_RxDataBuffer_au8[e_TWO];

#if defined( BUILD_MCU1_0 )
#define CDD_PMIC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_PMIC_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_PMIC_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_PMIC_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_PMIC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_PMIC_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_PMIC_START_SEC_CONST_UNSPECIFIED
#include "CDD_PMIC_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_PMIC_STOP_SEC_CONST_UNSPECIFIED
#include "CDD_PMIC_MemMap.h"
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * DeviceAddress: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * PmicStatus: Array with 8 element(s) of type uint8
 * WdgFltSts: Array with 2 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define CDD_PMIC_START_SEC_CODE
#include "CDD_PMIC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_MCUReadDeviceReg
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <MCUReadDeviceReg> of PortPrototype <PpMCUDeviceRegReadWrite>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_MCUReadDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_MCUReadDeviceReg_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_PMIC_CODE) RE_MCUReadDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress) /* PRQA S 0624, 3206, 1503 */ /* MD_Rte_0624, MD_Rte_3206, Used in other file with trusted call */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_MCUReadDeviceReg (returns application error)
 *********************************************************************************************************************/
	/*ReqID:-*/

  /* DD-ID: {0AC091C2-721A-4ba9-BD7F-8055C1455504}*/
	uint8_t slaveaddr;
	uint8_t v_devIdx_u8;
	int32_t boardStatus;
	Std_ReturnType returnTemp;
	uint8_t RegData = (uint8_t)e_ZERO;

	switch(DeviceAdd)
	{
		case (DeviceAddress)e_ZERO:
		slaveaddr = LEO_PMICA_WDG_SLAVE_ADDR;
		v_devIdx_u8 = (uint8_t)e_ZERO;
		break;

		case (DeviceAddress)e_ONE:
		slaveaddr = LEO_PMICA_SLAVE_ADDR;
		v_devIdx_u8 = (uint8_t)e_ZERO;
		break;

		case (DeviceAddress)e_TWO:
		slaveaddr = LEO_PMICB_SLAVE_ADDR;
		v_devIdx_u8 = (uint8_t)e_ONE;
		break;

		case (DeviceAddress)e_THREE:
		slaveaddr = HERA_PMIC_SLAVE_ADDR;
		v_devIdx_u8 = (uint8_t)e_TWO;
		break;

		default:
		slaveaddr = INVALID_PMIC_SLAVE_ADDR;
		break;
	}

	if(slaveaddr != (uint8_t)INVALID_PMIC_SLAVE_ADDR)
	{
		boardStatus = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle, (uint16_t)RegAddress, &RegData);

		if(boardStatus != BOARD_SOK)
		{

			returnTemp = RTE_E_INVALID;
		}
		else
		{
			s_I2C0_RxDataBuffer_au8[e_ZERO] = RegData;
			returnTemp = RTE_E_OK;
		}
	}
	else
	{
		returnTemp = RTE_E_INVALID;
	}
	return returnTemp;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_MCUReadDeviceRegData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <MCUReadDeviceRegData> of PortPrototype <PpMCUDeviceRegReadWrite>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_MCUReadDeviceRegData(DeviceAddress DeviceAdd, uint16 *RegAddress)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_MCUReadDeviceRegData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_PMIC_CODE) RE_MCUReadDeviceRegData(DeviceAddress DeviceAdd, P2VAR(uint16, AUTOMATIC, RTE_CDD_PMIC_APPL_VAR) RegAddress) /* PRQA S 0624, 3206, 1503, 3432 */ /* MD_Rte_0624, MD_Rte_3206, Used in other file with trusted call, Generated code */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_MCUReadDeviceRegData (returns application error)
 *********************************************************************************************************************/
	/*ReqID:-*/
   /* DD-ID:{B43E64E0-2F5B-4aee-AF2A-1E6DF31D8743}*/
	Std_ReturnType returnTemp = RTE_E_OK;
	*RegAddress = (uint16)(((uint16)s_I2C0_RxDataBuffer_au8[e_ONE] << BIT_SHIFT_EIGHT_BIT) | s_I2C0_RxDataBuffer_au8[e_ZERO]);
	return returnTemp;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_MCUWriteDeviceReg
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <MCUWriteDeviceReg> of PortPrototype <PpMCUDeviceRegReadWrite>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_MCUWriteDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress, uint16 RegData)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_MCUWriteDeviceReg_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_PMIC_CODE) RE_MCUWriteDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress, uint16 RegData) /* PRQA S 0624, 3206, 1503 */ /* MD_Rte_0624, MD_Rte_3206, Used in other file with trusted call */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_MCUWriteDeviceReg (returns application error)
 *********************************************************************************************************************/
	/*ReqID:-*/
   /* DD-ID: {2CAAEC66-63BE-48d3-B76B-AFD80ED7D134}*/
  
  /* DD-ID: {2CAAEC66-63BE-48d3-B76B-AFD80ED7D134}*/
	uint8_t slaveaddr;
	int32_t boardStatus;
	Std_ReturnType returnTemp;
	uint8_t	v_devIdx_u8;

	switch(DeviceAdd)
	{
		case (DeviceAddress)e_ZERO:
		slaveaddr = LEO_PMICA_WDG_SLAVE_ADDR;
		v_devIdx_u8 = (uint8_t)e_ZERO;
		break;

		case (DeviceAddress)e_ONE:
		slaveaddr = LEO_PMICA_SLAVE_ADDR;
		v_devIdx_u8 = (uint8_t)e_ZERO;
		break;

		case (DeviceAddress)e_TWO:
		slaveaddr = LEO_PMICB_SLAVE_ADDR;
		v_devIdx_u8 = (uint8_t)e_ONE;
		break;

		case (DeviceAddress)e_THREE:
		slaveaddr = HERA_PMIC_SLAVE_ADDR;
		v_devIdx_u8 = (uint8_t)e_TWO;
		break;

		default:
		slaveaddr = INVALID_PMIC_SLAVE_ADDR;
		break;
	}

	if(slaveaddr != (uint8_t)INVALID_PMIC_SLAVE_ADDR)
	{
		boardStatus = Pmic_commIntf_sendByte(&pmic_device[v_devIdx_u8].pmicCoreHandle, (uint16_t)RegAddress, (uint8_t)RegData);
		if(boardStatus != BOARD_SOK)
		{
			returnTemp = RTE_E_INVALID;
		}
		else
		{
			returnTemp = RTE_E_OK;
		}
	}
	else
	{
		returnTemp = RTE_E_INVALID;
	}
	return returnTemp;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PMIC_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PMIC_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_PMIC_CODE) RE_PMIC_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PMIC_Init
 *********************************************************************************************************************/
 /*ReqID:-*/
   /* DD-ID: {826BD8DC-FE78-4a8c-AA04-B402DD04B915}*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PMIC_Main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpPMICFaultstatus_Sts(const uint8 *data)
 *     Argument data: uint8* is of type PmicStatus
 *   Std_ReturnType Rte_Write_PpWDGFaultStatus_Sts(const uint8 *data)
 *     Argument data: uint8* is of type WdgFltSts
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PMIC_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_PMIC_CODE) RE_PMIC_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PMIC_Main
 *********************************************************************************************************************/
   /* DD-ID: {C721AE41-4349-40ec-AEF5-4D3607E735F6}*/
  /* f_UpdatePMICLdoRegister(); */        /* Call to f_UpdatePMICLdoRegister function */

  /* PMIC functions */
  /* Pmic_F_MainTask_v(); */  /* PMIC scheduled function */
  /* DD-ID: {AE879848-F973-4556-9184-8A778F7521EC}*/
  /* DD-ID: {C721AE41-4349-40ec-AEF5-4D3607E735F6}*/
  /* DD-ID: {B4599AFF-2F82-4a6d-9F6D-9E233A5C4399}*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define CDD_PMIC_STOP_SEC_CODE
#include "CDD_PMIC_MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
