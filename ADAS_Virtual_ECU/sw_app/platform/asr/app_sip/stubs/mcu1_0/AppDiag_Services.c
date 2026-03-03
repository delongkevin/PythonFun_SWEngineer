/** file AppDiag_Services.c
 *  brief Diagnostics
 * 
 *  Diagnostics
 * 
 *  --------------------------------------------------------------------------
 *  copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  author Anonymous Author 
 */
/*==================[inclusions]============================================*/
#include "Dcm.h"
#include "Com.h"
#include "AppDiag_Services.h"
#include "NvM.h"
#include "vstdlib.h"
#include "Enums.h"
#include "Csm.h"
#include "Ea.h"
#include "Eep_30_XXi2c01.h"
#include "Rte_Main.h"
#include "Dio.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "pmic.h"
#include "SSM_BSW_Interface.h"
#include "Os.h"

#include <ti/drv/sciclient/sciclient.h>

/*==================[internal macros]=======================================*/
# define kFblStartMagicByte0     0x50u /* 'P' */
# define kFblStartMagicByte1     0x72u /* 'r' */
# define kFblStartMagicByte2     0x6Fu /* 'o' */
# define kFblStartMagicByte3     0x67u /* 'g' */
# define kFblStartMagicByte4     0x53u /* 'S' */
# define kFblStartMagicByte5     0x69u /* 'i' */
# define kFblStartMagicByte6     0x67u /* 'g' */
# define kFblStartMagicByte7     0x6Eu /* 'n' */
# define kFblNoOfMagicBytes      e_EIGHT

#define ENABLE_SSM_NOTIFICATION
#define D_DELAY_COUNT          50000u

/*==================[internal type definitions]=============================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/
volatile uint8 fblStartMagicFlag[kFblNoOfMagicBytes]__attribute__ ((section("reset_protected_ram")));
/*==================[internal data]=========================================*/
static uint8 RST_DiagState = NO_RESET;
static uint8 Do_CANStandby = TRUE;
static Dcm_EcuResetType Dcm_ECU_Reset_Reason = RTE_MODE_DcmEcuReset_NONE;

extern void EcuM_AL_SwitchOff(void);
static void Eep_Ecureset(void);
static void AppDiagService_MemSetInteger(uint8 count, uint32 input, uint8* buffer );
static void Set_CANStandby(boolean u8CANState);
static uint8 Get_CANStandby(void);
static void RST_SetPlannedReset(uint8 resettype);
static uint8 RST_GetPlannedReset(void);
static void EcuReset(void);
static void FblSetFblStartMagicFlag(void);
/*==================[internal data]=========================================*/
/*==================[external function definitions]=========================*/

static void FblSetFblStartMagicFlag(void)
{
   fblStartMagicFlag[e_ZERO] = kFblStartMagicByte0;
   fblStartMagicFlag[e_ONE] = kFblStartMagicByte1;
   fblStartMagicFlag[e_TWO] = kFblStartMagicByte2;
   fblStartMagicFlag[e_THREE] = kFblStartMagicByte3;
   fblStartMagicFlag[e_FOUR] = kFblStartMagicByte4;
   fblStartMagicFlag[e_FIVE] = kFblStartMagicByte5;
   fblStartMagicFlag[e_SIX] = kFblStartMagicByte6;
   fblStartMagicFlag[e_SEVEN] = kFblStartMagicByte7;
}

FUNC(void, DCM_CALLOUT_CODE) Dcm_Confirmation(Dcm_IdContextType idContext
                                             ,PduIdType dcmRxPduId
                                             ,Dcm_ConfirmationStatusType status)
{
	(void)idContext;
	(void)dcmRxPduId;
	(void)status;
}

/***********************************************************************************************************************
 *  AppDiagService_MemSetInteger
 **********************************************************************************************************************/
/*! \brief      Convert given integer value to big-endian byte array
 *  \param[in]  count Number of relevant bytes
 *  \param[in]  input Input value
 *  \param[out] buffer Pointer to output buffer
 **********************************************************************************************************************/
