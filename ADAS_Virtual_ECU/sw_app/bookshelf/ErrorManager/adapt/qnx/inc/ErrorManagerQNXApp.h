#ifndef ErrorManagerQNXApp_IncludeGuard
#define ErrorManagerQNXApp_IncludeGuard


/* the API for reporting out the errors */
bool_t ErrorMgrSatelliteQnx_ReportErrorStatus(ldef_ErrorMgr_enErrorNo err, ldef_ErrorMgr_enErrorStatus enErrorStatus,const ldef_ErrorMgr_stAddData *AddData);


/* this API is for used within the generated framework. Not supposed to be used directly by application */
bool_t ErrorMgrSatelliteQnx_Write(const char *Path,ldef_ErrorMgr_enErrorStatus enErrorStatus,const ldef_ErrorMgr_stAddData *AddData);

#endif