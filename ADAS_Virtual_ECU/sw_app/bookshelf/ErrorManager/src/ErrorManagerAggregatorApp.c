#include "ErrorManagerTypes.h"
#include "ErrorManagerAggregator.h"
#include "ErrorManagerAggregatorDef.h"
#include "ErrorManagerAggregatorApp.h"

#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE 



#if ERRORMGT_AGGREGATORCORE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_SIGNALMGR
#include "SignalDef.h"
#elif ERRORMGT_AGGREGATORCORE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_RTE
#define RTE_ERRORMGRAGG_RTE_STUB_IFDEFS
#include "ErrorManager_Rte.h"
#endif




/*Application and project specific modifications can be made to this file*/

void ErrorMgrAggregatorApp_Init(ErrorMgr_AsilList AsilLevel)
{
  /* DD-ID: {B9D27E62-DC09-4d64-9936-D020E59AD180}*/
  (void)AsilLevel;
/*If the underlying method is notification */
#if ERRORMGR_AGGREGATORCORE_SATMONITOR == ERRORMGR_TYPE_ASYNC_NOTIFICATION

	#if ERRORMGT_AGGREGATORCORE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_SIGNALMGR
		/*Setup the callbacks*/
		#if ERRORMGR_CURRENTCORE == ERRORMGRCORE_MCU3_0
			SigMgr_Data_ErrorMgr_ErrorCommPack_3_0_QM_RegisterCallback(ErrorMgrAggregator_HandleNotification_3_0_QM);
			SigMgr_Data_ErrorMgr_ErrorCommPack_3_0_A_RegisterCallback(ErrorMgrAggregator_HandleNotification_3_0_A);
			SigMgr_Data_ErrorMgr_ErrorCommPack_3_0_B_RegisterCallback(ErrorMgrAggregator_HandleNotification_3_0_B);
			SigMgr_Data_ErrorMgr_ErrorCommPack_3_0_C_RegisterCallback(ErrorMgrAggregator_HandleNotification_3_0_C);
			SigMgr_Data_ErrorMgr_ErrorCommPack_3_0_D_RegisterCallback(ErrorMgrAggregator_HandleNotification_3_0_D);
		#elif ERRORMGR_CURRENTCORE == ERRORMGRCORE_MCU2_1
			SigMgr_Data_ErrorMgr_ErrorCommPack_2_1_QM_RegisterCallback(ErrorMgrAggregator_HandleNotification_2_1_QM);
			SigMgr_Data_ErrorMgr_ErrorCommPack_2_1_A_RegisterCallback(ErrorMgrAggregator_HandleNotification_2_1_A);
			SigMgr_Data_ErrorMgr_ErrorCommPack_2_1_B_RegisterCallback(ErrorMgrAggregator_HandleNotification_2_1_B);
			SigMgr_Data_ErrorMgr_ErrorCommPack_2_1_C_RegisterCallback(ErrorMgrAggregator_HandleNotification_2_1_C);
			SigMgr_Data_ErrorMgr_ErrorCommPack_2_1_D_RegisterCallback(ErrorMgrAggregator_HandleNotification_2_1_D);
		#endif
	#endif
	/*Otherwise configure that in ASR onData Received callback*/
#endif

}

/* DD-ID: {AC66B0B1-C882-4fe8-B223-BFED2058A7FE}*/
/*void ErrorMgrAggregatorApp_DeInit(void)
{
  Kept in case of future use
}*/


#if ERRMANAGER_D_LEVEL_ACTIVE == 1
static void ErrorMgrAggregatorApp_Read_D_Inputs()
{
  /* DD-ID: {BBF390D5-F08E-4404-A365-97BBB6042C82}*/
	ldef_ErrorMgr_ErrorCommPack_1_0_D data_1_0;


#if ERRORMGT_AGGREGATORCORE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_SIGNALMGR

	Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_D_stub(&data_1_0);


#elif ERRORMGT_AGGREGATORCORE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_RTE

/*Enable after the ARXML import to 1_0*/

	Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_D_stub(&data_1_0);

#endif

	ErrorMgrAggregator_HandleNotification_1_0_D(&data_1_0);

}

#endif