static void AppDiagService_MemSetInteger(uint8 count, uint32 input, uint8* buffer )
{
	uint32 v_Input_u32;
	uint8 v_Count_u8;

	v_Input_u32 = input;
	v_Count_u8 = count;

	/* Loop relevant bytes */
	while (v_Count_u8 > (uint8)e_ZERO)
	{
		v_Count_u8--;
		/* Store most significant byte first */
		buffer[v_Count_u8] = (uint8)(v_Input_u32 & (uint32)BIT_MASK);
		/* Shift in next byte */
		v_Input_u32 >>= (uint32)e_EIGHT;
	}
}
/******************************************************************************************
FUNCTION NAME:          Dcm_GetProgConditions
PURPOSE:                Function required by DCM to retrieve any application specific 
                        preconditions for programming. 
                        Stub is created here because the application does not have an use case
                        for this scenario.

RETURN VALUE:           Dcm_EcuStartModeType - Always returns DCM_COLD_START.
INPUT PARAMETERS:       None.
OUTPUT PARAMETERS:      Dcm_ProgConditionsPtrType progConditions - stubbed output parameter.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
	(void)progConditions;
	return DCM_COLD_START;
}

/******************************************************************************************
FUNCTION NAME:          Dcm_SetProgConditions
PURPOSE:                Function required by DCM to set any specific preconditions for 
                        programming. The application specific preconditions are checked.
                        

RETURN VALUE:           Std_ReturnType - E_OK - Transition to Bootloader is allowed.
                                         E_NOT_OK - Transition to Bootloader is not allowed.
INPUT PARAMETERS:       Dcm_ProgConditionsPtrType progConditions - unused input parameter.
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
   Std_ReturnType retValue = DCM_E_NOT_OK;
   uint8 v_TesterSourceAddress_au8[e_TWO];
   static uint8 s_TstSrcAddrNvMTriggered_u8 = (uint8)FALSE;
   NvM_RequestResultType ErrorStatus_u8;
   FblSetFblStartMagicFlag();
  
   if(s_TstSrcAddrNvMTriggered_u8 == (uint8)FALSE)
   {
	   AppDiagService_MemSetInteger(sizeof(v_TesterSourceAddress_au8),(uint32)progConditions->TesterSourceAddr,v_TesterSourceAddress_au8);
	   retValue = NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DcmDslRxTesterSourceAddr,(void*)v_TesterSourceAddress_au8);
	   if(retValue == DCM_E_OK)
	   {
		   s_TstSrcAddrNvMTriggered_u8 = (uint8)TRUE;
	   }
     else
     {
         /*Do nothing*/
	   }
   }
   else
   {
    /*Do Nothing*/
   }

   do
   {
     NvM_MainFunction();
     Ea_MainFunction();
     Eep_30_XXi2c01_MainFunction();

     (void)NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DcmDslRxTesterSourceAddr, &ErrorStatus_u8);
   } while (ErrorStatus_u8 == (uint8)NVM_REQ_PENDING);

   if(s_TstSrcAddrNvMTriggered_u8 == (uint8)TRUE)
   {
	   (void)NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DcmDslRxTesterSourceAddr,&ErrorStatus_u8);
	   if(ErrorStatus_u8 == (uint8)NVM_REQ_PENDING)
	   {
		   retValue = DCM_E_PENDING;
	   }
	   else if(ErrorStatus_u8 == (uint8)NVM_REQ_OK)
	   {
		   retValue = DCM_E_OK;
	   }
	   else
	   {
		   retValue = DCM_E_NOT_OK;
	   }
   }
   else
   {
    /*Do Nothing*/
   }
   return retValue;
}

