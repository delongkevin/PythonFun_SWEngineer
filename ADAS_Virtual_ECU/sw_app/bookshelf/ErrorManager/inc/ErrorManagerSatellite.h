#ifndef ERRORMANAGERSATELLITE_H_INCLUDEGUARD
#define ERRORMANAGERSATELLITE_H_INCLUDEGUARD

#include "ErrorManagerDef.h"


#ifdef __cplusplus
extern "C" {
#endif
	void ErrorMgrSatellite_Init_QM(void);
//	void ErrorMgrSatellite_Init_A(void);
	void ErrorMgrSatellite_Init_B(void);
//	void ErrorMgrSatellite_Init_C(void);
//	void ErrorMgrSatellite_Init_D(void);

/*	void ErrorMgrSatellite_DeInit(void);*/

//	void ErrorMgrSatellite_PeriodicFunction_A(void);
	void ErrorMgrSatellite_PeriodicFunction_B(void);
	void ErrorMgrSatellite_PeriodicFunction_QM(void);
//	void ErrorMgrSatellite_PeriodicFunction_D(void);
	
	bool_t ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_enErrorNo err, ldef_ErrorMgr_enErrorStatus enErrorStatus,const ldef_ErrorMgr_stAddData *AddData);

#ifdef __cplusplus
}
#endif

#endif
