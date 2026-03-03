#ifndef DEG_MANAGER_APP_INCLUDEGUARD_NAME
#define DEG_MANAGER_APP_INCLUDEGUARD_NAME

#include "PlatformDataTypes.h"
#include "ErrorManagerTypes.h"
#include "ErrorManagerShared.h"
#include "DegManagercfg.h"


bool_t DegManagerApp_Send(uint32_t *Fid_Output, uint16_t FidCount, uint32_t *Res_Output,uint16_t ResCount, ErrorMgr_AsilList asil);
bool_t DegManagerApp_Read(uint32_t *bInputData,ErrorMgr_AsilList asilInput,ErrorMgr_AsilList asilMod);


#endif