/******************************************************************************************
FUNCTION NAME:          ReqSciclientECUReset
PURPOSE:                Function required by DCM to check any specific preconditions for
                        ECU Reset.


RETURN VALUE:           Std_ReturnType - E_OK - ECU Reset is allowed.
                                         E_NOT_OK - ECU Reset is not allowed.
INPUT PARAMETERS:       Dcm_EcuResetType nextMode - input parameter specifying the type
                        of the pending ECU Reset.
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
void ReqSciclientECUReset(void)
{
    struct tisci_msg_sys_reset_req request;
    struct tisci_msg_sys_reset_resp response = {0};

    Sciclient_ReqPrm_t reqParam;
    Sciclient_RespPrm_t respParam;
  
    VStdLib_MemClr(&request, sizeof(request));
    request.domain = 0x00u; /* Whole System reset */

    reqParam.messageType    = (uint16_t) TISCI_MSG_SYS_RESET;
    reqParam.flags          = (uint32_t) TISCI_MSG_FLAG_AOP;
    reqParam.pReqPayload    = (const uint8_t *) &request;
    reqParam.reqPayloadSize = (uint32_t) sizeof (request);
    reqParam.timeout        = (uint32_t) SCICLIENT_SERVICE_WAIT_FOREVER;
    respParam.flags           = (uint32_t) 0;   /* Populated by the API */
    respParam.pRespPayload    = (uint8_t *) &response;
    respParam.respPayloadSize = (uint32_t) sizeof (response);

    (void)Sciclient_service(&reqParam, &respParam);
}
/**********************************************************************************************************************
 *  Dcm_ProcessRequestDownload()
 *********************************************************************************************************************/
/*! \brief         Starts a software download sequence.
 *  \details        This call-out is used during software download processing, if RequestDownload is configured.
 *  \param[in]      OpStatus                Operation status
 *  \param[in]      DataFormatIdentifier    Identifier of the Data Format
 *  \param[in]      MemoryIdentifier        Identifier of the Memory Block
 *  \param[in]      MemoryAddress           Starting address of server memory from which data is to be retrieved
 *  \param[in]      MemorySize              Number of bytes in the MemoryData
 *  \param[in,out]  BlockLength             Maximum number of bytes for one Dcm_ProcessTransferDataWrite
 *  \param[out]     ErrorCode               Negative response code in case return value is DCM_E_NOT_OK
 *  \return         DCM_E_OK                Request was successful
 *  \return         DCM_E_NOT_OK            Request was not successful
 *  \return         DCM_E_PENDING           Request is not yet finished
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         This function is only available if DCM_FBLMGR_SUPPORT_ENABLED = STD_ON.
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestDownload(
  Dcm_OpStatusType OpStatus,
  uint8  DataFormatIdentifier,
  uint8  MemoryIdentifier,
  uint32 MemoryAddress,
  uint32 MemorySize,
  uint32* BlockLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  )
  {
	(void)OpStatus;
	(void)DataFormatIdentifier;
	(void)MemoryIdentifier;
	(void)MemoryAddress;
	(void)MemorySize;
	(void)BlockLength;
	(void)ErrorCode;
    return RTE_E_OK;
  }
/**********************************************************************************************************************
 *  Dcm_ProcessTransferDataWrite()
 *********************************************************************************************************************/
/*! \brief         Transfers data during a download sequence.
 *  \details        This call-out is used during software download processing, if TransferData is configured.
 *  \param[in]      OpStatus                Operation status
 *  \param[in]      MemoryIdentifier        Identifier of the Memory Block
 *  \param[in]      MemoryAddress           Starting address of server memory from which data is to be retrieved
 *  \param[in]      MemorySize              Number of bytes in the MemoryData
 *  \param[in]      MemoryData              Data to write (Points to the diagnostic buffer in DCM)
 *  \param[out]     ErrorCode               Negative response code in case return value is DCM_E_NOT_OK
 *  \return         DCM_WRITE_OK            Write was successful
 *  \return         DCM_WRITE_FAILED        Write was not successful
 *  \return         DCM_WRITE_PENDING       Write is not yet finished
 *  \return         DCM_WRITE_FORCE_RCRRP   Enforce RCR-RP transmission (vendor extension)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         This function is only available if DCM_FBLMGR_SUPPORT_ENABLED = STD_ON.
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Dcm_ReturnWriteMemoryType, DCM_CALLOUT_CODE) Dcm_ProcessTransferDataWrite(
  Dcm_OpStatusType OpStatus,
  uint8  MemoryIdentifier,
  uint32 MemoryAddress,
  uint32 MemorySize,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) MemoryData,
  Dcm_NegativeResponseCodePtrType ErrorCode
  )
  {
	(void)OpStatus;
	(void)MemoryIdentifier;
	(void)MemoryAddress;
	(void)MemorySize;
	(void)MemoryData;
	(void)ErrorCode;
    return RTE_E_OK;
  }

/**********************************************************************************************************************
 *  Dcm_ProcessRequestTransferExit()
 *********************************************************************************************************************/
