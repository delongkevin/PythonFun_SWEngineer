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
 *             File:  IoHwAb.c
 *           Config:  C:/_mks/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  IoHwAb
 *  Generation Time:  2024-02-14 18:38:48
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <IoHwAb>
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
 * IOHWAB_BOOL
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * IOHWAB_UINT16
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IOHWAB_UINT8
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Runnable Entities:
 * ==================
 * IoHwAb_PpIoHwAbAdc_GetRawValues
 *   Runnable Entity for calling the Operation 'GetRawValues' of the Client/Server Port Prototype 'PpIoHwAbAdc'.
 *
 * IoHwAb_PpUSSDselPin_GetUSSDselPinStatus
 *   Runnable Entity for calling the Operation 'GetUSSDselPinStatus' of the Client/Server Port Prototype 'PpUSSDselPin'.
 *
 *********************************************************************************************************************/

#include "Rte_IoHwAb.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Adc.h"
#include "Dio.h"
#include "Enums.h"
#include "Wdg.h"

#define D_MAX_AVG_CNT             3U

/* Define IoHwAb ADC group length */
#define D_IOHWAB_ADC_GROUP0_LEN          8u
#define D_IOHWAB_ADC_GROUP1_LEN          3u 


#define D_IOHWAB_ADC_GROUP0_STARTINDEX   0u
#define D_IOHWAB_ADC_GROUP0_ENDINDEX     D_IOHWAB_ADC_GROUP0_LEN
#define D_IOHWAB_ADC_GROUP1_STARTINDEX   8u
#define D_IOHWAB_ADC_GROUP1_ENDINDEX     (D_IOHWAB_ADC_GROUP0_LEN+D_IOHWAB_ADC_GROUP1_LEN)

#define D_IOHWAB_ADC_ALLGROUP_LEN        (D_IOHWAB_ADC_GROUP0_LEN+D_IOHWAB_ADC_GROUP1_LEN)

#define D_ADC_CAM_CS_A                  (1u)/* ADC channel for reading CAM voltage for des 0 */
#define D_ADC_CAM_CS_B                  (2u)/* ADC channel for reading CAM voltage for des 1 */

#if !defined (D_IOHWAB_LOCAL) /* D_IOHWAB_LOCAL TX */
# define D_IOHWAB_LOCAL static
#endif

static uint32 s_Adc_ResultBufferGroup_au32[D_MAX_AVG_CNT][D_IOHWAB_ADC_ALLGROUP_LEN];
static uint32 s_Adc_ResultAvgBufferGroup_au32[D_IOHWAB_ADC_ALLGROUP_LEN];

D_IOHWAB_LOCAL FUNC(void, IOHWAB_CODE) f_IoHwAb_StartGroupConversion(void);
D_IOHWAB_LOCAL FUNC(void, IOHWAB_CODE) f_IoHwAb_ReadGroup0Conversion(void);
D_IOHWAB_LOCAL FUNC(void, IOHWAB_CODE) f_IoHwAb_ReadGroup1Conversion(void);
FUNC(void, IOHWAB_CODE) IoHwAb_Init (void);
void AdcApp_HwUnit0_Group0EndNotification(void);
void AdcApp_HwUnit1_Group1EndNotification(void); 
 