#if ERRMANAGER_B_LEVEL_ACTIVE == 1
static void ErrorMgrAggregatorApp_Read_B_Inputs(void)
{
  /* DD-ID: {6B247291-A4AE-44a9-BD69-781129C1DEE5}*/
	ldef_ErrorMgr_ErrorCommPack_1_0_B data_1_0;
	ldef_ErrorMgr_ErrorCommPack_2_0_B data_2_0;
	ldef_ErrorMgr_ErrorCommPack_2_1_B data_2_1;
/*	ldef_ErrorMgr_ErrorCommPack_3_0_B data_3_0;
	ldef_ErrorMgr_ErrorCommPack_3_1_B data_3_1;*/
	ldef_ErrorMgr_ErrorCommPack_QNX_B data_QNX;

#if ERRORMGT_AGGREGATORCORE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_SIGNALMGR

	SigMgr_Data_ErrorMgr_ErrorCommPack_1_0_B_Get(&data_1_0);
	SigMgr_Data_ErrorMgr_ErrorCommPack_2_0_B_Get(&data_2_0);
	SigMgr_Data_ErrorMgr_ErrorCommPack_2_1_B_Get(&data_2_1);
	SigMgr_Data_ErrorMgr_ErrorCommPack_3_0_B_Get(&data_3_0);
	SigMgr_Data_ErrorMgr_ErrorCommPack_3_1_B_Get(&data_3_0);
	SigMgr_Data_ErrorMgr_ErrorCommPack_QNX_B_Get(&data_QNX);


#elif ERRORMGT_AGGREGATORCORE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_RTE
/*Enable after the ARXML import to 1_0*/

	(void)Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B_stub(&data_1_0);
	(void)Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B_stub(&data_2_0);
	(void)Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_B_stub(&data_2_1);
/*	Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_0_B_stub(&data_3_0);
	Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_1_B_stub(&data_3_1);*/
	(void)Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B_stub(&data_QNX);
#endif

	(void)ErrorMgrAggregator_HandleNotification_1_0_B(&data_1_0);
	(void)ErrorMgrAggregator_HandleNotification_2_0_B(&data_2_0);
	(void)ErrorMgrAggregator_HandleNotification_2_1_B(&data_2_1);
/*	ErrorMgrAggregator_HandleNotification_3_0_B(&data_3_0);
	ErrorMgrAggregator_HandleNotification_3_1_B(&data_3_1);*/
	(void)ErrorMgrAggregator_HandleNotification_QNX_B(&data_QNX);

}
#endif


#if ERRMANAGER_QM_LEVEL_ACTIVE == 1
static void ErrorMgrAggregatorApp_Read_QM_Inputs(void)
{
	/* DD-ID :{B6105AF2-547D-4d7a-87C8-77266A36DEC6}*/
	ldef_ErrorMgr_ErrorCommPack_1_0_QM data_1_0;
	ldef_ErrorMgr_ErrorCommPack_2_0_QM data_2_0;
	ldef_ErrorMgr_ErrorCommPack_2_1_QM data_2_1;
/*	ldef_ErrorMgr_ErrorCommPack_3_0_QM data_3_0;
	ldef_ErrorMgr_ErrorCommPack_3_1_QM data_3_1;*/
	ldef_ErrorMgr_ErrorCommPack_QNX_QM data_QNX;

#if ERRORMGT_AGGREGATORCORE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_SIGNALMGR

	SigMgr_Data_ErrorMgr_ErrorCommPack_1_0_QM_Get(&data_1_0);
	SigMgr_Data_ErrorMgr_ErrorCommPack_2_0_QM_Get(&data_2_0);
	SigMgr_Data_ErrorMgr_ErrorCommPack_2_1_QM_Get(&data_2_1);
/*	SigMgr_Data_ErrorMgr_ErrorCommPack_3_0_QM_Get(&data_3_0);
	SigMgr_Data_ErrorMgr_ErrorCommPack_3_1_QM_Get(&data_3_0);*/
	SigMgr_Data_ErrorMgr_ErrorCommPack_QNX_QM_Get(&data_QNX);


#elif ERRORMGT_AGGREGATORCORE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_RTE
/*Enable after the ARXML import to 1_0*/

	(void)Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_stub(&data_1_0);
	(void)Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_QM_stub(&data_2_0);
	(void)Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_QM_stub(&data_2_1);
/*	Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_0_QM_stub(&data_3_0);
	Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_1_QM_stub(&data_3_1);*/
	(void)Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_QM_stub(&data_QNX);
#endif

	(void)ErrorMgrAggregator_HandleNotification_1_0_QM(&data_1_0);
	(void)ErrorMgrAggregator_HandleNotification_2_0_QM(&data_2_0);
	(void)ErrorMgrAggregator_HandleNotification_2_1_QM(&data_2_1);
/*	ErrorMgrAggregator_HandleNotification_3_0_QM(&data_3_0);
	ErrorMgrAggregator_HandleNotification_3_1_QM(&data_3_1);*/
	(void)ErrorMgrAggregator_HandleNotification_QNX_QM(&data_QNX);

}
#endif