/*! \brief         Finalizes a software download sequence.
 *  \details        This call-out is used during software download processing, if RequestTransferExit is configured.
 *  \param[in]      OpStatus                             Operation status
 *  \param[in]      transferRequestParameterRecord       Request data
 *  \param[in]      transferRequestParameterRecordSize   Number of request data bytes
 *  \param[out]     transferResponseParameterRecord      Response data from the application
 *  \param[in,out]  transferResponseParameterRecordSize  Available buffer size, Number of written response data bytes
 *  \param[out]     ErrorCode                            Negative response code in case return value is DCM_E_NOT_OK
 *  \return         DCM_E_OK                             Request was successful
 *  \return         DCM_E_NOT_OK                         Request was not successful
 *  \return         DCM_E_PENDING                        Request is not yet finished
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         This function is only available if DCM_FBLMGR_SUPPORT_ENABLED = STD_ON.
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestTransferExit(
  Dcm_OpStatusType OpStatus,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) transferRequestParameterRecord,
  uint32 transferRequestParameterRecordSize,
  uint8* transferResponseParameterRecord,
  uint32* transferResponseParameterRecordSize,
  Dcm_NegativeResponseCodePtrType ErrorCode
  )
  {
	(void)OpStatus;
	(void)transferRequestParameterRecord;
	(void)transferRequestParameterRecordSize;
	(void)transferResponseParameterRecord;
	(void)transferResponseParameterRecordSize;
	(void)ErrorCode;
    return RTE_E_OK;
  
  }


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/
#ifdef ENABLE_SSM_NOTIFICATION  /* Enabled for SSM State machine */

FUNC(Dcm_EcuResetType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_ADAS_ECU_Reset_DcmEcuReset(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  Dcm_EcuResetType curMode;
  curMode = Dcm_ECU_Reset_Reason;
  return curMode;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
	Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

	  switch (nextMode)
	    {
	    case RTE_MODE_DcmEcuReset_HARD:
	    case RTE_MODE_DcmEcuReset_SOFT:
		RST_SetPlannedReset(SOFT_RESET);
	      /* Set Flag marking Reset was requested */
	      /* Reset will be done when all EEPROM writes are complete */
        #ifdef Enable_Printf
        appLogPrintf("\n In Soft Reset !! ");
        #endif
	      break;
	    case RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER:
		RST_SetPlannedReset(BOOTLOADER_RESET);
        #ifdef Enable_Printf
        appLogPrintf("\n Jumping to Boot !! ");
        #endif
	      /* Set flag marking that a programming session transition was requested. */
	      FblSetFblStartMagicFlag();
	      /* Reset will be done when all EEPROM writes are complete */
	      break;
	    case RTE_MODE_DcmEcuReset_EXECUTE:
	      /* Write to EEPROm and Reset */
        #ifdef Enable_Printf
        appLogPrintf("\n EcuReset called!!");
	      #endif
        EcuReset();
	      break;
	    default:
	      ret = RTE_E_INVALID;
	      break;
	    }
	  Dcm_ECU_Reset_Reason = nextMode;

	  return ret;
}

#endif
/******************************************************************************************
FUNCTION NAME:          RST_SetPlannedReset
PURPOSE:                Function for setting ECU reset state


RETURN VALUE:           None
INPUT PARAMETERS:       None
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
static void RST_SetPlannedReset(uint8 resettype)
{
	RST_DiagState = resettype;
}
/******************************************************************************************
FUNCTION NAME:          RST_GetPlannedReset
PURPOSE:                Function for getting ECU reset state


RETURN VALUE:           None
INPUT PARAMETERS:       None
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
static uint8 RST_GetPlannedReset(void)
{
	return RST_DiagState;
}




/******************************************************************************************
FUNCTION NAME:          EcuReset
PURPOSE:                Function required by DCM to check any specific preconditions for
                        ECU Reset.


RETURN VALUE:           Std_ReturnType - E_OK - ECU Reset is allowed.
                                         E_NOT_OK - ECU Reset is not allowed.
INPUT PARAMETERS:       Dcm_EcuResetType nextMode - input parameter specifying the type
                        of the pending ECU Reset.
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
static void EcuReset(void)
{
	switch(RST_DiagState)
	{
		case BOOTLOADER_RESET:
			{
				EEP_Shutdown();
				break;
			}

		case SOFT_RESET:
			{
				SSM_Master_SetShutDownRequest();
				break;
			}

		case NO_RESET:
		default:
			/* No action */
			break;
	}

}
/******************************************************************************************/


