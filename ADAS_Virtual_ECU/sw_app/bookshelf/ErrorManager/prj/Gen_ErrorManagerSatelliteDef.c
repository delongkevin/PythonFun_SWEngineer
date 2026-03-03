

/* initialized Errormmgr satellite generated objects */
void ErrorManagerSatelliteDef_Init(ErrorMgr_AsilList asil)
{
	const ErrorMgr_ErrorDescExt * ErrDescExt;
	uint16_t i,cnt;

	*ldef_ErrorMgr_ErrorCommPackRef[asil].RunningCounter=0;
	*ldef_ErrorMgr_ErrorCommPackRef[asil].Checksum=0;
	memset(ldef_ErrorMgr_ErrorCommPackRef[asil].Error,0,sizeof(ldef_ErrorMgr_ErrorCommPackRef[asil].Count*sizeof(ldef_ErrorMgr_ErrorField)));
	memset(ldef_ErrorMgr_ErrorCommPackRef[asil].Data,0,sizeof(ldef_ErrorMgr_ErrorCommPackRef[asil].Count*sizeof(ldef_ErrorMgr_stAddData)));

	ErrDescExt=ErrorMgr_getGetErrorLocalDesc();
	for(i=0;i<(uint16_t)ErrorMgr_Asil_MAX;i++)
	{
		if((ErrDescExt[i].Count > 0) && (ErrDescExt[i].ErrorDesc != NULL))
		{
			for(cnt=0;cnt<ErrDescExt[i].Count;cnt++)
			{
				memset(ErrDescExt[i].ErrorDesc[cnt].RamDef,0,sizeof(ErrorMgr_RuntimeStateDef));
			}

		}
	}
}