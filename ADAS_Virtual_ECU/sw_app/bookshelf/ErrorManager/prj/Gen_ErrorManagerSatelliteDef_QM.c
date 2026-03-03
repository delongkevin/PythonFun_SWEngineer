/* initialized Errormmgr satellite generated objects */
void ErrorManagerSatelliteDef_Init_QM(void)
{
	const ErrorMgr_ErrorDescExt * ErrDescExt;
	uint16_t cnt;
	ErrorMgr_AsilList i = ErrorMgr_Asil_QM;

	ldef_Sat_ErrorCommPack_Current_Core.RunningCounter=0;
	ldef_Sat_ErrorCommPack_Current_Core.Checksum=0;

	memset(&ldef_Sat_ErrorCommPack_Current_Core.Error,0,sizeof(ldef_Sat_ErrorCommPack_Current_Core.Error));
	memset(&ldef_Sat_ErrorCommPack_Current_Core.Data,0,sizeof(ldef_Sat_ErrorCommPack_Current_Core.Data));

	ErrDescExt=ErrorMgr_getGetErrorLocalDesc();

		if((ErrDescExt[i].Count > 0) && (ErrDescExt[i].ErrorDesc != NULL))
		{
			for(cnt=0;cnt<ErrDescExt[i].Count;cnt++)
			{
				memset(ErrDescExt[i].ErrorDesc[cnt].RamDef,0,sizeof(ErrorMgr_RuntimeStateDef));
			}

		}
}
	