#define D_COUNTERDELAY            20U
#define D_LED_MASK                1U
#define D_RESULT_BUFR_DEFAULT_VALUE 0xFFFFFFFFu

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
 * IOHWAB_BOOL: Boolean
 * IOHWAB_UINT16: Integer in interval [0...65535]
 * IOHWAB_UINT8: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAb_Mainfunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAb_Mainfunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, IoHwAb_CODE) IoHwAb_IoHwAb_Mainfunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAb_Mainfunction
 *********************************************************************************************************************/
	/*ReqID:-*/
  /* DD-ID: {AB8F5BA6-106E-4e16-B60D-4BC070092494}*/
	static uint8 s_toggleLed_u8 = FALSE;
	static uint8 s_toggleCnt_u8 = FALSE;

	(void)f_IoHwAb_StartGroupConversion();

	if (s_toggleCnt_u8 < D_COUNTERDELAY)
	{
		s_toggleCnt_u8++;
	}
	else
	{
		s_toggleCnt_u8 = FALSE;
		s_toggleLed_u8 = ~s_toggleLed_u8;
		Dio_WriteChannel(DioConf_DioChannel_DioChannel_MCU_LED, (s_toggleLed_u8 & D_LED_MASK));
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_PpIoHwAbAdc_GetRawValues
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetRawValues> of PortPrototype <PpIoHwAbAdc>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_PpIoHwAbAdc_GetRawValues(IOHWAB_UINT8 Channelndex, IOHWAB_UINT16 *ChannelRawValue)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_IoHwAbADCData_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_PpIoHwAbAdc_GetRawValues_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_PpIoHwAbAdc_GetRawValues(IOHWAB_UINT8 Channelndex, P2VAR(IOHWAB_UINT16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ChannelRawValue) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_PpIoHwAbAdc_GetRawValues (returns application error)
 *********************************************************************************************************************/
	/*ReqID:-*/
  /* DD-ID: {CE45A84E-2653-4ae9-B9EA-6F7682D862C1}*/
	if(D_IOHWAB_ADC_ALLGROUP_LEN > Channelndex)
	{
		*ChannelRawValue = (IOHWAB_UINT16)s_Adc_ResultAvgBufferGroup_au32[Channelndex];
	}
	else
	{
		/* Do Nothing*/
	}

	return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_PpUSSDselPin_GetUSSDselPinStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetUSSDselPinStatus> of PortPrototype <PpUSSDselPin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_PpUSSDselPin_GetUSSDselPinStatus(IOHWAB_BOOL USSDselPinStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_IoHwAbUSSDselPin_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_PpUSSDselPin_GetUSSDselPinStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_PpUSSDselPin_GetUSSDselPinStatus(IOHWAB_BOOL USSDselPinStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_PpUSSDselPin_GetUSSDselPinStatus (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {195118CE-BFDA-4122-AEC2-93F3291CB098}*/

  Dio_WriteChannel(DioConf_DioChannel_DioChannel_USSDselPIN, USSDselPinStatus);

  return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, IOHWAB_CODE) IoHwAb_Init (void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Initialization Code>
 *********************************************************************************************************************/
  /* TODO: Add the implementation of the initialization code here */
  /* DD-ID: {E29F26B6-8D61-4233-B1BB-68019DC87766}*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/
	/*ReqID:-*/
	/*GUID:-{E29F26B6-8D61-4233-B1BB-68019DC87766}*/

	 uint8 v_id_u8;

	(void)Adc_SetupResultBuffer(ADC_GROUP_ID_0, &s_Adc_ResultBufferGroup_au32[e_ZERO][D_IOHWAB_ADC_GROUP0_STARTINDEX]);
	(void)Adc_SetupResultBuffer(ADC_GROUP_ID_1, &s_Adc_ResultBufferGroup_au32[e_ZERO][D_IOHWAB_ADC_GROUP1_STARTINDEX]);
	(void)f_IoHwAb_StartGroupConversion();

	for(v_id_u8 = (uint8)e_ZERO; v_id_u8 < D_IOHWAB_ADC_ALLGROUP_LEN; v_id_u8++)
	{
		s_Adc_ResultAvgBufferGroup_au32[v_id_u8] = D_RESULT_BUFR_DEFAULT_VALUE;
	}

	return;
} 
/*************************************ADC_NOTIFICATION_ENABLED***********************************************************/

void AdcApp_HwUnit0_Group0EndNotification(void)
{
  /* DD-ID: {949D9D23-BB9B-4539-9F09-D453894455FD}*/
	 /*GUID:- {949D9D23-BB9B-4539-9F09-D453894455FD}*/
	f_IoHwAb_ReadGroup0Conversion();
	return;
}

void AdcApp_HwUnit1_Group1EndNotification(void)
{
  /* DD-ID: {4CF12DE9-A2F4-46e3-A494-FA30CF5054EC}*/
	f_IoHwAb_ReadGroup1Conversion();
	return;
}

/**************************************IoHwAb_StartGroupConversion**********************************************************/ 

D_IOHWAB_LOCAL FUNC(void, IOHWAB_CODE) f_IoHwAb_StartGroupConversion(void)
{
  /* DD-ID: {C55B14B0-D832-4c23-9923-9DD2BBF25A9A}*/
	Adc_StatusType v_AdcGroupStatus_e;
	v_AdcGroupStatus_e = Adc_GetGroupStatus(ADC_GROUP_ID_0);

	if (ADC_BUSY != v_AdcGroupStatus_e)	
	{
		/* Enable notification */
		Adc_EnableGroupNotification(ADC_GROUP_ID_0);
		Adc_StartGroupConversion(ADC_GROUP_ID_0);
	}
	else
	{
		/*Do nothing*/
	}

	v_AdcGroupStatus_e = Adc_GetGroupStatus(ADC_GROUP_ID_1);

	if (ADC_BUSY != v_AdcGroupStatus_e)
	{
		/* Enable notification */
		Adc_EnableGroupNotification(ADC_GROUP_ID_1);
		Adc_StartGroupConversion(ADC_GROUP_ID_1);
	}
	else
	{
		/*Do nothing*/
	}

}
/***********************************IoHwAb_ReadGroup0Conversion*************************************************************/

D_IOHWAB_LOCAL FUNC(void, IOHWAB_CODE) f_IoHwAb_ReadGroup0Conversion(void)
{
  /* DD-ID: {6B72BCBE-6F69-4fa7-B831-BE33AD0A2C46}*/
	Adc_StatusType	v_AdcGroupStatus_e;
	uint8 	      v_AvgIndex_u8;
	uint8           v_ADCchanelindex_u8;
	static uint8    s_AvgSamplegroup0_u8;

	v_AdcGroupStatus_e = Adc_GetGroupStatus(ADC_GROUP_ID_0);

	if ((ADC_STREAM_COMPLETED == v_AdcGroupStatus_e) || (ADC_COMPLETED == v_AdcGroupStatus_e))
	{
		(void)Adc_ReadGroup(ADC_GROUP_ID_0, &s_Adc_ResultBufferGroup_au32[s_AvgSamplegroup0_u8][D_IOHWAB_ADC_GROUP0_STARTINDEX]);

		if((D_MAX_AVG_CNT-(uint8)e_ONE) <= s_AvgSamplegroup0_u8)   /*Check Max count completed*/
		{
			/*clear counter value for next cycle*/
			s_AvgSamplegroup0_u8= (uint8)e_ZERO;

			for (v_ADCchanelindex_u8 = D_IOHWAB_ADC_GROUP0_STARTINDEX; v_ADCchanelindex_u8 < D_IOHWAB_ADC_GROUP0_ENDINDEX; v_ADCchanelindex_u8++)
			{
				s_Adc_ResultAvgBufferGroup_au32[v_ADCchanelindex_u8] = (uint32)e_ZERO;

        if((v_ADCchanelindex_u8 == D_ADC_CAM_CS_A) || (v_ADCchanelindex_u8 == D_ADC_CAM_CS_B))/* Excluding average values for CAM voltage */
        {
          s_Adc_ResultAvgBufferGroup_au32[v_ADCchanelindex_u8] = s_Adc_ResultBufferGroup_au32[D_MAX_AVG_CNT-(uint8)e_ONE][v_ADCchanelindex_u8]; /* Storing the most recent ADC value */
        }
        else
        {
				  /*Add 3 samples value*/
				  for (v_AvgIndex_u8 = (uint8)e_ZERO; v_AvgIndex_u8 < D_MAX_AVG_CNT; v_AvgIndex_u8++)
				  {
					  s_Adc_ResultAvgBufferGroup_au32[v_ADCchanelindex_u8] += s_Adc_ResultBufferGroup_au32[v_AvgIndex_u8][v_ADCchanelindex_u8];
				  }

				  s_Adc_ResultAvgBufferGroup_au32[v_ADCchanelindex_u8] /= D_MAX_AVG_CNT;  /*take avg value*/
			  }
      }

		}/*end of if((D_MAX_AVG_CNT-(uint8)1) <= s_AvgSamplegroup0_u8) */
		else
		{
		 /* INCREMENT_VALUE_BYONE(u8AvgSample); */    /*increament counter value by one*/
		s_AvgSamplegroup0_u8++;
		}
	}/*end of if ((ADC_STREAM_COMPLETED == v_AdcGroupStatus_e) || (ADC_COMPLETED == v_AdcGroupStatus_e)) */
	else
	{
		/*Do nothing*/
	}
}

/***********************************IoHwAb_ReadGroup1Conversion*************************************************************/

D_IOHWAB_LOCAL FUNC(void, IOHWAB_CODE) f_IoHwAb_ReadGroup1Conversion(void)
{
  /* DD-ID: {55E01B6A-5865-475f-AB4F-086A6EF16EFA}*/
	Adc_StatusType	v_AdcGroupStatus_e;
	uint8			v_AvgIndex_u8;
	uint8			v_ADCchanelindex_u8;
	static uint8	s_AvgSamplegroup1_u8;

	v_AdcGroupStatus_e = Adc_GetGroupStatus(ADC_GROUP_ID_1);

	if ((ADC_STREAM_COMPLETED == v_AdcGroupStatus_e) || (ADC_COMPLETED == v_AdcGroupStatus_e))
	{
		(void)Adc_ReadGroup(ADC_GROUP_ID_1, &s_Adc_ResultBufferGroup_au32[s_AvgSamplegroup1_u8][D_IOHWAB_ADC_GROUP1_STARTINDEX]);

		if((D_MAX_AVG_CNT-(uint8)e_ONE) <= s_AvgSamplegroup1_u8)   /*Check Max count completed*/
		{
			/*clear counter value for next cycle*/
			s_AvgSamplegroup1_u8= (uint8)e_ZERO;

			for (v_ADCchanelindex_u8 = D_IOHWAB_ADC_GROUP1_STARTINDEX; v_ADCchanelindex_u8 < D_IOHWAB_ADC_GROUP1_ENDINDEX; v_ADCchanelindex_u8++)
			{
				s_Adc_ResultAvgBufferGroup_au32[v_ADCchanelindex_u8] = (uint32)e_ZERO;

				/*Add 3 samples value*/
				for (v_AvgIndex_u8 =(uint8) e_ZERO; v_AvgIndex_u8 < D_MAX_AVG_CNT; v_AvgIndex_u8++)
				{
					s_Adc_ResultAvgBufferGroup_au32[v_ADCchanelindex_u8] += s_Adc_ResultBufferGroup_au32[v_AvgIndex_u8][v_ADCchanelindex_u8];
				}

				s_Adc_ResultAvgBufferGroup_au32[v_ADCchanelindex_u8] /= D_MAX_AVG_CNT;  /*take avg value*/
			}
		}
		else
		{
			/* INCREMENT_VALUE_BYONE(u8AvgSample); */
			/*increment counter value by one*/
			s_AvgSamplegroup1_u8++;
		}
	}
	else
	{
		/*Do nothing*/
	}
}

/************************************************************************************************/

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
