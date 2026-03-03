#include "SignalDef.h"
#include "SignalMgr.h"
#include "SigMgr_IpcBridge.h"

 



	bool_t SignalMgr_Init(void)
	{
		bool_t bRet ;
		bRet = SigDef_Init();
		bRet &= SigMgr_IpcBridge_Init();

		return bRet;
	}


