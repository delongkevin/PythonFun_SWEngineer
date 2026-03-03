#ifndef ERRORMANAGERSATELLITEAPP_H_INCLUDEGUARD
#define ERRORMANAGERSATELLITEAPP_H_INCLUDEGUARD

#include "ErrorManagerTypes.h"
#include "ErrorManagerDef.h"


#ifdef __cplusplus
extern "C" {
#endif
	void ErrorMgrSatelliteApp_Init(ErrorMgr_AsilList AsilLevel);
	/*void ErrorMgrSatelliteApp_DeInit(void);*/
	void ErrorMggrSatelliteApp_Send(const ldef_ErrorMgr_ErrorCommPack* ComPack, ErrorMgr_AsilList AsilLevel);
	
#ifdef __cplusplus
}
#endif

#endif
