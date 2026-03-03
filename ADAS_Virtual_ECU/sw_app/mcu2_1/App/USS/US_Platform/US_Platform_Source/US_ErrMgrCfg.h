/*
 * US_ErrMgrCfg.h
 *
 */

#ifndef US_ERR_MGR_H_
#define US_ERR_MGR_H_

#include "US_ErrMgr_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_PlatformCfg_Global.h"
#include "ErrorManagerDef.h"

#define SNR_ERR_MAP_SIZE   (uint32_t)(US_D_MAX_NUM_SENSORS * MAX_DTC_SNR_FLAGS)

extern US_DiagConfStrType DiagConfg[SNR_DIAG_FLG_SNR_FLAG_MAX_CODE];
extern US_ECUDiagConfStrType ECUDiagConfg[DIAG_FLAG_ECU_MAX_CODE] ;
extern ldef_ErrorMgr_enErrorNo SensorErrMap[US_D_MAX_NUM_SENSORS][MAX_DTC_SNR_FLAGS];
extern ldef_ErrorMgr_enErrorNo ECUErrMap[MAX_ECU_FLAGS];

#endif