/******************************************************************************************
FUNCTION NAME:          Eep_Ecureset
PURPOSE:                Function for doing an ECU reset


RETURN VALUE:           None
INPUT PARAMETERS:       None
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
void EEP_Shutdown(void)
{
    uint8 RST_DiagState_u8 = NO_RESET;
    RST_DiagState_u8 = RST_GetPlannedReset();

    if((uint8)BOOTLOADER_RESET == RST_DiagState_u8)
    {
        /* Stop RTE & Scheduler*/
        (void)Rte_Stop();
        SchM_Deinit();
        /* Disable watchdog */
        if(PMIC_ST_SUCCESS != Os_Call_Pmic_AppEnterInLongWindow())
        {
            /* if it fails retry, else the flashing will fail */
            (void)Os_Call_Pmic_AppEnterInLongWindow();
        }
        else
        {
        /*Do Nothing*/
        }
    }
    else
    {
    	/*Do Nothing*/
    }

    if(((uint8)BOOTLOADER_RESET == RST_DiagState) ||
       ((uint8)SOFT_RESET == RST_DiagState))
    {
       Eep_Ecureset();
    }
    else
    {
       EcuM_AL_SwitchOff();
    }
}


/******************************************************************************************
FUNCTION NAME:          Eep_Ecureset
PURPOSE:                Function for doing an ECU reset


RETURN VALUE:           None
INPUT PARAMETERS:       None
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
static void Eep_Ecureset(void)
{
	uint32 delaycnt;

    /*Transition to CAN Standby on ECU resets, so the ECU does not completely power off */
    if((uint8)TRUE == Get_CANStandby())
    {
    	/* Tranistion to Standby mode */
    	Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_DioChannel_pinEN, STD_LOW);
    	for(delaycnt=(uint32)e_ZERO;delaycnt<(uint32)D_DELAY_COUNT;delaycnt++)
    	{
    		/* Do nothing */
    	}
    	Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_DioChannel_PinSTB, STD_LOW);
    	for(delaycnt=(uint32)e_ZERO;delaycnt<(uint32)D_DELAY_COUNT;delaycnt++)
    	{
    		/* Do nothing */
    	}
    }
    else
    {
        /*Do Nothing*/
    }

    Set_CANStandby(TRUE);

    ReqSciclientECUReset();
}

/******************************************************************************************
FUNCTION NAME:          Set_CANStandby
PURPOSE:                Function for setting ECU reset without transition CAN Transceiver to
                        standby state


RETURN VALUE:           None
INPUT PARAMETERS:       None
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
static void Set_CANStandby(boolean u8CANState)
{
   Do_CANStandby = u8CANState;
}
/******************************************************************************************
FUNCTION NAME:          Get_CANStandby
PURPOSE:                Function for getting ECU reset without transition CAN Transceiver to
                        standby state


RETURN VALUE:           None
INPUT PARAMETERS:       None
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
static uint8 Get_CANStandby(void)
{
	return Do_CANStandby;
}

/******************************************************************************************
FUNCTION NAME:          AppDiag_InternalError_SysResetReq
PURPOSE:                Function to Trigger PMIC reset due to Internal error

RETURN VALUE:           None
INPUT PARAMETERS:       None
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
void AppDiag_InternalError_SysResetReq(void)
{
  /* trusted call added, since BswM is QM, who is calling it */
  (void)Os_Call_Pmic_F_SafeState2_v(SAFESTATE_REASON_ERROR_MGR);
}

/******************************************************************************************
FUNCTION NAME:          BSW_Set_SC_CAL_ResetType
PURPOSE:                Function to Set reset type after SC Calibration

RETURN VALUE:           None
INPUT PARAMETERS:       None
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
void BSW_Set_SC_CAL_ResetType(void)
{
  RST_SetPlannedReset(SOFT_RESET);
}

/*==================[end of file]===========================================*/