void ErrorMgrAggregatorApp_ReadInputs(ErrorMgr_AsilList AsilLevel)
{
  /* DD-ID: {D51B9F36-116C-452b-A1F7-26412C7DF49D}*/

#if ERRORMGR_AGGREGATORCORE_SATMONITOR == ERRORMGR_TYPE_PERIODIC_SATSAMPLING
	switch (AsilLevel)
	{
		#if ERRMANAGER_QM_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_QM:
		(void)ErrorMgrAggregatorApp_Read_QM_Inputs();
		break;
		#endif
		#if ERRMANAGER_B_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_B:
		(void)ErrorMgrAggregatorApp_Read_B_Inputs();
		break;
		#endif
		#if ERRMANAGER_D_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_D:
		(void)ErrorMgrAggregatorApp_Read_D_Inputs();
		break;
		#endif

	default:
		/* Do Nothing */
		break;
	}
#endif

}


void ErrorMgrAggregatorApp_Write_AsilGrouped_ErrorStatus(ErrorMgr_AsilList asilLevel,uint32_t *bErrorData,uint32_t errsize,ErrorMgrAggregator_InternalRuntimeErrorDefs *RunDef)
{
  /* DD-ID: {1438C80B-185B-49e1-B253-E13774041207}*/

	switch (asilLevel)
	{
		#if ERRMANAGER_QM_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_QM:
		(void)ErrorMgrAggregatorApp_Write_QM_ErrorStatus(bErrorData,errsize,RunDef);
		break;
		#endif
		#if ERRMANAGER_A_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_A:
		(void)ErrorMgrAggregatorApp_Write_A_ErrorStatus(bErrorData,errsize,RunDef);
		break;
		#endif
		#if ERRMANAGER_B_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_B:
		(void)ErrorMgrAggregatorApp_Write_B_ErrorStatus(bErrorData,errsize,RunDef);
		break;
		#endif
		#if ERRMANAGER_C_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_C:
		(void)ErrorMgrAggregatorApp_Write_C_ErrorStatus(bErrorData,errsize,RunDef);
		break;
		#endif
		#if ERRMANAGER_D_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_D:
		(void)ErrorMgrAggregatorApp_Write_D_ErrorStatus(bErrorData,errsize,RunDef);
		break;
		#endif

	default:
		/* Do Nothing */
		break;
	}

}

void ErrorMgrAggregatorApp_Write_SafeState(ErrorMgr_AsilList asilLevel,bool_t *bSafeState,uint32_t SafeStateMax,ErrorMgrAggregator_InternalRuntimeErrorDefs *RunDef)
{
  /* DD-ID: {78AA56D2-034A-454a-9919-6EA40612DE1C}*/

	switch (asilLevel)
	{
		#if ERRMANAGER_QM_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_QM:
		(void)ErrorMgrAggregatorApp_Write_QM_SafeState(bSafeState,SafeStateMax,RunDef);
		break;
		#endif
		#if ERRMANAGER_A_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_A:
		(void)ErrorMgrAggregatorApp_Write_A_SafeState(bSafeState,SafeStateMax,RunDef);
		break;
		#endif
		#if ERRMANAGER_B_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_B:
		(void)ErrorMgrAggregatorApp_Write_B_SafeState(bSafeState,SafeStateMax,RunDef);
		break;
		#endif
		#if ERRMANAGER_C_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_C:
		(void)ErrorMgrAggregatorApp_Write_C_SafeState(bSafeState,SafeStateMax,RunDef);
		break;
		#endif
		#if ERRMANAGER_D_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_D:
		(void)ErrorMgrAggregatorApp_Write_D_SafeState(bSafeState,SafeStateMax,RunDef);
		break;
		#endif

	default:
		/* Do Nothing */
		break;
	}

}
#if ERRORMGR_CURRENTCORE == ERRORMGRCORE_MCU1_0
void ErrorMgrAggregatorApp_Write_SafeState2ReasonProcess(uint16 SafeState2_RstRsn_flag)
{
  /* DD-ID: {78AA56D2-034A-454a-9919-6EA40612DE1C}*/
  /* DD-ID :{9FFF2295-0C31-4991-B9A3-346528B5DFFC}*/
   (void)ErrorMgrAggregatorApp_Write_SafeState2Reason(SafeState2_RstRsn_flag);
}
#endif
#endif


