#include "DegManager.h"
#include "DegManager_app.h"

#define DEGMANAGER_RTE_STUB_IF
#include "DegManager_Rte.h"

#include "DegManagerTypes.h"

#include "ipc_lookup_table.h"

#include "DegManager_Common_Memmap_adapt.h"

/* This  file needs to be adopted according to project and underlying communication protocol*/


bool_t DegManagerApp_Send(uint32_t *Fid_Output, uint16_t FidCount, uint32_t *Res_Output,uint16_t ResCount, ErrorMgr_AsilList asil)
{
  /* DD-ID: {A08CE036-BC52-4255-BFE2-8FE53D56D0B2}*/
	(void)Res_Output;
	(void)ResCount;
	(void)FidCount;
	bool_t bRet=FALSE;
	switch (asil)
	{
	case ErrorMgr_Asil_QM:

	 #if defined(DEGMANAGER_FID_BYTE_STRUCT)
		(void)DEGMANAGER_SEND_QM((void *)Fid_Output,(UINT16)DEGMANAGER_WRITE_QM_MSGID,sizeof(FID_BYTE_STRUCT_QM));
	 #else
	 	/*RTE_Write*/
   		Rte_Write_P_FID_Output_QM_FID_QM_stub(Fid_Output);
	  	Rte_Write_P_RES_Output_QM_RES_QM_stub(Res_Output);
		 DEGMANAGER_SEND_QM((void *)Fid_Output,DEGMANAGER_WRITE_QM_MSGID,sizeof(DegManager_Output_QM_t));
	 #endif
		bRet=TRUE;
		break;

	case ErrorMgr_Asil_B:
	 #if defined(DEGMANAGER_FID_BYTE_STRUCT)
		(void)DEGMANAGER_SEND_B((void *)Fid_Output,(UINT16)DEGMANAGER_WRITE_B_MSGID,sizeof(FID_BYTE_STRUCT_B));
	 #else
		 Rte_Write_P_FID_Output_B_FID_B_stub(Fid_Output);
		 Rte_Write_P_RES_Output_B_RES_B_stub(Res_Output);
		 DEGMANAGER_SEND_B((void *)Fid_Output,DEGMANAGER_WRITE_B_MSGID,sizeof(DegManager_Output_B_t));
		#endif
		bRet=TRUE;
		break;
	default:
		/* Do Nothing */
		break;
	}

	return bRet;
}

bool_t DegManagerApp_Read(uint32_t *bInputData,ErrorMgr_AsilList asilInput,ErrorMgr_AsilList asilMod)
{
  /* DD-ID: {4317C75B-4221-426d-A6CA-36958AAAD4E7}*/
	bool_t bRet=FALSE;

	if(asilMod == ErrorMgr_Asil_QM)
	{
		bRet=TRUE;
		switch (asilInput)
		{
			case ErrorMgr_Asil_QM:
				(void)DEGMANAGER_READ_QM_INPUT_BY_QM(bInputData);

				break;
			case ErrorMgr_Asil_B:
				(void)DEGMANAGER_READ_B_INPUT_BY_QM(bInputData);
				break;
			default:
				bRet=FALSE;
				break;
		}

	}
	else if(asilMod == ErrorMgr_Asil_B)
	{
		bRet=TRUE;
		switch (asilInput)
		{
			/* this case is temporary till Naveen fixes the sheet of cross dependency*/
			case ErrorMgr_Asil_QM:
				(void)DEGMANAGER_READ_QM_INPUT_BY_B(bInputData);
				break;

			case ErrorMgr_Asil_B:
				(void)DEGMANAGER_READ_B_INPUT_BY_B(bInputData);
				break;
			default:
				bRet=FALSE;
				break;
		}

	}
	else
	{
		/* Do Nothing */
	}
	return bRet;
}
